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

class aiGoalCollision final : public aiGoal
{
public:
    // ??0aiGoalCollision@@QAE@PAVaiRailSet@@PAVaiVehicleSpline@@@Z
    ARTS_IMPORT aiGoalCollision(aiRailSet* arg1, aiVehicleSpline* arg2);

    // ??1aiGoalCollision@@QAE@XZ
    ARTS_EXPORT ~aiGoalCollision() = default;

    // ?Context@aiGoalCollision@@UAEHXZ
    ARTS_IMPORT b32 Context() override;

    // ?Init@aiGoalCollision@@UAEXXZ
    ARTS_IMPORT void Init() override;

    // ?Priority@aiGoalCollision@@UAEHXZ
    ARTS_IMPORT i32 Priority() override;

    // ?Reset@aiGoalCollision@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@aiGoalCollision@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap8[0x8];
};

check_size(aiGoalCollision, 0x10);
