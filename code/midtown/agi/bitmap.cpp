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

define_dummy_symbol(agi_bitmap);

#include "bitmap.h"

agiBitmap::agiBitmap(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

void agiBitmap::UpdateFlags()
{
    return stub<thiscall_t<void, agiBitmap*>>(0x15A630_Offset, this);
}

char* agiBitmap::GetName()
{
    return stub<thiscall_t<char*, agiBitmap*>>(0x15A6D0_Offset, this);
}

i32 agiBitmap::Init(char* arg1, f32 arg2, f32 arg3, i32 arg4)
{
    return stub<thiscall_t<i32, agiBitmap*, char*, f32, f32, i32>>(0x15A3F0_Offset, this, arg1, arg2, arg3, arg4);
}

void agiBitmap::SetTransparency(i32 arg1)
{
    return stub<thiscall_t<void, agiBitmap*, i32>>(0x15A600_Offset, this, arg1);
}

agiBitmap::~agiBitmap()
{
    unimplemented(arg1);
}
