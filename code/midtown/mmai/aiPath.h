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
    mmai:aiPath

    0x43C390 | public: __thiscall aiPath::aiPath(int) | ??0aiPath@@QAE@H@Z
    0x43C3C0 | public: __thiscall aiPath::~aiPath(void) | ??1aiPath@@QAE@XZ
    0x43C450 | public: void __thiscall aiPath::Reset(void) | ?Reset@aiPath@@QAEXXZ
    0x43C490 | public: void __thiscall aiPath::UpdateAmbients(void) | ?UpdateAmbients@aiPath@@QAEXXZ
    0x43C5A0 | public: void __thiscall aiPath::UpdatePedestrians(void) | ?UpdatePedestrians@aiPath@@QAEXXZ
    0x43C640 | public: void __thiscall aiPath::ResetVehicleReactTicks(void) | ?ResetVehicleReactTicks@aiPath@@QAEXXZ
    0x43C670 | public: void __thiscall aiPath::AddPathVerts(class mmRoadSect &,int,int) | ?AddPathVerts@aiPath@@QAEXAAVmmRoadSect@@HH@Z
    0x43CFA0 | public: void __thiscall aiPath::AddPathVerts(class Vector3 *,int) | ?AddPathVerts@aiPath@@QAEXPAVVector3@@H@Z
    0x43D610 | public: void __thiscall aiPath::CalcCenterVerts(class mmRoadSect &,int) | ?CalcCenterVerts@aiPath@@QAEXAAVmmRoadSect@@H@Z
    0x43D950 | public: void __thiscall aiPath::SaveBinary(class Stream *) | ?SaveBinary@aiPath@@QAEXPAVStream@@@Z
    0x43DBC0 | public: void __thiscall aiPath::ReadBinary(class Stream *) | ?ReadBinary@aiPath@@QAEXPAVStream@@@Z
    0x43E0C0 | public: void __thiscall aiPath::Draw(void) | ?Draw@aiPath@@QAEXXZ
    0x43E280 | public: void __thiscall aiPath::DrawNormals(void) | ?DrawNormals@aiPath@@QAEXXZ
    0x43E370 | public: void __thiscall aiPath::DrawId(void) | ?DrawId@aiPath@@QAEXXZ
    0x43E3E0 | public: void __thiscall aiPath::DrawVehicleIds(void) | ?DrawVehicleIds@aiPath@@QAEXXZ
    0x43E450 | public: void __thiscall aiPath::Dump(void) | ?Dump@aiPath@@QAEXXZ
    0x43E4F0 | public: void __thiscall aiPath::AllwaysStop(int) | ?AllwaysStop@aiPath@@QAEXH@Z
    0x43E510 | public: void __thiscall aiPath::StopIncomingRoads(int) | ?StopIncomingRoads@aiPath@@QAEXH@Z
    0x43E5D0 | public: void __thiscall aiPath::StopDestinationSources(int) | ?StopDestinationSources@aiPath@@QAEXH@Z
    0x43E650 | public: void __thiscall aiPath::AllwaysGo(int) | ?AllwaysGo@aiPath@@QAEXH@Z
    0x43E670 | public: float __thiscall aiPath::CenterLength(int,int) | ?CenterLength@aiPath@@QAEMHH@Z
    0x43E690 | public: float __thiscall aiPath::SubSectionLength(int,int) | ?SubSectionLength@aiPath@@QAEMHH@Z
    0x43E6B0 | public: float __thiscall aiPath::GetHeading(float,int) | ?GetHeading@aiPath@@QAEMMH@Z
    0x43E780 | public: float __thiscall aiPath::SubSectionDist(float,int) | ?SubSectionDist@aiPath@@QAEMMH@Z
    0x43E840 | public: int __thiscall aiPath::CenterIndex(float) | ?CenterIndex@aiPath@@QAEHM@Z
    0x43E8E0 | public: void __thiscall aiPath::CenterPosition(float,class Vector3 &) | ?CenterPosition@aiPath@@QAEXMAAVVector3@@@Z
    0x43E9B0 | public: int __thiscall aiPath::Index(float,int) | ?Index@aiPath@@QAEHMH@Z
    0x43EA60 | public: int __thiscall aiPath::Index(class Vector3 &) | ?Index@aiPath@@QAEHAAVVector3@@@Z
    0x43EB60 | public: void __thiscall aiPath::RoadDistance(class Vector3 &,short *,float *,short,float *) | ?RoadDistance@aiPath@@QAEXAAVVector3@@PAFPAMF2@Z
    0x43ED00 | public: int __thiscall aiPath::CenterDistance(class Vector3 &,short *,float *,float *) | ?CenterDistance@aiPath@@QAEHAAVVector3@@PAFPAM2@Z
    0x43F020 | public: void __thiscall aiPath::AmbientCenterDistance(class aiVehicleSpline *,float *,float *,float *,float *) | ?AmbientCenterDistance@aiPath@@QAEXPAVaiVehicleSpline@@PAM111@Z
    0x43F710 | public: void __thiscall aiPath::SubSectionPt(class Vector3 &,int,int,float) | ?SubSectionPt@aiPath@@QAEXAAVVector3@@HHM@Z
    0x43F780 | public: void __thiscall aiPath::SubSectionDir(class Vector3 &,int,int,float) | ?SubSectionDir@aiPath@@QAEXAAVVector3@@HHM@Z
    0x43F7D0 | public: void __thiscall aiPath::IntersectionEntryPt(class Vector3 &,int,float) | ?IntersectionEntryPt@aiPath@@QAEXAAVVector3@@HM@Z
    0x43F890 | public: void __thiscall aiPath::IntersectionEntryVector(class Vector3 &,float) | ?IntersectionEntryVector@aiPath@@QAEXAAVVector3@@M@Z
    0x43F910 | public: void __thiscall aiPath::IntersectionExitVector(class Vector3 &,float) | ?IntersectionExitVector@aiPath@@QAEXAAVVector3@@M@Z
    0x43F980 | public: int __thiscall aiPath::NumVehiclesAfterDist(int,float) | ?NumVehiclesAfterDist@aiPath@@QAEHHM@Z
    0x43F9D0 | public: int __thiscall aiPath::ContinuityError(int) | ?ContinuityError@aiPath@@QAEHH@Z
    0x43FA30 | public: void __thiscall aiPath::PopVehicle(class aiVehicleSpline *,int) | ?PopVehicle@aiPath@@QAEXPAVaiVehicleSpline@@H@Z
    0x43FB10 | public: void __thiscall aiPath::PushVehicle(class aiVehicleSpline *,int) | ?PushVehicle@aiPath@@QAEXPAVaiVehicleSpline@@H@Z
    0x43FB80 | public: void __thiscall aiPath::AddVehicle(class aiVehicleSpline *,int,float) | ?AddVehicle@aiPath@@QAEXPAVaiVehicleSpline@@HM@Z
    0x43FCB0 | public: int __thiscall aiPath::RemoveVehicle(class aiVehicleSpline *,int) | ?RemoveVehicle@aiPath@@QAEHPAVaiVehicleSpline@@H@Z
    0x43FDC0 | public: int __thiscall aiPath::RoadCapacity(class aiVehicleSpline *,int) | ?RoadCapacity@aiPath@@QAEHPAVaiVehicleSpline@@H@Z
    0x43FE80 | public: void __thiscall aiPath::AddPedestrian(class aiPedestrian *) | ?AddPedestrian@aiPath@@QAEXPAVaiPedestrian@@@Z
    0x43FEC0 | public: void __thiscall aiPath::RemovePedestrian(class aiPedestrian *) | ?RemovePedestrian@aiPath@@QAEXPAVaiPedestrian@@@Z
    0x43FF30 | public: void __thiscall aiPath::Blocked(int) | ?Blocked@aiPath@@QAEXH@Z
    0x43FF50 | public: class Vector3 * __thiscall aiPath::VertXDir(int) | ?VertXDir@aiPath@@QAEPAVVector3@@H@Z
    0x43FFA0 | public: class Vector3 __thiscall Vector3::operator-(class Vector3 const &) const | ??GVector3@@QBE?AV0@ABV0@@Z
    0x43FFD0 | public: class Vector3 * __thiscall aiPath::VertZDir(int) | ?VertZDir@aiPath@@QAEPAVVector3@@H@Z
    0x440020 | public: class Vector3 * __thiscall aiPath::CenterVertice(int) | ?CenterVertice@aiPath@@QAEPAVVector3@@H@Z
