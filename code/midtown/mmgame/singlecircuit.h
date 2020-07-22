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
    mmgame:singlecircuit

    0x414BF0 | public: __thiscall mmSingleCircuit::mmSingleCircuit(void) | ??0mmSingleCircuit@@QAE@XZ
    0x414C90 | public: virtual __thiscall mmSingleCircuit::~mmSingleCircuit(void) | ??1mmSingleCircuit@@UAE@XZ
    0x414D50 | public: int __thiscall mmSingleCircuit::Init(void) | ?Init@mmSingleCircuit@@QAEHXZ
    0x414ED0 | public: virtual void __thiscall mmSingleCircuit::InitMyPlayer(void) | ?InitMyPlayer@mmSingleCircuit@@UAEXXZ
    0x414F40 | public: virtual void __thiscall mmSingleCircuit::InitHUD(void) | ?InitHUD@mmSingleCircuit@@UAEXXZ
    0x414F90 | public: virtual void __thiscall mmSingleCircuit::InitGameObjects(void) | ?InitGameObjects@mmSingleCircuit@@UAEXXZ
    0x415200 | public: virtual void __thiscall mmSingleCircuit::InitOtherPlayers(void) | ?InitOtherPlayers@mmSingleCircuit@@UAEXXZ
    0x415210 | public: virtual void __thiscall mmSingleCircuit::Reset(void) | ?Reset@mmSingleCircuit@@UAEXXZ
    0x4152E0 | public: virtual void __thiscall mmSingleCircuit::HitWaterHandler(void) | ?HitWaterHandler@mmSingleCircuit@@UAEXXZ
    0x415390 | private: void __thiscall mmSingleCircuit::EnableRacers(void) | ?EnableRacers@mmSingleCircuit@@AAEXXZ
    0x415420 | private: void __thiscall mmSingleCircuit::DisableRacers(void) | ?DisableRacers@mmSingleCircuit@@AAEXXZ
    0x415490 | public: virtual void __thiscall mmSingleCircuit::Update(void) | ?Update@mmSingleCircuit@@UAEXXZ
    0x4154B0 | public: virtual void __thiscall mmSingleCircuit::UpdateGameInput(int) | ?UpdateGameInput@mmSingleCircuit@@UAEXH@Z
    0x4154C0 | public: void __thiscall mmSingleCircuit::UpdateScore(void) | ?UpdateScore@mmSingleCircuit@@QAEXXZ
    0x415850 | public: virtual void __thiscall mmSingleCircuit::UpdateGame(void) | ?UpdateGame@mmSingleCircuit@@UAEXXZ
    0x415FE0 | private: void __thiscall mmSingleCircuit::FinishMessage(int,int) | ?FinishMessage@mmSingleCircuit@@AAEXHH@Z
    0x416170 | private: int __thiscall mmSingleCircuit::RegisterLap(void) | ?RegisterLap@mmSingleCircuit@@AAEHXZ
    0x4161D0 | private: int __thiscall mmSingleCircuit::RegisterFinish(void) | ?RegisterFinish@mmSingleCircuit@@AAEHXZ
    0x4165F0 | private: int __thiscall mmSingleCircuit::ProgressCheck(int,int) | ?ProgressCheck@mmSingleCircuit@@AAEHHH@Z
    0x416620 | public: virtual void __thiscall mmSingleCircuit::NextRace(void) | ?NextRace@mmSingleCircuit@@UAEXXZ
    0x4167A0 | public: virtual void __thiscall mmSingleCircuit::AddWidgets(class Bank *) | ?AddWidgets@mmSingleCircuit@@UAEXPAVBank@@@Z
    0x416940 | public: static void __cdecl mmSingleCircuit::DeclareFields(void) | ?DeclareFields@mmSingleCircuit@@SAXXZ
    0x416AB0 | public: virtual class MetaClass * __thiscall mmSingleCircuit::GetClass(void) | ?GetClass@mmSingleCircuit@@UAEPAVMetaClass@@XZ
    0x416C10 | public: virtual void * __thiscall mmSingleCircuit::`vector deleting destructor'(unsigned int) | ??_EmmSingleCircuit@@UAEPAXI@Z
    0x416C70 | public: virtual void __thiscall mmSingleCircuit::UpdateDebugKeyInput(int) | ?UpdateDebugKeyInput@mmSingleCircuit@@UAEXH@Z
    0x416C80 | public: virtual class mmWaypoints * __thiscall mmSingleCircuit::GetWaypoints(void) | ?GetWaypoints@mmSingleCircuit@@UAEPAVmmWaypoints@@XZ
    0x61A680 | const mmSingleCircuit::`vftable' | ??_7mmSingleCircuit@@6B@
    0x6A70A8 | class MetaClass mmSingleCircuitMetaClass | ?mmSingleCircuitMetaClass@@3VMetaClass@@A
