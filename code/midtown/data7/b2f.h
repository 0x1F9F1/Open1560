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

// Use the original but slower float conversion functions
#define ARTS_USE_ORIG_B2F

ARTS_FORCEINLINE f32 ByteToFloat(u8 value) noexcept
{
#ifdef ARTS_USE_ORIG_B2F
    return ByteToFloatTable[value];
#else
    return static_cast<f32>(value);
#endif
}

ARTS_FORCEINLINE u8 FloatToByte(f32 value) noexcept
{
#ifdef ARTS_USE_ORIG_B2F
    return static_cast<u8>(mem::bit_cast<u32>(value + 12582912.0f));
#else
    return static_cast<u8>(value);
#endif
}
