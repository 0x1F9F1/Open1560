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

#include "data7/pager.h"
#include "stream.h"
#include "vstream.h"

VirtualFileSystem::VirtualFileSystem(class Stream* stream)
    : base_stream_(stream)
{
    base_stream_->Read(&file_header_, sizeof(file_header_));

    if (file_header_.Magic != AresMagic)
        Quitf("VFS::VFS: Not a valid AngelRes file.");

    file_nodes_ = MakeUniqueUninit<VirtualFileInode[]>(file_header_.NodeCount);
    base_stream_->Read(file_nodes_.get(), file_header_.NodeCount * sizeof(VirtualFileInode));

    file_names_ = MakeUniqueUninit<char[]>(file_header_.NamesSize);
    base_stream_->Read(file_names_.get(), file_header_.NamesSize);

    ValidateNodes();
}

VirtualFileSystem::~VirtualFileSystem() = default;

b32 VirtualFileSystem::ChangeDir(const char*)
{
    return false;
}

Owner<class Stream> VirtualFileSystem::CreateOn(const char*, void*, isize)
{
    return nullptr;
}

struct VirtualFileEntry
{
    VirtualFileInode* Nodes {nullptr};
    u32 NodeCount {0};

    inline void FillInfo(VirtualFileSystem* fs, FileInfo& info)
    {
        fs->ExpandName(info.Path, ARTS_SIZE(info.Path), Nodes);
        info.IsDirectory = Nodes->IsDirectory();
    }
};

struct FileInfo* VirtualFileSystem::FirstEntry(const char* path)
{
    VirtualFileInode* nodes = nullptr;
    u32 node_count = 0;

    if (*path)
    {
        VirtualFileInode* node = Lookup(path);

        if (!node || !node->IsDirectory())
            return nullptr;

        nodes = &file_nodes_[node->GetEntryIndex()];
        node_count = node->GetEntryCount();
    }
    else
    {
        nodes = file_nodes_.get();
        node_count = file_header_.RootCount;
    }

    Ptr<FileInfo> result = MakeUnique<FileInfo>();

    Ptr<VirtualFileEntry> context = MakeUnique<VirtualFileEntry>();
    context->Nodes = nodes;
    context->NodeCount = node_count;
    context->FillInfo(this, *result);

    result->Context = context.release();

    return result.release();
}

b32 VirtualFileSystem::GetDir(char*, isize)
{
    return false;
}

struct FileInfo* VirtualFileSystem::NextEntry(struct FileInfo* info)
{
    VirtualFileEntry* context = static_cast<VirtualFileEntry*>(info->Context);

    if (!--context->NodeCount)
    {
        delete context;
        delete info;

        return nullptr;
    }

    ++context->Nodes;
    context->FillInfo(this, *info);

    return info;
}

Owner<class Stream> VirtualFileSystem::OpenOn(const char* path, b32 read_only, void* buffer, isize buffer_len)
{
    if (!read_only)
        return nullptr;

    VirtualFileInode* node = Lookup(path);

    if (!node || node->IsDirectory())
        return nullptr;

    return AsOwner(MakeUnique<VirtualStream>(base_stream_.get(), node, buffer, buffer_len, this));
}

b32 VirtualFileSystem::PagerInfo(const char* path, struct PagerInfo_t& info)
{
    VirtualFileInode* node = Lookup(path);

    if (!node || node->IsDirectory())
        return false;

    info.Handle = base_stream_->GetPagerHandle();
    info.Offset = node->GetOffset();
    info.Size = node->GetSize();
    info.Name = arts_strdup(path); // FIXME: Memory leak

    return true;
}

b32 VirtualFileSystem::QueryOn(const char* path)
{
    VirtualFileInode* node = Lookup(path);

    return node && !node->IsDirectory();
}

b32 VirtualFileSystem::ValidPath(const char*)
{
    return true;
}

void VirtualFileSystem::ExpandName(char* buf, struct VirtualFileInode* node, const char* names)
{
    ExpandName(buf, 56, node, names);
}

