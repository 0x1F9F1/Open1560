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

define_dummy_symbol(mmeffects_mmnumber);

#include "mmnumber.h"

mmNumber::mmNumber()
{
    unimplemented();
}

mmNumber::~mmNumber()
{
    unimplemented();
}

void mmNumber::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmNumber*, class Bank*>>(0x4FECA0, this, arg1);
}

void mmNumber::Cull()
{
    return stub<thiscall_t<void, mmNumber*>>(0x4FEB90, this);
}

class MetaClass* mmNumber::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmNumber*>>(0x4FEE20, this);
}

void mmNumber::Init(class mmNumberFont* arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmNumber*, class mmNumberFont*, f32, f32>>(0x4FEAB0, this, arg1, arg2, arg3);
}

void mmNumber::Printf(char const* arg1, ...)
{
    unimplemented(arg1);
}

void mmNumber::SetString(char* arg1)
{
    return stub<thiscall_t<void, mmNumber*, char*>>(0x4FEB20, this, arg1);
}

void mmNumber::Update()
{
    return stub<thiscall_t<void, mmNumber*>>(0x4FEB70, this);
}

void mmNumber::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4FECB0);
}

mmNumberFont::mmNumberFont()
{
    unimplemented();
}

mmNumberFont::~mmNumberFont()
{
    unimplemented();
}

void mmNumberFont::LoadFont(char* arg1, i32 arg2, u32 arg3)
{
    return stub<thiscall_t<void, mmNumberFont*, char*, i32, u32>>(0x4FE780, this, arg1, arg2, arg3);
}

void mmNumberFont::LoadLocFont(char* arg1, struct LocString* arg2, i32 arg3, u32 arg4)
{
    return stub<thiscall_t<void, mmNumberFont*, char*, struct LocString*, i32, u32>>(
        0x4FE880, this, arg1, arg2, arg3, arg4);
}
