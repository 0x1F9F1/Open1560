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
    return stub<thiscall_t<i16, SoundObj*>>(0xF2500_Offset, this);
}

void SoundObj::ConvertTo8Bit()
{
    return stub<thiscall_t<void, SoundObj*>>(0xF15F0_Offset, this);
}

u16 SoundObj::CreateListenerEAXObj()
{
    return stub<thiscall_t<u16, SoundObj*>>(0xF3370_Offset, this);
}

u16 SoundObj::CreateSecondaryEAXObj()
{
    return stub<thiscall_t<u16, SoundObj*>>(0xF3410_Offset, this);
}

i32 SoundObj::DSCreateSoundBuffer(struct IDirectSoundBuffer** arg1, u8 arg2)
{
    return stub<thiscall_t<i32, SoundObj*, struct IDirectSoundBuffer**, u8>>(0xF0FA0_Offset, this, arg1, arg2);
}

i32 SoundObj::DSFillSoundBuffer(struct IDirectSoundBuffer* arg1)
{
    return stub<thiscall_t<i32, SoundObj*, struct IDirectSoundBuffer*>>(0xF21D0_Offset, this, arg1);
}

i32 SoundObj::DSGetWaveFile(
    struct HINSTANCE__* arg1, char const* arg2, struct tWAVEFORMATEX** arg3, u8** arg4, u32* arg5, void** arg6)
{
    return stub<
        thiscall_t<i32, SoundObj*, struct HINSTANCE__*, char const*, struct tWAVEFORMATEX**, u8**, u32*, void**>>(
        0xF1750_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

i32 SoundObj::DSGetWaveResource(
    struct HINSTANCE__* arg1, char const* arg2, struct tWAVEFORMATEX** arg3, u8** arg4, u32* arg5)
{
    return stub<thiscall_t<i32, SoundObj*, struct HINSTANCE__*, char const*, struct tWAVEFORMATEX**, u8**, u32*>>(
        0xF1510_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

struct IDirectSoundBuffer* SoundObj::DSLoadSoundBuffer(char const* arg1, u32 arg2)
{
    return stub<thiscall_t<struct IDirectSoundBuffer*, SoundObj*, char const*, u32>>(0xF1030_Offset, this, arg1, arg2);
}

void SoundObj::DSLoadSoundBuffer(u16 arg1, u32 arg2)
{
    return stub<thiscall_t<void, SoundObj*, u16, u32>>(0xF1210_Offset, this, arg1, arg2);
}

i32 SoundObj::DSParseWaveResource(void* arg1, struct tWAVEFORMATEX** arg2, u8** arg3, u32* arg4)
{
    return stub<thiscall_t<i32, SoundObj*, void*, struct tWAVEFORMATEX**, u8**, u32*>>(
        0xF2290_Offset, this, arg1, arg2, arg3, arg4);
}

void SoundObj::DeallocateEffects()
{
    return stub<thiscall_t<void, SoundObj*>>(0xF0CA0_Offset, this);
}

void SoundObj::Disable3DMode()
{
    return stub<thiscall_t<void, SoundObj*>>(0xF3580_Offset, this);
}

void SoundObj::DisableEffect(i16 arg1)
{
    return stub<thiscall_t<void, SoundObj*, i16>>(0xF3270_Offset, this, arg1);
}

void SoundObj::Enable3DMode()
{
    return stub<thiscall_t<void, SoundObj*>>(0xF3550_Offset, this);
}

void SoundObj::FreeOneShotLayerBuffers()
{
    return stub<thiscall_t<void, SoundObj*>>(0xF0F20_Offset, this);
}

struct tWAVEFORMATEX* SoundObj::GetFormat()
{
    return stub<thiscall_t<struct tWAVEFORMATEX*, SoundObj*>>(0xF34D0_Offset, this);
}

i32 SoundObj::Init(char const* arg1, u32 arg2, i16 arg3)
{
    return stub<thiscall_t<i32, SoundObj*, char const*, u32, i16>>(0xF1BD0_Offset, this, arg1, arg2, arg3);
}

i32 SoundObj::Init(u16 arg1, u32 arg2, i16 arg3)
{
    return stub<thiscall_t<i32, SoundObj*, u16, u32, i16>>(0xF1C90_Offset, this, arg1, arg2, arg3);
}

i32 SoundObj::InitDummy()
{
    return stub<thiscall_t<i32, SoundObj*>>(0xF1A20_Offset, this);
}

i16 SoundObj::IsPlaying(i16 arg1)
{
    return stub<thiscall_t<i16, SoundObj*, i16>>(0xF2390_Offset, this, arg1);
}

i32 SoundObj::Play(u32 arg1, char* arg2)
{
    return stub<thiscall_t<i32, SoundObj*, u32, char*>>(0xF1EE0_Offset, this, arg1, arg2);
}

void SoundObj::ReadADFRecord(u16 arg1)
{
    return stub<thiscall_t<void, SoundObj*, u16>>(0xF1350_Offset, this, arg1);
}

i16 SoundObj::ReadyOneShotLayerBuf()
{
    return stub<thiscall_t<i16, SoundObj*>>(0xF2470_Offset, this);
}

void SoundObj::Set3DMode(u32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, u32>>(0xF2C00_Offset, this, arg1);
}

void SoundObj::SetConeAngles(u32 arg1, u32 arg2)
{
    return stub<thiscall_t<void, SoundObj*, u32, u32>>(0xF2C50_Offset, this, arg1, arg2);
}

void SoundObj::SetConeOrientation(class Vector3* arg1)
{
    return stub<thiscall_t<void, SoundObj*, class Vector3*>>(0xF2C90_Offset, this, arg1);
}

void SoundObj::SetConeOutsideVolume(i32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, i32>>(0xF2C20_Offset, this, arg1);
}

void SoundObj::SetDelayTime(f32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, f32>>(0xF0D70_Offset, this, arg1);
}

void SoundObj::SetEchoFrequency(f32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, f32>>(0xF2860_Offset, this, arg1);
}

void SoundObj::SetEchoPan(f32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, f32>>(0xF2BA0_Offset, this, arg1);
}

void SoundObj::SetEffect(i16 arg1, char* arg2)
{
    return stub<thiscall_t<void, SoundObj*, i16, char*>>(0xF1D40_Offset, this, arg1, arg2);
}

void SoundObj::SetFrequency(f32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, f32>>(0xF2620_Offset, this, arg1);
}

void SoundObj::SetPan(f32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, f32>>(0xF2A60_Offset, this, arg1);
}

void SoundObj::SetPlayPosition(u32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, u32>>(0xF1EC0_Offset, this, arg1);
}

void SoundObj::SetPosition(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, SoundObj*, f32, f32, f32>>(0xF25A0_Offset, this, arg1, arg2, arg3);
}

void SoundObj::SetRamp(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, SoundObj*, f32, f32>>(0xF2BD0_Offset, this, arg1, arg2);
}

void SoundObj::SetVelocity(f32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, SoundObj*, f32, f32, f32>>(0xF25E0_Offset, this, arg1, arg2, arg3);
}

void SoundObj::SetVolume(f32 arg1)
{
    return stub<thiscall_t<void, SoundObj*, f32>>(0xF2920_Offset, this, arg1);
}

struct IDirectSoundBuffer* SoundObj::SetupDuplicateBuffer(char* arg1)
{
    return stub<thiscall_t<struct IDirectSoundBuffer*, SoundObj*, char*>>(0xF2CC0_Offset, this, arg1);
}

void SoundObj::SetupEchoBuffer(char* arg1)
{
    return stub<thiscall_t<void, SoundObj*, char*>>(0xF2D70_Offset, this, arg1);
}

i16 SoundObj::SetupOneShotLayerBuffers(i16 arg1, f32 arg2, char* arg3)
{
    return stub<thiscall_t<i16, SoundObj*, i16, f32, char*>>(0xF0E90_Offset, this, arg1, arg2, arg3);
}

i32 SoundObj::Stop()
{
    return stub<thiscall_t<i32, SoundObj*>>(0xF2120_Offset, this);
}

void SoundObj::StopEchoBuffers()
{
    return stub<thiscall_t<void, SoundObj*>>(0xF21B0_Offset, this);
}

void SoundObj::UpdateEcho()
{
    return stub<thiscall_t<void, SoundObj*>>(0xF2EC0_Offset, this);
}

void SoundObj::UpdatePitchEcho()
{
    return stub<thiscall_t<void, SoundObj*>>(0xF31B0_Offset, this);
}

void SoundObj::UpdatePlayEcho()
{
    return stub<thiscall_t<void, SoundObj*>>(0xF2F30_Offset, this);
}

void SoundObj::UpdateSeconds()
{
    return stub<thiscall_t<void, SoundObj*>>(0xF2E90_Offset, this);
}

void SoundObj::UpdateStopEcho()
{
    return stub<thiscall_t<void, SoundObj*>>(0xF3030_Offset, this);
}

void SoundObj::UpdateVolumeEcho()
{
    return stub<thiscall_t<void, SoundObj*>>(0xF30F0_Offset, this);
}

struct IDirectSoundBuffer* SoundObj::SetupChorusBuffer(char* arg1)
{
    return stub<thiscall_t<struct IDirectSoundBuffer*, SoundObj*, char*>>(0xF2E10_Offset, this, arg1);
}
