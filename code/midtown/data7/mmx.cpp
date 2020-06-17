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

define_dummy_symbol(data7_mmx);

#include "mmx.h"

#include <intrin.h>

static i32 cpuid()
{
    int values[4];
    __cpuid(values, 1);
    return values[3];
}

initHaveMMX::initHaveMMX()
{
    i32 flags = cpuid();

    HavePPro = (flags >> 15) & 1;

    HaveMMX = (flags >> 23) & 1;
    UseMMX = HaveMMX;

    HaveKNI = (flags >> 25) & 1;
    UseKNI = HaveKNI;
}
