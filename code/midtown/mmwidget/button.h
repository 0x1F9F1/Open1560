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
    ARTS_IMPORT void Action(eqEvent arg1) override;

    // ?Disable@UIButton@@UAEXXZ | inline
    ARTS_IMPORT void Disable() override;

    // ?Enable@UIButton@@UAEXXZ | inline
    ARTS_IMPORT void Enable() override;

    // ?Init@UIButton@@QAEXPAULocString@@HMMMMHVCallback@@@Z
    ARTS_IMPORT void Init(LocString* arg1, i32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7, Callback arg8);

    // ?SetReadOnly@UIButton@@UAEXH@Z
    ARTS_IMPORT void SetReadOnly(i32 arg1) override;

    // ?SetString@UIButton@@QAEXPAULocString@@@Z
    ARTS_IMPORT void SetString(LocString* arg1);

    // ?SetType@UIButton@@QAEXH@Z
    ARTS_IMPORT void SetType(i32 arg1);

    // ?Switch@UIButton@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // ?TestHit@UIButton@@QAEHMM@Z | unused
    ARTS_EXPORT i32 TestHit(f32 arg1, f32 arg2);

    // ?Update@UIButton@@UAEXXZ
    ARTS_IMPORT void Update() override;

private:
    u8 gap74[0x40];
};

check_size(UIButton, 0xB4);
