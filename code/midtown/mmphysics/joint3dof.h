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
    mmphysics:joint3dof

    0x4DBC20 | public: __thiscall Joint3Dof::Joint3Dof(void) | ??0Joint3Dof@@QAE@XZ
    0x4DBC70 | public: void __thiscall Joint3Dof::Init(void) | ?Init@Joint3Dof@@QAEXXZ
    0x4DBCE0 | public: virtual void __thiscall Joint3Dof::Reset(void) | ?Reset@Joint3Dof@@UAEXXZ
    0x4DBCF0 | public: void __thiscall Joint3Dof::InitJoint3Dof(class asInertialCS *,class Vector3 const &,class asInertialCS *,class Vector3 const &) | ?InitJoint3Dof@Joint3Dof@@QAEXPAVasInertialCS@@ABVVector3@@01@Z
    0x4DBD70 | public: void __thiscall Joint3Dof::SetPosition(class Vector3 const &) | ?SetPosition@Joint3Dof@@QAEXABVVector3@@@Z
    0x4DBE50 | public: void __thiscall Joint3Dof::SetRotate1(class Matrix34 const &) | ?SetRotate1@Joint3Dof@@QAEXABVMatrix34@@@Z
    0x4DBE70 | public: void __thiscall Joint3Dof::SetRotate2(class Matrix34 const &) | ?SetRotate2@Joint3Dof@@QAEXABVMatrix34@@@Z
    0x4DBE90 | public: void __thiscall Joint3Dof::SetFrictionLean(float,float,float) | ?SetFrictionLean@Joint3Dof@@QAEXMMM@Z
    0x4DBEC0 | public: void __thiscall Joint3Dof::SetFrictionRoll(float,float,float) | ?SetFrictionRoll@Joint3Dof@@QAEXMMM@Z
    0x4DBEF0 | public: void __thiscall Joint3Dof::SetLeanLimit(float,float) | ?SetLeanLimit@Joint3Dof@@QAEXMM@Z
    0x4DBF10 | public: void __thiscall Joint3Dof::SetRollLimit(float,float,float) | ?SetRollLimit@Joint3Dof@@QAEXMMM@Z
    0x4DBF40 | public: void __thiscall Joint3Dof::SetRestOrientation(void) | ?SetRestOrientation@Joint3Dof@@QAEXXZ
    0x4DBFB0 | public: void __thiscall Joint3Dof::SetRestOrientMat(class Matrix34 const &) | ?SetRestOrientMat@Joint3Dof@@QAEXABVMatrix34@@@Z
    0x4DBFF0 | public: void __thiscall Joint3Dof::SetRestOrientMat(class Matrix34 const &,class Matrix34 const &) | ?SetRestOrientMat@Joint3Dof@@QAEXABVMatrix34@@0@Z
    0x4DC040 | public: void __thiscall Joint3Dof::SetForceLimit(float) | ?SetForceLimit@Joint3Dof@@QAEXM@Z
    0x4DC050 | public: void __thiscall Joint3Dof::SetJointForceFlag(void) | ?SetJointForceFlag@Joint3Dof@@QAEXXZ
    0x4DC0F0 | public: virtual void __thiscall Joint3Dof::Update(void) | ?Update@Joint3Dof@@UAEXXZ
    0x4DD350 | public: void __thiscall Joint3Dof::MoveICS(void) | ?MoveICS@Joint3Dof@@QAEXXZ
    0x4DD3A0 | public: void __thiscall Joint3Dof::BreakJoint(void) | ?BreakJoint@Joint3Dof@@QAEXXZ
    0x4DD3D0 | public: void __thiscall Joint3Dof::UnbreakJoint(void) | ?UnbreakJoint@Joint3Dof@@QAEXXZ
    0x4DD400 | public: void __thiscall Joint3Dof::DoJointTorque(class Matrix34 const &,class Matrix34 const &,class Matrix34 const &,class Matrix34 const &,float &,float &,class Vector3 &,float &,float &) | ?DoJointTorque@Joint3Dof@@QAEXABVMatrix34@@000AAM1AAVVector3@@11@Z
    0x4DD990 | public: void __thiscall Joint3Dof::DoJointLimits(float,class Vector3 const &,float,class Vector3 const &,class Vector3 &,class Matrix34 const &,class Matrix34 const &,class Matrix34 const &,class Matrix34 const &,class Matrix34 const &) | ?DoJointLimits@Joint3Dof@@QAEXMABVVector3@@M0AAV2@ABVMatrix34@@2222@Z
    0x4DE050 | public: virtual void __thiscall Joint3Dof::GetCMatrix(class asInertialCS const *,class Matrix34 &,class Vector3 const &) | ?GetCMatrix@Joint3Dof@@UAEXPBVasInertialCS@@AAVMatrix34@@ABVVector3@@@Z
    0x4DE3B0 | public: virtual void __thiscall Joint3Dof::GetCMatrix(class asInertialCS const *,class asInertialCS const *,class Matrix34 &,class Vector3 const &) | ?GetCMatrix@Joint3Dof@@UAEXPBVasInertialCS@@0AAVMatrix34@@ABVVector3@@@Z
    0x4DE9A0 | public: virtual void __thiscall Joint3Dof::AddWidgets(class Bank *) | ?AddWidgets@Joint3Dof@@UAEXPAVBank@@@Z
    0x4DE9B0 | public: static void __cdecl Joint3Dof::DeclareFields(void) | ?DeclareFields@Joint3Dof@@SAXXZ
    0x4DEB20 | public: virtual class MetaClass * __thiscall Joint3Dof::GetClass(void) | ?GetClass@Joint3Dof@@UAEPAVMetaClass@@XZ
    0x4DEB60 | public: virtual __thiscall JointedStruct::~JointedStruct(void) | ??1JointedStruct@@UAE@XZ
    0x4DEB70 | public: class Vector3 __thiscall Vector3::operator^(class Matrix34 const &) const | ??TVector3@@QBE?AV0@ABVMatrix34@@@Z
    0x4DEBA0 | public: void __thiscall Vector3::operator-=(class Vector3 const &) | ??ZVector3@@QAEXABV0@@Z
    0x4DEBD0 | public: void __thiscall Vector3::operator*=(float) | ??XVector3@@QAEXM@Z
    0x4DEC00 | public: virtual void * __thiscall Joint3Dof::`vector deleting destructor'(unsigned int) | ??_EJoint3Dof@@UAEPAXI@Z
    0x4DEC60 | public: virtual __thiscall Joint3Dof::~Joint3Dof(void) | ??1Joint3Dof@@UAE@XZ
    0x4DEC70 | public: class Vector3 __thiscall Matrix34::RotateNoTrans(class Vector3 const &) const | ?RotateNoTrans@Matrix34@@QBE?AVVector3@@ABV2@@Z
    0x4DECA0 | public: class Matrix34 __thiscall Matrix34::Transpose(void) const | ?Transpose@Matrix34@@QBE?AV1@XZ
    0x4DECD0 | void __cdecl CrossProdMatrix(class Matrix34 *,class Vector3 const &) | ?CrossProdMatrix@@YAXPAVMatrix34@@ABVVector3@@@Z
    0x61FAE0 | const Joint3Dof::`vftable' | ??_7Joint3Dof@@6B@
    0x719118 | class MetaClass Joint3DofMetaClass | ?Joint3DofMetaClass@@3VMetaClass@@A
    0x719140 | class Vector3 Veldiscrepancy | ?Veldiscrepancy@@3VVector3@@A
    0x719150 | class Vector3 discrepancy | ?discrepancy@@3VVector3@@A
