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

#include "pcwindis.h"
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

#include <ddraw.h>
#include <dinput.h>
#include <miniz.h>

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

i32 dxiChangeDisplaySettings(i32 /*width*/, i32 /*height*/, i32 /*bpp*/)
{
    return 0;
}

static inline GUID* dxiGetInterfaceGUID()
{
    dxiRendererInfo_t& info = GetRendererInfo();

    return ((info.Type == dxiRendererType::DX6) && dxiIsFullScreen()) ? &info.Guid.Interface : nullptr;
}

static GUID* dxiCurrentInterfaceGUID = nullptr;

void dxiDirectDrawCreate()
{
    HMODULE ddraw = GetModuleHandleA("DDRAW.DLL");

    if (ddraw == nullptr)
        Quitf("Failed to find DDRAW.DLL");

    auto pDirectDrawCreate = reinterpret_cast<decltype(&DirectDrawCreate)>(GetProcAddress(ddraw, "DirectDrawCreate"));

    if (pDirectDrawCreate == nullptr)
        Quitf("Failed to find DirectDrawCreate");

    dxiCurrentInterfaceGUID = dxiGetInterfaceGUID();

    IDirectDraw* lpDD = nullptr;

    if (pDirectDrawCreate(dxiCurrentInterfaceGUID, &lpDD, NULL) != 0)
        Quitf("dxiDirectDrawCreate: DirectDrawCreate failed.");

    if (lpDD->QueryInterface(IID_IDirectDraw4, (void**) &lpDD4) != 0)
        Quitf("dxiDirectDrawCreate: QI DD4 failed.");

    lpDD->Release();

    if (lpDD4->SetCooperativeLevel(
            hwndMain, dxiIsFullScreen() ? (DDSCL_FULLSCREEN | DDSCL_ALLOWREBOOT | DDSCL_EXCLUSIVE) : DDSCL_NORMAL) != 0)
    {
        Quitf("dxiDirectDrawCreate: SetCooperativeLevel failed.");
    }
}

void dxiDirectDrawSurfaceDestroy()
{
    SafeRelease(lpClip);
    SafeRelease(lpdsRend);
    SafeRelease(lpdsBack2);
    SafeRelease(lpdsBack);
    SafeRelease(lpdsFront);
}

extern "C" HRESULT WINAPI DirectInputCreateA_Impl(
    HINSTANCE hinst, DWORD dwVersion, LPDIRECTINPUTA* ppDI, LPUNKNOWN punkOuter);

void dxiDirectInputCreate()
{
#if DIRECTINPUT_VERSION == 0x0800
    create_patch("CLSID_IDirectInputDevice2A", "Replace with IID_IDirectInputDevice8A", 0x624A58,
        &IID_IDirectInputDevice8A, sizeof(IID_IDirectInputDevice8A));

    HRESULT(WINAPI * pDirectInput8Create)
    (HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID * ppvOut, LPUNKNOWN punkOuter) =
        reinterpret_cast<decltype(pDirectInput8Create)>(
            GetProcAddress(LoadLibraryA("dinput8.dll"), "DirectInput8Create"));

    HRESULT err =
        pDirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8A, (void**) &lpDI, NULL);
#else
    HRESULT err = DirectInputCreateA_Impl(GetModuleHandleA(NULL), DIRECTINPUT_VERSION, &lpDI, 0);
#endif

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
        else if (ARG("-width"))
        {
            dxiWidth = std::atoi(argv[i++]);
        }
        else if (ARG("-height"))
        {
            dxiHeight = std::atoi(argv[i++]);
        }
    }

