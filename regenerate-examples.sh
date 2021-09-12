#!/bin/bash

# Copyright 2021 Johannes Marbach
#
# This file is part of squeek2lvgl, hereafter referred to as the program.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <https://www.gnu.org/licenses/>.

pipenv install

pipenv run python squeek2lvgl.py \
    --input us.yaml \
    --output examples/us \
    --surround-space-with-arrows

pipenv run python squeek2lvgl.py \
    --input terminal/us.yaml \
    --output examples/us-terminal-with-scancodes \
    --generate-scancodes
