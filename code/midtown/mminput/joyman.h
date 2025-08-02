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

struct DIDEVICEINSTANCEA;
struct HINSTANCE__;
struct HWND__;

class mmEffectFF;

// ?inputEnumDeviceProc@@YGHPAUDIDEVICEINSTANCEA@@PAX@Z
ARTS_IMPORT i32 ARTS_STDCALL inputEnumDeviceProc(DIDEVICEINSTANCEA* arg1, void* arg2);

class mmJoyMan
{
public:
    // ??0mmJoyMan@@QAE@XZ
    ARTS_IMPORT mmJoyMan();

    // ??1mmJoyMan@@QAE@XZ
    ARTS_IMPORT ~mmJoyMan();

    // ?ButtonToBit@mmJoyMan@@QAEHH@Z
    ARTS_EXPORT i32 ButtonToBit(i32 button);

    // ?FFIsPlaying@mmJoyMan@@QAEHH@Z
    ARTS_IMPORT i32 FFIsPlaying(i32 arg1);

    // ?FFPlay@mmJoyMan@@QAEHH@Z
    ARTS_IMPORT i32 FFPlay(i32 arg1);

    // ?FFSetValues@mmJoyMan@@QAEHHMM@Z
    ARTS_IMPORT i32 FFSetValues(i32 arg1, f32 arg2, f32 arg3);

    // ?FFStop@mmJoyMan@@QAEHH@Z
    ARTS_IMPORT i32 FFStop(i32 arg1);

    // ?GetFFEffect@mmJoyMan@@QAEPAVmmEffectFF@@H@Z
    ARTS_IMPORT mmEffectFF* GetFFEffect(i32 arg1);

    // ?GetJoyAxis@mmJoyMan@@QAEMHH@Z
    ARTS_IMPORT f32 GetJoyAxis(i32 arg1, i32 arg2);

    // ?GetJoyButton@mmJoyMan@@QAEHHH@Z
    ARTS_IMPORT i32 GetJoyButton(i32 arg1, i32 arg2);

    // ?GetOneButton@mmJoyMan@@QAEHJ@Z
    ARTS_EXPORT i32 GetOneButton(ilong flags);

    // ?HasCoolie@mmJoyMan@@QAEHXZ
    ARTS_IMPORT i32 HasCoolie();

    // ?HasThrottle@mmJoyMan@@QAEHXZ
    ARTS_IMPORT i32 HasThrottle();

    // ?Init@mmJoyMan@@QAEHPAUHINSTANCE__@@PAUHWND__@@@Z
    ARTS_IMPORT i32 Init(HINSTANCE__* arg1, HWND__* arg2);

    // ?PollJoyAxes@mmJoyMan@@QAEHXZ
    ARTS_IMPORT i32 PollJoyAxes();

    // ?PollJoyButtons@mmJoyMan@@QAEHXZ
    ARTS_IMPORT i32 PollJoyButtons();

    // ?SetCapture@mmJoyMan@@QAEXH@Z
    ARTS_IMPORT void SetCapture(i32 arg1);

    // ?StopAllFF@mmJoyMan@@QAEXXZ
    ARTS_IMPORT void StopAllFF();

    // ?ToggleEnabled@mmJoyMan@@QAEHH@Z
    ARTS_IMPORT i32 ToggleEnabled(i32 arg1);

    // ?Update@mmJoyMan@@QAEXXZ
    ARTS_IMPORT void Update();

    u8 gap0[0x48];
};

check_size(mmJoyMan, 0x48);
