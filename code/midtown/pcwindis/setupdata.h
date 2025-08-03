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

#include <guiddef.h>

struct dxiResolution
{
    u16 uWidth;
    u16 uHeight;
    u32 uTexMem;
};

check_size(dxiResolution, 8);

enum class dxiRendererType : i32
{
    Invalid = -1,
    Removed_DX6_Soft = 0, // DX6 Software
    Removed_DX6_GDI = 1,  // DX6 Hardware (Primary Surface)
    Removed_DX6 = 2,      // DX6 Hardware
    OpenGL = 3,           // OpenGL Hardware
    SDL2 = 4,             // SDL_Renderer Software
};

struct dxiRendererInfo_t
{
    b32 Valid;
    b32 Usable;
    dxiRendererType Type2; // Assigned to, but unused

    // 0xA6 for Software
    // 0x85 for Hardware
    u32 Flags;

    b32 SmoothAlpha;
    b32 AdditiveBlending;
    b32 VertexFog;
    b32 MultiTexture;
    b32 TexturePalette;
    b32 HaveMipmaps;

    // 0x1 | Use Software Renderer
    // 0x2 | TextureQuality = 0, FogDistance = 450
    // 0x4 | NoColorKey
    // 0x8 | agiMeshSet::HalfHeight *= 1.01
    // 0x10 | UsePixelFog, ShadowZBias = 0.001 (1588+)
    // 0x20 | Hardware Clipping (Open1560+)
    u32 SpecialFlags;
    char Name[64];

    union
    {
        struct
        {
            GUID Interface;
            GUID Driver;
        } DX6;

        struct
        {
            u32 Format;
            i32 RefreshRate;
            i32 Left;
            i32 Top;
            u32 Width;
            u32 Height;
            i32 Index;
            u32 Padding;
        } SDL;
    };

    dxiRendererType Type;

    dxiResolution Resolutions[32];
    i32 ResCount;
    i32 ResChoice;
};

check_size(dxiRendererInfo_t, 0x198);

// ?dxiReadConfigFile@@YAHXZ
b32 dxiReadConfigFile();

// ?dxiWriteConfigFile@@YAXXZ
ARTS_EXPORT void dxiWriteConfigFile();

// ?dxiResClosestMatch@@YAHHHH@Z
i32 dxiResClosestMatch(i32 renderer, i32 width, i32 height);

// ?dxiResGetRecommended@@YAHHH@Z
ARTS_EXPORT i32 dxiResGetRecommended(i32 renderer, i32 cpu_speed);

// ?dxiInfo@@3PAUdxiRendererInfo_t@@A
ARTS_EXPORT extern dxiRendererInfo_t dxiInfo[16];

// ?dxiRendererChoice@@3HA
ARTS_EXPORT extern i32 dxiRendererChoice;

// ?dxiRendererCount@@3HA
ARTS_EXPORT extern i32 dxiRendererCount;

inline dxiRendererInfo_t& GetRendererInfo()
{
    return dxiInfo[dxiRendererChoice];
}

inline bool IsSoftwareRenderer(dxiRendererType type)
{
    return (type == dxiRendererType::SDL2);
}

inline bool IsSDLRenderer(dxiRendererType type)
{
    return (type == dxiRendererType::OpenGL) || (type == dxiRendererType::SDL2);
}
