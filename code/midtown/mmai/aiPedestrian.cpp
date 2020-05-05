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

define_dummy_symbol(mmai_aiPedestrian);

#include "aiPedestrian.h"

aiPedestrian::aiPedestrian()
{
    unimplemented();
}

aiPedestrian::~aiPedestrian()
{
    unimplemented();
}

void aiPedestrian::CalculateAudioPanning()
{
    return stub<thiscall_t<void, aiPedestrian*>>(0x4CFC0_Offset, this);
}

void aiPedestrian::CalculateDistToPlayer2()
{
    return stub<thiscall_t<void, aiPedestrian*>>(0x4CF70_Offset, this);
}

void aiPedestrian::DrawDebug()
{
    return stub<thiscall_t<void, aiPedestrian*>>(0x4D3B0_Offset, this);
}

void aiPedestrian::Dump()
{
    return stub<thiscall_t<void, aiPedestrian*>>(0x4D1E0_Offset, this);
}

void aiPedestrian::Go()
{
    return stub<thiscall_t<void, aiPedestrian*>>(0x4D1A0_Offset, this);
}

void aiPedestrian::Init(char* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, aiPedestrian*, char*, i32, i32>>(0x47DB0_Offset, this, arg1, arg2, arg3);
}

void aiPedestrian::PlayVoice(i16 arg1)
{
    return stub<thiscall_t<void, aiPedestrian*, i16>>(0x4CEA0_Offset, this, arg1);
}

void aiPedestrian::Reset()
{
    return stub<thiscall_t<void, aiPedestrian*>>(0x4D130_Offset, this);
}

void aiPedestrian::Reset(class aiPath* arg1)
{
    return stub<thiscall_t<void, aiPedestrian*, class aiPath*>>(0x48130_Offset, this, arg1);
}

void aiPedestrian::SetVoiceSoundPtr(class AudSound* arg1)
{
    return stub<thiscall_t<void, aiPedestrian*, class AudSound*>>(0x4D0E0_Offset, this, arg1);
}

void aiPedestrian::Stop()
{
    return stub<thiscall_t<void, aiPedestrian*>>(0x4D160_Offset, this);
}

void aiPedestrian::UnAssignSounds()
{
    return stub<thiscall_t<void, aiPedestrian*>>(0x4D0F0_Offset, this);
}

void aiPedestrian::Update()
{
    return stub<thiscall_t<void, aiPedestrian*>>(0x48460_Offset, this);
}

void aiPedestrian::UpdateAudio()
{
    return stub<thiscall_t<void, aiPedestrian*>>(0x4D010_Offset, this);
}

void aiPedestrian::Anticipate(class mmIntersection& arg1, i32 arg2)
{
    return stub<thiscall_t<void, aiPedestrian*, class mmIntersection&, i32>>(0x49CB0_Offset, this, arg1, arg2);
}

void aiPedestrian::Avoid(class mmIntersection& arg1, f32* arg2)
{
    return stub<thiscall_t<void, aiPedestrian*, class mmIntersection&, f32*>>(0x49ED0_Offset, this, arg1, arg2);
}

void aiPedestrian::AvoidBanger(class mmInstance* arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiPedestrian*, class mmInstance*, f32>>(0x4C170_Offset, this, arg1, arg2);
}

void aiPedestrian::AvoidObstacle(class Vector3& arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiPedestrian*, class Vector3&, f32>>(0x4C350_Offset, this, arg1, arg2);
}

void aiPedestrian::AvoidPedCollision(class aiPedestrian* arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiPedestrian*, class aiPedestrian*, f32>>(0x4C260_Offset, this, arg1, arg2);
}

void aiPedestrian::AvoidPlayer(class Vector3& arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiPedestrian*, class Vector3&, f32>>(0x4C0E0_Offset, this, arg1, arg2);
}

void aiPedestrian::CalcCurve(i32 arg1, i32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, aiPedestrian*, i32, i32, f32>>(0x4C6E0_Offset, this, arg1, arg2, arg3);
}

void aiPedestrian::ComputeCurve(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4)
{
    return stub<thiscall_t<void, aiPedestrian*, class Vector3&, class Vector3&, class Vector3&, class Vector3&>>(
        0x4CDA0_Offset, this, arg1, arg2, arg3, arg4);
}

