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

class mmMultiBlitz final : public mmGameMulti
{
public:
    // ??0mmMultiBlitz@@QAE@XZ
    ARTS_IMPORT mmMultiBlitz();

    // ??1mmMultiBlitz@@UAE@XZ
    ARTS_IMPORT ~mmMultiBlitz() override;

    // ?GameMessage@mmMultiBlitz@@UAEXPAUNETGAME_MSG@@@Z
    ARTS_IMPORT void GameMessage(NETGAME_MSG* arg1) override;

    // ?GetClass@mmMultiBlitz@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetWaypoints@mmMultiBlitz@@UAEPAVmmWaypoints@@XZ | inline
    ARTS_IMPORT mmWaypoints* GetWaypoints() override;

    // ?Init@mmMultiBlitz@@QAEHXZ
    ARTS_IMPORT i32 Init();

    // ?InitGameObjects@mmMultiBlitz@@UAEXXZ
    ARTS_IMPORT void InitGameObjects() override;

    // ?InitHUD@mmMultiBlitz@@UAEXXZ
    ARTS_IMPORT void InitHUD() override;

    // ?InitMyPlayer@mmMultiBlitz@@UAEXXZ
    ARTS_IMPORT void InitMyPlayer() override;

    // ?InitNetworkPlayers@mmMultiBlitz@@UAEXXZ
    ARTS_IMPORT void InitNetworkPlayers() override;

    // ?PlayTimerWarning@mmMultiBlitz@@QAEXM@Z
    ARTS_IMPORT void PlayTimerWarning(f32 arg1);

    // ?Reset@mmMultiBlitz@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SystemMessage@mmMultiBlitz@@UAEXPAUNETSYS_MSG@@@Z
    ARTS_IMPORT void SystemMessage(NETSYS_MSG* arg1) override;

    // ?UpdateGame@mmMultiBlitz@@UAEXXZ
    ARTS_IMPORT void UpdateGame() override;

    // ?UpdateGameInput@mmMultiBlitz@@UAEXH@Z
    ARTS_IMPORT void UpdateGameInput(i32 arg1) override;

    // ?DeclareFields@mmMultiBlitz@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?SendPlayerFinish@mmMultiBlitz@@AAEXXZ
    ARTS_IMPORT void SendPlayerFinish();

    u8 gap1EEA8[0x10];
};

check_size(mmMultiBlitz, 0x1EEB8);
