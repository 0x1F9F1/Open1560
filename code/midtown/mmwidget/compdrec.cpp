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

define_dummy_symbol(mmwidget_compdrec);

#include "compdrec.h"

mmCompDRecord::mmCompDRecord()
{
    unimplemented();
}

mmCompDRecord::~mmCompDRecord()
{
    unimplemented(arg1);
}

void mmCompDRecord::Cull()
{
    return stub<thiscall_t<void, mmCompDRecord*>>(0x4B5FC0, this);
}

void mmCompDRecord::DisableBlt()
{
    return stub<thiscall_t<void, mmCompDRecord*>>(0x4B6090, this);
}

void mmCompDRecord::Init(i32 arg1, char* arg2, f32 arg3, char* arg4, i32 arg5, i32 arg6, i32 arg7)
{
    return stub<thiscall_t<void, mmCompDRecord*, i32, char*, f32, char*, i32, i32, i32>>(
        0x4B5B70, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void mmCompDRecord::InitTitle(f32 arg1, f32 arg2, f32 arg3, f32 arg4, struct LocString* arg5, struct LocString* arg6,
    struct LocString* arg7, struct LocString* arg8, struct LocString* arg9, i32 arg10)
{
    return stub<thiscall_t<void, mmCompDRecord*, f32, f32, f32, f32, struct LocString*, struct LocString*,
        struct LocString*, struct LocString*, struct LocString*, i32>>(
        0x4B5C60, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}

void mmCompDRecord::LoadBitmap(char* arg1)
{
    return stub<thiscall_t<void, mmCompDRecord*, char*>>(0x4B5CD0, this, arg1);
}

void mmCompDRecord::Reset()
{
    return stub<thiscall_t<void, mmCompDRecord*>>(0x4B5D40, this);
}

void mmCompDRecord::SetBltXY(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmCompDRecord*, f32, f32>>(0x4B5F70, this, arg1, arg2);
}

void mmCompDRecord::SetGeometry(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, mmCompDRecord*, f32, f32, f32, f32>>(0x4B5F40, this, arg1, arg2, arg3, arg4);
}

void mmCompDRecord::SetPosition(class mmTextNode* arg1, i32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmCompDRecord*, class mmTextNode*, i32, f32>>(0x4B5EA0, this, arg1, arg2, arg3);
}

void mmCompDRecord::SetSubwidgetGeometry()
{
    return stub<thiscall_t<void, mmCompDRecord*>>(0x4B5D80, this);
}

void mmCompDRecord::Update()
{
    return stub<thiscall_t<void, mmCompDRecord*>>(0x4B5D50, this);
}
