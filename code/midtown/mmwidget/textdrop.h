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
    mmwidget:textdrop

    0x4B2ED0 | public: __thiscall UITextDropdown::UITextDropdown(void) | ??0UITextDropdown@@QAE@XZ
    0x4B2F60 | public: virtual __thiscall UITextDropdown::~UITextDropdown(void) | ??1UITextDropdown@@UAE@XZ
    0x4B2FD0 | public: void __thiscall UITextDropdown::Init(struct LocString *,int *,float,float,float,float,class string,int,int,int,class Callback,char *) | ?Init@UITextDropdown@@QAEXPAULocString@@PAHMMMMVstring@@HHHVCallback@@PAD@Z
    0x4B3390 | public: virtual float __thiscall UITextDropdown::GetScreenHeight(void) | ?GetScreenHeight@UITextDropdown@@UAEMXZ
    0x4B33A0 | public: void __thiscall UITextDropdown::SetPos(float,float) | ?SetPos@UITextDropdown@@QAEXMM@Z
    0x4B33B0 | public: void __thiscall UITextDropdown::AssignString(class string) | ?AssignString@UITextDropdown@@QAEXVstring@@@Z
    0x4B3460 | public: void __thiscall UITextDropdown::SetData(int *) | ?SetData@UITextDropdown@@QAEXPAH@Z
    0x4B3490 | public: virtual void __thiscall UITextDropdown::Update(void) | ?Update@UITextDropdown@@UAEXXZ
    0x4B3500 | public: void __thiscall UITextDropdown::SetText(struct LocString *) | ?SetText@UITextDropdown@@QAEXPAULocString@@@Z
    0x4B3510 | public: virtual void __thiscall UITextDropdown::CaptureAction(union eqEvent) | ?CaptureAction@UITextDropdown@@UAEXTeqEvent@@@Z
    0x4B3680 | public: virtual void __thiscall UITextDropdown::Action(union eqEvent) | ?Action@UITextDropdown@@UAEXTeqEvent@@@Z
    0x4B37B0 | public: virtual void __thiscall UITextDropdown::Switch(int) | ?Switch@UITextDropdown@@UAEXH@Z
    0x4B3830 | public: void __thiscall UITextDropdown::SetSliderFocus(int) | ?SetSliderFocus@UITextDropdown@@QAEXH@Z
    0x4B38B0 | public: int __thiscall UITextDropdown::GetValue(void) | ?GetValue@UITextDropdown@@QAEHXZ
    0x4B38C0 | public: int __thiscall UITextDropdown::SetValue(int) | ?SetValue@UITextDropdown@@QAEHH@Z
    0x4B38F0 | public: void __thiscall UITextDropdown::SetDisabledMask(long) | ?SetDisabledMask@UITextDropdown@@QAEXJ@Z
    0x4B3910 | public: int __thiscall UITextDropdown::AnyEnabled(void) | ?AnyEnabled@UITextDropdown@@QAEHXZ
    0x4B3920 | public: virtual void __thiscall UITextDropdown::Cull(void) | ?Cull@UITextDropdown@@UAEXXZ
    0x4B3980 | public: virtual void * __thiscall UITextDropdown::`vector deleting destructor'(unsigned int) | ??_EUITextDropdown@@UAEPAXI@Z
    0x4B3980 | public: virtual void * __thiscall UITextDropdown::`scalar deleting destructor'(unsigned int) | ??_GUITextDropdown@@UAEPAXI@Z
    0x61E4F8 | const UITextDropdown::`vftable' | ??_7UITextDropdown@@6B@
*/

#include "widget.h"

class UITextDropdown : public uiWidget
{
    // const UITextDropdown::`vftable' @ 0x61E4F8

public:
    // 0x4B2ED0 | ??0UITextDropdown@@QAE@XZ
    ARTS_IMPORT UITextDropdown();

    // 0x4B3980 | ??_GUITextDropdown@@UAEPAXI@Z
    // 0x4B3980 | ??_EUITextDropdown@@UAEPAXI@Z
    // 0x4B2F60 | ??1UITextDropdown@@UAE@XZ
    ARTS_IMPORT ~UITextDropdown() override;

    // 0x4B3680 | ?Action@UITextDropdown@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(union eqEvent arg1) override;

    // 0x4B3910 | ?AnyEnabled@UITextDropdown@@QAEHXZ | unused
    ARTS_IMPORT i32 AnyEnabled();

    // 0x4B33B0 | ?AssignString@UITextDropdown@@QAEXVstring@@@Z
    ARTS_IMPORT void AssignString(class string arg1);

    // 0x4B3510 | ?CaptureAction@UITextDropdown@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void CaptureAction(union eqEvent arg1) override;

    // 0x4B3920 | ?Cull@UITextDropdown@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x4B3390 | ?GetScreenHeight@UITextDropdown@@UAEMXZ
    ARTS_IMPORT f32 GetScreenHeight() override;

    // 0x4B38B0 | ?GetValue@UITextDropdown@@QAEHXZ | unused
    ARTS_IMPORT i32 GetValue();

    // 0x4B2FD0 | ?Init@UITextDropdown@@QAEXPAULocString@@PAHMMMMVstring@@HHHVCallback@@PAD@Z
    ARTS_IMPORT void Init(struct LocString* arg1, i32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, class string arg7,
        i32 arg8, i32 arg9, i32 arg10, class Callback arg11, char* arg12);

    // 0x4B3460 | ?SetData@UITextDropdown@@QAEXPAH@Z
    ARTS_IMPORT void SetData(i32* arg1);

    // 0x4B38F0 | ?SetDisabledMask@UITextDropdown@@QAEXJ@Z
    ARTS_IMPORT void SetDisabledMask(i32 arg1);

    // 0x4B33A0 | ?SetPos@UITextDropdown@@QAEXMM@Z | unused
    ARTS_IMPORT void SetPos(f32 arg1, f32 arg2);

    // 0x4B3830 | ?SetSliderFocus@UITextDropdown@@QAEXH@Z
    ARTS_IMPORT void SetSliderFocus(i32 arg1);

    // 0x4B3500 | ?SetText@UITextDropdown@@QAEXPAULocString@@@Z | unused
    ARTS_IMPORT void SetText(struct LocString* arg1);

    // 0x4B38C0 | ?SetValue@UITextDropdown@@QAEHH@Z
    ARTS_IMPORT i32 SetValue(i32 arg1);

    // 0x4B37B0 | ?Switch@UITextDropdown@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // 0x4B3490 | ?Update@UITextDropdown@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap74[0x90];
};

check_size(UITextDropdown, 0x104);
