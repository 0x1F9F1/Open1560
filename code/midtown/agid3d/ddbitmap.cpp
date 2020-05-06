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

define_dummy_symbol(agid3d_ddbitmap);

#include "ddbitmap.h"

agiDDBitmap::agiDDBitmap(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

agiDDBitmap::~agiDDBitmap()
{
    unimplemented(arg1);
}

i32 agiDDBitmap::BeginGfx()
{
    return stub<thiscall_t<i32, agiDDBitmap*>>(0x533A20, this);
}

void agiDDBitmap::EndGfx()
{
    return stub<thiscall_t<void, agiDDBitmap*>>(0x533CC0, this);
}

void agiDDBitmap::Restore()
{
    return stub<thiscall_t<void, agiDDBitmap*>>(0x533D50, this);
}

void agiDDBitmap::UpdateFlags()
{
    return stub<thiscall_t<void, agiDDBitmap*>>(0x533C80, this);
}

void breakme()
{
    return stub<cdecl_t<void>>(0x533D40);
}
