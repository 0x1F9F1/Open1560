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

#include "viewport.h"

agiViewParameters::agiViewParameters()
{
    unimplemented();
}

void agiViewParameters::Frustum(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6)
{
    return stub<thiscall_t<void, agiViewParameters*, f32, f32, f32, f32, f32, f32>>(
        0x1573B0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void agiViewParameters::Ortho(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, agiViewParameters*, f32, f32, f32, f32>>(
        0x157310_Offset, this, arg1, arg2, arg3, arg4);
}

void agiViewParameters::Perspective(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, agiViewParameters*, f32, f32, f32, f32>>(
        0x157240_Offset, this, arg1, arg2, arg3, arg4);
}

void agiViewParameters::Project(class Vector3& arg1, class Vector3& arg2)
{
    return stub<thiscall_t<void, agiViewParameters*, class Vector3&, class Vector3&>>(
        0x157960_Offset, this, arg1, arg2);
}

void agiViewParameters::SetBill(class Vector3& arg1)
{
    return stub<thiscall_t<void, agiViewParameters*, class Vector3&>>(0x157590_Offset, this, arg1);
}

void agiViewParameters::SetBillY(class Matrix34& arg1)
{
    return stub<thiscall_t<void, agiViewParameters*, class Matrix34&>>(0x1576D0_Offset, this, arg1);
}

i32 agiViewParameters::SphereVisible(class Vector3& arg1, f32 arg2)
{
    return stub<thiscall_t<i32, agiViewParameters*, class Vector3&, f32>>(0x157490_Offset, this, arg1, arg2);
}

void agiViewport::Activate()
{
    return stub<thiscall_t<void, agiViewport*>>(0x - 400000_Offset, this);
}

void agiViewport::SetBackground(class Vector3& arg1)
{
    return stub<thiscall_t<void, agiViewport*, class Vector3&>>(0x - 400000_Offset, this, arg1);
}

void agiViewport::Clear(i32 arg1)
{
    return stub<thiscall_t<void, agiViewport*, i32>>(0x - 400000_Offset, this, arg1);
}

void agiViewport::SetWorld(class Matrix34& arg1)
{
    return stub<thiscall_t<void, agiViewport*, class Matrix34&>>(0x1578A0_Offset, this, arg1);
}

f32 agiViewport::Aspect()
{
    return stub<thiscall_t<f32, agiViewport*>>(0x157870_Offset, this);
}

char* agiViewport::GetName()
{
    return stub<thiscall_t<char*, agiViewport*>>(0x1579D0_Offset, this);
}

agiViewport::agiViewport(class agiPipeline* arg1)
{
    unimplemented();
}

agiViewport::~agiViewport()
{
    unimplemented();
}

define_dummy_symbol(agi_viewport);
