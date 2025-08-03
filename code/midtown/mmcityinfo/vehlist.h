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

#include "vehinfo.h"

class mmVehList final
{
public:
    // ??0mmVehList@@QAE@XZ
    ARTS_EXPORT mmVehList();

    // ??1mmVehList@@UAE@XZ
    virtual ~mmVehList();

    // ?GetVehicleID@mmVehList@@QAEHPAD@Z
    ARTS_EXPORT i32 GetVehicleID(char* name);

    // ?GetVehicleInfo@mmVehList@@QAEPAVmmVehInfo@@PAD@Z
    mmVehInfo* GetVehicleInfo(const char* name);

    // ?GetVehicleInfo@mmVehList@@QAEPAVmmVehInfo@@H@Z
    ARTS_EXPORT mmVehInfo* GetVehicleInfo(i32 index);

    // ?Init@mmVehList@@QAEXH@Z | unused
    void Init(i32 arg1);

    // ?Load@mmVehList@@QAEXPAD@Z
    void Load(char* name);

    // ?LoadAll@mmVehList@@QAEXXZ
    ARTS_EXPORT void LoadAll();

    // ?Print@mmVehList@@QAEXXZ | unused
    void Print();

    void SetDefaultVehicle(const char* name);

    Ptr<mmVehInfo*[]> Vehicles;
    i32 NumVehicles {};
    mmVehInfo* DefaultVehicle {};
};

check_size(mmVehList, 0x10);

// ?VehicleListPtr@@3PAVmmVehList@@A
ARTS_IMPORT extern mmVehList* VehicleListPtr;

inline mmVehList* VehList()
{
    return VehicleListPtr;
}