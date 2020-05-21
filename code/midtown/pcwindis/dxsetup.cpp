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

define_dummy_symbol(pcwindis_dxsetup);

#include "dxsetup.h"

struct dxiResolution
{
    u16 uWidth;
    u16 uHeight;
    u32 uTexMem;
};

check_size(dxiResolution, 8);

struct dxiRendererInfo_t
{
    b32 Valid;
    i32 CurrentIndex;
    i32 Hardware2;
    i32 field_C;
    i32 bSmoothAlpha;
    i32 bAdditiveBlending;
    i32 bVertexFog;
    i32 bMultiTexture;
    i32 bTexturePalette;
    i32 bHaveMipmaps;

    // 0x2 | TextureQuality = 0, FogDistance = 450
    // 0x4 | PixelFog
    // 0x8 | agiMeshSet::HalfHeight *= 1.01
    i32 uSpecialFlags;
    char Name[64];
    GUID InterfaceGuid;
    GUID DriverGuid;
    u32 Type;
    dxiResolution Resolutions[32];
    i32 ResCount;
    u32 ResolutionIndex;
};

check_size(dxiRendererInfo_t, 0x198);

static mem::cmd_param PARAM_min_aspect {"minaspect"};
static mem::cmd_param PARAM_max_aspect {"maxaspect"};

i32 WINAPI ModeCallback(DDSURFACEDESC2* sd, void* ctx)
{
    export_hook(0x575F40);

    dxiRendererInfo_t* info = static_cast<dxiRendererInfo_t*>(ctx);

    if (info->ResCount < 32)
    {
        f32 ar = static_cast<f32>(sd->dwWidth) / static_cast<f32>(sd->dwHeight);

        if (sd->dwWidth >= 640 && sd->dwHeight >= 480 && sd->ddpfPixelFormat.dwRGBBitCount == 32 &&
            ar >= PARAM_min_aspect.get_or<f32>(1.6f) && ar <= PARAM_max_aspect.get_or<f32>(2.4f))
        {
            info->Resolutions[info->ResCount].uWidth = static_cast<u16>(sd->dwWidth);
            info->Resolutions[info->ResCount].uHeight = static_cast<u16>(sd->dwHeight);

            info->ResCount++;
        }
    }

    return 1;
}

i32 __stdcall MultiMonCallback(struct _GUID* arg1, char* arg2, char* arg3, void* arg4, void* arg5)
{
    return stub<stdcall_t<i32, struct _GUID*, char*, char*, void*, void*>>(0x575320, arg1, arg2, arg3, arg4, arg5);
}

void dxiConfig(i32 arg1, char** arg2)
{
    return stub<cdecl_t<void, i32, char**>>(0x575360, arg1, arg2);
}

static void AddRenderer(struct IDirectDraw4* arg1, struct _GUID* arg2, char* arg3)
{
    return stub<cdecl_t<void, struct IDirectDraw4*, struct _GUID*, char*>>(0x576000, arg1, arg2, arg3);
}

static i32 CheckSoftwareRenderer(struct IDirectDraw4* arg1, struct _GUID* arg2)
{
    return stub<cdecl_t<i32, struct IDirectDraw4*, struct _GUID*>>(0x575920, arg1, arg2);
}

static i32 __stdcall EnumCounter(struct _GUID* arg1, char* arg2, char* arg3, void* arg4)
{
    return stub<stdcall_t<i32, struct _GUID*, char*, char*, void*>>(0x575740, arg1, arg2, arg3, arg4);
}

static i32 __stdcall EnumTextures(struct _DDPIXELFORMAT* arg1, void* arg2)
{
    return stub<stdcall_t<i32, struct _DDPIXELFORMAT*, void*>>(0x576470, arg1, arg2);
}

i32 __stdcall EnumZ(DDPIXELFORMAT* ddpf, void* ctx)
{
    export_hook(0x575FD0);

    if (ddpf->dwRGBBitCount == 32)
        std::memcpy(ctx, ddpf, sizeof(*ddpf));

    return 1;
}

static void EnumerateRenderers2()
{
    return stub<cdecl_t<void>>(0x5757D0);
}

static i32 __stdcall Enumerator(struct _GUID* arg1, char* arg2, char* arg3, void* arg4)
{
    return stub<stdcall_t<i32, struct _GUID*, char*, char*, void*>>(0x576580, arg1, arg2, arg3, arg4);
}

static u32 GetSpecialFlags(u32 arg1, u32 arg2)
{
    return stub<cdecl_t<u32, u32, u32>>(0x5764B0, arg1, arg2);
}

static i32 LockScreen(struct IDirectDraw4* arg1)
{
    return stub<cdecl_t<i32, struct IDirectDraw4*>>(0x575A10, arg1);
}

static void MyDirectDrawEnumerate(i32(__stdcall* arg1)(struct _GUID*, char*, char*, void*), void* arg2)
{
    return stub<cdecl_t<void, i32(__stdcall*)(struct _GUID*, char*, char*, void*), void*>>(0x575760, arg1, arg2);
}

static void NeedDX6()
{
    return stub<cdecl_t<void>>(0x575710);
}

static i32 NotLameChipset(u32 arg1, u32 arg2)
{
    return stub<cdecl_t<i32, u32, u32>>(0x5764A0, arg1, arg2);
}

static i32 TestResolution(struct IDirectDraw4* arg1, struct dxiRendererInfo_t& arg2)
{
    return stub<cdecl_t<i32, struct IDirectDraw4*, struct dxiRendererInfo_t&>>(0x575AF0, arg1, arg2);
}

static void UnlockScreen()
{
    return stub<cdecl_t<void>>(0x575AD0);
}

run_once([] {
    create_patch("TestResolution", "Unsigned Comparison", 0x575E34, "\x72", 1);
    create_patch("TestResolution", "Unsigned Comparison", 0x575E38, "\x72", 1);

    create_patch("Res String", "Unsigned Printf", 0x661890, "res %d x %d: %u %u / %u %u", 27);

    create_patch(
        "EliminatingRes String", "Unsigned Printf", 0x6618AC, "Eliminating res %d x %d; texmem=%u, vidmem=%u", 46);
});
