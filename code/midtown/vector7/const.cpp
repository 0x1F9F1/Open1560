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

#include "const.h"

void ResetMathSpeed()
{
    return stub<cdecl_t<void>>(0x173530_Offset);
}

void SetMathSpeedFast()
{
    return stub<cdecl_t<void>>(0x173510_Offset);
}

void SetMathSpeedMed()
{
    return stub<cdecl_t<void>>(0x1734F0_Offset);
}

void SetMathSpeedSlow()
{
    return stub<cdecl_t<void>>(0x1734D0_Offset);
}

void IntArray::operator=(class IntArray& arg1)
{
    return stub<thiscall_t<void, IntArray*, class IntArray&>>(0x1736D0_Offset, this, arg1);
}

i32& IntArray::operator[](i32 arg1)
{
    return stub<thiscall_t<i32&, IntArray*, i32>>(0x173670_Offset, this, arg1);
}

void IntArray::BlockCopy(class IntArray& arg1)
{
    return stub<thiscall_t<void, IntArray*, class IntArray&>>(0x173790_Offset, this, arg1);
}

void IntArray::Delete()
{
    return stub<thiscall_t<void, IntArray*>>(0x1735B0_Offset, this);
}

void IntArray::Init(i32 arg1)
{
    return stub<thiscall_t<void, IntArray*, i32>>(0x173540_Offset, this, arg1);
}

void IntArray::NewTable(i32 arg1)
{
    return stub<thiscall_t<void, IntArray*, i32>>(0x173600_Offset, this, arg1);
}

void FloatArray::operator=(class FloatArray& arg1)
{
    return stub<thiscall_t<void, FloatArray*, class FloatArray&>>(0x1739F0_Offset, this, arg1);
}

f32& FloatArray::operator[](i32 arg1)
{
    return stub<thiscall_t<f32&, FloatArray*, i32>>(0x173990_Offset, this, arg1);
}

void FloatArray::BlockCopy(class FloatArray& arg1)
{
    return stub<thiscall_t<void, FloatArray*, class FloatArray&>>(0x173AB0_Offset, this, arg1);
}

void FloatArray::Delete()
{
    return stub<thiscall_t<void, FloatArray*>>(0x1738D0_Offset, this);
}

void FloatArray::Init(i32 arg1)
{
    return stub<thiscall_t<void, FloatArray*, i32>>(0x173860_Offset, this, arg1);
}

void FloatArray::NewTable(i32 arg1)
{
    return stub<thiscall_t<void, FloatArray*, i32>>(0x173920_Offset, this, arg1);
}

define_dummy_symbol(vector7_const);
