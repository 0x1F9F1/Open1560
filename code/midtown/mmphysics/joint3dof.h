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

#include "joint.h"

#include "vector7/matrix34.h"

#define JOINT_FLAG_BROKEN 0x1
#define JOINT_FLAG_LIMIT 0x2 // DoJoint[Torque/Limits]

class Joint3Dof final : public JointedStruct
{
public:
    // ??0Joint3Dof@@QAE@XZ
    ARTS_IMPORT Joint3Dof();

    // ??1Joint3Dof@@UAE@XZ | inline
    ARTS_EXPORT ~Joint3Dof() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@Joint3Dof@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?BreakJoint@Joint3Dof@@QAEXXZ
    ARTS_IMPORT void BreakJoint();

    // ?DoJointLimits@Joint3Dof@@QAEXMABVVector3@@M0AAV2@ABVMatrix34@@2222@Z
    ARTS_IMPORT void DoJointLimits(f32 arg1, const Vector3& arg2, f32 arg3, const Vector3& arg4, Vector3& arg5,
        const Matrix34& arg6, const Matrix34& arg7, const Matrix34& arg8, const Matrix34& arg9, const Matrix34& arg10);

    // ?DoJointTorque@Joint3Dof@@QAEXABVMatrix34@@000AAM1AAVVector3@@11@Z
    ARTS_IMPORT void DoJointTorque(const Matrix34& arg1, const Matrix34& arg2, const Matrix34& arg3,
        const Matrix34& arg4, f32& arg5, f32& arg6, Vector3& arg7, f32& arg8, f32& arg9);

    // ?GetCMatrix@Joint3Dof@@UAEXPBVasInertialCS@@AAVMatrix34@@ABVVector3@@@Z
    ARTS_IMPORT void GetCMatrix(const asInertialCS* arg1, Matrix34& arg2, const Vector3& arg3) override;

    // ?GetCMatrix@Joint3Dof@@UAEXPBVasInertialCS@@0AAVMatrix34@@ABVVector3@@@Z
    ARTS_IMPORT void GetCMatrix(
        const asInertialCS* arg1, const asInertialCS* arg2, Matrix34& arg3, const Vector3& arg4) override;

    // ?GetClass@Joint3Dof@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@Joint3Dof@@QAEXXZ
    ARTS_IMPORT void Init();

    // ?InitJoint3Dof@Joint3Dof@@QAEXPAVasInertialCS@@ABVVector3@@01@Z
    ARTS_IMPORT void InitJoint3Dof(asInertialCS* arg1, const Vector3& arg2, asInertialCS* arg3, const Vector3& arg4);

    // ?MoveICS@Joint3Dof@@QAEXXZ
    void MoveICS();

    // ?Reset@Joint3Dof@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetFrictionLean@Joint3Dof@@QAEXMMM@Z
    ARTS_IMPORT void SetFrictionLean(f32 arg1, f32 arg2, f32 arg3);

    // ?SetFrictionRoll@Joint3Dof@@QAEXMMM@Z
    ARTS_IMPORT void SetFrictionRoll(f32 arg1, f32 arg2, f32 arg3);

    // ?SetJointForceFlag@Joint3Dof@@QAEXXZ
    ARTS_IMPORT void SetJointForceFlag();

    // ?SetLeanLimit@Joint3Dof@@QAEXMM@Z
    ARTS_IMPORT void SetLeanLimit(f32 arg1, f32 arg2);

    // ?SetPosition@Joint3Dof@@QAEXABVVector3@@@Z
    ARTS_IMPORT void SetPosition(const Vector3& arg1);

    // ?SetRestOrientMat@Joint3Dof@@QAEXABVMatrix34@@@Z
    ARTS_IMPORT void SetRestOrientMat(const Matrix34& arg1);

    // ?SetRestOrientMat@Joint3Dof@@QAEXABVMatrix34@@0@Z
    ARTS_IMPORT void SetRestOrientMat(const Matrix34& arg1, const Matrix34& arg2);

    // ?SetRollLimit@Joint3Dof@@QAEXMMM@Z
    ARTS_IMPORT void SetRollLimit(f32 arg1, f32 arg2, f32 arg3);

    // ?UnbreakJoint@Joint3Dof@@QAEXXZ
    ARTS_IMPORT void UnbreakJoint();

    // ?Update@Joint3Dof@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@Joint3Dof@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    b32 IsBroken() const
    {
        return (JointFlags & JOINT_FLAG_BROKEN) != 0;
    }

    asInertialCS* ICS1;
    asInertialCS* ICS2;
    Vector3 Offset1;
    Vector3 Offset2;
    Vector3 Position;
    f32 ForceLimit;
    i32 JointFlags;
    Matrix34 Orientation1;
    Matrix34 Orientation2;
    Vector3 FrictionLean;
    Vector3 FrictionRoll;
    f32 LeanLimit1;
    f32 RollLimit1;
    f32 RollLimit2;
    f32 LeanLimit2;
    f32 RollLimit3;
};

check_size(Joint3Dof, 0xE0);

// ?CrossProdMatrix@@YAXPAVMatrix34@@ABVVector3@@@Z | inline
ARTS_IMPORT void CrossProdMatrix(Matrix34* arg1, const Vector3& arg2);

// ?Veldiscrepancy@@3VVector3@@A
ARTS_IMPORT extern Vector3 Veldiscrepancy;

// ?discrepancy@@3VVector3@@A
ARTS_IMPORT extern Vector3 discrepancy;
