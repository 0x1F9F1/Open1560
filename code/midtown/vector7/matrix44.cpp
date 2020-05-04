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

#include "matrix44.h"

Matrix44::Matrix44(class Matrix34 const& arg1)
{
    unimplemented();
}

Matrix44::Matrix44(class Matrix44 const& arg1)
{
    unimplemented();
}

class Matrix44 Matrix44::operator*(f32 arg1)
{
    return stub<thiscall_t<class Matrix44, Matrix44*, f32>>(0x16EA80_Offset, this, arg1);
}

class Matrix44 Matrix44::operator+(class Matrix44 const& arg1)
{
    return stub<thiscall_t<class Matrix44, Matrix44*, class Matrix44 const&>>(0x16E570_Offset, this, arg1);
}

class Matrix44 Matrix44::operator-()
{
    return stub<thiscall_t<class Matrix44, Matrix44*>>(0x16E820_Offset, this);
}

class Matrix44 Matrix44::operator-(class Matrix44 const& arg1)
{
    return stub<thiscall_t<class Matrix44, Matrix44*, class Matrix44 const&>>(0x16E6D0_Offset, this, arg1);
}

class Matrix44 Matrix44::operator/(f32 arg1)
{
    return stub<thiscall_t<class Matrix44, Matrix44*, f32>>(0x16EBD0_Offset, this, arg1);
}

class Matrix44 Matrix44::operator^(class Matrix44 const& arg1)
{
    return stub<thiscall_t<class Matrix44, Matrix44*, class Matrix44 const&>>(0x16EDB0_Offset, this, arg1);
}

class Vector4 Matrix44::operator^(class Vector4 const& arg1)
{
    return stub<thiscall_t<class Vector4, Matrix44*, class Vector4 const&>>(0x16F2F0_Offset, this, arg1);
}

f32 Matrix44::Determinant()
{
    return stub<thiscall_t<f32, Matrix44*>>(0x16F690_Offset, this);
}

void Matrix44::Dot(class Matrix44 const& arg1, class Matrix44 const& arg2)
{
    return stub<thiscall_t<void, Matrix44*, class Matrix44 const&, class Matrix44 const&>>(
        0x16F020_Offset, this, arg1, arg2);
}

void Matrix44::FromQuaternion(class Quaternion const& arg1)
{
    return stub<thiscall_t<void, Matrix44*, class Quaternion const&>>(0x1709D0_Offset, this, arg1);
}

void Matrix44::Identity()
{
    return stub<thiscall_t<void, Matrix44*>>(0x170460_Offset, this);
}

class Matrix44 Matrix44::Inverse()
{
    return stub<thiscall_t<class Matrix44, Matrix44*>>(0x16F8E0_Offset, this);
}

void Matrix44::Ortho(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6)
{
    return stub<thiscall_t<void, Matrix44*, f32, f32, f32, f32, f32, f32>>(
        0x16F580_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void Matrix44::Perspective(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, Matrix44*, f32, f32, f32, f32>>(0x16F490_Offset, this, arg1, arg2, arg3, arg4);
}

void Matrix44::Print()
{
    return stub<thiscall_t<void, Matrix44*>>(0x170B10_Offset, this);
}

void Matrix44::Rotate(char arg1, f32 arg2)
{
    return stub<thiscall_t<void, Matrix44*, char, f32>>(0x1704A0_Offset, this, arg1, arg2);
}

void Matrix44::Rotate(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, Matrix44*, class Vector3 const&, class Vector3 const&>>(
        0x170680_Offset, this, arg1, arg2);
}

void Matrix44::Rotate(class Vector3 const& arg1, f32 arg2)
{
    return stub<thiscall_t<void, Matrix44*, class Vector3 const&, f32>>(0x170620_Offset, this, arg1, arg2);
}

void Matrix44::Scale(class Vector3 const& arg1, f32 arg2)
{
    return stub<thiscall_t<void, Matrix44*, class Vector3 const&, f32>>(0x170970_Offset, this, arg1, arg2);
}

void Matrix44::Scale(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix44*, f32, f32, f32>>(0x170920_Offset, this, arg1, arg2, arg3);
}

void Matrix44::Translate(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, Matrix44*, f32, f32, f32>>(0x1708D0_Offset, this, arg1, arg2, arg3);
}

class Matrix44 Matrix44::Transpose()
{
    return stub<thiscall_t<class Matrix44, Matrix44*>>(0x170380_Offset, this);
}

class Matrix44 operator*(f32 arg1, class Matrix44 const& arg2)
{
    return stub<cdecl_t<class Matrix44, f32, class Matrix44 const&>>(0x16E920_Offset, arg1, arg2);
}

class Vector3 operator^(class Vector3 const& arg1, class Matrix44 const& arg2)
{
    return stub<cdecl_t<class Vector3, class Vector3 const&, class Matrix44 const&>>(0x16F3F0_Offset, arg1, arg2);
}

class Vector4 operator^(class Vector4 const& arg1, class Matrix44 const& arg2)
{
    return stub<cdecl_t<class Vector4, class Vector4 const&, class Matrix44 const&>>(0x16F460_Offset, arg1, arg2);
}

define_dummy_symbol(vector7_matrix44);
