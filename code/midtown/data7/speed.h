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
    data7:speed

    0x57CE90 | unsigned int __cdecl __ComputeCpuSpeed(void) | ?__ComputeCpuSpeed@@YAIXZ
    0x57CF50 | unsigned int __cdecl ComputeCpuSpeed(void) | ?ComputeCpuSpeed@@YAIXZ
*/

// 0x57CF50 | ?ComputeCpuSpeed@@YAIXZ
u32 ComputeCpuSpeed();

// 0x57CE90 | ?__ComputeCpuSpeed@@YAIXZ
u32 __ComputeCpuSpeed();
