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
    data7:b2f

    0x662478 | float * ByteToFloatTable | ?ByteToFloatTable@@3PAMA
*/

// 0x662478 | ?ByteToFloatTable@@3PAMA
extern const f32 ByteToFloatTable[256];

inline f32 b2f(u8 value)
{
    return ByteToFloatTable[value];
}

inline u32 f2u(f32 value)
{
    return mem::bit_cast<u32>(value);
}

inline u8 f2b(f32 value)
{
    return static_cast<u8>(f2u(value + 12582912.0f));
}
