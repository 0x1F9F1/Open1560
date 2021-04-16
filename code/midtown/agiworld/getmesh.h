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
    agiworld:getmesh

    0x512610 | void __cdecl FixTexFlags(class agiTexParameters &) | ?FixTexFlags@@YAXAAVagiTexParameters@@@Z
    0x5128A0 | class agiMeshSet * __cdecl GetMeshSet(char *,char *,class Vector3 *,int) | ?GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z
    0x5140E0 | public: __thiscall `class agiMeshSet * __cdecl GetMeshSet(char *,char *,class Vector3 *,int)'::`77'::DLPVertex2::DLPVertex2(void) | ??0DLPVertex2@?EN@??GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z@QAE@XZ
    0x5140F0 | public: __thiscall `class agiMeshSet * __cdecl GetMeshSet(char *,char *,class Vector3 *,int)'::`77'::DLPVertex2::DLPVertex2(struct DLPVertex2 const &) | ??0DLPVertex2@?EN@??GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z@QAE@ABU0@@Z
    0x514150 | public: __thiscall `class agiMeshSet * __cdecl GetMeshSet(char *,char *,class Vector3 *,int)'::`77'::nbuf::nbuf(void) | ??0nbuf@?EN@??GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z@QAE@XZ
    0x514170 | public: __thiscall `class agiMeshSet * __cdecl GetMeshSet(char *,char *,class Vector3 *,int)'::`77'::nbuf::nbuf(struct nbuf const &) | ??0nbuf@?EN@??GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z@QAE@ABU0@@Z
    0x73E6E4 | int IsSnowing | ?IsSnowing@@3HA
    0x73E70C | char * MeshCurrentObject | ?MeshCurrentObject@@3PADA
*/

// 0x512610 | ?FixTexFlags@@YAXAAVagiTexParameters@@@Z
ARTS_IMPORT void FixTexFlags(class agiTexParameters& arg1);

// 0x5128A0 | ?GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z
ARTS_IMPORT class agiMeshSet* GetMeshSet(char* arg1, char* arg2, class Vector3* arg3, i32 arg4);

// 0x73E6E4 | ?IsSnowing@@3HA
ARTS_IMPORT extern i32 IsSnowing;

// 0x73E70C | ?MeshCurrentObject@@3PADA
ARTS_IMPORT extern char* MeshCurrentObject;

#if 0
struct GetMeshSet_DLPVertex2
{
public:
    // 0x5140E0 | ??0DLPVertex2@?EN@??GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z@QAE@XZ
    ARTS_IMPORT ARTS_CDECL DLPVertex2(char* arg1, char* arg2, class Vector3* arg3, i32 arg4);

    // 0x5140F0 | ??0DLPVertex2@?EN@??GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z@QAE@ABU0@@Z
    ARTS_IMPORT ARTS_CDECL DLPVertex2(char* arg1, char* arg2, class Vector3* arg3, i32 arg4);
};

check_size(GetMeshSet_DLPVertex2, 0x0);

struct GetMeshSet_nbuf
{
public:
    // 0x514150 | ??0nbuf@?EN@??GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z@QAE@XZ
    ARTS_IMPORT ARTS_CDECL nbuf(char* arg1, char* arg2, class Vector3* arg3, i32 arg4);

    // 0x514170 | ??0nbuf@?EN@??GetMeshSet@@YAPAVagiMeshSet@@PAD0PAVVector3@@H@Z@QAE@ABU0@@Z | unused
    ARTS_IMPORT ARTS_CDECL nbuf(char* arg1, char* arg2, class Vector3* arg3, i32 arg4);
};

check_size(GetMeshSet_nbuf, 0x0);
#endif