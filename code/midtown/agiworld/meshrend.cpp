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

define_dummy_symbol(agiworld_meshrend);

#include "meshrend.h"

u32 EyePlaneOutcode(u8* arg1, u8 arg2, class Vector4& arg3, class Vector3* arg4, i32 arg5)
{
    return stub<cdecl_t<u32, u8*, u8, class Vector4&, class Vector3*, i32>>(0x505990, arg1, arg2, arg3, arg4, arg5);
}

void SetClipMode(i32 arg1)
{
    return stub<cdecl_t<void, i32>>(0x504690, arg1);
}

void __fastcall begin_invert(class Vector4* arg1)
{
    return stub<fastcall_t<void, class Vector4*>>(0x505E00, arg1);
}

void __fastcall end_invert(class Vector4* arg1)
{
    return stub<fastcall_t<void, class Vector4*>>(0x505E10, arg1);
}

static void __fastcall ClipNX(struct CV& arg1, struct CV& arg2)
{
    return stub<fastcall_t<void, struct CV&, struct CV&>>(0x506380, arg1, arg2);
}

static i32 ClipNX(struct CV* arg1, struct CV* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, struct CV*, struct CV*, i32>>(0x506260, arg1, arg2, arg3);
}

static void __fastcall ClipNY(struct CV& arg1, struct CV& arg2)
{
    return stub<fastcall_t<void, struct CV&, struct CV&>>(0x5067A0, arg1, arg2);
}

static i32 ClipNY(struct CV* arg1, struct CV* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, struct CV*, struct CV*, i32>>(0x506680, arg1, arg2, arg3);
}

static void __fastcall ClipNZ(struct CV& arg1, struct CV& arg2)
{
    return stub<fastcall_t<void, struct CV&, struct CV&>>(0x506BB0, arg1, arg2);
}

static i32 ClipNZ(struct CV* arg1, struct CV* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, struct CV*, struct CV*, i32>>(0x506A90, arg1, arg2, arg3);
}

static void __fastcall ClipPX(struct CV& arg1, struct CV& arg2)
{
    return stub<fastcall_t<void, struct CV&, struct CV&>>(0x506590, arg1, arg2);
}

static i32 ClipPX(struct CV* arg1, struct CV* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, struct CV*, struct CV*, i32>>(0x506470, arg1, arg2, arg3);
}

static void __fastcall ClipPY(struct CV& arg1, struct CV& arg2)
{
    return stub<fastcall_t<void, struct CV&, struct CV&>>(0x5069B0, arg1, arg2);
}

static i32 ClipPY(struct CV* arg1, struct CV* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, struct CV*, struct CV*, i32>>(0x506890, arg1, arg2, arg3);
}

static void __fastcall ClipPZ(struct CV& arg1, struct CV& arg2)
{
    return stub<fastcall_t<void, struct CV&, struct CV&>>(0x506DC0, arg1, arg2);
}

static i32 ClipPZ(struct CV* arg1, struct CV* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, struct CV*, struct CV*, i32>>(0x506CA0, arg1, arg2, arg3);
}

static i32 FullClip(struct CV* arg1, struct CV* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, struct CV*, struct CV*, i32>>(0x5061B0, arg1, arg2, arg3);
}

static i32 ZClipOnly(struct CV* arg1, struct CV* arg2, i32 arg3)
{
    return stub<cdecl_t<i32, struct CV*, struct CV*, i32>>(0x506EA0, arg1, arg2, arg3);
}

void agiMeshCardInfo::Init(i32 arg1, struct agiMeshCardVertex* arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, agiMeshCardInfo*, i32, struct agiMeshCardVertex*, i32, i32, i32>>(
        0x50EC90, this, arg1, arg2, arg3, arg4, arg5);
}

void agiPolySet::Triangle(i32 arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, agiPolySet*, i32, i32, i32>>(0x510480, this, arg1, arg2, arg3);
}
