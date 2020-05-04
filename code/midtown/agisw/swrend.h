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
    0x535510 | void __fastcall __setupUV(struct swSurface *) | ?__setupUV@@YIXPAUswSurface@@@Z
    0x5355D0 | void __fastcall __setupUVZ(struct swSurface *) | ?__setupUVZ@@YIXPAUswSurface@@@Z
    0x5356A0 | void __fastcall __setupZ(struct swSurface *) | ?__setupZ@@YIXPAUswSurface@@@Z
    0x5356E0 | void __fastcall __setupUVI(struct swSurface *) | ?__setupUVI@@YIXPAUswSurface@@@Z
    0x5357B0 | void __fastcall __setupUVIZ(struct swSurface *) | ?__setupUVIZ@@YIXPAUswSurface@@@Z
    0x535890 | void __fastcall __setupNone(struct swSurface *) | ?__setupNone@@YIXPAUswSurface@@@Z
    0x5358A0 | void __fastcall __spanLinear(struct swSurface *,int) | ?__spanLinear@@YIXPAUswSurface@@H@Z
    0x5358D0 | void __fastcall __spanLinearZwrite(struct swSurface *,int) | ?__spanLinearZwrite@@YIXPAUswSurface@@H@Z
    0x5359D0 | void __fastcall __spanPerspXY(struct swSurface *,int) | ?__spanPerspXY@@YIXPAUswSurface@@H@Z
    0x535BD0 | void __fastcall __spanPerspXYZwrite(struct swSurface *,int) | ?__spanPerspXYZwrite@@YIXPAUswSurface@@H@Z
    0x535BF0 | void __cdecl swScanSurface(struct swSurface *) | ?swScanSurface@@YAXPAUswSurface@@@Z
    0x535E30 | struct swSurface * __cdecl swInitSurface(struct agiScreenVtx,struct agiScreenVtx,struct agiScreenVtx,unsigned int) | ?swInitSurface@@YAPAUswSurface@@UagiScreenVtx@@00I@Z
    0x536880 | void __cdecl swScanSurfaces(void) | ?swScanSurfaces@@YAXXZ
    0x536950 | void __cdecl swTri(struct agiScreenVtx *,struct agiScreenVtx *,struct agiScreenVtx *) | ?swTri@@YAXPAUagiScreenVtx@@00@Z
    0x536B10 | void __cdecl swQuad(struct agiScreenVtx *,struct agiScreenVtx *,struct agiScreenVtx *,struct agiScreenVtx *) | ?swQuad@@YAXPAUagiScreenVtx@@000@Z
    0x536EE0 | void __cdecl swPoly(struct agiScreenVtx *,int) | ?swPoly@@YAXPAUagiScreenVtx@@H@Z
    0x537270 | void __cdecl swLineInt(int,int,int,int,int) | ?swLineInt@@YAXHHHHH@Z
    0x537360 | void __cdecl swLine(struct agiScreenVtx *,struct agiScreenVtx *) | ?swLine@@YAXPAUagiScreenVtx@@0@Z
    0x537410 | void __cdecl swKill(void) | ?swKill@@YAXXZ
    0x537440 | void __cdecl swSetInterlace(int) | ?swSetInterlace@@YAXH@Z
    0x537480 | void __cdecl swInit(void) | ?swInit@@YAXXZ
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

// 0x5351C0 | ?__emitDebug@@YIXPAUswSurface@@H@Z
void __fastcall __emitDebug(struct swSurface* arg1, i32 arg2);

// 0x535220 | ?__emitDepthComplexity@@YIXH@Z
void __fastcall __emitDepthComplexity(i32 arg1);

// 0x535260 | ?__emitSolid@@YIXH@Z
void __fastcall __emitSolid(i32 arg1);

// 0x5352B0 | ?__emitSolidZ@@YIXH@Z
void __fastcall __emitSolidZ(i32 arg1);

