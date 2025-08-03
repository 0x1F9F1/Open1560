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
#include "data7/metatype.h"

class Vector2
{
public:
    constexpr inline Vector2() noexcept = default;

    constexpr inline Vector2(f32 x, f32 y) noexcept
        : x(x)
        , y(y)
    {}

    inline Vector2 operator*(f32 value) const
    {
        return {x * value, y * value};
    }

    // ??SVector2@@QBE?AV0@XZ | unused
    inline Vector2 operator~() const
    {
        return *this * InvMag();
    }

    // ?InvMag@Vector2@@QBEMXZ
    ARTS_IMPORT f32 InvMag() const;

    // ?Mag@Vector2@@QBEMXZ
    ARTS_IMPORT f32 Mag() const;

    constexpr inline bool operator==(const Vector2& other) const noexcept
    {
        return (x == other.x) && (y == other.y);
    }

    constexpr inline bool operator!=(const Vector2& other) const noexcept
    {
        return (x != other.x) || (y != other.y);
    }

    f32 x {};
    f32 y {};
};

check_size(Vector2, 0x8);

#if 0
struct Vector2Type final : MetaType
{
    public:
    // ?Delete@Vector2Type@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // ?Load@Vector2Type@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(MiniParser* arg1, void* arg2) override;

    // ?New@Vector2Type@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // ?Save@Vector2Type@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(MiniParser* arg1, void* arg2) override;

    // ?SizeOf@Vector2Type@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;
};

check_size(Vector2Type, 0x4);

// ?Vector2Inst@@3UVector2Type@@A
ARTS_IMPORT extern Vector2Type Vector2Inst;
#endif

template <>
ARTS_FORCEINLINE Vector2 ByteSwap<Vector2>(Vector2 value) noexcept
{
    ByteSwapV(value.x, value.y);
    return value;
}
