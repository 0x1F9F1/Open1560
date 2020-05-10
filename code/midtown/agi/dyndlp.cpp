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

define_dummy_symbol(agi_dyndlp);

#include "dyndlp.h"

DynamicDLP::DynamicDLP(i32 arg1)
{
    unimplemented(arg1);
}

DynamicDLP::~DynamicDLP()
{
    unimplemented(arg1);
}

i32 DynamicDLP::InitOffsets(class DLP* arg1, char* arg2)
{
    return stub<thiscall_t<i32, DynamicDLP*, class DLP*, char*>>(0x55E620, this, arg1, arg2);
}

i32 DynamicDLP::Release()
{
    return stub<thiscall_t<i32, DynamicDLP*>>(0x55E600, this);
}
