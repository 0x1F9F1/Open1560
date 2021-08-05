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
    mmcityinfo:vehinfo

    0x4D39D0 | public: __thiscall mmVehInfo::mmVehInfo(void) | ??0mmVehInfo@@QAE@XZ
    0x4D39F0 | public: virtual __thiscall mmVehInfo::~mmVehInfo(void) | ??1mmVehInfo@@UAE@XZ
    0x4D3A00 | public: int __thiscall mmVehInfo::Load(char *) | ?Load@mmVehInfo@@QAEHPAD@Z
    0x4D3BE0 | public: int __thiscall mmVehInfo::HasColorVariations(void) | ?HasColorVariations@mmVehInfo@@QAEHXZ
    0x4D3C00 | public: void __thiscall mmVehInfo::Print(void) | ?Print@mmVehInfo@@QAEXXZ
    0x4D3C90 | public: virtual void * __thiscall mmVehInfo::`scalar deleting destructor'(unsigned int) | ??_GmmVehInfo@@UAEPAXI@Z
    0x4D3C90 | public: virtual void * __thiscall mmVehInfo::`vector deleting destructor'(unsigned int) | ??_EmmVehInfo@@UAEPAXI@Z
    0x61F948 | const mmVehInfo::`vftable' | ??_7mmVehInfo@@6B@
*/

class mmVehInfo final
{
    // const mmVehInfo::`vftable'

public:
    // ??0mmVehInfo@@QAE@XZ
    ARTS_IMPORT mmVehInfo();

    // ??_EmmVehInfo@@UAEPAXI@Z
    // ??_GmmVehInfo@@UAEPAXI@Z
    // ??1mmVehInfo@@UAE@XZ
    ARTS_IMPORT virtual ~mmVehInfo() = default;

    // ?HasColorVariations@mmVehInfo@@QAEHXZ | unused
    ARTS_IMPORT i32 HasColorVariations();

    // ?IsValid@mmVehInfo@@QAEHXZ | inline
    ARTS_IMPORT i32 IsValid();

    // ?Load@mmVehInfo@@QAEHPAD@Z
    ARTS_IMPORT i32 Load(char* arg1);

    // ?Print@mmVehInfo@@QAEXXZ
    ARTS_IMPORT void Print();

    char BaseName[40] {};
    char Description[40] {};
    char field_54[40] {};
    char Colors[80] {};

    i32 Flags {0};
    i32 Order {0};
    b32 Valid {false};
    i32 UnlockScore {0};
    i32 UnlockFlags {0};
    b32 IsLocked {false};
    i32 Horsepower {0};
    i32 TopSpeed {0};
    i32 Durability {0};
    i32 Mass {0};
    f32 ScoringBias {0.0f};
};

check_size(mmVehInfo, 0xF8);
