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

#include "surfrender.h"

agiSurfRenderer::agiSurfRenderer(class agiRasterizer* arg1)
{
    unimplemented();
}

void agiSurfRenderer::BeginDraw(i32 arg1)
{
    return stub<thiscall_t<void, agiSurfRenderer*, i32>>(0x154D70_Offset, this, arg1);
}

void agiSurfRenderer::BeginGroup()
{
    return stub<thiscall_t<void, agiSurfRenderer*>>(0x152DC0_Offset, this);
}

void agiSurfRenderer::Draw(class DLP* arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiSurfRenderer*, class DLP*, i32>>(0x1544F0_Offset, this, arg1, arg2);
}

void agiSurfRenderer::DrawCard(class Vector3& arg1)
{
    return stub<thiscall_t<void, agiSurfRenderer*, class Vector3&>>(0x154890_Offset, this, arg1);
}

void agiSurfRenderer::DrawLabel(union agiVtx& arg1, char* arg2)
{
    return stub<thiscall_t<void, agiSurfRenderer*, union agiVtx&, char*>>(0x155180_Offset, this, arg1, arg2);
}

void agiSurfRenderer::DrawLine(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiSurfRenderer*, i32, i32>>(0x154EE0_Offset, this, arg1, arg2);
}

void agiSurfRenderer::DrawTri(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiSurfRenderer*, i32, i32, i32>>(0x154EB0_Offset, this, arg1, arg2, arg3);
}

void agiSurfRenderer::EndDraw()
{
    return stub<thiscall_t<void, agiSurfRenderer*>>(0x1551F0_Offset, this);
}

void agiSurfRenderer::Points(union agiVtx* arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiSurfRenderer*, union agiVtx*, i32>>(0x154E40_Offset, this, arg1, arg2);
}

void agiSurfRenderer::Verts(union agiVtx* arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiSurfRenderer*, union agiVtx*, i32>>(0x154DA0_Offset, this, arg1, arg2);
}

agiSurfRenderer::~agiSurfRenderer()
{
    unimplemented();
}

i32 agiSurfRenderer::AddSurface(struct agiPatch* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<cdecl_t<i32, struct agiPatch*, i32, i32, i32, i32>>(0x152E00_Offset, arg1, arg2, arg3, arg4, arg5);
}

agiRenderer::agiRenderer()
{
    unimplemented();
}

agiRenderer::~agiRenderer()
{
    unimplemented();
}

void agiRenderer::BeginGroup()
{
    return stub<thiscall_t<void, agiRenderer*>>(0x - 400000_Offset, this);
}

void agiRenderer::Draw(class DLP* arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiRenderer*, class DLP*, i32>>(0x - 400000_Offset, this, arg1, arg2);
}

void agiRenderer::DrawCard(class Vector3& arg1)
{
    return stub<thiscall_t<void, agiRenderer*, class Vector3&>>(0x - 400000_Offset, this, arg1);
}

void agiRenderer::EndGroup()
{
    return stub<thiscall_t<void, agiRenderer*>>(0x - 400000_Offset, this);
}

void agiRenderer::BeginDraw(i32 arg1)
{
    return stub<thiscall_t<void, agiRenderer*, i32>>(0x - 400000_Offset, this, arg1);
}

void agiRenderer::Verts(union agiVtx* arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiRenderer*, union agiVtx*, i32>>(0x - 400000_Offset, this, arg1, arg2);
}

void agiRenderer::Points(union agiVtx* arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiRenderer*, union agiVtx*, i32>>(0x - 400000_Offset, this, arg1, arg2);
}

void agiRenderer::DrawTri(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiRenderer*, i32, i32, i32>>(0x - 400000_Offset, this, arg1, arg2, arg3);
}

void agiRenderer::DrawLine(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiRenderer*, i32, i32>>(0x - 400000_Offset, this, arg1, arg2);
}

void agiRenderer::DrawLabel(union agiVtx& arg1, char* arg2)
{
    return stub<thiscall_t<void, agiRenderer*, union agiVtx&, char*>>(0x - 400000_Offset, this, arg1, arg2);
}

void agiRenderer::EndDraw()
{
    return stub<thiscall_t<void, agiRenderer*>>(0x - 400000_Offset, this);
}

define_dummy_symbol(agirend_surfrender);
