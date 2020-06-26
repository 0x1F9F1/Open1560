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
    mmdyna:poly

    0x51A7E0 | public: __thiscall mmPolygon::mmPolygon(void) | ??0mmPolygon@@QAE@XZ
    0x51A820 | private: void __thiscall mmPolygon::Init(void) | ?Init@mmPolygon@@AAEXXZ
    0x51ADA0 | private: void __thiscall mmPolygon::GetST(class Vector3 *,class Vector3 *,class mmBoundTemplate *) | ?GetST@mmPolygon@@AAEXPAVVector3@@0PAVmmBoundTemplate@@@Z
    0x51AEB0 | private: int __thiscall mmPolygon::FullSegment(class mmEdgeBodyIsect *) | ?FullSegment@mmPolygon@@AAEHPAVmmEdgeBodyIsect@@@Z
    0x51B440 | private: int __thiscall mmPolygon::FullSegment(class mmIntersection *) | ?FullSegment@mmPolygon@@AAEHPAVmmIntersection@@@Z
    0x51B990 | private: int __thiscall mmPolygon::GetCorner(class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &,float &) | ?GetCorner@mmPolygon@@AAEHAAVVector3@@00000AAM@Z
    0x51BC80 | private: int __thiscall mmPolygon::FullSphere(class mmIntersection *) | ?FullSphere@mmPolygon@@AAEHPAVmmIntersection@@@Z
    0x51C2A0 | private: void __thiscall mmPolygon::Draw(void) | ?Draw@mmPolygon@@AAEXXZ
    0x51C320 | private: void __thiscall mmPolygon::Plot(class mmBoundTemplate *,int) | ?Plot@mmPolygon@@AAEXPAVmmBoundTemplate@@H@Z
    0x51C380 | private: void __thiscall mmPolygon::PlotTriangle(int,int,int,class mmBoundTemplate *,int) | ?PlotTriangle@mmPolygon@@AAEXHHHPAVmmBoundTemplate@@H@Z
    0x51CBD0 | private: void __thiscall mmPolygon::PlotScan(int,int,int,class mmBoundTemplate *,int) | ?PlotScan@mmPolygon@@AAEXHHHPAVmmBoundTemplate@@H@Z
    0x51CC60 | private: float __thiscall mmPolygon::MaxY(float,float,float,float) | ?MaxY@mmPolygon@@AAEMMMMM@Z
    0x51CDB0 | private: float __thiscall mmPolygon::CornersHeight(float,float,float,float) | ?CornersHeight@mmPolygon@@AAEMMMMM@Z
    0x51CFD0 | private: float __thiscall mmPolygon::CheckCorner(float,float,float *,float *,float *) | ?CheckCorner@mmPolygon@@AAEMMMPAM00@Z
    0x51D080 | private: float __thiscall mmPolygon::CheckCellXSide(float,float,float) | ?CheckCellXSide@mmPolygon@@AAEMMMM@Z
    0x51D170 | private: float __thiscall mmPolygon::CheckCellZSide(float,float,float) | ?CheckCellZSide@mmPolygon@@AAEMMMM@Z
*/

class mmPolygon
{
public:
    // 0x51A7E0 | ??0mmPolygon@@QAE@XZ
    ARTS_IMPORT mmPolygon();

private:
    // 0x51D080 | ?CheckCellXSide@mmPolygon@@AAEMMMM@Z
    ARTS_IMPORT f32 CheckCellXSide(f32 arg1, f32 arg2, f32 arg3);

    // 0x51D170 | ?CheckCellZSide@mmPolygon@@AAEMMMM@Z
    ARTS_IMPORT f32 CheckCellZSide(f32 arg1, f32 arg2, f32 arg3);

    // 0x51CFD0 | ?CheckCorner@mmPolygon@@AAEMMMPAM00@Z
    ARTS_IMPORT f32 CheckCorner(f32 arg1, f32 arg2, f32* arg3, f32* arg4, f32* arg5);

    // 0x51CDB0 | ?CornersHeight@mmPolygon@@AAEMMMMM@Z
    ARTS_IMPORT f32 CornersHeight(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x51C2A0 | ?Draw@mmPolygon@@AAEXXZ
    ARTS_IMPORT void Draw();

    // 0x51AEB0 | ?FullSegment@mmPolygon@@AAEHPAVmmEdgeBodyIsect@@@Z
    ARTS_IMPORT i32 FullSegment(class mmEdgeBodyIsect* arg1);

    // 0x51B440 | ?FullSegment@mmPolygon@@AAEHPAVmmIntersection@@@Z
    ARTS_IMPORT i32 FullSegment(class mmIntersection* arg1);

    // 0x51BC80 | ?FullSphere@mmPolygon@@AAEHPAVmmIntersection@@@Z
    ARTS_IMPORT i32 FullSphere(class mmIntersection* arg1);

    // 0x51B990 | ?GetCorner@mmPolygon@@AAEHAAVVector3@@00000AAM@Z
    ARTS_IMPORT i32 GetCorner(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4,
        class Vector3& arg5, class Vector3& arg6, f32& arg7);

    // 0x51ADA0 | ?GetST@mmPolygon@@AAEXPAVVector3@@0PAVmmBoundTemplate@@@Z | unused
    ARTS_IMPORT void GetST(class Vector3* arg1, class Vector3* arg2, class mmBoundTemplate* arg3);

    // 0x51A820 | ?Init@mmPolygon@@AAEXXZ
    ARTS_IMPORT void Init();

    // 0x51CC60 | ?MaxY@mmPolygon@@AAEMMMMM@Z
    ARTS_IMPORT f32 MaxY(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x51C320 | ?Plot@mmPolygon@@AAEXPAVmmBoundTemplate@@H@Z
    ARTS_IMPORT void Plot(class mmBoundTemplate* arg1, i32 arg2);

    // 0x51CBD0 | ?PlotScan@mmPolygon@@AAEXHHHPAVmmBoundTemplate@@H@Z
    ARTS_IMPORT void PlotScan(i32 arg1, i32 arg2, i32 arg3, class mmBoundTemplate* arg4, i32 arg5);

    // 0x51C380 | ?PlotTriangle@mmPolygon@@AAEXHHHPAVmmBoundTemplate@@H@Z
    ARTS_IMPORT void PlotTriangle(i32 arg1, i32 arg2, i32 arg3, class mmBoundTemplate* arg4, i32 arg5);
};

check_size(mmPolygon, 0x4C);
