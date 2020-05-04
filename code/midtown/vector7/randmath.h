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
    vector7:randmath

    0x564A00 | int __cdecl irand(int) | ?irand@@YAHH@Z
    0x564A30 | int __cdecl irand(void) | ?irand@@YAHXZ
    0x564A70 | float __cdecl frand(void) | ?frand@@YAMXZ
    0x564A90 | float __cdecl frand(int) | ?frand@@YAMH@Z
    0x564AB0 | _rand
    0x564AC0 | _srand
    0x658A60 | int gRandSeed | ?gRandSeed@@3HA
    0x909448 | void (__cdecl* LogRandomCalls)(void) | ?LogRandomCalls@@3P6AXXZA
*/

// 0x564A70 | ?frand@@YAMXZ
f32 frand();

// 0x564A90 | ?frand@@YAMH@Z
f32 frand(i32 arg1);

// 0x564A30 | ?irand@@YAHXZ
i32 irand();

// 0x564A00 | ?irand@@YAHH@Z
i32 irand(i32 arg1);

// 0x909448 | ?LogRandomCalls@@3P6AXXZA
inline extern_var(0x509448_Offset, void (*)(void), LogRandomCalls);

// 0x564AB0 | _rand (Skipped: void)

// 0x564AC0 | _srand (Skipped: void)

// 0x658A60 | ?gRandSeed@@3HA
inline extern_var(0x258A60_Offset, i32, gRandSeed);
