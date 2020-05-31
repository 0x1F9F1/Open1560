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
    mmwidget:icon

    0x4B9900 | public: __thiscall UIIcon::UIIcon(void) | ??0UIIcon@@QAE@XZ
    0x4B9950 | public: virtual __thiscall UIIcon::~UIIcon(void) | ??1UIIcon@@UAE@XZ
    0x4B9960 | public: void __thiscall UIIcon::Init(char *,float,float) | ?Init@UIIcon@@QAEXPADMM@Z
    0x4B99A0 | public: void __thiscall UIIcon::LoadBitmap(char *) | ?LoadBitmap@UIIcon@@QAEXPAD@Z
    0x4B9A10 | public: class agiBitmap * __thiscall UIIcon::CreateDummyBitmap(void) | ?CreateDummyBitmap@UIIcon@@QAEPAVagiBitmap@@XZ
    0x4B9A60 | public: void __thiscall UIIcon::GetHitArea(float &,float &) | ?GetHitArea@UIIcon@@QAEXAAM0@Z
    0x4B9A90 | public: virtual void __thiscall UIIcon::Switch(int) | ?Switch@UIIcon@@UAEXH@Z
    0x4B9AD0 | public: virtual void __thiscall UIIcon::Update(void) | ?Update@UIIcon@@UAEXXZ
    0x4B9AF0 | public: virtual void __thiscall UIIcon::Cull(void) | ?Cull@UIIcon@@UAEXXZ
    0x4B9B20 | public: virtual void * __thiscall UIIcon::`scalar deleting destructor'(unsigned int) | ??_GUIIcon@@UAEPAXI@Z
    0x4B9B20 | public: virtual void * __thiscall UIIcon::`vector deleting destructor'(unsigned int) | ??_EUIIcon@@UAEPAXI@Z
    0x61EBA8 | const UIIcon::`vftable' | ??_7UIIcon@@6B@
*/

#include "widget.h"

class UIIcon : public uiWidget
{
    // const UIIcon::`vftable' @ 0x61EBA8

public:
    // 0x4B9900 | ??0UIIcon@@QAE@XZ
    UIIcon();

    // 0x4B9B20 | ??_EUIIcon@@UAEPAXI@Z
    // 0x4B9950 | ??1UIIcon@@UAE@XZ
    ~UIIcon() override;

    // 0x4B9A10 | ?CreateDummyBitmap@UIIcon@@QAEPAVagiBitmap@@XZ
    class agiBitmap* CreateDummyBitmap();

    // 0x4B9AF0 | ?Cull@UIIcon@@UAEXXZ
    void Cull() override;

    // 0x4B9A60 | ?GetHitArea@UIIcon@@QAEXAAM0@Z
    void GetHitArea(f32& arg1, f32& arg2);

    // 0x4B9960 | ?Init@UIIcon@@QAEXPADMM@Z
    void Init(char* arg1, f32 arg2, f32 arg3);

    // 0x4B99A0 | ?LoadBitmap@UIIcon@@QAEXPAD@Z
    void LoadBitmap(char* arg1);

    // 0x4B9A90 | ?Switch@UIIcon@@UAEXH@Z
    void Switch(i32 arg1) override;

    // 0x4B9AD0 | ?Update@UIIcon@@UAEXXZ
    void Update() override;
};

check_size(UIIcon, 0x94);
