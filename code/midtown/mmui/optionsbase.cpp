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

define_dummy_symbol(mmui_optionsbase);

#include "optionsbase.h"

OptionsBase::OptionsBase(i32 arg1)
{
    unimplemented(arg1);
}

OptionsBase::~OptionsBase()
{
    unimplemented();
}

void OptionsBase::ResetDefaultAction()
{
    return stub<thiscall_t<void, OptionsBase*>>(0x4AB6F0, this);
}

void OptionsBase::StoreCurrentSetup()
{
    return stub<thiscall_t<void, OptionsBase*>>(0x49A6D0, this);
}

void OptionsBase::CreateTitle(struct LocString* arg1)
{
    return stub<thiscall_t<void, OptionsBase*, struct LocString*>>(0x4AB620, this, arg1);
}

i32 OptionsBase::IsAnOptionMenu()
{
    return stub<thiscall_t<i32, OptionsBase*>>(0x49A6E0, this);
}
