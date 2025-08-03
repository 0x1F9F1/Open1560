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

class UITextRoller2 final : public uiWidget
{
public:
    // ??0UITextRoller2@@QAE@XZ
    ARTS_IMPORT UITextRoller2();

    // ??1UITextRoller2@@UAE@XZ
    ARTS_IMPORT ~UITextRoller2() override;

    // ?Action@UITextRoller2@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(eqEvent arg1) override;

    // ?Cull@UITextRoller2@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?Dec@UITextRoller2@@QAEHXZ
    ARTS_IMPORT i32 Dec();

    // ?EvalMouseXY@UITextRoller2@@QAEXMM@Z
    ARTS_IMPORT void EvalMouseXY(f32 arg1, f32 arg2);

    // ?Inc@UITextRoller2@@QAEHXZ
    ARTS_IMPORT i32 Inc();

    // ?Init@UITextRoller2@@QAEXPAULocString@@PAHMMMMVstring@@HHHHVCallback@@PAVUIMenu@@@Z
    ARTS_IMPORT void Init(LocString* arg1, i32* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, string arg7, i32 arg8,
        i32 arg9, i32 arg10, i32 arg11, Callback arg12, UIMenu* arg13);

    // ?SetString@UITextRoller2@@QAEXVstring@@@Z
    ARTS_IMPORT void SetString(string arg1);

    // ?SetText@UITextRoller2@@QAEXXZ
    ARTS_IMPORT void SetText();

    // ?SetValue@UITextRoller2@@QAEHH@Z
    ARTS_IMPORT i32 SetValue(i32 arg1);

    // ?Switch@UITextRoller2@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // ?Update@UITextRoller2@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap74[0xD0];
};

check_size(UITextRoller2, 0x144);
