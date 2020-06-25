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
    mmui:pu_audio

    0x4AA790 | public: __thiscall PUAudioOptions::PUAudioOptions(int,float,float,float,float) | ??0PUAudioOptions@@QAE@HMMMM@Z
    0x4AA9D0 | public: virtual __thiscall PUAudioOptions::~PUAudioOptions(void) | ??1PUAudioOptions@@UAE@XZ
    0x4AA9E0 | public: void __thiscall PUAudioOptions::SetWaveVolume(void) | ?SetWaveVolume@PUAudioOptions@@QAEXXZ
    0x4AAA00 | public: void __thiscall PUAudioOptions::SetCDVolume(void) | ?SetCDVolume@PUAudioOptions@@QAEXXZ
    0x4AAA20 | public: void __thiscall PUAudioOptions::SetBalance(void) | ?SetBalance@PUAudioOptions@@QAEXXZ
    0x4AAA50 | public: virtual void __thiscall PUAudioOptions::PreSetup(void) | ?PreSetup@PUAudioOptions@@UAEXXZ
    0x4AAA60 | public: void __thiscall PUAudioOptions::CancelAction(void) | ?CancelAction@PUAudioOptions@@QAEXXZ
    0x4AAA70 | public: virtual void * __thiscall PUAudioOptions::`vector deleting destructor'(unsigned int) | ??_EPUAudioOptions@@UAEPAXI@Z
    0x4AAA70 | public: virtual void * __thiscall PUAudioOptions::`scalar deleting destructor'(unsigned int) | ??_GPUAudioOptions@@UAEPAXI@Z
    0x61E0A8 | const PUAudioOptions::`vftable' | ??_7PUAudioOptions@@6B@
    0x705958 | class mmPlayerConfig * PUOptionsConfig | ?PUOptionsConfig@@3PAVmmPlayerConfig@@A
*/

#include "pu_menu.h"

class PUAudioOptions : public PUMenuBase
{
    // const PUAudioOptions::`vftable' @ 0x61E0A8

public:
    // 0x4AA790 | ??0PUAudioOptions@@QAE@HMMMM@Z
    ARTS_IMPORT PUAudioOptions(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // 0x4AAA70 | ??_GPUAudioOptions@@UAEPAXI@Z
    // 0x4AA9D0 | ??1PUAudioOptions@@UAE@XZ
    ARTS_IMPORT ~PUAudioOptions() override;

    // 0x4AAA60 | ?CancelAction@PUAudioOptions@@QAEXXZ
    ARTS_IMPORT void CancelAction();

    // 0x4AAA50 | ?PreSetup@PUAudioOptions@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    // 0x4AAA20 | ?SetBalance@PUAudioOptions@@QAEXXZ
    ARTS_IMPORT void SetBalance();

    // 0x4AAA00 | ?SetCDVolume@PUAudioOptions@@QAEXXZ
    ARTS_IMPORT void SetCDVolume();

    // 0x4AA9E0 | ?SetWaveVolume@PUAudioOptions@@QAEXXZ
    ARTS_IMPORT void SetWaveVolume();
};

check_size(PUAudioOptions, 0xC0);

// 0x705958 | ?PUOptionsConfig@@3PAVmmPlayerConfig@@A
ARTS_IMPORT extern class mmPlayerConfig* PUOptionsConfig;
