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

define_dummy_symbol(mmcityinfo_playerdata);

#include "playerdata.h"

mmPlayerRecord::mmPlayerRecord()
{
    unimplemented();
}

mmPlayerRecord::mmPlayerRecord(class mmPlayerRecord const& arg1)
{
    unimplemented(arg1);
}

mmPlayerRecord::~mmPlayerRecord()
{
    unimplemented();
}

void mmPlayerRecord::operator=(class mmPlayerRecord& arg1)
{
    return stub<thiscall_t<void, mmPlayerRecord*, class mmPlayerRecord&>>(0x4CFC90, this, arg1);
}

u32 mmPlayerRecord::ComputeCRC()
{
    return stub<thiscall_t<u32, mmPlayerRecord*>>(0x4CFCE0, this);
}

class MetaClass* mmPlayerRecord::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmPlayerRecord*>>(0x4D0010, this);
}

i32 mmPlayerRecord::LoadBinary(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmPlayerRecord*, class Stream*>>(0x4CFDC0, this, arg1);
}

void mmPlayerRecord::Reset()
{
    return stub<thiscall_t<void, mmPlayerRecord*>>(0x4CFC60, this);
}

i32 mmPlayerRecord::SaveBinary(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmPlayerRecord*, class Stream*>>(0x4CFD40, this, arg1);
}

void mmPlayerRecord::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4CFE40);
}

mmPlayerData::mmPlayerData()
{
    unimplemented();
}

mmPlayerData::~mmPlayerData()
{
    unimplemented();
}

void mmPlayerData::operator=(class mmPlayerData& arg1)
{
    return stub<thiscall_t<void, mmPlayerData*, class mmPlayerData&>>(0x4D0140, this, arg1);
}

u32 mmPlayerData::ComputeCRC()
{
    return stub<thiscall_t<u32, mmPlayerData*>>(0x4D09E0, this);
}

i32 mmPlayerData::GetBlitzMask()
{
    return stub<thiscall_t<i32, mmPlayerData*>>(0x4D02B0, this);
}

i32 mmPlayerData::GetBlitzPassed()
{
    return stub<thiscall_t<i32, mmPlayerData*>>(0x4D0340, this);
}

i32 mmPlayerData::GetCheckpointMask()
{
    return stub<thiscall_t<i32, mmPlayerData*>>(0x4D02E0, this);
}

i32 mmPlayerData::GetCheckpointPassed()
{
    return stub<thiscall_t<i32, mmPlayerData*>>(0x4D0360, this);
}

i32 mmPlayerData::GetCheckpointProgress(i32 arg1)
{
    return stub<thiscall_t<i32, mmPlayerData*, i32>>(0x4D0290, this, arg1);
}

i32 mmPlayerData::GetCircuitMask()
{
    return stub<thiscall_t<i32, mmPlayerData*>>(0x4D0310, this);
}

i32 mmPlayerData::GetCircuitPassed()
{
    return stub<thiscall_t<i32, mmPlayerData*>>(0x4D0380, this);
}

class MetaClass* mmPlayerData::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmPlayerData*>>(0x4D11E0, this);
}

char* mmPlayerData::GetFileName()
{
    return stub<thiscall_t<char*, mmPlayerData*>>(0x4D0900, this);
}

char* mmPlayerData::GetName()
{
    return stub<thiscall_t<char*, mmPlayerData*>>(0x4D0860, this);
}

char* mmPlayerData::GetNetName()
{
    return stub<thiscall_t<char*, mmPlayerData*>>(0x4D08B0, this);
}

i32 mmPlayerData::GetTotalPassed()
{
    return stub<thiscall_t<i32, mmPlayerData*>>(0x4D03A0, this);
}

i32 mmPlayerData::GetTotalScore()
{
    return stub<thiscall_t<i32, mmPlayerData*>>(0x4D03C0, this);
}

i32 mmPlayerData::Load(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerData*, char*>>(0x4D0910, this, arg1);
}

i32 mmPlayerData::LoadBinary(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerData*, char*>>(0x4D0A90, this, arg1);
}

i32 mmPlayerData::RegisterFinish(class mmPlayerRecord arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<i32, mmPlayerData*, class mmPlayerRecord, i32, i32>>(0x4D04A0, this, arg1, arg2, arg3);
}

i32 mmPlayerData::RegisterFinish(i32 arg1, f32 arg2, char arg3)
{
    return stub<thiscall_t<i32, mmPlayerData*, i32, f32, char>>(0x4D0280, this, arg1, arg2, arg3);
}

void mmPlayerData::Reset()
{
    return stub<thiscall_t<void, mmPlayerData*>>(0x4D0750, this);
}

void mmPlayerData::ResolveCheckpointProgress()
{
    return stub<thiscall_t<void, mmPlayerData*>>(0x4D0410, this);
}

i32 mmPlayerData::Save(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmPlayerData*, char*, i32>>(0x4D0940, this, arg1, arg2);
}

i32 mmPlayerData::SaveBinary(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerData*, char*>>(0x4D0CF0, this, arg1);
}

void mmPlayerData::SetFileName(char* arg1)
{
    return stub<thiscall_t<void, mmPlayerData*, char*>>(0x4D08C0, this, arg1);
}

void mmPlayerData::SetName(char* arg1)
{
    return stub<thiscall_t<void, mmPlayerData*, char*>>(0x4D0820, this, arg1);
}

void mmPlayerData::SetNetName(char* arg1)
{
    return stub<thiscall_t<void, mmPlayerData*, char*>>(0x4D0870, this, arg1);
}

void mmPlayerData::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4D0F00);
}
