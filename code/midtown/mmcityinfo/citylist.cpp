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

define_dummy_symbol(mmcityinfo_citylist);

#include "citylist.h"
#include "cityinfo.h"

#include "agiworld/texsheet.h"
#include "stream/fsystem.h"

mmCityList::mmCityList()
{
    CityListPtr = this;
}

mmCityList::~mmCityList()
{
    for (i32 i = 0; i < NumCities; ++i)
        delete Cities[i];

    CityListPtr = nullptr;
}

i32 mmCityList::GetCityID(char* name)
{
    for (i32 i = 0; i < NumCities; ++i)
    {
        if (!std::strcmp(name, Cities[i]->RaceDir))
            return i;
    }

    return -1;
}

mmCityInfo* mmCityList::GetCityInfo(char* name)
{
    for (i32 i = 0; i < NumCities; ++i)
    {
        if (!std::strcmp(name, Cities[i]->RaceDir))
            return Cities[i];
    }

    return nullptr;
}

mmCityInfo* mmCityList::GetCityInfo(i32 index)
{
    if (index >= 0 && index < NumCities)
        return Cities[index];

    Errorf("mmCityList::GetCityInfo Illegal id(%d)", index);

    return nullptr;
}

mmCityInfo* mmCityList::GetCurrentCity()
{
    return Cities[CurrentCity];
}

void mmCityList::Init(i32 /*arg1*/)
{
    NumCities = 0;
}

void mmCityList::Load(char* name)
{
    char path[64];
    arts_sprintf(path, "tune/%s", name);

    Ptr<mmCityInfo> info = MakeUnique<mmCityInfo>();

    if (!info->Load(path) || GetCityID(info->RaceDir) >= 0)
        return;

    Ptr<mmCityInfo*[]> cities = MakeUniqueUninit<mmCityInfo*[]>(NumCities + 1);

    for (i32 i = 0; i < NumCities; ++i)
        cities[i] = Cities[i];

    cities[NumCities] = info.release();
    Cities.swap(cities);
    ++NumCities;
}

void mmCityList::LoadAll()
{
    if (!TEXSHEET.GetPropCount())
        TEXSHEET.Load(const_cast<char*>("mtl/global.tsh"));

    Load(const_cast<char*>("Chicago.cinfo")); // Load Chicago first

    for (i32 i = 0; i < FileSystem::FSCount; ++i)
    {
        FileSystem* fs = FileSystem::FS[i];

        for (FileInfo* f = fs->FirstEntry("tune"); f; f = fs->NextEntry(f))
        {
            if (const char* ext = std::strrchr(f->Path, '.'); ext && !arts_stricmp(ext, ".CINFO"))
                Load(f->Path);
        }
    }
}

void mmCityList::Print()
{
    for (i32 i = 0; i < NumCities; ++i)
        Displayf("******City # %d: %s", i + 1, Cities[i]->RaceDir);
}

void mmCityList::SetCurrentCity(char* name)
{
    CurrentCity = GetCityID(name);
}

void mmCityList::SetCurrentCity(i32 index)
{
    CurrentCity = std::clamp(index, 0, NumCities - 1);
}
