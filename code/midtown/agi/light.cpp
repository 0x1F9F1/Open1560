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

define_dummy_symbol(agi_light);

#include "light.h"

agiLightParameters::agiLightParameters()
{
    unimplemented();
}

void agiLightParameters::operator=(class agiLightParameters const& arg1)
{
    return stub<thiscall_t<void, agiLightParameters*, class agiLightParameters const&>>(0x55BA60, this, arg1);
}

agiLight::agiLight(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

agiLight::~agiLight()
{
    unimplemented(arg1);
}

i32 agiLight::Update()
{
    return stub<thiscall_t<i32, agiLight*>>(0x - 400000_Offset, this);
}

void agiLight::Remove()
{
    return stub<thiscall_t<void, agiLight*>>(0x55BB00, this);
}

char* agiLight::GetName()
{
    return stub<thiscall_t<char*, agiLight*>>(0x55BB20, this);
}

i32 agiLight::Init(class agiLightParameters const& arg1)
{
    return stub<thiscall_t<i32, agiLight*, class agiLightParameters const&>>(0x55BAD0, this, arg1);
}
