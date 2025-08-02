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

#include "arts7/linear.h"

class JointedStruct;

// Translation
#define ICS_CONSTRAIN_TX 0x1
#define ICS_CONSTRAIN_TY 0x2
#define ICS_CONSTRAIN_TZ 0x4

// Rotation
#define ICS_CONSTRAIN_RX 0x8
#define ICS_CONSTRAIN_RY 0x10
#define ICS_CONSTRAIN_RZ 0x20

#define ICS_CONSTRAIN_ALL 0x3F

#define ICS_CONSTRAIN_LINK 0x40
#define ICS_CONSTRAIN_80 0x80
#define ICS_CONSTRAIN_ZERODOF 0x400

#define ICS_STATE_OFF 0
#define ICS_STATE_AWAKE 1
#define ICS_STATE_ASLEEP 2

class asInertialCS final : public asLinearCS
{
public:
    // ??0asInertialCS@@QAE@XZ
    ARTS_EXPORT asInertialCS();

    // ??_EasInertialCS@@UAEPAXI@Z
    // ??1asInertialCS@@UAE@XZ | inline
    ARTS_EXPORT ~asInertialCS() override = default;

    // ?ApplyPush@asInertialCS@@UAEXABVVector3@@0@Z
    ARTS_IMPORT virtual void ApplyPush(const Vector3& push, const Vector3& arg2);

    // ?GetCMatrix@asInertialCS@@UBEXAAVMatrix34@@ABVVector3@@@Z
    ARTS_IMPORT virtual void GetCMatrix(Matrix34& arg1, const Vector3& arg2) const;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asInertialCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?ApplyAngImpulse@asInertialCS@@QAEXABVVector3@@@Z
    ARTS_IMPORT void ApplyAngImpulse(const Vector3& arg1);

    // ?ApplyForce@asInertialCS@@QAEXABVVector3@@@Z
    ARTS_IMPORT void ApplyForce(const Vector3& arg1);

    // ?ApplyForce@asInertialCS@@QAEXABVVector3@@0@Z
    ARTS_IMPORT void ApplyForce(const Vector3& arg1, const Vector3& arg2);

    // ?ApplyImpulse@asInertialCS@@QAEXABVVector3@@0@Z
    ARTS_IMPORT void ApplyImpulse(const Vector3& arg1, const Vector3& arg2);

    // ?ApplyPush@asInertialCS@@QAEXABVVector3@@@Z
    ARTS_IMPORT void ApplyPush(const Vector3& arg1);

    // ?ApplyTorque@asInertialCS@@QAEXABVVector3@@@Z
    ARTS_IMPORT void ApplyTorque(const Vector3& arg1);

    // ?CalcCMatrix@asInertialCS@@QBEXAAVMatrix34@@ABVVector3@@@Z
    ARTS_IMPORT void CalcCMatrix(Matrix34& arg1, const Vector3& arg2) const;

    // ?DoConstrain@asInertialCS@@QAEXXZ
    ARTS_IMPORT void DoConstrain();

    // ?FileIO@asInertialCS@@QAEXPAVMiniParser@@@Z | unused
    ARTS_EXPORT void FileIO(MiniParser* arg1);

    // ?FinishForces@asInertialCS@@QAEXXZ
    ARTS_IMPORT void FinishForces();

    // ?FinishUpdate@asInertialCS@@QAEXXZ
    ARTS_IMPORT void FinishUpdate();

    // ?GetClass@asInertialCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetVelocity@asInertialCS@@QAE?AVVector3@@PBV2@@Z
    ARTS_IMPORT Vector3 GetVelocity(const Vector3* arg1 = nullptr);

    // ?MoveICS@asInertialCS@@QAEXXZ
    ARTS_IMPORT void MoveICS();

    // ?Reset@asInertialCS@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetDensity@asInertialCS@@QAEXMMMM@Z
    ARTS_EXPORT void SetDensity(f32 size_x, f32 size_y, f32 size_z, f32 density);

    // ?SetMass@asInertialCS@@QAEXMMMM@Z
    ARTS_EXPORT void SetMass(f32 size_x, f32 size_y, f32 size_z, f32 mass);

    // ?Update@asInertialCS@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?Zero@asInertialCS@@QAEXXZ
    ARTS_IMPORT void Zero();

    // ?DeclareFields@asInertialCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    Vector3 Size {};
    f32 Mass {};
    f32 InvMass {};
    Vector3 Inertia {};
    Vector3 InvInertia {};
    Vector3 LinearMomentum {};
    Vector3 AngularMomentum {};
    Vector3 LinearVelocity {};
    Vector3 AngularVelocity {};
    Vector3 FrameVelocity {};
    Vector3 LinearForce {};
    Vector3 AngularTorque {};
    Vector3 LinearImpulse {};
    Vector3 AngularImpulse {};
    Vector3 LinearPush {};
    Vector3 TurnForce {};
    Vector3 FramePush {};
    i32 NumImpulses {};
    i32 field_148 {};
    f32 Elasticity {};
    f32 Friction {};
    Vector3 Gravity {0.0f, -10.0f, 0.0f};
    Vector3 field_160 {};
    Vector3 field_16C {};
    i32 Constraints {};
    i32 field_17C {-1};
    i32 State {};
    f32 Vel2 {0.1f};
    f32 AngVel2 {0.1f};
    f32 Time {1.0f};
    f32 Counter {};
    f32 ForceLimit2 {FLT_MAX};
    f32 ImpulseLimit2 {};
    JointedStruct* Joint {};
    f32 MaxAngVelocity {ARTS_PI * 10.0f};
    b32 LimitAngVelocity {};

private:
    // ?DrawForce@asInertialCS@@AAEXABVVector3@@0@Z
    ARTS_IMPORT void DrawForce(const Vector3& arg1, const Vector3& arg2);

    // ?DrawForce@asInertialCS@@AAEXABVVector3@@00@Z
    ARTS_IMPORT void DrawForce(const Vector3& arg1, const Vector3& arg2, const Vector3& arg3);
};

check_size(asInertialCS, 0x1A8);

// ?MatrixToAngVelocity@@YA?AVVector3@@ABVMatrix34@@M@Z
ARTS_IMPORT Vector3 MatrixToAngVelocity(const Matrix34& arg1, f32 arg2);