#undef ARG

    {
        bool use_gpu = !PARAM_integrated.get_or(false);
        HINSTANCE hInstance = GetModuleHandle(NULL);

        if (void* AmdPowerXpressRequestHighPerformance =
                GetProcAddress(hInstance, "AmdPowerXpressRequestHighPerformance"))
            *static_cast<DWORD*>(AmdPowerXpressRequestHighPerformance) = use_gpu;

        // NOTE: NVIDIA seems to only care about NvOptimusEnablement being present, not the value, despite what their documentation says
        if (void* NvOptimusEnablement = GetProcAddress(hInstance, "NvOptimusEnablement"))
            *static_cast<DWORD*>(NvOptimusEnablement) = use_gpu;
    }

    dxiRendererType type = GetRendererInfo().Type;

    dxiWindowCreate(title, type);

    if (IsDX6Renderer(type))
    {
        dxiDirectDrawCreate();
        dxiSetDisplayMode();
    }

    dxiDirectInputCreate();
}

// ?translate555@@YAXPAEPAGI@Z
ARTS_IMPORT /*static*/ void translate555(u8* output, u16* input, u32 width);

// ?translate565@@YAXPAEPAGI@Z
ARTS_IMPORT /*static*/ void translate565(u8* output, u16* input, u32 width);

Ptr<u8[]> dxiScreenShot(i32& width, i32& height)
{
    if (lpdsRend == nullptr)
        return nullptr;

    DDSURFACEDESC2 sd {sizeof(sd)};

    if (lpdsRend->Lock(NULL, &sd, DDLOCK_WAIT, NULL))
    {
        Errorf("Error locking surface for screenshot.");
        return nullptr;
    }

    width = static_cast<i32>(sd.dwWidth);
    height = static_cast<i32>(sd.dwHeight);

    void (*translate)(u8 * output, u16 * input, u32 width) = nullptr;

    switch (sd.ddpfPixelFormat.dwRBitMask)
    {
        case 0x7C00: translate = translate555; break;
        case 0xF800: translate = translate565; break;
    }

    Ptr<u8[]> buffer;

    if (translate)
    {
        buffer = MakeUniqueUninit<u8[]>(width * height * 3);

        // Translate and flip horizontally
        for (i32 i = 0; i < height; ++i)
        {
            translate(buffer.get() + (i * width * 3),
                reinterpret_cast<u16*>(static_cast<u8*>(sd.lpSurface) + (sd.lPitch * (height - i - 1))), sd.dwWidth);
        }
    }
    else
    {
        Errorf("Unknown framebuffer format %X %X %X", sd.ddpfPixelFormat.dwRBitMask, sd.ddpfPixelFormat.dwGBitMask,
            sd.ddpfPixelFormat.dwBBitMask);
    }

    lpdsRend->Unlock(NULL);

    return buffer;
}

static std::atomic<bool> TakingScreenshot {false};

struct ScreenShotContext
{
    Ptr<u8[]> Pixels;
    i32 Width;
    i32 Height;
    ConstString Filename;

    ScreenShotContext(Ptr<u8[]> pixels, i32 width, i32 height, ConstString file_name)
        : Pixels(std::move(pixels))
        , Width(width)
        , Height(height)
        , Filename(std::move(file_name))
    {
        TakingScreenshot = true;
    }

    ~ScreenShotContext()
    {
        TakingScreenshot = false;
    }
};

