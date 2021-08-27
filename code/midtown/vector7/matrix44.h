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
    vector7:matrix44

    0x56E500 | public: __thiscall Matrix44::Matrix44(class Matrix34 const &) | ??0Matrix44@@QAE@ABVMatrix34@@@Z
    0x56E570 | public: class Matrix44 __thiscall Matrix44::operator+(class Matrix44 const &) const | ??HMatrix44@@QBE?AV0@ABV0@@Z
    0x56E6D0 | public: class Matrix44 __thiscall Matrix44::operator-(class Matrix44 const &) const | ??GMatrix44@@QBE?AV0@ABV0@@Z
    0x56E820 | public: class Matrix44 __thiscall Matrix44::operator-(void) const | ??GMatrix44@@QBE?AV0@XZ
    0x56E920 | class Matrix44 __cdecl operator*(float,class Matrix44 const &) | ??D@YA?AVMatrix44@@MABV0@@Z
    0x56EA80 | public: class Matrix44 __thiscall Matrix44::operator*(float) const | ??DMatrix44@@QBE?AV0@M@Z
    0x56EBD0 | public: class Matrix44 __thiscall Matrix44::operator/(float) const | ??KMatrix44@@QBE?AV0@M@Z
    0x56EDB0 | public: class Matrix44 __thiscall Matrix44::operator^(class Matrix44 const &) const | ??TMatrix44@@QBE?AV0@ABV0@@Z
    0x56F020 | public: void __thiscall Matrix44::Dot(class Matrix44 const &,class Matrix44 const &) | ?Dot@Matrix44@@QAEXABV1@0@Z
    0x56F2F0 | public: class Vector4 __thiscall Matrix44::operator^(class Vector4 const &) const | ??TMatrix44@@QBE?AVVector4@@ABV1@@Z
    0x56F3F0 | class Vector3 __cdecl operator^(class Vector3 const &,class Matrix44 const &) | ??T@YA?AVVector3@@ABV0@ABVMatrix44@@@Z
    0x56F460 | class Vector4 __cdecl operator^(class Vector4 const &,class Matrix44 const &) | ??T@YA?AVVector4@@ABV0@ABVMatrix44@@@Z
    0x56F490 | public: void __thiscall Matrix44::Perspective(float,float,float,float) | ?Perspective@Matrix44@@QAEXMMMM@Z
    0x56F580 | public: void __thiscall Matrix44::Ortho(float,float,float,float,float,float) | ?Ortho@Matrix44@@QAEXMMMMMM@Z
    0x56F690 | public: float __thiscall Matrix44::Determinant(void) const | ?Determinant@Matrix44@@QBEMXZ
    0x56F8E0 | public: class Matrix44 __thiscall Matrix44::Inverse(void) const | ?Inverse@Matrix44@@QBE?AV1@XZ
    0x570380 | public: class Matrix44 __thiscall Matrix44::Transpose(void) const | ?Transpose@Matrix44@@QBE?AV1@XZ
    0x570460 | public: void __thiscall Matrix44::Identity(void) | ?Identity@Matrix44@@QAEXXZ
    0x5704A0 | public: void __thiscall Matrix44::Rotate(char,float) | ?Rotate@Matrix44@@QAEXDM@Z
    0x570620 | public: void __thiscall Matrix44::Rotate(class Vector3 const &,float) | ?Rotate@Matrix44@@QAEXABVVector3@@M@Z
    0x570680 | public: void __thiscall Matrix44::Rotate(class Vector3 const &,class Vector3 const &) | ?Rotate@Matrix44@@QAEXABVVector3@@0@Z
    0x5708D0 | public: void __thiscall Matrix44::Translate(float,float,float) | ?Translate@Matrix44@@QAEXMMM@Z
    0x570920 | public: void __thiscall Matrix44::Scale(float,float,float) | ?Scale@Matrix44@@QAEXMMM@Z
    0x570970 | public: void __thiscall Matrix44::Scale(class Vector3 const &,float) | ?Scale@Matrix44@@QAEXABVVector3@@M@Z
    0x5709D0 | public: void __thiscall Matrix44::FromQuaternion(class Quaternion const &) | ?FromQuaternion@Matrix44@@QAEXABVQuaternion@@@Z
    0x570B10 | public: void __thiscall Matrix44::Print(void) const | ?Print@Matrix44@@QBEXXZ
    0x570C80 | public: __thiscall Matrix44::Matrix44(class Matrix44 const &) | ??0Matrix44@@QAE@ABV0@@Z
    0x570D00 | public: class Vector3 __thiscall Vector3::operator~(void) const | ??SVector3@@QBE?AV0@XZ
    0x570D50 | public: void __thiscall Vector4::Set(float,float,float,float) | ?Set@Vector4@@QAEXMMMM@Z
    0x570D70 | public: float __thiscall Vector4::operator^(class Vector4 const &) const | ??TVector4@@QBEMABV0@@Z
    0x658D70 | float * id | ?id@@3PAMA
    0x658DB0 | float * bb | ?bb@@3PAMA
    0x658DF0 | float * bt | ?bt@@3PAMA
    0x658E30 | float * hb | ?hb@@3PAMA
    0x658E70 | float * ht | ?ht@@3PAMA
    0x9094F0 | class Matrix44 HermiteBasis | ?HermiteBasis@@3VMatrix44@@A
    0x909530 | class Matrix44 BezierBasis | ?BezierBasis@@3VMatrix44@@A
    0x909570 | class Matrix44 HermiteTranspose | ?HermiteTranspose@@3VMatrix44@@A
    0x9095B0 | class Matrix44 BezierTranspose | ?BezierTranspose@@3VMatrix44@@A
    0x9095F0 | class Matrix44 Identity | ?Identity@@3VMatrix44@@A
