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
    return stub<thiscall_t<void, DriverMenu*, char*>>(0x4A5B80, this, arg1);
}

void DriverMenu::DecPlayer()
{
    return stub<thiscall_t<void, DriverMenu*>>(0x4A5B10, this);
}

void DriverMenu::DeleteCB()
{
    return stub<thiscall_t<void, DriverMenu*>>(0x4A5CA0, this);
}

void DriverMenu::DisplayDriverInfo(char* arg1, char* arg2, char* arg3, char* arg4, char* arg5, i32 arg6)
{
    return stub<thiscall_t<void, DriverMenu*, char*, char*, char*, char*, char*, i32>>(
        0x4A5CE0, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void DriverMenu::EnterNewPlayer()
{
    return stub<thiscall_t<void, DriverMenu*>>(0x4A5CD0, this);
}

char* DriverMenu::GetNewDriverName()
{
    return stub<thiscall_t<char*, DriverMenu*>>(0x4A5CC0, this);
}

void DriverMenu::IncPlayer()
{
    return stub<thiscall_t<void, DriverMenu*>>(0x4A5B40, this);
}

void DriverMenu::InitPlayerSelection()
{
    return stub<thiscall_t<void, DriverMenu*>>(0x4A5460, this);
}

void DriverMenu::NewPlayer()
{
    return stub<thiscall_t<void, DriverMenu*>>(0x4A5CB0, this);
}

void DriverMenu::PreSetup()
{
    return stub<thiscall_t<void, DriverMenu*>>(0x4A5430, this);
}

void DriverMenu::RemoveAllPlayers()
{
    return stub<thiscall_t<void, DriverMenu*>>(0x4A5B70, this);
}

void DriverMenu::RemovePlayer(char* arg1)
{
    return stub<thiscall_t<void, DriverMenu*, char*>>(0x4A58C0, this, arg1);
}

void DriverMenu::SetController(char* arg1)
{
    return stub<thiscall_t<void, DriverMenu*, char*>>(0x4A5DA0, this, arg1);
}

void DriverMenu::SetNetName(char* arg1)
{
    return stub<thiscall_t<void, DriverMenu*, char*>>(0x4A5DC0, this, arg1);
}

void DriverMenu::SetPlayerPick(i32 arg1)
{
    return stub<thiscall_t<void, DriverMenu*, i32>>(0x4A5B00, this, arg1);
}

void DriverMenu::TDPickCB()
{
    return stub<thiscall_t<void, DriverMenu*>>(0x4A5C90, this);
}
