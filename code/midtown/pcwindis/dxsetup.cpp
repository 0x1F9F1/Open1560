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
#include "setupdata.h"

static mem::cmd_param PARAM_min_aspect {"minaspect"};
static mem::cmd_param PARAM_max_aspect {"maxaspect"};

// 0x576000 | ?AddRenderer@@YAXPAUIDirectDraw4@@PAU_GUID@@PAD@Z
ARTS_IMPORT /*static*/ void AddRenderer(struct IDirectDraw4* arg1, struct _GUID* arg2, char* arg3);

// 0x575920 | ?CheckSoftwareRenderer@@YAHPAUIDirectDraw4@@PAU_GUID@@@Z
ARTS_IMPORT /*static*/ i32 CheckSoftwareRenderer(struct IDirectDraw4* arg1, struct _GUID* arg2);

// 0x575740 | ?EnumCounter@@YGHPAU_GUID@@PAD1PAX@Z
ARTS_IMPORT /*static*/ i32 ARTS_STDCALL EnumCounter(struct _GUID* arg1, char* arg2, char* arg3, void* arg4);

// 0x576470 | ?EnumTextures@@YGJPAU_DDPIXELFORMAT@@PAX@Z
ARTS_IMPORT /*static*/ i32 ARTS_STDCALL EnumTextures(struct _DDPIXELFORMAT* arg1, void* arg2);

// 0x575FD0 | ?EnumZ@@YGJPAU_DDPIXELFORMAT@@PAX@Z
static long WINAPI EnumZ(DDPIXELFORMAT* ddpf, void* ctx)
{
    if (ddpf->dwRGBBitCount == 24)
        std::memcpy(ctx, ddpf, sizeof(*ddpf));

    return 1;
}

// 0x5757D0 | ?EnumerateRenderers2@@YAXXZ
ARTS_IMPORT /*static*/ void EnumerateRenderers2();

// 0x576580 | ?Enumerator@@YGHPAU_GUID@@PAD1PAX@Z
ARTS_IMPORT /*static*/ i32 ARTS_STDCALL Enumerator(struct _GUID* arg1, char* arg2, char* arg3, void* arg4);

// 0x5764B0 | ?GetSpecialFlags@@YAIKK@Z
ARTS_IMPORT /*static*/ u32 GetSpecialFlags(u32 arg1, u32 arg2);

// 0x575A10 | ?LockScreen@@YAJPAUIDirectDraw4@@@Z
ARTS_IMPORT /*static*/ i32 LockScreen(struct IDirectDraw4* arg1);

// 0x575F40 | ?ModeCallback@@YGJPAU_DDSURFACEDESC2@@PAX@Z
ARTS_EXPORT /*static*/ long WINAPI ModeCallback(DDSURFACEDESC2* sd, void* ctx)
{
    dxiRendererInfo_t* info = static_cast<dxiRendererInfo_t*>(ctx);

    if (info->ResCount < 32)
    {
        f32 ar = static_cast<f32>(sd->dwWidth) / static_cast<f32>(sd->dwHeight);

        if (sd->dwWidth >= 640 && sd->dwHeight >= 480 &&
            sd->ddpfPixelFormat.dwRGBBitCount == ((info->Type != 0) ? 32u : 16u) &&
            ar >= PARAM_min_aspect.get_or<f32>(1.6f) && ar <= PARAM_max_aspect.get_or<f32>(2.4f))
        {
            info->Resolutions[info->ResCount].uWidth = static_cast<u16>(sd->dwWidth);
            info->Resolutions[info->ResCount].uHeight = static_cast<u16>(sd->dwHeight);

            info->ResCount++;
        }
    }

    return 1;
}

// 0x575760 | ?MyDirectDrawEnumerate@@YAXP6GHPAU_GUID@@PAD1PAX@Z2@Z
ARTS_IMPORT /*static*/ void MyDirectDrawEnumerate(
    i32(ARTS_STDCALL* arg1)(struct _GUID*, char*, char*, void*), void* arg2);

// 0x575710 | ?NeedDX6@@YAXXZ
ARTS_IMPORT /*static*/ void NeedDX6();

// 0x5764A0 | ?NotLameChipset@@YAHKK@Z
ARTS_IMPORT /*static*/ i32 NotLameChipset(u32 arg1, u32 arg2);

// 0x575AF0 | ?TestResolution@@YAHPAUIDirectDraw4@@AAUdxiRendererInfo_t@@@Z
ARTS_IMPORT /*static*/ i32 TestResolution(struct IDirectDraw4* arg1, struct dxiRendererInfo_t& arg2);

// 0x575AD0 | ?UnlockScreen@@YAXXZ
ARTS_IMPORT /*static*/ void UnlockScreen();

run_once([] {
    auto_hook(0x575FD0, EnumZ);

    create_patch("TestResolution", "Unsigned Comparison", 0x575E34, "\x72", 1);
    create_patch("TestResolution", "Unsigned Comparison", 0x575E38, "\x72", 1);

    create_patch("Res String", "Unsigned Printf", 0x661890, "res %d x %d: %u %u / %u %u", 27);

    create_patch(
        "EliminatingRes String", "Unsigned Printf", 0x6618AC, "Eliminating res %d x %d; texmem=%u, vidmem=%u", 46);
});
