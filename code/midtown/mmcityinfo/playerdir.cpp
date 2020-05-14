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

define_dummy_symbol(mmcityinfo_playerdir);

#include "playerdir.h"

mmPlayerDirectory::mmPlayerDirectory()
{
    unimplemented();
}

mmPlayerDirectory::~mmPlayerDirectory()
{
    unimplemented();
}

i32 mmPlayerDirectory::AddPlayer(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerDirectory*, char*>>(0x4CF0D0, this, arg1);
}

i32 mmPlayerDirectory::FindPlayer(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerDirectory*, char*>>(0x4CF320, this, arg1);
}

class MetaClass* mmPlayerDirectory::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmPlayerDirectory*>>(0x4CFB80, this);
}

char* mmPlayerDirectory::GetFileName(char* arg1)
{
    return stub<thiscall_t<char*, mmPlayerDirectory*, char*>>(0x4CF390, this, arg1);
}

char* mmPlayerDirectory::GetFileName(i32 arg1)
{
    return stub<thiscall_t<char*, mmPlayerDirectory*, i32>>(0x4CF4B0, this, arg1);
}

char* mmPlayerDirectory::GetLastPlayer()
{
    return stub<thiscall_t<char*, mmPlayerDirectory*>>(0x4CF0A0, this);
}

i32 mmPlayerDirectory::GetNumPlayers()
{
    return stub<thiscall_t<i32, mmPlayerDirectory*>>(0x4CF090, this);
}

char* mmPlayerDirectory::GetPlayer(i32 arg1)
{
    return stub<thiscall_t<char*, mmPlayerDirectory*, i32>>(0x4CF060, this, arg1);
}

char* mmPlayerDirectory::GetPlayerName(char* arg1)
{
    return stub<thiscall_t<char*, mmPlayerDirectory*, char*>>(0x4CF420, this, arg1);
}

i32 mmPlayerDirectory::Load(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerDirectory*, char*>>(0x4CF6A0, this, arg1);
}

i32 mmPlayerDirectory::LoadBinary(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerDirectory*, char*>>(0x4CF870, this, arg1);
}

void mmPlayerDirectory::NewDirectory(i32 arg1)
{
    return stub<thiscall_t<void, mmPlayerDirectory*, i32>>(0x4CEFA0, this, arg1);
}

i32 mmPlayerDirectory::RemovePlayer(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerDirectory*, char*>>(0x4CF5A0, this, arg1);
}

i32 mmPlayerDirectory::Save(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmPlayerDirectory*, char*, i32>>(0x4CF6D0, this, arg1, arg2);
}

i32 mmPlayerDirectory::SaveBinary(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerDirectory*, char*>>(0x4CF770, this, arg1);
}

void mmPlayerDirectory::SetLastPlayer(char* arg1)
{
    return stub<thiscall_t<void, mmPlayerDirectory*, char*>>(0x4CF010, this, arg1);
}

void mmPlayerDirectory::SetPlayer(i32 arg1, char* arg2, char* arg3)
{
    return stub<thiscall_t<void, mmPlayerDirectory*, i32, char*, char*>>(0x4CEFE0, this, arg1, arg2, arg3);
}

void mmPlayerDirectory::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4CF9B0);
}

void mmPlayerDirectory::CreatePlayer(char* arg1, char* arg2)
{
    return stub<thiscall_t<void, mmPlayerDirectory*, char*, char*>>(0x4CF210, this, arg1, arg2);
}

char* mmPlayerDirectory::MakeFileName()
{
    return stub<thiscall_t<char*, mmPlayerDirectory*>>(0x4CF4E0, this);
}

struct MetaType* RefTo(struct MetaType* arg1, i32 arg2, i32* arg3)
{
    return stub<cdecl_t<struct MetaType*, struct MetaType*, i32, i32*>>(0x4CFB90, arg1, arg2, arg3);
}
