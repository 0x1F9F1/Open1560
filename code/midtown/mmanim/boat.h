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
