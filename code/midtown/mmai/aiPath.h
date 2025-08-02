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

#include "vector7/vector3.h"

class aiIntersection;
class aiPedestrian;
class aiVehicleSpline;
class mmRoadSect;

#define AI_INTERSECTION_STOP 0
#define AI_INTERSECTION_TRAFFIC_LIGHT 1
#define AI_INTERSECTION_YIELD 2 // Unused
#define AI_INTERSECTION_CONTINUE 3

class aiPath
{
public:
    // ??0aiPath@@QAE@H@Z
    ARTS_IMPORT aiPath(i32 arg1);

    // ??1aiPath@@QAE@XZ
    ARTS_IMPORT ~aiPath();

    // ?AddPathVerts@aiPath@@QAEXPAVVector3@@H@Z
    ARTS_IMPORT void AddPathVerts(Vector3* arg1, i32 arg2);

    // ?AddPathVerts@aiPath@@QAEXAAVmmRoadSect@@HH@Z
    ARTS_IMPORT void AddPathVerts(mmRoadSect& arg1, i32 arg2, i32 arg3);

    // ?AddPedestrian@aiPath@@QAEXPAVaiPedestrian@@@Z
    ARTS_IMPORT void AddPedestrian(aiPedestrian* arg1);

    // ?AddVehicle@aiPath@@QAEXPAVaiVehicleSpline@@HM@Z
    ARTS_IMPORT void AddVehicle(aiVehicleSpline* arg1, i32 arg2, f32 arg3);

    // ?AllwaysGo@aiPath@@QAEXH@Z
    ARTS_IMPORT void AllwaysGo(i32 arg1);

    // ?AllwaysStop@aiPath@@QAEXH@Z
    ARTS_IMPORT void AllwaysStop(i32 arg1);

    // ?AmbientCenterDistance@aiPath@@QAEXPAVaiVehicleSpline@@PAM111@Z
    ARTS_IMPORT void AmbientCenterDistance(aiVehicleSpline* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5);

    // ?Blocked@aiPath@@QAEXH@Z
    ARTS_IMPORT void Blocked(i32 arg1);

    // ?CalcCenterVerts@aiPath@@QAEXAAVmmRoadSect@@H@Z
    ARTS_IMPORT void CalcCenterVerts(mmRoadSect& arg1, i32 arg2);

    // ?CenterDistance@aiPath@@QAEHAAVVector3@@PAFPAM2@Z
    ARTS_IMPORT i32 CenterDistance(Vector3& arg1, i16* arg2, f32* arg3, f32* arg4);

    // ?CenterIndex@aiPath@@QAEHM@Z
    ARTS_IMPORT i32 CenterIndex(f32 arg1);

    // ?CenterLength@aiPath@@QAEMHH@Z
    ARTS_IMPORT f32 CenterLength(i32 arg1, i32 arg2);

    // ?CenterVertice@aiPath@@QAEPAVVector3@@H@Z | inline
    ARTS_IMPORT Vector3* CenterVertice(i32 arg1);

#ifdef ARTS_DEV_BUILD
    // ?Draw@aiPath@@QAEXXZ
    ARTS_IMPORT void Draw();

    // ?DrawId@aiPath@@QAEXXZ
    ARTS_IMPORT void DrawId();

    // ?DrawNormals@aiPath@@QAEXXZ
    ARTS_IMPORT void DrawNormals();

#endif

    // ?Dump@aiPath@@QAEXXZ | unused
    ARTS_EXPORT void Dump();

    // ?GetHeading@aiPath@@QAEMMH@Z
    ARTS_IMPORT f32 GetHeading(f32 arg1, i32 arg2);

    // ?Index@aiPath@@QAEHAAVVector3@@@Z
    ARTS_IMPORT i32 Index(Vector3& arg1);

    // ?Index@aiPath@@QAEHMH@Z
    ARTS_IMPORT i32 Index(f32 arg1, i32 arg2);

    // ?IntersectionEntryPt@aiPath@@QAEXAAVVector3@@HM@Z
    ARTS_IMPORT void IntersectionEntryPt(Vector3& arg1, i32 arg2, f32 arg3);

    // ?IntersectionEntryVector@aiPath@@QAEXAAVVector3@@M@Z
    ARTS_IMPORT void IntersectionEntryVector(Vector3& arg1, f32 arg2);

    // ?IntersectionExitVector@aiPath@@QAEXAAVVector3@@M@Z
    ARTS_IMPORT void IntersectionExitVector(Vector3& arg1, f32 arg2);

    // ?LBoundary@aiPath@@QAEPAVVector3@@H@Z | inline
    ARTS_IMPORT Vector3* LBoundary(i32 arg1);

    // ?NumVehiclesAfterDist@aiPath@@QAEHHM@Z
    ARTS_IMPORT i32 NumVehiclesAfterDist(i32 arg1, f32 arg2);