static void SaveScreenShot(void* ctx)
{
    Ptr<ScreenShotContext> context {static_cast<ScreenShotContext*>(ctx)};

    auto& [pixels, width, height, wanted_file_name] = *context;

    if (OpenClipboard(NULL))
    {
        if (EmptyClipboard())
        {
            i32 src_pitch = width * 3;
            i32 dst_pitch = (src_pitch + 3) & ~3;

            BITMAPINFOHEADER info_header {};
            info_header.biSize = sizeof(info_header);
            info_header.biWidth = width;
            info_header.biHeight = height;
            info_header.biPlanes = 1;
            info_header.biBitCount = 24;
            info_header.biCompression = BI_RGB;
            info_header.biSizeImage = 0;
            info_header.biXPelsPerMeter = width;
            info_header.biYPelsPerMeter = height;
            info_header.biClrUsed = 0;
            info_header.biClrImportant = 0;

            if (HGLOBAL clip_handle =
                    GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT, sizeof(info_header) + dst_pitch * height))
            {
                if (u8* clip_data = static_cast<u8*>(GlobalLock(clip_handle)))
                {
                    std::memcpy(clip_data, &info_header, sizeof(info_header));
                    clip_data += sizeof(info_header);

                    for (i32 i = 0; i < height; ++i)
                        std::memcpy(&clip_data[i * dst_pitch], &pixels[i * src_pitch], src_pitch);

                    GlobalUnlock(clip_handle);
                }

                SetClipboardData(CF_DIB, clip_handle);
            }
        }

        CloseClipboard();
    }

    char name_buffer[64];
    const char* file_name = wanted_file_name.get();

    if (file_name == nullptr)
    {
        i32 shot_num = 0;
        WIN32_FIND_DATAA find_data;

        if (HANDLE find_handle = FindFirstFileA("screen/SHOT*.PNG", &find_data); find_handle != INVALID_HANDLE_VALUE)
        {
            do
            {
                if (!arts_strnicmp(find_data.cFileName, "SHOT", 4))
                    shot_num = std::max<i32>(shot_num, std::atoi(find_data.cFileName + 4));
            } while (FindNextFileA(find_handle, &find_data));

            FindClose(find_handle);
        }

        CreateDirectoryA("screen", NULL);

        arts_sprintf(name_buffer, "screen/SHOT%04d.PNG", shot_num + 1);
        file_name = name_buffer;
    }

    // BGR -> RGB
    for (i32 i = 0; i < height; ++i)
    {
        u8* row = pixels.get() + (i * width * 3);

        for (i32 j = 0; j < width; ++j, row += 3)
        {
            u8 tmp = row[0];
            row[0] = row[2];
            row[2] = tmp;
        }
    }

    size_t png_size = 0;
    if (void* png_data =
            tdefl_write_image_to_png_file_in_memory_ex(pixels.get(), width, height, 3, &png_size, 10, true);
        png_data)
    {
        if (HANDLE file = CreateFileA(file_name, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
            file != INVALID_HANDLE_VALUE)
        {
            DWORD written = 0;
            WriteFile(file, png_data, png_size, &written, NULL);
            CloseHandle(file);
        }

        mz_free(png_data);
    }
}

void dxiScreenShot(char* file_name)
{
    if (TakingScreenshot)
        return;

    i32 width = 0;
    i32 height = 0;

    Ptr<u8[]> pixels;

#ifdef ARTS_ENABLE_OPENGL
    if (pixels == nullptr)
        pixels = sdlScreenShot(width, height);

    if (pixels == nullptr)
        pixels = glScreenShot(width, height);
#endif

    if (pixels == nullptr)
        pixels = dxiScreenShot(width, height);

    if (pixels == nullptr)
        return;

    GFXPAGER.Send(SaveScreenShot, new ScreenShotContext {std::move(pixels), width, height, ConstString(file_name)});
}

static inline void dxiRestoreDisplayMode()
{
    if (dxiIsFullScreen() && lpDD4)
    {
        lpDD4->RestoreDisplayMode();
        lpDD4->SetCooperativeLevel(hwndMain, DDSCL_NORMAL);
    }
}

