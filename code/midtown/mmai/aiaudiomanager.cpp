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

define_dummy_symbol(mmai_aiaudiomanager);

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
    return stub<thiscall_t<i16, aiAudioManager*, class aiVehicleAmbient*>>(0x440790, this, arg1);
}

i16 aiAudioManager::AddVehicle(class aiVehicleOpponent* arg1)
{
    return stub<thiscall_t<i16, aiAudioManager*, class aiVehicleOpponent*>>(0x440840, this, arg1);
}

i16 aiAudioManager::AddVehicle(class aiVehiclePolice* arg1)
{
    return stub<thiscall_t<i16, aiAudioManager*, class aiVehiclePolice*>>(0x4408F0, this, arg1);
}

i16 aiAudioManager::AllocateAddOnEngine(char* arg1)
{
    return stub<thiscall_t<i16, aiAudioManager*, char*>>(0x443930, this, arg1);
}

void aiAudioManager::AllocateAmbients()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x442820, this);
}

void aiAudioManager::AllocateCopVoice()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x442EB0, this);
}

class AudSound** aiAudioManager::AllocateEngine(char* arg1)
{
    return stub<thiscall_t<class AudSound**, aiAudioManager*, char*>>(0x443B00, this, arg1);
}

void aiAudioManager::AllocateEngine(i16 arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiAudioManager*, i16, i16>>(0x443720, this, arg1, arg2);
}

void aiAudioManager::AllocateHorns()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x443370, this);
}

void aiAudioManager::AllocateImpacts()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x4432C0, this);
}

void aiAudioManager::AllocateOpponents()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x442880, this);
}

void aiAudioManager::AllocatePolice()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x4428D0, this);
}

void aiAudioManager::AllocateReverseBeep()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x443C50, this);
}

void aiAudioManager::AllocateSkids()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x442C10, this);
}

void aiAudioManager::AllocateVoices()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x443550, this);
}

void aiAudioManager::AssignAddOnSounds(class aiVehicleOpponent* arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiAudioManager*, class aiVehicleOpponent*, i16>>(0x441F50, this, arg1, arg2);
}

void aiAudioManager::AssignSounds(class aiVehicleAmbient* arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiAudioManager*, class aiVehicleAmbient*, i16>>(0x442630, this, arg1, arg2);
}

void aiAudioManager::AssignSounds(class aiVehicleOpponent* arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiAudioManager*, class aiVehicleOpponent*, i16>>(0x441B60, this, arg1, arg2);
}

void aiAudioManager::AssignSounds(class aiVehiclePolice* arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiAudioManager*, class aiVehiclePolice*, i16>>(0x442050, this, arg1, arg2);
}

void aiAudioManager::EchoOff()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x4419C0, this);
}

void aiAudioManager::EchoOn(f32 arg1)
{
    return stub<thiscall_t<void, aiAudioManager*, f32>>(0x441670, this, arg1);
}

i16 aiAudioManager::FindGreatestDistance(class aiVehicleAmbient* arg1)
{
    return stub<thiscall_t<i16, aiAudioManager*, class aiVehicleAmbient*>>(0x440AF0, this, arg1);
}

i16 aiAudioManager::FindGreatestDistance(class aiVehicleOpponent* arg1)
{
    return stub<thiscall_t<i16, aiAudioManager*, class aiVehicleOpponent*>>(0x440CE0, this, arg1);
}

i16 aiAudioManager::FindGreatestDistance(class aiVehiclePolice* arg1)
{
    return stub<thiscall_t<i16, aiAudioManager*, class aiVehiclePolice*>>(0x440ED0, this, arg1);
}

i16 aiAudioManager::FindUnusedSlot()
{
    return stub<thiscall_t<i16, aiAudioManager*>>(0x4412C0, this);
}

i16 aiAudioManager::GetClosestCop()
{
    return stub<thiscall_t<i16, aiAudioManager*>>(0x443E50, this);
}

void aiAudioManager::LoadCopVoice()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x442F90, this);
}

i16 aiAudioManager::PlayCopVoice()
{
    return stub<thiscall_t<i16, aiAudioManager*>>(0x443E00, this);
}

i16 aiAudioManager::QueueInCopVoice(f32 arg1)
{
    return stub<thiscall_t<i16, aiAudioManager*, f32>>(0x443DA0, this, arg1);
}

void aiAudioManager::RemoveVehicle(class aiVehicleAmbient* arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiAudioManager*, class aiVehicleAmbient*, i16>>(0x4409A0, this, arg1, arg2);
}

void aiAudioManager::RemoveVehicle(class aiVehicleOpponent* arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiAudioManager*, class aiVehicleOpponent*, i16>>(0x440A10, this, arg1, arg2);
}

void aiAudioManager::RemoveVehicle(class aiVehiclePolice* arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiAudioManager*, class aiVehiclePolice*, i16>>(0x440A80, this, arg1, arg2);
}

i16 aiAudioManager::UnassignFurthestAmbient()
{
    return stub<thiscall_t<i16, aiAudioManager*>>(0x441130, this);
}

i16 aiAudioManager::UnassignFurthestOpponent()
{
    return stub<thiscall_t<i16, aiAudioManager*>>(0x4411F0, this);
}

void aiAudioManager::Update()
{
    return stub<thiscall_t<void, aiAudioManager*>>(0x441300, this);
}

char* aiAudioManager::CatName(char* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<char*, aiAudioManager*, char*, i32, i32>>(0x4430C0, this, arg1, arg2, arg3);
}
