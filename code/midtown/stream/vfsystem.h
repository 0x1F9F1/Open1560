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

#include "fsystem.h"

/*
    stream:vfsystem

    0x560650 | public: __thiscall VirtualFileSystem::VirtualFileSystem(class Stream *) | ??0VirtualFileSystem@@QAE@PAVStream@@@Z
    0x560710 | public: virtual __thiscall VirtualFileSystem::~VirtualFileSystem(void) | ??1VirtualFileSystem@@UAE@XZ
    0x560780 | public: virtual int __thiscall VirtualFileSystem::ValidPath(char *) | ?ValidPath@VirtualFileSystem@@UAEHPAD@Z
    0x560790 | public: static void __cdecl VirtualFileSystem::NormalizeName(char *,char *) | ?NormalizeName@VirtualFileSystem@@SAXPAD0@Z
    0x560800 | public: static void __cdecl VirtualFileSystem::ExpandName(char *,struct VirtualFileInode *,char *) | ?ExpandName@VirtualFileSystem@@SAXPADPAUVirtualFileInode@@0@Z
    0x560920 | public: static struct VirtualFileInode * __cdecl VirtualFileSystem::Lookup(struct VirtualFileInode *,int,char *,char *) | ?Lookup@VirtualFileSystem@@SAPAUVirtualFileInode@@PAU2@HPAD1@Z
    0x560A00 | public: virtual int __thiscall VirtualFileSystem::QueryOn(char *) | ?QueryOn@VirtualFileSystem@@UAEHPAD@Z
    0x560A50 | public: virtual int __thiscall VirtualFileSystem::PagerInfo(char *,struct PagerInfo_t &) | ?PagerInfo@VirtualFileSystem@@UAEHPADAAUPagerInfo_t@@@Z
    0x560AD0 | public: virtual class Stream * __thiscall VirtualFileSystem::OpenOn(char *,int,void *,int) | ?OpenOn@VirtualFileSystem@@UAEPAVStream@@PADHPAXH@Z
    0x560B80 | public: virtual class Stream * __thiscall VirtualFileSystem::CreateOn(char *,void *,int) | ?CreateOn@VirtualFileSystem@@UAEPAVStream@@PADPAXH@Z
    0x560B90 | public: virtual int __thiscall VirtualFileSystem::ChangeDir(char *) | ?ChangeDir@VirtualFileSystem@@UAEHPAD@Z
    0x560BA0 | public: virtual int __thiscall VirtualFileSystem::GetDir(char *,int) | ?GetDir@VirtualFileSystem@@UAEHPADH@Z
    0x560BB0 | public: virtual struct FileInfo * __thiscall VirtualFileSystem::FirstEntry(char *) | ?FirstEntry@VirtualFileSystem@@UAEPAUFileInfo@@PAD@Z
    0x560D00 | public: virtual struct FileInfo * __thiscall VirtualFileSystem::NextEntry(struct FileInfo *) | ?NextEntry@VirtualFileSystem@@UAEPAUFileInfo@@PAU2@@Z
    0x560D80 | public: virtual void * __thiscall VirtualFileSystem::`scalar deleting destructor'(unsigned int) | ??_GVirtualFileSystem@@UAEPAXI@Z
    0x560D80 | public: virtual void * __thiscall VirtualFileSystem::`vector deleting destructor'(unsigned int) | ??_EVirtualFileSystem@@UAEPAXI@Z
    0x6219A8 | const VirtualFileSystem::`vftable' | ??_7VirtualFileSystem@@6B@
*/

class VirtualFileSystem : public FileSystem
{
    // const VirtualFileSystem::`vftable' @ 0x6219A8

public:
    // 0x560650 | ??0VirtualFileSystem@@QAE@PAVStream@@@Z
    VirtualFileSystem(class Stream* arg1);

    // 0x560D80 | ??_EVirtualFileSystem@@UAEPAXI@Z
    // 0x560710 | ??1VirtualFileSystem@@UAE@XZ
    ~VirtualFileSystem() override;

    // 0x560B90 | ?ChangeDir@VirtualFileSystem@@UAEHPAD@Z
    i32 ChangeDir(char* arg1) override;

    // 0x560B80 | ?CreateOn@VirtualFileSystem@@UAEPAVStream@@PADPAXH@Z
    class Stream* CreateOn(char* arg1, void* arg2, i32 arg3) override;

    // 0x560BB0 | ?FirstEntry@VirtualFileSystem@@UAEPAUFileInfo@@PAD@Z
    struct FileInfo* FirstEntry(char* arg1) override;

    // 0x560BA0 | ?GetDir@VirtualFileSystem@@UAEHPADH@Z
    i32 GetDir(char* arg1, i32 arg2) override;

    // 0x560D00 | ?NextEntry@VirtualFileSystem@@UAEPAUFileInfo@@PAU2@@Z
    struct FileInfo* NextEntry(struct FileInfo* arg1) override;

    // 0x560AD0 | ?OpenOn@VirtualFileSystem@@UAEPAVStream@@PADHPAXH@Z
    class Stream* OpenOn(char* arg1, i32 arg2, void* arg3, i32 arg4) override;

    // 0x560A50 | ?PagerInfo@VirtualFileSystem@@UAEHPADAAUPagerInfo_t@@@Z
    i32 PagerInfo(char* arg1, struct PagerInfo_t& arg2) override;

    // 0x560A00 | ?QueryOn@VirtualFileSystem@@UAEHPAD@Z
    i32 QueryOn(char* arg1) override;

    // 0x560780 | ?ValidPath@VirtualFileSystem@@UAEHPAD@Z
    i32 ValidPath(char* arg1) override;

    // 0x560800 | ?ExpandName@VirtualFileSystem@@SAXPADPAUVirtualFileInode@@0@Z
    static void ExpandName(char* arg1, struct VirtualFileInode* arg2, char* arg3);

    // 0x560920 | ?Lookup@VirtualFileSystem@@SAPAUVirtualFileInode@@PAU2@HPAD1@Z
    static struct VirtualFileInode* Lookup(struct VirtualFileInode* arg1, i32 arg2, char* arg3, char* arg4);

    // 0x560790 | ?NormalizeName@VirtualFileSystem@@SAXPAD0@Z
    static void NormalizeName(char* arg1, char* arg2);
};

check_size(VirtualFileSystem, 0x24);
