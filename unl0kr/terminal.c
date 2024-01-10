/**
 * Copyright 2021 Johannes Marbach
 *
 * This file is part of buffybox, hereafter referred to as the program.
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


#include "terminal.h"

#include "log.h"

#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>

#include <linux/kd.h>

#include <sys/ioctl.h>


/**
 * Static variables
 */

static int current_fd = -1;

static int original_mode = -1;
static int original_kb_mode = -1;


/**
 * Static prototypes
 */

/**
 * Close the current file descriptor and reopen /dev/tty0.
 * 
 * @return true if opening was successful, false otherwise
 */
static bool reopen_current_terminal(void);

/**
 * Close the current file descriptor.
 */
static void close_current_terminal(void);


/**
 * Static functions
 */

static bool reopen_current_terminal(void) {
    close_current_terminal();

    current_fd = open("/dev/tty0", O_RDWR);
	if (current_fd < 0) {
        ul_log(UL_LOG_LEVEL_WARNING, "Could not open /dev/tty0");
		return false;
	}

    return true;
}

static void close_current_terminal(void) {
    if (current_fd < 0) {
        return;
    }

    close(current_fd);
    current_fd = -1;
}


/**
 * Public functions
 */

void ul_terminal_prepare_current_terminal(bool enable_graphics_mode, bool disable_keyboard_input) {
    /* Exit early if there is nothing to do */
    if (!enable_graphics_mode && !disable_keyboard_input) {
        return;
    }

    /* Reopen the current terminal */
    reopen_current_terminal();

    if (current_fd < 0) {
        ul_log(UL_LOG_LEVEL_WARNING, "Could not prepare current terminal");
        return;
    }

    /* Disable terminal keyboard input (hides entered text) */
    if (disable_keyboard_input) {
        if (ioctl(current_fd, KDGKBMODE, &original_kb_mode) != 0) {
            ul_log(UL_LOG_LEVEL_WARNING, "Could not get terminal keyboard mode");
        }

        if (ioctl(current_fd, KDSKBMODE, K_OFF) != 0) {
            ul_log(UL_LOG_LEVEL_WARNING, "Could not set terminal keyboard mode to off");
        }
    }

    /* Switch terminal into graphics mode (hides command prompt) */
    if (enable_graphics_mode) {
        if (ioctl(current_fd, KDGETMODE, &original_mode) != 0) {
            ul_log(UL_LOG_LEVEL_WARNING, "Could not get terminal mode");
        }

        if (ioctl(current_fd, KDSETMODE, KD_GRAPHICS) != 0) {
            ul_log(UL_LOG_LEVEL_WARNING, "Could not set terminal mode to graphics");
        }
    }
}

void ul_terminal_reset_current_terminal(void) {
    /* If we haven't previously opened the current terminal, exit */
    if (current_fd < 0) {
        ul_log(UL_LOG_LEVEL_WARNING, "Could not reset current terminal");
        return;
    }

    /* Reset terminal mode if needed */
    if (original_mode >= 0 && ioctl(current_fd, KDSETMODE, original_mode) != 0) {
        ul_log(UL_LOG_LEVEL_WARNING, "Could not reset terminal mode");
    }

    /* Reset terminal keyboard mode if needed */
    if (original_kb_mode >= 0 && ioctl(current_fd, KDSKBMODE, original_kb_mode) != 0) {
        ul_log(UL_LOG_LEVEL_WARNING, "Could not reset terminal keyboard mode");
    }

    close_current_terminal();
}
