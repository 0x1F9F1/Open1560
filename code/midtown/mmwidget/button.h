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
    mmwidget:button

    0x4B9B50 | public: __thiscall UIButton::UIButton(void) | ??0UIButton@@QAE@XZ
    0x4B9BE0 | public: virtual __thiscall UIButton::~UIButton(void) | ??1UIButton@@UAE@XZ
    0x4B9C50 | public: void __thiscall UIButton::Init(struct LocString *,int,float,float,float,float,int,class Callback) | ?Init@UIButton@@QAEXPAULocString@@HMMMMHVCallback@@@Z
    0x4B9D20 | public: virtual void __thiscall UIButton::Update(void) | ?Update@UIButton@@UAEXXZ
    0x4B9D30 | public: void __thiscall UIButton::SetString(struct LocString *) | ?SetString@UIButton@@QAEXPAULocString@@@Z
    0x4B9D50 | private: void __thiscall UIButton::DrawOff(void) | ?DrawOff@UIButton@@AAEXXZ
    0x4B9D80 | private: void __thiscall UIButton::DrawOn(void) | ?DrawOn@UIButton@@AAEXXZ
    0x4B9DB0 | public: virtual void __thiscall UIButton::Action(union eqEvent) | ?Action@UIButton@@UAEXTeqEvent@@@Z
    0x4B9E00 | public: virtual void __thiscall UIButton::SetReadOnly(int) | ?SetReadOnly@UIButton@@UAEXH@Z
    0x4B9E50 | public: virtual void __thiscall UIButton::Switch(int) | ?Switch@UIButton@@UAEXH@Z
    0x4B9ED0 | public: void __thiscall UIButton::SetType(int) | ?SetType@UIButton@@QAEXH@Z
    0x4B9F20 | public: int __thiscall UIButton::TestHit(float,float) | ?TestHit@UIButton@@QAEHMM@Z
    0x4B9F30 | public: virtual void * __thiscall UIButton::`vector deleting destructor'(unsigned int) | ??_EUIButton@@UAEPAXI@Z
    0x4B9F30 | public: virtual void * __thiscall UIButton::`scalar deleting destructor'(unsigned int) | ??_GUIButton@@UAEPAXI@Z
    0x4B9F60 | public: virtual void __thiscall UIButton::Enable(void) | ?Enable@UIButton@@UAEXXZ
    0x4B9F80 | public: virtual void __thiscall UIButton::Disable(void) | ?Disable@UIButton@@UAEXXZ
    0x61EC18 | const UIButton::`vftable' | ??_7UIButton@@6B@
*/

#include "widget.h"

class UIButton : public uiWidget
{
public:
    // ??0UIButton@@QAE@XZ
    ARTS_IMPORT UIButton();

    // ??_GUIButton@@UAEPAXI@Z
    // ??_EUIButton@@UAEPAXI@Z
    // ??1UIButton@@UAE@XZ
    ARTS_IMPORT ~UIButton() override;

    // ?Action@UIButton@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(union eqEvent arg1) override;

    // ?Disable@UIButton@@UAEXXZ | inline
    ARTS_IMPORT void Disable() override;

    // ?Enable@UIButton@@UAEXXZ | inline
    ARTS_IMPORT void Enable() override;

    // ?Init@UIButton@@QAEXPAULocString@@HMMMMHVCallback@@@Z
    ARTS_IMPORT void Init(
        struct LocString* arg1, i32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7, class Callback arg8);

    // ?SetReadOnly@UIButton@@UAEXH@Z
    ARTS_IMPORT void SetReadOnly(i32 arg1) override;

    // ?SetString@UIButton@@QAEXPAULocString@@@Z
    ARTS_IMPORT void SetString(struct LocString* arg1);

    // ?SetType@UIButton@@QAEXH@Z
    ARTS_IMPORT void SetType(i32 arg1);

    // ?Switch@UIButton@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // ?TestHit@UIButton@@QAEHMM@Z | unused
    ARTS_EXPORT i32 TestHit(f32 arg1, f32 arg2);

    // ?Update@UIButton@@UAEXXZ
    ARTS_IMPORT void Update() override;

private:
    // ?DrawOff@UIButton@@AAEXXZ | unused
    ARTS_IMPORT void DrawOff();

    // ?DrawOn@UIButton@@AAEXXZ | unused
    ARTS_IMPORT void DrawOn();

    u8 gap74[0x40];
};

check_size(UIButton, 0xB4);
