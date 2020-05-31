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

class mmPlayerRecord : public mmInfoBase
{
    // const mmPlayerRecord::`vftable' @ 0x61A608

public:
    // 0x4CFC30 | ??0mmPlayerRecord@@QAE@XZ
    mmPlayerRecord();

    // 0x414A50 | ??0mmPlayerRecord@@QAE@ABV0@@Z | inline
    mmPlayerRecord(class mmPlayerRecord const& arg1);

    // 0x4D11F0 | ??_EmmPlayerRecord@@UAEPAXI@Z
    // 0x414B00 | ??_GmmPlayerRecord@@UAEPAXI@Z | unused
    // 0x4CFC50 | ??1mmPlayerRecord@@UAE@XZ
    ~mmPlayerRecord() override;

    // 0x4CFC90 | ??4mmPlayerRecord@@QAEXAAV0@@Z
    void operator=(class mmPlayerRecord& arg1);

    // 0x4CFCE0 | ?ComputeCRC@mmPlayerRecord@@QAEIXZ
    u32 ComputeCRC();

    // 0x4D0010 | ?GetClass@mmPlayerRecord@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4CFDC0 | ?LoadBinary@mmPlayerRecord@@QAEHPAVStream@@@Z
    i32 LoadBinary(class Stream* arg1);

    // 0x4CFC60 | ?Reset@mmPlayerRecord@@QAEXXZ
    void Reset();

    // 0x4CFD40 | ?SaveBinary@mmPlayerRecord@@QAEHPAVStream@@@Z
    i32 SaveBinary(class Stream* arg1);

    // 0x4CFE40 | ?DeclareFields@mmPlayerRecord@@SAXXZ
    static void DeclareFields();
};

check_size(mmPlayerRecord, 0xE4);

class mmPlayerData : public mmInfoBase
{
    // const mmPlayerData::`vftable' @ 0x61F898

public:
    // 0x4D0020 | ??0mmPlayerData@@QAE@XZ
    mmPlayerData();

    // 0x4D1250 | ??_EmmPlayerData@@UAEPAXI@Z
    // 0x4CBBE0 | ??_GmmPlayerData@@UAEPAXI@Z | unused
    // 0x4CBB40 | ??1mmPlayerData@@UAE@XZ | inline
    ~mmPlayerData() override;

    // 0x4D0140 | ??4mmPlayerData@@QAEXAAV0@@Z | unused
    void operator=(class mmPlayerData& arg1);

    // 0x4D09E0 | ?ComputeCRC@mmPlayerData@@QAEIXZ
    u32 ComputeCRC();

    // 0x4D02B0 | ?GetBlitzMask@mmPlayerData@@QAEHXZ
    i32 GetBlitzMask();

    // 0x4D0340 | ?GetBlitzPassed@mmPlayerData@@QAEHXZ
    i32 GetBlitzPassed();

    // 0x4D02E0 | ?GetCheckpointMask@mmPlayerData@@QAEHXZ
    i32 GetCheckpointMask();

    // 0x4D0360 | ?GetCheckpointPassed@mmPlayerData@@QAEHXZ
    i32 GetCheckpointPassed();

    // 0x4D0290 | ?GetCheckpointProgress@mmPlayerData@@QAEHH@Z
    i32 GetCheckpointProgress(i32 arg1);

    // 0x4D0310 | ?GetCircuitMask@mmPlayerData@@QAEHXZ
    i32 GetCircuitMask();

    // 0x4D0380 | ?GetCircuitPassed@mmPlayerData@@QAEHXZ
    i32 GetCircuitPassed();

    // 0x4D11E0 | ?GetClass@mmPlayerData@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4D0900 | ?GetFileName@mmPlayerData@@QAEPADXZ
    char* GetFileName();

    // 0x4D0860 | ?GetName@mmPlayerData@@QAEPADXZ
    char* GetName();

    // 0x4D08B0 | ?GetNetName@mmPlayerData@@QAEPADXZ
    char* GetNetName();

    // 0x4D03A0 | ?GetTotalPassed@mmPlayerData@@QAEHXZ
    i32 GetTotalPassed();

    // 0x4D03C0 | ?GetTotalScore@mmPlayerData@@QAEHXZ
    i32 GetTotalScore();

    // 0x4D0910 | ?Load@mmPlayerData@@QAEHPAD@Z
    i32 Load(char* arg1);

    // 0x4D0A90 | ?LoadBinary@mmPlayerData@@QAEHPAD@Z
    i32 LoadBinary(char* arg1);

    // 0x4D04A0 | ?RegisterFinish@mmPlayerData@@QAEHVmmPlayerRecord@@HH@Z
    i32 RegisterFinish(class mmPlayerRecord arg1, i32 arg2, i32 arg3);

    // 0x4D0280 | ?RegisterFinish@mmPlayerData@@QAEHHMD@Z | unused
    i32 RegisterFinish(i32 arg1, f32 arg2, char arg3);

    // 0x4D0750 | ?Reset@mmPlayerData@@QAEXXZ
    void Reset();

    // 0x4D0410 | ?ResolveCheckpointProgress@mmPlayerData@@QAEXXZ
    void ResolveCheckpointProgress();

    // 0x4D0940 | ?Save@mmPlayerData@@QAEHPADH@Z
    i32 Save(char* arg1, i32 arg2);

    // 0x4D0CF0 | ?SaveBinary@mmPlayerData@@QAEHPAD@Z
    i32 SaveBinary(char* arg1);

    // 0x4D08C0 | ?SetFileName@mmPlayerData@@QAEXPAD@Z
    void SetFileName(char* arg1);

    // 0x4D0820 | ?SetName@mmPlayerData@@QAEXPAD@Z
    void SetName(char* arg1);

    // 0x4D0870 | ?SetNetName@mmPlayerData@@QAEXPAD@Z
    void SetNetName(char* arg1);

    // 0x4D0F00 | ?DeclareFields@mmPlayerData@@SAXXZ
    static void DeclareFields();
};

check_size(mmPlayerData, 0x2178);

// 0x708570 | ?mmPlayerDataMetaClass@@3VMetaClass@@A
inline extern_var(0x708570, class MetaClass, mmPlayerDataMetaClass);

// 0x708598 | ?mmPlayerRecordMetaClass@@3VMetaClass@@A
inline extern_var(0x708598, class MetaClass, mmPlayerRecordMetaClass);
