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
class aiVehicleSpline;

class aiGoalRegainRail final : public aiGoal
{
public:
    // ??0aiGoalRegainRail@@QAE@PAVaiRailSet@@PAVaiVehicleSpline@@@Z
    ARTS_IMPORT aiGoalRegainRail(aiRailSet* arg1, aiVehicleSpline* arg2);

    // ??1aiGoalRegainRail@@QAE@XZ
    ARTS_EXPORT ~aiGoalRegainRail() = default;

    // ?Context@aiGoalRegainRail@@UAEHXZ
    ARTS_IMPORT b32 Context() override;

    // ?Dump@aiGoalRegainRail@@QAEXXZ
    ARTS_IMPORT void Dump();

    // ?Init@aiGoalRegainRail@@UAEXXZ
    ARTS_IMPORT void Init() override;

    // ?Priority@aiGoalRegainRail@@UAEHXZ
    ARTS_IMPORT i32 Priority() override;

    // ?Reset@aiGoalRegainRail@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@aiGoalRegainRail@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap8[0x20];
};

check_size(aiGoalRegainRail, 0x28);
