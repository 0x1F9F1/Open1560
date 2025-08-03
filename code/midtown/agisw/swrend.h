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

struct agiScreenVtx;
struct swr_sizes_t;
struct swRastInfo;
struct swSurface;

// ?__emitDepthComplexity@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL __emitDepthComplexity(i32 arg1);

// ?__emitSolid@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL __emitSolid(i32 arg1);

// ?__emitSolidZ@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL __emitSolidZ(i32 arg1);

// ?__emitWireframe@@YIXH@Z
ARTS_IMPORT void ARTS_FASTCALL __emitWireframe(i32 arg1);

// ?__setupNone@@YIXPAUswSurface@@@Z
ARTS_EXPORT void ARTS_FASTCALL __setupNone(swSurface* arg1);

// ?__setupUV@@YIXPAUswSurface@@@Z
ARTS_IMPORT void ARTS_FASTCALL __setupUV(swSurface* arg1);

// ?__setupUVZ@@YIXPAUswSurface@@@Z
ARTS_IMPORT void ARTS_FASTCALL __setupUVZ(swSurface* arg1);

// ?__setupZ@@YIXPAUswSurface@@@Z
ARTS_IMPORT void ARTS_FASTCALL __setupZ(swSurface* arg1);

// ?__spanLinear@@YIXPAUswSurface@@H@Z
ARTS_IMPORT void ARTS_FASTCALL __spanLinear(swSurface* arg1, i32 arg2);

// ?__spanLinearZwrite@@YIXPAUswSurface@@H@Z
ARTS_IMPORT void ARTS_FASTCALL __spanLinearZwrite(swSurface* arg1, i32 arg2);

// ?__spanPerspXY@@YIXPAUswSurface@@H@Z
ARTS_IMPORT void ARTS_FASTCALL __spanPerspXY(swSurface* arg1, i32 arg2);

// ?__spanPerspXYZwrite@@YIXPAUswSurface@@H@Z
ARTS_IMPORT void ARTS_FASTCALL __spanPerspXYZwrite(swSurface* arg1, i32 arg2);

// ?swAddEdge@@YAXHH@Z
ARTS_IMPORT void swAddEdge(i32 arg1, i32 arg2);

// ?swInit@@YAXXZ
ARTS_IMPORT void swInit();

// ?swInitSurface@@YAPAUswSurface@@UagiScreenVtx@@00I@Z
ARTS_IMPORT swSurface* swInitSurface(agiScreenVtx arg1, agiScreenVtx arg2, agiScreenVtx arg3, u32 arg4);

// ?swKill@@YAXXZ
ARTS_EXPORT void swKill();

// ?swLine@@YAXPAUagiScreenVtx@@0@Z
void swLine(agiScreenVtx* start, agiScreenVtx* end);

// ?swLineInt@@YAXHHHHH@Z
ARTS_IMPORT void swLineInt(i32 start_x, i32 start_y, i32 end_x, i32 end_y, i32 color);

// ?swPoly@@YAXPAUagiScreenVtx@@H@Z
ARTS_IMPORT void swPoly(agiScreenVtx* arg1, i32 arg2);

// ?swQuad@@YAXPAUagiScreenVtx@@000@Z
ARTS_IMPORT void swQuad(agiScreenVtx* arg1, agiScreenVtx* arg2, agiScreenVtx* arg3, agiScreenVtx* arg4);

// ?swScanSurface@@YAXPAUswSurface@@@Z
ARTS_IMPORT void swScanSurface(swSurface* arg1);

// ?swScanSurfaces@@YAXXZ
ARTS_IMPORT void swScanSurfaces();

// ?swSetInterlace@@YAXH@Z
ARTS_IMPORT void swSetInterlace(i32 arg1);

// ?swTri@@YAXPAUagiScreenVtx@@00@Z
ARTS_IMPORT void swTri(agiScreenVtx* arg1, agiScreenVtx* arg2, agiScreenVtx* arg3);

// ?BACKFACE@@3HA
ARTS_IMPORT extern i32 BACKFACE;

// ?BADEDGE@@3HA
ARTS_IMPORT extern i32 BADEDGE;

// ?EnableParabolic@@3HA
ARTS_IMPORT extern i32 EnableParabolic;

// ?FLIPLOD@@3HA
ARTS_IMPORT extern i32 FLIPLOD;

// ?FLIPWINDING@@3HA
ARTS_IMPORT extern i32 FLIPWINDING;

// ?LODBIAS@@3HA
ARTS_IMPORT extern i32 LODBIAS;

// ?PERSP2@@3HA
ARTS_IMPORT extern i32 PERSP2;

// ?PERSP_THRESH@@3MA
ARTS_IMPORT extern f32 PERSP_THRESH;

// ?QUADS@@3HA
ARTS_IMPORT extern i32 QUADS;

// ?XPTHRESH@@3HA
ARTS_IMPORT extern i32 XPTHRESH;

// ?YPTHRESH@@3HA
ARTS_IMPORT extern i32 YPTHRESH;

