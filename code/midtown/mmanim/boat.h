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
    // const mmBoat::`vftable' @ 0x61F5F8

public:
    // 0x4C7120 | ??0mmBoat@@QAE@XZ
    ARTS_IMPORT mmBoat();

    // 0x4C7FD0 | ??_EmmBoat@@UAEPAXI@Z
    // 0x4C7200 | ??1mmBoat@@UAE@XZ
    ARTS_IMPORT ~mmBoat() override;

#ifdef ARTS_DEV_BUILD
    // 0x4C7820 | ?AddWidgets@mmBoat@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // 0x4C77A0 | ?AdjustPhaseOffsets@mmBoat@@QAEXXZ
    ARTS_IMPORT void AdjustPhaseOffsets();

    // 0x4C7910 | ?CalculateCubics@mmBoat@@QAEXH@Z
    ARTS_IMPORT void CalculateCubics(i32 arg1);

    // 0x4C7C90 | ?ComputeXZCurve@mmBoat@@QAEXAAVVector3@@000@Z
    ARTS_IMPORT void ComputeXZCurve(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4);

    // 0x4C7FC0 | ?GetClass@mmBoat@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4C7270 | ?Init@mmBoat@@QAEXHPAD0PAVVector3@@HHPAM@Z | unused
    ARTS_IMPORT void Init(i32 arg1, char* arg2, char* arg3, class Vector3* arg4, i32 arg5, i32 arg6, f32* arg7);

    // 0x4C7570 | ?Reset@mmBoat@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4C76A0 | ?ReverseCalcPathSpeed@mmBoat@@QAEXXZ
    ARTS_IMPORT void ReverseCalcPathSpeed();

    // 0x4C7650 | ?SetPathSpeed@mmBoat@@QAEXXZ
    ARTS_IMPORT void SetPathSpeed();

    // 0x4C7670 | ?SetRock@mmBoat@@QAEXMM@Z | unused
    ARTS_IMPORT void SetRock(f32 arg1, f32 arg2);

    // 0x4C76C0 | ?SolvePosition@mmBoat@@QAEXAAVVector3@@AAM@Z
    ARTS_IMPORT void SolvePosition(class Vector3& arg1, f32& arg2);

    // 0x4C7B20 | ?SolveVector@mmBoat@@QAEXMAAVVector3@@0@Z | unused
    ARTS_IMPORT void SolveVector(f32 arg1, class Vector3& arg2, class Vector3& arg3);

    // 0x4C7D80 | ?SolveXZCurve@mmBoat@@QAEXAAVVector3@@0M@Z
    ARTS_IMPORT void SolveXZCurve(class Vector3& arg1, class Vector3& arg2, f32 arg3);

    // 0x4C75D0 | ?Update@mmBoat@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x4C7600 | ?UpdatePathPosition@mmBoat@@QAEXXZ
    ARTS_IMPORT void UpdatePathPosition();

    // 0x4C7E50 | ?DeclareFields@mmBoat@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x384];
};

check_size(mmBoat, 0x3A4);

// 0x705F70 | ?CatmullBasis@@3VMatrix44@@A
ARTS_IMPORT extern class Matrix44 CatmullBasis;

// 0x642848 | ?GSFDef@@3MA
ARTS_IMPORT extern f32 GSFDef;

// 0x705F30 | ?_Hermite@@3VMatrix44@@A
ARTS_IMPORT extern class Matrix44 _Hermite;

// 0x642808 | ?cb@@3PAMA
ARTS_IMPORT extern f32 cb[16];

// 0x705F08 | ?mmBoatMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmBoatMetaClass;
