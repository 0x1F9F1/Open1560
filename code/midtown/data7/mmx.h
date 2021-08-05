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
    data7:mmx

    0x57C400 | int __cdecl cpuid(void) | ?cpuid@@YAHXZ
    0x57C410 | public: __thiscall initHaveMMX::initHaveMMX(void) | ??0initHaveMMX@@QAE@XZ
    0x90B4A0 | int UseKNI | ?UseKNI@@3HA
    0x90B4A4 | int UseMMX | ?UseMMX@@3HA
    0x90B4A8 | int HavePPro | ?HavePPro@@3HA
    0x90B4AC | int HaveKNI | ?HaveKNI@@3HA
    0x90B4B0 | int HaveMMX | ?HaveMMX@@3HA
*/

// ?HaveKNI@@3HA
ARTS_EXPORT extern b32 HaveKNI;

// ?HaveMMX@@3HA
ARTS_EXPORT extern b32 HaveMMX;

// ?HavePPro@@3HA
ARTS_EXPORT extern b32 HavePPro;

// ?UseKNI@@3HA
ARTS_EXPORT extern b32 UseKNI;

// ?UseMMX@@3HA
ARTS_EXPORT extern b32 UseMMX;

struct initHaveMMX
{
public:
    // ??0initHaveMMX@@QAE@XZ | inline
    ARTS_EXPORT initHaveMMX();
};

check_size(initHaveMMX, 0x1);