*/

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

    // ??DMatrix44@@QBE?AV0@M@Z | unused
    ARTS_IMPORT Matrix44 operator*(f32 arg1) const;

    // ??HMatrix44@@QBE?AV0@ABV0@@Z | unused
    ARTS_IMPORT Matrix44 operator+(const Matrix44& arg1) const;

    // ??GMatrix44@@QBE?AV0@XZ | unused
    ARTS_IMPORT Matrix44 operator-() const;

    // ??GMatrix44@@QBE?AV0@ABV0@@Z | unused
    ARTS_IMPORT Matrix44 operator-(const Matrix44& arg1) const;

    // ??KMatrix44@@QBE?AV0@M@Z | unused
    ARTS_IMPORT Matrix44 operator/(f32 arg1) const;

    // ??TMatrix44@@QBE?AV0@ABV0@@Z
    ARTS_IMPORT Matrix44 operator^(const Matrix44& arg1) const;

    // ??TMatrix44@@QBE?AVVector4@@ABV1@@Z
    ARTS_IMPORT Vector4 operator^(const Vector4& arg1) const;

    // ?Determinant@Matrix44@@QBEMXZ
    ARTS_IMPORT f32 Determinant() const;

    // ?Dot@Matrix44@@QAEXABV1@0@Z
    ARTS_IMPORT void Dot(const Matrix44& arg1, const Matrix44& arg2);

    // ?FromQuaternion@Matrix44@@QAEXABVQuaternion@@@Z
    ARTS_IMPORT void FromQuaternion(const Quaternion& arg1);

    // ?Identity@Matrix44@@QAEXXZ
    ARTS_IMPORT void Identity();

    // ?Inverse@Matrix44@@QBE?AV1@XZ | unused
    ARTS_IMPORT Matrix44 Inverse() const;

    // ?Ortho@Matrix44@@QAEXMMMMMM@Z | unused
    ARTS_IMPORT void Ortho(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);

    // ?Perspective@Matrix44@@QAEXMMMM@Z | unused
    ARTS_IMPORT void Perspective(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // ?Print@Matrix44@@QBEXXZ | unused
    ARTS_IMPORT void Print() const;

    // ?Rotate@Matrix44@@QAEXDM@Z | unused
    ARTS_IMPORT void Rotate(char arg1, f32 arg2);

    // ?Rotate@Matrix44@@QAEXABVVector3@@0@Z
    ARTS_IMPORT void Rotate(const Vector3& arg1, const Vector3& arg2);

    // ?Rotate@Matrix44@@QAEXABVVector3@@M@Z | unused
    ARTS_IMPORT void Rotate(const Vector3& arg1, f32 arg2);

    // ?Scale@Matrix44@@QAEXABVVector3@@M@Z | unused
    ARTS_IMPORT void Scale(const Vector3& arg1, f32 arg2);

    // ?Scale@Matrix44@@QAEXMMM@Z
    ARTS_IMPORT void Scale(f32 arg1, f32 arg2, f32 arg3);

    // ?Translate@Matrix44@@QAEXMMM@Z | unused
    ARTS_IMPORT void Translate(f32 arg1, f32 arg2, f32 arg3);

    // ?Transpose@Matrix44@@QBE?AV1@XZ
    ARTS_IMPORT Matrix44 Transpose() const;

    Vector4 m0; // Left
    Vector4 m1; // Up
    Vector4 m2; // Forward
    Vector4 m3; // Translation
};

check_size(Matrix44, 0x40);

// ??D@YA?AVMatrix44@@MABV0@@Z | unused
ARTS_IMPORT Matrix44 operator*(f32 arg1, const Matrix44& arg2);

// ??T@YA?AVVector3@@ABV0@ABVMatrix44@@@Z | unused
ARTS_IMPORT Vector3 operator^(const Vector3& arg1, const Matrix44& arg2);

// ??T@YA?AVVector4@@ABV0@ABVMatrix44@@@Z
ARTS_IMPORT Vector4 operator^(const Vector4& arg1, const Matrix44& arg2);

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
