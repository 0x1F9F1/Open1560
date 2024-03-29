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
    mmcityinfo:vehlist

    0x4CC080 | public: __thiscall mmVehList::mmVehList(void) | ??0mmVehList@@QAE@XZ
    0x4CC0A0 | public: virtual __thiscall mmVehList::~mmVehList(void) | ??1mmVehList@@UAE@XZ
    0x4CC100 | public: void __thiscall mmVehList::Init(int) | ?Init@mmVehList@@QAEXH@Z
    0x4CC110 | public: class mmVehInfo * __thiscall mmVehList::GetVehicleInfo(int) | ?GetVehicleInfo@mmVehList@@QAEPAVmmVehInfo@@H@Z
    0x4CC140 | public: class mmVehInfo * __thiscall mmVehList::GetVehicleInfo(char *) | ?GetVehicleInfo@mmVehList@@QAEPAVmmVehInfo@@PAD@Z
    0x4CC1C0 | public: int __thiscall mmVehList::GetVehicleID(char *) | ?GetVehicleID@mmVehList@@QAEHPAD@Z
    0x4CC240 | public: void __thiscall mmVehList::Load(char *) | ?Load@mmVehList@@QAEXPAD@Z
    0x4CC370 | public: void __thiscall mmVehList::Print(void) | ?Print@mmVehList@@QAEXXZ
    0x4CC3C0 | public: void __thiscall mmVehList::LoadAll(void) | ?LoadAll@mmVehList@@QAEXXZ
    0x4CC460 | public: virtual void * __thiscall mmVehList::`vector deleting destructor'(unsigned int) | ??_EmmVehList@@UAEPAXI@Z
    0x4CC460 | public: virtual void * __thiscall mmVehList::`scalar deleting destructor'(unsigned int) | ??_GmmVehList@@UAEPAXI@Z
    0x61F8B0 | const mmVehList::`vftable' | ??_7mmVehList@@6B@
    0x7084EC | class mmVehList * VehicleListPtr | ?VehicleListPtr@@3PAVmmVehList@@A
*/

#include "vehinfo.h"

class mmVehList final
{
public:
    // ??0mmVehList@@QAE@XZ
    ARTS_EXPORT mmVehList();

    // ??_GmmVehList@@UAEPAXI@Z
    // ??_EmmVehList@@UAEPAXI@Z
    // ??1mmVehList@@UAE@XZ
    ARTS_EXPORT virtual ~mmVehList();

    // ?GetVehicleID@mmVehList@@QAEHPAD@Z
    ARTS_EXPORT i32 GetVehicleID(char* name);

    // ?GetVehicleInfo@mmVehList@@QAEPAVmmVehInfo@@PAD@Z
    ARTS_EXPORT mmVehInfo* GetVehicleInfo(const char* name);

    // ?GetVehicleInfo@mmVehList@@QAEPAVmmVehInfo@@H@Z
    ARTS_EXPORT mmVehInfo* GetVehicleInfo(i32 index);

    // ?Init@mmVehList@@QAEXH@Z | unused
    ARTS_EXPORT void Init(i32 arg1);

    // ?Load@mmVehList@@QAEXPAD@Z
    ARTS_EXPORT void Load(char* name);

    // ?LoadAll@mmVehList@@QAEXXZ
    ARTS_EXPORT void LoadAll();

    // ?Print@mmVehList@@QAEXXZ | unused
    ARTS_EXPORT void Print();

    void SetDefaultVehicle(const char* name);

    Ptr<mmVehInfo*[]> Vehicles;
    i32 NumVehicles {};
    mmVehInfo* DefaultVehicle {};
};

// check_size(mmVehList, 0xC);

// ?VehicleListPtr@@3PAVmmVehList@@A
ARTS_IMPORT extern mmVehList* VehicleListPtr;

inline mmVehList* VehList()
{
    return VehicleListPtr;
}