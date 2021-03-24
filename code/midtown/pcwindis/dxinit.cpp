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

#include <ddraw.h>
#include <dinput.h>

#include "pcwindis.h"
#include "setupdata.h"

#include "agi/pipeline.h"
#include "data7/ipc.h"
#include <miniz.h>

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

    return ((info.Type == 2) && dxiIsFullScreen()) ? &info.Guid.Interface : nullptr;
}

static GUID* dxiCurrentInterfaceGUID = nullptr;

void dxiDirectDrawCreate()
{
#ifndef ARTS_DISABLE_DDRAW
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
#endif
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

#ifdef ARTS_ENABLE_OPENGL
#    include "agigl/glpipe.h"
#endif

// 0x574940 | ?translate555@@YAXPAEPAGI@Z
ARTS_IMPORT /*static*/ void translate555(u8* output, u16* input, u32 width);

// 0x5748D0 | ?translate565@@YAXPAEPAGI@Z
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

struct ScreenShotContext
{
    Ptr<u8[]> Pixels;
    i32 Width;
    i32 Height;
    CString Filename;
};

static void SaveScreenShot(void* ctx)
{
    Ptr<ScreenShotContext> context {static_cast<ScreenShotContext*>(ctx)};

    auto& [pixels, width, height, wanted_file_name] = *context;

    if (OpenClipboard(NULL))
    {
        if (EmptyClipboard())
        {
            i32 pixels_size = 3 * width * height;

            BITMAPFILEHEADER file_header {};
            file_header.bfType = 0x4D42;
            file_header.bfSize = 54 + pixels_size;
            file_header.bfReserved1 = 0;
            file_header.bfReserved2 = 0;
            file_header.bfOffBits = 54;

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

            if (HGLOBAL clip_handle = GlobalAlloc(GMEM_MOVEABLE, sizeof(info_header) + pixels_size))
            {
                if (u8* clip_data = static_cast<u8*>(GlobalLock(clip_handle)))
                {
                    std::memcpy(clip_data + 0x0, &info_header, sizeof(info_header));
                    std::memcpy(clip_data + sizeof(info_header), pixels.get(), pixels_size);

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
    i32 width = 0;
    i32 height = 0;
    Ptr<u8[]> pixels;

    if (lpdsRend)
    {
        pixels = dxiScreenShot(width, height);
    }
    else
    {
#ifdef ARTS_ENABLE_OPENGL
        pixels = glScreenShot(width, height);
#endif
    }

    if (pixels == nullptr)
        return;

    GFXPAGER.Send(SaveScreenShot, new ScreenShotContext {std::move(pixels), width, height, file_name});
}

#ifndef ARTS_DISABLE_DDRAW
static inline void dxiRestoreDisplayMode()
{
    if (dxiIsFullScreen() && lpDD4)
    {
        lpDD4->RestoreDisplayMode();
        lpDD4->SetCooperativeLevel(hwndMain, DDSCL_NORMAL);
    }
}
#endif

void dxiSetDisplayMode()
{
#ifndef ARTS_DISABLE_DDRAW
    dxiDirectDrawSurfaceDestroy();

    if (dxiCurrentInterfaceGUID != dxiGetInterfaceGUID())
    {
        dxiRestoreDisplayMode();
        SafeRelease(lpDD4);
        dxiDirectDrawCreate();
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

        MONITORINFO info {sizeof(MONITORINFO)};
        GetMonitorInfo(MonitorFromWindow(hwndMain, MONITOR_DEFAULTTONEAREST), &info);

        SetWindowPos(hwndMain, HWND_TOP, info.rcMonitor.left, info.rcMonitor.top,
            info.rcMonitor.right - info.rcMonitor.left, info.rcMonitor.bottom - info.rcMonitor.top, SWP_NOZORDER);
    }
    else
    {
        SetWindowPos(hwndMain, HWND_TOP, 0, 0, dxiWidth, dxiHeight, SWP_NOMOVE | SWP_NOZORDER);
    }

    dxiDirectDrawSurfaceCreate();
#endif
}

void dxiShutdown()
{
    SafeRelease(lpDI);

#ifndef ARTS_DISABLE_DDRAW
    dxiDirectDrawSurfaceDestroy();
    dxiRestoreDisplayMode();

    SafeRelease(lpDD4);
#endif

    if (hwndMain)
    {
        DestroyWindow(hwndMain);
        hwndMain = NULL;
    }
}

static ATOM dxiWindowClass = 0;

#define AGI_WINDOW_CLASS "agiwindow"

void dxiWindowCreate(const char* title)
{
    if (hwndMain != NULL)
        return;

    HINSTANCE hInstance = GetModuleHandle(NULL);

    if (!dxiWindowClass)
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
        wc.lpszClassName = AGI_WINDOW_CLASS;

        dxiWindowClass = RegisterClassA(&wc);
    }

    hwndMain =
        CreateWindowExA(0, AGI_WINDOW_CLASS, title, WS_POPUP, 0, 0, dxiWidth, dxiHeight, NULL, NULL, hInstance, NULL);

    ShowWindow(hwndMain, SW_SHOWNORMAL);
    UpdateWindow(hwndMain);
}
