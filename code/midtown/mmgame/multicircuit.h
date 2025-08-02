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

#include "gamemulti.h"

class mmMultiCircuit final : public mmGameMulti
{
public:
    // ??0mmMultiCircuit@@QAE@XZ
    ARTS_IMPORT mmMultiCircuit();

    // ??_EmmMultiCircuit@@UAEPAXI@Z
    // ??1mmMultiCircuit@@UAE@XZ
    ARTS_IMPORT ~mmMultiCircuit() override;

    // ?GameMessage@mmMultiCircuit@@UAEXPAUNETGAME_MSG@@@Z
    ARTS_IMPORT void GameMessage(NETGAME_MSG* arg1) override;

    // ?GetClass@mmMultiCircuit@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetWaypoints@mmMultiCircuit@@UAEPAVmmWaypoints@@XZ | inline
    ARTS_IMPORT mmWaypoints* GetWaypoints() override;

    // ?Init@mmMultiCircuit@@QAEHXZ
    ARTS_IMPORT i32 Init();

    // ?InitGameObjects@mmMultiCircuit@@UAEXXZ
    ARTS_IMPORT void InitGameObjects() override;

    // ?InitHUD@mmMultiCircuit@@UAEXXZ
    ARTS_IMPORT void InitHUD() override;

    // ?InitMyPlayer@mmMultiCircuit@@UAEXXZ
    ARTS_IMPORT void InitMyPlayer() override;

    // ?InitNetworkPlayers@mmMultiCircuit@@UAEXXZ
    ARTS_IMPORT void InitNetworkPlayers() override;

    // ?Reset@mmMultiCircuit@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SystemMessage@mmMultiCircuit@@UAEXPAUNETSYS_MSG@@@Z
    ARTS_IMPORT void SystemMessage(NETSYS_MSG* arg1) override;

    // ?UpdateDebugKeyInput@mmMultiCircuit@@UAEXH@Z
    ARTS_EXPORT void UpdateDebugKeyInput(i32 arg1) override;

    // ?UpdateGame@mmMultiCircuit@@UAEXXZ
    ARTS_IMPORT void UpdateGame() override;

    // ?UpdateGameInput@mmMultiCircuit@@UAEXH@Z
    ARTS_IMPORT void UpdateGameInput(i32 arg1) override;

    // ?DeclareFields@mmMultiCircuit@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?SendPlayerFinish@mmMultiCircuit@@AAEXXZ
    ARTS_IMPORT void SendPlayerFinish();

    u8 gap1EEA8[0x8];
};

check_size(mmMultiCircuit, 0x1EEB0);
