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

class agiMeshSet;
class agiTexParameters;

// ?FixTexFlags@@YAXAAVagiTexParameters@@@Z
ARTS_EXPORT void FixTexFlags(agiTexParameters& tex);

// ?GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z
ARTS_IMPORT agiMeshSet* GetMeshSet(char* arg1, char* arg2, Vector3* arg3, i32 arg4);

// ?IsSnowing@@3HA
ARTS_IMPORT extern i32 IsSnowing;

// ?MeshCurrentObject@@3PADA
ARTS_IMPORT extern char* MeshCurrentObject;

#if 0
struct GetMeshSet_DLPVertex2
{
public:
    // ??0DLPVertex2@?EN@??GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z@QAE@XZ
    ARTS_IMPORT ARTS_CDECL DLPVertex2(char* arg1, char* arg2,  Vector3* arg3, i32 arg4);

    // ??0DLPVertex2@?EN@??GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z@QAE@ABU0@@Z
    ARTS_IMPORT ARTS_CDECL DLPVertex2(char* arg1, char* arg2,  Vector3* arg3, i32 arg4);
};

check_size(GetMeshSet_DLPVertex2, 0x0);

struct GetMeshSet_nbuf
{
public:
    // ??0nbuf@?EN@??GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z@QAE@XZ
    ARTS_IMPORT ARTS_CDECL nbuf(char* arg1, char* arg2,  Vector3* arg3, i32 arg4);

    };

check_size(GetMeshSet_nbuf, 0x0);
#endif
