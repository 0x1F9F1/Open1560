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

define_dummy_symbol(mmai_aipedaudiomanager);

#include "aipedaudiomanager.h"

aiPedAudioManager::aiPedAudioManager()
{
    unimplemented();
}

aiPedAudioManager::~aiPedAudioManager()
{
    unimplemented(arg1);
}

i16 aiPedAudioManager::Add(class aiPedestrian* arg1)
{
    return stub<thiscall_t<i16, aiPedAudioManager*, class aiPedestrian*>>(0x447030, this, arg1);
}

void aiPedAudioManager::AssignSounds(i16 arg1)
{
    return stub<thiscall_t<void, aiPedAudioManager*, i16>>(0x447280, this, arg1);
}

i16 aiPedAudioManager::FindGreatestDistance(class aiPedestrian* arg1)
{
    return stub<thiscall_t<i16, aiPedAudioManager*, class aiPedestrian*>>(0x447150, this, arg1);
}

i16 aiPedAudioManager::FindUnusedSlot()
{
    return stub<thiscall_t<i16, aiPedAudioManager*>>(0x4471E0, this);
}

void aiPedAudioManager::RandomizeSeconds(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, aiPedAudioManager*, f32, f32>>(0x4472A0, this, arg1, arg2);
}

void aiPedAudioManager::Remove(class aiPedestrian* arg1, i16 arg2)
{
    return stub<thiscall_t<void, aiPedAudioManager*, class aiPedestrian*, i16>>(0x4470E0, this, arg1, arg2);
}

void aiPedAudioManager::Update()
{
    return stub<thiscall_t<void, aiPedAudioManager*>>(0x447220, this);
}
