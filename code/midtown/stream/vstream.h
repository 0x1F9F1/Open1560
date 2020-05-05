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

class VirtualStream : public Stream
{
    // const VirtualStream::`vftable' @ 0x621A38

public:
    // 0x561B40 | ??0VirtualStream@@QAE@PAVStream@@PAUVirtualFileInode@@PAXHPAVFileSystem@@@Z
    VirtualStream(class Stream* arg1, struct VirtualFileInode* arg2, void* arg3, i32 arg4, class FileSystem* arg5);

    // 0x561D60 | ??_EVirtualStream@@UAEPAXI@Z
    // 0x561C00 | ??1VirtualStream@@UAE@XZ
    ~VirtualStream() override;

    // 0x561D40 | ?GetMapping@VirtualStream@@UAEPAXXZ
    void* GetMapping() override;

    // 0x561BD0 | ?GetPagingInfo@VirtualStream@@UAEHAAI00@Z
    i32 GetPagingInfo(u32& arg1, u32& arg2, u32& arg3) override;

    // 0x561C60 | ?RawRead@VirtualStream@@UAEHPAXH@Z
    i32 RawRead(void* arg1, i32 arg2) override;

    // 0x561CE0 | ?RawSeek@VirtualStream@@UAEHH@Z
    i32 RawSeek(i32 arg1) override;

    // 0x561D30 | ?RawSize@VirtualStream@@UAEHXZ
    i32 RawSize() override;

    // 0x561D10 | ?RawTell@VirtualStream@@UAEHXZ
    i32 RawTell() override;

    // 0x561CD0 | ?RawWrite@VirtualStream@@UAEHPAXH@Z
    i32 RawWrite(void* arg1, i32 arg2) override;
};

check_size(VirtualStream, 0x30);
