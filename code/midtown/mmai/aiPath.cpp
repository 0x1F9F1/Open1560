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

define_dummy_symbol(mmai_aiPath);

#include "aiPath.h"

aiPath::aiPath(i32 arg1)
{
    unimplemented(arg1);
}

aiPath::~aiPath()
{
    unimplemented();
}

void aiPath::AddPathVerts(class Vector3* arg1, i32 arg2)
{
    return stub<thiscall_t<void, aiPath*, class Vector3*, i32>>(0x43CFA0, this, arg1, arg2);
}

void aiPath::AddPathVerts(class mmRoadSect& arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, aiPath*, class mmRoadSect&, i32, i32>>(0x43C670, this, arg1, arg2, arg3);
}

void aiPath::AddPedestrian(class aiPedestrian* arg1)
{
    return stub<thiscall_t<void, aiPath*, class aiPedestrian*>>(0x43FE80, this, arg1);
}

void aiPath::AddVehicle(class aiVehicleSpline* arg1, i32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, aiPath*, class aiVehicleSpline*, i32, f32>>(0x43FB80, this, arg1, arg2, arg3);
}

void aiPath::AllwaysGo(i32 arg1)
{
    return stub<thiscall_t<void, aiPath*, i32>>(0x43E650, this, arg1);
}

void aiPath::AllwaysStop(i32 arg1)
{
    return stub<thiscall_t<void, aiPath*, i32>>(0x43E4F0, this, arg1);
}

void aiPath::AmbientCenterDistance(class aiVehicleSpline* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5)
{
    return stub<thiscall_t<void, aiPath*, class aiVehicleSpline*, f32*, f32*, f32*, f32*>>(
        0x43F020, this, arg1, arg2, arg3, arg4, arg5);
}

void aiPath::Blocked(i32 arg1)
{
    return stub<thiscall_t<void, aiPath*, i32>>(0x43FF30, this, arg1);
}

void aiPath::CalcCenterVerts(class mmRoadSect& arg1, i32 arg2)
{
    return stub<thiscall_t<void, aiPath*, class mmRoadSect&, i32>>(0x43D610, this, arg1, arg2);
}

i32 aiPath::CenterDistance(class Vector3& arg1, i16* arg2, f32* arg3, f32* arg4)
{
    return stub<thiscall_t<i32, aiPath*, class Vector3&, i16*, f32*, f32*>>(0x43ED00, this, arg1, arg2, arg3, arg4);
}

i32 aiPath::CenterIndex(f32 arg1)
{
    return stub<thiscall_t<i32, aiPath*, f32>>(0x43E840, this, arg1);
}

f32 aiPath::CenterLength(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<f32, aiPath*, i32, i32>>(0x43E670, this, arg1, arg2);
}

void aiPath::CenterPosition(f32 arg1, class Vector3& arg2)
{
    return stub<thiscall_t<void, aiPath*, f32, class Vector3&>>(0x43E8E0, this, arg1, arg2);
}

class Vector3* aiPath::CenterVertice(i32 arg1)
{
    return stub<thiscall_t<class Vector3*, aiPath*, i32>>(0x440020, this, arg1);
}

i32 aiPath::ContinuityError(i32 arg1)
{
    return stub<thiscall_t<i32, aiPath*, i32>>(0x43F9D0, this, arg1);
}

void aiPath::Draw()
{
    return stub<thiscall_t<void, aiPath*>>(0x43E0C0, this);
}

void aiPath::DrawId()
{
    return stub<thiscall_t<void, aiPath*>>(0x43E370, this);
}

void aiPath::DrawNormals()
{
    return stub<thiscall_t<void, aiPath*>>(0x43E280, this);
}

void aiPath::DrawVehicleIds()
{
    return stub<thiscall_t<void, aiPath*>>(0x43E3E0, this);
}

void aiPath::Dump()
{
    return stub<thiscall_t<void, aiPath*>>(0x43E450, this);
}

f32 aiPath::GetHeading(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<f32, aiPath*, f32, i32>>(0x43E6B0, this, arg1, arg2);
}

i32 aiPath::Index(class Vector3& arg1)
{
    return stub<thiscall_t<i32, aiPath*, class Vector3&>>(0x43EA60, this, arg1);
}

i32 aiPath::Index(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, aiPath*, f32, i32>>(0x43E9B0, this, arg1, arg2);
}

void aiPath::IntersectionEntryPt(class Vector3& arg1, i32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, aiPath*, class Vector3&, i32, f32>>(0x43F7D0, this, arg1, arg2, arg3);
}

