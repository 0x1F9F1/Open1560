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

#include "textfield.h"

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

class UITextRoller : public uiWidget
{
    // const UITextRoller::`vftable' @ 0x61EC88

public:
    // 0x4B9F90 | ??0UITextRoller@@QAE@XZ
    UITextRoller();

    // 0x4BAB80 | ??_GUITextRoller@@UAEPAXI@Z
    // 0x4BA070 | ??1UITextRoller@@UAE@XZ
    ~UITextRoller() override;

    // 0x4BA640 | ?Action@UITextRoller@@UAEXTeqEvent@@@Z
    void Action(union eqEvent arg1) override;

    // 0x4BAAD0 | ?Cull@UITextRoller@@UAEXXZ
    void Cull() override;

    // 0x4BAAB0 | ?Dec@UITextRoller@@QAEHXZ
    i32 Dec();

    // 0x4BA720 | ?EvalMouseXY@UITextRoller@@QAEXMM@Z
    void EvalMouseXY(f32 arg1, f32 arg2);

    // 0x4BAA90 | ?Inc@UITextRoller@@QAEHXZ
    i32 Inc();

    // 0x4BA0E0 | ?Init@UITextRoller@@QAEXPAULocString@@PAHMMMMVstring@@HHHHVCallback@@PAVUIMenu@@@Z
    void Init(struct LocString* arg1, i32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, class string arg7, i32 arg8,
        i32 arg9, i32 arg10, i32 arg11, class Callback arg12, class UIMenu* arg13);

    // 0x4BA950 | ?SetString@UITextRoller@@QAEXVstring@@@Z
    void SetString(class string arg1);

    // 0x4BAA20 | ?SetText@UITextRoller@@QAEXXZ
    void SetText();

    // 0x4BA8B0 | ?SetValue@UITextRoller@@QAEHH@Z
    i32 SetValue(i32 arg1);

    // 0x4BA610 | ?Switch@UITextRoller@@UAEXH@Z
    void Switch(i32 arg1) override;

    // 0x4BA5B0 | ?Update@UITextRoller@@UAEXXZ
    void Update() override;
};

check_size(UITextRoller, 0x110);
