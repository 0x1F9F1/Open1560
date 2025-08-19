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

#include "vector7/vector3.h"

class mmDofBangerInstance;
class agiMeshSet;

class mmCellRenderer final : public asPortalRenderable
{
public:
    // ??0mmCellRenderer@@QAE@XZ
    ARTS_IMPORT mmCellRenderer();

    // ?Cull@mmCellRenderer@@UAEXH@Z
    ARTS_IMPORT void Cull(b32 sub_cull) override;

    // ?Init@mmCellRenderer@@QAEXPADHHHHPAH@Z
    ARTS_IMPORT void Init(aconst char* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32* arg6);

    // ?Relight@mmCellRenderer@@QAEXXZ
    ARTS_EXPORT void Relight();

    mmDofBangerInstance* Drawbridge {};
    agiMeshSet* Meshes[8] {};
    Vector3 CellCenter;
    f32 CellMagnitude {};
    u8* SlideData {};
    i16 Index {};
    i16 RoomFlags {};
    i16 VisitTagCount {};
    u16* VisitTags {};
};

check_size(mmCellRenderer, 0x48);

// ?CRPass1Only@@3HA
ARTS_IMPORT extern i32 CRPass1Only;

// ?CRPass3Only@@3HA
ARTS_IMPORT extern i32 CRPass3Only;

// ?CRPassBoth@@3HA
ARTS_IMPORT extern i32 CRPassBoth;

// ?CellTriCount@@3PAHA
ARTS_IMPORT extern i32 CellTriCount[3];

// ?CellTypeCount@@3PAHA
ARTS_IMPORT extern i32 CellTypeCount[3];

// ?EnableSlide@@3HA
ARTS_IMPORT extern b32 EnableSlide;

// ?ObjectMaxDist@@3MA
ARTS_EXPORT extern f32 ObjectMaxDist;

// ?StaticTerrainLodTable@@3PAY01MA
ARTS_EXPORT extern f32 StaticTerrainLodTable[4][2];
