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
    mmgame:gamesingle

    0x416C90 | unsigned long __stdcall ThreadFunc(void *) | ?ThreadFunc@@YGKPAX@Z
    0x416CA0 | public: __thiscall mmGameSingle::mmGameSingle(void) | ??0mmGameSingle@@QAE@XZ
    0x416D30 | public: virtual __thiscall mmGameSingle::~mmGameSingle(void) | ??1mmGameSingle@@UAE@XZ
    0x416DF0 | public: int __thiscall mmGameSingle::Init(void) | ?Init@mmGameSingle@@QAEHXZ
    0x416F70 | public: virtual void __thiscall mmGameSingle::InitMyPlayer(void) | ?InitMyPlayer@mmGameSingle@@UAEXXZ
    0x416FE0 | public: virtual void __thiscall mmGameSingle::InitHUD(void) | ?InitHUD@mmGameSingle@@UAEXXZ
    0x417040 | public: virtual void __thiscall mmGameSingle::InitGameObjects(void) | ?InitGameObjects@mmGameSingle@@UAEXXZ
    0x417340 | public: virtual void __thiscall mmGameSingle::InitOtherPlayers(void) | ?InitOtherPlayers@mmGameSingle@@UAEXXZ
    0x4173A0 | public: virtual void __thiscall mmGameSingle::Reset(void) | ?Reset@mmGameSingle@@UAEXXZ
    0x4174A0 | private: void __thiscall mmGameSingle::EnableRacers(void) | ?EnableRacers@mmGameSingle@@AAEXXZ
    0x417530 | private: void __thiscall mmGameSingle::DisableRacers(void) | ?DisableRacers@mmGameSingle@@AAEXXZ
    0x4175A0 | public: virtual void __thiscall mmGameSingle::HitWaterHandler(void) | ?HitWaterHandler@mmGameSingle@@UAEXXZ
    0x417640 | public: virtual void __thiscall mmGameSingle::Update(void) | ?Update@mmGameSingle@@UAEXXZ
    0x417660 | public: virtual void __thiscall mmGameSingle::UpdateGameInput(int) | ?UpdateGameInput@mmGameSingle@@UAEXH@Z
    0x4176A0 | public: virtual void __thiscall mmGameSingle::UpdateGame(void) | ?UpdateGame@mmGameSingle@@UAEXXZ
    0x417EF0 | public: void __thiscall mmGameSingle::UpdateScore(void) | ?UpdateScore@mmGameSingle@@QAEXXZ
    0x418270 | private: void __thiscall mmGameSingle::FinishMessage(int,int) | ?FinishMessage@mmGameSingle@@AAEXHH@Z
    0x4183F0 | private: int __thiscall mmGameSingle::RegisterFinish(void) | ?RegisterFinish@mmGameSingle@@AAEHXZ
    0x4187F0 | private: int __thiscall mmGameSingle::ProgressCheck(int,int) | ?ProgressCheck@mmGameSingle@@AAEHHH@Z
    0x418840 | public: virtual void __thiscall mmGameSingle::NextRace(void) | ?NextRace@mmGameSingle@@UAEXXZ
    0x4189E0 | public: virtual void __thiscall mmGameSingle::AddWidgets(class Bank *) | ?AddWidgets@mmGameSingle@@UAEXPAVBank@@@Z
    0x418B90 | public: static void __cdecl mmGameSingle::DeclareFields(void) | ?DeclareFields@mmGameSingle@@SAXXZ
    0x418D00 | public: virtual class MetaClass * __thiscall mmGameSingle::GetClass(void) | ?GetClass@mmGameSingle@@UAEPAVMetaClass@@XZ
    0x418E60 | public: virtual void * __thiscall mmGameSingle::`vector deleting destructor'(unsigned int) | ??_EmmGameSingle@@UAEPAXI@Z
    0x418EC0 | public: virtual void __thiscall mmGameSingle::UpdateDebugKeyInput(int) | ?UpdateDebugKeyInput@mmGameSingle@@UAEXH@Z
    0x418ED0 | public: virtual class mmWaypoints * __thiscall mmGameSingle::GetWaypoints(void) | ?GetWaypoints@mmGameSingle@@UAEPAVmmWaypoints@@XZ
    0x61A728 | const mmGameSingle::`vftable' | ??_7mmGameSingle@@6B@
    0x6A7110 | class MetaClass mmGameSingleMetaClass | ?mmGameSingleMetaClass@@3VMetaClass@@A
