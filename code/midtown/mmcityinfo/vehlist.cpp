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

define_dummy_symbol(mmcityinfo_vehlist);

#include "vehlist.h"

#include "agiworld/texsheet.h"
#include "stream/fsystem.h"

mmVehList::mmVehList()
{
    VehicleListPtr = this;
}

mmVehList::~mmVehList()
{
    for (i32 i = 0; i < NumVehicles; ++i)
        delete Vehicles[i];

    VehicleListPtr = nullptr;
}

i32 mmVehList::GetVehicleID(char* name)
{
    for (i32 i = 0; i < NumVehicles; ++i)
    {
        if (!std::strcmp(name, Vehicles[i]->BaseName))
            return i;
    }

    return -1;
}

mmVehInfo* mmVehList::GetVehicleInfo(const char* name)
{
    for (i32 i = 0; i < NumVehicles; ++i)
    {
        if (mmVehInfo* vehicle = Vehicles[i]; std::strcmp(vehicle->BaseName, name) == 0)
            return vehicle;
    }

    return DefaultVehicle;
}

mmVehInfo* mmVehList::GetVehicleInfo(i32 index)
{
    if (index >= 0 && index < NumVehicles)
        return Vehicles[index];

    Errorf("mmVehList::GetVehicleInfo Illegal id(%d)", index);

    return nullptr;
}

void mmVehList::Init(i32 /*arg1*/)
{
    NumVehicles = 0;
}

void mmVehList::Load(char* name)
{
    Ptr<mmVehInfo> info = MakeUnique<mmVehInfo>();

    if (!info->Load(arts_formatf<64>("tune/%s", name)) || GetVehicleID(info->BaseName) >= 0)
        return;

    Ptr<mmVehInfo*[]> vehicles = MakeUniqueUninit<mmVehInfo*[]>(NumVehicles + 1);

    for (i32 i = 0; i < NumVehicles; ++i)
        vehicles[i] = Vehicles[i];

    vehicles[NumVehicles] = info.release();
    Vehicles.swap(vehicles);
    ++NumVehicles;
}

void mmVehList::LoadAll()
{
    InitTexSheet();

    for (i32 i = 0; i < FileSystem::FSCount; ++i)
    {
        FileSystem* fs = FileSystem::FS[i];

        for (FileInfo* f = fs->FirstEntry("tune"); f; f = fs->NextEntry(f))
        {
            if (const char* ext = std::strrchr(f->Path, '.'); ext && !arts_stricmp(ext, ".INFO"))
                Load(f->Path);
        }
    }

    SetDefaultVehicle("vpbug");
}

void mmVehList::Print()
{
    for (i32 i = 0; i < NumVehicles; ++i)
    {
        Displayf("******VEHICLE # %d", i + 1);
        Vehicles[i]->Print();
        Displayf("");
    }
}

void mmVehList::SetDefaultVehicle(const char* name)
{
    DefaultVehicle = GetVehicleInfo(name);

    ArAssert(DefaultVehicle, "Invalid Default Vehicle");
}

hook_func(INIT_main, [] {
    for (usize addr : {0x403EEC, 0x406B8B})
    {
        create_hook("mmVehList", "Size of mmVehList", addr, alloc_proxy<mmVehList>, hook_type::call);
    }
});
