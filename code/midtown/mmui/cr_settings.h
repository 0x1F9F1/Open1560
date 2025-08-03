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

#include "mmwidget/menu.h"

class CRSettings final : public UIMenu
{
public:
    // ??0CRSettings@@QAE@H@Z
    ARTS_IMPORT CRSettings(i32 arg1);

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
    void SettingsCB();

    u8 gap90[0xB0];
};

check_size(CRSettings, 0x140);

// ?GameType_PenaltyTable@@3PAHA
ARTS_IMPORT extern i32 GameType_PenaltyTable[10];

// ?Limit_ValueTable@@3PAHA
ARTS_IMPORT extern i32 Limit_ValueTable[12];
