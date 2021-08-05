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
    mmcityinfo:playerdir

    0x4CEF00 | public: __thiscall mmPlayerDirectory::mmPlayerDirectory(void) | ??0mmPlayerDirectory@@QAE@XZ
    0x4CEF40 | public: virtual __thiscall mmPlayerDirectory::~mmPlayerDirectory(void) | ??1mmPlayerDirectory@@UAE@XZ
    0x4CEFA0 | public: void __thiscall mmPlayerDirectory::NewDirectory(int) | ?NewDirectory@mmPlayerDirectory@@QAEXH@Z
    0x4CEFE0 | public: void __thiscall mmPlayerDirectory::SetPlayer(int,char *,char *) | ?SetPlayer@mmPlayerDirectory@@QAEXHPAD0@Z
    0x4CF010 | public: void __thiscall mmPlayerDirectory::SetLastPlayer(char *) | ?SetLastPlayer@mmPlayerDirectory@@QAEXPAD@Z
    0x4CF060 | public: char * __thiscall mmPlayerDirectory::GetPlayer(int) | ?GetPlayer@mmPlayerDirectory@@QAEPADH@Z
    0x4CF090 | public: int __thiscall mmPlayerDirectory::GetNumPlayers(void) | ?GetNumPlayers@mmPlayerDirectory@@QAEHXZ
    0x4CF0A0 | public: char * __thiscall mmPlayerDirectory::GetLastPlayer(void) | ?GetLastPlayer@mmPlayerDirectory@@QAEPADXZ
    0x4CF0D0 | public: int __thiscall mmPlayerDirectory::AddPlayer(char *) | ?AddPlayer@mmPlayerDirectory@@QAEHPAD@Z
    0x4CF210 | private: void __thiscall mmPlayerDirectory::CreatePlayer(char *,char *) | ?CreatePlayer@mmPlayerDirectory@@AAEXPAD0@Z
    0x4CF320 | public: int __thiscall mmPlayerDirectory::FindPlayer(char *) | ?FindPlayer@mmPlayerDirectory@@QAEHPAD@Z
    0x4CF390 | public: char * __thiscall mmPlayerDirectory::GetFileName(char *) | ?GetFileName@mmPlayerDirectory@@QAEPADPAD@Z
    0x4CF420 | public: char * __thiscall mmPlayerDirectory::GetPlayerName(char *) | ?GetPlayerName@mmPlayerDirectory@@QAEPADPAD@Z
    0x4CF4B0 | public: char * __thiscall mmPlayerDirectory::GetFileName(int) | ?GetFileName@mmPlayerDirectory@@QAEPADH@Z
    0x4CF4E0 | private: char * __thiscall mmPlayerDirectory::MakeFileName(void) | ?MakeFileName@mmPlayerDirectory@@AAEPADXZ
    0x4CF5A0 | public: int __thiscall mmPlayerDirectory::RemovePlayer(char *) | ?RemovePlayer@mmPlayerDirectory@@QAEHPAD@Z
    0x4CF6A0 | public: int __thiscall mmPlayerDirectory::Load(char *) | ?Load@mmPlayerDirectory@@QAEHPAD@Z
    0x4CF6D0 | public: int __thiscall mmPlayerDirectory::Save(char *,int) | ?Save@mmPlayerDirectory@@QAEHPADH@Z
    0x4CF770 | public: int __thiscall mmPlayerDirectory::SaveBinary(char *) | ?SaveBinary@mmPlayerDirectory@@QAEHPAD@Z
    0x4CF870 | public: int __thiscall mmPlayerDirectory::LoadBinary(char *) | ?LoadBinary@mmPlayerDirectory@@QAEHPAD@Z
    0x4CF9B0 | public: static void __cdecl mmPlayerDirectory::DeclareFields(void) | ?DeclareFields@mmPlayerDirectory@@SAXXZ
    0x4CFB80 | public: virtual class MetaClass * __thiscall mmPlayerDirectory::GetClass(void) | ?GetClass@mmPlayerDirectory@@UAEPAVMetaClass@@XZ
    0x4CFB90 | struct MetaType * __cdecl RefTo(struct MetaType *,int,int *) | ?RefTo@@YAPAUMetaType@@PAU1@HPAH@Z
    0x4CFBD0 | public: virtual void * __thiscall mmPlayerDirectory::`vector deleting destructor'(unsigned int) | ??_EmmPlayerDirectory@@UAEPAXI@Z
    0x61F900 | const mmPlayerDirectory::`vftable' | ??_7mmPlayerDirectory@@6B@
    0x708548 | class MetaClass mmPlayerDirectoryMetaClass | ?mmPlayerDirectoryMetaClass@@3VMetaClass@@A
