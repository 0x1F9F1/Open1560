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

define_dummy_symbol(agi_mtldef);

#include "mtldef.h"

agiMtlParameters::agiMtlParameters()
{
    unimplemented();
}

void agiMtlParameters::operator=(class agiMtlParameters const& arg1)
{
    return stub<thiscall_t<void, agiMtlParameters*, class agiMtlParameters const&>>(0x55DBE0, this, arg1);
}

void agiMtlParameters::Load(class Stream* arg1)
{
    return stub<thiscall_t<void, agiMtlParameters*, class Stream*>>(0x55DB00, this, arg1);
}

void agiMtlParameters::Save(class Stream* arg1)
{
    return stub<thiscall_t<void, agiMtlParameters*, class Stream*>>(0x55DB70, this, arg1);
}

char* agiMtlDef::GetName()
{
    return stub<thiscall_t<char*, agiMtlDef*>>(0x55DD30, this);
}

i32 agiMtlDef::Init(class agiMtlParameters const& arg1)
{
    return stub<thiscall_t<i32, agiMtlDef*, class agiMtlParameters const&>>(0x55DC50, this, arg1);
}

agiMtlDef::agiMtlDef(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

agiMtlDef::~agiMtlDef()
{
    unimplemented(arg1);
}
