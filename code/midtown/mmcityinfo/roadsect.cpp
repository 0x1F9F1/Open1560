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

define_dummy_symbol(mmcityinfo_roadsect);

#include "roadsect.h"

mmRoadSide::mmRoadSide()
{
    unimplemented();
}

mmRoadSide::~mmRoadSide()
{
    unimplemented(arg1);
}

class MetaClass* mmRoadSide::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmRoadSide*>>(0x4D2D80, this);
}

void mmRoadSide::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4D2B70);
}

mmRoadSect::mmRoadSect()
{
    unimplemented();
}

mmRoadSect::~mmRoadSect()
{
    unimplemented(arg1);
}

class MetaClass* mmRoadSect::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmRoadSect*>>(0x4D3140, this);
}

i32 mmRoadSect::GetIntersectionType(i32 arg1)
{
    return stub<thiscall_t<i32, mmRoadSect*, i32>>(0x4D27D0, this, arg1);
}

class Vector3* mmRoadSect::GetNormal(i32 arg1)
{
    return stub<thiscall_t<class Vector3*, mmRoadSect*, i32>>(0x4D2790, this, arg1);
}

i32 mmRoadSect::GetRoomId(i32 arg1)
{
    return stub<thiscall_t<i32, mmRoadSect*, i32>>(0x4D27B0, this, arg1);
}

class Vector3* mmRoadSect::GetSidewalkVertex(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<class Vector3*, mmRoadSect*, i32, i32, i32>>(0x4D26E0, this, arg1, arg2, arg3);
}

char* mmRoadSect::GetStopLightName(i32 arg1)
{
    return stub<thiscall_t<char*, mmRoadSect*, i32>>(0x4D2940, this, arg1);
}

void mmRoadSect::GetStopLightPos(i32 arg1, class Vector3& arg2, class Vector3& arg3)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, class Vector3&, class Vector3&>>(0x4D2840, this, arg1, arg2, arg3);
}

class Vector3* mmRoadSect::GetVertex(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<class Vector3*, mmRoadSect*, i32, i32, i32>>(0x4D26B0, this, arg1, arg2, arg3);
}

i32 mmRoadSect::IsAlley()
{
    return stub<thiscall_t<i32, mmRoadSect*>>(0x4D2990, this);
}

i32 mmRoadSect::IsBlocked(i32 arg1)
{
    return stub<thiscall_t<i32, mmRoadSect*, i32>>(0x4D28B0, this, arg1);
}

i32 mmRoadSect::IsDivided()
{
    return stub<thiscall_t<i32, mmRoadSect*>>(0x4D2970, this);
}

i32 mmRoadSect::IsPedBlocked(i32 arg1)
{
    return stub<thiscall_t<i32, mmRoadSect*, i32>>(0x4D28F0, this, arg1);
}

void mmRoadSect::NewVertexs(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, i32, i32, i32, i32>>(0x4D2550, this, arg1, arg2, arg3, arg4, arg5);
}

void mmRoadSect::SetAlley(i32 arg1)
{
    return stub<thiscall_t<void, mmRoadSect*, i32>>(0x4D2980, this, arg1);
}

void mmRoadSect::SetBlocked(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, i32>>(0x4D2890, this, arg1, arg2);
}

void mmRoadSect::SetDivided(i32 arg1)
{
    return stub<thiscall_t<void, mmRoadSect*, i32>>(0x4D2960, this, arg1);
}

void mmRoadSect::SetIntersectionType(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, i32>>(0x4D2770, this, arg1, arg2);
}

void mmRoadSect::SetLSidewalk(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmRoadSect*, f32, f32>>(0x4D2530, this, arg1, arg2);
}

void mmRoadSect::SetPedBlocked(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, i32>>(0x4D28D0, this, arg1, arg2);
}

void mmRoadSect::SetRSidewalk(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmRoadSect*, f32, f32>>(0x4D2510, this, arg1, arg2);
}

void mmRoadSect::SetRoadNormal(i32 arg1, class Vector3& arg2)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, class Vector3&>>(0x4D2720, this, arg1, arg2);
}

void mmRoadSect::SetRoadVertex(i32 arg1, i32 arg2, i32 arg3, class Vector3& arg4)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, i32, i32, class Vector3&>>(0x4D2600, this, arg1, arg2, arg3, arg4);
}

void mmRoadSect::SetRoomId(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, i32>>(0x4D2750, this, arg1, arg2);
}

void mmRoadSect::SetSidewalkVertex(i32 arg1, i32 arg2, i32 arg3, class Vector3& arg4)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, i32, i32, class Vector3&>>(0x4D2650, this, arg1, arg2, arg3, arg4);
}

void mmRoadSect::SetStopLightName(i32 arg1, char* arg2)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, char*>>(0x4D2910, this, arg1, arg2);
}

void mmRoadSect::SetStopLightPos(i32 arg1, class Vector3 const& arg2, class Vector3 const& arg3)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, class Vector3 const&, class Vector3 const&>>(
        0x4D27F0, this, arg1, arg2, arg3);
}

void mmRoadSect::SetStreetType(char* arg1)
{
    return stub<thiscall_t<void, mmRoadSect*, char*>>(0x4D2500, this, arg1);
}

void mmRoadSect::SetStreetWidth(f32 arg1)
{
    return stub<thiscall_t<void, mmRoadSect*, f32>>(0x4D24F0, this, arg1);
}

void mmRoadSect::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4D2D90);
}

mmPropInfo::mmPropInfo()
{
    unimplemented();
}

mmPropInfo::~mmPropInfo()
{
    unimplemented(arg1);
}

void mmPropInfo::Append(char* arg1)
{
    return stub<thiscall_t<void, mmPropInfo*, char*>>(0x4D22A0, this, arg1);
}

class MetaClass* mmPropInfo::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmPropInfo*>>(0x4D2B60, this);
}

char* mmPropInfo::GetItem(i32 arg1)
{
    return stub<thiscall_t<char*, mmPropInfo*, i32>>(0x4D2250, this, arg1);
}

i32 mmPropInfo::GetNumItems()
{
    return stub<thiscall_t<i32, mmPropInfo*>>(0x4D2290, this);
}

f32 mmPropInfo::GetSpacing()
{
    return stub<thiscall_t<f32, mmPropInfo*>>(0x4D2280, this);
}

void mmPropInfo::NewItems(i32 arg1)
{
    return stub<thiscall_t<void, mmPropInfo*, i32>>(0x4D21F0, this, arg1);
}

void mmPropInfo::SetItem(i32 arg1, char* arg2)
{
    return stub<thiscall_t<void, mmPropInfo*, i32, char*>>(0x4D2220, this, arg1, arg2);
}

void mmPropInfo::SetSpacing(f32 arg1)
{
    return stub<thiscall_t<void, mmPropInfo*, f32>>(0x4D2240, this, arg1);
}

void mmPropInfo::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4D29A0);
}
