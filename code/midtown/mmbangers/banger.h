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
    mmbangers:banger

    0x4C9C30 | public: virtual int __thiscall mmBangerInstance::ComputeLod(float,float) | ?ComputeLod@mmBangerInstance@@UAEHMM@Z
    0x4C9C50 | public: virtual void __fastcall mmBangerInstance::Draw(int) | ?Draw@mmBangerInstance@@UAIXH@Z
    0x4C9E50 | public: virtual void __fastcall mmBangerInstance::DrawGlow(void) | ?DrawGlow@mmBangerInstance@@UAIXXZ
    0x4C9F20 | public: virtual void __fastcall mmHitBangerInstance::Draw(int) | ?Draw@mmHitBangerInstance@@UAIXH@Z
    0x4CA110 | public: virtual void __fastcall mmBangerInstance::DrawShadow(void) | ?DrawShadow@mmBangerInstance@@UAIXXZ
    0x4CA460 | public: class mmBangerData * __thiscall mmBangerInstance::GetData(void) | ?GetData@mmBangerInstance@@QAEPAVmmBangerData@@XZ
    0x4CA480 | public: virtual class mmPhysEntity * __thiscall mmBangerInstance::GetEntity(void) | ?GetEntity@mmBangerInstance@@UAEPAVmmPhysEntity@@XZ
    0x4CA490 | public: virtual class mmPhysEntity * __thiscall mmBangerInstance::AttachEntity(void) | ?AttachEntity@mmBangerInstance@@UAEPAVmmPhysEntity@@XZ
    0x4CA4D0 | public: virtual class Vector3 __thiscall mmBangerInstance::GetVelocity(void) | ?GetVelocity@mmBangerInstance@@UAE?AVVector3@@XZ
    0x4CA520 | public: virtual void __fastcall mmHitBangerInstance::FromMatrix(class Matrix34 const &) | ?FromMatrix@mmHitBangerInstance@@UAIXABVMatrix34@@@Z
    0x4CA540 | public: virtual class Matrix34 & __fastcall mmHitBangerInstance::ToMatrix(class Matrix34 &) | ?ToMatrix@mmHitBangerInstance@@UAIAAVMatrix34@@AAV2@@Z
    0x4CA550 | public: virtual class Vector3 & __fastcall mmHitBangerInstance::GetPos(void) | ?GetPos@mmHitBangerInstance@@UAIAAVVector3@@XZ
    0x4CA560 | public: void __thiscall mmUnhitBangerInstance::InitBreakables(char *,char *,class mmBangerData *) | ?InitBreakables@mmUnhitBangerInstance@@QAEXPAD0PAVmmBangerData@@@Z
    0x4CA5F0 | public: virtual int __thiscall mmUnhitBangerInstance::Init(char *,class Vector3 &,class Vector3 &,int,char *) | ?Init@mmUnhitBangerInstance@@UAEHPADAAVVector3@@1H0@Z
    0x4CA810 | public: virtual void __fastcall mmUnhitBangerInstance::FromMatrix(class Matrix34 const &) | ?FromMatrix@mmUnhitBangerInstance@@UAIXABVMatrix34@@@Z
    0x4CA830 | public: virtual void __thiscall mmUnhitBangerInstance::Reset(void) | ?Reset@mmUnhitBangerInstance@@UAEXXZ
    0x4CA880 | public: virtual class Matrix34 & __fastcall mmUnhitBangerInstance::ToMatrix(class Matrix34 &) | ?ToMatrix@mmUnhitBangerInstance@@UAIAAVMatrix34@@AAV2@@Z
    0x4CA8D0 | public: virtual class Vector3 & __fastcall mmUnhitBangerInstance::GetPos(void) | ?GetPos@mmUnhitBangerInstance@@UAIAAVVector3@@XZ
    0x4CA8E0 | public: virtual void __thiscall mmUnhitBangerInstance::Impact(class mmInstance *,class Vector3 *) | ?Impact@mmUnhitBangerInstance@@UAEXPAVmmInstance@@PAVVector3@@@Z
    0x4CAC40 | public: virtual void __thiscall mmHitBangerInstance::Detach(void) | ?Detach@mmHitBangerInstance@@UAEXXZ
    0x4CAC70 | public: class mmHitBangerInstance * __thiscall mmBangerManager::GetBanger(void) | ?GetBanger@mmBangerManager@@QAEPAVmmHitBangerInstance@@XZ
    0x4CACD0 | public: void __thiscall mmBangerManager::Init(int) | ?Init@mmBangerManager@@QAEXH@Z
    0x4CAD90 | public: virtual void __thiscall mmBangerManager::Reset(void) | ?Reset@mmBangerManager@@UAEXXZ
    0x4CAE00 | public: virtual void * __thiscall mmHitBangerInstance::`vector deleting destructor'(unsigned int) | ??_EmmHitBangerInstance@@UAEPAXI@Z
    0x4CAE60 | public: __thiscall mmHitBangerInstance::mmHitBangerInstance(void) | ??0mmHitBangerInstance@@QAE@XZ
    0x4CAEC0 | public: virtual unsigned int __thiscall mmHitBangerInstance::SizeOf(void) | ?SizeOf@mmHitBangerInstance@@UAEIXZ
    0x4CAED0 | public: virtual __thiscall mmHitBangerInstance::~mmHitBangerInstance(void) | ??1mmHitBangerInstance@@UAE@XZ
    0x61F7A0 | const mmHitBangerInstance::`vftable' | ??_7mmHitBangerInstance@@6B@
    0x642C8C | int ExpensiveShadows | ?ExpensiveShadows@@3HA
    0x706048 | protected: static class mmBangerManager * mmBangerManager::Instance | ?Instance@mmBangerManager@@1PAV1@A
