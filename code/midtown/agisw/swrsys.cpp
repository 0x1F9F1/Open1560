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

define_dummy_symbol(agisw_swrsys);

#include "swrsys.h"

agiSWRasterizer::agiSWRasterizer(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

agiSWRasterizer::~agiSWRasterizer()
{
    unimplemented();
}

i32 agiSWRasterizer::BeginGfx()
{
    return stub<thiscall_t<i32, agiSWRasterizer*>>(0x537BE0, this);
}

void agiSWRasterizer::BeginGroup()
{
    return stub<thiscall_t<void, agiSWRasterizer*>>(0x537C00, this);
}

void agiSWRasterizer::Card(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiSWRasterizer*, i32, i32>>(0x537CF0, this, arg1, arg2);
}

void agiSWRasterizer::EndGfx()
{
    return stub<thiscall_t<void, agiSWRasterizer*>>(0x537BF0, this);
}

void agiSWRasterizer::EndGroup()
{
    return stub<thiscall_t<void, agiSWRasterizer*>>(0x537C10, this);
}

void agiSWRasterizer::Line(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiSWRasterizer*, i32, i32>>(0x537CB0, this, arg1, arg2);
}

void agiSWRasterizer::Mesh(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3, u16* arg4, i32 arg5)
{
    return stub<thiscall_t<void, agiSWRasterizer*, enum agiVtxType, union agiVtx*, i32, u16*, i32>>(
        0x537D10, this, arg1, arg2, arg3, arg4, arg5);
}

void agiSWRasterizer::Points(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiSWRasterizer*, enum agiVtxType, union agiVtx*, i32>>(
        0x537D00, this, arg1, arg2, arg3);
}

void agiSWRasterizer::Quad(i32 arg1, i32 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<void, agiSWRasterizer*, i32, i32, i32, i32>>(0x537C70, this, arg1, arg2, arg3, arg4);
}

void agiSWRasterizer::SetVertCount(i32 arg1)
{
    return stub<thiscall_t<void, agiSWRasterizer*, i32>>(0x537C30, this, arg1);
}

void agiSWRasterizer::Triangle(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiSWRasterizer*, i32, i32, i32>>(0x537C40, this, arg1, arg2, arg3);
}

void agiSWRasterizer::Verts(enum agiVtxType arg1, union agiVtx* arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiSWRasterizer*, enum agiVtxType, union agiVtx*, i32>>(
        0x537C20, this, arg1, arg2, arg3);
}
