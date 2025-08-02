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
    mmcityinfo:playerdata

    0x4CFC30 | public: __thiscall mmPlayerRecord::mmPlayerRecord(void) | ??0mmPlayerRecord@@QAE@XZ
    0x4CFC50 | public: virtual __thiscall mmPlayerRecord::~mmPlayerRecord(void) | ??1mmPlayerRecord@@UAE@XZ
    0x4CFC60 | public: void __thiscall mmPlayerRecord::Reset(void) | ?Reset@mmPlayerRecord@@QAEXXZ
    0x4CFC90 | public: void __thiscall mmPlayerRecord::operator=(class mmPlayerRecord &) | ??4mmPlayerRecord@@QAEXAAV0@@Z
    0x4CFCE0 | public: unsigned int __thiscall mmPlayerRecord::ComputeCRC(void) | ?ComputeCRC@mmPlayerRecord@@QAEIXZ
    0x4CFD40 | public: int __thiscall mmPlayerRecord::SaveBinary(class Stream *) | ?SaveBinary@mmPlayerRecord@@QAEHPAVStream@@@Z
    0x4CFDC0 | public: int __thiscall mmPlayerRecord::LoadBinary(class Stream *) | ?LoadBinary@mmPlayerRecord@@QAEHPAVStream@@@Z
    0x4CFE40 | public: static void __cdecl mmPlayerRecord::DeclareFields(void) | ?DeclareFields@mmPlayerRecord@@SAXXZ
    0x4D0010 | public: virtual class MetaClass * __thiscall mmPlayerRecord::GetClass(void) | ?GetClass@mmPlayerRecord@@UAEPAVMetaClass@@XZ
    0x4D0020 | public: __thiscall mmPlayerData::mmPlayerData(void) | ??0mmPlayerData@@QAE@XZ
    0x4D0140 | public: void __thiscall mmPlayerData::operator=(class mmPlayerData &) | ??4mmPlayerData@@QAEXAAV0@@Z
    0x4D0280 | public: int __thiscall mmPlayerData::RegisterFinish(int,float,char) | ?RegisterFinish@mmPlayerData@@QAEHHMD@Z
    0x4D0290 | public: int __thiscall mmPlayerData::GetCheckpointProgress(int) | ?GetCheckpointProgress@mmPlayerData@@QAEHH@Z
    0x4D02B0 | public: int __thiscall mmPlayerData::GetBlitzMask(void) | ?GetBlitzMask@mmPlayerData@@QAEHXZ
    0x4D02E0 | public: int __thiscall mmPlayerData::GetCheckpointMask(void) | ?GetCheckpointMask@mmPlayerData@@QAEHXZ
    0x4D0310 | public: int __thiscall mmPlayerData::GetCircuitMask(void) | ?GetCircuitMask@mmPlayerData@@QAEHXZ
    0x4D0340 | public: int __thiscall mmPlayerData::GetBlitzPassed(void) | ?GetBlitzPassed@mmPlayerData@@QAEHXZ
    0x4D0360 | public: int __thiscall mmPlayerData::GetCheckpointPassed(void) | ?GetCheckpointPassed@mmPlayerData@@QAEHXZ
    0x4D0380 | public: int __thiscall mmPlayerData::GetCircuitPassed(void) | ?GetCircuitPassed@mmPlayerData@@QAEHXZ
    0x4D03A0 | public: int __thiscall mmPlayerData::GetTotalPassed(void) | ?GetTotalPassed@mmPlayerData@@QAEHXZ
    0x4D03C0 | public: int __thiscall mmPlayerData::GetTotalScore(void) | ?GetTotalScore@mmPlayerData@@QAEHXZ
    0x4D0410 | public: void __thiscall mmPlayerData::ResolveCheckpointProgress(void) | ?ResolveCheckpointProgress@mmPlayerData@@QAEXXZ
    0x4D04A0 | public: int __thiscall mmPlayerData::RegisterFinish(class mmPlayerRecord,int,int) | ?RegisterFinish@mmPlayerData@@QAEHVmmPlayerRecord@@HH@Z
    0x4D0750 | public: void __thiscall mmPlayerData::Reset(void) | ?Reset@mmPlayerData@@QAEXXZ
    0x4D0820 | public: void __thiscall mmPlayerData::SetName(char *) | ?SetName@mmPlayerData@@QAEXPAD@Z
    0x4D0860 | public: char * __thiscall mmPlayerData::GetName(void) | ?GetName@mmPlayerData@@QAEPADXZ
    0x4D0870 | public: void __thiscall mmPlayerData::SetNetName(char *) | ?SetNetName@mmPlayerData@@QAEXPAD@Z
    0x4D08B0 | public: char * __thiscall mmPlayerData::GetNetName(void) | ?GetNetName@mmPlayerData@@QAEPADXZ
    0x4D08C0 | public: void __thiscall mmPlayerData::SetFileName(char *) | ?SetFileName@mmPlayerData@@QAEXPAD@Z
    0x4D0900 | public: char * __thiscall mmPlayerData::GetFileName(void) | ?GetFileName@mmPlayerData@@QAEPADXZ
    0x4D0910 | public: int __thiscall mmPlayerData::Load(char *) | ?Load@mmPlayerData@@QAEHPAD@Z
    0x4D0940 | public: int __thiscall mmPlayerData::Save(char *,int) | ?Save@mmPlayerData@@QAEHPADH@Z
    0x4D09E0 | public: unsigned int __thiscall mmPlayerData::ComputeCRC(void) | ?ComputeCRC@mmPlayerData@@QAEIXZ
    0x4D0A90 | public: int __thiscall mmPlayerData::LoadBinary(char *) | ?LoadBinary@mmPlayerData@@QAEHPAD@Z
    0x4D0CF0 | public: int __thiscall mmPlayerData::SaveBinary(char *) | ?SaveBinary@mmPlayerData@@QAEHPAD@Z
    0x4D0F00 | public: static void __cdecl mmPlayerData::DeclareFields(void) | ?DeclareFields@mmPlayerData@@SAXXZ
    0x4D11E0 | public: virtual class MetaClass * __thiscall mmPlayerData::GetClass(void) | ?GetClass@mmPlayerData@@UAEPAVMetaClass@@XZ
    0x4D11F0 | public: virtual void * __thiscall mmPlayerRecord::`vector deleting destructor'(unsigned int) | ??_EmmPlayerRecord@@UAEPAXI@Z
    0x4D1250 | public: virtual void * __thiscall mmPlayerData::`vector deleting destructor'(unsigned int) | ??_EmmPlayerData@@UAEPAXI@Z
    0x708570 | class MetaClass mmPlayerDataMetaClass | ?mmPlayerDataMetaClass@@3VMetaClass@@A
    0x708598 | class MetaClass mmPlayerRecordMetaClass | ?mmPlayerRecordMetaClass@@3VMetaClass@@A
*/

#include "infobase.h"

class mmPlayerRecord final : public mmInfoBase
{
public:
    // ??0mmPlayerRecord@@QAE@XZ
    ARTS_IMPORT mmPlayerRecord();

    // ??0mmPlayerRecord@@QAE@ABV0@@Z | inline
    ARTS_IMPORT mmPlayerRecord(const mmPlayerRecord& arg1);

    // ??_EmmPlayerRecord@@UAEPAXI@Z
    // ??_GmmPlayerRecord@@UAEPAXI@Z | unused
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

    // ??_EmmPlayerData@@UAEPAXI@Z
    // ??_GmmPlayerData@@UAEPAXI@Z | unused
    // ??1mmPlayerData@@UAE@XZ | inline
    ARTS_IMPORT ~mmPlayerData() override;

    // ??4mmPlayerData@@QAEXAAV0@@Z | unused
    ARTS_IMPORT void operator=(mmPlayerData& arg1);

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
    ARTS_EXPORT i32 RegisterFinish(i32 arg1, f32 arg2, char arg3);

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
