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

#include "vector7/vector4.h"

class aiPath;

class aiRailSet
{
public:
    // ??0aiRailSet@@QAE@XZ
    ARTS_IMPORT aiRailSet();

    // ??1aiRailSet@@QAE@XZ
    ARTS_EXPORT ~aiRailSet() = default;

    // ?CalcCopRailPosition@aiRailSet@@QAEHAAVVector3@@0MM@Z
    ARTS_IMPORT i32 CalcCopRailPosition(Vector3& arg1, Vector3& arg2, f32 arg3, f32 arg4);

    // ?CalcRailLength@aiRailSet@@QAEMXZ
    ARTS_IMPORT f32 CalcRailLength();

    // ?CalcRailPosOrient@aiRailSet@@QAEXAAVVector3@@0M@Z
    ARTS_IMPORT void CalcRailPosOrient(Vector3& arg1, Vector3& arg2, f32 arg3);

    // ?CalcRailPosition@aiRailSet@@QAEXAAVVector3@@M@Z
    ARTS_IMPORT void CalcRailPosition(Vector3& arg1, f32 arg2);

    // ?CalcRailState@aiRailSet@@QAEHM@Z
    ARTS_IMPORT i32 CalcRailState(f32 arg1);

    // ?CalcTurnIntersection@aiRailSet@@QAEXAAVVector3@@HPAVaiPath@@1@Z
    ARTS_IMPORT void CalcTurnIntersection(Vector3& arg1, i32 arg2, aiPath* arg3, aiPath* arg4);

    // ?CalcXZDirection@aiRailSet@@QAEXAAVVector3@@0000M@Z | unused
    ARTS_IMPORT void CalcXZDirection(
        Vector3& arg1, Vector3& arg2, Vector3& arg3, Vector3& arg4, Vector3& arg5, f32 arg6);

    // ?CalcXZPosOrient@aiRailSet@@QAEXAAVVector3@@00000M@Z
    ARTS_IMPORT void CalcXZPosOrient(
        Vector3& arg1, Vector3& arg2, Vector3& arg3, Vector3& arg4, Vector3& arg5, Vector3& arg6, f32 arg7);

    // ?CalcXZPosition@aiRailSet@@QAEXAAVVector3@@0000M@Z
    ARTS_IMPORT void CalcXZPosition(
        Vector3& arg1, Vector3& arg2, Vector3& arg3, Vector3& arg4, Vector3& arg5, f32 arg6);

    // ?ComputeXZCurve@aiRailSet@@QAEXAAVVector3@@000@Z
    ARTS_IMPORT void ComputeXZCurve(Vector3& arg1, Vector3& arg2, Vector3& arg3, Vector3& arg4);

    // ?ComputeXZCurve@aiRailSet@@QAEXAAVVector3@@000AAVVector4@@1@Z
    ARTS_IMPORT void ComputeXZCurve(
        Vector3& arg1, Vector3& arg2, Vector3& arg3, Vector3& arg4, Vector4& arg5, Vector4& arg6);

    // ?DrawTurn@aiRailSet@@QAEXM@Z
    ARTS_IMPORT void DrawTurn(f32 arg1);

    // ?Dump@aiRailSet@@QAEXXZ
    ARTS_IMPORT void Dump();

    // ?SolveTurnType@aiRailSet@@QAEHPAVaiPath@@0@Z
    ARTS_IMPORT i32 SolveTurnType(aiPath* arg1, aiPath* arg2);

    // ?SolveXZCurve@aiRailSet@@QAEXAAVVector3@@0M@Z
    ARTS_IMPORT void SolveXZCurve(Vector3& arg1, Vector3& arg2, f32 arg3);

    f32 BackBumperDist;
    f32 FrontBumperDist;
    f32 LSideDist;
    f32 RSideDist;
    i16 EnterInt;
    f32 RoadDist;
    f32 ResumeDist;
    f32 SubSectionDist;
    f32 TurnDist;
    f32 LaneRandomness;
    i16 WaitCount;
    i16 SSIdx;
    i16 CurLane;
    i16 NextLane;
    i16 TargetLane;
    i32 RailType;
    aiPath* NextLink;
    aiPath* CurLink;
    f32 TurnCenterPtOffset;
    f32 CurAccelFactor;
    f32 ExheedLimit;
    f32 TargetVelocity;
    f32 CarReactDist;
    f32 VehicleAccelFactor;
    f32 SeparationDist;
    f32 IntersectionReactDist;
    f32 field_60;
    f32 field_64;
    f32 field_68;
    f32 field_6C;
    Vector4 field_70;
};

check_size(aiRailSet, 0x80);

// ??D@YA?AVVector3@@MABV0@@Z | inline
ARTS_IMPORT Vector3 operator*(f32 arg1, const Vector3& arg2);
