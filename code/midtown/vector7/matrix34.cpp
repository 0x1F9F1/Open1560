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

define_dummy_symbol(vector7_matrix34);

#include "matrix34.h"

Matrix34::Matrix34()
{
    unimplemented();
}

Matrix34::Matrix34(class Matrix44 const& arg1)
{
    unimplemented(arg1);
}

class Matrix34 Matrix34::operator*(f32 arg1)
{
    return stub<thiscall_t<class Matrix34, Matrix34*, f32>>(0x56A6F0, this, arg1);
}

class Matrix34 Matrix34::operator+(class Matrix34 const& arg1)
{
    return stub<thiscall_t<class Matrix34, Matrix34*, class Matrix34 const&>>(0x5674E0, this, arg1);
}

class Matrix34 Matrix34::operator-(class Matrix34 const& arg1)
{
    return stub<thiscall_t<class Matrix34, Matrix34*, class Matrix34 const&>>(0x5675B0, this, arg1);
}

i32 Matrix34::Approach(class Matrix34 const& arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<i32, Matrix34*, class Matrix34 const&, f32, f32>>(0x56D460, this, arg1, arg2, arg3);
}

i32 Matrix34::Approach(class Matrix34 const& arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<i32, Matrix34*, class Matrix34 const&, f32, f32, f32>>(
        0x56D310, this, arg1, arg2, arg3, arg4);
}

f32 Matrix34::Atan3(char arg1, char arg2)
{
    return stub<thiscall_t<f32, Matrix34*, char, char>>(0x56B2B0, this, arg1, arg2);
}

void Matrix34::CalcAppRates(f32& arg1, f32& arg2, class Matrix34 const& arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, Matrix34*, f32&, f32&, class Matrix34 const&, f32, f32>>(
        0x56D220, this, arg1, arg2, arg3, arg4, arg5);
}

f32 Matrix34::Determinant()
{
    return stub<thiscall_t<f32, Matrix34*>>(0x5686F0, this);
}

void Matrix34::Dot(class Matrix34 const& arg1, class Matrix34 const& arg2)
{
    return stub<thiscall_t<void, Matrix34*, class Matrix34 const&, class Matrix34 const&>>(0x567680, this, arg1, arg2);
}

void Matrix34::Dot3x3(class Matrix34 const& arg1, class Matrix34 const& arg2)
{
    return stub<thiscall_t<void, Matrix34*, class Matrix34 const&, class Matrix34 const&>>(0x5678A0, this, arg1, arg2);
}

u32 Matrix34::Equal(class Matrix34 const& arg1, f32 arg2)
{
    return stub<thiscall_t<u32, Matrix34*, class Matrix34 const&, f32>>(0x56D1E0, this, arg1, arg2);
}

void Matrix34::FastInverse(class Matrix34 const& arg1)
{
    return stub<thiscall_t<void, Matrix34*, class Matrix34 const&>>(0x568980, this, arg1);
}

void Matrix34::FastInverseFull(class Matrix34 const& arg1)
{
    return stub<thiscall_t<void, Matrix34*, class Matrix34 const&>>(0x568A80, this, arg1);
}

void Matrix34::FromEulers(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&>>(0x56C7E0, this, arg1);
}

void Matrix34::FromEulers(class Vector3 const& arg1, char const* arg2)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, char const*>>(0x56BE80, this, arg1, arg2);
}

void Matrix34::FromQuaternion(class Quaternion const& arg1)
{
    return stub<thiscall_t<void, Matrix34*, class Quaternion const&>>(0x56CD00, this, arg1);
}

class Vector3 Matrix34::GetEulers()
{
    return stub<thiscall_t<class Vector3, Matrix34*>>(0x56BCE0, this);
}

class Vector3 Matrix34::GetEulers(char const* arg1)
{
    return stub<thiscall_t<class Vector3, Matrix34*, char const*>>(0x56B630, this, arg1);
}

void Matrix34::GetLookAt(class Vector3* arg1, class Vector3* arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3*, class Vector3*, f32>>(0x56D0B0, this, arg1, arg2, arg3);
}

void Matrix34::GetPolar(class Vector4* arg1, class Vector3* arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, class Vector4*, class Vector3*, f32>>(0x56D140, this, arg1, arg2, arg3);
}

void Matrix34::Identity()
{
    return stub<thiscall_t<void, Matrix34*>>(0x5674B0, this);
}

void Matrix34::Interpolate(class Matrix34 const& arg1, class Matrix34 const& arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, class Matrix34 const&, class Matrix34 const&, f32>>(
        0x56D5B0, this, arg1, arg2, arg3);
}

class Matrix34 Matrix34::Inverse()
{
    return stub<thiscall_t<class Matrix34, Matrix34*>>(0x5687A0, this);
}

void Matrix34::LookAt(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, class Vector3 const&>>(0x56CE30, this, arg1, arg2);
}

void Matrix34::Normalize()
{
    return stub<thiscall_t<void, Matrix34*>>(0x56AE80, this);
}

void Matrix34::PolarView(class Vector4 const& arg1)
{
    return stub<thiscall_t<void, Matrix34*, class Vector4 const&>>(0x56D090, this, arg1);
}

void Matrix34::PolarView(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, Matrix34*, f32, f32, f32, f32>>(0x56CFD0, this, arg1, arg2, arg3, arg4);
}

