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

define_dummy_symbol(agiworld_meshlight);

#include "meshlight.h"

void agiBeginCones()
{
    return stub<cdecl_t<void>>(0x5111E0);
}

void agiConeLighter(u8* arg1, u32* arg2, u32* arg3, class agiMeshSet* arg4)
{
    return stub<cdecl_t<void, u8*, u32*, u32*, class agiMeshSet*>>(0x5112C0, arg1, arg2, arg3, arg4);
}

void agiDeclareCone(
    class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, f32 arg4, f32 arg5, class Vector3& arg6, i32 arg7)
{
    return stub<cdecl_t<void, class Vector3&, class Vector3&, class Vector3&, f32, f32, class Vector3&, i32>>(
        0x5111F0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

void agiDrawCones()
{
    return stub<cdecl_t<void>>(0x5118F0);
}

void agiMeshLighterQuarter(u8* arg1, u32* arg2, u32* arg3, class agiMeshSet* arg4)
{
    return stub<cdecl_t<void, u8*, u32*, u32*, class agiMeshSet*>>(0x510730, arg1, arg2, arg3, arg4);
}

void agiMeshLighterReset()
{
    return stub<cdecl_t<void>>(0x510640);
}

void agiMeshLighterSpecular(u8* arg1, u32* arg2, u32* arg3, class agiMeshSet* arg4)
{
    return stub<cdecl_t<void, u8*, u32*, u32*, class agiMeshSet*>>(0x5119F0, arg1, arg2, arg3, arg4);
}

void agiMeshLighterTriple(u8* arg1, u32* arg2, u32* arg3, class agiMeshSet* arg4)
{
    return stub<cdecl_t<void, u8*, u32*, u32*, class agiMeshSet*>>(0x510AE0, arg1, arg2, arg3, arg4);
}

void agiMeshLighterUpdateColors()
{
    return stub<cdecl_t<void>>(0x5108F0);
}

void agiMeshPrelight(u32* arg1, class agiMeshSet* arg2, class Matrix34& arg3)
{
    return stub<cdecl_t<void, u32*, class agiMeshSet*, class Matrix34&>>(0x511010, arg1, arg2, arg3);
}

static void agiInitCones(class Matrix34& arg1, f32 arg2)
{
    return stub<cdecl_t<void, class Matrix34&, f32>>(0x5116B0, arg1, arg2);
}

static void mmxTriple(u32* arg1, u32* arg2, i32 arg3, u8* arg4, i32 arg5)
{
    return stub<cdecl_t<void, u32*, u32*, i32, u8*, i32>>(0x510EE0, arg1, arg2, arg3, arg4, arg5);
}
