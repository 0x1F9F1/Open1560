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

#pragma once

#include "stream.h"

#include "data7/mutex.h"

struct VirtualFileInode;

class VirtualStream final : public Stream
{
public:
    // ??0VirtualStream@@QAE@PAVStream@@PAUVirtualFileInode@@PAXHPAVFileSystem@@@Z
    VirtualStream(
        Stream* base_stream, VirtualFileInode* file_node, void* buffer, isize buffer_size, FileSystem* file_system);

    // ??1VirtualStream@@UAE@XZ
    ~VirtualStream() override;

    // ?GetMapping@VirtualStream@@UAEPAXXZ
    void* GetMapping() override;

    // ?GetPagingInfo@VirtualStream@@UAEHAAI00@Z
    b32 GetPagingInfo(usize& handle, u32& offset, u32& size) override;

    // ?RawRead@VirtualStream@@UAEHPAXH@Z
    isize RawRead(void* ptr, isize size) override;

    // ?RawSeek@VirtualStream@@UAEHH@Z
    i32 RawSeek(i32 pos) override;

    // ?RawSize@VirtualStream@@UAEHXZ
    i32 RawSize() override;

    // ?RawTell@VirtualStream@@UAEHXZ
    i32 RawTell() override;

    // ?RawWrite@VirtualStream@@UAEHPAXH@Z
    isize RawWrite(const void* ptr, isize size) override;

private:
    Stream* base_stream_ {};
    u32 data_offset_ {};
    u32 data_size_ {};
    Mutex lock_ {};
};

check_size(VirtualStream, 0x30);
