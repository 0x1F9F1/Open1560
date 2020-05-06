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

define_dummy_symbol(mmcity_renderweb);

#include "renderweb.h"

asRenderWeb::asRenderWeb()
{
    unimplemented();
}

asRenderWeb::~asRenderWeb()
{
    unimplemented(arg1);
}

void asRenderWeb::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asRenderWeb*, class Bank*>>(0x491690, this, arg1);
}

void asRenderWeb::Cull()
{
    return stub<thiscall_t<void, asRenderWeb*>>(0x490FF0, this);
}

void asRenderWeb::DrawAllBounds()
{
    return stub<thiscall_t<void, asRenderWeb*>>(0x491610, this);
}

i32 asRenderWeb::GetCellNeighbors(i32 arg1, struct asPortalCell** arg2, i32 arg3)
{
    return stub<thiscall_t<i32, asRenderWeb*, i32, struct asPortalCell**, i32>>(0x4915A0, this, arg1, arg2, arg3);
}

class MetaClass* asRenderWeb::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asRenderWeb*>>(0x491890, this);
}

struct asPortalCell* asRenderWeb::GetStartCell(class Vector3& arg1, struct asPortalCell* arg2, class mmPolygon** arg3)
{
    return stub<
        thiscall_t<struct asPortalCell*, asRenderWeb*, class Vector3&, struct asPortalCell*, class mmPolygon**>>(
        0x48FDD0, this, arg1, arg2, arg3);
}

i32 asRenderWeb::Load(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, asRenderWeb*, char*, i32>>(0x48FFF0, this, arg1, arg2);
}

void asRenderWeb::SetMirrorPos(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<void, asRenderWeb*, f32, f32, f32, f32, f32>>(0x490E70, this, arg1, arg2, arg3, arg4, arg5);
}

void asRenderWeb::Update()
{
    return stub<thiscall_t<void, asRenderWeb*>>(0x490CD0, this);
}

void asRenderWeb::UpdateMirror()
{
    return stub<thiscall_t<void, asRenderWeb*>>(0x490D60, this);
}

void asRenderWeb::DeclareFields()
{
    return stub<cdecl_t<void>>(0x491710);
}

void DrawMirrorBorder()
{
    return stub<cdecl_t<void>>(0x490F40);
}
