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
    mmcar:trailer

    0x479230 | public: __thiscall mmTrailer::mmTrailer(void) | ??0mmTrailer@@QAE@XZ
    0x479480 | public: void __thiscall mmTrailer::Init(char *,class mmCarSim *,class Vector3) | ?Init@mmTrailer@@QAEXPADPAVmmCarSim@@VVector3@@@Z
    0x4796D0 | public: virtual void __fastcall mmTrailerInstance::FromMatrix(class Matrix34 const &) | ?FromMatrix@mmTrailerInstance@@UAIXABVMatrix34@@@Z
    0x4796F0 | public: virtual class Matrix34 & __fastcall mmTrailerInstance::ToMatrix(class Matrix34 &) | ?ToMatrix@mmTrailerInstance@@UAIAAVMatrix34@@AAV2@@Z
    0x479710 | public: virtual class Vector3 & __fastcall mmTrailerInstance::GetPos(void) | ?GetPos@mmTrailerInstance@@UAIAAVVector3@@XZ
    0x479720 | public: virtual class mmPhysEntity * __thiscall mmTrailerInstance::GetEntity(void) | ?GetEntity@mmTrailerInstance@@UAEPAVmmPhysEntity@@XZ
    0x479730 | public: virtual class mmPhysEntity * __thiscall mmTrailerInstance::AttachEntity(void) | ?AttachEntity@mmTrailerInstance@@UAEPAVmmPhysEntity@@XZ
    0x479740 | public: virtual class Vector3 __thiscall mmTrailerInstance::GetVelocity(void) | ?GetVelocity@mmTrailerInstance@@UAE?AVVector3@@XZ
    0x479770 | public: void __thiscall mmTrailerInstance::Init(char *,class Vector3 *) | ?Init@mmTrailerInstance@@QAEXPADPAVVector3@@@Z
    0x479910 | public: virtual void __fastcall mmTrailerInstance::Draw(int) | ?Draw@mmTrailerInstance@@UAIXH@Z
    0x479B20 | public: virtual void __fastcall mmTrailerInstance::DrawShadow(void) | ?DrawShadow@mmTrailerInstance@@UAIXXZ
    0x479B40 | public: virtual void __thiscall mmTrailer::AfterLoad(void) | ?AfterLoad@mmTrailer@@UAEXXZ
    0x479BB0 | public: void __thiscall mmTrailer::Activate(void) | ?Activate@mmTrailer@@QAEXXZ
    0x479BC0 | public: void __thiscall mmTrailer::Deactivate(void) | ?Deactivate@mmTrailer@@QAEXXZ
    0x479BD0 | public: virtual void __thiscall mmTrailer::BeforeSave(void) | ?BeforeSave@mmTrailer@@UAEXXZ
    0x479C00 | public: void __thiscall mmTrailer::UpdateICSParams(void) | ?UpdateICSParams@mmTrailer@@QAEXXZ
    0x479C30 | public: void __thiscall mmTrailer::RestoreImpactParams(void) | ?RestoreImpactParams@mmTrailer@@QAEXXZ
    0x479C60 | public: void __thiscall mmTrailer::SetHackedImpactParams(void) | ?SetHackedImpactParams@mmTrailer@@QAEXXZ
    0x479C80 | public: virtual void __thiscall mmTrailer::Reset(void) | ?Reset@mmTrailer@@UAEXXZ
    0x479D60 | public: virtual void __thiscall mmTrailer::Update(void) | ?Update@mmTrailer@@UAEXXZ
    0x479E30 | public: virtual void __thiscall mmTrailer::PostUpdate(void) | ?PostUpdate@mmTrailer@@UAEXXZ
    0x479E40 | public: virtual void __thiscall mmTrailer::AddWidgets(class Bank *) | ?AddWidgets@mmTrailer@@UAEXPAVBank@@@Z
    0x479F30 | public: static void __cdecl mmTrailer::DeclareFields(void) | ?DeclareFields@mmTrailer@@SAXXZ
    0x47A130 | public: virtual class MetaClass * __thiscall mmTrailer::GetClass(void) | ?GetClass@mmTrailer@@UAEPAVMetaClass@@XZ
    0x47A140 | public: virtual __thiscall mmTrailerInstance::~mmTrailerInstance(void) | ??1mmTrailerInstance@@UAE@XZ
    0x47A150 | public: virtual void * __thiscall mmTrailerInstance::`vector deleting destructor'(unsigned int) | ??_EmmTrailerInstance@@UAEPAXI@Z
    0x47A150 | public: virtual void * __thiscall mmTrailerInstance::`scalar deleting destructor'(unsigned int) | ??_GmmTrailerInstance@@UAEPAXI@Z
    0x47A170 | public: virtual void * __thiscall mmTrailer::`vector deleting destructor'(unsigned int) | ??_EmmTrailer@@UAEPAXI@Z
    0x47A1D0 | public: virtual __thiscall mmTrailer::~mmTrailer(void) | ??1mmTrailer@@UAE@XZ
    0x47A300 | public: virtual void __thiscall mmTrailerInstance::AddWidgets(class Bank *) | ?AddWidgets@mmTrailerInstance@@UAEXPAVBank@@@Z
    0x47A310 | public: virtual class asInertialCS * __thiscall mmTrailer::GetICS(void) | ?GetICS@mmTrailer@@UAEPAVasInertialCS@@XZ
    0x47A320 | public: virtual class asBound * __thiscall mmTrailer::GetBound(void) | ?GetBound@mmTrailer@@UAEPAVasBound@@XZ
    0x61C390 | const mmTrailer::`vftable' | ??_7mmTrailer@@6B@
    0x61C3E0 | const mmTrailerInstance::`vftable' | ??_7mmTrailerInstance@@6B@
    0x6A7F98 | class MetaClass mmTrailerMetaClass | ?mmTrailerMetaClass@@3VMetaClass@@A
*/

#include "mmcity/inst.h"
#include "mmphysics/entity.h"

class mmTrailer /*final*/ : public mmPhysEntity
{
    // const mmTrailer::`vftable' @ 0x61C390

