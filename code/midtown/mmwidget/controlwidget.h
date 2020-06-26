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
    mmwidget:controlwidget

    0x4BBA80 | public: __thiscall UIControlWidget::UIControlWidget(void) | ??0UIControlWidget@@QAE@XZ
    0x4BBBA0 | public: virtual __thiscall UIControlWidget::~UIControlWidget(void) | ??1UIControlWidget@@UAE@XZ
    0x4BBC40 | public: void __thiscall UIControlWidget::Init(float,float,float,float,float,class mmIO *,class Callback) | ?Init@UIControlWidget@@QAEXMMMMMPAVmmIO@@VCallback@@@Z
    0x4BBE00 | public: void __thiscall UIControlWidget::SetPosition(float,float,float,float) | ?SetPosition@UIControlWidget@@QAEXMMMM@Z
    0x4BBEC0 | public: virtual void __thiscall UIControlWidget::Update(void) | ?Update@UIControlWidget@@UAEXXZ
    0x4BBEE0 | public: void __thiscall UIControlWidget::UpdateField(void) | ?UpdateField@UIControlWidget@@QAEXXZ
    0x4BBF10 | public: virtual void __thiscall UIControlWidget::Action(union eqEvent) | ?Action@UIControlWidget@@UAEXTeqEvent@@@Z
    0x4BBF60 | public: virtual void __thiscall UIControlWidget::Switch(int) | ?Switch@UIControlWidget@@UAEXH@Z
    0x4BBFE0 | public: void __thiscall UIControlWidget::EnableField(void) | ?EnableField@UIControlWidget@@QAEXXZ
    0x4BC050 | public: void __thiscall UIControlWidget::DisableField(void) | ?DisableField@UIControlWidget@@QAEXXZ
    0x4BC0A0 | public: virtual void * __thiscall UIControlWidget::`scalar deleting destructor'(unsigned int) | ??_GUIControlWidget@@UAEPAXI@Z
    0x4BC0D0 | public: virtual void __thiscall UIControlWidget::TurnOn(void) | ?TurnOn@UIControlWidget@@UAEXXZ
    0x4BC0E0 | public: virtual void __thiscall UIControlWidget::TurnOff(void) | ?TurnOff@UIControlWidget@@UAEXXZ
    0x61ED88 | const UIControlWidget::`vftable' | ??_7UIControlWidget@@6B@
*/

#include "widget.h"

class UIControlWidget : public uiWidget
{
    // const UIControlWidget::`vftable' @ 0x61ED88

public:
    // 0x4BBA80 | ??0UIControlWidget@@QAE@XZ
    ARTS_IMPORT UIControlWidget();

    // 0x4B8790 | ??_EUIControlWidget@@UAEPAXI@Z
    // 0x4BC0A0 | ??_GUIControlWidget@@UAEPAXI@Z | unused
    // 0x4BBBA0 | ??1UIControlWidget@@UAE@XZ
    ARTS_IMPORT ~UIControlWidget() override;

    // 0x4BBF10 | ?Action@UIControlWidget@@UAEXTeqEvent@@@Z
    ARTS_IMPORT void Action(union eqEvent arg1) override;

    // 0x4BC050 | ?DisableField@UIControlWidget@@QAEXXZ
    ARTS_IMPORT void DisableField();

    // 0x4BBFE0 | ?EnableField@UIControlWidget@@QAEXXZ
    ARTS_IMPORT void EnableField();

    // 0x4BBC40 | ?Init@UIControlWidget@@QAEXMMMMMPAVmmIO@@VCallback@@@Z
    ARTS_IMPORT void Init(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, class mmIO* arg6, class Callback arg7);

    // 0x4BBE00 | ?SetPosition@UIControlWidget@@QAEXMMMM@Z
    ARTS_IMPORT void SetPosition(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x4BBF60 | ?Switch@UIControlWidget@@UAEXH@Z
    ARTS_IMPORT void Switch(i32 arg1) override;

    // 0x4BC0E0 | ?TurnOff@UIControlWidget@@UAEXXZ | inline
    ARTS_IMPORT void TurnOff() override;

    // 0x4BC0D0 | ?TurnOn@UIControlWidget@@UAEXXZ | inline
    ARTS_IMPORT void TurnOn() override;

    // 0x4BBEC0 | ?Update@UIControlWidget@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x4BBEE0 | ?UpdateField@UIControlWidget@@QAEXXZ
    ARTS_IMPORT void UpdateField();

    u8 gap74[0x44];
};

check_size(UIControlWidget, 0xB8);
