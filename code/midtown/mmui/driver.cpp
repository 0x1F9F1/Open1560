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

define_dummy_symbol(mmui_driver);

#include "driver.h"

DriverMenu::DriverMenu(i32 arg1)
{
    unimplemented(arg1);
}

DriverMenu::~DriverMenu()
{
    unimplemented(arg1);
}

void DriverMenu::AddPlayer(char* arg1)
{
    return stub<thiscall_t<void, DriverMenu*, char*>>(0xA5B80_Offset, this, arg1);
}

void DriverMenu::DecPlayer()
{
    return stub<thiscall_t<void, DriverMenu*>>(0xA5B10_Offset, this);
}

void DriverMenu::DeleteCB()
{
    return stub<thiscall_t<void, DriverMenu*>>(0xA5CA0_Offset, this);
}

void DriverMenu::DisplayDriverInfo(char* arg1, char* arg2, char* arg3, char* arg4, char* arg5, i32 arg6)
{
    return stub<thiscall_t<void, DriverMenu*, char*, char*, char*, char*, char*, i32>>(
        0xA5CE0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void DriverMenu::EnterNewPlayer()
{
    return stub<thiscall_t<void, DriverMenu*>>(0xA5CD0_Offset, this);
}

char* DriverMenu::GetNewDriverName()
{
    return stub<thiscall_t<char*, DriverMenu*>>(0xA5CC0_Offset, this);
}

void DriverMenu::IncPlayer()
{
    return stub<thiscall_t<void, DriverMenu*>>(0xA5B40_Offset, this);
}

void DriverMenu::InitPlayerSelection()
{
    return stub<thiscall_t<void, DriverMenu*>>(0xA5460_Offset, this);
}

void DriverMenu::NewPlayer()
{
    return stub<thiscall_t<void, DriverMenu*>>(0xA5CB0_Offset, this);
}

void DriverMenu::PreSetup()
{
    return stub<thiscall_t<void, DriverMenu*>>(0xA5430_Offset, this);
}

void DriverMenu::RemoveAllPlayers()
{
    return stub<thiscall_t<void, DriverMenu*>>(0xA5B70_Offset, this);
}

void DriverMenu::RemovePlayer(char* arg1)
{
    return stub<thiscall_t<void, DriverMenu*, char*>>(0xA58C0_Offset, this, arg1);
}

void DriverMenu::SetController(char* arg1)
{
    return stub<thiscall_t<void, DriverMenu*, char*>>(0xA5DA0_Offset, this, arg1);
}

void DriverMenu::SetNetName(char* arg1)
{
    return stub<thiscall_t<void, DriverMenu*, char*>>(0xA5DC0_Offset, this, arg1);
}

void DriverMenu::SetPlayerPick(i32 arg1)
{
    return stub<thiscall_t<void, DriverMenu*, i32>>(0xA5B00_Offset, this, arg1);
}

void DriverMenu::TDPickCB()
{
    return stub<thiscall_t<void, DriverMenu*>>(0xA5C90_Offset, this);
}
