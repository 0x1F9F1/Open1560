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
#include "dxinit.h"
#include "localize/localize.h"
#include "midtown.h"
#include "mmui/graphics.h"
#include "setupdata.h"

HRESULT(WINAPI* agiDirectDrawCreate)(GUID FAR* lpGUID, LPDIRECTDRAW FAR* lplpDD, IUnknown FAR* pUnkOuter);
HRESULT(WINAPI* agiDirectDrawEnumerateA)(LPDDENUMCALLBACKA lpCallback, LPVOID lpContext);
HRESULT(WINAPI* agiDirectDrawEnumerateExA)(LPDDENUMCALLBACKEXA lpCallback, LPVOID lpContext, DWORD dwFlags);

bool agiLoadDirectDraw()
{
    if (!agiDirectDrawCreate || !agiDirectDrawEnumerateA)
    {
        HMODULE hddraw = LoadLibraryA("DDRAW.DLL");

        if (hddraw)
        {
            agiDirectDrawCreate = (decltype(agiDirectDrawCreate)) GetProcAddress(hddraw, "DirectDrawCreate");
            agiDirectDrawEnumerateA =
                (decltype(agiDirectDrawEnumerateA)) GetProcAddress(hddraw, "DirectDrawEnumerateA");
            agiDirectDrawEnumerateExA =
                (decltype(agiDirectDrawEnumerateExA)) GetProcAddress(hddraw, "DirectDrawEnumerateExA");
        }
    }

    return agiDirectDrawCreate && agiDirectDrawEnumerateA;
}

// ?AddRenderer@@YAXPAUIDirectDraw4@@PAU_GUID@@PAD@Z
ARTS_IMPORT /*static*/ void AddRenderer(IDirectDraw4* arg1, _GUID* arg2, char* arg3);

// ?CheckSoftwareRenderer@@YAHPAUIDirectDraw4@@PAU_GUID@@@Z
ARTS_IMPORT /*static*/ i32 CheckSoftwareRenderer(IDirectDraw4* arg1, _GUID* arg2);

// ?EnumCounter@@YGHPAU_GUID@@PAD1PAX@Z
ARTS_IMPORT /*static*/ i32 ARTS_STDCALL EnumCounter(_GUID* arg1, char* arg2, char* arg3, void* arg4);

// ?EnumTextures@@YGJPAU_DDPIXELFORMAT@@PAX@Z
ARTS_IMPORT /*static*/ ilong ARTS_STDCALL EnumTextures(_DDPIXELFORMAT* arg1, void* arg2);

#ifndef ARTS_STANDALONE // Just to shut up warnings
// ?EnumZ@@YGJPAU_DDPIXELFORMAT@@PAX@Z
static long WINAPI EnumZ(DDPIXELFORMAT* ddpf, void* ctx)
{
    if (ddpf->dwRGBBitCount == 16)
        std::memcpy(ctx, ddpf, sizeof(*ddpf));

    return 1;
}
#endif

// ?EnumerateRenderers2@@YAXXZ
ARTS_IMPORT /*static*/ void EnumerateRenderers2();

static void EnumerateRenderersDX6()
{
    EnumerateRenderers2();
}

// ?Enumerator@@YGHPAU_GUID@@PAD1PAX@Z
ARTS_IMPORT /*static*/ i32 ARTS_STDCALL Enumerator(_GUID* arg1, char* arg2, char* arg3, void* arg4);

// ?GetSpecialFlags@@YAIKK@Z
ARTS_IMPORT /*static*/ u32 GetSpecialFlags(ulong arg1, ulong arg2);

// ?LockScreen@@YAJPAUIDirectDraw4@@@Z
ARTS_IMPORT /*static*/ ilong LockScreen(IDirectDraw4* arg1);

static mem::cmd_param PARAM_min_aspect {"minaspect"};
static mem::cmd_param PARAM_max_aspect {"maxaspect"};

static bool IsGoodResolution(i32 width, i32 height, dxiRendererType type)
{
    if (width < 640 || height < 480)
        return false;

    if ((type == dxiRendererType::DX6_Soft) && (width >= 4096 || height >= 4096))
        return false;

    if (height <= 720)
        return true;

    f32 ar = static_cast<f32>(width) / static_cast<f32>(height);

    return ar >= PARAM_min_aspect.get_or<f32>(1.6f) && ar <= PARAM_max_aspect.get_or<f32>(2.4f);
}

// ?ModeCallback@@YGJPAU_DDSURFACEDESC2@@PAX@Z
ARTS_EXPORT /*static*/ long WINAPI ModeCallback(DDSURFACEDESC2* sd, void* ctx)
{
    dxiRendererInfo_t* info = static_cast<dxiRendererInfo_t*>(ctx);

    if (info->ResCount < 32)
    {
        if (IsGoodResolution(sd->dwWidth, sd->dwHeight, info->Type) && (sd->ddpfPixelFormat.dwRGBBitCount == 16))
        {
            info->Resolutions[info->ResCount].uWidth = static_cast<u16>(sd->dwWidth);
            info->Resolutions[info->ResCount].uHeight = static_cast<u16>(sd->dwHeight);

            info->ResCount++;
        }
    }

    return 1;
}

