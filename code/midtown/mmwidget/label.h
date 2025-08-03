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

#define UI_LABEL_VTOP 0x4   // Disables MM_TEXT_VCENTER
#define UI_LABEL_CENTER 0x8 // MM_TEXT_CENTER

class UILabel final : public uiWidget
{
public:
    // ??0UILabel@@QAE@XZ
    ARTS_IMPORT UILabel();

    // ??1UILabel@@UAE@XZ
    ARTS_IMPORT ~UILabel() override;

    // ?Action@UILabel@@UAEXTeqEvent@@@Z | inline
    ARTS_EXPORT void Action(eqEvent arg1) override;

    // ?Init@UILabel@@QAEXPAULocString@@HMMMMH@Z
    ARTS_IMPORT void Init(LocString* arg1, i32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7);

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
