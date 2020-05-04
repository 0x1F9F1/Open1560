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

#include "cmodel.h"

agiColorModel::~agiColorModel()
{
    unimplemented();
}

u32 agiColorModel::GetColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModel*, struct agiRgba>>(0x - 400000_Offset, this, arg1);
}

u32 agiColorModel::FindColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModel*, struct agiRgba>>(0x - 400000_Offset, this, arg1);
}

u32 agiColorModel::Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
    return stub<thiscall_t<u32, agiColorModel*, u32, u32, u32, u32>>(0x - 400000_Offset, this, arg1, arg2, arg3, arg4);
}

void agiColorModel::SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4)
{
    return stub<thiscall_t<void, agiColorModel*, class agiSurfaceDesc*, i32, i32, u32>>(
        0x - 400000_Offset, this, arg1, arg2, arg3, arg4);
}

u32 agiColorModel::GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<u32, agiColorModel*, class agiSurfaceDesc*, i32, i32>>(
        0x - 400000_Offset, this, arg1, arg2, arg3);
}

u32 agiColorModel::FindColor(i32 arg1, i32 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<u32, agiColorModel*, i32, i32, i32, i32>>(0x15BBB0_Offset, this, arg1, arg2, arg3, arg4);
}

u32 agiColorModel::GetColor(class Vector3 const& arg1)
{
    return stub<thiscall_t<u32, agiColorModel*, class Vector3 const&>>(0x15BBE0_Offset, this, arg1);
}

u32 agiColorModel::GetColor(class Vector4 const& arg1)
{
    return stub<thiscall_t<u32, agiColorModel*, class Vector4 const&>>(0x15BC40_Offset, this, arg1);
}

u32 agiColorModel::GetColor(i32 arg1, i32 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<u32, agiColorModel*, i32, i32, i32, i32>>(0x15BB80_Offset, this, arg1, arg2, arg3, arg4);
}

class agiColorModel* agiColorModel::FindMatch(class agiSurfaceDesc* arg1)
{
    return stub<cdecl_t<class agiColorModel*, class agiSurfaceDesc*>>(0x15D810_Offset, arg1);
}

class agiColorModel* agiColorModel::FindMatch(i32 arg1, i32 arg2, i32 arg3, i32 arg4)
{
    return stub<cdecl_t<class agiColorModel*, i32, i32, i32, i32>>(0x15D760_Offset, arg1, arg2, arg3, arg4);
}

define_dummy_symbol(agi_cmodel);
