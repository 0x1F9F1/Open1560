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

#pragma once

/*
    mmui:netselect

    0x4A3BA0 | public: __thiscall NetSelectMenu::NetSelectMenu(int) | ??0NetSelectMenu@@QAE@H@Z
    0x4A42F0 | public: virtual __thiscall NetSelectMenu::~NetSelectMenu(void) | ??1NetSelectMenu@@UAE@XZ
    0x4A4360 | public: virtual void __thiscall NetSelectMenu::PreSetup(void) | ?PreSetup@NetSelectMenu@@UAEXXZ
    0x4A43D0 | public: virtual void __thiscall NetSelectMenu::PostSetup(void) | ?PostSetup@NetSelectMenu@@UAEXXZ
    0x4A43F0 | public: void __thiscall NetSelectMenu::HostCB(void) | ?HostCB@NetSelectMenu@@QAEXXZ
    0x4A4400 | public: void __thiscall NetSelectMenu::JoinCB(void) | ?JoinCB@NetSelectMenu@@QAEXXZ
    0x4A4410 | public: int __thiscall NetSelectMenu::GetHostJoin(void) | ?GetHostJoin@NetSelectMenu@@QAEHXZ
    0x4A4420 | public: void __thiscall NetSelectMenu::FocusDescription(int) | ?FocusDescription@NetSelectMenu@@QAEXH@Z
    0x4A44A0 | public: void __thiscall NetSelectMenu::SetDescription(struct LocString *) | ?SetDescription@NetSelectMenu@@QAEXPAULocString@@@Z
    0x4A44B0 | public: void __thiscall NetSelectMenu::JoinCallback(void) | ?JoinCallback@NetSelectMenu@@QAEXXZ
    0x4A44C0 | public: void __thiscall NetSelectMenu::ShowTCPIPNetSessions(void) | ?ShowTCPIPNetSessions@NetSelectMenu@@QAEXXZ
    0x4A44D0 | public: void __thiscall NetSelectMenu::DisableSessions(void) | ?DisableSessions@NetSelectMenu@@QAEXXZ
    0x4A44E0 | public: void __thiscall NetSelectMenu::ProtocolBack(void) | ?ProtocolBack@NetSelectMenu@@QAEXXZ
    0x4A4500 | public: void __thiscall NetSelectMenu::SetNetname(char *) | ?SetNetname@NetSelectMenu@@QAEXPAD@Z
    0x4A4540 | public: void __thiscall NetSelectMenu::SetPhoneNumber(char *) | ?SetPhoneNumber@NetSelectMenu@@QAEXPAD@Z
    0x4A4560 | public: void __thiscall NetSelectMenu::SetIPAddress(char *) | ?SetIPAddress@NetSelectMenu@@QAEXPAD@Z
    0x4A4580 | public: void __thiscall NetSelectMenu::BuildAllTheModemWidgets(float,float,float,float,char *) | ?BuildAllTheModemWidgets@NetSelectMenu@@QAEXMMMMPAD@Z
    0x4A4690 | public: void __thiscall NetSelectMenu::BuildAllTheIPXWidgets(float,float,float,float) | ?BuildAllTheIPXWidgets@NetSelectMenu@@QAEXMMMM@Z
    0x4A46A0 | public: void __thiscall NetSelectMenu::BuildAllTheTCPWidgets(float,float,float,float) | ?BuildAllTheTCPWidgets@NetSelectMenu@@QAEXMMMM@Z
    0x4A46B0 | public: class UITextScroll * __thiscall NetSelectMenu::GetSessions(void) | ?GetSessions@NetSelectMenu@@QAEPAVUITextScroll@@XZ
    0x4A46C0 | public: int __thiscall NetSelectMenu::GetSessionID(void) | ?GetSessionID@NetSelectMenu@@QAEHXZ
    0x4A46D0 | public: void __thiscall NetSelectMenu::SetSession(char *,int) | ?SetSession@NetSelectMenu@@QAEXPADH@Z
    0x4A4700 | public: void __thiscall NetSelectMenu::IPAddressCallback(void) | ?IPAddressCallback@NetSelectMenu@@QAEXXZ
    0x4A4720 | public: void __thiscall NetSelectMenu::BuildComs(void) | ?BuildComs@NetSelectMenu@@QAEXXZ
    0x4A4820 | public: void __thiscall NetSelectMenu::SetComs(void) | ?SetComs@NetSelectMenu@@QAEXXZ
    0x4A4930 | public: void __thiscall NetSelectMenu::ReparentWidgets(int) | ?ReparentWidgets@NetSelectMenu@@QAEXH@Z
    0x4A4940 | public: void __thiscall NetSelectMenu::WidgetSwitch(int,int) | ?WidgetSwitch@NetSelectMenu@@QAEXHH@Z
    0x4A4950 | public: void __thiscall NetSelectMenu::AddWidgetToList(int,class uiWidget *) | ?AddWidgetToList@NetSelectMenu@@QAEXHPAVuiWidget@@@Z
    0x4A4960 | public: void __thiscall NetSelectMenu::AddModem(char *,int) | ?AddModem@NetSelectMenu@@QAEXPADH@Z
    0x4A4A60 | public: void __thiscall NetSelectMenu::ClearProtocol(void) | ?ClearProtocol@NetSelectMenu@@QAEXXZ
    0x4A4A70 | public: void __thiscall NetSelectMenu::SetIPXButton(int) | ?SetIPXButton@NetSelectMenu@@QAEXH@Z
    0x4A4AA0 | public: void __thiscall NetSelectMenu::SetTCPLocalButton(int) | ?SetTCPLocalButton@NetSelectMenu@@QAEXH@Z
    0x4A4AB0 | public: void __thiscall NetSelectMenu::SetTCPNetButton(int) | ?SetTCPNetButton@NetSelectMenu@@QAEXH@Z
    0x4A4AE0 | public: void __thiscall NetSelectMenu::SetModemButton(int) | ?SetModemButton@NetSelectMenu@@QAEXH@Z
    0x4A4B10 | public: void __thiscall NetSelectMenu::SetSerialButton(int) | ?SetSerialButton@NetSelectMenu@@QAEXH@Z
    0x4A4B40 | public: struct NETCOMMPACK * __thiscall NetSelectMenu::GetCommPack(void) | ?GetCommPack@NetSelectMenu@@QAEPAUNETCOMMPACK@@XZ
    0x4A4B70 | public: void __thiscall NetSelectMenu::NetNameCB(void) | ?NetNameCB@NetSelectMenu@@QAEXXZ
    0x4A4BA0 | public: __thiscall string::string(char const *) | ??0string@@QAE@PBD@Z
    0x4A4C00 | public: virtual void * __thiscall NetSelectMenu::`vector deleting destructor'(unsigned int) | ??_ENetSelectMenu@@UAEPAXI@Z
    0x4A4C00 | public: virtual void * __thiscall NetSelectMenu::`scalar deleting destructor'(unsigned int) | ??_GNetSelectMenu@@UAEPAXI@Z
    0x61DA78 | const NetSelectMenu::`vftable' | ??_7NetSelectMenu@@6B@
*/

