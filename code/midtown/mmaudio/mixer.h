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
    mmaudio:mixer

    0x4EE040 | public: void __thiscall VolumeDW::Set(float,float) | ?Set@VolumeDW@@QAEXMM@Z
    0x4EE110 | public: unsigned long __thiscall VolumeDW::Value(void) | ?Value@VolumeDW@@QAEKXZ
    0x4EE140 | public: unsigned long __thiscall MixerCTL::Init(void) | ?Init@MixerCTL@@QAEKXZ
    0x4EE180 | public: virtual __thiscall MixerCTL::~MixerCTL(void) | ??1MixerCTL@@UAE@XZ
    0x4EE1F0 | public: void __thiscall MixerCTL::AssignWaveBalance(float) | ?AssignWaveBalance@MixerCTL@@QAEXM@Z
    0x4EE240 | public: void __thiscall MixerCTL::AssignCDBalance(float) | ?AssignCDBalance@MixerCTL@@QAEXM@Z
    0x4EE290 | public: void __thiscall MixerCTL::RefreshAll(unsigned long) | ?RefreshAll@MixerCTL@@QAEXK@Z
    0x4EE2A0 | public: float __thiscall MixerCTL::GetWaveBalance(void) | ?GetWaveBalance@MixerCTL@@QAEMXZ
    0x4EE2B0 | public: float __thiscall MixerCTL::GetWaveVolume(void) | ?GetWaveVolume@MixerCTL@@QAEMXZ
    0x4EE2C0 | public: void __thiscall MixerCTL::AssignWaveVolume(float) | ?AssignWaveVolume@MixerCTL@@QAEXM@Z
    0x4EE2E0 | public: void __thiscall MixerCTL::AssignCDVolume(float) | ?AssignCDVolume@MixerCTL@@QAEXM@Z
    0x4EE300 | public: float __thiscall MixerCTL::GetCDBalance(void) | ?GetCDBalance@MixerCTL@@QAEMXZ
    0x4EE310 | public: float __thiscall MixerCTL::GetCDVolume(void) | ?GetCDVolume@MixerCTL@@QAEMXZ
    0x4EE320 | public: unsigned long __thiscall MixerCTL::AssignMixerVolume(float,unsigned long) | ?AssignMixerVolume@MixerCTL@@QAEKMK@Z
    0x4EE580 | public: unsigned long __thiscall MixerCTL::AssignMixerBalance(float,unsigned long) | ?AssignMixerBalance@MixerCTL@@QAEKMK@Z
    0x4EE830 | public: float __thiscall MixerCTL::GetMixerBalance(unsigned long) | ?GetMixerBalance@MixerCTL@@QAEMK@Z
    0x4EEAB0 | public: void __thiscall MixerCTL::SetDeviceNum(unsigned int) | ?SetDeviceNum@MixerCTL@@QAEXI@Z
    0x4EEAD0 | private: char * __thiscall MixerCTL::GetErrorMessage(unsigned long) | ?GetErrorMessage@MixerCTL@@AAEPADK@Z
    0x4EEB70 | private: virtual long __thiscall MixerCTL::WindowProc(struct HWND__ *,unsigned int,unsigned int,long) | ?WindowProc@MixerCTL@@EAEJPAUHWND__@@IIJ@Z
    0x4EEB80 | public: __thiscall VolumeDW::~VolumeDW(void) | ??1VolumeDW@@QAE@XZ
    0x4EEB90 | public: virtual void * __thiscall MixerCTL::`vector deleting destructor'(unsigned int) | ??_EMixerCTL@@UAEPAXI@Z
    0x4EEB90 | public: virtual void * __thiscall MixerCTL::`scalar deleting destructor'(unsigned int) | ??_GMixerCTL@@UAEPAXI@Z
    0x61FEB8 | const MixerCTL::`vftable'{for `Base'} | ??_7MixerCTL@@6BBase@@@
    0x61FECC | const MixerCTL::`vftable'{for `Dispatchable'} | ??_7MixerCTL@@6BDispatchable@@@
