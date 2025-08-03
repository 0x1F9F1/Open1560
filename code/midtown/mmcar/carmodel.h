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
    i32 GetCarFlags(char* arg1);

    // ?GetClass@mmCarModel@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetEntity@mmCarModel@@UAEPAVmmPhysEntity@@XZ | inline
    ARTS_IMPORT mmPhysEntity* GetEntity() override;

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
