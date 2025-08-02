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

#include "aiGoal.h"

class aiRailSet;
class mmCar;

class aiGoalBackup final : public aiGoal
{
public:
    // ??0aiGoalBackup@@QAE@PAVaiRailSet@@PAVmmCar@@PAF@Z
    ARTS_EXPORT aiGoalBackup(aiRailSet* rail, mmCar* car, b16* backing_up);

    // ??1aiGoalBackup@@QAE@XZ
    ARTS_EXPORT ~aiGoalBackup() = default;

    // ?Context@aiGoalBackup@@UAEHXZ
    ARTS_EXPORT b32 Context() override;

    // ?Init@aiGoalBackup@@UAEXXZ
    ARTS_EXPORT void Init() override;

    // ?Priority@aiGoalBackup@@UAEHXZ
    ARTS_EXPORT i32 Priority() override;

    // ?Reset@aiGoalBackup@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // ?Update@aiGoalBackup@@UAEXXZ
    ARTS_EXPORT void Update() override;

private:
    // ?FinishedBackingUp@aiGoalBackup@@AAEXXZ
    ARTS_EXPORT void FinishedBackingUp();

    aiRailSet* Rail {};
    mmCar* Car {};
    b16* BackingUp {};
};

check_size(aiGoalBackup, 0x14);
