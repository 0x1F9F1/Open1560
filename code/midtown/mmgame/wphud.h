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

class mmWPHUD : public asNode
{
    // const mmWPHUD::`vftable' @ 0x61AC38

public:
    // 0x4241A0 | ??0mmWPHUD@@QAE@XZ
    mmWPHUD();

    // 0x426240 | ??_GmmWPHUD@@UAEPAXI@Z
    // 0x4242B0 | ??1mmWPHUD@@UAE@XZ
    ~mmWPHUD() override;

    // 0x424780 | ?AddWidgets@mmWPHUD@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x424770 | ?Cull@mmWPHUD@@UAEXXZ
    void Cull() override;

    // 0x4243F0 | ?Init@mmWPHUD@@QAEXHPAH0H@Z
    void Init(i32 arg1, i32* arg2, i32* arg3, i32 arg4);

    // 0x4246E0 | ?Reset@mmWPHUD@@UAEXXZ
    void Reset() override;

    // 0x4243B0 | ?SetStandings@mmWPHUD@@QAEXHH@Z
    void SetStandings(i32 arg1, i32 arg2);

    // 0x424360 | ?SetWPCleared@mmWPHUD@@QAEXXZ
    void SetWPCleared();

    // 0x424730 | ?Update@mmWPHUD@@UAEXXZ
    void Update() override;
};

check_size(mmWPHUD, 0x0);

class mmCircuitHUD : public asNode
{
    // const mmCircuitHUD::`vftable' @ 0x61AC78

public:
    // 0x424790 | ??0mmCircuitHUD@@QAE@XZ
    mmCircuitHUD();

    // 0x426270 | ??_EmmCircuitHUD@@UAEPAXI@Z
    // 0x4248A0 | ??1mmCircuitHUD@@UAE@XZ
    ~mmCircuitHUD() override;

    // 0x4249A0 | ?Init@mmCircuitHUD@@QAEXXZ
    void Init();

    // 0x425090 | ?Reset@mmCircuitHUD@@UAEXXZ
    void Reset() override;

    // 0x424FB0 | ?SetLapTime@mmCircuitHUD@@QAEXHMPADH@Z
    void SetLapTime(i32 arg1, f32 arg2, char* arg3, i32 arg4);

    // 0x424F60 | ?SetStandings@mmCircuitHUD@@QAEXHH@Z
    void SetStandings(i32 arg1, i32 arg2);

    // 0x425050 | ?SetWPCleared@mmCircuitHUD@@QAEXHH@Z
    void SetWPCleared(i32 arg1, i32 arg2);

    // 0x424F50 | ?Update@mmCircuitHUD@@UAEXXZ
    void Update() override;
};

check_size(mmCircuitHUD, 0x0);

class mmCRHUD : public asNode
{
    // const mmCRHUD::`vftable' @ 0x61ACB8

public:
    // 0x425140 | ??0mmCRHUD@@QAE@XZ
    mmCRHUD();

    // 0x426360 | ??_EmmCRHUD@@UAEPAXI@Z
    // 0x4252E0 | ??1mmCRHUD@@UAE@XZ
    ~mmCRHUD() override;

    // 0x426090 | ?ActivateGold@mmCRHUD@@QAEXXZ
    void ActivateGold();

    // 0x4260B0 | ?ActivateRosterGold@mmCRHUD@@QAEXK@Z
    void ActivateRosterGold(u32 arg1);

    // 0x425C50 | ?AddPlayer@mmCRHUD@@QAEXPADKHI@Z
    void AddPlayer(char* arg1, u32 arg2, i32 arg3, u32 arg4);

    // 0x4260A0 | ?DeactivateGold@mmCRHUD@@QAEXXZ
    void DeactivateGold();

    // 0x426100 | ?DeactivateRosterGold@mmCRHUD@@QAEXXZ
    void DeactivateRosterGold();

    // 0x425410 | ?Init@mmCRHUD@@QAEXPAVasLinearCS@@PADW4mmCRGameClass@@@Z
    void Init(class asLinearCS* arg1, char* arg2, enum mmCRGameClass arg3);

    // 0x425F20 | ?RemovePlayer@mmCRHUD@@QAEXK@Z
    void RemovePlayer(u32 arg1);

    // 0x426180 | ?Reset@mmCRHUD@@UAEXXZ
    void Reset() override;

    // 0x426190 | ?SetBlueScore@mmCRHUD@@QAEXH@Z
    void SetBlueScore(i32 arg1);

    // 0x425E30 | ?SetName@mmCRHUD@@QAEXPADH@Z
    void SetName(char* arg1, i32 arg2);

    // 0x4261D0 | ?SetRedScore@mmCRHUD@@QAEXH@Z
    void SetRedScore(i32 arg1);

    // 0x425E10 | ?SetScore@mmCRHUD@@QAEXPAD@Z
    void SetScore(char* arg1);

    // 0x425EB0 | ?SetScore@mmCRHUD@@QAEXKH@Z
    void SetScore(u32 arg1, i32 arg2);

    // 0x425C20 | ?ToggleScores@mmCRHUD@@QAEXXZ
    void ToggleScores();

    // 0x425D90 | ?UnPackColor@mmCRHUD@@QAEXIAAVVector4@@@Z
    void UnPackColor(u32 arg1, class Vector4& arg2);

    // 0x426160 | ?Update@mmCRHUD@@UAEXXZ
    void Update() override;

    // 0x426140 | ?UpdateGold@mmCRHUD@@QAEXXZ
    void UpdateGold();
};

check_size(mmCRHUD, 0x218);

// 0x636A00 | ?fontscalar@@3MA
inline extern_var(0x636A00, f32, fontscalar);
