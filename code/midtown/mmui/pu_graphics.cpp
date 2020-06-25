/*
    Open1560 - An Open Source Re-Implementation of Midtown Madness 1 Beta
    Copyright (C) 2020 Brick

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

define_dummy_symbol(mmui_pu_graphics);

#include "pu_graphics.h"

// 0x4A9EC0 | ?fix_lighting_lame@@YAXXZ
ARTS_IMPORT /*static*/ void fix_lighting_lame();

// 0x4A9E90 | ?toggle_filter@@YAXXZ
ARTS_IMPORT /*static*/ void toggle_filter();

// 0x4A9E70 | ?toggle_interlace@@YAXXZ
ARTS_IMPORT /*static*/ void toggle_interlace();
