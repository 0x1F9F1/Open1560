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

#include "bilmodel.h"

agiBILightModel::agiBILightModel(class agiPipeline* arg1)
{
    unimplemented();
}

agiBILightModel::~agiBILightModel()
{
    unimplemented();
}

i32 agiBILightModel::Activate()
{
    return stub<thiscall_t<i32, agiBILightModel*>>(0x155320_Offset, this);
}

i32 agiBILightModel::BeginGfx()
{
    return stub<thiscall_t<i32, agiBILightModel*>>(0x1552E0_Offset, this);
}

void agiBILightModel::EndGfx()
{
    return stub<thiscall_t<void, agiBILightModel*>>(0x155310_Offset, this);
}

define_dummy_symbol(agirend_bilmodel);
