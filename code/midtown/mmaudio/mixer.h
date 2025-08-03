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

#include "data7/base.h"
#include "eventq7/dispatchable.h"

struct VolumeDW
{
public:
    // ??1VolumeDW@@QAE@XZ | inline
    ARTS_EXPORT ~VolumeDW();

    u8 gap0[0xC];
};

check_size(VolumeDW, 0xC);

inline VolumeDW::~VolumeDW() = default;

class MixerCTL final
    : public Dispatchable
    , public Base
{
public:
    MixerCTL(HWND window);

    // ??1MixerCTL@@UAE@XZ
    ARTS_EXPORT ~MixerCTL() override;

    // ?AssignCDBalance@MixerCTL@@QAEXM@Z
    ARTS_IMPORT void AssignCDBalance(f32 arg1);

    // ?AssignCDVolume@MixerCTL@@QAEXM@Z
    ARTS_IMPORT void AssignCDVolume(f32 arg1);

    // ?AssignMixerBalance@MixerCTL@@QAEKMK@Z
    ARTS_IMPORT u32 AssignMixerBalance(f32 arg1, ulong arg2);

    // ?AssignMixerVolume@MixerCTL@@QAEKMK@Z
    ARTS_IMPORT u32 AssignMixerVolume(f32 arg1, ulong arg2);

    // ?AssignWaveBalance@MixerCTL@@QAEXM@Z
    ARTS_IMPORT void AssignWaveBalance(f32 arg1);

    // ?AssignWaveVolume@MixerCTL@@QAEXM@Z
    ARTS_IMPORT void AssignWaveVolume(f32 arg1);

    // ?GetCDBalance@MixerCTL@@QAEMXZ
    ARTS_IMPORT f32 GetCDBalance();

    // ?GetCDVolume@MixerCTL@@QAEMXZ
    ARTS_IMPORT f32 GetCDVolume();

    // ?GetMixerBalance@MixerCTL@@QAEMK@Z
    ARTS_IMPORT f32 GetMixerBalance(ulong arg1);

    // ?GetWaveBalance@MixerCTL@@QAEMXZ
    ARTS_IMPORT f32 GetWaveBalance();

    // ?GetWaveVolume@MixerCTL@@QAEMXZ
    ARTS_IMPORT f32 GetWaveVolume();

    // ?Init@MixerCTL@@QAEKXZ
    ARTS_IMPORT ulong Init();

    // ?RefreshAll@MixerCTL@@QAEXK@Z | unused
    void RefreshAll(ulong arg1);

    // ?SetDeviceNum@MixerCTL@@QAEXI@Z
    ARTS_EXPORT void SetDeviceNum(u32 device_id);

private:
    // ?GetErrorMessage@MixerCTL@@AAEPADK@Z
    const char* GetErrorMessage(ulong error);

    // ?WindowProc@MixerCTL@@EAEJPAUHWND__@@IIJ@Z
    ARTS_EXPORT LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;

    f32 field_8 {1.0f};
    f32 field_C {1.0f};
    f32 field_10 {1.0f};
    f32 field_14 {1.0f};
    f32 field_18 {1.0f};
    f32 field_1C {1.0f};

    void* window_ {};
    i32 field_24 {};
    i32 field_28 {1};
    u32 device_id_ {};

    f32 wave_balance_ {};
    f32 cd_balance_ {};
};

check_size(MixerCTL, 0x38);
