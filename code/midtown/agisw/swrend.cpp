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

define_dummy_symbol(agisw_swrend);

#include "swrend.h"

#include "agi/pipeline.h"
#include "agi/rsys.h"
#include "data7/utimer.h"
#include "eventq7/winevent.h"

static extern_var(0x7960A8, u32 (*)(u32), swFindColor);

void ARTS_FASTCALL __setupNone(struct swSurface* /*arg1*/)
{}

// 0x5367C0 | ?__emitSemiBlack@@YIXH@Z
ARTS_IMPORT /*static*/ void ARTS_FASTCALL __emitSemiBlack(i32 arg1);

// 0x536800 | ?__emitStippleBlack@@YIXH@Z
ARTS_IMPORT /*static*/ void ARTS_FASTCALL __emitStippleBlack(i32 arg1);

// 0x535910 | ?__emitZwrite@@YIXPAUswSurface@@H@Z
ARTS_IMPORT /*static*/ void ARTS_FASTCALL __emitZwrite(struct swSurface* arg1, i32 arg2);

// 0x536940 | ?emms@@YAXXZ
ARTS_IMPORT /*static*/ void emms();

// 0x537690 | ?swClampAdd555@@YIIII@Z
ARTS_IMPORT /*static*/ u32 ARTS_FASTCALL swClampAdd555(u32 arg1, u32 arg2);

// 0x537650 | ?swClampAdd565@@YIIII@Z
ARTS_IMPORT /*static*/ u32 ARTS_FASTCALL swClampAdd565(u32 arg1, u32 arg2);

// 0x537610 | ?swClampAddColor555@@YIII@Z
ARTS_IMPORT /*static*/ u32 ARTS_FASTCALL swClampAddColor555(u32 arg1);

// 0x5375D0 | ?swClampAddColor565@@YIII@Z
ARTS_IMPORT /*static*/ u32 ARTS_FASTCALL swClampAddColor565(u32 arg1);

// 0x536840 | ?swComputeIntensity@@YAHAAUagiScreenVtx@@@Z
ARTS_IMPORT /*static*/ i32 swComputeIntensity(struct agiScreenVtx& arg1);

// 0x537550 | ?swFindColor555@@YAII@Z
ARTS_IMPORT /*static*/ u32 swFindColor555(u32 arg1);

// 0x537590 | ?swFindColor565@@YAII@Z
ARTS_IMPORT /*static*/ u32 swFindColor565(u32 arg1);

// 0x535460 | ?swSetupEdgeScan@@YAXPAUswEdge@@HH@Z
ARTS_IMPORT /*static*/ void swSetupEdgeScan(struct swEdge* arg1, i32 arg2, i32 arg3);

void swKill()
{
    delete[] swDepthBuffer;
    swDepthBuffer = nullptr;

    agiCurState.SetSoftwareRendering(false);
}

void swLine(agiScreenVtx* start, agiScreenVtx* end)
{
    if (!IsAppActive())
        return;

    ARTS_UTIMED(agiRasterization);

    // NOTE: Quantizing rounds upwards, casting rounds to zero (truncates)
    // NOTE: This needs to be clamped, otherwise it can write out of bounds
#define X(V, LIMIT) std::min<i32>(static_cast<u16>(mem::bit_cast<u32>(V + 12582912.0f)), LIMIT)
    i32 start_x = X(start->x, swFbWidth - 1);
    i32 start_y = X(start->y, swFbHeight - 1);
    i32 end_x = X(end->x, swFbWidth - 1);
    i32 end_y = X(end->y, swFbHeight - 1);
#undef X

    swLineInt(start_x, start_y, end_x, end_y, swFindColor(start->color));
}