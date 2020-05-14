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

define_dummy_symbol(mmaudio_audstream);

#include "audstream.h"

AudStream::AudStream(u32 arg1, i32 arg2, i16 arg3)
{
    unimplemented(arg1, arg2, arg3);
}

AudStream::~AudStream()
{
    unimplemented();
}

void AudStream::DeallocateStreamObjs()
{
    return stub<thiscall_t<void, AudStream*>>(0x4F3800, this);
}

void AudStream::Disable()
{
    return stub<thiscall_t<void, AudStream*>>(0x4F3AC0, this);
}

void AudStream::Enable()
{
    return stub<thiscall_t<void, AudStream*>>(0x4F3AB0, this);
}

class StreamObj* AudStream::GetCurrentSoundObj()
{
    return stub<thiscall_t<class StreamObj*, AudStream*>>(0x4F4140, this);
}

f32 AudStream::GetFrequency(i32 arg1)
{
    return stub<thiscall_t<f32, AudStream*, i32>>(0x4F3FA0, this, arg1);
}

i32 AudStream::IsPlaying()
{
    return stub<thiscall_t<i32, AudStream*>>(0x4F40E0, this);
}

i32 AudStream::Load(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, AudStream*, char*, i32>>(0x4F3910, this, arg1, arg2);
}

void AudStream::PlayLoop(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, AudStream*, f32, f32>>(0x4F3E40, this, arg1, arg2);
}

void AudStream::PlayLoop(char* arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, AudStream*, char*, f32, f32>>(0x4F3D20, this, arg1, arg2, arg3);
}

void AudStream::PlayOnce(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, AudStream*, f32, f32>>(0x4F3B60, this, arg1, arg2);
}

void AudStream::PlayOnce(char* arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, AudStream*, char*, f32, f32>>(0x4F3C10, this, arg1, arg2, arg3);
}

void AudStream::ReallocateStreamObjs()
{
    return stub<thiscall_t<void, AudStream*>>(0x4F3890, this);
}

void AudStream::Reset()
{
    return stub<thiscall_t<void, AudStream*>>(0x4F3AE0, this);
}

void AudStream::SetFrequency(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudStream*, f32, i32>>(0x4F3F30, this, arg1, arg2);
}

void AudStream::SetLoopIndex(i16 arg1)
{
    return stub<thiscall_t<void, AudStream*, i16>>(0x4F4180, this, arg1);
}

void AudStream::SetLoopPointInfo(u32 arg1, u32 arg2, u32 arg3, i16 arg4, i16 arg5)
{
    return stub<thiscall_t<void, AudStream*, u32, u32, u32, i16, i16>>(0x4F41B0, this, arg1, arg2, arg3, arg4, arg5);
}

void AudStream::SetNumLoopIndices(i16 arg1)
{
    return stub<thiscall_t<void, AudStream*, i16>>(0x4F4150, this, arg1);
}

void AudStream::SetPan(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudStream*, f32, i32>>(0x4F4050, this, arg1, arg2);
}

void AudStream::SetPlayPosition(u32 arg1)
{
    return stub<thiscall_t<void, AudStream*, u32>>(0x4F3B50, this, arg1);
}

void AudStream::SetPriority(i32 arg1)
{
    return stub<thiscall_t<void, AudStream*, i32>>(0x4F37E0, this, arg1);
}

void AudStream::SetVolume(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, AudStream*, f32, i32>>(0x4F3FE0, this, arg1, arg2);
}

void AudStream::SetupNotifications()
{
    return stub<thiscall_t<void, AudStream*>>(0x4F41F0, this);
}

void AudStream::Stop()
{
    return stub<thiscall_t<void, AudStream*>>(0x4F3EF0, this);
}

void AudStream::StopNow()
{
    return stub<thiscall_t<void, AudStream*>>(0x4F3F10, this);
}

void AudStream::Update()
{
    return stub<thiscall_t<void, AudStream*>>(0x4F3B00, this);
}

u32 const AudStream::Get2DFlags()
{
    return stub<cdecl_t<u32 const>>(0x4F4100);
}

u32 const AudStream::GetFreqChange2DFlags()
{
    return stub<cdecl_t<u32 const>>(0x4F4120);
}
