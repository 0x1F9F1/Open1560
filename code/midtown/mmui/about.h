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
    mmui:about

    0x4A5E30 | public: __thiscall AboutMenu::AboutMenu(int) | ??0AboutMenu@@QAE@H@Z
    0x4A6050 | public: virtual __thiscall AboutMenu::~AboutMenu(void) | ??1AboutMenu@@UAE@XZ
    0x4A6060 | public: virtual void __thiscall AboutMenu::PreSetup(void) | ?PreSetup@AboutMenu@@UAEXXZ
    0x4A6080 | public: virtual void __thiscall AboutMenu::Update(void) | ?Update@AboutMenu@@UAEXXZ
    0x4A6100 | public: virtual void __thiscall AboutMenu::Cull(void) | ?Cull@AboutMenu@@UAEXXZ
    0x4A61C0 | public: virtual void * __thiscall AboutMenu::`scalar deleting destructor'(unsigned int) | ??_GAboutMenu@@UAEPAXI@Z
    0x4A61C0 | public: virtual void * __thiscall AboutMenu::`vector deleting destructor'(unsigned int) | ??_EAboutMenu@@UAEPAXI@Z
    0x61DC40 | const AboutMenu::`vftable' | ??_7AboutMenu@@6B@
*/

#include "mmwidget/menu.h"

class AboutMenu : public UIMenu
{
    // const AboutMenu::`vftable' @ 0x61DC40

public:
    // 0x4A5E30 | ??0AboutMenu@@QAE@H@Z
    ARTS_IMPORT AboutMenu(i32 arg1);

    // 0x4A61C0 | ??_EAboutMenu@@UAEPAXI@Z
    // 0x4A61C0 | ??_GAboutMenu@@UAEPAXI@Z
    // 0x4A6050 | ??1AboutMenu@@UAE@XZ
    ARTS_IMPORT ~AboutMenu() override = default;

    // 0x4A6100 | ?Cull@AboutMenu@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x4A6060 | ?PreSetup@AboutMenu@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    // 0x4A6080 | ?Update@AboutMenu@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap90[0x20];
};

check_size(AboutMenu, 0xB0);
