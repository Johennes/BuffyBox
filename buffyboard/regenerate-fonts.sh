#!/bin/sh -ex

# Copyright 2022 Johannes Marbach
# SPDX-License-Identifier: GPL-3.0-or-later


npx lv_font_conv --bpp 4 --size 32 --no-compress -o font_32.c --format lvgl \
    --font OpenSans-Regular.ttf \
      --range '0x0020-0x007F' \
      --range '0x00A0-0x00FF' \
      --range '0x0100-0x017F' \
      --range '0x0370-0x03FF' \
      --range '0x2000-0x206F' \
      --range '0x20A0-0x20CF' \
      --range '0x2200-0x22FF' \
    --font FontAwesome5-Solid+Brands+Regular.woff \
      --range '0xF001,0xF008,0xF00B,0xF00C,0xF00D,0xF011,0xF013,0xF015,0xF019,0xF01C,0xF021,0xF026,0xF027,0xF028,0xF03E,0xF0E0,0xF304,0xF043,0xF048,0xF04B,0xF04C,0xF04D,0xF051,0xF052,0xF053,0xF054,0xF067,0xF068,0xF06E,0xF070,0xF071,0xF074,0xF077,0xF078,0xF079,0xF07B,0xF093,0xF095,0xF0C4,0xF0C5,0xF0C7,0xF0C9,0xF0E7,0xF0EA,0xF0F3,0xF11C,0xF124,0xF158,0xF1EB,0xF240,0xF241,0xF242,0xF243,0xF244,0xF287,0xF293,0xF2ED,0xF55A,0xF7C2,0xF8A2' \
      --range '0xF042' \
      --range '0xF35B'

# Fix type qualifier for compatibility with LV_FONT_DECLARE
sed 's/^lv_font_t font_32/const lv_font_t font_32/g' font_32.c \
    > font_32.c.tmp
mv font_32.c.tmp font_32.c