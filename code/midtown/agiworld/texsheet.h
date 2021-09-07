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

class agiTexSheet;

// ?mystrtok@@YAPADPADPBD@Z
ARTS_IMPORT char* mystrtok(char* str, const char* delims);

// ?TEXSHEET@@3VagiTexSheet@@A
ARTS_IMPORT extern agiTexSheet TEXSHEET;

struct agiTexProp
{
    char* Name {};
    char Palette[4] {};

    // PackShift Levels
    u8 High {};   // agiRQ.TextureQuality  > 1
    u8 Medium {}; // agiRQ.TextureQuality == 1
    u8 Low {};    // agiRQ.TextureQuality == 0

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

    u32 Flags {};

    char* AlternateName {};
    char* Sibling {};
    u16 Width {};
    u16 Height {};
    u32 Color {};
};

check_size(agiTexProp, 0x20);

class agiTexSheet
{
public:
    // ?Add@agiTexSheet@@QAEXPAD@Z | unused
    ARTS_IMPORT void Add(aconst char* arg1);

    // ?GetVariationCount@agiTexSheet@@QAEHPAD@Z
    ARTS_IMPORT i32 GetVariationCount(aconst char* arg1);

    // ?Kill@agiTexSheet@@QAEXXZ
    ARTS_IMPORT void Kill();

    // ?Load@agiTexSheet@@QAEXPAD@Z
    ARTS_IMPORT void Load(aconst char* arg1);

    // ?Lookup@agiTexSheet@@QAEPAUagiTexProp@@PADH@Z
    ARTS_IMPORT agiTexProp* Lookup(aconst char* name, i32 variation = 0);

    // ?LookupAlternate@agiTexSheet@@QAEPAUagiTexProp@@PAD@Z | unused
    ARTS_IMPORT agiTexProp* LookupAlternate(aconst char* arg1);

    // ?RemapName@agiTexSheet@@QAEPADPADH@Z
    ARTS_IMPORT char* RemapName(aconst char* arg1, i32 arg2);

    // ?Save@agiTexSheet@@QAEXPAD@Z | unused
    ARTS_IMPORT void Save(aconst char* arg1);

    i32 GetPropCount() const
    {
        return prop_count_;
    }

private:
    agiTexProp* props_ {};
    i32 prop_count_ {};
    b32 allow_remapping_ {}; // UseAlternate
};

check_size(agiTexSheet, 0xC);

inline void InitTexSheet()
{
    if (!TEXSHEET.GetPropCount())
        TEXSHEET.Load(xconst("mtl/global.tsh"));
}
