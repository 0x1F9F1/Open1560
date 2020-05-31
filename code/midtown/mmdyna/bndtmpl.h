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

class mmBoundTemplate
{
public:
    // 0x51D9A0 | ??0mmBoundTemplate@@QAE@XZ
    mmBoundTemplate();

    // 0x51DA60 | ??1mmBoundTemplate@@QAE@XZ
    ~mmBoundTemplate();

    // 0x519F70 | ?AddIndex@mmBoundTemplate@@QAEXHHH@Z | mmdyna:bndtmpl2
    void AddIndex(i32 arg1, i32 arg2, i32 arg3);

    // 0x517370 | ?AddQuad@mmBoundTemplate@@QAEXHHHHHH@Z | mmdyna:bndtmpl2
    void AddQuad(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6);

    // 0x51D8F0 | ?AddRef@mmBoundTemplate@@QAEXXZ
    void AddRef();

    // 0x517280 | ?AddTriangle@mmBoundTemplate@@QAEXHHHHH@Z | mmdyna:bndtmpl2
    void AddTriangle(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5);

    // 0x51E550 | ?Collide@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    i32 Collide(class mmIntersection* arg1);

    // 0x51E4F0 | ?Collide@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@H@Z
    i32 Collide(class mmEdgeBodyIsect* arg1, i32 arg2);

    // 0x51DB70 | ?Collide@mmBoundTemplate@@QAEHPAV1@AAVMatrix34@@11PAVmmEdgeBodyIsect@@HHPAVasInertialCS@@3PAVVector3@@4@Z
    i32 Collide(class mmBoundTemplate* arg1, class Matrix34& arg2, class Matrix34& arg3, class Matrix34& arg4,
        class mmEdgeBodyIsect* arg5, i32 arg6, i32 arg7, class asInertialCS* arg8, class asInertialCS* arg9,
        class Vector3* arg10, class Vector3* arg11);

    // 0x51E240 | ?CollideTerrains@mmBoundTemplate@@QAEHPAPAV1@AAVMatrix34@@PAVmmEdgeBodyIsect@@HH@Z
    i32 CollideTerrains(
        class mmBoundTemplate** arg1, class Matrix34& arg2, class mmEdgeBodyIsect* arg3, i32 arg4, i32 arg5);

    // 0x5175E0 | ?ComputeBounds@mmBoundTemplate@@QAEXXZ | mmdyna:bndtmpl2
    void ComputeBounds();

    // 0x5193A0 | ?ComputeEdgeNormals@mmBoundTemplate@@QAEXXZ | mmdyna:bndtmpl2
    void ComputeEdgeNormals();

    // 0x517680 | ?ComputeEdges@mmBoundTemplate@@QAEXXZ | mmdyna:bndtmpl2
    void ComputeEdges();

    // 0x51FCF0 | ?Draw@mmBoundTemplate@@QAEXXZ
    void Draw();

    // 0x51FD70 | ?DrawBox@mmBoundTemplate@@QAEXXZ
    void DrawBox();

    // 0x51FD90 | ?DrawGeometry@mmBoundTemplate@@QAEXXZ
    void DrawGeometry();

    // 0x520000 | ?DrawGraph@mmBoundTemplate@@QAEXXZ | unused
    void DrawGraph();

    // 0x51FD30 | ?DrawSphere@mmBoundTemplate@@QAEXXZ
    void DrawSphere();

    // 0x51FE00 | ?DrawTable@mmBoundTemplate@@QAEXXZ
    void DrawTable();

    // 0x5171D0 | ?InitGeometry@mmBoundTemplate@@QAEXHH@Z | mmdyna:bndtmpl2
    void InitGeometry(i32 arg1, i32 arg2);

    // 0x51F670 | ?LineGeometry@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    i32 LineGeometry(class mmIntersection* arg1);

    // 0x51F120 | ?LineGeometry@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@H@Z
    i32 LineGeometry(class mmEdgeBodyIsect* arg1, i32 arg2);

    // 0x51FB20 | ?LineSpan@mmBoundTemplate@@QAEHPAVmmIntersection@@HHH@Z
    i32 LineSpan(class mmIntersection* arg1, i32 arg2, i32 arg3, i32 arg4);

    // 0x51F500 | ?LineSpan@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@HHHH@Z
    i32 LineSpan(class mmEdgeBodyIsect* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5);

    // 0x51F110 | ?LineSphere@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    i32 LineSphere(class mmIntersection* arg1);

    // 0x51F7A0 | ?LineTable@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    i32 LineTable(class mmIntersection* arg1);

    // 0x51F1E0 | ?LineTable@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@H@Z
    i32 LineTable(class mmEdgeBodyIsect* arg1, i32 arg2);

    // 0x517850 | ?Load@mmBoundTemplate@@QAEHPAD0PAVVector3@@HHHHHH@Z | mmdyna:bndtmpl2
    i32 Load(char* arg1, char* arg2, class Vector3* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7, i32 arg8, i32 arg9);

    // 0x519320 | ?LockIfResident@mmBoundTemplate@@QAEHXZ | mmdyna:bndtmpl2
    i32 LockIfResident();

    // 0x519300 | ?PageIn@mmBoundTemplate@@QAEXXZ | mmdyna:bndtmpl2
    void PageIn();

    // 0x51A090 | ?PlotLine@mmBoundTemplate@@QAEXVVector3@@0@Z | mmdyna:bndtmpl2 | unused
    void PlotLine(class Vector3 arg1, class Vector3 arg2);

