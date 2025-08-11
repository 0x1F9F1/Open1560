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

class Vector3
{
public:
    constexpr inline Vector3() noexcept = default;

    // ??0Vector3@@QAE@MMM@Z | inline
    ARTS_EXPORT constexpr inline Vector3(f32 x, f32 y, f32 z) noexcept
        : x(x)
        , y(y)
        , z(z)
    {}

    // ??LVector3@@QBE?AV0@ABV0@@Z | inline
    ARTS_EXPORT inline Vector3 operator%(const Vector3& other) const
    {
        Vector3 result;
        result.Cross(*this, other);
        return result;
    }

    // ??DVector3@@QBE?AV0@M@Z | inline
    ARTS_EXPORT inline Vector3 operator*(f32 value) const
    {
        return {x * value, y * value, z * value};
    }

    // ??XVector3@@QAEXM@Z | inline
    ARTS_EXPORT inline void operator*=(f32 value)
    {
        *this = {x * value, y * value, z * value};
    }

    // ??HVector3@@QBE?AV0@ABV0@@Z | inline
    ARTS_EXPORT inline Vector3 operator+(const Vector3& other) const
    {
        return {x + other.x, y + other.y, z + other.z};
    }

    // ??YVector3@@QAEXABV0@@Z | inline
    ARTS_EXPORT inline void operator+=(const Vector3& other)
    {
        *this = {x + other.x, y + other.y, z + other.z};
    }

    // ??GVector3@@QBE?AV0@XZ | inline
    ARTS_EXPORT inline Vector3 operator-() const
    {
        return {-x, -y, -z};
    }

    // ??GVector3@@QBE?AV0@ABV0@@Z | inline
    ARTS_EXPORT inline Vector3 operator-(const Vector3& other) const
    {
        return {x - other.x, y - other.y, z - other.z};
    }

    // ??ZVector3@@QAEXABV0@@Z | inline
    ARTS_EXPORT inline void operator-=(const Vector3& other)
    {
        *this = {x - other.x, y - other.y, z - other.z};
    }

    // ??KVector3@@QBE?AV0@M@Z | inline
    ARTS_EXPORT inline Vector3 operator/(f32 value) const
    {
        value = 1.0f / value;
        return {x * value, y * value, z * value};
    }

    // Dot Product
    // ??TVector3@@QBE?AV0@ABVMatrix34@@@Z | inline
    ARTS_EXPORT inline Vector3 operator^(const Matrix34& other) const
    {
        Vector3 result;
        result.Dot(*this, other);
        return result;
    }

    // Dot Product
    // ??TVector3@@QBEMABV0@@Z | inline
    ARTS_EXPORT inline f32 operator^(const Vector3& other) const
    {
        return (x * other.x) + (y * other.y) + (z * other.z);
    }

    // ??SVector3@@QBE?AV0@XZ | inline
    ARTS_EXPORT inline Vector3 operator~() const
    {
        return *this * InvMag();
    }

    // ?Add@Vector3@@QAEXABV1@0@Z | inline
    ARTS_EXPORT inline void Add(const Vector3& lhs, const Vector3& rhs)
    {
        *this = lhs + rhs;
    }

    // ?Angle@Vector3@@QBEMABV1@@Z
    ARTS_IMPORT f32 Angle(const Vector3& arg1) const;

    // ?Approach@Vector3@@QAEHABV1@MMPAM@Z
    ARTS_IMPORT i32 Approach(const Vector3& arg1, f32 arg2, f32 arg3, f32* arg4);

    // ?Area@Vector3@@QBEMABV1@0@Z
    ARTS_IMPORT f32 Area(const Vector3& arg1, const Vector3& arg2) const;

    // ?Bilinear@Vector3@@QAEXMMABV1@000@Z | unused
    ARTS_IMPORT void Bilinear(
        f32 arg1, f32 arg2, const Vector3& arg3, const Vector3& arg4, const Vector3& arg5, const Vector3& arg6);

    // ?CatmullRom@Vector3@@QAEXMABV1@000@Z | unused
    ARTS_IMPORT void CatmullRom(
        f32 arg1, const Vector3& arg2, const Vector3& arg3, const Vector3& arg4, const Vector3& arg5);

    // ?Cross@Vector3@@QAEXABV1@0@Z | inline
    ARTS_EXPORT inline void Cross(const Vector3& lhs, const Vector3& rhs)
    {
        *this = {lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x};
    }

