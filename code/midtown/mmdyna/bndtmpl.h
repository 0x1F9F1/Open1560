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

#include "data7/pager.h"
#include "vector7/vector3.h"

/*
    mmdyna:bndtmpl

    0x51D2E0 | public: static class mmBoundTemplate * __cdecl mmBoundTemplate::GetBoundTemplate(char *,char *,class Vector3 *,int,int,int,int,int) | ?GetBoundTemplate@mmBoundTemplate@@SAPAV1@PAD0PAVVector3@@HHHHH@Z
    0x51D3F0 | public: static class mmBoundTemplate * __cdecl mmBoundTemplate::MakeBox(char *,char *,int,class Vector3 *,class Vector3 *) | ?MakeBox@mmBoundTemplate@@SAPAV1@PAD0HPAVVector3@@1@Z
    0x51D8F0 | public: void __thiscall mmBoundTemplate::AddRef(void) | ?AddRef@mmBoundTemplate@@QAEXXZ
    0x51D910 | public: int __thiscall mmBoundTemplate::Release(void) | ?Release@mmBoundTemplate@@QAEHXZ
    0x51D940 | public: void __thiscall mmBoundTemplate::ValidatePtr(char *) | ?ValidatePtr@mmBoundTemplate@@QAEXPAD@Z
    0x51D9A0 | public: __thiscall mmBoundTemplate::mmBoundTemplate(void) | ??0mmBoundTemplate@@QAE@XZ
    0x51DA60 | public: __thiscall mmBoundTemplate::~mmBoundTemplate(void) | ??1mmBoundTemplate@@QAE@XZ
    0x51DB20 | public: void __thiscall mmBoundTemplate::Reset(void) | ?Reset@mmBoundTemplate@@QAEXXZ
    0x51DB70 | public: int __thiscall mmBoundTemplate::Collide(class mmBoundTemplate *,class Matrix34 &,class Matrix34 &,class Matrix34 &,class mmEdgeBodyIsect *,int,int,class asInertialCS *,class asInertialCS *,class Vector3 *,class Vector3 *) | ?Collide@mmBoundTemplate@@QAEHPAV1@AAVMatrix34@@11PAVmmEdgeBodyIsect@@HHPAVasInertialCS@@3PAVVector3@@4@Z
    0x51E240 | public: int __thiscall mmBoundTemplate::CollideTerrains(class mmBoundTemplate * *,class Matrix34 &,class mmEdgeBodyIsect *,int,int) | ?CollideTerrains@mmBoundTemplate@@QAEHPAPAV1@AAVMatrix34@@PAVmmEdgeBodyIsect@@HH@Z
    0x51E4F0 | public: int __thiscall mmBoundTemplate::Collide(class mmEdgeBodyIsect *,int) | ?Collide@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@H@Z
    0x51E550 | public: int __thiscall mmBoundTemplate::Collide(class mmIntersection *) | ?Collide@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    0x51E620 | public: int __thiscall mmBoundTemplate::QuickSphereSphere(class mmIntersection *) | ?QuickSphereSphere@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    0x51E6C0 | public: int __thiscall mmBoundTemplate::QuickLineSphere(class mmEdgeBodyIsect *) | ?QuickLineSphere@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@@Z
    0x51E820 | public: int __thiscall mmBoundTemplate::QuickLineSphere(class mmIntersection *) | ?QuickLineSphere@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    0x51E940 | public: int __thiscall mmBoundTemplate::QuickSphereBox(class mmIntersection *) | ?QuickSphereBox@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    0x51EA00 | public: int __thiscall mmBoundTemplate::QuickLineBox(class mmEdgeBodyIsect *) | ?QuickLineBox@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@@Z
    0x51EAF0 | public: int __thiscall mmBoundTemplate::QuickLineBox(class mmIntersection *) | ?QuickLineBox@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    0x51EBE0 | public: int __thiscall mmBoundTemplate::SphereSphere(class mmIntersection *) | ?SphereSphere@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    0x51ED80 | public: int __thiscall mmBoundTemplate::SphereGeometry(class mmIntersection *) | ?SphereGeometry@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    0x51EEB0 | public: int __thiscall mmBoundTemplate::SphereTable(class mmIntersection *) | ?SphereTable@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    0x51F110 | public: int __thiscall mmBoundTemplate::LineSphere(class mmIntersection *) | ?LineSphere@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    0x51F120 | public: int __thiscall mmBoundTemplate::LineGeometry(class mmEdgeBodyIsect *,int) | ?LineGeometry@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@H@Z
    0x51F1E0 | public: int __thiscall mmBoundTemplate::LineTable(class mmEdgeBodyIsect *,int) | ?LineTable@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@H@Z
    0x51F500 | public: int __thiscall mmBoundTemplate::LineSpan(class mmEdgeBodyIsect *,int,int,int,int) | ?LineSpan@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@HHHH@Z
    0x51F670 | public: int __thiscall mmBoundTemplate::LineGeometry(class mmIntersection *) | ?LineGeometry@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    0x51F7A0 | public: int __thiscall mmBoundTemplate::LineTable(class mmIntersection *) | ?LineTable@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    0x51FB20 | public: int __thiscall mmBoundTemplate::LineSpan(class mmIntersection *,int,int,int) | ?LineSpan@mmBoundTemplate@@QAEHPAVmmIntersection@@HHH@Z
    0x51FCF0 | public: void __thiscall mmBoundTemplate::Draw(void) | ?Draw@mmBoundTemplate@@QAEXXZ
    0x51FD30 | public: void __thiscall mmBoundTemplate::DrawSphere(void) | ?DrawSphere@mmBoundTemplate@@QAEXXZ
    0x51FD70 | public: void __thiscall mmBoundTemplate::DrawBox(void) | ?DrawBox@mmBoundTemplate@@QAEXXZ
    0x51FD90 | public: void __thiscall mmBoundTemplate::DrawGeometry(void) | ?DrawGeometry@mmBoundTemplate@@QAEXXZ
    0x51FE00 | public: void __thiscall mmBoundTemplate::DrawTable(void) | ?DrawTable@mmBoundTemplate@@QAEXXZ
    0x520000 | public: void __thiscall mmBoundTemplate::DrawGraph(void) | ?DrawGraph@mmBoundTemplate@@QAEXXZ
    0x77F498 | public: static unsigned short * mmBoundTemplate::LastIsect | ?LastIsect@mmBoundTemplate@@2PAGA
    0x77F4A0 | int * * CollidedLines | ?CollidedLines@@3PAPAHA
    0x77F518 | int * InsideVerts | ?InsideVerts@@3PAHA
    0x77F590 | public: static unsigned short mmBoundTemplate::IsectCount | ?IsectCount@mmBoundTemplate@@2GA
    0x77F594 | public: static class Vector3 * mmBoundTemplate::VertPtr | ?VertPtr@mmBoundTemplate@@2PAVVector3@@A
    0x77F598 | public: static class mmBoundTemplate * mmBoundTemplate::BoundPtr | ?BoundPtr@mmBoundTemplate@@2PAV1@A
*/

