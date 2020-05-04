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

#include "portal.h"

asPortalWeb::asPortalWeb()
{
    unimplemented();
}

asPortalWeb::~asPortalWeb()
{
    unimplemented();
}

struct asPortalCell* asPortalWeb::GetStartCell(class Vector3& arg1, struct asPortalCell* arg2, class mmPolygon** arg3)
{
    return stub<
        thiscall_t<struct asPortalCell*, asPortalWeb*, class Vector3&, struct asPortalCell*, class mmPolygon**>>(
        0x - 400000_Offset, this, arg1, arg2, arg3);
}

struct asPortalCell* asPortalWeb::AddCell(char* arg1, class asPortalRenderable* arg2, u32 arg3)
{
    return stub<thiscall_t<struct asPortalCell*, asPortalWeb*, char*, class asPortalRenderable*, u32>>(
        0x957E0_Offset, this, arg1, arg2, arg3);
}

struct asPortalEdge* asPortalWeb::AddEdge(char* arg1, struct asPortalCell* arg2, struct asPortalCell* arg3, i32 arg4)
{
    return stub<thiscall_t<struct asPortalEdge*, asPortalWeb*, char*, struct asPortalCell*, struct asPortalCell*, i32>>(
        0x958E0_Offset, this, arg1, arg2, arg3, arg4);
}

void asPortalWeb::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asPortalWeb*, class Bank*>>(0x97540_Offset, this, arg1);
}

void asPortalWeb::BuildGroups()
{
    return stub<thiscall_t<void, asPortalWeb*>>(0x969F0_Offset, this);
}

i32 asPortalWeb::BuildVisibilityList(class Matrix34& arg1, struct asPortalCell** arg2, i32 arg3, f32 arg4)
{
    return stub<thiscall_t<i32, asPortalWeb*, class Matrix34&, struct asPortalCell**, i32, f32>>(
        0x95B70_Offset, this, arg1, arg2, arg3, arg4);
}

i32 asPortalWeb::BuildVisibilityList(class Vector3& arg1, struct asPortalCell** arg2, i32 arg3, f32 arg4)
{
    return stub<thiscall_t<i32, asPortalWeb*, class Vector3&, struct asPortalCell**, i32, f32>>(
        0x95DD0_Offset, this, arg1, arg2, arg3, arg4);
}

void asPortalWeb::Cull(i32 arg1)
{
    return stub<thiscall_t<void, asPortalWeb*, i32>>(0x96FE0_Offset, this, arg1);
}

void asPortalWeb::DeleteCell(struct asPortalCell* arg1)
{
    return stub<thiscall_t<void, asPortalWeb*, struct asPortalCell*>>(0x95830_Offset, this, arg1);
}

void asPortalWeb::DeleteEdge(struct asPortalEdge* arg1)
{
    return stub<thiscall_t<void, asPortalWeb*, struct asPortalEdge*>>(0x959A0_Offset, this, arg1);
}

class MetaClass* asPortalWeb::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asPortalWeb*>>(0x97770_Offset, this);
}

void asPortalWeb::LockTarget()
{
    return stub<thiscall_t<void, asPortalWeb*>>(0x97530_Offset, this);
}

void asPortalWeb::Stats()
{
    return stub<thiscall_t<void, asPortalWeb*>>(0x97400_Offset, this);
}

void asPortalWeb::Update()
{
    return stub<thiscall_t<void, asPortalWeb*>>(0x95EE0_Offset, this);
}

void asPortalWeb::DeclareFields()
{
    return stub<cdecl_t<void>>(0x976D0_Offset);
}

struct asPortalCell* LookupCell(char* arg1)
{
    return stub<cdecl_t<struct asPortalCell*, char*>>(0x959B0_Offset, arg1);
}

struct asPortalCell* LookupEdge(char* arg1)
{
    return stub<cdecl_t<struct asPortalCell*, char*>>(0x959C0_Offset, arg1);
}

void asPortalPVS::Init(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, asPortalPVS*, i32, i32>>(0x959D0_Offset, this, arg1, arg2);
}

void asPortalPVS::SetVisible(u32 arg1)
{
    return stub<thiscall_t<void, asPortalPVS*, u32>>(0x95AB0_Offset, this, arg1);
}

struct asPortalPVS* asPortalPVS::Create(i32 arg1, ...)
{
    unimplemented();
}

asPortalEdge::asPortalEdge(struct asPortalCell* arg1, struct asPortalCell* arg2, i32 arg3)
{
    unimplemented();
}

define_dummy_symbol(mmcity_portal);