void dxiSetDisplayMode()
{
    dxiDirectDrawSurfaceDestroy();

    if (dxiCurrentInterfaceGUID != dxiGetInterfaceGUID())
    {
        dxiRestoreDisplayMode();
        SafeRelease(lpDD4);
        dxiDirectDrawCreate();
    }

    if (g_MainWindow)
    {
        SDL_SetWindowResizable(g_MainWindow, dxiIsFullScreen() ? SDL_TRUE : SDL_FALSE);
        SDL_SetWindowPosition(g_MainWindow, 0, 0);
    }

    if (dxiIsFullScreen())
    {
        Displayf("dxiSetDisplayMode(%d,%d,%d)", dxiWidth, dxiHeight, dxiDepth);

        u32 err = lpDD4->SetDisplayMode(dxiWidth, dxiHeight, dxiDepth, 0, 0);

        if (err)
        {
            Quitf(
                "dxiDirectDrawCreate: SetDisplayMode(%d,%d,%d) failed: code %08X.", dxiWidth, dxiHeight, dxiDepth, err);
        }
    }
    else
    {
        if (g_MainWindow)
            SDL_SetWindowSize(g_MainWindow, dxiWidth, dxiHeight);
        else
            SetWindowPos(hwndMain, 0, 0, 0, dxiWidth, dxiHeight, SWP_NOMOVE | SWP_NOZORDER);
    }

    dxiDirectDrawSurfaceCreate();
}

void dxiShutdown()
{
    SafeRelease(lpDI);

    dxiDirectDrawSurfaceDestroy();
    dxiRestoreDisplayMode();

    SafeRelease(lpDD4);

    dxiWindowDestroy();
}

void dxiWindowCreate(const char* title)
{
    if (hwndMain != NULL)
        return;

    HINSTANCE hInstance = GetModuleHandle(NULL);

    if (static ATOM agiWindowClass = 0; agiWindowClass == 0)
    {
        WNDCLASSA wc {};

        wc.style = CS_OWNDC;
        wc.lpfnWndProc = &MasterWindowProc;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = hInstance;
        wc.hIcon = dxiIcon ? LoadIcon(hInstance, MAKEINTRESOURCE(dxiIcon)) : LoadIcon(NULL, IDI_APPLICATION);
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
        wc.lpszMenuName = NULL;
        wc.lpszClassName = "agiwindow";

        agiWindowClass = RegisterClassA(&wc);
    }

    hwndMain = CreateWindowExA(WS_EX_APPWINDOW, "agiwindow", title, WS_POPUP, 0, 0, 0, 0, NULL, NULL, hInstance, NULL);

    ShowWindow(hwndMain, SW_SHOWNORMAL);
    UpdateWindow(hwndMain);
}

static mem::cmd_param PARAM_legacygl {"legacygl"};
static mem::cmd_param PARAM_sdlwindow {"sdlwindow"};

static dxiRendererType s_WindowType = dxiRendererType::Invalid;

void dxiWindowCreate(const char* title, dxiRendererType type)
{
    if (!IsSDLRenderer(type) && !PARAM_sdlwindow.get_or(false))
        return dxiWindowCreate(title);

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
    else if (IsDX6Renderer(type))
    {
        // DDRAW will likely try and change the window size
        window_flags |= SDL_WINDOW_RESIZABLE;
    }

    SDL_SetHintWithPriority(SDL_HINT_WINDOWS_INTRESOURCE_ICON, arts_formatf<16>("%i", dxiIcon), SDL_HINT_OVERRIDE);
    SDL_SetHintWithPriority(SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4, "1", SDL_HINT_OVERRIDE);

    g_MainWindow = SDL_CreateWindow(title, 0, 0, 0, 0, window_flags);

    SDL_SysWMinfo wm_info {};
    SDL_VERSION(&wm_info.version);
    ArAssert(SDL_GetWindowWMInfo(g_MainWindow, &wm_info), "Failed to get native window handle");
    hwndMain = wm_info.info.win.window;
}

void dxiWindowDestroy()
{
    if (g_MainWindow)
    {
        if (!(SDL_GetWindowFlags(g_MainWindow) & SDL_WINDOW_FOREIGN))
            hwndMain = NULL;

        SDL_DestroyWindow(g_MainWindow);
        g_MainWindow = nullptr;
    }

    if (hwndMain)
    {
        DestroyWindow(hwndMain);
        hwndMain = NULL;
    }

    s_WindowType = dxiRendererType::Invalid;
}
