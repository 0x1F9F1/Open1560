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

define_dummy_symbol(mmcar_netaudiomanager);

#include "netaudiomanager.h"

NetAudioManager::NetAudioManager()
{
    unimplemented();
}

NetAudioManager::~NetAudioManager()
{
    unimplemented(arg1);
}

i16 NetAudioManager::AddVehicle(class mmNetworkCarAudio* arg1)
{
    return stub<thiscall_t<i16, NetAudioManager*, class mmNetworkCarAudio*>>(0x475770, this, arg1);
}

i16 NetAudioManager::AllocateAddOnEngine(char* arg1)
{
    return stub<thiscall_t<i16, NetAudioManager*, char*>>(0x476D20, this, arg1);
}

class AudSound** NetAudioManager::AllocateEngine(char* arg1)
{
    return stub<thiscall_t<class AudSound**, NetAudioManager*, char*>>(0x476EF0, this, arg1);
}

void NetAudioManager::AllocateEngine(i16 arg1)
{
    return stub<thiscall_t<void, NetAudioManager*, i16>>(0x476BA0, this, arg1);
}

void NetAudioManager::AllocateHorn(i16 arg1)
{
    return stub<thiscall_t<void, NetAudioManager*, i16>>(0x477170, this, arg1);
}

void NetAudioManager::AllocateImpacts()
{
    return stub<thiscall_t<void, NetAudioManager*>>(0x4775E0, this);
}

void NetAudioManager::AllocatePoliceSiren()
{
    return stub<thiscall_t<void, NetAudioManager*>>(0x477670, this);
}

void NetAudioManager::AllocateReverseBeep()
{
    return stub<thiscall_t<void, NetAudioManager*>>(0x477020, this);
}

void NetAudioManager::AllocateSkids()
{
    return stub<thiscall_t<void, NetAudioManager*>>(0x477360, this);
}

void NetAudioManager::AssignSounds(class mmNetworkCarAudio* arg1, i16 arg2)
{
    return stub<thiscall_t<void, NetAudioManager*, class mmNetworkCarAudio*, i16>>(0x476000, this, arg1, arg2);
}

void NetAudioManager::EchoOff()
{
    return stub<thiscall_t<void, NetAudioManager*>>(0x475E70, this);
}

void NetAudioManager::EchoOn(f32 arg1)
{
    return stub<thiscall_t<void, NetAudioManager*, f32>>(0x475B00, this, arg1);
}

i16 NetAudioManager::FindGreatestDistance(class mmNetworkCarAudio* arg1)
{
    return stub<thiscall_t<i16, NetAudioManager*, class mmNetworkCarAudio*>>(0x475860, this, arg1);
}

i16 NetAudioManager::FindUnusedSlot()
{
    return stub<thiscall_t<i16, NetAudioManager*>>(0x475900, this);
}

f32 NetAudioManager::GetAvailableDistance()
{
    return stub<thiscall_t<f32, NetAudioManager*>>(0x476B60, this);
}

void NetAudioManager::RemoveVehicle(class mmNetworkCarAudio* arg1, i16 arg2)
{
    return stub<thiscall_t<void, NetAudioManager*, class mmNetworkCarAudio*, i16>>(0x475800, this, arg1, arg2);
}

void NetAudioManager::Update()
{
    return stub<thiscall_t<void, NetAudioManager*>>(0x475940, this);
}

void NetAudioManager::AssignAddOnSounds(class mmNetworkCarAudio* arg1, i16 arg2)
{
    return stub<thiscall_t<void, NetAudioManager*, class mmNetworkCarAudio*, i16>>(0x476940, this, arg1, arg2);
}
