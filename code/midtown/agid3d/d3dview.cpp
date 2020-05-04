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

#include "d3dview.h"

agiD3DViewport::agiD3DViewport(class agiPipeline* arg1)
{
    unimplemented();
}

agiD3DViewport::~agiD3DViewport()
{
    unimplemented();
}

void agiD3DViewport::Activate()
{
    return stub<thiscall_t<void, agiD3DViewport*>>(0x133350_Offset, this);
}

i32 agiD3DViewport::BeginGfx()
{
    return stub<thiscall_t<i32, agiD3DViewport*>>(0x133300_Offset, this);
}

void agiD3DViewport::Clear(i32 arg1)
{
    return stub<thiscall_t<void, agiD3DViewport*, i32>>(0x133460_Offset, this, arg1);
}

void agiD3DViewport::EndGfx()
{
    return stub<thiscall_t<void, agiD3DViewport*>>(0x133330_Offset, this);
}

void agiD3DViewport::SetBackground(class Vector3& arg1)
{
    return stub<thiscall_t<void, agiD3DViewport*, class Vector3&>>(0x133410_Offset, this, arg1);
}

define_dummy_symbol(agid3d_d3dview);
