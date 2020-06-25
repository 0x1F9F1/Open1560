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

#pragma once

/*
    data7:perfstat

    0x57B410 | void __cdecl PerfInit(void) | ?PerfInit@@YAXXZ
    0x57B450 | void __cdecl PerfShutdown(void) | ?PerfShutdown@@YAXXZ
    0x57B470 | int __cdecl PerfLookup(char *) | ?PerfLookup@@YAHPAD@Z
    0x57B530 | unsigned int __cdecl PerfGetValue(int) | ?PerfGetValue@@YAIH@Z
*/

// 0x57B530 | ?PerfGetValue@@YAIH@Z
ARTS_IMPORT u32 PerfGetValue(i32 arg1);

// 0x57B410 | ?PerfInit@@YAXXZ | unused
ARTS_IMPORT void PerfInit();

// 0x57B470 | ?PerfLookup@@YAHPAD@Z | unused
ARTS_IMPORT i32 PerfLookup(char* arg1);

// 0x57B450 | ?PerfShutdown@@YAXXZ | unused
ARTS_IMPORT void PerfShutdown();
