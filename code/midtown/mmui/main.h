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

/*
    mmui:main

    0x4A61F0 | public: __thiscall MainMenu::MainMenu(int) | ??0MainMenu@@QAE@H@Z
    0x4A6370 | public: virtual __thiscall MainMenu::~MainMenu(void) | ??1MainMenu@@UAE@XZ
    0x4A6380 | public: virtual void __thiscall MainMenu::PreSetup(void) | ?PreSetup@MainMenu@@UAEXXZ
    0x4A6390 | public: virtual void * __thiscall MainMenu::`vector deleting destructor'(unsigned int) | ??_EMainMenu@@UAEPAXI@Z
    0x4A6390 | public: virtual void * __thiscall MainMenu::`scalar deleting destructor'(unsigned int) | ??_GMainMenu@@UAEPAXI@Z
    0x61DCB0 | const MainMenu::`vftable' | ??_7MainMenu@@6B@
*/

#include "mmwidget/menu.h"

class MainMenu final : public UIMenu
{
    // const MainMenu::`vftable'

public:
    // ??0MainMenu@@QAE@H@Z
    ARTS_IMPORT MainMenu(i32 arg1);

    // ??_GMainMenu@@UAEPAXI@Z
    // ??_EMainMenu@@UAEPAXI@Z
    // ??1MainMenu@@UAE@XZ
    ARTS_IMPORT ~MainMenu() override = default;

    // ?PreSetup@MainMenu@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;
};

check_size(MainMenu, 0x90);
