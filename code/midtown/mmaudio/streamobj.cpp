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

define_dummy_symbol(mmaudio_streamobj);

#include "streamobj.h"

StreamObj::StreamObj()
{
    unimplemented();
}

StreamObj::~StreamObj()
{
    unimplemented();
}

i32 StreamObj::DSCreateSoundBuffer()
{
    return stub<thiscall_t<i32, StreamObj*>>(0x4F4DC0, this);
}

struct IDirectSoundBuffer* StreamObj::DSLoadSoundBuffer(char const* arg1, u32 arg2)
{
    return stub<thiscall_t<struct IDirectSoundBuffer*, StreamObj*, char const*, u32>>(0x4F4E50, this, arg1, arg2);
}

i32 StreamObj::FillDataBuffer(u32 arg1)
{
    return stub<thiscall_t<i32, StreamObj*, u32>>(0x4F5540, this, arg1);
}

class Stream* StreamObj::GetFileStreamPtr()
{
    return stub<thiscall_t<class Stream*, StreamObj*>>(0x4F6040, this);
}

i32 StreamObj::Init(char const* arg1, u32 arg2)
{
    return stub<thiscall_t<i32, StreamObj*, char const*, u32>>(0x4F5200, this, arg1, arg2);
}

i16 StreamObj::IsPlaying()
{
    return stub<thiscall_t<i16, StreamObj*>>(0x4F5750, this);
}

i32 StreamObj::Play()
{
    return stub<thiscall_t<i32, StreamObj*>>(0x4F5290, this);
}

i32 StreamObj::Play(char* arg1)
{
    return stub<thiscall_t<i32, StreamObj*, char*>>(0x4F5440, this, arg1);
}

void StreamObj::ReadInLoopIndex(i16 arg1)
{
    return stub<thiscall_t<void, StreamObj*, i16>>(0x4F61C0, this, arg1);
}

void StreamObj::SetFrequency(f32 arg1)
{
    return stub<thiscall_t<void, StreamObj*, f32>>(0x4F57B0, this, arg1);
}

void StreamObj::SetFrequencyEvent(f32 arg1)
{
    return stub<thiscall_t<void, StreamObj*, f32>>(0x4F53E0, this, arg1);
}

void StreamObj::SetLoopPointInfo(u32 arg1, u32 arg2, u32 arg3, i16 arg4, i16 arg5)
{
    return stub<thiscall_t<void, StreamObj*, u32, u32, u32, i16, i16>>(0x4F60B0, this, arg1, arg2, arg3, arg4, arg5);
}

void StreamObj::SetNumLoopIndices(i16 arg1)
{
    return stub<thiscall_t<void, StreamObj*, i16>>(0x4F6050, this, arg1);
}

void StreamObj::SetPan(f32 arg1)
{
    return stub<thiscall_t<void, StreamObj*, f32>>(0x4F58A0, this, arg1);
}

void StreamObj::SetPanEvent(f32 arg1)
{
    return stub<thiscall_t<void, StreamObj*, f32>>(0x4F5410, this, arg1);
}

void StreamObj::SetPlayOneShotEvent(char* arg1)
{
    return stub<thiscall_t<void, StreamObj*, char*>>(0x4F5330, this, arg1);
}

void StreamObj::SetPlayPosition(u32 arg1)
{
    return stub<thiscall_t<void, StreamObj*, u32>>(0x4F5270, this, arg1);
}

void StreamObj::SetPlayingFlag(i16 arg1)
{
    return stub<thiscall_t<void, StreamObj*, i16>>(0x4F6290, this, arg1);
}

void StreamObj::SetStopEvent()
{
    return stub<thiscall_t<void, StreamObj*>>(0x4F5390, this);
}

void StreamObj::SetVolume(f32 arg1)
{
    return stub<thiscall_t<void, StreamObj*, f32>>(0x4F5860, this, arg1);
}

void StreamObj::SetVolumeEvent(f32 arg1)
{
    return stub<thiscall_t<void, StreamObj*, f32>>(0x4F53B0, this, arg1);
}

i32 StreamObj::SetupNotifications()
{
    return stub<thiscall_t<i32, StreamObj*>>(0x4F58E0, this);
}

i32 StreamObj::Stop()
{
    return stub<thiscall_t<i32, StreamObj*>>(0x4F5510, this);
}

void StreamObj::Update()
{
    return stub<thiscall_t<void, StreamObj*>>(0x4F5F80, this);
}

u32 StreamObj::GetWaveBytesOffset(class Stream* arg1, i16 arg2)
{
    return stub<thiscall_t<u32, StreamObj*, class Stream*, i16>>(0x4F50C0, this, arg1, arg2);
}

class Stream* StreamObj::OpenWaveFile(char const* arg1, i16 arg2)
{
    return stub<thiscall_t<class Stream*, StreamObj*, char const*, i16>>(0x4F4EA0, this, arg1, arg2);
}

u32 HandleNotifications(void* arg1)
{
    return stub<cdecl_t<u32, void*>>(0x4F5B80, arg1);
}
