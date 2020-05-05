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
    mmui:pu_menu

    0x4AAFE0 | public: __thiscall PUMenuBase::PUMenuBase(int,float,float,float,float,char *) | ??0PUMenuBase@@QAE@HMMMMPAD@Z
    0x4AB1B0 | public: virtual __thiscall PUMenuBase::~PUMenuBase(void) | ??1PUMenuBase@@UAE@XZ
    0x4AB210 | public: class agiBitmap * __thiscall PUMenuBase::CreateDummyBitmap(void) | ?CreateDummyBitmap@PUMenuBase@@QAEPAVagiBitmap@@XZ
    0x4AB270 | public: float __thiscall PUMenuBase::CreateTitle(void) | ?CreateTitle@PUMenuBase@@QAEMXZ
    0x4AB280 | public: float __thiscall PUMenuBase::AddPrevious(float,float,float,float) | ?AddPrevious@PUMenuBase@@QAEMMMMM@Z
    0x4AB2F0 | public: void __thiscall PUMenuBase::AddOKCancel(class Callback,class Callback) | ?AddOKCancel@PUMenuBase@@QAEXVCallback@@0@Z
    0x4AB390 | public: float __thiscall PUMenuBase::AddExit(float,float,float,float) | ?AddExit@PUMenuBase@@QAEMMMMM@Z
    0x4AB400 | public: virtual void __thiscall PUMenuBase::Update(void) | ?Update@PUMenuBase@@UAEXXZ
    0x4AB430 | public: virtual void __thiscall PUMenuBase::Cull(void) | ?Cull@PUMenuBase@@UAEXXZ
    0x4AB470 | public: void __thiscall PUMenuBase::DisableExit(void) | ?DisableExit@PUMenuBase@@QAEXXZ
    0x4AB480 | public: void __thiscall PUMenuBase::EnableExit(void) | ?EnableExit@PUMenuBase@@QAEXXZ
    0x4AB490 | public: virtual void * __thiscall PUMenuBase::`scalar deleting destructor'(unsigned int) | ??_GPUMenuBase@@UAEPAXI@Z
    0x4AB490 | public: virtual void * __thiscall PUMenuBase::`vector deleting destructor'(unsigned int) | ??_EPUMenuBase@@UAEPAXI@Z
    0x61E200 | const PUMenuBase::`vftable' | ??_7PUMenuBase@@6B@
*/

#include "mmwidget/menu.h"

class PUMenuBase : public UIMenu
{
    // const PUMenuBase::`vftable' @ 0x61E200

public:
    // 0x4AAFE0 | ??0PUMenuBase@@QAE@HMMMMPAD@Z
    PUMenuBase(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, char* arg6);

    // 0x4AB490 | ??_EPUMenuBase@@UAEPAXI@Z
    // 0x4AB1B0 | ??1PUMenuBase@@UAE@XZ
    ~PUMenuBase() override;

    // 0x4AB390 | ?AddExit@PUMenuBase@@QAEMMMMM@Z
    f32 AddExit(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x4AB2F0 | ?AddOKCancel@PUMenuBase@@QAEXVCallback@@0@Z
    void AddOKCancel(class Callback arg1, class Callback arg2);

    // 0x4AB280 | ?AddPrevious@PUMenuBase@@QAEMMMMM@Z
    f32 AddPrevious(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x4AB210 | ?CreateDummyBitmap@PUMenuBase@@QAEPAVagiBitmap@@XZ
    class agiBitmap* CreateDummyBitmap();

    // 0x4AB270 | ?CreateTitle@PUMenuBase@@QAEMXZ
    f32 CreateTitle();

    // 0x4AB430 | ?Cull@PUMenuBase@@UAEXXZ
    void Cull() override;

    // 0x4AB470 | ?DisableExit@PUMenuBase@@QAEXXZ
    void DisableExit();

    // 0x4AB480 | ?EnableExit@PUMenuBase@@QAEXXZ
    void EnableExit();

    // 0x4AB400 | ?Update@PUMenuBase@@UAEXXZ
    void Update() override;
};

check_size(PUMenuBase, 0x0);
