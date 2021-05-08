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
            arts_sprintf(buffer, buflen, "%s on ", device.DeviceString);
            break;
        }
    }

    arts_strcat(buffer, buflen, szDevice);
}

static mem::cmd_param PARAM_min_aspect {"minaspect"};
static mem::cmd_param PARAM_max_aspect {"maxaspect"};

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
    info.Type2 = 3;
    info.Flags = 0;

    info.SmoothAlpha = true;
    info.AdditiveBlending = true;
    info.VertexFog = true;
    info.MultiTexture = true;
    info.TexturePalette = true;
    info.HaveMipmaps = true;
    info.SpecialFlags = 0;

    GetMonitorName(info.Name, ARTS_SIZE(info.Name), iMonitor.szDevice);
    arts_strcpy(info.Device, iMonitor.szDevice);

    info.Type = dxiRendererType::OpenGL;

    info.ResCount = 0;
    info.ResChoice = -1;

    Displayf("Renderer: '%s'", info.Name);

    DEVMODEA cur_dev_mode {};

    if (!EnumDisplaySettingsA(iMonitor.szDevice, ENUM_CURRENT_SETTINGS, &cur_dev_mode))
        Quitf("Failed to get current display settings");

    f32 current_ar = static_cast<f32>(cur_dev_mode.dmPelsWidth) / static_cast<f32>(cur_dev_mode.dmPelsHeight);

    f32 min_aspect = PARAM_min_aspect.get_or<f32>(current_ar * 0.8f);
    f32 max_aspect = PARAM_max_aspect.get_or<f32>(current_ar * 1.2f);

    DEVMODEA dev_mode {};

    for (DWORD i = 0; EnumDisplaySettingsA(iMonitor.szDevice, i, &dev_mode); ++i)
    {
        if (info.ResCount >= ARTS_SSIZE(info.Resolutions))
            break;

        if (dev_mode.dmDisplayFlags & DM_INTERLACED)
            continue;

        if (dev_mode.dmPelsWidth < 640 || dev_mode.dmPelsHeight < 480 || dev_mode.dmBitsPerPel < 32)
            continue;

        if (dev_mode.dmPelsWidth > cur_dev_mode.dmPelsWidth || dev_mode.dmPelsHeight > cur_dev_mode.dmPelsHeight)
            continue;

        if (dev_mode.dmPelsHeight > 720)
        {
            if (f32 ar = static_cast<f32>(dev_mode.dmPelsWidth) / static_cast<f32>(dev_mode.dmPelsHeight);
                ar < min_aspect || ar > max_aspect)
                continue;
        }

        bool exists = false;

        for (i32 j = 0; j < info.ResCount; ++j)
        {
            dxiResolution& res = info.Resolutions[j];

            if (res.uWidth == dev_mode.dmPelsWidth && res.uHeight == dev_mode.dmPelsHeight)
            {
                exists = true;
                break;
            }
        }

        if (exists)
            continue;

        dxiResolution& res = info.Resolutions[info.ResCount];

        res.uWidth = static_cast<u16>(dev_mode.dmPelsWidth);
        res.uHeight = static_cast<u16>(dev_mode.dmPelsHeight);
        res.uTexMem = 128 << 20;

        Displayf("Resolution: %u x %u", res.uWidth, res.uHeight);

        ++info.ResCount;
    }

    if (info.ResCount == 0)
        return TRUE;

    std::sort(
        info.Resolutions, info.Resolutions + info.ResCount, [](const dxiResolution& lhs, const dxiResolution& rhs) {
            return (lhs.uWidth != rhs.uWidth) ? (lhs.uWidth < rhs.uWidth) : (lhs.uHeight < rhs.uHeight);
        });

    if (iMonitor.dwFlags & MONITORINFOF_PRIMARY)
    {
        Displayf("Display '%s' (%i) is primary", info.Name, dxiRendererCount);

        if (dxiRendererChoice == -1)
            dxiRendererChoice = dxiRendererCount;
    }

    info.ResChoice = dxiResClosestMatch(
        dxiRendererCount, static_cast<i32>(720.0f * current_ar), (std::min<i32>) (720, cur_dev_mode.dmPelsHeight));

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

    char name[64] {};
    GetMonitorName(name, ARTS_SIZE(name), iMonitor.szDevice);

    for (i32 i = 0; i < dxiRendererCount; ++i)
    {
        dxiRendererInfo_t& info = dxiInfo[i];

        if ((info.Type == dxiRendererType::OpenGL) && !std::strcmp(name, dxiInfo[i].Name))
        {
            ++count;

            return TRUE;
        }
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
        dxiRendererInfo_t& info = dxiInfo[dxiRendererCount];

        if (info.ResChoice == -1)
            info.ResChoice = dxiResGetRecommended(i, dxiCpuSpeed);

        AutoDetect(i, info.ResChoice);
    }
}

bool ValidateRenderersGL()
{
    i32 count = 0;
    EnumDisplayMonitors(NULL, NULL, CountRendererCallback, (LPARAM) &count);
    return count == dxiRendererCount;
}
