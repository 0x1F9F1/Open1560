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
    mmaudio:streamobj

    0x4F4C10 | public: __thiscall StreamObj::StreamObj(void) | ??0StreamObj@@QAE@XZ
    0x4F4CA0 | public: __thiscall StreamObj::~StreamObj(void) | ??1StreamObj@@QAE@XZ
    0x4F4DC0 | public: int __thiscall StreamObj::DSCreateSoundBuffer(void) | ?DSCreateSoundBuffer@StreamObj@@QAEHXZ
    0x4F4E50 | public: struct IDirectSoundBuffer * __thiscall StreamObj::DSLoadSoundBuffer(char const *,unsigned long) | ?DSLoadSoundBuffer@StreamObj@@QAEPAUIDirectSoundBuffer@@PBDK@Z
    0x4F4EA0 | private: class Stream * __thiscall StreamObj::OpenWaveFile(char const *,short) | ?OpenWaveFile@StreamObj@@AAEPAVStream@@PBDF@Z
    0x4F50C0 | private: unsigned int __thiscall StreamObj::GetWaveBytesOffset(class Stream *,short) | ?GetWaveBytesOffset@StreamObj@@AAEIPAVStream@@F@Z
    0x4F5200 | public: int __thiscall StreamObj::Init(char const *,unsigned long) | ?Init@StreamObj@@QAEHPBDK@Z
    0x4F5270 | public: void __thiscall StreamObj::SetPlayPosition(unsigned long) | ?SetPlayPosition@StreamObj@@QAEXK@Z
    0x4F5290 | public: int __thiscall StreamObj::Play(void) | ?Play@StreamObj@@QAEHXZ
    0x4F5330 | public: void __thiscall StreamObj::SetPlayOneShotEvent(char *) | ?SetPlayOneShotEvent@StreamObj@@QAEXPAD@Z
    0x4F5390 | public: void __thiscall StreamObj::SetStopEvent(void) | ?SetStopEvent@StreamObj@@QAEXXZ
    0x4F53B0 | public: void __thiscall StreamObj::SetVolumeEvent(float) | ?SetVolumeEvent@StreamObj@@QAEXM@Z
    0x4F53E0 | public: void __thiscall StreamObj::SetFrequencyEvent(float) | ?SetFrequencyEvent@StreamObj@@QAEXM@Z
    0x4F5410 | public: void __thiscall StreamObj::SetPanEvent(float) | ?SetPanEvent@StreamObj@@QAEXM@Z
    0x4F5440 | public: int __thiscall StreamObj::Play(char *) | ?Play@StreamObj@@QAEHPAD@Z
    0x4F5510 | public: int __thiscall StreamObj::Stop(void) | ?Stop@StreamObj@@QAEHXZ
    0x4F5540 | public: int __thiscall StreamObj::FillDataBuffer(unsigned int) | ?FillDataBuffer@StreamObj@@QAEHI@Z
    0x4F5750 | public: short __thiscall StreamObj::IsPlaying(void) | ?IsPlaying@StreamObj@@QAEFXZ
    0x4F57B0 | public: void __thiscall StreamObj::SetFrequency(float) | ?SetFrequency@StreamObj@@QAEXM@Z
    0x4F5860 | public: void __thiscall StreamObj::SetVolume(float) | ?SetVolume@StreamObj@@QAEXM@Z
    0x4F58A0 | public: void __thiscall StreamObj::SetPan(float) | ?SetPan@StreamObj@@QAEXM@Z
    0x4F58E0 | public: int __thiscall StreamObj::SetupNotifications(void) | ?SetupNotifications@StreamObj@@QAEHXZ
    0x4F5B80 | unsigned long __cdecl HandleNotifications(void *) | ?HandleNotifications@@YAKPAX@Z
    0x4F5F80 | public: void __thiscall StreamObj::Update(void) | ?Update@StreamObj@@QAEXXZ
    0x4F6040 | public: class Stream * __thiscall StreamObj::GetFileStreamPtr(void) | ?GetFileStreamPtr@StreamObj@@QAEPAVStream@@XZ
    0x4F6050 | public: void __thiscall StreamObj::SetNumLoopIndices(short) | ?SetNumLoopIndices@StreamObj@@QAEXF@Z
    0x4F60B0 | public: void __thiscall StreamObj::SetLoopPointInfo(unsigned long,unsigned long,unsigned int,short,short) | ?SetLoopPointInfo@StreamObj@@QAEXKKIFF@Z
    0x4F61C0 | public: void __thiscall StreamObj::ReadInLoopIndex(short) | ?ReadInLoopIndex@StreamObj@@QAEXF@Z
    0x4F6290 | public: void __thiscall StreamObj::SetPlayingFlag(short) | ?SetPlayingFlag@StreamObj@@QAEXF@Z
