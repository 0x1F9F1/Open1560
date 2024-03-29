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

#include "mmeffects/damage.h"
#include "mmeffects/linespark.h"
#include "vector7/matrix34.h"

class mmCar;
class mmCarSim;
class mmHitBangerInstance;
class mmWheel;

#define CAR_FLAG_AXLES 0x1         // Has axles
#define CAR_FLAG_SIREN 0x2         // Has a siren
#define CAR_FLAG_SIREN_ON 0x4      // Siren on
#define CAR_FLAG_UNIMPL_DAMAGE 0x8 // This kind of damage is no longer implemented (probably deformation)
#define CAR_FLAG_FENDERS 0x10      // Has fenders
#define CAR_FLAG_6_WHEELS 0x20     // Has 6 wheels
#define CAR_FLAG_ACTIVE 0x40       // Activated (visible)
#define CAR_FLAG_TRAILER 0x80      // Has a trailer
#define CAR_FLAG_LARGE 0x100       // Disable mmStuck, use ind cam indoors

// Visible parts (zero if ejected)
#define CAR_FLAG_FL_WHEEL 0x200  // Front Left Wheel
#define CAR_FLAG_FR_WHEEL 0x400  // Front Right Wheel
#define CAR_FLAG_BL_WHEEL 0x800  // Back Left Wheel
#define CAR_FLAG_BR_WHEEL 0x1000 // Back Right Wheel
#define CAR_FLAG_L_FENDER 0x2000 // Left Fender
#define CAR_FLAG_R_FENDER 0x4000 // Right Fender (FIXME: 0x2000 checked when in DashView)

#define CAR_FLAG_HIGH_QUALITY 0x8000 // Increase LOD

class mmCarModel final : public mmInstance
{
public:
    // ??0mmCarModel@@QAE@XZ
    ARTS_EXPORT mmCarModel();

    // ??_EmmCarModel@@UAEPAXI@Z
    // ??1mmCarModel@@UAE@XZ
    ARTS_EXPORT ~mmCarModel() override = default;

    // ?Activate@mmCarModel@@QAEXXZ
    ARTS_IMPORT void Activate();

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmCarModel@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?ApplyDamage@mmCarModel@@QAEXAAVVector3@@M@Z
    ARTS_IMPORT void ApplyDamage(Vector3& arg1, f32 arg2);

    // ?AttachEntity@mmCarModel@@UAEPAVmmPhysEntity@@XZ | inline
    ARTS_IMPORT mmPhysEntity* AttachEntity() override;

    // ?ClearDamage@mmCarModel@@QAEXH@Z
    ARTS_IMPORT void ClearDamage(b32 arg1);

    // ?DashActivated@mmCarModel@@QAEXXZ
    ARTS_IMPORT void DashActivated();

    // ?DashDeactivated@mmCarModel@@QAEXXZ
    ARTS_IMPORT void DashDeactivated();

    // ?Deactivate@mmCarModel@@QAEXXZ
    ARTS_IMPORT void Deactivate();

    // ?Draw@mmCarModel@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?DrawGlow@mmCarModel@@UAIXXZ
    ARTS_IMPORT void ARTS_FASTCALL DrawGlow() override;

    // ?DrawShadow@mmCarModel@@UAIXXZ
    ARTS_IMPORT void ARTS_FASTCALL DrawShadow() override;

    // ?EjectPart@mmCarModel@@QAEXPAVmmWheel@@FFH@Z
    ARTS_IMPORT void EjectPart(mmWheel* wheel, i16 banger, i16 mesh, i32 part);

    // ?EjectWheels@mmCarModel@@QAEXH@Z
    ARTS_IMPORT void EjectWheels(i32 arg1);

    // ?FromMatrix@mmCarModel@@UAIXABVMatrix34@@@Z
    ARTS_IMPORT void ARTS_FASTCALL FromMatrix(const Matrix34& arg1) override;

    // ?GetCarFlags@mmCarModel@@QAEHPAD@Z | unused
    ARTS_EXPORT i32 GetCarFlags(char* arg1);

    // ?GetClass@mmCarModel@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetEntity@mmCarModel@@UAEPAVmmPhysEntity@@XZ | inline
    ARTS_IMPORT mmPhysEntity* GetEntity() override;

    // ?GetPart@mmCarModel@@QAEPAVmmHitBangerInstance@@H@Z | unused
    ARTS_IMPORT mmHitBangerInstance* GetPart(i32 arg1);

    // ?GetPos@mmCarModel@@UAIAAVVector3@@XZ
    ARTS_IMPORT Vector3& ARTS_FASTCALL GetPos() override;

    // ?GetVelocity@mmCarModel@@UAE?AVVector3@@XZ | inline
    ARTS_IMPORT Vector3 GetVelocity() override;

    // ?Impact@mmCarModel@@QAEXPAVVector3@@@Z
    ARTS_IMPORT void Impact(Vector3* arg1);

    // ?Init@mmCarModel@@QAEXPADPAVmmCar@@H@Z
    ARTS_IMPORT void Init(char* arg1, mmCar* arg2, i32 arg3);

    // ?InitDamage@mmCarModel@@QAEXXZ
    ARTS_IMPORT void InitDamage();

    // ?Kill@mmCarModel@@QAEXXZ | unused
    ARTS_IMPORT void Kill();

    // ?Reset@mmCarModel@@UAEXXZ | inline
    ARTS_IMPORT void Reset() override;

    // ?ToMatrix@mmCarModel@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_IMPORT Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& arg1) override;

    // ?DeclareFields@mmCarModel@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    bool HasSiren() const
    {
        return CarFlags & CAR_FLAG_SIREN;
    }

    bool HasTrailer() const
    {
        return CarFlags & CAR_FLAG_TRAILER;
    }

    mmCarSim* CarSim {};
    mmCar* Entity {};
    u32 CarFlags {}; // CAR_FLAG_*
    Matrix34 field_20 {IDENTITY};
    i32 field_50 {};
    i32 PaintJobIndex {};
    mmDamage DamageHigh {};
    mmDamage DamageMedium {};
    asLineSparks Sparks {};
    i16 WHL0_Entry {-1};
    i16 FNDR0_Entry {-1};
    mmHitBangerInstance* Bangers[6] {};
};

check_size(mmCarModel, 0x110);

// ?IsPlayerAutoCam@@3HA
ARTS_IMPORT extern i32 IsPlayerAutoCam;
