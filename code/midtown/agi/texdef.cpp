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
    return stub<thiscall_t<void, agiTexParameters*, class Stream*>>(0x156120_Offset, this, arg1);
}

void agiTexParameters::Save(class Stream* arg1)
{
    return stub<thiscall_t<void, agiTexParameters*, class Stream*>>(0x156170_Offset, this, arg1);
}

i32 agiTexDef::IsAvailable()
{
    return stub<thiscall_t<i32, agiTexDef*>>(0x1567F0_Offset, this);
}

void agiTexDef::Set(class Vector2& arg1, class Vector2& arg2)
{
    return stub<thiscall_t<void, agiTexDef*, class Vector2&, class Vector2&>>(0x - 400000_Offset, this, arg1, arg2);
}

i32 agiTexDef::Lock(struct agiTexLock& arg1)
{
    return stub<thiscall_t<i32, agiTexDef*, struct agiTexLock&>>(0x156440_Offset, this, arg1);
}

void agiTexDef::Unlock(struct agiTexLock& arg1)
{
    return stub<thiscall_t<void, agiTexDef*, struct agiTexLock&>>(0x156450_Offset, this, arg1);
}

void agiTexDef::Request()
{
    return stub<thiscall_t<void, agiTexDef*>>(0x1567E0_Offset, this);
}

void agiTexDef::CheckSurface()
{
    return stub<thiscall_t<void, agiTexDef*>>(0x1562F0_Offset, this);
}

void agiTexDef::DoPageIn()
{
    return stub<thiscall_t<void, agiTexDef*>>(0x156550_Offset, this);
}

char* agiTexDef::GetName()
{
    return stub<thiscall_t<char*, agiTexDef*>>(0x156400_Offset, this);
}

i32 agiTexDef::Init(class agiTexParameters const& arg1)
{
    return stub<thiscall_t<i32, agiTexDef*, class agiTexParameters const&>>(0x156380_Offset, this, arg1);
}

i32 agiTexDef::IsTexture()
{
    return stub<thiscall_t<i32, agiTexDef*>>(0x156430_Offset, this);
}

i32 agiTexDef::LockSurfaceIfResident()
{
    return stub<thiscall_t<i32, agiTexDef*>>(0x156770_Offset, this);
}

void agiTexDef::PageInSurface()
{
    return stub<thiscall_t<void, agiTexDef*>>(0x1566B0_Offset, this);
}

i32 agiTexDef::Reload()
{
    return stub<thiscall_t<i32, agiTexDef*>>(0x156310_Offset, this);
}

void agiTexDef::UnlockAndFreeSurface()
{
    return stub<thiscall_t<void, agiTexDef*>>(0x1567C0_Offset, this);
}

void agiTexDef::UnlockSurface()
{
    return stub<thiscall_t<void, agiTexDef*>>(0x1567A0_Offset, this);
}

void agiTexDef::PageInCallback(void* arg1)
{
    return stub<cdecl_t<void, void*>>(0x1566A0_Offset, arg1);
}

void agiTexDef::PageOutCallback(void* arg1, i32 arg2)
{
    return stub<cdecl_t<void, void*, i32>>(0x156460_Offset, arg1, arg2);
}

agiTexDef::agiTexDef(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

agiTexDef::~agiTexDef()
{
    unimplemented(arg1);
}

void ShutdownLutQueue()
{
    return stub<cdecl_t<void>>(0x156530_Offset);
}

void UpdateLutQueue()
{
    return stub<cdecl_t<void>>(0x1564A0_Offset);
}

char* agiTexLut::GetName()
{
    return stub<thiscall_t<char*, agiTexLut*>>(0x1568D0_Offset, this);
}

i32 agiTexLut::Init(char* arg1)
{
    return stub<thiscall_t<i32, agiTexLut*, char*>>(0x156800_Offset, this, arg1);
}

agiTexLut::agiTexLut(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

agiTexLut::~agiTexLut()
{
    unimplemented(arg1);
}
