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

struct agiAdjunctData;
class agiLighter;
struct agiLitVtx;
union agiVtx;

struct agiProjVtx
{
public:
    // ?Init@agiProjVtx@@SAXHPAVagiLighter@@I@Z
    ARTS_IMPORT static void Init(i32 arg1, agiLighter* arg2, u32 arg3);

    // ?InitMtx@agiProjVtx@@SAXAAVMatrix34@@MMMM@Z
    ARTS_IMPORT static void InitMtx(Matrix34& arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // ?Project@agiProjVtx@@SAHHPAUagiLitVtx@@@Z
    ARTS_IMPORT static i32 Project(i32 arg1, agiLitVtx* arg2);

    // ?SetOutcode@agiProjVtx@@SAXH@Z
    ARTS_IMPORT static void SetOutcode(i32 arg1);

    // ?ToScreen@agiProjVtx@@SAXH@Z
    ARTS_IMPORT static void ToScreen(i32 arg1);

    // ?Adj@agiProjVtx@@2PAUagiAdjunctData@@A
    ARTS_IMPORT static agiAdjunctData Adj[6968];

    // ?HalfHeight@agiProjVtx@@2MA
    ARTS_IMPORT static f32 HalfHeight;

    // ?HalfWidth@agiProjVtx@@2MA
    ARTS_IMPORT static f32 HalfWidth;

    // ?LIGHTER@agiProjVtx@@2PAVagiLighter@@A
    ARTS_IMPORT static agiLighter* LIGHTER;

    // ?M@agiProjVtx@@2VMatrix34@@A
    ARTS_IMPORT static Matrix34 M;

    // ?M2@agiProjVtx@@2VMatrix34@@A
    ARTS_IMPORT static Matrix34 M2;

    // ?NeedsClip@agiProjVtx@@2HA
    ARTS_IMPORT static i32 NeedsClip;

    // ?NoModelView@agiProjVtx@@2HA
    ARTS_IMPORT static i32 NoModelView;

    // ?OffsX@agiProjVtx@@2MA
    ARTS_IMPORT static f32 OffsX;

    // ?OffsY@agiProjVtx@@2MA
    ARTS_IMPORT static f32 OffsY;

    // ?Orthographic@agiProjVtx@@2HA
    ARTS_IMPORT static i32 Orthographic;

    // ?ProjX@agiProjVtx@@2MA
    ARTS_IMPORT static f32 ProjX;

    // ?ProjXZ@agiProjVtx@@2MA
    ARTS_IMPORT static f32 ProjXZ;

    // ?ProjY@agiProjVtx@@2MA
    ARTS_IMPORT static f32 ProjY;

    // ?ProjYZ@agiProjVtx@@2MA
    ARTS_IMPORT static f32 ProjYZ;

    // ?ProjZW@agiProjVtx@@2MA
    ARTS_IMPORT static f32 ProjZW;

    // ?ProjZZ@agiProjVtx@@2MA
    ARTS_IMPORT static f32 ProjZZ;

    // ?ScreenHeight@agiProjVtx@@2MA
    ARTS_IMPORT static f32 ScreenHeight;

    // ?ScreenWidth@agiProjVtx@@2MA
    ARTS_IMPORT static f32 ScreenWidth;

    // ?Vtx@agiProjVtx@@2PATagiVtx@@A
    ARTS_IMPORT static agiVtx Vtx[6968];
};

// ?DepthOffset@@3MA
ARTS_IMPORT extern f32 DepthOffset;

// ?DepthScale@@3MA
ARTS_IMPORT extern f32 DepthScale;

// ?clip_pz@@3HA
ARTS_IMPORT extern i32 clip_pz;
