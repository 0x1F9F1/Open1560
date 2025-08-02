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

class DLPTemplate;

// ?CheckLibraries@@YAXXZ
ARTS_IMPORT void CheckLibraries();

// TODO: Use RcOwner
// ?GetDLPTemplate@@YAPAVDLPTemplate@@PAD@Z
ARTS_IMPORT DLPTemplate* GetDLPTemplate(char* arg1);

// ?OutOfDate@@YAHPAD0@Z
ARTS_EXPORT b32 OutOfDate(char* dst_file, char* src_file);

// ?DLPTemplateBadHash@@3VHashTable@@A
ARTS_IMPORT extern HashTable DLPTemplateBadHash;

// ?FlagGetDLPTemplateCalls@@3HA
ARTS_IMPORT extern i32 FlagGetDLPTemplateCalls;
