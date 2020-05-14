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

define_dummy_symbol(mmai_aiMap);

#include "aiMap.h"

aiMap::aiMap()
{
    unimplemented();
}

aiMap::~aiMap()
{
    unimplemented();
}

void aiMap::AddAmbient(class aiVehicleSpline* arg1)
{
    return stub<thiscall_t<void, aiMap*, class aiVehicleSpline*>>(0x43BA60, this, arg1);
}

class aiIntersection* aiMap::AddIntersection(class Vector3* arg1)
{
    return stub<thiscall_t<class aiIntersection*, aiMap*, class Vector3*>>(0x439670, this, arg1);
}

void aiMap::AddPedestrian(class aiPedestrian* arg1)
{
    return stub<thiscall_t<void, aiMap*, class aiPedestrian*>>(0x43B500, this, arg1);
}

void aiMap::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, aiMap*, class Bank*>>(0x43BBE0, this, arg1);
}

void aiMap::AllwaysGreen()
{
    return stub<thiscall_t<void, aiMap*>>(0x436CF0, this);
}

void aiMap::AllwaysRed()
{
    return stub<thiscall_t<void, aiMap*>>(0x436D30, this);
}

i32 aiMap::ChooseNextFreewayLink(class aiRailSet* arg1)
{
    return stub<thiscall_t<i32, aiMap*, class aiRailSet*>>(0x43AE90, this, arg1);
}

i32 aiMap::ChooseNextLaneLink(class aiRailSet* arg1)
{
    return stub<thiscall_t<i32, aiMap*, class aiRailSet*>>(0x43ADF0, this, arg1);
}

i32 aiMap::ChooseNextLeftStraightLink(class aiRailSet* arg1)
{
    return stub<thiscall_t<i32, aiMap*, class aiRailSet*>>(0x43A5D0, this, arg1);
}

i32 aiMap::ChooseNextRandomLink(class aiRailSet* arg1)
{
    return stub<thiscall_t<i32, aiMap*, class aiRailSet*>>(0x43A440, this, arg1);
}

i32 aiMap::ChooseNextRightStraightFreewayLink(class aiRailSet* arg1)
{
    return stub<thiscall_t<i32, aiMap*, class aiRailSet*>>(0x43AFA0, this, arg1);
}

i32 aiMap::ChooseNextRightStraightLink(class aiRailSet* arg1)
{
    return stub<thiscall_t<i32, aiMap*, class aiRailSet*>>(0x43A840, this, arg1);
}

i32 aiMap::ChooseNextStraightLink(class aiRailSet* arg1)
{
    return stub<thiscall_t<i32, aiMap*, class aiRailSet*>>(0x43AAE0, this, arg1);
}

void aiMap::Clean()
{
    return stub<thiscall_t<void, aiMap*>>(0x433FF0, this);
}

void aiMap::Cull()
{
    return stub<thiscall_t<void, aiMap*>>(0x436680, this);
}

class aiPath* aiMap::DetRdSegBetweenInts(class aiIntersection* arg1, class aiIntersection* arg2)
{
    return stub<thiscall_t<class aiPath*, aiMap*, class aiIntersection*, class aiIntersection*>>(
        0x43BB10, this, arg1, arg2);
}

