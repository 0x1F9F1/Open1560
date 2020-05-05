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
    mmwidget:mexbutton

    0x4BCAB0 | public: __thiscall UIMexButton::UIMexButton(void) | ??0UIMexButton@@QAE@XZ
    0x4BCB30 | public: virtual __thiscall UIMexButton::~UIMexButton(void) | ??1UIMexButton@@UAE@XZ
    0x4BCB40 | public: void __thiscall UIMexButton::Init(struct LocString *,int *,int,float,float,float,float,int,int,class Callback) | ?Init@UIMexButton@@QAEXPAULocString@@PAHHMMMMHHVCallback@@@Z
    0x4BCC10 | public: virtual void __thiscall UIMexButton::Update(void) | ?Update@UIMexButton@@UAEXXZ
    0x4BCC60 | private: virtual void __thiscall UIMexButton::DrawOff(void) | ?DrawOff@UIMexButton@@EAEXXZ
    0x4BCC70 | private: virtual void __thiscall UIMexButton::DrawOn(void) | ?DrawOn@UIMexButton@@EAEXXZ
    0x4BCCA0 | public: virtual void __thiscall UIMexButton::DoToggle(void) | ?DoToggle@UIMexButton@@UAEXXZ
    0x4BCCC0 | public: virtual void __thiscall UIMexButton::Action(union eqEvent) | ?Action@UIMexButton@@UAEXTeqEvent@@@Z
    0x4BCD30 | public: virtual void * __thiscall UIMexButton::`scalar deleting destructor'(unsigned int) | ??_GUIMexButton@@UAEPAXI@Z
    0x4BCD30 | public: virtual void * __thiscall UIMexButton::`vector deleting destructor'(unsigned int) | ??_EUIMexButton@@UAEPAXI@Z
    0x61EFA8 | const UIMexButton::`vftable' | ??_7UIMexButton@@6B@
*/

#include "togglebutton2.h"

class UIMexButton : public UIToggleButton2
{
    // const UIMexButton::`vftable' @ 0x61EFA8

public:
    // 0x4BCAB0 | ??0UIMexButton@@QAE@XZ
    UIMexButton();

    // 0x4BCD30 | ??_EUIMexButton@@UAEPAXI@Z
    // 0x4BCB30 | ??1UIMexButton@@UAE@XZ
    ~UIMexButton() override;

    // 0x4BCCC0 | ?Action@UIMexButton@@UAEXTeqEvent@@@Z
    void Action(union eqEvent arg1) override;

    // 0x4BCCA0 | ?DoToggle@UIMexButton@@UAEXXZ
    void DoToggle() override;

    // 0x4BCB40 | ?Init@UIMexButton@@QAEXPAULocString@@PAHHMMMMHHVCallback@@@Z
    void Init(struct LocString* arg1, i32* arg2, i32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, i32 arg8, i32 arg9,
        class Callback arg10);

    // 0x4BCC10 | ?Update@UIMexButton@@UAEXXZ
    void Update() override;

private:
    // 0x4BCC60 | ?DrawOff@UIMexButton@@EAEXXZ
    void DrawOff() override;

    // 0x4BCC70 | ?DrawOn@UIMexButton@@EAEXXZ
    void DrawOn() override;
};

check_size(UIMexButton, 0xCC);