*/

#include "arts7/node.h"
#include "mmcity/inst.h"

class mmBangerInstance : public mmInstance
{
    // const mmBangerInstance::`vftable' @ 0x61B480

public:
    // 0x4446F0 | ??0mmBangerInstance@@QAE@XZ | inline
    ARTS_IMPORT mmBangerInstance();

    // 0x444720 | ??_EmmBangerInstance@@UAEPAXI@Z
    // 0x444720 | ??_GmmBangerInstance@@UAEPAXI@Z
    // 0x444740 | ??1mmBangerInstance@@UAE@XZ | inline
    ARTS_IMPORT ~mmBangerInstance() override = default;

    // 0x444710 | ?AddWidgets@mmBangerInstance@@UAEXPAVBank@@@Z | inline
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x4CA490 | ?AttachEntity@mmBangerInstance@@UAEPAVmmPhysEntity@@XZ
    ARTS_IMPORT class mmPhysEntity* AttachEntity() override;

    // 0x4C9C30 | ?ComputeLod@mmBangerInstance@@UAEHMM@Z
    ARTS_IMPORT i32 ComputeLod(f32 arg1, f32 arg2) override;

    // 0x4C9C50 | ?Draw@mmBangerInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // 0x4C9E50 | ?DrawGlow@mmBangerInstance@@UAIXXZ
    ARTS_IMPORT void ARTS_FASTCALL DrawGlow() override;

    // 0x4CA110 | ?DrawShadow@mmBangerInstance@@UAIXXZ
    ARTS_IMPORT void ARTS_FASTCALL DrawShadow() override;

    // 0x4CA460 | ?GetData@mmBangerInstance@@QAEPAVmmBangerData@@XZ
    ARTS_IMPORT class mmBangerData* GetData();

    // 0x4CA480 | ?GetEntity@mmBangerInstance@@UAEPAVmmPhysEntity@@XZ
    ARTS_IMPORT class mmPhysEntity* GetEntity() override;

    // 0x4CA4D0 | ?GetVelocity@mmBangerInstance@@UAE?AVVector3@@XZ
    ARTS_IMPORT class Vector3 GetVelocity() override;

    u8 gap14[0x8];
};

check_size(mmBangerInstance, 0x1C);

class mmUnhitBangerInstance : public mmBangerInstance
{
    // const mmUnhitBangerInstance::`vftable' @ 0x61CED8

public:
    // 0x4C4E20 | ??0mmUnhitBangerInstance@@QAE@XZ | inline
    ARTS_IMPORT mmUnhitBangerInstance();

    // 0x48FC50 | ??_GmmUnhitBangerInstance@@UAEPAXI@Z
    // 0x48FC50 | ??_EmmUnhitBangerInstance@@UAEPAXI@Z
    // 0x48FC70 | ??1mmUnhitBangerInstance@@UAE@XZ | inline
    ARTS_IMPORT ~mmUnhitBangerInstance() override = default;

    // 0x4CA810 | ?FromMatrix@mmUnhitBangerInstance@@UAIXABVMatrix34@@@Z
    ARTS_IMPORT void ARTS_FASTCALL FromMatrix(class Matrix34 const& arg1) override;

