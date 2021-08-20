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
    mmwidget:iconwidget

    0x4BC0F0 | public: __thiscall UIIconW::UIIconW(void) | ??0UIIconW@@QAE@XZ
    0x4BC1B0 | public: virtual __thiscall UIIconW::~UIIconW(void) | ??1UIIconW@@UAE@XZ
    0x4BC220 | public: void __thiscall UIIconW::Init(struct LocString *,char *,float,float,float,float,class Callback) | ?Init@UIIconW@@QAEXPAULocString@@PADMMMMVCallback@@@Z
    0x4BC300 | public: virtual void __thiscall UIIconW::Action(union eqEvent) | ?Action@UIIconW@@UAEXTeqEvent@@@Z
    0x4BC360 | public: virtual void __thiscall UIIconW::Update(void) | ?Update@UIIconW@@UAEXXZ
    0x4BC3E0 | public: virtual void __thiscall UIIconW::Switch(int) | ?Switch@UIIconW@@UAEXH@Z
    0x4BC460 | public: virtual void * __thiscall UIIconW::`vector deleting destructor'(unsigned int) | ??_EUIIconW@@UAEPAXI@Z
    0x4BC460 | public: virtual void * __thiscall UIIconW::`scalar deleting destructor'(unsigned int) | ??_GUIIconW@@UAEPAXI@Z
    0x61EE18 | const UIIconW::`vftable' | ??_7UIIconW@@6B@
*/

#include "widget.h"

class UIIconW final : public uiWidget
{
public:
    // ??0UIIconW@@QAE@XZ
    ARTS_IMPORT UIIconW();

    // ??_GUIIconW@@UAEPAXI@Z
    // ??_EUIIconW@@UAEPAXI@Z
    // ??1UIIconW@@UAE@XZ
    ARTS_IMPORT ~UIIconW() override;

    // ?Action@UIIconW@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(eqEvent arg1) override;

    // ?Init@UIIconW@@QAEXPAULocString@@PADMMMMVCallback@@@Z
    ARTS_IMPORT void Init(LocString* arg1, char* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, Callback arg7);

    // ?Switch@UIIconW@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // ?Update@UIIconW@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap74[0x48];
};

check_size(UIIconW, 0xBC);
