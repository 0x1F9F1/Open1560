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

define_dummy_symbol(agi_dlp);

#include "dlp.h"

DLP::DLP(class agiPipeline* arg1)
{
    unimplemented(arg1);
}

DLP::~DLP()
{
    unimplemented(arg1);
}

void DLP::Cull(i32 arg1)
{
    return stub<thiscall_t<void, DLP*, i32>>(0x15E490_Offset, this, arg1);
}

void DLP::FixROpts(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, DLP*, i32, i32>>(0x15E530_Offset, this, arg1, arg2);
}

class DynamicDLP* DLP::GetDynamic(i32 arg1)
{
    return stub<thiscall_t<class DynamicDLP*, DLP*, i32>>(0x - 400000_Offset, this, arg1);
}

class MultipassDLP* DLP::GetMultipass(i32 arg1)
{
    return stub<thiscall_t<class MultipassDLP*, DLP*, i32>>(0x - 400000_Offset, this, arg1);
}

i32 DLP::BeginGfx()
{
    return stub<thiscall_t<i32, DLP*>>(0x15E0D0_Offset, this);
}

class DLP* DLP::Clone()
{
    return stub<thiscall_t<class DLP*, DLP*>>(0x15E460_Offset, this);
}

void DLP::EndGfx()
{
    return stub<thiscall_t<void, DLP*>>(0x15E2F0_Offset, this);
}

char* DLP::GetName()
{
    return stub<thiscall_t<char*, DLP*>>(0x15E4F0_Offset, this);
}

i32 DLP::Init(char* arg1, char* arg2, class Vector3* arg3)
{
    return stub<thiscall_t<i32, DLP*, char*, char*, class Vector3*>>(0x15E300_Offset, this, arg1, arg2, arg3);
}

i32 DLP::Init(class DLPTemplate* arg1, char* arg2, class Vector3* arg3)
{
    return stub<thiscall_t<i32, DLP*, class DLPTemplate*, char*, class Vector3*>>(
        0x15E380_Offset, this, arg1, arg2, arg3);
}

void DLP::FixTemplateRefs(i32 arg1)
{
    return stub<thiscall_t<void, DLP*, i32>>(0x15E000_Offset, this, arg1);
}
