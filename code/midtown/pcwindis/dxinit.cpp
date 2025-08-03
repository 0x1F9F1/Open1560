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

define_dummy_symbol(pcwindis_dxinit);

#include "dxinit.h"

#include "dxsetup.h"
#include "pcwindis.h"
#include "sdldinput.h"
#include "setupdata.h"

#include "agi/pipeline.h"
#include "data7/ipc.h"

#ifdef ARTS_ENABLE_OPENGL
#    include "agigl/glpipe.h"
#    include "agisdl/sdlswpipe.h"
#endif

#include <SDL_hints.h>
#include <SDL_syswm.h>
#include <SDL_video.h>

i32 dxiFlags = DXI_FLAG_FULL_SCREEN | DXI_FLAG_DOUBLE_BUFFER;
i32 dxiIcon = 0;

HWND__* hwndMain = nullptr;
IDirectInputA* lpDI = nullptr;

SDL_Window* g_MainWindow = nullptr;

template <typename T>
inline void SafeRelease(T*& ptr)
{
    if (ptr)
    {
        ptr->Release();
        ptr = nullptr;
    }
}

static mem::cmd_param PARAM_sdljoy {"sdljoy"};

void dxiDirectInputCreate()
{
    if (PARAM_sdljoy.get_or(true))
    {
        lpDI = Create_SDL_IDirectInput2A();

        if (lpDI)
        {
            // TODO: Add support for all SDL joysticks

            bool has_devices = false;

            const auto enum_callback = [](LPCDIDEVICEINSTANCEA, LPVOID pvRev) -> BOOL {
                *static_cast<bool*>(pvRev) = true;

                return DIENUM_CONTINUE;
            };

            if ((lpDI->EnumDevices(DIDEVTYPE_JOYSTICK, enum_callback, &has_devices, DIEDFL_ATTACHEDONLY) == DI_OK) &&
                has_devices)
            {
                return;
            }

            // No valid devices, fallback to dinput
            lpDI->Release();
        }
    }

#if DIRECTINPUT_VERSION != 0x0500
#    error Unsupported
#endif

    HMODULE hdinput = LoadLibraryA("dinput.dll");

    HRESULT(WINAPI * pDirectInputCreateA)
    (HINSTANCE hinst, DWORD dwVersion, LPDIRECTINPUTA * ppDI, LPUNKNOWN punkOuter) =
        mem::bit_cast<decltype(pDirectInputCreateA)>(GetProcAddress(hdinput, "DirectInputCreateA"));

    HRESULT err = pDirectInputCreateA(GetModuleHandleA(NULL), DIRECTINPUT_VERSION, &lpDI, 0);

    if (err != 0)
        Quitf("DirectInputCreate failed, code %x", err);
}

static mem::cmd_param PARAM_integrated {"integrated"};

void dxiInit(char* title, i32 argc, char** argv)
{
#define ARG(NAME) !std::strcmp(arg, NAME)

    for (int i = 1; i < argc;)
    {
        char* arg = argv[i++];

        if (ARG("-triple"))
        {
            dxiFlags |= DXI_FLAG_TRIPLE_BUFFER;
        }
        else if (ARG("-sysmem"))
        {
            dxiFlags |= DXI_FLAG_SYSTEM_MEMORY;
        }
        else if (ARG("-single"))
        {
            dxiFlags &= ~DXI_FLAG_DOUBLE_BUFFER;
        }
        else if (ARG("-window"))
        {
            dxiFlags &= ~DXI_FLAG_FULL_SCREEN;
        }
    }

#undef ARG

    {
        bool use_gpu = !PARAM_integrated.get_or(false);
        HINSTANCE hInstance = GetModuleHandle(NULL);

        if (auto AmdPowerXpressRequestHighPerformance =
                GetProcAddress(hInstance, "AmdPowerXpressRequestHighPerformance"))
            *reinterpret_cast<DWORD*>(AmdPowerXpressRequestHighPerformance) = use_gpu;

        // NOTE: NVIDIA seems to only care about NvOptimusEnablement being present, not the value, despite what their documentation says
        if (auto NvOptimusEnablement = GetProcAddress(hInstance, "NvOptimusEnablement"))
            *reinterpret_cast<DWORD*>(NvOptimusEnablement) = use_gpu;
    }

    dxiRendererType type = GetRendererInfo().Type;

    dxiWindowCreate(title, type);

    dxiDirectInputCreate();
}

void dxiScreenShot(char* file_name)
{
    agiPipeline::RequestScreenShot(ConstString(file_name));
}

void dxiShutdown()
{
    SafeRelease(lpDI);

    dxiWindowDestroy();
}

static mem::cmd_param PARAM_legacygl {"legacygl"};
static mem::cmd_param PARAM_sdlwindow {"sdlwindow"};

static dxiRendererType s_WindowType = dxiRendererType::Invalid;

void dxiWindowCreate(const char* title, dxiRendererType type)
{
    if (g_MainWindow != NULL)
    {
        if (s_WindowType == type)
            return;

        dxiWindowDestroy();
    }

    s_WindowType = type;

    u32 window_flags = SDL_WINDOW_BORDERLESS;

    if (type == dxiRendererType::OpenGL)
    {
#ifdef ARTS_ENABLE_OPENGL
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
            PARAM_legacygl.get_or(false) ? SDL_GL_CONTEXT_PROFILE_COMPATIBILITY : SDL_GL_CONTEXT_PROFILE_CORE);

        window_flags |= SDL_WINDOW_OPENGL /*| SDL_WINDOW_FULLSCREEN_DESKTOP*/;
#endif
    }

    g_MainWindow = SDL_CreateWindow(title, 0, 0, 0, 0, window_flags);

    if (!g_MainWindow)
    {
        Quitf("Failed to create main window: %s", SDL_GetError());
    }

    SDL_SysWMinfo wm_info {};
    SDL_VERSION(&wm_info.version);
    ArAssert(SDL_GetWindowWMInfo(g_MainWindow, &wm_info), "Failed to get native window handle");
    hwndMain = wm_info.info.win.window;

    SDL_RaiseWindow(g_MainWindow);
}

void dxiWindowDestroy()
{
    if (g_MainWindow)
    {
        SDL_DestroyWindow(g_MainWindow);
        g_MainWindow = nullptr;
    }

    hwndMain = NULL;
    s_WindowType = dxiRendererType::Invalid;
}
