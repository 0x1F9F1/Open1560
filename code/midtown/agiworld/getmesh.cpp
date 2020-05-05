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

define_dummy_symbol(agiworld_getmesh);

#include "getmesh.h"

void FixTexFlags(class agiTexParameters& arg1)
{
    return stub<cdecl_t<void, class agiTexParameters&>>(0x112610_Offset, arg1);
}

class agiMeshSet* GetMeshSet(char* arg1, char* arg2, class Vector3* arg3, i32 arg4)
{
    return stub<cdecl_t<class agiMeshSet*, char*, char*, class Vector3*, i32>>(0x1128A0_Offset, arg1, arg2, arg3, arg4);
}

__cdecl GetMeshSet::N::operator++ ::DLPVertex2::DLPVertex2(char* arg1, char* arg2, class Vector3* arg3, i32 arg4)
{
    unimplemented(arg1, arg2, arg3, arg4);
}

__cdecl GetMeshSet::N::operator++ ::DLPVertex2::DLPVertex2(char* arg1, char* arg2, class Vector3* arg3, i32 arg4)
{
    unimplemented(arg1, arg2, arg3, arg4);
}

__cdecl GetMeshSet::N::operator++ ::nbuf::nbuf(char* arg1, char* arg2, class Vector3* arg3, i32 arg4)
{
    unimplemented(arg1, arg2, arg3, arg4);
}

__cdecl GetMeshSet::N::operator++ ::nbuf::nbuf(char* arg1, char* arg2, class Vector3* arg3, i32 arg4)
{
    unimplemented(arg1, arg2, arg3, arg4);
}
