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

#include "popup.h"

mmPopup::mmPopup(class mmGame* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    unimplemented();
}

mmPopup::~mmPopup()
{
    unimplemented();
}

void mmPopup::ChatCB()
{
    return stub<thiscall_t<void, mmPopup*>>(0x27CF0_Offset, this);
}

void mmPopup::DisablePU(i32 arg1)
{
    return stub<thiscall_t<void, mmPopup*, i32>>(0x27030_Offset, this, arg1);
}

void mmPopup::ForceRoster()
{
    return stub<thiscall_t<void, mmPopup*>>(0x27600_Offset, this);
}

char* mmPopup::GetComment()
{
    return stub<thiscall_t<char*, mmPopup*>>(0x27C70_Offset, this);
}

i32 mmPopup::IsEnabled()
{
    return stub<thiscall_t<i32, mmPopup*>>(0x27020_Offset, this);
}

void mmPopup::Lock()
{
    return stub<thiscall_t<void, mmPopup*>>(0x27CD0_Offset, this);
}

void mmPopup::ProcessChat()
{
    return stub<thiscall_t<void, mmPopup*>>(0x27250_Offset, this);
}

void mmPopup::ProcessEscape(i32 arg1)
{
    return stub<thiscall_t<void, mmPopup*, i32>>(0x27110_Offset, this, arg1);
}

void mmPopup::ProcessKeymap(i32 arg1)
{
    return stub<thiscall_t<void, mmPopup*, i32>>(0x27350_Offset, this, arg1);
}

void mmPopup::RecordPosition()
{
    return stub<thiscall_t<void, mmPopup*>>(0x27CA0_Offset, this);
}

void mmPopup::Reset()
{
    return stub<thiscall_t<void, mmPopup*>>(0x27C50_Offset, this);
}

void mmPopup::SetComment(char* arg1)
{
    return stub<thiscall_t<void, mmPopup*, char*>>(0x27C80_Offset, this, arg1);
}

void mmPopup::ShowResults()
{
    return stub<thiscall_t<void, mmPopup*>>(0x274D0_Offset, this);
}

void mmPopup::ShowRoster()
{
    return stub<thiscall_t<void, mmPopup*>>(0x27560_Offset, this);
}

void mmPopup::Unlock()
{
    return stub<thiscall_t<void, mmPopup*>>(0x27CE0_Offset, this);
}

void mmPopup::Update()
{
    return stub<thiscall_t<void, mmPopup*>>(0x27680_Offset, this);
}

define_dummy_symbol(mmgame_popup);
