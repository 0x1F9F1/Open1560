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

class mmIO;

class UIControlWidget final : public uiWidget
{
public:
    // ??0UIControlWidget@@QAE@XZ
    ARTS_IMPORT UIControlWidget();

    // ??_EUIControlWidget@@UAEPAXI@Z
    // ??_GUIControlWidget@@UAEPAXI@Z | unused
    // ??1UIControlWidget@@UAE@XZ
    ARTS_IMPORT ~UIControlWidget() override;

    // ?Action@UIControlWidget@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(eqEvent arg1) override;

    // ?DisableField@UIControlWidget@@QAEXXZ
    ARTS_IMPORT void DisableField();

    // ?EnableField@UIControlWidget@@QAEXXZ
    ARTS_IMPORT void EnableField();

    // ?Init@UIControlWidget@@QAEXMMMMMPAVmmIO@@VCallback@@@Z
    ARTS_IMPORT void Init(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, mmIO* arg6, Callback arg7);

    // ?SetPosition@UIControlWidget@@QAEXMMMM@Z
    ARTS_IMPORT void SetPosition(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // ?Switch@UIControlWidget@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // ?TurnOff@UIControlWidget@@UAEXXZ | inline
    ARTS_IMPORT void TurnOff() override;

    // ?TurnOn@UIControlWidget@@UAEXXZ | inline
    ARTS_IMPORT void TurnOn() override;

    // ?Update@UIControlWidget@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateField@UIControlWidget@@QAEXXZ
    ARTS_IMPORT void UpdateField();

    u8 gap74[0x44];
};

check_size(UIControlWidget, 0xB8);
