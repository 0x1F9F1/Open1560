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

#include "swtexdef.h"

agiSWTexDef::agiSWTexDef(class agiSWPipeline* arg1)
{
    unimplemented();
}

agiSWTexDef::~agiSWTexDef()
{
    unimplemented();
}

i32 agiSWTexDef::BeginGfx()
{
    return stub<thiscall_t<i32, agiSWTexDef*>>(0x137730_Offset, this);
}

void agiSWTexDef::EndGfx()
{
    return stub<thiscall_t<void, agiSWTexDef*>>(0x137820_Offset, this);
}

i32 agiSWTexDef::IsAvailable()
{
    return stub<thiscall_t<i32, agiSWTexDef*>>(0x137810_Offset, this);
}

i32 agiSWTexDef::Lock(struct agiTexLock& arg1)
{
    return stub<thiscall_t<i32, agiSWTexDef*, struct agiTexLock&>>(0x137870_Offset, this, arg1);
}

void agiSWTexDef::Request()
{
    return stub<thiscall_t<void, agiSWTexDef*>>(0x1378D0_Offset, this);
}

void agiSWTexDef::Set(class Vector2& arg1, class Vector2& arg2)
{
    return stub<thiscall_t<void, agiSWTexDef*, class Vector2&, class Vector2&>>(0x137710_Offset, this, arg1, arg2);
}

void agiSWTexDef::Unlock(struct agiTexLock& arg1)
{
    return stub<thiscall_t<void, agiSWTexDef*, struct agiTexLock&>>(0x1378C0_Offset, this, arg1);
}

agiSWTexLut::agiSWTexLut(class agiSWPipeline* arg1)
{
    unimplemented();
}

agiSWTexLut::~agiSWTexLut()
{
    unimplemented();
}

i32 agiSWTexLut::BeginGfx()
{
    return stub<thiscall_t<i32, agiSWTexLut*>>(0x137950_Offset, this);
}

void agiSWTexLut::EndGfx()
{
    return stub<thiscall_t<void, agiSWTexLut*>>(0x137B30_Offset, this);
}

define_dummy_symbol(agisw_swtexdef);
