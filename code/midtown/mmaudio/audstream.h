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

#pragma once

/*
    mmaudio:audstream

    0x4F35A0 | public: __thiscall AudStream::AudStream(unsigned long,int,short) | ??0AudStream@@QAE@KHF@Z
    0x4F36E0 | public: virtual __thiscall AudStream::~AudStream(void) | ??1AudStream@@UAE@XZ
    0x4F37E0 | public: void __thiscall AudStream::SetPriority(int) | ?SetPriority@AudStream@@QAEXH@Z
    0x4F3800 | public: void __thiscall AudStream::DeallocateStreamObjs(void) | ?DeallocateStreamObjs@AudStream@@QAEXXZ
    0x4F3890 | public: void __thiscall AudStream::ReallocateStreamObjs(void) | ?ReallocateStreamObjs@AudStream@@QAEXXZ
    0x4F3910 | public: int __thiscall AudStream::Load(char *,int) | ?Load@AudStream@@QAEHPADH@Z
    0x4F3AB0 | public: void __thiscall AudStream::Enable(void) | ?Enable@AudStream@@QAEXXZ
    0x4F3AC0 | public: void __thiscall AudStream::Disable(void) | ?Disable@AudStream@@QAEXXZ
    0x4F3AE0 | public: virtual void __thiscall AudStream::Reset(void) | ?Reset@AudStream@@UAEXXZ
    0x4F3B00 | public: virtual void __thiscall AudStream::Update(void) | ?Update@AudStream@@UAEXXZ
    0x4F3B50 | public: void __thiscall AudStream::SetPlayPosition(unsigned long) | ?SetPlayPosition@AudStream@@QAEXK@Z
    0x4F3B60 | public: void __thiscall AudStream::PlayOnce(float,float) | ?PlayOnce@AudStream@@QAEXMM@Z
    0x4F3C10 | public: void __thiscall AudStream::PlayOnce(char *,float,float) | ?PlayOnce@AudStream@@QAEXPADMM@Z
    0x4F3D20 | public: void __thiscall AudStream::PlayLoop(char *,float,float) | ?PlayLoop@AudStream@@QAEXPADMM@Z
    0x4F3E40 | public: void __thiscall AudStream::PlayLoop(float,float) | ?PlayLoop@AudStream@@QAEXMM@Z
    0x4F3EF0 | public: void __thiscall AudStream::Stop(void) | ?Stop@AudStream@@QAEXXZ
    0x4F3F10 | public: void __thiscall AudStream::StopNow(void) | ?StopNow@AudStream@@QAEXXZ
    0x4F3F30 | public: void __thiscall AudStream::SetFrequency(float,int) | ?SetFrequency@AudStream@@QAEXMH@Z
    0x4F3FA0 | public: float __thiscall AudStream::GetFrequency(int) | ?GetFrequency@AudStream@@QAEMH@Z
    0x4F3FE0 | public: void __thiscall AudStream::SetVolume(float,int) | ?SetVolume@AudStream@@QAEXMH@Z
    0x4F4050 | public: void __thiscall AudStream::SetPan(float,int) | ?SetPan@AudStream@@QAEXMH@Z
    0x4F40E0 | public: int __thiscall AudStream::IsPlaying(void) | ?IsPlaying@AudStream@@QAEHXZ
    0x4F4100 | public: static unsigned long const __cdecl AudStream::Get2DFlags(void) | ?Get2DFlags@AudStream@@SA?BKXZ
    0x4F4120 | public: static unsigned long const __cdecl AudStream::GetFreqChange2DFlags(void) | ?GetFreqChange2DFlags@AudStream@@SA?BKXZ
    0x4F4140 | public: class StreamObj * __thiscall AudStream::GetCurrentSoundObj(void) | ?GetCurrentSoundObj@AudStream@@QAEPAVStreamObj@@XZ
    0x4F4150 | public: void __thiscall AudStream::SetNumLoopIndices(short) | ?SetNumLoopIndices@AudStream@@QAEXF@Z
    0x4F4180 | public: void __thiscall AudStream::SetLoopIndex(short) | ?SetLoopIndex@AudStream@@QAEXF@Z
    0x4F41B0 | public: void __thiscall AudStream::SetLoopPointInfo(unsigned long,unsigned long,unsigned int,short,short) | ?SetLoopPointInfo@AudStream@@QAEXKKIFF@Z
    0x4F41F0 | public: void __thiscall AudStream::SetupNotifications(void) | ?SetupNotifications@AudStream@@QAEXXZ
    0x4F4210 | public: virtual void * __thiscall AudStream::`scalar deleting destructor'(unsigned int) | ??_GAudStream@@UAEPAXI@Z
    0x4F4210 | public: virtual void * __thiscall AudStream::`vector deleting destructor'(unsigned int) | ??_EAudStream@@UAEPAXI@Z
    0x61FF24 | private: static unsigned long const AudStream::s_DWDefault2DCtrlFlags | ?s_DWDefault2DCtrlFlags@AudStream@@0KB
    0x61FF28 | private: static unsigned long const AudStream::s_DWFreqChange2DCtrlFlags | ?s_DWFreqChange2DCtrlFlags@AudStream@@0KB
    0x61FF40 | const AudStream::`vftable' | ??_7AudStream@@6B@
*/

