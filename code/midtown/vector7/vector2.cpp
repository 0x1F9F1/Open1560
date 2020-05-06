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

define_dummy_symbol(vector7_vector2);

#include "vector2.h"

Vector2::Vector2(class Vector2 const& arg1)
{
    unimplemented(arg1);
}

class Vector2 Vector2::operator/(f32 arg1)
{
    return stub<thiscall_t<class Vector2, Vector2*, f32>>(0x571110, this, arg1);
}

class Vector2 Vector2::operator~()
{
    return stub<thiscall_t<class Vector2, Vector2*>>(0x571170, this);
}

f32 Vector2::InvMag()
{
    return stub<thiscall_t<f32, Vector2*>>(0x571260, this);
}

f32 Vector2::Mag()
{
    return stub<thiscall_t<f32, Vector2*>>(0x5711E0, this);
}

void Vector2Array::operator=(class Vector2Array& arg1)
{
    return stub<thiscall_t<void, Vector2Array*, class Vector2Array&>>(0x571460, this, arg1);
}

class Vector2& Vector2Array::operator[](i32 arg1)
{
    return stub<thiscall_t<class Vector2&, Vector2Array*, i32>>(0x5713F0, this, arg1);
}

void Vector2Array::BlockCopy(class Vector2Array& arg1)
{
    return stub<thiscall_t<void, Vector2Array*, class Vector2Array&>>(0x571540, this, arg1);
}

void Vector2Array::Delete()
{
    return stub<thiscall_t<void, Vector2Array*>>(0x571330, this);
}

void Vector2Array::Init(i32 arg1)
{
    return stub<thiscall_t<void, Vector2Array*, i32>>(0x5712C0, this, arg1);
}

void Vector2Array::NewTable(i32 arg1)
{
    return stub<thiscall_t<void, Vector2Array*, i32>>(0x571380, this, arg1);
}

void Vector2Type::Delete(void* arg1, i32 arg2)
{
    return stub<thiscall_t<void, Vector2Type*, void*, i32>>(0x571700, this, arg1, arg2);
}

void Vector2Type::Load(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, Vector2Type*, class MiniParser*, void*>>(0x571670, this, arg1, arg2);
}

void* Vector2Type::New(i32 arg1)
{
    return stub<thiscall_t<void*, Vector2Type*, i32>>(0x5716B0, this, arg1);
}

void Vector2Type::Save(class MiniParser* arg1, void* arg2)
{
    return stub<thiscall_t<void, Vector2Type*, class MiniParser*, void*>>(0x571640, this, arg1, arg2);
}

u32 Vector2Type::SizeOf()
{
    return stub<thiscall_t<u32, Vector2Type*>>(0x5716A0, this);
}
