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

#include "vector4.h"

class Matrix44
{
public:
    constexpr inline Matrix44() noexcept = default;

    constexpr inline Matrix44(Vector4 m0, Vector4 m1, Vector4 m2, Vector4 m3) noexcept
        : m0(m0)
        , m1(m1)
        , m2(m2)
        , m3(m3)
    {}

    // ??0Matrix44@@QAE@ABVMatrix34@@@Z
    ARTS_IMPORT Matrix44(const Matrix34& arg1);

    // ??0Matrix44@@QAE@ABV0@@Z | inline
    ARTS_IMPORT Matrix44(const Matrix44& arg1);

    // ??TMatrix44@@QBE?AV0@ABV0@@Z
    ARTS_IMPORT Matrix44 operator^(const Matrix44& arg1) const;

    // ??TMatrix44@@QBE?AVVector4@@ABV1@@Z
    ARTS_IMPORT Vector4 operator^(const Vector4& arg1) const;

    // ?Determinant@Matrix44@@QBEMXZ
    ARTS_IMPORT f32 Determinant() const;

    // ?Dot@Matrix44@@QAEXABV1@0@Z
    ARTS_EXPORT void Dot(const Matrix44& lhs, const Matrix44& rhs);

    // ?FromQuaternion@Matrix44@@QAEXABVQuaternion@@@Z
    ARTS_IMPORT void FromQuaternion(const Quaternion& arg1);

    // ?Identity@Matrix44@@QAEXXZ
    ARTS_IMPORT void Identity();

    // ?Rotate@Matrix44@@QAEXABVVector3@@0@Z
    ARTS_IMPORT void Rotate(const Vector3& arg1, const Vector3& arg2);

    // ?Scale@Matrix44@@QAEXMMM@Z
    ARTS_IMPORT void Scale(f32 arg1, f32 arg2, f32 arg3);

    // ?Transpose@Matrix44@@QBE?AV1@XZ
    ARTS_IMPORT Matrix44 Transpose() const;

    Vector4 m0; // Left
    Vector4 m1; // Up
    Vector4 m2; // Forward
    Vector4 m3; // Translation
};

check_size(Matrix44, 0x40);

// ??T@YA?AVVector4@@ABV0@ABVMatrix44@@@Z
inline Vector4 operator^(const Vector4& lhs, const Matrix44& rhs)
{
    return (rhs.m0 * lhs.x) + (rhs.m1 * lhs.y) + (rhs.m2 * lhs.z) + (rhs.m3 * lhs.w);
}

// ?BezierBasis@@3VMatrix44@@A
ARTS_IMPORT extern Matrix44 BezierBasis;

// ?BezierTranspose@@3VMatrix44@@A
ARTS_IMPORT extern Matrix44 BezierTranspose;

// ?HermiteBasis@@3VMatrix44@@A
ARTS_IMPORT extern Matrix44 HermiteBasis;

// ?HermiteTranspose@@3VMatrix44@@A
ARTS_IMPORT extern Matrix44 HermiteTranspose;

// ?Identity@@3VMatrix44@@A
ARTS_IMPORT extern Matrix44 Identity;

// ?bb@@3PAMA
ARTS_IMPORT extern f32 bb[16];

// ?bt@@3PAMA
ARTS_IMPORT extern f32 bt[16];

// ?hb@@3PAMA
ARTS_IMPORT extern f32 hb[16];

// ?ht@@3PAMA
ARTS_IMPORT extern f32 ht[16];

// ?id@@3PAMA
ARTS_IMPORT extern f32 id[16];
