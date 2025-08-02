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

class mmAnimPlane final : public mmMatrixInstance
{
public:
    // ??0mmAnimPlane@@QAE@XZ
    ARTS_IMPORT mmAnimPlane();

    // ??_EmmAnimPlane@@UAEPAXI@Z
    // ??_GmmAnimPlane@@UAEPAXI@Z
    // ??1mmAnimPlane@@UAE@XZ
    ARTS_IMPORT ~mmAnimPlane() override;

    // ?AdjustPhaseOffsets@mmAnimPlane@@QAEXXZ
    ARTS_IMPORT void AdjustPhaseOffsets();

    // ?CalculateCubics@mmAnimPlane@@QAEXHAAVVector4@@00@Z
    ARTS_IMPORT void CalculateCubics(i32 arg1, Vector4& arg2, Vector4& arg3, Vector4& arg4);

    // ?Draw@mmAnimPlane@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?Init@mmAnimPlane@@QAEXHPAD0PAVVector3@@HHPAM@Z
    ARTS_IMPORT void Init(i32 arg1, char* arg2, char* arg3, Vector3* arg4, i32 arg5, i32 arg6, f32* arg7);

    // ?PreCalcCubics@mmAnimPlane@@QAEXXZ
    ARTS_IMPORT void PreCalcCubics();

    // ?Reset@mmAnimPlane@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetPathSpeed@mmAnimPlane@@QAEXXZ
    ARTS_IMPORT void SetPathSpeed();

    // ?SolvePosition@mmAnimPlane@@QAEXAAVVector3@@AAM@Z
    ARTS_IMPORT void SolvePosition(Vector3& arg1, f32& arg2);

    // ?SolveVector@mmAnimPlane@@QAEXMAAVVector3@@0@Z
    ARTS_IMPORT void SolveVector(f32 arg1, Vector3& arg2, Vector3& arg3);

    // ?Update@mmAnimPlane@@QAEXXZ
    ARTS_IMPORT void Update();

    // ?UpdatePathPosition@mmAnimPlane@@QAEXXZ
    ARTS_IMPORT void UpdatePathPosition();

private:
    // ?CalculateAudioPanning@mmAnimPlane@@AAEXXZ
    ARTS_IMPORT void CalculateAudioPanning();

    // ?CalculateDistToPlayer2@mmAnimPlane@@AAEXXZ
    ARTS_IMPORT void CalculateDistToPlayer2();

    // ?CalculateDoppler@mmAnimPlane@@AAEMM@Z
    ARTS_IMPORT f32 CalculateDoppler(f32 arg1);

    // ?UpdateAudio@mmAnimPlane@@AAEXXZ
    ARTS_IMPORT void UpdateAudio();

    // ?s_fAudioAttenuationMult@mmAnimPlane@@0MA
    ARTS_IMPORT static f32 s_fAudioAttenuationMult;

    // ?s_fAudioMaxDistance@mmAnimPlane@@0MA
    ARTS_IMPORT static f32 s_fAudioMaxDistance;

    // ?s_fAudioMinDistance@mmAnimPlane@@0MA
    ARTS_IMPORT static f32 s_fAudioMinDistance;

    // ?s_fAudioVolume@mmAnimPlane@@0MA
    ARTS_IMPORT static f32 s_fAudioVolume;

    // ?s_fCloserMinDistMult@mmAnimPlane@@0MA
    ARTS_IMPORT static f32 s_fCloserMinDistMult;

    u8 gap44[0xC4];
};

check_size(mmAnimPlane, 0x108);