// ?debugTri@@3HA
ARTS_IMPORT extern i32 debugTri;

// ?debugTriGate@@3HA
ARTS_IMPORT extern i32 debugTriGate;

// ?debugTriMatch@@3HA
ARTS_IMPORT extern i32 debugTriMatch;

// ?swActualScreenStride@@3IA
ARTS_IMPORT extern u32 swActualScreenStride;

// ?swBlueMask@@3HA
ARTS_IMPORT extern i32 swBlueMask;

// ?swBytesPerPixel@@3HA
ARTS_IMPORT extern i32 swBytesPerPixel;

// ?swClampAdd@@3P6IIII@ZA
ARTS_IMPORT extern u32(ARTS_FASTCALL* swClampAdd)(u32, u32);

// ?swCurrentDepthLine@@3PAGA
ARTS_IMPORT extern u16* swCurrentDepthLine;

// ?swCurrentLut@@3PAGA
ARTS_IMPORT extern u16* swCurrentLut;

// ?swCurrentScanline@@3PAXA
ARTS_IMPORT extern void* swCurrentScanline;

// ?swDepthBuffer@@3PAGA
ARTS_IMPORT extern u16* swDepthBuffer;

// ?swFbEnd@@3P6AXXZA
ARTS_IMPORT extern void (*swFbEnd)(void);

// ?swFbEndFrame@@3P6AXXZA
ARTS_IMPORT extern void (*swFbEndFrame)(void);

// ?swFbEndScene@@3P6AXXZA
ARTS_IMPORT extern void (*swFbEndScene)(void);

// ?swFbHeight@@3HA
ARTS_IMPORT extern i32 swFbHeight;

// ?swFbParent@@3PAXA
ARTS_IMPORT extern void* swFbParent;

// ?swFbStart@@3P6AXXZA
ARTS_IMPORT extern void (*swFbStart)(void);

// ?swFbStartFrame@@3P6AXXZA
ARTS_IMPORT extern void (*swFbStartFrame)(void);

// ?swFbStartScene@@3P6AXXZA
ARTS_IMPORT extern void (*swFbStartScene)(void);

// ?swFbWidth@@3HA
ARTS_IMPORT extern i32 swFbWidth;

// ?swFbX@@3HA
ARTS_IMPORT extern i32 swFbX;

// ?swFbY@@3HA
ARTS_IMPORT extern i32 swFbY;

// ?swFrameOffset@@3IA
ARTS_IMPORT extern u32 swFrameOffset;

// ?swGreenMask@@3HA
ARTS_IMPORT extern i32 swGreenMask;

// ?swInfo@@3UswRastInfo@@A
ARTS_IMPORT extern swRastInfo swInfo;

// ?swIsInterlaced@@3HA
ARTS_IMPORT extern i32 swIsInterlaced;

// ?swPixelSizeShift@@3HA
ARTS_IMPORT extern i32 swPixelSizeShift;

// ?swRedMask@@3HA
ARTS_IMPORT extern i32 swRedMask;

// ?swScreen@@3PAXA
ARTS_IMPORT extern void* swScreen;

// ?swScreenStride@@3IA
ARTS_IMPORT extern u32 swScreenStride;

// ?swStippleTest@@3PAEA
ARTS_IMPORT extern u8* swStippleTest;

// ?swr_color@@3HA
ARTS_IMPORT extern i32 swr_color;

// ?swr_ddu@@3HA
ARTS_IMPORT extern i32 swr_ddu;

// ?swr_ddv@@3HA
ARTS_IMPORT extern i32 swr_ddv;

// ?swr_dest@@3PAXA
ARTS_IMPORT extern void* swr_dest;

// ?swr_di@@3HA
ARTS_IMPORT extern i32 swr_di;

// ?swr_du@@3HA
ARTS_IMPORT extern i32 swr_du;

// ?swr_dv@@3HA
ARTS_IMPORT extern i32 swr_dv;

// ?swr_dz@@3HA
ARTS_IMPORT extern i32 swr_dz;

// ?swr_i@@3HA
ARTS_IMPORT extern i32 swr_i;

// ?swr_sizes@@3Tswr_sizes_t@@A
ARTS_IMPORT extern swr_sizes_t swr_sizes;

// ?swr_src@@3PAXA
ARTS_IMPORT extern void* swr_src;

// ?swr_texmask@@3HA
ARTS_IMPORT extern i32 swr_texmask;

// ?swr_texshift@@3HA
ARTS_IMPORT extern i32 swr_texshift;

// ?swr_texstride@@3HA
ARTS_IMPORT extern i32 swr_texstride;

// ?swr_u@@3HA
ARTS_IMPORT extern i32 swr_u;

// ?swr_v@@3HA
ARTS_IMPORT extern i32 swr_v;

// ?swr_z@@3HA
ARTS_IMPORT extern i32 swr_z;

// ?swr_zb@@3PAGA
ARTS_IMPORT extern u16* swr_zb;
