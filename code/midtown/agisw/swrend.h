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
    agisw:swrend

    0x5351C0 | void __fastcall __emitDebug(struct swSurface *,int) | ?__emitDebug@@YIXPAUswSurface@@H@Z
    0x535220 | void __fastcall __emitDepthComplexity(int) | ?__emitDepthComplexity@@YIXH@Z
    0x535260 | void __fastcall __emitSolid(int) | ?__emitSolid@@YIXH@Z
    0x5352B0 | void __fastcall __emitSolidZ(int) | ?__emitSolidZ@@YIXH@Z
    0x535320 | void __fastcall __emitWireframe(int) | ?__emitWireframe@@YIXH@Z
    0x535340 | void __cdecl swAddEdge(int,int) | ?swAddEdge@@YAXHH@Z
    0x535460 | void __cdecl swSetupEdgeScan(struct swEdge *,int,int) | ?swSetupEdgeScan@@YAXPAUswEdge@@HH@Z
    0x535510 | void __fastcall __setupUV(struct swSurface *) | ?__setupUV@@YIXPAUswSurface@@@Z
    0x5355D0 | void __fastcall __setupUVZ(struct swSurface *) | ?__setupUVZ@@YIXPAUswSurface@@@Z
    0x5356A0 | void __fastcall __setupZ(struct swSurface *) | ?__setupZ@@YIXPAUswSurface@@@Z
    0x5356E0 | void __fastcall __setupUVI(struct swSurface *) | ?__setupUVI@@YIXPAUswSurface@@@Z
    0x5357B0 | void __fastcall __setupUVIZ(struct swSurface *) | ?__setupUVIZ@@YIXPAUswSurface@@@Z
    0x535890 | void __fastcall __setupNone(struct swSurface *) | ?__setupNone@@YIXPAUswSurface@@@Z
    0x5358A0 | void __fastcall __spanLinear(struct swSurface *,int) | ?__spanLinear@@YIXPAUswSurface@@H@Z
    0x5358D0 | void __fastcall __spanLinearZwrite(struct swSurface *,int) | ?__spanLinearZwrite@@YIXPAUswSurface@@H@Z
    0x535910 | void __fastcall __emitZwrite(struct swSurface *,int) | ?__emitZwrite@@YIXPAUswSurface@@H@Z
    0x5359D0 | void __fastcall __spanPerspXY(struct swSurface *,int) | ?__spanPerspXY@@YIXPAUswSurface@@H@Z
    0x535BD0 | void __fastcall __spanPerspXYZwrite(struct swSurface *,int) | ?__spanPerspXYZwrite@@YIXPAUswSurface@@H@Z
    0x535BF0 | void __cdecl swScanSurface(struct swSurface *) | ?swScanSurface@@YAXPAUswSurface@@@Z
    0x535E30 | struct swSurface * __cdecl swInitSurface(struct agiScreenVtx,struct agiScreenVtx,struct agiScreenVtx,unsigned int) | ?swInitSurface@@YAPAUswSurface@@UagiScreenVtx@@00I@Z
    0x5367C0 | void __fastcall __emitSemiBlack(int) | ?__emitSemiBlack@@YIXH@Z
    0x536800 | void __fastcall __emitStippleBlack(int) | ?__emitStippleBlack@@YIXH@Z
    0x536840 | int __cdecl swComputeIntensity(struct agiScreenVtx &) | ?swComputeIntensity@@YAHAAUagiScreenVtx@@@Z
    0x536880 | void __cdecl swScanSurfaces(void) | ?swScanSurfaces@@YAXXZ
    0x536940 | void __cdecl emms(void) | ?emms@@YAXXZ
    0x536950 | void __cdecl swTri(struct agiScreenVtx *,struct agiScreenVtx *,struct agiScreenVtx *) | ?swTri@@YAXPAUagiScreenVtx@@00@Z
    0x536B10 | void __cdecl swQuad(struct agiScreenVtx *,struct agiScreenVtx *,struct agiScreenVtx *,struct agiScreenVtx *) | ?swQuad@@YAXPAUagiScreenVtx@@000@Z
    0x536EE0 | void __cdecl swPoly(struct agiScreenVtx *,int) | ?swPoly@@YAXPAUagiScreenVtx@@H@Z
    0x537270 | void __cdecl swLineInt(int,int,int,int,int) | ?swLineInt@@YAXHHHHH@Z
    0x537360 | void __cdecl swLine(struct agiScreenVtx *,struct agiScreenVtx *) | ?swLine@@YAXPAUagiScreenVtx@@0@Z
    0x537410 | void __cdecl swKill(void) | ?swKill@@YAXXZ
    0x537440 | void __cdecl swSetInterlace(int) | ?swSetInterlace@@YAXH@Z
    0x537480 | void __cdecl swInit(void) | ?swInit@@YAXXZ
    0x537550 | unsigned int __cdecl swFindColor555(unsigned int) | ?swFindColor555@@YAII@Z
    0x537590 | unsigned int __cdecl swFindColor565(unsigned int) | ?swFindColor565@@YAII@Z
    0x5375D0 | unsigned int __fastcall swClampAddColor565(unsigned int) | ?swClampAddColor565@@YIII@Z
    0x537610 | unsigned int __fastcall swClampAddColor555(unsigned int) | ?swClampAddColor555@@YIII@Z
    0x537650 | unsigned int __fastcall swClampAdd565(unsigned int,unsigned int) | ?swClampAdd565@@YIIII@Z
    0x537690 | unsigned int __fastcall swClampAdd555(unsigned int,unsigned int) | ?swClampAdd555@@YIIII@Z
    0x652048 | int swFbWidth | ?swFbWidth@@3HA
    0x65204C | int swFbHeight | ?swFbHeight@@3HA
    0x65225C | int FLIPWINDING | ?FLIPWINDING@@3HA
    0x652260 | int BACKFACE | ?BACKFACE@@3HA
    0x652264 | int XPTHRESH | ?XPTHRESH@@3HA
    0x652268 | int YPTHRESH | ?YPTHRESH@@3HA
    0x65226C | int PERSP2 | ?PERSP2@@3HA
    0x652270 | float PERSP_THRESH | ?PERSP_THRESH@@3MA
    0x6522C0 | int QUADS | ?QUADS@@3HA
    0x795F48 | unsigned short * swDepthBuffer | ?swDepthBuffer@@3PAGA
    0x795F4C | int FLIPLOD | ?FLIPLOD@@3HA
    0x795F50 | void * swScreen | ?swScreen@@3PAXA
    0x795F54 | unsigned short * swCurrentDepthLine | ?swCurrentDepthLine@@3PAGA
    0x795F5C | union swr_sizes_t swr_sizes | ?swr_sizes@@3Tswr_sizes_t@@A
    0x795F60 | void (__cdecl* swFbStartFrame)(void) | ?swFbStartFrame@@3P6AXXZA
    0x795F68 | int swr_color | ?swr_color@@3HA
    0x795F6C | int swr_texmask | ?swr_texmask@@3HA
    0x795F70 | int EnableParabolic | ?EnableParabolic@@3HA
    0x795F74 | void (__cdecl* swFbEndFrame)(void) | ?swFbEndFrame@@3P6AXXZA
    0x795F78 | int swPixelSizeShift | ?swPixelSizeShift@@3HA
    0x795F7C | unsigned char * swStippleTest | ?swStippleTest@@3PAEA
    0x795F80 | int swr_di | ?swr_di@@3HA
    0x795F84 | int debugTri | ?debugTri@@3HA
    0x795F88 | int swr_du | ?swr_du@@3HA
    0x795F8C | int swr_dv | ?swr_dv@@3HA
    0x795F90 | int swr_dz | ?swr_dz@@3HA
    0x795F98 | unsigned short * swr_zb | ?swr_zb@@3PAGA
    0x795FA0 | int swGreenMask | ?swGreenMask@@3HA
    0x795FA8 | int debugTriGate | ?debugTriGate@@3HA
    0x795FAC | unsigned int swActualScreenStride | ?swActualScreenStride@@3IA
    0x795FB0 | unsigned int (__fastcall* swClampAdd)(unsigned int,unsigned int) | ?swClampAdd@@3P6IIII@ZA
    0x795FF8 | void (__cdecl* swFbStartScene)(void) | ?swFbStartScene@@3P6AXXZA
    0x795FFC | int swBlueMask | ?swBlueMask@@3HA
    0x796044 | int swIsInterlaced | ?swIsInterlaced@@3HA
    0x796048 | int BADEDGE | ?BADEDGE@@3HA
    0x79604C | int swr_texstride | ?swr_texstride@@3HA
    0x796090 | int swr_i | ?swr_i@@3HA
    0x796094 | int swr_ddu | ?swr_ddu@@3HA
    0x796098 | int swr_ddv | ?swr_ddv@@3HA
    0x79609C | int swr_u | ?swr_u@@3HA
    0x7960A0 | int swr_v | ?swr_v@@3HA
    0x7960A4 | int swr_z | ?swr_z@@3HA
    0x7960AC | void * swCurrentScanline | ?swCurrentScanline@@3PAXA
    0x7960B0 | int swBytesPerPixel | ?swBytesPerPixel@@3HA
    0x7960B4 | void * swFbParent | ?swFbParent@@3PAXA
    0x7960B8 | unsigned int swFrameOffset | ?swFrameOffset@@3IA
    0x7960BC | void (__cdecl* swFbEnd)(void) | ?swFbEnd@@3P6AXXZA
    0x7960C0 | int swRedMask | ?swRedMask@@3HA
    0x7960C4 | void * swr_dest | ?swr_dest@@3PAXA
    0x7960C8 | void (__cdecl* swFbEndScene)(void) | ?swFbEndScene@@3P6AXXZA
    0x7960CC | void (__cdecl* swFbStart)(void) | ?swFbStart@@3P6AXXZA
    0x7960D0 | unsigned short * swCurrentLut | ?swCurrentLut@@3PAGA
    0x79BEE4 | int swr_texshift | ?swr_texshift@@3HA
    0x79BEE8 | int debugTriMatch | ?debugTriMatch@@3HA
    0x79BEF0 | struct swRastInfo swInfo | ?swInfo@@3UswRastInfo@@A
    0x79FF00 | void * swr_src | ?swr_src@@3PAXA
    0x79FF04 | unsigned int swScreenStride | ?swScreenStride@@3IA
    0x79FF08 | int swFbX | ?swFbX@@3HA
    0x79FF0C | int swFbY | ?swFbY@@3HA
    0x79FF10 | int LODBIAS | ?LODBIAS@@3HA
*/

struct agiScreenVtx;
struct swr_sizes_t;
struct swRastInfo;
struct swSurface;

// ?__emitDebug@@YIXPAUswSurface@@H@Z | unused
ARTS_IMPORT void ARTS_FASTCALL __emitDebug(swSurface* arg1, i32 arg2);

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

// ?__setupUVI@@YIXPAUswSurface@@@Z | unused
ARTS_IMPORT void ARTS_FASTCALL __setupUVI(swSurface* arg1);

// ?__setupUVIZ@@YIXPAUswSurface@@@Z | unused
ARTS_IMPORT void ARTS_FASTCALL __setupUVIZ(swSurface* arg1);

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
ARTS_EXPORT void swLine(agiScreenVtx* start, agiScreenVtx* end);

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
