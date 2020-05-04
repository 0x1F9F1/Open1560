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

#include "d3drsys.h"

agiD3DRasterizer::agiD3DRasterizer(class agiPipeline* arg1)
{
    unimplemented();
}

agiD3DRasterizer::~agiD3DRasterizer()
{
    unimplemented();
}

i32 agiD3DRasterizer::BeginGfx()
{
    return stub<thiscall_t<i32, agiD3DRasterizer*>>(0x12E570_Offset, this);
}

void agiD3DRasterizer::BeginGroup()
{
    return stub<thiscall_t<void, agiD3DRasterizer*>>(0x12E5A0_Offset, this);
}

void agiD3DRasterizer::Card(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiD3DRasterizer*, i32, i32>>(0x12F8E0_Offset, this, arg1, arg2);
}

void agiD3DRasterizer::EndGfx()
{
    return stub<thiscall_t<void, agiD3DRasterizer*>>(0x12E580_Offset, this);
}

void agiD3DRasterizer::EndGroup()
{
    return stub<thiscall_t<void, agiD3DRasterizer*>>(0x12E5B0_Offset, this);
}

void agiD3DRasterizer::Line(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiD3DRasterizer*, i32, i32>>(0x12F860_Offset, this, arg1, arg2);
}

void agiD3DRasterizer::Mesh(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3, u16* arg4, i32 arg5)
{
    return stub<thiscall_t<void, agiD3DRasterizer*, enum agiVtxType, union agiVtx*, i32, u16*, i32>>(
        0x12F950_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void agiD3DRasterizer::Mesh2(struct agiScreenVtx2* arg1, i32 arg2, u16* arg3, i32 arg4)
{
    return stub<thiscall_t<void, agiD3DRasterizer*, struct agiScreenVtx2*, i32, u16*, i32>>(
        0x12F9C0_Offset, this, arg1, arg2, arg3, arg4);
}

void agiD3DRasterizer::Points(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiD3DRasterizer*, enum agiVtxType, union agiVtx*, i32>>(
        0x12F8F0_Offset, this, arg1, arg2, arg3);
}

void agiD3DRasterizer::SetVertCount(i32 arg1)
{
    return stub<thiscall_t<void, agiD3DRasterizer*, i32>>(0x12F7C0_Offset, this, arg1);
}

void agiD3DRasterizer::Triangle(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiD3DRasterizer*, i32, i32, i32>>(0x12F7D0_Offset, this, arg1, arg2, arg3);
}

void agiD3DRasterizer::Verts(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiD3DRasterizer*, enum agiVtxType, union agiVtx*, i32>>(
        0x12F770_Offset, this, arg1, arg2, arg3);
}

void agiD3DRasterizer::FlushState()
{
    return stub<thiscall_t<void, agiD3DRasterizer*>>(0x12E630_Offset, this);
}

void d3d_state_init()
{
    return stub<cdecl_t<void>>(0x12E5C0_Offset);
}

define_dummy_symbol(agid3d_d3drsys);
