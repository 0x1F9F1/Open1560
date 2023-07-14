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
#include "hud.h"
#include "netobject.h"

struct NETGAME_MSG;
struct NETSYS_MSG;

class mmGameMulti : public mmGame
{
public:
    // ??0mmGameMulti@@QAE@XZ
    ARTS_IMPORT mmGameMulti();

    // ??_EmmGameMulti@@UAEPAXI@Z
    // ??_GmmGameMulti@@UAEPAXI@Z
    // ??1mmGameMulti@@UAE@XZ
    ARTS_IMPORT ~mmGameMulti() override;

    virtual void InitNetworkPlayers() = 0;

    // ?InitRoster@mmGameMulti@@UAEXXZ
    ARTS_IMPORT virtual void InitRoster();

    virtual void SystemMessage(NETSYS_MSG* arg1) = 0;

    virtual void GameMessage(NETGAME_MSG* arg1) = 0;

    // ?ActivateMapNetObject@mmGameMulti@@QAEXH@Z
    ARTS_EXPORT void ActivateMapNetObject(i32 player);

    // ?BootPlayerCB@mmGameMulti@@QAEXPAX0@Z
    ARTS_IMPORT void BootPlayerCB(void* arg1, void* arg2);

    // ?BootStrapCars@mmGameMulti@@QAEXXZ
    ARTS_IMPORT void BootStrapCars();

    // ?ClearNetObjects@mmGameMulti@@QAEXXZ
    ARTS_IMPORT void ClearNetObjects();

    // ?DeactivateMapNetObject@mmGameMulti@@QAEXH@Z
    ARTS_EXPORT void DeactivateMapNetObject(i32 player);

    // ?DropThruCityHandler@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void DropThruCityHandler() override;

    // ?FinishMessage@mmGameMulti@@QAEXH@Z
    ARTS_IMPORT void FinishMessage(i32 arg1);

    // ?GameMessageCB@mmGameMulti@@QAEXPAX0@Z
    ARTS_IMPORT void GameMessageCB(void* arg1, void* arg2);

    // ?GetClass@mmGameMulti@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?HitWaterHandler@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void HitWaterHandler() override;

    // ?Init@mmGameMulti@@QAEHXZ
    ARTS_IMPORT i32 Init();

    // ?InitGameStrings@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void InitGameStrings() override;

    // ?InitOtherPlayers@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void InitOtherPlayers() override;

    // ?NextRace@mmGameMulti@@UAEXXZ | inline
    ARTS_EXPORT void NextRace() override;

    // ?ParseChatMessage@mmGameMulti@@QAEHPADH@Z
    ARTS_IMPORT i32 ParseChatMessage(char* arg1, i32 arg2);

    // ?QuitNetwork@mmGameMulti@@QAEXXZ
    ARTS_EXPORT void QuitNetwork();

    // ?RegisterMapNetObjects@mmGameMulti@@QAEXH@Z
    ARTS_IMPORT void RegisterMapNetObjects(i32 arg1);

    // ?Reset@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SendBootMsg@mmGameMulti@@QAEXK@Z
    ARTS_IMPORT void SendBootMsg(ulong arg1);

    // ?SendChatMessage@mmGameMulti@@UAEXPAD@Z
    ARTS_IMPORT void SendChatMessage(char* arg1) override;

    // ?SendMsg@mmGameMulti@@QAEXH@Z
    ARTS_IMPORT void SendMsg(i32 arg1);

    // ?SendToChatMessage@mmGameMulti@@QAEXPADK@Z
    ARTS_IMPORT void SendToChatMessage(char* arg1, ulong arg2);

    // ?SystemMessageCB@mmGameMulti@@QAEXPAX0@Z
    ARTS_IMPORT void SystemMessageCB(void* arg1, void* arg2);

    // ?Update@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateDebugKeyInput@mmGameMulti@@UAEXH@Z
    ARTS_EXPORT void UpdateDebugKeyInput(i32 arg1) override;

    // ?UpdateGame@mmGameMulti@@UAEXXZ
    ARTS_IMPORT void UpdateGame() override;

    // ?UpdateNetWorkAudio@mmGameMulti@@QAEXXZ
    ARTS_IMPORT void UpdateNetWorkAudio();

    // ?UpdateScore@mmGameMulti@@QAEXXZ
    ARTS_IMPORT void UpdateScore();

    // ?DeclareFields@mmGameMulti@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

protected:
    // ?DisableRacers@mmGameMulti@@IAEXXZ
    ARTS_IMPORT void DisableRacers();

    // ?EnableRacers@mmGameMulti@@IAEXXZ
    ARTS_IMPORT void EnableRacers();

    // ?StartXYZ@mmGameMulti@@IAEXHAAVVector3@@0MM@Z
    ARTS_IMPORT void StartXYZ(i32 arg1, Vector3& arg2, Vector3& arg3, f32 arg4, f32 arg5);

public:
    f32 ResetRotation;
    f32 Time;
    mmWaypoints* Waypoints;
    string field_1E57C;
    string field_1E584;
    i32 field_1E58C;
    i32 field_1E590;
    f32 field_1E594;
    mmNetObject PlayerObject;
    mmNetObject NetObjects[8];
    mmCar* Cars[8];
    void* field_1EE4C[8];
    mmTimer TimeLimit;
    i32 field_1EE9C;
    b32 NoKicking;
    i32 field_1EEA4;
};

check_size(mmGameMulti, 0x1EEA8);
