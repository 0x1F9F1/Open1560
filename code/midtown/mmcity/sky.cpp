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

#include "sky.h"

mmSky::mmSky()
{
    unimplemented();
}

mmSky::~mmSky()
{
    unimplemented();
}

void mmSky::Draw(class Matrix34& arg1)
{
    return stub<thiscall_t<void, mmSky*, class Matrix34&>>(0x956A0_Offset, this, arg1);
}

void mmSky::Init(char* arg1)
{
    return stub<thiscall_t<void, mmSky*, char*>>(0x95650_Offset, this, arg1);
}

void mmSky::SetTexture(class agiTexDef* arg1)
{
    return stub<thiscall_t<void, mmSky*, class agiTexDef*>>(0x95680_Offset, this, arg1);
}

define_dummy_symbol(mmcity_sky);
