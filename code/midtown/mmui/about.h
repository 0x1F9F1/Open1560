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

#include "mmwidget/menu.h"

void GetMidtownRegString(char* buffer, i32 buffer_len, char* key, char* default_value);

class AboutMenu final : public UIMenu
{
public:
    // ??0AboutMenu@@QAE@H@Z
    ARTS_IMPORT AboutMenu(i32 arg1);

    // ??_EAboutMenu@@UAEPAXI@Z
    // ??_GAboutMenu@@UAEPAXI@Z
    // ??1AboutMenu@@UAE@XZ
    ARTS_EXPORT ~AboutMenu() override = default;

    // ?Cull@AboutMenu@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?PreSetup@AboutMenu@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    // ?Update@AboutMenu@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap90[0x20];
};

check_size(AboutMenu, 0xB0);
