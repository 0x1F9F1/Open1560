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
    agi:getdlp

    0x5569D0 | int __cdecl OutOfDate(char *,char *) | ?OutOfDate@@YAHPAD0@Z
    0x556A30 | void __cdecl CheckLibraries(void) | ?CheckLibraries@@YAXXZ
    0x556B60 | class DLPTemplate * __cdecl GetDLPTemplate(char *) | ?GetDLPTemplate@@YAPAVDLPTemplate@@PAD@Z
    0x556DF0 | int __cdecl GetGroupVerts(char *,char *,class Vector3 *,int) | ?GetGroupVerts@@YAHPAD0PAVVector3@@H@Z
    0x8FAFD0 | class HashTable DLPTemplateBadHash | ?DLPTemplateBadHash@@3VHashTable@@A
    0x8FAFE0 | int FlagGetDLPTemplateCalls | ?FlagGetDLPTemplateCalls@@3HA
*/

// 0x556A30 | ?CheckLibraries@@YAXXZ
void CheckLibraries();

// 0x556B60 | ?GetDLPTemplate@@YAPAVDLPTemplate@@PAD@Z
class DLPTemplate* GetDLPTemplate(char* arg1);

// 0x556DF0 | ?GetGroupVerts@@YAHPAD0PAVVector3@@H@Z
i32 GetGroupVerts(char* arg1, char* arg2, class Vector3* arg3, i32 arg4);

// 0x5569D0 | ?OutOfDate@@YAHPAD0@Z
i32 OutOfDate(char* arg1, char* arg2);

// 0x8FAFD0 | ?DLPTemplateBadHash@@3VHashTable@@A
inline extern_var(0x8FAFD0, class HashTable, DLPTemplateBadHash);

// 0x8FAFE0 | ?FlagGetDLPTemplateCalls@@3HA
inline extern_var(0x8FAFE0, i32, FlagGetDLPTemplateCalls);
