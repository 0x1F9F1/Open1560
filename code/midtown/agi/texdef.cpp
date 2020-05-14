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

define_dummy_symbol(agi_texdef);

#include "texdef.h"

agiTexParameters::agiTexParameters()
{
    unimplemented();
}

void agiTexParameters::Load(class Stream* arg1)
{
    return stub<thiscall_t<void, agiTexParameters*, class Stream*>>(0x556120, this, arg1);
}

void agiTexParameters::Save(class Stream* arg1)
{
    return stub<thiscall_t<void, agiTexParameters*, class Stream*>>(0x556170, this, arg1);
}

i32 agiTexDef::IsAvailable()
{
    return stub<thiscall_t<i32, agiTexDef*>>(0x5567F0, this);
}

i32 agiTexDef::Lock(struct agiTexLock& arg1)
{
    return stub<thiscall_t<i32, agiTexDef*, struct agiTexLock&>>(0x556440, this, arg1);
}

void agiTexDef::Unlock(struct agiTexLock& arg1)
{
    return stub<thiscall_t<void, agiTexDef*, struct agiTexLock&>>(0x556450, this, arg1);
}

void agiTexDef::Request()
{
    return stub<thiscall_t<void, agiTexDef*>>(0x5567E0, this);
}

void agiTexDef::CheckSurface()
{
    return stub<thiscall_t<void, agiTexDef*>>(0x5562F0, this);
}

void agiTexDef::DoPageIn()
{
    return stub<thiscall_t<void, agiTexDef*>>(0x556550, this);
}

char* agiTexDef::GetName()
{
    return stub<thiscall_t<char*, agiTexDef*>>(0x556400, this);
}

i32 agiTexDef::Init(class agiTexParameters const& arg1)
{
    return stub<thiscall_t<i32, agiTexDef*, class agiTexParameters const&>>(0x556380, this, arg1);
}

i32 agiTexDef::IsTexture()
{
    return stub<thiscall_t<i32, agiTexDef*>>(0x556430, this);
}

i32 agiTexDef::LockSurfaceIfResident()
{
    return stub<thiscall_t<i32, agiTexDef*>>(0x556770, this);
}

void agiTexDef::PageInSurface()
{
    return stub<thiscall_t<void, agiTexDef*>>(0x5566B0, this);
}

i32 agiTexDef::Reload()
{
    return stub<thiscall_t<i32, agiTexDef*>>(0x556310, this);
}

void agiTexDef::UnlockAndFreeSurface()
{
    return stub<thiscall_t<void, agiTexDef*>>(0x5567C0, this);
}

void agiTexDef::UnlockSurface()
{
    return stub<thiscall_t<void, agiTexDef*>>(0x5567A0, this);
}

void agiTexDef::PageInCallback(void* arg1)
{
    return stub<cdecl_t<void, void*>>(0x5566A0, arg1);
}

void agiTexDef::PageOutCallback(void* arg1, i32 arg2)
{
    return stub<cdecl_t<void, void*, i32>>(0x556460, arg1, arg2);
}

agiTexDef::agiTexDef(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

agiTexDef::~agiTexDef()
{
    unimplemented();
}

void ShutdownLutQueue()
{
    return stub<cdecl_t<void>>(0x556530);
}

void UpdateLutQueue()
{
    return stub<cdecl_t<void>>(0x5564A0);
}

char* agiTexLut::GetName()
{
    return stub<thiscall_t<char*, agiTexLut*>>(0x5568D0, this);
}

i32 agiTexLut::Init(char* arg1)
{
    return stub<thiscall_t<i32, agiTexLut*, char*>>(0x556800, this, arg1);
}

agiTexLut::agiTexLut(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

agiTexLut::~agiTexLut()
{
    unimplemented();
}
