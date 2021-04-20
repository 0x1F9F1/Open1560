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
    mminput:joyman

    0x4E5A60 | int __stdcall inputEnumDeviceProc(struct DIDEVICEINSTANCEA *,void *) | ?inputEnumDeviceProc@@YGHPAUDIDEVICEINSTANCEA@@PAX@Z
    0x4E5A90 | public: __thiscall mmJoyMan::mmJoyMan(void) | ??0mmJoyMan@@QAE@XZ
    0x4E5AA0 | public: __thiscall mmJoyMan::~mmJoyMan(void) | ??1mmJoyMan@@QAE@XZ
    0x4E5AE0 | public: int __thiscall mmJoyMan::Init(struct HINSTANCE__ *,struct HWND__ *) | ?Init@mmJoyMan@@QAEHPAUHINSTANCE__@@PAUHWND__@@@Z
    0x4E5C40 | public: int __thiscall mmJoyMan::ButtonToBit(int) | ?ButtonToBit@mmJoyMan@@QAEHH@Z
    0x4E5C70 | public: int __thiscall mmJoyMan::QJoystick(void) | ?QJoystick@mmJoyMan@@QAEHXZ
    0x4E5C80 | public: void __thiscall mmJoyMan::Update(void) | ?Update@mmJoyMan@@QAEXXZ
    0x4E5CB0 | public: float __thiscall mmJoyMan::GetJoyAxis(int,int) | ?GetJoyAxis@mmJoyMan@@QAEMHH@Z
    0x4E5CF0 | public: int __thiscall mmJoyMan::GetJoyButton(int,int) | ?GetJoyButton@mmJoyMan@@QAEHHH@Z
    0x4E5D40 | public: int __thiscall mmJoyMan::PollJoyButtons(void) | ?PollJoyButtons@mmJoyMan@@QAEHXZ
    0x4E5DA0 | public: int __thiscall mmJoyMan::PollJoyAxes(void) | ?PollJoyAxes@mmJoyMan@@QAEHXZ
    0x4E5DE0 | public: void __thiscall mmJoyMan::SetCapture(int) | ?SetCapture@mmJoyMan@@QAEXH@Z
    0x4E5E50 | public: int __thiscall mmJoyMan::GetOneButton(long) | ?GetOneButton@mmJoyMan@@QAEHJ@Z
    0x4E5E80 | public: class mmEffectFF * __thiscall mmJoyMan::GetFFEffect(int) | ?GetFFEffect@mmJoyMan@@QAEPAVmmEffectFF@@H@Z
    0x4E5EB0 | public: int __thiscall mmJoyMan::ToggleEnabled(int) | ?ToggleEnabled@mmJoyMan@@QAEHH@Z
    0x4E5EF0 | public: int __thiscall mmJoyMan::FFPlay(int) | ?FFPlay@mmJoyMan@@QAEHH@Z
    0x4E5F20 | public: int __thiscall mmJoyMan::FFStop(int) | ?FFStop@mmJoyMan@@QAEHH@Z
    0x4E5F50 | public: int __thiscall mmJoyMan::FFIsPlaying(int) | ?FFIsPlaying@mmJoyMan@@QAEHH@Z
    0x4E5F80 | public: int __thiscall mmJoyMan::FFSetValues(int,float,float) | ?FFSetValues@mmJoyMan@@QAEHHMM@Z
    0x4E5FC0 | public: void __thiscall mmJoyMan::StopAllFF(void) | ?StopAllFF@mmJoyMan@@QAEXXZ
    0x4E5FE0 | public: int __thiscall mmJoyMan::HasCoolie(void) | ?HasCoolie@mmJoyMan@@QAEHXZ
    0x4E6000 | public: int __thiscall mmJoyMan::HasThrottle(void) | ?HasThrottle@mmJoyMan@@QAEHXZ
    0x4E6020 | public: void * __thiscall mmJoystick::`vector deleting destructor'(unsigned int) | ??_EmmJoystick@@QAEPAXI@Z
*/

// 0x4E5A60 | ?inputEnumDeviceProc@@YGHPAUDIDEVICEINSTANCEA@@PAX@Z
ARTS_IMPORT i32 ARTS_STDCALL inputEnumDeviceProc(struct DIDEVICEINSTANCEA* arg1, void* arg2);

struct mmJoyMan
{
public:
    // 0x4E5A90 | ??0mmJoyMan@@QAE@XZ
    ARTS_IMPORT mmJoyMan();

    // 0x4E5AA0 | ??1mmJoyMan@@QAE@XZ
    ARTS_IMPORT ~mmJoyMan();

    // 0x4E5C40 | ?ButtonToBit@mmJoyMan@@QAEHH@Z
    ARTS_IMPORT i32 ButtonToBit(i32 arg1);

    // 0x4E5F50 | ?FFIsPlaying@mmJoyMan@@QAEHH@Z
    ARTS_IMPORT i32 FFIsPlaying(i32 arg1);

    // 0x4E5EF0 | ?FFPlay@mmJoyMan@@QAEHH@Z
    ARTS_IMPORT i32 FFPlay(i32 arg1);

    // 0x4E5F80 | ?FFSetValues@mmJoyMan@@QAEHHMM@Z
    ARTS_IMPORT i32 FFSetValues(i32 arg1, f32 arg2, f32 arg3);

    // 0x4E5F20 | ?FFStop@mmJoyMan@@QAEHH@Z
    ARTS_IMPORT i32 FFStop(i32 arg1);

    // 0x4E5E80 | ?GetFFEffect@mmJoyMan@@QAEPAVmmEffectFF@@H@Z
    ARTS_IMPORT class mmEffectFF* GetFFEffect(i32 arg1);

    // 0x4E5CB0 | ?GetJoyAxis@mmJoyMan@@QAEMHH@Z
    ARTS_IMPORT f32 GetJoyAxis(i32 arg1, i32 arg2);

    // 0x4E5CF0 | ?GetJoyButton@mmJoyMan@@QAEHHH@Z
    ARTS_IMPORT i32 GetJoyButton(i32 arg1, i32 arg2);

    // 0x4E5E50 | ?GetOneButton@mmJoyMan@@QAEHJ@Z
    ARTS_IMPORT i32 GetOneButton(ilong arg1);

    // 0x4E5FE0 | ?HasCoolie@mmJoyMan@@QAEHXZ
    ARTS_IMPORT i32 HasCoolie();

    // 0x4E6000 | ?HasThrottle@mmJoyMan@@QAEHXZ
    ARTS_IMPORT i32 HasThrottle();

    // 0x4E5AE0 | ?Init@mmJoyMan@@QAEHPAUHINSTANCE__@@PAUHWND__@@@Z
    ARTS_IMPORT i32 Init(struct HINSTANCE__* arg1, struct HWND__* arg2);

    // 0x4E5DA0 | ?PollJoyAxes@mmJoyMan@@QAEHXZ
    ARTS_IMPORT i32 PollJoyAxes();

    // 0x4E5D40 | ?PollJoyButtons@mmJoyMan@@QAEHXZ
    ARTS_IMPORT i32 PollJoyButtons();

    // 0x4E5C70 | ?QJoystick@mmJoyMan@@QAEHXZ | unused
    ARTS_IMPORT i32 QJoystick();

    // 0x4E5DE0 | ?SetCapture@mmJoyMan@@QAEXH@Z
    ARTS_IMPORT void SetCapture(i32 arg1);

    // 0x4E5FC0 | ?StopAllFF@mmJoyMan@@QAEXXZ
    ARTS_IMPORT void StopAllFF();

    // 0x4E5EB0 | ?ToggleEnabled@mmJoyMan@@QAEHH@Z
    ARTS_IMPORT i32 ToggleEnabled(i32 arg1);

    // 0x4E5C80 | ?Update@mmJoyMan@@QAEXXZ
    ARTS_IMPORT void Update();

    u8 gap0[0x48];
};

check_size(mmJoyMan, 0x48);
