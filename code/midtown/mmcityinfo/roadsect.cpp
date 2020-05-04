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

#include "roadsect.h"

mmRoadSide::mmRoadSide()
{
    unimplemented();
}

mmRoadSide::~mmRoadSide()
{
    unimplemented();
}

class MetaClass* mmRoadSide::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmRoadSide*>>(0xD2D80_Offset, this);
}

void mmRoadSide::DeclareFields()
{
    return stub<cdecl_t<void>>(0xD2B70_Offset);
}

mmRoadSect::mmRoadSect()
{
    unimplemented();
}

mmRoadSect::~mmRoadSect()
{
    unimplemented();
}

class MetaClass* mmRoadSect::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmRoadSect*>>(0xD3140_Offset, this);
}

i32 mmRoadSect::GetIntersectionType(i32 arg1)
{
    return stub<thiscall_t<i32, mmRoadSect*, i32>>(0xD27D0_Offset, this, arg1);
}

class Vector3* mmRoadSect::GetNormal(i32 arg1)
{
    return stub<thiscall_t<class Vector3*, mmRoadSect*, i32>>(0xD2790_Offset, this, arg1);
}

i32 mmRoadSect::GetRoomId(i32 arg1)
{
    return stub<thiscall_t<i32, mmRoadSect*, i32>>(0xD27B0_Offset, this, arg1);
}

class Vector3* mmRoadSect::GetSidewalkVertex(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<class Vector3*, mmRoadSect*, i32, i32, i32>>(0xD26E0_Offset, this, arg1, arg2, arg3);
}

char* mmRoadSect::GetStopLightName(i32 arg1)
{
    return stub<thiscall_t<char*, mmRoadSect*, i32>>(0xD2940_Offset, this, arg1);
}

void mmRoadSect::GetStopLightPos(i32 arg1, class Vector3& arg2, class Vector3& arg3)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, class Vector3&, class Vector3&>>(
        0xD2840_Offset, this, arg1, arg2, arg3);
}

class Vector3* mmRoadSect::GetVertex(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<class Vector3*, mmRoadSect*, i32, i32, i32>>(0xD26B0_Offset, this, arg1, arg2, arg3);
}

i32 mmRoadSect::IsAlley()
{
    return stub<thiscall_t<i32, mmRoadSect*>>(0xD2990_Offset, this);
}

i32 mmRoadSect::IsBlocked(i32 arg1)
{
    return stub<thiscall_t<i32, mmRoadSect*, i32>>(0xD28B0_Offset, this, arg1);
}

i32 mmRoadSect::IsDivided()
{
    return stub<thiscall_t<i32, mmRoadSect*>>(0xD2970_Offset, this);
}

i32 mmRoadSect::IsPedBlocked(i32 arg1)
{
    return stub<thiscall_t<i32, mmRoadSect*, i32>>(0xD28F0_Offset, this, arg1);
}

void mmRoadSect::NewVertexs(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, i32, i32, i32, i32>>(
        0xD2550_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void mmRoadSect::SetAlley(i32 arg1)
{
    return stub<thiscall_t<void, mmRoadSect*, i32>>(0xD2980_Offset, this, arg1);
}

void mmRoadSect::SetBlocked(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, i32>>(0xD2890_Offset, this, arg1, arg2);
}

void mmRoadSect::SetDivided(i32 arg1)
{
    return stub<thiscall_t<void, mmRoadSect*, i32>>(0xD2960_Offset, this, arg1);
}

void mmRoadSect::SetIntersectionType(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, i32>>(0xD2770_Offset, this, arg1, arg2);
}

void mmRoadSect::SetLSidewalk(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmRoadSect*, f32, f32>>(0xD2530_Offset, this, arg1, arg2);
}

void mmRoadSect::SetPedBlocked(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, i32>>(0xD28D0_Offset, this, arg1, arg2);
}

void mmRoadSect::SetRSidewalk(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmRoadSect*, f32, f32>>(0xD2510_Offset, this, arg1, arg2);
}

void mmRoadSect::SetRoadNormal(i32 arg1, class Vector3& arg2)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, class Vector3&>>(0xD2720_Offset, this, arg1, arg2);
}

void mmRoadSect::SetRoadVertex(i32 arg1, i32 arg2, i32 arg3, class Vector3& arg4)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, i32, i32, class Vector3&>>(
        0xD2600_Offset, this, arg1, arg2, arg3, arg4);
}

void mmRoadSect::SetRoomId(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, i32>>(0xD2750_Offset, this, arg1, arg2);
}

void mmRoadSect::SetSidewalkVertex(i32 arg1, i32 arg2, i32 arg3, class Vector3& arg4)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, i32, i32, class Vector3&>>(
        0xD2650_Offset, this, arg1, arg2, arg3, arg4);
}

void mmRoadSect::SetStopLightName(i32 arg1, char* arg2)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, char*>>(0xD2910_Offset, this, arg1, arg2);
}

void mmRoadSect::SetStopLightPos(i32 arg1, class Vector3 const& arg2, class Vector3 const& arg3)
{
    return stub<thiscall_t<void, mmRoadSect*, i32, class Vector3 const&, class Vector3 const&>>(
        0xD27F0_Offset, this, arg1, arg2, arg3);
}

void mmRoadSect::SetStreetType(char* arg1)
{
    return stub<thiscall_t<void, mmRoadSect*, char*>>(0xD2500_Offset, this, arg1);
}

void mmRoadSect::SetStreetWidth(f32 arg1)
{
    return stub<thiscall_t<void, mmRoadSect*, f32>>(0xD24F0_Offset, this, arg1);
}

void mmRoadSect::DeclareFields()
{
    return stub<cdecl_t<void>>(0xD2D90_Offset);
}

mmPropInfo::mmPropInfo()
{
    unimplemented();
}

mmPropInfo::~mmPropInfo()
{
    unimplemented();
}

void mmPropInfo::Append(char* arg1)
{
    return stub<thiscall_t<void, mmPropInfo*, char*>>(0xD22A0_Offset, this, arg1);
}

class MetaClass* mmPropInfo::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmPropInfo*>>(0xD2B60_Offset, this);
}

char* mmPropInfo::GetItem(i32 arg1)
{
    return stub<thiscall_t<char*, mmPropInfo*, i32>>(0xD2250_Offset, this, arg1);
}

i32 mmPropInfo::GetNumItems()
{
    return stub<thiscall_t<i32, mmPropInfo*>>(0xD2290_Offset, this);
}

f32 mmPropInfo::GetSpacing()
{
    return stub<thiscall_t<f32, mmPropInfo*>>(0xD2280_Offset, this);
}

void mmPropInfo::NewItems(i32 arg1)
{
    return stub<thiscall_t<void, mmPropInfo*, i32>>(0xD21F0_Offset, this, arg1);
}

void mmPropInfo::SetItem(i32 arg1, char* arg2)
{
    return stub<thiscall_t<void, mmPropInfo*, i32, char*>>(0xD2220_Offset, this, arg1, arg2);
}

void mmPropInfo::SetSpacing(f32 arg1)
{
    return stub<thiscall_t<void, mmPropInfo*, f32>>(0xD2240_Offset, this, arg1);
}

void mmPropInfo::DeclareFields()
{
    return stub<cdecl_t<void>>(0xD29A0_Offset);
}

define_dummy_symbol(mmcityinfo_roadsect);