#include "arts7/node.h"

class StreamObj;

class AudStream final : public asNode
{
public:
    // ??0AudStream@@QAE@KHF@Z
    ARTS_IMPORT AudStream(ulong arg1, i32 arg2, i16 arg3);

    // ??_EAudStream@@UAEPAXI@Z
    // ??_GAudStream@@UAEPAXI@Z
    // ??1AudStream@@UAE@XZ
    ARTS_IMPORT ~AudStream() override;

    // ?DeallocateStreamObjs@AudStream@@QAEXXZ
    ARTS_IMPORT void DeallocateStreamObjs();

    // ?Disable@AudStream@@QAEXXZ | unused
    ARTS_IMPORT void Disable();

    // ?Enable@AudStream@@QAEXXZ | unused
    ARTS_IMPORT void Enable();

    // ?GetCurrentSoundObj@AudStream@@QAEPAVStreamObj@@XZ | unused
    ARTS_IMPORT StreamObj* GetCurrentSoundObj();

    // ?GetFrequency@AudStream@@QAEMH@Z | unused
    ARTS_IMPORT f32 GetFrequency(i32 arg1);

    // ?IsPlaying@AudStream@@QAEHXZ
    ARTS_IMPORT i32 IsPlaying();

    // ?Load@AudStream@@QAEHPADH@Z
    ARTS_IMPORT i32 Load(char* arg1, i32 arg2);

    // ?PlayLoop@AudStream@@QAEXMM@Z | unused
    ARTS_IMPORT void PlayLoop(f32 arg1, f32 arg2);

    // ?PlayLoop@AudStream@@QAEXPADMM@Z | unused
    ARTS_IMPORT void PlayLoop(char* arg1, f32 arg2, f32 arg3);

    // ?PlayOnce@AudStream@@QAEXMM@Z | unused
    ARTS_IMPORT void PlayOnce(f32 arg1, f32 arg2);

    // ?PlayOnce@AudStream@@QAEXPADMM@Z
    ARTS_IMPORT void PlayOnce(char* arg1, f32 arg2, f32 arg3);

    // ?ReallocateStreamObjs@AudStream@@QAEXXZ
    ARTS_IMPORT void ReallocateStreamObjs();

    // ?Reset@AudStream@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetFrequency@AudStream@@QAEXMH@Z
    ARTS_IMPORT void SetFrequency(f32 arg1, i32 arg2);

    // ?SetLoopIndex@AudStream@@QAEXF@Z | unused
    ARTS_IMPORT void SetLoopIndex(i16 arg1);

    // ?SetLoopPointInfo@AudStream@@QAEXKKIFF@Z | unused
    ARTS_IMPORT void SetLoopPointInfo(ulong arg1, ulong arg2, u32 arg3, i16 arg4, i16 arg5);

    // ?SetNumLoopIndices@AudStream@@QAEXF@Z | unused
    ARTS_IMPORT void SetNumLoopIndices(i16 arg1);

    // ?SetPan@AudStream@@QAEXMH@Z
    ARTS_IMPORT void SetPan(f32 arg1, i32 arg2);

    // ?SetPlayPosition@AudStream@@QAEXK@Z | unused
    ARTS_EXPORT void SetPlayPosition(ulong arg1);

    // ?SetPriority@AudStream@@QAEXH@Z
    ARTS_IMPORT void SetPriority(i32 arg1);

    // ?SetVolume@AudStream@@QAEXMH@Z
    ARTS_IMPORT void SetVolume(f32 arg1, i32 arg2);

    // ?SetupNotifications@AudStream@@QAEXXZ | unused
    ARTS_IMPORT void SetupNotifications();

    // ?Stop@AudStream@@QAEXXZ
    ARTS_IMPORT void Stop();

    // ?StopNow@AudStream@@QAEXXZ | unused
    ARTS_IMPORT void StopNow();

    // ?Update@AudStream@@UAEXXZ
    ARTS_IMPORT void Update() override;

    ARTS_DIAGNOSTIC_PUSH;
    ARTS_CLANG_DIAGNOSTIC_IGNORED("-Wignored-qualifiers");

    // ?Get2DFlags@AudStream@@SA?BKXZ | unused
    ARTS_IMPORT static const ulong Get2DFlags();

    // ?GetFreqChange2DFlags@AudStream@@SA?BKXZ
    ARTS_IMPORT static const ulong GetFreqChange2DFlags();

private:
    // ?s_DWDefault2DCtrlFlags@AudStream@@0KB
    ARTS_IMPORT static const ulong s_DWDefault2DCtrlFlags;

    // ?s_DWFreqChange2DCtrlFlags@AudStream@@0KB
    ARTS_IMPORT static const ulong s_DWFreqChange2DCtrlFlags;

    ARTS_DIAGNOSTIC_POP;

    u8 gap20[0x34];
};

check_size(AudStream, 0x54);
