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

// 0x416C90 | ?ThreadFunc@@YGKPAX@Z | unused
ARTS_IMPORT u32 ARTS_STDCALL ThreadFunc(void* arg1);

// 0x6A7110 | ?mmGameSingleMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmGameSingleMetaClass;

class mmGameSingle /*final*/ : public mmGame
{
    // const mmGameSingle::`vftable' @ 0x61A728

public:
    // 0x416CA0 | ??0mmGameSingle@@QAE@XZ
    ARTS_IMPORT mmGameSingle();

    // 0x418E60 | ??_EmmGameSingle@@UAEPAXI@Z
    // 0x416D30 | ??1mmGameSingle@@UAE@XZ
    ARTS_IMPORT ~mmGameSingle() override;

    // 0x4189E0 | ?AddWidgets@mmGameSingle@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x418D00 | ?GetClass@mmGameSingle@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x418ED0 | ?GetWaypoints@mmGameSingle@@UAEPAVmmWaypoints@@XZ | inline
    ARTS_IMPORT class mmWaypoints* GetWaypoints() override;

    // 0x4175A0 | ?HitWaterHandler@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void HitWaterHandler() override;

    // 0x416DF0 | ?Init@mmGameSingle@@QAEHXZ
    ARTS_IMPORT i32 Init();

    // 0x417040 | ?InitGameObjects@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void InitGameObjects() override;

    // 0x416FE0 | ?InitHUD@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void InitHUD() override;

    // 0x416F70 | ?InitMyPlayer@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void InitMyPlayer() override;

    // 0x417340 | ?InitOtherPlayers@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void InitOtherPlayers() override;

    // 0x418840 | ?NextRace@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void NextRace() override;

    // 0x4173A0 | ?Reset@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x417640 | ?Update@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x418EC0 | ?UpdateDebugKeyInput@mmGameSingle@@UAEXH@Z | inline
    ARTS_EXPORT void UpdateDebugKeyInput(i32 arg1) override;

    // 0x4176A0 | ?UpdateGame@mmGameSingle@@UAEXXZ
    ARTS_IMPORT void UpdateGame() override;

    // 0x417660 | ?UpdateGameInput@mmGameSingle@@UAEXH@Z
    ARTS_IMPORT void UpdateGameInput(i32 arg1) override;

    // 0x417EF0 | ?UpdateScore@mmGameSingle@@QAEXXZ
    ARTS_IMPORT void UpdateScore();

    // 0x418B90 | ?DeclareFields@mmGameSingle@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // 0x417530 | ?DisableRacers@mmGameSingle@@AAEXXZ
    ARTS_IMPORT void DisableRacers();

    // 0x4174A0 | ?EnableRacers@mmGameSingle@@AAEXXZ
    ARTS_IMPORT void EnableRacers();

    // 0x418270 | ?FinishMessage@mmGameSingle@@AAEXHH@Z
    ARTS_IMPORT void FinishMessage(i32 arg1, i32 arg2);

    // 0x4187F0 | ?ProgressCheck@mmGameSingle@@AAEHHH@Z
    ARTS_IMPORT i32 ProgressCheck(i32 arg1, i32 arg2);

    // 0x4183F0 | ?RegisterFinish@mmGameSingle@@AAEHXZ
    ARTS_IMPORT i32 RegisterFinish();

    u8 gap1E570[0x80];
};

check_size(mmGameSingle, 0x1E5F0);
