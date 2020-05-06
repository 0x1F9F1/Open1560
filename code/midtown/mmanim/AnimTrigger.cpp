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

define_dummy_symbol(mmanim_AnimTrigger);

#include "AnimTrigger.h"

mmAnimTrigger::mmAnimTrigger()
{
    unimplemented();
}

mmAnimTrigger::~mmAnimTrigger()
{
    unimplemented();
}

i32 mmAnimTrigger::CheckCondition()
{
    return stub<thiscall_t<i32, mmAnimTrigger*>>(0x4C4290, this);
}

i32 mmAnimTrigger::CheckObjectDistance()
{
    return stub<thiscall_t<i32, mmAnimTrigger*>>(0x4C43B0, this);
}

i32 mmAnimTrigger::CheckObjectHit()
{
    return stub<thiscall_t<i32, mmAnimTrigger*>>(0x4C4300, this);
}

i32 mmAnimTrigger::CheckStateStatus()
{
    return stub<thiscall_t<i32, mmAnimTrigger*>>(0x4C4350, this);
}

i32 mmAnimTrigger::CheckTimeDelay()
{
    return stub<thiscall_t<i32, mmAnimTrigger*>>(0x4C4320, this);
}

void mmAnimTrigger::Init(f32 arg1)
{
    return stub<thiscall_t<void, mmAnimTrigger*, f32>>(0x4C4270, this, arg1);
}

void mmAnimTrigger::Init(class Vector3* arg1, f32* arg2)
{
    return stub<thiscall_t<void, mmAnimTrigger*, class Vector3*, f32*>>(0x4C4220, this, arg1, arg2);
}

void mmAnimTrigger::Init(class mmInstance* arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmAnimTrigger*, class mmInstance*, i32>>(0x4C4200, this, arg1, arg2);
}

void mmAnimTrigger::Init(i32* arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmAnimTrigger*, i32*, f32>>(0x4C4240, this, arg1, arg2);
}

void mmAnimTrigger::Reset()
{
    return stub<thiscall_t<void, mmAnimTrigger*>>(0x4C43A0, this);
}
