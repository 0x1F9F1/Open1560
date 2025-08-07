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

#include "vector7/vector2.h"
#include "vector7/vector3.h"
#include "vector7/vector4.h"

template <typename Param, typename Def>
class agiLib;

class agiMtlDef;
class agiMtlParameters;

class agiTexDef;
class agiTexParameters;

class agiPhysDef;
class agiPhysParameters;

class DLPGroup;
class DLPPatch;
struct DLPVertex;

class DLPTemplate
{
public:
    // ??0DLPTemplate@@QAE@PAD@Z
    ARTS_EXPORT DLPTemplate(aconst char* name);

    // ?AddRef@DLPTemplate@@QAEXXZ
    ARTS_EXPORT void AddRef()
    {
        ++RefCount;
    }

    // ?BoundBox@DLPTemplate@@QAEHAAVVector3@@0PAD@Z
    ARTS_IMPORT i32 BoundBox(Vector3& arg1, Vector3& arg2, aconst char* arg3);

    // ?GetCentroid@DLPTemplate@@QAEHAAVVector3@@PAD@Z
    ARTS_IMPORT i32 GetCentroid(Vector3& arg1, aconst char* arg2);

    // ?GroupExists@DLPTemplate@@QAEPAVDLPGroup@@PAD@Z
    ARTS_IMPORT DLPGroup* GroupExists(aconst char* arg1);

    // ?Init@DLPTemplate@@QAEXHHH@Z
    ARTS_IMPORT void Init(i32 arg1, i32 arg2, i32 arg3);

    // ?InitRemap@DLPTemplate@@QAEXAAV?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@AAV?$agiLib@VagiTexParameters@@VagiTexDef@@@@AAV?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@@Z
    void InitRemap(agiLib<agiMtlParameters, agiMtlDef>& mlib, agiLib<agiTexParameters, agiTexDef>& tlib,
        agiLib<agiPhysParameters, agiPhysDef>& plib);

    // ?Load@DLPTemplate@@QAEHPAD@Z | unused
    i32 Load(aconst char* path);

    // ?Load@DLPTemplate@@QAEXPAVStream@@@Z
    ARTS_EXPORT void Load(Stream* file);

    // ?Release@DLPTemplate@@QAEHXZ
    ARTS_IMPORT i32 Release();

    // ?Restrict@DLPTemplate@@QAEHPAD@Z
    ARTS_IMPORT i32 Restrict(aconst char* arg1);

private:
    // ??1DLPTemplate@@AAE@XZ
    ARTS_EXPORT ~DLPTemplate();

    i32 NumGroups {};
    Ptr<DLPGroup[]> Groups;

    i32 NumPatches {};
    Ptr<DLPPatch[]> Patches;

    i32 NumVertices {};
    Ptr<Vector3[]> Vertices;

    ConstString Name;

    i32 MtlCount {};
    i32 TexCount {};
    i32 PhysCount {};

    Ptr<u16[]> MtlIds;
    Ptr<u16[]> TexIds;
    Ptr<u16[]> PhysIds;

    u32 RefCount {1};

    DLPGroup* RestrictGroup {};
};

check_size(DLPTemplate, 0x3C);

class DLPPatch
{
public:
    // ??0DLPPatch@@QAE@XZ | inline
    ARTS_EXPORT DLPPatch() = default;

    // ??1DLPPatch@@QAE@XZ | inline
    ARTS_EXPORT ~DLPPatch() = default;

    // ?Load@DLPPatch@@QAEXPAVStream@@@Z
    void Load(Stream* file);

    // ?Print@DLPPatch@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Print(Stream* arg1);

    // ?Save@DLPPatch@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Save(Stream* arg1);

    i16 SRes {};
    i16 TRes {};

    enum : u16
    {
        Flags_Enabled = 0x1,
        Flags_Flag4 = 0x4,
        Flags_Flag8 = 0x8,
        Flags_Flag100 = 0x100,
        Flags_Flag400 = 0x400,
    };

    u16 Flags {};

    enum : u16
    {
        ROpts_CPV = 0x1,
        ROpts_Emission = 0x2,
        ROpts_Shade = 0x4,
        ROpts_Solid = 0x8,
        ROpts_Cull = 0x10,
        ROpts_ZWrite = 0x20,
        ROpts_ZRead = 0x40,
        ROpts_Shadow = 0x80,
        ROpts_Flat = 0x100,
        ROpts_Antialias = 0x200,
        ROpts_Interpenetrate = 0x400,
    };

    u16 ROpts {};

    i16 MtlIdx {};
    i16 TexIdx {};
    i16 NumVertices {};
    i16 PhysIdx {};

    Ptr<DLPVertex[]> Vertices;
    ConstString Name;
};

check_size(DLPPatch, 0x18);

class DLPGroup final
{
public:
    // ??0DLPGroup@@QAE@XZ
    ARTS_EXPORT DLPGroup() = default;

    // ??0DLPGroup@@QAE@PAVDLPTemplate@@PAV0@@Z
    ARTS_IMPORT DLPGroup(DLPTemplate* arg1, DLPGroup* arg2);

    // ??1DLPGroup@@QAE@XZ
    ARTS_EXPORT ~DLPGroup() = default;

    // ?Init@DLPGroup@@QAEXHH@Z
    void Init(i32 num_verts, i32 num_patches);

    // ?Load@DLPGroup@@QAEXPAVStream@@@Z
    void Load(Stream* file);

    // ?Print@DLPGroup@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Print(Stream* arg1);

    // ?Save@DLPGroup@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Save(Stream* arg1);

    char Name[32] {};

    // The set of all vertex indices used by enabled patches in this group
    i32 NumVertices {};
    Ptr<u16[]> VertexIndices;

    i32 NumPatches {};
    Ptr<u16[]> PatchIndices;
};

check_size(DLPGroup, 0x30);

// ?PackAngle@@YAIM@Z
ARTS_IMPORT u32 PackAngle(f32 arg1);

// ?UnpackAngle@@YAME@Z
ARTS_IMPORT f32 UnpackAngle(u8 arg1);

// ?DLPTemplateHash@@3VHashTable@@A
ARTS_IMPORT extern HashTable DLPTemplateHash;

struct DLPVertex
{
public:
    // ?Load@DLPVertex@@QAEXPAVStream@@@Z
    void Load(Stream* file);

    // ?Save@DLPVertex@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Save(Stream* arg1);

    u32 Id {};
    Vector2 UV {};
    Vector4 Color {};
    Vector3 Normal {};
};

check_size(DLPVertex, 0x28);