*/

#include "arts7/node.h"

#include "vector7/matrix34.h"

class asInertialCS;

class JointedStruct : public asNode
{
public:
    // ??1JointedStruct@@UAE@XZ | inline
    ARTS_IMPORT ~JointedStruct() = default;

    virtual void GetCMatrix(
        asInertialCS const* arg1, asInertialCS const* arg2, Matrix34& arg3, Vector3 const& arg4) = 0;

    virtual void GetCMatrix(asInertialCS const* arg1, Matrix34& arg2, Vector3 const& arg3) = 0;
};

check_size(JointedStruct, 0x20);

class Joint3Dof final : public JointedStruct
{
public:
    // ??0Joint3Dof@@QAE@XZ
    ARTS_IMPORT Joint3Dof();

    // ??_EJoint3Dof@@UAEPAXI@Z
    // ??1Joint3Dof@@UAE@XZ | inline
    ARTS_IMPORT ~Joint3Dof() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@Joint3Dof@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?BreakJoint@Joint3Dof@@QAEXXZ
    ARTS_IMPORT void BreakJoint();

    // ?DoJointLimits@Joint3Dof@@QAEXMABVVector3@@M0AAV2@ABVMatrix34@@2222@Z
    ARTS_IMPORT void DoJointLimits(f32 arg1, Vector3 const& arg2, f32 arg3, Vector3 const& arg4, Vector3& arg5,
        Matrix34 const& arg6, Matrix34 const& arg7, Matrix34 const& arg8, Matrix34 const& arg9, Matrix34 const& arg10);

