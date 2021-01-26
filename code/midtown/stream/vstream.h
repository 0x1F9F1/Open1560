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

/*
    stream:vstream

    0x561B40 | public: __thiscall VirtualStream::VirtualStream(class Stream *,struct VirtualFileInode *,void *,int,class FileSystem *) | ??0VirtualStream@@QAE@PAVStream@@PAUVirtualFileInode@@PAXHPAVFileSystem@@@Z
    0x561BD0 | public: virtual int __thiscall VirtualStream::GetPagingInfo(unsigned int &,unsigned int &,unsigned int &) | ?GetPagingInfo@VirtualStream@@UAEHAAI00@Z
    0x561C00 | public: virtual __thiscall VirtualStream::~VirtualStream(void) | ??1VirtualStream@@UAE@XZ
    0x561C60 | public: virtual int __thiscall VirtualStream::RawRead(void *,int) | ?RawRead@VirtualStream@@UAEHPAXH@Z
    0x561CD0 | public: virtual int __thiscall VirtualStream::RawWrite(void *,int) | ?RawWrite@VirtualStream@@UAEHPAXH@Z
    0x561CE0 | public: virtual int __thiscall VirtualStream::RawSeek(int) | ?RawSeek@VirtualStream@@UAEHH@Z
    0x561D10 | public: virtual int __thiscall VirtualStream::RawTell(void) | ?RawTell@VirtualStream@@UAEHXZ
    0x561D30 | public: virtual int __thiscall VirtualStream::RawSize(void) | ?RawSize@VirtualStream@@UAEHXZ
    0x561D40 | public: virtual void * __thiscall VirtualStream::GetMapping(void) | ?GetMapping@VirtualStream@@UAEPAXXZ
    0x561D60 | public: virtual void * __thiscall VirtualStream::`scalar deleting destructor'(unsigned int) | ??_GVirtualStream@@UAEPAXI@Z
    0x561D60 | public: virtual void * __thiscall VirtualStream::`vector deleting destructor'(unsigned int) | ??_EVirtualStream@@UAEPAXI@Z
    0x621A38 | const VirtualStream::`vftable' | ??_7VirtualStream@@6B@
*/

#include "stream.h"

#include "data7/mutex.h"

class VirtualStream final : public Stream
{
    // const VirtualStream::`vftable' @ 0x621A38

public:
    // 0x561B40 | ??0VirtualStream@@QAE@PAVStream@@PAUVirtualFileInode@@PAXHPAVFileSystem@@@Z
    ARTS_EXPORT VirtualStream(class Stream* base_stream, struct VirtualFileInode* file_node, void* buffer,
        isize buffer_size, class FileSystem* file_system);

    // 0x561D60 | ??_EVirtualStream@@UAEPAXI@Z
    // 0x561C00 | ??1VirtualStream@@UAE@XZ
    ARTS_EXPORT ~VirtualStream() override;

    // 0x561D40 | ?GetMapping@VirtualStream@@UAEPAXXZ
    ARTS_EXPORT void* GetMapping() override;

    // 0x561BD0 | ?GetPagingInfo@VirtualStream@@UAEHAAI00@Z
    ARTS_EXPORT b32 GetPagingInfo(usize& handle, u32& offset, u32& size) override;

    // 0x561C60 | ?RawRead@VirtualStream@@UAEHPAXH@Z
    ARTS_EXPORT isize RawRead(void* ptr, isize size) override;

    // 0x561CE0 | ?RawSeek@VirtualStream@@UAEHH@Z
    ARTS_EXPORT i32 RawSeek(i32 pos) override;

    // 0x561D30 | ?RawSize@VirtualStream@@UAEHXZ
    ARTS_EXPORT i32 RawSize() override;

    // 0x561D10 | ?RawTell@VirtualStream@@UAEHXZ
    ARTS_EXPORT i32 RawTell() override;

    // 0x561CD0 | ?RawWrite@VirtualStream@@UAEHPAXH@Z
    ARTS_EXPORT isize RawWrite(const void* ptr, isize size) override;

private:
    Stream* base_stream_ {nullptr};
    u32 data_offset_ {0};
    u32 data_size_ {0};
    CriticalSection lock_ {};
};

check_size(VirtualStream, 0x30);