    // ?Dist@Vector3@@QBEMABV1@@Z
    ARTS_IMPORT f32 Dist(const Vector3& arg1) const;

    // ?Dot@Vector3@@QAIXABV1@ABVMatrix34@@@Z
    ARTS_EXPORT void ARTS_FASTCALL Dot(const Vector3& vec, const Matrix34& mat);

    // ?Dot3x3@Vector3@@QAIXABV1@ABVMatrix34@@@Z
    ARTS_EXPORT void ARTS_FASTCALL Dot3x3(const Vector3& vec, const Matrix34& mat);

    // ?Equal@Vector3@@QBEIABV1@M@Z
    ARTS_IMPORT u32 Equal(const Vector3& arg1, f32 arg2) const;

    // ?GetPolar@Vector3@@QBEXABV1@PAVVector4@@PAV1@@Z
    ARTS_IMPORT void GetPolar(const Vector3& arg1, Vector4* arg2, Vector3* arg3) const;

    // ?Hermite@Vector3@@QAEXMABV1@000M@Z | unused
    ARTS_IMPORT void Hermite(
        f32 arg1, const Vector3& arg2, const Vector3& arg3, const Vector3& arg4, const Vector3& arg5, f32 arg6);

    // ?InvMag@Vector3@@QBEMXZ
    ARTS_IMPORT f32 InvMag() const;

    // ?Mag@Vector3@@QBEMXZ
    ARTS_IMPORT f32 Mag() const;

    // ?Neg@Vector3@@QAEXABV1@@Z | inline
    ARTS_IMPORT void Neg(const Vector3& arg1);

    // ?PointToSegment2@Vector3@@QBEMABV1@0AAV1@AAHPAM@Z | unused
    ARTS_IMPORT f32 PointToSegment2(
        const Vector3& arg1, const Vector3& arg2, Vector3& arg3, i32& arg4, f32* arg5) const;

    // ?Rotate@Vector3@@QAEXMH@Z
    ARTS_IMPORT void Rotate(f32 arg1, i32 arg2);

    // ?Scale@Vector3@@QAEXABV1@M@Z | inline
    ARTS_IMPORT void Scale(const Vector3& arg1, f32 arg2);

    // ?Set@Vector3@@QAEXMMM@Z | inline
    ARTS_EXPORT void Set(f32 x_, f32 y_, f32 z_)
    {
        x = x_;
        y = y_;
        z = z_;
    }

    inline f32 Mag2() const
    {
        return (x * x) + (y * y) + (z * z);
    }

    inline f32 Dist2(const Vector3& other) const
    {
        return (*this - other).Mag2();
    }

    constexpr inline bool operator==(const Vector3& other) const
    {
        return (x == other.x) && (y == other.y) && (z == other.z);
    }

    constexpr inline bool operator!=(const Vector3& other) const
    {
        return (x != other.x) || (y != other.y) || (z != other.z);
    }

    operator Vector4() const;

    f32 x {};
    f32 y {};
    f32 z {};
};

check_size(Vector3, 0xC);

inline Vector3 operator/(f32 lhs, const Vector3& rhs)
{
    return {lhs / rhs.x, lhs / rhs.y, lhs / rhs.z};
}

// ?TransformVertList@@YAXPAVVector3@@PBV1@HABVMatrix34@@@Z
ARTS_IMPORT void TransformVertList(Vector3* arg1, const Vector3* arg2, i32 arg3, const Matrix34& arg4);

// ?TransformVertNorm@@YAXAAVVector3@@0ABV1@0ABVMatrix34@@@Z | unused
ARTS_IMPORT void TransformVertNorm(
    Vector3& arg1, Vector3& arg2, const Vector3& arg3, Vector3& arg4, const Matrix34& arg5);

// ?ORIGIN@@3VVector3@@A
ARTS_IMPORT extern Vector3 ORIGIN;

// ?XAXIS@@3VVector3@@A
ARTS_IMPORT extern Vector3 XAXIS;

// ?YAXIS@@3VVector3@@A
ARTS_IMPORT extern Vector3 YAXIS;

// ?ZAXIS@@3VVector3@@A
ARTS_IMPORT extern Vector3 ZAXIS;

template <>
const MetaType* CreateMetaType_<Vector3>();

template <>
ARTS_FORCEINLINE Vector3 ByteSwap<Vector3>(Vector3 value) noexcept
{
    ByteSwapV(value.x, value.y, value.z);
    return value;
}
