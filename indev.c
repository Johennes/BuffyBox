/**
 * Copyright 2021 Johannes Marbach
 *
 * This file is part of unl0kr, hereafter referred to as the program.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */


#include "indev.h"

#include "cursor.h"
#include "log.h"

#include "lv_drivers/indev/libinput_drv.h"

#include <libinput.h>
#include <libudev.h>
#include <limits.h>
#include <stdio.h>

#include <linux/input.h>

#include <sys/select.h>


/**
 * Defines
 */

#define INPUT_DEVICE_NODE_PREFIX "/dev/input/event"

#define MAX_KEYBOARD_DEVS 4
#define MAX_POINTER_DEVS 4
#define MAX_TOUCHSCREEN_DEVS 1


/**
 * Static variables
 */

static libinput_capability allowed_capability = LIBINPUT_CAPABILITY_NONE;

static struct udev *context = NULL;
static struct udev_monitor *monitor = NULL;
static int monitor_fd = -1;

struct input_device {
  char *node;
  libinput_capability capability;
  libinput_drv_state_t drv_state;
  lv_indev_drv_t indev_drv;
  lv_indev_t *indev;
};

static struct input_device **devices = NULL;
static int num_devices = 0;
static int num_connected_devices = 0;

lv_group_t *keyboard_input_group = NULL;
lv_obj_t *cursor_obj = NULL;


/**
 * Static prototypes
 */

/**
 * Test whether a device can act as a keyboard device.
 * 
 * @param device the device to test
 * @return true if the device has the keyboard capability
 */
static bool is_keyboard_device(struct input_device *device);

/**
 * Test whether a device can act as a pointer device.
 * 
 * @param device the device to test
 * @return true if the device has the pointer capability
 */
static bool is_pointer_device(struct input_device *device);

/**
 * Convert a device capability into a descriptive string.
 * 
 * @param capability input device capability
 * @return textual description
 */
static char *capability_to_str(libinput_capability capability);

/**
 * Connect a specific input device using its udev device.
 *
 * @param device udev device
 */
static void connect_udev_device(struct udev_device *device);

/**
 * Connect a specific input device using its device node.
 *
 * @param node device node path
 */
static void connect_devnode(const char *node);

/**
 * Disconnect a specific input device using its device node.
 *
 * @param node device node path
 */
static void disconnect_devnode(const char *node);

/**
 * Disconnect a specific input device using its index in the devices array.
 *
 * @param idx index in devices array
 */
static void disconnect_idx(int idx);

/**
 * Perform an input read on a device using the libinput driver.
 *
 * @param indev_drv input device driver
 * @param data input device data to write into
 */
static void libinput_read_cb(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);

/**
 * Set up the input group for a keyboard device.
 *
 * @param device the input device
 */
static void set_keyboard_input_group(struct input_device *device);

/**
 * Set up the mouse cursor image for a pointer device.
 * 
 * @param device the input device
 */
static void set_mouse_cursor(struct input_device *device);


/**
 * Static functions
 */

static bool is_keyboard_device(struct input_device *device) {
    return (device->capability & LIBINPUT_CAPABILITY_KEYBOARD) != LIBINPUT_CAPABILITY_NONE;
}

static bool is_pointer_device(struct input_device *device) {
    return (device->capability & LIBINPUT_CAPABILITY_POINTER) != LIBINPUT_CAPABILITY_NONE;
}

static char *capability_to_str(libinput_capability capability) {
    if (capability == LIBINPUT_CAPABILITY_KEYBOARD) {
        return "keyboard";
    }
    if (capability == LIBINPUT_CAPABILITY_POINTER) {
        return "pointer";
    }
    if (capability == LIBINPUT_CAPABILITY_TOUCH) {
        return "touch";
    }
    return "none";
}

static void connect_udev_device(struct udev_device *device) {
    /* Obtain and verify device node */
    const char *node = udev_device_get_devnode(device);
    if (!node || strncmp(node, INPUT_DEVICE_NODE_PREFIX, strlen(INPUT_DEVICE_NODE_PREFIX)) != 0) {
        ul_log(UL_LOG_LEVEL_VERBOSE, "Ignoring unsupported input device %s", udev_device_get_syspath(device));
        return;
    }

    /* Connect device using its node */
    connect_devnode(node);
}

