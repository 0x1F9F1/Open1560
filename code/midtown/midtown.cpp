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

#include "midtown.h"

void Application(i32 arg1, char** arg2)
{
    return stub<cdecl_t<void, i32, char**>>(0x30C0_Offset, arg1, arg2);
}

void ApplicationHelper(i32 arg1, char** arg2)
{
    return stub<cdecl_t<void, i32, char**>>(0x1830_Offset, arg1, arg2);
}

class agiPipeline* CreatePipeline(i32 arg1, char** arg2)
{
    return stub<cdecl_t<class agiPipeline*, i32, char**>>(0x10B0_Offset, arg1, arg2);
}

i32 GameFilter(struct _EXCEPTION_POINTERS* arg1)
{
    return stub<cdecl_t<i32, struct _EXCEPTION_POINTERS*>>(0x14B0_Offset, arg1);
}

void GameLoop(class mmInterface* arg1, class mmGameManager* arg2, char* arg3)
{
    return stub<cdecl_t<void, class mmInterface*, class mmGameManager*, char*>>(0x15A0_Offset, arg1, arg2, arg3);
}

i32 GenerateLoadScreenName()
{
    return stub<cdecl_t<i32>>(0x12D0_Offset);
}

void InitAudioManager()
{
    return stub<cdecl_t<void>>(0x2F40_Offset);
}

define_dummy_symbol(midtown);
