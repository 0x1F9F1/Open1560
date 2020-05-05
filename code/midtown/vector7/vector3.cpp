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

#include "vector3.h"

class Vector3 Vector3::operator%(class Vector3 const& arg1)
{
    return stub<thiscall_t<class Vector3, Vector3*, class Vector3 const&>>(0x5C420_Offset, this, arg1);
}

class Vector3 Vector3::operator*(f32 arg1)
{
    return stub<thiscall_t<class Vector3, Vector3*, f32>>(0x51320_Offset, this, arg1);
}

void Vector3::operator*=(f32 arg1)
{
    return stub<thiscall_t<void, Vector3*, f32>>(0xDEBD0_Offset, this, arg1);
}

class Vector3 Vector3::operator+(class Vector3 const& arg1)
{
    return stub<thiscall_t<class Vector3, Vector3*, class Vector3 const&>>(0x512F0_Offset, this, arg1);
}

void Vector3::operator+=(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, Vector3*, class Vector3 const&>>(0xDBB50_Offset, this, arg1);
}

class Vector3 Vector3::operator-()
{
    return stub<thiscall_t<class Vector3, Vector3*>>(0x59E70_Offset, this);
}

class Vector3 Vector3::operator-(class Vector3 const& arg1)
{
    return stub<thiscall_t<class Vector3, Vector3*, class Vector3 const&>>(0x3FFA0_Offset, this, arg1);
}

void Vector3::operator-=(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, Vector3*, class Vector3 const&>>(0xDEBA0_Offset, this, arg1);
}

class Vector3 Vector3::operator/(f32 arg1)
{
    return stub<thiscall_t<class Vector3, Vector3*, f32>>(0xD9080_Offset, this, arg1);
}

class Vector3 Vector3::operator^(class Matrix34 const& arg1)
{
    return stub<thiscall_t<class Vector3, Vector3*, class Matrix34 const&>>(0xDEB70_Offset, this, arg1);
}

f32 Vector3::operator^(class Vector3 const& arg1)
{
    return stub<thiscall_t<f32, Vector3*, class Vector3 const&>>(0x59E40_Offset, this, arg1);
}

class Vector3 Vector3::operator~()
{
    return stub<thiscall_t<class Vector3, Vector3*>>(0x170D00_Offset, this);
}

void Vector3::Add(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, Vector3*, class Vector3 const&, class Vector3 const&>>(
        0x12BB70_Offset, this, arg1, arg2);
}

f32 Vector3::Angle(class Vector3 const& arg1)
{
    return stub<thiscall_t<f32, Vector3*, class Vector3 const&>>(0x164CF0_Offset, this, arg1);
}

i32 Vector3::Approach(class Vector3 const& arg1, f32 arg2, f32 arg3, f32* arg4)
{
    return stub<thiscall_t<i32, Vector3*, class Vector3 const&, f32, f32, f32*>>(
        0x1656A0_Offset, this, arg1, arg2, arg3, arg4);
}

f32 Vector3::Area(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<f32, Vector3*, class Vector3 const&, class Vector3 const&>>(
        0x164EC0_Offset, this, arg1, arg2);
}

f32 Vector3::Atan3(char arg1, char arg2)
{
    return stub<thiscall_t<f32, Vector3*, char, char>>(0x165000_Offset, this, arg1, arg2);
}

