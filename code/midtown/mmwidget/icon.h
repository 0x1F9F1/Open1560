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

class agiBitmap;

class UIIcon final : public uiWidget
{
public:
    // ??0UIIcon@@QAE@XZ
    ARTS_IMPORT UIIcon();

    // ??_EUIIcon@@UAEPAXI@Z
    // ??_GUIIcon@@UAEPAXI@Z
    // ??1UIIcon@@UAE@XZ
    ARTS_EXPORT ~UIIcon() override = default;

    // ?CreateDummyBitmap@UIIcon@@QAEPAVagiBitmap@@XZ
    ARTS_IMPORT agiBitmap* CreateDummyBitmap();

    // ?Cull@UIIcon@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?GetHitArea@UIIcon@@QAEXAAM0@Z
    ARTS_IMPORT void GetHitArea(f32& arg1, f32& arg2);

    // ?Init@UIIcon@@QAEXPADMM@Z
    ARTS_IMPORT void Init(char* arg1, f32 arg2, f32 arg3);

    // ?LoadBitmap@UIIcon@@QAEXPAD@Z
    ARTS_IMPORT void LoadBitmap(char* arg1);

    // ?Switch@UIIcon@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // ?Update@UIIcon@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap74[0x20];
};

check_size(UIIcon, 0x94);
