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
    mmgame:game

    0x40E880 | public: __thiscall mmGame::mmGame(void) | ??0mmGame@@QAE@XZ
    0x40EA00 | public: int __thiscall mmGame::Init(void) | ?Init@mmGame@@QAEHXZ
    0x40F8C0 | public: virtual void __thiscall mmGame::InitOtherPlayers(void) | ?InitOtherPlayers@mmGame@@UAEXXZ
    0x40F9C0 | public: void __thiscall mmGame::CollideAIOpponents(void) | ?CollideAIOpponents@mmGame@@QAEXXZ
    0x40FAC0 | public: virtual void __thiscall mmGame::InitGameStrings(void) | ?InitGameStrings@mmGame@@UAEXXZ
    0x40FDB0 | public: virtual __thiscall mmGame::~mmGame(void) | ??1mmGame@@UAE@XZ
    0x410050 | public: void __thiscall mmGame::Stats(void) | ?Stats@mmGame@@QAEXXZ
    0x410130 | protected: void __thiscall mmGame::RespawnXYZ(class Vector3 &,float &) | ?RespawnXYZ@mmGame@@IAEXAAVVector3@@AAM@Z
    0x410230 | public: int __thiscall mmGame::IsPopupEnabled(void) | ?IsPopupEnabled@mmGame@@QAEHXZ
    0x410240 | public: virtual void __thiscall mmGame::Reset(void) | ?Reset@mmGame@@UAEXXZ
    0x4102A0 | public: virtual void __thiscall mmGame::Update(void) | ?Update@mmGame@@UAEXXZ
    0x410490 | public: virtual void __thiscall mmGame::DropThruCityHandler(void) | ?DropThruCityHandler@mmGame@@UAEXXZ
    0x4104A0 | public: virtual void __thiscall mmGame::HitWaterHandler(void) | ?HitWaterHandler@mmGame@@UAEXXZ
    0x4104B0 | public: virtual void __thiscall mmGame::UpdateDebugInput(void) | ?UpdateDebugInput@mmGame@@UAEXXZ
    0x410DA0 | public: virtual void __thiscall mmGame::UpdatePaused(void) | ?UpdatePaused@mmGame@@UAEXXZ
    0x410E90 | public: void __thiscall mmGame::UpdateGameInput(void) | ?UpdateGameInput@mmGame@@QAEXXZ
    0x411320 | public: void __thiscall mmGame::UpdateSteeringBrakes(void) | ?UpdateSteeringBrakes@mmGame@@QAEXXZ
    0x411400 | public: void __thiscall mmGame::SetIconsState(void) | ?SetIconsState@mmGame@@QAEXXZ
    0x411420 | public: void __thiscall mmGame::PlayerSetState(void) | ?PlayerSetState@mmGame@@QAEXXZ
    0x411520 | protected: int __thiscall mmGame::CalculateRaceScore(int,int) | ?CalculateRaceScore@mmGame@@IAEHHH@Z
    0x411590 | public: virtual void __thiscall mmGame::SendChatMessage(char *) | ?SendChatMessage@mmGame@@UAEXPAD@Z
    0x411960 | public: int __thiscall mmGame::GetCDTrack(short) | ?GetCDTrack@mmGame@@QAEHF@Z
    0x411E30 | public: virtual void __thiscall mmGame::AddWidgets(class Bank *) | ?AddWidgets@mmGame@@UAEXPAVBank@@@Z
    0x411EE0 | private: virtual void __thiscall foobar::Update(void) | ?Update@foobar@@EAEXXZ
    0x411F10 | private: virtual void __thiscall foobar::UpdatePaused(void) | ?UpdatePaused@foobar@@EAEXXZ
    0x411F20 | public: static void __cdecl mmGame::DeclareFields(void) | ?DeclareFields@mmGame@@SAXXZ
    0x411FC0 | public: virtual class MetaClass * __thiscall mmGame::GetClass(void) | ?GetClass@mmGame@@UAEPAVMetaClass@@XZ
    0x412120 | public: virtual void * __thiscall mmGame::`vector deleting destructor'(unsigned int) | ??_EmmGame@@UAEPAXI@Z
    0x412120 | public: virtual void * __thiscall mmGame::`scalar deleting destructor'(unsigned int) | ??_GmmGame@@UAEPAXI@Z
    0x61A408 | const mmGame::`vftable' | ??_7mmGame@@6B@
    0x635AC0 | float ProjectileY | ?ProjectileY@@3MA
    0x635AC8 | unsigned int * IconColor | ?IconColor@@3PAIA
    0x6A6F30 | char * LocPlayerName | ?LocPlayerName@@3PADA
    0x6A6F60 | class MetaClass mmGameMetaClass | ?mmGameMetaClass@@3VMetaClass@@A
    0x6A6F90 | class Vector3 ProjectileV | ?ProjectileV@@3VVector3@@A
    0x6A6FB4 | int masscycle | ?masscycle@@3HA
    0x6A6FB8 | class mmBangerData * BangerProjectile | ?BangerProjectile@@3PAVmmBangerData@@A
*/

#include "arts7/node.h"

class mmGame : public asNode
{
    // const mmGame::`vftable' @ 0x61A408

