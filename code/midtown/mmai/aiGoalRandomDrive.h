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

class aiGoalRandomDrive final : public aiGoal
{
public:
    // ??0aiGoalRandomDrive@@QAE@PAVaiRailSet@@PAVaiVehicleSpline@@@Z
    ARTS_IMPORT aiGoalRandomDrive(aiRailSet* arg1, aiVehicleSpline* arg2);

    // ??1aiGoalRandomDrive@@QAE@XZ
    ARTS_EXPORT ~aiGoalRandomDrive() = default;

    // ?Context@aiGoalRandomDrive@@UAEHXZ
    ARTS_IMPORT b32 Context() override;

    // ?Dump@aiGoalRandomDrive@@QAEXXZ
    ARTS_IMPORT void Dump();

    // ?Init@aiGoalRandomDrive@@UAEXXZ
    ARTS_IMPORT void Init() override;

    // ?Priority@aiGoalRandomDrive@@UAEHXZ
    ARTS_IMPORT b32 Priority() override;

    // ?Reset@aiGoalRandomDrive@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@aiGoalRandomDrive@@UAEXXZ
    ARTS_IMPORT void Update() override;

private:
    // ?AnyVehiclesComingThisWay@aiGoalRandomDrive@@AAEHXZ
    ARTS_IMPORT i32 AnyVehiclesComingThisWay();

    // ?AvoidCollision@aiGoalRandomDrive@@AAEXPAVaiVehicleSpline@@M@Z
    ARTS_IMPORT void AvoidCollision(aiVehicleSpline* arg1, f32 arg2);

    // ?ChangeLanes@aiGoalRandomDrive@@AAEXXZ
    ARTS_IMPORT void ChangeLanes();

    // ?OkayToEnterIntersection@aiGoalRandomDrive@@AAEHXZ
    ARTS_IMPORT i32 OkayToEnterIntersection();

    // ?SolveLane@aiGoalRandomDrive@@AAEXXZ
    ARTS_IMPORT void SolveLane();

    // ?SolveRailType@aiGoalRandomDrive@@AAEXXZ
    ARTS_IMPORT void SolveRailType();

    // ?SolveVelocity@aiGoalRandomDrive@@AAEXXZ
    ARTS_IMPORT void SolveVelocity();

    u8 gap8[0xC];
};

check_size(aiGoalRandomDrive, 0x14);
