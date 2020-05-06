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

define_dummy_symbol(mmgame_hudmap);

#include "hudmap.h"

mmHudMap::mmHudMap()
{
    unimplemented();
}

mmHudMap::~mmHudMap()
{
    unimplemented(arg1);
}

void mmHudMap::Activate()
{
    return stub<thiscall_t<void, mmHudMap*>>(0x428810, this);
}

void mmHudMap::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmHudMap*, class Bank*>>(0x429C60, this, arg1);
}

void mmHudMap::Cull()
{
    return stub<thiscall_t<void, mmHudMap*>>(0x428E50, this);
}

void mmHudMap::Cycle()
{
    return stub<thiscall_t<void, mmHudMap*>>(0x428B90, this);
}

void mmHudMap::Deactivate()
{
    return stub<thiscall_t<void, mmHudMap*>>(0x428840, this);
}

void mmHudMap::DrawMisc()
{
    return stub<thiscall_t<void, mmHudMap*>>(0x429930, this);
}

class MetaClass* mmHudMap::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmHudMap*>>(0x429F30, this);
}

void mmHudMap::Init(class asCamera* arg1, class Matrix34* arg2, class mmHUD* arg3, class mmGame* arg4, char* arg5)
{
    return stub<thiscall_t<void, mmHudMap*, class asCamera*, class Matrix34*, class mmHUD*, class mmGame*, char*>>(
        0x4281B0, this, arg1, arg2, arg3, arg4, arg5);
}

void mmHudMap::RegisterCopsnRobbers(class Vector3** arg1)
{
    return stub<thiscall_t<void, mmHudMap*, class Vector3**>>(0x4287B0, this, arg1);
}

void mmHudMap::RegisterMisc(class Vector3** arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmHudMap*, class Vector3**, i32>>(0x4287E0, this, arg1, arg2);
}

void mmHudMap::RegisterOpponents(struct OppIconInfo* arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmHudMap*, struct OppIconInfo*, i32>>(0x428790, this, arg1, arg2);
}

void mmHudMap::ResChanged()
{
    return stub<thiscall_t<void, mmHudMap*>>(0x4293D0, this);
}

void mmHudMap::Reset()
{
    return stub<thiscall_t<void, mmHudMap*>>(0x428750, this);
}

void mmHudMap::SetMode(i32 arg1)
{
    return stub<thiscall_t<void, mmHudMap*, i32>>(0x428870, this, arg1);
}

void mmHudMap::ToggleFullScreen()
{
    return stub<thiscall_t<void, mmHudMap*>>(0x428BC0, this);
}

void mmHudMap::ToggleMapRes()
{
    return stub<thiscall_t<void, mmHudMap*>>(0x428C00, this);
}

void mmHudMap::Update()
{
    return stub<thiscall_t<void, mmHudMap*>>(0x428C60, this);
}

void mmHudMap::DeclareFields()
{
    return stub<cdecl_t<void>>(0x429DC0);
}

i32 mmHudMap::BitmapToScreen(struct Point* arg1, struct Point arg2)
{
    return stub<thiscall_t<i32, mmHudMap*, struct Point*, struct Point>>(0x429BC0, this, arg1, arg2);
}

void mmHudMap::DrawCentered(class agiBitmap* arg1, struct Point arg2)
{
    return stub<thiscall_t<void, mmHudMap*, class agiBitmap*, struct Point>>(0x428FE0, this, arg1, arg2);
}

void mmHudMap::DrawClipped(class agiBitmap* arg1, struct Point arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6)
{
    return stub<thiscall_t<void, mmHudMap*, class agiBitmap*, struct Point, f32, f32, f32, f32>>(
        0x429050, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void mmHudMap::DrawCops()
{
    return stub<thiscall_t<void, mmHudMap*>>(0x4296B0, this);
}

void mmHudMap::DrawCopsnRobbers()
{
    return stub<thiscall_t<void, mmHudMap*>>(0x429860, this);
}

void mmHudMap::DrawOpponents()
{
    return stub<thiscall_t<void, mmHudMap*>>(0x4295F0, this);
}

void mmHudMap::DrawOriented(class Matrix34* arg1, u32 arg2)
{
    return stub<thiscall_t<void, mmHudMap*, class Matrix34*, u32>>(0x429410, this, arg1, arg2);
}

void mmHudMap::DrawOrientedBitmap(class Matrix34* arg1, class agiBitmap* arg2)
{
    return stub<thiscall_t<void, mmHudMap*, class Matrix34*, class agiBitmap*>>(0x4291F0, this, arg1, arg2);
}

void mmHudMap::DrawWaypoints()
{
    return stub<thiscall_t<void, mmHudMap*>>(0x429720, this);
}

void mmHudMap::FlushVerts()
{
    return stub<thiscall_t<void, mmHudMap*>>(0x4299A0, this);
}

class agiBitmap* mmHudMap::GetCurrentMap()
{
    return stub<thiscall_t<class agiBitmap*, mmHudMap*>>(0x428BF0, this);
}

struct Point mmHudMap::WorldToBitmap(class Vector3* arg1)
{
    return stub<thiscall_t<struct Point, mmHudMap*, class Vector3*>>(0x429B20, this, arg1);
}
