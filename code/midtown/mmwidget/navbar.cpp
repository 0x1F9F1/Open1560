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

#include "navbar.h"

uiNavBar::uiNavBar(i32 arg1)
{
    unimplemented();
}

uiNavBar::~uiNavBar()
{
    unimplemented();
}

void uiNavBar::BackUp()
{
    return stub<thiscall_t<void, uiNavBar*>>(0xB2150_Offset, this);
}

void uiNavBar::Help()
{
    return stub<thiscall_t<void, uiNavBar*>>(0xB1F10_Offset, this);
}

void uiNavBar::Minimize()
{
    return stub<thiscall_t<void, uiNavBar*>>(0xB1F20_Offset, this);
}

void uiNavBar::OptionActive()
{
    return stub<thiscall_t<void, uiNavBar*>>(0xB1F90_Offset, this);
}

void uiNavBar::OptionInActive()
{
    return stub<thiscall_t<void, uiNavBar*>>(0xB1FB0_Offset, this);
}

void uiNavBar::ResetState()
{
    return stub<thiscall_t<void, uiNavBar*>>(0xB1F80_Offset, this);
}

void uiNavBar::SetPrevBitmap(char* arg1)
{
    return stub<thiscall_t<void, uiNavBar*, char*>>(0xB2100_Offset, this, arg1);
}

void uiNavBar::SetPrevPos(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, uiNavBar*, f32, f32>>(0xB2070_Offset, this, arg1, arg2);
}

void uiNavBar::TurnOffPrev()
{
    return stub<thiscall_t<void, uiNavBar*>>(0xB20E0_Offset, this);
}

void uiNavBar::TurnOnPrev()
{
    return stub<thiscall_t<void, uiNavBar*>>(0xB20C0_Offset, this);
}

void uiNavBar::Update()
{
    return stub<thiscall_t<void, uiNavBar*>>(0xB1FD0_Offset, this);
}

define_dummy_symbol(mmwidget_navbar);