    // ?DoJointTorque@Joint3Dof@@QAEXABVMatrix34@@000AAM1AAVVector3@@11@Z
    ARTS_IMPORT void DoJointTorque(Matrix34 const& arg1, Matrix34 const& arg2, Matrix34 const& arg3,
        Matrix34 const& arg4, f32& arg5, f32& arg6, Vector3& arg7, f32& arg8, f32& arg9);

    // ?GetCMatrix@Joint3Dof@@UAEXPBVasInertialCS@@AAVMatrix34@@ABVVector3@@@Z
    ARTS_IMPORT void GetCMatrix(asInertialCS const* arg1, Matrix34& arg2, Vector3 const& arg3) override;

    // ?GetCMatrix@Joint3Dof@@UAEXPBVasInertialCS@@0AAVMatrix34@@ABVVector3@@@Z
    ARTS_IMPORT void GetCMatrix(
        asInertialCS const* arg1, asInertialCS const* arg2, Matrix34& arg3, Vector3 const& arg4) override;

    // ?GetClass@Joint3Dof@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@Joint3Dof@@QAEXXZ
    ARTS_IMPORT void Init();

    // ?InitJoint3Dof@Joint3Dof@@QAEXPAVasInertialCS@@ABVVector3@@01@Z
    ARTS_IMPORT void InitJoint3Dof(asInertialCS* arg1, Vector3 const& arg2, asInertialCS* arg3, Vector3 const& arg4);

    // ?MoveICS@Joint3Dof@@QAEXXZ
    ARTS_EXPORT void MoveICS();

    // ?Reset@Joint3Dof@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetForceLimit@Joint3Dof@@QAEXM@Z | unused
    ARTS_IMPORT void SetForceLimit(f32 arg1);

    // ?SetFrictionLean@Joint3Dof@@QAEXMMM@Z
    ARTS_IMPORT void SetFrictionLean(f32 arg1, f32 arg2, f32 arg3);

    // ?SetFrictionRoll@Joint3Dof@@QAEXMMM@Z
    ARTS_IMPORT void SetFrictionRoll(f32 arg1, f32 arg2, f32 arg3);

    // ?SetJointForceFlag@Joint3Dof@@QAEXXZ
    ARTS_IMPORT void SetJointForceFlag();

    // ?SetLeanLimit@Joint3Dof@@QAEXMM@Z
    ARTS_IMPORT void SetLeanLimit(f32 arg1, f32 arg2);

    // ?SetPosition@Joint3Dof@@QAEXABVVector3@@@Z
    ARTS_IMPORT void SetPosition(Vector3 const& arg1);

    // ?SetRestOrientMat@Joint3Dof@@QAEXABVMatrix34@@@Z
    ARTS_IMPORT void SetRestOrientMat(Matrix34 const& arg1);

    // ?SetRestOrientMat@Joint3Dof@@QAEXABVMatrix34@@0@Z
    ARTS_IMPORT void SetRestOrientMat(Matrix34 const& arg1, Matrix34 const& arg2);

    // ?SetRestOrientation@Joint3Dof@@QAEXXZ | unused
    ARTS_IMPORT void SetRestOrientation();

    // ?SetRollLimit@Joint3Dof@@QAEXMMM@Z
    ARTS_IMPORT void SetRollLimit(f32 arg1, f32 arg2, f32 arg3);

    // ?SetRotate1@Joint3Dof@@QAEXABVMatrix34@@@Z | unused
    ARTS_IMPORT void SetRotate1(Matrix34 const& arg1);

    // ?SetRotate2@Joint3Dof@@QAEXABVMatrix34@@@Z | unused
    ARTS_IMPORT void SetRotate2(Matrix34 const& arg1);

    // ?UnbreakJoint@Joint3Dof@@QAEXXZ
    ARTS_IMPORT void UnbreakJoint();

    // ?Update@Joint3Dof@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@Joint3Dof@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    asInertialCS* CarICS;
    asInertialCS* TrailerICS;
    Vector3 CarOffset;
    Vector3 TrailerOffset;
    Vector3 Position;
    f32 ForceLimit;

#define JOINT_FLAG_BROKEN 0x1
#define JOINT_FLAG_LIMIT 0x2 // DoJoint[Torque/Limits]

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
ARTS_IMPORT void CrossProdMatrix(Matrix34* arg1, Vector3 const& arg2);

// ?Veldiscrepancy@@3VVector3@@A
ARTS_IMPORT extern Vector3 Veldiscrepancy;

// ?discrepancy@@3VVector3@@A
ARTS_IMPORT extern Vector3 discrepancy;