public:
    // 0x40E880 | ??0mmGame@@QAE@XZ
    mmGame();

    // 0x412120 | ??_GmmGame@@UAEPAXI@Z
    // 0x40FDB0 | ??1mmGame@@UAE@XZ
    ~mmGame() override;

    // 0x40FAC0 | ?InitGameStrings@mmGame@@UAEXXZ
    virtual void InitGameStrings();

    virtual void InitMyPlayer() = 0;

    // 0x40F8C0 | ?InitOtherPlayers@mmGame@@UAEXXZ
    virtual void InitOtherPlayers();

    virtual void InitGameObjects() = 0;

    virtual void InitHUD() = 0;

    virtual void UpdateGameInput(i32 arg1) = 0;

    // 0x4104B0 | ?UpdateDebugInput@mmGame@@UAEXXZ
    virtual void UpdateDebugInput();

    virtual void UpdateDebugKeyInput(i32 arg1) = 0;

    virtual void UpdateGame() = 0;

    virtual void NextRace() = 0;

    // 0x4104A0 | ?HitWaterHandler@mmGame@@UAEXXZ
    virtual void HitWaterHandler();

    // 0x410490 | ?DropThruCityHandler@mmGame@@UAEXXZ
    virtual void DropThruCityHandler();

    // 0x411590 | ?SendChatMessage@mmGame@@UAEXPAD@Z
    virtual void SendChatMessage(char* arg1);

    virtual class mmWaypoints* GetWaypoints() = 0;

    // 0x411E30 | ?AddWidgets@mmGame@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x40F9C0 | ?CollideAIOpponents@mmGame@@QAEXXZ
    void CollideAIOpponents();

    // 0x411960 | ?GetCDTrack@mmGame@@QAEHF@Z
    i32 GetCDTrack(i16 arg1);

    // 0x411FC0 | ?GetClass@mmGame@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x40EA00 | ?Init@mmGame@@QAEHXZ
    i32 Init();

    // 0x410230 | ?IsPopupEnabled@mmGame@@QAEHXZ
    i32 IsPopupEnabled();

    // 0x411420 | ?PlayerSetState@mmGame@@QAEXXZ
    void PlayerSetState();

    // 0x410240 | ?Reset@mmGame@@UAEXXZ
    void Reset() override;

    // 0x411400 | ?SetIconsState@mmGame@@QAEXXZ
    void SetIconsState();

    // 0x410050 | ?Stats@mmGame@@QAEXXZ | unused
    void Stats();

    // 0x4102A0 | ?Update@mmGame@@UAEXXZ
    void Update() override;

    // 0x410E90 | ?UpdateGameInput@mmGame@@QAEXXZ
    void UpdateGameInput();

    // 0x410DA0 | ?UpdatePaused@mmGame@@UAEXXZ
    void UpdatePaused() override;

    // 0x411320 | ?UpdateSteeringBrakes@mmGame@@QAEXXZ
    void UpdateSteeringBrakes();

    // 0x411F20 | ?DeclareFields@mmGame@@SAXXZ
    static void DeclareFields();

protected:
    // 0x411520 | ?CalculateRaceScore@mmGame@@IAEHHH@Z
    i32 CalculateRaceScore(i32 arg1, i32 arg2);

    // 0x410130 | ?RespawnXYZ@mmGame@@IAEXAAVVector3@@AAM@Z
    void RespawnXYZ(class Vector3& arg1, f32& arg2);
};

check_size(mmGame, 0x1E570);

// 0x6A6FB8 | ?BangerProjectile@@3PAVmmBangerData@@A
inline extern_var(0x6A6FB8, class mmBangerData*, BangerProjectile);

// 0x635AC8 | ?IconColor@@3PAIA
inline extern_var(0x635AC8, u32*, IconColor);

// 0x6A6F30 | ?LocPlayerName@@3PADA
inline extern_var(0x6A6F30, char*, LocPlayerName);

// 0x6A6F90 | ?ProjectileV@@3VVector3@@A
inline extern_var(0x6A6F90, class Vector3, ProjectileV);

// 0x635AC0 | ?ProjectileY@@3MA
inline extern_var(0x635AC0, f32, ProjectileY);

// 0x6A6FB4 | ?masscycle@@3HA
inline extern_var(0x6A6FB4, i32, masscycle);

// 0x6A6F60 | ?mmGameMetaClass@@3VMetaClass@@A
inline extern_var(0x6A6F60, class MetaClass, mmGameMetaClass);
