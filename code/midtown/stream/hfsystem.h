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

class HierFileSystem final : public FileSystem
{
public:
    // ??0HierFileSystem@@QAE@XZ
    HierFileSystem();

    // ??1HierFileSystem@@UAE@XZ
    ~HierFileSystem() override;

    // ?ChangeDir@HierFileSystem@@UAEHPAD@Z
    b32 ChangeDir(const char* path) override;

    // ?CreateOn@HierFileSystem@@UAEPAVStream@@PADPAXH@Z
    Owner<Stream> CreateOn(const char* path, void* buffer, isize buffer_len) override;

    // ?FirstEntry@HierFileSystem@@UAEPAUFileInfo@@PAD@Z
    FileInfo* FirstEntry(const char* path) override;

    // ?GetDir@HierFileSystem@@UAEHPADH@Z
    b32 GetDir(char* buffer, isize buffer_len) override;

    // ?NextEntry@HierFileSystem@@UAEPAUFileInfo@@PAU2@@Z
    FileInfo* NextEntry(FileInfo* info) override;

    // ?OpenOn@HierFileSystem@@UAEPAVStream@@PADHPAXH@Z
    Owner<Stream> OpenOn(const char* path, b32 read_only, void* buffer, isize buffer_len) override;

    // ?QueryOn@HierFileSystem@@UAEHPAD@Z
    b32 QueryOn(const char* path) override;

    // ?ValidPath@HierFileSystem@@UAEHPAD@Z
    b32 ValidPath(const char* path) override;
};

check_size(HierFileSystem, 0x8);

// ?FQN@@YAPADPAD@Z
const char* FQN(const char* path);

// ?HFS@@3VHierFileSystem@@A
extern HierFileSystem HFS;

// ?HierAllowPath@@3PADA
extern aconst char* HierAllowPath; // Null Separated

// ?HierPrefix@@3PADA
extern aconst char* HierPrefix;

// ?LogOpenOn@@3HA
extern b32 LogOpenOn;
