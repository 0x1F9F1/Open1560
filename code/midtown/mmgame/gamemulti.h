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
    mmgame:gamemulti

    0x4306A0 | public: __thiscall mmGameMulti::mmGameMulti(void) | ??0mmGameMulti@@QAE@XZ
    0x4307B0 | public: virtual __thiscall mmGameMulti::~mmGameMulti(void) | ??1mmGameMulti@@UAE@XZ
    0x430870 | public: int __thiscall mmGameMulti::Init(void) | ?Init@mmGameMulti@@QAEHXZ
    0x4309A0 | public: virtual void __thiscall mmGameMulti::HitWaterHandler(void) | ?HitWaterHandler@mmGameMulti@@UAEXXZ
    0x430A90 | public: virtual void __thiscall mmGameMulti::DropThruCityHandler(void) | ?DropThruCityHandler@mmGameMulti@@UAEXXZ
    0x430AA0 | public: virtual void __thiscall mmGameMulti::InitGameStrings(void) | ?InitGameStrings@mmGameMulti@@UAEXXZ
    0x430CC0 | protected: void __thiscall mmGameMulti::StartXYZ(int,class Vector3 &,class Vector3 &,float,float) | ?StartXYZ@mmGameMulti@@IAEXHAAVVector3@@0MM@Z
    0x430EF0 | public: void __thiscall mmGameMulti::SystemMessageCB(void *,void *) | ?SystemMessageCB@mmGameMulti@@QAEXPAX0@Z
    0x431100 | public: void __thiscall mmGameMulti::GameMessageCB(void *,void *) | ?GameMessageCB@mmGameMulti@@QAEXPAX0@Z
    0x431480 | public: void __thiscall mmGameMulti::BootStrapCars(void) | ?BootStrapCars@mmGameMulti@@QAEXXZ
    0x431620 | public: virtual void __thiscall mmGameMulti::Reset(void) | ?Reset@mmGameMulti@@UAEXXZ
    0x4316A0 | public: void __thiscall mmGameMulti::ClearNetObjects(void) | ?ClearNetObjects@mmGameMulti@@QAEXXZ
    0x4316E0 | public: virtual void __thiscall mmGameMulti::InitOtherPlayers(void) | ?InitOtherPlayers@mmGameMulti@@UAEXXZ
    0x431960 | public: virtual void __thiscall mmGameMulti::InitRoster(void) | ?InitRoster@mmGameMulti@@UAEXXZ
    0x4319F0 | public: virtual void __thiscall mmGameMulti::Update(void) | ?Update@mmGameMulti@@UAEXXZ
    0x431A10 | public: virtual void __thiscall mmGameMulti::UpdateGame(void) | ?UpdateGame@mmGameMulti@@UAEXXZ
    0x431AA0 | public: void __thiscall mmGameMulti::UpdateScore(void) | ?UpdateScore@mmGameMulti@@QAEXXZ
    0x431ED0 | public: virtual void __thiscall mmGameMulti::UpdateDebugKeyInput(int) | ?UpdateDebugKeyInput@mmGameMulti@@UAEXH@Z
    0x431EE0 | public: void __thiscall mmGameMulti::RegisterMapNetObjects(int) | ?RegisterMapNetObjects@mmGameMulti@@QAEXH@Z
    0x432000 | public: void __thiscall mmGameMulti::DeactivateMapNetObject(int) | ?DeactivateMapNetObject@mmGameMulti@@QAEXH@Z
    0x432030 | public: void __thiscall mmGameMulti::ActivateMapNetObject(int) | ?ActivateMapNetObject@mmGameMulti@@QAEXH@Z
    0x432070 | protected: void __thiscall mmGameMulti::EnableRacers(void) | ?EnableRacers@mmGameMulti@@IAEXXZ
    0x4320F0 | protected: void __thiscall mmGameMulti::DisableRacers(void) | ?DisableRacers@mmGameMulti@@IAEXXZ
    0x432140 | public: void __thiscall mmGameMulti::QuitNetwork(void) | ?QuitNetwork@mmGameMulti@@QAEXXZ
    0x432160 | public: int __thiscall mmGameMulti::ParseChatMessage(char *,int) | ?ParseChatMessage@mmGameMulti@@QAEHPADH@Z
    0x4321D0 | public: virtual void __thiscall mmGameMulti::SendChatMessage(char *) | ?SendChatMessage@mmGameMulti@@UAEXPAD@Z
    0x432290 | public: void __thiscall mmGameMulti::SendToChatMessage(char *,unsigned long) | ?SendToChatMessage@mmGameMulti@@QAEXPADK@Z
    0x432350 | public: void __thiscall mmGameMulti::FinishMessage(int) | ?FinishMessage@mmGameMulti@@QAEXH@Z
    0x432410 | public: void __thiscall mmGameMulti::BootPlayerCB(void *,void *) | ?BootPlayerCB@mmGameMulti@@QAEXPAX0@Z
    0x432450 | public: void __thiscall mmGameMulti::UpdateNetWorkAudio(void) | ?UpdateNetWorkAudio@mmGameMulti@@QAEXXZ
    0x4324A0 | public: void __thiscall mmGameMulti::SendMsg(int) | ?SendMsg@mmGameMulti@@QAEXH@Z
    0x4324D0 | public: void __thiscall mmGameMulti::SendBootMsg(unsigned long) | ?SendBootMsg@mmGameMulti@@QAEXK@Z
    0x432510 | public: static void __cdecl mmGameMulti::DeclareFields(void) | ?DeclareFields@mmGameMulti@@SAXXZ
    0x4325B0 | public: virtual class MetaClass * __thiscall mmGameMulti::GetClass(void) | ?GetClass@mmGameMulti@@UAEPAVMetaClass@@XZ
    0x432710 | public: virtual void * __thiscall mmGameMulti::`scalar deleting destructor'(unsigned int) | ??_GmmGameMulti@@UAEPAXI@Z
    0x432710 | public: virtual void * __thiscall mmGameMulti::`vector deleting destructor'(unsigned int) | ??_EmmGameMulti@@UAEPAXI@Z
    0x61B068 | const mmGameMulti::`vftable' | ??_7mmGameMulti@@6B@
    0x6A77A0 | class MetaClass mmGameMultiMetaClass | ?mmGameMultiMetaClass@@3VMetaClass@@A
*/

#include "game.h"

class mmGameMulti : public mmGame
{
    // const mmGameMulti::`vftable' @ 0x61B068

