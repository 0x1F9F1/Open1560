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
    mmgame:multicircuit

    0x41A8B0 | public: __thiscall mmMultiCircuit::mmMultiCircuit(void) | ??0mmMultiCircuit@@QAE@XZ
    0x41A920 | public: virtual __thiscall mmMultiCircuit::~mmMultiCircuit(void) | ??1mmMultiCircuit@@UAE@XZ
    0x41A9E0 | public: int __thiscall mmMultiCircuit::Init(void) | ?Init@mmMultiCircuit@@QAEHXZ
    0x41AB00 | public: virtual void __thiscall mmMultiCircuit::InitMyPlayer(void) | ?InitMyPlayer@mmMultiCircuit@@UAEXXZ
    0x41AB70 | public: virtual void __thiscall mmMultiCircuit::InitHUD(void) | ?InitHUD@mmMultiCircuit@@UAEXXZ
    0x41ABC0 | public: virtual void __thiscall mmMultiCircuit::InitGameObjects(void) | ?InitGameObjects@mmMultiCircuit@@UAEXXZ
    0x41AE30 | public: virtual void __thiscall mmMultiCircuit::InitNetworkPlayers(void) | ?InitNetworkPlayers@mmMultiCircuit@@UAEXXZ
    0x41B190 | public: virtual void __thiscall mmMultiCircuit::Reset(void) | ?Reset@mmMultiCircuit@@UAEXXZ
    0x41B230 | public: virtual void __thiscall mmMultiCircuit::UpdateGameInput(int) | ?UpdateGameInput@mmMultiCircuit@@UAEXH@Z
    0x41B270 | public: virtual void __thiscall mmMultiCircuit::UpdateGame(void) | ?UpdateGame@mmMultiCircuit@@UAEXXZ
    0x41B820 | public: virtual void __thiscall mmMultiCircuit::UpdateDebugKeyInput(int) | ?UpdateDebugKeyInput@mmMultiCircuit@@UAEXH@Z
    0x41B830 | public: virtual void __thiscall mmMultiCircuit::SystemMessage(struct NETSYS_MSG *) | ?SystemMessage@mmMultiCircuit@@UAEXPAUNETSYS_MSG@@@Z
    0x41B9C0 | public: virtual void __thiscall mmMultiCircuit::GameMessage(struct NETGAME_MSG *) | ?GameMessage@mmMultiCircuit@@UAEXPAUNETGAME_MSG@@@Z
    0x41BC20 | private: void __thiscall mmMultiCircuit::SendPlayerFinish(void) | ?SendPlayerFinish@mmMultiCircuit@@AAEXXZ
    0x41BC60 | public: static void __cdecl mmMultiCircuit::DeclareFields(void) | ?DeclareFields@mmMultiCircuit@@SAXXZ
    0x41BDE0 | public: virtual class MetaClass * __thiscall mmMultiCircuit::GetClass(void) | ?GetClass@mmMultiCircuit@@UAEPAVMetaClass@@XZ
    0x41BF40 | public: virtual void * __thiscall mmMultiCircuit::`vector deleting destructor'(unsigned int) | ??_EmmMultiCircuit@@UAEPAXI@Z
    0x41BFA0 | public: virtual class mmWaypoints * __thiscall mmMultiCircuit::GetWaypoints(void) | ?GetWaypoints@mmMultiCircuit@@UAEPAVmmWaypoints@@XZ
    0x61A890 | const mmMultiCircuit::`vftable' | ??_7mmMultiCircuit@@6B@
    0x6A71B8 | class MetaClass mmMultiCircuitMetaClass | ?mmMultiCircuitMetaClass@@3VMetaClass@@A
*/

#include "gamemulti.h"

class mmMultiCircuit final : public mmGameMulti
{
    // const mmMultiCircuit::`vftable'

public:
    // ??0mmMultiCircuit@@QAE@XZ
    ARTS_IMPORT mmMultiCircuit();

    // ??_EmmMultiCircuit@@UAEPAXI@Z
    // ??1mmMultiCircuit@@UAE@XZ
    ARTS_IMPORT ~mmMultiCircuit() override;

    // ?GameMessage@mmMultiCircuit@@UAEXPAUNETGAME_MSG@@@Z
    ARTS_IMPORT void GameMessage(struct NETGAME_MSG* arg1) override;

    // ?GetClass@mmMultiCircuit@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?GetWaypoints@mmMultiCircuit@@UAEPAVmmWaypoints@@XZ | inline
    ARTS_IMPORT class mmWaypoints* GetWaypoints() override;

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
    ARTS_IMPORT void SystemMessage(struct NETSYS_MSG* arg1) override;

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

// ?mmMultiCircuitMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmMultiCircuitMetaClass;
