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

    return (info.IsHardware() && dxiIsFullScreen()) ? &info.InterfaceGuid : nullptr;
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
    HRESULT err = DirectInputCreateA_Impl(GetModuleHandleA(NULL), DIRECTINPUT_VERSION, &lpDI, 0);

    if (err != 0)
        Quitf("DirectInputCreate failed, code %x", u16(err));
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

    if (dxiIsFullScreen())
    {
        Displayf("dxiSetDisplayMode(%d,%d,%d)", dxiWidth, dxiHeight, dxiDepth);

        u32 err = lpDD4->SetDisplayMode(dxiWidth, dxiHeight, dxiDepth, 0, 0);

        if (err)
        {
            Quitf("dxiDirectDrawCreate: SetDisplayMode(%d,%d,%d) failed: code %d.", dxiWidth, dxiHeight, dxiDepth,
                u16(err));
        }
    }
    else
    {
        SetWindowPos(hwndMain, HWND_TOP, 0, 0, dxiWidth, dxiHeight, SWP_NOMOVE | SWP_NOZORDER);
    }

    dxiDirectDrawSurfaceCreate();
}

void dxiShutdown()
{
    SafeRelease(lpDI);

    dxiDirectDrawSurfaceDestroy();
    dxiRestoreDisplayMode();

    SafeRelease(lpDD4);

    if (hwndMain)
    {
        DestroyWindow(hwndMain);
        hwndMain = NULL;
    }
}

static ATOM dxiWindowClass = 0;

void dxiWindowCreate(const char* title)
{
    if (hwndMain != NULL)
        return;

    if (!dxiWindowClass)
    {
        WNDCLASSA wnd_class {};

        wnd_class.style = CS_VREDRAW | CS_HREDRAW;
        wnd_class.lpfnWndProc = &MasterWindowProc;
        wnd_class.cbClsExtra = 0;
        wnd_class.cbWndExtra = 0;
        wnd_class.hInstance = 0;

        wnd_class.hIcon =
            dxiIcon ? LoadIcon(GetModuleHandleA(NULL), MAKEINTRESOURCE(dxiIcon)) : LoadIcon(NULL, IDI_APPLICATION);

        wnd_class.hCursor = LoadCursor(NULL, IDC_ARROW);

        wnd_class.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
        wnd_class.lpszMenuName = 0;
        wnd_class.lpszClassName = "agiwindow";

        dxiWindowClass = RegisterClassA(&wnd_class);
    }

    hwndMain = CreateWindowExA(
        0, "agiwindow", title, WS_POPUP | WS_SYSMENU, 0, 0, dxiWidth, dxiHeight, NULL, NULL, NULL, NULL);

    ShowWindow(hwndMain, SW_SHOWNORMAL);
    UpdateWindow(hwndMain);
}

// 0x574940 | ?translate555@@YAXPAEPAGI@Z
ARTS_IMPORT /*static*/ void translate555(u8* arg1, u16* arg2, u32 arg3);

// 0x5748D0 | ?translate565@@YAXPAEPAGI@Z
ARTS_IMPORT /*static*/ void translate565(u8* arg1, u16* arg2, u32 arg3);
