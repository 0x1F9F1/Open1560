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

define_dummy_symbol(mmai_aiGoalChase);

#include "aiGoalChase.h"

aiGoalChase::aiGoalChase(
    class aiVehiclePolice* arg1, class aiRailSet* arg2, class mmCar** arg3, i16* arg4, class Vector3* arg5, i16* arg6)
{
    unimplemented(arg1, arg2, arg3, arg4, arg5, arg6);
}

aiGoalChase::~aiGoalChase()
{
    unimplemented();
}

void aiGoalChase::Init()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x5FDC0_Offset, this);
}

void aiGoalChase::Reset()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x5FED0_Offset, this);
}

i32 aiGoalChase::Context()
{
    return stub<thiscall_t<i32, aiGoalChase*>>(0x60080_Offset, this);
}

i32 aiGoalChase::Priority()
{
    return stub<thiscall_t<i32, aiGoalChase*>>(0x60760_Offset, this);
}

void aiGoalChase::Update()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x60770_Offset, this);
}

void aiGoalChase::Dump()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x655D0_Offset, this);
}

void aiGoalChase::AddToBlockedRange(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, aiGoalChase*, f32, f32, f32>>(0x64F10_Offset, this, arg1, arg2, arg3);
}

void aiGoalChase::AvoidAmbientCollision(i32 arg1)
{
    return stub<thiscall_t<void, aiGoalChase*, i32>>(0x650B0_Offset, this, arg1);
}

void aiGoalChase::AvoidCopCollision(class aiVehiclePolice* arg1)
{
    return stub<thiscall_t<void, aiGoalChase*, class aiVehiclePolice*>>(0x62030_Offset, this, arg1);
}

void aiGoalChase::Barricade()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x63570_Offset, this);
}

void aiGoalChase::Block()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x63A00_Offset, this);
}

void aiGoalChase::CalcSpeed(f32 arg1)
{
    return stub<thiscall_t<void, aiGoalChase*, f32>>(0x62430_Offset, this, arg1);
}

void aiGoalChase::CloseInOpenArea()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x63090_Offset, this);
}

void aiGoalChase::CloseInRoad()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x62BB0_Offset, this);
}

i32 aiGoalChase::Collision(class mmCar* arg1)
{
    return stub<thiscall_t<i32, aiGoalChase*, class mmCar*>>(0x60600_Offset, this, arg1);
}

i32 aiGoalChase::DetectAmbientCollision(i32* arg1)
{
    return stub<thiscall_t<i32, aiGoalChase*, i32*>>(0x64000_Offset, this, arg1);
}

class aiVehiclePolice* aiGoalChase::DetectCopCollision()
{
    return stub<thiscall_t<class aiVehiclePolice*, aiGoalChase*>>(0x61EF0_Offset, this);
}

i32 aiGoalChase::FindPerp(i32 arg1, i32 arg2, class aiPath* arg3)
{
    return stub<thiscall_t<i32, aiGoalChase*, i32, i32, class aiPath*>>(0x61DC0_Offset, this, arg1, arg2, arg3);
}

void aiGoalChase::Follow()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x62300_Offset, this);
}

i32 aiGoalChase::Fov(class mmCar* arg1)
{
    return stub<thiscall_t<i32, aiGoalChase*, class mmCar*>>(0x60420_Offset, this, arg1);
}

i32 aiGoalChase::HitMe(class mmCar* arg1)
{
    return stub<thiscall_t<i32, aiGoalChase*, class mmCar*>>(0x60620_Offset, this, arg1);
}

i32 aiGoalChase::IsPerpACop(class mmCar* arg1)
{
    return stub<thiscall_t<i32, aiGoalChase*, class mmCar*>>(0x60670_Offset, this, arg1);
}

i32 aiGoalChase::LocatePerpFromInt(class aiIntersection* arg1, class aiPath** arg2)
{
    return stub<thiscall_t<i32, aiGoalChase*, class aiIntersection*, class aiPath**>>(0x61B60_Offset, this, arg1, arg2);
}

i32 aiGoalChase::LocatePerpFromRoad(class aiPath* arg1, class aiPath** arg2, class aiPath** arg3)
{
    return stub<thiscall_t<i32, aiGoalChase*, class aiPath*, class aiPath**, class aiPath**>>(
        0x61490_Offset, this, arg1, arg2, arg3);
}

i32 aiGoalChase::OffRoad(class mmCar* arg1)
{
    return stub<thiscall_t<i32, aiGoalChase*, class mmCar*>>(0x60690_Offset, this, arg1);
}

i32 aiGoalChase::PlanRoute()
{
    return stub<thiscall_t<i32, aiGoalChase*>>(0x613F0_Offset, this);
}

void aiGoalChase::ProcessCollision(i32 arg1)
{
    return stub<thiscall_t<void, aiGoalChase*, i32>>(0x65310_Offset, this, arg1);
}

void aiGoalChase::Push()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x63E10_Offset, this);
}

i32 aiGoalChase::Speeding(class mmCar* arg1)
{
    return stub<thiscall_t<i32, aiGoalChase*, class mmCar*>>(0x605B0_Offset, this, arg1);
}

i32 aiGoalChase::Stopped(class mmCar* arg1)
{
    return stub<thiscall_t<i32, aiGoalChase*, class mmCar*>>(0x60640_Offset, this, arg1);
}