// 0x535320 | ?__emitWireframe@@YIXH@Z
void __fastcall __emitWireframe(i32 arg1);

// 0x535890 | ?__setupNone@@YIXPAUswSurface@@@Z
void __fastcall __setupNone(struct swSurface* arg1);

// 0x535510 | ?__setupUV@@YIXPAUswSurface@@@Z
void __fastcall __setupUV(struct swSurface* arg1);

// 0x5356E0 | ?__setupUVI@@YIXPAUswSurface@@@Z
void __fastcall __setupUVI(struct swSurface* arg1);

// 0x5357B0 | ?__setupUVIZ@@YIXPAUswSurface@@@Z
void __fastcall __setupUVIZ(struct swSurface* arg1);

// 0x5355D0 | ?__setupUVZ@@YIXPAUswSurface@@@Z
void __fastcall __setupUVZ(struct swSurface* arg1);

// 0x5356A0 | ?__setupZ@@YIXPAUswSurface@@@Z
void __fastcall __setupZ(struct swSurface* arg1);

// 0x5358A0 | ?__spanLinear@@YIXPAUswSurface@@H@Z
void __fastcall __spanLinear(struct swSurface* arg1, i32 arg2);

// 0x5358D0 | ?__spanLinearZwrite@@YIXPAUswSurface@@H@Z
void __fastcall __spanLinearZwrite(struct swSurface* arg1, i32 arg2);

// 0x5359D0 | ?__spanPerspXY@@YIXPAUswSurface@@H@Z
void __fastcall __spanPerspXY(struct swSurface* arg1, i32 arg2);

// 0x535BD0 | ?__spanPerspXYZwrite@@YIXPAUswSurface@@H@Z
void __fastcall __spanPerspXYZwrite(struct swSurface* arg1, i32 arg2);

// 0x535340 | ?swAddEdge@@YAXHH@Z
void swAddEdge(i32 arg1, i32 arg2);

// 0x537480 | ?swInit@@YAXXZ
void swInit();

// 0x535E30 | ?swInitSurface@@YAPAUswSurface@@UagiScreenVtx@@00I@Z
struct swSurface* swInitSurface(struct agiScreenVtx arg1, struct agiScreenVtx arg2, struct agiScreenVtx arg3, u32 arg4);

// 0x537410 | ?swKill@@YAXXZ
void swKill();

// 0x537360 | ?swLine@@YAXPAUagiScreenVtx@@0@Z
void swLine(struct agiScreenVtx* arg1, struct agiScreenVtx* arg2);

// 0x537270 | ?swLineInt@@YAXHHHHH@Z
void swLineInt(i32 arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5);

// 0x536EE0 | ?swPoly@@YAXPAUagiScreenVtx@@H@Z
void swPoly(struct agiScreenVtx* arg1, i32 arg2);

// 0x536B10 | ?swQuad@@YAXPAUagiScreenVtx@@000@Z
void swQuad(struct agiScreenVtx* arg1, struct agiScreenVtx* arg2, struct agiScreenVtx* arg3, struct agiScreenVtx* arg4);

// 0x535BF0 | ?swScanSurface@@YAXPAUswSurface@@@Z
void swScanSurface(struct swSurface* arg1);

// 0x536880 | ?swScanSurfaces@@YAXXZ
void swScanSurfaces();

// 0x537440 | ?swSetInterlace@@YAXH@Z
void swSetInterlace(i32 arg1);

// 0x536950 | ?swTri@@YAXPAUagiScreenVtx@@00@Z
void swTri(struct agiScreenVtx* arg1, struct agiScreenVtx* arg2, struct agiScreenVtx* arg3);

// 0x652260 | ?BACKFACE@@3HA
inline extern_var(0x252260_Offset, i32, BACKFACE);

// 0x796048 | ?BADEDGE@@3HA
inline extern_var(0x396048_Offset, i32, BADEDGE);

