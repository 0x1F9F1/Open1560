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

#include "agi/render.h"

class agiLighter;
struct agiPatch;
class agiRasterizer;
struct agiSurface;

class agiSurfRenderer : public agiRenderer
{
public:
    // ??0agiSurfRenderer@@QAE@PAVagiRasterizer@@@Z
    ARTS_IMPORT agiSurfRenderer(agiRasterizer* arg1);

    // ?BeginDraw@agiSurfRenderer@@UAEXH@Z
    ARTS_EXPORT void BeginDraw(i32 flags) override;

    // ?BeginGroup@agiSurfRenderer@@UAEXXZ
    ARTS_EXPORT void BeginGroup() override;

    // ?Draw@agiSurfRenderer@@UAEXPAVDLP@@H@Z
    ARTS_IMPORT void Draw(DLP* arg1, i32 arg2) override;

    // ?DrawCard@agiSurfRenderer@@UAEXAAVVector3@@@Z
    ARTS_IMPORT void DrawCard(Vector3& arg1) override;

    // ?DrawLabel@agiSurfRenderer@@UAEXAATagiVtx@@PAD@Z
    ARTS_IMPORT void DrawLabel(agiVtx& arg1, char* arg2) override;

    // ?DrawLine@agiSurfRenderer@@UAEXHH@Z
    ARTS_IMPORT void DrawLine(i32 arg1, i32 arg2) override;

    // ?DrawTri@agiSurfRenderer@@UAEXHHH@Z
    ARTS_IMPORT void DrawTri(i32 arg1, i32 arg2, i32 arg3) override;

    // ?EndDraw@agiSurfRenderer@@UAEXXZ
    ARTS_IMPORT void EndDraw() override;

    // ?Points@agiSurfRenderer@@UAEXPATagiVtx@@H@Z
    ARTS_IMPORT void Points(agiVtx* arg1, i32 arg2) override;

    // ?Verts@agiSurfRenderer@@UAEXPATagiVtx@@H@Z
    ARTS_IMPORT void Verts(agiVtx* arg1, i32 arg2) override;

protected:
    // ??1agiSurfRenderer@@MAE@XZ
    ARTS_EXPORT ~agiSurfRenderer() override = default;

    // ?SurfaceCount@agiSurfRenderer@@1HA
    ARTS_IMPORT static i32 SurfaceCount;

    // ?SurfaceHeap@agiSurfRenderer@@1PAUagiSurface@@A
    ARTS_IMPORT static agiSurface SurfaceHeap[16384];

    // ?VertexCount@agiSurfRenderer@@1HA
    ARTS_IMPORT static i32 VertexCount;

private:
    // ?AddSurface@agiSurfRenderer@@CAHPAUagiPatch@@HHHH@Z
    ARTS_IMPORT static i32 AddSurface(agiPatch* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5);

    agiRasterizer* rasterizer_ {};
    agiLighter* lighter_ {};
};

check_size(agiSurfRenderer, 0x14);

// ?EarlyBackface@@3HA
ARTS_IMPORT extern i32 EarlyBackface;

// ?NoClip@@3HA
ARTS_IMPORT extern i32 NoClip;

// ?ZTrick@@3HA
ARTS_IMPORT extern i32 ZTrick;

void UpdateZTrick();
