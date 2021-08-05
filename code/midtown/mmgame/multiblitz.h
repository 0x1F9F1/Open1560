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
    mmgame:multiblitz

    0x418EE0 | public: __thiscall mmMultiBlitz::mmMultiBlitz(void) | ??0mmMultiBlitz@@QAE@XZ
    0x418F50 | public: virtual __thiscall mmMultiBlitz::~mmMultiBlitz(void) | ??1mmMultiBlitz@@UAE@XZ
    0x419010 | public: int __thiscall mmMultiBlitz::Init(void) | ?Init@mmMultiBlitz@@QAEHXZ
    0x419140 | public: virtual void __thiscall mmMultiBlitz::InitMyPlayer(void) | ?InitMyPlayer@mmMultiBlitz@@UAEXXZ
    0x4191B0 | public: virtual void __thiscall mmMultiBlitz::InitHUD(void) | ?InitHUD@mmMultiBlitz@@UAEXXZ
    0x419230 | public: virtual void __thiscall mmMultiBlitz::InitGameObjects(void) | ?InitGameObjects@mmMultiBlitz@@UAEXXZ
    0x4194C0 | public: virtual void __thiscall mmMultiBlitz::InitNetworkPlayers(void) | ?InitNetworkPlayers@mmMultiBlitz@@UAEXXZ
    0x419820 | public: virtual void __thiscall mmMultiBlitz::Reset(void) | ?Reset@mmMultiBlitz@@UAEXXZ
    0x4198D0 | public: virtual void __thiscall mmMultiBlitz::UpdateGameInput(int) | ?UpdateGameInput@mmMultiBlitz@@UAEXH@Z
    0x419910 | public: virtual void __thiscall mmMultiBlitz::UpdateGame(void) | ?UpdateGame@mmMultiBlitz@@UAEXXZ
    0x41A030 | public: virtual void __thiscall mmMultiBlitz::SystemMessage(struct NETSYS_MSG *) | ?SystemMessage@mmMultiBlitz@@UAEXPAUNETSYS_MSG@@@Z
    0x41A1C0 | public: virtual void __thiscall mmMultiBlitz::GameMessage(struct NETGAME_MSG *) | ?GameMessage@mmMultiBlitz@@UAEXPAUNETGAME_MSG@@@Z
    0x41A420 | private: void __thiscall mmMultiBlitz::SendPlayerFinish(void) | ?SendPlayerFinish@mmMultiBlitz@@AAEXXZ
    0x41A470 | public: void __thiscall mmMultiBlitz::PlayTimerWarning(float) | ?PlayTimerWarning@mmMultiBlitz@@QAEXM@Z
    0x41A550 | public: static void __cdecl mmMultiBlitz::DeclareFields(void) | ?DeclareFields@mmMultiBlitz@@SAXXZ
    0x41A6D0 | public: virtual class MetaClass * __thiscall mmMultiBlitz::GetClass(void) | ?GetClass@mmMultiBlitz@@UAEPAVMetaClass@@XZ
    0x41A830 | public: virtual void * __thiscall mmMultiBlitz::`vector deleting destructor'(unsigned int) | ??_EmmMultiBlitz@@UAEPAXI@Z
    0x41A890 | public: virtual void __thiscall mmGameMulti::NextRace(void) | ?NextRace@mmGameMulti@@UAEXXZ
    0x41A8A0 | public: virtual class mmWaypoints * __thiscall mmMultiBlitz::GetWaypoints(void) | ?GetWaypoints@mmMultiBlitz@@UAEPAVmmWaypoints@@XZ
    0x61A7D8 | const mmMultiBlitz::`vftable' | ??_7mmMultiBlitz@@6B@
    0x6A7170 | class MetaClass mmMultiBlitzMetaClass | ?mmMultiBlitzMetaClass@@3VMetaClass@@A
*/

#include "gamemulti.h"

class mmMultiBlitz final : public mmGameMulti
{
    // const mmMultiBlitz::`vftable'

public:
    // ??0mmMultiBlitz@@QAE@XZ
    ARTS_IMPORT mmMultiBlitz();

    // ??_EmmMultiBlitz@@UAEPAXI@Z
    // ??1mmMultiBlitz@@UAE@XZ
    ARTS_IMPORT ~mmMultiBlitz() override;

    // ?GameMessage@mmMultiBlitz@@UAEXPAUNETGAME_MSG@@@Z
    ARTS_IMPORT void GameMessage(struct NETGAME_MSG* arg1) override;

    // ?GetClass@mmMultiBlitz@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?GetWaypoints@mmMultiBlitz@@UAEPAVmmWaypoints@@XZ | inline
    ARTS_IMPORT class mmWaypoints* GetWaypoints() override;

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
    ARTS_IMPORT void SystemMessage(struct NETSYS_MSG* arg1) override;

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

// ?mmMultiBlitzMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmMultiBlitzMetaClass;
