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
    mmwidget:widget

    0x4B4860 | public: __thiscall uiWidget::uiWidget(void) | ??0uiWidget@@QAE@XZ
    0x4B4890 | public: void __thiscall uiWidget::AddToolTip(class UIMenu *,struct LocString *) | ?AddToolTip@uiWidget@@QAEXPAVUIMenu@@PAULocString@@@Z
    0x4B48A0 | public: virtual void __thiscall uiWidget::Switch(int) | ?Switch@uiWidget@@UAEXH@Z
    0x4B48C0 | public: void __thiscall uiWidget::ResetToolTip(void) | ?ResetToolTip@uiWidget@@QAEXXZ
    0x4B48D0 | public: void __thiscall uiWidget::SetToolTipText(struct LocString *) | ?SetToolTipText@uiWidget@@QAEXPAULocString@@@Z
*/

#include "arts7/node.h"

class uiWidget : public asNode
{
    // const uiWidget::`vftable' @ 0x61E478

public:
    // 0x4B4860 | ??0uiWidget@@QAE@XZ
    uiWidget();

    // 0x4B2E90 | ??_GuiWidget@@UAEPAXI@Z
    // 0x4B2DB0 | ??1uiWidget@@UAE@XZ | inline
    ~uiWidget() override;

    // 0x4B2DC0 | ?Disable@uiWidget@@UAEXXZ | inline
    virtual void Disable();

    // 0x4B2DD0 | ?Enable@uiWidget@@UAEXXZ | inline
    virtual void Enable();

    // 0x4B2DE0 | ?TurnOn@uiWidget@@UAEXXZ | inline
    virtual void TurnOn();

    // 0x4B2E00 | ?TurnOff@uiWidget@@UAEXXZ | inline
    virtual void TurnOff();

    // 0x4B2E10 | ?SetReadOnly@uiWidget@@UAEXH@Z | inline
    virtual void SetReadOnly(i32 arg1);

    // 0x4B2E30 | ?Action@uiWidget@@UAEXTeqEvent@@@Z | inline
    virtual void Action(union eqEvent arg1);

    // 0x4B2E40 | ?CaptureAction@uiWidget@@UAEXTeqEvent@@@Z | inline
    virtual void CaptureAction(union eqEvent arg1);

    // 0x4B48A0 | ?Switch@uiWidget@@UAEXH@Z
    virtual void Switch(i32 arg1);

    // 0x4B2E50 | ?EvalMouseX@uiWidget@@UAEXM@Z | inline
    virtual void EvalMouseX(f32 arg1);

    // 0x4B2E60 | ?ReturnDescription@uiWidget@@UAEPADXZ | inline
    virtual char* ReturnDescription();

    // 0x4B2E70 | ?SetPosition@uiWidget@@UAEXMM@Z | inline
    virtual void SetPosition(f32 arg1, f32 arg2);

    // 0x4B2E80 | ?GetScreenHeight@uiWidget@@UAEMXZ | inline
    virtual f32 GetScreenHeight();

    // 0x4B4890 | ?AddToolTip@uiWidget@@QAEXPAVUIMenu@@PAULocString@@@Z
    void AddToolTip(class UIMenu* arg1, struct LocString* arg2);

    // 0x4B48C0 | ?ResetToolTip@uiWidget@@QAEXXZ
    void ResetToolTip();

    // 0x4B48D0 | ?SetToolTipText@uiWidget@@QAEXPAULocString@@@Z
    void SetToolTipText(struct LocString* arg1);
};

check_size(uiWidget, 0x74);
