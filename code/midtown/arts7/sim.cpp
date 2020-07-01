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

define_dummy_symbol(arts7_sim);

#include "sim.h"

void InitBank(i32 /*arg1*/, char** /*arg2*/)
{}

// 0x523510 | ?IsValidPointer@@YAHPAXIH@Z
ARTS_IMPORT /*static*/ i32 IsValidPointer(void* arg1, u32 arg2, i32 arg3);

// 0x521C20 | ?QuietPrinter@@YAXHPBDPAD@Z
ARTS_IMPORT /*static*/ void QuietPrinter(i32 arg1, char const* arg2, char* arg3);