    // ?PopVehicle@aiPath@@QAEXPAVaiVehicleSpline@@H@Z
    ARTS_IMPORT void PopVehicle(aiVehicleSpline* arg1, i32 arg2);

    // ?PushVehicle@aiPath@@QAEXPAVaiVehicleSpline@@H@Z
    ARTS_IMPORT void PushVehicle(aiVehicleSpline* arg1, i32 arg2);

    // ?ReadBinary@aiPath@@QAEXPAVStream@@@Z
    ARTS_IMPORT void ReadBinary(Stream* arg1);

    // ?RemovePedestrian@aiPath@@QAEXPAVaiPedestrian@@@Z
    ARTS_IMPORT void RemovePedestrian(aiPedestrian* arg1);

    // ?RemoveVehicle@aiPath@@QAEHPAVaiVehicleSpline@@H@Z
    ARTS_IMPORT i32 RemoveVehicle(aiVehicleSpline* arg1, i32 arg2);

    // ?Reset@aiPath@@QAEXXZ
    ARTS_IMPORT void Reset();

    // ?ResetVehicleReactTicks@aiPath@@QAEXXZ
    ARTS_IMPORT void ResetVehicleReactTicks();

    // ?RoadCapacity@aiPath@@QAEHPAVaiVehicleSpline@@H@Z
    ARTS_IMPORT i32 RoadCapacity(aiVehicleSpline* arg1, i32 arg2);

    // ?RoadDistance@aiPath@@QAEXAAVVector3@@PAFPAMF2@Z
    ARTS_IMPORT void RoadDistance(Vector3& arg1, i16* arg2, f32* arg3, i16 arg4, f32* arg5);

    // ?SaveBinary@aiPath@@QAEXPAVStream@@@Z
    ARTS_IMPORT void SaveBinary(Stream* arg1);

    // ?StopDestinationSources@aiPath@@QAEXH@Z
    ARTS_IMPORT void StopDestinationSources(b32 arg1);

    // ?SubSectionDir@aiPath@@QAEXAAVVector3@@HHM@Z
    ARTS_IMPORT void SubSectionDir(Vector3& arg1, i32 arg2, i32 arg3, f32 arg4);

    // ?SubSectionDist@aiPath@@QAEMMH@Z
    ARTS_IMPORT f32 SubSectionDist(f32 arg1, i32 arg2);

    // ?SubSectionLength@aiPath@@QAEMHH@Z
    ARTS_IMPORT f32 SubSectionLength(i32 arg1, i32 arg2);

    // ?SubSectionPt@aiPath@@QAEXAAVVector3@@HHM@Z
    ARTS_IMPORT void SubSectionPt(Vector3& arg1, i32 arg2, i32 arg3, f32 arg4);

    // ?UpdateAmbients@aiPath@@QAEXXZ
    ARTS_IMPORT void UpdateAmbients();

    // ?UpdatePedestrians@aiPath@@QAEXXZ
    ARTS_IMPORT void UpdatePedestrians();

    // ?VertXDir@aiPath@@QAEPAVVector3@@H@Z | inline
    ARTS_IMPORT Vector3* VertXDir(i32 arg1);

    // ?VertZDir@aiPath@@QAEPAVVector3@@H@Z | inline
    ARTS_IMPORT Vector3* VertZDir(i32 arg1);

    aiPath* OncomingPath;
    i32 EdgeIndex;
    i32 PathIndex;
    i16 VertexCount;
    i16 Id;
    i16 NumLanes;
    i16 NumSidewalks;
    i16 IntersectionType;
    i16 IsBlocked;
    i16 IsAlwaysBlocked;
    i16 IsPedBlocked;
    i16 IsDivided;
    i16 IsFlat;
    i16 IsAlley;
    i16 HasBridge;
    i16 StopLightIndex;
    i16 field_26;
    f32 RoadLength;
    f32 SpeedLimit;
    f32* SubSectionOffsets;
    f32* CenterOffsets;
    char StopLightName[32];
    aiIntersection* Sink;
    aiIntersection* Source;
    Vector3* LaneVertices;
    Vector3* CenterVerts;
    Vector3* VertXDirs;
    Vector3* Normals;
    Vector3* VertZDirs;
    Vector3* SubSectionDirs;
    Vector3* Boundaries;
    Vector3* LBoundaries;
    Vector3 StopLightPos[2];
    i16 NumVehicles[4];
    aiVehicleSpline* Splines[4];
    aiVehicleSpline* Vehicles[4];
    aiPedestrian* Peds;
    f32 LaneWidths[5];
    f32 LaneLengths[10];
    b16 AlwaysGo;
    b16 AlwaysStop;
};

check_size(aiPath, 0x104);
