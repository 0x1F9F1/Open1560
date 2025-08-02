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

    // ?IsPlaying@AudStream@@QAEHXZ
    ARTS_IMPORT i32 IsPlaying();

    // ?Load@AudStream@@QAEHPADH@Z
    ARTS_IMPORT i32 Load(char* arg1, i32 arg2);

    // ?PlayOnce@AudStream@@QAEXPADMM@Z
    ARTS_IMPORT void PlayOnce(char* arg1, f32 arg2, f32 arg3);

    // ?ReallocateStreamObjs@AudStream@@QAEXXZ
    ARTS_IMPORT void ReallocateStreamObjs();

    // ?Reset@AudStream@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetFrequency@AudStream@@QAEXMH@Z
    ARTS_IMPORT void SetFrequency(f32 arg1, i32 arg2);

    // ?SetPan@AudStream@@QAEXMH@Z
    ARTS_IMPORT void SetPan(f32 arg1, i32 arg2);

    // ?SetPlayPosition@AudStream@@QAEXK@Z | unused
    ARTS_EXPORT void SetPlayPosition(ulong arg1);

    // ?SetPriority@AudStream@@QAEXH@Z
    ARTS_IMPORT void SetPriority(i32 arg1);

    // ?SetVolume@AudStream@@QAEXMH@Z
    ARTS_IMPORT void SetVolume(f32 arg1, i32 arg2);

    // ?Stop@AudStream@@QAEXXZ
    ARTS_IMPORT void Stop();

    // ?Update@AudStream@@UAEXXZ
    ARTS_IMPORT void Update() override;

    ARTS_DIAGNOSTIC_PUSH;
    ARTS_CLANG_DIAGNOSTIC_IGNORED("-Wignored-qualifiers");

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
