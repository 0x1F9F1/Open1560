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

define_dummy_symbol(mmwidget_label);

#include "label.h"

UILabel::UILabel()
{
    unimplemented();
}

UILabel::~UILabel()
{
    unimplemented();
}

void UILabel::Action(union eqEvent arg1)
{
    return stub<thiscall_t<void, UILabel*, union eqEvent>>(0x4B98F0, this, arg1);
}

void UILabel::Init(struct LocString* arg1, i32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, i32 arg7)
{
    return stub<thiscall_t<void, UILabel*, struct LocString*, i32, f32, f32, f32, f32, i32>>(
        0x4B96F0, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void UILabel::SetBlink(i32 arg1)
{
    return stub<thiscall_t<void, UILabel*, i32>>(0x4B9820, this, arg1);
}

void UILabel::SetText(struct LocString* arg1)
{
    return stub<thiscall_t<void, UILabel*, struct LocString*>>(0x4B97B0, this, arg1);
}

void UILabel::Switch(i32 arg1)
{
    return stub<thiscall_t<void, UILabel*, i32>>(0x4B9850, this, arg1);
}

void UILabel::SwitchState(i32 arg1)
{
    return stub<thiscall_t<void, UILabel*, i32>>(0x4B9860, this, arg1);
}

void UILabel::Update()
{
    return stub<thiscall_t<void, UILabel*>>(0x4B97D0, this);
}
