/**
 * Copyright 2021 Johannes Marbach
 *
 * This file is part of buffyboard, hereafter referred to as the program.
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


#ifndef BB_BUFFYBOARD_H
#define BB_BUFFYBOARD_H

#include "lvgl/lvgl.h"

#ifndef BB_VERSION
#define BB_VERSION "?" /* Just to silence IDE warning. Real version injected by meson during build. */
#endif

/**
 * Fonts
 */

LV_FONT_DECLARE(font_32);

#endif /* BB_BUFFYBOARD_H */