void VirtualFileSystem::ExpandName(char* buf, isize buf_len, VirtualFileInode* node, const char* names)
{
    CStringBuilder builder(buf, buf_len);

    for (const char* name = &names[node->GetNameOffset()]; *name; ++name)
    {
        char c = *name;

        if (c == '\1')
        {
            // Max Value: 8191
            u32 value = node->GetNameInteger();
            bool pad = false;

            if (value >= 1000)
            {
                builder += char(value / 1000) + '0';
                value %= 1000;
                pad = true;
            }

            if (pad || value >= 100)
            {
                builder += char(value / 100) + '0';
                value %= 100;
                pad = true;
            }

            if (pad || value >= 10)
            {
                builder += char(value / 10) + '0';
                value %= 10;
            }

            c = char(value) + '0';
        }

        builder += c;
    }

    if (u32 ext_offset = node->GetExtOffset())
    {
        builder += '.';
        builder += &names[ext_offset];
    }
}

struct VirtualFileInode* VirtualFileSystem::Lookup(
    struct VirtualFileInode* nodes, i32 node_count, const char* names, char* path)
{
    if (node_count == 0)
        return nullptr;

    i32 start = 0;
    i32 end = node_count - 1;

    while (true)
    {
        char* dir_end = std::strchr(path, '/');

        if (dir_end)
            *dir_end = '\0';

        VirtualFileInode* node = nullptr;

        while (true)
        {
            if (start > end)
                return nullptr;

            i32 here = (start + end) >> 1;

            node = &nodes[here];

            CStringBuffer<256> buf;
            ExpandName(buf.get(), buf.capacity(), node, names);

            i32 cmp = std::strcmp(path, buf);

            if (cmp > 0)
                start = here + 1;
            else if (cmp < 0)
                end = here - 1;
            else
                break;
        }

        if (dir_end == nullptr)
            return node;

        if (!node->IsDirectory())
            return nullptr;

        start = node->GetEntryIndex();
        end = start + node->GetEntryCount() - 1;
        path = dir_end + 1;
    }
}

void VirtualFileSystem::NormalizeName(char* buf, const char* path)
{
    NormalizeName(buf, 56, path);
}

void VirtualFileSystem::NormalizeName(char* buf, isize buf_len, const char* path)
{
    if (!std::strncmp(path, "/VFS/", 5))
        path += 5;

    while (IsPathSeparator(*path))
        ++path;

    CStringBuilder builder(buf, buf_len);

    while (*path)
    {
        char c = *path++;

        if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
        else if (c == '\\')
            c = '/';
        else if (c < 0x20)
            continue;

        builder += c;
    }
}

inline VirtualFileInode* VirtualFileSystem::Lookup(const char* path)
{
    CStringBuffer<128> buffer;
    NormalizeName(buffer.get(), buffer.capacity(), path);
    return Lookup(file_nodes_.get(), file_header_.RootCount, file_names_.get(), buffer.get());
}

void VirtualFileSystem::ExpandName(char* buf, isize buf_len, VirtualFileInode* node)
{
    ExpandName(buf, buf_len, node, file_names_.get());
}

void VirtualFileSystem::ValidateNodes()
{
    if (file_header_.RootCount > file_header_.NodeCount)
        Quitf("Invalid Archive: More roots than nodes (%u > %u)", file_header_.RootCount, file_header_.NodeCount);

    u32 file_size = base_stream_->Size();

    for (u32 i = 0; i < file_header_.NodeCount; ++i)
    {
        VirtualFileInode* node = &file_nodes_[i];

        if (node->GetNameOffset() >= file_header_.NamesSize)
            Quitf("Invalid Archive: Entry Name Offset for node %u", i);

        if (node->GetExtOffset() >= file_header_.NamesSize)
            Quitf("Invalid Archive: Entry Extension Offset for node %u", i);

        if (node->IsDirectory())
        {
            if (node->GetEntryIndex() + node->GetEntryCount() > file_header_.NodeCount)
            {
                CStringBuffer<256> buffer;
                ExpandName(buffer.get(), buffer.capacity(), node);
                Quitf("Invalid Archive Directory '%s'", buffer.get());
            }
        }
        else
        {
            if ((node->GetSize() == 0x4DCDCD) || (node->GetOffset() + node->GetSize() > file_size))
            {
                CStringBuffer<256> buffer;
                ExpandName(buffer.get(), buffer.capacity(), node);
                Quitf("Invalid Archive Entry '%s'", buffer.get());
            }
        }
    }
}
