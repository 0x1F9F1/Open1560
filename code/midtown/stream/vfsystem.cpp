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

#include "stream.h"

VirtualFileSystem::VirtualFileSystem(class Stream* stream)
    : base_stream_(stream)
{
    export_hook(0x560650);

    base_stream_->Read(&file_header_, sizeof(file_header_));

    if (file_header_.Magic != AresMagic)
        Quitf("VFS::VFS: Not a valid AngelRes file.");

    file_nodes_.reset(new VirtualFileInode[file_header_.FileCount]);
    base_stream_->Read(file_nodes_.get(), file_header_.FileCount * sizeof(VirtualFileInode));

    file_names_.reset(new char[file_header_.NamesSize]);
    base_stream_->Read(file_names_.get(), file_header_.NamesSize);

    u32 file_size = base_stream_->Size();

    for (u32 i = 0; i < file_header_.FileCount; ++i)
    {
        VirtualFileInode* node = &file_nodes_[i];

        if ((node->GetSize() == 0x4DCDCD) || (node->GetOffset() + node->GetSize() > file_size))
        {
            char buffer[256];
            ExpandName(buffer, node, file_names_.get());
            Errorf("Invalid/Corrupt Archive Entry '%s'", buffer);
        }
    }
}

VirtualFileSystem::~VirtualFileSystem()
{
    export_hook(0x560710);
}

b32 VirtualFileSystem::ChangeDir(const char*)
{
    export_hook(0x560B90);

    return false;
}

class Stream* VirtualFileSystem::CreateOn(const char*, void*, i32)
{
    export_hook(0x560B80);

    return nullptr;
}

struct FileInfo* VirtualFileSystem::FirstEntry(const char* arg1)
{
    return stub<thiscall_t<struct FileInfo*, VirtualFileSystem*, const char*>>(0x560BB0, this, arg1);
}

b32 VirtualFileSystem::GetDir(char*, i32)
{
    export_hook(0x560BA0);

    return false;
}

struct FileInfo* VirtualFileSystem::NextEntry(struct FileInfo* arg1)
{
    return stub<thiscall_t<struct FileInfo*, VirtualFileSystem*, struct FileInfo*>>(0x560D00, this, arg1);
}

class Stream* VirtualFileSystem::OpenOn(const char* arg1, i32 arg2, void* arg3, i32 arg4)
{
    return stub<thiscall_t<class Stream*, VirtualFileSystem*, const char*, i32, void*, i32>>(
        0x560AD0, this, arg1, arg2, arg3, arg4);
}

i32 VirtualFileSystem::PagerInfo(const char* arg1, struct PagerInfo_t& arg2)
{
    return stub<thiscall_t<i32, VirtualFileSystem*, const char*, struct PagerInfo_t&>>(0x560A50, this, arg1, arg2);
}

i32 VirtualFileSystem::QueryOn(const char* arg1)
{
    return stub<thiscall_t<i32, VirtualFileSystem*, const char*>>(0x560A00, this, arg1);
}

i32 VirtualFileSystem::ValidPath(const char* arg1)
{
    return stub<thiscall_t<i32, VirtualFileSystem*, const char*>>(0x560780, this, arg1);
}

void VirtualFileSystem::ExpandName(char* arg1, struct VirtualFileInode* arg2, char* arg3)
{
    // TODO: Pass buffer size

    return stub<cdecl_t<void, char*, struct VirtualFileInode*, char*>>(0x560800, arg1, arg2, arg3);
}

struct VirtualFileInode* VirtualFileSystem::Lookup(struct VirtualFileInode* arg1, i32 arg2, char* arg3, char* arg4)
{
    return stub<cdecl_t<struct VirtualFileInode*, struct VirtualFileInode*, i32, char*, char*>>(
        0x560920, arg1, arg2, arg3, arg4);
}

void VirtualFileSystem::NormalizeName(char* arg1, char* arg2)
{
    // TODO: Pass buffer size

    return stub<cdecl_t<void, char*, char*>>(0x560790, arg1, arg2);
}
