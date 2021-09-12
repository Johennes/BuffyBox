/**
 * Auto-generated with unsqu33kr
 **/

#include "sq2lv_layouts.h"

/**
 * Layout: US English - generated from us
 **/

static const char * const name_us = "us";

/* Layer: Lowercase letters - generated from base */

static const char * const keycaps_lower_us[] = { \
    "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "\n", \
    "a", "s", "d", "f", "g", "h", "j", "k", "l", "\n", \
    "ABC", "z", "x", "c", "v", "b", "n", "m", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_lower_us[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

/* Layer: Uppercase letters - generated from upper */

static const char * const keycaps_upper_us[] = { \
    "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "\n", \
    "A", "S", "D", "F", "G", "H", "J", "K", "L", "\n", \
    "abc", "Z", "X", "C", "V", "B", "N", "M", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_upper_us[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

/* Layer: Numbers / symbols - generated from numbers */

static const char * const keycaps_numbers_us[] = { \
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "\n", \
    "@", "#", "$", "%", "&", "-", "_", "+", "(", ")", "\n", \
    ",", "\"", "'", ":", ";", "!", "?", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_numbers_us[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

/**
 * Public interface
 **/

const sq2lv_layout_t sq2lv_layouts[] = {
    /* US English */
    {
        .layers = (sq2lv_layer_t[]){
            {
                .keycaps = keycaps_lower_us,
                .attributes = attributes_lower_us
            },
            {
                .keycaps = keycaps_upper_us,
                .attributes = attributes_upper_us
            },
            {
                .keycaps = keycaps_numbers_us,
                .attributes = attributes_numbers_us
            }
        },
        .num_layers = 3
    }
};

const int sq2lv_num_layouts = 1;

const char * const sq2lv_layout_names = 
    "US English";
