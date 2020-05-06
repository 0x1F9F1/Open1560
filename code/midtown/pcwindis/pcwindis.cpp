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

define_dummy_symbol(pcwindis_pcwindis);

#include "pcwindis.h"

i32 __stdcall MasterWindowProc(struct HWND__* arg1, u32 arg2, u32 arg3, i32 arg4)
{
    return stub<stdcall_t<i32, struct HWND__*, u32, u32, i32>>(0x5765F0, arg1, arg2, arg3, arg4);
}

void RegisterMap(char* arg1, u32* arg2, i32 arg3, class Dispatchable* arg4)
{
    return stub<cdecl_t<void, char*, u32*, i32, class Dispatchable*>>(0x576670, arg1, arg2, arg3, arg4);
}

void UnregisterMap(char* arg1)
{
    return stub<cdecl_t<void, char*>>(0x576750, arg1);
}
