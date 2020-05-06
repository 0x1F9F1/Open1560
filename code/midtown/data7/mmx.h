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

    0x57C410 | public: __thiscall initHaveMMX::initHaveMMX(void) | ??0initHaveMMX@@QAE@XZ
    0x90B4A0 | int UseKNI | ?UseKNI@@3HA
    0x90B4A4 | int UseMMX | ?UseMMX@@3HA
    0x90B4A8 | int HavePPro | ?HavePPro@@3HA
    0x90B4AC | int HaveKNI | ?HaveKNI@@3HA
    0x90B4B0 | int HaveMMX | ?HaveMMX@@3HA
*/

struct initHaveMMX
{
public:
    // 0x57C410 | ??0initHaveMMX@@QAE@XZ
    initHaveMMX();
};

check_size(initHaveMMX, 0x0);

// 0x90B4AC | ?HaveKNI@@3HA
inline extern_var(0x90B4AC, i32, HaveKNI);

// 0x90B4B0 | ?HaveMMX@@3HA
inline extern_var(0x90B4B0, i32, HaveMMX);

// 0x90B4A8 | ?HavePPro@@3HA
inline extern_var(0x90B4A8, i32, HavePPro);

// 0x90B4A0 | ?UseKNI@@3HA
inline extern_var(0x90B4A0, i32, UseKNI);

// 0x90B4A4 | ?UseMMX@@3HA
inline extern_var(0x90B4A4, i32, UseMMX);
