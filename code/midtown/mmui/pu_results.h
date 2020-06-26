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
    mmui:pu_results

    0x4A8080 | public: __thiscall PUResults::PUResults(int,float,float,float,float,char *) | ??0PUResults@@QAE@HMMMMPAD@Z
    0x4A81B0 | public: void __thiscall PUResults::Init320(void) | ?Init320@PUResults@@QAEXXZ
    0x4A8590 | public: void __thiscall PUResults::Init640(void) | ?Init640@PUResults@@QAEXXZ
    0x4A89C0 | public: virtual __thiscall PUResults::~PUResults(void) | ??1PUResults@@UAE@XZ
    0x4A89D0 | public: void __thiscall PUResults::AddTitle(struct LocString *,struct LocString *) | ?AddTitle@PUResults@@QAEXPAULocString@@0@Z
    0x4A8A00 | public: virtual void __thiscall PUResults::Reset(void) | ?Reset@PUResults@@UAEXXZ
    0x4A8A10 | public: void __thiscall PUResults::RosterRO(int) | ?RosterRO@PUResults@@QAEXH@Z
    0x4A8A30 | public: void __thiscall PUResults::RestartRO(int) | ?RestartRO@PUResults@@QAEXH@Z
    0x4A8A50 | public: void __thiscall PUResults::AddName(int,char *,float) | ?AddName@PUResults@@QAEXHPADM@Z
    0x4A8B00 | public: void __thiscall PUResults::AddName(int,char *,int) | ?AddName@PUResults@@QAEXHPADH@Z
    0x4A8BC0 | public: void __thiscall PUResults::ClearNames(void) | ?ClearNames@PUResults@@QAEXXZ
    0x4A8C30 | public: void __thiscall PUResults::DisableNextRace(void) | ?DisableNextRace@PUResults@@QAEXXZ
    0x4A8C40 | public: void __thiscall PUResults::EnableNextRace(void) | ?EnableNextRace@PUResults@@QAEXXZ
    0x4A8C50 | public: void __thiscall PUResults::SetMessage(struct LocString *) | ?SetMessage@PUResults@@QAEXPAULocString@@@Z
    0x4A8C70 | public: virtual void * __thiscall PUResults::`vector deleting destructor'(unsigned int) | ??_EPUResults@@UAEPAXI@Z
    0x4A8C70 | public: virtual void * __thiscall PUResults::`scalar deleting destructor'(unsigned int) | ??_GPUResults@@UAEPAXI@Z
    0x61DDA8 | const PUResults::`vftable' | ??_7PUResults@@6B@
*/

#include "pu_menu.h"

class PUResults : public PUMenuBase
{
    // const PUResults::`vftable' @ 0x61DDA8

public:
    // 0x4A8080 | ??0PUResults@@QAE@HMMMMPAD@Z
    ARTS_IMPORT PUResults(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6);

    // 0x4A8C70 | ??_GPUResults@@UAEPAXI@Z
    // 0x4A89C0 | ??1PUResults@@UAE@XZ
    ARTS_IMPORT ~PUResults() override;

    // 0x4A8A50 | ?AddName@PUResults@@QAEXHPADM@Z
    ARTS_IMPORT void AddName(i32 arg1, char* arg2, f32 arg3);

    // 0x4A8B00 | ?AddName@PUResults@@QAEXHPADH@Z
    ARTS_IMPORT void AddName(i32 arg1, char* arg2, i32 arg3);

    // 0x4A89D0 | ?AddTitle@PUResults@@QAEXPAULocString@@0@Z
    ARTS_IMPORT void AddTitle(struct LocString* arg1, struct LocString* arg2);

    // 0x4A8BC0 | ?ClearNames@PUResults@@QAEXXZ
    ARTS_IMPORT void ClearNames();

    // 0x4A8C30 | ?DisableNextRace@PUResults@@QAEXXZ
    ARTS_IMPORT void DisableNextRace();

    // 0x4A8C40 | ?EnableNextRace@PUResults@@QAEXXZ
    ARTS_IMPORT void EnableNextRace();

    // 0x4A81B0 | ?Init320@PUResults@@QAEXXZ
    ARTS_IMPORT void Init320();

    // 0x4A8590 | ?Init640@PUResults@@QAEXXZ
    ARTS_IMPORT void Init640();

    // 0x4A8A00 | ?Reset@PUResults@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4A8A30 | ?RestartRO@PUResults@@QAEXH@Z
    ARTS_IMPORT void RestartRO(i32 arg1);

    // 0x4A8A10 | ?RosterRO@PUResults@@QAEXH@Z
    ARTS_IMPORT void RosterRO(i32 arg1);

    // 0x4A8C50 | ?SetMessage@PUResults@@QAEXPAULocString@@@Z
    ARTS_IMPORT void SetMessage(struct LocString* arg1);
};

check_size(PUResults, 0xF0);
