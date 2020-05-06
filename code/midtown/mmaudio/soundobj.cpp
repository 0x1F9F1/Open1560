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

define_dummy_symbol(mmaudio_soundobj);

#include "soundobj.h"

SoundObj::SoundObj()
{
    unimplemented();
}

SoundObj::~SoundObj()
{
    unimplemented();
}

i16 SoundObj::AllOneShotLayersPlaying()
{
    return stub<thiscall_t<i16, SoundObj*>>(0x4F2500, this);
}

void SoundObj::ConvertTo8Bit()
{
    return stub<thiscall_t<void, SoundObj*>>(0x4F15F0, this);
}

u16 SoundObj::CreateListenerEAXObj()
{
    return stub<thiscall_t<u16, SoundObj*>>(0x4F3370, this);
}

u16 SoundObj::CreateSecondaryEAXObj()
{
    return stub<thiscall_t<u16, SoundObj*>>(0x4F3410, this);
}

i32 SoundObj::DSCreateSoundBuffer(struct IDirectSoundBuffer** arg1, u8 arg2)
{
    return stub<thiscall_t<i32, SoundObj*, struct IDirectSoundBuffer**, u8>>(0x4F0FA0, this, arg1, arg2);
}

i32 SoundObj::DSFillSoundBuffer(struct IDirectSoundBuffer* arg1)
{
    return stub<thiscall_t<i32, SoundObj*, struct IDirectSoundBuffer*>>(0x4F21D0, this, arg1);
}