static void connect_devnode(const char *node) {
    /* Check if the device is already connected */
    for (int i = 0; i < num_connected_devices; ++i) {
        if (strcmp(devices[i]->node, node) == 0) {
            ul_log(UL_LOG_LEVEL_WARNING, "Ignoring already connected input device %s", node);
            return;
        }
    }

    /* Double array size every time it's filled */
    if (num_connected_devices == num_devices) {
        /* Re-allocate array */
        struct input_device **tmp = realloc(devices, (2 * num_devices + 1) * sizeof(struct input_device *));
        if (!tmp) {
            ul_log(UL_LOG_LEVEL_ERROR, "Could not reallocate memory for input device array");
            return;
        }
        devices = tmp;

        /* Update size counter */
        num_devices = 2 * num_devices + 1;

        /* Fill empty space with zeros */
        lv_memzero(devices + num_connected_devices, (num_devices - num_connected_devices) * sizeof(struct input_device *));
    }

    /* Allocate memory for new input device and insert it */
    struct input_device *device = malloc(sizeof(struct input_device));
    lv_memzero(device, sizeof(struct input_device));
    devices[num_connected_devices] = device;

    /* Get pointers to driver state & indev driver */
    libinput_drv_state_t *drv_state = &(device->drv_state);
    lv_indev_drv_t *indev_drv = &(device->indev_drv);

    /* Copy the node path so that it can be used beyond the caller's scope */
    device->node = strdup(node);

    /* Initialise the driver state and obtain the libinput device */
    libinput_init_state(drv_state, device->node);
    struct libinput_device *device_libinput = drv_state->libinput_device;

    /* If libinput failed to connect the device, exit */
    if (!device_libinput) {
        ul_log(UL_LOG_LEVEL_WARNING, "Aborting connection of input device %s because libinput failed to connect it", node);
        disconnect_idx(num_connected_devices);
        return;
    }

    /* Obtain device capabilities */
    device->capability = libinput_query_capability(device_libinput);

    /* If the device doesn't have any supported capabilities, exit */
    if ((device->capability & allowed_capability) == LIBINPUT_CAPABILITY_NONE)  {
        ul_log(UL_LOG_LEVEL_WARNING, "Aborting connection of input device %s because it has no allowed capabilities", node);
        disconnect_idx(num_connected_devices);
        return;
    }

    /* Initialise indev driver */
    lv_indev_drv_init(indev_drv);
    indev_drv->read_cb = libinput_read_cb;
    indev_drv->user_data = drv_state;

    /* Set up indev driver type and related properties */
    switch (device->capability) {
        case LIBINPUT_CAPABILITY_KEYBOARD:
            indev_drv->type = LV_INDEV_TYPE_KEYPAD;
            break;
        case LIBINPUT_CAPABILITY_POINTER:
            indev_drv->type = LV_INDEV_TYPE_POINTER;
            indev_drv->long_press_repeat_time = USHRT_MAX;
            break;
        case LIBINPUT_CAPABILITY_TOUCH:
            indev_drv->type = LV_INDEV_TYPE_POINTER;
            indev_drv->long_press_repeat_time = USHRT_MAX;
            break;
        default:
            break;
    }

    /* Register indev */
    device->indev = lv_indev_drv_register(indev_drv);

    /* Set the input group for keyboard devices */
    if (is_keyboard_device(device)) {
        set_keyboard_input_group(device);
    }

    /* Set the mouse cursor for pointer devices */
    if (is_pointer_device(device)) {
        set_mouse_cursor(device);
    }

    /* Increment connected device count */
    num_connected_devices++;

    ul_log(UL_LOG_LEVEL_VERBOSE, "Connected input device %s (%s)", node, capability_to_str(device->capability));
}

