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

#include "menu.h"

class uiNavBar final : public UIMenu
{
public:
    // ??0uiNavBar@@QAE@H@Z
    ARTS_IMPORT uiNavBar(i32 arg1);

    // ??_EuiNavBar@@UAEPAXI@Z
    // ??_GuiNavBar@@UAEPAXI@Z
    // ??1uiNavBar@@UAE@XZ
    ARTS_EXPORT ~uiNavBar() override = default;

    // ?BackUp@uiNavBar@@UAEXXZ | inline
    ARTS_EXPORT void BackUp() override;

    // ?Help@uiNavBar@@QAEXXZ
    ARTS_IMPORT void Help();

    // ?Minimize@uiNavBar@@QAEXXZ
    ARTS_IMPORT void Minimize();

    // ?OptionActive@uiNavBar@@QAEXXZ
    ARTS_IMPORT void OptionActive();

    // ?OptionInActive@uiNavBar@@QAEXXZ
    ARTS_IMPORT void OptionInActive();

    // ?SetPrevPos@uiNavBar@@QAEXMM@Z
    ARTS_IMPORT void SetPrevPos(f32 arg1, f32 arg2);

    // ?TurnOffPrev@uiNavBar@@QAEXXZ
    ARTS_IMPORT void TurnOffPrev();

    // ?TurnOnPrev@uiNavBar@@QAEXXZ
    ARTS_IMPORT void TurnOnPrev();

    // ?Update@uiNavBar@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap90[0x30];
};

check_size(uiNavBar, 0xC0);
