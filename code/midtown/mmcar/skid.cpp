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

define_dummy_symbol(mmcar_skid);

#include "skid.h"

mmSkid::mmSkid()
{
    unimplemented();
}

mmSkid::~mmSkid()
{
    unimplemented(arg1);
}

void mmSkid::AddSkid(class Matrix34& arg1, class Vector3* arg2, class agiPhysParameters* arg3, f32 arg4)
{
    return stub<thiscall_t<void, mmSkid*, class Matrix34&, class Vector3*, class agiPhysParameters*, f32>>(
        0x4778A0, this, arg1, arg2, arg3, arg4);
}

void mmSkid::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmSkid*, class Bank*>>(0x478550, this, arg1);
}

void __fastcall mmSkid::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmSkid*, i32>>(0x477AA0, this, arg1);
}

void __fastcall mmSkid::DrawShadow()
{
    return stub<fastcall_t<void, mmSkid*>>(0x477B30, this);
}

void __fastcall mmSkid::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, mmSkid*, class Matrix34 const&>>(0x477A60, this, arg1);
}

class MetaClass* mmSkid::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmSkid*>>(0x478300, this);
}

class Vector3& __fastcall mmSkid::GetPos()
{
    return stub<fastcall_t<class Vector3&, mmSkid*>>(0x477A80, this);
}

void mmSkid::Init(char* arg1)
{
    return stub<thiscall_t<void, mmSkid*, char*>>(0x477870, this, arg1);
}

class Matrix34& __fastcall mmSkid::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmSkid*, class Matrix34&>>(0x477A70, this, arg1);
}

void mmSkid::Update()
{
    return stub<thiscall_t<void, mmSkid*>>(0x477A90, this);
}

void mmSkid::DeclareFields()
{
    return stub<cdecl_t<void>>(0x478180);
}

mmSkidManager::mmSkidManager()
{
    unimplemented();
}

mmSkidManager::~mmSkidManager()
{
    unimplemented(arg1);
}

class MetaClass* mmSkidManager::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmSkidManager*>>(0x478470, this);
}

void mmSkidManager::Init(char* arg1, i32 arg2, class mmWheel* arg3)
{
    return stub<thiscall_t<void, mmSkidManager*, char*, i32, class mmWheel*>>(0x477BD0, this, arg1, arg2, arg3);
}

void mmSkidManager::LayTrack()
{
    return stub<thiscall_t<void, mmSkidManager*>>(0x477D10, this);
}

void mmSkidManager::ReInit(class mmWheel* arg1)
{
    return stub<thiscall_t<void, mmSkidManager*, class mmWheel*>>(0x477C90, this, arg1);
}

void mmSkidManager::Reset()
{
    return stub<thiscall_t<void, mmSkidManager*>>(0x477CC0, this);
}

void mmSkidManager::Update()
{
    return stub<thiscall_t<void, mmSkidManager*>>(0x4780A0, this);
}

void mmSkidManager::DeclareFields()
{
    return stub<cdecl_t<void>>(0x478310);
}