class asInertialCS;
class mmEdgeBodyIsect;
class mmIntersection;
class mmPolygon;

class mmBoundTemplate
{
public:
    // ??0mmBoundTemplate@@QAE@XZ
    ARTS_IMPORT mmBoundTemplate();

    // ??1mmBoundTemplate@@QAE@XZ
    ARTS_IMPORT ~mmBoundTemplate();

    // ?AddIndex@mmBoundTemplate@@QAEXHHH@Z | mmdyna:bndtmpl2
    ARTS_IMPORT void AddIndex(i32 arg1, i32 arg2, i32 arg3);

    // ?AddQuad@mmBoundTemplate@@QAEXHHHHHH@Z | mmdyna:bndtmpl2
    ARTS_IMPORT void AddQuad(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6);

    // ?AddRef@mmBoundTemplate@@QAEXXZ
    ARTS_IMPORT void AddRef();

    // ?AddTriangle@mmBoundTemplate@@QAEXHHHHH@Z | mmdyna:bndtmpl2
    ARTS_IMPORT void AddTriangle(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5);

    // ?Collide@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    ARTS_IMPORT i32 Collide(mmIntersection* arg1);

    // ?Collide@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@H@Z
    ARTS_IMPORT i32 Collide(mmEdgeBodyIsect* arg1, i32 arg2);

    // ?Collide@mmBoundTemplate@@QAEHPAV1@AAVMatrix34@@11PAVmmEdgeBodyIsect@@HHPAVasInertialCS@@3PAVVector3@@4@Z
    ARTS_IMPORT i32 Collide(mmBoundTemplate* arg1, Matrix34& arg2, Matrix34& arg3, Matrix34& arg4,
        mmEdgeBodyIsect* arg5, i32 arg6, i32 arg7, asInertialCS* arg8, asInertialCS* arg9, Vector3* arg10,
        Vector3* arg11);

    // ?CollideTerrains@mmBoundTemplate@@QAEHPAPAV1@AAVMatrix34@@PAVmmEdgeBodyIsect@@HH@Z
    ARTS_IMPORT i32 CollideTerrains(mmBoundTemplate** arg1, Matrix34& arg2, mmEdgeBodyIsect* arg3, i32 arg4, i32 arg5);

    // ?ComputeBounds@mmBoundTemplate@@QAEXXZ | mmdyna:bndtmpl2
    ARTS_IMPORT void ComputeBounds();

