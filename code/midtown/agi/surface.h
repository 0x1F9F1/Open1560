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
    0x55AAE0 | void __cdecl RescaleJpeg(unsigned int,unsigned int,unsigned char *,struct jpeg_decompress_struct &) | ?RescaleJpeg@@YAXIIPAEAAUjpeg_decompress_struct@@@Z
    0x55ADE0 | public: void __thiscall agiSurfaceDesc::Reload(char *,char *,int,int,class Stream *,int,int) | ?Reload@agiSurfaceDesc@@QAEXPAD0HHPAVStream@@HH@Z
    0x55B160 | public: void __thiscall agiSurfaceDesc::Unload(void) | ?Unload@agiSurfaceDesc@@QAEXXZ
    0x55B180 | public: void __thiscall agiSurfaceDesc::CopyFrom(class agiSurfaceDesc *,int) | ?CopyFrom@agiSurfaceDesc@@QAEXPAV1@H@Z
    0x55B510 | void __cdecl copyrow565_to_555(void *,void *,unsigned int,unsigned int) | ?copyrow565_to_555@@YAXPAX0II@Z
    0x55B560 | void __cdecl copyrow565_to_5551(void *,void *,unsigned int,unsigned int) | ?copyrow565_to_5551@@YAXPAX0II@Z
    0x55B5C0 | void __cdecl copyrow565_to_888(void *,void *,unsigned int,unsigned int) | ?copyrow565_to_888@@YAXPAX0II@Z
    0x55B640 | void __cdecl copyrow565_to_888rev(void *,void *,unsigned int,unsigned int) | ?copyrow565_to_888rev@@YAXPAX0II@Z
    0x55B6C0 | void __cdecl copyrow4444_to_8888(void *,void *,unsigned int,unsigned int) | ?copyrow4444_to_8888@@YAXPAX0II@Z
    0x55B750 | void __cdecl copyrow4444_to_8888rev(void *,void *,unsigned int,unsigned int) | ?copyrow4444_to_8888rev@@YAXPAX0II@Z
    0x55B7E0 | void __cdecl copyrow4444_to_555(void *,void *,unsigned int,unsigned int) | ?copyrow4444_to_555@@YAXPAX0II@Z
    0x55B860 | void __cdecl copyrow4444_to_565(void *,void *,unsigned int,unsigned int) | ?copyrow4444_to_565@@YAXPAX0II@Z
    0x55B8E0 | void __cdecl copyrow4444_to_5551(void *,void *,unsigned int,unsigned int) | ?copyrow4444_to_5551@@YAXPAX0II@Z
    0x903190 | int AnnotateTextures | ?AnnotateTextures@@3HA
*/

class agiTexParameters;

struct agiColorKey // DDCOLORKEY
{
    u32 Low {0};
    u32 High {0};
};

#define AGIPF_ALPHAPIXELS 0x00000001l
#define AGIPF_ALPHA 0x00000002l
#define AGIPF_FOURCC 0x00000004l
#define AGIPF_PALETTEINDEXED4 0x00000008l
#define AGIPF_PALETTEINDEXEDTO8 0x00000010l
#define AGIPF_PALETTEINDEXED8 0x00000020l
#define AGIPF_RGB 0x00000040l

struct agiPixelFormat // DDPIXELFORMAT
{
    u32 Size {0};
    u32 Flags {0};
    u32 FourCC {0};
    u32 RGBBitCount {0};
    u32 RBitMask {0};
    u32 GBitMask {0};
    u32 BBitMask {0};
    u32 RGBAlphaBitMask {0};
};

struct agiDDSCAPS2 // DDSCAPS2
{
    u32 Caps {0};
    u32 Caps2 {0};
    u32 Caps3 {0};
    u32 Caps4 {0};
};

#define AGISD_HEIGHT 0x00000002l
#define AGISD_WIDTH 0x00000004l
#define AGISD_PITCH 0x00000008l
#define AGISD_MIPMAPCOUNT 0x00020000l
#define AGISD_CKDESTOVERLAY 0x00002000l
#define AGISD_CKDESTBLT 0x00004000l
#define AGISD_CKSRCOVERLAY 0x00008000l
#define AGISD_CKSRCBLT 0x00010000l

// TODO: Allow safe conversion to/from DDSURFACEDESC2 (instead of bitcasting)

class agiSurfaceDesc // DDSURFACEDESC2
{
public:
    // 0x55B180 | ?CopyFrom@agiSurfaceDesc@@QAEXPAV1@H@Z
    ARTS_EXPORT void CopyFrom(agiSurfaceDesc* src, i32 lod);

    void CopyFrom(agiSurfaceDesc* src, i32 lod, agiTexParameters* params);

    // 0x55ADE0 | ?Reload@agiSurfaceDesc@@QAEXPAD0HHPAVStream@@HH@Z
    ARTS_IMPORT void Reload(char* arg1, char* arg2, i32 arg3, i32 arg4, class Stream* arg5, i32 arg6, i32 arg7);

    // 0x55B160 | ?Unload@agiSurfaceDesc@@QAEXXZ
    ARTS_EXPORT void Unload();

    // 0x55A720 | ?Init@agiSurfaceDesc@@SAPAV1@HHAAV1@@Z
    [[nodiscard]] ARTS_EXPORT static Owner<agiSurfaceDesc*> Init(i32 width, i32 height, const agiSurfaceDesc& desc);

    // 0x55A7A0 | ?Load@agiSurfaceDesc@@SAPAV1@PAD0HHHH@Z
    [[nodiscard]] ARTS_IMPORT static Owner<agiSurfaceDesc*> Load(
        char* name, char* path, i32 index, i32 pack, i32 width, i32 height);

    void Clear(i32 x, i32 y, i32 width, i32 height);

    void Fill(i32 x, i32 y, i32 width, i32 height, u32 color);

    u32 Size {0};
    u32 Flags {0};
    u32 Height {0};
    u32 Width {0};
    i32 Pitch {0};
    u32 BackBufferCount {0};
    u32 MipMapCount {0};
    u32 AlphaBitDepth {0};

    union
    {
        // NOTE: 64-bit incompatible
        class agiTexLut* lpLut {0};
        char szLut[4];
    };

    void* Surface {nullptr};
    agiColorKey DestOverlay {};
    agiColorKey DestBlt {};
    agiColorKey SrcOverlay {};
    agiColorKey SrcBlt {};
    agiPixelFormat PixelFormat {};
    agiDDSCAPS2 SCaps {};
    u32 TextureStage {0};
};

check_size(agiSurfaceDesc, 0x7C);

// 0x903190 | ?AnnotateTextures@@3HA
ARTS_IMPORT extern i32 AnnotateTextures;
