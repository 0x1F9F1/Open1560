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

#ifdef _MSC_VER
#    include <stdlib.h>
#endif

template <typename... Args>
ARTS_FORCEINLINE void ByteSwap(Args&... args) noexcept;

template <typename... Args>
ARTS_FORCEINLINE void ByteSwap(Args&... args) noexcept
{
    (ByteSwap<Args>(args), ...);
}

// TODO: Add i8, i16, i32, i64, f32, f64

template <>
ARTS_FORCEINLINE void ByteSwap<u8>(u8&) noexcept
{}

template <>
ARTS_FORCEINLINE void ByteSwap<u16>(u16& value) noexcept
{
#ifdef _MSC_VER
    value = _byteswap_ushort(value);
#else
    value = (value >> 8) | (value << 8);
#endif
}

template <>
ARTS_FORCEINLINE void ByteSwap<u32>(u32& value) noexcept
{
#ifdef _MSC_VER
    value = _byteswap_ulong(value);
#else
    value = (value << 24) | ((value & 0x0000FF00) << 8) | ((value & 0x00FF0000) >> 8) | (value >> 24);
#endif
}

template <>
ARTS_FORCEINLINE void ByteSwap<u64>(u64& value) noexcept
{
#ifdef _MSC_VER
    value = _byteswap_uint64(value);
#else
    value = (value >> 56) | ((value & 0x00FF000000000000) << 40) | ((value & 0x0000FF0000000000) << 24) |
        ((value & 0x000000FF00000000) << 8) | ((value & 0x00000000FF000000) >> 8) |
        ((value & 0x0000000000FF0000) >> 24) | ((value & 0x000000000000FF00) >> 40) | (value << 56);
#endif
}
