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

/*
    mminput:joystick

    0x4E6080 | public: __thiscall mmJaxis::mmJaxis(void) | ??0mmJaxis@@QAE@XZ
    0x4E60A0 | public: __thiscall mmJaxis::~mmJaxis(void) | ??1mmJaxis@@QAE@XZ
    0x4E60B0 | public: void __thiscall mmJaxis::SetRange(float,float) | ?SetRange@mmJaxis@@QAEXMM@Z
    0x4E60D0 | public: void __thiscall mmJaxis::Normalize(float) | ?Normalize@mmJaxis@@QAEXM@Z
    0x4E60F0 | public: void __thiscall mmJaxis::NormalizePOV(unsigned long) | ?NormalizePOV@mmJaxis@@QAEXK@Z
    0x4E6130 | public: int __thiscall mmJaxis::Capture(void) | ?Capture@mmJaxis@@QAEHXZ
    0x4E6160 | public: void __thiscall mmJaxis::ResetCapture(void) | ?ResetCapture@mmJaxis@@QAEXXZ
    0x4E6180 | public: __thiscall mmJoystick::mmJoystick(void) | ??0mmJoystick@@QAE@XZ
    0x4E6240 | public: __thiscall mmJoystick::~mmJoystick(void) | ??1mmJoystick@@QAE@XZ
    0x4E6360 | public: int __thiscall mmJoystick::Init(struct IDirectInputDevice2A *,struct HWND__ *) | ?Init@mmJoystick@@QAEHPAUIDirectInputDevice2A@@PAUHWND__@@@Z
    0x4E6470 | public: int __thiscall mmJoystick::inputPrepareDevice(void) | ?inputPrepareDevice@mmJoystick@@QAEHXZ
    0x4E6620 | public: int __thiscall mmJoystick::SetDeadZone(float) | ?SetDeadZone@mmJoystick@@QAEHM@Z
    0x4E66C0 | public: int __thiscall mmJoystick::DisableAutoCenter(void) | ?DisableAutoCenter@mmJoystick@@QAEHXZ
    0x4E6720 | public: unsigned long __thiscall mmJoystick::Poll(void) | ?Poll@mmJoystick@@QAEKXZ
    0x4E6850 | public: float __thiscall mmJoystick::GetAxis(int) | ?GetAxis@mmJoystick@@QAEMH@Z
    0x4E6950 | public: float __thiscall mmJoystick::GetButton(int) | ?GetButton@mmJoystick@@QAEMH@Z
    0x4E6980 | public: void __thiscall mmJoystick::Update(void) | ?Update@mmJoystick@@QAEXXZ
    0x4E6A10 | public: void __thiscall mmJoystick::ResetAxisCapture(void) | ?ResetAxisCapture@mmJoystick@@QAEXXZ
    0x4E6A90 | public: void __thiscall mmJoystick::InputCreateEffect(void) | ?InputCreateEffect@mmJoystick@@QAEXXZ
    0x4E6BB0 | public: void __thiscall mmJoystick::InputInitEffect(void) | ?InputInitEffect@mmJoystick@@QAEXXZ
    0x4E6BF0 | public: void __thiscall mmJoystick::InputStopEffect(void) | ?InputStopEffect@mmJoystick@@QAEXXZ
    0x4E6C30 | public: int __thiscall mmJoystick::SetShake(unsigned long,unsigned long) | ?SetShake@mmJoystick@@QAEHKK@Z
    0x4E6C60 | public: int __thiscall mmJoystick::PlayShake(void) | ?PlayShake@mmJoystick@@QAEHXZ
    0x4E6C80 | public: int __thiscall mmJoystick::StopShake(void) | ?StopShake@mmJoystick@@QAEHXZ
    0x4E6CA0 | public: int __thiscall mmJoystick::PlayCollision(void) | ?PlayCollision@mmJoystick@@QAEHXZ
    0x4E6CC0 | public: int __thiscall mmJoystick::SetSteer(long) | ?SetSteer@mmJoystick@@QAEHJ@Z
    0x4E6CE0 | public: int __thiscall mmJoystick::PlaySteer(void) | ?PlaySteer@mmJoystick@@QAEHXZ
    0x4E6D00 | public: int __thiscall mmJoystick::StopSteer(void) | ?StopSteer@mmJoystick@@QAEHXZ
    0x4E6D20 | public: int __thiscall mmJoystick::SetFriction(long) | ?SetFriction@mmJoystick@@QAEHJ@Z
    0x4E6D40 | public: int __thiscall mmJoystick::PlayFriction(void) | ?PlayFriction@mmJoystick@@QAEHXZ
    0x4E6D60 | public: int __thiscall mmJoystick::StopFriction(void) | ?StopFriction@mmJoystick@@QAEHXZ
    0x4E6D80 | public: class mmEffectFF * __thiscall mmJoystick::GetFFEffect(int) | ?GetFFEffect@mmJoystick@@QAEPAVmmEffectFF@@H@Z
    0x4E6DD0 | public: void __thiscall mmJoystick::PrintDeviceCaps(void) | ?PrintDeviceCaps@mmJoystick@@QAEXXZ
    0x4E6FB0 | void __cdecl DecodeDIErrorMFlag(long) | ?DecodeDIErrorMFlag@@YAXJ@Z
    0x61FCD0 | const mmFrictionFF::`vftable' | ??_7mmFrictionFF@@6B@
    0x61FCE0 | const mmCollideFF::`vftable' | ??_7mmCollideFF@@6B@
    0x61FCF0 | const mmSpringFF::`vftable' | ??_7mmSpringFF@@6B@
    0x61FD00 | const mmRoadFF::`vftable' | ??_7mmRoadFF@@6B@
*/