    // ?ComputeEdgeNormals@mmBoundTemplate@@QAEXXZ | mmdyna:bndtmpl2
    ARTS_IMPORT void ComputeEdgeNormals();

    // ?ComputeEdges@mmBoundTemplate@@QAEXXZ | mmdyna:bndtmpl2
    ARTS_IMPORT void ComputeEdges();

#ifdef ARTS_DEV_BUILD
    // ?Draw@mmBoundTemplate@@QAEXXZ
    ARTS_IMPORT void Draw();

    // ?DrawBox@mmBoundTemplate@@QAEXXZ
    ARTS_IMPORT void DrawBox();

    // ?DrawGeometry@mmBoundTemplate@@QAEXXZ
    ARTS_IMPORT void DrawGeometry();

    // ?DrawGraph@mmBoundTemplate@@QAEXXZ | unused
    ARTS_EXPORT void DrawGraph();

    // ?DrawSphere@mmBoundTemplate@@QAEXXZ
    ARTS_IMPORT void DrawSphere();

    // ?DrawTable@mmBoundTemplate@@QAEXXZ
    ARTS_IMPORT void DrawTable();
#endif

    // ?InitGeometry@mmBoundTemplate@@QAEXHH@Z | mmdyna:bndtmpl2
    ARTS_IMPORT void InitGeometry(i32 arg1, i32 arg2);

    // ?LineGeometry@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    ARTS_IMPORT i32 LineGeometry(mmIntersection* arg1);

    // ?LineGeometry@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@H@Z
    ARTS_IMPORT i32 LineGeometry(mmEdgeBodyIsect* arg1, i32 arg2);

    // ?LineSpan@mmBoundTemplate@@QAEHPAVmmIntersection@@HHH@Z
    ARTS_IMPORT i32 LineSpan(mmIntersection* arg1, i32 arg2, i32 arg3, i32 arg4);

    // ?LineSpan@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@HHHH@Z
    ARTS_IMPORT i32 LineSpan(mmEdgeBodyIsect* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5);

    // ?LineSphere@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    ARTS_EXPORT i32 LineSphere(mmIntersection* arg1);

    // ?LineTable@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    ARTS_IMPORT i32 LineTable(mmIntersection* arg1);

    // ?LineTable@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@H@Z
    ARTS_IMPORT i32 LineTable(mmEdgeBodyIsect* arg1, i32 arg2);

    // ?Load@mmBoundTemplate@@QAEHPAD0PAVVector3@@HHHHHH@Z | mmdyna:bndtmpl2
    ARTS_IMPORT i32 Load(
        char* arg1, char* arg2, Vector3* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7, i32 arg8, i32 arg9);

    // ?LockIfResident@mmBoundTemplate@@QAEHXZ | mmdyna:bndtmpl2
    ARTS_IMPORT i32 LockIfResident();

    // ?PageIn@mmBoundTemplate@@QAEXXZ | mmdyna:bndtmpl2
    ARTS_IMPORT void PageIn();

    // ?PlotLine@mmBoundTemplate@@QAEXVVector3@@0@Z | mmdyna:bndtmpl2 | unused
    ARTS_IMPORT void PlotLine(Vector3 arg1, Vector3 arg2);

    // ?PlotSpan@mmBoundTemplate@@QAEXHHH@Z | mmdyna:bndtmpl2
    ARTS_EXPORT void PlotSpan(i32 arg1, i32 arg2, i32 arg3);

    // ?QuickLineBox@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@@Z
    ARTS_IMPORT i32 QuickLineBox(mmEdgeBodyIsect* arg1);

    // ?QuickLineBox@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    ARTS_IMPORT i32 QuickLineBox(mmIntersection* arg1);

    // ?QuickLineSphere@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@@Z
    ARTS_IMPORT i32 QuickLineSphere(mmEdgeBodyIsect* arg1);

    // ?QuickLineSphere@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    ARTS_IMPORT i32 QuickLineSphere(mmIntersection* arg1);

    // ?QuickSphereBox@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    ARTS_IMPORT i32 QuickSphereBox(mmIntersection* arg1);

    // ?QuickSphereSphere@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z | unused
    ARTS_IMPORT i32 QuickSphereSphere(mmIntersection* arg1);

    // ?Release@mmBoundTemplate@@QAEHXZ
    ARTS_IMPORT i32 Release();

    // ?Reset@mmBoundTemplate@@QAEXXZ | unused
    ARTS_IMPORT void Reset();

    // ?SphereGeometry@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    ARTS_IMPORT i32 SphereGeometry(mmIntersection* arg1);

    // ?SphereSphere@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    ARTS_IMPORT i32 SphereSphere(mmIntersection* arg1);

    // ?SphereTable@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    ARTS_IMPORT i32 SphereTable(mmIntersection* arg1);

