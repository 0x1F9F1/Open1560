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

#include <SDL3/SDL_gamepad.h>
#include <SDL3/SDL_init.h>

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

class SDL_DirectInputDevice2A_GamePad final : public IDirectInputDevice2A
{
public:
    SDL_DirectInputDevice2A_GamePad(Ptr<SDL_Gamepad*[]> controllers)
        : Controllers(std::move(controllers))
    {}

    ~SDL_DirectInputDevice2A_GamePad()
    {
        for (usize i = 0; Controllers[i]; ++i)
            SDL_CloseGamepad(Controllers[i]);
    }

    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(REFIID riid, LPVOID* ppvObj) override
    {
        if (riid == IID_IDirectInputDevice2A)
        {
            *ppvObj = static_cast<IDirectInputDevice2A*>(this);
            AddRef();
            return S_OK;
        }

        return E_NOINTERFACE;
    }

    STDMETHOD_(ULONG, AddRef)() override
    {
        return ++RefCount;
    }

    STDMETHOD_(ULONG, Release)() override
    {
        ULONG refs = --RefCount;

        if (refs == 0)
        {
            ArWithStaticHeap static_heap;

            delete this;
        }

        return refs;
    }

    /*** IDirectInputDeviceA methods ***/
    STDMETHOD(GetCapabilities)(LPDIDEVCAPS lpDIDevCaps) override
    {
        if (lpDIDevCaps->dwSize != sizeof(*lpDIDevCaps))
            return DIERR_INVALIDPARAM;

        *lpDIDevCaps = {sizeof(*lpDIDevCaps)};

        lpDIDevCaps->dwFlags = 0; // TODO: Add DIDC_FORCEFEEDBACK support
        lpDIDevCaps->dwDevType = MAKEWORD(DIDEVTYPE_JOYSTICK, DIDEVTYPEJOYSTICK_GAMEPAD);

        lpDIDevCaps->dwAxes = 5;
        lpDIDevCaps->dwPOVs = 1;
        lpDIDevCaps->dwButtons = 10;

        return DI_OK;
    }

    STDMETHOD(EnumObjects)(LPDIENUMDEVICEOBJECTSCALLBACKA, LPVOID, DWORD) override
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(GetProperty)(REFGUID, LPDIPROPHEADER) override
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(SetProperty)(REFGUID, LPCDIPROPHEADER) override
    {
        // TODO: Handle setting properties

        return DI_OK;

        // return FunctionNotImplemented();
    }

    STDMETHOD(Acquire)() override
    {
        return DI_OK;
    }

    STDMETHOD(Unacquire)() override
    {
        return DI_OK;
    }

