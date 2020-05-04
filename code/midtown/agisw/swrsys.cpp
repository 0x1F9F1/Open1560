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

#include "swrsys.h"

agiSWRasterizer::agiSWRasterizer(class agiPipeline* arg1)
{
    unimplemented();
}

agiSWRasterizer::~agiSWRasterizer()
{
    unimplemented();
}

i32 agiSWRasterizer::BeginGfx()
{
    return stub<thiscall_t<i32, agiSWRasterizer*>>(0x137BE0_Offset, this);
}

void agiSWRasterizer::BeginGroup()
{
    return stub<thiscall_t<void, agiSWRasterizer*>>(0x137C00_Offset, this);
}

void agiSWRasterizer::Card(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiSWRasterizer*, i32, i32>>(0x137CF0_Offset, this, arg1, arg2);
}

void agiSWRasterizer::EndGfx()
{
    return stub<thiscall_t<void, agiSWRasterizer*>>(0x137BF0_Offset, this);
}

void agiSWRasterizer::EndGroup()
{
    return stub<thiscall_t<void, agiSWRasterizer*>>(0x137C10_Offset, this);
}

void agiSWRasterizer::Line(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiSWRasterizer*, i32, i32>>(0x137CB0_Offset, this, arg1, arg2);
}

void agiSWRasterizer::Mesh(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3, u16* arg4, i32 arg5)
{
    return stub<thiscall_t<void, agiSWRasterizer*, enum agiVtxType, union agiVtx*, i32, u16*, i32>>(
        0x137D10_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void agiSWRasterizer::Points(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiSWRasterizer*, enum agiVtxType, union agiVtx*, i32>>(
        0x137D00_Offset, this, arg1, arg2, arg3);
}

void agiSWRasterizer::Quad(i32 arg1, i32 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<void, agiSWRasterizer*, i32, i32, i32, i32>>(0x137C70_Offset, this, arg1, arg2, arg3, arg4);
}

void agiSWRasterizer::SetVertCount(i32 arg1)
{
    return stub<thiscall_t<void, agiSWRasterizer*, i32>>(0x137C30_Offset, this, arg1);
}

void agiSWRasterizer::Triangle(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiSWRasterizer*, i32, i32, i32>>(0x137C40_Offset, this, arg1, arg2, arg3);
}

void agiSWRasterizer::Verts(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiSWRasterizer*, enum agiVtxType, union agiVtx*, i32>>(
        0x137C20_Offset, this, arg1, arg2, arg3);
}

define_dummy_symbol(agisw_swrsys);
