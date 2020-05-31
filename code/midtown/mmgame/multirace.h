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

class mmMultiRace : public mmGameMulti
{
    // const mmMultiRace::`vftable' @ 0x61AA18

public:
    // 0x41F930 | ??0mmMultiRace@@QAE@XZ
    mmMultiRace();

    // 0x421560 | ??_EmmMultiRace@@UAEPAXI@Z
    // 0x41F9A0 | ??1mmMultiRace@@UAE@XZ
    ~mmMultiRace() override;

    // 0x420480 | ?ChangePlayerData@mmMultiRace@@QAEXXZ
    void ChangePlayerData();

    // 0x420EE0 | ?GameMessage@mmMultiRace@@UAEXPAUNETGAME_MSG@@@Z
    void GameMessage(struct NETGAME_MSG* arg1) override;

    // 0x421400 | ?GetClass@mmMultiRace@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4215C0 | ?GetWaypoints@mmMultiRace@@UAEPAVmmWaypoints@@XZ | inline
    class mmWaypoints* GetWaypoints() override;

    // 0x41FA60 | ?Init@mmMultiRace@@QAEHXZ
    i32 Init();

    // 0x41FC70 | ?InitGameObjects@mmMultiRace@@UAEXXZ
    void InitGameObjects() override;

    // 0x41FC10 | ?InitHUD@mmMultiRace@@UAEXXZ
    void InitHUD() override;

    // 0x41FBA0 | ?InitMyPlayer@mmMultiRace@@UAEXXZ
    void InitMyPlayer() override;

    // 0x41FF40 | ?InitNetworkPlayers@mmMultiRace@@UAEXXZ
    void InitNetworkPlayers() override;

    // 0x420370 | ?Reset@mmMultiRace@@UAEXXZ
    void Reset() override;

    // 0x420D10 | ?SystemMessage@mmMultiRace@@UAEXPAUNETSYS_MSG@@@Z
    void SystemMessage(struct NETSYS_MSG* arg1) override;

    // 0x420510 | ?UpdateGame@mmMultiRace@@UAEXXZ
    void UpdateGame() override;

    // 0x4204D0 | ?UpdateGameInput@mmMultiRace@@UAEXH@Z
    void UpdateGameInput(i32 arg1) override;

    // 0x421280 | ?DeclareFields@mmMultiRace@@SAXXZ
    static void DeclareFields();

private:
    // 0x421240 | ?SendPlayerFinish@mmMultiRace@@AAEXXZ
    void SendPlayerFinish();
};

check_size(mmMultiRace, 0x1EEB0);

// 0x6A7280 | ?mmMultiRaceMetaClass@@3VMetaClass@@A
inline extern_var(0x6A7280, class MetaClass, mmMultiRaceMetaClass);
