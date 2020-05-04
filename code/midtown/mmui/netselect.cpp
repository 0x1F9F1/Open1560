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

#include "netselect.h"

NetSelectMenu::NetSelectMenu(i32 arg1)
{
    unimplemented();
}

NetSelectMenu::~NetSelectMenu()
{
    unimplemented();
}

void NetSelectMenu::AddModem(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, NetSelectMenu*, char*, i32>>(0xA4960_Offset, this, arg1, arg2);
}

void NetSelectMenu::AddWidgetToList(i32 arg1, class uiWidget* arg2)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32, class uiWidget*>>(0xA4950_Offset, this, arg1, arg2);
}

void NetSelectMenu::BuildAllTheIPXWidgets(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, NetSelectMenu*, f32, f32, f32, f32>>(0xA4690_Offset, this, arg1, arg2, arg3, arg4);
}

void NetSelectMenu::BuildAllTheModemWidgets(f32 arg1, f32 arg2, f32 arg3, f32 arg4, char* arg5)
{
    return stub<thiscall_t<void, NetSelectMenu*, f32, f32, f32, f32, char*>>(
        0xA4580_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void NetSelectMenu::BuildAllTheTCPWidgets(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, NetSelectMenu*, f32, f32, f32, f32>>(0xA46A0_Offset, this, arg1, arg2, arg3, arg4);
}

void NetSelectMenu::BuildComs()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0xA4720_Offset, this);
}

void NetSelectMenu::ClearProtocol()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0xA4A60_Offset, this);
}

void NetSelectMenu::DisableSessions()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0xA44D0_Offset, this);
}

void NetSelectMenu::FocusDescription(i32 arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32>>(0xA4420_Offset, this, arg1);
}

struct NETCOMMPACK* NetSelectMenu::GetCommPack()
{
    return stub<thiscall_t<struct NETCOMMPACK*, NetSelectMenu*>>(0xA4B40_Offset, this);
}

i32 NetSelectMenu::GetHostJoin()
{
    return stub<thiscall_t<i32, NetSelectMenu*>>(0xA4410_Offset, this);
}

i32 NetSelectMenu::GetSessionID()
{
    return stub<thiscall_t<i32, NetSelectMenu*>>(0xA46C0_Offset, this);
}

class UITextScroll* NetSelectMenu::GetSessions()
{
    return stub<thiscall_t<class UITextScroll*, NetSelectMenu*>>(0xA46B0_Offset, this);
}

void NetSelectMenu::HostCB()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0xA43F0_Offset, this);
}

void NetSelectMenu::IPAddressCallback()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0xA4700_Offset, this);
}

void NetSelectMenu::JoinCB()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0xA4400_Offset, this);
}

void NetSelectMenu::JoinCallback()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0xA44B0_Offset, this);
}

void NetSelectMenu::NetNameCB()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0xA4B70_Offset, this);
}

void NetSelectMenu::PostSetup()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0xA43D0_Offset, this);
}

void NetSelectMenu::PreSetup()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0xA4360_Offset, this);
}

void NetSelectMenu::ProtocolBack()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0xA44E0_Offset, this);
}

void NetSelectMenu::ReparentWidgets(i32 arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32>>(0xA4930_Offset, this, arg1);
}

void NetSelectMenu::SetComs()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0xA4820_Offset, this);
}

void NetSelectMenu::SetDescription(struct LocString* arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, struct LocString*>>(0xA44A0_Offset, this, arg1);
}

void NetSelectMenu::SetIPAddress(char* arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, char*>>(0xA4560_Offset, this, arg1);
}

void NetSelectMenu::SetIPXButton(i32 arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32>>(0xA4A70_Offset, this, arg1);
}

void NetSelectMenu::SetModemButton(i32 arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32>>(0xA4AE0_Offset, this, arg1);
}

void NetSelectMenu::SetNetname(char* arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, char*>>(0xA4500_Offset, this, arg1);
}

void NetSelectMenu::SetPhoneNumber(char* arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, char*>>(0xA4540_Offset, this, arg1);
}

void NetSelectMenu::SetSerialButton(i32 arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32>>(0xA4B10_Offset, this, arg1);
}

void NetSelectMenu::SetSession(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, NetSelectMenu*, char*, i32>>(0xA46D0_Offset, this, arg1, arg2);
}

void NetSelectMenu::SetTCPLocalButton(i32 arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32>>(0xA4AA0_Offset, this, arg1);
}

void NetSelectMenu::SetTCPNetButton(i32 arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32>>(0xA4AB0_Offset, this, arg1);
}

void NetSelectMenu::ShowTCPIPNetSessions()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0xA44C0_Offset, this);
}

void NetSelectMenu::WidgetSwitch(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32, i32>>(0xA4940_Offset, this, arg1, arg2);
}

define_dummy_symbol(mmui_netselect);
