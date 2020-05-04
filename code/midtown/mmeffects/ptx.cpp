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

#include "ptx.h"

asParticles::asParticles()
{
    unimplemented();
}

asParticles::~asParticles()
{
    unimplemented();
}

void asParticles::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asParticles*, class Bank*>>(0x100750_Offset, this, arg1);
}

void asParticles::Blast(i32 arg1, class asBirthRule* arg2)
{
    return stub<thiscall_t<void, asParticles*, i32, class asBirthRule*>>(0x1005F0_Offset, this, arg1, arg2);
}

void asParticles::Cull()
{
    return stub<thiscall_t<void, asParticles*>>(0x1006B0_Offset, this);
}

class MetaClass* asParticles::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asParticles*>>(0x100990_Offset, this);
}

void asParticles::Init(i32 arg1, i32 arg2, i32 arg3, i32 arg4, struct agiMeshCardVertex* arg5)
{
    return stub<thiscall_t<void, asParticles*, i32, i32, i32, i32, struct agiMeshCardVertex*>>(
        0x1001A0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void asParticles::Reset()
{
    return stub<thiscall_t<void, asParticles*>>(0x100210_Offset, this);
}

void asParticles::SetTexture(char* arg1)
{
    return stub<thiscall_t<void, asParticles*, char*>>(0x100250_Offset, this, arg1);
}

void asParticles::SetTexture(class agiTexDef* arg1)
{
    return stub<thiscall_t<void, asParticles*, class agiTexDef*>>(0x100220_Offset, this, arg1);
}

void asParticles::Update()
{
    return stub<thiscall_t<void, asParticles*>>(0x1002A0_Offset, this);
}

void asParticles::DeclareFields()
{
    return stub<cdecl_t<void>>(0x100830_Offset);
}

i32 cmpPtx(void const* arg1, void const* arg2)
{
    return stub<cdecl_t<i32, void const*, void const*>>(0x100690_Offset, arg1, arg2);
}

define_dummy_symbol(mmeffects_ptx);
