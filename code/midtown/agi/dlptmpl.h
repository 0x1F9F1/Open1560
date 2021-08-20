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
    agi:dlptmpl

    0x5582E0 | public: __thiscall DLPTemplate::DLPTemplate(char *) | ??0DLPTemplate@@QAE@PAD@Z
    0x558330 | private: __thiscall DLPTemplate::~DLPTemplate(void) | ??1DLPTemplate@@AAE@XZ
    0x5583D0 | public: void __thiscall DLPTemplate::Init(int,int,int) | ?Init@DLPTemplate@@QAEXHHH@Z
    0x558500 | public: void __thiscall DLPTemplate::Save(class Stream *) | ?Save@DLPTemplate@@QAEXPAVStream@@@Z
    0x558640 | public: void __thiscall DLPTemplate::Load(class Stream *) | ?Load@DLPTemplate@@QAEXPAVStream@@@Z
    0x558990 | public: char * __thiscall DLPPatch::GetProp(char *) | ?GetProp@DLPPatch@@QAEPADPAD@Z
    0x558A40 | public: void __thiscall DLPTemplate::InitRemap(class agiLib<class agiMtlParameters,class agiMtlDef> &,class agiLib<class agiTexParameters,class agiTexDef> &,class agiLib<class agiPhysParameters,class agiPhysDef> &) | ?InitRemap@DLPTemplate@@QAEXAAV?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@AAV?$agiLib@VagiTexParameters@@VagiTexDef@@@@AAV?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@@Z
    0x558B60 | public: int __thiscall DLPTemplate::Load(char *) | ?Load@DLPTemplate@@QAEHPAD@Z
    0x558BA0 | public: void __thiscall DLPTemplate::Print(class Stream *) | ?Print@DLPTemplate@@QAEXPAVStream@@@Z
    0x558C90 | public: __thiscall DLPGroup::DLPGroup(void) | ??0DLPGroup@@QAE@XZ
    0x558CB0 | public: __thiscall DLPGroup::DLPGroup(class DLPTemplate *,class DLPGroup *) | ??0DLPGroup@@QAE@PAVDLPTemplate@@PAV0@@Z
    0x558E90 | public: __thiscall DLPGroup::~DLPGroup(void) | ??1DLPGroup@@QAE@XZ
    0x558EC0 | public: void __thiscall DLPGroup::Load(class Stream *) | ?Load@DLPGroup@@QAEXPAVStream@@@Z
    0x558F40 | public: void __thiscall DLPGroup::Save(class Stream *) | ?Save@DLPGroup@@QAEXPAVStream@@@Z
    0x558FC0 | public: void __thiscall DLPGroup::Print(class Stream *) | ?Print@DLPGroup@@QAEXPAVStream@@@Z
    0x559040 | public: void __thiscall DLPGroup::Init(int,int) | ?Init@DLPGroup@@QAEXHH@Z
    0x559080 | public: void __thiscall DLPPatch::Load(class Stream *) | ?Load@DLPPatch@@QAEXPAVStream@@@Z
    0x559180 | public: void __thiscall DLPPatch::Save(class Stream *) | ?Save@DLPPatch@@QAEXPAVStream@@@Z
    0x559250 | public: void __thiscall DLPPatch::Print(class Stream *) | ?Print@DLPPatch@@QAEXPAVStream@@@Z
    0x559310 | float __cdecl UnpackAngle(unsigned char) | ?UnpackAngle@@YAME@Z
    0x559340 | void __cdecl UnpackNormal(class Vector3 &,unsigned short &) | ?UnpackNormal@@YAXAAVVector3@@AAG@Z
    0x5593A0 | unsigned int __cdecl PackAngle(float) | ?PackAngle@@YAIM@Z
    0x559400 | void __cdecl PackNormal(unsigned short &,class Vector3 &) | ?PackNormal@@YAXAAGAAVVector3@@@Z
    0x5594D0 | public: void __thiscall DLPVertex::Load(class Stream *) | ?Load@DLPVertex@@QAEXPAVStream@@@Z
    0x5595A0 | public: void __thiscall DLPVertex::Save(class Stream *) | ?Save@DLPVertex@@QAEXPAVStream@@@Z
    0x559630 | public: class DLPGroup * __thiscall DLPTemplate::GroupExists(char *) | ?GroupExists@DLPTemplate@@QAEPAVDLPGroup@@PAD@Z
    0x5596B0 | public: int __thiscall DLPTemplate::Restrict(char *) | ?Restrict@DLPTemplate@@QAEHPAD@Z
    0x5597C0 | public: void __thiscall DLPTemplate::AddRef(void) | ?AddRef@DLPTemplate@@QAEXXZ
    0x5597D0 | public: int __thiscall DLPTemplate::Release(void) | ?Release@DLPTemplate@@QAEHXZ
    0x559800 | public: int __thiscall DLPTemplate::GetVertexCentroid(class Vector3 &,char *) | ?GetVertexCentroid@DLPTemplate@@QAEHAAVVector3@@PAD@Z
    0x559930 | public: int __thiscall DLPTemplate::GetCentroid(class Vector3 &,char *) | ?GetCentroid@DLPTemplate@@QAEHAAVVector3@@PAD@Z
    0x5599B0 | public: class Vector3 * __thiscall DLPTemplate::GetGroupVertex(char *) | ?GetGroupVertex@DLPTemplate@@QAEPAVVector3@@PAD@Z
    0x559A00 | public: int __thiscall DLPTemplate::BoundBox(class Vector3 &,class Vector3 &,char *) | ?BoundBox@DLPTemplate@@QAEHAAVVector3@@0PAD@Z
    0x559C20 | public: void * __thiscall DLPGroup::`vector deleting destructor'(unsigned int) | ??_EDLPGroup@@QAEPAXI@Z
    0x559C80 | public: void * __thiscall DLPPatch::`vector deleting destructor'(unsigned int) | ??_EDLPPatch@@QAEPAXI@Z
    0x559CF0 | public: __thiscall agiLib<class agiMtlParameters,class agiMtlDef>::~agiLib<class agiMtlParameters,class agiMtlDef>(void) | ??1?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@QAE@XZ
    0x559D90 | public: int __thiscall agiLib<class agiMtlParameters,class agiMtlDef>::Add(class agiMtlParameters &) | ?Add@?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@QAEHAAVagiMtlParameters@@@Z
    0x559EF0 | public: int __thiscall agiLib<class agiPhysParameters,class agiPhysDef>::Add(class agiPhysParameters &) | ?Add@?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@QAEHAAVagiPhysParameters@@@Z
    0x55A030 | public: void __thiscall agiLib<class agiMtlParameters,class agiMtlDef>::Kill(void) | ?Kill@?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@QAEXXZ
    0x55A080 | public: void __thiscall agiLib<class agiMtlParameters,class agiMtlDef>::Init(int) | ?Init@?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@QAEXH@Z
    0x55A140 | public: void __thiscall agiLib<class agiTexParameters,class agiTexDef>::Kill(void) | ?Kill@?$agiLib@VagiTexParameters@@VagiTexDef@@@@QAEXXZ
    0x55A190 | public: void __thiscall agiLib<class agiTexParameters,class agiTexDef>::Init(int) | ?Init@?$agiLib@VagiTexParameters@@VagiTexDef@@@@QAEXH@Z
    0x55A250 | public: void __thiscall agiLib<class agiPhysParameters,class agiPhysDef>::Kill(void) | ?Kill@?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@QAEXXZ
    0x55A290 | public: void __thiscall agiLib<class agiPhysParameters,class agiPhysDef>::Init(int) | ?Init@?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@QAEXH@Z
    0x55A310 | public: __thiscall DLPPatch::DLPPatch(void) | ??0DLPPatch@@QAE@XZ
    0x55A320 | public: __thiscall DLPPatch::~DLPPatch(void) | ??1DLPPatch@@QAE@XZ
    0x903130 | class HashTable DLPTemplateHash | ?DLPTemplateHash@@3VHashTable@@A
