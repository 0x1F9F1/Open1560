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
    return stub<thiscall_t<void, aiPath*, class Vector3*, i32>>(0x3CFA0_Offset, this, arg1, arg2);
}

void aiPath::AddPathVerts(class mmRoadSect& arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, aiPath*, class mmRoadSect&, i32, i32>>(0x3C670_Offset, this, arg1, arg2, arg3);
}

void aiPath::AddPedestrian(class aiPedestrian* arg1)
{
    return stub<thiscall_t<void, aiPath*, class aiPedestrian*>>(0x3FE80_Offset, this, arg1);
}

void aiPath::AddVehicle(class aiVehicleSpline* arg1, i32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, aiPath*, class aiVehicleSpline*, i32, f32>>(0x3FB80_Offset, this, arg1, arg2, arg3);
}

void aiPath::AllwaysGo(i32 arg1)
{
    return stub<thiscall_t<void, aiPath*, i32>>(0x3E650_Offset, this, arg1);
}

void aiPath::AllwaysStop(i32 arg1)
{
    return stub<thiscall_t<void, aiPath*, i32>>(0x3E4F0_Offset, this, arg1);
}

void aiPath::AmbientCenterDistance(class aiVehicleSpline* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5)
{
    return stub<thiscall_t<void, aiPath*, class aiVehicleSpline*, f32*, f32*, f32*, f32*>>(
        0x3F020_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void aiPath::Blocked(i32 arg1)
{
    return stub<thiscall_t<void, aiPath*, i32>>(0x3FF30_Offset, this, arg1);
}

void aiPath::CalcCenterVerts(class mmRoadSect& arg1, i32 arg2)
{
    return stub<thiscall_t<void, aiPath*, class mmRoadSect&, i32>>(0x3D610_Offset, this, arg1, arg2);
}

i32 aiPath::CenterDistance(class Vector3& arg1, i16* arg2, f32* arg3, f32* arg4)
{
    return stub<thiscall_t<i32, aiPath*, class Vector3&, i16*, f32*, f32*>>(
        0x3ED00_Offset, this, arg1, arg2, arg3, arg4);
}

i32 aiPath::CenterIndex(f32 arg1)
{
    return stub<thiscall_t<i32, aiPath*, f32>>(0x3E840_Offset, this, arg1);
}

f32 aiPath::CenterLength(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<f32, aiPath*, i32, i32>>(0x3E670_Offset, this, arg1, arg2);
}

void aiPath::CenterPosition(f32 arg1, class Vector3& arg2)
{
    return stub<thiscall_t<void, aiPath*, f32, class Vector3&>>(0x3E8E0_Offset, this, arg1, arg2);
}

class Vector3* aiPath::CenterVertice(i32 arg1)
{
    return stub<thiscall_t<class Vector3*, aiPath*, i32>>(0x40020_Offset, this, arg1);
}

i32 aiPath::ContinuityError(i32 arg1)
{
    return stub<thiscall_t<i32, aiPath*, i32>>(0x3F9D0_Offset, this, arg1);
}

void aiPath::Draw()
{
    return stub<thiscall_t<void, aiPath*>>(0x3E0C0_Offset, this);
}

void aiPath::DrawId()
{
    return stub<thiscall_t<void, aiPath*>>(0x3E370_Offset, this);
}

void aiPath::DrawNormals()
{
    return stub<thiscall_t<void, aiPath*>>(0x3E280_Offset, this);
}

void aiPath::DrawVehicleIds()
{
    return stub<thiscall_t<void, aiPath*>>(0x3E3E0_Offset, this);
}

void aiPath::Dump()
{
    return stub<thiscall_t<void, aiPath*>>(0x3E450_Offset, this);
}

f32 aiPath::GetHeading(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<f32, aiPath*, f32, i32>>(0x3E6B0_Offset, this, arg1, arg2);
}

i32 aiPath::Index(class Vector3& arg1)
{
    return stub<thiscall_t<i32, aiPath*, class Vector3&>>(0x3EA60_Offset, this, arg1);
}

i32 aiPath::Index(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, aiPath*, f32, i32>>(0x3E9B0_Offset, this, arg1, arg2);
}

void aiPath::IntersectionEntryPt(class Vector3& arg1, i32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, aiPath*, class Vector3&, i32, f32>>(0x3F7D0_Offset, this, arg1, arg2, arg3);
}

void aiPath::IntersectionEntryVector(class Vector3& arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiPath*, class Vector3&, f32>>(0x3F890_Offset, this, arg1, arg2);
}

void aiPath::IntersectionExitVector(class Vector3& arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiPath*, class Vector3&, f32>>(0x3F910_Offset, this, arg1, arg2);
}

class Vector3* aiPath::LBoundary(i32 arg1)
{
    return stub<thiscall_t<class Vector3*, aiPath*, i32>>(0x59E90_Offset, this, arg1);
}

i32 aiPath::NumVehiclesAfterDist(i32 arg1, f32 arg2)
{
    return stub<thiscall_t<i32, aiPath*, i32, f32>>(0x3F980_Offset, this, arg1, arg2);
}

void aiPath::PopVehicle(class aiVehicleSpline* arg1, i32 arg2)
{
    return stub<thiscall_t<void, aiPath*, class aiVehicleSpline*, i32>>(0x3FA30_Offset, this, arg1, arg2);
}

void aiPath::PushVehicle(class aiVehicleSpline* arg1, i32 arg2)
{
    return stub<thiscall_t<void, aiPath*, class aiVehicleSpline*, i32>>(0x3FB10_Offset, this, arg1, arg2);
}

void aiPath::ReadBinary(class Stream* arg1)
{
    return stub<thiscall_t<void, aiPath*, class Stream*>>(0x3DBC0_Offset, this, arg1);
}

void aiPath::RemovePedestrian(class aiPedestrian* arg1)
{
    return stub<thiscall_t<void, aiPath*, class aiPedestrian*>>(0x3FEC0_Offset, this, arg1);
}

i32 aiPath::RemoveVehicle(class aiVehicleSpline* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, aiPath*, class aiVehicleSpline*, i32>>(0x3FCB0_Offset, this, arg1, arg2);
}

void aiPath::Reset()
{
    return stub<thiscall_t<void, aiPath*>>(0x3C450_Offset, this);
}

void aiPath::ResetVehicleReactTicks()
{
    return stub<thiscall_t<void, aiPath*>>(0x3C640_Offset, this);
}

i32 aiPath::RoadCapacity(class aiVehicleSpline* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, aiPath*, class aiVehicleSpline*, i32>>(0x3FDC0_Offset, this, arg1, arg2);
}

void aiPath::RoadDistance(class Vector3& arg1, i16* arg2, f32* arg3, i16 arg4, f32* arg5)
{
    return stub<thiscall_t<void, aiPath*, class Vector3&, i16*, f32*, i16, f32*>>(
        0x3EB60_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void aiPath::SaveBinary(class Stream* arg1)
{
    return stub<thiscall_t<void, aiPath*, class Stream*>>(0x3D950_Offset, this, arg1);
}

void aiPath::StopDestinationSources(i32 arg1)
{
    return stub<thiscall_t<void, aiPath*, i32>>(0x3E5D0_Offset, this, arg1);
}

void aiPath::StopIncomingRoads(i32 arg1)
{
    return stub<thiscall_t<void, aiPath*, i32>>(0x3E510_Offset, this, arg1);
}

void aiPath::SubSectionDir(class Vector3& arg1, i32 arg2, i32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, aiPath*, class Vector3&, i32, i32, f32>>(0x3F780_Offset, this, arg1, arg2, arg3, arg4);
}

f32 aiPath::SubSectionDist(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<f32, aiPath*, f32, i32>>(0x3E780_Offset, this, arg1, arg2);
}

f32 aiPath::SubSectionLength(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<f32, aiPath*, i32, i32>>(0x3E690_Offset, this, arg1, arg2);
}

void aiPath::SubSectionPt(class Vector3& arg1, i32 arg2, i32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, aiPath*, class Vector3&, i32, i32, f32>>(0x3F710_Offset, this, arg1, arg2, arg3, arg4);
}

void aiPath::UpdateAmbients()
{
    return stub<thiscall_t<void, aiPath*>>(0x3C490_Offset, this);
}

void aiPath::UpdatePedestrians()
{
    return stub<thiscall_t<void, aiPath*>>(0x3C5A0_Offset, this);
}

class Vector3* aiPath::VertXDir(i32 arg1)
{
    return stub<thiscall_t<class Vector3*, aiPath*, i32>>(0x3FF50_Offset, this, arg1);
}

class Vector3* aiPath::VertZDir(i32 arg1)
{
    return stub<thiscall_t<class Vector3*, aiPath*, i32>>(0x3FFD0_Offset, this, arg1);
}