// 0x795F70 | ?EnableParabolic@@3HA
inline extern_var(0x395F70_Offset, i32, EnableParabolic);

// 0x795F4C | ?FLIPLOD@@3HA
inline extern_var(0x395F4C_Offset, i32, FLIPLOD);

// 0x65225C | ?FLIPWINDING@@3HA
inline extern_var(0x25225C_Offset, i32, FLIPWINDING);

// 0x79FF10 | ?LODBIAS@@3HA
inline extern_var(0x39FF10_Offset, i32, LODBIAS);

// 0x65226C | ?PERSP2@@3HA
inline extern_var(0x25226C_Offset, i32, PERSP2);

// 0x652270 | ?PERSP_THRESH@@3MA
inline extern_var(0x252270_Offset, f32, PERSP_THRESH);

// 0x6522C0 | ?QUADS@@3HA
inline extern_var(0x2522C0_Offset, i32, QUADS);

// 0x652264 | ?XPTHRESH@@3HA
inline extern_var(0x252264_Offset, i32, XPTHRESH);

// 0x652268 | ?YPTHRESH@@3HA
inline extern_var(0x252268_Offset, i32, YPTHRESH);

// 0x795F84 | ?debugTri@@3HA
inline extern_var(0x395F84_Offset, i32, debugTri);

// 0x795FA8 | ?debugTriGate@@3HA
inline extern_var(0x395FA8_Offset, i32, debugTriGate);

// 0x79BEE8 | ?debugTriMatch@@3HA
inline extern_var(0x39BEE8_Offset, i32, debugTriMatch);

// 0x795FAC | ?swActualScreenStride@@3IA
inline extern_var(0x395FAC_Offset, u32, swActualScreenStride);

// 0x795FFC | ?swBlueMask@@3HA
inline extern_var(0x395FFC_Offset, i32, swBlueMask);

// 0x7960B0 | ?swBytesPerPixel@@3HA
inline extern_var(0x3960B0_Offset, i32, swBytesPerPixel);

// 0x795FB0 | ?swClampAdd@@3P6IIII@ZA
inline extern_var(0x395FB0_Offset, u32(__fastcall*)(u32, u32), swClampAdd);

// 0x795F54 | ?swCurrentDepthLine@@3PAGA
inline extern_var(0x395F54_Offset, u16*, swCurrentDepthLine);

// 0x7960D0 | ?swCurrentLut@@3PAGA
inline extern_var(0x3960D0_Offset, u16*, swCurrentLut);

// 0x7960AC | ?swCurrentScanline@@3PAXA
inline extern_var(0x3960AC_Offset, void*, swCurrentScanline);

// 0x795F48 | ?swDepthBuffer@@3PAGA
inline extern_var(0x395F48_Offset, u16*, swDepthBuffer);

// 0x7960BC | ?swFbEnd@@3P6AXXZA
inline extern_var(0x3960BC_Offset, void (*)(void), swFbEnd);

// 0x795F74 | ?swFbEndFrame@@3P6AXXZA
inline extern_var(0x395F74_Offset, void (*)(void), swFbEndFrame);

// 0x7960C8 | ?swFbEndScene@@3P6AXXZA
inline extern_var(0x3960C8_Offset, void (*)(void), swFbEndScene);

// 0x65204C | ?swFbHeight@@3HA
inline extern_var(0x25204C_Offset, i32, swFbHeight);

// 0x7960B4 | ?swFbParent@@3PAXA
inline extern_var(0x3960B4_Offset, void*, swFbParent);

// 0x7960CC | ?swFbStart@@3P6AXXZA
inline extern_var(0x3960CC_Offset, void (*)(void), swFbStart);

// 0x795F60 | ?swFbStartFrame@@3P6AXXZA
inline extern_var(0x395F60_Offset, void (*)(void), swFbStartFrame);

// 0x795FF8 | ?swFbStartScene@@3P6AXXZA
inline extern_var(0x395FF8_Offset, void (*)(void), swFbStartScene);

