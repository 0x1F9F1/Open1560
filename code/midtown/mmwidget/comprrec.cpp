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

define_dummy_symbol(mmwidget_comprrec);

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
    return stub<thiscall_t<void, mmCompRaceRecord*>>(0x4B4D80, this);
}

void mmCompRaceRecord::Init(i32 arg1, char* arg2, char* arg3, char* arg4, char* arg5, char* arg6, i32 arg7, i32 arg8)
{
    return stub<thiscall_t<void, mmCompRaceRecord*, i32, char*, char*, char*, char*, char*, i32, i32>>(
        0x4B49D0, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

void mmCompRaceRecord::InitTitle(f32 arg1, f32 arg2, f32 arg3, f32 arg4, struct LocString* arg5, struct LocString* arg6,
    struct LocString* arg7, struct LocString* arg8, struct LocString* arg9, struct LocString* arg10, i32 arg11)
{
    return stub<thiscall_t<void, mmCompRaceRecord*, f32, f32, f32, f32, struct LocString*, struct LocString*,
        struct LocString*, struct LocString*, struct LocString*, struct LocString*, i32>>(
        0x4B4A60, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}

void mmCompRaceRecord::LoadBitmap(char* arg1)
{
    return stub<thiscall_t<void, mmCompRaceRecord*, char*>>(0x4B4AD0, this, arg1);
}

void mmCompRaceRecord::Reset()
{
    return stub<thiscall_t<void, mmCompRaceRecord*>>(0x4B4B20, this);
}

void mmCompRaceRecord::SelectIfRaceType(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmCompRaceRecord*, i32, i32>>(0x4B4CA0, this, arg1, arg2);
}

void mmCompRaceRecord::SetGeometry(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, mmCompRaceRecord*, f32, f32, f32, f32>>(0x4B4C70, this, arg1, arg2, arg3, arg4);
}

void mmCompRaceRecord::SetPosition(class mmTextNode* arg1, i32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmCompRaceRecord*, class mmTextNode*, i32, f32>>(0x4B4CE0, this, arg1, arg2, arg3);
}

void mmCompRaceRecord::SetSubwidgetGeometry()
{
    return stub<thiscall_t<void, mmCompRaceRecord*>>(0x4B4B40, this);
}

void mmCompRaceRecord::Update()
{
    return stub<thiscall_t<void, mmCompRaceRecord*>>(0x4B4B30, this);
}

mmCompBase::~mmCompBase()
{
    unimplemented();
}

void mmCompBase::DisableBlt()
{
    return stub<thiscall_t<void, mmCompBase*>>(0x4B4E00, this);
}

void mmCompBase::SetBltXY(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmCompBase*, f32, f32>>(0x4B4E10, this, arg1, arg2);
}

void mmCompBase::Action(union eqEvent arg1, f32 arg2, f32 arg3, i32 arg4)
{
    return stub<thiscall_t<void, mmCompBase*, union eqEvent, f32, f32, i32>>(0x4B4E70, this, arg1, arg2, arg3, arg4);
}

void mmCompBase::Action(union eqEvent arg1)
{
    return stub<thiscall_t<void, mmCompBase*, union eqEvent>>(0x4B4E40, this, arg1);
}

void mmCompBase::CaptureAction(union eqEvent arg1)
{
    return stub<thiscall_t<void, mmCompBase*, union eqEvent>>(0x4B4E50, this, arg1);
}

void mmCompBase::Switch(i32 arg1)
{
    return stub<thiscall_t<void, mmCompBase*, i32>>(0x4B4E60, this, arg1);
}

void mmCompBase::EvalMouseXY(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmCompBase*, f32, f32>>(0x4B4E80, this, arg1, arg2);
}

void mmCompBase::Highlight(class mmTextNode* arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmCompBase*, class mmTextNode*, i32>>(0x4B4E90, this, arg1, arg2);
}

void mmCompBase::SetGeometry(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, mmCompBase*, f32, f32, f32, f32>>(0x4B4EA0, this, arg1, arg2, arg3, arg4);
}

void mmCompBase::Reset()
{
    return stub<thiscall_t<void, mmCompBase*>>(0x4BF2D0, this);
}

void mmCompBase::Update()
{
    return stub<thiscall_t<void, mmCompBase*>>(0x4BF2E0, this);
}
