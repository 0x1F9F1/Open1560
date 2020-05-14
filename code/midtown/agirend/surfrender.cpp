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

define_dummy_symbol(agirend_surfrender);

#include "surfrender.h"

agiSurfRenderer::agiSurfRenderer(class agiRasterizer* arg1)
{
    unimplemented(arg1);
}

void agiSurfRenderer::BeginDraw(i32 arg1)
{
    return stub<thiscall_t<void, agiSurfRenderer*, i32>>(0x554D70, this, arg1);
}

void agiSurfRenderer::BeginGroup()
{
    return stub<thiscall_t<void, agiSurfRenderer*>>(0x552DC0, this);
}

void agiSurfRenderer::Draw(class DLP* arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiSurfRenderer*, class DLP*, i32>>(0x5544F0, this, arg1, arg2);
}

void agiSurfRenderer::DrawCard(class Vector3& arg1)
{
    return stub<thiscall_t<void, agiSurfRenderer*, class Vector3&>>(0x554890, this, arg1);
}

void agiSurfRenderer::DrawLabel(union agiVtx& arg1, char* arg2)
{
    return stub<thiscall_t<void, agiSurfRenderer*, union agiVtx&, char*>>(0x555180, this, arg1, arg2);
}

void agiSurfRenderer::DrawLine(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiSurfRenderer*, i32, i32>>(0x554EE0, this, arg1, arg2);
}

void agiSurfRenderer::DrawTri(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiSurfRenderer*, i32, i32, i32>>(0x554EB0, this, arg1, arg2, arg3);
}

void agiSurfRenderer::EndDraw()
{
    return stub<thiscall_t<void, agiSurfRenderer*>>(0x5551F0, this);
}

void agiSurfRenderer::Points(union agiVtx* arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiSurfRenderer*, union agiVtx*, i32>>(0x554E40, this, arg1, arg2);
}

void agiSurfRenderer::Verts(union agiVtx* arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiSurfRenderer*, union agiVtx*, i32>>(0x554DA0, this, arg1, arg2);
}

agiSurfRenderer::~agiSurfRenderer()
{
    unimplemented();
}

i32 agiSurfRenderer::AddSurface(struct agiPatch* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<cdecl_t<i32, struct agiPatch*, i32, i32, i32, i32>>(0x552E00, arg1, arg2, arg3, arg4, arg5);
}

agiRenderer::agiRenderer()
{
    unimplemented();
}

agiRenderer::~agiRenderer()
{
    unimplemented();
}