// 0x652048 | ?swFbWidth@@3HA
inline extern_var(0x252048_Offset, i32, swFbWidth);

// 0x79FF08 | ?swFbX@@3HA
inline extern_var(0x39FF08_Offset, i32, swFbX);

// 0x79FF0C | ?swFbY@@3HA
inline extern_var(0x39FF0C_Offset, i32, swFbY);

// 0x7960B8 | ?swFrameOffset@@3IA
inline extern_var(0x3960B8_Offset, u32, swFrameOffset);

// 0x795FA0 | ?swGreenMask@@3HA
inline extern_var(0x395FA0_Offset, i32, swGreenMask);

// 0x79BEF0 | ?swInfo@@3UswRastInfo@@A
inline extern_var(0x39BEF0_Offset, struct swRastInfo, swInfo);

// 0x796044 | ?swIsInterlaced@@3HA
inline extern_var(0x396044_Offset, i32, swIsInterlaced);

// 0x795F78 | ?swPixelSizeShift@@3HA
inline extern_var(0x395F78_Offset, i32, swPixelSizeShift);

// 0x7960C0 | ?swRedMask@@3HA
inline extern_var(0x3960C0_Offset, i32, swRedMask);

// 0x795F50 | ?swScreen@@3PAXA
inline extern_var(0x395F50_Offset, void*, swScreen);

// 0x79FF04 | ?swScreenStride@@3IA
inline extern_var(0x39FF04_Offset, u32, swScreenStride);

// 0x795F7C | ?swStippleTest@@3PAEA
inline extern_var(0x395F7C_Offset, u8*, swStippleTest);

// 0x795F68 | ?swr_color@@3HA
inline extern_var(0x395F68_Offset, i32, swr_color);

// 0x796094 | ?swr_ddu@@3HA
inline extern_var(0x396094_Offset, i32, swr_ddu);

// 0x796098 | ?swr_ddv@@3HA
inline extern_var(0x396098_Offset, i32, swr_ddv);

// 0x7960C4 | ?swr_dest@@3PAXA
inline extern_var(0x3960C4_Offset, void*, swr_dest);

// 0x795F80 | ?swr_di@@3HA
inline extern_var(0x395F80_Offset, i32, swr_di);

// 0x795F88 | ?swr_du@@3HA
inline extern_var(0x395F88_Offset, i32, swr_du);

// 0x795F8C | ?swr_dv@@3HA
inline extern_var(0x395F8C_Offset, i32, swr_dv);

// 0x795F90 | ?swr_dz@@3HA
inline extern_var(0x395F90_Offset, i32, swr_dz);

// 0x796090 | ?swr_i@@3HA
inline extern_var(0x396090_Offset, i32, swr_i);

// 0x795F5C | ?swr_sizes@@3Tswr_sizes_t@@A
inline extern_var(0x395F5C_Offset, union swr_sizes_t, swr_sizes);

// 0x79FF00 | ?swr_src@@3PAXA
inline extern_var(0x39FF00_Offset, void*, swr_src);

// 0x795F6C | ?swr_texmask@@3HA
inline extern_var(0x395F6C_Offset, i32, swr_texmask);

// 0x79BEE4 | ?swr_texshift@@3HA
inline extern_var(0x39BEE4_Offset, i32, swr_texshift);

// 0x79604C | ?swr_texstride@@3HA
inline extern_var(0x39604C_Offset, i32, swr_texstride);

// 0x79609C | ?swr_u@@3HA
inline extern_var(0x39609C_Offset, i32, swr_u);

// 0x7960A0 | ?swr_v@@3HA
inline extern_var(0x3960A0_Offset, i32, swr_v);

// 0x7960A4 | ?swr_z@@3HA
inline extern_var(0x3960A4_Offset, i32, swr_z);

// 0x795F98 | ?swr_zb@@3PAGA
inline extern_var(0x395F98_Offset, u16*, swr_zb);
