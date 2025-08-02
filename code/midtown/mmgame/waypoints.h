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

#include "arts7/node.h"

class mmPlayer;

class mmWaypoints final : public asNode
{
public:
    // ??0mmWaypoints@@QAE@XZ
    ARTS_IMPORT mmWaypoints();

    // ??_EmmWaypoints@@UAEPAXI@Z
    // ??_GmmWaypoints@@UAEPAXI@Z
    // ??1mmWaypoints@@UAE@XZ
    ARTS_IMPORT ~mmWaypoints() override;

    // ?AIWPHit@mmWaypoints@@QAEHHHVMatrix34@@VVector3@@M@Z
    ARTS_IMPORT i32 AIWPHit(i32 arg1, i32 arg2, Matrix34 arg3, Vector3 arg4, f32 arg5);

    // ?AnyAIWPHit@mmWaypoints@@QAEHAAIHVMatrix34@@VVector3@@M@Z
    ARTS_IMPORT i32 AnyAIWPHit(u32& arg1, i32 arg2, Matrix34 arg3, Vector3 arg4, f32 arg5);

    // ?AnyWPHits@mmWaypoints@@QAEHH@Z
    ARTS_IMPORT i32 AnyWPHits(i32 arg1);

    // ?BlitzRemove@mmWaypoints@@QAEHH@Z
    ARTS_IMPORT i32 BlitzRemove(i32 arg1);

    // ?CalculateGatePoints@mmWaypoints@@QAEXVVector3@@MMPAVVector2@@1@Z
    ARTS_IMPORT void CalculateGatePoints(Vector3 arg1, f32 arg2, f32 arg3, Vector2* arg4, Vector2* arg5);

    // ?ClearWaypoint@mmWaypoints@@QAEXH@Z
    ARTS_IMPORT void ClearWaypoint(i32 arg1);

    // ?Cull@mmWaypoints@@UAEXXZ
    ARTS_EXPORT void Cull() override;

    // ?CycleCurrentWaypoint@mmWaypoints@@QAEXH@Z
    ARTS_IMPORT void CycleCurrentWaypoint(i32 arg1);

    // ?DeactivateFinish@mmWaypoints@@QAEXXZ
    ARTS_IMPORT void DeactivateFinish();

    // ?DisplayHUDMessage@mmWaypoints@@QAEXHH@Z
    ARTS_IMPORT void DisplayHUDMessage(i32 arg1, i32 arg2);

    // ?GenerateHitRooms@mmWaypoints@@QAEXXZ
    ARTS_IMPORT void GenerateHitRooms();

    // ?GetClosestWaypoint@mmWaypoints@@QAEXXZ
    ARTS_IMPORT void GetClosestWaypoint();

    // ?GetHeading@mmWaypoints@@QAEMH@Z
    ARTS_IMPORT f32 GetHeading(i32 arg1);

    // ?GetHitRoom@mmWaypoints@@QAEHH@Z
    ARTS_IMPORT i32 GetHitRoom(i32 arg1);

    // ?GetLastWaypoint@mmWaypoints@@QAEXXZ
    ARTS_IMPORT void GetLastWaypoint();

    // ?GetNextWaypoint@mmWaypoints@@QAEXXZ
    ARTS_IMPORT void GetNextWaypoint();

    // ?GetStart@mmWaypoints@@QAEXAAVVector3@@@Z
    ARTS_IMPORT void GetStart(Vector3& arg1);

    // ?GetStartAngle@mmWaypoints@@QAEMXZ
    ARTS_IMPORT f32 GetStartAngle();

    // ?GetWaypoint@mmWaypoints@@QAEXHAAVVector3@@@Z
    ARTS_IMPORT void GetWaypoint(i32 arg1, Vector3& arg2);

    // ?Init@mmWaypoints@@QAEHPAVmmPlayer@@PADHHHH@Z
    ARTS_IMPORT i32 Init(mmPlayer* arg1, char* arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6);

    // ?LineIntersect@mmWaypoints@@QAEHVVector2@@000M@Z
    ARTS_IMPORT i32 LineIntersect(Vector2 arg1, Vector2 arg2, Vector2 arg3, Vector2 arg4, f32 arg5);

    // ?LoadCSV@mmWaypoints@@QAEHPADH@Z
    ARTS_IMPORT i32 LoadCSV(char* arg1, i32 arg2);

    // ?Reset@mmWaypoints@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?ResetAllTags@mmWaypoints@@QAEXXZ
    ARTS_IMPORT void ResetAllTags();

    // ?SetArrow@mmWaypoints@@QAEXXZ
    ARTS_IMPORT void SetArrow();

    // ?SetCurrentGoals@mmWaypoints@@QAEXH@Z
    ARTS_IMPORT void SetCurrentGoals(i32 arg1);

    // ?Update@mmWaypoints@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateWPHUD@mmWaypoints@@QAEXXZ
    ARTS_IMPORT void UpdateWPHUD();

    // ?WPHit@mmWaypoints@@QAEHHVVector3@@HH@Z
    ARTS_IMPORT i32 WPHit(i32 arg1, Vector3 arg2, i32 arg3, i32 arg4);

    u8 gap20[0x8C];
};

check_size(mmWaypoints, 0xAC);

struct mmGate
{
public:
    // ?CloseEnough@mmGate@@QAEHMM@Z
    ARTS_IMPORT i32 CloseEnough(f32 arg1, f32 arg2);

    // ?LineEq@mmGate@@QAEMMM@Z
    ARTS_IMPORT f32 LineEq(f32 arg1, f32 arg2);

    u8 gap0[0x18];
};

check_size(mmGate, 0x18);

// ?Size@@3VVector3@@A
ARTS_IMPORT extern Vector3 Size;
