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

#include "glsetup.h"

#include "core/minwin.h"
#include "mmui/graphics.h"

#include "pcwindis/dxsetup.h"
#include "pcwindis/setupdata.h"

#include <numeric>

static void GetMonitorName(char* buffer, usize buflen, const char* szDevice)
{
    buffer[0] = '\0';

    DISPLAY_DEVICEA device {sizeof(device)};

    for (DWORD i = 0; EnumDisplayDevicesA(szDevice, i, &device, 0); ++i)
    {
        if (device.StateFlags & DISPLAY_DEVICE_MIRRORING_DRIVER)
            continue;

        if (device.StateFlags & DISPLAY_DEVICE_ACTIVE)
        {
            arts_snprintf(buffer, buflen, ARTS_TRUNCATE, "%s on ", device.DeviceString);

            break;
        }
    }

    arts_strncat(buffer, buflen, szDevice, ARTS_TRUNCATE);
}

static const u32 SpecialFlags_GL = 0x10 | 0x20;

static BOOL CALLBACK AddRendererCallback(HMONITOR hMonitor, [[maybe_unused]] HDC hdcMonitor,
    [[maybe_unused]] LPRECT lprcMonitor, [[maybe_unused]] LPARAM lParam)
{
    if (dxiRendererCount >= ARTS_SSIZE(dxiInfo))
        return FALSE;

    MONITORINFOEXA iMonitor {{sizeof(iMonitor)}};

    if (!GetMonitorInfoA(hMonitor, &iMonitor))
        return TRUE;

    dxiRendererInfo_t& info = dxiInfo[dxiRendererCount];

    info = {};

    info.Valid = true;
    info.Usable = true;
    info.Type2 = dxiRendererType::OpenGL;
    info.Flags = 0;

    info.SmoothAlpha = true;
    info.AdditiveBlending = true;
    info.VertexFog = true;
    info.MultiTexture = true;
    info.TexturePalette = true;
    info.HaveMipmaps = true;
    info.SpecialFlags = SpecialFlags_GL;

    GetMonitorName(info.Name, ARTS_SIZE(info.Name), iMonitor.szDevice);
    arts_strcpy(info.Device, iMonitor.szDevice);

    info.Type = dxiRendererType::OpenGL;

    info.ResCount = 0;
    info.ResChoice = -1;

    Displayf("Renderer: '%s'", info.Name);

    DEVMODEA cur_dev_mode {};

    if (!EnumDisplaySettingsA(iMonitor.szDevice, ENUM_CURRENT_SETTINGS, &cur_dev_mode))
    {
        Errorf("Failed to get monitor display settings");
        return TRUE;
    }

    // Choosing resolutions to list is fairly arbitrary for two main reasons:
    // * By default the OpenGL pipe always renders using the native resolution, so only the UI is affected.
    // * Frame buffers support arbitrary resolutions.
    // Asking EnumDisplaySettingsA is just as arbitrary, since that has no bearing what OpenGL supports.
    // So instead, try and pick a small set of fairly sane resolutions.
    // TODO: Allow picking a custom resolution in the UI, similar to -width/-height

    const auto add_resolution = [&](u32 width, u32 height) {
        if (height < 480 || height > cur_dev_mode.dmPelsHeight)
            return false;

        if (width < 640 || width > cur_dev_mode.dmPelsWidth)
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

    u32 max_scale = std::gcd(cur_dev_mode.dmPelsWidth, cur_dev_mode.dmPelsHeight);
    u32 aspect_w = cur_dev_mode.dmPelsWidth / max_scale;
    u32 aspect_h = cur_dev_mode.dmPelsHeight / max_scale;

    const auto add_height = [&](u32 height) {
        // TODO: Add 16:9 if the monitor is ultra-wide?
        add_resolution((height * aspect_w) / aspect_h, height);
        add_resolution((height * 4) / 3, height);
    };

    add_height(480);

    u32 curr_height = cur_dev_mode.dmPelsHeight;

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
        return TRUE;

    std::sort(
        info.Resolutions, info.Resolutions + info.ResCount, [](const dxiResolution& lhs, const dxiResolution& rhs) {
            return (lhs.uHeight != rhs.uHeight) ? (lhs.uHeight < rhs.uHeight) : (lhs.uWidth < rhs.uWidth);
        });

    if (iMonitor.dwFlags & MONITORINFOF_PRIMARY)
    {
        Displayf("Display '%s' (%i) is primary", info.Name, dxiRendererCount);

        if (dxiRendererChoice == -1)
            dxiRendererChoice = dxiRendererCount;
    }

    ++dxiRendererCount;

    return TRUE;
}

static BOOL CALLBACK CountRendererCallback(HMONITOR hMonitor, [[maybe_unused]] HDC hdcMonitor,
    [[maybe_unused]] LPRECT lprcMonitor, [[maybe_unused]] LPARAM lParam)
{
    MONITORINFOEXA iMonitor {{sizeof(iMonitor)}};

    if (!GetMonitorInfoA(hMonitor, &iMonitor))
        return TRUE;

    i32& count = *(i32*) (lParam);

    DEVMODEA cur_dev_mode {};

    if (!EnumDisplaySettingsA(iMonitor.szDevice, ENUM_CURRENT_SETTINGS, &cur_dev_mode))
        return TRUE;

    for (i32 i = 0; i < dxiRendererCount; ++i)
    {
        dxiRendererInfo_t& info = dxiInfo[i];

        if (info.Type != dxiRendererType::OpenGL)
            continue;

        if (info.SpecialFlags != SpecialFlags_GL)
            continue;

        if (std::strcmp(iMonitor.szDevice, info.Device))
            continue;

        char name[64] {};
        GetMonitorName(name, ARTS_SIZE(name), iMonitor.szDevice);

        if (std::strcmp(name, info.Name))
            continue;

        if (info.ResCount == 0)
            break;

        if (dxiResolution& res = info.Resolutions[info.ResCount - 1];
            res.uWidth != cur_dev_mode.dmPelsWidth || res.uHeight != cur_dev_mode.dmPelsHeight)
            break;

        ++count;
        return TRUE;
    }

    count = -1;
    return FALSE;
}

void EnumerateRenderersGL()
{
    dxiRendererCount = 0;
    dxiRendererChoice = -1;

    EnumDisplayMonitors(NULL, NULL, AddRendererCallback, NULL);

    if (dxiRendererCount == 0)
        Quitf("No Valid Renderers");

    if (dxiRendererChoice == -1)
        dxiRendererChoice = 0;

    for (i32 i = 0; i < dxiRendererCount; ++i)
    {
        dxiRendererInfo_t& info = dxiInfo[i];

        if (info.ResChoice == -1)
            info.ResChoice = dxiResGetRecommended(i, dxiCpuSpeed);
    }
}

bool ValidateRenderersGL()
{
    i32 count = 0;
    EnumDisplayMonitors(NULL, NULL, CountRendererCallback, (LPARAM) &count);
    return count == dxiRendererCount;
}