void Matrix34::PolarView2(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, Matrix34*, f32, f32, f32, f32>>(0x56D030, this, arg1, arg2, arg3, arg4);
}

void Matrix34::Print()
{
    return stub<thiscall_t<void, Matrix34*>>(0x56D6A0, this);
}

u32 Matrix34::RotEqual(class Matrix34 const& arg1, f32 arg2)
{
    return stub<thiscall_t<u32, Matrix34*, class Matrix34 const&, f32>>(0x56D180, this, arg1, arg2);
}

void Matrix34::Rotate(class Vector3 const& arg1, f32 arg2)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, f32>>(0x5691D0, this, arg1, arg2);
}

void Matrix34::RotateAbs(class Vector3 const& arg1, f32 arg2)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, f32>>(0x569820, this, arg1, arg2);
}

void Matrix34::RotateFull(class Vector3 const& arg1, f32 arg2)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, f32>>(0x569D20, this, arg1, arg2);
}

class Vector3 Matrix34::RotateNoTrans(class Vector3 const& arg1)
{
    return stub<thiscall_t<class Vector3, Matrix34*, class Vector3 const&>>(0x4DEC70, this, arg1);
}

void Matrix34::RotateTo(class Vector3 const& arg1, class Vector3 const& arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, class Vector3 const&, f32>>(
        0x56A6C0, this, arg1, arg2, arg3);
}

void Matrix34::RotateToAbs(class Vector3 const& arg1, class Vector3 const& arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, class Vector3 const&, f32>>(
        0x56A400, this, arg1, arg2, arg3);
}

void Matrix34::RotateToFull(class Vector3 const& arg1, class Vector3 const& arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, class Vector3 const&, f32>>(
        0x56A670, this, arg1, arg2, arg3);
}

void Matrix34::Scale(f32 arg1)
{
    return stub<thiscall_t<void, Matrix34*, f32>>(0x56A9A0, this, arg1);
}

void Matrix34::Scale(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, f32, f32, f32>>(0x56A8F0, this, arg1, arg2, arg3);
}

void Matrix34::ScaleAbs(f32 arg1)
{
    return stub<thiscall_t<void, Matrix34*, f32>>(0x56AA20, this, arg1);
}

void Matrix34::ScaleAbs(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, f32, f32, f32>>(0x56A970, this, arg1, arg2, arg3);
}

void Matrix34::ScaleFull(f32 arg1)
{
    return stub<thiscall_t<void, Matrix34*, f32>>(0x56AB30, this, arg1);
}

void Matrix34::ScaleFull(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, f32, f32, f32>>(0x56AA50, this, arg1, arg2, arg3);
}

void Matrix34::ScaleFullAbs(f32 arg1)
{
    return stub<thiscall_t<void, Matrix34*, f32>>(0x56ABD0, this, arg1);
}

void Matrix34::ScaleFullAbs(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, f32, f32, f32>>(0x56AAF0, this, arg1, arg2, arg3);
}

void Matrix34::ScaleVolume(f32 arg1, char arg2)
{
    return stub<thiscall_t<void, Matrix34*, f32, char>>(0x56AC10, this, arg1, arg2);
}

void Matrix34::ScaleVolumeAbs(f32 arg1, char arg2)
{
    return stub<thiscall_t<void, Matrix34*, f32, char>>(0x56AD10, this, arg1, arg2);
}

class Vector3 Matrix34::SolveSVD(class Vector3 const& arg1)
{
    return stub<thiscall_t<class Vector3, Matrix34*, class Vector3 const&>>(0x567A30, this, arg1);
}

void Matrix34::TrackBall(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, Matrix34*, f32, f32, f32, f32, f32>>(0x56AFA0, this, arg1, arg2, arg3, arg4, arg5);
}

void Matrix34::Transform(class Vector3 const& arg1, class Vector3 const& arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, class Vector3 const&, f32>>(
        0x56AE10, this, arg1, arg2, arg3);
}

class Matrix34 Matrix34::Transpose()
{
    return stub<thiscall_t<class Matrix34, Matrix34*>>(0x4DECA0, this);
}

void Matrix34::Transpose(class Matrix34 const& arg1)
{
    return stub<thiscall_t<void, Matrix34*, class Matrix34 const&>>(0x56B250, this, arg1);
}

void Matrix34::DeclareFields()
{
    return stub<cdecl_t<void>>(0x56D760);
}

class MetaClass* Matrix34::GetClass()
{
    return stub<cdecl_t<class MetaClass*>>(0x56D8A0);
}

void Matrix34::ArbitraryRotation(class Vector3 const& arg1, f32 arg2)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, f32>>(0x568D20, this, arg1, arg2);
}

class Matrix34 operator*(f32 arg1, class Matrix34 const& arg2)
{
    return stub<cdecl_t<class Matrix34, f32, class Matrix34 const&>>(0x56A7F0, arg1, arg2);
}

f32 ASinf(f32 arg1)
{
    return stub<cdecl_t<f32, f32>>(0x56D8B0, arg1);
}

f32 ATan2f(f32 arg1, f32 arg2)
{
    return stub<cdecl_t<f32, f32, f32>>(0x56D980, arg1, arg2);
}

f32 asinf_fast(f32 arg1)
{
    return stub<cdecl_t<f32, f32>>(0x56D950, arg1);
}
