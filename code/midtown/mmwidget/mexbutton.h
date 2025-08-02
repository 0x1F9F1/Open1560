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

#include "togglebutton2.h"

class UIMexButton final : public UIToggleButton2
{
public:
    // ??0UIMexButton@@QAE@XZ
    ARTS_IMPORT UIMexButton();

    // ??_EUIMexButton@@UAEPAXI@Z
    // ??_GUIMexButton@@UAEPAXI@Z
    // ??1UIMexButton@@UAE@XZ
    ARTS_EXPORT ~UIMexButton() override = default;

    // ?Action@UIMexButton@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(eqEvent arg1) override;

    // ?DoToggle@UIMexButton@@UAEXXZ
    ARTS_IMPORT void DoToggle() override;

    // ?Init@UIMexButton@@QAEXPAULocString@@PAHHMMMMHHVCallback@@@Z
    ARTS_IMPORT void Init(LocString* arg1, i32* arg2, i32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, i32 arg8,
        i32 arg9, Callback arg10);

    // ?Update@UIMexButton@@UAEXXZ
    ARTS_IMPORT void Update() override;

private:
    // ?DrawOff@UIMexButton@@EAEXXZ
    ARTS_IMPORT void DrawOff() override;

    // ?DrawOn@UIMexButton@@EAEXXZ
    ARTS_IMPORT void DrawOn() override;

    u8 gapC0[0xC];
};

check_size(UIMexButton, 0xCC);