*/

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
    ARTS_EXPORT DLPTemplate(char* name);

    // ?AddRef@DLPTemplate@@QAEXXZ
    ARTS_EXPORT void AddRef()
    {
        ++RefCount;
    }

    // ?BoundBox@DLPTemplate@@QAEHAAVVector3@@0PAD@Z
    ARTS_IMPORT i32 BoundBox(Vector3& arg1, Vector3& arg2, char* arg3);

    // ?GetCentroid@DLPTemplate@@QAEHAAVVector3@@PAD@Z
    ARTS_IMPORT i32 GetCentroid(Vector3& arg1, char* arg2);

    // ?GetGroupVertex@DLPTemplate@@QAEPAVVector3@@PAD@Z | unused
    ARTS_IMPORT Vector3* GetGroupVertex(char* arg1);

    // ?GetVertexCentroid@DLPTemplate@@QAEHAAVVector3@@PAD@Z | unused
    ARTS_IMPORT i32 GetVertexCentroid(Vector3& arg1, char* arg2);

    // ?GroupExists@DLPTemplate@@QAEPAVDLPGroup@@PAD@Z
    ARTS_IMPORT DLPGroup* GroupExists(char* arg1);

    // ?Init@DLPTemplate@@QAEXHHH@Z
    ARTS_IMPORT void Init(i32 arg1, i32 arg2, i32 arg3);

    // ?InitRemap@DLPTemplate@@QAEXAAV?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@AAV?$agiLib@VagiTexParameters@@VagiTexDef@@@@AAV?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@@Z
    ARTS_IMPORT void InitRemap(agiLib<agiMtlParameters, agiMtlDef>& mlib, agiLib<agiTexParameters, agiTexDef>& tlib,
        agiLib<agiPhysParameters, agiPhysDef>& plib);

    // ?Load@DLPTemplate@@QAEHPAD@Z | unused
    ARTS_EXPORT i32 Load(char* path);

    // ?Load@DLPTemplate@@QAEXPAVStream@@@Z
    ARTS_EXPORT void Load(Stream* file);

    // ?Print@DLPTemplate@@QAEXPAVStream@@@Z | unused
    ARTS_IMPORT void Print(Stream* arg1);

    // ?Release@DLPTemplate@@QAEHXZ
    ARTS_IMPORT i32 Release();

    // ?Restrict@DLPTemplate@@QAEHPAD@Z
    ARTS_IMPORT i32 Restrict(char* arg1);

    // ?Save@DLPTemplate@@QAEXPAVStream@@@Z | unused
    ARTS_IMPORT void Save(Stream* arg1);

