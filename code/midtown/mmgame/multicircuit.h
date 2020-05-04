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

class mmMultiCircuit : public mmGameMulti
{
    // const mmMultiCircuit::`vftable' @ 0x61A890

public:
    // 0x41A8B0 | ??0mmMultiCircuit@@QAE@XZ
    mmMultiCircuit();

    // 0x41BF40 | ??_EmmMultiCircuit@@UAEPAXI@Z
    // 0x41A920 | ??1mmMultiCircuit@@UAE@XZ
    ~mmMultiCircuit() override;

    // 0x41B9C0 | ?GameMessage@mmMultiCircuit@@UAEXPAUNETGAME_MSG@@@Z
    void GameMessage(struct NETGAME_MSG* arg1) override;

    // 0x41BDE0 | ?GetClass@mmMultiCircuit@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x41BFA0 | ?GetWaypoints@mmMultiCircuit@@UAEPAVmmWaypoints@@XZ
    class mmWaypoints* GetWaypoints() override;

    // 0x41A9E0 | ?Init@mmMultiCircuit@@QAEHXZ
    i32 Init();

    // 0x41ABC0 | ?InitGameObjects@mmMultiCircuit@@UAEXXZ
    void InitGameObjects() override;

    // 0x41AB70 | ?InitHUD@mmMultiCircuit@@UAEXXZ
    void InitHUD() override;

    // 0x41AB00 | ?InitMyPlayer@mmMultiCircuit@@UAEXXZ
    void InitMyPlayer() override;

    // 0x41AE30 | ?InitNetworkPlayers@mmMultiCircuit@@UAEXXZ
    void InitNetworkPlayers() override;

    // 0x41B190 | ?Reset@mmMultiCircuit@@UAEXXZ
    void Reset() override;

    // 0x41B830 | ?SystemMessage@mmMultiCircuit@@UAEXPAUNETSYS_MSG@@@Z
    void SystemMessage(struct NETSYS_MSG* arg1) override;

    // 0x41B820 | ?UpdateDebugKeyInput@mmMultiCircuit@@UAEXH@Z
    void UpdateDebugKeyInput(i32 arg1) override;

    // 0x41B270 | ?UpdateGame@mmMultiCircuit@@UAEXXZ
    void UpdateGame() override;

    // 0x41B230 | ?UpdateGameInput@mmMultiCircuit@@UAEXH@Z
    void UpdateGameInput(i32 arg1) override;

    // 0x41BC60 | ?DeclareFields@mmMultiCircuit@@SAXXZ
    static void DeclareFields();

private:
    // 0x41BC20 | ?SendPlayerFinish@mmMultiCircuit@@AAEXXZ
    void SendPlayerFinish();
};

check_size(mmMultiCircuit, 0x1EEB0);

// 0x6A71B8 | ?mmMultiCircuitMetaClass@@3VMetaClass@@A
inline extern_var(0x2A71B8_Offset, class MetaClass, mmMultiCircuitMetaClass);
