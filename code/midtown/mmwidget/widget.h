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

union eqEvent;
class UIMenu;

class uiWidget : public asNode
{
public:
    // ??0uiWidget@@QAE@XZ
    ARTS_IMPORT uiWidget();

    // ??_GuiWidget@@UAEPAXI@Z
    // ??_EuiWidget@@UAEPAXI@Z
    // ??1uiWidget@@UAE@XZ | inline
    ARTS_IMPORT ~uiWidget() override = default;

    // ?Disable@uiWidget@@UAEXXZ | inline
    ARTS_IMPORT virtual void Disable();

    // ?Enable@uiWidget@@UAEXXZ | inline
    ARTS_IMPORT virtual void Enable();

    // ?TurnOn@uiWidget@@UAEXXZ | inline
    ARTS_IMPORT virtual void TurnOn();

    // ?TurnOff@uiWidget@@UAEXXZ | inline
    ARTS_IMPORT virtual void TurnOff();

    // ?SetReadOnly@uiWidget@@UAEXH@Z | inline
    ARTS_IMPORT virtual void SetReadOnly(i32 arg1);

    // ?Action@uiWidget@@UAEXTeqEvent@@@Z | inline
    ARTS_EXPORT virtual void Action(eqEvent arg1);

    // ?CaptureAction@uiWidget@@UAEXTeqEvent@@@Z | inline
    ARTS_EXPORT virtual void CaptureAction(eqEvent arg1);

    // ?Switch@uiWidget@@UAEXH@Z
    ARTS_EXPORT virtual void Switch(i32 arg1);

    // ?EvalMouseX@uiWidget@@UAEXM@Z | inline
    ARTS_EXPORT virtual void EvalMouseX(f32 arg1);

    // ?ReturnDescription@uiWidget@@UAEPADXZ | inline
    ARTS_EXPORT virtual char* ReturnDescription();

    // ?SetPosition@uiWidget@@UAEXMM@Z | inline
    ARTS_EXPORT virtual void SetPosition(f32 arg1, f32 arg2);

    // ?GetScreenHeight@uiWidget@@UAEMXZ | inline
    ARTS_IMPORT virtual f32 GetScreenHeight();

    // ?AddToolTip@uiWidget@@QAEXPAVUIMenu@@PAULocString@@@Z
    ARTS_EXPORT void AddToolTip(UIMenu* arg1, LocString* arg2);

    // ?ResetToolTip@uiWidget@@QAEXXZ
    ARTS_EXPORT void ResetToolTip();

    // ?SetToolTipText@uiWidget@@QAEXPAULocString@@@Z
    ARTS_IMPORT void SetToolTipText(LocString* arg1);

    u8 gap20[0x54];
};

check_size(uiWidget, 0x74);
