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
    stream:filestream

    0x5617F0 | public: __thiscall FileStream::FileStream(void *,int,class FileSystem *) | ??0FileStream@@QAE@PAXHPAVFileSystem@@@Z
    0x561830 | public: virtual unsigned int __thiscall FileStream::GetPagerHandle(void) | ?GetPagerHandle@FileStream@@UAEIXZ
    0x561840 | public: int __thiscall FileStream::Create(char *) | ?Create@FileStream@@QAEHPAD@Z
    0x561870 | public: int __thiscall FileStream::Open(char *,int) | ?Open@FileStream@@QAEHPADH@Z
    0x5618E0 | public: __thiscall FileStream::FileStream(int) | ??0FileStream@@QAE@H@Z
    0x561910 | public: int __thiscall FileStream::Stdin(void) | ?Stdin@FileStream@@QAEHXZ
    0x561930 | public: int __thiscall FileStream::Stdout(void) | ?Stdout@FileStream@@QAEHXZ
    0x561950 | public: int __thiscall FileStream::Stderr(void) | ?Stderr@FileStream@@QAEHXZ
    0x561970 | public: virtual int __thiscall FileStream::RawRead(void *,int) | ?RawRead@FileStream@@UAEHPAXH@Z
    0x561990 | public: virtual int __thiscall FileStream::RawWrite(void *,int) | ?RawWrite@FileStream@@UAEHPAXH@Z
    0x5619B0 | public: virtual int __thiscall FileStream::RawSeek(int) | ?RawSeek@FileStream@@UAEHH@Z
    0x5619D0 | public: virtual int __thiscall FileStream::RawTell(void) | ?RawTell@FileStream@@UAEHXZ
    0x5619F0 | public: virtual int __thiscall FileStream::RawSize(void) | ?RawSize@FileStream@@UAEHXZ
    0x561A20 | public: int __thiscall FileStream::Close(void) | ?Close@FileStream@@QAEHXZ
    0x561A60 | public: virtual __thiscall FileStream::~FileStream(void) | ??1FileStream@@UAE@XZ
    0x561B10 | public: virtual void * __thiscall FileStream::`scalar deleting destructor'(unsigned int) | ??_GFileStream@@UAEPAXI@Z
    0x561B10 | public: virtual void * __thiscall FileStream::`vector deleting destructor'(unsigned int) | ??_EFileStream@@UAEPAXI@Z
    0x6219F8 | const FileStream::`vftable' | ??_7FileStream@@6B@
    0x908BE0 | class FileStream __stdout | ?__stdout@@3VFileStream@@A
    0x908C08 | class FileStream __stdin | ?__stdin@@3VFileStream@@A
*/

#include "stream.h"

class FileStream final : public Stream
{
public:
    // ??0FileStream@@QAE@H@Z
    ARTS_EXPORT FileStream(i32 handle);

    // ??0FileStream@@QAE@PAXHPAVFileSystem@@@Z
    ARTS_EXPORT FileStream(void* buffer, isize buffer_size, FileSystem* file_system);

    // ??_EFileStream@@UAEPAXI@Z
    // ??1FileStream@@UAE@XZ
    ARTS_EXPORT ~FileStream() override;

    // ?Close@FileStream@@QAEHXZ
    ARTS_EXPORT i32 Close();

    // ?Create@FileStream@@QAEHPAD@Z
    ARTS_EXPORT i32 Create(const char* path);

    void* GetMapping() override;

    // ?GetPagerHandle@FileStream@@UAEIXZ
    ARTS_EXPORT usize GetPagerHandle() override;

    // ?Open@FileStream@@QAEHPADH@Z
    ARTS_EXPORT i32 Open(const char* path, b32 read_only);

    // ?RawRead@FileStream@@UAEHPAXH@Z
    ARTS_EXPORT isize RawRead(void* ptr, isize size) override;

    // ?RawSeek@FileStream@@UAEHH@Z
    ARTS_EXPORT i32 RawSeek(i32 pos) override;

    // ?RawSize@FileStream@@UAEHXZ
    ARTS_EXPORT i32 RawSize() override;

    // ?RawTell@FileStream@@UAEHXZ
    ARTS_EXPORT i32 RawTell() override;

    // ?RawWrite@FileStream@@UAEHPAXH@Z
    ARTS_EXPORT isize RawWrite(const void* ptr, isize size) override;

    // ?Stderr@FileStream@@QAEHXZ | unused
    ARTS_EXPORT i32 Stderr();

    // ?Stdin@FileStream@@QAEHXZ
    ARTS_EXPORT i32 Stdin();

    // ?Stdout@FileStream@@QAEHXZ
    ARTS_EXPORT i32 Stdout();

protected:
    i32 GetError(char* buf, isize buf_len) override;

private:
    void* file_handle_ {nullptr};
    void* pager_handle_ {nullptr};
    void* file_mapping_ {nullptr};
};

// check_size(FileStream, 0x28);

// ?__stdin@@3VFileStream@@A
ARTS_EXPORT extern FileStream __stdin;

// ?__stdout@@3VFileStream@@A
ARTS_EXPORT extern FileStream __stdout;
