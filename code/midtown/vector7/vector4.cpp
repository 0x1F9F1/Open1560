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

define_dummy_symbol(vector7_vector4);

#include "vector4.h"

class Vector4 Vector4::operator!()
{
    return stub<thiscall_t<class Vector4, Vector4*>>(0x56DD00, this);
}

class Vector4 Vector4::operator/(f32 arg1)
{
    return stub<thiscall_t<class Vector4, Vector4*, f32>>(0x56DC70, this, arg1);
}

f32 Vector4::operator^(class Vector4 const& arg1)
{
    return stub<thiscall_t<f32, Vector4*, class Vector4 const&>>(0x570D70, this, arg1);
}

void Vector4::Bilinear(f32 arg1, f32 arg2, class Vector4 const& arg3, class Vector4 const& arg4,
    class Vector4 const& arg5, class Vector4 const& arg6)
{
    return stub<thiscall_t<void, Vector4*, f32, f32, class Vector4 const&, class Vector4 const&, class Vector4 const&,
        class Vector4 const&>>(0x56DD80, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void Vector4::CalculatePlane(class Vector3 const& arg1, class Vector3 const& arg2, class Vector3 const& arg3)
{
    return stub<thiscall_t<void, Vector4*, class Vector3 const&, class Vector3 const&, class Vector3 const&>>(
        0x56DDD0, this, arg1, arg2, arg3);
}

void Vector4::GetLookAt(class Vector3 const& arg1, class Vector3* arg2, class Vector3* arg3)
{
    return stub<thiscall_t<void, Vector4*, class Vector3 const&, class Vector3*, class Vector3*>>(
        0x56DED0, this, arg1, arg2, arg3);
}

void Vector4::Lerp(f32 arg1, class Vector4 const& arg2, class Vector4 const& arg3)
{
    return stub<thiscall_t<void, Vector4*, f32, class Vector4 const&, class Vector4 const&>>(
        0x56DF50, this, arg1, arg2, arg3);
}

f32 Vector4::Mag()
{
    return stub<thiscall_t<f32, Vector4*>>(0x56DBA0, this);
}

void Vector4::Set(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, Vector4*, f32, f32, f32, f32>>(0x570D50, this, arg1, arg2, arg3, arg4);
}

void Vector4Array::operator=(class Vector4Array& arg1)
{
    return stub<thiscall_t<void, Vector4Array*, class Vector4Array&>>(0x56E1F0, this, arg1);
}

class Vector4& Vector4Array::operator[](i32 arg1)
{
    return stub<thiscall_t<class Vector4&, Vector4Array*, i32>>(0x56E170, this, arg1);
}

void Vector4Array::BlockCopy(class Vector4Array& arg1)
{
    return stub<thiscall_t<void, Vector4Array*, class Vector4Array&>>(0x56E2F0, this, arg1);
}

void Vector4Array::Delete()
{
    return stub<thiscall_t<void, Vector4Array*>>(0x56E0B0, this);
}

void Vector4Array::Init(i32 arg1)
{
    return stub<thiscall_t<void, Vector4Array*, i32>>(0x56E040, this, arg1);
}

void Vector4Array::NewTable(i32 arg1)
{
    return stub<thiscall_t<void, Vector4Array*, i32>>(0x56E100, this, arg1);
}

void Vector4Type::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, Vector4Type*, void*, i32>>(0x56E4D0, this, arg1, arg2);
}

void Vector4Type::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, Vector4Type*, class MiniParser*, void*>>(0x56E430, this, arg1, arg2);
}

void* Vector4Type::New(i32 arg1)
{
    return stub<thiscall_t<void*, Vector4Type*, i32>>(0x56E480, this, arg1);
}

void Vector4Type::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, Vector4Type*, class MiniParser*, void*>>(0x56E3F0, this, arg1, arg2);
}

u32 Vector4Type::SizeOf()
{
    return stub<thiscall_t<u32, Vector4Type*>>(0x56E470, this);
}
