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

#include "data7/base.h"

#ifndef MAX_FILESYSTEMS
#    define MAX_FILESYSTEMS 128
#endif

#define ARTS_MAX_PATH 1024

struct PagerInfo_t;

struct FileInfo
{
    char Path[(ARTS_TARGET_BUILD > 1560) ? ARTS_MAX_PATH : 256] {};

    b32 IsDirectory {};

    // TODO: Use inheritance instead of Context pointer
    void* Context {};
};

check_size(FileInfo, 0x108);

class FileSystem : public Base
{
public:
    // ??0FileSystem@@QAE@XZ
    FileSystem();

    // ??1FileSystem@@UAE@XZ
    ~FileSystem() override;

    virtual b32 ValidPath(const char* path) = 0;

    virtual b32 QueryOn(const char* path) = 0;

    virtual Owner<Stream> OpenOn(const char* path, b32 read_only, void* buffer, isize buffer_len) = 0;

    virtual Owner<Stream> CreateOn(const char* path, void* buffer, isize buffer_len) = 0;

    // ?PagerInfo@FileSystem@@UAEHPADAAUPagerInfo_t@@@Z
    virtual b32 PagerInfo(const char* path, PagerInfo_t& pager);

    virtual b32 ChangeDir(const char* path) = 0;

    virtual b32 GetDir(char* buffer, isize buffer_len) = 0;

    virtual FileInfo* FirstEntry(const char* path) = 0;

    virtual FileInfo* NextEntry(FileInfo* info) = 0;

    // ?Search@FileSystem@@QAEHPAD00H0@Z
    b32 Search(
        const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer, isize buffer_len);

    // ?OpenAny@FileSystem@@SAPAVStream@@PADHPAXH@Z
    static Owner<Stream> OpenAny(const char* path, b32 read_only, void* buffer, isize buffer_len);

    // ?PagerInfoAny@FileSystem@@SAHPADAAUPagerInfo_t@@@Z
    static b32 PagerInfoAny(const char* path, PagerInfo_t& pager);

    // ?SearchAll@FileSystem@@SAPAV1@PAD00H0@Z
    static FileSystem* SearchAll(
        const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer, isize buffer_len);

    // ?FS@FileSystem@@2PAPAV1@A
    static FileSystem* FS[MAX_FILESYSTEMS];

    // ?FSCount@FileSystem@@2HA
    static i32 FSCount;

    static inline constexpr bool IsPathSeparator(char c) noexcept
    {
        return (c == '/') || (c == '\\');
    }

    static inline constexpr bool IsPhysicalPath(const char* path) noexcept
    {
        return IsPathSeparator(path[0])                     // "/foo", "\foo"
            || (path[0] == '.' && IsPathSeparator(path[1])) // "./foo", ".\foo"
            || (path[0] != '\0' && path[1] == ':');         // "X:"
    }

protected:
    friend class Stream;

    // ?NotifyDelete@FileSystem@@MAEXXZ
    virtual void NotifyDelete();

private:
    i32 fs_index_ {};
};

check_size(FileSystem, 0x8);

// ?FindFile@@YAPAVFileSystem@@PAD00H0@Z
[[deprecated]] FileSystem* FindFile(
    const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer);

FileSystem* FindFile(const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer, usize buffer_len);

// ?OpenFile@@YAPAVStream@@PAD00H00@Z
[[deprecated]] Owner<Stream> OpenFile(
    const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer, const char* desc);

Owner<Stream> OpenFile(const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer,
    isize buffer_len, const char* desc);

// ?fsVerbose@@3HA
ARTS_EXPORT extern b32 fsVerbose;
