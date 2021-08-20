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

union eqEvent;

class mmIODev final : public mmInfoBase
{
public:
    // ??0mmIODev@@QAE@XZ
    ARTS_IMPORT mmIODev();

    // ??_EmmIODev@@UAEPAXI@Z
    // ??1mmIODev@@UAE@XZ
    ARTS_IMPORT ~mmIODev() override = default;

    // ??8mmIODev@@QAEHPATeqEvent@@@Z
    ARTS_IMPORT i32 operator==(eqEvent* arg1);

    // ?Assign@mmIODev@@QAEXHHH@Z
    ARTS_IMPORT void Assign(i32 arg1, i32 arg2, i32 arg3);

    // ?GetClass@mmIODev@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetComponentType@mmIODev@@QAEHHH@Z
    ARTS_EXPORT i32 GetComponentType(i32 device, i32 component);

    // ?GetDescription@mmIODev@@QAEXPAD@Z
    [[deprecated]] ARTS_EXPORT void GetDescription(char* buffer);

    void GetDescription(char* buffer, usize buflen);

    // ?Init@mmIODev@@QAEXH_J@Z
    ARTS_IMPORT void Init(i32 arg1, i64 arg2);

    // ?Print@mmIODev@@QAEXH@Z
    ARTS_IMPORT void Print(i32 arg1);

    // ?Read@mmIODev@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 Read(Stream* arg1);

    // ?ReadBinary@mmIODev@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 ReadBinary(Stream* arg1);

    // ?SanityCheckioType@mmIODev@@QAEHHHH@Z
    ARTS_IMPORT i32 SanityCheckioType(i32 arg1, i32 arg2, i32 arg3);

    // ?Write@mmIODev@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 Write(Stream* arg1);

    // ?WriteBinary@mmIODev@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 WriteBinary(Stream* arg1);

    // ?DeclareFields@mmIODev@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    i32 IoType; // ioType
    u32 dword8C;
    i64 IoidBits;
    i32 Device;    // mmIODevice
    i32 Component; // mmJoyInput
    u64 State;
};

check_size(mmIODev, 0xA8);

// ?ConvertDItoString@@YAHHPADH@Z
ARTS_EXPORT b32 ConvertDItoString(i32 vsc, char* buffer, i32 buflen);
