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

define_dummy_symbol(mmwidget_widget);

#include "widget.h"

uiWidget::uiWidget()
{
    unimplemented();
}

uiWidget::~uiWidget()
{
    unimplemented();
}

void uiWidget::Disable()
{
    return stub<thiscall_t<void, uiWidget*>>(0x4B2DC0, this);
}

void uiWidget::Enable()
{
    return stub<thiscall_t<void, uiWidget*>>(0x4B2DD0, this);
}

void uiWidget::TurnOn()
{
    return stub<thiscall_t<void, uiWidget*>>(0x4B2DE0, this);
}

void uiWidget::TurnOff()
{
    return stub<thiscall_t<void, uiWidget*>>(0x4B2E00, this);
}

void uiWidget::SetReadOnly(i32 arg1)
{
    return stub<thiscall_t<void, uiWidget*, i32>>(0x4B2E10, this, arg1);
}

void uiWidget::Action(union eqEvent arg1)
{
    return stub<thiscall_t<void, uiWidget*, union eqEvent>>(0x4B2E30, this, arg1);
}

void uiWidget::CaptureAction(union eqEvent arg1)
{
    return stub<thiscall_t<void, uiWidget*, union eqEvent>>(0x4B2E40, this, arg1);
}

void uiWidget::Switch(i32 arg1)
{
    return stub<thiscall_t<void, uiWidget*, i32>>(0x4B48A0, this, arg1);
}

void uiWidget::EvalMouseX(f32 arg1)
{
    return stub<thiscall_t<void, uiWidget*, f32>>(0x4B2E50, this, arg1);
}

char* uiWidget::ReturnDescription()
{
    return stub<thiscall_t<char*, uiWidget*>>(0x4B2E60, this);
}

void uiWidget::SetPosition(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, uiWidget*, f32, f32>>(0x4B2E70, this, arg1, arg2);
}

f32 uiWidget::GetScreenHeight()
{
    return stub<thiscall_t<f32, uiWidget*>>(0x4B2E80, this);
}

void uiWidget::AddToolTip(class UIMenu* arg1, struct LocString* arg2)
{
    return stub<thiscall_t<void, uiWidget*, class UIMenu*, struct LocString*>>(0x4B4890, this, arg1, arg2);
}

void uiWidget::ResetToolTip()
{
    return stub<thiscall_t<void, uiWidget*>>(0x4B48C0, this);
}

void uiWidget::SetToolTipText(struct LocString* arg1)
{
    return stub<thiscall_t<void, uiWidget*, struct LocString*>>(0x4B48D0, this, arg1);
}
