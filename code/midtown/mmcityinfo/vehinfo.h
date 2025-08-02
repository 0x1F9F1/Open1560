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

#define VEH_INFO_FLAG_6_WHEELS 0x1 // Has 6 wheels
#define VEH_INFO_FLAG_TRAILER 0x2  // Has a trailer
#define VEH_INFO_FLAG_FENDERS 0x4  // Has fenders
#define VEH_INFO_FLAG_SIREN 0x8    // Has a siren
#define VEH_INFO_FLAG_LARGE 0x10   // Disable mmStuck, use ind cam indoors
#define VEH_INFO_FLAG_AXLES 0x20   // Has axles (new)

#define VEH_INFO_UNLOCK_BLITZ 0x1      // Pass half of the blitz races
#define VEH_INFO_UNLOCK_CIRCUIT 0x2    // Pass half of the circuit races
#define VEH_INFO_UNLOCK_CHECKPOINT 0x4 // Pass half of the checkpoint races
#define VEH_INFO_UNLOCK_COMPLETE 0x8   // Pass all events
#define VEH_INFO_UNLOCK_PRO 0x10       // Only in professional mode
#define VEH_INFO_UNLOCK_ANY_TWO 0x20   // Pass any two events

class mmVehInfo final
{
public:
    // ??0mmVehInfo@@QAE@XZ
    ARTS_IMPORT mmVehInfo();

    // ??_EmmVehInfo@@UAEPAXI@Z
    // ??_GmmVehInfo@@UAEPAXI@Z
    // ??1mmVehInfo@@UAE@XZ
    ARTS_EXPORT virtual ~mmVehInfo() = default;

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

    i32 Flags {}; // VEH_INFO_FLAG_*
    i32 Order {};
    b32 Valid {};

    // See mmInterface::PlayerResolveCars
    i32 UnlockScore {};
    i32 UnlockFlags {}; // VEH_INFO_UNLOCK_*
    b32 IsLocked {};

    i32 Horsepower {};
    i32 TopSpeed {};
    i32 Durability {};
    i32 Mass {};
    f32 ScoringBias {};
};

check_size(mmVehInfo, 0xF8);