public:
    // 0x4306A0 | ??0mmGameMulti@@QAE@XZ
    ARTS_IMPORT mmGameMulti();

    // 0x432710 | ??_EmmGameMulti@@UAEPAXI@Z
    // 0x432710 | ??_GmmGameMulti@@UAEPAXI@Z
    // 0x4307B0 | ??1mmGameMulti@@UAE@XZ
    ARTS_IMPORT ~mmGameMulti() override;

    virtual void InitNetworkPlayers() = 0;

    // 0x431960 | ?InitRoster@mmGameMulti@@UAEXXZ
    ARTS_IMPORT virtual void InitRoster();

    virtual void SystemMessage(struct NETSYS_MSG* arg1) = 0;

    virtual void GameMessage(struct NETGAME_MSG* arg1) = 0;

    // 0x432030 | ?ActivateMapNetObject@mmGameMulti@@QAEXH@Z
    ARTS_IMPORT void ActivateMapNetObject(i32 arg1);

    // 0x432410 | ?BootPlayerCB@mmGameMulti@@QAEXPAX0@Z
    ARTS_IMPORT void BootPlayerCB(void* arg1, void* arg2);

    // 0x431480 | ?BootStrapCars@mmGameMulti@@QAEXXZ
    ARTS_IMPORT void BootStrapCars();

    // 0x4316A0 | ?ClearNetObjects@mmGameMulti@@QAEXXZ
    ARTS_IMPORT void ClearNetObjects();

    // 0x432000 | ?DeactivateMapNetObject@mmGameMulti@@QAEXH@Z
    ARTS_IMPORT void DeactivateMapNetObject(i32 arg1);

    // 0x430A90 | ?DropThruCityHandler@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void DropThruCityHandler() override;

    // 0x432350 | ?FinishMessage@mmGameMulti@@QAEXH@Z
    ARTS_IMPORT void FinishMessage(i32 arg1);

    // 0x431100 | ?GameMessageCB@mmGameMulti@@QAEXPAX0@Z
    ARTS_IMPORT void GameMessageCB(void* arg1, void* arg2);

    // 0x4325B0 | ?GetClass@mmGameMulti@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4309A0 | ?HitWaterHandler@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void HitWaterHandler() override;

    // 0x430870 | ?Init@mmGameMulti@@QAEHXZ
    ARTS_IMPORT i32 Init();

    // 0x430AA0 | ?InitGameStrings@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void InitGameStrings() override;

    // 0x4316E0 | ?InitOtherPlayers@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void InitOtherPlayers() override;

    // 0x41A890 | ?NextRace@mmGameMulti@@UAEXXZ | inline
    ARTS_EXPORT void NextRace() override;

    // 0x432160 | ?ParseChatMessage@mmGameMulti@@QAEHPADH@Z
    ARTS_IMPORT i32 ParseChatMessage(char* arg1, i32 arg2);

    // 0x432140 | ?QuitNetwork@mmGameMulti@@QAEXXZ
    ARTS_EXPORT void QuitNetwork();

    // 0x431EE0 | ?RegisterMapNetObjects@mmGameMulti@@QAEXH@Z
    ARTS_IMPORT void RegisterMapNetObjects(i32 arg1);

    // 0x431620 | ?Reset@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4324D0 | ?SendBootMsg@mmGameMulti@@QAEXK@Z
    ARTS_IMPORT void SendBootMsg(u32 arg1);

    // 0x4321D0 | ?SendChatMessage@mmGameMulti@@UAEXPAD@Z
    ARTS_IMPORT void SendChatMessage(char* arg1) override;

    // 0x4324A0 | ?SendMsg@mmGameMulti@@QAEXH@Z
    ARTS_IMPORT void SendMsg(i32 arg1);

    // 0x432290 | ?SendToChatMessage@mmGameMulti@@QAEXPADK@Z
    ARTS_IMPORT void SendToChatMessage(char* arg1, u32 arg2);

    // 0x430EF0 | ?SystemMessageCB@mmGameMulti@@QAEXPAX0@Z
    ARTS_IMPORT void SystemMessageCB(void* arg1, void* arg2);

    // 0x4319F0 | ?Update@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x431ED0 | ?UpdateDebugKeyInput@mmGameMulti@@UAEXH@Z
    ARTS_EXPORT void UpdateDebugKeyInput(i32 arg1) override;

    // 0x431A10 | ?UpdateGame@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void UpdateGame() override;

    // 0x432450 | ?UpdateNetWorkAudio@mmGameMulti@@QAEXXZ
    ARTS_IMPORT void UpdateNetWorkAudio();

    // 0x431AA0 | ?UpdateScore@mmGameMulti@@QAEXXZ
    ARTS_IMPORT void UpdateScore();

    // 0x432510 | ?DeclareFields@mmGameMulti@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

protected:
    // 0x4320F0 | ?DisableRacers@mmGameMulti@@IAEXXZ
    ARTS_IMPORT void DisableRacers();

    // 0x432070 | ?EnableRacers@mmGameMulti@@IAEXXZ
    ARTS_IMPORT void EnableRacers();

    // 0x430CC0 | ?StartXYZ@mmGameMulti@@IAEXHAAVVector3@@0MM@Z
    ARTS_IMPORT void StartXYZ(i32 arg1, class Vector3& arg2, class Vector3& arg3, f32 arg4, f32 arg5);

    u8 gap1E570[0x938];
};

check_size(mmGameMulti, 0x1EEA8);

// 0x6A77A0 | ?mmGameMultiMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmGameMultiMetaClass;
