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
    mmai:aiGoalBackup

    0x45F830 | public: __thiscall aiGoalBackup::aiGoalBackup(class aiRailSet *,class mmCar *,short *) | ??0aiGoalBackup@@QAE@PAVaiRailSet@@PAVmmCar@@PAF@Z
    0x45F860 | public: __thiscall aiGoalBackup::~aiGoalBackup(void) | ??1aiGoalBackup@@QAE@XZ
    0x45F870 | public: virtual void __thiscall aiGoalBackup::Init(void) | ?Init@aiGoalBackup@@UAEXXZ
    0x45F880 | public: virtual int __thiscall aiGoalBackup::Context(void) | ?Context@aiGoalBackup@@UAEHXZ
    0x45F890 | public: virtual int __thiscall aiGoalBackup::Priority(void) | ?Priority@aiGoalBackup@@UAEHXZ
    0x45F8A0 | public: virtual void __thiscall aiGoalBackup::Reset(void) | ?Reset@aiGoalBackup@@UAEXXZ
    0x45F8D0 | public: virtual void __thiscall aiGoalBackup::Update(void) | ?Update@aiGoalBackup@@UAEXXZ
    0x45FC10 | private: void __thiscall aiGoalBackup::FinishedBackingUp(void) | ?FinishedBackingUp@aiGoalBackup@@AAEXXZ
    0x61BB50 | const aiGoalBackup::`vftable' | ??_7aiGoalBackup@@6B@
*/

#include "aiGoal.h"

class aiGoalBackup final : public aiGoal
{
public:
    // ??0aiGoalBackup@@QAE@PAVaiRailSet@@PAVmmCar@@PAF@Z
    ARTS_IMPORT aiGoalBackup(class aiRailSet* arg1, class mmCar* arg2, i16* arg3);

    // ??1aiGoalBackup@@QAE@XZ
    ARTS_IMPORT ~aiGoalBackup() = default;

    // ?Context@aiGoalBackup@@UAEHXZ
    ARTS_IMPORT i32 Context() override;

    // ?Init@aiGoalBackup@@UAEXXZ
    ARTS_IMPORT void Init() override;

    // ?Priority@aiGoalBackup@@UAEHXZ
    ARTS_IMPORT i32 Priority() override;

    // ?Reset@aiGoalBackup@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@aiGoalBackup@@UAEXXZ
    ARTS_IMPORT void Update() override;

private:
    // ?FinishedBackingUp@aiGoalBackup@@AAEXXZ
    ARTS_IMPORT void FinishedBackingUp();

    u8 gap8[0xC];
};

check_size(aiGoalBackup, 0x14);
