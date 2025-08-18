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

#include "data7/metatype.h"

#ifdef ARTS_ENABLE_KNI
#    include <xmmintrin.h>
#endif

class Vector4
{
public:
    constexpr inline Vector4() noexcept = default;

    constexpr inline Vector4(f32 x, f32 y, f32 z, f32 w) noexcept
        : x(x)
        , y(y)
        , z(z)
        , w(w)
    {}

#ifdef ARTS_ENABLE_KNI
    inline Vector4(__m128 xmm) noexcept
        : Vector4(mem::bit_cast<Vector4>(xmm))
    {}
#endif

    // ??7Vector4@@QBE?AV0@XZ
    ARTS_IMPORT Vector4 operator!() const;

    // ??TVector4@@QBEMABV0@@Z | inline
    ARTS_IMPORT f32 operator^(const Vector4& arg1) const;

    // ?Bilinear@Vector4@@QAEXMMABV1@000@Z | unused
    ARTS_IMPORT void Bilinear(
        f32 arg1, f32 arg2, const Vector4& arg3, const Vector4& arg4, const Vector4& arg5, const Vector4& arg6);

    // ?CalculatePlane@Vector4@@QAEXABVVector3@@00@Z
    ARTS_EXPORT void CalculatePlane(const Vector3& arg1, const Vector3& arg2, const Vector3& arg3);

    // ?Lerp@Vector4@@QAEXMABV1@0@Z
    ARTS_IMPORT void Lerp(f32 arg1, const Vector4& arg2, const Vector4& arg3);

    // ?Set@Vector4@@QAEXMMMM@Z | inline
    ARTS_EXPORT void Set(f32 x_, f32 y_, f32 z_, f32 w_)
    {
        x = x_;
        y = y_;
        z = z_;
        w = w_;
    }

#ifdef ARTS_ENABLE_KNI
    inline operator __m128() const
    {
        return mem::bit_cast<__m128>(*this);
    }
#endif

    inline Vector4 operator*(f32 value) const
    {
#ifdef ARTS_ENABLE_KNI
        return _mm_mul_ps(*this, _mm_set_ps1(value));
#else
        return {x * value, y * value, z * value, w * value};
#endif
    }

    inline void operator*=(f32 value)
    {
        *this = *this * value;
    }

    inline Vector4 operator+(const Vector4& other) const
    {
#ifdef ARTS_ENABLE_KNI
        return _mm_add_ps(*this, other);
#else
        return {x + other.x, y + other.y, z + other.z, w + other.w};
#endif
    }

    inline Vector4 operator-(const Vector4& other) const
    {
#ifdef ARTS_ENABLE_KNI
        return _mm_sub_ps(*this, other);
#else
        return {x - other.x, y - other.y, z - other.z, w - other.w};
#endif
    }

    constexpr inline bool operator==(const Vector4& other) const noexcept
    {
        return (x == other.x) && (y == other.y) && (z == other.z) && (w == other.w);
    }

    constexpr inline bool operator!=(const Vector4& other) const noexcept
    {
        return (x != other.x) || (y != other.y) || (z != other.z) || (w != other.w);
    }

    f32 x {};
    f32 y {};
    f32 z {};
    f32 w {};
};

check_size(Vector4, 0x10);

#if 0
struct Vector4Type final : MetaType
{
    public:
    // ?Delete@Vector4Type@@UAEXPAXH@Z
    ARTS_IMPORT void Delete(void* arg1, i32 arg2) override;

    // ?Load@Vector4Type@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Load(MiniParser* arg1, void* arg2) override;

    // ?New@Vector4Type@@UAEPAXH@Z
    ARTS_IMPORT void* New(i32 arg1) override;

    // ?Save@Vector4Type@@UAEXPAVMiniParser@@PAX@Z
    ARTS_IMPORT void Save(MiniParser* arg1, void* arg2) override;

    // ?SizeOf@Vector4Type@@UAEIXZ
    ARTS_IMPORT usize SizeOf() override;
};

check_size(Vector4Type, 0x4);

// ?Vector4Inst@@3UVector4Type@@A
ARTS_IMPORT extern Vector4Type Vector4Inst;
#endif
