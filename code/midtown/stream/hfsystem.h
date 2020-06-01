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
    stream:hfsystem

    0x55FF50 | public: __thiscall HierFileSystem::HierFileSystem(void) | ??0HierFileSystem@@QAE@XZ
    0x55FF70 | public: virtual __thiscall HierFileSystem::~HierFileSystem(void) | ??1HierFileSystem@@UAE@XZ
    0x55FF80 | public: virtual int __thiscall HierFileSystem::ValidPath(char *) | ?ValidPath@HierFileSystem@@UAEHPAD@Z
    0x55FF90 | char * __cdecl FQN(char *) | ?FQN@@YAPADPAD@Z
    0x560040 | public: virtual int __thiscall HierFileSystem::QueryOn(char *) | ?QueryOn@HierFileSystem@@UAEHPAD@Z
    0x560100 | public: virtual class Stream * __thiscall HierFileSystem::OpenOn(char *,int,void *,int) | ?OpenOn@HierFileSystem@@UAEPAVStream@@PADHPAXH@Z
    0x5602A0 | public: virtual class Stream * __thiscall HierFileSystem::CreateOn(char *,void *,int) | ?CreateOn@HierFileSystem@@UAEPAVStream@@PADPAXH@Z
    0x560380 | public: virtual int __thiscall HierFileSystem::ChangeDir(char *) | ?ChangeDir@HierFileSystem@@UAEHPAD@Z
    0x5603A0 | public: virtual int __thiscall HierFileSystem::GetDir(char *,int) | ?GetDir@HierFileSystem@@UAEHPADH@Z
    0x5603C0 | public: virtual struct FileInfo * __thiscall HierFileSystem::FirstEntry(char *) | ?FirstEntry@HierFileSystem@@UAEPAUFileInfo@@PAD@Z
    0x560500 | public: virtual struct FileInfo * __thiscall HierFileSystem::NextEntry(struct FileInfo *) | ?NextEntry@HierFileSystem@@UAEPAUFileInfo@@PAU2@@Z
    0x5605D0 | public: void __thiscall PagerInfo_t::Read(void *,unsigned int,unsigned int) | ?Read@PagerInfo_t@@QAEXPAXII@Z
    0x560620 | public: virtual void * __thiscall HierFileSystem::`vector deleting destructor'(unsigned int) | ??_EHierFileSystem@@UAEPAXI@Z
    0x560620 | public: virtual void * __thiscall HierFileSystem::`scalar deleting destructor'(unsigned int) | ??_GHierFileSystem@@UAEPAXI@Z
    0x621968 | const HierFileSystem::`vftable' | ??_7HierFileSystem@@6B@
    0x907B40 | char * HierPrefix | ?HierPrefix@@3PADA
    0x907BC8 | class HierFileSystem HFS | ?HFS@@3VHierFileSystem@@A
    0x907BD0 | char * HierAllowPath | ?HierAllowPath@@3PADA
    0x907BD4 | int LogOpenOn | ?LogOpenOn@@3HA
*/

#include "fsystem.h"

class HierFileSystem : public FileSystem
{
    // const HierFileSystem::`vftable' @ 0x621968

public:
    // 0x55FF50 | ??0HierFileSystem@@QAE@XZ
    HierFileSystem();

    // 0x560620 | ??_GHierFileSystem@@UAEPAXI@Z
    // 0x55FF70 | ??1HierFileSystem@@UAE@XZ
    ~HierFileSystem() override;

    // 0x560380 | ?ChangeDir@HierFileSystem@@UAEHPAD@Z
    b32 ChangeDir(const char* path) override;

    // 0x5602A0 | ?CreateOn@HierFileSystem@@UAEPAVStream@@PADPAXH@Z
    class Stream* CreateOn(const char* path, void* buffer, i32 buffer_len) override;

    // 0x5603C0 | ?FirstEntry@HierFileSystem@@UAEPAUFileInfo@@PAD@Z
    struct FileInfo* FirstEntry(const char* path) override;

    // 0x5603A0 | ?GetDir@HierFileSystem@@UAEHPADH@Z
    b32 GetDir(char* buffer, i32 buffer_len) override;

    // 0x560500 | ?NextEntry@HierFileSystem@@UAEPAUFileInfo@@PAU2@@Z
    struct FileInfo* NextEntry(struct FileInfo* info) override;

    // 0x560100 | ?OpenOn@HierFileSystem@@UAEPAVStream@@PADHPAXH@Z
    class Stream* OpenOn(const char* path, b32 read_only, void* buffer, i32 buffer_len) override;

    // 0x560040 | ?QueryOn@HierFileSystem@@UAEHPAD@Z
    b32 QueryOn(const char* path) override;

    // 0x55FF80 | ?ValidPath@HierFileSystem@@UAEHPAD@Z
    b32 ValidPath(const char* path) override;
};

check_size(HierFileSystem, 0x8);

// 0x55FF90 | ?FQN@@YAPADPAD@Z
const char* FQN(const char* path);

// 0x907BC8 | ?HFS@@3VHierFileSystem@@A
inline extern_var(0x907BC8, class HierFileSystem, HFS);

// 0x907BD0 | ?HierAllowPath@@3PADA
inline extern_var(0x907BD0, char*, HierAllowPath);

// 0x907B40 | ?HierPrefix@@3PADA
inline extern_var(0x907B40, char*, HierPrefix);

// 0x907BD4 | ?LogOpenOn@@3HA
inline extern_var(0x907BD4, i32, LogOpenOn);
