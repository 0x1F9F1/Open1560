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

#include "lmodel.h"

agiLightModelParameters::agiLightModelParameters()
{
    unimplemented();
}

agiLightModelParameters::~agiLightModelParameters()
{
    unimplemented();
}

void agiLightModelParameters::operator=(class agiLightModelParameters const& arg1)
{
    return stub<thiscall_t<void, agiLightModelParameters*, class agiLightModelParameters const&>>(
        0x15BCD0_Offset, this, arg1);
}

agiLightModel::~agiLightModel()
{
    unimplemented();
}

i32 agiLightModel::Activate()
{
    return stub<thiscall_t<i32, agiLightModel*>>(0x - 400000_Offset, this);
}

char* agiLightModel::GetName()
{
    return stub<thiscall_t<char*, agiLightModel*>>(0x15BDD0_Offset, this);
}

i32 agiLightModel::Init(class agiLightModelParameters const& arg1)
{
    return stub<thiscall_t<i32, agiLightModel*, class agiLightModelParameters const&>>(0x15BD50_Offset, this, arg1);
}

agiLightModel::agiLightModel(class agiPipeline* arg1)
{
    unimplemented();
}

define_dummy_symbol(agi_lmodel);
