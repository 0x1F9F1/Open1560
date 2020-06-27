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
    mmui:options

    0x4A3950 | public: __thiscall OptionsMenu::OptionsMenu(int) | ??0OptionsMenu@@QAE@H@Z
    0x4A3B10 | public: virtual __thiscall OptionsMenu::~OptionsMenu(void) | ??1OptionsMenu@@UAE@XZ
    0x4A3B20 | public: virtual void __thiscall OptionsMenu::PreSetup(void) | ?PreSetup@OptionsMenu@@UAEXXZ
    0x4A3B50 | public: virtual void __thiscall OptionsMenu::PostSetup(void) | ?PostSetup@OptionsMenu@@UAEXXZ
    0x4A3B70 | public: virtual void * __thiscall OptionsMenu::`scalar deleting destructor'(unsigned int) | ??_GOptionsMenu@@UAEPAXI@Z
    0x4A3B70 | public: virtual void * __thiscall OptionsMenu::`vector deleting destructor'(unsigned int) | ??_EOptionsMenu@@UAEPAXI@Z
    0x61DA00 | const OptionsMenu::`vftable' | ??_7OptionsMenu@@6B@
*/

#include "mmwidget/menu.h"

class OptionsMenu : public UIMenu
{
    // const OptionsMenu::`vftable' @ 0x61DA00

public:
    // 0x4A3950 | ??0OptionsMenu@@QAE@H@Z
    ARTS_IMPORT OptionsMenu(i32 arg1);

    // 0x4A3B70 | ??_EOptionsMenu@@UAEPAXI@Z
    // 0x4A3B70 | ??_GOptionsMenu@@UAEPAXI@Z
    // 0x4A3B10 | ??1OptionsMenu@@UAE@XZ
    ARTS_IMPORT ~OptionsMenu() override;

    // 0x4A3B50 | ?PostSetup@OptionsMenu@@UAEXXZ
    ARTS_IMPORT void PostSetup() override;

    // 0x4A3B20 | ?PreSetup@OptionsMenu@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    u8 gap90[0x8];
};

check_size(OptionsMenu, 0x98);
