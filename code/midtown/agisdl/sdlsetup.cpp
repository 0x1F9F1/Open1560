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

#include "sdlsetup.h"

#include "pcwindis/setupdata.h"

#include <SDL_video.h>
#include <numeric>

static u32 GetSpecialFlags(dxiRendererType type)
{
    if (type == dxiRendererType::OpenGL)
        return 0x10 | 0x20;

    return 0;
}

static void AddVideoDisplay(i32 index, dxiRendererType type)
{
    if (dxiRendererCount >= ARTS_SSIZE(dxiInfo))
        return;

    dxiRendererInfo_t& info = dxiInfo[dxiRendererCount];

    info = {};

    info.Valid = true;
    info.Usable = true;
    info.Type2 = type;
    info.Flags = 0;

    info.SmoothAlpha = (type != dxiRendererType::SDL2);
    info.AdditiveBlending = true;
    info.VertexFog = true;
    info.MultiTexture = true;
    info.TexturePalette = true;
    info.HaveMipmaps = true;
    info.SpecialFlags = GetSpecialFlags(type);

    const char* name = SDL_GetDisplayName(index);
    if (name == nullptr)
        return;

    SDL_Rect bounds;
    if (SDL_GetDisplayBounds(index, &bounds) != 0)
        return;

    SDL_DisplayMode mode;
    if (SDL_GetDesktopDisplayMode(index, &mode) != 0)
        return;

    arts_strncpy(info.Name, name, ARTS_TRUNCATE);

    if (type == dxiRendererType::SDL2)
        arts_strncat(info.Name, " (Software)", ARTS_TRUNCATE);

    // Pipes are used as the list separator
    for (char* s = info.Name; *s; ++s)
    {
        if (*s == '|')
            *s = ' ';
    }

    info.SDL.Left = bounds.x;
    info.SDL.Top = bounds.y;
    info.SDL.Width = bounds.w;
    info.SDL.Height = bounds.h;
    info.SDL.Format = mode.format;
    info.SDL.RefreshRate = mode.refresh_rate;

    info.Type = type;

    info.ResCount = 0;
    info.ResChoice = -1;

    Displayf("Renderer: '%s' @ {%i,%i}, Refresh=%i", info.Name, info.SDL.Left, info.SDL.Top, info.SDL.RefreshRate);

    // Choosing resolutions to list is fairly arbitrary for two main reasons:
    // * By default the OpenGL pipe always renders using the native resolution, so only the UI is affected.
    // * Frame buffers support arbitrary resolutions.
    // TODO: Allow picking a custom resolution in the UI, similar to -width/-height

    const auto add_resolution = [&](u32 width, u32 height) {
        if (height < 480 || height > info.SDL.Height)
            return false;

        if (width < 640 || width > info.SDL.Width)
            return false;

        for (i32 i = 0; i < info.ResCount; ++i)
        {
            if (dxiResolution& res = info.Resolutions[i]; res.uWidth == width && res.uHeight == height)
                return false;
        }

        info.Resolutions[info.ResCount++] =
            dxiResolution {static_cast<u16>(width), static_cast<u16>(height), 128 << 20};

        Displayf("Resolution: %u x %u", width, height);
        return true;
    };

    u32 max_scale = std::gcd(info.SDL.Width, info.SDL.Height);
    u32 aspect_w = info.SDL.Width / max_scale;
    u32 aspect_h = info.SDL.Height / max_scale;

    const auto add_height = [&](u32 height) {
        // TODO: Add 16:9 if the monitor is ultra-wide?
        add_resolution((height * aspect_w) / aspect_h, height);
        add_resolution((height * 4) / 3, height);
    };

    add_height(480);

    u32 curr_height = info.SDL.Height;

    for (;; curr_height /= 2)
    {
        add_height(curr_height);

        if (curr_height <= 2048)
            break;
    }

    static const u32 small_height_ratios[][2] {
        {4, 5}, // 80%
        {3, 4}, // 75%
        {2, 3}, // 66%
        {1, 2}, // 50%
        {2, 5}, // 40%
        {1, 3}, // 33%
        {1, 4}, // 25%
    };

    for (const u32* ratio : small_height_ratios)
    {
        u32 height = (curr_height * ratio[0]) / ratio[1];

        static const u32 valid_small_heights[] {480, 540, 576, 600, 720, 768, 800, 900, 960, 1080};

        if (std::find(std::begin(valid_small_heights), std::end(valid_small_heights), height) !=
            std::end(valid_small_heights))
        {
            add_height(height);
        }
    }

    if (info.ResCount == 0)
        return;

    std::sort(
        info.Resolutions, info.Resolutions + info.ResCount, [](const dxiResolution& lhs, const dxiResolution& rhs) {
            return (lhs.uHeight != rhs.uHeight) ? (lhs.uHeight < rhs.uHeight) : (lhs.uWidth < rhs.uWidth);
        });

    if (info.SDL.Left == 0 && info.SDL.Top == 0 && dxiRendererChoice == -1)
    {
        Displayf("Display '%s' (%i) is primary", info.Name, dxiRendererCount);
        arts_strncat(info.Name, " (Primary)", ARTS_TRUNCATE);
        dxiRendererChoice = dxiRendererCount;
    }

    ++dxiRendererCount;
}

