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
    agiworld:getmodel

    0x5154C0 | class agiMeshModel * __cdecl GetModel(char *,char *,char *) | ?GetModel@@YAPAVagiMeshModel@@PAD00@Z
    0x73E720 | class HashTable MeshModelHash | ?MeshModelHash@@3VHashTable@@A
*/

// 0x5154C0 | ?GetModel@@YAPAVagiMeshModel@@PAD00@Z
class agiMeshModel* GetModel(char* arg1, char* arg2, char* arg3);

// 0x73E720 | ?MeshModelHash@@3VHashTable@@A
inline extern_var(0x73E720, class HashTable, MeshModelHash);
