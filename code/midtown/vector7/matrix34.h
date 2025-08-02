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

#include "data7/metadeclare.h"

#include "vector3.h"

class Matrix34
{
public:
    // ??0Matrix34@@QAE@XZ | inline
    constexpr inline Matrix34() noexcept = default;

    constexpr inline Matrix34(Vector3 m0, Vector3 m1, Vector3 m2, Vector3 m3) noexcept
        : m0(m0)
        , m1(m1)
        , m2(m2)
        , m3(m3)
    {}

    // ?Approach@Matrix34@@QAEHABV1@MMM@Z
    ARTS_IMPORT i32 Approach(const Matrix34& arg1, f32 arg2, f32 arg3, f32 arg4);

    // ?Dot@Matrix34@@QAEXABV1@0@Z
    ARTS_IMPORT void Dot(const Matrix34& arg1, const Matrix34& arg2);

    // ?Dot3x3@Matrix34@@QAEXABV1@0@Z
    ARTS_IMPORT void Dot3x3(const Matrix34& arg1, const Matrix34& arg2);

    // ?FastInverse@Matrix34@@QAEXABV1@@Z
    ARTS_IMPORT void FastInverse(const Matrix34& arg1);

    Matrix34 FastInverse() const
    {
        Matrix34 result;
        result.FastInverse(*this);
        return result;
    }

    // ?FromEulers@Matrix34@@QAEXABVVector3@@@Z
    ARTS_IMPORT void FromEulers(const Vector3& arg1);

    // ?FromEulers@Matrix34@@QAEXABVVector3@@PBD@Z
    ARTS_IMPORT void FromEulers(const Vector3& arg1, const char* arg2);

    // ?FromQuaternion@Matrix34@@QAEXABVQuaternion@@@Z
    ARTS_IMPORT void FromQuaternion(const Quaternion& arg1);

    // ?GetEulers@Matrix34@@QBE?AVVector3@@XZ
    ARTS_IMPORT Vector3 GetEulers() const;

    // ?GetEulers@Matrix34@@QBE?AVVector3@@PBD@Z
    ARTS_IMPORT Vector3 GetEulers(const char* arg1) const;

    // ?GetLookAt@Matrix34@@QBEXPAVVector3@@0M@Z
    ARTS_IMPORT void GetLookAt(Vector3* arg1, Vector3* arg2, f32 arg3) const;

    // ?GetPolar@Matrix34@@QBEXPAVVector4@@PAVVector3@@M@Z
    ARTS_IMPORT void GetPolar(Vector4* arg1, Vector3* arg2, f32 arg3) const;

    // ?Identity@Matrix34@@QAEXXZ
    ARTS_EXPORT constexpr void Identity();

    // ?Inverse@Matrix34@@QBE?AV1@XZ
    ARTS_IMPORT Matrix34 Inverse() const;

    // ?LookAt@Matrix34@@QAEXABVVector3@@0@Z
    ARTS_IMPORT void LookAt(const Vector3& arg1, const Vector3& arg2);

    // ?Normalize@Matrix34@@QAEXXZ
    ARTS_IMPORT void Normalize();

    // ?PolarView@Matrix34@@QAEXABVVector4@@@Z
    ARTS_IMPORT void PolarView(const Vector4& arg1);

    // ?PolarView@Matrix34@@QAEXMMMM@Z
    ARTS_IMPORT void PolarView(f32 offz, f32 roty, f32 rotx, f32 rotz);

    // ?RotEqual@Matrix34@@QBEIABV1@M@Z
    ARTS_IMPORT u32 RotEqual(const Matrix34& arg1, f32 arg2) const;

    // ?Rotate@Matrix34@@QAEXABVVector3@@M@Z
    ARTS_IMPORT void Rotate(const Vector3& arg1, f32 arg2);

    // ?RotateAbs@Matrix34@@QAEXABVVector3@@M@Z
    ARTS_IMPORT void RotateAbs(const Vector3& arg1, f32 arg2);

    // ?RotateFull@Matrix34@@QAEXABVVector3@@M@Z
    ARTS_IMPORT void RotateFull(const Vector3& arg1, f32 arg2);

    // ?RotateNoTrans@Matrix34@@QBE?AVVector3@@ABV2@@Z | inline
    ARTS_IMPORT Vector3 RotateNoTrans(const Vector3& arg1) const;

    // ?RotateTo@Matrix34@@QAEXABVVector3@@0M@Z
    ARTS_IMPORT void RotateTo(const Vector3& arg1, const Vector3& arg2, f32 arg3);

    // ?RotateToAbs@Matrix34@@QAEXABVVector3@@0M@Z
    ARTS_IMPORT void RotateToAbs(const Vector3& arg1, const Vector3& arg2, f32 arg3);

    // ?Scale@Matrix34@@QAEXM@Z
    ARTS_IMPORT void Scale(f32 arg1);

    // ?Scale@Matrix34@@QAEXMMM@Z
    ARTS_IMPORT void Scale(f32 arg1, f32 arg2, f32 arg3);

    // ?ScaleAbs@Matrix34@@QAEXMMM@Z
    ARTS_IMPORT void ScaleAbs(f32 arg1, f32 arg2, f32 arg3);

    // ?ScaleFullAbs@Matrix34@@QAEXMMM@Z
    ARTS_IMPORT void ScaleFullAbs(f32 arg1, f32 arg2, f32 arg3);

    // ?SolveSVD@Matrix34@@QBE?AVVector3@@ABV2@@Z
    ARTS_IMPORT Vector3 SolveSVD(const Vector3& arg1) const;

    // ?Transpose@Matrix34@@QBE?AV1@XZ | inline
    ARTS_IMPORT Matrix34 Transpose() const;

    // ?Transpose@Matrix34@@QAEXABV1@@Z
    ARTS_IMPORT void Transpose(const Matrix34& arg1);

    Vector3 m0; // a/Left
    Vector3 m1; // b/Up
    Vector3 m2; // c/Forward
    Vector3 m3; // d/Translation

    STATIC_META_DECLARE;

private:
    // ?ArbitraryRotation@Matrix34@@AAEXABVVector3@@M@Z
    ARTS_IMPORT void ArbitraryRotation(const Vector3& arg1, f32 arg2);
};

check_size(Matrix34, 0x30);

// ?IDENTITY@@3VMatrix34@@A
inline constexpr const Matrix34 IDENTITY {
    {1.0f, 0.0f, 0.0f},
    {0.0f, 1.0f, 0.0f},
    {0.0f, 0.0f, 1.0f},
    {0.0f, 0.0f, 0.0f},
};

constexpr void Matrix34::Identity()
{
    *this = IDENTITY;
}
