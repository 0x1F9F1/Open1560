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

define_dummy_symbol(stream_vstream);

#include "vstream.h"

#include "vfsystem.h"

VirtualStream::VirtualStream(class Stream* base_stream, struct VirtualFileInode* file_node, void* buffer,
    isize buffer_size, class FileSystem* file_system)
    : Stream(buffer, buffer_size, file_system)
    , base_stream_(base_stream)
    , data_offset_(file_node->GetOffset())
    , data_size_(file_node->GetSize())
{
    RawSeek(0);

    if (base_stream_->SupportsMapping())
        flags_ |= ARTS_STREAM_SUPPORTS_MAPPING;

    lock_.init();
}

VirtualStream::~VirtualStream() = default;

void* VirtualStream::GetMapping()
{
    if (void* mapping = base_stream_->GetMapping())
        return static_cast<u8*>(mapping) + data_offset_;

    return nullptr;
}

b32 VirtualStream::GetPagingInfo(usize& handle, u32& offset, u32& size)
{
    handle = base_stream_->GetPagerHandle();
    offset = data_offset_;
    size = data_size_;

    return true;
}

isize VirtualStream::RawRead(void* ptr, isize size)
{
    LockGuard lock(lock_);

    i32 here = RawTell();

    if (here != static_cast<i32>(position_))
        here = RawSeek(position_);

    return base_stream_->Read(ptr, std::min<isize>(size, isize(data_size_) - here));
}

i32 VirtualStream::RawSeek(i32 pos)
{
    return base_stream_->Seek(data_offset_ + pos) - data_offset_;
}

i32 VirtualStream::RawSize()
{
    return data_size_;
}

i32 VirtualStream::RawTell()
{
    return base_stream_->Tell() - data_offset_;
}

isize VirtualStream::RawWrite(const void*, isize)
{
    return -1;
}
