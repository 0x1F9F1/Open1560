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
    IDC_MAIN_MENU_QUICK = 100,
    IDC_MAIN_MENU_SINGLE = 101,
    IDC_MAIN_MENU_MULTI = 102,
    IDC_MAIN_MENU_RECORDS = 105,
};

class MainMenu final : public UIMenu
{
public:
    // ??0MainMenu@@QAE@H@Z
    ARTS_EXPORT MainMenu(i32 idd);

    // ??1MainMenu@@UAE@XZ
    ~MainMenu() override = default;

    // ?PreSetup@MainMenu@@UAEXXZ
    void PreSetup() override;
};

check_size(MainMenu, 0x90);
