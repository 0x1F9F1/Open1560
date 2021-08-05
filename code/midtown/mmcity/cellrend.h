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
    mmcity:cellrend

    0x498970 | public: __thiscall mmCellRenderer::mmCellRenderer(void) | ??0mmCellRenderer@@QAE@XZ
    0x4989A0 | public: __thiscall mmCellRenderer::~mmCellRenderer(void) | ??1mmCellRenderer@@QAE@XZ
    0x4989E0 | public: void __thiscall mmCellRenderer::Init(char *,int,int,int,int,int *) | ?Init@mmCellRenderer@@QAEXPADHHHHPAH@Z
    0x498F90 | public: void __thiscall mmCellRenderer::Relight(void) | ?Relight@mmCellRenderer@@QAEXXZ
    0x498FA0 | public: virtual void __thiscall mmCellRenderer::Cull(int) | ?Cull@mmCellRenderer@@UAEXH@Z
    0x61D320 | const mmCellRenderer::`vftable' | ??_7mmCellRenderer@@6B@
    0x6401C0 | float (* StaticTerrainLodTable)[2] | ?StaticTerrainLodTable@@3PAY01MA
    0x6401E0 | float ObjectMaxDist | ?ObjectMaxDist@@3MA
    0x6401E4 | int EnableSlide | ?EnableSlide@@3HA
    0x7057B8 | int CRPassBoth | ?CRPassBoth@@3HA
    0x7057BC | int CRPass1Only | ?CRPass1Only@@3HA
    0x7057C0 | int * CellTriCount | ?CellTriCount@@3PAHA
    0x7057D0 | int * CellTypeCount | ?CellTypeCount@@3PAHA
    0x7057DC | int CRPass3Only | ?CRPass3Only@@3HA
*/

#include "portal.h"

class mmCellRenderer final : public asPortalRenderable
{
    // const mmCellRenderer::`vftable'

public:
    // ??0mmCellRenderer@@QAE@XZ
    ARTS_IMPORT mmCellRenderer();

    // ??1mmCellRenderer@@QAE@XZ | unused
    ARTS_IMPORT ~mmCellRenderer();

    // ?Cull@mmCellRenderer@@UAEXH@Z
    ARTS_IMPORT void Cull(i32 arg1) override;

    // ?Init@mmCellRenderer@@QAEXPADHHHHPAH@Z
    ARTS_IMPORT void Init(char* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, i32* arg6);

    // ?Relight@mmCellRenderer@@QAEXXZ
    ARTS_EXPORT void Relight();

    u8 gap4[0x44];
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
ARTS_IMPORT extern i32 EnableSlide;

// ?ObjectMaxDist@@3MA
ARTS_IMPORT extern f32 ObjectMaxDist;

// ?StaticTerrainLodTable@@3PAY01MA
ARTS_EXPORT extern f32 StaticTerrainLodTable[4][2];
