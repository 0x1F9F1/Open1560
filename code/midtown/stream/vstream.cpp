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
    i32 buffer_size, class FileSystem* file_system)
    : Stream(buffer, buffer_size, file_system)
    , base_stream_(base_stream)
    , data_offset_(file_node->GetOffset())
    , data_size_(file_node->GetSize())
{
    export_hook(0x561B40);

    RawSeek(0);
    flags_ |= 0x2;
    lock_.init();
}

VirtualStream::~VirtualStream()
{
    export_hook(0x561C00);

    lock_.close(); // TODO: Should this be closed after flushing?

    Flush();
}

void* VirtualStream::GetMapping()
{
    export_hook(0x561D40);

    if (void* mapping = base_stream_->GetMapping())
        return static_cast<u8*>(mapping) + data_offset_;

    return nullptr;
}

i32 VirtualStream::GetPagingInfo(u32& handle, u32& offset, u32& size)
{
    export_hook(0x561BD0);

    handle = base_stream_->GetPagerHandle();
    offset = data_offset_;
    size = data_size_;

    return true;
}

i32 VirtualStream::RawRead(void* ptr, i32 size)
{
    export_hook(0x561C60);

    lock_.lock();

    i32 here = RawTell();

    if (here < 0 || u32(here) > data_size_)
    {
        here = position_; // TODO: Should this be `here = Tell()`?
        Seek(here);
    }

    i32 result = base_stream_->Read(ptr, std::min<i32>(size, i32(data_size_) - here));

    lock_.unlock();

    return result;
}

i32 VirtualStream::RawSeek(i32 pos)
{
    export_hook(0x561CE0);

    return base_stream_->Seek(data_offset_ + pos) - data_offset_;
}

i32 VirtualStream::RawSize()
{
    export_hook(0x561D30);

    return data_size_;
}

i32 VirtualStream::RawTell()
{
    export_hook(0x561D10);

    return base_stream_->Tell() - data_offset_;
}

i32 VirtualStream::RawWrite(const void*, i32)
{
    return -1;
}
