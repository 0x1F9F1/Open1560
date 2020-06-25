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
    agiworld:texsheet

    0x511B30 | char * __cdecl mystrtok(char *,char const *) | ?mystrtok@@YAPADPADPBD@Z
    0x511B90 | public: void __thiscall agiTexSheet::Load(char *) | ?Load@agiTexSheet@@QAEXPAD@Z
    0x512080 | int __cdecl cmpTex(void const *,void const *) | ?cmpTex@@YAHPBX0@Z
    0x5120A0 | public: void __thiscall agiTexSheet::Kill(void) | ?Kill@agiTexSheet@@QAEXXZ
    0x5120D0 | public: void __thiscall agiTexSheet::Save(char *) | ?Save@agiTexSheet@@QAEXPAD@Z
    0x512340 | public: struct agiTexProp * __thiscall agiTexSheet::Lookup(char *,int) | ?Lookup@agiTexSheet@@QAEPAUagiTexProp@@PADH@Z
    0x5123A0 | public: struct agiTexProp * __thiscall agiTexSheet::LookupAlternate(char *) | ?LookupAlternate@agiTexSheet@@QAEPAUagiTexProp@@PAD@Z
    0x512410 | public: int __thiscall agiTexSheet::GetVariationCount(char *) | ?GetVariationCount@agiTexSheet@@QAEHPAD@Z
    0x512460 | public: char * __thiscall agiTexSheet::RemapName(char *,int) | ?RemapName@agiTexSheet@@QAEPADPADH@Z
    0x5124A0 | public: void __thiscall agiTexSheet::Add(char *) | ?Add@agiTexSheet@@QAEXPAD@Z
    0x73E6C0 | class agiTexSheet TEXSHEET | ?TEXSHEET@@3VagiTexSheet@@A
*/

// 0x511B30 | ?mystrtok@@YAPADPADPBD@Z
ARTS_IMPORT char* mystrtok(char* arg1, char const* arg2);

// 0x73E6C0 | ?TEXSHEET@@3VagiTexSheet@@A
ARTS_IMPORT extern class agiTexSheet TEXSHEET;

class agiTexSheet
{
public:
    // 0x5124A0 | ?Add@agiTexSheet@@QAEXPAD@Z | unused
    ARTS_IMPORT void Add(char* arg1);

    // 0x512410 | ?GetVariationCount@agiTexSheet@@QAEHPAD@Z
    ARTS_IMPORT i32 GetVariationCount(char* arg1);

    // 0x5120A0 | ?Kill@agiTexSheet@@QAEXXZ
    ARTS_IMPORT void Kill();

    // 0x511B90 | ?Load@agiTexSheet@@QAEXPAD@Z
    ARTS_IMPORT void Load(char* arg1);

    // 0x512340 | ?Lookup@agiTexSheet@@QAEPAUagiTexProp@@PADH@Z
    ARTS_IMPORT struct agiTexProp* Lookup(char* arg1, i32 arg2);

    // 0x5123A0 | ?LookupAlternate@agiTexSheet@@QAEPAUagiTexProp@@PAD@Z | unused
    ARTS_IMPORT struct agiTexProp* LookupAlternate(char* arg1);

    // 0x512460 | ?RemapName@agiTexSheet@@QAEPADPADH@Z
    ARTS_IMPORT char* RemapName(char* arg1, i32 arg2);

    // 0x5120D0 | ?Save@agiTexSheet@@QAEXPAD@Z | unused
    ARTS_IMPORT void Save(char* arg1);
};

check_size(agiTexSheet, 0x0);
