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
#include "vector7/vector3.h"
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

struct PtlPath
{
    i32 PathId;
    i32 Type;
};

struct PortalLink
{
    asPortalEdge* Edge;
    PortalLink* Next;
};

check_size(PortalLink, 0x8);

#define PORTAL_CELL_FLAG_1 0x1 // Enable distance sorting?

struct asPortalCell
{
    PortalLink* Edges;
    asPortalRenderable* CellRenderer;
    asPortalCell* Next;
    u16 VisitTag;
    u16 CellIndex;
    u16 NumPtlPaths;
    u16 Flags;
    PtlPath** PtlPaths;

    bool HasFlag1() const
    {
        return (Flags & PORTAL_CELL_FLAG_1) != 0;
    }
};

check_size(asPortalCell, 0x18);

class asPortalWeb : public asNode
{
public:
    // ??0asPortalWeb@@QAE@XZ
    asPortalWeb();

    // ??1asPortalWeb@@UAE@XZ
    ~asPortalWeb() override;

    virtual asPortalCell* GetStartCell(Vector3& arg1, asPortalCell* arg2, mmPolygon** arg3) = 0;

    // ?AddCell@asPortalWeb@@QAEPAUasPortalCell@@PADPAVasPortalRenderable@@I@Z
    ARTS_IMPORT asPortalCell* AddCell(aconst char* name, asPortalRenderable* render, u32 index);

    // ?AddEdge@asPortalWeb@@QAEPAUasPortalEdge@@PADPAUasPortalCell@@1H@Z
    ARTS_IMPORT asPortalEdge* AddEdge(aconst char* name, asPortalCell* cell1, asPortalCell* cell2, i32 num_edges);

    // ?BuildGroups@asPortalWeb@@QAEXXZ
    ARTS_IMPORT void BuildGroups();

    // ?Update@asPortalWeb@@UAEXXZ
    ARTS_EXPORT void Update() override;

    // ?Cull@asPortalWeb@@QAEXH@Z
    ARTS_EXPORT void Cull(b32 front_to_back);

#ifdef ARTS_DEV_BUILD
    // ?BuildVisibilityList@asPortalWeb@@QAEHAAVMatrix34@@PAPAUasPortalCell@@HM@Z
    ARTS_IMPORT i32 BuildVisibilityList(Matrix34& arg1, asPortalCell** arg2, i32 arg3, f32 arg4);

    // ?BuildVisibilityList@asPortalWeb@@QAEHAAVVector3@@PAPAUasPortalCell@@HM@Z
    ARTS_IMPORT i32 BuildVisibilityList(Vector3& arg1, asPortalCell** arg2, i32 arg3, f32 arg4);

    // ?Stats@asPortalWeb@@QAEXXZ
    ARTS_IMPORT void Stats();

    // ?AddWidgets@asPortalWeb@@UAEXPAVBank@@@Z
    void AddWidgets(Bank* bank) override;
#endif

    VIRTUAL_META_DECLARE;

    // ?VisitTag@asPortalWeb@@2GA
    ARTS_EXPORT static u16 VisitTag;

    b32 DisableTextures {};
    i32 MaxRenderDepth {32};
    asPortalCell* CellList {};
    asPortalCell* StartCell {};
    asPortalEdge* Edges {};
    b32 Debug {};
    b32 SubClip {};
    b32 NoPortals {};

    // 0 = Main
    // 1 = Mirror
    static const i32 NUM_PORTAL_PASSES = 2;
    static const i32 MAX_ACTIVE_PORTALS = 256;

    i32 CurrentPass {};
    i32 NumSubPortals[NUM_PORTAL_PASSES] {};
    asPortalView Portals[NUM_PORTAL_PASSES][MAX_ACTIVE_PORTALS] {};
};

check_size(asPortalWeb, 0x904C);

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

    bool IsEnabled() const
    {
        return (Flags & Flags_Enabled) != 0;
    }

    bool IsOpenArea() const
    {
        return (Flags & Flags_Open) != 0;
    }

    bool IsSemiOpenArea() const
    {
        return (Flags & Flags_SemiOpen) != 0;
    }

    bool HasFlag8() const
    {
        return (Flags & Flags_Flag8) != 0;
    }

    f32 GetDistance(Vector3 pos) const
    {
        return Plane.x * pos.x + Plane.y * pos.y + Plane.z * pos.z + Plane.w;
    }
};

check_size(asPortalEdge, 0x30);

class asPortalRenderable
{
public:
    virtual void Cull(b32 sub_cull) = 0;
};

check_size(asPortalRenderable, 0x4);
