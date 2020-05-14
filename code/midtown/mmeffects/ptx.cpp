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

define_dummy_symbol(mmeffects_ptx);

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
    return stub<thiscall_t<void, asParticles*, class Bank*>>(0x500750, this, arg1);
}

void asParticles::Blast(i32 arg1, class asBirthRule* arg2)
{
    return stub<thiscall_t<void, asParticles*, i32, class asBirthRule*>>(0x5005F0, this, arg1, arg2);
}

void asParticles::Cull()
{
    return stub<thiscall_t<void, asParticles*>>(0x5006B0, this);
}

class MetaClass* asParticles::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asParticles*>>(0x500990, this);
}

void asParticles::Init(i32 arg1, i32 arg2, i32 arg3, i32 arg4, struct agiMeshCardVertex* arg5)
{
    return stub<thiscall_t<void, asParticles*, i32, i32, i32, i32, struct agiMeshCardVertex*>>(
        0x5001A0, this, arg1, arg2, arg3, arg4, arg5);
}

void asParticles::Reset()
{
    return stub<thiscall_t<void, asParticles*>>(0x500210, this);
}

void asParticles::SetTexture(char* arg1)
{
    return stub<thiscall_t<void, asParticles*, char*>>(0x500250, this, arg1);
}

void asParticles::SetTexture(class agiTexDef* arg1)
{
    return stub<thiscall_t<void, asParticles*, class agiTexDef*>>(0x500220, this, arg1);
}

void asParticles::Update()
{
    return stub<thiscall_t<void, asParticles*>>(0x5002A0, this);
}

void asParticles::DeclareFields()
{
    return stub<cdecl_t<void>>(0x500830);
}

i32 cmpPtx(void const* arg1, void const* arg2)
{
    return stub<cdecl_t<i32, void const*, void const*>>(0x500690, arg1, arg2);
}
