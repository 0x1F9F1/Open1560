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

constexpr bool WANT_WIDESCREEN = true;

i32 WINAPI ModeCallback(DDSURFACEDESC2* sd, void* ctx)
{
    export_hook(0x175F40);

    dxiRendererInfo_t* info = static_cast<dxiRendererInfo_t*>(ctx);

    if (info->ResCount < 32)
    {
        float ar = static_cast<float>(sd->dwWidth) / static_cast<float>(sd->dwHeight);

        if (sd->dwWidth >= 640 && sd->dwHeight >= 480 && sd->ddpfPixelFormat.dwRGBBitCount == 32 &&
            (ar > 1.6f) == WANT_WIDESCREEN)
        {
            info->Resolutions[info->ResCount].uWidth = static_cast<uint16_t>(sd->dwWidth);
            info->Resolutions[info->ResCount].uHeight = static_cast<uint16_t>(sd->dwHeight);

            info->ResCount++;
        }
    }

    return 1;
}

i32 __stdcall MultiMonCallback(struct _GUID* arg1, char* arg2, char* arg3, void* arg4, void* arg5)
{
    return stub<stdcall_t<i32, struct _GUID*, char*, char*, void*, void*>>(
        0x175320_Offset, arg1, arg2, arg3, arg4, arg5);
}

void dxiConfig(i32 arg1, char** arg2)
{
    return stub<cdecl_t<void, i32, char**>>(0x175360_Offset, arg1, arg2);
}

define_dummy_symbol(pcwindis_dxsetup);
