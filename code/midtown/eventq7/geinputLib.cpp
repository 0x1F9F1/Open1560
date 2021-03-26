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

define_dummy_symbol(eventq7_geinputLib);

#include "geinputLib.h"

#include "pcwindis/dxinit.h"
#include "winevent.h"

#include <dinput.h>

static extern_var(0x909424, IDirectInputDeviceA*, MouseDevice);
static extern_var(0x909428, IDirectInputDeviceA*, KeyboardDevice);

static extern_var(0x90942C, HANDLE, MouseEvent);

void geinputAcquireMouse()
{
    if (MouseDevice)
        MouseDevice->Acquire();
}

void geinputUnacquireMouse()
{
    if (MouseDevice)
        MouseDevice->Unacquire();
}

void geinputCleanup()
{
    if (MouseDevice)
    {
        MouseDevice->Unacquire();
        MouseDevice->Release();
        MouseDevice = nullptr;
    }

    if (MouseEvent)
    {
        CloseHandle(MouseEvent);
        MouseEvent = NULL;
    }

    if (KeyboardDevice)
    {
        KeyboardDevice->Unacquire();
        KeyboardDevice->Release();
        KeyboardDevice = nullptr;
    }
}

void geinputClearCache()
{}

// TODO: Pass in max number of presses
i32 geinputGetBufferedKeyboard(i8* presses)
{
    if (KeyboardDevice == nullptr)
        return 0;

    DIDEVICEOBJECTDATA data[32];
    DWORD dwItems = ARTS_SIZE32(data);

    HRESULT hres = KeyboardDevice->GetDeviceData(sizeof(*data), data, &dwItems, 0);

    if (FAILED(hres))
        return 0;

    if (presses == nullptr)
        return 0;

    if (hres == DI_BUFFEROVERFLOW)
        Errorf("Keyboard buffer had overflowed.");

    u32 count = 0;
    u32 num_items = std::min<u32>(dwItems, ARTS_SIZE32(data));

    for (u32 i = 0; i < num_items; ++i)
    {
        if (data[i].dwData & 0x80)
        {
            presses[count++] = static_cast<i8>(data[i].dwOfs);
        }
    }

    return count;
}

static i8 KeyboardState[256] {};

i8* geinputGetKeyboard()
{
    if (KeyboardDevice && FAILED(KeyboardDevice->GetDeviceState(ARTS_SIZE32(KeyboardState), KeyboardState)))
    {
        if (KeyboardDevice)
            KeyboardDevice->Acquire();

        if (FAILED(KeyboardDevice->GetDeviceState(ARTS_SIZE32(KeyboardState), KeyboardState)))
        {
            std::memset(KeyboardState, 0, sizeof(KeyboardState));
        }
    }

    return KeyboardState;
}

static bool MouseStateNeedsReset = true;
static ilong MouseRawStartX = 0;
static ilong MouseRawStartY = 0;

// FIXME: These are 640 x 480 even ingame
static extern_var(0x9092B4, ilong, InputWndWidth);
static extern_var(0x9092BC, ilong, InputWndHeight);

void geinputGetMouse(ilong* mouse_x, ilong* mouse_y, i8* l_button, i8* r_button, ilong* mouse_raw_x, ilong* mouse_raw_y,
    ilong* mouse_raw_z, i8* m_button)
{
    *mouse_x = 0;
    *mouse_y = 0;

    *l_button = 0;
    *r_button = 0;

    if (mouse_raw_z)
        *mouse_raw_z = 0;

    if (m_button)
        *m_button = 0;

    if (!MouseDevice)
        return;

    if (HRESULT hr = MouseDevice->GetDeviceState(sizeof(MOUSESTATE), &MOUSESTATE); FAILED(hr))
    {
        if ((ActiveFlag & 1) == 0)
            return;

        MouseDevice->Acquire();

        if (hr = MouseDevice->GetDeviceState(sizeof(MOUSESTATE), &MOUSESTATE); FAILED(hr))
        {
            const char* error_msg = "unknown";

            switch (hr)
            {
                case E_PENDING: error_msg = "pending"; break;
                case DIERR_NOTACQUIRED: return;
                case DIERR_INPUTLOST: error_msg = "input lost"; break;
                case DIERR_INVALIDPARAM: error_msg = "invalid param"; break;
            }

            Errorf("DirectInput problem, code = %u(%x) [%s]", hr, hr, error_msg);

            return;
        }
    }

    if (mouse_raw_x)
        *mouse_raw_x = MOUSESTATE.lX;
    if (mouse_raw_y)
        *mouse_raw_y = MOUSESTATE.lY;
    if (mouse_raw_z)
        *mouse_raw_z = MOUSESTATE.lZ;

    if (MouseStateNeedsReset)
    {
        MouseStateNeedsReset = false;
        MouseRawStartX = MOUSESTATE.lX - InputWndWidth / 2;
        MouseRawStartY = MOUSESTATE.lY - InputWndHeight / 2;
    }

    ilong window_x = MOUSESTATE.lX - MouseRawStartX;
    ilong window_y = MOUSESTATE.lY - MouseRawStartY;

    *mouse_x = std::clamp<ilong>(window_x, 0, InputWndWidth);
    *mouse_y = std::clamp<ilong>(window_y, 0, InputWndHeight);

    MouseRawStartX += window_x - *mouse_x;
    MouseRawStartY += window_y - *mouse_y;

    *l_button = (MOUSESTATE.rgbButtons[0] & 0x80) != 0;
    *r_button = (MOUSESTATE.rgbButtons[1] & 0x80) != 0;

    if (m_button)
        *m_button = (MOUSESTATE.rgbButtons[2] & 0x80) != 0;
}

