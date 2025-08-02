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

#pragma once

#include <dinput.h>

class mmCollideFF;
class mmEffectFF;
class mmFrictionFF;
class mmRoadFF;
class mmSpringFF;

struct mmJaxis
{
public:
    // ??0mmJaxis@@QAE@XZ
    ARTS_IMPORT mmJaxis();

    // ??1mmJaxis@@QAE@XZ
    ARTS_EXPORT ~mmJaxis();

    // ?Capture@mmJaxis@@QAEHXZ
    ARTS_IMPORT i32 Capture();

    // ?Normalize@mmJaxis@@QAEXM@Z
    ARTS_IMPORT void Normalize(f32 arg1);

    // ?NormalizePOV@mmJaxis@@QAEXK@Z
    ARTS_IMPORT void NormalizePOV(ulong arg1);

    // ?ResetCapture@mmJaxis@@QAEXXZ
    ARTS_IMPORT void ResetCapture();

    // ?SetRange@mmJaxis@@QAEXMM@Z
    ARTS_IMPORT void SetRange(f32 arg1, f32 arg2);

    f32 CapStart;
    f32 Value;
    f32 Range;
    f32 Min;
    f32 DeadMin;
    f32 DeadMax;
    b32 Enabled;
};

check_size(mmJaxis, 0x1C);

struct mmJoystick final
{
public:
    // ??0mmJoystick@@QAE@XZ
    ARTS_IMPORT mmJoystick();

    // ??_EmmJoystick@@QAEPAXI@Z | unused
    // ??1mmJoystick@@QAE@XZ
    ARTS_IMPORT ~mmJoystick();

    // ?DisableAutoCenter@mmJoystick@@QAEHXZ
    ARTS_IMPORT i32 DisableAutoCenter();

    // ?GetAxis@mmJoystick@@QAEMH@Z
    ARTS_EXPORT f32 GetAxis(i32 axis);

    // ?GetButton@mmJoystick@@QAEMH@Z
    ARTS_IMPORT f32 GetButton(i32 arg1);

    // ?GetFFEffect@mmJoystick@@QAEPAVmmEffectFF@@H@Z
    ARTS_IMPORT mmEffectFF* GetFFEffect(i32 arg1);

    // ?Init@mmJoystick@@QAEHPAUIDirectInputDevice2A@@PAUHWND__@@@Z
    ARTS_IMPORT i32 Init(IDirectInputDevice2A* arg1, HWND__* arg2);

    // ?InputCreateEffect@mmJoystick@@QAEXXZ
    ARTS_IMPORT void InputCreateEffect();

    // ?InputInitEffect@mmJoystick@@QAEXXZ
    ARTS_IMPORT void InputInitEffect();

    // ?InputStopEffect@mmJoystick@@QAEXXZ
    ARTS_IMPORT void InputStopEffect();

    // ?Poll@mmJoystick@@QAEKXZ
    ARTS_EXPORT ulong Poll();

    // ?PrintDeviceCaps@mmJoystick@@QAEXXZ
    ARTS_IMPORT void PrintDeviceCaps();

    // ?ResetAxisCapture@mmJoystick@@QAEXXZ
    ARTS_IMPORT void ResetAxisCapture();

    // ?SetDeadZone@mmJoystick@@QAEHM@Z
    ARTS_IMPORT i32 SetDeadZone(f32 arg1);

    // ?Update@mmJoystick@@QAEXXZ
    ARTS_EXPORT void Update();

    // ?inputPrepareDevice@mmJoystick@@QAEHXZ
    ARTS_IMPORT i32 inputPrepareDevice();

    IDirectInputDevice2A* Device;
    b32 HasFF;
    DIJOYSTATE JoyState;
    DIDEVCAPS DevCaps;
    DIDEVICEINSTANCEA DevInfo;
    mmSpringFF* SpringFF;
    mmFrictionFF* FrictionFF;
    mmRoadFF* RoadFF;
    mmCollideFF* CollideFF;
    mmJaxis XAxis;
    mmJaxis YAxis;
    mmJaxis ZAxis;
    mmJaxis RAxis;
    mmJaxis UAxis;
    mmJaxis VAxis;
    mmJaxis PovAxis;
    u32 ButtonFlags;
    u32 Capture;
    i32 State;
};

check_size(mmJoystick, 0x3A8);

// ?DecodeDIErrorMFlag@@YAXJ@Z
ARTS_IMPORT void DecodeDIErrorMFlag(ilong arg1);

inline mmJaxis::~mmJaxis() = default;