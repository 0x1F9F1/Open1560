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
    mmui:cr_settings

    0x4A0550 | public: __thiscall CRSettings::CRSettings(int) | ??0CRSettings@@QAE@H@Z
    0x4A0E90 | public: virtual __thiscall CRSettings::~CRSettings(void) | ??1CRSettings@@UAE@XZ
    0x4A0F10 | public: void __thiscall CRSettings::SettingsCB(void) | ?SettingsCB@CRSettings@@QAEXXZ
    0x4A0F20 | public: void __thiscall CRSettings::SetTeam(void) | ?SetTeam@CRSettings@@QAEXXZ
    0x4A0F40 | public: void __thiscall CRSettings::SetTeamWidget(void) | ?SetTeamWidget@CRSettings@@QAEXXZ
    0x4A0F50 | public: void __thiscall CRSettings::SetHost(int) | ?SetHost@CRSettings@@QAEXH@Z
    0x4A1050 | public: void __thiscall CRSettings::InitPlayerRecord(void) | ?InitPlayerRecord@CRSettings@@QAEXXZ
    0x4A1120 | public: int __thiscall CRSettings::AddPlayerRecord(char *,int,int,char *) | ?AddPlayerRecord@CRSettings@@QAEHPADHH0@Z
    0x4A1260 | public: void __thiscall CRSettings::SetPlayerScore(int,int) | ?SetPlayerScore@CRSettings@@QAEXHH@Z
    0x4A12A0 | public: void __thiscall CRSettings::ResetPlayerRecord(void) | ?ResetPlayerRecord@CRSettings@@QAEXXZ
    0x4A1330 | public: void __thiscall CRSettings::SetLimitControl(void) | ?SetLimitControl@CRSettings@@QAEXXZ
    0x4A1490 | public: int __thiscall CRSettings::EncodeCRData(void) | ?EncodeCRData@CRSettings@@QAEHXZ
    0x4A14E0 | public: void __thiscall CRSettings::DecodeCRData(int) | ?DecodeCRData@CRSettings@@QAEXH@Z
    0x4A1550 | public: void __thiscall CRSettings::GetLimit(int &,int &) | ?GetLimit@CRSettings@@QAEXAAH0@Z
    0x4A15A0 | public: void __thiscall CRSettings::SetLimit(int &,int &) | ?SetLimit@CRSettings@@QAEXAAH0@Z
    0x4A1620 | public: void __thiscall CRSettings::SetGoldMass(int) | ?SetGoldMass@CRSettings@@QAEXH@Z
    0x4A1650 | public: int __thiscall CRSettings::GetGoldMass(void) | ?GetGoldMass@CRSettings@@QAEHXZ
    0x4A1660 | public: int __thiscall CRSettings::GetLimitVal(int &) | ?GetLimitVal@CRSettings@@QAEHAAH@Z
    0x4A16B0 | public: int __thiscall CRSettings::GetGoldMassVal(void) | ?GetGoldMassVal@CRSettings@@QAEHXZ
    0x4A16C0 | public: void __thiscall CRSettings::SetGameClassCallback(void) | ?SetGameClassCallback@CRSettings@@QAEXXZ
    0x4A16E0 | public: void __thiscall CRSettings::SetTeamWidgets(void) | ?SetTeamWidgets@CRSettings@@QAEXXZ
    0x4A1760 | public: virtual void * __thiscall CRSettings::`scalar deleting destructor'(unsigned int) | ??_GCRSettings@@UAEPAXI@Z
    0x4A1760 | public: virtual void * __thiscall CRSettings::`vector deleting destructor'(unsigned int) | ??_ECRSettings@@UAEPAXI@Z
    0x61D870 | const CRSettings::`vftable' | ??_7CRSettings@@6B@
    0x640A60 | int * GameType_PenaltyTable | ?GameType_PenaltyTable@@3PAHA
    0x640A88 | int * Limit_ValueTable | ?Limit_ValueTable@@3PAHA
*/

#include "mmwidget/menu.h"

class CRSettings : public UIMenu
{
    // const CRSettings::`vftable' @ 0x61D870

public:
    // 0x4A0550 | ??0CRSettings@@QAE@H@Z
    CRSettings(i32 arg1);

    // 0x4A1760 | ??_ECRSettings@@UAEPAXI@Z
    // 0x4A0E90 | ??1CRSettings@@UAE@XZ
    ~CRSettings() override;

    // 0x4A1120 | ?AddPlayerRecord@CRSettings@@QAEHPADHH0@Z
    i32 AddPlayerRecord(char* arg1, i32 arg2, i32 arg3, char* arg4);

    // 0x4A14E0 | ?DecodeCRData@CRSettings@@QAEXH@Z
    void DecodeCRData(i32 arg1);

    // 0x4A1490 | ?EncodeCRData@CRSettings@@QAEHXZ
    i32 EncodeCRData();

    // 0x4A1650 | ?GetGoldMass@CRSettings@@QAEHXZ
    i32 GetGoldMass();

    // 0x4A16B0 | ?GetGoldMassVal@CRSettings@@QAEHXZ
    i32 GetGoldMassVal();

    // 0x4A1550 | ?GetLimit@CRSettings@@QAEXAAH0@Z
    void GetLimit(i32& arg1, i32& arg2);

    // 0x4A1660 | ?GetLimitVal@CRSettings@@QAEHAAH@Z
    i32 GetLimitVal(i32& arg1);

    // 0x4A1050 | ?InitPlayerRecord@CRSettings@@QAEXXZ
    void InitPlayerRecord();

    // 0x4A12A0 | ?ResetPlayerRecord@CRSettings@@QAEXXZ
    void ResetPlayerRecord();

    // 0x4A16C0 | ?SetGameClassCallback@CRSettings@@QAEXXZ
    void SetGameClassCallback();

    // 0x4A1620 | ?SetGoldMass@CRSettings@@QAEXH@Z
    void SetGoldMass(i32 arg1);

    // 0x4A0F50 | ?SetHost@CRSettings@@QAEXH@Z
    void SetHost(i32 arg1);

    // 0x4A15A0 | ?SetLimit@CRSettings@@QAEXAAH0@Z
    void SetLimit(i32& arg1, i32& arg2);

    // 0x4A1330 | ?SetLimitControl@CRSettings@@QAEXXZ
    void SetLimitControl();

    // 0x4A1260 | ?SetPlayerScore@CRSettings@@QAEXHH@Z
    void SetPlayerScore(i32 arg1, i32 arg2);

    // 0x4A0F20 | ?SetTeam@CRSettings@@QAEXXZ
    void SetTeam();

    // 0x4A0F40 | ?SetTeamWidget@CRSettings@@QAEXXZ
    void SetTeamWidget();

    // 0x4A16E0 | ?SetTeamWidgets@CRSettings@@QAEXXZ
    void SetTeamWidgets();

    // 0x4A0F10 | ?SettingsCB@CRSettings@@QAEXXZ
    void SettingsCB();
};

check_size(CRSettings, 0x140);

// 0x640A60 | ?GameType_PenaltyTable@@3PAHA
inline extern_var(0x240A60_Offset, i32*, GameType_PenaltyTable);

// 0x640A88 | ?Limit_ValueTable@@3PAHA
inline extern_var(0x240A88_Offset, i32*, Limit_ValueTable);