    STDMETHOD(GetDeviceState)(DWORD cbData, LPVOID lpvData) override
    {
        if (cbData != sizeof(DIJOYSTATE))
            return DIERR_INVALIDPARAM;

        DIJOYSTATE* state = (DIJOYSTATE*) lpvData;

        *state = {};

        SDL_Gamepad* controller = GetActiveController();

        const auto get_axis = [controller](SDL_GamepadAxis axis, LONG min, LONG max) -> LONG {
            return (((SDL_GetGamepadAxis(controller, axis) + 32768) * (max - min)) / 65535) + min;
        };

        state->lX = get_axis(SDL_GAMEPAD_AXIS_LEFTX, -2000, 2000); // XAxis
        state->lY = get_axis(SDL_GAMEPAD_AXIS_LEFTY, -2000, 2000); // YAxis

        state->lZ = get_axis(SDL_GAMEPAD_AXIS_LEFT_TRIGGER, -2000, 2000) -
            get_axis(SDL_GAMEPAD_AXIS_RIGHT_TRIGGER, -2000, 2000); // ZAxis

        state->lRx = get_axis(SDL_GAMEPAD_AXIS_RIGHTX, -2000, 2000); // UAxis
        state->lRy = get_axis(SDL_GAMEPAD_AXIS_RIGHTY, -2000, 2000); // VAxis

        const auto get_button = [controller](SDL_GamepadButton button) -> Uint8 {
            return SDL_GetGamepadButton(controller, button);
        };

        Uint8 dpad_py = get_button(SDL_GAMEPAD_BUTTON_DPAD_UP);
        Uint8 dpad_ny = get_button(SDL_GAMEPAD_BUTTON_DPAD_DOWN);
        Uint8 dpad_nx = get_button(SDL_GAMEPAD_BUTTON_DPAD_LEFT);
        Uint8 dpad_px = get_button(SDL_GAMEPAD_BUTTON_DPAD_RIGHT);

        const DWORD pov_rot[16] {0xFFFFFFFF, 27000, 18000, 22500, 9000, 0xFFFFFFFF, 13500, 18000, 0, 31500, 0xFFFFFFFF,
            27000, 4500, 0, 9000, 0xFFFFFFFF};

        state->rgdwPOV[0] = pov_rot[(dpad_py << 3) | (dpad_px << 2) | (dpad_ny << 1) | (dpad_nx << 0)];

        state->rgbButtons[0] = get_button(SDL_GAMEPAD_BUTTON_SOUTH) ? 0x80 : 0x00;
        state->rgbButtons[1] = get_button(SDL_GAMEPAD_BUTTON_EAST) ? 0x80 : 0x00;
        state->rgbButtons[2] = get_button(SDL_GAMEPAD_BUTTON_WEST) ? 0x80 : 0x00;
        state->rgbButtons[3] = get_button(SDL_GAMEPAD_BUTTON_NORTH) ? 0x80 : 0x00;
        state->rgbButtons[4] = get_button(SDL_GAMEPAD_BUTTON_LEFT_SHOULDER) ? 0x80 : 0x00;
        state->rgbButtons[5] = get_button(SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER) ? 0x80 : 0x00;
        state->rgbButtons[6] = get_button(SDL_GAMEPAD_BUTTON_BACK) ? 0x80 : 0x00;
        state->rgbButtons[7] = get_button(SDL_GAMEPAD_BUTTON_START) ? 0x80 : 0x00;
        state->rgbButtons[8] = get_button(SDL_GAMEPAD_BUTTON_LEFT_STICK) ? 0x80 : 0x00;
        state->rgbButtons[9] = get_button(SDL_GAMEPAD_BUTTON_RIGHT_STICK) ? 0x80 : 0x00;

        return DI_OK;
    }

    STDMETHOD(GetDeviceData)(DWORD, LPDIDEVICEOBJECTDATA, LPDWORD, DWORD) override
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(SetDataFormat)(LPCDIDATAFORMAT lpdf) override
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

    STDMETHOD(SetEventNotification)(HANDLE) override
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(SetCooperativeLevel)(HWND /*hwnd*/, DWORD /*dwFlags*/) override
    {
        return DI_OK;
    }

    STDMETHOD(GetObjectInfo)(LPDIDEVICEOBJECTINSTANCEA, DWORD, DWORD) override
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(GetDeviceInfo)(LPDIDEVICEINSTANCEA pdidi) override
    {
        if (pdidi->dwSize != sizeof(*pdidi))
            return DIERR_INVALIDPARAM;

        *pdidi = {sizeof(*pdidi)};

        pdidi->guidInstance = GUID_Joystick;
        arts_strncpy(pdidi->tszInstanceName, "SDL Unified Game Controller", ARTS_TRUNCATE);
        pdidi->dwDevType = MAKEWORD(DIDEVTYPE_JOYSTICK, DIDEVTYPEJOYSTICK_GAMEPAD);

        return DI_OK;
    }

    STDMETHOD(RunControlPanel)(HWND, DWORD) override
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(Initialize)(HINSTANCE, DWORD, REFGUID) override
    {
        return FunctionNotImplemented();
    }

    /*** IDirectInputDevice2A methods ***/
    STDMETHOD(CreateEffect)(REFGUID, LPCDIEFFECT, LPDIRECTINPUTEFFECT*, LPUNKNOWN) override
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(EnumEffects)(LPDIENUMEFFECTSCALLBACKA /*lpCallback*/, LPVOID /*pvRef*/, DWORD /*dwEffType*/) override
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(GetEffectInfo)(LPDIEFFECTINFOA, REFGUID) override
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(GetForceFeedbackState)(LPDWORD) override
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(SendForceFeedbackCommand)(DWORD) override
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(EnumCreatedEffectObjects)(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK, LPVOID, DWORD) override
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(Escape)(LPDIEFFESCAPE) override
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(Poll)() override
    {
        SDL_UpdateGamepads();

        // mmJoyMan::Init only supports one controller, so unify them and find the active one
        for (usize i = 0; Controllers[i]; ++i)
        {
            SDL_Gamepad* controller = Controllers[i];

            bool active = false;

            for (int j = 0; j < SDL_GAMEPAD_BUTTON_COUNT; ++j)
            {
                if (SDL_GetGamepadButton(controller, static_cast<SDL_GamepadButton>(j)))
                {
                    active = true;
                    break;
                }
            }

            if (active)
            {
                std::swap(Controllers[0], Controllers[i]);
                break;
            }
        }

        return DI_OK;
    }

