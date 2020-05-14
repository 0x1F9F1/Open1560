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

define_dummy_symbol(mmcityinfo_vehinfo);

#include "vehinfo.h"

mmVehInfo::mmVehInfo()
{
    unimplemented();
}

mmVehInfo::~mmVehInfo()
{
    unimplemented();
}

i32 mmVehInfo::HasColorVariations()
{
    return stub<thiscall_t<i32, mmVehInfo*>>(0x4D3BE0, this);
}

i32 mmVehInfo::IsValid()
{
    return stub<thiscall_t<i32, mmVehInfo*>>(0x49C590, this);
}

i32 mmVehInfo::Load(char* arg1)
{
    return stub<thiscall_t<i32, mmVehInfo*, char*>>(0x4D3A00, this, arg1);
}

void mmVehInfo::Print()
{
    return stub<thiscall_t<void, mmVehInfo*>>(0x4D3C00, this);
}