*/

class StreamObj
{
public:
    // 0x4F4C10 | ??0StreamObj@@QAE@XZ
    StreamObj();

    // 0x4F4CA0 | ??1StreamObj@@QAE@XZ
    ~StreamObj();

    // 0x4F4DC0 | ?DSCreateSoundBuffer@StreamObj@@QAEHXZ
    i32 DSCreateSoundBuffer();

    // 0x4F4E50 | ?DSLoadSoundBuffer@StreamObj@@QAEPAUIDirectSoundBuffer@@PBDK@Z
    struct IDirectSoundBuffer* DSLoadSoundBuffer(char const* arg1, u32 arg2);

    // 0x4F5540 | ?FillDataBuffer@StreamObj@@QAEHI@Z
    i32 FillDataBuffer(u32 arg1);

    // 0x4F6040 | ?GetFileStreamPtr@StreamObj@@QAEPAVStream@@XZ
    class Stream* GetFileStreamPtr();

    // 0x4F5200 | ?Init@StreamObj@@QAEHPBDK@Z
    i32 Init(char const* arg1, u32 arg2);

    // 0x4F5750 | ?IsPlaying@StreamObj@@QAEFXZ
    i16 IsPlaying();

    // 0x4F5290 | ?Play@StreamObj@@QAEHXZ
    i32 Play();

    // 0x4F5440 | ?Play@StreamObj@@QAEHPAD@Z
    i32 Play(char* arg1);

    // 0x4F61C0 | ?ReadInLoopIndex@StreamObj@@QAEXF@Z
    void ReadInLoopIndex(i16 arg1);

    // 0x4F57B0 | ?SetFrequency@StreamObj@@QAEXM@Z
    void SetFrequency(f32 arg1);

    // 0x4F53E0 | ?SetFrequencyEvent@StreamObj@@QAEXM@Z
    void SetFrequencyEvent(f32 arg1);

    // 0x4F60B0 | ?SetLoopPointInfo@StreamObj@@QAEXKKIFF@Z
    void SetLoopPointInfo(u32 arg1, u32 arg2, u32 arg3, i16 arg4, i16 arg5);

    // 0x4F6050 | ?SetNumLoopIndices@StreamObj@@QAEXF@Z
    void SetNumLoopIndices(i16 arg1);

    // 0x4F58A0 | ?SetPan@StreamObj@@QAEXM@Z
    void SetPan(f32 arg1);

    // 0x4F5410 | ?SetPanEvent@StreamObj@@QAEXM@Z
    void SetPanEvent(f32 arg1);

    // 0x4F5330 | ?SetPlayOneShotEvent@StreamObj@@QAEXPAD@Z
    void SetPlayOneShotEvent(char* arg1);

    // 0x4F5270 | ?SetPlayPosition@StreamObj@@QAEXK@Z
    void SetPlayPosition(u32 arg1);

    // 0x4F6290 | ?SetPlayingFlag@StreamObj@@QAEXF@Z
    void SetPlayingFlag(i16 arg1);

    // 0x4F5390 | ?SetStopEvent@StreamObj@@QAEXXZ
    void SetStopEvent();

    // 0x4F5860 | ?SetVolume@StreamObj@@QAEXM@Z
    void SetVolume(f32 arg1);

    // 0x4F53B0 | ?SetVolumeEvent@StreamObj@@QAEXM@Z
    void SetVolumeEvent(f32 arg1);

    // 0x4F58E0 | ?SetupNotifications@StreamObj@@QAEHXZ
    i32 SetupNotifications();

    // 0x4F5510 | ?Stop@StreamObj@@QAEHXZ
    i32 Stop();

    // 0x4F5F80 | ?Update@StreamObj@@QAEXXZ
    void Update();

private:
    // 0x4F50C0 | ?GetWaveBytesOffset@StreamObj@@AAEIPAVStream@@F@Z
    u32 GetWaveBytesOffset(class Stream* arg1, i16 arg2);

    // 0x4F4EA0 | ?OpenWaveFile@StreamObj@@AAEPAVStream@@PBDF@Z
    class Stream* OpenWaveFile(char const* arg1, i16 arg2);
};

check_size(StreamObj, 0x138);

// 0x4F5B80 | ?HandleNotifications@@YAKPAX@Z
u32 HandleNotifications(void* arg1);
