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

#include "vector7/vector2.h"
#include "vector7/vector3.h"

class mmBangerData;
class mmPhysEntity;

class mmBangerInstance : public mmInstance
{
public:
    // ??0mmBangerInstance@@QAE@XZ | inline
    ARTS_EXPORT mmBangerInstance();

    // ??_EmmBangerInstance@@UAEPAXI@Z
    // ??_GmmBangerInstance@@UAEPAXI@Z
    // ??1mmBangerInstance@@UAE@XZ | inline
    ARTS_EXPORT ~mmBangerInstance() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmBangerInstance@@UAEXPAVBank@@@Z | inline
    ARTS_EXPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?AttachEntity@mmBangerInstance@@UAEPAVmmPhysEntity@@XZ
    ARTS_EXPORT mmPhysEntity* AttachEntity() override;

    // ?ComputeLod@mmBangerInstance@@UAEHMM@Z
    ARTS_IMPORT i32 ComputeLod(f32 arg1, f32 arg2) override;

    // ?Draw@mmBangerInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?DrawGlow@mmBangerInstance@@UAIXXZ
    ARTS_IMPORT void ARTS_FASTCALL DrawGlow() override;

    // ?DrawShadow@mmBangerInstance@@UAIXXZ
    ARTS_IMPORT void ARTS_FASTCALL DrawShadow() override;

    // ?GetData@mmBangerInstance@@QAEPAVmmBangerData@@XZ
    ARTS_EXPORT mmBangerData* GetData();

    // ?GetEntity@mmBangerInstance@@UAEPAVmmPhysEntity@@XZ
    ARTS_EXPORT mmPhysEntity* GetEntity() override;

    // ?GetVelocity@mmBangerInstance@@UAE?AVVector3@@XZ
    ARTS_EXPORT Vector3 GetVelocity() override;

    i16 BangerIndex {};
    u8 NormalIndex {};
    f32 Normal {};
};

check_size(mmBangerInstance, 0x1C);

class mmUnhitBangerInstance : public mmBangerInstance
{
public:
    // ??0mmUnhitBangerInstance@@QAE@XZ | inline
    ARTS_EXPORT mmUnhitBangerInstance();

    // ??_GmmUnhitBangerInstance@@UAEPAXI@Z
    // ??_EmmUnhitBangerInstance@@UAEPAXI@Z
    // ??1mmUnhitBangerInstance@@UAE@XZ | inline
    ARTS_EXPORT ~mmUnhitBangerInstance() override = default;

    // ?FromMatrix@mmUnhitBangerInstance@@UAIXABVMatrix34@@@Z
    ARTS_EXPORT void ARTS_FASTCALL FromMatrix(const Matrix34& matrix) override;

    // ?GetPos@mmUnhitBangerInstance@@UAIAAVVector3@@XZ
    ARTS_EXPORT Vector3& ARTS_FASTCALL GetPos() override;

    // ?Impact@mmUnhitBangerInstance@@UAEXPAVmmInstance@@PAVVector3@@@Z
    ARTS_IMPORT void Impact(mmInstance* arg1, Vector3* arg2) override;

    // ?Init@mmUnhitBangerInstance@@UAEHPADAAVVector3@@1H0@Z
    ARTS_EXPORT b32 Init(aconst char* name, Vector3& pos1, Vector3& pos2, i32 init_flags, aconst char* part) override;

    // ?InitBreakables@mmUnhitBangerInstance@@QAEXPAD0PAVmmBangerData@@@Z
    ARTS_IMPORT void InitBreakables(aconst char* name, aconst char* part, mmBangerData* bng_data);

    // ?Reset@mmUnhitBangerInstance@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SizeOf@mmUnhitBangerInstance@@UAEIXZ | inline
    ARTS_EXPORT u32 SizeOf() override;

    // ?ToMatrix@mmUnhitBangerInstance@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_EXPORT Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& matrix) override;

    Vector3 Position {};
    Vector2 Angle {};
};

check_size(mmUnhitBangerInstance, 0x30);

class mmHitBangerInstance final : public mmBangerInstance
{
public:
    // ??0mmHitBangerInstance@@QAE@XZ | inline
    ARTS_EXPORT mmHitBangerInstance();

    // ??_EmmHitBangerInstance@@UAEPAXI@Z
    // ??1mmHitBangerInstance@@UAE@XZ | inline
    ARTS_EXPORT ~mmHitBangerInstance() override = default;

    // ?Detach@mmHitBangerInstance@@UAEXXZ
    ARTS_EXPORT void Detach() override;

    // ?Draw@mmHitBangerInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?FromMatrix@mmHitBangerInstance@@UAIXABVMatrix34@@@Z
    ARTS_EXPORT void ARTS_FASTCALL FromMatrix(const Matrix34& matrix) override;

    // ?GetPos@mmHitBangerInstance@@UAIAAVVector3@@XZ
    ARTS_EXPORT Vector3& ARTS_FASTCALL GetPos() override;

    // ?SizeOf@mmHitBangerInstance@@UAEIXZ | inline
    ARTS_EXPORT u32 SizeOf() override;

    // ?ToMatrix@mmHitBangerInstance@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_EXPORT Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& matrix) override;

    i32 MeshVariant {};
    Matrix34 Matrix {IDENTITY};
};

check_size(mmHitBangerInstance, 0x50);

class mmBangerManager final : public asNode
{
public:
    // ??_GmmBangerManager@@UAEPAXI@Z
    // ??_EmmBangerManager@@UAEPAXI@Z
    // ??1mmBangerManager@@UAE@XZ | inline
    ARTS_EXPORT ~mmBangerManager() override = default;

    // ?GetBanger@mmBangerManager@@QAEPAVmmHitBangerInstance@@XZ
    ARTS_IMPORT mmHitBangerInstance* GetBanger();

    // ?Init@mmBangerManager@@QAEXH@Z
    ARTS_IMPORT void Init(i32 arg1);

    // ?Reset@mmBangerManager@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    friend mmBangerManager* BangerMgr();

protected:
    // ?Instance@mmBangerManager@@1PAV1@A
    ARTS_IMPORT static mmBangerManager* Instance;

private:
    mmHitBangerInstance* Bangers {};
    i32 NumBangers {};
    i32 MaxBangers {};
};

check_size(mmBangerManager, 0x2C);

inline mmBangerManager* BangerMgr()
{
    return mmBangerManager::Instance;
}

// ?ExpensiveShadows@@3HA
ARTS_IMPORT extern i32 ExpensiveShadows;
