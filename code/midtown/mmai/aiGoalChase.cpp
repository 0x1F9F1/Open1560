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
    return stub<thiscall_t<void, aiGoalChase*>>(0x45FDC0, this);
}

void aiGoalChase::Reset()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x45FED0, this);
}

i32 aiGoalChase::Context()
{
    return stub<thiscall_t<i32, aiGoalChase*>>(0x460080, this);
}

i32 aiGoalChase::Priority()
{
    return stub<thiscall_t<i32, aiGoalChase*>>(0x460760, this);
}

void aiGoalChase::Update()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x460770, this);
}

void aiGoalChase::Dump()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x4655D0, this);
}

void aiGoalChase::AddToBlockedRange(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, aiGoalChase*, f32, f32, f32>>(0x464F10, this, arg1, arg2, arg3);
}

void aiGoalChase::AvoidAmbientCollision(i32 arg1)
{
    return stub<thiscall_t<void, aiGoalChase*, i32>>(0x4650B0, this, arg1);
}

void aiGoalChase::AvoidCopCollision(class aiVehiclePolice* arg1)
{
    return stub<thiscall_t<void, aiGoalChase*, class aiVehiclePolice*>>(0x462030, this, arg1);
}

void aiGoalChase::Barricade()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x463570, this);
}

void aiGoalChase::Block()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x463A00, this);
}

void aiGoalChase::CalcSpeed(f32 arg1)
{
    return stub<thiscall_t<void, aiGoalChase*, f32>>(0x462430, this, arg1);
}

void aiGoalChase::CloseInOpenArea()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x463090, this);
}

void aiGoalChase::CloseInRoad()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x462BB0, this);
}

i32 aiGoalChase::Collision(class mmCar* arg1)
{
    return stub<thiscall_t<i32, aiGoalChase*, class mmCar*>>(0x460600, this, arg1);
}

i32 aiGoalChase::DetectAmbientCollision(i32* arg1)
{
    return stub<thiscall_t<i32, aiGoalChase*, i32*>>(0x464000, this, arg1);
}

class aiVehiclePolice* aiGoalChase::DetectCopCollision()
{
    return stub<thiscall_t<class aiVehiclePolice*, aiGoalChase*>>(0x461EF0, this);
}

i32 aiGoalChase::FindPerp(i32 arg1, i32 arg2, class aiPath* arg3)
{
    return stub<thiscall_t<i32, aiGoalChase*, i32, i32, class aiPath*>>(0x461DC0, this, arg1, arg2, arg3);
}

void aiGoalChase::Follow()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x462300, this);
}

i32 aiGoalChase::Fov(class mmCar* arg1)
{
    return stub<thiscall_t<i32, aiGoalChase*, class mmCar*>>(0x460420, this, arg1);
}

i32 aiGoalChase::HitMe(class mmCar* arg1)
{
    return stub<thiscall_t<i32, aiGoalChase*, class mmCar*>>(0x460620, this, arg1);
}

i32 aiGoalChase::IsPerpACop(class mmCar* arg1)
{
    return stub<thiscall_t<i32, aiGoalChase*, class mmCar*>>(0x460670, this, arg1);
}

i32 aiGoalChase::LocatePerpFromInt(class aiIntersection* arg1, class aiPath** arg2)
{
    return stub<thiscall_t<i32, aiGoalChase*, class aiIntersection*, class aiPath**>>(0x461B60, this, arg1, arg2);
}

i32 aiGoalChase::LocatePerpFromRoad(class aiPath* arg1, class aiPath** arg2, class aiPath** arg3)
{
    return stub<thiscall_t<i32, aiGoalChase*, class aiPath*, class aiPath**, class aiPath**>>(
        0x461490, this, arg1, arg2, arg3);
}

i32 aiGoalChase::OffRoad(class mmCar* arg1)
{
    return stub<thiscall_t<i32, aiGoalChase*, class mmCar*>>(0x460690, this, arg1);
}

i32 aiGoalChase::PlanRoute()
{
    return stub<thiscall_t<i32, aiGoalChase*>>(0x4613F0, this);
}

void aiGoalChase::ProcessCollision(i32 arg1)
{
    return stub<thiscall_t<void, aiGoalChase*, i32>>(0x465310, this, arg1);
}

void aiGoalChase::Push()
{
    return stub<thiscall_t<void, aiGoalChase*>>(0x463E10, this);
}

i32 aiGoalChase::Speeding(class mmCar* arg1)
{
    return stub<thiscall_t<i32, aiGoalChase*, class mmCar*>>(0x4605B0, this, arg1);
}

i32 aiGoalChase::Stopped(class mmCar* arg1)
{
    return stub<thiscall_t<i32, aiGoalChase*, class mmCar*>>(0x460640, this, arg1);
}
