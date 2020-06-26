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
    mmcityinfo:miscdata

    0x4CC490 | public: __thiscall mmMiscData::mmMiscData(void) | ??0mmMiscData@@QAE@XZ
    0x4CC5A0 | public: virtual __thiscall mmMiscData::~mmMiscData(void) | ??1mmMiscData@@UAE@XZ
    0x4CC6A0 | public: int __thiscall mmMiscData::Load(char *) | ?Load@mmMiscData@@QAEHPAD@Z
    0x4CC710 | public: int __thiscall mmMiscData::Save(char *,int) | ?Save@mmMiscData@@QAEHPADH@Z
    0x4CC7A0 | public: int __thiscall mmMiscData::LoadBinary(char *) | ?LoadBinary@mmMiscData@@QAEHPAD@Z
    0x4CC960 | public: int __thiscall mmMiscData::SaveBinary(char *) | ?SaveBinary@mmMiscData@@QAEHPAD@Z
    0x4CCAE0 | public: class mmRecord __thiscall mmMiscData::GetBestRaceTime(int,int) | ?GetBestRaceTime@mmMiscData@@QAE?AVmmRecord@@HH@Z
    0x4CCC10 | public: class mmRecord __thiscall mmMiscData::GetBestBlitzTime(int,int) | ?GetBestBlitzTime@mmMiscData@@QAE?AVmmRecord@@HH@Z
    0x4CCD40 | public: class mmRecord __thiscall mmMiscData::GetBestCircuitTime(int,int) | ?GetBestCircuitTime@mmMiscData@@QAE?AVmmRecord@@HH@Z
    0x4CCE70 | public: class mmRecord __thiscall mmMiscData::GetBestRaceScore(int,int) | ?GetBestRaceScore@mmMiscData@@QAE?AVmmRecord@@HH@Z
    0x4CCFA0 | public: class mmRecord __thiscall mmMiscData::GetBestBlitzScore(int,int) | ?GetBestBlitzScore@mmMiscData@@QAE?AVmmRecord@@HH@Z
    0x4CD0D0 | public: class mmRecord __thiscall mmMiscData::GetBestCircuitScore(int,int) | ?GetBestCircuitScore@mmMiscData@@QAE?AVmmRecord@@HH@Z
    0x4CD200 | public: int __thiscall mmMiscData::CheckCheckpoint(char *,float,int,char *,int,int) | ?CheckCheckpoint@mmMiscData@@QAEHPADMH0HH@Z
    0x4CD3A0 | public: int __thiscall mmMiscData::CheckCircuit(char *,float,int,char *,int,int) | ?CheckCircuit@mmMiscData@@QAEHPADMH0HH@Z
    0x4CD540 | public: int __thiscall mmMiscData::CheckBlitz(char *,float,int,char *,int,int) | ?CheckBlitz@mmMiscData@@QAEHPADMH0HH@Z
    0x4CD6E0 | public: static void __cdecl mmMiscData::DeclareFields(void) | ?DeclareFields@mmMiscData@@SAXXZ
    0x4CD960 | public: virtual class MetaClass * __thiscall mmMiscData::GetClass(void) | ?GetClass@mmMiscData@@UAEPAVMetaClass@@XZ
    0x4CD970 | public: virtual void * __thiscall mmRecord::`scalar deleting destructor'(unsigned int) | ??_GmmRecord@@UAEPAXI@Z
    0x4CD9A0 | public: virtual void * __thiscall mmMiscData::`vector deleting destructor'(unsigned int) | ??_EmmMiscData@@UAEPAXI@Z
    0x61F8B8 | const mmMiscData::`vftable' | ??_7mmMiscData@@6B@
    0x61F8D0 | const mmRecord::`vftable' | ??_7mmRecord@@6B@
    0x7084F8 | class MetaClass mmMiscDataMetaClass | ?mmMiscDataMetaClass@@3VMetaClass@@A
*/

#include "infobase.h"

class mmMiscData : public mmInfoBase
{
    // const mmMiscData::`vftable' @ 0x61F8B8

public:
    // 0x4CC490 | ??0mmMiscData@@QAE@XZ
    ARTS_IMPORT mmMiscData();

    // 0x4CD9A0 | ??_EmmMiscData@@UAEPAXI@Z
    // 0x4CC5A0 | ??1mmMiscData@@UAE@XZ
    ARTS_IMPORT ~mmMiscData() override;

    // 0x4CD540 | ?CheckBlitz@mmMiscData@@QAEHPADMH0HH@Z
    ARTS_IMPORT i32 CheckBlitz(char* arg1, f32 arg2, i32 arg3, char* arg4, i32 arg5, i32 arg6);

    // 0x4CD200 | ?CheckCheckpoint@mmMiscData@@QAEHPADMH0HH@Z
    ARTS_IMPORT i32 CheckCheckpoint(char* arg1, f32 arg2, i32 arg3, char* arg4, i32 arg5, i32 arg6);

    // 0x4CD3A0 | ?CheckCircuit@mmMiscData@@QAEHPADMH0HH@Z
    ARTS_IMPORT i32 CheckCircuit(char* arg1, f32 arg2, i32 arg3, char* arg4, i32 arg5, i32 arg6);

    // 0x4CCFA0 | ?GetBestBlitzScore@mmMiscData@@QAE?AVmmRecord@@HH@Z
    ARTS_IMPORT class mmRecord GetBestBlitzScore(i32 arg1, i32 arg2);

    // 0x4CCC10 | ?GetBestBlitzTime@mmMiscData@@QAE?AVmmRecord@@HH@Z
    ARTS_IMPORT class mmRecord GetBestBlitzTime(i32 arg1, i32 arg2);

    // 0x4CD0D0 | ?GetBestCircuitScore@mmMiscData@@QAE?AVmmRecord@@HH@Z
    ARTS_IMPORT class mmRecord GetBestCircuitScore(i32 arg1, i32 arg2);

    // 0x4CCD40 | ?GetBestCircuitTime@mmMiscData@@QAE?AVmmRecord@@HH@Z
    ARTS_IMPORT class mmRecord GetBestCircuitTime(i32 arg1, i32 arg2);

    // 0x4CCE70 | ?GetBestRaceScore@mmMiscData@@QAE?AVmmRecord@@HH@Z
    ARTS_IMPORT class mmRecord GetBestRaceScore(i32 arg1, i32 arg2);

    // 0x4CCAE0 | ?GetBestRaceTime@mmMiscData@@QAE?AVmmRecord@@HH@Z
    ARTS_IMPORT class mmRecord GetBestRaceTime(i32 arg1, i32 arg2);

    // 0x4CD960 | ?GetClass@mmMiscData@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4CC6A0 | ?Load@mmMiscData@@QAEHPAD@Z
    ARTS_IMPORT i32 Load(char* arg1);

    // 0x4CC7A0 | ?LoadBinary@mmMiscData@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadBinary(char* arg1);

    // 0x4CC710 | ?Save@mmMiscData@@QAEHPADH@Z
    ARTS_IMPORT i32 Save(char* arg1, i32 arg2);

    // 0x4CC960 | ?SaveBinary@mmMiscData@@QAEHPAD@Z
    ARTS_IMPORT i32 SaveBinary(char* arg1);

    // 0x4CD6E0 | ?DeclareFields@mmMiscData@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap88[0x17340];
};

check_size(mmMiscData, 0x173C8);

// 0x7084F8 | ?mmMiscDataMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmMiscDataMetaClass;
