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
    mmgame:wphud

    0x4241A0 | public: __thiscall mmWPHUD::mmWPHUD(void) | ??0mmWPHUD@@QAE@XZ
    0x4242B0 | public: virtual __thiscall mmWPHUD::~mmWPHUD(void) | ??1mmWPHUD@@UAE@XZ
    0x424360 | public: void __thiscall mmWPHUD::SetWPCleared(void) | ?SetWPCleared@mmWPHUD@@QAEXXZ
    0x4243B0 | public: void __thiscall mmWPHUD::SetStandings(int,int) | ?SetStandings@mmWPHUD@@QAEXHH@Z
    0x4243F0 | public: void __thiscall mmWPHUD::Init(int,int *,int *,int) | ?Init@mmWPHUD@@QAEXHPAH0H@Z
    0x4246E0 | public: virtual void __thiscall mmWPHUD::Reset(void) | ?Reset@mmWPHUD@@UAEXXZ
    0x424730 | public: virtual void __thiscall mmWPHUD::Update(void) | ?Update@mmWPHUD@@UAEXXZ
    0x424770 | public: virtual void __thiscall mmWPHUD::Cull(void) | ?Cull@mmWPHUD@@UAEXXZ
    0x424780 | public: virtual void __thiscall mmWPHUD::AddWidgets(class Bank *) | ?AddWidgets@mmWPHUD@@UAEXPAVBank@@@Z
    0x424790 | public: __thiscall mmCircuitHUD::mmCircuitHUD(void) | ??0mmCircuitHUD@@QAE@XZ
    0x4248A0 | public: virtual __thiscall mmCircuitHUD::~mmCircuitHUD(void) | ??1mmCircuitHUD@@UAE@XZ
    0x4249A0 | public: void __thiscall mmCircuitHUD::Init(void) | ?Init@mmCircuitHUD@@QAEXXZ
    0x424F50 | public: virtual void __thiscall mmCircuitHUD::Update(void) | ?Update@mmCircuitHUD@@UAEXXZ
    0x424F60 | public: void __thiscall mmCircuitHUD::SetStandings(int,int) | ?SetStandings@mmCircuitHUD@@QAEXHH@Z
    0x424FB0 | public: void __thiscall mmCircuitHUD::SetLapTime(int,float,char *,int) | ?SetLapTime@mmCircuitHUD@@QAEXHMPADH@Z
    0x425050 | public: void __thiscall mmCircuitHUD::SetWPCleared(int,int) | ?SetWPCleared@mmCircuitHUD@@QAEXHH@Z
    0x425090 | public: virtual void __thiscall mmCircuitHUD::Reset(void) | ?Reset@mmCircuitHUD@@UAEXXZ
    0x425140 | public: __thiscall mmCRHUD::mmCRHUD(void) | ??0mmCRHUD@@QAE@XZ
    0x4252E0 | public: virtual __thiscall mmCRHUD::~mmCRHUD(void) | ??1mmCRHUD@@UAE@XZ
    0x425410 | public: void __thiscall mmCRHUD::Init(class asLinearCS *,char *,enum mmCRGameClass) | ?Init@mmCRHUD@@QAEXPAVasLinearCS@@PADW4mmCRGameClass@@@Z
    0x425C20 | public: void __thiscall mmCRHUD::ToggleScores(void) | ?ToggleScores@mmCRHUD@@QAEXXZ
    0x425C50 | public: void __thiscall mmCRHUD::AddPlayer(char *,unsigned long,int,unsigned int) | ?AddPlayer@mmCRHUD@@QAEXPADKHI@Z
    0x425D90 | public: void __thiscall mmCRHUD::UnPackColor(unsigned int,class Vector4 &) | ?UnPackColor@mmCRHUD@@QAEXIAAVVector4@@@Z
    0x425E10 | public: void __thiscall mmCRHUD::SetScore(char *) | ?SetScore@mmCRHUD@@QAEXPAD@Z
    0x425E30 | public: void __thiscall mmCRHUD::SetName(char *,int) | ?SetName@mmCRHUD@@QAEXPADH@Z
    0x425EB0 | public: void __thiscall mmCRHUD::SetScore(unsigned long,int) | ?SetScore@mmCRHUD@@QAEXKH@Z
    0x425F20 | public: void __thiscall mmCRHUD::RemovePlayer(unsigned long) | ?RemovePlayer@mmCRHUD@@QAEXK@Z
    0x426090 | public: void __thiscall mmCRHUD::ActivateGold(void) | ?ActivateGold@mmCRHUD@@QAEXXZ
    0x4260A0 | public: void __thiscall mmCRHUD::DeactivateGold(void) | ?DeactivateGold@mmCRHUD@@QAEXXZ
    0x4260B0 | public: void __thiscall mmCRHUD::ActivateRosterGold(unsigned long) | ?ActivateRosterGold@mmCRHUD@@QAEXK@Z
    0x426100 | public: void __thiscall mmCRHUD::DeactivateRosterGold(void) | ?DeactivateRosterGold@mmCRHUD@@QAEXXZ
    0x426140 | public: void __thiscall mmCRHUD::UpdateGold(void) | ?UpdateGold@mmCRHUD@@QAEXXZ
    0x426160 | public: virtual void __thiscall mmCRHUD::Update(void) | ?Update@mmCRHUD@@UAEXXZ
    0x426180 | public: virtual void __thiscall mmCRHUD::Reset(void) | ?Reset@mmCRHUD@@UAEXXZ
    0x426190 | public: void __thiscall mmCRHUD::SetBlueScore(int) | ?SetBlueScore@mmCRHUD@@QAEXH@Z
    0x4261D0 | public: void __thiscall mmCRHUD::SetRedScore(int) | ?SetRedScore@mmCRHUD@@QAEXH@Z
    0x426240 | public: virtual void * __thiscall mmWPHUD::`vector deleting destructor'(unsigned int) | ??_EmmWPHUD@@UAEPAXI@Z
    0x426240 | public: virtual void * __thiscall mmWPHUD::`scalar deleting destructor'(unsigned int) | ??_GmmWPHUD@@UAEPAXI@Z
    0x426270 | public: virtual void * __thiscall mmCircuitHUD::`scalar deleting destructor'(unsigned int) | ??_GmmCircuitHUD@@UAEPAXI@Z
    0x426270 | public: virtual void * __thiscall mmCircuitHUD::`vector deleting destructor'(unsigned int) | ??_EmmCircuitHUD@@UAEPAXI@Z
    0x4262A0 | public: virtual void * __thiscall mmNumber::`vector deleting destructor'(unsigned int) | ??_EmmNumber@@UAEPAXI@Z
    0x426300 | public: virtual void * __thiscall mmTextNode::`vector deleting destructor'(unsigned int) | ??_EmmTextNode@@UAEPAXI@Z
    0x426360 | public: virtual void * __thiscall mmCRHUD::`scalar deleting destructor'(unsigned int) | ??_GmmCRHUD@@UAEPAXI@Z
    0x426360 | public: virtual void * __thiscall mmCRHUD::`vector deleting destructor'(unsigned int) | ??_EmmCRHUD@@UAEPAXI@Z
    0x61AC38 | const mmWPHUD::`vftable' | ??_7mmWPHUD@@6B@
    0x61AC78 | const mmCircuitHUD::`vftable' | ??_7mmCircuitHUD@@6B@
    0x61ACB8 | const mmCRHUD::`vftable' | ??_7mmCRHUD@@6B@
    0x636A00 | float fontscalar | ?fontscalar@@3MA
*/

#include "arts7/node.h"

enum class mmCRGameClass : i32;
class asLinearCS;

class mmWPHUD final : public asNode
{
public:
    // ??0mmWPHUD@@QAE@XZ
    ARTS_IMPORT mmWPHUD();

    // ??_GmmWPHUD@@UAEPAXI@Z
    // ??_EmmWPHUD@@UAEPAXI@Z
    // ??1mmWPHUD@@UAE@XZ
    ARTS_IMPORT ~mmWPHUD() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmWPHUD@@UAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Cull@mmWPHUD@@UAEXXZ
    ARTS_EXPORT void Cull() override;

    // ?Init@mmWPHUD@@QAEXHPAH0H@Z
    ARTS_IMPORT void Init(i32 arg1, i32* arg2, i32* arg3, i32 arg4);

    // ?Reset@mmWPHUD@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetStandings@mmWPHUD@@QAEXHH@Z
    ARTS_IMPORT void SetStandings(i32 arg1, i32 arg2);

    // ?SetWPCleared@mmWPHUD@@QAEXXZ
    ARTS_IMPORT void SetWPCleared();

    // ?Update@mmWPHUD@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x78];
};

check_size(mmWPHUD, 0x98);

class mmCircuitHUD final : public asNode
{
public:
    // ??0mmCircuitHUD@@QAE@XZ
    ARTS_IMPORT mmCircuitHUD();

    // ??_EmmCircuitHUD@@UAEPAXI@Z
    // ??_GmmCircuitHUD@@UAEPAXI@Z
    // ??1mmCircuitHUD@@UAE@XZ
    ARTS_IMPORT ~mmCircuitHUD() override;

    // ?Init@mmCircuitHUD@@QAEXXZ
    ARTS_IMPORT void Init();

    // ?Reset@mmCircuitHUD@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetLapTime@mmCircuitHUD@@QAEXHMPADH@Z
    ARTS_IMPORT void SetLapTime(i32 arg1, f32 arg2, char* arg3, i32 arg4);

    // ?SetStandings@mmCircuitHUD@@QAEXHH@Z
    ARTS_IMPORT void SetStandings(i32 arg1, i32 arg2);

    // ?SetWPCleared@mmCircuitHUD@@QAEXHH@Z
    ARTS_IMPORT void SetWPCleared(i32 arg1, i32 arg2);

    // ?Update@mmCircuitHUD@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x7C];
};

check_size(mmCircuitHUD, 0x9C);

class mmCRHUD final : public asNode
{
public:
    // ??0mmCRHUD@@QAE@XZ
    ARTS_IMPORT mmCRHUD();

    // ??_EmmCRHUD@@UAEPAXI@Z
    // ??_GmmCRHUD@@UAEPAXI@Z
    // ??1mmCRHUD@@UAE@XZ
    ARTS_IMPORT ~mmCRHUD() override;

    // ?ActivateGold@mmCRHUD@@QAEXXZ
    ARTS_IMPORT void ActivateGold();

    // ?ActivateRosterGold@mmCRHUD@@QAEXK@Z
    ARTS_IMPORT void ActivateRosterGold(ulong arg1);

    // ?AddPlayer@mmCRHUD@@QAEXPADKHI@Z
    ARTS_IMPORT void AddPlayer(char* arg1, ulong arg2, i32 arg3, u32 arg4);

    // ?DeactivateGold@mmCRHUD@@QAEXXZ
    ARTS_IMPORT void DeactivateGold();

    // ?DeactivateRosterGold@mmCRHUD@@QAEXXZ
    ARTS_IMPORT void DeactivateRosterGold();

    // ?Init@mmCRHUD@@QAEXPAVasLinearCS@@PADW4mmCRGameClass@@@Z
    ARTS_IMPORT void Init(asLinearCS* arg1, char* arg2, mmCRGameClass arg3);

    // ?RemovePlayer@mmCRHUD@@QAEXK@Z
    ARTS_IMPORT void RemovePlayer(ulong arg1);

    // ?Reset@mmCRHUD@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetBlueScore@mmCRHUD@@QAEXH@Z
    ARTS_IMPORT void SetBlueScore(i32 arg1);

    // ?SetName@mmCRHUD@@QAEXPADH@Z
    ARTS_IMPORT void SetName(char* arg1, i32 arg2);

    // ?SetRedScore@mmCRHUD@@QAEXH@Z
    ARTS_IMPORT void SetRedScore(i32 arg1);

    // ?SetScore@mmCRHUD@@QAEXPAD@Z
    ARTS_IMPORT void SetScore(char* arg1);

    // ?SetScore@mmCRHUD@@QAEXKH@Z
    ARTS_IMPORT void SetScore(ulong arg1, i32 arg2);

    // ?ToggleScores@mmCRHUD@@QAEXXZ | unused
    ARTS_IMPORT void ToggleScores();

    // ?UnPackColor@mmCRHUD@@QAEXIAAVVector4@@@Z
    ARTS_IMPORT void UnPackColor(u32 arg1, Vector4& arg2);

    // ?Update@mmCRHUD@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateGold@mmCRHUD@@QAEXXZ
    ARTS_IMPORT void UpdateGold();

    u8 gap20[0x1F8];
};

check_size(mmCRHUD, 0x218);

// ?fontscalar@@3MA
ARTS_IMPORT extern f32 fontscalar;
