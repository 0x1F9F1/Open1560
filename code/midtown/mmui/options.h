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

enum
{
    IDC_OPTIONS_MENU_AUDIO = 100,
    IDC_OPTIONS_MENU_CONTROLS = 101,
    IDC_OPTIONS_MENU_GRAPHICS = 102,
    IDC_OPTIONS_MENU_CREDITS = 103,
};

class OptionsMenu final : public UIMenu
{
public:
    // ??0OptionsMenu@@QAE@H@Z
    ARTS_EXPORT OptionsMenu(i32 menu_id);

    // ??1OptionsMenu@@UAE@XZ
    ARTS_EXPORT ~OptionsMenu() override;

    // ?PostSetup@OptionsMenu@@UAEXXZ
    ARTS_EXPORT void PostSetup() override;

    // ?PreSetup@OptionsMenu@@UAEXXZ
    ARTS_EXPORT void PreSetup() override;

    f32 previous_x_;
    f32 previous_y_;
};

check_size(OptionsMenu, 0x98);
