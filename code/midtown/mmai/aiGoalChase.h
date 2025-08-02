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

class aiIntersection;
class aiPath;
class aiRailSet;
class aiVehiclePolice;
class mmCar;

class aiGoalChase final : public aiGoal
{
public:
    // ??0aiGoalChase@@QAE@PAVaiVehiclePolice@@PAVaiRailSet@@PAPAVmmCar@@PAFPAVVector3@@3@Z
    ARTS_IMPORT aiGoalChase(aiVehiclePolice* arg1, aiRailSet* arg2, mmCar** arg3, i16* arg4, Vector3* arg5, i16* arg6);

    // ??1aiGoalChase@@QAE@XZ
    ARTS_IMPORT ~aiGoalChase();

    // ?Context@aiGoalChase@@UAEHXZ
    ARTS_IMPORT b32 Context() override;

    // ?Dump@aiGoalChase@@QAEXXZ
    ARTS_IMPORT void Dump();

    // ?Init@aiGoalChase@@UAEXXZ
    ARTS_IMPORT void Init() override;

    // ?Priority@aiGoalChase@@UAEHXZ
    ARTS_IMPORT i32 Priority() override;

    // ?Reset@aiGoalChase@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@aiGoalChase@@UAEXXZ
    ARTS_IMPORT void Update() override;

private:
    // ?AddToBlockedRange@aiGoalChase@@AAEXMMM@Z
    ARTS_IMPORT void AddToBlockedRange(f32 arg1, f32 arg2, f32 arg3);

    // ?AvoidAmbientCollision@aiGoalChase@@AAEXH@Z
    ARTS_IMPORT void AvoidAmbientCollision(i32 arg1);

    // ?AvoidCopCollision@aiGoalChase@@AAEXPAVaiVehiclePolice@@@Z
    ARTS_IMPORT void AvoidCopCollision(aiVehiclePolice* arg1);

    // ?Barricade@aiGoalChase@@AAEXXZ
    ARTS_IMPORT void Barricade();

    // ?Block@aiGoalChase@@AAEXXZ
    ARTS_IMPORT void Block();

    // ?CalcSpeed@aiGoalChase@@AAEXM@Z
    ARTS_IMPORT void CalcSpeed(f32 arg1);

    // ?CloseInOpenArea@aiGoalChase@@AAEXXZ
    ARTS_IMPORT void CloseInOpenArea();

    // ?CloseInRoad@aiGoalChase@@AAEXXZ
    ARTS_IMPORT void CloseInRoad();

    // ?Collision@aiGoalChase@@AAEHPAVmmCar@@@Z
    ARTS_IMPORT i32 Collision(mmCar* arg1);

    // ?DetectAmbientCollision@aiGoalChase@@AAEHPAH@Z
    ARTS_IMPORT i32 DetectAmbientCollision(i32* arg1);

    // ?DetectCopCollision@aiGoalChase@@AAEPAVaiVehiclePolice@@XZ
    ARTS_IMPORT aiVehiclePolice* DetectCopCollision();

    // ?FindPerp@aiGoalChase@@AAEHHHPAVaiPath@@@Z
    ARTS_IMPORT i32 FindPerp(i32 arg1, i32 arg2, aiPath* arg3);

    // ?Follow@aiGoalChase@@AAEXXZ
    ARTS_IMPORT void Follow();

    // ?Fov@aiGoalChase@@AAEHPAVmmCar@@@Z
    ARTS_IMPORT i32 Fov(mmCar* arg1);

    // ?HitMe@aiGoalChase@@AAEHPAVmmCar@@@Z
    ARTS_IMPORT i32 HitMe(mmCar* arg1);

    // ?IsPerpACop@aiGoalChase@@AAEHPAVmmCar@@@Z
    ARTS_IMPORT i32 IsPerpACop(mmCar* arg1);

    // ?LocatePerpFromInt@aiGoalChase@@AAEHPAVaiIntersection@@PAPAVaiPath@@@Z
    ARTS_IMPORT i32 LocatePerpFromInt(aiIntersection* arg1, aiPath** arg2);

    // ?LocatePerpFromRoad@aiGoalChase@@AAEHPAVaiPath@@PAPAV2@1@Z
    ARTS_IMPORT i32 LocatePerpFromRoad(aiPath* arg1, aiPath** arg2, aiPath** arg3);

    // ?OffRoad@aiGoalChase@@AAEHPAVmmCar@@@Z
    ARTS_IMPORT i32 OffRoad(mmCar* arg1);

    // ?PlanRoute@aiGoalChase@@AAEHXZ
    ARTS_IMPORT i32 PlanRoute();

    // ?ProcessCollision@aiGoalChase@@AAEXH@Z
    ARTS_IMPORT void ProcessCollision(i32 arg1);

    // ?Push@aiGoalChase@@AAEXXZ
    ARTS_IMPORT void Push();

    // ?Speeding@aiGoalChase@@AAEHPAVmmCar@@@Z
    ARTS_IMPORT i32 Speeding(mmCar* arg1);

    // ?Stopped@aiGoalChase@@AAEHPAVmmCar@@@Z
    ARTS_IMPORT i32 Stopped(mmCar* arg1);

    u8 gap8[0x1A4];
};

check_size(aiGoalChase, 0x1AC);
