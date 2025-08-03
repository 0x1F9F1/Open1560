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

#include "widget.h"

class TextDropWidget;

class UITextDropdown final : public uiWidget
{
public:
    // ??0UITextDropdown@@QAE@XZ
    ARTS_IMPORT UITextDropdown();

    // ??1UITextDropdown@@UAE@XZ
    ARTS_IMPORT ~UITextDropdown() override;

    // ?Action@UITextDropdown@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(eqEvent arg1) override;

    // ?AssignString@UITextDropdown@@QAEXVstring@@@Z
    ARTS_EXPORT void AssignString(string options);

    // ?CaptureAction@UITextDropdown@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void CaptureAction(eqEvent arg1) override;

    // ?Cull@UITextDropdown@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?GetScreenHeight@UITextDropdown@@UAEMXZ
    ARTS_IMPORT f32 GetScreenHeight() override;

    // ?Init@UITextDropdown@@QAEXPAULocString@@PAHMMMMVstring@@HHHVCallback@@PAD@Z
    ARTS_IMPORT void Init(LocString* arg1, i32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, string arg7, i32 arg8,
        i32 arg9, i32 arg10, Callback arg11, char* arg12);

    // ?SetData@UITextDropdown@@QAEXPAH@Z
    ARTS_IMPORT void SetData(i32* arg1);

    // ?SetDisabledMask@UITextDropdown@@QAEXJ@Z
    ARTS_IMPORT void SetDisabledMask(ilong arg1);

    // ?SetPos@UITextDropdown@@QAEXMM@Z | unused
    void SetPos(f32 arg1, f32 arg2);

    // ?SetSliderFocus@UITextDropdown@@QAEXH@Z
    ARTS_IMPORT void SetSliderFocus(i32 arg1);

    // ?SetText@UITextDropdown@@QAEXPAULocString@@@Z | unused
    void SetText(LocString* arg1);

    // ?SetValue@UITextDropdown@@QAEHH@Z
    ARTS_IMPORT i32 SetValue(i32 arg1);

    // ?Switch@UITextDropdown@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // ?Update@UITextDropdown@@UAEXXZ
    ARTS_IMPORT void Update() override;

    offset_field(0x9C, TextDropWidget*, DropWidget);
    offset_field(0xB4, i32*, ValuePtr);

    u8 gap74[0x90];
};

check_size(UITextDropdown, 0x104);
