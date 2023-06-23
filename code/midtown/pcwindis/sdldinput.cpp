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

#include "sdldinput.h"

#include <SDL.h>

static HRESULT DoFunctionNotImplemented(const char* name, usize times)
{
    if (times < 5)
        Errorf("%s is not implemented (called %zu times)", name, times);

    return E_NOTIMPL;
}

#define FunctionNotImplemented()                 \
    DoFunctionNotImplemented(ARTS_FUNCTION, [] { \
        static usize counter = 0;                \
        return ++counter;                        \
    }());

class SDL_DirectInputDevice2A_GameController final : public IDirectInputDevice2A
{
public:
    SDL_DirectInputDevice2A_GameController(SDL_GameController* controller)
        : Controller(controller)
        , Joystick(SDL_GameControllerGetJoystick(Controller))
    {}

    ~SDL_DirectInputDevice2A_GameController()
    {
        SDL_GameControllerClose(Controller);
    }

    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(REFIID riid, LPVOID* ppvObj)
    {
        if (riid == IID_IDirectInputDevice2A)
        {
            *ppvObj = static_cast<IDirectInputDevice2A*>(this);
            AddRef();
            return S_OK;
        }

        return E_NOINTERFACE;
    }

    STDMETHOD_(ULONG, AddRef)()
    {
        return ++RefCount;
    }

    STDMETHOD_(ULONG, Release)()
    {
        ULONG refs = --RefCount;

        if (refs == 0)
            delete this;

        return refs;
    }

    /*** IDirectInputDeviceA methods ***/
    STDMETHOD(GetCapabilities)(LPDIDEVCAPS lpDIDevCaps)
    {
        if (lpDIDevCaps->dwSize != sizeof(*lpDIDevCaps))
            return DIERR_INVALIDPARAM;

        *lpDIDevCaps = {sizeof(*lpDIDevCaps)};

        // TODO: Check for rumble support

        // Make some stuff up
        // TODO: Add rumble support
        lpDIDevCaps->dwFlags = DIDC_FORCEFEEDBACK;
        lpDIDevCaps->dwDevType = MAKEWORD(DIDEVTYPE_JOYSTICK, DIDEVTYPEJOYSTICK_TRADITIONAL);

        lpDIDevCaps->dwAxes = 4;
        lpDIDevCaps->dwButtons = 9;

        lpDIDevCaps->dwPOVs = 1;

        return DI_OK;
    }

    STDMETHOD(EnumObjects)(LPDIENUMDEVICEOBJECTSCALLBACKA, LPVOID, DWORD)
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(GetProperty)(REFGUID, LPDIPROPHEADER)
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(SetProperty)(REFGUID, LPCDIPROPHEADER)
    {
        return DI_OK;
        // return FunctionNotImplemented();
    }

    STDMETHOD(Acquire)()
    {
        return DI_OK;
    }

    STDMETHOD(Unacquire)()
    {
        return DI_OK;
    }

