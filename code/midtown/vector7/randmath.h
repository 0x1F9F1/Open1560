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

// ?frand@@YAMXZ
ARTS_IMPORT f32 frand();

// ?irand@@YAHXZ
ARTS_IMPORT i32 irand();

// ?irand@@YAHH@Z
ARTS_IMPORT i32 irand(i32 seed);

// ?LogRandomCalls@@3P6AXXZA
ARTS_IMPORT extern void (*LogRandomCalls)(void);

// _rand | void

// _srand | void

// ?gRandSeed@@3HA
ARTS_IMPORT extern i32 gRandSeed;
