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

#include "vector7/vector3.h"

class mmBoundTemplate;
class mmEdgeBodyIsect;
class mmIntersection;

// A triangle or coplanar quad
class mmPolygon
{
public:
    // ??0mmPolygon@@QAE@XZ
    ARTS_IMPORT mmPolygon();

private:
    // ?CheckCellXSide@mmPolygon@@AAEMMMM@Z
    ARTS_EXPORT f32 CheckCellXSide(f32 x_plane, f32 z_min, f32 z_max);

    // ?CheckCellZSide@mmPolygon@@AAEMMMM@Z
    ARTS_EXPORT f32 CheckCellZSide(f32 z_plane, f32 x_min, f32 x_max);

    // ?CheckCorner@mmPolygon@@AAEMMMPAM00@Z
    ARTS_EXPORT f32 CheckCorner(f32 x, f32 z, f32* x_plane, f32* z_plane, f32* const_plane);

    // ?CornersHeight@mmPolygon@@AAEMMMMM@Z
    ARTS_EXPORT f32 CornersHeight(f32 x1, f32 z1, f32 x2, f32 z2);

#ifdef ARTS_DEV_BUILD
    // ?Draw@mmPolygon@@AAEXXZ
    ARTS_IMPORT void Draw();
#endif

    // ?FullSegment@mmPolygon@@AAEHPAVmmEdgeBodyIsect@@@Z
    ARTS_IMPORT i32 FullSegment(mmEdgeBodyIsect* arg1);

    // ?FullSegment@mmPolygon@@AAEHPAVmmIntersection@@@Z
    ARTS_IMPORT i32 FullSegment(mmIntersection* arg1);

    // ?FullSphere@mmPolygon@@AAEHPAVmmIntersection@@@Z
    ARTS_IMPORT i32 FullSphere(mmIntersection* arg1);

    // ?GetCorner@mmPolygon@@AAEHAAVVector3@@00000AAM@Z
    ARTS_IMPORT i32 GetCorner(
        Vector3& arg1, Vector3& arg2, Vector3& arg3, Vector3& arg4, Vector3& arg5, Vector3& arg6, f32& arg7);

    // ?GetST@mmPolygon@@AAEXPAVVector3@@0PAVmmBoundTemplate@@@Z | unused
    ARTS_IMPORT void GetST(Vector3* arg1, Vector3* arg2, mmBoundTemplate* arg3);

    // ?Init@mmPolygon@@AAEXXZ
    ARTS_IMPORT void Init();

    // ?MaxY@mmPolygon@@AAEMMMMM@Z
    ARTS_EXPORT f32 MaxY(f32 x_min, f32 z_min, f32 x_max, f32 z_max);

    // ?Plot@mmPolygon@@AAEXPAVmmBoundTemplate@@H@Z
    ARTS_EXPORT void Plot(mmBoundTemplate* t, i32 poly_index);

    // ?PlotScan@mmPolygon@@AAEXHHHPAVmmBoundTemplate@@H@Z
    ARTS_EXPORT void PlotScan(i32 x1, i32 x2, i32 z, mmBoundTemplate* t, i32 poly_index);

    // ?PlotTriangle@mmPolygon@@AAEXHHHPAVmmBoundTemplate@@H@Z
    ARTS_IMPORT void PlotTriangle(i32 arg1, i32 arg2, i32 arg3, mmBoundTemplate* arg4, i32 arg5);

public:
    u16 RoomId;
    u8 MtlIndex;

    // Flags & 0x3:
    // 0x0: PlaneEdges are projected along X axis
    // 0x1: PlaneEdges are projected along Z axis
    // 0x2: PlaneEdges are projected along Y axis

    // 0x4: Is Quad
    // 0x8: Flip Winding?
    u8 Flags;
    i16 VertIndices[4];

    // Equations of the 2D lines representing the edges of the polygon
    // The lines are projected from the 3D plane onto an orthoganal 2D plane
    Vector3 PlaneEdges[4];

    // Equation of the 3D plane which the polygon exists on
    // d = PlaneN * PointQ + PlaneD
    Vector3 PlaneN;
    f32 PlaneD;
};

check_size(mmPolygon, 0x4C);
