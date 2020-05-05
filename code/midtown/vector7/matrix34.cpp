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
    return stub<thiscall_t<class Matrix34, Matrix34*, f32>>(0x16A6F0_Offset, this, arg1);
}

class Matrix34 Matrix34::operator+(class Matrix34 const& arg1)
{
    return stub<thiscall_t<class Matrix34, Matrix34*, class Matrix34 const&>>(0x1674E0_Offset, this, arg1);
}

class Matrix34 Matrix34::operator-(class Matrix34 const& arg1)
{
    return stub<thiscall_t<class Matrix34, Matrix34*, class Matrix34 const&>>(0x1675B0_Offset, this, arg1);
}

i32 Matrix34::Approach(class Matrix34 const& arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<i32, Matrix34*, class Matrix34 const&, f32, f32>>(0x16D460_Offset, this, arg1, arg2, arg3);
}

i32 Matrix34::Approach(class Matrix34 const& arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<i32, Matrix34*, class Matrix34 const&, f32, f32, f32>>(
        0x16D310_Offset, this, arg1, arg2, arg3, arg4);
}

f32 Matrix34::Atan3(char arg1, char arg2)
{
    return stub<thiscall_t<f32, Matrix34*, char, char>>(0x16B2B0_Offset, this, arg1, arg2);
}

void Matrix34::CalcAppRates(f32& arg1, f32& arg2, class Matrix34 const& arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, Matrix34*, f32&, f32&, class Matrix34 const&, f32, f32>>(
        0x16D220_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

f32 Matrix34::Determinant()
{
    return stub<thiscall_t<f32, Matrix34*>>(0x1686F0_Offset, this);
}

void Matrix34::Dot(class Matrix34 const& arg1, class Matrix34 const& arg2)
{
    return stub<thiscall_t<void, Matrix34*, class Matrix34 const&, class Matrix34 const&>>(
        0x167680_Offset, this, arg1, arg2);
}

void Matrix34::Dot3x3(class Matrix34 const& arg1, class Matrix34 const& arg2)
{
    return stub<thiscall_t<void, Matrix34*, class Matrix34 const&, class Matrix34 const&>>(
        0x1678A0_Offset, this, arg1, arg2);
}

u32 Matrix34::Equal(class Matrix34 const& arg1, f32 arg2)
{
    return stub<thiscall_t<u32, Matrix34*, class Matrix34 const&, f32>>(0x16D1E0_Offset, this, arg1, arg2);
}

void Matrix34::FastInverse(class Matrix34 const& arg1)
{
    return stub<thiscall_t<void, Matrix34*, class Matrix34 const&>>(0x168980_Offset, this, arg1);
}

void Matrix34::FastInverseFull(class Matrix34 const& arg1)
{
    return stub<thiscall_t<void, Matrix34*, class Matrix34 const&>>(0x168A80_Offset, this, arg1);
}

void Matrix34::FromEulers(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&>>(0x16C7E0_Offset, this, arg1);
}

void Matrix34::FromEulers(class Vector3 const& arg1, char const* arg2)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, char const*>>(0x16BE80_Offset, this, arg1, arg2);
}

void Matrix34::FromQuaternion(class Quaternion const& arg1)
{
    return stub<thiscall_t<void, Matrix34*, class Quaternion const&>>(0x16CD00_Offset, this, arg1);
}

class Vector3 Matrix34::GetEulers()
{
    return stub<thiscall_t<class Vector3, Matrix34*>>(0x16BCE0_Offset, this);
}

class Vector3 Matrix34::GetEulers(char const* arg1)
{
    return stub<thiscall_t<class Vector3, Matrix34*, char const*>>(0x16B630_Offset, this, arg1);
}

void Matrix34::GetLookAt(class Vector3* arg1, class Vector3* arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3*, class Vector3*, f32>>(
        0x16D0B0_Offset, this, arg1, arg2, arg3);
}

void Matrix34::GetPolar(class Vector4* arg1, class Vector3* arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, class Vector4*, class Vector3*, f32>>(
        0x16D140_Offset, this, arg1, arg2, arg3);
}

void Matrix34::Identity()
{
    return stub<thiscall_t<void, Matrix34*>>(0x1674B0_Offset, this);
}

void Matrix34::Interpolate(class Matrix34 const& arg1, class Matrix34 const& arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, class Matrix34 const&, class Matrix34 const&, f32>>(
        0x16D5B0_Offset, this, arg1, arg2, arg3);
}

class Matrix34 Matrix34::Inverse()
{
    return stub<thiscall_t<class Matrix34, Matrix34*>>(0x1687A0_Offset, this);
}

void Matrix34::LookAt(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, class Vector3 const&>>(
        0x16CE30_Offset, this, arg1, arg2);
}

void Matrix34::Normalize()
{
    return stub<thiscall_t<void, Matrix34*>>(0x16AE80_Offset, this);
}

void Matrix34::PolarView(class Vector4 const& arg1)
{
    return stub<thiscall_t<void, Matrix34*, class Vector4 const&>>(0x16D090_Offset, this, arg1);
}

void Matrix34::PolarView(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, Matrix34*, f32, f32, f32, f32>>(0x16CFD0_Offset, this, arg1, arg2, arg3, arg4);
}

void Matrix34::PolarView2(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, Matrix34*, f32, f32, f32, f32>>(0x16D030_Offset, this, arg1, arg2, arg3, arg4);
}

void Matrix34::Print()
{
    return stub<thiscall_t<void, Matrix34*>>(0x16D6A0_Offset, this);
}

u32 Matrix34::RotEqual(class Matrix34 const& arg1, f32 arg2)
{
    return stub<thiscall_t<u32, Matrix34*, class Matrix34 const&, f32>>(0x16D180_Offset, this, arg1, arg2);
}

void Matrix34::Rotate(class Vector3 const& arg1, f32 arg2)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, f32>>(0x1691D0_Offset, this, arg1, arg2);
}