*/

#include "data7/base.h"
#include "eventq7/dispatchable.h"

struct VolumeDW
{
public:
    // 0x4EEB80 | ??1VolumeDW@@QAE@XZ | inline
    ARTS_IMPORT ~VolumeDW();

    // 0x4EE040 | ?Set@VolumeDW@@QAEXMM@Z | unused
    ARTS_IMPORT void Set(f32 arg1, f32 arg2);

    // 0x4EE110 | ?Value@VolumeDW@@QAEKXZ | unused
    ARTS_IMPORT u32 Value();
};

check_size(VolumeDW, 0xC);

class MixerCTL
    : public Dispatchable
    , public Base /* Warning: Unordered Multiple Inheritance */
{
    // const MixerCTL::`vftable'{for `Base'} @ 0x61FEB8
    // const MixerCTL::`vftable'{for `Dispatchable'} @ 0x61FECC

public:
    // 0x4EEB90 | ??_GMixerCTL@@UAEPAXI@Z
    // 0x4EE180 | ??1MixerCTL@@UAE@XZ
    ARTS_IMPORT ~MixerCTL() override;

    // 0x4EE240 | ?AssignCDBalance@MixerCTL@@QAEXM@Z
    ARTS_IMPORT void AssignCDBalance(f32 arg1);

    // 0x4EE2E0 | ?AssignCDVolume@MixerCTL@@QAEXM@Z
    ARTS_IMPORT void AssignCDVolume(f32 arg1);

    // 0x4EE580 | ?AssignMixerBalance@MixerCTL@@QAEKMK@Z
    ARTS_IMPORT u32 AssignMixerBalance(f32 arg1, u32 arg2);

    // 0x4EE320 | ?AssignMixerVolume@MixerCTL@@QAEKMK@Z
    ARTS_IMPORT u32 AssignMixerVolume(f32 arg1, u32 arg2);

    // 0x4EE1F0 | ?AssignWaveBalance@MixerCTL@@QAEXM@Z
    ARTS_IMPORT void AssignWaveBalance(f32 arg1);

    // 0x4EE2C0 | ?AssignWaveVolume@MixerCTL@@QAEXM@Z
    ARTS_IMPORT void AssignWaveVolume(f32 arg1);

    // 0x4EE300 | ?GetCDBalance@MixerCTL@@QAEMXZ
    ARTS_IMPORT f32 GetCDBalance();

    // 0x4EE310 | ?GetCDVolume@MixerCTL@@QAEMXZ
    ARTS_IMPORT f32 GetCDVolume();

    // 0x4EE830 | ?GetMixerBalance@MixerCTL@@QAEMK@Z
    ARTS_IMPORT f32 GetMixerBalance(u32 arg1);

    // 0x4EE2A0 | ?GetWaveBalance@MixerCTL@@QAEMXZ
    ARTS_IMPORT f32 GetWaveBalance();

    // 0x4EE2B0 | ?GetWaveVolume@MixerCTL@@QAEMXZ
    ARTS_IMPORT f32 GetWaveVolume();

    // 0x4EE140 | ?Init@MixerCTL@@QAEKXZ
    ARTS_IMPORT u32 Init();

    // 0x4EE290 | ?RefreshAll@MixerCTL@@QAEXK@Z | unused
    ARTS_IMPORT void RefreshAll(u32 arg1);

    // 0x4EEAB0 | ?SetDeviceNum@MixerCTL@@QAEXI@Z
    ARTS_IMPORT void SetDeviceNum(u32 arg1);

private:
    // 0x4EEAD0 | ?GetErrorMessage@MixerCTL@@AAEPADK@Z
    ARTS_IMPORT char* GetErrorMessage(u32 arg1);

    // 0x4EEB70 | ?WindowProc@MixerCTL@@EAEJPAUHWND__@@IIJ@Z
    ARTS_IMPORT i32 WindowProc(struct HWND__* arg1, u32 arg2, u32 arg3, i32 arg4) override;
};

check_size(MixerCTL, 0x38);