i32 aiPedestrian::DetectBangerCollision(class mmInstance** arg1, f32* arg2, f32 arg3)
{
    return stub<thiscall_t<i32, aiPedestrian*, class mmInstance**, f32*, f32>>(0x4B420_Offset, this, arg1, arg2, arg3);
}

class mmInstance* aiPedestrian::DetectBangerObstacle()
{
    return stub<thiscall_t<class mmInstance*, aiPedestrian*>>(0x4BA10_Offset, this);
}

i32 aiPedestrian::DetectPedCollision(f32 arg1, class aiPedestrian** arg2, f32* arg3)
{
    return stub<thiscall_t<i32, aiPedestrian*, f32, class aiPedestrian**, f32*>>(
        0x4BC00_Offset, this, arg1, arg2, arg3);
}

class aiPedestrian* aiPedestrian::DetectPedObstacle()
{
    return stub<thiscall_t<class aiPedestrian*, aiPedestrian*>>(0x4BB80_Offset, this);
}

i32 aiPedestrian::DetectPlayerAnticipate(f32* arg1, f32* arg2)
{
    return stub<thiscall_t<i32, aiPedestrian*, f32*, f32*>>(0x4A4D0_Offset, this, arg1, arg2);
}

i32 aiPedestrian::DetectPlayerCollision(f32* arg1)
{
    return stub<thiscall_t<i32, aiPedestrian*, f32*>>(0x4B0C0_Offset, this, arg1);
}

i32 aiPedestrian::DetectPlayerForwardCollision(f32* arg1, f32* arg2)
{
    return stub<thiscall_t<i32, aiPedestrian*, f32*, f32*>>(0x4A2F0_Offset, this, arg1, arg2);
}

i16 aiPedestrian::GetRaceVoiceIndex()
{
    return stub<thiscall_t<i16, aiPedestrian*>>(0x4D650_Offset, this);
}

i16 aiPedestrian::GetRoamVoiceIndex()
{
    return stub<thiscall_t<i16, aiPedestrian*>>(0x4D480_Offset, this);
}

class aiPath* aiPedestrian::PickNextRdSeg()
{
    return stub<thiscall_t<class aiPath*, aiPedestrian*>>(0x4AED0_Offset, this);
}

f32 aiPedestrian::RoadDistance()
{
    return stub<thiscall_t<f32, aiPedestrian*>>(0x4A690_Offset, this);
}

void aiPedestrian::SolvePosition(class Vector3& arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiPedestrian*, class Vector3&, f32>>(0x4CE50_Offset, this, arg1, arg2);
}

void aiPedestrian::SolveRoadSegment(f32 arg1)
{
    return stub<thiscall_t<void, aiPedestrian*, f32>>(0x4AD90_Offset, this, arg1);
}

void aiPedestrian::SolveTargetPoint(f32 arg1)
{
    return stub<thiscall_t<void, aiPedestrian*, f32>>(0x4C670_Offset, this, arg1);
}

f32 aiPedestrian::TimeToCollision(f32 arg1)
{
    return stub<thiscall_t<f32, aiPedestrian*, f32>>(0x4A2D0_Offset, this, arg1);
}

void aiPedestrian::Wander()
{
    return stub<thiscall_t<void, aiPedestrian*>>(0x49850_Offset, this);
}

aiPedestrianInstance::~aiPedestrianInstance()
{
    unimplemented(arg1);
}

void aiPedestrianInstance::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, aiPedestrianInstance*, class Bank*>>(0x4DA30_Offset, this, arg1);
}

i32 aiPedestrianInstance::ComputeLod(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<i32, aiPedestrianInstance*, f32, f32>>(0x4D820_Offset, this, arg1, arg2);
}

void __fastcall aiPedestrianInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, aiPedestrianInstance*, i32>>(0x4D850_Offset, this, arg1);
}

void __fastcall aiPedestrianInstance::DrawShadow()
{
    return stub<fastcall_t<void, aiPedestrianInstance*>>(0x4D960_Offset, this);
}

void __fastcall aiPedestrianInstance::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, aiPedestrianInstance*, class Matrix34 const&>>(0x4D800_Offset, this, arg1);
}

class Vector3& __fastcall aiPedestrianInstance::GetPos()
{
    return stub<fastcall_t<class Vector3&, aiPedestrianInstance*>>(0x4D810_Offset, this);
}

class Matrix34& __fastcall aiPedestrianInstance::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, aiPedestrianInstance*, class Matrix34&>>(0x4D7F0_Offset, this, arg1);
}
