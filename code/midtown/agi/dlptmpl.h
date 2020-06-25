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

class DLPTemplate
{
public:
    // 0x5582E0 | ??0DLPTemplate@@QAE@PAD@Z
    ARTS_IMPORT DLPTemplate(char* arg1);

    // 0x5597C0 | ?AddRef@DLPTemplate@@QAEXXZ
    ARTS_IMPORT void AddRef();

    // 0x559A00 | ?BoundBox@DLPTemplate@@QAEHAAVVector3@@0PAD@Z
    ARTS_IMPORT i32 BoundBox(class Vector3& arg1, class Vector3& arg2, char* arg3);

    // 0x559930 | ?GetCentroid@DLPTemplate@@QAEHAAVVector3@@PAD@Z
    ARTS_IMPORT i32 GetCentroid(class Vector3& arg1, char* arg2);

    // 0x5599B0 | ?GetGroupVertex@DLPTemplate@@QAEPAVVector3@@PAD@Z | unused
    ARTS_IMPORT class Vector3* GetGroupVertex(char* arg1);

    // 0x559800 | ?GetVertexCentroid@DLPTemplate@@QAEHAAVVector3@@PAD@Z | unused
    ARTS_IMPORT i32 GetVertexCentroid(class Vector3& arg1, char* arg2);

    // 0x559630 | ?GroupExists@DLPTemplate@@QAEPAVDLPGroup@@PAD@Z
    ARTS_IMPORT class DLPGroup* GroupExists(char* arg1);

    // 0x5583D0 | ?Init@DLPTemplate@@QAEXHHH@Z
    ARTS_IMPORT void Init(i32 arg1, i32 arg2, i32 arg3);

    // 0x558A40 | ?InitRemap@DLPTemplate@@QAEXAAV?$agiLib@VagiMtlParameters@@VagiMtlDef@@@@AAV?$agiLib@VagiTexParameters@@VagiTexDef@@@@AAV?$agiLib@VagiPhysParameters@@VagiPhysDef@@@@@Z
    ARTS_IMPORT void InitRemap(class agiLib<class agiMtlParameters, class agiMtlDef>& arg1,
        class agiLib<class agiTexParameters, class agiTexDef>& arg2,
        class agiLib<class agiPhysParameters, class agiPhysDef>& arg3);

    // 0x558B60 | ?Load@DLPTemplate@@QAEHPAD@Z | unused
    ARTS_IMPORT i32 Load(char* arg1);

    // 0x558640 | ?Load@DLPTemplate@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Load(class Stream* arg1);

    // 0x558BA0 | ?Print@DLPTemplate@@QAEXPAVStream@@@Z | unused
    ARTS_IMPORT void Print(class Stream* arg1);

    // 0x5597D0 | ?Release@DLPTemplate@@QAEHXZ
    ARTS_IMPORT i32 Release();

    // 0x5596B0 | ?Restrict@DLPTemplate@@QAEHPAD@Z
    ARTS_IMPORT i32 Restrict(char* arg1);

    // 0x558500 | ?Save@DLPTemplate@@QAEXPAVStream@@@Z | unused
    ARTS_IMPORT void Save(class Stream* arg1);

private:
    // 0x558330 | ??1DLPTemplate@@AAE@XZ
    ARTS_IMPORT ~DLPTemplate();
};

check_size(DLPTemplate, 0x3C);

struct DLPPatch
{
public:
    // 0x55A310 | ??0DLPPatch@@QAE@XZ | inline
    ARTS_IMPORT DLPPatch();

    // 0x559C80 | ??_EDLPPatch@@QAEPAXI@Z | unused
    // 0x55A320 | ??1DLPPatch@@QAE@XZ | inline
    ARTS_IMPORT ~DLPPatch();

    // 0x558990 | ?GetProp@DLPPatch@@QAEPADPAD@Z | unused
    ARTS_IMPORT char* GetProp(char* arg1);

    // 0x559080 | ?Load@DLPPatch@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Load(class Stream* arg1);

    // 0x559250 | ?Print@DLPPatch@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Print(class Stream* arg1);

    // 0x559180 | ?Save@DLPPatch@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Save(class Stream* arg1);
};

check_size(DLPPatch, 0x18);

class DLPGroup
{
public:
    // 0x558C90 | ??0DLPGroup@@QAE@XZ
    ARTS_IMPORT DLPGroup();

    // 0x558CB0 | ??0DLPGroup@@QAE@PAVDLPTemplate@@PAV0@@Z
    ARTS_IMPORT DLPGroup(class DLPTemplate* arg1, class DLPGroup* arg2);

    // 0x559C20 | ??_EDLPGroup@@QAEPAXI@Z | unused
    // 0x558E90 | ??1DLPGroup@@QAE@XZ
    ARTS_IMPORT ~DLPGroup();

    // 0x559040 | ?Init@DLPGroup@@QAEXHH@Z
    ARTS_IMPORT void Init(i32 arg1, i32 arg2);

    // 0x558EC0 | ?Load@DLPGroup@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Load(class Stream* arg1);

    // 0x558FC0 | ?Print@DLPGroup@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Print(class Stream* arg1);

    // 0x558F40 | ?Save@DLPGroup@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Save(class Stream* arg1);
};

check_size(DLPGroup, 0x30);

// 0x5593A0 | ?PackAngle@@YAIM@Z
ARTS_IMPORT u32 PackAngle(f32 arg1);

// 0x559400 | ?PackNormal@@YAXAAGAAVVector3@@@Z | unused
ARTS_IMPORT void PackNormal(u16& arg1, class Vector3& arg2);

// 0x559310 | ?UnpackAngle@@YAME@Z
ARTS_IMPORT f32 UnpackAngle(u8 arg1);

// 0x559340 | ?UnpackNormal@@YAXAAVVector3@@AAG@Z | unused
ARTS_IMPORT void UnpackNormal(class Vector3& arg1, u16& arg2);

// 0x903130 | ?DLPTemplateHash@@3VHashTable@@A
ARTS_IMPORT extern class HashTable DLPTemplateHash;

struct DLPVertex
{
public:
    // 0x5594D0 | ?Load@DLPVertex@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Load(class Stream* arg1);

    // 0x5595A0 | ?Save@DLPVertex@@QAEXPAVStream@@@Z
    ARTS_IMPORT void Save(class Stream* arg1);
};

check_size(DLPVertex, 0x0);
