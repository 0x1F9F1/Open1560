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
    mmcityinfo:cityinfo

    0x4D3620 | public: __thiscall mmCityInfo::mmCityInfo(void) | ??0mmCityInfo@@QAE@XZ
    0x4D3640 | public: virtual __thiscall mmCityInfo::~mmCityInfo(void) | ??1mmCityInfo@@UAE@XZ
    0x4D3650 | public: int __thiscall mmCityInfo::Load(char *) | ?Load@mmCityInfo@@QAEHPAD@Z
    0x4D39A0 | public: virtual void * __thiscall mmCityInfo::`scalar deleting destructor'(unsigned int) | ??_GmmCityInfo@@UAEPAXI@Z
    0x4D39A0 | public: virtual void * __thiscall mmCityInfo::`vector deleting destructor'(unsigned int) | ??_EmmCityInfo@@UAEPAXI@Z
    0x61F944 | const mmCityInfo::`vftable' | ??_7mmCityInfo@@6B@
*/

class mmCityInfo final
{
public:
    // ??0mmCityInfo@@QAE@XZ
    ARTS_EXPORT mmCityInfo();

    // ??_EmmCityInfo@@UAEPAXI@Z
    // ??_GmmCityInfo@@UAEPAXI@Z
    // ??1mmCityInfo@@UAE@XZ
    ARTS_EXPORT virtual ~mmCityInfo();

    // ?Load@mmCityInfo@@QAEHPAD@Z
    ARTS_IMPORT b32 Load(char* path);

    char LocalizedName[40];
    char MapName[40];
    char RaceDir[40];
    ConstString BlitzNames;
    ConstString CheckpointNames;
    ConstString CircuitNames;
    b32 Loaded {};
    i32 BlitzCount {};
    i32 CheckpointCount {};
    i32 CircuitCount {};
    i32 field_98 {};
    i32 field_9C {};
};

check_size(mmCityInfo, 0xA0);
