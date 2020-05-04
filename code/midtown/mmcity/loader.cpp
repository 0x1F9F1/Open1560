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

#include "loader.h"

mmLoader::mmLoader()
{
    unimplemented();
}

mmLoader::~mmLoader()
{
    unimplemented();
}

void mmLoader::BeginTask(struct LocString* arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmLoader*, struct LocString*, f32>>(0x8B850_Offset, this, arg1, arg2);
}

void mmLoader::Cull()
{
    return stub<thiscall_t<void, mmLoader*>>(0x8BA70_Offset, this);
}

void mmLoader::EndTask(f32 arg1)
{
    return stub<thiscall_t<void, mmLoader*, f32>>(0x8B8D0_Offset, this, arg1);
}

void mmLoader::Init(char* arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmLoader*, char*, f32, f32>>(0x8B720_Offset, this, arg1, arg2, arg3);
}

void mmLoader::Percent(i32 arg1)
{
    return stub<thiscall_t<void, mmLoader*, i32>>(0x8B970_Offset, this, arg1);
}

void mmLoader::Reset()
{
    return stub<thiscall_t<void, mmLoader*>>(0x8B9C0_Offset, this);
}

void mmLoader::SetIntroText(struct LocString* arg1)
{
    return stub<thiscall_t<void, mmLoader*, struct LocString*>>(0x8B820_Offset, this, arg1);
}

void mmLoader::Shutdown()
{
    return stub<thiscall_t<void, mmLoader*>>(0x8B810_Offset, this);
}

void mmLoader::Update()
{
    return stub<thiscall_t<void, mmLoader*>>(0x8B9E0_Offset, this);
}

define_dummy_symbol(mmcity_loader);