public:
    // 0x479230 | ??0mmTrailer@@QAE@XZ
    ARTS_IMPORT mmTrailer();

    // 0x47A170 | ??_EmmTrailer@@UAEPAXI@Z
    // 0x47A1D0 | ??1mmTrailer@@UAE@XZ | inline
    ARTS_IMPORT ~mmTrailer() override;

    // 0x479BB0 | ?Activate@mmTrailer@@QAEXXZ
    ARTS_IMPORT void Activate();

    // 0x479E40 | ?AddWidgets@mmTrailer@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x479B40 | ?AfterLoad@mmTrailer@@UAEXXZ
    ARTS_IMPORT void AfterLoad() override;

    // 0x479BD0 | ?BeforeSave@mmTrailer@@UAEXXZ
    ARTS_IMPORT void BeforeSave() override;

    // 0x479BC0 | ?Deactivate@mmTrailer@@QAEXXZ
    ARTS_IMPORT void Deactivate();

    // 0x47A320 | ?GetBound@mmTrailer@@UAEPAVasBound@@XZ | inline
    ARTS_IMPORT class asBound* GetBound() override;

    // 0x47A130 | ?GetClass@mmTrailer@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x47A310 | ?GetICS@mmTrailer@@UAEPAVasInertialCS@@XZ | inline
    ARTS_IMPORT class asInertialCS* GetICS() override;

    // 0x479480 | ?Init@mmTrailer@@QAEXPADPAVmmCarSim@@VVector3@@@Z
    ARTS_IMPORT void Init(char* arg1, class mmCarSim* arg2, class Vector3 arg3);

    // 0x479E30 | ?PostUpdate@mmTrailer@@UAEXXZ
    ARTS_IMPORT void PostUpdate() override;

    // 0x479C80 | ?Reset@mmTrailer@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x479C30 | ?RestoreImpactParams@mmTrailer@@QAEXXZ
    ARTS_IMPORT void RestoreImpactParams();

    // 0x479C60 | ?SetHackedImpactParams@mmTrailer@@QAEXXZ
    ARTS_IMPORT void SetHackedImpactParams();

    // 0x479D60 | ?Update@mmTrailer@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x479C00 | ?UpdateICSParams@mmTrailer@@QAEXXZ | unused
    ARTS_IMPORT void UpdateICSParams();

    // 0x479F30 | ?DeclareFields@mmTrailer@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x11E4];
};

check_size(mmTrailer, 0x1204);

class mmTrailerInstance /*final*/ : public mmInstance
{
    // const mmTrailerInstance::`vftable' @ 0x61C3E0

public:
    // 0x47A150 | ??_GmmTrailerInstance@@UAEPAXI@Z
    // 0x47A150 | ??_EmmTrailerInstance@@UAEPAXI@Z
    // 0x47A140 | ??1mmTrailerInstance@@UAE@XZ | inline
    ARTS_IMPORT ~mmTrailerInstance() override = default;

    // 0x47A300 | ?AddWidgets@mmTrailerInstance@@UAEXPAVBank@@@Z | inline
    ARTS_EXPORT void AddWidgets(class Bank* arg1) override;

    // 0x479730 | ?AttachEntity@mmTrailerInstance@@UAEPAVmmPhysEntity@@XZ
    ARTS_IMPORT class mmPhysEntity* AttachEntity() override;

    // 0x479910 | ?Draw@mmTrailerInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // 0x479B20 | ?DrawShadow@mmTrailerInstance@@UAIXXZ
    ARTS_IMPORT void ARTS_FASTCALL DrawShadow() override;

    // 0x4796D0 | ?FromMatrix@mmTrailerInstance@@UAIXABVMatrix34@@@Z
    ARTS_IMPORT void ARTS_FASTCALL FromMatrix(class Matrix34 const& arg1) override;

    // 0x479720 | ?GetEntity@mmTrailerInstance@@UAEPAVmmPhysEntity@@XZ
    ARTS_IMPORT class mmPhysEntity* GetEntity() override;

    // 0x479710 | ?GetPos@mmTrailerInstance@@UAIAAVVector3@@XZ
    ARTS_IMPORT class Vector3& ARTS_FASTCALL GetPos() override;

    // 0x479740 | ?GetVelocity@mmTrailerInstance@@UAE?AVVector3@@XZ
    ARTS_IMPORT class Vector3 GetVelocity() override;

    // 0x479770 | ?Init@mmTrailerInstance@@QAEXPADPAVVector3@@@Z
    ARTS_IMPORT void Init(char* arg1, class Vector3* arg2);

    // 0x4796F0 | ?ToMatrix@mmTrailerInstance@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_IMPORT class Matrix34& ARTS_FASTCALL ToMatrix(class Matrix34& arg1) override;

    u8 gap14[0x34];
};

check_size(mmTrailerInstance, 0x48);

// 0x6A7F98 | ?mmTrailerMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmTrailerMetaClass;
