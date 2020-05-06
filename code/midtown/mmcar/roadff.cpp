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

define_dummy_symbol(mmcar_roadff);

#include "roadff.h"

mmCarRoadFF::mmCarRoadFF()
{
    unimplemented();
}

mmCarRoadFF::~mmCarRoadFF()
{
    unimplemented(arg1);
}

void mmCarRoadFF::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmCarRoadFF*, class Bank*>>(0x481810, this, arg1);
}

void mmCarRoadFF::AssignProperties(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmCarRoadFF*, f32, i32>>(0x481570, this, arg1, arg2);
}

class MetaClass* mmCarRoadFF::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmCarRoadFF*>>(0x481A90, this);
}

i32 mmCarRoadFF::IsPlaying()
{
    return stub<thiscall_t<i32, mmCarRoadFF*>>(0x481760, this);
}

void mmCarRoadFF::Reset()
{
    return stub<thiscall_t<void, mmCarRoadFF*>>(0x481730, this);
}

void mmCarRoadFF::SetFGVals(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmCarRoadFF*, f32, f32, f32>>(0x481610, this, arg1, arg2, arg3);
}

void mmCarRoadFF::Start()
{
    return stub<thiscall_t<void, mmCarRoadFF*>>(0x481700, this);
}

void mmCarRoadFF::Stop()
{
    return stub<thiscall_t<void, mmCarRoadFF*>>(0x481720, this);
}

void mmCarRoadFF::Update()
{
    return stub<thiscall_t<void, mmCarRoadFF*>>(0x481770, this);
}

void mmCarRoadFF::UpdateVals()
{
    return stub<thiscall_t<void, mmCarRoadFF*>>(0x4817C0, this);
}

void mmCarRoadFF::DeclareFields()
{
    return stub<cdecl_t<void>>(0x481920);
}
