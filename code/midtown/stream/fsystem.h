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
    stream:fsystem

    0x55F530 | public: __thiscall FileSystem::FileSystem(void) | ??0FileSystem@@QAE@XZ
    0x55F5A0 | public: virtual __thiscall FileSystem::~FileSystem(void) | ??1FileSystem@@UAE@XZ
    0x55F610 | protected: virtual void __thiscall FileSystem::NotifyDelete(void) | ?NotifyDelete@FileSystem@@MAEXXZ
    0x55F620 | public: static class FileSystem * __cdecl FileSystem::SearchAll(char *,char *,char *,int,char *) | ?SearchAll@FileSystem@@SAPAV1@PAD00H0@Z
    0x55F690 | public: int __thiscall FileSystem::Search(char *,char *,char *,int,char *) | ?Search@FileSystem@@QAEHPAD00H0@Z
    0x55FAF0 | char * __cdecl SubString(int,char *) | ?SubString@@YAPADHPAD@Z
    0x55FB70 | int __cdecl NumSubStrings(char *) | ?NumSubStrings@@YAHPAD@Z
    0x55FBA0 | int __cdecl Contains(char *,char *) | ?Contains@@YAHPAD0@Z
    0x55FC20 | void __cdecl ExpandEnvs(char *) | ?ExpandEnvs@@YAXPAD@Z
    0x55FD30 | class FileSystem * __cdecl FindFile(char *,char *,char *,int,char *) | ?FindFile@@YAPAVFileSystem@@PAD00H0@Z
    0x55FD60 | class Stream * __cdecl OpenFile(char *,char *,char *,int,char *,char *) | ?OpenFile@@YAPAVStream@@PAD00H00@Z
    0x55FE60 | public: static class Stream * __cdecl FileSystem::OpenAny(char *,int,void *,int) | ?OpenAny@FileSystem@@SAPAVStream@@PADHPAXH@Z
    0x55FEC0 | public: virtual int __thiscall FileSystem::PagerInfo(char *,struct PagerInfo_t &) | ?PagerInfo@FileSystem@@UAEHPADAAUPagerInfo_t@@@Z
    0x55FED0 | public: static int __cdecl FileSystem::PagerInfoAny(char *,struct PagerInfo_t &) | ?PagerInfoAny@FileSystem@@SAHPADAAUPagerInfo_t@@@Z
    0x55FF20 | public: virtual void * __thiscall FileSystem::`vector deleting destructor'(unsigned int) | ??_EFileSystem@@UAEPAXI@Z
    0x55FF20 | public: virtual void * __thiscall FileSystem::`scalar deleting destructor'(unsigned int) | ??_GFileSystem@@UAEPAXI@Z
    0x621928 | const FileSystem::`vftable' | ??_7FileSystem@@6B@
    0x907A30 | public: static int FileSystem::FSCount | ?FSCount@FileSystem@@2HA
    0x907A38 | public: static class FileSystem * * FileSystem::FS | ?FS@FileSystem@@2PAPAV1@A
    0x907B38 | int fsVerbose | ?fsVerbose@@3HA
*/

#include "data7/base.h"

#define ARTS_MAX_PATH 1024

struct FileInfo
{
    char Path[(ARTS_TARGET_BUILD > 1560) ? ARTS_MAX_PATH : 256] {};

    b32 IsDirectory {false};

    // TODO: Use inheritance instead of Context pointer
    void* Context {nullptr};
};

check_size(FileInfo, 0x108);

class FileSystem : public Base
{
public:
    // ??0FileSystem@@QAE@XZ
    ARTS_EXPORT FileSystem();

    // ??_GFileSystem@@UAEPAXI@Z
    // ??1FileSystem@@UAE@XZ
    ARTS_EXPORT ~FileSystem() override;

    virtual b32 ValidPath(const char* path) = 0;

    virtual b32 QueryOn(const char* path) = 0;

    virtual Owner<class Stream> OpenOn(const char* path, b32 read_only, void* buffer, isize buffer_len) = 0;

    virtual Owner<class Stream> CreateOn(const char* path, void* buffer, isize buffer_len) = 0;

    // ?PagerInfo@FileSystem@@UAEHPADAAUPagerInfo_t@@@Z
    ARTS_EXPORT virtual b32 PagerInfo(const char* path, struct PagerInfo_t& pager);

    virtual b32 ChangeDir(const char* path) = 0;

    virtual b32 GetDir(char* buffer, isize buffer_len) = 0;

    virtual struct FileInfo* FirstEntry(const char* path) = 0;

    virtual struct FileInfo* NextEntry(struct FileInfo* info) = 0;

    // ?Search@FileSystem@@QAEHPAD00H0@Z
    ARTS_EXPORT b32 Search(
        const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer, isize buffer_len);

    // ?OpenAny@FileSystem@@SAPAVStream@@PADHPAXH@Z
    ARTS_EXPORT static Owner<class Stream> OpenAny(const char* path, b32 read_only, void* buffer, isize buffer_len);

    // ?PagerInfoAny@FileSystem@@SAHPADAAUPagerInfo_t@@@Z
    ARTS_EXPORT static b32 PagerInfoAny(const char* path, struct PagerInfo_t& pager);

    // ?SearchAll@FileSystem@@SAPAV1@PAD00H0@Z
    ARTS_EXPORT static class FileSystem* SearchAll(
        const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer, isize buffer_len);

    static constexpr i32 MAX_FILESYSTEMS = 128;

    // ?FS@FileSystem@@2PAPAV1@A
    ARTS_EXPORT static class FileSystem* FS[MAX_FILESYSTEMS];

    // ?FSCount@FileSystem@@2HA
    ARTS_EXPORT static i32 FSCount;

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
    i32 fs_index_ {0};
};

check_size(FileSystem, 0x8);

// ?FindFile@@YAPAVFileSystem@@PAD00H0@Z
[[deprecated]] ARTS_EXPORT class FileSystem* FindFile(
    const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer);

class FileSystem* FindFile(
    const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer, isize buffer_len);

// ?OpenFile@@YAPAVStream@@PAD00H00@Z
[[deprecated]] ARTS_EXPORT Owner<class Stream> OpenFile(
    const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer, const char* desc);

Owner<class Stream> OpenFile(const char* file, const char* folder, const char* ext, i32 ext_id, char* buffer,
    isize buffer_len, const char* desc);

// ?fsVerbose@@3HA
ARTS_EXPORT extern b32 fsVerbose;