    // 0x4CA8D0 | ?GetPos@mmUnhitBangerInstance@@UAIAAVVector3@@XZ
    ARTS_IMPORT class Vector3& ARTS_FASTCALL GetPos() override;

    // 0x4CA8E0 | ?Impact@mmUnhitBangerInstance@@UAEXPAVmmInstance@@PAVVector3@@@Z
    ARTS_IMPORT void Impact(class mmInstance* arg1, class Vector3* arg2) override;

    // 0x4CA5F0 | ?Init@mmUnhitBangerInstance@@UAEHPADAAVVector3@@1H0@Z
    ARTS_IMPORT i32 Init(char* arg1, class Vector3& arg2, class Vector3& arg3, i32 arg4, char* arg5) override;

    // 0x4CA560 | ?InitBreakables@mmUnhitBangerInstance@@QAEXPAD0PAVmmBangerData@@@Z
    ARTS_IMPORT void InitBreakables(char* arg1, char* arg2, class mmBangerData* arg3);

    // 0x4CA830 | ?Reset@mmUnhitBangerInstance@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x444750 | ?SizeOf@mmUnhitBangerInstance@@UAEIXZ | inline
    ARTS_IMPORT u32 SizeOf() override;

    // 0x4CA880 | ?ToMatrix@mmUnhitBangerInstance@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_IMPORT class Matrix34& ARTS_FASTCALL ToMatrix(class Matrix34& arg1) override;

    u8 gap1C[0x14];
};

check_size(mmUnhitBangerInstance, 0x30);

class mmBangerManager : public asNode
{
    // const mmBangerManager::`vftable' @ 0x61CD18

public:
    // 0x48FC80 | ??_GmmBangerManager@@UAEPAXI@Z
    // 0x48FC80 | ??_EmmBangerManager@@UAEPAXI@Z
    // 0x48FCB0 | ??1mmBangerManager@@UAE@XZ | inline
    ARTS_IMPORT ~mmBangerManager() override = default;

    // 0x4CAC70 | ?GetBanger@mmBangerManager@@QAEPAVmmHitBangerInstance@@XZ
    ARTS_IMPORT class mmHitBangerInstance* GetBanger();

    // 0x4CACD0 | ?Init@mmBangerManager@@QAEXH@Z
    ARTS_IMPORT void Init(i32 arg1);

    // 0x4CAD90 | ?Reset@mmBangerManager@@UAEXXZ
    ARTS_IMPORT void Reset() override;

protected:
    // 0x706048 | ?Instance@mmBangerManager@@1PAV1@A
    ARTS_IMPORT static class mmBangerManager* Instance;

    u8 gap20[0xC];
};

check_size(mmBangerManager, 0x2C);

class mmHitBangerInstance : public mmBangerInstance
{
    // const mmHitBangerInstance::`vftable' @ 0x61F7A0

public:
    // 0x4CAE60 | ??0mmHitBangerInstance@@QAE@XZ | inline
    ARTS_IMPORT mmHitBangerInstance();

    // 0x4CAE00 | ??_EmmHitBangerInstance@@UAEPAXI@Z
    // 0x4CAED0 | ??1mmHitBangerInstance@@UAE@XZ | inline
    ARTS_IMPORT ~mmHitBangerInstance() override = default;

    // 0x4CAC40 | ?Detach@mmHitBangerInstance@@UAEXXZ
    ARTS_IMPORT void Detach() override;

    // 0x4C9F20 | ?Draw@mmHitBangerInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // 0x4CA520 | ?FromMatrix@mmHitBangerInstance@@UAIXABVMatrix34@@@Z
    ARTS_IMPORT void ARTS_FASTCALL FromMatrix(class Matrix34 const& arg1) override;

    // 0x4CA550 | ?GetPos@mmHitBangerInstance@@UAIAAVVector3@@XZ
    ARTS_IMPORT class Vector3& ARTS_FASTCALL GetPos() override;

    // 0x4CAEC0 | ?SizeOf@mmHitBangerInstance@@UAEIXZ | inline
    ARTS_IMPORT u32 SizeOf() override;

    // 0x4CA540 | ?ToMatrix@mmHitBangerInstance@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_IMPORT class Matrix34& ARTS_FASTCALL ToMatrix(class Matrix34& arg1) override;

    u8 gap1C[0x34];
};

check_size(mmHitBangerInstance, 0x50);

// 0x642C8C | ?ExpensiveShadows@@3HA
ARTS_IMPORT extern i32 ExpensiveShadows;
