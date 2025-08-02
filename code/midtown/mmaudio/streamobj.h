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

struct IDirectSoundBuffer;

class StreamObj
{
public:
    // ??0StreamObj@@QAE@XZ
    ARTS_IMPORT StreamObj();

    // ??1StreamObj@@QAE@XZ
    ARTS_IMPORT ~StreamObj();

    // ?DSCreateSoundBuffer@StreamObj@@QAEHXZ
    ARTS_IMPORT i32 DSCreateSoundBuffer();

    // ?DSLoadSoundBuffer@StreamObj@@QAEPAUIDirectSoundBuffer@@PBDK@Z
    ARTS_IMPORT IDirectSoundBuffer* DSLoadSoundBuffer(const char* arg1, ulong arg2);

    // ?FillDataBuffer@StreamObj@@QAEHI@Z
    ARTS_IMPORT i32 FillDataBuffer(u32 arg1);

    // ?GetFileStreamPtr@StreamObj@@QAEPAVStream@@XZ
    ARTS_IMPORT Stream* GetFileStreamPtr();

    // ?Init@StreamObj@@QAEHPBDK@Z
    ARTS_IMPORT i32 Init(const char* arg1, ulong arg2);

    // ?IsPlaying@StreamObj@@QAEFXZ
    ARTS_IMPORT i16 IsPlaying();

    // ?Play@StreamObj@@QAEHXZ
    ARTS_IMPORT i32 Play();

    // ?Play@StreamObj@@QAEHPAD@Z
    ARTS_IMPORT i32 Play(char* arg1);

    // ?SetFrequency@StreamObj@@QAEXM@Z
    ARTS_IMPORT void SetFrequency(f32 arg1);

    // ?SetFrequencyEvent@StreamObj@@QAEXM@Z
    ARTS_IMPORT void SetFrequencyEvent(f32 arg1);

    // ?SetLoopPointInfo@StreamObj@@QAEXKKIFF@Z
    ARTS_IMPORT void SetLoopPointInfo(ulong arg1, ulong arg2, u32 arg3, i16 arg4, i16 arg5);

    // ?SetNumLoopIndices@StreamObj@@QAEXF@Z
    ARTS_IMPORT void SetNumLoopIndices(i16 arg1);

    // ?SetPan@StreamObj@@QAEXM@Z
    ARTS_IMPORT void SetPan(f32 arg1);

    // ?SetPanEvent@StreamObj@@QAEXM@Z
    ARTS_IMPORT void SetPanEvent(f32 arg1);

    // ?SetPlayOneShotEvent@StreamObj@@QAEXPAD@Z
    ARTS_IMPORT void SetPlayOneShotEvent(char* arg1);

    // ?SetPlayingFlag@StreamObj@@QAEXF@Z
    ARTS_IMPORT void SetPlayingFlag(i16 arg1);

    // ?SetStopEvent@StreamObj@@QAEXXZ
    ARTS_IMPORT void SetStopEvent();

    // ?SetVolume@StreamObj@@QAEXM@Z
    ARTS_IMPORT void SetVolume(f32 arg1);

    // ?SetVolumeEvent@StreamObj@@QAEXM@Z
    ARTS_IMPORT void SetVolumeEvent(f32 arg1);

    // ?SetupNotifications@StreamObj@@QAEHXZ
    ARTS_IMPORT i32 SetupNotifications();

    // ?Stop@StreamObj@@QAEHXZ
    ARTS_IMPORT i32 Stop();

    // ?Update@StreamObj@@QAEXXZ
    ARTS_IMPORT void Update();

private:
    // ?GetWaveBytesOffset@StreamObj@@AAEIPAVStream@@F@Z
    ARTS_IMPORT u32 GetWaveBytesOffset(Stream* arg1, i16 arg2);

    // ?OpenWaveFile@StreamObj@@AAEPAVStream@@PBDF@Z
    ARTS_IMPORT Stream* OpenWaveFile(const char* arg1, i16 arg2);

    u8 gap0[0x138];
};

check_size(StreamObj, 0x138);

// ?HandleNotifications@@YAKPAX@Z
ARTS_IMPORT ulong HandleNotifications(void* arg1);