void aiPath::IntersectionEntryVector(class Vector3& arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiPath*, class Vector3&, f32>>(0x43F890, this, arg1, arg2);
}

void aiPath::IntersectionExitVector(class Vector3& arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiPath*, class Vector3&, f32>>(0x43F910, this, arg1, arg2);
}

class Vector3* aiPath::LBoundary(i32 arg1)
{
    return stub<thiscall_t<class Vector3*, aiPath*, i32>>(0x459E90, this, arg1);
}

i32 aiPath::NumVehiclesAfterDist(i32 arg1, f32 arg2)
{
    return stub<thiscall_t<i32, aiPath*, i32, f32>>(0x43F980, this, arg1, arg2);
}

void aiPath::PopVehicle(class aiVehicleSpline* arg1, i32 arg2)
{
    return stub<thiscall_t<void, aiPath*, class aiVehicleSpline*, i32>>(0x43FA30, this, arg1, arg2);
}

void aiPath::PushVehicle(class aiVehicleSpline* arg1, i32 arg2)
{
    return stub<thiscall_t<void, aiPath*, class aiVehicleSpline*, i32>>(0x43FB10, this, arg1, arg2);
}

void aiPath::ReadBinary(class Stream* arg1)
{
    return stub<thiscall_t<void, aiPath*, class Stream*>>(0x43DBC0, this, arg1);
}

void aiPath::RemovePedestrian(class aiPedestrian* arg1)
{
    return stub<thiscall_t<void, aiPath*, class aiPedestrian*>>(0x43FEC0, this, arg1);
}

i32 aiPath::RemoveVehicle(class aiVehicleSpline* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, aiPath*, class aiVehicleSpline*, i32>>(0x43FCB0, this, arg1, arg2);
}

void aiPath::Reset()
{
    return stub<thiscall_t<void, aiPath*>>(0x43C450, this);
}

void aiPath::ResetVehicleReactTicks()
{
    return stub<thiscall_t<void, aiPath*>>(0x43C640, this);
}

i32 aiPath::RoadCapacity(class aiVehicleSpline* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, aiPath*, class aiVehicleSpline*, i32>>(0x43FDC0, this, arg1, arg2);
}

void aiPath::RoadDistance(class Vector3& arg1, i16* arg2, f32* arg3, i16 arg4, f32* arg5)
{
    return stub<thiscall_t<void, aiPath*, class Vector3&, i16*, f32*, i16, f32*>>(
        0x43EB60, this, arg1, arg2, arg3, arg4, arg5);
}

void aiPath::SaveBinary(class Stream* arg1)
{
    return stub<thiscall_t<void, aiPath*, class Stream*>>(0x43D950, this, arg1);
}

void aiPath::StopDestinationSources(i32 arg1)
{
    return stub<thiscall_t<void, aiPath*, i32>>(0x43E5D0, this, arg1);
}

void aiPath::StopIncomingRoads(i32 arg1)
{
    return stub<thiscall_t<void, aiPath*, i32>>(0x43E510, this, arg1);
}

void aiPath::SubSectionDir(class Vector3& arg1, i32 arg2, i32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, aiPath*, class Vector3&, i32, i32, f32>>(0x43F780, this, arg1, arg2, arg3, arg4);
}

f32 aiPath::SubSectionDist(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<f32, aiPath*, f32, i32>>(0x43E780, this, arg1, arg2);
}

f32 aiPath::SubSectionLength(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<f32, aiPath*, i32, i32>>(0x43E690, this, arg1, arg2);
}

void aiPath::SubSectionPt(class Vector3& arg1, i32 arg2, i32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, aiPath*, class Vector3&, i32, i32, f32>>(0x43F710, this, arg1, arg2, arg3, arg4);
}

void aiPath::UpdateAmbients()
{
    return stub<thiscall_t<void, aiPath*>>(0x43C490, this);
}

void aiPath::UpdatePedestrians()
{
    return stub<thiscall_t<void, aiPath*>>(0x43C5A0, this);
}

class Vector3* aiPath::VertXDir(i32 arg1)
{
    return stub<thiscall_t<class Vector3*, aiPath*, i32>>(0x43FF50, this, arg1);
}

class Vector3* aiPath::VertZDir(i32 arg1)
{
    return stub<thiscall_t<class Vector3*, aiPath*, i32>>(0x43FFD0, this, arg1);
}
