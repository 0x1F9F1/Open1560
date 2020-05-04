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

#include "netaudiomanager.h"

NetAudioManager::NetAudioManager()
{
    unimplemented();
}

NetAudioManager::~NetAudioManager()
{
    unimplemented();
}

i16 NetAudioManager::AddVehicle(class mmNetworkCarAudio* arg1)
{
    return stub<thiscall_t<i16, NetAudioManager*, class mmNetworkCarAudio*>>(0x75770_Offset, this, arg1);
}

i16 NetAudioManager::AllocateAddOnEngine(char* arg1)
{
    return stub<thiscall_t<i16, NetAudioManager*, char*>>(0x76D20_Offset, this, arg1);
}

class AudSound** NetAudioManager::AllocateEngine(char* arg1)
{
    return stub<thiscall_t<class AudSound**, NetAudioManager*, char*>>(0x76EF0_Offset, this, arg1);
}

void NetAudioManager::AllocateEngine(i16 arg1)
{
    return stub<thiscall_t<void, NetAudioManager*, i16>>(0x76BA0_Offset, this, arg1);
}

void NetAudioManager::AllocateHorn(i16 arg1)
{
    return stub<thiscall_t<void, NetAudioManager*, i16>>(0x77170_Offset, this, arg1);
}

void NetAudioManager::AllocateImpacts()
{
    return stub<thiscall_t<void, NetAudioManager*>>(0x775E0_Offset, this);
}

void NetAudioManager::AllocatePoliceSiren()
{
    return stub<thiscall_t<void, NetAudioManager*>>(0x77670_Offset, this);
}

void NetAudioManager::AllocateReverseBeep()
{
    return stub<thiscall_t<void, NetAudioManager*>>(0x77020_Offset, this);
}

void NetAudioManager::AllocateSkids()
{
    return stub<thiscall_t<void, NetAudioManager*>>(0x77360_Offset, this);
}

void NetAudioManager::AssignSounds(class mmNetworkCarAudio* arg1, i16 arg2)
{
    return stub<thiscall_t<void, NetAudioManager*, class mmNetworkCarAudio*, i16>>(0x76000_Offset, this, arg1, arg2);
}

void NetAudioManager::EchoOff()
{
    return stub<thiscall_t<void, NetAudioManager*>>(0x75E70_Offset, this);
}

void NetAudioManager::EchoOn(f32 arg1)
{
    return stub<thiscall_t<void, NetAudioManager*, f32>>(0x75B00_Offset, this, arg1);
}

i16 NetAudioManager::FindGreatestDistance(class mmNetworkCarAudio* arg1)
{
    return stub<thiscall_t<i16, NetAudioManager*, class mmNetworkCarAudio*>>(0x75860_Offset, this, arg1);
}

i16 NetAudioManager::FindUnusedSlot()
{
    return stub<thiscall_t<i16, NetAudioManager*>>(0x75900_Offset, this);
}

f32 NetAudioManager::GetAvailableDistance()
{
    return stub<thiscall_t<f32, NetAudioManager*>>(0x76B60_Offset, this);
}

void NetAudioManager::RemoveVehicle(class mmNetworkCarAudio* arg1, i16 arg2)
{
    return stub<thiscall_t<void, NetAudioManager*, class mmNetworkCarAudio*, i16>>(0x75800_Offset, this, arg1, arg2);
}

void NetAudioManager::Update()
{
    return stub<thiscall_t<void, NetAudioManager*>>(0x75940_Offset, this);
}

void NetAudioManager::AssignAddOnSounds(class mmNetworkCarAudio* arg1, i16 arg2)
{
    return stub<thiscall_t<void, NetAudioManager*, class mmNetworkCarAudio*, i16>>(0x76940_Offset, this, arg1, arg2);
}

define_dummy_symbol(mmcar_netaudiomanager);
