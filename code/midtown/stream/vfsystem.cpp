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

define_dummy_symbol(stream_vfsystem);

#include "vfsystem.h"

VirtualFileSystem::VirtualFileSystem(class Stream* arg1)
{
    unimplemented(arg1);
}

VirtualFileSystem::~VirtualFileSystem()
{
    unimplemented(arg1);
}

i32 VirtualFileSystem::ChangeDir(char* arg1)
{
    return stub<thiscall_t<i32, VirtualFileSystem*, char*>>(0x160B90_Offset, this, arg1);
}

class Stream* VirtualFileSystem::CreateOn(char* arg1, void* arg2, i32 arg3)
{
    return stub<thiscall_t<class Stream*, VirtualFileSystem*, char*, void*, i32>>(
        0x160B80_Offset, this, arg1, arg2, arg3);
}

struct FileInfo* VirtualFileSystem::FirstEntry(char* arg1)
{
    return stub<thiscall_t<struct FileInfo*, VirtualFileSystem*, char*>>(0x160BB0_Offset, this, arg1);
}

i32 VirtualFileSystem::GetDir(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, VirtualFileSystem*, char*, i32>>(0x160BA0_Offset, this, arg1, arg2);
}

struct FileInfo* VirtualFileSystem::NextEntry(struct FileInfo* arg1)
{
    return stub<thiscall_t<struct FileInfo*, VirtualFileSystem*, struct FileInfo*>>(0x160D00_Offset, this, arg1);
}

class Stream* VirtualFileSystem::OpenOn(char* arg1, i32 arg2, void* arg3, i32 arg4)
{
    return stub<thiscall_t<class Stream*, VirtualFileSystem*, char*, i32, void*, i32>>(
        0x160AD0_Offset, this, arg1, arg2, arg3, arg4);
}

i32 VirtualFileSystem::PagerInfo(char* arg1, struct PagerInfo_t& arg2)
{
    return stub<thiscall_t<i32, VirtualFileSystem*, char*, struct PagerInfo_t&>>(0x160A50_Offset, this, arg1, arg2);
}

i32 VirtualFileSystem::QueryOn(char* arg1)
{
    return stub<thiscall_t<i32, VirtualFileSystem*, char*>>(0x160A00_Offset, this, arg1);
}

i32 VirtualFileSystem::ValidPath(char* arg1)
{
    return stub<thiscall_t<i32, VirtualFileSystem*, char*>>(0x160780_Offset, this, arg1);
}

void VirtualFileSystem::ExpandName(char* arg1, struct VirtualFileInode* arg2, char* arg3)
{
    return stub<cdecl_t<void, char*, struct VirtualFileInode*, char*>>(0x160800_Offset, arg1, arg2, arg3);
}

struct VirtualFileInode* VirtualFileSystem::Lookup(struct VirtualFileInode* arg1, i32 arg2, char* arg3, char* arg4)
{
    return stub<cdecl_t<struct VirtualFileInode*, struct VirtualFileInode*, i32, char*, char*>>(
        0x160920_Offset, arg1, arg2, arg3, arg4);
}

void VirtualFileSystem::NormalizeName(char* arg1, char* arg2)
{
    return stub<cdecl_t<void, char*, char*>>(0x160790_Offset, arg1, arg2);
}
