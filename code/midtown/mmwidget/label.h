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
    mmwidget:label

    0x4B9600 | public: __thiscall UILabel::UILabel(void) | ??0UILabel@@QAE@XZ
    0x4B9690 | public: virtual __thiscall UILabel::~UILabel(void) | ??1UILabel@@UAE@XZ
    0x4B96F0 | public: void __thiscall UILabel::Init(struct LocString *,int,float,float,float,float,int) | ?Init@UILabel@@QAEXPAULocString@@HMMMMH@Z
    0x4B97B0 | public: void __thiscall UILabel::SetText(struct LocString *) | ?SetText@UILabel@@QAEXPAULocString@@@Z
    0x4B97D0 | public: virtual void __thiscall UILabel::Update(void) | ?Update@UILabel@@UAEXXZ
    0x4B9820 | public: void __thiscall UILabel::SetBlink(int) | ?SetBlink@UILabel@@QAEXH@Z
    0x4B9850 | public: virtual void __thiscall UILabel::Switch(int) | ?Switch@UILabel@@UAEXH@Z
    0x4B9860 | public: void __thiscall UILabel::SwitchState(int) | ?SwitchState@UILabel@@QAEXH@Z
    0x4B98C0 | public: virtual void * __thiscall UILabel::`vector deleting destructor'(unsigned int) | ??_EUILabel@@UAEPAXI@Z
    0x4B98C0 | public: virtual void * __thiscall UILabel::`scalar deleting destructor'(unsigned int) | ??_GUILabel@@UAEPAXI@Z
    0x4B98F0 | public: virtual void __thiscall UILabel::Action(union eqEvent) | ?Action@UILabel@@UAEXTeqEvent@@@Z
    0x61EB28 | const UILabel::`vftable' | ??_7UILabel@@6B@
    0x705A10 | public: static float UILabel::TextHeight | ?TextHeight@UILabel@@2MA
*/

#include "widget.h"

#define UI_LABEL_VTOP 0x4   // Disables MM_TEXT_VCENTER
#define UI_LABEL_CENTER 0x8 // MM_TEXT_CENTER

class UILabel final : public uiWidget
{
public:
    // ??0UILabel@@QAE@XZ
    ARTS_IMPORT UILabel();

    // ??_GUILabel@@UAEPAXI@Z
    // ??_EUILabel@@UAEPAXI@Z
    // ??1UILabel@@UAE@XZ
    ARTS_IMPORT ~UILabel() override;

    // ?Action@UILabel@@UAEXTeqEvent@@@Z | inline
    ARTS_EXPORT void Action(eqEvent arg1) override;

    // ?Init@UILabel@@QAEXPAULocString@@HMMMMH@Z
    ARTS_IMPORT void Init(LocString* arg1, i32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7);

    // ?SetBlink@UILabel@@QAEXH@Z | unused
    ARTS_IMPORT void SetBlink(i32 arg1);

    // ?SetText@UILabel@@QAEXPAULocString@@@Z
    ARTS_IMPORT void SetText(LocString* arg1);

    // ?Switch@UILabel@@UAEXH@Z
    ARTS_EXPORT void Switch(i32 arg1) override;

    // ?SwitchState@UILabel@@QAEXH@Z
    ARTS_IMPORT void SwitchState(i32 arg1);

    // ?Update@UILabel@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?TextHeight@UILabel@@2MA
    ARTS_IMPORT static f32 TextHeight;

    u8 gap74[0x14];
};

check_size(UILabel, 0x88);
