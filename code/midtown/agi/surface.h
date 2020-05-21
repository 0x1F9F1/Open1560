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
    agi:surface

    0x55A720 | public: static class agiSurfaceDesc * __cdecl agiSurfaceDesc::Init(int,int,class agiSurfaceDesc &) | ?Init@agiSurfaceDesc@@SAPAV1@HHAAV1@@Z
    0x55A7A0 | public: static class agiSurfaceDesc * __cdecl agiSurfaceDesc::Load(char *,char *,int,int,int,int) | ?Load@agiSurfaceDesc@@SAPAV1@PAD0HHHH@Z
    0x55ADE0 | public: void __thiscall agiSurfaceDesc::Reload(char *,char *,int,int,class Stream *,int,int) | ?Reload@agiSurfaceDesc@@QAEXPAD0HHPAVStream@@HH@Z
    0x55B160 | public: void __thiscall agiSurfaceDesc::Unload(void) | ?Unload@agiSurfaceDesc@@QAEXXZ
    0x55B180 | public: void __thiscall agiSurfaceDesc::CopyFrom(class agiSurfaceDesc *,int) | ?CopyFrom@agiSurfaceDesc@@QAEXPAV1@H@Z
    0x903190 | int AnnotateTextures | ?AnnotateTextures@@3HA
    0x55AAE0 | void __cdecl RescaleJpeg(unsigned int,unsigned int,unsigned char *,struct jpeg_decompress_struct &) | ?RescaleJpeg@@YAXIIPAEAAUjpeg_decompress_struct@@@Z
    0x55B510 | void __cdecl copyrow565_to_555(void *,void *,unsigned int,unsigned int) | ?copyrow565_to_555@@YAXPAX0II@Z
    0x55B560 | void __cdecl copyrow565_to_5551(void *,void *,unsigned int,unsigned int) | ?copyrow565_to_5551@@YAXPAX0II@Z
    0x55B5C0 | void __cdecl copyrow565_to_888(void *,void *,unsigned int,unsigned int) | ?copyrow565_to_888@@YAXPAX0II@Z
    0x55B640 | void __cdecl copyrow565_to_888rev(void *,void *,unsigned int,unsigned int) | ?copyrow565_to_888rev@@YAXPAX0II@Z
    0x55B6C0 | void __cdecl copyrow4444_to_8888(void *,void *,unsigned int,unsigned int) | ?copyrow4444_to_8888@@YAXPAX0II@Z
    0x55B750 | void __cdecl copyrow4444_to_8888rev(void *,void *,unsigned int,unsigned int) | ?copyrow4444_to_8888rev@@YAXPAX0II@Z
    0x55B7E0 | void __cdecl copyrow4444_to_555(void *,void *,unsigned int,unsigned int) | ?copyrow4444_to_555@@YAXPAX0II@Z
    0x55B860 | void __cdecl copyrow4444_to_565(void *,void *,unsigned int,unsigned int) | ?copyrow4444_to_565@@YAXPAX0II@Z
    0x55B8E0 | void __cdecl copyrow4444_to_5551(void *,void *,unsigned int,unsigned int) | ?copyrow4444_to_5551@@YAXPAX0II@Z
*/

struct agiColorKey
{
    u32 dwColorSpaceLowValue {0};
    u32 dwColorSpaceHighValue {0};
};

struct agiPixelFormat
{
    u32 dwSize {0};
    u32 dwFlags {0};
    u32 dwFourCC {0};
    u32 dwRGBBitCount {0};
    u32 dwRBitMask {0};
    u32 dwGBitMask {0};
    u32 dwBBitMask {0};
    u32 dwRGBAlphaBitMask {0};
};

struct agiDDSCAPS2
{
    u32 dwCaps {0};
    u32 dwCaps2 {0};
    u32 dwCaps3 {0};
    u32 dwCaps4 {0};
};

#define AGISD_HEIGHT 0x00000002l
#define AGISD_WIDTH 0x00000004l

class agiSurfaceDesc // DDSURFACEDESC2
{
public:
    // 0x55B180 | ?CopyFrom@agiSurfaceDesc@@QAEXPAV1@H@Z
    void CopyFrom(class agiSurfaceDesc* src, i32 lod);

    // 0x55ADE0 | ?Reload@agiSurfaceDesc@@QAEXPAD0HHPAVStream@@HH@Z
    void Reload(char* arg1, char* arg2, i32 arg3, i32 arg4, class Stream* arg5, i32 arg6, i32 arg7);

    // 0x55B160 | ?Unload@agiSurfaceDesc@@QAEXXZ
    void Unload();

    // 0x55A720 | ?Init@agiSurfaceDesc@@SAPAV1@HHAAV1@@Z
    static class agiSurfaceDesc* Init(i32 width, i32 height, class agiSurfaceDesc& desc);

    // 0x55A7A0 | ?Load@agiSurfaceDesc@@SAPAV1@PAD0HHHH@Z
    static class agiSurfaceDesc* Load(char* arg1, char* arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6);

    u32 dwSize {0};
    u32 dwFlags {0};
    u32 dwHeight {0};
    u32 dwWidth {0};
    i32 lPitch {0};
    u32 dwBackBufferCount {0};
    u32 dwMipMapCount {0};
    u32 dwAlphaBitDepth {0};

    union
    {
        struct agiTexLut* lpLut {0};
        char szLut[4];
    };

    void* lpSurface {nullptr};
    agiColorKey ddckCKDestOverlay {};
    agiColorKey ddckCKDestBlt {};
    agiColorKey ddckCKSrcOverlay {};
    agiColorKey ddckCKSrcBlt {};
    agiPixelFormat ddpfPixelFormat {};
    agiDDSCAPS2 ddsCaps {};
    u32 dwTextureStage {0};
};

check_size(agiSurfaceDesc, 0x7C);

// 0x903190 | ?AnnotateTextures@@3HA
inline extern_var(0x903190, i32, AnnotateTextures);
