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

/*
    mmphysics:inertia

    0x4D91F0 | public: __thiscall asInertialCS::asInertialCS(void) | ??0asInertialCS@@QAE@XZ
    0x4D92F0 | public: void __thiscall asInertialCS::SetMass(float,float,float,float) | ?SetMass@asInertialCS@@QAEXMMMM@Z
    0x4D9400 | public: void __thiscall asInertialCS::SetDensity(float,float,float,float) | ?SetDensity@asInertialCS@@QAEXMMMM@Z
    0x4D9450 | public: void __thiscall asInertialCS::SetZeroDOF(float,float) | ?SetZeroDOF@asInertialCS@@QAEXMM@Z
    0x4D9510 | public: void __thiscall asInertialCS::Zero(void) | ?Zero@asInertialCS@@QAEXXZ
    0x4D9630 | public: virtual void __thiscall asInertialCS::Reset(void) | ?Reset@asInertialCS@@UAEXXZ
    0x4D9650 | public: void __thiscall asInertialCS::UpdateKids(void) | ?UpdateKids@asInertialCS@@QAEXXZ
    0x4D9680 | public: virtual void __thiscall asInertialCS::Update(void) | ?Update@asInertialCS@@UAEXXZ
    0x4D9740 | public: void __thiscall asInertialCS::FinishForces(void) | ?FinishForces@asInertialCS@@QAEXXZ
    0x4D9AE0 | public: void __thiscall asInertialCS::MoveICS(void) | ?MoveICS@asInertialCS@@QAEXXZ
    0x4D9B60 | public: void __thiscall asInertialCS::FinishUpdate(void) | ?FinishUpdate@asInertialCS@@QAEXXZ
    0x4DA200 | public: void __thiscall asInertialCS::ApplyForce(class Vector3 const &) | ?ApplyForce@asInertialCS@@QAEXABVVector3@@@Z
    0x4DA290 | public: void __thiscall asInertialCS::ApplyForce(class Vector3 const &,class Vector3 const &) | ?ApplyForce@asInertialCS@@QAEXABVVector3@@0@Z
    0x4DA3A0 | public: void __thiscall asInertialCS::ApplyTorque(class Vector3 const &) | ?ApplyTorque@asInertialCS@@QAEXABVVector3@@@Z
    0x4DA430 | public: void __thiscall asInertialCS::ApplyImpulse(class Vector3 const &) | ?ApplyImpulse@asInertialCS@@QAEXABVVector3@@@Z
    0x4DA4C0 | public: void __thiscall asInertialCS::ApplyImpulse(class Vector3 const &,class Vector3 const &) | ?ApplyImpulse@asInertialCS@@QAEXABVVector3@@0@Z
    0x4DA5D0 | public: void __thiscall asInertialCS::ApplyAngImpulse(class Vector3 const &) | ?ApplyAngImpulse@asInertialCS@@QAEXABVVector3@@@Z
    0x4DA660 | public: virtual void __thiscall asInertialCS::ApplyPush(class Vector3 const &,class Vector3 const &) | ?ApplyPush@asInertialCS@@UAEXABVVector3@@0@Z
    0x4DA7D0 | public: void __thiscall asInertialCS::ApplyPush(class Vector3 const &) | ?ApplyPush@asInertialCS@@QAEXABVVector3@@@Z
    0x4DA940 | public: void __thiscall asInertialCS::ApplyTurn(class Vector3 const &) | ?ApplyTurn@asInertialCS@@QAEXABVVector3@@@Z
    0x4DA980 | private: void __thiscall asInertialCS::DrawForce(class Vector3 const &,class Vector3 const &) | ?DrawForce@asInertialCS@@AAEXABVVector3@@0@Z
    0x4DA9D0 | private: void __thiscall asInertialCS::DrawForce(class Vector3 const &,class Vector3 const &,class Vector3 const &) | ?DrawForce@asInertialCS@@AAEXABVVector3@@00@Z
    0x4DAA20 | public: void __thiscall asInertialCS::DoConstrain(void) | ?DoConstrain@asInertialCS@@QAEXXZ
    0x4DAAD0 | public: class Vector3 __thiscall asInertialCS::GetVelocity(class Vector3 const *) | ?GetVelocity@asInertialCS@@QAE?AVVector3@@PBV2@@Z
    0x4DABA0 | public: void __thiscall asInertialCS::CalcCMatrix(class Matrix34 &,class Vector3 const &) const | ?CalcCMatrix@asInertialCS@@QBEXAAVMatrix34@@ABVVector3@@@Z
    0x4DAD70 | public: virtual void __thiscall asInertialCS::GetCMatrix(class Matrix34 &,class Vector3 const &) const | ?GetCMatrix@asInertialCS@@UBEXAAVMatrix34@@ABVVector3@@@Z
    0x4DADE0 | float __cdecl InertiaAxis(class Vector3 const &,class Vector3 const &) | ?InertiaAxis@@YAMABVVector3@@0@Z
    0x4DAE20 | class Vector3 __cdecl MatrixToAngVelocity(class Matrix34 const &,float) | ?MatrixToAngVelocity@@YA?AVVector3@@ABVMatrix34@@M@Z
    0x4DAEF0 | public: void __thiscall asInertialCS::MatricesToMomenta(class Matrix34 const &,class Matrix34 const &,float) | ?MatricesToMomenta@asInertialCS@@QAEXABVMatrix34@@0M@Z
    0x4DB120 | class Vector3 __cdecl MatrixToAngVelocity(class Matrix34 const &,class Matrix34 const &,float) | ?MatrixToAngVelocity@@YA?AVVector3@@ABVMatrix34@@0M@Z
    0x4DB180 | public: void __thiscall asInertialCS::FileIO(class MiniParser *) | ?FileIO@asInertialCS@@QAEXPAVMiniParser@@@Z
    0x4DB190 | public: virtual void __thiscall asInertialCS::AddWidgets(class Bank *) | ?AddWidgets@asInertialCS@@UAEXPAVBank@@@Z
    0x4DB970 | public: static void __cdecl asInertialCS::DeclareFields(void) | ?DeclareFields@asInertialCS@@SAXXZ
    0x4DBAF0 | public: virtual class MetaClass * __thiscall asInertialCS::GetClass(void) | ?GetClass@asInertialCS@@UAEPAVMetaClass@@XZ
    0x4DBB30 | public: void __thiscall Vector3::Set(float,float,float) | ?Set@Vector3@@QAEXMMM@Z
    0x4DBB50 | public: void __thiscall Vector3::operator+=(class Vector3 const &) | ??YVector3@@QAEXABV0@@Z
    0x4DBB80 | public: virtual void * __thiscall asInertialCS::`vector deleting destructor'(unsigned int) | ??_EasInertialCS@@UAEPAXI@Z
    0x61FA48 | const asInertialCS::`vftable' | ??_7asInertialCS@@6B@
    0x7190E8 | class MetaClass asInertialCSMetaClass | ?asInertialCSMetaClass@@3VMetaClass@@A
*/

