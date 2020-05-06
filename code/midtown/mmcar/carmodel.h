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
    mmcar:carmodel

    0x471490 | public: __thiscall mmCarModel::mmCarModel(void) | ??0mmCarModel@@QAE@XZ
    0x471540 | public: virtual __thiscall mmCarModel::~mmCarModel(void) | ??1mmCarModel@@UAE@XZ
    0x4715A0 | public: virtual void __fastcall mmCarModel::FromMatrix(class Matrix34 const &) | ?FromMatrix@mmCarModel@@UAIXABVMatrix34@@@Z
    0x4715C0 | public: virtual class Matrix34 & __fastcall mmCarModel::ToMatrix(class Matrix34 &) | ?ToMatrix@mmCarModel@@UAIAAVMatrix34@@AAV2@@Z
    0x4715D0 | public: virtual class Vector3 & __fastcall mmCarModel::GetPos(void) | ?GetPos@mmCarModel@@UAIAAVVector3@@XZ
    0x471640 | public: void __thiscall mmCarModel::Impact(class Vector3 *) | ?Impact@mmCarModel@@QAEXPAVVector3@@@Z
    0x471780 | public: void __thiscall mmCarModel::EjectWheels(int) | ?EjectWheels@mmCarModel@@QAEXH@Z
    0x4718D0 | public: void __thiscall mmCarModel::EjectPart(class mmWheel *,short,short,int) | ?EjectPart@mmCarModel@@QAEXPAVmmWheel@@FFH@Z
    0x471B70 | public: virtual void __fastcall mmCarModel::Draw(int) | ?Draw@mmCarModel@@UAIXH@Z
    0x472B00 | public: virtual void __fastcall mmCarModel::DrawGlow(void) | ?DrawGlow@mmCarModel@@UAIXXZ
    0x472B90 | public: virtual void __fastcall mmCarModel::DrawShadow(void) | ?DrawShadow@mmCarModel@@UAIXXZ
    0x472BE0 | public: int __thiscall mmCarModel::GetCarFlags(char *) | ?GetCarFlags@mmCarModel@@QAEHPAD@Z
    0x472BF0 | public: void __thiscall mmCarModel::InitDamage(void) | ?InitDamage@mmCarModel@@QAEXXZ
    0x472C50 | public: class mmHitBangerInstance * __thiscall mmCarModel::GetPart(int) | ?GetPart@mmCarModel@@QAEPAVmmHitBangerInstance@@H@Z
    0x472CA0 | public: void __thiscall mmCarModel::ClearDamage(int) | ?ClearDamage@mmCarModel@@QAEXH@Z
    0x472D90 | public: void __thiscall mmCarModel::ApplyDamage(class Vector3 &,float) | ?ApplyDamage@mmCarModel@@QAEXAAVVector3@@M@Z
    0x472DC0 | public: void __thiscall mmCarModel::Init(char *,class mmCar *,int) | ?Init@mmCarModel@@QAEXPADPAVmmCar@@H@Z
    0x473080 | public: void __thiscall mmCarModel::DashActivated(void) | ?DashActivated@mmCarModel@@QAEXXZ
    0x473090 | public: void __thiscall mmCarModel::DashDeactivated(void) | ?DashDeactivated@mmCarModel@@QAEXXZ
    0x4730A0 | public: void __thiscall mmCarModel::Activate(void) | ?Activate@mmCarModel@@QAEXXZ
    0x4730B0 | public: void __thiscall mmCarModel::Deactivate(void) | ?Deactivate@mmCarModel@@QAEXXZ
    0x4730D0 | public: void __thiscall mmCarModel::Kill(void) | ?Kill@mmCarModel@@QAEXXZ
    0x4730E0 | public: virtual void __thiscall mmCarModel::AddWidgets(class Bank *) | ?AddWidgets@mmCarModel@@UAEXPAVBank@@@Z
    0x473100 | public: static void __cdecl mmCarModel::DeclareFields(void) | ?DeclareFields@mmCarModel@@SAXXZ
    0x473280 | public: virtual class MetaClass * __thiscall mmCarModel::GetClass(void) | ?GetClass@mmCarModel@@UAEPAVMetaClass@@XZ
    0x4732C0 | public: virtual void * __thiscall mmCarModel::`vector deleting destructor'(unsigned int) | ??_EmmCarModel@@UAEPAXI@Z
    0x473320 | public: virtual class mmPhysEntity * __thiscall mmCarModel::GetEntity(void) | ?GetEntity@mmCarModel@@UAEPAVmmPhysEntity@@XZ
    0x473330 | public: virtual class mmPhysEntity * __thiscall mmCarModel::AttachEntity(void) | ?AttachEntity@mmCarModel@@UAEPAVmmPhysEntity@@XZ
    0x473340 | public: virtual class Vector3 __thiscall mmCarModel::GetVelocity(void) | ?GetVelocity@mmCarModel@@UAE?AVVector3@@XZ
    0x473370 | public: virtual void __thiscall mmCarModel::Reset(void) | ?Reset@mmCarModel@@UAEXXZ
    0x61C010 | const mmCarModel::`vftable' | ??_7mmCarModel@@6B@
    0x6A7DF8 | class MetaClass mmCarModelMetaClass | ?mmCarModelMetaClass@@3VMetaClass@@A
    0x6A7E2C | int IsPlayerAutoCam | ?IsPlayerAutoCam@@3HA