// 0x564050 | ?DIError@@YAPADH@Z
ARTS_EXPORT /*static*/ const char* DIError(i32 error)
{
    static char buffer[64]; // FIXME: Static buffer
    arts_sprintf(buffer, "Error 0x%08X", error);
    return buffer;
}

i32 inputSetup(i32 width, i32 height, b32 enable_mouse, i32 /*arg4*/, i32 /*arg5*/)
{
    InputWndHeight = height;
    InputWndWidth = width;

    if (enable_mouse)
    {
        if (HRESULT err = lpDI->CreateDevice(GUID_SysMouse, &MouseDevice, 0); err < 0)
            Quitf("DirectInput::CreateDevice: %s", DIError(err));

        if (HRESULT err = MouseDevice->SetDataFormat(&c_dfDIMouse); err < 0)
            Quitf("DirectInput::SetDataFormat: %s", DIError(err));

        if (HRESULT err = MouseDevice->SetCooperativeLevel(GetActiveWindow(), DISCL_FOREGROUND | DISCL_EXCLUSIVE);
            err < 0)
            Quitf("DirectInput::SetCooperativeLevel: %s", DIError(err));

        MouseEvent = CreateEventA(NULL, FALSE, FALSE, NULL);

        if (!MouseEvent)
            Quitf("CreateEvent: failed.");

        if (MouseDevice->SetEventNotification(MouseEvent) < 0)
        {
            MessageBoxA(NULL, "Could not associate event", "System mouse", 0);
            std::exit(1);
        }

        DIPROPDWORD prop_buffersize;
        prop_buffersize.diph = {sizeof(prop_buffersize), sizeof(prop_buffersize.diph), 0, DIPH_DEVICE};
        prop_buffersize.dwData = 16;

        if (MouseDevice->SetProperty(DIPROP_BUFFERSIZE, &prop_buffersize.diph) < 0)
        {
            MessageBoxA(NULL, "Could not set properties", "System mouse", 0);
            std::exit(1);
        }

        DIPROPDWORD prop_axismode;
        prop_axismode.diph = {sizeof(prop_axismode), sizeof(prop_axismode.diph), 0, DIPH_DEVICE};
        prop_axismode.dwData = DIPROPAXISMODE_ABS;

        if (MouseDevice->SetProperty(DIPROP_AXISMODE, &prop_axismode.diph) < 0)
        {
            MessageBoxA(NULL, "Could not set properties", "System mouse (absolute mode)", 0);
            std::exit(1);
        }

        if (MouseDevice)
            MouseDevice->Acquire();
    }

    if (lpDI->CreateDevice(GUID_SysKeyboard, &KeyboardDevice, 0) < 0)
    {
        MessageBoxA(NULL, "Can not create device", "System keyboard COM interface", 0);
        std::exit(1);
    }

    if (KeyboardDevice->SetDataFormat(&c_dfDIKeyboard) < 0)
    {
        MessageBoxA(NULL, "Could not set device parameters", "System keyboard", 0);
        std::exit(1);
    }

    DIPROPDWORD prop_buffersize;
    prop_buffersize.diph = {sizeof(prop_buffersize), sizeof(prop_buffersize.diph), 0, DIPH_DEVICE};
    prop_buffersize.dwData = 32;

    KeyboardDevice->SetProperty(DIPROP_BUFFERSIZE, &prop_buffersize.diph);

    if (KeyboardDevice)
        KeyboardDevice->Acquire();

    return 0;
}

void geinputAcquireKeyboard()
{
    if (KeyboardDevice)
        KeyboardDevice->Acquire();
}

void geinputUnacquireKeyboard()
{
    if (KeyboardDevice)
        KeyboardDevice->Unacquire();
}