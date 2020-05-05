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

define_dummy_symbol(agi_rsys);

#include "rsys.h"

agiRasterizer::agiRasterizer(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

agiRasterizer::~agiRasterizer()
{
    unimplemented(arg1);
}

void agiRasterizer::BeginGroup()
{
    return stub<thiscall_t<void, agiRasterizer*>>(0x157D20_Offset, this);
}

void agiRasterizer::EndGroup()
{
    return stub<thiscall_t<void, agiRasterizer*>>(0x157D30_Offset, this);
}

void agiRasterizer::Verts(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiRasterizer*, enum agiVtxType, union agiVtx*, i32>>(
        0x - 400000_Offset, this, arg1, arg2, arg3);
}

void agiRasterizer::Points(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiRasterizer*, enum agiVtxType, union agiVtx*, i32>>(
        0x - 400000_Offset, this, arg1, arg2, arg3);
}

void agiRasterizer::SetVertCount(i32 arg1)
{
    return stub<thiscall_t<void, agiRasterizer*, i32>>(0x - 400000_Offset, this, arg1);
}

void agiRasterizer::Triangle(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiRasterizer*, i32, i32, i32>>(0x - 400000_Offset, this, arg1, arg2, arg3);
}

void agiRasterizer::Quad(i32 arg1, i32 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<void, agiRasterizer*, i32, i32, i32, i32>>(0x157D40_Offset, this, arg1, arg2, arg3, arg4);
}

void agiRasterizer::Poly(i32* arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiRasterizer*, i32*, i32>>(0x157D70_Offset, this, arg1, arg2);
}

void agiRasterizer::Line(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiRasterizer*, i32, i32>>(0x - 400000_Offset, this, arg1, arg2);
}

void agiRasterizer::Card(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiRasterizer*, i32, i32>>(0x - 400000_Offset, this, arg1, arg2);
}

void agiRasterizer::Mesh(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3, u16* arg4, i32 arg5)
{
    return stub<thiscall_t<void, agiRasterizer*, enum agiVtxType, union agiVtx*, i32, u16*, i32>>(
        0x - 400000_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void agiRasterizer::Mesh2(struct agiScreenVtx2* arg1, i32 arg2, u16* arg3, i32 arg4)
{
    return stub<thiscall_t<void, agiRasterizer*, struct agiScreenVtx2*, i32, u16*, i32>>(
        0x157DB0_Offset, this, arg1, arg2, arg3, arg4);
}

void agiRasterizer::LineList(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiRasterizer*, enum agiVtxType, union agiVtx*, i32>>(
        0x157DD0_Offset, this, arg1, arg2, arg3);
}

void agiRendStateStruct::Reset()
{
    return stub<thiscall_t<void, agiRendStateStruct*>>(0x157CE0_Offset, this);
}
