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

define_dummy_symbol(mmai_aiVehicleSpline);

#include "aiVehicleSpline.h"

aiVehicleSpline::aiVehicleSpline()
{
    unimplemented();
}

aiVehicleSpline::~aiVehicleSpline()
{
    unimplemented();
}

void aiVehicleSpline::Impact(i32 arg1)
{
    return stub<thiscall_t<void, aiVehicleSpline*, i32>>(0x5BD00_Offset, this, arg1);
}

class mmOpponentImpactAudio* aiVehicleSpline::GetImpactAudioPtr()
{
    return stub<thiscall_t<class mmOpponentImpactAudio*, aiVehicleSpline*>>(0x465E0_Offset, this);
}

void aiVehicleSpline::PlayHorn(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiVehicleSpline*, f32, f32>>(0x465F0_Offset, this, arg1, arg2);
}

void aiVehicleSpline::ImpactAudioReaction(f32 arg1)
{
    return stub<thiscall_t<void, aiVehicleSpline*, f32>>(0x46600_Offset, this, arg1);
}

void aiVehicleSpline::StopVoice()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x46610_Offset, this);
}

class MetaClass* aiVehicleSpline::GetClass()
{
    return stub<thiscall_t<class MetaClass*, aiVehicleSpline*>>(0x5C3E0_Offset, this);
}

void aiVehicleSpline::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, aiVehicleSpline*, class Bank*>>(0x5C1F0_Offset, this, arg1);
}

void aiVehicleSpline::AvoidPlayerCollision()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x5BC50_Offset, this);
}

i32 aiVehicleSpline::DetectPlayerCollision(i32 arg1, f32 arg2)
{
    return stub<thiscall_t<i32, aiVehicleSpline*, i32, f32>>(0x5B270_Offset, this, arg1, arg2);
}

i32 aiVehicleSpline::DetectPlayerForwardCollision()
{
    return stub<thiscall_t<i32, aiVehicleSpline*>>(0x5B040_Offset, this);
}

i32 aiVehicleSpline::DetectPlayerTargetPtCollision()
{
    return stub<thiscall_t<i32, aiVehicleSpline*>>(0x5B130_Offset, this);
}

i32 aiVehicleSpline::DetectPlayerZoneCollision()
{
    return stub<thiscall_t<i32, aiVehicleSpline*>>(0x5B870_Offset, this);
}

f32 aiVehicleSpline::DistanceToIntersection()
{
    return stub<thiscall_t<f32, aiVehicleSpline*>>(0x5BFF0_Offset, this);
}

f32 aiVehicleSpline::DistanceToVehicle(class aiVehicleSpline* arg1)
{
    return stub<thiscall_t<f32, aiVehicleSpline*, class aiVehicleSpline*>>(0x5BD10_Offset, this, arg1);
}

void aiVehicleSpline::DrawId()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x5C200_Offset, this);
}

void aiVehicleSpline::Dump()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x5C090_Offset, this);
}

void aiVehicleSpline::Init(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, aiVehicleSpline*, char*, i32>>(0x59FC0_Offset, this, arg1, arg2);
}

i32 aiVehicleSpline::IsAmbientBlockingPlayer()
{
    return stub<thiscall_t<i32, aiVehicleSpline*>>(0x5BB60_Offset, this);
}

i32 aiVehicleSpline::IsThePlayerInFrontOfMe()
{
    return stub<thiscall_t<i32, aiVehicleSpline*>>(0x5BA60_Offset, this);
}

void aiVehicleSpline::Reset()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x5A2B0_Offset, this);
}

void aiVehicleSpline::ResetReactTicks()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x5A340_Offset, this);
}

void aiVehicleSpline::SolvePositionAndOrientation()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x5A3A0_Offset, this);
}

void aiVehicleSpline::SolveYPositionAndOrientation()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x5AAB0_Offset, this);
}

f32 aiVehicleSpline::TotLength()
{
    return stub<thiscall_t<f32, aiVehicleSpline*>>(0x5BCF0_Offset, this);
}

i32 aiVehicleSpline::Type()
{
    return stub<thiscall_t<i32, aiVehicleSpline*>>(0x5C500_Offset, this);
}

void aiVehicleSpline::Update()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x5A2F0_Offset, this);
}

i32 aiVehicleSpline::WaitTime()
{
    return stub<thiscall_t<i32, aiVehicleSpline*>>(0x5BCD0_Offset, this);
}

void aiVehicleSpline::DeclareFields()
{
    return stub<cdecl_t<void>>(0x5C250_Offset);
}
