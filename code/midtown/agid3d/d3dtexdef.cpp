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

define_dummy_symbol(agid3d_d3dtexdef);

#include "d3dtexdef.h"

agiD3DTexDef::agiD3DTexDef(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

agiD3DTexDef::~agiD3DTexDef()
{
    unimplemented();
}

i32 agiD3DTexDef::BeginGfx()
{
    return stub<thiscall_t<i32, agiD3DTexDef*>>(0x5319E0, this);
}

void agiD3DTexDef::EndGfx()
{
    return stub<thiscall_t<void, agiD3DTexDef*>>(0x531EF0, this);
}

struct IDirect3DTexture2* agiD3DTexDef::GetHandle(i32 arg1)
{
    return stub<thiscall_t<struct IDirect3DTexture2*, agiD3DTexDef*, i32>>(0x531DA0, this, arg1);
}

i32 agiD3DTexDef::IsAvailable()
{
    return stub<thiscall_t<i32, agiD3DTexDef*>>(0x531F60, this);
}

i32 agiD3DTexDef::Lock(struct agiTexLock& arg1)
{
    return stub<thiscall_t<i32, agiD3DTexDef*, struct agiTexLock&>>(0x531E20, this, arg1);
}

void agiD3DTexDef::Request()
{
    return stub<thiscall_t<void, agiD3DTexDef*>>(0x531D40, this);
}

void agiD3DTexDef::Restore()
{
    return stub<thiscall_t<void, agiD3DTexDef*>>(0x531F90, this);
}

void agiD3DTexDef::Set(class Vector2& arg1, class Vector2& arg2)
{
    return stub<thiscall_t<void, agiD3DTexDef*, class Vector2&, class Vector2&>>(0x531F70, this, arg1, arg2);
}

void agiD3DTexDef::Unlock(struct agiTexLock& arg1)
{
    return stub<thiscall_t<void, agiD3DTexDef*, struct agiTexLock&>>(0x531EC0, this, arg1);
}

agiD3DTexLut::~agiD3DTexLut()
{
    unimplemented();
}

i32 agiD3DTexLut::BeginGfx()
{
    return stub<thiscall_t<i32, agiD3DTexLut*>>(0x531FD0, this);
}

void agiD3DTexLut::EndGfx()
{
    return stub<thiscall_t<void, agiD3DTexLut*>>(0x532020, this);
}
