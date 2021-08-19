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

#include "arts7/linear.h"

class asInertialCS final : public asLinearCS
{
public:
    // ??0asInertialCS@@QAE@XZ
    ARTS_IMPORT asInertialCS();

    // ??_EasInertialCS@@UAEPAXI@Z
    // ??1asInertialCS@@UAE@XZ | inline
    ARTS_IMPORT ~asInertialCS() override = default;

    // ?ApplyPush@asInertialCS@@UAEXABVVector3@@0@Z
    ARTS_IMPORT virtual void ApplyPush(class Vector3 const& arg1, class Vector3 const& arg2);

    // ?GetCMatrix@asInertialCS@@UBEXAAVMatrix34@@ABVVector3@@@Z
    ARTS_IMPORT virtual void GetCMatrix(class Matrix34& arg1, class Vector3 const& arg2);

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asInertialCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // ?ApplyAngImpulse@asInertialCS@@QAEXABVVector3@@@Z
    ARTS_IMPORT void ApplyAngImpulse(class Vector3 const& arg1);

    // ?ApplyForce@asInertialCS@@QAEXABVVector3@@@Z
    ARTS_IMPORT void ApplyForce(class Vector3 const& arg1);

    // ?ApplyForce@asInertialCS@@QAEXABVVector3@@0@Z
    ARTS_IMPORT void ApplyForce(class Vector3 const& arg1, class Vector3 const& arg2);

    // ?ApplyImpulse@asInertialCS@@QAEXABVVector3@@@Z | unused
    ARTS_IMPORT void ApplyImpulse(class Vector3 const& arg1);

    // ?ApplyImpulse@asInertialCS@@QAEXABVVector3@@0@Z
    ARTS_IMPORT void ApplyImpulse(class Vector3 const& arg1, class Vector3 const& arg2);

    // ?ApplyPush@asInertialCS@@QAEXABVVector3@@@Z
    ARTS_IMPORT void ApplyPush(class Vector3 const& arg1);

    // ?ApplyTorque@asInertialCS@@QAEXABVVector3@@@Z
    ARTS_IMPORT void ApplyTorque(class Vector3 const& arg1);

    // ?ApplyTurn@asInertialCS@@QAEXABVVector3@@@Z | unused
    ARTS_IMPORT void ApplyTurn(class Vector3 const& arg1);

    // ?CalcCMatrix@asInertialCS@@QBEXAAVMatrix34@@ABVVector3@@@Z
    ARTS_IMPORT void CalcCMatrix(class Matrix34& arg1, class Vector3 const& arg2) const;

    // ?DoConstrain@asInertialCS@@QAEXXZ
    ARTS_IMPORT void DoConstrain();

    // ?FileIO@asInertialCS@@QAEXPAVMiniParser@@@Z | unused
    ARTS_EXPORT void FileIO(class MiniParser* arg1);

    // ?FinishForces@asInertialCS@@QAEXXZ
    ARTS_IMPORT void FinishForces();

    // ?FinishUpdate@asInertialCS@@QAEXXZ
    ARTS_IMPORT void FinishUpdate();

    // ?GetClass@asInertialCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?GetVelocity@asInertialCS@@QAE?AVVector3@@PBV2@@Z
    ARTS_IMPORT class Vector3 GetVelocity(class Vector3 const* arg1);

    // ?MatricesToMomenta@asInertialCS@@QAEXABVMatrix34@@0M@Z | unused
    ARTS_IMPORT void MatricesToMomenta(class Matrix34 const& arg1, class Matrix34 const& arg2, f32 arg3);

    // ?MoveICS@asInertialCS@@QAEXXZ
    ARTS_IMPORT void MoveICS();

    // ?Reset@asInertialCS@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetDensity@asInertialCS@@QAEXMMMM@Z
    ARTS_IMPORT void SetDensity(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // ?SetMass@asInertialCS@@QAEXMMMM@Z
    ARTS_IMPORT void SetMass(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // ?SetZeroDOF@asInertialCS@@QAEXMM@Z | unused
    ARTS_IMPORT void SetZeroDOF(f32 arg1, f32 arg2);

    // ?Update@asInertialCS@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateKids@asInertialCS@@QAEXXZ | unused
    ARTS_IMPORT void UpdateKids();

    // ?Zero@asInertialCS@@QAEXXZ
    ARTS_IMPORT void Zero();

    // ?DeclareFields@asInertialCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    offset_field(0x94, f32, Mass);
    offset_field(0x120, Vector3, LinearPush);

private:
    // ?DrawForce@asInertialCS@@AAEXABVVector3@@0@Z
    ARTS_IMPORT void DrawForce(class Vector3 const& arg1, class Vector3 const& arg2);

    // ?DrawForce@asInertialCS@@AAEXABVVector3@@00@Z
    ARTS_IMPORT void DrawForce(class Vector3 const& arg1, class Vector3 const& arg2, class Vector3 const& arg3);

    u8 gap88[0x120];
};

check_size(asInertialCS, 0x1A8);

// ?InertiaAxis@@YAMABVVector3@@0@Z | unused
ARTS_IMPORT f32 InertiaAxis(class Vector3 const& arg1, class Vector3 const& arg2);

// ?MatrixToAngVelocity@@YA?AVVector3@@ABVMatrix34@@M@Z
ARTS_IMPORT class Vector3 MatrixToAngVelocity(class Matrix34 const& arg1, f32 arg2);

// ?MatrixToAngVelocity@@YA?AVVector3@@ABVMatrix34@@0M@Z | unused
ARTS_IMPORT class Vector3 MatrixToAngVelocity(class Matrix34 const& arg1, class Matrix34 const& arg2, f32 arg3);

// ?asInertialCSMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass asInertialCSMetaClass;
