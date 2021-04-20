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
    mmaudio:creverb

    0x4F4760 | public: __thiscall CReverb::CReverb(struct IDirectSound3DBuffer *) | ??0CReverb@@QAE@PAUIDirectSound3DBuffer@@@Z
    0x4F4800 | public: __thiscall CReverb::~CReverb(void) | ??1CReverb@@QAE@XZ
    0x4F4810 | public: int __thiscall CReverb::PropertySetOk(void) | ?PropertySetOk@CReverb@@QAEHXZ
    0x4F4820 | private: int __thiscall CReverb::QueryProperty(unsigned long) | ?QueryProperty@CReverb@@AAEHK@Z
    0x4F4870 | public: void __thiscall CReverb::SetEnvironment(unsigned long) | ?SetEnvironment@CReverb@@QAEXK@Z
    0x4F4890 | public: void __thiscall CReverb::SetVolume(float) | ?SetVolume@CReverb@@QAEXM@Z
    0x4F48B0 | public: void __thiscall CReverb::SetDecayTime(float) | ?SetDecayTime@CReverb@@QAEXM@Z
    0x4F48D0 | public: void __thiscall CReverb::SetDamping(float) | ?SetDamping@CReverb@@QAEXM@Z
    0x4F48F0 | public: void __thiscall CReverb::SetAll(struct EAX_REVERBPROPERTIES *) | ?SetAll@CReverb@@QAEXPAUEAX_REVERBPROPERTIES@@@Z
    0x4F4910 | public: void __thiscall CReverb::SetPreset(unsigned long,float,float,float) | ?SetPreset@CReverb@@QAEXKMMM@Z
    0x4F4950 | public: void __thiscall CReverb::SetPreset(struct EAX_REVERBPROPERTIES *) | ?SetPreset@CReverb@@QAEXPAUEAX_REVERBPROPERTIES@@@Z
    0x4F4970 | public: unsigned long __thiscall CReverb::GetEnvironment(void) | ?GetEnvironment@CReverb@@QAEKXZ
    0x4F49B0 | public: float __thiscall CReverb::GetVolume(void) | ?GetVolume@CReverb@@QAEMXZ
    0x4F49F0 | public: float __thiscall CReverb::GetDecayTime(void) | ?GetDecayTime@CReverb@@QAEMXZ
    0x4F4A30 | public: float __thiscall CReverb::GetDamping(void) | ?GetDamping@CReverb@@QAEMXZ
    0x4F4A70 | public: void __thiscall CReverb::GetAll(struct EAX_REVERBPROPERTIES *) | ?GetAll@CReverb@@QAEXPAUEAX_REVERBPROPERTIES@@@Z
*/

class CReverb
{
public:
    // 0x4F4760 | ??0CReverb@@QAE@PAUIDirectSound3DBuffer@@@Z
    ARTS_IMPORT CReverb(struct IDirectSound3DBuffer* arg1);

    // 0x4F4800 | ??1CReverb@@QAE@XZ
    ARTS_IMPORT ~CReverb();

    // 0x4F4A70 | ?GetAll@CReverb@@QAEXPAUEAX_REVERBPROPERTIES@@@Z
    ARTS_IMPORT void GetAll(struct EAX_REVERBPROPERTIES* arg1);

    // 0x4F4A30 | ?GetDamping@CReverb@@QAEMXZ
    ARTS_IMPORT f32 GetDamping();

    // 0x4F49F0 | ?GetDecayTime@CReverb@@QAEMXZ
    ARTS_IMPORT f32 GetDecayTime();

    // 0x4F4970 | ?GetEnvironment@CReverb@@QAEKXZ
    ARTS_IMPORT ulong GetEnvironment();

    // 0x4F49B0 | ?GetVolume@CReverb@@QAEMXZ
    ARTS_IMPORT f32 GetVolume();

    // 0x4F4810 | ?PropertySetOk@CReverb@@QAEHXZ
    ARTS_IMPORT i32 PropertySetOk();

    // 0x4F48F0 | ?SetAll@CReverb@@QAEXPAUEAX_REVERBPROPERTIES@@@Z | unused
    ARTS_IMPORT void SetAll(struct EAX_REVERBPROPERTIES* arg1);

    // 0x4F48D0 | ?SetDamping@CReverb@@QAEXM@Z
    ARTS_IMPORT void SetDamping(f32 arg1);

    // 0x4F48B0 | ?SetDecayTime@CReverb@@QAEXM@Z
    ARTS_IMPORT void SetDecayTime(f32 arg1);

    // 0x4F4870 | ?SetEnvironment@CReverb@@QAEXK@Z
    ARTS_IMPORT void SetEnvironment(ulong arg1);

    // 0x4F4950 | ?SetPreset@CReverb@@QAEXPAUEAX_REVERBPROPERTIES@@@Z
    ARTS_IMPORT void SetPreset(struct EAX_REVERBPROPERTIES* arg1);

    // 0x4F4910 | ?SetPreset@CReverb@@QAEXKMMM@Z
    ARTS_IMPORT void SetPreset(ulong arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x4F4890 | ?SetVolume@CReverb@@QAEXM@Z
    ARTS_IMPORT void SetVolume(f32 arg1);

private:
    // 0x4F4820 | ?QueryProperty@CReverb@@AAEHK@Z
    ARTS_IMPORT i32 QueryProperty(ulong arg1);

    u8 gap0[0x4];
};

check_size(CReverb, 0x4);
