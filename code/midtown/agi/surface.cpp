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

#include "surface.h"

void agiSurfaceDesc::CopyFrom(class agiSurfaceDesc* arg1, i32 arg2)
{
    return stub<thiscall_t<void, agiSurfaceDesc*, class agiSurfaceDesc*, i32>>(0x15B180_Offset, this, arg1, arg2);
}

void agiSurfaceDesc::Reload(char* arg1, char* arg2, i32 arg3, i32 arg4, class Stream* arg5, i32 arg6, i32 arg7)
{
    return stub<thiscall_t<void, agiSurfaceDesc*, char*, char*, i32, i32, class Stream*, i32, i32>>(
        0x15ADE0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void agiSurfaceDesc::Unload()
{
    return stub<thiscall_t<void, agiSurfaceDesc*>>(0x15B160_Offset, this);
}

class agiSurfaceDesc* agiSurfaceDesc::Init(i32 arg1, i32 arg2, class agiSurfaceDesc& arg3)
{
    return stub<cdecl_t<class agiSurfaceDesc*, i32, i32, class agiSurfaceDesc&>>(0x15A720_Offset, arg1, arg2, arg3);
}

class agiSurfaceDesc* agiSurfaceDesc::Load(char* arg1, char* arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6)
{
    return stub<cdecl_t<class agiSurfaceDesc*, char*, char*, i32, i32, i32, i32>>(
        0x15A7A0_Offset, arg1, arg2, arg3, arg4, arg5, arg6);
}

define_dummy_symbol(agi_surface);
