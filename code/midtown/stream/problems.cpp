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

define_dummy_symbol(stream_problems);

#include "problems.h"

void DumpProblems()
{
    return stub<cdecl_t<void>>(0x560E10);
}

void InitProblems()
{
    return stub<cdecl_t<void>>(0x560DB0);
}

void RegisterProblem(char* arg1, char* arg2, char* arg3)
{
    return stub<cdecl_t<void, char*, char*, char*>>(0x561100, arg1, arg2, arg3);
}

static i32 cmpProblem(void const* arg1, void const* arg2)
{
    return stub<cdecl_t<i32, void const*, void const*>>(0x561050, arg1, arg2);
}

problem_t::~problem_t()
{
    unimplemented();
}
