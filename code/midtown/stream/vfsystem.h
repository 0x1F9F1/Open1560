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

#include "fsystem.h"

static constexpr u32 AresMagic = 0x53455241;

struct AresHeader
{
    u32 Magic {0};
    u32 FileCount {0};
    u32 RootCount {0};
    u32 NamesSize {0};
};

check_size(AresHeader, 0x10);

struct VirtualFileInode
{
    u32 dword0 {0};
    u32 dword4 {0};
    u32 dword8 {0};

    u32 GetOffset() const
    {
        return dword0;
    }

    u32 GetSize() const
    {
        return dword4 & 0x7FFFFF;
    }

    u32 GetEntryIndex() const
    {
        return dword0;
    }

    u32 GetEntryCount() const
    {
        return dword4 & 0x7FFFFF;
    }

    bool IsDirectory() const
    {
        return (dword8 & 1) != 0;
    }

    u32 GetNameOffset() const
    {
        return (dword8 >> 14) & 0x3FFFF;
    }

    u32 GetExtOffset() const
    {
        return (dword4 >> 23) & 0x1FF;
    }

    u32 GetNameInteger() const
    {
        return (dword8 >> 1) & 0x1FFF;
    }

    void SetOffset(u32 offset)
    {
        dword0 = offset;
    }

    void SetSize(u32 size)
    {
        dword4 = (dword4 & 0xFF800000) | (size);
    }

    void SetEntryIndex(u32 index)
    {
        dword0 = index;
    }

    void SetEntryCount(u32 size)
    {
        dword4 = (dword4 & 0xFF800000) | (size);
    }

    void SetIsDirectory(bool is_dir)
    {
        dword8 = (dword8 & 0xFFFFFFFE) | u32(is_dir);
    }

    void SetNameOffset(u32 offset)
    {
        dword8 = (dword8 & 0x00003FFF) | (offset << 14);
    }

    void SetExtOffset(u32 offset)
    {
        dword4 = (dword4 & 0x007FFFFF) | (offset << 23);
    }

    void SetNameInteger(u32 value)
    {
        dword8 = (dword8 & 0xFFFFC001) | (value << 1);
    }
};

check_size(VirtualFileInode, 0xC);

class VirtualFileSystem : public FileSystem
{
    // const VirtualFileSystem::`vftable' @ 0x6219A8

public:
    // 0x560650 | ??0VirtualFileSystem@@QAE@PAVStream@@@Z
    VirtualFileSystem(class Stream* stream);

    // 0x560D80 | ??_EVirtualFileSystem@@UAEPAXI@Z
    // 0x560710 | ??1VirtualFileSystem@@UAE@XZ
    ~VirtualFileSystem() override;

    // 0x560B90 | ?ChangeDir@VirtualFileSystem@@UAEHPAD@Z
    b32 ChangeDir(const char* path) override;

    // 0x560B80 | ?CreateOn@VirtualFileSystem@@UAEPAVStream@@PADPAXH@Z
    class Stream* CreateOn(const char* path, void* buffer, i32 buffer_len) override;

    // 0x560BB0 | ?FirstEntry@VirtualFileSystem@@UAEPAUFileInfo@@PAD@Z
    struct FileInfo* FirstEntry(const char* path) override;

    // 0x560BA0 | ?GetDir@VirtualFileSystem@@UAEHPADH@Z
    b32 GetDir(char* buffer, i32 buffer_len) override;

    // 0x560D00 | ?NextEntry@VirtualFileSystem@@UAEPAUFileInfo@@PAU2@@Z
    struct FileInfo* NextEntry(struct FileInfo* info) override;

    // 0x560AD0 | ?OpenOn@VirtualFileSystem@@UAEPAVStream@@PADHPAXH@Z
    class Stream* OpenOn(const char* path, i32 mode, void* buffer, i32 buffer_len) override;

    // 0x560A50 | ?PagerInfo@VirtualFileSystem@@UAEHPADAAUPagerInfo_t@@@Z
    b32 PagerInfo(const char* path, struct PagerInfo_t& info) override;

    // 0x560A00 | ?QueryOn@VirtualFileSystem@@UAEHPAD@Z
    b32 QueryOn(const char* path) override;

    // 0x560780 | ?ValidPath@VirtualFileSystem@@UAEHPAD@Z
    b32 ValidPath(const char* path) override;

    // 0x560800 | ?ExpandName@VirtualFileSystem@@SAXPADPAUVirtualFileInode@@0@Z
    [[deprecated]] static void ExpandName(char* buf, struct VirtualFileInode* node, const char* names);

    static void ExpandName(char* buf, i32 buf_len, struct VirtualFileInode* node, const char* names);

    // 0x560920 | ?Lookup@VirtualFileSystem@@SAPAUVirtualFileInode@@PAU2@HPAD1@Z
    static struct VirtualFileInode* Lookup(
        struct VirtualFileInode* nodes, i32 node_count, const char* names, char* path);

    // 0x560790 | ?NormalizeName@VirtualFileSystem@@SAXPAD0@Z
    [[deprecated]] static void NormalizeName(char* buf, const char* path);

    static void NormalizeName(char* buf, i32 buf_len, const char* path);

private:
    friend struct VirtualFileEntry;

    VirtualFileInode* Lookup(const char* path);
    void ExpandName(char* buf, i32 buf_len, struct VirtualFileInode* node);

    Ptr<Stream> base_stream_ {nullptr};
    AresHeader file_header_ {};
    Ptr<VirtualFileInode[]> file_nodes_ {nullptr};
    Ptr<char[]> file_names_ {nullptr};
};

check_size(VirtualFileSystem, 0x24);