*/

#include "game.h"

// ?ThreadFunc@@YGKPAX@Z | unused
ARTS_IMPORT ulong ARTS_STDCALL ThreadFunc(void* arg1);

class mmGameSingle final : public mmGame
{
public:
    // ??0mmGameSingle@@QAE@XZ
    ARTS_IMPORT mmGameSingle();

    // ??_EmmGameSingle@@UAEPAXI@Z
    // ??1mmGameSingle@@UAE@XZ
    ARTS_IMPORT ~mmGameSingle() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmGameSingle@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?GetClass@mmGameSingle@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetWaypoints@mmGameSingle@@UAEPAVmmWaypoints@@XZ | inline
    ARTS_IMPORT mmWaypoints* GetWaypoints() override;

    // ?HitWaterHandler@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void HitWaterHandler() override;

    // ?Init@mmGameSingle@@QAEHXZ
    ARTS_EXPORT b32 Init();

    // ?InitGameObjects@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void InitGameObjects() override;

    // ?InitHUD@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void InitHUD() override;

    // ?InitMyPlayer@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void InitMyPlayer() override;

    // ?InitOtherPlayers@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void InitOtherPlayers() override;

    // ?NextRace@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void NextRace() override;

    // ?Reset@mmGameSingle@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // ?Update@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateDebugKeyInput@mmGameSingle@@UAEXH@Z | inline
    ARTS_EXPORT void UpdateDebugKeyInput(i32 arg1) override;

    // ?UpdateGame@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void UpdateGame() override;

    // ?UpdateGameInput@mmGameSingle@@UAEXH@Z
    ARTS_IMPORT void UpdateGameInput(i32 arg1) override;

    // ?UpdateScore@mmGameSingle@@QAEXXZ
    ARTS_IMPORT void UpdateScore();

    // ?DeclareFields@mmGameSingle@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?DisableRacers@mmGameSingle@@AAEXXZ
    ARTS_IMPORT void DisableRacers();

    // ?EnableRacers@mmGameSingle@@AAEXXZ
    ARTS_IMPORT void EnableRacers();

    // ?FinishMessage@mmGameSingle@@AAEXHH@Z
    ARTS_IMPORT void FinishMessage(i32 arg1, i32 arg2);

    // ?ProgressCheck@mmGameSingle@@AAEHHH@Z
    ARTS_IMPORT i32 ProgressCheck(i32 arg1, i32 arg2);

    // ?RegisterFinish@mmGameSingle@@AAEHXZ
    ARTS_IMPORT i32 RegisterFinish();

public:
    i32 field_1E570 {};
    foobar FooBar {};

#ifdef ARTS_STANDALONE
    i32 OppNumCheck[MaxOpponents] {};
#else
    static i32 OppNumCheck[MaxOpponents];
    i32 OldOppNumCheck[8] {};

    [[deprecated]] i32 field_1E5B4[8] {};
#endif

    mmWaypoints* Waypoints {};

#ifdef ARTS_STANDALONE
    i16 OppFinishPositions[MaxOpponents] {};
#else
    static i16 OppFinishPositions[MaxOpponents];
    i16 OldOppFinishPositions[8] {};
#endif

    i16 NumFinished {};
    f32 RespawnPosition {};
};

check_size(mmGameSingle, 0x1E5F0);