struct mmJoystick
{
public:
    // 0x4E6180 | ??0mmJoystick@@QAE@XZ
    ARTS_IMPORT mmJoystick();

    // 0x4E6020 | ??_EmmJoystick@@QAEPAXI@Z | unused
    // 0x4E6240 | ??1mmJoystick@@QAE@XZ
    ARTS_IMPORT ~mmJoystick();

    // 0x4E66C0 | ?DisableAutoCenter@mmJoystick@@QAEHXZ
    ARTS_IMPORT i32 DisableAutoCenter();

    // 0x4E6850 | ?GetAxis@mmJoystick@@QAEMH@Z
    ARTS_IMPORT f32 GetAxis(i32 arg1);

    // 0x4E6950 | ?GetButton@mmJoystick@@QAEMH@Z
    ARTS_IMPORT f32 GetButton(i32 arg1);

    // 0x4E6D80 | ?GetFFEffect@mmJoystick@@QAEPAVmmEffectFF@@H@Z
    ARTS_IMPORT class mmEffectFF* GetFFEffect(i32 arg1);

    // 0x4E6360 | ?Init@mmJoystick@@QAEHPAUIDirectInputDevice2A@@PAUHWND__@@@Z
    ARTS_IMPORT i32 Init(struct IDirectInputDevice2A* arg1, struct HWND__* arg2);

    // 0x4E6A90 | ?InputCreateEffect@mmJoystick@@QAEXXZ
    ARTS_IMPORT void InputCreateEffect();

    // 0x4E6BB0 | ?InputInitEffect@mmJoystick@@QAEXXZ
    ARTS_IMPORT void InputInitEffect();

    // 0x4E6BF0 | ?InputStopEffect@mmJoystick@@QAEXXZ
    ARTS_IMPORT void InputStopEffect();

    // 0x4E6CA0 | ?PlayCollision@mmJoystick@@QAEHXZ | unused
    ARTS_IMPORT i32 PlayCollision();

    // 0x4E6D40 | ?PlayFriction@mmJoystick@@QAEHXZ | unused
    ARTS_IMPORT i32 PlayFriction();

    // 0x4E6C60 | ?PlayShake@mmJoystick@@QAEHXZ | unused
    ARTS_IMPORT i32 PlayShake();

    // 0x4E6CE0 | ?PlaySteer@mmJoystick@@QAEHXZ | unused
    ARTS_IMPORT i32 PlaySteer();

    // 0x4E6720 | ?Poll@mmJoystick@@QAEKXZ
    ARTS_IMPORT u32 Poll();

    // 0x4E6DD0 | ?PrintDeviceCaps@mmJoystick@@QAEXXZ
    ARTS_IMPORT void PrintDeviceCaps();

    // 0x4E6A10 | ?ResetAxisCapture@mmJoystick@@QAEXXZ
    ARTS_IMPORT void ResetAxisCapture();

    // 0x4E6620 | ?SetDeadZone@mmJoystick@@QAEHM@Z
    ARTS_IMPORT i32 SetDeadZone(f32 arg1);

    // 0x4E6D20 | ?SetFriction@mmJoystick@@QAEHJ@Z | unused
    ARTS_IMPORT i32 SetFriction(i32 arg1);

    // 0x4E6C30 | ?SetShake@mmJoystick@@QAEHKK@Z | unused
    ARTS_IMPORT i32 SetShake(u32 arg1, u32 arg2);

    // 0x4E6CC0 | ?SetSteer@mmJoystick@@QAEHJ@Z | unused
    ARTS_IMPORT i32 SetSteer(i32 arg1);

    // 0x4E6D60 | ?StopFriction@mmJoystick@@QAEHXZ | unused
    ARTS_IMPORT i32 StopFriction();

    // 0x4E6C80 | ?StopShake@mmJoystick@@QAEHXZ | unused
    ARTS_IMPORT i32 StopShake();

    // 0x4E6D00 | ?StopSteer@mmJoystick@@QAEHXZ | unused
    ARTS_IMPORT i32 StopSteer();

    // 0x4E6980 | ?Update@mmJoystick@@QAEXXZ
    ARTS_IMPORT void Update();

    // 0x4E6470 | ?inputPrepareDevice@mmJoystick@@QAEHXZ
    ARTS_IMPORT i32 inputPrepareDevice();
};

check_size(mmJoystick, 0x3A8);

struct mmJaxis
{
public:
    // 0x4E6080 | ??0mmJaxis@@QAE@XZ
    ARTS_IMPORT mmJaxis();

    // 0x4E60A0 | ??1mmJaxis@@QAE@XZ
    ARTS_IMPORT ~mmJaxis();

    // 0x4E6130 | ?Capture@mmJaxis@@QAEHXZ
    ARTS_IMPORT i32 Capture();

    // 0x4E60D0 | ?Normalize@mmJaxis@@QAEXM@Z
    ARTS_IMPORT void Normalize(f32 arg1);

    // 0x4E60F0 | ?NormalizePOV@mmJaxis@@QAEXK@Z
    ARTS_IMPORT void NormalizePOV(u32 arg1);

    // 0x4E6160 | ?ResetCapture@mmJaxis@@QAEXXZ
    ARTS_IMPORT void ResetCapture();

    // 0x4E60B0 | ?SetRange@mmJaxis@@QAEXMM@Z
    ARTS_IMPORT void SetRange(f32 arg1, f32 arg2);
};

check_size(mmJaxis, 0x0);

// 0x4E6FB0 | ?DecodeDIErrorMFlag@@YAXJ@Z
ARTS_IMPORT void DecodeDIErrorMFlag(i32 arg1);
