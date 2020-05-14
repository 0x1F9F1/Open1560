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

define_dummy_symbol(mmbangers_data);

#include "data.h"

mmBangerData::mmBangerData()
{
    unimplemented();
}

mmBangerData::~mmBangerData()
{
    unimplemented();
}

void mmBangerData::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmBangerData*, class Bank*>>(0x4C85E0, this, arg1);
}

i32 mmBangerData::Bootstrap(char* arg1, char* arg2)
{
    return stub<thiscall_t<i32, mmBangerData*, char*, char*>>(0x4C8E70, this, arg1, arg2);
}

void mmBangerData::BootstrapBreakablesOnly(char* arg1)
{
    return stub<thiscall_t<void, mmBangerData*, char*>>(0x4C8ED0, this, arg1);
}

void mmBangerData::ComputeYRadius(char* arg1)
{
    return stub<thiscall_t<void, mmBangerData*, char*>>(0x4C93D0, this, arg1);
}

class MetaClass* mmBangerData::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmBangerData*>>(0x4C98C0, this);
}

void mmBangerData::InitBreakables(char* arg1)
{
    return stub<thiscall_t<void, mmBangerData*, char*>>(0x4C8F10, this, arg1);
}

i32 mmBangerData::InitPhysics(char* arg1, char* arg2)
{
    return stub<thiscall_t<i32, mmBangerData*, char*, char*>>(0x4C9150, this, arg1, arg2);
}

void mmBangerData::LaunchInstance(f32 arg1, class Vector3* arg2)
{
    return stub<thiscall_t<void, mmBangerData*, f32, class Vector3*>>(0x4C8370, this, arg1, arg2);
}

i32 mmBangerData::LoadEntry(char* arg1)
{
    return stub<thiscall_t<i32, mmBangerData*, char*>>(0x4C81B0, this, arg1);
}

void mmBangerData::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4C9540);
}

mmBangerDataManager::mmBangerDataManager()
{
    unimplemented();
}

mmBangerDataManager::~mmBangerDataManager()
{
    unimplemented();
}

i32 mmBangerDataManager::AddBangerDataEntry(char* arg1, char* arg2)
{
    return stub<thiscall_t<i32, mmBangerDataManager*, char*, char*>>(0x4C8C10, this, arg1, arg2);
}

void mmBangerDataManager::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmBangerDataManager*, class Bank*>>(0x4C8550, this, arg1);
}

class MetaClass* mmBangerDataManager::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmBangerDataManager*>>(0x4C9A40, this);
}

void mmBangerDataManager::Save()
{
    return stub<thiscall_t<void, mmBangerDataManager*>>(0x4C9510, this);
}

void mmBangerDataManager::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4C98D0);
}

struct MetaType* RefTo(struct MetaType* arg1, i32 arg2, i16* arg3)
{
    return stub<cdecl_t<struct MetaType*, struct MetaType*, i32, i16*>>(0x4C9A50, arg1, arg2, arg3);
}
