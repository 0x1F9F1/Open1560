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
ARTS_IMPORT char* mystrtok(char* str, char const* delims);

// 0x73E6C0 | ?TEXSHEET@@3VagiTexSheet@@A
ARTS_IMPORT extern class agiTexSheet TEXSHEET;

struct agiTexProp
{
    char* Name {nullptr};
    char Palette[4] {};

    // PackShift Levels
    u8 High {0};   // agiRQ.TextureQuality  > 1
    u8 Medium {0}; // agiRQ.TextureQuality == 1
    u8 Low {0};    // agiRQ.TextureQuality == 0

    enum : u32
    {
        Snowable = 0x1,              // w
        AlphaGlow = 0x2,             // g
        Lightmap = 0x4,              // l
        Shadow = 0x8,                // s
        Transparent = 0x10,          // t
        Chromakey = 0x20,            // k
        NotLit = 0x40,               // n
        DullOrDamaged = 0x80,        // d
        ClampUOrBoth = 0x100,        // u
        ClampVOrBoth = 0x200,        // v
        ClampBoth = 0x400,           // c
        ClampUOrNeither = 0x800,     // U
        ClampVOrNeither = 0x1000,    // V
        RoadFloorCeiling = 0x2000,   // e
        AlwaysModulate = 0x4000,     // m
        AlwaysPerspCorrect = 0x8000, // p

        ClampModeMask = ClampUOrBoth | ClampVOrBoth | ClampBoth | ClampUOrNeither | ClampVOrNeither,
    };

    u32 Flags {0};

    char* AlternateName {nullptr};
    char* Sibling {nullptr};
    u16 Width {0};
    u16 Height {0};
    u32 Color {0};
};

check_size(agiTexProp, 0x20);

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

    i32 GetPropCount() const
    {
        return prop_count_;
    }

private:
    agiTexProp* props_ {nullptr};
    i32 prop_count_ {0};
    b32 allow_remapping_ {false}; // UseAlternate
};

check_size(agiTexSheet, 0xC);