    STDMETHOD(SendDeviceData)(DWORD, LPDIDEVICEOBJECTDATA, LPDWORD, DWORD) override
    {
        return FunctionNotImplemented();
    }

private:
    ULONG RefCount {1};

    Ptr<SDL_Gamepad*[]> Controllers {};

    SDL_Gamepad* GetActiveController()
    {
        return Controllers[0];
    }
};

class SDL_DirectInput2A final : public IDirectInput2A
{
public:
    SDL_DirectInput2A()
    {
        if (!SDL_WasInit(SDL_INIT_GAMEPAD))
            SDL_InitSubSystem(SDL_INIT_GAMEPAD);
    }

    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(REFIID /*riid*/, LPVOID* /*ppvObj*/) override
    {
        return FunctionNotImplemented();
    }

    STDMETHOD_(ULONG, AddRef)() override
    {
        return ++RefCount;
    }

    STDMETHOD_(ULONG, Release)() override
    {
        ULONG refs = --RefCount;

        if (refs == 0)
        {
            ArWithStaticHeap static_heap;

            delete this;
        }

        return refs;
    }

    /*** IDirectInputA methods ***/
    STDMETHOD(CreateDevice)
    (REFGUID rguid, LPDIRECTINPUTDEVICEA* lplpDirectInputDevice, LPUNKNOWN /*pUnkOuter*/) override
    {
        HRESULT result = DIERR_DEVICENOTREG;

        *lplpDirectInputDevice = nullptr;

        if (rguid == GUID_Joystick)
        {
            ArWithStaticHeap static_heap;

            int num_gamepads = 0;
            SDL_JoystickID* gamepads_ids = SDL_GetGamepads(&num_gamepads);

            if (num_gamepads > 0)
            {
                Ptr<SDL_Gamepad*[]> gamepads = arnewa SDL_Gamepad * [num_gamepads + 1] {};
                usize num_opened = 0;

                for (int i = 0; i < num_gamepads; ++i)
                {
                    SDL_Gamepad* gamepad = SDL_OpenGamepad(gamepads_ids[i]);

                    if (!gamepad)
                        continue;

                    gamepads[num_opened++] = gamepad;
                }

                if (num_opened)
                {
                    *lplpDirectInputDevice = new SDL_DirectInputDevice2A_GamePad(std::move(gamepads));
                    result = DI_OK;
                }
            }

            SDL_free(gamepads_ids);
        }

        return result;
    }

    STDMETHOD(EnumDevices)(DWORD dwDevType, LPDIENUMDEVICESCALLBACKA lpCallback, LPVOID pvRef, DWORD dwFlags) override
    {
        if (dwDevType == DIDEVTYPE_JOYSTICK && dwFlags == DIEDFL_ATTACHEDONLY)
        {
            int num_gamepads = 0;
            SDL_JoystickID* gamepads = SDL_GetGamepads(&num_gamepads);

            if (num_gamepads)
            {
                DIDEVICEINSTANCEA dev_inst = {sizeof(dev_inst)};
                dev_inst.guidInstance = GUID_Joystick;
                arts_strncpy(dev_inst.tszInstanceName, "SDL Unified Game Controller", ARTS_TRUNCATE);
                dev_inst.dwDevType = MAKEWORD(DIDEVTYPE_JOYSTICK, DIDEVTYPEJOYSTICK_GAMEPAD);

                lpCallback(&dev_inst, pvRef);
            }

            SDL_free(gamepads);

            return DI_OK;
        }

        return FunctionNotImplemented();
    }

    STDMETHOD(GetDeviceStatus)(REFGUID) override
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(RunControlPanel)(HWND, DWORD) override
    {
        return FunctionNotImplemented();
    }

    STDMETHOD(Initialize)(HINSTANCE, DWORD) override
    {
        return FunctionNotImplemented();
    }

    /*** IDirectInput2A methods ***/
    STDMETHOD(FindDevice)(REFGUID, LPCSTR, LPGUID) override
    {
        return FunctionNotImplemented();
    }

private:
    ULONG RefCount {1};
};

IDirectInputA* Create_SDL_IDirectInput2A()
{
    ArWithStaticHeap static_heap;

    return new SDL_DirectInput2A();
}