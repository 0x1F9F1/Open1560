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
    mmcity:portal

    0x4957E0 | public: struct asPortalCell * __thiscall asPortalWeb::AddCell(char *,class asPortalRenderable *,unsigned int) | ?AddCell@asPortalWeb@@QAEPAUasPortalCell@@PADPAVasPortalRenderable@@I@Z
    0x495830 | public: void __thiscall asPortalWeb::DeleteCell(struct asPortalCell *) | ?DeleteCell@asPortalWeb@@QAEXPAUasPortalCell@@@Z
    0x4958E0 | public: struct asPortalEdge * __thiscall asPortalWeb::AddEdge(char *,struct asPortalCell *,struct asPortalCell *,int) | ?AddEdge@asPortalWeb@@QAEPAUasPortalEdge@@PADPAUasPortalCell@@1H@Z
    0x4959A0 | public: void __thiscall asPortalWeb::DeleteEdge(struct asPortalEdge *) | ?DeleteEdge@asPortalWeb@@QAEXPAUasPortalEdge@@@Z
    0x4959B0 | struct asPortalCell * __cdecl LookupCell(char *) | ?LookupCell@@YAPAUasPortalCell@@PAD@Z
    0x4959C0 | struct asPortalCell * __cdecl LookupEdge(char *) | ?LookupEdge@@YAPAUasPortalCell@@PAD@Z
    0x4959D0 | public: void __thiscall asPortalPVS::Init(int,int) | ?Init@asPortalPVS@@QAEXHH@Z
    0x495A30 | public: static struct asPortalPVS * __cdecl asPortalPVS::Create(int,...) | ?Create@asPortalPVS@@SAPAU1@HZZ
    0x495AB0 | public: void __thiscall asPortalPVS::SetVisible(unsigned int) | ?SetVisible@asPortalPVS@@QAEXI@Z
    0x495AE0 | public: __thiscall asPortalWeb::asPortalWeb(void) | ??0asPortalWeb@@QAE@XZ
    0x495B70 | public: int __thiscall asPortalWeb::BuildVisibilityList(class Matrix34 &,struct asPortalCell * *,int,float) | ?BuildVisibilityList@asPortalWeb@@QAEHAAVMatrix34@@PAPAUasPortalCell@@HM@Z
    0x495DD0 | public: int __thiscall asPortalWeb::BuildVisibilityList(class Vector3 &,struct asPortalCell * *,int,float) | ?BuildVisibilityList@asPortalWeb@@QAEHAAVVector3@@PAPAUasPortalCell@@HM@Z
    0x495EE0 | public: virtual void __thiscall asPortalWeb::Update(void) | ?Update@asPortalWeb@@UAEXXZ
    0x4969F0 | public: void __thiscall asPortalWeb::BuildGroups(void) | ?BuildGroups@asPortalWeb@@QAEXXZ
    0x496FE0 | public: void __thiscall asPortalWeb::Cull(int) | ?Cull@asPortalWeb@@QAEXH@Z
    0x497400 | public: void __thiscall asPortalWeb::Stats(void) | ?Stats@asPortalWeb@@QAEXXZ
    0x4974C0 | public: virtual __thiscall asPortalWeb::~asPortalWeb(void) | ??1asPortalWeb@@UAE@XZ
    0x497530 | public: void __thiscall asPortalWeb::LockTarget(void) | ?LockTarget@asPortalWeb@@QAEXXZ
    0x497540 | public: virtual void __thiscall asPortalWeb::AddWidgets(class Bank *) | ?AddWidgets@asPortalWeb@@UAEXPAVBank@@@Z
    0x4976D0 | public: static void __cdecl asPortalWeb::DeclareFields(void) | ?DeclareFields@asPortalWeb@@SAXXZ
    0x497770 | public: virtual class MetaClass * __thiscall asPortalWeb::GetClass(void) | ?GetClass@asPortalWeb@@UAEPAVMetaClass@@XZ
    0x497780 | public: virtual void * __thiscall asPortalWeb::`scalar deleting destructor'(unsigned int) | ??_GasPortalWeb@@UAEPAXI@Z
    0x497780 | public: virtual void * __thiscall asPortalWeb::`vector deleting destructor'(unsigned int) | ??_EasPortalWeb@@UAEPAXI@Z
    0x4977B0 | public: __thiscall asPortalEdge::asPortalEdge(struct asPortalCell *,struct asPortalCell *,int) | ??0asPortalEdge@@QAE@PAUasPortalCell@@0H@Z
    0x61D1E0 | const asPortalWeb::`vftable' | ??_7asPortalWeb@@6B@
    0x705714 | public: static unsigned short asPortalWeb::VisitTag | ?VisitTag@asPortalWeb@@2GA
    0x705718 | class MetaClass asPortalWebMetaClass | ?asPortalWebMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class asPortalWeb : public asNode
{
    // const asPortalWeb::`vftable' @ 0x61D1E0

