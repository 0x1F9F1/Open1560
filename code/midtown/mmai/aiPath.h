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

class aiPath
{
public:
    // 0x43C390 | ??0aiPath@@QAE@H@Z
    aiPath(i32 arg1);

    // 0x43C3C0 | ??1aiPath@@QAE@XZ
    ~aiPath();

    // 0x43CFA0 | ?AddPathVerts@aiPath@@QAEXPAVVector3@@H@Z
    void AddPathVerts(class Vector3* arg1, i32 arg2);

    // 0x43C670 | ?AddPathVerts@aiPath@@QAEXAAVmmRoadSect@@HH@Z
    void AddPathVerts(class mmRoadSect& arg1, i32 arg2, i32 arg3);

    // 0x43FE80 | ?AddPedestrian@aiPath@@QAEXPAVaiPedestrian@@@Z
    void AddPedestrian(class aiPedestrian* arg1);

    // 0x43FB80 | ?AddVehicle@aiPath@@QAEXPAVaiVehicleSpline@@HM@Z
    void AddVehicle(class aiVehicleSpline* arg1, i32 arg2, f32 arg3);

    // 0x43E650 | ?AllwaysGo@aiPath@@QAEXH@Z
    void AllwaysGo(i32 arg1);

    // 0x43E4F0 | ?AllwaysStop@aiPath@@QAEXH@Z
    void AllwaysStop(i32 arg1);

    // 0x43F020 | ?AmbientCenterDistance@aiPath@@QAEXPAVaiVehicleSpline@@PAM111@Z
    void AmbientCenterDistance(class aiVehicleSpline* arg1, f32* arg2, f32* arg3, f32* arg4, f32* arg5);

    // 0x43FF30 | ?Blocked@aiPath@@QAEXH@Z
    void Blocked(i32 arg1);

    // 0x43D610 | ?CalcCenterVerts@aiPath@@QAEXAAVmmRoadSect@@H@Z
    void CalcCenterVerts(class mmRoadSect& arg1, i32 arg2);

    // 0x43ED00 | ?CenterDistance@aiPath@@QAEHAAVVector3@@PAFPAM2@Z
    i32 CenterDistance(class Vector3& arg1, i16* arg2, f32* arg3, f32* arg4);

    // 0x43E840 | ?CenterIndex@aiPath@@QAEHM@Z
    i32 CenterIndex(f32 arg1);

    // 0x43E670 | ?CenterLength@aiPath@@QAEMHH@Z
    f32 CenterLength(i32 arg1, i32 arg2);

    // 0x43E8E0 | ?CenterPosition@aiPath@@QAEXMAAVVector3@@@Z | unused
    void CenterPosition(f32 arg1, class Vector3& arg2);

    // 0x440020 | ?CenterVertice@aiPath@@QAEPAVVector3@@H@Z | inline
    class Vector3* CenterVertice(i32 arg1);

    // 0x43F9D0 | ?ContinuityError@aiPath@@QAEHH@Z | unused
    i32 ContinuityError(i32 arg1);

    // 0x43E0C0 | ?Draw@aiPath@@QAEXXZ
    void Draw();

    // 0x43E370 | ?DrawId@aiPath@@QAEXXZ
    void DrawId();

    // 0x43E280 | ?DrawNormals@aiPath@@QAEXXZ
    void DrawNormals();

    // 0x43E3E0 | ?DrawVehicleIds@aiPath@@QAEXXZ | unused
    void DrawVehicleIds();

    // 0x43E450 | ?Dump@aiPath@@QAEXXZ | unused
    void Dump();

    // 0x43E6B0 | ?GetHeading@aiPath@@QAEMMH@Z
    f32 GetHeading(f32 arg1, i32 arg2);

    // 0x43EA60 | ?Index@aiPath@@QAEHAAVVector3@@@Z
    i32 Index(class Vector3& arg1);

    // 0x43E9B0 | ?Index@aiPath@@QAEHMH@Z
    i32 Index(f32 arg1, i32 arg2);

    // 0x43F7D0 | ?IntersectionEntryPt@aiPath@@QAEXAAVVector3@@HM@Z
    void IntersectionEntryPt(class Vector3& arg1, i32 arg2, f32 arg3);

