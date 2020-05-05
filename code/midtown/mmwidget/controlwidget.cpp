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

define_dummy_symbol(mmwidget_controlwidget);

#include "controlwidget.h"

UIControlWidget::UIControlWidget()
{
    unimplemented();
}

UIControlWidget::~UIControlWidget()
{
    unimplemented(arg1);
}

void UIControlWidget::Action(union eqEvent arg1)
{
    return stub<thiscall_t<void, UIControlWidget*, union eqEvent>>(0xBBF10_Offset, this, arg1);
}

void UIControlWidget::DisableField()
{
    return stub<thiscall_t<void, UIControlWidget*>>(0xBC050_Offset, this);
}

void UIControlWidget::EnableField()
{
    return stub<thiscall_t<void, UIControlWidget*>>(0xBBFE0_Offset, this);
}

void UIControlWidget::Init(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, class mmIO* arg6, class Callback arg7)
{
    return stub<thiscall_t<void, UIControlWidget*, f32, f32, f32, f32, f32, class mmIO*, class Callback>>(
        0xBBC40_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void UIControlWidget::SetPosition(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, UIControlWidget*, f32, f32, f32, f32>>(0xBBE00_Offset, this, arg1, arg2, arg3, arg4);
}

void UIControlWidget::Switch(i32 arg1)
{
    return stub<thiscall_t<void, UIControlWidget*, i32>>(0xBBF60_Offset, this, arg1);
}

void UIControlWidget::TurnOff()
{
    return stub<thiscall_t<void, UIControlWidget*>>(0xBC0E0_Offset, this);
}

void UIControlWidget::TurnOn()
{
    return stub<thiscall_t<void, UIControlWidget*>>(0xBC0D0_Offset, this);
}

void UIControlWidget::Update()
{
    return stub<thiscall_t<void, UIControlWidget*>>(0xBBEC0_Offset, this);
}

void UIControlWidget::UpdateField()
{
    return stub<thiscall_t<void, UIControlWidget*>>(0xBBEE0_Offset, this);
}
