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

#include "mmwidget/menu.h"

struct NETCOMMPACK;

class NetSelectMenu final : public UIMenu
{
public:
    // ??0NetSelectMenu@@QAE@H@Z
    ARTS_IMPORT NetSelectMenu(i32 arg1);

    // ??_GNetSelectMenu@@UAEPAXI@Z
    // ??_ENetSelectMenu@@UAEPAXI@Z
    // ??1NetSelectMenu@@UAE@XZ
    ARTS_IMPORT ~NetSelectMenu() override;

    // ?AddWidgetToList@NetSelectMenu@@QAEXHPAVuiWidget@@@Z | unused
    ARTS_EXPORT void AddWidgetToList(i32 arg1, uiWidget* arg2);

    // ?BuildAllTheIPXWidgets@NetSelectMenu@@QAEXMMMM@Z
    ARTS_EXPORT void BuildAllTheIPXWidgets(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // ?BuildAllTheModemWidgets@NetSelectMenu@@QAEXMMMMPAD@Z
    ARTS_IMPORT void BuildAllTheModemWidgets(f32 arg1, f32 arg2, f32 arg3, f32 arg4, char* arg5);

    // ?BuildAllTheTCPWidgets@NetSelectMenu@@QAEXMMMM@Z
    ARTS_EXPORT void BuildAllTheTCPWidgets(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // ?BuildComs@NetSelectMenu@@QAEXXZ
    ARTS_IMPORT void BuildComs();

    // ?ClearProtocol@NetSelectMenu@@QAEXXZ
    ARTS_IMPORT void ClearProtocol();

    // ?DisableSessions@NetSelectMenu@@QAEXXZ
    ARTS_EXPORT void DisableSessions();

    // ?FocusDescription@NetSelectMenu@@QAEXH@Z
    ARTS_IMPORT void FocusDescription(i32 arg1);

    // ?GetCommPack@NetSelectMenu@@QAEPAUNETCOMMPACK@@XZ
    ARTS_IMPORT NETCOMMPACK* GetCommPack();

    // ?GetHostJoin@NetSelectMenu@@QAEHXZ
    ARTS_IMPORT i32 GetHostJoin();

    // ?GetSessionID@NetSelectMenu@@QAEHXZ
    ARTS_IMPORT i32 GetSessionID();

    // ?GetSessions@NetSelectMenu@@QAEPAVUITextScroll@@XZ
    ARTS_IMPORT UITextScroll* GetSessions();

    // ?HostCB@NetSelectMenu@@QAEXXZ
    ARTS_IMPORT void HostCB();

    // ?IPAddressCallback@NetSelectMenu@@QAEXXZ
    ARTS_IMPORT void IPAddressCallback();

    // ?JoinCB@NetSelectMenu@@QAEXXZ
    ARTS_IMPORT void JoinCB();

    // ?JoinCallback@NetSelectMenu@@QAEXXZ
    ARTS_IMPORT void JoinCallback();

    // ?NetNameCB@NetSelectMenu@@QAEXXZ
    ARTS_IMPORT void NetNameCB();

    // ?PostSetup@NetSelectMenu@@UAEXXZ
    ARTS_IMPORT void PostSetup() override;

    // ?PreSetup@NetSelectMenu@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    // ?ProtocolBack@NetSelectMenu@@QAEXXZ
    ARTS_IMPORT void ProtocolBack();

    // ?ReparentWidgets@NetSelectMenu@@QAEXH@Z | unused
    ARTS_EXPORT void ReparentWidgets(i32 arg1);

    // ?SetComs@NetSelectMenu@@QAEXXZ
    ARTS_IMPORT void SetComs();

    // ?SetDescription@NetSelectMenu@@QAEXPAULocString@@@Z
    ARTS_EXPORT void SetDescription(LocString* arg1);

    // ?SetIPAddress@NetSelectMenu@@QAEXPAD@Z
    ARTS_IMPORT void SetIPAddress(char* arg1);

    // ?SetIPXButton@NetSelectMenu@@QAEXH@Z
    ARTS_IMPORT void SetIPXButton(i32 arg1);

    // ?SetModemButton@NetSelectMenu@@QAEXH@Z
    ARTS_IMPORT void SetModemButton(i32 arg1);

    // ?SetNetname@NetSelectMenu@@QAEXPAD@Z
    ARTS_IMPORT void SetNetname(char* arg1);

    // ?SetPhoneNumber@NetSelectMenu@@QAEXPAD@Z
    ARTS_IMPORT void SetPhoneNumber(char* arg1);

    // ?SetSerialButton@NetSelectMenu@@QAEXH@Z
    ARTS_IMPORT void SetSerialButton(i32 arg1);

    // ?SetSession@NetSelectMenu@@QAEXPADH@Z
    ARTS_IMPORT void SetSession(char* arg1, i32 arg2);

    // ?SetTCPLocalButton@NetSelectMenu@@QAEXH@Z
    ARTS_EXPORT void SetTCPLocalButton(i32 arg1);

    // ?SetTCPNetButton@NetSelectMenu@@QAEXH@Z
    ARTS_IMPORT void SetTCPNetButton(i32 arg1);

    // ?ShowTCPIPNetSessions@NetSelectMenu@@QAEXXZ
    ARTS_EXPORT void ShowTCPIPNetSessions();

    // ?WidgetSwitch@NetSelectMenu@@QAEXHH@Z
    ARTS_EXPORT void WidgetSwitch(i32 arg1, i32 arg2);

    u8 gap90[0x1EC];
};

check_size(NetSelectMenu, 0x27C);