    // 0x51A1A0 | ?PlotSpan@mmBoundTemplate@@QAEXHHH@Z | mmdyna:bndtmpl2
    void PlotSpan(i32 arg1, i32 arg2, i32 arg3);

    // 0x51EA00 | ?QuickLineBox@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@@Z
    i32 QuickLineBox(class mmEdgeBodyIsect* arg1);

    // 0x51EAF0 | ?QuickLineBox@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    i32 QuickLineBox(class mmIntersection* arg1);

    // 0x51E6C0 | ?QuickLineSphere@mmBoundTemplate@@QAEHPAVmmEdgeBodyIsect@@@Z
    i32 QuickLineSphere(class mmEdgeBodyIsect* arg1);

    // 0x51E820 | ?QuickLineSphere@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    i32 QuickLineSphere(class mmIntersection* arg1);

    // 0x51E940 | ?QuickSphereBox@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    i32 QuickSphereBox(class mmIntersection* arg1);

    // 0x51E620 | ?QuickSphereSphere@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z | unused
    i32 QuickSphereSphere(class mmIntersection* arg1);

    // 0x51D910 | ?Release@mmBoundTemplate@@QAEHXZ
    i32 Release();

    // 0x51DB20 | ?Reset@mmBoundTemplate@@QAEXXZ | unused
    void Reset();

    // 0x51ED80 | ?SphereGeometry@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    i32 SphereGeometry(class mmIntersection* arg1);

    // 0x51EBE0 | ?SphereSphere@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    i32 SphereSphere(class mmIntersection* arg1);

    // 0x51EEB0 | ?SphereTable@mmBoundTemplate@@QAEHPAVmmIntersection@@@Z
    i32 SphereTable(class mmIntersection* arg1);

    // 0x519380 | ?Unlock@mmBoundTemplate@@QAEXXZ | mmdyna:bndtmpl2
    void Unlock();

    // 0x51D940 | ?ValidatePtr@mmBoundTemplate@@QAEXPAD@Z
    void ValidatePtr(char* arg1);

    // 0x51D2E0 | ?GetBoundTemplate@mmBoundTemplate@@SAPAV1@PAD0PAVVector3@@HHHHH@Z
    static class mmBoundTemplate* GetBoundTemplate(
        char* arg1, char* arg2, class Vector3* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7, i32 arg8);

    // 0x51D3F0 | ?MakeBox@mmBoundTemplate@@SAPAV1@PAD0HPAVVector3@@1@Z
    static class mmBoundTemplate* MakeBox(char* arg1, char* arg2, i32 arg3, class Vector3* arg4, class Vector3* arg5);

    // 0x77F598 | ?BoundPtr@mmBoundTemplate@@2PAV1@A
    static inline extern_var(0x77F598, class mmBoundTemplate*, BoundPtr);

    // 0x77EED0 | ?ConstructionTable@mmBoundTemplate@@2PAGA | mmdyna:bndtmpl2
    static inline extern_var(0x77EED0, u16*, ConstructionTable);

    // 0x77EE48 | ?DrawGrid@mmBoundTemplate@@2HA | mmdyna:bndtmpl2
    static inline extern_var(0x77EE48, i32, DrawGrid);

    // 0x77F590 | ?IsectCount@mmBoundTemplate@@2GA
    static inline extern_var(0x77F590, u16, IsectCount);

    // 0x77F498 | ?LastIsect@mmBoundTemplate@@2PAGA
    static inline extern_var(0x77F498, u16*, LastIsect);

    // 0x77EED4 | ?MaxPerBucket@mmBoundTemplate@@2HA | mmdyna:bndtmpl2
    static inline extern_var(0x77EED4, i32, MaxPerBucket);

    // 0x77EE3C | ?NumIndexs@mmBoundTemplate@@2HA | mmdyna:bndtmpl2
    static inline extern_var(0x77EE3C, i32, NumIndexs);

    // 0x77F594 | ?VertPtr@mmBoundTemplate@@2PAVVector3@@A
    static inline extern_var(0x77F594, class Vector3*, VertPtr);

    // 0x77EE38 | ?WinID@mmBoundTemplate@@2HA | mmdyna:bndtmpl2
    static inline extern_var(0x77EE38, i32, WinID);

private:
    // 0x519A30 | ?DoMakeTable@mmBoundTemplate@@AAEXHHH@Z | mmdyna:bndtmpl2
    void DoMakeTable(i32 arg1, i32 arg2, i32 arg3);

    // 0x518E90 | ?DoPageIn@mmBoundTemplate@@AAEXXZ | mmdyna:bndtmpl2
    void DoPageIn();

    // 0x519830 | ?MakeTable@mmBoundTemplate@@AAEXHHH@Z | mmdyna:bndtmpl2
    void MakeTable(i32 arg1, i32 arg2, i32 arg3);

    // 0x5192F0 | ?PageInCallback@mmBoundTemplate@@CAXPAX@Z | mmdyna:bndtmpl2
    static void PageInCallback(void* arg1);

    // 0x518D40 | ?PageOutCallback@mmBoundTemplate@@CAXPAXH@Z | mmdyna:bndtmpl2
    static void PageOutCallback(void* arg1, i32 arg2);
};

check_size(mmBoundTemplate, 0xB4);

// 0x77F4A0 | ?CollidedLines@@3PAPAHA
inline extern_var(0x77F4A0, i32**, CollidedLines);

// 0x77F518 | ?InsideVerts@@3PAHA
inline extern_var(0x77F518, i32*, InsideVerts);