void Vector3::Bilinear(f32 arg1, f32 arg2, class Vector3 const& arg3, class Vector3 const& arg4,
    class Vector3 const& arg5, class Vector3 const& arg6)
{
    return stub<thiscall_t<void, Vector3*, f32, f32, class Vector3 const&, class Vector3 const&, class Vector3 const&,
        class Vector3 const&>>(0x165D00_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void Vector3::Bounce(class Vector3 const& arg1, f32 arg2)
{
    return stub<thiscall_t<void, Vector3*, class Vector3 const&, f32>>(0x166820_Offset, this, arg1, arg2);
}

void Vector3::CatmullRom(f32 arg1, class Vector3 const& arg2, class Vector3 const& arg3, class Vector3 const& arg4,
    class Vector3 const& arg5)
{
    return stub<thiscall_t<void, Vector3*, f32, class Vector3 const&, class Vector3 const&, class Vector3 const&,
        class Vector3 const&>>(0x1657E0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void Vector3::Clamp(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, Vector3*, class Vector3 const&, class Vector3 const&>>(
        0x1665E0_Offset, this, arg1, arg2);
}

void Vector3::Clamp(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, Vector3*, f32, f32>>(0x166550_Offset, this, arg1, arg2);
}

f32 Vector3::Cos(class Vector3 const& arg1)
{
    return stub<thiscall_t<f32, Vector3*, class Vector3 const&>>(0x164BB0_Offset, this, arg1);
}

void Vector3::Cross(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<void, Vector3*, class Vector3 const&, class Vector3 const&>>(
        0x1724F0_Offset, this, arg1, arg2);
}

f32 Vector3::Dist(class Vector3 const& arg1)
{
    return stub<thiscall_t<f32, Vector3*, class Vector3 const&>>(0x1669C0_Offset, this, arg1);
}

void __fastcall Vector3::Dot(class Vector3 const& arg1, class Matrix34 const& arg2)
{
    return stub<fastcall_t<void, Vector3*, class Vector3 const&, class Matrix34 const&>>(
        0x164AE0_Offset, this, arg1, arg2);
}

void __fastcall Vector3::Dot3x3(class Vector3 const& arg1, class Matrix34 const& arg2)
{
    return stub<fastcall_t<void, Vector3*, class Vector3 const&, class Matrix34 const&>>(
        0x164B50_Offset, this, arg1, arg2);
}

u32 Vector3::Equal(class Vector3 const& arg1, f32 arg2)
{
    return stub<thiscall_t<u32, Vector3*, class Vector3 const&, f32>>(0x1662A0_Offset, this, arg1, arg2);
}

void Vector3::GetPolar(class Vector3 const& arg1, class Vector4* arg2, class Vector3* arg3)
{
    return stub<thiscall_t<void, Vector3*, class Vector3 const&, class Vector4*, class Vector3*>>(
        0x166680_Offset, this, arg1, arg2, arg3);
}

i32 Vector3::HalfSpace(class Vector4 const& arg1)
{
    return stub<thiscall_t<i32, Vector3*, class Vector4 const&>>(0x165490_Offset, this, arg1);
}

void Vector3::Hermite(f32 arg1, class Vector3 const& arg2, class Vector3 const& arg3, class Vector3 const& arg4,
    class Vector3 const& arg5, f32 arg6)
{
    return stub<thiscall_t<void, Vector3*, f32, class Vector3 const&, class Vector3 const&, class Vector3 const&,
        class Vector3 const&, f32>>(0x165B50_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

f32 Vector3::InvMag()
{
    return stub<thiscall_t<f32, Vector3*>>(0x166960_Offset, this);
}

f32 Vector3::Mag()
{
    return stub<thiscall_t<f32, Vector3*>>(0x1668A0_Offset, this);
}

void Vector3::Neg(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, Vector3*, class Vector3 const&>>(0x1724D0_Offset, this, arg1);
}

f32 Vector3::PointToLine(class Vector3 const& arg1, class Vector3 const& arg2)
{
    return stub<thiscall_t<f32, Vector3*, class Vector3 const&, class Vector3 const&>>(
        0x165DD0_Offset, this, arg1, arg2);
}

f32 Vector3::PointToSegment(
    class Vector3 const& arg1, class Vector3 const& arg2, class Vector3& arg3, i32& arg4, f32* arg5)
{
    return stub<thiscall_t<f32, Vector3*, class Vector3 const&, class Vector3 const&, class Vector3&, i32&, f32*>>(
        0x165EB0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

f32 Vector3::PointToSegment2(
    class Vector3 const& arg1, class Vector3 const& arg2, class Vector3& arg3, i32& arg4, f32* arg5)
{
    return stub<thiscall_t<f32, Vector3*, class Vector3 const&, class Vector3 const&, class Vector3&, i32&, f32*>>(
        0x166080_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

class Vector3 Vector3::Project(class Vector3& arg1)
{
    return stub<thiscall_t<class Vector3, Vector3*, class Vector3&>>(0x164F60_Offset, this, arg1);
}

i32 Vector3::RayIntersectPlane(
    class Vector3 const& arg1, class Vector3 const& arg2, class Vector4 const& arg3, f32 arg4)
{
    return stub<thiscall_t<i32, Vector3*, class Vector3 const&, class Vector3 const&, class Vector4 const&, f32>>(
        0x165540_Offset, this, arg1, arg2, arg3, arg4);
}

void Vector3::Rebound(class Vector3 const& arg1, f32 arg2)
{
    return stub<thiscall_t<void, Vector3*, class Vector3 const&, f32>>(0x1667C0_Offset, this, arg1, arg2);
}

class Vector3 Vector3::Reflect(class Vector3 const& arg1)
{
    return stub<thiscall_t<class Vector3, Vector3*, class Vector3 const&>>(0x1651C0_Offset, this, arg1);
}

void Vector3::Rotate(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, Vector3*, f32, i32>>(0x1652C0_Offset, this, arg1, arg2);
}

void Vector3::Scale(class Vector3 const& arg1, f32 arg2)
{
    return stub<thiscall_t<void, Vector3*, class Vector3 const&, f32>>(0x5C470_Offset, this, arg1, arg2);
}

void Vector3::Set(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, Vector3*, f32, f32, f32>>(0xDBB30_Offset, this, arg1, arg2, arg3);
}

void Vector3::Slerp(f32 arg1, class Vector3 const& arg2, class Vector3 const& arg3)
{
    return stub<thiscall_t<void, Vector3*, f32, class Vector3 const&, class Vector3 const&>>(
        0x165990_Offset, this, arg1, arg2, arg3);
}

void Vector3::hsvtorgb()
{
    return stub<thiscall_t<void, Vector3*>>(0x166420_Offset, this);
}

void Vector3::rgbtohsv()
{
    return stub<thiscall_t<void, Vector3*>>(0x166300_Offset, this);
}

void TransformNormalList(class Vector3* arg1, class Vector3 const* arg2, i32 arg3, class Matrix34 const& arg4)
{
    return stub<cdecl_t<void, class Vector3*, class Vector3 const*, i32, class Matrix34 const&>>(
        0x166D00_Offset, arg1, arg2, arg3, arg4);
}

void TransformNormalList(class Vector3** arg1, class Vector3 const** arg2, i32 arg3, class Matrix34 const& arg4)
{
    return stub<cdecl_t<void, class Vector3**, class Vector3 const**, i32, class Matrix34 const&>>(
        0x166DD0_Offset, arg1, arg2, arg3, arg4);
}

void TransformVertList(class Vector3* arg1, class Vector3 const* arg2, i32 arg3, class Matrix34 const& arg4)
{
    return stub<cdecl_t<void, class Vector3*, class Vector3 const*, i32, class Matrix34 const&>>(
        0x166B70_Offset, arg1, arg2, arg3, arg4);
}

void TransformVertList(class Vector3** arg1, class Vector3 const** arg2, i32 arg3, class Matrix34 const& arg4)
{
    return stub<cdecl_t<void, class Vector3**, class Vector3 const**, i32, class Matrix34 const&>>(
        0x166C30_Offset, arg1, arg2, arg3, arg4);
}

void TransformVertNorm(class Vector3& arg1, class Vector3& arg2, class Vector3 const& arg3, class Vector3& arg4,
    class Matrix34 const& arg5)
{
    return stub<
        cdecl_t<void, class Vector3&, class Vector3&, class Vector3 const&, class Vector3&, class Matrix34 const&>>(
        0x166A80_Offset, arg1, arg2, arg3, arg4, arg5);
}

/*
void Vector3Array::operator=(class Vector3Array& arg1)
{
    return stub<thiscall_t<void, Vector3Array*, class Vector3Array&>>(0x167030_Offset, this, arg1);
}

class Vector3& Vector3Array::operator[](i32 arg1)
{
    return stub<thiscall_t<class Vector3&, Vector3Array*, i32>>(0x166FB0_Offset, this, arg1);
}

void Vector3Array::BlockCopy(class Vector3Array& arg1)
{
    return stub<thiscall_t<void, Vector3Array*, class Vector3Array&>>(0x167120_Offset, this, arg1);
}

void Vector3Array::Delete()
{
    return stub<thiscall_t<void, Vector3Array*>>(0x166EF0_Offset, this);
}

void Vector3Array::Init(i32 arg1)
{
    return stub<thiscall_t<void, Vector3Array*, i32>>(0x166E80_Offset, this, arg1);
}

void Vector3Array::NewTable(i32 arg1)
{
    return stub<thiscall_t<void, Vector3Array*, i32>>(0x166F40_Offset, this, arg1);
}

void Vector3Type::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, Vector3Type*, void*, i32>>(0x1673F0_Offset, this, arg1, arg2);
}

void Vector3Type::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, Vector3Type*, class MiniParser*, void*>>(0x167360_Offset, this, arg1, arg2);
}

void* Vector3Type::New(i32 arg1)
{
    return stub<thiscall_t<void*, Vector3Type*, i32>>(0x1673A0_Offset, this, arg1);
}

void Vector3Type::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, Vector3Type*, class MiniParser*, void*>>(0x167320_Offset, this, arg1, arg2);
}

u32 Vector3Type::SizeOf()
{
    return stub<thiscall_t<u32, Vector3Type*>>(0x167390_Offset, this);
}
*/

define_dummy_symbol(vector7_vector3);
