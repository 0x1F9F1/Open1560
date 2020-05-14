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

define_dummy_symbol(agi_viewport);

#include "viewport.h"

agiViewParameters::agiViewParameters()
{
    unimplemented();
}

void agiViewParameters::Frustum(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6)
{
    return stub<thiscall_t<void, agiViewParameters*, f32, f32, f32, f32, f32, f32>>(
        0x5573B0, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void agiViewParameters::Ortho(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, agiViewParameters*, f32, f32, f32, f32>>(0x557310, this, arg1, arg2, arg3, arg4);
}

void agiViewParameters::Perspective(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, agiViewParameters*, f32, f32, f32, f32>>(0x557240, this, arg1, arg2, arg3, arg4);
}

void agiViewParameters::Project(class Vector3& arg1, class Vector3& arg2)
{
    return stub<thiscall_t<void, agiViewParameters*, class Vector3&, class Vector3&>>(0x557960, this, arg1, arg2);
}

void agiViewParameters::SetBill(class Vector3& arg1)
{
    return stub<thiscall_t<void, agiViewParameters*, class Vector3&>>(0x557590, this, arg1);
}

void agiViewParameters::SetBillY(class Matrix34& arg1)
{
    return stub<thiscall_t<void, agiViewParameters*, class Matrix34&>>(0x5576D0, this, arg1);
}

i32 agiViewParameters::SphereVisible(class Vector3& arg1, f32 arg2)
{
    return stub<thiscall_t<i32, agiViewParameters*, class Vector3&, f32>>(0x557490, this, arg1, arg2);
}

void agiViewport::SetWorld(class Matrix34& arg1)
{
    return stub<thiscall_t<void, agiViewport*, class Matrix34&>>(0x5578A0, this, arg1);
}

f32 agiViewport::Aspect()
{
    return stub<thiscall_t<f32, agiViewport*>>(0x557870, this);
}

char* agiViewport::GetName()
{
    return stub<thiscall_t<char*, agiViewport*>>(0x5579D0, this);
}

agiViewport::agiViewport(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

agiViewport::~agiViewport()
{
    unimplemented();
}
