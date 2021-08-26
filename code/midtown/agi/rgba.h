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

#include "core/endian.h"

struct agiRgba
{
    u8 R {};
    u8 G {};
    u8 B {};
    u8 A {};

    ARTS_FORCEINLINE u32 ToABGR() const
    {
        // NOTE: Assume little endian
        return mem::bit_cast<u32>(*this);
    }

    ARTS_FORCEINLINE u32 ToRGBA() const
    {
        return ByteSwap(ToABGR()); // ABGR -> RGBA
    }

    ARTS_FORCEINLINE u32 ToARGB() const
    {
        u32 result = ToRGBA();
        return (result >> 8) | (result << 24); // RGBA -> ARGB
    }

    ARTS_FORCEINLINE static agiRgba FromABGR(u32 color)
    {
        // NOTE: Assume little endian
        return mem::bit_cast<agiRgba>(color);
    }

    ARTS_FORCEINLINE static agiRgba FromRGBA(u32 color)
    {
        return FromABGR(ByteSwap(color)); // RGBA -> ABGR
    }

    ARTS_FORCEINLINE static agiRgba FromARGB(u32 color)
    {
        color = (color << 8) | (color >> 24); // ARGB -> RGBA
        return FromRGBA(color);
    }
};

check_size(agiRgba, 0x4);
