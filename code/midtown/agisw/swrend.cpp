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

void __fastcall __emitDebug(struct swSurface* arg1, i32 arg2)
{
    return stub<fastcall_t<void, struct swSurface*, i32>>(0x5351C0, arg1, arg2);
}

void __fastcall __emitDepthComplexity(i32 arg1)
{
    return stub<fastcall_t<void, i32>>(0x535220, arg1);
}

void __fastcall __emitSolid(i32 arg1)
{
    return stub<fastcall_t<void, i32>>(0x535260, arg1);
}

void __fastcall __emitSolidZ(i32 arg1)
{
    return stub<fastcall_t<void, i32>>(0x5352B0, arg1);
}

void __fastcall __emitWireframe(i32 arg1)
{
    return stub<fastcall_t<void, i32>>(0x535320, arg1);
}

void __fastcall __setupNone(struct swSurface* arg1)
{
    return stub<fastcall_t<void, struct swSurface*>>(0x535890, arg1);
}

void __fastcall __setupUV(struct swSurface* arg1)
{
    return stub<fastcall_t<void, struct swSurface*>>(0x535510, arg1);
}

void __fastcall __setupUVI(struct swSurface* arg1)
{
    return stub<fastcall_t<void, struct swSurface*>>(0x5356E0, arg1);
}

void __fastcall __setupUVIZ(struct swSurface* arg1)
{
    return stub<fastcall_t<void, struct swSurface*>>(0x5357B0, arg1);
}

void __fastcall __setupUVZ(struct swSurface* arg1)
{
    return stub<fastcall_t<void, struct swSurface*>>(0x5355D0, arg1);
}

void __fastcall __setupZ(struct swSurface* arg1)
{
    return stub<fastcall_t<void, struct swSurface*>>(0x5356A0, arg1);
}

void __fastcall __spanLinear(struct swSurface* arg1, i32 arg2)
{
    return stub<fastcall_t<void, struct swSurface*, i32>>(0x5358A0, arg1, arg2);
}

void __fastcall __spanLinearZwrite(struct swSurface* arg1, i32 arg2)
{
    return stub<fastcall_t<void, struct swSurface*, i32>>(0x5358D0, arg1, arg2);
}

void __fastcall __spanPerspXY(struct swSurface* arg1, i32 arg2)
{
    return stub<fastcall_t<void, struct swSurface*, i32>>(0x5359D0, arg1, arg2);
}

void __fastcall __spanPerspXYZwrite(struct swSurface* arg1, i32 arg2)
{
    return stub<fastcall_t<void, struct swSurface*, i32>>(0x535BD0, arg1, arg2);
}

void swAddEdge(i32 arg1, i32 arg2)
{
    return stub<cdecl_t<void, i32, i32>>(0x535340, arg1, arg2);
}

void swInit()
{
    return stub<cdecl_t<void>>(0x537480);
}

struct swSurface* swInitSurface(struct agiScreenVtx arg1, struct agiScreenVtx arg2, struct agiScreenVtx arg3, u32 arg4)
{
    return stub<cdecl_t<struct swSurface*, struct agiScreenVtx, struct agiScreenVtx, struct agiScreenVtx, u32>>(
        0x535E30, arg1, arg2, arg3, arg4);
}

void swKill()
{
    return stub<cdecl_t<void>>(0x537410);
}

void swLine(struct agiScreenVtx* arg1, struct agiScreenVtx* arg2)
{
    return stub<cdecl_t<void, struct agiScreenVtx*, struct agiScreenVtx*>>(0x537360, arg1, arg2);
}

void swLineInt(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<cdecl_t<void, i32, i32, i32, i32, i32>>(0x537270, arg1, arg2, arg3, arg4, arg5);
}

void swPoly(struct agiScreenVtx* arg1, i32 arg2)
{
    return stub<cdecl_t<void, struct agiScreenVtx*, i32>>(0x536EE0, arg1, arg2);
}

void swQuad(struct agiScreenVtx* arg1, struct agiScreenVtx* arg2, struct agiScreenVtx* arg3, struct agiScreenVtx* arg4)
{
    return stub<cdecl_t<void, struct agiScreenVtx*, struct agiScreenVtx*, struct agiScreenVtx*, struct agiScreenVtx*>>(
        0x536B10, arg1, arg2, arg3, arg4);
}

void swScanSurface(struct swSurface* arg1)
{
    return stub<cdecl_t<void, struct swSurface*>>(0x535BF0, arg1);
}

void swScanSurfaces()
{
    return stub<cdecl_t<void>>(0x536880);
}

void swSetInterlace(i32 arg1)
{
    return stub<cdecl_t<void, i32>>(0x537440, arg1);
}

void swTri(struct agiScreenVtx* arg1, struct agiScreenVtx* arg2, struct agiScreenVtx* arg3)
{
    return stub<cdecl_t<void, struct agiScreenVtx*, struct agiScreenVtx*, struct agiScreenVtx*>>(
        0x536950, arg1, arg2, arg3);
}

static void __fastcall __emitSemiBlack(i32 arg1)
{
    return stub<fastcall_t<void, i32>>(0x5367C0, arg1);
}

static void __fastcall __emitStippleBlack(i32 arg1)
{
    return stub<fastcall_t<void, i32>>(0x536800, arg1);
}

static void __fastcall __emitZwrite(struct swSurface* arg1, i32 arg2)
{
    return stub<fastcall_t<void, struct swSurface*, i32>>(0x535910, arg1, arg2);
}

static void emms()
{
    return stub<cdecl_t<void>>(0x536940);
}

static u32 __fastcall swClampAdd555(u32 arg1, u32 arg2)
{
    return stub<fastcall_t<u32, u32, u32>>(0x537690, arg1, arg2);
}

static u32 __fastcall swClampAdd565(u32 arg1, u32 arg2)
{
    return stub<fastcall_t<u32, u32, u32>>(0x537650, arg1, arg2);
}

static u32 __fastcall swClampAddColor555(u32 arg1)
{
    return stub<fastcall_t<u32, u32>>(0x537610, arg1);
}

static u32 __fastcall swClampAddColor565(u32 arg1)
{
    return stub<fastcall_t<u32, u32>>(0x5375D0, arg1);
}

static i32 swComputeIntensity(struct agiScreenVtx& arg1)
{
    return stub<cdecl_t<i32, struct agiScreenVtx&>>(0x536840, arg1);
}

static u32 swFindColor555(u32 arg1)
{
    return stub<cdecl_t<u32, u32>>(0x537550, arg1);
}

static u32 swFindColor565(u32 arg1)
{
    return stub<cdecl_t<u32, u32>>(0x537590, arg1);
}

static void swSetupEdgeScan(struct swEdge* arg1, i32 arg2, i32 arg3)
{
    return stub<cdecl_t<void, struct swEdge*, i32, i32>>(0x535460, arg1, arg2, arg3);
}
