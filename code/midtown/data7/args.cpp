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

define_dummy_symbol(data7_args);

#include "args.h"

asArg::asArg(char arg1, char* arg2)
{
    unimplemented(arg1, arg2);
}

void asArg::Print(char* arg1)
{
    return stub<thiscall_t<void, asArg*, char*>>(0x578C80, this, arg1);
}

void ArgSet::ParseArgs(i32 arg1, char** arg2)
{
    return stub<thiscall_t<void, ArgSet*, i32, char**>>(0x578DD0, this, arg1, arg2);
}

void ArgSet::Print(char* arg1)
{
    return stub<thiscall_t<void, ArgSet*, char*>>(0x578D80, this, arg1);
}

void ArgSet::Usage()
{
    return stub<thiscall_t<void, ArgSet*>>(0x579010, this);
}
