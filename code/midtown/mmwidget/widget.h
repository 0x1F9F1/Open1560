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

#include "arts7/node.h"

union eqEvent;
class mmToolTip;
class UIMenu;

class uiWidget : public asNode
{
public:
    // ??0uiWidget@@QAE@XZ
    ARTS_IMPORT uiWidget();

    // ??_GuiWidget@@UAEPAXI@Z
    // ??_EuiWidget@@UAEPAXI@Z
    // ??1uiWidget@@UAE@XZ | inline
    ARTS_EXPORT ~uiWidget() override = default;

    void SetEnabled(bool enabled);

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

    UIMenu* Menu;
    f32 MinX;
    f32 MinY;
    f32 MaxX;
    f32 MaxY;
    f32 MouseX;
    f32 MouseY;
    i32 MouseHit;
    i32 MouseButton;
    b32 Active;
    i32 WidgetID;
    i32 ReadOnly;
    const char* Label;
    const char* Icon;
    f32 X;
    f32 Y;
    f32 Width;
    f32 Height;
    i32 Enabled;
    i32 field_6C;
    mmToolTip* ToolTip;
};

check_size(uiWidget, 0x74);
