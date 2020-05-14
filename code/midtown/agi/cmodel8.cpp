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

define_dummy_symbol(agi_cmodel8);

#include "cmodel8.h"

agiColorModel8::agiColorModel8(class agiPalette* arg1)
{
    unimplemented(arg1);
}

agiColorModel8::~agiColorModel8()
{
    unimplemented();
}

u32 agiColorModel8::Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
    return stub<thiscall_t<u32, agiColorModel8*, u32, u32, u32, u32>>(0x55BF50, this, arg1, arg2, arg3, arg4);
}

u32 agiColorModel8::FindColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModel8*, struct agiRgba>>(0x55BF30, this, arg1);
}

u32 agiColorModel8::GetColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModel8*, struct agiRgba>>(0x55BF10, this, arg1);
}

u32 agiColorModel8::GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<u32, agiColorModel8*, class agiSurfaceDesc*, i32, i32>>(0x55C000, this, arg1, arg2, arg3);
}

void agiColorModel8::SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4)
{
    return stub<thiscall_t<void, agiColorModel8*, class agiSurfaceDesc*, i32, i32, u32>>(
        0x55C020, this, arg1, arg2, arg3, arg4);
}
