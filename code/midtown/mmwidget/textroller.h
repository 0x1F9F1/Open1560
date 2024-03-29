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
    mmwidget:textroller

    0x4B9F90 | public: __thiscall UITextRoller::UITextRoller(void) | ??0UITextRoller@@QAE@XZ
    0x4BA070 | public: virtual __thiscall UITextRoller::~UITextRoller(void) | ??1UITextRoller@@UAE@XZ
    0x4BA0E0 | public: void __thiscall UITextRoller::Init(struct LocString *,int *,float,float,float,float,class string,int,int,int,int,class Callback,class UIMenu *) | ?Init@UITextRoller@@QAEXPAULocString@@PAHMMMMVstring@@HHHHVCallback@@PAVUIMenu@@@Z
    0x4BA5B0 | public: virtual void __thiscall UITextRoller::Update(void) | ?Update@UITextRoller@@UAEXXZ
    0x4BA610 | public: virtual void __thiscall UITextRoller::Switch(int) | ?Switch@UITextRoller@@UAEXH@Z
    0x4BA640 | public: virtual void __thiscall UITextRoller::Action(union eqEvent) | ?Action@UITextRoller@@UAEXTeqEvent@@@Z
    0x4BA720 | public: void __thiscall UITextRoller::EvalMouseXY(float,float) | ?EvalMouseXY@UITextRoller@@QAEXMM@Z
    0x4BA8B0 | public: int __thiscall UITextRoller::SetValue(int) | ?SetValue@UITextRoller@@QAEHH@Z
    0x4BA950 | public: void __thiscall UITextRoller::SetString(class string) | ?SetString@UITextRoller@@QAEXVstring@@@Z
    0x4BAA20 | public: void __thiscall UITextRoller::SetText(void) | ?SetText@UITextRoller@@QAEXXZ
    0x4BAA90 | public: int __thiscall UITextRoller::Inc(void) | ?Inc@UITextRoller@@QAEHXZ
    0x4BAAB0 | public: int __thiscall UITextRoller::Dec(void) | ?Dec@UITextRoller@@QAEHXZ
    0x4BAAD0 | public: virtual void __thiscall UITextRoller::Cull(void) | ?Cull@UITextRoller@@UAEXXZ
    0x4BAB80 | public: virtual void * __thiscall UITextRoller::`vector deleting destructor'(unsigned int) | ??_EUITextRoller@@UAEPAXI@Z
    0x4BAB80 | public: virtual void * __thiscall UITextRoller::`scalar deleting destructor'(unsigned int) | ??_GUITextRoller@@UAEPAXI@Z
    0x61EC88 | const UITextRoller::`vftable' | ??_7UITextRoller@@6B@
*/

#include "widget.h"

class UITextRoller final : public uiWidget
{
public:
    // ??0UITextRoller@@QAE@XZ
    ARTS_IMPORT UITextRoller();

    // ??_GUITextRoller@@UAEPAXI@Z
    // ??_EUITextRoller@@UAEPAXI@Z
    // ??1UITextRoller@@UAE@XZ
    ARTS_IMPORT ~UITextRoller() override;

    // ?Action@UITextRoller@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(eqEvent arg1) override;

    // ?Cull@UITextRoller@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?Dec@UITextRoller@@QAEHXZ
    ARTS_IMPORT i32 Dec();

    // ?EvalMouseXY@UITextRoller@@QAEXMM@Z
    ARTS_IMPORT void EvalMouseXY(f32 arg1, f32 arg2);

    // ?Inc@UITextRoller@@QAEHXZ
    ARTS_IMPORT i32 Inc();

    // ?Init@UITextRoller@@QAEXPAULocString@@PAHMMMMVstring@@HHHHVCallback@@PAVUIMenu@@@Z
    ARTS_IMPORT void Init(LocString* arg1, i32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, string arg7, i32 arg8,
        i32 arg9, i32 arg10, i32 arg11, Callback arg12, UIMenu* arg13);

    // ?SetString@UITextRoller@@QAEXVstring@@@Z
    ARTS_IMPORT void SetString(string arg1);

    // ?SetText@UITextRoller@@QAEXXZ
    ARTS_IMPORT void SetText();

    // ?SetValue@UITextRoller@@QAEHH@Z
    ARTS_IMPORT i32 SetValue(i32 arg1);

    // ?Switch@UITextRoller@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // ?Update@UITextRoller@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap74[0x9C];
};

check_size(UITextRoller, 0x110);
