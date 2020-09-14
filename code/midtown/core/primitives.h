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

#include <cstddef>
#include <cstdint>

#ifdef ARTS_STANDALONE
using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using b32 = bool;
#else
using i8 = char;
using i16 = short;
using i32 = int;
using i64 = long long;

using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;

using b16 = i16;
using b32 = i32;
#endif

using i8fast = std::int_fast8_t;
using i16fast = std::int_fast16_t;
using i32fast = std::int_fast32_t;
using i64fast = std::int_fast64_t;

using u8fast = std::uint_fast8_t;
using u16fast = std::uint_fast16_t;
using u32fast = std::uint_fast32_t;
using u64fast = std::uint_fast64_t;

using f32 = float;
using f64 = double;

using usize = std::size_t;
using isize = std::ptrdiff_t;

using ilong = signed long;
using ulong = unsigned long;

#define _ARTS_LITERAL(NAME, IN_TYPE, OUT_TYPE)                              \
    ARTS_FORCEINLINE constexpr OUT_TYPE operator"" NAME(IN_TYPE n) noexcept \
    {                                                                       \
        return static_cast<OUT_TYPE>(n);                                    \
    }

_ARTS_LITERAL(_i8, unsigned long long int, i8);
_ARTS_LITERAL(_i16, unsigned long long int, i16);
_ARTS_LITERAL(_i32, unsigned long long int, i32);
_ARTS_LITERAL(_i64, unsigned long long int, i64);

_ARTS_LITERAL(_u8, unsigned long long int, u8);
_ARTS_LITERAL(_u16, unsigned long long int, u16);
_ARTS_LITERAL(_u32, unsigned long long int, u32);
_ARTS_LITERAL(_u64, unsigned long long int, u64);

_ARTS_LITERAL(_f32, long double, f32);
_ARTS_LITERAL(_f64, long double, f64);

_ARTS_LITERAL(_isize, unsigned long long int, isize);
_ARTS_LITERAL(_usize, unsigned long long int, usize);

#undef _ARTS_LITERAL
