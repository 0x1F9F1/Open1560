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

#include "portal.h"

class agiViewport;
class asParticles;
class mmBoundTemplate;

#define RENDER_PASS_TERRAIN 0x1   // Roads, Grass, Water, Bridges
#define RENDER_PASS_SHADOWS 0x2   // Shadows, Skids
#define RENDER_PASS_BUILDINGS 0x4 // Buildings
#define RENDER_PASS_OBJECTS 0x8   // Objects
#define RENDER_PASS_LIGHTS 0x10   // Lights

/*
    Cells:

    [LM]
    1-199 : Open Areas / Landmarks
    200   : Uppers

    [CITY]
    201-859 : Roads
    860+    : Intersections
*/

class asRenderWeb final : public asPortalWeb
{
public:
    // ??0asRenderWeb@@QAE@XZ
    ARTS_IMPORT asRenderWeb();

    // ??_EasRenderWeb@@UAEPAXI@Z
    // ??1asRenderWeb@@UAE@XZ
    ARTS_IMPORT ~asRenderWeb() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asRenderWeb@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Cull@asRenderWeb@@UAEXXZ
    ARTS_IMPORT void Cull() override;

#ifdef ARTS_DEV_BUILD
    // ?DrawAllBounds@asRenderWeb@@QAEXXZ
    ARTS_IMPORT void DrawAllBounds();
#endif

    // ?GetCellNeighbors@asRenderWeb@@QAEHHPAPAUasPortalCell@@H@Z
    ARTS_IMPORT i32 GetCellNeighbors(i32 arg1, asPortalCell** arg2, i32 arg3);

    // ?GetClass@asRenderWeb@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetStartCell@asRenderWeb@@UAEPAUasPortalCell@@AAVVector3@@PAU2@PAPAVmmPolygon@@@Z
    ARTS_IMPORT asPortalCell* GetStartCell(Vector3& arg1, asPortalCell* arg2, mmPolygon** arg3) override;

    // ?Load@asRenderWeb@@QAEHPADH@Z
    ARTS_IMPORT i32 Load(char* arg1, i32 arg2);

    // ?SetMirrorPos@asRenderWeb@@QAEXMMMMM@Z
    ARTS_IMPORT void SetMirrorPos(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // ?Update@asRenderWeb@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateMirror@asRenderWeb@@QAEXXZ
    ARTS_IMPORT void UpdateMirror();

    asPortalCell* GetCell(i32 index) const
    {
        return (index >= 0 && index < MaxCells) ? CellArray[index] : nullptr;
    }

    // ?DeclareFields@asRenderWeb@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // ?InvLodFactor@asRenderWeb@@2MA
    ARTS_IMPORT static f32 InvLodFactor;

    // RENDER_PASS_*
    // ?PassMask@asRenderWeb@@2HA
    ARTS_IMPORT static i32 PassMask;

    asPortalCell** CellArray;
    mmBoundTemplate* HitIdBound;
    mmBoundTemplate** Bounds;
    i32 HasHitIdBound;
    i32 MaxCells;
    i32 HitID;
    asParticles* Particles[64];
    i32 PtxCount;
    b32 EnableMirror;
    agiViewport* Viewport;
    Matrix34* CarCamera;
    Matrix34* MirrorMatrix;
};

check_size(asRenderWeb, 0x9178);

// ?DrawMirrorBorder@@YAXXZ
ARTS_IMPORT void DrawMirrorBorder();

// ?CachedFullSegmentHits@@3HA
ARTS_IMPORT extern i32 CachedFullSegmentHits;

// ?CachedFullSegmentTests@@3HA
ARTS_IMPORT extern i32 CachedFullSegmentTests;

// ?EnableCachedPoly@@3HA
ARTS_IMPORT extern i32 EnableCachedPoly;

// ?EnableSubClip@@3HA
ARTS_IMPORT extern i32 EnableSubClip;

// ?Front2Back@@3HA
ARTS_IMPORT extern i32 Front2Back;

// ?GridMtx@@3PAVMatrix34@@A
ARTS_IMPORT extern Matrix34* GridMtx;

// ?MULTIPASS@@3HA
ARTS_IMPORT extern i32 MULTIPASS;

// ?PopupEnabled@@3HA
ARTS_IMPORT extern i32 PopupEnabled;

// ?SC_SVCP@@3HA
ARTS_IMPORT extern i32 SC_SVCP;

// ?SC_SVP@@3HA
ARTS_IMPORT extern i32 SC_SVP;

// ?ScreenClearY@@3MA
ARTS_IMPORT extern f32 ScreenClearY;

// ?ShadowZBias@@3MA
ARTS_IMPORT extern f32 ShadowZBias;

// ?StartCellCollides@@3HA
ARTS_IMPORT extern i32 StartCellCollides;

// ?ZREAD@@3HA
ARTS_IMPORT extern i32 ZREAD;

// ?ZWRITE@@3HA
ARTS_IMPORT extern i32 ZWRITE;

#ifdef ARTS_DEV_BUILD
// ?pass1Count@@3HA
ARTS_IMPORT extern i32 pass1Count;

// ?pass2Count@@3HA
ARTS_IMPORT extern i32 pass2Count;

// ?pass3Count@@3HA
ARTS_IMPORT extern i32 pass3Count;

// ?pass4Count@@3HA
ARTS_IMPORT extern i32 pass4Count;

// ?upperCount@@3HA
ARTS_IMPORT extern i32 upperCount;
#endif
