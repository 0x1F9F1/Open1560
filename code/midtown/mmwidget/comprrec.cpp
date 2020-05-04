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

#include "comprrec.h"

mmCompRaceRecord::mmCompRaceRecord()
{
    unimplemented();
}

mmCompRaceRecord::~mmCompRaceRecord()
{
    unimplemented();
}

void mmCompRaceRecord::Cull()
{
    return stub<thiscall_t<void, mmCompRaceRecord*>>(0xB4D80_Offset, this);
}

void mmCompRaceRecord::Init(i32 arg1, char* arg2, char* arg3, char* arg4, char* arg5, char* arg6, i32 arg7, i32 arg8)
{
    return stub<thiscall_t<void, mmCompRaceRecord*, i32, char*, char*, char*, char*, char*, i32, i32>>(
        0xB49D0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

void mmCompRaceRecord::InitTitle(f32 arg1, f32 arg2, f32 arg3, f32 arg4, struct LocString* arg5, struct LocString* arg6,
    struct LocString* arg7, struct LocString* arg8, struct LocString* arg9, struct LocString* arg10, i32 arg11)
{
    return stub<thiscall_t<void, mmCompRaceRecord*, f32, f32, f32, f32, struct LocString*, struct LocString*,
        struct LocString*, struct LocString*, struct LocString*, struct LocString*, i32>>(
        0xB4A60_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}

void mmCompRaceRecord::LoadBitmap(char* arg1)
{
    return stub<thiscall_t<void, mmCompRaceRecord*, char*>>(0xB4AD0_Offset, this, arg1);
}

void mmCompRaceRecord::Reset()
{
    return stub<thiscall_t<void, mmCompRaceRecord*>>(0xB4B20_Offset, this);
}

void mmCompRaceRecord::SelectIfRaceType(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmCompRaceRecord*, i32, i32>>(0xB4CA0_Offset, this, arg1, arg2);
}

void mmCompRaceRecord::SetGeometry(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, mmCompRaceRecord*, f32, f32, f32, f32>>(0xB4C70_Offset, this, arg1, arg2, arg3, arg4);
}

void mmCompRaceRecord::SetPosition(class mmTextNode* arg1, i32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmCompRaceRecord*, class mmTextNode*, i32, f32>>(
        0xB4CE0_Offset, this, arg1, arg2, arg3);
}

void mmCompRaceRecord::SetSubwidgetGeometry()
{
    return stub<thiscall_t<void, mmCompRaceRecord*>>(0xB4B40_Offset, this);
}

void mmCompRaceRecord::Update()
{
    return stub<thiscall_t<void, mmCompRaceRecord*>>(0xB4B30_Offset, this);
}

mmCompBase::~mmCompBase()
{
    unimplemented();
}

void mmCompBase::DisableBlt()
{
    return stub<thiscall_t<void, mmCompBase*>>(0xB4E00_Offset, this);
}

void mmCompBase::SetBltXY(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmCompBase*, f32, f32>>(0xB4E10_Offset, this, arg1, arg2);
}

void mmCompBase::Action(union eqEvent arg1, f32 arg2, f32 arg3, i32 arg4)
{
    return stub<thiscall_t<void, mmCompBase*, union eqEvent, f32, f32, i32>>(
        0xB4E70_Offset, this, arg1, arg2, arg3, arg4);
}

void mmCompBase::Action(union eqEvent arg1)
{
    return stub<thiscall_t<void, mmCompBase*, union eqEvent>>(0xB4E40_Offset, this, arg1);
}

void mmCompBase::CaptureAction(union eqEvent arg1)
{
    return stub<thiscall_t<void, mmCompBase*, union eqEvent>>(0xB4E50_Offset, this, arg1);
}

void mmCompBase::Switch(i32 arg1)
{
    return stub<thiscall_t<void, mmCompBase*, i32>>(0xB4E60_Offset, this, arg1);
}

void mmCompBase::EvalMouseXY(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmCompBase*, f32, f32>>(0xB4E80_Offset, this, arg1, arg2);
}

void mmCompBase::Highlight(class mmTextNode* arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmCompBase*, class mmTextNode*, i32>>(0xB4E90_Offset, this, arg1, arg2);
}

void mmCompBase::SetGeometry(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, mmCompBase*, f32, f32, f32, f32>>(0xB4EA0_Offset, this, arg1, arg2, arg3, arg4);
}

void mmCompBase::SetPosition(class mmTextNode* arg1, i32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmCompBase*, class mmTextNode*, i32, f32>>(0x - 400000_Offset, this, arg1, arg2, arg3);
}

void mmCompBase::Reset()
{
    return stub<thiscall_t<void, mmCompBase*>>(0xBF2D0_Offset, this);
}

void mmCompBase::Update()
{
    return stub<thiscall_t<void, mmCompBase*>>(0xBF2E0_Offset, this);
}

define_dummy_symbol(mmwidget_comprrec);