private:
    // ??1DLPTemplate@@AAE@XZ
    ARTS_EXPORT ~DLPTemplate();

    i32 NumGroups {0};
    Ptr<DLPGroup[]> Groups;

    i32 NumPatches {0};
    Ptr<DLPPatch[]> Patches;

    i32 NumVertices {0};
    Ptr<Vector3[]> Vertices;

    ConstString Name;

    i32 MtlCount {0};
    i32 TexCount {0};
    i32 PhysCount {0};

    Ptr<i16[]> MtlIds;
    Ptr<i16[]> TexIds;
    Ptr<i16[]> PhysIds;

    u32 RefCount {1};

    DLPGroup* RestrictGroup {nullptr};
};

check_size(DLPTemplate, 0x3C);

class DLPPatch
{
public:
    // ??0DLPPatch@@QAE@XZ | inline
    ARTS_EXPORT DLPPatch() = default;

    // ??_EDLPPatch@@QAEPAXI@Z | unused
    // ??1DLPPatch@@QAE@XZ | inline
    ARTS_EXPORT ~DLPPatch() = default;

    // ?GetProp@DLPPatch@@QAEPADPAD@Z | unused
    ARTS_IMPORT char* GetProp(char* arg1);

    // ?Load@DLPPatch@@QAEXPAVStream@@@Z
    ARTS_EXPORT void Load(Stream* file);

    // ?Print@DLPPatch@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Print(Stream* arg1);

    // ?Save@DLPPatch@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Save(Stream* arg1);

    i16 SRes {0};
    i16 TRes {0};

    enum : u16
    {
        Flags_Enabled = 0x1,
        Flags_Flag8 = 0x8,
    };

    u16 Flags {0};

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

    u16 ROpts {0};

    i16 MtlIdx {0};
    i16 TexIdx {0};
    i16 NumVertices {0};
    i16 PhysIdx {0};

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

    // ??_EDLPGroup@@QAEPAXI@Z | unused
    // ??1DLPGroup@@QAE@XZ
    ARTS_EXPORT ~DLPGroup() = default;

    // ?Init@DLPGroup@@QAEXHH@Z
    ARTS_EXPORT void Init(i32 num_verts, i32 num_patches);

    // ?Load@DLPGroup@@QAEXPAVStream@@@Z
    ARTS_EXPORT void Load(Stream* file);

    // ?Print@DLPGroup@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Print(Stream* arg1);

    // ?Save@DLPGroup@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Save(Stream* arg1);

    char Name[32] {};

    i32 NumVertices {0};
    Ptr<u16[]> VertexIndices;

    i32 NumPatches {0};
    Ptr<u16[]> PatchIndices;
};

check_size(DLPGroup, 0x30);

// ?PackAngle@@YAIM@Z
ARTS_IMPORT u32 PackAngle(f32 arg1);

// ?PackNormal@@YAXAAGAAVVector3@@@Z | unused
ARTS_IMPORT void PackNormal(u16& arg1, Vector3& arg2);

// ?UnpackAngle@@YAME@Z
ARTS_IMPORT f32 UnpackAngle(u8 arg1);

// ?UnpackNormal@@YAXAAVVector3@@AAG@Z | unused
ARTS_IMPORT void UnpackNormal(Vector3& arg1, u16& arg2);

// ?DLPTemplateHash@@3VHashTable@@A
ARTS_IMPORT extern HashTable DLPTemplateHash;

struct DLPVertex
{
public:
    // ?Load@DLPVertex@@QAEXPAVStream@@@Z
    ARTS_EXPORT void Load(Stream* file);

    // ?Save@DLPVertex@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Save(Stream* arg1);

    u32 Id {0};
    Vector2 UV {};
    Vector4 Color {};
    Vector3 Position {};
};

check_size(DLPVertex, 0x28);