*/

#include "mmcity/inst.h"

class mmCarModel : public mmInstance
{
    // const mmCarModel::`vftable' @ 0x61C010

public:
    // 0x471490 | ??0mmCarModel@@QAE@XZ
    mmCarModel();

    // 0x4732C0 | ??_EmmCarModel@@UAEPAXI@Z
    // 0x471540 | ??1mmCarModel@@UAE@XZ
    ~mmCarModel() override;

    // 0x4730A0 | ?Activate@mmCarModel@@QAEXXZ
    void Activate();

    // 0x4730E0 | ?AddWidgets@mmCarModel@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x472D90 | ?ApplyDamage@mmCarModel@@QAEXAAVVector3@@M@Z
    void ApplyDamage(class Vector3& arg1, f32 arg2);

    // 0x473330 | ?AttachEntity@mmCarModel@@UAEPAVmmPhysEntity@@XZ
    class mmPhysEntity* AttachEntity() override;

    // 0x472CA0 | ?ClearDamage@mmCarModel@@QAEXH@Z
    void ClearDamage(i32 arg1);

    // 0x473080 | ?DashActivated@mmCarModel@@QAEXXZ
    void DashActivated();

    // 0x473090 | ?DashDeactivated@mmCarModel@@QAEXXZ
    void DashDeactivated();

    // 0x4730B0 | ?Deactivate@mmCarModel@@QAEXXZ
    void Deactivate();

    // 0x471B70 | ?Draw@mmCarModel@@UAIXH@Z
    void __fastcall Draw(i32 arg1) override;

    // 0x472B00 | ?DrawGlow@mmCarModel@@UAIXXZ
    void __fastcall DrawGlow() override;

    // 0x472B90 | ?DrawShadow@mmCarModel@@UAIXXZ
    void __fastcall DrawShadow() override;

    // 0x4718D0 | ?EjectPart@mmCarModel@@QAEXPAVmmWheel@@FFH@Z
    void EjectPart(class mmWheel* arg1, i16 arg2, i16 arg3, i32 arg4);

    // 0x471780 | ?EjectWheels@mmCarModel@@QAEXH@Z
    void EjectWheels(i32 arg1);

    // 0x4715A0 | ?FromMatrix@mmCarModel@@UAIXABVMatrix34@@@Z
    void __fastcall FromMatrix(class Matrix34 const& arg1) override;

    // 0x472BE0 | ?GetCarFlags@mmCarModel@@QAEHPAD@Z
    i32 GetCarFlags(char* arg1);

    // 0x473280 | ?GetClass@mmCarModel@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x473320 | ?GetEntity@mmCarModel@@UAEPAVmmPhysEntity@@XZ
    class mmPhysEntity* GetEntity() override;

    // 0x472C50 | ?GetPart@mmCarModel@@QAEPAVmmHitBangerInstance@@H@Z
    class mmHitBangerInstance* GetPart(i32 arg1);

    // 0x4715D0 | ?GetPos@mmCarModel@@UAIAAVVector3@@XZ
    class Vector3& __fastcall GetPos() override;

    // 0x473340 | ?GetVelocity@mmCarModel@@UAE?AVVector3@@XZ
    class Vector3 GetVelocity() override;

    // 0x471640 | ?Impact@mmCarModel@@QAEXPAVVector3@@@Z
    void Impact(class Vector3* arg1);

    // 0x472DC0 | ?Init@mmCarModel@@QAEXPADPAVmmCar@@H@Z
    void Init(char* arg1, class mmCar* arg2, i32 arg3);

    // 0x472BF0 | ?InitDamage@mmCarModel@@QAEXXZ
    void InitDamage();

    // 0x4730D0 | ?Kill@mmCarModel@@QAEXXZ
    void Kill();

    // 0x473370 | ?Reset@mmCarModel@@UAEXXZ
    void Reset() override;

    // 0x4715C0 | ?ToMatrix@mmCarModel@@UAIAAVMatrix34@@AAV2@@Z
    class Matrix34& __fastcall ToMatrix(class Matrix34& arg1) override;

    // 0x473100 | ?DeclareFields@mmCarModel@@SAXXZ
    static void DeclareFields();
};

check_size(mmCarModel, 0x110);

// 0x6A7E2C | ?IsPlayerAutoCam@@3HA
inline extern_var(0x6A7E2C, i32, IsPlayerAutoCam);

// 0x6A7DF8 | ?mmCarModelMetaClass@@3VMetaClass@@A
inline extern_var(0x6A7DF8, class MetaClass, mmCarModelMetaClass);
