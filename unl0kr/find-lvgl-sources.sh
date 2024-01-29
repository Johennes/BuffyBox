#!/bin/sh

# Copyright 2022 Johannes Marbach, Oliver Smith
# SPDX-License-Identifier: GPL-3.0-or-later


find lvgl/src -name 'lv_init.c'
find lvgl/src/core -name '*.c'
find lvgl/src/dev -name '*.c'
find lvgl/src/display -name '*.c'
find lvgl/src/draw -name '*.c'
find lvgl/src/drivers -name '*.c'
find lvgl/src/extra -name '*.c'
find lvgl/src/extra/widgets/keyboard -name '*.c'
find lvgl/src/extra/widgets/msgbox -name '*.c'
find lvgl/src/extra/widgets/span -name '*.c'
find lvgl/src/indev -name '*.c'
find lvgl/src/font -name '*.c'
find lvgl/src/hal -name '*.c'
find lvgl/src/layouts -name '*.c'
find lvgl/src/libs -name '*.c'
find lvgl/src/misc -name '*.c'
find lvgl/src/osal -name '*.c'
find lvgl/src/stdlib -name '*.c'
find lvgl/src/tick -name '*.c'
find lvgl/src/themes -name '*.c'
find lvgl/src/widgets -name '*.c'