    // 0x43F890 | ?IntersectionEntryVector@aiPath@@QAEXAAVVector3@@M@Z
    void IntersectionEntryVector(class Vector3& arg1, f32 arg2);

    // 0x43F910 | ?IntersectionExitVector@aiPath@@QAEXAAVVector3@@M@Z
    void IntersectionExitVector(class Vector3& arg1, f32 arg2);

    // 0x459E90 | ?LBoundary@aiPath@@QAEPAVVector3@@H@Z | inline
    class Vector3* LBoundary(i32 arg1);

    // 0x43F980 | ?NumVehiclesAfterDist@aiPath@@QAEHHM@Z
    i32 NumVehiclesAfterDist(i32 arg1, f32 arg2);

    // 0x43FA30 | ?PopVehicle@aiPath@@QAEXPAVaiVehicleSpline@@H@Z
    void PopVehicle(class aiVehicleSpline* arg1, i32 arg2);

    // 0x43FB10 | ?PushVehicle@aiPath@@QAEXPAVaiVehicleSpline@@H@Z
    void PushVehicle(class aiVehicleSpline* arg1, i32 arg2);

    // 0x43DBC0 | ?ReadBinary@aiPath@@QAEXPAVStream@@@Z
    void ReadBinary(class Stream* arg1);

    // 0x43FEC0 | ?RemovePedestrian@aiPath@@QAEXPAVaiPedestrian@@@Z
    void RemovePedestrian(class aiPedestrian* arg1);

    // 0x43FCB0 | ?RemoveVehicle@aiPath@@QAEHPAVaiVehicleSpline@@H@Z
    i32 RemoveVehicle(class aiVehicleSpline* arg1, i32 arg2);

    // 0x43C450 | ?Reset@aiPath@@QAEXXZ
    void Reset();

    // 0x43C640 | ?ResetVehicleReactTicks@aiPath@@QAEXXZ
    void ResetVehicleReactTicks();

    // 0x43FDC0 | ?RoadCapacity@aiPath@@QAEHPAVaiVehicleSpline@@H@Z
    i32 RoadCapacity(class aiVehicleSpline* arg1, i32 arg2);

    // 0x43EB60 | ?RoadDistance@aiPath@@QAEXAAVVector3@@PAFPAMF2@Z
    void RoadDistance(class Vector3& arg1, i16* arg2, f32* arg3, i16 arg4, f32* arg5);

    // 0x43D950 | ?SaveBinary@aiPath@@QAEXPAVStream@@@Z
    void SaveBinary(class Stream* arg1);

    // 0x43E5D0 | ?StopDestinationSources@aiPath@@QAEXH@Z
    void StopDestinationSources(i32 arg1);

    // 0x43E510 | ?StopIncomingRoads@aiPath@@QAEXH@Z | unused
    void StopIncomingRoads(i32 arg1);

    // 0x43F780 | ?SubSectionDir@aiPath@@QAEXAAVVector3@@HHM@Z
    void SubSectionDir(class Vector3& arg1, i32 arg2, i32 arg3, f32 arg4);

    // 0x43E780 | ?SubSectionDist@aiPath@@QAEMMH@Z
    f32 SubSectionDist(f32 arg1, i32 arg2);

    // 0x43E690 | ?SubSectionLength@aiPath@@QAEMHH@Z
    f32 SubSectionLength(i32 arg1, i32 arg2);

    // 0x43F710 | ?SubSectionPt@aiPath@@QAEXAAVVector3@@HHM@Z
    void SubSectionPt(class Vector3& arg1, i32 arg2, i32 arg3, f32 arg4);

    // 0x43C490 | ?UpdateAmbients@aiPath@@QAEXXZ
    void UpdateAmbients();

    // 0x43C5A0 | ?UpdatePedestrians@aiPath@@QAEXXZ
    void UpdatePedestrians();

    // 0x43FF50 | ?VertXDir@aiPath@@QAEPAVVector3@@H@Z | inline
    class Vector3* VertXDir(i32 arg1);

    // 0x43FFD0 | ?VertZDir@aiPath@@QAEPAVVector3@@H@Z | inline
    class Vector3* VertZDir(i32 arg1);
};

check_size(aiPath, 0x104);
