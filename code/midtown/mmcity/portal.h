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
    mmcity:portal

    0x4957E0 | public: struct asPortalCell * __thiscall asPortalWeb::AddCell(char *,class asPortalRenderable *,unsigned int) | ?AddCell@asPortalWeb@@QAEPAUasPortalCell@@PADPAVasPortalRenderable@@I@Z
    0x495830 | public: void __thiscall asPortalWeb::DeleteCell(struct asPortalCell *) | ?DeleteCell@asPortalWeb@@QAEXPAUasPortalCell@@@Z
    0x4958E0 | public: struct asPortalEdge * __thiscall asPortalWeb::AddEdge(char *,struct asPortalCell *,struct asPortalCell *,int) | ?AddEdge@asPortalWeb@@QAEPAUasPortalEdge@@PADPAUasPortalCell@@1H@Z
    0x4959A0 | public: void __thiscall asPortalWeb::DeleteEdge(struct asPortalEdge *) | ?DeleteEdge@asPortalWeb@@QAEXPAUasPortalEdge@@@Z
    0x4959B0 | struct asPortalCell * __cdecl LookupCell(char *) | ?LookupCell@@YAPAUasPortalCell@@PAD@Z
    0x4959C0 | struct asPortalCell * __cdecl LookupEdge(char *) | ?LookupEdge@@YAPAUasPortalCell@@PAD@Z
    0x4959D0 | public: void __thiscall asPortalPVS::Init(int,int) | ?Init@asPortalPVS@@QAEXHH@Z
    0x495A30 | public: static struct asPortalPVS * __cdecl asPortalPVS::Create(int,...) | ?Create@asPortalPVS@@SAPAU1@HZZ
    0x495AB0 | public: void __thiscall asPortalPVS::SetVisible(unsigned int) | ?SetVisible@asPortalPVS@@QAEXI@Z
    0x495AE0 | public: __thiscall asPortalWeb::asPortalWeb(void) | ??0asPortalWeb@@QAE@XZ
    0x495B70 | public: int __thiscall asPortalWeb::BuildVisibilityList(class Matrix34 &,struct asPortalCell * *,int,float) | ?BuildVisibilityList@asPortalWeb@@QAEHAAVMatrix34@@PAPAUasPortalCell@@HM@Z
    0x495DD0 | public: int __thiscall asPortalWeb::BuildVisibilityList(class Vector3 &,struct asPortalCell * *,int,float) | ?BuildVisibilityList@asPortalWeb@@QAEHAAVVector3@@PAPAUasPortalCell@@HM@Z
    0x495EE0 | public: virtual void __thiscall asPortalWeb::Update(void) | ?Update@asPortalWeb@@UAEXXZ
    0x4969F0 | public: void __thiscall asPortalWeb::BuildGroups(void) | ?BuildGroups@asPortalWeb@@QAEXXZ
    0x496FE0 | public: void __thiscall asPortalWeb::Cull(int) | ?Cull@asPortalWeb@@QAEXH@Z
    0x497400 | public: void __thiscall asPortalWeb::Stats(void) | ?Stats@asPortalWeb@@QAEXXZ
    0x4974C0 | public: virtual __thiscall asPortalWeb::~asPortalWeb(void) | ??1asPortalWeb@@UAE@XZ
    0x497530 | public: void __thiscall asPortalWeb::LockTarget(void) | ?LockTarget@asPortalWeb@@QAEXXZ
    0x497540 | public: virtual void __thiscall asPortalWeb::AddWidgets(class Bank *) | ?AddWidgets@asPortalWeb@@UAEXPAVBank@@@Z
    0x4976D0 | public: static void __cdecl asPortalWeb::DeclareFields(void) | ?DeclareFields@asPortalWeb@@SAXXZ
    0x497770 | public: virtual class MetaClass * __thiscall asPortalWeb::GetClass(void) | ?GetClass@asPortalWeb@@UAEPAVMetaClass@@XZ
    0x497780 | public: virtual void * __thiscall asPortalWeb::`scalar deleting destructor'(unsigned int) | ??_GasPortalWeb@@UAEPAXI@Z
    0x497780 | public: virtual void * __thiscall asPortalWeb::`vector deleting destructor'(unsigned int) | ??_EasPortalWeb@@UAEPAXI@Z
    0x4977B0 | public: __thiscall asPortalEdge::asPortalEdge(struct asPortalCell *,struct asPortalCell *,int) | ??0asPortalEdge@@QAE@PAUasPortalCell@@0H@Z
    0x61D1E0 | const asPortalWeb::`vftable' | ??_7asPortalWeb@@6B@
    0x705714 | public: static unsigned short asPortalWeb::VisitTag | ?VisitTag@asPortalWeb@@2GA
    0x705718 | class MetaClass asPortalWebMetaClass | ?asPortalWebMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"
#include "vector7/vector4.h"

struct asPortalCell;
struct asPortalEdge;
class asPortalRenderable;
class mmPolygon;
class agiTexDef;

struct asPortalView
{
    f32 X;
    f32 Y;
    f32 Width;
    f32 Height;
    f32 ProjX;
    f32 ProjY;
    f32 ProjXZ;
    f32 ProjYZ;
    f32 ProjLeft;
    f32 ProjTop;
    f32 ProjRight;
    f32 ProjBottom;
    f32 ProjWidth;
    f32 ProjHeight;

    asPortalCell* Cell;
    asPortalEdge* Edge;
    agiTexDef* Texture;
    i32 RenderDepth;
};

check_size(asPortalView, 0x48);

struct asPortalCell
{
    struct PortalLink* Edges;
    asPortalRenderable* CellRenderer;
    asPortalCell* Next;
    u16 VisitTag;
    u16 CellIndex;
    u16 NumPtlPaths;
    u16 Flags;
    struct PtlPath** PtlPaths;
};

check_size(asPortalCell, 0x18);

class asPortalWeb : public asNode
{
public:
    // ??0asPortalWeb@@QAE@XZ
    ARTS_IMPORT asPortalWeb();

    // ??_EasPortalWeb@@UAEPAXI@Z
    // ??_GasPortalWeb@@UAEPAXI@Z
    // ??1asPortalWeb@@UAE@XZ
    ARTS_IMPORT ~asPortalWeb() override;

    virtual asPortalCell* GetStartCell(Vector3& arg1, asPortalCell* arg2, mmPolygon** arg3) = 0;

    // ?AddCell@asPortalWeb@@QAEPAUasPortalCell@@PADPAVasPortalRenderable@@I@Z
    ARTS_IMPORT asPortalCell* AddCell(char* arg1, asPortalRenderable* arg2, u32 arg3);

    // ?AddEdge@asPortalWeb@@QAEPAUasPortalEdge@@PADPAUasPortalCell@@1H@Z
    ARTS_IMPORT asPortalEdge* AddEdge(char* arg1, asPortalCell* arg2, asPortalCell* arg3, i32 arg4);

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asPortalWeb@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?BuildGroups@asPortalWeb@@QAEXXZ
    ARTS_IMPORT void BuildGroups();

#ifdef ARTS_DEV_BUILD
    // ?BuildVisibilityList@asPortalWeb@@QAEHAAVMatrix34@@PAPAUasPortalCell@@HM@Z
    ARTS_IMPORT i32 BuildVisibilityList(Matrix34& arg1, asPortalCell** arg2, i32 arg3, f32 arg4);

    // ?BuildVisibilityList@asPortalWeb@@QAEHAAVVector3@@PAPAUasPortalCell@@HM@Z
    ARTS_IMPORT i32 BuildVisibilityList(Vector3& arg1, asPortalCell** arg2, i32 arg3, f32 arg4);
#endif

    // ?Cull@asPortalWeb@@QAEXH@Z
    ARTS_EXPORT void Cull(b32 front_to_back);

    // ?DeleteCell@asPortalWeb@@QAEXPAUasPortalCell@@@Z | unused
    ARTS_IMPORT void DeleteCell(asPortalCell* arg1);

    // ?DeleteEdge@asPortalWeb@@QAEXPAUasPortalEdge@@@Z | unused
    ARTS_EXPORT void DeleteEdge(asPortalEdge* arg1);

    // ?GetClass@asPortalWeb@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

#ifdef ARTS_DEV_BUILD
    // ?LockTarget@asPortalWeb@@QAEXXZ
    ARTS_IMPORT void LockTarget();
#endif

#ifdef ARTS_DEV_BUILD
    // ?Stats@asPortalWeb@@QAEXXZ
    ARTS_IMPORT void Stats();
#endif

    // ?Update@asPortalWeb@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@asPortalWeb@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // ?VisitTag@asPortalWeb@@2GA
    ARTS_IMPORT static u16 VisitTag;

    b32 DisableTextures;
    i32 MaxRenderDepth;
    asPortalCell* CellList;
    asPortalCell* StartCell;
    asPortalEdge* Edges;
    b32 Debug;
    b32 SubClip;
    b32 NoPortals;

    // 0 = Main
    // 1 = Mirror
    u32 CurrentGroup;
    i32 NumSubPortals[2];
    asPortalView Portals[2][256];
};

check_size(asPortalWeb, 0x904C);

// ?LookupCell@@YAPAUasPortalCell@@PAD@Z | unused
ARTS_EXPORT asPortalCell* LookupCell(char* arg1);

// ?LookupEdge@@YAPAUasPortalCell@@PAD@Z | unused
ARTS_EXPORT asPortalCell* LookupEdge(char* arg1);

struct asPortalPVS
{
public:
    // ?Init@asPortalPVS@@QAEXHH@Z
    ARTS_IMPORT void Init(i32 arg1, i32 arg2);

    // ?SetVisible@asPortalPVS@@QAEXI@Z
    ARTS_IMPORT void SetVisible(u32 arg1);

    // ?Create@asPortalPVS@@SAPAU1@HZZ | unused
    ARTS_IMPORT static asPortalPVS* Create(i32 arg1, ...);

    u8 gap0[0x8];
};

check_size(asPortalPVS, 0x8);

struct asPortalEdge
{
public:
    // ??0asPortalEdge@@QAE@PAUasPortalCell@@0H@Z | inline
    ARTS_IMPORT asPortalEdge(asPortalCell* arg1, asPortalCell* arg2, i32 arg3);

    enum : u8
    {
        Flags_Enabled = 1 << 0,

        // Reset all clipping
        Flags_Open = 1 << 1,

        // Reset MinX or MaxX clipping depending on cell visit direction
        Flags_SemiOpen = 1 << 2,

        // Hide if EyePos is infront/behind the plane, depending on cell visit direction
        Flags_Flag8 = 1 << 3,

        // These appear to be unused by the game, but are used by the PTL file.
        // They seem to be related to which sides of the portal are open/closed
        Flags_Flag10 = 1 << 4,
        Flags_Flag20 = 1 << 5,
        Flags_Flag40 = 1 << 6,
        Flags_Flag80 = 1 << 7,
    };

    u8 Flags;
    u8 NumEdges;
    u16 VisitTag;

    // *Edges++ = Vector3(min.x, min.y + height, min.z);
    // *Edges++ = Vector3(max.x, max.y + height, max.z);
    // *Edges++ = Vector3(max.x, max.y         , max.z);
    // if (EdgeCount == 3) *Edges++ = ExtraEdge;
    // *Edges++ = Vector3(min.x, min.y         , min.z);
    Vector3* Edges;
    asPortalCell* Cell1;
    asPortalCell* Cell2;
    Vector4 Plane;
    agiTexDef* Texture;
    asPortalEdge* Next;
    f32 PlaneDist;

    Vector3* Groups; // Vector3[4]
};

check_size(asPortalEdge, 0x30);

class asPortalRenderable
{
public:
    virtual void Cull(b32 sub_cull) = 0;
};

check_size(asPortalRenderable, 0x4);
