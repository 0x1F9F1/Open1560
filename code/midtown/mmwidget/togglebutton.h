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
    mmwidget:togglebutton

    0x4BC490 | public: __thiscall UIToggleButton::UIToggleButton(void) | ??0UIToggleButton@@QAE@XZ
    0x4BC510 | public: virtual __thiscall UIToggleButton::~UIToggleButton(void) | ??1UIToggleButton@@UAE@XZ
    0x4BC580 | public: void __thiscall UIToggleButton::Init(struct LocString *,int *,float,float,float,float,int,int,class Callback) | ?Init@UIToggleButton@@QAEXPAULocString@@PAHMMMMHHVCallback@@@Z
    0x4BC620 | protected: virtual void __thiscall UIToggleButton::DrawOff(void) | ?DrawOff@UIToggleButton@@MAEXXZ
    0x4BC640 | protected: virtual void __thiscall UIToggleButton::DrawOn(void) | ?DrawOn@UIToggleButton@@MAEXXZ
    0x4BC660 | public: virtual void __thiscall UIToggleButton::DoToggle(void) | ?DoToggle@UIToggleButton@@UAEXXZ
    0x4BC680 | public: virtual void __thiscall UIToggleButton::Action(union eqEvent) | ?Action@UIToggleButton@@UAEXTeqEvent@@@Z
    0x4BC6F0 | public: virtual void * __thiscall UIToggleButton::`scalar deleting destructor'(unsigned int) | ??_GUIToggleButton@@UAEPAXI@Z
    0x4BC6F0 | public: virtual void * __thiscall UIToggleButton::`vector deleting destructor'(unsigned int) | ??_EUIToggleButton@@UAEPAXI@Z
    0x4BC720 | public: virtual void __thiscall UIToggleButton::Update(void) | ?Update@UIToggleButton@@UAEXXZ
    0x61EE98 | const UIToggleButton::`vftable' | ??_7UIToggleButton@@6B@
    0x705C1C | protected: static int UIToggleButton::ToggleBMLoaded | ?ToggleBMLoaded@UIToggleButton@@1HA
*/

#include "button.h"

class UIToggleButton final : public UIButton
{
    // const UIToggleButton::`vftable'

public:
    // ??0UIToggleButton@@QAE@XZ
    ARTS_IMPORT UIToggleButton();

    // ??_EUIToggleButton@@UAEPAXI@Z
    // ??_GUIToggleButton@@UAEPAXI@Z
    // ??1UIToggleButton@@UAE@XZ
    ARTS_IMPORT ~UIToggleButton() override;

    // ?DoToggle@UIToggleButton@@UAEXXZ
    ARTS_IMPORT virtual void DoToggle();

    // ?Action@UIToggleButton@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(union eqEvent arg1) override;

    // ?Init@UIToggleButton@@QAEXPAULocString@@PAHMMMMHHVCallback@@@Z
    ARTS_IMPORT void Init(struct LocString* arg1, i32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7, i32 arg8,
        class Callback arg9);

    // ?Update@UIToggleButton@@UAEXXZ | inline
    ARTS_IMPORT void Update() override;

protected:
    // ?DrawOff@UIToggleButton@@MAEXXZ
    ARTS_IMPORT virtual void DrawOff();

    // ?DrawOn@UIToggleButton@@MAEXXZ
    ARTS_IMPORT virtual void DrawOn();

    // ?ToggleBMLoaded@UIToggleButton@@1HA
    ARTS_IMPORT static i32 ToggleBMLoaded;

    u8 gapB4[0x8];
};

check_size(UIToggleButton, 0xBC);