void Matrix34::RotateAbs(class Vector3 const& arg1, f32 arg2)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, f32>>(0x169820_Offset, this, arg1, arg2);
}

void Matrix34::RotateFull(class Vector3 const& arg1, f32 arg2)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, f32>>(0x169D20_Offset, this, arg1, arg2);
}

class Vector3 Matrix34::RotateNoTrans(class Vector3 const& arg1)
{
    return stub<thiscall_t<class Vector3, Matrix34*, class Vector3 const&>>(0xDEC70_Offset, this, arg1);
}

void Matrix34::RotateTo(class Vector3 const& arg1, class Vector3 const& arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, class Vector3 const&, f32>>(
        0x16A6C0_Offset, this, arg1, arg2, arg3);
}

void Matrix34::RotateToAbs(class Vector3 const& arg1, class Vector3 const& arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, class Vector3 const&, f32>>(
        0x16A400_Offset, this, arg1, arg2, arg3);
}

void Matrix34::RotateToFull(class Vector3 const& arg1, class Vector3 const& arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, class Vector3 const&, f32>>(
        0x16A670_Offset, this, arg1, arg2, arg3);
}

void Matrix34::Scale(f32 arg1)
{
    return stub<thiscall_t<void, Matrix34*, f32>>(0x16A9A0_Offset, this, arg1);
}

void Matrix34::Scale(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, f32, f32, f32>>(0x16A8F0_Offset, this, arg1, arg2, arg3);
}

void Matrix34::ScaleAbs(f32 arg1)
{
    return stub<thiscall_t<void, Matrix34*, f32>>(0x16AA20_Offset, this, arg1);
}

void Matrix34::ScaleAbs(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, f32, f32, f32>>(0x16A970_Offset, this, arg1, arg2, arg3);
}

void Matrix34::ScaleFull(f32 arg1)
{
    return stub<thiscall_t<void, Matrix34*, f32>>(0x16AB30_Offset, this, arg1);
}

void Matrix34::ScaleFull(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, f32, f32, f32>>(0x16AA50_Offset, this, arg1, arg2, arg3);
}

void Matrix34::ScaleFullAbs(f32 arg1)
{
    return stub<thiscall_t<void, Matrix34*, f32>>(0x16ABD0_Offset, this, arg1);
}

void Matrix34::ScaleFullAbs(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, f32, f32, f32>>(0x16AAF0_Offset, this, arg1, arg2, arg3);
}

void Matrix34::ScaleVolume(f32 arg1, char arg2)
{
    return stub<thiscall_t<void, Matrix34*, f32, char>>(0x16AC10_Offset, this, arg1, arg2);
}

void Matrix34::ScaleVolumeAbs(f32 arg1, char arg2)
{
    return stub<thiscall_t<void, Matrix34*, f32, char>>(0x16AD10_Offset, this, arg1, arg2);
}

class Vector3 Matrix34::SolveSVD(class Vector3 const& arg1)
{
    return stub<thiscall_t<class Vector3, Matrix34*, class Vector3 const&>>(0x167A30_Offset, this, arg1);
}

void Matrix34::TrackBall(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, Matrix34*, f32, f32, f32, f32, f32>>(
        0x16AFA0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void Matrix34::Transform(class Vector3 const& arg1, class Vector3 const& arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, class Vector3 const&, f32>>(
        0x16AE10_Offset, this, arg1, arg2, arg3);
}

class Matrix34 Matrix34::Transpose()
{
    return stub<thiscall_t<class Matrix34, Matrix34*>>(0xDECA0_Offset, this);
}

void Matrix34::Transpose(class Matrix34 const& arg1)
{
    return stub<thiscall_t<void, Matrix34*, class Matrix34 const&>>(0x16B250_Offset, this, arg1);
}

void Matrix34::DeclareFields()
{
    return stub<cdecl_t<void>>(0x16D760_Offset);
}

class MetaClass* Matrix34::GetClass()
{
    return stub<cdecl_t<class MetaClass*>>(0x16D8A0_Offset);
}

void Matrix34::ArbitraryRotation(class Vector3 const& arg1, f32 arg2)
{
    return stub<thiscall_t<void, Matrix34*, class Vector3 const&, f32>>(0x168D20_Offset, this, arg1, arg2);
}

class Matrix34 operator*(f32 arg1, class Matrix34 const& arg2)
{
    return stub<cdecl_t<class Matrix34, f32, class Matrix34 const&>>(0x16A7F0_Offset, arg1, arg2);
}

f32 ASinf(f32 arg1)
{
    return stub<cdecl_t<f32, f32>>(0x16D8B0_Offset, arg1);
}

f32 ATan2f(f32 arg1, f32 arg2)
{
    return stub<cdecl_t<f32, f32, f32>>(0x16D980_Offset, arg1, arg2);
}

f32 asinf_fast(f32 arg1)
{
    return stub<cdecl_t<f32, f32>>(0x16D950_Offset, arg1);
}
