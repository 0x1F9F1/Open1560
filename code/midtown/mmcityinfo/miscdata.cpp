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

#include "miscdata.h"

mmMiscData::mmMiscData()
{
    unimplemented();
}

mmMiscData::~mmMiscData()
{
    unimplemented();
}

i32 mmMiscData::CheckBlitz(char* arg1, f32 arg2, i32 arg3, char* arg4, i32 arg5, i32 arg6)
{
    return stub<thiscall_t<i32, mmMiscData*, char*, f32, i32, char*, i32, i32>>(
        0xCD540_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

i32 mmMiscData::CheckCheckpoint(char* arg1, f32 arg2, i32 arg3, char* arg4, i32 arg5, i32 arg6)
{
    return stub<thiscall_t<i32, mmMiscData*, char*, f32, i32, char*, i32, i32>>(
        0xCD200_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

i32 mmMiscData::CheckCircuit(char* arg1, f32 arg2, i32 arg3, char* arg4, i32 arg5, i32 arg6)
{
    return stub<thiscall_t<i32, mmMiscData*, char*, f32, i32, char*, i32, i32>>(
        0xCD3A0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class mmRecord mmMiscData::GetBestBlitzScore(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<class mmRecord, mmMiscData*, i32, i32>>(0xCCFA0_Offset, this, arg1, arg2);
}

class mmRecord mmMiscData::GetBestBlitzTime(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<class mmRecord, mmMiscData*, i32, i32>>(0xCCC10_Offset, this, arg1, arg2);
}

class mmRecord mmMiscData::GetBestCircuitScore(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<class mmRecord, mmMiscData*, i32, i32>>(0xCD0D0_Offset, this, arg1, arg2);
}

class mmRecord mmMiscData::GetBestCircuitTime(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<class mmRecord, mmMiscData*, i32, i32>>(0xCCD40_Offset, this, arg1, arg2);
}

class mmRecord mmMiscData::GetBestRaceScore(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<class mmRecord, mmMiscData*, i32, i32>>(0xCCE70_Offset, this, arg1, arg2);
}

class mmRecord mmMiscData::GetBestRaceTime(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<class mmRecord, mmMiscData*, i32, i32>>(0xCCAE0_Offset, this, arg1, arg2);
}

class MetaClass* mmMiscData::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmMiscData*>>(0xCD960_Offset, this);
}

i32 mmMiscData::Load(char* arg1)
{
    return stub<thiscall_t<i32, mmMiscData*, char*>>(0xCC6A0_Offset, this, arg1);
}

i32 mmMiscData::LoadBinary(char* arg1)
{
    return stub<thiscall_t<i32, mmMiscData*, char*>>(0xCC7A0_Offset, this, arg1);
}

i32 mmMiscData::Save(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmMiscData*, char*, i32>>(0xCC710_Offset, this, arg1, arg2);
}

i32 mmMiscData::SaveBinary(char* arg1)
{
    return stub<thiscall_t<i32, mmMiscData*, char*>>(0xCC960_Offset, this, arg1);
}

void mmMiscData::DeclareFields()
{
    return stub<cdecl_t<void>>(0xCD6E0_Offset);
}

define_dummy_symbol(mmcityinfo_miscdata);
