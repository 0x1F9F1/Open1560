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

define_dummy_symbol(agid3d_d3dmtldef);

#include "d3dmtldef.h"

agiD3DMtlDef::agiD3DMtlDef(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

agiD3DMtlDef::~agiD3DMtlDef()
{
    unimplemented(arg1);
}

void agiD3DMtlDef::Activate()
{
    return stub<thiscall_t<void, agiD3DMtlDef*>>(0x533670, this);
}

i32 agiD3DMtlDef::BeginGfx()
{
    return stub<thiscall_t<i32, agiD3DMtlDef*>>(0x533590, this);
}

void agiD3DMtlDef::EndGfx()
{
    return stub<thiscall_t<void, agiD3DMtlDef*>>(0x533620, this);
}

u32 agiD3DMtlDef::GetHandle()
{
    return stub<thiscall_t<u32, agiD3DMtlDef*>>(0x533750, this);
}
