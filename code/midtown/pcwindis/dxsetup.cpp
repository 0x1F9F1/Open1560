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

#include "data7/speed.h"
#include "data7/timer.h"
#include "mmui/graphics.h"
#include "setupdata.h"

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

static mem::cmd_param PARAM_min_aspect {"minaspect"};
static mem::cmd_param PARAM_max_aspect {"maxaspect"};

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

#ifdef ARTS_ENABLE_OPENGL
static mem::cmd_param PARAM_config {"config"};

static BOOL CALLBACK AddRendererCallback(HMONITOR hMonitor, [[maybe_unused]] HDC hdcMonitor,
    [[maybe_unused]] LPRECT lprcMonitor, [[maybe_unused]] LPARAM lParam)
{
    if (dxiRendererCount >= static_cast<isize>(std::size(dxiInfo)))
        return FALSE;

    MONITORINFOEXA iMonitor {sizeof(MONITORINFOEXA)};

    if (!GetMonitorInfoA(hMonitor, &iMonitor))
        return TRUE;

    dxiRendererInfo_t& info = dxiInfo[dxiRendererCount];

    info = {};

    info.Valid = true;
    info.Valid2 = true;
    info.Hardware2 = true;
    info.field_C = 0;

    info.SmoothAlpha = true;
    info.AdditiveBlending = true;
    info.VertexFog = true;
    info.MultiTexture = true;
    info.TexturePalette = true;
    info.HaveMipmaps = true;
    info.SpecialFlags = 0;

    arts_strcpy(info.Name, iMonitor.szDevice);

    info.InterfaceGuid = {};
    info.DriverGuid = {};

    info.Type = 2;

    info.ResCount = 0;
    info.ResChoice = -1;

    Displayf("Renderer: '%s'", info.Name);

    f32 min_aspect = PARAM_min_aspect.get_or<f32>(1.6f);
    f32 max_aspect = PARAM_max_aspect.get_or<f32>(2.4f);

    DEVMODEA dev_mode {};

    for (DWORD i = 0; EnumDisplaySettingsA(iMonitor.szDevice, i, &dev_mode); ++i)
    {
        if (info.ResCount >= static_cast<isize>(std::size(info.Resolutions)))
            break;

        if (dev_mode.dmBitsPerPel != 32)
            continue;

        if (dev_mode.dmDisplayFlags & DM_INTERLACED)
            continue;

        if (dev_mode.dmPelsWidth < 640)
            continue;

        if (dev_mode.dmPelsHeight < 480)
            continue;

        if (f32 ar = static_cast<f32>(dev_mode.dmPelsWidth) / static_cast<f32>(dev_mode.dmPelsHeight);
            ar < min_aspect || ar > max_aspect)
            continue;

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
            if (lhs.uWidth != rhs.uWidth)
                return lhs.uWidth < rhs.uWidth;

            return lhs.uHeight < rhs.uHeight;
        });

    if ((iMonitor.dwFlags & MONITORINFOF_PRIMARY) == MONITORINFOF_PRIMARY)
    {
        Displayf("Display '%s' (%i) is primary", info.Name, dxiRendererCount);

        if (dxiRendererChoice == -1)
            dxiRendererChoice = dxiRendererCount;
    }

    if (EnumDisplaySettingsA(iMonitor.szDevice, ENUM_CURRENT_SETTINGS, &dev_mode))
    {
        info.ResChoice = dxiResClosestMatch(dxiRendererCount, dev_mode.dmPelsWidth, dev_mode.dmPelsHeight);
    }

    ++dxiRendererCount;

    return TRUE;
}

static BOOL CALLBACK CountRendererCallback(HMONITOR hMonitor, [[maybe_unused]] HDC hdcMonitor,
    [[maybe_unused]] LPRECT lprcMonitor, [[maybe_unused]] LPARAM lParam)
{
    MONITORINFOEXA iMonitor {sizeof(MONITORINFOEXA)};

    if (!GetMonitorInfoA(hMonitor, &iMonitor))
        return TRUE;

    i32& count = *(i32*) (lParam);

    for (i32 i = 0; i < dxiRendererCount; ++i)
    {
        if (std::strcmp(iMonitor.szDevice, dxiInfo[i].Name) == 0)
        {
            ++count;

            return TRUE;
        }
    }

    count = -1;

    return FALSE;
}

static void EnumerateRenderers3()
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
#endif

#ifdef ARTS_ENABLE_OPENGL
void dxiConfig([[maybe_unused]] i32 argc, [[maybe_unused]] char** argv)
{
    dxiCpuSpeed = ComputeCpuSpeed();

    bool redetect = PARAM_config.get_or(false);

    if (!redetect)
    {
        redetect = !dxiReadConfigFile();

        if (!redetect)
        {
            i32 count = 0;
            EnumDisplayMonitors(NULL, NULL, CountRendererCallback, (LPARAM) &count);
            redetect = count != dxiRendererCount;
        }
    }

    if (redetect)
    {
        Timer detect_time;
        EnumerateRenderers3();
        Displayf("DETECT TIME: %f s", detect_time.Time());

        dxiWriteConfigFile();

        AutoDetect(-1, -1);
    }
}
#endif

run_once([] {
    auto_hook(0x575FD0, EnumZ);

    create_patch("TestResolution", "Unsigned Comparison", 0x575E34, "\x72", 1);
    create_patch("TestResolution", "Unsigned Comparison", 0x575E38, "\x72", 1);

    create_patch("Res String", "Unsigned Printf", 0x661890, "res %d x %d: %u %u / %u %u", 27);

    create_patch(
        "EliminatingRes String", "Unsigned Printf", 0x6618AC, "Eliminating res %d x %d; texmem=%u, vidmem=%u", 46);
});
