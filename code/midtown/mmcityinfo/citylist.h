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

#include "cityinfo.h"

class mmCityList final
{
public:
    // ??0mmCityList@@QAE@XZ
    ARTS_EXPORT mmCityList();

    // ??1mmCityList@@UAE@XZ
    virtual ~mmCityList();

    // ?GetCityID@mmCityList@@QAEHPAD@Z
    ARTS_EXPORT i32 GetCityID(aconst char* name);

    // ?GetCityInfo@mmCityList@@QAEPAVmmCityInfo@@PAD@Z
    ARTS_EXPORT mmCityInfo* GetCityInfo(aconst char* name);

    // ?GetCityInfo@mmCityList@@QAEPAVmmCityInfo@@H@Z
    ARTS_EXPORT mmCityInfo* GetCityInfo(i32 index);

    // ?GetCurrentCity@mmCityList@@QAEPAVmmCityInfo@@XZ
    ARTS_EXPORT mmCityInfo* GetCurrentCity();

    // ?Init@mmCityList@@QAEXH@Z | unused
    void Init(i32 arg1);

    // ?Load@mmCityList@@QAEXPAD@Z
    void Load(aconst char* name);

    // ?LoadAll@mmCityList@@QAEXXZ
    ARTS_EXPORT void LoadAll();

    // ?Print@mmCityList@@QAEXXZ | unused
    void Print();

    // ?SetCurrentCity@mmCityList@@QAEXPAD@Z
    ARTS_EXPORT void SetCurrentCity(aconst char* name);

    // ?SetCurrentCity@mmCityList@@QAEXH@Z
    ARTS_EXPORT void SetCurrentCity(i32 index);

    Ptr<mmCityInfo*[]> Cities;
    i32 NumCities {};
    i32 CurrentCity {};
};

check_size(mmCityList, 0x10);

// ?CityListPtr@@3PAVmmCityList@@A
ARTS_IMPORT extern mmCityList* CityListPtr;

extern const char* DEFAULT_CITY;

inline mmCityList* CityList()
{
    return CityListPtr;
}

inline mmCityInfo* DefaultCityInfo()
{
    return CityList()->GetCityInfo(const_cast<char*>(DEFAULT_CITY));
}