class asInertialCS : public asLinearCS
{
    // const asInertialCS::`vftable' @ 0x61FA48

public:
    // 0x4D91F0 | ??0asInertialCS@@QAE@XZ
    asInertialCS();

    // 0x4DBB80 | ??_EasInertialCS@@UAEPAXI@Z
    // 0x453A30 | ??1asInertialCS@@UAE@XZ
    ~asInertialCS() override;

    // 0x4DA660 | ?ApplyPush@asInertialCS@@UAEXABVVector3@@0@Z
    virtual void ApplyPush(class Vector3 const& arg1, class Vector3 const& arg2);

    // 0x4DAD70 | ?GetCMatrix@asInertialCS@@UBEXAAVMatrix34@@ABVVector3@@@Z
    virtual void GetCMatrix(class Matrix34& arg1, class Vector3 const& arg2);

    // 0x4DB190 | ?AddWidgets@asInertialCS@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x4DA5D0 | ?ApplyAngImpulse@asInertialCS@@QAEXABVVector3@@@Z
    void ApplyAngImpulse(class Vector3 const& arg1);

    // 0x4DA200 | ?ApplyForce@asInertialCS@@QAEXABVVector3@@@Z
    void ApplyForce(class Vector3 const& arg1);

    // 0x4DA290 | ?ApplyForce@asInertialCS@@QAEXABVVector3@@0@Z
    void ApplyForce(class Vector3 const& arg1, class Vector3 const& arg2);

    // 0x4DA430 | ?ApplyImpulse@asInertialCS@@QAEXABVVector3@@@Z
    void ApplyImpulse(class Vector3 const& arg1);