// ?MyDirectDrawEnumerate@@YAXP6GHPAU_GUID@@PAD1PAX@Z2@Z
ARTS_IMPORT /*static*/ void MyDirectDrawEnumerate(i32(ARTS_STDCALL* arg1)(_GUID*, char*, char*, void*), void* arg2);

// ?NeedDX6@@YAXXZ
ARTS_IMPORT /*static*/ void NeedDX6();

// ?NotLameChipset@@YAHKK@Z
ARTS_IMPORT /*static*/ i32 NotLameChipset(ulong arg1, ulong arg2);

// ?TestResolution@@YAHPAUIDirectDraw4@@AAUdxiRendererInfo_t@@@Z
ARTS_IMPORT /*static*/ i32 TestResolution(IDirectDraw4* arg1, dxiRendererInfo_t& arg2);

// ?UnlockScreen@@YAXXZ
ARTS_EXPORT /*static*/ void UnlockScreen()
{
    dxiWindowDestroy();
}

static bool ValidateRenderersDX6()
{
    i32 count = 0;

    for (i32 i = 0; i < dxiRendererCount; ++i)
    {
        dxiRendererInfo_t& info = dxiInfo[i];

        if (!IsDX6Renderer(info.Type))
            return false;

        IDirectDraw* ddraw = nullptr;

        if (agiDirectDrawCreate((info.Type == dxiRendererType::DX6) ? &info.DX6.Interface : nullptr, &ddraw, NULL))
            return false;

        IDirectDraw4* ddraw4 = nullptr;
        DDDEVICEIDENTIFIER ident;

        if (ddraw->QueryInterface(IID_IDirectDraw4, (LPVOID*) &ddraw4))
            NeedDX6();

        if (!ddraw4->GetDeviceIdentifier(&ident, 0) &&
            !std::memcmp(&ident.guidDeviceIdentifier, &info.DX6.Driver, sizeof(GUID)))
        {
            ++count;
        }

        ddraw4->Release();
        ddraw->Release();
    }

    return count == dxiRendererCount;
}

#ifdef ARTS_ENABLE_OPENGL
#    include "agisdl/sdlsetup.h"

static mem::cmd_param PARAM_opengl {"opengl"};
#endif

static mem::cmd_param PARAM_d3d {"d3d"};
static mem::cmd_param PARAM_config {"config"};
static mem::cmd_param PARAM_sw {"sw"};

void dxiConfig([[maybe_unused]] i32 argc, [[maybe_unused]] char** argv)
{
    dxiCpuSpeed = ComputeCpuSpeed();

    bool (*validate)() = nullptr;
    void (*enumerate)() = nullptr;
    bool show_message = false;

    if (PARAM_d3d && agiLoadDirectDraw())
    {
        validate = ValidateRenderersDX6;
        enumerate = EnumerateRenderersDX6;
        show_message = true;
    }
#ifdef ARTS_ENABLE_OPENGL
    else if (PARAM_opengl.get_or(true))
    {
        validate = ValidateRenderersSDL;
        enumerate = EnumerateRenderersSDL;
        show_message = false;
    }
#endif
    else
    {
        Quitf("No valid renderer backends");
    }

    if (PARAM_config.get_or(false) || !dxiReadConfigFile() || !validate())
    {
        if (show_message)
        {
            if (MessageBoxA(NULL, LOC_STR(MM_IDS_DETECTING_GPU), APPTITLE, MB_OKCANCEL) != IDOK)
            {
                Errorf("User declined GPU detection");
                ExitProcess(0);
            }
        }

        std::memset(dxiInfo, 0, sizeof(dxiInfo));
        dxiRendererChoice = -1;
        dxiRendererCount = 0;

        Timer detect_time;
        enumerate();
        Displayf("DETECT TIME: %f ms", detect_time.TimeMS());

        if (dxiRendererCount == 0)
        {
            MessageBoxA(NULL, LOC_STR(MM_IDS_NO_RENDERERS), APPTITLE, MB_OK);
            ExitProcess(0);
        }

        if (dxiRendererChoice == -1)
            dxiRendererChoice = std::min<i32>(1, dxiRendererCount - 1);

        dxiWriteConfigFile();
        AutoDetect(-1, -1);
    }

    if (PARAM_sw)
        dxiRendererChoice = 0;
}

run_once([] {
    auto_hook(0x575FD0, EnumZ);

    create_patch("TestResolution", "Unsigned Comparison", 0x575E34, "\x72", 1);
    create_patch("TestResolution", "Unsigned Comparison", 0x575E38, "\x72", 1);

    create_patch("Res String", "Unsigned Printf", 0x661890, "res %d x %d: %u %u / %u %u", 27);

    create_patch(
        "EliminatingRes String", "Unsigned Printf", 0x6618AC, "Eliminating res %d x %d; texmem=%u, vidmem=%u", 46);

    create_hook("DirectDrawCreate", "Dynamically load DDRAW", 0x5A2EF0 + 2, &agiDirectDrawCreate, hook_type::pointer);
    create_hook(
        "DirectDrawEnumerateA", "Dynamically load DDRAW", 0x5A2EF6 + 2, &agiDirectDrawEnumerateA, hook_type::pointer);
});