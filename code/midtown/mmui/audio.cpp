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

#include "audio.h"

AudioOptions::AudioOptions(i32 arg1)
{
    unimplemented();
}

AudioOptions::~AudioOptions()
{
    unimplemented();
}

void AudioOptions::CancelAction()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9D150_Offset, this);
}

void AudioOptions::DoneAction()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9D1D0_Offset, this);
}

i32 AudioOptions::FindDevice(char* arg1)
{
    return stub<thiscall_t<i32, AudioOptions*, char*>>(0x9D480_Offset, this, arg1);
}

char* AudioOptions::GetCurrentDeviceName()
{
    return stub<thiscall_t<char*, AudioOptions*>>(0x9D510_Offset, this);
}

void AudioOptions::PreSetup()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9CEF0_Offset, this);
}

void AudioOptions::ResetCDMusic()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9D590_Offset, this);
}

void AudioOptions::ResetCommentary()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9D620_Offset, this);
}

void AudioOptions::ResetDefaultAction()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9D0D0_Offset, this);
}

void AudioOptions::ResetSoundFX()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9D560_Offset, this);
}

void AudioOptions::ResetSoundQuality()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9D5C0_Offset, this);
}

void AudioOptions::ResetStereo()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9D530_Offset, this);
}

void AudioOptions::SetAudioState()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9D1E0_Offset, this);
}

void AudioOptions::SetBalance()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9CF40_Offset, this);
}

void AudioOptions::SetCDMusic()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9D3F0_Offset, this);
}

void AudioOptions::SetCDVolume()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9CF20_Offset, this);
}

void AudioOptions::SetCommentary()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9D450_Offset, this);
}

void AudioOptions::SetDevice(i32 arg1)
{
    return stub<thiscall_t<void, AudioOptions*, i32>>(0x9D650_Offset, this, arg1);
}

void AudioOptions::SetQuality()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9CF70_Offset, this);
}

void AudioOptions::SetSoundFX()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9D420_Offset, this);
}

void AudioOptions::SetStereoFX()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9D040_Offset, this);
}

void AudioOptions::SetWaveVolume()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9CF00_Offset, this);
}

void AudioOptions::StoreCurrentSetup()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x9D0C0_Offset, this);
}

define_dummy_symbol(mmui_audio);
