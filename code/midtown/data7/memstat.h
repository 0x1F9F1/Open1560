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
    data7:memstat

    0x578B20 | void __cdecl BeginMemStat(char const *) | ?BeginMemStat@@YAXPBD@Z
    0x578BB0 | void __cdecl EndMemStat(void) | ?EndMemStat@@YAXXZ
    0x6620A8 | int EnableMemStat | ?EnableMemStat@@3HA
    0x90AEA8 | int beginStackCount | ?beginStackCount@@3HA
*/

// 0x578B20 | ?BeginMemStat@@YAXPBD@Z
void BeginMemStat(char const* arg1);

// 0x578BB0 | ?EndMemStat@@YAXXZ
void EndMemStat();

// 0x6620A8 | ?EnableMemStat@@3HA
inline extern_var(0x6620A8, i32, EnableMemStat);

// 0x90AEA8 | ?beginStackCount@@3HA
inline extern_var(0x90AEA8, i32, beginStackCount);