    // ?Unlock@mmBoundTemplate@@QAEXXZ | mmdyna:bndtmpl2
    ARTS_IMPORT void Unlock();

    // ?ValidatePtr@mmBoundTemplate@@QAEXPAD@Z
    ARTS_IMPORT void ValidatePtr(char* arg1);

    // ?GetBoundTemplate@mmBoundTemplate@@SAPAV1@PAD0PAVVector3@@HHHHH@Z
    ARTS_IMPORT static mmBoundTemplate* GetBoundTemplate(
        char* arg1, char* arg2, Vector3* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7, i32 arg8);

    // ?MakeBox@mmBoundTemplate@@SAPAV1@PAD0HPAVVector3@@1@Z
    ARTS_IMPORT static mmBoundTemplate* MakeBox(char* arg1, char* arg2, i32 arg3, Vector3* arg4, Vector3* arg5);

    // ?BoundPtr@mmBoundTemplate@@2PAV1@A
    ARTS_IMPORT static mmBoundTemplate* BoundPtr;

    // ?ConstructionTable@mmBoundTemplate@@2PAGA | mmdyna:bndtmpl2
    ARTS_IMPORT static u16* ConstructionTable;

    // ?DrawGrid@mmBoundTemplate@@2HA | mmdyna:bndtmpl2
    ARTS_IMPORT static i32 DrawGrid;

    // ?IsectCount@mmBoundTemplate@@2GA
    ARTS_IMPORT static u16 IsectCount;

    // ?LastIsect@mmBoundTemplate@@2PAGA
    ARTS_IMPORT static u16* LastIsect;

    // ?MaxPerBucket@mmBoundTemplate@@2HA | mmdyna:bndtmpl2
    ARTS_IMPORT static i32 MaxPerBucket;

    // ?NumIndexs@mmBoundTemplate@@2HA | mmdyna:bndtmpl2
    ARTS_IMPORT static i32 NumIndexs;

    // ?VertPtr@mmBoundTemplate@@2PAVVector3@@A
    ARTS_IMPORT static Vector3* VertPtr;

    // ?WinID@mmBoundTemplate@@2HA | mmdyna:bndtmpl2
    ARTS_IMPORT static i32 WinID;

private:
    // ?DoMakeTable@mmBoundTemplate@@AAEXHHH@Z | mmdyna:bndtmpl2
    ARTS_IMPORT void DoMakeTable(i32 arg1, i32 arg2, i32 arg3);

    // ?DoPageIn@mmBoundTemplate@@AAEXXZ | mmdyna:bndtmpl2
    ARTS_IMPORT void DoPageIn();

    // ?MakeTable@mmBoundTemplate@@AAEXHHH@Z | mmdyna:bndtmpl2
    ARTS_IMPORT void MakeTable(i32 arg1, i32 arg2, i32 arg3);

    // ?PageInCallback@mmBoundTemplate@@CAXPAX@Z | mmdyna:bndtmpl2
    ARTS_IMPORT static void PageInCallback(void* arg1);

    // ?PageOutCallback@mmBoundTemplate@@CAXPAXH@Z | mmdyna:bndtmpl2
    ARTS_IMPORT static void PageOutCallback(void* arg1, i32 arg2);

    u32 RefCount;
    PagerInfo_t PagerInfo;
    i32 Handle;
    i32 PageState;
    Vector3 Center;
    f32 Radius;
    f32 RadiusSqr;
    Vector3 BBMin;
    Vector3 BBMax;
    u32 NumVerts;
    i32 NumPolys;
    Vector3* Verts;
    mmPolygon* Polygons;
    i32 NumHotVerts1;
    i32 NumHotVerts2;
    i32 NumEdges;
    Vector3* HotVerts;
    u32* EdgeVerts1;
    u32* EdgeVerts2;
    u16* field_70;
    u8* field_74;

    Vector3* EdgePlaneNs;
    f32* EdgePlaneDs;

    i32 XDim;
    b32 YDim;
    i32 ZDim;

    // Bucket = &RowBuckets[RowOffsets[z] + BucketOffsets[z * XDim + x]];
    // do {
    //     mmPolygon* poly = &Polygons[*Bucket & 0x7FFF];
    // } while (*Bucket++ < 0x8000);
    u32* RowOffsets;
    u16* BucketOffsets;
    u16* RowBuckets;

    u8* FixedHeights;
    f32 HeightScale;
    f32 XScale;
    f32 ZScale;
    u32 Flags;
    u32 field_AC;
    ConstString Name;
};

check_size(mmBoundTemplate, 0xB4);

// ?CollidedLines@@3PAPAHA
ARTS_IMPORT extern i32* CollidedLines[30];

// ?InsideVerts@@3PAHA
ARTS_IMPORT extern i32 InsideVerts[30];
