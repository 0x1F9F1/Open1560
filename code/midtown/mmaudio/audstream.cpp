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

#include "audstream.h"

AudStream::AudStream(u32 arg1, i32 arg2, i16 arg3)
{
    unimplemented();
}

AudStream::~AudStream()
{
    unimplemented();
}

void AudStream::DeallocateStreamObjs()
{
    return stub<thiscall_t<void, AudStream*>>(0xF3800_Offset, this);
}

void AudStream::Disable()
{
    return stub<thiscall_t<void, AudStream*>>(0xF3AC0_Offset, this);
}

void AudStream::Enable()
{
    return stub<thiscall_t<void, AudStream*>>(0xF3AB0_Offset, this);
}

class StreamObj* AudStream::GetCurrentSoundObj()
{
    return stub<thiscall_t<class StreamObj*, AudStream*>>(0xF4140_Offset, this);
}

f32 AudStream::GetFrequency(i32 arg1)
{
    return stub<thiscall_t<f32, AudStream*, i32>>(0xF3FA0_Offset, this, arg1);
}

i32 AudStream::IsPlaying()
{
    return stub<thiscall_t<i32, AudStream*>>(0xF40E0_Offset, this);
}

i32 AudStream::Load(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, AudStream*, char*, i32>>(0xF3910_Offset, this, arg1, arg2);
}

void AudStream::PlayLoop(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, AudStream*, f32, f32>>(0xF3E40_Offset, this, arg1, arg2);
}

void AudStream::PlayLoop(char* arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, AudStream*, char*, f32, f32>>(0xF3D20_Offset, this, arg1, arg2, arg3);
}

void AudStream::PlayOnce(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, AudStream*, f32, f32>>(0xF3B60_Offset, this, arg1, arg2);
}

void AudStream::PlayOnce(char* arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, AudStream*, char*, f32, f32>>(0xF3C10_Offset, this, arg1, arg2, arg3);
}

void AudStream::ReallocateStreamObjs()
{
    return stub<thiscall_t<void, AudStream*>>(0xF3890_Offset, this);
}

void AudStream::Reset()
{
    return stub<thiscall_t<void, AudStream*>>(0xF3AE0_Offset, this);
}

void AudStream::SetFrequency(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudStream*, f32, i32>>(0xF3F30_Offset, this, arg1, arg2);
}

void AudStream::SetLoopIndex(i16 arg1)
{
    return stub<thiscall_t<void, AudStream*, i16>>(0xF4180_Offset, this, arg1);
}

void AudStream::SetLoopPointInfo(u32 arg1, u32 arg2, u32 arg3, i16 arg4, i16 arg5)
{
    return stub<thiscall_t<void, AudStream*, u32, u32, u32, i16, i16>>(
        0xF41B0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void AudStream::SetNumLoopIndices(i16 arg1)
{
    return stub<thiscall_t<void, AudStream*, i16>>(0xF4150_Offset, this, arg1);
}

void AudStream::SetPan(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudStream*, f32, i32>>(0xF4050_Offset, this, arg1, arg2);
}

void AudStream::SetPlayPosition(u32 arg1)
{
    return stub<thiscall_t<void, AudStream*, u32>>(0xF3B50_Offset, this, arg1);
}

void AudStream::SetPriority(i32 arg1)
{
    return stub<thiscall_t<void, AudStream*, i32>>(0xF37E0_Offset, this, arg1);
}

void AudStream::SetVolume(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudStream*, f32, i32>>(0xF3FE0_Offset, this, arg1, arg2);
}

void AudStream::SetupNotifications()
{
    return stub<thiscall_t<void, AudStream*>>(0xF41F0_Offset, this);
}

void AudStream::Stop()
{
    return stub<thiscall_t<void, AudStream*>>(0xF3EF0_Offset, this);
}

void AudStream::StopNow()
{
    return stub<thiscall_t<void, AudStream*>>(0xF3F10_Offset, this);
}

void AudStream::Update()
{
    return stub<thiscall_t<void, AudStream*>>(0xF3B00_Offset, this);
}

u32 const AudStream::Get2DFlags()
{
    return stub<cdecl_t<u32 const>>(0xF4100_Offset);
}

u32 const AudStream::GetFreqChange2DFlags()
{
    return stub<cdecl_t<u32 const>>(0xF4120_Offset);
}

define_dummy_symbol(mmaudio_audstream);