static void disconnect_udev_device(struct udev_device *device) {
    /* Obtain and verify device node */
    const char *node = udev_device_get_devnode(device);
    if (!node || strncmp(node, INPUT_DEVICE_NODE_PREFIX, strlen(INPUT_DEVICE_NODE_PREFIX)) != 0) {
        ul_log(UL_LOG_LEVEL_VERBOSE, "Ignoring unsupported input device %s", udev_device_get_syspath(device));
        return;
    }

    /* Disconnect device using its node */
    disconnect_devnode(node);
}

static void disconnect_devnode(const char *node) {
    /* Find connected device matching the specified node */
    int idx = -1;
    for (int i = 0; i < num_connected_devices; ++i) {
        if (strcmp(devices[i]->node, node) == 0) {
            idx = i;
            break;
        }
    }

    /* If no matching device was found, exit */
    if (idx < 0) {
        ul_log(UL_LOG_LEVEL_WARNING, "Ignoring already disconnected input device %s", node);
        return;
    }

    /* Disconnect device using its index */
    disconnect_idx(idx);

    /* Shift subsequent devices forward */
    for (int i = idx + 1; i < num_connected_devices; ++i) {
        devices[i - 1] = devices[i];

        /* Zero out the last element after shifting it forward */
        if (i == num_connected_devices - 1) {
            lv_memzero(devices + i, sizeof(struct input_device *));
        }
    }
    
    /* Decrement connected device count */
    --num_connected_devices;

    ul_log(UL_LOG_LEVEL_VERBOSE, "Disconnected input device %s", node);
}

static void disconnect_idx(int idx) {
    /* Delete LVGL indev */
    if (devices[idx]->indev) {
        lv_indev_delete(devices[idx]->indev);
    }

    /* Free previously copied node path */
    if (devices[idx]->node) {
        free(devices[idx]->node);
    }

    /* De-initialise driver state */
    libinput_deinit_state(&(devices[idx]->drv_state));

    /* Deallocate memory and zero out freed array element */
    free(devices[idx]);
    lv_memzero(devices + idx, sizeof(struct input_device *));
}

static void libinput_read_cb(lv_indev_drv_t *indev_drv, lv_indev_data_t *data) {
    libinput_read_state(indev_drv->user_data, indev_drv, data);
}

static void set_keyboard_input_group(struct input_device *device) {
    /* Ignore non-keyboard devices */
    if (!is_keyboard_device(device)) {
        return;
    }

    /* Apply the input group */
    lv_indev_set_group(device->indev, keyboard_input_group);
}

static void set_mouse_cursor(struct input_device *device) {
    /* Ignore non-pointer devices */
    if (!is_pointer_device(device)) {
        return;
    }

    /* Initialise cursor image if needed */
    if (!cursor_obj) {
        cursor_obj = lv_img_create(lv_scr_act());
        lv_img_set_src(cursor_obj, &ul_cursor_img_dsc);
    }

    /* Apply the cursor image */
    lv_indev_set_cursor(device->indev, cursor_obj);
}


/**
 * Public functions
 */

void ul_indev_set_allowed_device_capability(bool keyboard, bool pointer, bool touchscreen) {
    allowed_capability = LIBINPUT_CAPABILITY_NONE;
    if (keyboard) {
        allowed_capability |= LIBINPUT_CAPABILITY_KEYBOARD;
    }
    if (pointer) {
        allowed_capability |= LIBINPUT_CAPABILITY_POINTER;
    }
    if (touchscreen) {
        allowed_capability |= LIBINPUT_CAPABILITY_TOUCH;
    }
}

void ul_indev_set_keyboard_input_group(lv_group_t *group) {
    /* Store the group */
    keyboard_input_group = group;

    /* Apply the group on all connected keyboard devices */
    for (int i = 0; i < num_connected_devices; ++i) {
        if (is_keyboard_device(devices[i])) {
            set_keyboard_input_group(devices[i]);
        }
    }
}

