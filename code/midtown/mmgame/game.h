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
#include "data7/str.h"
#include "eventq7/eventq.h"
#include "mmcityinfo/miscdata.h"
#include "mmcityinfo/playercfg.h"
#include "vector7/random.h"
#include "vector7/vector3.h"

#include "hudmap.h"
#include "icons.h"

class asLamp;
class asLinearCS;
class AudSound;
class eqEventQ;
class mmAmbientAudio;
class mmAnimMgr;
class mmBangerData;
class mmCullCity;
class mmPlayer;
class mmPopup;
class mmPositions;
class mmRaceData;
class mmVoiceCommentary;

class mmGame : public asNode
{
public:
    // ??0mmGame@@QAE@XZ
    ARTS_EXPORT mmGame();

    // ??_GmmGame@@UAEPAXI@Z
    // ??_EmmGame@@UAEPAXI@Z
    // ??1mmGame@@UAE@XZ
    ARTS_EXPORT ~mmGame() override;

    // ?InitGameStrings@mmGame@@UAEXXZ
    ARTS_IMPORT virtual void InitGameStrings();

    virtual void InitMyPlayer() = 0;

    // ?InitOtherPlayers@mmGame@@UAEXXZ
    ARTS_IMPORT virtual void InitOtherPlayers();

    virtual void InitGameObjects() = 0;

    virtual void InitHUD() = 0;

    virtual void UpdateGameInput(i32 key) = 0;

    // ?UpdateDebugInput@mmGame@@UAEXXZ
    ARTS_EXPORT virtual void UpdateDebugInput();

    virtual void UpdateDebugKeyInput(i32 key) = 0;

    virtual void UpdateGame() = 0;

    virtual void NextRace() = 0;

    // ?HitWaterHandler@mmGame@@UAEXXZ
    ARTS_IMPORT virtual void HitWaterHandler();

    // ?DropThruCityHandler@mmGame@@UAEXXZ
    ARTS_IMPORT virtual void DropThruCityHandler();

    // ?SendChatMessage@mmGame@@UAEXPAD@Z
    ARTS_EXPORT virtual void SendChatMessage(char* msg);

    virtual mmWaypoints* GetWaypoints() = 0;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmGame@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?CollideAIOpponents@mmGame@@QAEXXZ
    ARTS_IMPORT void CollideAIOpponents();

    // ?GetCDTrack@mmGame@@QAEHF@Z
    ARTS_IMPORT i32 GetCDTrack(i16 arg1);

    // ?GetClass@mmGame@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmGame@@QAEHXZ
    ARTS_IMPORT i32 Init();

    // ?IsPopupEnabled@mmGame@@QAEHXZ
    ARTS_EXPORT b32 IsPopupEnabled();

    // ?PlayerSetState@mmGame@@QAEXXZ
    ARTS_IMPORT void PlayerSetState();

    // ?Reset@mmGame@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetIconsState@mmGame@@QAEXXZ
    ARTS_IMPORT void SetIconsState();

    // ?Stats@mmGame@@QAEXXZ | unused
    ARTS_IMPORT void Stats();

    // ?Update@mmGame@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateGameInput@mmGame@@QAEXXZ
    ARTS_EXPORT void UpdateGameInput();

    // ?UpdatePaused@mmGame@@UAEXXZ
    ARTS_EXPORT void UpdatePaused() override;

    // ?UpdateSteeringBrakes@mmGame@@QAEXXZ
    ARTS_IMPORT void UpdateSteeringBrakes();

    // ?DeclareFields@mmGame@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    Ptr<mmPlayer> Player;
    Ptr<mmPositions> ResetPositions;
    mmIcons Icons {};
    string OpponentNames {};
    string FinishMessages {};
    f32 AutoRevLevel {0.8f};
    f32 AutoRevSpeed {5.0f};
    Vector3 ResetPosition {};
    b32 ShowResults {};
    Ptr<mmCullCity> pCullCity;
    i32 field_B0 {};
    i32 field_B4 {};
    Ptr<asLamp> Lamp;
    Ptr<asLinearCS> LampCS;
    i32 field_C0 {};
    Ptr<AudSound> StartSounds;
    Ptr<mmVoiceCommentary> VoiceCommentary;
    Ptr<mmAmbientAudio> AmbientAudio;
    Ptr<mmPopup> Popup;
    Ptr<mmAnimMgr> AnimMgr;
    Ptr<mmRaceData> RaceData;
    mmMiscData MiscData {};
    b32 MiscDataLoaded {};
    b32 IsChicago {};
    i32 GameState {};
    b16 HornPressed {};
    bool HasAIMap {};
    bool EnableAI {true};
    char MapName[40] {};
    char RaceDir[40] {};
    OppIconInfo OppIcons[8] {};
    Ptr<eqEventQ> EventQueue;
    eqEvent CurrentEvent {};
    f32 GameStateWait {};
    mmPlayerConfig Config {};
    b32 EnableSave {};
    i32 NextHudMode {-1};
    Random RNG {};

protected:
    // ?CalculateRaceScore@mmGame@@IAEHHH@Z
    ARTS_IMPORT i32 CalculateRaceScore(i32 arg1, i32 arg2);

    // ?RespawnXYZ@mmGame@@IAEXAAVVector3@@AAM@Z
    ARTS_IMPORT void RespawnXYZ(Vector3& arg1, f32& arg2);
};

check_size(mmGame, 0x1E570);

class foobar final : public asNode
{
public:
    // ??_Gfoobar@@UAEPAXI@Z
    // ??_Efoobar@@UAEPAXI@Z
    // ??1foobar@@UAE@XZ | inline
    ARTS_IMPORT ~foobar() override = default;

private:
    // ?Update@foobar@@EAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdatePaused@foobar@@EAEXXZ
    ARTS_IMPORT void UpdatePaused() override;
};

check_size(foobar, 0x20);

// ?BangerProjectile@@3PAVmmBangerData@@A
ARTS_IMPORT extern mmBangerData* BangerProjectile;

// ?IconColor@@3PAIA
ARTS_EXPORT extern u32 IconColor[8];

// ?LocPlayerName@@3PADA
ARTS_IMPORT extern char LocPlayerName[20];

// ?ProjectileV@@3VVector3@@A
ARTS_IMPORT extern Vector3 ProjectileV;

// ?ProjectileY@@3MA
ARTS_IMPORT extern f32 ProjectileY;

// ?masscycle@@3HA
ARTS_IMPORT extern i32 masscycle;