    STDMETHOD(GetDeviceState)(DWORD cbData, LPVOID lpvData)
    {
        if (cbData != sizeof(DIJOYSTATE))
            return DIERR_INVALIDPARAM;

        DIJOYSTATE* state = (DIJOYSTATE*) lpvData;

        *state = {};

        const auto get_axis = [this](SDL_GameControllerAxis axis, LONG min, LONG max) -> LONG {
            return (((SDL_GameControllerGetAxis(Controller, axis) + 32768) * (max - min)) / 65535) + min;
        };

        state->lX = get_axis(SDL_CONTROLLER_AXIS_LEFTX, -2000, 2000); // XAxis
        state->lY = get_axis(SDL_CONTROLLER_AXIS_LEFTY, -2000, 2000); // YAxis

        state->lZ = get_axis(SDL_CONTROLLER_AXIS_TRIGGERLEFT, -2000, 2000) -
            get_axis(SDL_CONTROLLER_AXIS_TRIGGERRIGHT, -2000, 2000); // ZAxis

        state->lRx = get_axis(SDL_CONTROLLER_AXIS_RIGHTX, -2000, 2000); // RAxis
        state->lRy = get_axis(SDL_CONTROLLER_AXIS_RIGHTY, -2000, 2000); // RAxis

        const auto get_button = [this](SDL_GameControllerButton button) -> Uint8 {
            return !!SDL_GameControllerGetButton(Controller, button);
        };

        Uint8 dpad_py = get_button(SDL_CONTROLLER_BUTTON_DPAD_UP);
        Uint8 dpad_ny = get_button(SDL_CONTROLLER_BUTTON_DPAD_DOWN);
        Uint8 dpad_nx = get_button(SDL_CONTROLLER_BUTTON_DPAD_LEFT);
        Uint8 dpad_px = get_button(SDL_CONTROLLER_BUTTON_DPAD_RIGHT);

        const DWORD pov_rot[16] {
            0xFFFF, 0, 18000, 0xFFFF, 27000, 31500, 22500, 27000, 9000, 4500, 13500, 9000, 0xFFFF, 0, 18000, 0xFFFF};

        state->rgdwPOV[0] = pov_rot[(dpad_py << 0) | (dpad_ny << 1) | (dpad_nx << 2) | (dpad_px << 3)];

        state->rgbButtons[0] = get_button(SDL_CONTROLLER_BUTTON_A) ? 0x80 : 0x00;
        state->rgbButtons[1] = get_button(SDL_CONTROLLER_BUTTON_B) ? 0x80 : 0x00;
        state->rgbButtons[2] = get_button(SDL_CONTROLLER_BUTTON_X) ? 0x80 : 0x00;
        state->rgbButtons[3] = get_button(SDL_CONTROLLER_BUTTON_Y) ? 0x80 : 0x00;
        state->rgbButtons[4] = get_button(SDL_CONTROLLER_BUTTON_LEFTSHOULDER) ? 0x80 : 0x00;
        state->rgbButtons[5] = get_button(SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) ? 0x80 : 0x00;
        state->rgbButtons[6] = get_button(SDL_CONTROLLER_BUTTON_BACK) ? 0x80 : 0x00;
        state->rgbButtons[7] = get_button(SDL_CONTROLLER_BUTTON_START) ? 0x80 : 0x00;
        state->rgbButtons[8] = get_button(SDL_CONTROLLER_BUTTON_LEFTSTICK) ? 0x80 : 0x00;
        state->rgbButtons[9] = get_button(SDL_CONTROLLER_BUTTON_RIGHTSTICK) ? 0x80 : 0x00;

        return DI_OK;
    }

    STDMETHOD(GetDeviceData)(DWORD, LPDIDEVICEOBJECTDATA, LPDWORD, DWORD)
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(SetDataFormat)(LPCDIDATAFORMAT lpdf)
    {
        LPCDIDATAFORMAT joy_fmt = &c_dfDIJoystick; // DIJOYSTATE

        if (lpdf->dwSize != joy_fmt->dwSize || lpdf->dwObjSize != joy_fmt->dwObjSize ||
            lpdf->dwFlags != joy_fmt->dwFlags || lpdf->dwDataSize != joy_fmt->dwDataSize ||
            lpdf->dwNumObjs != joy_fmt->dwNumObjs)
            return DIERR_INVALIDPARAM;

        for (DWORD i = 0; i < lpdf->dwNumObjs; ++i)
        {
            LPDIOBJECTDATAFORMAT obj1 = &lpdf->rgodf[i];
            LPDIOBJECTDATAFORMAT obj2 = &joy_fmt->rgodf[i];

            if (((obj1->pguid && obj2->pguid) ? (*obj1->pguid != *obj2->pguid) : (obj1->pguid || obj2->pguid)) ||
                obj1->dwOfs != obj2->dwOfs || obj1->dwType != obj2->dwType || obj1->dwFlags != obj2->dwFlags)
                return DIERR_INVALIDPARAM;
        }

        return DI_OK;
    }

    STDMETHOD(SetEventNotification)(HANDLE)
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(SetCooperativeLevel)(HWND /*hwnd*/, DWORD /*dwFlags*/)
    {
        return DI_OK;
    }

    STDMETHOD(GetObjectInfo)(LPDIDEVICEOBJECTINSTANCEA, DWORD, DWORD)
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(GetDeviceInfo)(LPDIDEVICEINSTANCEA pdidi)
    {
        if (pdidi->dwSize != sizeof(*pdidi))
            return DIERR_INVALIDPARAM;

        *pdidi = {sizeof(*pdidi)};

        pdidi->guidInstance = mem::bit_cast<GUID>(SDL_JoystickGetGUID(Joystick));

        const char* name = SDL_GameControllerName(Controller);
        arts_strncpy(pdidi->tszInstanceName, name, ARTS_TRUNCATE);
        pdidi->dwDevType = MAKEWORD(DIDEVTYPE_JOYSTICK, DIDEVTYPEJOYSTICK_TRADITIONAL);

        return DI_OK;
    }