void EnumerateRenderersSDL()
{
    dxiRendererCount = 0;
    dxiRendererChoice = -1;

    for (i32 i = 0, count = SDL_GetNumVideoDisplays(); i < count; ++i)
        AddVideoDisplay(i, dxiRendererType::OpenGL);

    for (i32 i = 0, count = SDL_GetNumVideoDisplays(); i < count; ++i)
        AddVideoDisplay(i, dxiRendererType::SDL2);

    if (dxiRendererCount == 0)
        Quitf("No Valid Renderers");

    if (dxiRendererChoice == -1)
        dxiRendererChoice = 0;

    for (i32 i = 0; i < dxiRendererCount; ++i)
    {
        dxiRendererInfo_t& info = dxiInfo[i];

        if (info.ResChoice == -1)
            info.ResChoice = dxiResGetRecommended(i, 0);
    }
}

bool ValidateRenderersSDL()
{
    for (i32 i = 0; i < dxiRendererCount; ++i)
    {
        dxiRendererInfo_t& info = dxiInfo[i];

        if (info.Type != dxiRendererType::OpenGL && info.Type != dxiRendererType::SDL2)
            return false;

        info.SDL.Index = -1;
    }

    for (i32 i = 0, count = SDL_GetNumVideoDisplays(); i < count; ++i)
    {
        const char* name = SDL_GetDisplayName(i);
        if (name == nullptr)
            continue;

        SDL_Rect bounds;
        if (SDL_GetDisplayBounds(i, &bounds) != 0)
            continue;

        SDL_DisplayMode mode;
        if (SDL_GetDesktopDisplayMode(i, &mode) != 0)
            continue;

        bool found = false;

        for (i32 j = 0; j < dxiRendererCount; ++j)
        {
            dxiRendererInfo_t& info = dxiInfo[j];

            if (info.SpecialFlags != GetSpecialFlags(info.Type))
                continue;

            if (std::strncmp(info.Name, name, std::min(ARTS_SIZE(info.Name), std::strlen(name))) != 0)
                continue;

            if ((info.SDL.Format != mode.format) || (info.SDL.RefreshRate != mode.refresh_rate))
                continue;

            if ((info.SDL.Left != bounds.x) || (info.SDL.Top != bounds.y))
                continue;

            if ((info.SDL.Width != static_cast<u32>(bounds.w)) || (info.SDL.Height != static_cast<u32>(bounds.h)))
                continue;

            info.SDL.Index = i;
            found = true;
        }

        if (!found)
            return false;
    }

    return true;
}