    // 0x4DA4C0 | ?ApplyImpulse@asInertialCS@@QAEXABVVector3@@0@Z
    void ApplyImpulse(class Vector3 const& arg1, class Vector3 const& arg2);

    // 0x4DA7D0 | ?ApplyPush@asInertialCS@@QAEXABVVector3@@@Z
    void ApplyPush(class Vector3 const& arg1);

    // 0x4DA3A0 | ?ApplyTorque@asInertialCS@@QAEXABVVector3@@@Z
    void ApplyTorque(class Vector3 const& arg1);

    // 0x4DA940 | ?ApplyTurn@asInertialCS@@QAEXABVVector3@@@Z
    void ApplyTurn(class Vector3 const& arg1);

    // 0x4DABA0 | ?CalcCMatrix@asInertialCS@@QBEXAAVMatrix34@@ABVVector3@@@Z
    void CalcCMatrix(class Matrix34& arg1, class Vector3 const& arg2);

    // 0x4DAA20 | ?DoConstrain@asInertialCS@@QAEXXZ
    void DoConstrain();

    // 0x4DB180 | ?FileIO@asInertialCS@@QAEXPAVMiniParser@@@Z
    void FileIO(class MiniParser* arg1);

    // 0x4D9740 | ?FinishForces@asInertialCS@@QAEXXZ
    void FinishForces();

    // 0x4D9B60 | ?FinishUpdate@asInertialCS@@QAEXXZ
    void FinishUpdate();

    // 0x4DBAF0 | ?GetClass@asInertialCS@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4DAAD0 | ?GetVelocity@asInertialCS@@QAE?AVVector3@@PBV2@@Z
    class Vector3 GetVelocity(class Vector3 const* arg1);

    // 0x4DAEF0 | ?MatricesToMomenta@asInertialCS@@QAEXABVMatrix34@@0M@Z
    void MatricesToMomenta(class Matrix34 const& arg1, class Matrix34 const& arg2, f32 arg3);

    // 0x4D9AE0 | ?MoveICS@asInertialCS@@QAEXXZ
    void MoveICS();

    // 0x4D9630 | ?Reset@asInertialCS@@UAEXXZ
    void Reset() override;

    // 0x4D9400 | ?SetDensity@asInertialCS@@QAEXMMMM@Z
    void SetDensity(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x4D92F0 | ?SetMass@asInertialCS@@QAEXMMMM@Z
    void SetMass(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x4D9450 | ?SetZeroDOF@asInertialCS@@QAEXMM@Z
    void SetZeroDOF(f32 arg1, f32 arg2);

    // 0x4D9680 | ?Update@asInertialCS@@UAEXXZ
    void Update() override;

    // 0x4D9650 | ?UpdateKids@asInertialCS@@QAEXXZ
    void UpdateKids();

    // 0x4D9510 | ?Zero@asInertialCS@@QAEXXZ
    void Zero();

    // 0x4DB970 | ?DeclareFields@asInertialCS@@SAXXZ
    static void DeclareFields();

private:
    // 0x4DA980 | ?DrawForce@asInertialCS@@AAEXABVVector3@@0@Z
    void DrawForce(class Vector3 const& arg1, class Vector3 const& arg2);

    // 0x4DA9D0 | ?DrawForce@asInertialCS@@AAEXABVVector3@@00@Z
    void DrawForce(class Vector3 const& arg1, class Vector3 const& arg2, class Vector3 const& arg3);
};

check_size(asInertialCS, 0x1A8);

// 0x4DADE0 | ?InertiaAxis@@YAMABVVector3@@0@Z
f32 InertiaAxis(class Vector3 const& arg1, class Vector3 const& arg2);

// 0x4DAE20 | ?MatrixToAngVelocity@@YA?AVVector3@@ABVMatrix34@@M@Z
class Vector3 MatrixToAngVelocity(class Matrix34 const& arg1, f32 arg2);

// 0x4DB120 | ?MatrixToAngVelocity@@YA?AVVector3@@ABVMatrix34@@0M@Z
class Vector3 MatrixToAngVelocity(class Matrix34 const& arg1, class Matrix34 const& arg2, f32 arg3);

// 0x7190E8 | ?asInertialCSMetaClass@@3VMetaClass@@A
inline extern_var(0x3190E8_Offset, class MetaClass, asInertialCSMetaClass);
