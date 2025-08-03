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
    ARTS_EXPORT b32 Init();

    // ?IsPopupEnabled@mmGame@@QAEHXZ
    ARTS_EXPORT b32 IsPopupEnabled();

    // ?PlayerSetState@mmGame@@QAEXXZ
    ARTS_IMPORT void PlayerSetState();

    // ?Reset@mmGame@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetIconsState@mmGame@@QAEXXZ
    ARTS_IMPORT void SetIconsState();

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

    static const usize MaxOpponents = 64;

#ifdef ARTS_STANDALONE
    OppIconInfo OppIcons[MaxOpponents] {};
#else
    ARTS_EXPORT static OppIconInfo OppIcons[MaxOpponents];
    OppIconInfo OldOppIcons[8] {};
#endif

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
    // ??1foobar@@UAE@XZ | inline
    ARTS_EXPORT ~foobar() override = default;

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
extern u32 IconColor[8];

// ?LocPlayerName@@3PADA
ARTS_IMPORT extern char LocPlayerName[20];

// ?ProjectileV@@3VVector3@@A
ARTS_IMPORT extern Vector3 ProjectileV;

// ?ProjectileY@@3MA
ARTS_IMPORT extern f32 ProjectileY;

// ?masscycle@@3HA
ARTS_IMPORT extern i32 masscycle;
