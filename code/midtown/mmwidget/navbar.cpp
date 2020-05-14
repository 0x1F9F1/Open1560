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

define_dummy_symbol(mmwidget_navbar);

#include "navbar.h"

uiNavBar::uiNavBar(i32 arg1)
{
    unimplemented(arg1);
}

uiNavBar::~uiNavBar()
{
    unimplemented();
}

void uiNavBar::BackUp()
{
    return stub<thiscall_t<void, uiNavBar*>>(0x4B2150, this);
}

void uiNavBar::Help()
{
    return stub<thiscall_t<void, uiNavBar*>>(0x4B1F10, this);
}

void uiNavBar::Minimize()
{
    return stub<thiscall_t<void, uiNavBar*>>(0x4B1F20, this);
}

void uiNavBar::OptionActive()
{
    return stub<thiscall_t<void, uiNavBar*>>(0x4B1F90, this);
}

void uiNavBar::OptionInActive()
{
    return stub<thiscall_t<void, uiNavBar*>>(0x4B1FB0, this);
}

void uiNavBar::ResetState()
{
    return stub<thiscall_t<void, uiNavBar*>>(0x4B1F80, this);
}

void uiNavBar::SetPrevBitmap(char* arg1)
{
    return stub<thiscall_t<void, uiNavBar*, char*>>(0x4B2100, this, arg1);
}

void uiNavBar::SetPrevPos(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, uiNavBar*, f32, f32>>(0x4B2070, this, arg1, arg2);
}

void uiNavBar::TurnOffPrev()
{
    return stub<thiscall_t<void, uiNavBar*>>(0x4B20E0, this);
}

void uiNavBar::TurnOnPrev()
{
    return stub<thiscall_t<void, uiNavBar*>>(0x4B20C0, this);
}

void uiNavBar::Update()
{
    return stub<thiscall_t<void, uiNavBar*>>(0x4B1FD0, this);
}
