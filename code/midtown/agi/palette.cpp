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

#include "palette.h"

agiPalette::agiPalette()
{
    unimplemented();
}

void agiPalette::Cube()
{
    return stub<thiscall_t<void, agiPalette*>>(0x15C0F0_Offset, this);
}

u32 agiPalette::FindColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiPalette*, struct agiRgba>>(0x15C3A0_Offset, this, arg1);
}

u32 agiPalette::GetColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiPalette*, struct agiRgba>>(0x15C310_Offset, this, arg1);
}

void agiPalette::Kill()
{
    return stub<thiscall_t<void, agiPalette*>>(0x15C0B0_Offset, this);
}

void agiPalette::Load(char* arg1)
{
    return stub<thiscall_t<void, agiPalette*, char*>>(0x15C180_Offset, this, arg1);
}

define_dummy_symbol(agi_palette);