i32 SoundObj::DSGetWaveFile(
    struct HINSTANCE__* arg1, char const* arg2, struct tWAVEFORMATEX** arg3, u8** arg4, u32* arg5, void** arg6)
{
    return stub<
        thiscall_t<i32, SoundObj*, struct HINSTANCE__*, char const*, struct tWAVEFORMATEX**, u8**, u32*, void**>>(
        0x4F1750, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

i32 SoundObj::DSGetWaveResource(
    struct HINSTANCE__* arg1, char const* arg2, struct tWAVEFORMATEX** arg3, u8** arg4, u32* arg5)
{
    return stub<thiscall_t<i32, SoundObj*, struct HINSTANCE__*, char const*, struct tWAVEFORMATEX**, u8**, u32*>>(
        0x4F1510, this, arg1, arg2, arg3, arg4, arg5);
}

struct IDirectSoundBuffer* SoundObj::DSLoadSoundBuffer(char const* arg1, u32 arg2)
{
    return stub<thiscall_t<struct IDirectSoundBuffer*, SoundObj*, char const*, u32>>(0x4F1030, this, arg1, arg2);
}

void SoundObj::DSLoadSoundBuffer(u16 arg1, u32 arg2)
{
    return stub<thiscall_t<void, SoundObj*, u16, u32>>(0x4F1210, this, arg1, arg2);
}

i32 SoundObj::DSParseWaveResource(void* arg1, struct tWAVEFORMATEX** arg2, u8** arg3, u32* arg4)
{
    return stub<thiscall_t<i32, SoundObj*, void*, struct tWAVEFORMATEX**, u8**, u32*>>(
        0x4F2290, this, arg1, arg2, arg3, arg4);
}

void SoundObj::DeallocateEffects()
{
    return stub<thiscall_t<void, SoundObj*>>(0x4F0CA0, this);
}

void SoundObj::Disable3DMode()
{
    return stub<thiscall_t<void, SoundObj*>>(0x4F3580, this);
}

void SoundObj::DisableEffect(i16 arg1)
{
    return stub<thiscall_t<void, SoundObj*, i16>>(0x4F3270, this, arg1);
}

void SoundObj::Enable3DMode()
{
    return stub<thiscall_t<void, SoundObj*>>(0x4F3550, this);
}

void SoundObj::FreeOneShotLayerBuffers()
{
    return stub<thiscall_t<void, SoundObj*>>(0x4F0F20, this);
}

struct tWAVEFORMATEX* SoundObj::GetFormat()
{
    return stub<thiscall_t<struct tWAVEFORMATEX*, SoundObj*>>(0x4F34D0, this);
}

i32 SoundObj::Init(char const* arg1, u32 arg2, i16 arg3)
{
    return stub<thiscall_t<i32, SoundObj*, char const*, u32, i16>>(0x4F1BD0, this, arg1, arg2, arg3);
}

i32 SoundObj::Init(u16 arg1, u32 arg2, i16 arg3)
{
    return stub<thiscall_t<i32, SoundObj*, u16, u32, i16>>(0x4F1C90, this, arg1, arg2, arg3);
}

i32 SoundObj::InitDummy()
{
    return stub<thiscall_t<i32, SoundObj*>>(0x4F1A20, this);
}

i16 SoundObj::IsPlaying(i16 arg1)
{
    return stub<thiscall_t<i16, SoundObj*, i16>>(0x4F2390, this, arg1);
}

i32 SoundObj::Play(u32 arg1, char* arg2)
{
    return stub<thiscall_t<i32, SoundObj*, u32, char*>>(0x4F1EE0, this, arg1, arg2);
}

void SoundObj::ReadADFRecord(u16 arg1)
{
    return stub<thiscall_t<void, SoundObj*, u16>>(0x4F1350, this, arg1);
}

i16 SoundObj::ReadyOneShotLayerBuf()
{
    return stub<thiscall_t<i16, SoundObj*>>(0x4F2470, this);
}

void SoundObj::Set3DMode(u32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, u32>>(0x4F2C00, this, arg1);
}

void SoundObj::SetConeAngles(u32 arg1, u32 arg2)
{
    return stub<thiscall_t<void, SoundObj*, u32, u32>>(0x4F2C50, this, arg1, arg2);
}

void SoundObj::SetConeOrientation(class Vector3* arg1)
{
    return stub<thiscall_t<void, SoundObj*, class Vector3*>>(0x4F2C90, this, arg1);
}

void SoundObj::SetConeOutsideVolume(i32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, i32>>(0x4F2C20, this, arg1);
}

void SoundObj::SetDelayTime(f32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, f32>>(0x4F0D70, this, arg1);
}

void SoundObj::SetEchoFrequency(f32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, f32>>(0x4F2860, this, arg1);
}

void SoundObj::SetEchoPan(f32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, f32>>(0x4F2BA0, this, arg1);
}

void SoundObj::SetEffect(i16 arg1, char* arg2)
{
    return stub<thiscall_t<void, SoundObj*, i16, char*>>(0x4F1D40, this, arg1, arg2);
}

void SoundObj::SetFrequency(f32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, f32>>(0x4F2620, this, arg1);
}

void SoundObj::SetPan(f32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, f32>>(0x4F2A60, this, arg1);
}

void SoundObj::SetPlayPosition(u32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, u32>>(0x4F1EC0, this, arg1);
}

void SoundObj::SetPosition(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, SoundObj*, f32, f32, f32>>(0x4F25A0, this, arg1, arg2, arg3);
}

void SoundObj::SetRamp(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, SoundObj*, f32, f32>>(0x4F2BD0, this, arg1, arg2);
}

void SoundObj::SetVelocity(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, SoundObj*, f32, f32, f32>>(0x4F25E0, this, arg1, arg2, arg3);
}

void SoundObj::SetVolume(f32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, f32>>(0x4F2920, this, arg1);
}

struct IDirectSoundBuffer* SoundObj::SetupDuplicateBuffer(char* arg1)
{
    return stub<thiscall_t<struct IDirectSoundBuffer*, SoundObj*, char*>>(0x4F2CC0, this, arg1);
}

void SoundObj::SetupEchoBuffer(char* arg1)
{
    return stub<thiscall_t<void, SoundObj*, char*>>(0x4F2D70, this, arg1);
}

i16 SoundObj::SetupOneShotLayerBuffers(i16 arg1, f32 arg2, char* arg3)
{
    return stub<thiscall_t<i16, SoundObj*, i16, f32, char*>>(0x4F0E90, this, arg1, arg2, arg3);
}

i32 SoundObj::Stop()
{
    return stub<thiscall_t<i32, SoundObj*>>(0x4F2120, this);
}

void SoundObj::StopEchoBuffers()
{
    return stub<thiscall_t<void, SoundObj*>>(0x4F21B0, this);
}

void SoundObj::UpdateEcho()
{
    return stub<thiscall_t<void, SoundObj*>>(0x4F2EC0, this);
}

void SoundObj::UpdatePitchEcho()
{
    return stub<thiscall_t<void, SoundObj*>>(0x4F31B0, this);
}

void SoundObj::UpdatePlayEcho()
{
    return stub<thiscall_t<void, SoundObj*>>(0x4F2F30, this);
}

void SoundObj::UpdateSeconds()
{
    return stub<thiscall_t<void, SoundObj*>>(0x4F2E90, this);
}

void SoundObj::UpdateStopEcho()
{
    return stub<thiscall_t<void, SoundObj*>>(0x4F3030, this);
}

void SoundObj::UpdateVolumeEcho()
{
    return stub<thiscall_t<void, SoundObj*>>(0x4F30F0, this);
}

struct IDirectSoundBuffer* SoundObj::SetupChorusBuffer(char* arg1)
{
    return stub<thiscall_t<struct IDirectSoundBuffer*, SoundObj*, char*>>(0x4F2E10, this, arg1);
}
