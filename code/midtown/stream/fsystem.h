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

class FileSystem : public Base
{
    // const FileSystem::`vftable' @ 0x621928

public:
    // 0x55F530 | ??0FileSystem@@QAE@XZ
    FileSystem();

    // 0x55FF20 | ??_GFileSystem@@UAEPAXI@Z
    // 0x55F5A0 | ??1FileSystem@@UAE@XZ
    ~FileSystem() override;

    virtual i32 ValidPath(char* arg1) = 0;

    virtual i32 QueryOn(char* arg1) = 0;

    virtual class Stream* OpenOn(char* arg1, i32 arg2, void* arg3, i32 arg4) = 0;

    virtual class Stream* CreateOn(char* arg1, void* arg2, i32 arg3) = 0;

    // 0x55FEC0 | ?PagerInfo@FileSystem@@UAEHPADAAUPagerInfo_t@@@Z
    virtual i32 PagerInfo(char* arg1, struct PagerInfo_t& arg2);

    virtual i32 ChangeDir(char* arg1) = 0;

    virtual i32 GetDir(char* arg1, i32 arg2) = 0;

    virtual struct FileInfo* FirstEntry(char* arg1) = 0;

    virtual struct FileInfo* NextEntry(struct FileInfo* arg1) = 0;

protected:
    // 0x55F610 | ?NotifyDelete@FileSystem@@MAEXXZ
    virtual void NotifyDelete();

public:
    // 0x55F690 | ?Search@FileSystem@@QAEHPAD00H0@Z
    i32 Search(char* arg1, char* arg2, char* arg3, i32 arg4, char* arg5);

    // 0x55FE60 | ?OpenAny@FileSystem@@SAPAVStream@@PADHPAXH@Z
    static class Stream* OpenAny(char* arg1, i32 arg2, void* arg3, i32 arg4);

    // 0x55FED0 | ?PagerInfoAny@FileSystem@@SAHPADAAUPagerInfo_t@@@Z
    static i32 PagerInfoAny(char* arg1, struct PagerInfo_t& arg2);

    // 0x55F620 | ?SearchAll@FileSystem@@SAPAV1@PAD00H0@Z
    static class FileSystem* SearchAll(char* arg1, char* arg2, char* arg3, i32 arg4, char* arg5);

    // 0x907A38 | ?FS@FileSystem@@2PAPAV1@A
    static inline extern_var(0x907A38, class FileSystem**, FS);

    // 0x907A30 | ?FSCount@FileSystem@@2HA
    static inline extern_var(0x907A30, i32, FSCount);
};

check_size(FileSystem, 0x0);

// 0x55FD30 | ?FindFile@@YAPAVFileSystem@@PAD00H0@Z
class FileSystem* FindFile(char* arg1, char* arg2, char* arg3, i32 arg4, char* arg5);

// 0x55FD60 | ?OpenFile@@YAPAVStream@@PAD00H00@Z
class Stream* OpenFile(char* arg1, char* arg2, char* arg3, i32 arg4, char* arg5, char* arg6);

// 0x907B38 | ?fsVerbose@@3HA
inline extern_var(0x907B38, i32, fsVerbose);