    STDMETHOD(RunControlPanel)(HWND, DWORD)
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(Initialize)(HINSTANCE, DWORD, REFGUID)
    {
        return FunctionNotImplemented();
    }

    /*** IDirectInputDevice2A methods ***/
    STDMETHOD(CreateEffect)(REFGUID, LPCDIEFFECT, LPDIRECTINPUTEFFECT*, LPUNKNOWN)
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(EnumEffects)(LPDIENUMEFFECTSCALLBACKA /*lpCallback*/, LPVOID /*pvRef*/, DWORD /*dwEffType*/)
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(GetEffectInfo)(LPDIEFFECTINFOA, REFGUID)
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(GetForceFeedbackState)(LPDWORD)
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(SendForceFeedbackCommand)(DWORD)
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(EnumCreatedEffectObjects)(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK, LPVOID, DWORD)
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(Escape)(LPDIEFFESCAPE)
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(Poll)()
    {
        // Polling is handled by the event loop

        return DI_OK;
    }

    STDMETHOD(SendDeviceData)(DWORD, LPDIDEVICEOBJECTDATA, LPDWORD, DWORD)
    {
        return FunctionNotImplemented();
    }

private:
    ULONG RefCount {1};

    SDL_GameController* Controller {};
    SDL_Joystick* Joystick {};
};

class SDL_DirectInput2A final : public IDirectInput2A
{
public:
    SDL_DirectInput2A()
    {
        SDL_InitSubSystem(SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER);
    }

    ~SDL_DirectInput2A()
    {
        SDL_QuitSubSystem(SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER);
    }

    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(REFIID /*riid*/, LPVOID* /*ppvObj*/)
    {
        return FunctionNotImplemented();
    }

    STDMETHOD_(ULONG, AddRef)()
    {
        return ++RefCount;
    }

    STDMETHOD_(ULONG, Release)()
    {
        ULONG refs = --RefCount;

        if (refs == 0)
            delete this;

        return refs;
    }

    /*** IDirectInputA methods ***/
    STDMETHOD(CreateDevice)(REFGUID rguid, LPDIRECTINPUTDEVICEA* lplpDirectInputDevice, LPUNKNOWN /*pUnkOuter*/)
    {
        *lplpDirectInputDevice = nullptr;

        int device_index = -1;

        for (int i = 0; i < SDL_NumJoysticks(); ++i)
        {
            if (rguid == mem::bit_cast<GUID>(SDL_JoystickGetDeviceGUID(i)))
            {
                device_index = i;
                break;
            }
        }

        if (device_index < 0)
            return DIERR_DEVICENOTREG;

        if (SDL_IsGameController(device_index))
        {
            if (SDL_GameController* controller = SDL_GameControllerOpen(device_index))
            {
                *lplpDirectInputDevice = new SDL_DirectInputDevice2A_GameController(controller);

                return DI_OK;
            }
        }

        return FunctionNotImplemented();
    }

    STDMETHOD(EnumDevices)(DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags)
    {
        if (dwDevType == DIDEVTYPE_JOYSTICK && dwFlags == DIEDFL_ATTACHEDONLY)
        {
            Displayf("Num Joysticks: %i", SDL_NumJoysticks());

            for (int i = 0; i < SDL_NumJoysticks(); ++i)
            {
                Displayf(
                    "Joystick %i: %s (GameController=%i)", i, SDL_JoystickNameForIndex(i), SDL_IsGameController(i));

                DIDEVICEINSTANCEA dev_inst = {sizeof(dev_inst)};
                arts_strncpy(dev_inst.tszInstanceName, SDL_JoystickNameForIndex(i), ARTS_TRUNCATE);
                dev_inst.guidInstance = mem::bit_cast<GUID>(SDL_JoystickGetDeviceGUID(i));

                lpCallback(&dev_inst, pvRef);
            }

            return DI_OK;
        }

        return FunctionNotImplemented();
    }

    STDMETHOD(GetDeviceStatus)(REFGUID)
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(RunControlPanel)(HWND, DWORD)
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(Initialize)(HINSTANCE, DWORD)
    {
        return FunctionNotImplemented();
    }

    /*** IDirectInput2A methods ***/
    STDMETHOD(FindDevice)(REFGUID, LPCSTR, LPGUID)
    {
        return FunctionNotImplemented();
    }

private:
    ULONG RefCount {1};
};

HRESULT Create_SDL_IDirectInput2A(IDirectInputA** ppDI)
{
    *ppDI = new SDL_DirectInput2A();

    return NOERROR;
}