#include "mmwidget/menu.h"

class NetSelectMenu : public UIMenu
{
    // const NetSelectMenu::`vftable' @ 0x61DA78

public:
    // 0x4A3BA0 | ??0NetSelectMenu@@QAE@H@Z
    NetSelectMenu(i32 arg1);

    // 0x4A4C00 | ??_GNetSelectMenu@@UAEPAXI@Z
    // 0x4A42F0 | ??1NetSelectMenu@@UAE@XZ
    ~NetSelectMenu() override;

    // 0x4A4960 | ?AddModem@NetSelectMenu@@QAEXPADH@Z
    void AddModem(char* arg1, i32 arg2);

    // 0x4A4950 | ?AddWidgetToList@NetSelectMenu@@QAEXHPAVuiWidget@@@Z
    void AddWidgetToList(i32 arg1, class uiWidget* arg2);

    // 0x4A4690 | ?BuildAllTheIPXWidgets@NetSelectMenu@@QAEXMMMM@Z
    void BuildAllTheIPXWidgets(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x4A4580 | ?BuildAllTheModemWidgets@NetSelectMenu@@QAEXMMMMPAD@Z
    void BuildAllTheModemWidgets(f32 arg1, f32 arg2, f32 arg3, f32 arg4, char* arg5);

    // 0x4A46A0 | ?BuildAllTheTCPWidgets@NetSelectMenu@@QAEXMMMM@Z
    void BuildAllTheTCPWidgets(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x4A4720 | ?BuildComs@NetSelectMenu@@QAEXXZ
    void BuildComs();

    // 0x4A4A60 | ?ClearProtocol@NetSelectMenu@@QAEXXZ
    void ClearProtocol();

    // 0x4A44D0 | ?DisableSessions@NetSelectMenu@@QAEXXZ
    void DisableSessions();

    // 0x4A4420 | ?FocusDescription@NetSelectMenu@@QAEXH@Z
    void FocusDescription(i32 arg1);

    // 0x4A4B40 | ?GetCommPack@NetSelectMenu@@QAEPAUNETCOMMPACK@@XZ
    struct NETCOMMPACK* GetCommPack();

    // 0x4A4410 | ?GetHostJoin@NetSelectMenu@@QAEHXZ
    i32 GetHostJoin();

    // 0x4A46C0 | ?GetSessionID@NetSelectMenu@@QAEHXZ
    i32 GetSessionID();

    // 0x4A46B0 | ?GetSessions@NetSelectMenu@@QAEPAVUITextScroll@@XZ
    class UITextScroll* GetSessions();

    // 0x4A43F0 | ?HostCB@NetSelectMenu@@QAEXXZ
    void HostCB();

    // 0x4A4700 | ?IPAddressCallback@NetSelectMenu@@QAEXXZ
    void IPAddressCallback();

    // 0x4A4400 | ?JoinCB@NetSelectMenu@@QAEXXZ
    void JoinCB();

    // 0x4A44B0 | ?JoinCallback@NetSelectMenu@@QAEXXZ
    void JoinCallback();

    // 0x4A4B70 | ?NetNameCB@NetSelectMenu@@QAEXXZ
    void NetNameCB();

    // 0x4A43D0 | ?PostSetup@NetSelectMenu@@UAEXXZ
    void PostSetup() override;

    // 0x4A4360 | ?PreSetup@NetSelectMenu@@UAEXXZ
    void PreSetup() override;

    // 0x4A44E0 | ?ProtocolBack@NetSelectMenu@@QAEXXZ
    void ProtocolBack();

    // 0x4A4930 | ?ReparentWidgets@NetSelectMenu@@QAEXH@Z
    void ReparentWidgets(i32 arg1);

    // 0x4A4820 | ?SetComs@NetSelectMenu@@QAEXXZ
    void SetComs();

    // 0x4A44A0 | ?SetDescription@NetSelectMenu@@QAEXPAULocString@@@Z
    void SetDescription(struct LocString* arg1);

    // 0x4A4560 | ?SetIPAddress@NetSelectMenu@@QAEXPAD@Z
    void SetIPAddress(char* arg1);

    // 0x4A4A70 | ?SetIPXButton@NetSelectMenu@@QAEXH@Z
    void SetIPXButton(i32 arg1);

    // 0x4A4AE0 | ?SetModemButton@NetSelectMenu@@QAEXH@Z
    void SetModemButton(i32 arg1);

    // 0x4A4500 | ?SetNetname@NetSelectMenu@@QAEXPAD@Z
    void SetNetname(char* arg1);

    // 0x4A4540 | ?SetPhoneNumber@NetSelectMenu@@QAEXPAD@Z
    void SetPhoneNumber(char* arg1);

    // 0x4A4B10 | ?SetSerialButton@NetSelectMenu@@QAEXH@Z
    void SetSerialButton(i32 arg1);

    // 0x4A46D0 | ?SetSession@NetSelectMenu@@QAEXPADH@Z
    void SetSession(char* arg1, i32 arg2);

    // 0x4A4AA0 | ?SetTCPLocalButton@NetSelectMenu@@QAEXH@Z
    void SetTCPLocalButton(i32 arg1);

    // 0x4A4AB0 | ?SetTCPNetButton@NetSelectMenu@@QAEXH@Z
    void SetTCPNetButton(i32 arg1);

    // 0x4A44C0 | ?ShowTCPIPNetSessions@NetSelectMenu@@QAEXXZ
    void ShowTCPIPNetSessions();

    // 0x4A4940 | ?WidgetSwitch@NetSelectMenu@@QAEXHH@Z
    void WidgetSwitch(i32 arg1, i32 arg2);
};

check_size(NetSelectMenu, 0x27C);
