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

define_dummy_symbol(mmui_audio);

#include "audio.h"

AudioOptions::AudioOptions(i32 arg1)
{
    unimplemented(arg1);
}

AudioOptions::~AudioOptions()
{
    unimplemented();
}

void AudioOptions::CancelAction()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49D150, this);
}

void AudioOptions::DoneAction()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49D1D0, this);
}

i32 AudioOptions::FindDevice(char* arg1)
{
    return stub<thiscall_t<i32, AudioOptions*, char*>>(0x49D480, this, arg1);
}

char* AudioOptions::GetCurrentDeviceName()
{
    return stub<thiscall_t<char*, AudioOptions*>>(0x49D510, this);
}

void AudioOptions::PreSetup()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49CEF0, this);
}

void AudioOptions::ResetCDMusic()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49D590, this);
}

void AudioOptions::ResetCommentary()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49D620, this);
}

void AudioOptions::ResetDefaultAction()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49D0D0, this);
}

void AudioOptions::ResetSoundFX()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49D560, this);
}

void AudioOptions::ResetSoundQuality()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49D5C0, this);
}

void AudioOptions::ResetStereo()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49D530, this);
}

void AudioOptions::SetAudioState()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49D1E0, this);
}

void AudioOptions::SetBalance()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49CF40, this);
}

void AudioOptions::SetCDMusic()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49D3F0, this);
}

void AudioOptions::SetCDVolume()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49CF20, this);
}

void AudioOptions::SetCommentary()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49D450, this);
}

void AudioOptions::SetDevice(i32 arg1)
{
    return stub<thiscall_t<void, AudioOptions*, i32>>(0x49D650, this, arg1);
}

void AudioOptions::SetQuality()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49CF70, this);
}

void AudioOptions::SetSoundFX()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49D420, this);
}

void AudioOptions::SetStereoFX()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49D040, this);
}

void AudioOptions::SetWaveVolume()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49CF00, this);
}

void AudioOptions::StoreCurrentSetup()
{
    return stub<thiscall_t<void, AudioOptions*>>(0x49D0C0, this);
}