*/

#include "vector7/vector3.h"

class aiIntersection;
class aiPedestrian;
class aiVehicleSpline;
class mmRoadSect;

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

    // ?CenterPosition@aiPath@@QAEXMAAVVector3@@@Z | unused
    ARTS_IMPORT void CenterPosition(f32 arg1, Vector3& arg2);

    // ?CenterVertice@aiPath@@QAEPAVVector3@@H@Z | inline
    ARTS_IMPORT Vector3* CenterVertice(i32 arg1);

    // ?ContinuityError@aiPath@@QAEHH@Z | unused
    ARTS_IMPORT i32 ContinuityError(i32 arg1);

#ifdef ARTS_DEV_BUILD
    // ?Draw@aiPath@@QAEXXZ
    ARTS_IMPORT void Draw();

    // ?DrawId@aiPath@@QAEXXZ
    ARTS_IMPORT void DrawId();

    // ?DrawNormals@aiPath@@QAEXXZ
    ARTS_IMPORT void DrawNormals();

    // ?DrawVehicleIds@aiPath@@QAEXXZ | unused
    ARTS_IMPORT void DrawVehicleIds();
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
    ARTS_IMPORT void StopDestinationSources(i32 arg1);

    // ?StopIncomingRoads@aiPath@@QAEXH@Z | unused
    ARTS_IMPORT void StopIncomingRoads(i32 arg1);

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
    i16 PathId;
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
    aiIntersection* Intersections[2];
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
