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

#include "infobase.h"

mmInfoBase::mmInfoBase()
{
    unimplemented();
}

mmInfoBase::~mmInfoBase()
{
    unimplemented();
}

class MetaClass* mmInfoBase::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmInfoBase*>>(0xD15D0_Offset, this);
}

i32 mmInfoBase::Load(char* arg1)
{
    return stub<thiscall_t<i32, mmInfoBase*, char*>>(0xD12E0_Offset, this, arg1);
}

i32 mmInfoBase::Save(char* arg1)
{
    return stub<thiscall_t<i32, mmInfoBase*, char*>>(0xD1390_Offset, this, arg1);
}

void mmInfoBase::SetIOPath(char* arg1)
{
    return stub<thiscall_t<void, mmInfoBase*, char*>>(0xD1440_Offset, this, arg1);
}

void mmInfoBase::DeclareFields()
{
    return stub<cdecl_t<void>>(0xD1460_Offset);
}

define_dummy_symbol(mmcityinfo_infobase);