public:
    // 0x495AE0 | ??0asPortalWeb@@QAE@XZ
    ARTS_IMPORT asPortalWeb();

    // 0x497780 | ??_EasPortalWeb@@UAEPAXI@Z
    // 0x497780 | ??_GasPortalWeb@@UAEPAXI@Z
    // 0x4974C0 | ??1asPortalWeb@@UAE@XZ
    ARTS_IMPORT ~asPortalWeb() override;

    virtual struct asPortalCell* GetStartCell(
        class Vector3& arg1, struct asPortalCell* arg2, class mmPolygon** arg3) = 0;

    // 0x4957E0 | ?AddCell@asPortalWeb@@QAEPAUasPortalCell@@PADPAVasPortalRenderable@@I@Z
    ARTS_IMPORT struct asPortalCell* AddCell(char* arg1, class asPortalRenderable* arg2, u32 arg3);

    // 0x4958E0 | ?AddEdge@asPortalWeb@@QAEPAUasPortalEdge@@PADPAUasPortalCell@@1H@Z
    ARTS_IMPORT struct asPortalEdge* AddEdge(
        char* arg1, struct asPortalCell* arg2, struct asPortalCell* arg3, i32 arg4);

#ifdef ARTS_DEV_BUILD
    // 0x497540 | ?AddWidgets@asPortalWeb@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // 0x4969F0 | ?BuildGroups@asPortalWeb@@QAEXXZ
    ARTS_IMPORT void BuildGroups();

#ifdef ARTS_DEV_BUILD
    // 0x495B70 | ?BuildVisibilityList@asPortalWeb@@QAEHAAVMatrix34@@PAPAUasPortalCell@@HM@Z
    ARTS_IMPORT i32 BuildVisibilityList(class Matrix34& arg1, struct asPortalCell** arg2, i32 arg3, f32 arg4);

    // 0x495DD0 | ?BuildVisibilityList@asPortalWeb@@QAEHAAVVector3@@PAPAUasPortalCell@@HM@Z
    ARTS_IMPORT i32 BuildVisibilityList(class Vector3& arg1, struct asPortalCell** arg2, i32 arg3, f32 arg4);
#endif

    // 0x496FE0 | ?Cull@asPortalWeb@@QAEXH@Z
    ARTS_IMPORT void Cull(i32 arg1);

    // 0x495830 | ?DeleteCell@asPortalWeb@@QAEXPAUasPortalCell@@@Z | unused
    ARTS_IMPORT void DeleteCell(struct asPortalCell* arg1);

    // 0x4959A0 | ?DeleteEdge@asPortalWeb@@QAEXPAUasPortalEdge@@@Z | unused
    ARTS_EXPORT void DeleteEdge(struct asPortalEdge* arg1);

    // 0x497770 | ?GetClass@asPortalWeb@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

#ifdef ARTS_DEV_BUILD
    // 0x497530 | ?LockTarget@asPortalWeb@@QAEXXZ
    ARTS_IMPORT void LockTarget();
#endif

#ifdef ARTS_DEV_BUILD
    // 0x497400 | ?Stats@asPortalWeb@@QAEXXZ
    ARTS_IMPORT void Stats();
#endif

    // 0x495EE0 | ?Update@asPortalWeb@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x4976D0 | ?DeclareFields@asPortalWeb@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // 0x705714 | ?VisitTag@asPortalWeb@@2GA
    ARTS_IMPORT static u16 VisitTag;

    u8 gap20[0x902C];
};

check_size(asPortalWeb, 0x904C);

// 0x4959B0 | ?LookupCell@@YAPAUasPortalCell@@PAD@Z | unused
ARTS_EXPORT struct asPortalCell* LookupCell(char* arg1);

// 0x4959C0 | ?LookupEdge@@YAPAUasPortalCell@@PAD@Z | unused
ARTS_EXPORT struct asPortalCell* LookupEdge(char* arg1);

// 0x705718 | ?asPortalWebMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass asPortalWebMetaClass;

struct asPortalPVS
{
public:
    // 0x4959D0 | ?Init@asPortalPVS@@QAEXHH@Z
    ARTS_IMPORT void Init(i32 arg1, i32 arg2);

    // 0x495AB0 | ?SetVisible@asPortalPVS@@QAEXI@Z
    ARTS_IMPORT void SetVisible(u32 arg1);

    // 0x495A30 | ?Create@asPortalPVS@@SAPAU1@HZZ | unused
    ARTS_IMPORT static struct asPortalPVS* Create(i32 arg1, ...);

    u8 gap0[0x8];
};

check_size(asPortalPVS, 0x8);

struct asPortalEdge
{
public:
    // 0x4977B0 | ??0asPortalEdge@@QAE@PAUasPortalCell@@0H@Z | inline
    ARTS_IMPORT asPortalEdge(struct asPortalCell* arg1, struct asPortalCell* arg2, i32 arg3);

    u8 gap0[0x30];
};

check_size(asPortalEdge, 0x30);

class asPortalRenderable
{
public:
    virtual void Cull(i32 arg1) = 0;
};

check_size(asPortalRenderable, 0x4);
