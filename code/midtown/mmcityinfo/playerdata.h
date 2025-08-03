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

#include "infobase.h"

class mmPlayerRecord final : public mmInfoBase
{
public:
    // ??0mmPlayerRecord@@QAE@XZ
    ARTS_IMPORT mmPlayerRecord();

    // ??0mmPlayerRecord@@QAE@ABV0@@Z | inline
    ARTS_IMPORT mmPlayerRecord(const mmPlayerRecord& arg1);

    // ??1mmPlayerRecord@@UAE@XZ
    ARTS_EXPORT ~mmPlayerRecord() override = default;

    // ??4mmPlayerRecord@@QAEXAAV0@@Z
    ARTS_IMPORT void operator=(mmPlayerRecord& arg1);

    // ?ComputeCRC@mmPlayerRecord@@QAEIXZ
    ARTS_IMPORT u32 ComputeCRC();

    // ?GetClass@mmPlayerRecord@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?LoadBinary@mmPlayerRecord@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 LoadBinary(Stream* arg1);

    // ?Reset@mmPlayerRecord@@QAEXXZ
    ARTS_IMPORT void Reset();

    // ?SaveBinary@mmPlayerRecord@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 SaveBinary(Stream* arg1);

    // ?DeclareFields@mmPlayerRecord@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap88[0x5C];
};

check_size(mmPlayerRecord, 0xE4);

class mmPlayerData final : public mmInfoBase
{
public:
    // ??0mmPlayerData@@QAE@XZ
    ARTS_IMPORT mmPlayerData();

    // ??1mmPlayerData@@UAE@XZ | inline
    ARTS_IMPORT ~mmPlayerData() override;

    // ?ComputeCRC@mmPlayerData@@QAEIXZ
    ARTS_IMPORT u32 ComputeCRC();

    // ?GetBlitzMask@mmPlayerData@@QAEHXZ
    ARTS_IMPORT i32 GetBlitzMask();

    // ?GetBlitzPassed@mmPlayerData@@QAEHXZ
    ARTS_IMPORT i32 GetBlitzPassed();

    // ?GetCheckpointMask@mmPlayerData@@QAEHXZ
    ARTS_IMPORT i32 GetCheckpointMask();

    // ?GetCheckpointPassed@mmPlayerData@@QAEHXZ
    ARTS_IMPORT i32 GetCheckpointPassed();

    // ?GetCheckpointProgress@mmPlayerData@@QAEHH@Z
    ARTS_IMPORT i32 GetCheckpointProgress(i32 arg1);

    // ?GetCircuitMask@mmPlayerData@@QAEHXZ
    ARTS_IMPORT i32 GetCircuitMask();

    // ?GetCircuitPassed@mmPlayerData@@QAEHXZ
    ARTS_IMPORT i32 GetCircuitPassed();

    // ?GetClass@mmPlayerData@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetFileName@mmPlayerData@@QAEPADXZ
    ARTS_IMPORT char* GetFileName();

    // ?GetName@mmPlayerData@@QAEPADXZ
    ARTS_IMPORT char* GetName();

    // ?GetNetName@mmPlayerData@@QAEPADXZ
    ARTS_IMPORT char* GetNetName();

    // ?GetTotalPassed@mmPlayerData@@QAEHXZ
    ARTS_IMPORT i32 GetTotalPassed();

    // ?GetTotalScore@mmPlayerData@@QAEHXZ
    ARTS_IMPORT i32 GetTotalScore();

    // ?Load@mmPlayerData@@QAEHPAD@Z
    ARTS_IMPORT i32 Load(char* arg1);

    // ?LoadBinary@mmPlayerData@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadBinary(char* arg1);

    // ?RegisterFinish@mmPlayerData@@QAEHVmmPlayerRecord@@HH@Z
    ARTS_IMPORT i32 RegisterFinish(mmPlayerRecord arg1, i32 arg2, i32 arg3);

    // ?RegisterFinish@mmPlayerData@@QAEHHMD@Z | unused
    i32 RegisterFinish(i32 arg1, f32 arg2, char arg3);

    // ?Reset@mmPlayerData@@QAEXXZ
    ARTS_IMPORT void Reset();

    // ?ResolveCheckpointProgress@mmPlayerData@@QAEXXZ
    ARTS_IMPORT void ResolveCheckpointProgress();

    // ?Save@mmPlayerData@@QAEHPADH@Z
    ARTS_IMPORT i32 Save(char* arg1, i32 arg2);

    // ?SaveBinary@mmPlayerData@@QAEHPAD@Z
    ARTS_IMPORT i32 SaveBinary(char* arg1);

    // ?SetFileName@mmPlayerData@@QAEXPAD@Z
    ARTS_IMPORT void SetFileName(char* arg1);

    // ?SetName@mmPlayerData@@QAEXPAD@Z
    ARTS_IMPORT void SetName(char* arg1);

    // ?SetNetName@mmPlayerData@@QAEXPAD@Z
    ARTS_IMPORT void SetNetName(char* arg1);

    // ?DeclareFields@mmPlayerData@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    char PlayerName[40];
    char NetName[40];
    char FileName[40];
    i8 Difficulty;
    i32 Progress;
    mmPlayerRecord CheckpointRecords[12];
    mmPlayerRecord CircuitRecords[12];
    mmPlayerRecord BlitzRecords[12];
    char LastCarPicked[80];
    i32 LastCarColor;
    i32 LastGamePicked;
    i32 LastRacePicked;
    bool Loaded;
};

check_size(mmPlayerData, 0x2178);
