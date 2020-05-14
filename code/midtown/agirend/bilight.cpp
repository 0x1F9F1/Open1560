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

define_dummy_symbol(agirend_bilight);

#include "bilight.h"

agiBILight::agiBILight(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

agiBILight::~agiBILight()
{
    unimplemented();
}

i32 agiBILight::BeginGfx()
{
    return stub<thiscall_t<i32, agiBILight*>>(0x5553E0, this);
}

void agiBILight::EndGfx()
{
    return stub<thiscall_t<void, agiBILight*>>(0x555400, this);
}

void agiBILight::Remove()
{
    return stub<thiscall_t<void, agiBILight*>>(0x555420, this);
}

i32 agiBILight::Update()
{
    return stub<thiscall_t<i32, agiBILight*>>(0x555410, this);
}
