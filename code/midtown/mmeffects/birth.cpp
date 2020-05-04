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

#include "birth.h"

asBirthRule::asBirthRule()
{
    unimplemented();
}

asBirthRule::~asBirthRule()
{
    unimplemented();
}

void asBirthRule::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asBirthRule*, class Bank*>>(0x100D30_Offset, this, arg1);
}

class MetaClass* asBirthRule::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asBirthRule*>>(0x101620_Offset, this);
}

void asBirthRule::InitSpark(struct asSparkInfo* arg1, struct asSparkPos* arg2)
{
    return stub<thiscall_t<void, asBirthRule*, struct asSparkInfo*, struct asSparkPos*>>(
        0x100AB0_Offset, this, arg1, arg2);
}

void asBirthRule::DeclareFields()
{
    return stub<cdecl_t<void>>(0x1012A0_Offset);
}

define_dummy_symbol(mmeffects_birth);
