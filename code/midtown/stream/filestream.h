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

class FileStream final : public Stream
{
public:
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
    void* file_handle_ {};
    void* pager_handle_ {};
    void* file_mapping_ {};
};

// check_size(FileStream, 0x28);
