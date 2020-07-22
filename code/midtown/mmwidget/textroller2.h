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
    mmwidget:textroller2

    0x4BABB0 | public: __thiscall UITextRoller2::UITextRoller2(void) | ??0UITextRoller2@@QAE@XZ
    0x4BAC60 | public: virtual __thiscall UITextRoller2::~UITextRoller2(void) | ??1UITextRoller2@@UAE@XZ
    0x4BACD0 | public: void __thiscall UITextRoller2::Init(struct LocString *,int *,float,float,float,float,class string,int,int,int,int,class Callback,class UIMenu *) | ?Init@UITextRoller2@@QAEXPAULocString@@PAHMMMMVstring@@HHHHVCallback@@PAVUIMenu@@@Z
    0x4BB3C0 | public: virtual void __thiscall UITextRoller2::Update(void) | ?Update@UITextRoller2@@UAEXXZ
    0x4BB420 | public: virtual void __thiscall UITextRoller2::Switch(int) | ?Switch@UITextRoller2@@UAEXH@Z
    0x4BB4C0 | public: virtual void __thiscall UITextRoller2::Action(union eqEvent) | ?Action@UITextRoller2@@UAEXTeqEvent@@@Z
    0x4BB5A0 | public: void __thiscall UITextRoller2::EvalMouseXY(float,float) | ?EvalMouseXY@UITextRoller2@@QAEXMM@Z
    0x4BB710 | public: int __thiscall UITextRoller2::SetValue(int) | ?SetValue@UITextRoller2@@QAEHH@Z
    0x4BB7C0 | public: void __thiscall UITextRoller2::SetString(class string) | ?SetString@UITextRoller2@@QAEXVstring@@@Z
    0x4BB890 | public: void __thiscall UITextRoller2::SetData(int *) | ?SetData@UITextRoller2@@QAEXPAH@Z
    0x4BB8B0 | public: void __thiscall UITextRoller2::SetText(void) | ?SetText@UITextRoller2@@QAEXXZ
    0x4BB920 | public: int __thiscall UITextRoller2::Inc(void) | ?Inc@UITextRoller2@@QAEHXZ
    0x4BB950 | public: int __thiscall UITextRoller2::Dec(void) | ?Dec@UITextRoller2@@QAEHXZ
    0x4BB980 | public: virtual void __thiscall UITextRoller2::Cull(void) | ?Cull@UITextRoller2@@UAEXXZ
    0x4BBA50 | public: virtual void * __thiscall UITextRoller2::`scalar deleting destructor'(unsigned int) | ??_GUITextRoller2@@UAEPAXI@Z
    0x4BBA50 | public: virtual void * __thiscall UITextRoller2::`vector deleting destructor'(unsigned int) | ??_EUITextRoller2@@UAEPAXI@Z
    0x61ED08 | const UITextRoller2::`vftable' | ??_7UITextRoller2@@6B@
*/

#include "widget.h"

class UITextRoller2 final : public uiWidget
{
    // const UITextRoller2::`vftable' @ 0x61ED08

public:
    // 0x4BABB0 | ??0UITextRoller2@@QAE@XZ
    ARTS_IMPORT UITextRoller2();

    // 0x4BBA50 | ??_EUITextRoller2@@UAEPAXI@Z
    // 0x4BBA50 | ??_GUITextRoller2@@UAEPAXI@Z
    // 0x4BAC60 | ??1UITextRoller2@@UAE@XZ
    ARTS_IMPORT ~UITextRoller2() override;

    // 0x4BB4C0 | ?Action@UITextRoller2@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(union eqEvent arg1) override;

    // 0x4BB980 | ?Cull@UITextRoller2@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x4BB950 | ?Dec@UITextRoller2@@QAEHXZ
    ARTS_IMPORT i32 Dec();

    // 0x4BB5A0 | ?EvalMouseXY@UITextRoller2@@QAEXMM@Z
    ARTS_IMPORT void EvalMouseXY(f32 arg1, f32 arg2);

    // 0x4BB920 | ?Inc@UITextRoller2@@QAEHXZ
    ARTS_IMPORT i32 Inc();

    // 0x4BACD0 | ?Init@UITextRoller2@@QAEXPAULocString@@PAHMMMMVstring@@HHHHVCallback@@PAVUIMenu@@@Z
    ARTS_IMPORT void Init(struct LocString* arg1, i32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, class string arg7,
        i32 arg8, i32 arg9, i32 arg10, i32 arg11, class Callback arg12, class UIMenu* arg13);

    // 0x4BB890 | ?SetData@UITextRoller2@@QAEXPAH@Z | unused
    ARTS_IMPORT void SetData(i32* arg1);

    // 0x4BB7C0 | ?SetString@UITextRoller2@@QAEXVstring@@@Z
    ARTS_IMPORT void SetString(class string arg1);

    // 0x4BB8B0 | ?SetText@UITextRoller2@@QAEXXZ
    ARTS_IMPORT void SetText();

    // 0x4BB710 | ?SetValue@UITextRoller2@@QAEHH@Z
    ARTS_IMPORT i32 SetValue(i32 arg1);

    // 0x4BB420 | ?Switch@UITextRoller2@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // 0x4BB3C0 | ?Update@UITextRoller2@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap74[0xD0];
};

check_size(UITextRoller2, 0x144);
