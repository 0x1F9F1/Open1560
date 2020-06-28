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
    mmcityinfo:racerecord

    0x4D1640 | public: __thiscall mmRecord::mmRecord(void) | ??0mmRecord@@QAE@XZ
    0x4D1680 | public: virtual __thiscall mmRecord::~mmRecord(void) | ??1mmRecord@@UAE@XZ
    0x4D1690 | public: float __thiscall mmRecord::GetTime(void) | ?GetTime@mmRecord@@QAEMXZ
    0x4D16A0 | public: char * __thiscall mmRecord::GetCarName(void) | ?GetCarName@mmRecord@@QAEPADXZ
    0x4D16B0 | public: char * __thiscall mmRecord::GetName(void) | ?GetName@mmRecord@@QAEPADXZ
    0x4D16C0 | public: int __thiscall mmRecord::GetPassed(void) | ?GetPassed@mmRecord@@QAEHXZ
    0x4D16D0 | public: int __thiscall mmRecord::GetScore(void) | ?GetScore@mmRecord@@QAEHXZ
    0x4D16E0 | public: void __thiscall mmRecord::SetTime(float) | ?SetTime@mmRecord@@QAEXM@Z
    0x4D16F0 | public: void __thiscall mmRecord::SetCarName(char *) | ?SetCarName@mmRecord@@QAEXPAD@Z
    0x4D1710 | public: void __thiscall mmRecord::SetName(char *) | ?SetName@mmRecord@@QAEXPAD@Z
    0x4D1750 | public: void __thiscall mmRecord::SetPassed(int) | ?SetPassed@mmRecord@@QAEXH@Z
    0x4D1770 | public: void __thiscall mmRecord::SetScore(int) | ?SetScore@mmRecord@@QAEXH@Z
    0x4D1780 | public: void __thiscall mmRecord::operator=(class mmRecord &) | ??4mmRecord@@QAEXAAV0@@Z
    0x4D1810 | public: int __thiscall mmRecord::SaveBinary(class Stream *) | ?SaveBinary@mmRecord@@QAEHPAVStream@@@Z
    0x4D1890 | public: int __thiscall mmRecord::LoadBinary(class Stream *) | ?LoadBinary@mmRecord@@QAEHPAVStream@@@Z
    0x4D1910 | public: unsigned int __thiscall mmRecord::ComputeCRC(void) | ?ComputeCRC@mmRecord@@QAEIXZ
    0x4D1970 | public: static void __cdecl mmRecord::DeclareFields(void) | ?DeclareFields@mmRecord@@SAXXZ
    0x4D1B50 | public: virtual class MetaClass * __thiscall mmRecord::GetClass(void) | ?GetClass@mmRecord@@UAEPAVMetaClass@@XZ
    0x4D1B60 | public: virtual void * __thiscall mmRecord::`vector deleting destructor'(unsigned int) | ??_EmmRecord@@UAEPAXI@Z
    0x7085F0 | class MetaClass mmRecordMetaClass | ?mmRecordMetaClass@@3VMetaClass@@A
*/

#include "infobase.h"

class mmRecord : public mmInfoBase
{
    // const mmRecord::`vftable' @ 0x61F8D0

public:
    // 0x4D1640 | ??0mmRecord@@QAE@XZ
    ARTS_IMPORT mmRecord();

    // 0x4D1B60 | ??_EmmRecord@@UAEPAXI@Z
    // 0x4CD970 | ??_GmmRecord@@UAEPAXI@Z | unused
    // 0x4D1680 | ??1mmRecord@@UAE@XZ
    ARTS_IMPORT ~mmRecord() override = default;

    // 0x4D1780 | ??4mmRecord@@QAEXAAV0@@Z
    ARTS_IMPORT void operator=(class mmRecord& arg1);

    // 0x4D1910 | ?ComputeCRC@mmRecord@@QAEIXZ
    ARTS_IMPORT u32 ComputeCRC();

    // 0x4D16A0 | ?GetCarName@mmRecord@@QAEPADXZ
    ARTS_IMPORT char* GetCarName();

    // 0x4D1B50 | ?GetClass@mmRecord@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4D16B0 | ?GetName@mmRecord@@QAEPADXZ
    ARTS_IMPORT char* GetName();

    // 0x4D16C0 | ?GetPassed@mmRecord@@QAEHXZ | unused
    ARTS_IMPORT i32 GetPassed();

    // 0x4D16D0 | ?GetScore@mmRecord@@QAEHXZ
    ARTS_IMPORT i32 GetScore();

    // 0x4D1690 | ?GetTime@mmRecord@@QAEMXZ
    ARTS_IMPORT f32 GetTime();

    // 0x4D1890 | ?LoadBinary@mmRecord@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 LoadBinary(class Stream* arg1);

    // 0x4D1810 | ?SaveBinary@mmRecord@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 SaveBinary(class Stream* arg1);

    // 0x4D16F0 | ?SetCarName@mmRecord@@QAEXPAD@Z
    ARTS_IMPORT void SetCarName(char* arg1);

    // 0x4D1710 | ?SetName@mmRecord@@QAEXPAD@Z
    ARTS_IMPORT void SetName(char* arg1);

    // 0x4D1750 | ?SetPassed@mmRecord@@QAEXH@Z
    ARTS_IMPORT void SetPassed(i32 arg1);

    // 0x4D1770 | ?SetScore@mmRecord@@QAEXH@Z
    ARTS_IMPORT void SetScore(i32 arg1);

    // 0x4D16E0 | ?SetTime@mmRecord@@QAEXM@Z
    ARTS_IMPORT void SetTime(f32 arg1);

    // 0x4D1970 | ?DeclareFields@mmRecord@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap88[0x80];
};

check_size(mmRecord, 0x108);

// 0x7085F0 | ?mmRecordMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmRecordMetaClass;