i32 aiMap::DetermineOppMapComponent(class Matrix34& arg1, class aiRailSet* arg2, i16* arg3, i16* arg4, f32* arg5,
    f32* arg6, i16* arg7, f32* arg8, f32 arg9, i16 arg10, i16 arg11)
{
    return stub<
        thiscall_t<i32, aiMap*, class Matrix34&, class aiRailSet*, i16*, i16*, f32*, f32*, i16*, f32*, f32, i16, i16>>(
        0x437310, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
}

i32 aiMap::DetermineOppRoadPosInfo(
    class Vector3& arg1, class Vector3& arg2, class aiRailSet* arg3, i16* arg4, f32* arg5, f32* arg6, i32 arg7)
{
    return stub<thiscall_t<i32, aiMap*, class Vector3&, class Vector3&, class aiRailSet*, i16*, f32*, f32*, i32>>(
        0x438CB0, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

i32 aiMap::DeterminePerpMapComponent(
    class Matrix34& arg1, class aiRailSet* arg2, i16* arg3, i16* arg4, f32* arg5, f32* arg6, i16* arg7)
{
    return stub<thiscall_t<i32, aiMap*, class Matrix34&, class aiRailSet*, i16*, i16*, f32*, f32*, i16*>>(
        0x4370B0, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

i32 aiMap::DetermineRoadPosInfo(
    class Matrix34& arg1, class aiRailSet* arg2, i16* arg3, f32* arg4, i16* arg5, f32* arg6, i32 arg7)
{
    return stub<thiscall_t<i32, aiMap*, class Matrix34&, class aiRailSet*, i16*, f32*, i16*, f32*, i32>>(
        0x436F10, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void aiMap::DrawAppRoads()
{
    return stub<thiscall_t<void, aiMap*>>(0x436D70, this);
}

void aiMap::DrawNextVisibleAmbient()
{
    return stub<thiscall_t<void, aiMap*>>(0x436CD0, this);
}

void aiMap::Dump()
{
    return stub<thiscall_t<void, aiMap*>>(0x439400, this);
}

i32 aiMap::FindAmbAppRoad(i32 arg1)
{
    return stub<thiscall_t<i32, aiMap*, i32>>(0x438D90, this, arg1);
}

i32 aiMap::FindPedAppRoad(i32 arg1)
{
    return stub<thiscall_t<i32, aiMap*, i32>>(0x438DE0, this, arg1);
}

void aiMap::GetCameraPos()
{
    return stub<thiscall_t<void, aiMap*>>(0x439540, this);
}

class MetaClass* aiMap::GetClass()
{
    return stub<thiscall_t<class MetaClass*, aiMap*>>(0x43BD90, this);
}

i32 aiMap::GoodRoadForCopStartPos(i32 arg1)
{
    return stub<thiscall_t<i32, aiMap*, i32>>(0x43BB90, this, arg1);
}

void aiMap::Init(char* arg1, char* arg2, char* arg3, class mmCar* arg4)
{
    return stub<thiscall_t<void, aiMap*, char*, char*, char*, class mmCar*>>(0x434220, this, arg1, arg2, arg3, arg4);
}

class aiIntersection* aiMap::Intersection(i32 arg1)
{
    return stub<thiscall_t<class aiIntersection*, aiMap*, i32>>(0x433E80, this, arg1);
}

i32 aiMap::MapComponent(class Vector3& arg1, i16* arg2, i16* arg3, i16 arg4)
{
    return stub<thiscall_t<i32, aiMap*, class Vector3&, i16*, i16*, i16>>(0x436D90, this, arg1, arg2, arg3, arg4);
}

class aiVehicleOpponent* aiMap::Opponent(i32 arg1)
{
    return stub<thiscall_t<class aiVehicleOpponent*, aiMap*, i32>>(0x433F30, this, arg1);
}

class aiPath* aiMap::Path(i32 arg1)
{
    return stub<thiscall_t<class aiPath*, aiMap*, i32>>(0x433E50, this, arg1);
}

class aiPedestrian* aiMap::Pedestrian(i32 arg1)
{
    return stub<thiscall_t<class aiPedestrian*, aiMap*, i32>>(0x433F70, this, arg1);
}

class Vector3& aiMap::PlayerPos()
{
    return stub<thiscall_t<class Vector3&, aiMap*>>(0x433FB0, this);
}

class aiVehiclePolice* aiMap::Police(i32 arg1)
{
    return stub<thiscall_t<class aiVehiclePolice*, aiMap*, i32>>(0x433EF0, this, arg1);
}

class aiPath* aiMap::PredictAmbFreewayIntersectionPath(i32 arg1, class Matrix34& arg2)
{
    return stub<thiscall_t<class aiPath*, aiMap*, i32, class Matrix34&>>(0x4391F0, this, arg1, arg2);
}

class aiPath* aiMap::PredictAmbIntersectionPath(i32 arg1, class Matrix34& arg2)
{
    return stub<thiscall_t<class aiPath*, aiMap*, i32, class Matrix34&>>(0x439010, this, arg1, arg2);
}

class aiPath* aiMap::PredictIntersectionPath(i32 arg1, class Matrix34& arg2)
{
    return stub<thiscall_t<class aiPath*, aiMap*, i32, class Matrix34&>>(0x438E30, this, arg1, arg2);
}

void aiMap::RemoveAmbient(class aiVehicleSpline* arg1)
{
    return stub<thiscall_t<void, aiMap*, class aiVehicleSpline*>>(0x43BAA0, this, arg1);
}

void aiMap::RemovePedestrian(class aiPedestrian* arg1)
{
    return stub<thiscall_t<void, aiMap*, class aiPedestrian*>>(0x43B530, this, arg1);
}

void aiMap::Reset()
{
    return stub<thiscall_t<void, aiMap*>>(0x435FB0, this);
}

void aiMap::Stats()
{
    return stub<thiscall_t<void, aiMap*>>(0x435770, this);
}

void aiMap::Update()
{
    return stub<thiscall_t<void, aiMap*>>(0x4362F0, this);
}

void aiMap::UpdatePaused()
{
    return stub<thiscall_t<void, aiMap*>>(0x436670, this);
}

class aiVehicleAmbient* aiMap::Vehicle(i32 arg1)
{
    return stub<thiscall_t<class aiVehicleAmbient*, aiMap*, i32>>(0x433EB0, this, arg1);
}

void aiMap::DeclareFields()
{
    return stub<cdecl_t<void>>(0x43BC20);
}

class aiPath* aiMap::AddAIPath(class mmRoadSect& arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<class aiPath*, aiMap*, class mmRoadSect&, i32, i32>>(0x439570, this, arg1, arg2, arg3);
}

void aiMap::AddIntToAppRoadMap(class CArrayList* arg1, i32 arg2, f32 arg3, struct asPortalCell** arg4, i32 arg5)
{
    return stub<thiscall_t<void, aiMap*, class CArrayList*, i32, f32, struct asPortalCell**, i32>>(
        0x43A300, this, arg1, arg2, arg3, arg4, arg5);
}

void aiMap::AdjustAmbients(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, aiMap*, i32, i32>>(0x43B5A0, this, arg1, arg2);
}

void aiMap::AdjustPedestrians(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, aiMap*, i32, i32>>(0x43B160, this, arg1, arg2);
}

void aiMap::CreateAmbAppRoadMap()
{
    return stub<thiscall_t<void, aiMap*>>(0x439800, this);
}

void aiMap::CreatePedAppRoadMap()
{
    return stub<thiscall_t<void, aiMap*>>(0x439D80, this);
}

i32 aiMap::FindRoad(class CArrayList* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, aiMap*, class CArrayList*, i32>>(0x43A400, this, arg1, arg2);
}

class aiIntersection* aiMap::NewIntersection(class Vector3& arg1)
{
    return stub<thiscall_t<class aiIntersection*, aiMap*, class Vector3&>>(0x439720, this, arg1);
}

i32 aiMap::NumCars(i32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<i32, aiMap*, i32, f32, f32>>(0x43A3D0, this, arg1, arg2, arg3);
}

void aiMap::ReadBinary(char* arg1)
{
    return stub<thiscall_t<void, aiMap*, char*>>(0x4359B0, this, arg1);
}

f32 aiMap::RoadDensity(i32 arg1, f32 arg2, i32 arg3)
{
    return stub<thiscall_t<f32, aiMap*, i32, f32, i32>>(0x43A380, this, arg1, arg2, arg3);
}

void aiMap::SaveBinary(char* arg1)
{
    return stub<thiscall_t<void, aiMap*, char*>>(0x435830, this, arg1);
}

class aiIntersection* aiMap::ScanIntersections(class Vector3& arg1)
{
    return stub<thiscall_t<class aiIntersection*, aiMap*, class Vector3&>>(0x4396A0, this, arg1);
}

CArrayList::CArrayList()
{
    unimplemented();
}

CArrayList::~CArrayList()
{
    unimplemented();
}

void CArrayList::Append(i32 arg1)
{
    return stub<thiscall_t<void, CArrayList*, i32>>(0x446C20, this, arg1);
}

f32 Clamp(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<cdecl_t<f32, f32, f32, f32>>(0x43C0D0, arg1, arg2, arg3);
}
