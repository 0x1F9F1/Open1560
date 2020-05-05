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

class mmMultiBlitz : public mmGameMulti
{
    // const mmMultiBlitz::`vftable' @ 0x61A7D8

public:
    // 0x418EE0 | ??0mmMultiBlitz@@QAE@XZ
    mmMultiBlitz();

    // 0x41A830 | ??_EmmMultiBlitz@@UAEPAXI@Z
    // 0x418F50 | ??1mmMultiBlitz@@UAE@XZ
    ~mmMultiBlitz() override;

    // 0x41A1C0 | ?GameMessage@mmMultiBlitz@@UAEXPAUNETGAME_MSG@@@Z
    void GameMessage(struct NETGAME_MSG* arg1) override;

    // 0x41A6D0 | ?GetClass@mmMultiBlitz@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x41A8A0 | ?GetWaypoints@mmMultiBlitz@@UAEPAVmmWaypoints@@XZ
    class mmWaypoints* GetWaypoints() override;

    // 0x419010 | ?Init@mmMultiBlitz@@QAEHXZ
    i32 Init();

    // 0x419230 | ?InitGameObjects@mmMultiBlitz@@UAEXXZ
    void InitGameObjects() override;

    // 0x4191B0 | ?InitHUD@mmMultiBlitz@@UAEXXZ
    void InitHUD() override;

    // 0x419140 | ?InitMyPlayer@mmMultiBlitz@@UAEXXZ
    void InitMyPlayer() override;

    // 0x4194C0 | ?InitNetworkPlayers@mmMultiBlitz@@UAEXXZ
    void InitNetworkPlayers() override;

    // 0x41A470 | ?PlayTimerWarning@mmMultiBlitz@@QAEXM@Z
    void PlayTimerWarning(f32 arg1);

    // 0x419820 | ?Reset@mmMultiBlitz@@UAEXXZ
    void Reset() override;

    // 0x41A030 | ?SystemMessage@mmMultiBlitz@@UAEXPAUNETSYS_MSG@@@Z
    void SystemMessage(struct NETSYS_MSG* arg1) override;

    // 0x419910 | ?UpdateGame@mmMultiBlitz@@UAEXXZ
    void UpdateGame() override;

    // 0x4198D0 | ?UpdateGameInput@mmMultiBlitz@@UAEXH@Z
    void UpdateGameInput(i32 arg1) override;

    // 0x41A550 | ?DeclareFields@mmMultiBlitz@@SAXXZ
    static void DeclareFields();

private:
    // 0x41A420 | ?SendPlayerFinish@mmMultiBlitz@@AAEXXZ
    void SendPlayerFinish();
};

check_size(mmMultiBlitz, 0x1EEB8);

// 0x6A7170 | ?mmMultiBlitzMetaClass@@3VMetaClass@@A
inline extern_var(0x2A7170_Offset, class MetaClass, mmMultiBlitzMetaClass);