void ul_indev_auto_connect() {
    ul_log(UL_LOG_LEVEL_VERBOSE, "Auto-connecting supported input devices");

    /* Make sure udev context is initialised */
    if (!context) {
        context = udev_new();
        if (!context) {
            ul_log(UL_LOG_LEVEL_WARNING, "Could not create udev context");
            return;
        }
    }

    /* Scan for available input devices */
    struct udev_enumerate *enumerate = udev_enumerate_new(context);
    udev_enumerate_add_match_subsystem(enumerate, "input");
    udev_enumerate_scan_devices(enumerate);

    /* Prepare for enumerating found devices */
    struct udev_list_entry *first_entry = udev_enumerate_get_list_entry(enumerate);
    struct udev_list_entry *entry;

    udev_list_entry_foreach(entry, first_entry) {
        /* Obtain system path */
        const char *path = udev_list_entry_get_name(entry);

        /* Create udev device */
        struct udev_device *device = udev_device_new_from_syspath(context, path);
        if (!device) {
            ul_log(UL_LOG_LEVEL_WARNING, "Could not create udev device for %s", path);
            continue;
        }

        /* Connect device */
        connect_udev_device(device);

        /* Unreference udev device */
        udev_device_unref(device);
    }

    /* Unreference enumeration */
    udev_enumerate_unref(enumerate);
}

void ul_indev_start_monitor() {
    /* Make sure udev context is initialised */
    if (!context) {
        context = udev_new();
        if (!context) {
            ul_log(UL_LOG_LEVEL_WARNING, "Could not create udev context");
            return;
        }
    }

    /* Check if monitor is already running */
    if (monitor) {
        ul_log(UL_LOG_LEVEL_WARNING, "Not starting udev monitor because it is already running");
        return;
    }

    /* Create new monitor */
    monitor = udev_monitor_new_from_netlink(context, "udev");
    if (!monitor) {
        ul_log(UL_LOG_LEVEL_WARNING, "Could not create udev monitor");
        ul_indev_stop_monitor();
        return;
    }

    /* Apply input subsystem filter */
    if (udev_monitor_filter_add_match_subsystem_devtype(monitor, "input", NULL) < 0) {
        ul_log(UL_LOG_LEVEL_WARNING, "Could not add input subsystem filter for udev monitor");
    }

    /* Start monitor */
    if (udev_monitor_enable_receiving(monitor) < 0) {
        ul_log(UL_LOG_LEVEL_WARNING, "Could not enable udev monitor");
        ul_indev_stop_monitor();
        return;
    }

    /* Obtain monitor file descriptor */
    if ((monitor_fd = udev_monitor_get_fd(monitor)) < 0) {
        ul_log(UL_LOG_LEVEL_WARNING, "Could not acquire file descriptor for udev monitor");
        ul_indev_stop_monitor();
        return;
    }
}

void ul_indev_stop_monitor() {
    /* Unreference monitor */
    if (monitor) {
        udev_monitor_unref(monitor);
        monitor = NULL;
    }

    /* Reset monitor file descriptor */
    if (monitor_fd >= 0) {
        monitor_fd = -1;
    }

    /* Unreference udev context */
    if (context) {
        udev_unref(context);
        context = NULL;
    }
}

void ul_indev_query_monitor() {
    /* Make sure the monitor is running */
    if (!monitor) {
        ul_log(UL_LOG_LEVEL_ERROR, "Cannot query udev monitor because it is not running");
        return;
    }

    /* Prepare file descriptor set for reading */
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(monitor_fd, &fds);

    /* Set up timeval to not block when no updates are available */
    struct timeval tv = { .tv_sec = 0, .tv_usec = 0 };

    /* Read and process all updates */
    while (select(monitor_fd + 1, &fds, NULL, NULL, &tv) > 0 && FD_ISSET(monitor_fd, &fds)) {
        /* Obtain udev device */
        struct udev_device *device = udev_monitor_receive_device(monitor);
        if (!device) {
            continue;
        }

        /* Obtain action */
        const char *action = udev_device_get_action(device);

        /* Connect or disconnect the device */
        if (strcmp(action, "add") == 0) {
            connect_udev_device(device);
        } else if (strcmp(action, "remove") == 0) {
            disconnect_udev_device(device);
        }

        /* Unreference udev device */
        udev_device_unref(device);
    }
}

bool ul_indev_is_keyboard_connected() {
    for (int i = 0; i < num_connected_devices; ++i) {
        if (is_keyboard_device(devices[i])) {
            return true;
        }
    }
    return false;
}
