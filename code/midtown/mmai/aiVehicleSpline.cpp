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
    return stub<thiscall_t<void, aiVehicleSpline*, i32>>(0x45BD00, this, arg1);
}

class mmOpponentImpactAudio* aiVehicleSpline::GetImpactAudioPtr()
{
    return stub<thiscall_t<class mmOpponentImpactAudio*, aiVehicleSpline*>>(0x4465E0, this);
}

void aiVehicleSpline::PlayHorn(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiVehicleSpline*, f32, f32>>(0x4465F0, this, arg1, arg2);
}

void aiVehicleSpline::ImpactAudioReaction(f32 arg1)
{
    return stub<thiscall_t<void, aiVehicleSpline*, f32>>(0x446600, this, arg1);
}

void aiVehicleSpline::StopVoice()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x446610, this);
}

class MetaClass* aiVehicleSpline::GetClass()
{
    return stub<thiscall_t<class MetaClass*, aiVehicleSpline*>>(0x45C3E0, this);
}

void aiVehicleSpline::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, aiVehicleSpline*, class Bank*>>(0x45C1F0, this, arg1);
}

void aiVehicleSpline::AvoidPlayerCollision()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x45BC50, this);
}

i32 aiVehicleSpline::DetectPlayerCollision(i32 arg1, f32 arg2)
{
    return stub<thiscall_t<i32, aiVehicleSpline*, i32, f32>>(0x45B270, this, arg1, arg2);
}

i32 aiVehicleSpline::DetectPlayerForwardCollision()
{
    return stub<thiscall_t<i32, aiVehicleSpline*>>(0x45B040, this);
}

i32 aiVehicleSpline::DetectPlayerTargetPtCollision()
{
    return stub<thiscall_t<i32, aiVehicleSpline*>>(0x45B130, this);
}

i32 aiVehicleSpline::DetectPlayerZoneCollision()
{
    return stub<thiscall_t<i32, aiVehicleSpline*>>(0x45B870, this);
}

f32 aiVehicleSpline::DistanceToIntersection()
{
    return stub<thiscall_t<f32, aiVehicleSpline*>>(0x45BFF0, this);
}

f32 aiVehicleSpline::DistanceToVehicle(class aiVehicleSpline* arg1)
{
    return stub<thiscall_t<f32, aiVehicleSpline*, class aiVehicleSpline*>>(0x45BD10, this, arg1);
}

void aiVehicleSpline::DrawId()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x45C200, this);
}

void aiVehicleSpline::Dump()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x45C090, this);
}

void aiVehicleSpline::Init(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, aiVehicleSpline*, char*, i32>>(0x459FC0, this, arg1, arg2);
}

i32 aiVehicleSpline::IsAmbientBlockingPlayer()
{
    return stub<thiscall_t<i32, aiVehicleSpline*>>(0x45BB60, this);
}

i32 aiVehicleSpline::IsThePlayerInFrontOfMe()
{
    return stub<thiscall_t<i32, aiVehicleSpline*>>(0x45BA60, this);
}

void aiVehicleSpline::Reset()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x45A2B0, this);
}

void aiVehicleSpline::ResetReactTicks()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x45A340, this);
}

void aiVehicleSpline::SolvePositionAndOrientation()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x45A3A0, this);
}

void aiVehicleSpline::SolveYPositionAndOrientation()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x45AAB0, this);
}

f32 aiVehicleSpline::TotLength()
{
    return stub<thiscall_t<f32, aiVehicleSpline*>>(0x45BCF0, this);
}

i32 aiVehicleSpline::Type()
{
    return stub<thiscall_t<i32, aiVehicleSpline*>>(0x45C500, this);
}

void aiVehicleSpline::Update()
{
    return stub<thiscall_t<void, aiVehicleSpline*>>(0x45A2F0, this);
}

i32 aiVehicleSpline::WaitTime()
{
    return stub<thiscall_t<i32, aiVehicleSpline*>>(0x45BCD0, this);
}

void aiVehicleSpline::DeclareFields()
{
    return stub<cdecl_t<void>>(0x45C250);
}
