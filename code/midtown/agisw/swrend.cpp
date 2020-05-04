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

#include "swrend.h"

void __fastcall __emitDebug(struct swSurface* arg1, i32 arg2)
{
    return stub<fastcall_t<void, struct swSurface*, i32>>(0x1351C0_Offset, arg1, arg2);
}

void __fastcall __emitDepthComplexity(i32 arg1)
{
    return stub<fastcall_t<void, i32>>(0x135220_Offset, arg1);
}

void __fastcall __emitSolid(i32 arg1)
{
    return stub<fastcall_t<void, i32>>(0x135260_Offset, arg1);
}

void __fastcall __emitSolidZ(i32 arg1)
{
    return stub<fastcall_t<void, i32>>(0x1352B0_Offset, arg1);
}

void __fastcall __emitWireframe(i32 arg1)
{
    return stub<fastcall_t<void, i32>>(0x135320_Offset, arg1);
}

void __fastcall __setupNone(struct swSurface* arg1)
{
    return stub<fastcall_t<void, struct swSurface*>>(0x135890_Offset, arg1);
}

void __fastcall __setupUV(struct swSurface* arg1)
{
    return stub<fastcall_t<void, struct swSurface*>>(0x135510_Offset, arg1);
}

void __fastcall __setupUVI(struct swSurface* arg1)
{
    return stub<fastcall_t<void, struct swSurface*>>(0x1356E0_Offset, arg1);
}

void __fastcall __setupUVIZ(struct swSurface* arg1)
{
    return stub<fastcall_t<void, struct swSurface*>>(0x1357B0_Offset, arg1);
}

void __fastcall __setupUVZ(struct swSurface* arg1)
{
    return stub<fastcall_t<void, struct swSurface*>>(0x1355D0_Offset, arg1);
}

void __fastcall __setupZ(struct swSurface* arg1)
{
    return stub<fastcall_t<void, struct swSurface*>>(0x1356A0_Offset, arg1);
}

void __fastcall __spanLinear(struct swSurface* arg1, i32 arg2)
{
    return stub<fastcall_t<void, struct swSurface*, i32>>(0x1358A0_Offset, arg1, arg2);
}

void __fastcall __spanLinearZwrite(struct swSurface* arg1, i32 arg2)
{
    return stub<fastcall_t<void, struct swSurface*, i32>>(0x1358D0_Offset, arg1, arg2);
}

void __fastcall __spanPerspXY(struct swSurface* arg1, i32 arg2)
{
    return stub<fastcall_t<void, struct swSurface*, i32>>(0x1359D0_Offset, arg1, arg2);
}

void __fastcall __spanPerspXYZwrite(struct swSurface* arg1, i32 arg2)
{
    return stub<fastcall_t<void, struct swSurface*, i32>>(0x135BD0_Offset, arg1, arg2);
}

void swAddEdge(i32 arg1, i32 arg2)
{
    return stub<cdecl_t<void, i32, i32>>(0x135340_Offset, arg1, arg2);
}

void swInit()
{
    return stub<cdecl_t<void>>(0x137480_Offset);
}

struct swSurface* swInitSurface(struct agiScreenVtx arg1, struct agiScreenVtx arg2, struct agiScreenVtx arg3, u32 arg4)
{
    return stub<cdecl_t<struct swSurface*, struct agiScreenVtx, struct agiScreenVtx, struct agiScreenVtx, u32>>(
        0x135E30_Offset, arg1, arg2, arg3, arg4);
}

void swKill()
{
    return stub<cdecl_t<void>>(0x137410_Offset);
}

void swLine(struct agiScreenVtx* arg1, struct agiScreenVtx* arg2)
{
    return stub<cdecl_t<void, struct agiScreenVtx*, struct agiScreenVtx*>>(0x137360_Offset, arg1, arg2);
}

void swLineInt(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<cdecl_t<void, i32, i32, i32, i32, i32>>(0x137270_Offset, arg1, arg2, arg3, arg4, arg5);
}

void swPoly(struct agiScreenVtx* arg1, i32 arg2)
{
    return stub<cdecl_t<void, struct agiScreenVtx*, i32>>(0x136EE0_Offset, arg1, arg2);
}

void swQuad(struct agiScreenVtx* arg1, struct agiScreenVtx* arg2, struct agiScreenVtx* arg3, struct agiScreenVtx* arg4)
{
    return stub<cdecl_t<void, struct agiScreenVtx*, struct agiScreenVtx*, struct agiScreenVtx*, struct agiScreenVtx*>>(
        0x136B10_Offset, arg1, arg2, arg3, arg4);
}

void swScanSurface(struct swSurface* arg1)
{
    return stub<cdecl_t<void, struct swSurface*>>(0x135BF0_Offset, arg1);
}

void swScanSurfaces()
{
    return stub<cdecl_t<void>>(0x136880_Offset);
}

void swSetInterlace(i32 arg1)
{
    return stub<cdecl_t<void, i32>>(0x137440_Offset, arg1);
}

void swTri(struct agiScreenVtx* arg1, struct agiScreenVtx* arg2, struct agiScreenVtx* arg3)
{
    return stub<cdecl_t<void, struct agiScreenVtx*, struct agiScreenVtx*, struct agiScreenVtx*>>(
        0x136950_Offset, arg1, arg2, arg3);
}

define_dummy_symbol(agisw_swrend);
