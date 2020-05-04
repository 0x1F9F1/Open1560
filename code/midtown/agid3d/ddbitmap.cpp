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

#include "ddbitmap.h"

agiDDBitmap::agiDDBitmap(class agiPipeline* arg1)
{
    unimplemented();
}

agiDDBitmap::~agiDDBitmap()
{
    unimplemented();
}

i32 agiDDBitmap::BeginGfx()
{
    return stub<thiscall_t<i32, agiDDBitmap*>>(0x133A20_Offset, this);
}

void agiDDBitmap::EndGfx()
{
    return stub<thiscall_t<void, agiDDBitmap*>>(0x133CC0_Offset, this);
}

void agiDDBitmap::Restore()
{
    return stub<thiscall_t<void, agiDDBitmap*>>(0x133D50_Offset, this);
}

void agiDDBitmap::UpdateFlags()
{
    return stub<thiscall_t<void, agiDDBitmap*>>(0x133C80_Offset, this);
}

void breakme()
{
    return stub<cdecl_t<void>>(0x133D40_Offset);
}

define_dummy_symbol(agid3d_ddbitmap);
