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

define_dummy_symbol(agirend_lighter);

#include "lighter.h"

agiLighter::agiLighter()
{
    unimplemented();
}

agiLighter::~agiLighter()
{
    unimplemented(arg1);
}

void agiLighter::TransformAll(class Matrix34* arg1, class Vector3* arg2, u32 arg3)
{
    return stub<thiscall_t<void, agiLighter*, class Matrix34*, class Vector3*, u32>>(0x551800, this, arg1, arg2, arg3);
}

void agiLighter::BeginScene()
{
    return stub<cdecl_t<void>>(0x551760);
}

void agiLighter::DeclareLight(class agiLight* arg1)
{
    return stub<cdecl_t<void, class agiLight*>>(0x551780, arg1);
}

void agiLighter::RemoveLight(class agiLight* arg1)
{
    return stub<cdecl_t<void, class agiLight*>>(0x5517A0, arg1);
}

agiMonoLighter::agiMonoLighter()
{
    unimplemented();
}

agiMonoLighter::~agiMonoLighter()
{
    unimplemented(arg1);
}

u32 agiMonoLighter::LightVertex(u32 arg1, struct agiLitVtx* arg2, class Vector3* arg3)
{
    return stub<thiscall_t<u32, agiMonoLighter*, u32, struct agiLitVtx*, class Vector3*>>(
        0x551A20, this, arg1, arg2, arg3);
}

agiRGBLighter::agiRGBLighter()
{
    unimplemented();
}

agiRGBLighter::~agiRGBLighter()
{
    unimplemented(arg1);
}

u32 agiRGBLighter::LightVertex(u32 arg1, struct agiLitVtx* arg2, class Vector3* arg3)
{
    return stub<thiscall_t<u32, agiRGBLighter*, u32, struct agiLitVtx*, class Vector3*>>(
        0x551E70, this, arg1, arg2, arg3);
}
