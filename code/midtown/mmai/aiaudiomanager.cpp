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

#include "aiaudiomanager.h"

aiAudioManager::aiAudioManager()
{
    unimplemented();
}

aiAudioManager::~aiAudioManager()
{
    unimplemented();
}

i16 aiAudioManager::AddVehicle(class aiVehicleAmbient* arg1)
{
    return stub<thiscall_t<i16, aiAudioManager*, class aiVehicleAmbient*>>(0x40790_Offset, this, arg1);
}

i16 aiAudioManager::AddVehicle(class aiVehicleOpponent* arg1)
{
    return stub<thiscall_t<i16, aiAudioManager*, class aiVehicleOpponent*>>(0x40840_Offset, this, arg1);
}

i16 aiAudioManager::AddVehicle(class aiVehiclePolice* arg1)
{
    return stub<thiscall_t<i16, aiAudioManager*, class aiVehiclePolice*>>(0x408F0_Offset, this, arg1);
}

i16 aiAudioManager::AllocateAddOnEngine(char* arg1)
{
    return stub<thiscall_t<i16, aiAudioManager*, char*>>(0x43930_Offset, this, arg1);
}

void aiAudioManager::AllocateAmbients()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x42820_Offset, this);
}

void aiAudioManager::AllocateCopVoice()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x42EB0_Offset, this);
}

class AudSound** aiAudioManager::AllocateEngine(char* arg1)
{
    return stub<thiscall_t<class AudSound**, aiAudioManager*, char*>>(0x43B00_Offset, this, arg1);
}

void aiAudioManager::AllocateEngine(i16 arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiAudioManager*, i16, i16>>(0x43720_Offset, this, arg1, arg2);
}

void aiAudioManager::AllocateHorns()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x43370_Offset, this);
}

void aiAudioManager::AllocateImpacts()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x432C0_Offset, this);
}

void aiAudioManager::AllocateOpponents()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x42880_Offset, this);
}

void aiAudioManager::AllocatePolice()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x428D0_Offset, this);
}

void aiAudioManager::AllocateReverseBeep()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x43C50_Offset, this);
}

void aiAudioManager::AllocateSkids()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x42C10_Offset, this);
}

void aiAudioManager::AllocateVoices()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x43550_Offset, this);
}

void aiAudioManager::AssignAddOnSounds(class aiVehicleOpponent* arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiAudioManager*, class aiVehicleOpponent*, i16>>(0x41F50_Offset, this, arg1, arg2);
}

void aiAudioManager::AssignSounds(class aiVehicleAmbient* arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiAudioManager*, class aiVehicleAmbient*, i16>>(0x42630_Offset, this, arg1, arg2);
}

void aiAudioManager::AssignSounds(class aiVehicleOpponent* arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiAudioManager*, class aiVehicleOpponent*, i16>>(0x41B60_Offset, this, arg1, arg2);
}

void aiAudioManager::AssignSounds(class aiVehiclePolice* arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiAudioManager*, class aiVehiclePolice*, i16>>(0x42050_Offset, this, arg1, arg2);
}

void aiAudioManager::EchoOff()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x419C0_Offset, this);
}

void aiAudioManager::EchoOn(f32 arg1)
{
    return stub<thiscall_t<void, aiAudioManager*, f32>>(0x41670_Offset, this, arg1);
}

i16 aiAudioManager::FindGreatestDistance(class aiVehicleAmbient* arg1)
{
    return stub<thiscall_t<i16, aiAudioManager*, class aiVehicleAmbient*>>(0x40AF0_Offset, this, arg1);
}

i16 aiAudioManager::FindGreatestDistance(class aiVehicleOpponent* arg1)
{
    return stub<thiscall_t<i16, aiAudioManager*, class aiVehicleOpponent*>>(0x40CE0_Offset, this, arg1);
}

i16 aiAudioManager::FindGreatestDistance(class aiVehiclePolice* arg1)
{
    return stub<thiscall_t<i16, aiAudioManager*, class aiVehiclePolice*>>(0x40ED0_Offset, this, arg1);
}

i16 aiAudioManager::FindUnusedSlot()
{
    return stub<thiscall_t<i16, aiAudioManager*>>(0x412C0_Offset, this);
}

i16 aiAudioManager::GetClosestCop()
{
    return stub<thiscall_t<i16, aiAudioManager*>>(0x43E50_Offset, this);
}

void aiAudioManager::LoadCopVoice()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x42F90_Offset, this);
}

i16 aiAudioManager::PlayCopVoice()
{
    return stub<thiscall_t<i16, aiAudioManager*>>(0x43E00_Offset, this);
}

i16 aiAudioManager::QueueInCopVoice(f32 arg1)
{
    return stub<thiscall_t<i16, aiAudioManager*, f32>>(0x43DA0_Offset, this, arg1);
}

void aiAudioManager::RemoveVehicle(class aiVehicleAmbient* arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiAudioManager*, class aiVehicleAmbient*, i16>>(0x409A0_Offset, this, arg1, arg2);
}

void aiAudioManager::RemoveVehicle(class aiVehicleOpponent* arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiAudioManager*, class aiVehicleOpponent*, i16>>(0x40A10_Offset, this, arg1, arg2);
}

void aiAudioManager::RemoveVehicle(class aiVehiclePolice* arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiAudioManager*, class aiVehiclePolice*, i16>>(0x40A80_Offset, this, arg1, arg2);
}

i16 aiAudioManager::UnassignFurthestAmbient()
{
    return stub<thiscall_t<i16, aiAudioManager*>>(0x41130_Offset, this);
}

i16 aiAudioManager::UnassignFurthestOpponent()
{
    return stub<thiscall_t<i16, aiAudioManager*>>(0x411F0_Offset, this);
}

void aiAudioManager::Update()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x41300_Offset, this);
}

char* aiAudioManager::CatName(char* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<char*, aiAudioManager*, char*, i32, i32>>(0x430C0_Offset, this, arg1, arg2, arg3);
}

define_dummy_symbol(mmai_aiaudiomanager);
