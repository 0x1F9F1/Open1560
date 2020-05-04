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
    return stub<thiscall_t<i32, mmPlayerDirectory*, char*>>(0xCF0D0_Offset, this, arg1);
}

i32 mmPlayerDirectory::FindPlayer(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerDirectory*, char*>>(0xCF320_Offset, this, arg1);
}

class MetaClass* mmPlayerDirectory::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmPlayerDirectory*>>(0xCFB80_Offset, this);
}

char* mmPlayerDirectory::GetFileName(char* arg1)
{
    return stub<thiscall_t<char*, mmPlayerDirectory*, char*>>(0xCF390_Offset, this, arg1);
}

char* mmPlayerDirectory::GetFileName(i32 arg1)
{
    return stub<thiscall_t<char*, mmPlayerDirectory*, i32>>(0xCF4B0_Offset, this, arg1);
}

char* mmPlayerDirectory::GetLastPlayer()
{
    return stub<thiscall_t<char*, mmPlayerDirectory*>>(0xCF0A0_Offset, this);
}

i32 mmPlayerDirectory::GetNumPlayers()
{
    return stub<thiscall_t<i32, mmPlayerDirectory*>>(0xCF090_Offset, this);
}

char* mmPlayerDirectory::GetPlayer(i32 arg1)
{
    return stub<thiscall_t<char*, mmPlayerDirectory*, i32>>(0xCF060_Offset, this, arg1);
}

char* mmPlayerDirectory::GetPlayerName(char* arg1)
{
    return stub<thiscall_t<char*, mmPlayerDirectory*, char*>>(0xCF420_Offset, this, arg1);
}

i32 mmPlayerDirectory::Load(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerDirectory*, char*>>(0xCF6A0_Offset, this, arg1);
}

i32 mmPlayerDirectory::LoadBinary(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerDirectory*, char*>>(0xCF870_Offset, this, arg1);
}

void mmPlayerDirectory::NewDirectory(i32 arg1)
{
    return stub<thiscall_t<void, mmPlayerDirectory*, i32>>(0xCEFA0_Offset, this, arg1);
}

i32 mmPlayerDirectory::RemovePlayer(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerDirectory*, char*>>(0xCF5A0_Offset, this, arg1);
}

i32 mmPlayerDirectory::Save(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmPlayerDirectory*, char*, i32>>(0xCF6D0_Offset, this, arg1, arg2);
}

i32 mmPlayerDirectory::SaveBinary(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerDirectory*, char*>>(0xCF770_Offset, this, arg1);
}

void mmPlayerDirectory::SetLastPlayer(char* arg1)
{
    return stub<thiscall_t<void, mmPlayerDirectory*, char*>>(0xCF010_Offset, this, arg1);
}

void mmPlayerDirectory::SetPlayer(i32 arg1, char* arg2, char* arg3)
{
    return stub<thiscall_t<void, mmPlayerDirectory*, i32, char*, char*>>(0xCEFE0_Offset, this, arg1, arg2, arg3);
}

void mmPlayerDirectory::DeclareFields()
{
    return stub<cdecl_t<void>>(0xCF9B0_Offset);
}

void mmPlayerDirectory::CreatePlayer(char* arg1, char* arg2)
{
    return stub<thiscall_t<void, mmPlayerDirectory*, char*, char*>>(0xCF210_Offset, this, arg1, arg2);
}

char* mmPlayerDirectory::MakeFileName()
{
    return stub<thiscall_t<char*, mmPlayerDirectory*>>(0xCF4E0_Offset, this);
}

struct MetaType* RefTo(struct MetaType* arg1, i32 arg2, i32* arg3)
{
    return stub<cdecl_t<struct MetaType*, struct MetaType*, i32, i32*>>(0xCFB90_Offset, arg1, arg2, arg3);
}

define_dummy_symbol(mmcityinfo_playerdir);