*/

#include "game.h"

class mmSingleCircuit final : public mmGame
{
    // const mmSingleCircuit::`vftable' @ 0x61A680

public:
    // 0x414BF0 | ??0mmSingleCircuit@@QAE@XZ
    ARTS_IMPORT mmSingleCircuit();

    // 0x416C10 | ??_EmmSingleCircuit@@UAEPAXI@Z
    // 0x414C90 | ??1mmSingleCircuit@@UAE@XZ
    ARTS_IMPORT ~mmSingleCircuit() override;

    // 0x4167A0 | ?AddWidgets@mmSingleCircuit@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x416AB0 | ?GetClass@mmSingleCircuit@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x416C80 | ?GetWaypoints@mmSingleCircuit@@UAEPAVmmWaypoints@@XZ | inline
    ARTS_IMPORT class mmWaypoints* GetWaypoints() override;

    // 0x4152E0 | ?HitWaterHandler@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void HitWaterHandler() override;

    // 0x414D50 | ?Init@mmSingleCircuit@@QAEHXZ
    ARTS_IMPORT i32 Init();

    // 0x414F90 | ?InitGameObjects@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void InitGameObjects() override;

    // 0x414F40 | ?InitHUD@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void InitHUD() override;

    // 0x414ED0 | ?InitMyPlayer@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void InitMyPlayer() override;

    // 0x415200 | ?InitOtherPlayers@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void InitOtherPlayers() override;

    // 0x416620 | ?NextRace@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void NextRace() override;

    // 0x415210 | ?Reset@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x415490 | ?Update@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x416C70 | ?UpdateDebugKeyInput@mmSingleCircuit@@UAEXH@Z | inline
    ARTS_EXPORT void UpdateDebugKeyInput(i32 arg1) override;

    // 0x415850 | ?UpdateGame@mmSingleCircuit@@UAEXXZ
    ARTS_IMPORT void UpdateGame() override;

    // 0x4154B0 | ?UpdateGameInput@mmSingleCircuit@@UAEXH@Z
    ARTS_EXPORT void UpdateGameInput(i32 arg1) override;

    // 0x4154C0 | ?UpdateScore@mmSingleCircuit@@QAEXXZ
    ARTS_IMPORT void UpdateScore();

    // 0x416940 | ?DeclareFields@mmSingleCircuit@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // 0x415420 | ?DisableRacers@mmSingleCircuit@@AAEXXZ
    ARTS_IMPORT void DisableRacers();

    // 0x415390 | ?EnableRacers@mmSingleCircuit@@AAEXXZ
    ARTS_IMPORT void EnableRacers();

    // 0x415FE0 | ?FinishMessage@mmSingleCircuit@@AAEXHH@Z
    ARTS_IMPORT void FinishMessage(i32 arg1, i32 arg2);

    // 0x4165F0 | ?ProgressCheck@mmSingleCircuit@@AAEHHH@Z
    ARTS_IMPORT i32 ProgressCheck(i32 arg1, i32 arg2);

    // 0x4161D0 | ?RegisterFinish@mmSingleCircuit@@AAEHXZ
    ARTS_IMPORT i32 RegisterFinish();

    // 0x416170 | ?RegisterLap@mmSingleCircuit@@AAEHXZ
    ARTS_IMPORT i32 RegisterLap();

    u8 gap1E570[0x90];
};

check_size(mmSingleCircuit, 0x1E600);

// 0x6A70A8 | ?mmSingleCircuitMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmSingleCircuitMetaClass;
