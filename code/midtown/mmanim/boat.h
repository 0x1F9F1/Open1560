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
    mmanim:boat

    0x4C7120 | public: __thiscall mmBoat::mmBoat(void) | ??0mmBoat@@QAE@XZ
    0x4C7200 | public: virtual __thiscall mmBoat::~mmBoat(void) | ??1mmBoat@@UAE@XZ
    0x4C7270 | public: void __thiscall mmBoat::Init(int,char *,char *,class Vector3 *,int,int,float *) | ?Init@mmBoat@@QAEXHPAD0PAVVector3@@HHPAM@Z
    0x4C7570 | public: virtual void __thiscall mmBoat::Reset(void) | ?Reset@mmBoat@@UAEXXZ
    0x4C75D0 | public: virtual void __thiscall mmBoat::Update(void) | ?Update@mmBoat@@UAEXXZ
    0x4C7600 | public: void __thiscall mmBoat::UpdatePathPosition(void) | ?UpdatePathPosition@mmBoat@@QAEXXZ
    0x4C7650 | public: void __thiscall mmBoat::SetPathSpeed(void) | ?SetPathSpeed@mmBoat@@QAEXXZ
    0x4C7670 | public: void __thiscall mmBoat::SetRock(float,float) | ?SetRock@mmBoat@@QAEXMM@Z
    0x4C76A0 | public: void __thiscall mmBoat::ReverseCalcPathSpeed(void) | ?ReverseCalcPathSpeed@mmBoat@@QAEXXZ
    0x4C76C0 | public: void __thiscall mmBoat::SolvePosition(class Vector3 &,float &) | ?SolvePosition@mmBoat@@QAEXAAVVector3@@AAM@Z
    0x4C77A0 | public: void __thiscall mmBoat::AdjustPhaseOffsets(void) | ?AdjustPhaseOffsets@mmBoat@@QAEXXZ
    0x4C7820 | public: virtual void __thiscall mmBoat::AddWidgets(class Bank *) | ?AddWidgets@mmBoat@@UAEXPAVBank@@@Z
    0x4C7910 | public: void __thiscall mmBoat::CalculateCubics(int) | ?CalculateCubics@mmBoat@@QAEXH@Z
    0x4C7B20 | public: void __thiscall mmBoat::SolveVector(float,class Vector3 &,class Vector3 &) | ?SolveVector@mmBoat@@QAEXMAAVVector3@@0@Z
    0x4C7C90 | public: void __thiscall mmBoat::ComputeXZCurve(class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &) | ?ComputeXZCurve@mmBoat@@QAEXAAVVector3@@000@Z
    0x4C7D80 | public: void __thiscall mmBoat::SolveXZCurve(class Vector3 &,class Vector3 &,float) | ?SolveXZCurve@mmBoat@@QAEXAAVVector3@@0M@Z
    0x4C7E50 | public: static void __cdecl mmBoat::DeclareFields(void) | ?DeclareFields@mmBoat@@SAXXZ
    0x4C7FC0 | public: virtual class MetaClass * __thiscall mmBoat::GetClass(void) | ?GetClass@mmBoat@@UAEPAVMetaClass@@XZ
    0x4C7FD0 | public: virtual void * __thiscall mmBoat::`vector deleting destructor'(unsigned int) | ??_EmmBoat@@UAEPAXI@Z
    0x61F5F8 | const mmBoat::`vftable' | ??_7mmBoat@@6B@
    0x642808 | float * cb | ?cb@@3PAMA
    0x642848 | float GSFDef | ?GSFDef@@3MA
    0x705F08 | class MetaClass mmBoatMetaClass | ?mmBoatMetaClass@@3VMetaClass@@A
    0x705F30 | class Matrix44 _Hermite | ?_Hermite@@3VMatrix44@@A
    0x705F70 | class Matrix44 CatmullBasis | ?CatmullBasis@@3VMatrix44@@A
*/

#include "arts7/node.h"

class mmBoat final : public asNode
{
public:
    // ??0mmBoat@@QAE@XZ
    ARTS_IMPORT mmBoat();

    // ??_EmmBoat@@UAEPAXI@Z
    // ??1mmBoat@@UAE@XZ
    ARTS_IMPORT ~mmBoat() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmBoat@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?AdjustPhaseOffsets@mmBoat@@QAEXXZ
    ARTS_IMPORT void AdjustPhaseOffsets();

    // ?CalculateCubics@mmBoat@@QAEXH@Z
    ARTS_IMPORT void CalculateCubics(i32 arg1);

    // ?ComputeXZCurve@mmBoat@@QAEXAAVVector3@@000@Z
    ARTS_IMPORT void ComputeXZCurve(Vector3& arg1, Vector3& arg2, Vector3& arg3, Vector3& arg4);

    // ?GetClass@mmBoat@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Reset@mmBoat@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?ReverseCalcPathSpeed@mmBoat@@QAEXXZ
    ARTS_IMPORT void ReverseCalcPathSpeed();

    // ?SetPathSpeed@mmBoat@@QAEXXZ
    ARTS_IMPORT void SetPathSpeed();

    // ?SolvePosition@mmBoat@@QAEXAAVVector3@@AAM@Z
    ARTS_IMPORT void SolvePosition(Vector3& arg1, f32& arg2);

    // ?SolveXZCurve@mmBoat@@QAEXAAVVector3@@0M@Z
    ARTS_IMPORT void SolveXZCurve(Vector3& arg1, Vector3& arg2, f32 arg3);

    // ?Update@mmBoat@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdatePathPosition@mmBoat@@QAEXXZ
    ARTS_IMPORT void UpdatePathPosition();

    // ?DeclareFields@mmBoat@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x384];
};

check_size(mmBoat, 0x3A4);

// ?CatmullBasis@@3VMatrix44@@A
ARTS_IMPORT extern Matrix44 CatmullBasis;

// ?GSFDef@@3MA
ARTS_IMPORT extern f32 GSFDef;

// ?_Hermite@@3VMatrix44@@A
ARTS_IMPORT extern Matrix44 _Hermite;

// ?cb@@3PAMA
ARTS_IMPORT extern f32 cb[16];
