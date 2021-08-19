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
    mmgame:multirace

    0x41F930 | public: __thiscall mmMultiRace::mmMultiRace(void) | ??0mmMultiRace@@QAE@XZ
    0x41F9A0 | public: virtual __thiscall mmMultiRace::~mmMultiRace(void) | ??1mmMultiRace@@UAE@XZ
    0x41FA60 | public: int __thiscall mmMultiRace::Init(void) | ?Init@mmMultiRace@@QAEHXZ
    0x41FBA0 | public: virtual void __thiscall mmMultiRace::InitMyPlayer(void) | ?InitMyPlayer@mmMultiRace@@UAEXXZ
    0x41FC10 | public: virtual void __thiscall mmMultiRace::InitHUD(void) | ?InitHUD@mmMultiRace@@UAEXXZ
    0x41FC70 | public: virtual void __thiscall mmMultiRace::InitGameObjects(void) | ?InitGameObjects@mmMultiRace@@UAEXXZ
    0x41FF40 | public: virtual void __thiscall mmMultiRace::InitNetworkPlayers(void) | ?InitNetworkPlayers@mmMultiRace@@UAEXXZ
    0x420370 | public: virtual void __thiscall mmMultiRace::Reset(void) | ?Reset@mmMultiRace@@UAEXXZ
    0x420480 | public: void __thiscall mmMultiRace::ChangePlayerData(void) | ?ChangePlayerData@mmMultiRace@@QAEXXZ
    0x4204D0 | public: virtual void __thiscall mmMultiRace::UpdateGameInput(int) | ?UpdateGameInput@mmMultiRace@@UAEXH@Z
    0x420510 | public: virtual void __thiscall mmMultiRace::UpdateGame(void) | ?UpdateGame@mmMultiRace@@UAEXXZ
    0x420D10 | public: virtual void __thiscall mmMultiRace::SystemMessage(struct NETSYS_MSG *) | ?SystemMessage@mmMultiRace@@UAEXPAUNETSYS_MSG@@@Z
    0x420EE0 | public: virtual void __thiscall mmMultiRace::GameMessage(struct NETGAME_MSG *) | ?GameMessage@mmMultiRace@@UAEXPAUNETGAME_MSG@@@Z
    0x421240 | private: void __thiscall mmMultiRace::SendPlayerFinish(void) | ?SendPlayerFinish@mmMultiRace@@AAEXXZ
    0x421280 | public: static void __cdecl mmMultiRace::DeclareFields(void) | ?DeclareFields@mmMultiRace@@SAXXZ
    0x421400 | public: virtual class MetaClass * __thiscall mmMultiRace::GetClass(void) | ?GetClass@mmMultiRace@@UAEPAVMetaClass@@XZ
    0x421560 | public: virtual void * __thiscall mmMultiRace::`vector deleting destructor'(unsigned int) | ??_EmmMultiRace@@UAEPAXI@Z
    0x4215C0 | public: virtual class mmWaypoints * __thiscall mmMultiRace::GetWaypoints(void) | ?GetWaypoints@mmMultiRace@@UAEPAVmmWaypoints@@XZ
    0x61AA18 | const mmMultiRace::`vftable' | ??_7mmMultiRace@@6B@
    0x6A7280 | class MetaClass mmMultiRaceMetaClass | ?mmMultiRaceMetaClass@@3VMetaClass@@A
*/

#include "gamemulti.h"

class mmMultiRace final : public mmGameMulti
{
public:
    // ??0mmMultiRace@@QAE@XZ
    ARTS_IMPORT mmMultiRace();

    // ??_EmmMultiRace@@UAEPAXI@Z
    // ??1mmMultiRace@@UAE@XZ
    ARTS_IMPORT ~mmMultiRace() override;

    // ?ChangePlayerData@mmMultiRace@@QAEXXZ
    ARTS_IMPORT void ChangePlayerData();

    // ?GameMessage@mmMultiRace@@UAEXPAUNETGAME_MSG@@@Z
    ARTS_IMPORT void GameMessage(struct NETGAME_MSG* arg1) override;

    // ?GetClass@mmMultiRace@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?GetWaypoints@mmMultiRace@@UAEPAVmmWaypoints@@XZ | inline
    ARTS_IMPORT class mmWaypoints* GetWaypoints() override;

    // ?Init@mmMultiRace@@QAEHXZ
    ARTS_IMPORT i32 Init();

    // ?InitGameObjects@mmMultiRace@@UAEXXZ
    ARTS_IMPORT void InitGameObjects() override;

    // ?InitHUD@mmMultiRace@@UAEXXZ
    ARTS_IMPORT void InitHUD() override;

    // ?InitMyPlayer@mmMultiRace@@UAEXXZ
    ARTS_IMPORT void InitMyPlayer() override;

    // ?InitNetworkPlayers@mmMultiRace@@UAEXXZ
    ARTS_IMPORT void InitNetworkPlayers() override;

    // ?Reset@mmMultiRace@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SystemMessage@mmMultiRace@@UAEXPAUNETSYS_MSG@@@Z
    ARTS_IMPORT void SystemMessage(struct NETSYS_MSG* arg1) override;

    // ?UpdateGame@mmMultiRace@@UAEXXZ
    ARTS_IMPORT void UpdateGame() override;

    // ?UpdateGameInput@mmMultiRace@@UAEXH@Z
    ARTS_IMPORT void UpdateGameInput(i32 arg1) override;

    // ?DeclareFields@mmMultiRace@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?SendPlayerFinish@mmMultiRace@@AAEXXZ
    ARTS_IMPORT void SendPlayerFinish();

    u8 gap1EEA8[0x8];
};

check_size(mmMultiRace, 0x1EEB0);
