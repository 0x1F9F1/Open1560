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

define_dummy_symbol(mmui_netselect);

#include "netselect.h"

NetSelectMenu::NetSelectMenu(i32 arg1)
{
    unimplemented(arg1);
}

NetSelectMenu::~NetSelectMenu()
{
    unimplemented();
}

void NetSelectMenu::AddModem(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, NetSelectMenu*, char*, i32>>(0x4A4960, this, arg1, arg2);
}

void NetSelectMenu::AddWidgetToList(i32 arg1, class uiWidget* arg2)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32, class uiWidget*>>(0x4A4950, this, arg1, arg2);
}

void NetSelectMenu::BuildAllTheIPXWidgets(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, NetSelectMenu*, f32, f32, f32, f32>>(0x4A4690, this, arg1, arg2, arg3, arg4);
}

void NetSelectMenu::BuildAllTheModemWidgets(f32 arg1, f32 arg2, f32 arg3, f32 arg4, char* arg5)
{
    return stub<thiscall_t<void, NetSelectMenu*, f32, f32, f32, f32, char*>>(
        0x4A4580, this, arg1, arg2, arg3, arg4, arg5);
}

void NetSelectMenu::BuildAllTheTCPWidgets(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, NetSelectMenu*, f32, f32, f32, f32>>(0x4A46A0, this, arg1, arg2, arg3, arg4);
}

void NetSelectMenu::BuildComs()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0x4A4720, this);
}

void NetSelectMenu::ClearProtocol()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0x4A4A60, this);
}

void NetSelectMenu::DisableSessions()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0x4A44D0, this);
}

void NetSelectMenu::FocusDescription(i32 arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32>>(0x4A4420, this, arg1);
}

struct NETCOMMPACK* NetSelectMenu::GetCommPack()
{
    return stub<thiscall_t<struct NETCOMMPACK*, NetSelectMenu*>>(0x4A4B40, this);
}

i32 NetSelectMenu::GetHostJoin()
{
    return stub<thiscall_t<i32, NetSelectMenu*>>(0x4A4410, this);
}

i32 NetSelectMenu::GetSessionID()
{
    return stub<thiscall_t<i32, NetSelectMenu*>>(0x4A46C0, this);
}

class UITextScroll* NetSelectMenu::GetSessions()
{
    return stub<thiscall_t<class UITextScroll*, NetSelectMenu*>>(0x4A46B0, this);
}

void NetSelectMenu::HostCB()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0x4A43F0, this);
}

void NetSelectMenu::IPAddressCallback()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0x4A4700, this);
}

void NetSelectMenu::JoinCB()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0x4A4400, this);
}

void NetSelectMenu::JoinCallback()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0x4A44B0, this);
}

void NetSelectMenu::NetNameCB()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0x4A4B70, this);
}

void NetSelectMenu::PostSetup()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0x4A43D0, this);
}

void NetSelectMenu::PreSetup()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0x4A4360, this);
}

void NetSelectMenu::ProtocolBack()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0x4A44E0, this);
}

void NetSelectMenu::ReparentWidgets(i32 arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32>>(0x4A4930, this, arg1);
}

void NetSelectMenu::SetComs()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0x4A4820, this);
}

void NetSelectMenu::SetDescription(struct LocString* arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, struct LocString*>>(0x4A44A0, this, arg1);
}

void NetSelectMenu::SetIPAddress(char* arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, char*>>(0x4A4560, this, arg1);
}

void NetSelectMenu::SetIPXButton(i32 arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32>>(0x4A4A70, this, arg1);
}

void NetSelectMenu::SetModemButton(i32 arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32>>(0x4A4AE0, this, arg1);
}

void NetSelectMenu::SetNetname(char* arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, char*>>(0x4A4500, this, arg1);
}

void NetSelectMenu::SetPhoneNumber(char* arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, char*>>(0x4A4540, this, arg1);
}

void NetSelectMenu::SetSerialButton(i32 arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32>>(0x4A4B10, this, arg1);
}

void NetSelectMenu::SetSession(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, NetSelectMenu*, char*, i32>>(0x4A46D0, this, arg1, arg2);
}

void NetSelectMenu::SetTCPLocalButton(i32 arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32>>(0x4A4AA0, this, arg1);
}

void NetSelectMenu::SetTCPNetButton(i32 arg1)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32>>(0x4A4AB0, this, arg1);
}

void NetSelectMenu::ShowTCPIPNetSessions()
{
    return stub<thiscall_t<void, NetSelectMenu*>>(0x4A44C0, this);
}

void NetSelectMenu::WidgetSwitch(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, NetSelectMenu*, i32, i32>>(0x4A4940, this, arg1, arg2);
}
