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

define_dummy_symbol(stream_hfsystem);

#include "hfsystem.h"

HierFileSystem::HierFileSystem()
{
    unimplemented();
}

HierFileSystem::~HierFileSystem()
{
    unimplemented(arg1);
}

i32 HierFileSystem::ChangeDir(char* arg1)
{
    return stub<thiscall_t<i32, HierFileSystem*, char*>>(0x160380_Offset, this, arg1);
}

class Stream* HierFileSystem::CreateOn(char* arg1, void* arg2, i32 arg3)
{
    return stub<thiscall_t<class Stream*, HierFileSystem*, char*, void*, i32>>(0x1602A0_Offset, this, arg1, arg2, arg3);
}

struct FileInfo* HierFileSystem::FirstEntry(char* arg1)
{
    return stub<thiscall_t<struct FileInfo*, HierFileSystem*, char*>>(0x1603C0_Offset, this, arg1);
}

i32 HierFileSystem::GetDir(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, HierFileSystem*, char*, i32>>(0x1603A0_Offset, this, arg1, arg2);
}

struct FileInfo* HierFileSystem::NextEntry(struct FileInfo* arg1)
{
    return stub<thiscall_t<struct FileInfo*, HierFileSystem*, struct FileInfo*>>(0x160500_Offset, this, arg1);
}

class Stream* HierFileSystem::OpenOn(char* arg1, i32 arg2, void* arg3, i32 arg4)
{
    return stub<thiscall_t<class Stream*, HierFileSystem*, char*, i32, void*, i32>>(
        0x160100_Offset, this, arg1, arg2, arg3, arg4);
}

i32 HierFileSystem::QueryOn(char* arg1)
{
    return stub<thiscall_t<i32, HierFileSystem*, char*>>(0x160040_Offset, this, arg1);
}

i32 HierFileSystem::ValidPath(char* arg1)
{
    return stub<thiscall_t<i32, HierFileSystem*, char*>>(0x15FF80_Offset, this, arg1);
}

char* FQN(char* arg1)
{
    return stub<cdecl_t<char*, char*>>(0x15FF90_Offset, arg1);
}

void PagerInfo_t::Read(void* arg1, u32 arg2, u32 arg3)
{
    return stub<thiscall_t<void, PagerInfo_t*, void*, u32, u32>>(0x1605D0_Offset, this, arg1, arg2, arg3);
}
