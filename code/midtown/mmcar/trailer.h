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
#include "mmphysics/entity.h"

#include "drivetrain.h"
#include "mmphysics/bound.h"
#include "mmphysics/inertia.h"
#include "skid.h"
#include "splash.h"
#include "wheel.h"

class mmCarSim;

class mmTrailerInstance final : public mmInstance
{
public:
    // ??_GmmTrailerInstance@@UAEPAXI@Z
    // ??_EmmTrailerInstance@@UAEPAXI@Z
    // ??1mmTrailerInstance@@UAE@XZ | inline
    ARTS_EXPORT ~mmTrailerInstance() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmTrailerInstance@@UAEXPAVBank@@@Z | inline
    ARTS_EXPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?AttachEntity@mmTrailerInstance@@UAEPAVmmPhysEntity@@XZ
    ARTS_IMPORT mmPhysEntity* AttachEntity() override;

    // ?Draw@mmTrailerInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?DrawShadow@mmTrailerInstance@@UAIXXZ
    ARTS_IMPORT void ARTS_FASTCALL DrawShadow() override;

    // ?FromMatrix@mmTrailerInstance@@UAIXABVMatrix34@@@Z
    ARTS_IMPORT void ARTS_FASTCALL FromMatrix(const Matrix34& arg1) override;

    // ?GetEntity@mmTrailerInstance@@UAEPAVmmPhysEntity@@XZ
    ARTS_IMPORT mmPhysEntity* GetEntity() override;

    // ?GetPos@mmTrailerInstance@@UAIAAVVector3@@XZ
    ARTS_IMPORT Vector3& ARTS_FASTCALL GetPos() override;

    // ?GetVelocity@mmTrailerInstance@@UAE?AVVector3@@XZ
    ARTS_IMPORT Vector3 GetVelocity() override;

    // ?Init@mmTrailerInstance@@QAEXPADPAVVector3@@@Z
    ARTS_IMPORT void Init(char* arg1, Vector3* arg2);

    // ?ToMatrix@mmTrailerInstance@@UAIAAVMatrix34@@AAV2@@Z
    ARTS_IMPORT Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& arg1) override;

    u8 gap14[0x34];
};

check_size(mmTrailerInstance, 0x48);

class mmTrailer final : public mmPhysEntity
{
public:
    // ??0mmTrailer@@QAE@XZ
    ARTS_IMPORT mmTrailer();

    // ??_EmmTrailer@@UAEPAXI@Z
    // ??1mmTrailer@@UAE@XZ | inline
    ARTS_IMPORT ~mmTrailer() override;

    // ?Activate@mmTrailer@@QAEXXZ
    ARTS_IMPORT void Activate();

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmTrailer@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?AfterLoad@mmTrailer@@UAEXXZ
    ARTS_IMPORT void AfterLoad() override;

    // ?BeforeSave@mmTrailer@@UAEXXZ
    ARTS_IMPORT void BeforeSave() override;

    // ?Deactivate@mmTrailer@@QAEXXZ
    ARTS_IMPORT void Deactivate();

    // ?GetBound@mmTrailer@@UAEPAVasBound@@XZ | inline
    ARTS_IMPORT asBound* GetBound() override;

    // ?GetClass@mmTrailer@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetICS@mmTrailer@@UAEPAVasInertialCS@@XZ | inline
    ARTS_IMPORT asInertialCS* GetICS() override;

    // ?Init@mmTrailer@@QAEXPADPAVmmCarSim@@VVector3@@@Z
    ARTS_IMPORT void Init(char* arg1, mmCarSim* arg2, Vector3 arg3);

    // ?PostUpdate@mmTrailer@@UAEXXZ
    ARTS_IMPORT void PostUpdate() override;

    // ?Reset@mmTrailer@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?RestoreImpactParams@mmTrailer@@QAEXXZ
    ARTS_IMPORT void RestoreImpactParams();

    // ?SetHackedImpactParams@mmTrailer@@QAEXXZ
    ARTS_IMPORT void SetHackedImpactParams();

    // ?Update@mmTrailer@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@mmTrailer@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    mmCarSim* CarSim;
    mmTrailerInstance Inst;
    asInertialCS ICS;
    asBound Bound;
    Vector3 InertiaBox;
    Vector3 Center;
    f32 BoundElasticity;
    f32 BoundFriction;
    f32 Mass;
    mmDrivetrain DrivetrainFL;
    mmDrivetrain DrivetrainFR;
    mmDrivetrain DrivetrainBL;
    mmDrivetrain DrivetrainBR;
    mmWheel WheelFL;
    mmWheel WheelFR;
    mmWheel WheelBL;
    mmWheel WheelBR;
    mmSkidManager SkidFL;
    mmSkidManager SkidFR;
    mmSkidManager SkidBL;
    mmSkidManager SkidBR;
    mmSplash Splash;
};

check_size(mmTrailer, 0x1204);
