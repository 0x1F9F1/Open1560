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

#include "playerdata.h"

mmPlayerRecord::mmPlayerRecord()
{
    unimplemented();
}

mmPlayerRecord::mmPlayerRecord(class mmPlayerRecord const& arg1)
{
    unimplemented();
}

mmPlayerRecord::~mmPlayerRecord()
{
    unimplemented();
}

void mmPlayerRecord::operator=(class mmPlayerRecord& arg1)
{
    return stub<thiscall_t<void, mmPlayerRecord*, class mmPlayerRecord&>>(0xCFC90_Offset, this, arg1);
}

u32 mmPlayerRecord::ComputeCRC()
{
    return stub<thiscall_t<u32, mmPlayerRecord*>>(0xCFCE0_Offset, this);
}

class MetaClass* mmPlayerRecord::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmPlayerRecord*>>(0xD0010_Offset, this);
}

i32 mmPlayerRecord::LoadBinary(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmPlayerRecord*, class Stream*>>(0xCFDC0_Offset, this, arg1);
}

void mmPlayerRecord::Reset()
{
    return stub<thiscall_t<void, mmPlayerRecord*>>(0xCFC60_Offset, this);
}

i32 mmPlayerRecord::SaveBinary(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmPlayerRecord*, class Stream*>>(0xCFD40_Offset, this, arg1);
}

void mmPlayerRecord::DeclareFields()
{
    return stub<cdecl_t<void>>(0xCFE40_Offset);
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
    return stub<thiscall_t<void, mmPlayerData*, class mmPlayerData&>>(0xD0140_Offset, this, arg1);
}

u32 mmPlayerData::ComputeCRC()
{
    return stub<thiscall_t<u32, mmPlayerData*>>(0xD09E0_Offset, this);
}

i32 mmPlayerData::GetBlitzMask()
{
    return stub<thiscall_t<i32, mmPlayerData*>>(0xD02B0_Offset, this);
}

i32 mmPlayerData::GetBlitzPassed()
{
    return stub<thiscall_t<i32, mmPlayerData*>>(0xD0340_Offset, this);
}

i32 mmPlayerData::GetCheckpointMask()
{
    return stub<thiscall_t<i32, mmPlayerData*>>(0xD02E0_Offset, this);
}

i32 mmPlayerData::GetCheckpointPassed()
{
    return stub<thiscall_t<i32, mmPlayerData*>>(0xD0360_Offset, this);
}

i32 mmPlayerData::GetCheckpointProgress(i32 arg1)
{
    return stub<thiscall_t<i32, mmPlayerData*, i32>>(0xD0290_Offset, this, arg1);
}

i32 mmPlayerData::GetCircuitMask()
{
    return stub<thiscall_t<i32, mmPlayerData*>>(0xD0310_Offset, this);
}

i32 mmPlayerData::GetCircuitPassed()
{
    return stub<thiscall_t<i32, mmPlayerData*>>(0xD0380_Offset, this);
}

class MetaClass* mmPlayerData::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmPlayerData*>>(0xD11E0_Offset, this);
}

char* mmPlayerData::GetFileName()
{
    return stub<thiscall_t<char*, mmPlayerData*>>(0xD0900_Offset, this);
}

char* mmPlayerData::GetName()
{
    return stub<thiscall_t<char*, mmPlayerData*>>(0xD0860_Offset, this);
}

char* mmPlayerData::GetNetName()
{
    return stub<thiscall_t<char*, mmPlayerData*>>(0xD08B0_Offset, this);
}

i32 mmPlayerData::GetTotalPassed()
{
    return stub<thiscall_t<i32, mmPlayerData*>>(0xD03A0_Offset, this);
}

i32 mmPlayerData::GetTotalScore()
{
    return stub<thiscall_t<i32, mmPlayerData*>>(0xD03C0_Offset, this);
}

i32 mmPlayerData::Load(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerData*, char*>>(0xD0910_Offset, this, arg1);
}

i32 mmPlayerData::LoadBinary(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerData*, char*>>(0xD0A90_Offset, this, arg1);
}

i32 mmPlayerData::RegisterFinish(class mmPlayerRecord arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<i32, mmPlayerData*, class mmPlayerRecord, i32, i32>>(0xD04A0_Offset, this, arg1, arg2, arg3);
}

i32 mmPlayerData::RegisterFinish(i32 arg1, f32 arg2, char arg3)
{
    return stub<thiscall_t<i32, mmPlayerData*, i32, f32, char>>(0xD0280_Offset, this, arg1, arg2, arg3);
}

void mmPlayerData::Reset()
{
    return stub<thiscall_t<void, mmPlayerData*>>(0xD0750_Offset, this);
}

void mmPlayerData::ResolveCheckpointProgress()
{
    return stub<thiscall_t<void, mmPlayerData*>>(0xD0410_Offset, this);
}

i32 mmPlayerData::Save(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmPlayerData*, char*, i32>>(0xD0940_Offset, this, arg1, arg2);
}

i32 mmPlayerData::SaveBinary(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerData*, char*>>(0xD0CF0_Offset, this, arg1);
}

void mmPlayerData::SetFileName(char* arg1)
{
    return stub<thiscall_t<void, mmPlayerData*, char*>>(0xD08C0_Offset, this, arg1);
}

void mmPlayerData::SetName(char* arg1)
{
    return stub<thiscall_t<void, mmPlayerData*, char*>>(0xD0820_Offset, this, arg1);
}

void mmPlayerData::SetNetName(char* arg1)
{
    return stub<thiscall_t<void, mmPlayerData*, char*>>(0xD0870_Offset, this, arg1);
}

void mmPlayerData::DeclareFields()
{
    return stub<cdecl_t<void>>(0xD0F00_Offset);
}

define_dummy_symbol(mmcityinfo_playerdata);
