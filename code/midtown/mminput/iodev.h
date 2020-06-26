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
    mminput:iodev

    0x4E5060 | public: __thiscall mmIODev::mmIODev(void) | ??0mmIODev@@QAE@XZ
    0x4E50A0 | public: virtual __thiscall mmIODev::~mmIODev(void) | ??1mmIODev@@UAE@XZ
    0x4E50B0 | public: void __thiscall mmIODev::Init(int,__int64) | ?Init@mmIODev@@QAEXH_J@Z
    0x4E50E0 | public: void __thiscall mmIODev::Assign(int,int,int) | ?Assign@mmIODev@@QAEXHHH@Z
    0x4E5200 | public: int __thiscall mmIODev::operator==(union eqEvent *) | ??8mmIODev@@QAEHPATeqEvent@@@Z
    0x4E5260 | int __cdecl ConvertDItoString(int,char *,int) | ?ConvertDItoString@@YAHHPADH@Z
    0x4E52C0 | public: void __thiscall mmIODev::GetDescription(char *) | ?GetDescription@mmIODev@@QAEXPAD@Z
    0x4E5580 | public: int __thiscall mmIODev::GetComponentType(int,int) | ?GetComponentType@mmIODev@@QAEHHH@Z
    0x4E55F0 | public: int __thiscall mmIODev::SanityCheckioType(int,int,int) | ?SanityCheckioType@mmIODev@@QAEHHHH@Z
    0x4E5670 | public: void __thiscall mmIODev::Print(int) | ?Print@mmIODev@@QAEXH@Z
    0x4E5740 | public: int __thiscall mmIODev::Write(class Stream *) | ?Write@mmIODev@@QAEHPAVStream@@@Z
    0x4E57A0 | public: int __thiscall mmIODev::WriteBinary(class Stream *) | ?WriteBinary@mmIODev@@QAEHPAVStream@@@Z
    0x4E57F0 | public: int __thiscall mmIODev::Read(class Stream *) | ?Read@mmIODev@@QAEHPAVStream@@@Z
    0x4E5850 | public: int __thiscall mmIODev::ReadBinary(class Stream *) | ?ReadBinary@mmIODev@@QAEHPAVStream@@@Z
    0x4E58A0 | public: static void __cdecl mmIODev::DeclareFields(void) | ?DeclareFields@mmIODev@@SAXXZ
    0x4E5A50 | public: virtual class MetaClass * __thiscall mmIODev::GetClass(void) | ?GetClass@mmIODev@@UAEPAVMetaClass@@XZ
    0x61FCA8 | const mmIODev::`vftable' | ??_7mmIODev@@6B@
    0x719288 | class MetaClass mmIODevMetaClass | ?mmIODevMetaClass@@3VMetaClass@@A
*/

#include "mmcityinfo/infobase.h"

class mmIODev : public mmInfoBase
{
    // const mmIODev::`vftable' @ 0x61FCA8

public:
    // 0x4E5060 | ??0mmIODev@@QAE@XZ
    ARTS_IMPORT mmIODev();

    // 0x4E4AA0 | ??_EmmIODev@@UAEPAXI@Z
    // 0x4E50A0 | ??1mmIODev@@UAE@XZ
    ARTS_IMPORT ~mmIODev() override;

    // 0x4E5200 | ??8mmIODev@@QAEHPATeqEvent@@@Z
    ARTS_IMPORT i32 operator==(union eqEvent* arg1);

    // 0x4E50E0 | ?Assign@mmIODev@@QAEXHHH@Z
    ARTS_IMPORT void Assign(i32 arg1, i32 arg2, i32 arg3);

    // 0x4E5A50 | ?GetClass@mmIODev@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4E5580 | ?GetComponentType@mmIODev@@QAEHHH@Z
    ARTS_IMPORT i32 GetComponentType(i32 arg1, i32 arg2);

    // 0x4E52C0 | ?GetDescription@mmIODev@@QAEXPAD@Z
    ARTS_IMPORT void GetDescription(char* arg1);

    // 0x4E50B0 | ?Init@mmIODev@@QAEXH_J@Z
    ARTS_IMPORT void Init(i32 arg1, i64 arg2);

    // 0x4E5670 | ?Print@mmIODev@@QAEXH@Z
    ARTS_IMPORT void Print(i32 arg1);

    // 0x4E57F0 | ?Read@mmIODev@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 Read(class Stream* arg1);

    // 0x4E5850 | ?ReadBinary@mmIODev@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 ReadBinary(class Stream* arg1);

    // 0x4E55F0 | ?SanityCheckioType@mmIODev@@QAEHHHH@Z
    ARTS_IMPORT i32 SanityCheckioType(i32 arg1, i32 arg2, i32 arg3);

    // 0x4E5740 | ?Write@mmIODev@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 Write(class Stream* arg1);

    // 0x4E57A0 | ?WriteBinary@mmIODev@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 WriteBinary(class Stream* arg1);

    // 0x4E58A0 | ?DeclareFields@mmIODev@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap88[0x20];
};

check_size(mmIODev, 0xA8);

// 0x4E5260 | ?ConvertDItoString@@YAHHPADH@Z
ARTS_IMPORT i32 ConvertDItoString(i32 arg1, char* arg2, i32 arg3);

// 0x719288 | ?mmIODevMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmIODevMetaClass;