*/

#include "infobase.h"

class mmPlayerDirectory final : public mmInfoBase
{
    // const mmPlayerDirectory::`vftable'

public:
    // ??0mmPlayerDirectory@@QAE@XZ
    ARTS_IMPORT mmPlayerDirectory();

    // ??_EmmPlayerDirectory@@UAEPAXI@Z
    // ??1mmPlayerDirectory@@UAE@XZ
    ARTS_IMPORT ~mmPlayerDirectory() override;

    // ?AddPlayer@mmPlayerDirectory@@QAEHPAD@Z
    ARTS_IMPORT i32 AddPlayer(char* arg1);

    // ?FindPlayer@mmPlayerDirectory@@QAEHPAD@Z
    ARTS_IMPORT i32 FindPlayer(char* arg1);

    // ?GetClass@mmPlayerDirectory@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?GetFileName@mmPlayerDirectory@@QAEPADPAD@Z
    ARTS_IMPORT char* GetFileName(char* arg1);

    // ?GetFileName@mmPlayerDirectory@@QAEPADH@Z
    ARTS_IMPORT char* GetFileName(i32 arg1);

    // ?GetLastPlayer@mmPlayerDirectory@@QAEPADXZ
    ARTS_IMPORT char* GetLastPlayer();

    // ?GetNumPlayers@mmPlayerDirectory@@QAEHXZ
    ARTS_IMPORT i32 GetNumPlayers();

    // ?GetPlayer@mmPlayerDirectory@@QAEPADH@Z
    ARTS_IMPORT char* GetPlayer(i32 arg1);

    // ?GetPlayerName@mmPlayerDirectory@@QAEPADPAD@Z | unused
    ARTS_IMPORT char* GetPlayerName(char* arg1);

    // ?Load@mmPlayerDirectory@@QAEHPAD@Z
    ARTS_IMPORT i32 Load(char* arg1);

    // ?LoadBinary@mmPlayerDirectory@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadBinary(char* arg1);

    // ?NewDirectory@mmPlayerDirectory@@QAEXH@Z
    ARTS_IMPORT void NewDirectory(i32 arg1);

    // ?RemovePlayer@mmPlayerDirectory@@QAEHPAD@Z
    ARTS_IMPORT i32 RemovePlayer(char* arg1);

    // ?Save@mmPlayerDirectory@@QAEHPADH@Z
    ARTS_IMPORT i32 Save(char* arg1, i32 arg2);

    // ?SaveBinary@mmPlayerDirectory@@QAEHPAD@Z
    ARTS_IMPORT i32 SaveBinary(char* arg1);

    // ?SetLastPlayer@mmPlayerDirectory@@QAEXPAD@Z
    ARTS_IMPORT void SetLastPlayer(char* arg1);

    // ?SetPlayer@mmPlayerDirectory@@QAEXHPAD0@Z
    ARTS_IMPORT void SetPlayer(i32 arg1, char* arg2, char* arg3);

    // ?DeclareFields@mmPlayerDirectory@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?CreatePlayer@mmPlayerDirectory@@AAEXPAD0@Z | unused
    ARTS_IMPORT void CreatePlayer(char* arg1, char* arg2);

    // ?MakeFileName@mmPlayerDirectory@@AAEPADXZ
    ARTS_IMPORT char* MakeFileName();

    u8 gap88[0x5C];
};

check_size(mmPlayerDirectory, 0xE4);

// ?RefTo@@YAPAUMetaType@@PAU1@HPAH@Z | inline
ARTS_IMPORT struct MetaType* RefTo(struct MetaType* arg1, i32 arg2, i32* arg3);

// ?mmPlayerDirectoryMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmPlayerDirectoryMetaClass;
