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

#include "pu_menu.h"

class mmTextNode;

enum
{
    IDC_PU_RESULTS_RESTART = 10,
    IDC_PU_RESULTS_NEXT = 11,
    IDC_PU_RESULTS_ROSTER = 12,
    IDC_PU_RESULTS_QUIT = 13,
    IDC_PU_RESULTS_EXIT = 14,
};

class PUResults final : public PUMenuBase
{
public:
    // ??0PUResults@@QAE@HMMMMPAD@Z
    ARTS_EXPORT PUResults(i32 menu_id, f32 x, f32 y, f32 width, f32 height, char* background);

    // ??_GPUResults@@UAEPAXI@Z
    // ??_EPUResults@@UAEPAXI@Z
    // ??1PUResults@@UAE@XZ
    ARTS_EXPORT ~PUResults() override;

    // ?AddName@PUResults@@QAEXHPADM@Z
    ARTS_IMPORT void AddName(i32 arg1, char* arg2, f32 arg3);

    // ?AddName@PUResults@@QAEXHPADH@Z
    ARTS_IMPORT void AddName(i32 arg1, char* arg2, i32 arg3);

    // ?AddTitle@PUResults@@QAEXPAULocString@@0@Z
    ARTS_IMPORT void AddTitle(LocString* arg1, LocString* arg2);

    // ?ClearNames@PUResults@@QAEXXZ
    ARTS_IMPORT void ClearNames();

    // ?DisableNextRace@PUResults@@QAEXXZ
    ARTS_IMPORT void DisableNextRace();

    // ?EnableNextRace@PUResults@@QAEXXZ
    ARTS_IMPORT void EnableNextRace();

    // ?Init320@PUResults@@QAEXXZ
    ARTS_IMPORT void Init320();

    // ?Init640@PUResults@@QAEXXZ
    ARTS_EXPORT void Init640();

    // ?Reset@PUResults@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?RestartRO@PUResults@@QAEXH@Z
    ARTS_IMPORT void RestartRO(i32 arg1);

    // ?RosterRO@PUResults@@QAEXH@Z
    ARTS_IMPORT void RosterRO(i32 arg1);

    // ?SetMessage@PUResults@@QAEXPAULocString@@@Z
    ARTS_IMPORT void SetMessage(LocString* arg1);

    Ptr<mmTextNode> RaceType;
    Ptr<mmTextNode> RaceName;
    Ptr<mmTextNode> Names;
    Ptr<mmTextNode> Message;

    UIButton* RosterButton {};
    UIButton* NextButton {};
    UIButton* RestartButton {};

    ConstString RestartRace;
    ConstString NextRace;
    ConstString ShowRoster;
    ConstString RaceMenu;
    ConstString ExitToWindows;
};

check_size(PUResults, 0xF0);
