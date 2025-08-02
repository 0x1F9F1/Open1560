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

class UITextField final : public uiWidget
{
public:
    // ??0UITextField@@QAE@XZ
    ARTS_IMPORT UITextField();

    // ??_GUITextField@@UAEPAXI@Z
    // ??_EUITextField@@UAEPAXI@Z
    // ??1UITextField@@UAE@XZ
    ARTS_IMPORT ~UITextField() override;

    // ?Action@UITextField@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(eqEvent arg1) override;

    // ?CaptureAction@UITextField@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void CaptureAction(eqEvent arg1) override;

    // ?Init@UITextField@@QAEXPAULocString@@PADMMMMHHHHHVCallback@@PAVUIMenu@@@Z
    ARTS_IMPORT void Init(LocString* arg1, char* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7, i32 arg8,
        i32 arg9, i32 arg10, i32 arg11, Callback arg12, UIMenu* arg13);

    // ?IsValidChar@UITextField@@QAEHG@Z
    ARTS_IMPORT i32 IsValidChar(u16 arg1);

    // ?KeyAction@UITextField@@QAEXPATeqEvent@@@Z
    ARTS_IMPORT void KeyAction(eqEvent* arg1);

    // ?SetCompositionWindow@UITextField@@QAEXXZ
    ARTS_IMPORT void SetCompositionWindow();

    // ?SetField@UITextField@@QAEXPAD@Z
    ARTS_IMPORT void SetField(char* arg1);

    // ?SetTextField@UITextField@@QAEXXZ
    ARTS_IMPORT void SetTextField();

    // ?Switch@UITextField@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // ?ToggleField@UITextField@@QAEXH@Z
    ARTS_IMPORT void ToggleField(i32 arg1);

    // ?Update@UITextField@@UAEXXZ | inline
    ARTS_IMPORT void Update() override;

    // ?WmCharHandler@UITextField@@QAEXE@Z
    ARTS_IMPORT void WmCharHandler(u8 arg1);

    u8 gap74[0xD0];
};

check_size(UITextField, 0x144);
