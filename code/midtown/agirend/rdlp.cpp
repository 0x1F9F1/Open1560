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

define_dummy_symbol(agirend_rdlp);

#include "rdlp.h"

RDLP::RDLP(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

RDLP::~RDLP()
{
    unimplemented();
}

i32 RDLP::BeginGfx()
{
    return stub<thiscall_t<i32, RDLP*>>(0x550C40, this);
}

void RDLP::EndGfx()
{
    return stub<thiscall_t<void, RDLP*>>(0x551200, this);
}

void RDLP::FixROpts(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, RDLP*, i32, i32>>(0x551540, this, arg1, arg2);
}

class DynamicDLP* RDLP::GetDynamic(i32 arg1)
{
    return stub<thiscall_t<class DynamicDLP*, RDLP*, i32>>(0x551490, this, arg1);
}

class MultipassDLP* RDLP::GetMultipass(i32 arg1)
{
    return stub<thiscall_t<class MultipassDLP*, RDLP*, i32>>(0x551530, this, arg1);
}

i32 RDLP::InitFacet(struct agiPatch* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<i32, RDLP*, struct agiPatch*, i32, i32, i32, i32>>(
        0x5508A0, this, arg1, arg2, arg3, arg4, arg5);
}

RDynamicDLP::RDynamicDLP(i32 arg1, class RDLP* arg2)
{
    unimplemented(arg1, arg2);
}

RDynamicDLP::~RDynamicDLP()
{
    unimplemented();
}

i32 RDynamicDLP::Init(char* arg1)
{
    return stub<thiscall_t<i32, RDynamicDLP*, char*>>(0x551360, this, arg1);
}

void RDynamicDLP::Lock()
{
    return stub<thiscall_t<void, RDynamicDLP*>>(0x551440, this);
}

void RDynamicDLP::SetTexture(i16 arg1)
{
    return stub<thiscall_t<void, RDynamicDLP*, i16>>(0x5513B0, this, arg1);
}

void RDynamicDLP::Unlock()
{
    return stub<thiscall_t<void, RDynamicDLP*>>(0x551480, this);
}
