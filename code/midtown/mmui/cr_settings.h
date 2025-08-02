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

class CRSettings final : public UIMenu
{
public:
    // ??0CRSettings@@QAE@H@Z
    ARTS_IMPORT CRSettings(i32 arg1);

    // ??_ECRSettings@@UAEPAXI@Z
    // ??_GCRSettings@@UAEPAXI@Z
    // ??1CRSettings@@UAE@XZ
    ARTS_IMPORT ~CRSettings() override;

    // ?AddPlayerRecord@CRSettings@@QAEHPADHH0@Z
    ARTS_IMPORT i32 AddPlayerRecord(char* arg1, i32 arg2, i32 arg3, char* arg4);

    // ?DecodeCRData@CRSettings@@QAEXH@Z
    ARTS_IMPORT void DecodeCRData(i32 arg1);

    // ?EncodeCRData@CRSettings@@QAEHXZ
    ARTS_IMPORT i32 EncodeCRData();

    // ?GetGoldMassVal@CRSettings@@QAEHXZ
    ARTS_IMPORT i32 GetGoldMassVal();

    // ?GetLimit@CRSettings@@QAEXAAH0@Z
    ARTS_IMPORT void GetLimit(i32& arg1, i32& arg2);

    // ?GetLimitVal@CRSettings@@QAEHAAH@Z
    ARTS_IMPORT i32 GetLimitVal(i32& arg1);

    // ?InitPlayerRecord@CRSettings@@QAEXXZ
    ARTS_IMPORT void InitPlayerRecord();

    // ?ResetPlayerRecord@CRSettings@@QAEXXZ
    ARTS_IMPORT void ResetPlayerRecord();

    // ?SetGameClassCallback@CRSettings@@QAEXXZ
    ARTS_IMPORT void SetGameClassCallback();

    // ?SetHost@CRSettings@@QAEXH@Z
    ARTS_IMPORT void SetHost(i32 arg1);

    // ?SetLimit@CRSettings@@QAEXAAH0@Z
    ARTS_IMPORT void SetLimit(i32& arg1, i32& arg2);

    // ?SetLimitControl@CRSettings@@QAEXXZ
    ARTS_IMPORT void SetLimitControl();

    // ?SetPlayerScore@CRSettings@@QAEXHH@Z
    ARTS_IMPORT void SetPlayerScore(i32 arg1, i32 arg2);

    // ?SetTeam@CRSettings@@QAEXXZ
    ARTS_IMPORT void SetTeam();

    // ?SetTeamWidget@CRSettings@@QAEXXZ
    ARTS_IMPORT void SetTeamWidget();

    // ?SetTeamWidgets@CRSettings@@QAEXXZ
    ARTS_IMPORT void SetTeamWidgets();

    // ?SettingsCB@CRSettings@@QAEXXZ | unused
    ARTS_EXPORT void SettingsCB();

    u8 gap90[0xB0];
};

check_size(CRSettings, 0x140);

// ?GameType_PenaltyTable@@3PAHA
ARTS_IMPORT extern i32 GameType_PenaltyTable[10];

// ?Limit_ValueTable@@3PAHA
ARTS_IMPORT extern i32 Limit_ValueTable[12];
