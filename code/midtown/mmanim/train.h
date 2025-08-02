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

class mmAnimTrain
{
public:
    // ??0mmAnimTrain@@QAE@XZ
    ARTS_IMPORT mmAnimTrain();

    // ??1mmAnimTrain@@QAE@XZ
    ARTS_IMPORT ~mmAnimTrain();

    // ?CalculateCubics@mmAnimTrain@@QAEXHAAVVector4@@00@Z
    ARTS_IMPORT void CalculateCubics(i32 arg1, Vector4& arg2, Vector4& arg3, Vector4& arg4);

    // ?ComputeXZCurve@mmAnimTrain@@QAEXAAVVector3@@000AAVVector4@@11@Z
    ARTS_IMPORT void ComputeXZCurve(
        Vector3& arg1, Vector3& arg2, Vector3& arg3, Vector3& arg4, Vector4& arg5, Vector4& arg6, Vector4& arg7);

    // ?GetStart@mmAnimTrain@@QAEXMAAHAAM@Z
    ARTS_IMPORT void GetStart(f32 arg1, i32& arg2, f32& arg3);

    // ?Init@mmAnimTrain@@QAEXHPAD0PAVVector3@@HHPAM@Z
    ARTS_IMPORT void Init(i32 arg1, char* arg2, char* arg3, Vector3* arg4, i32 arg5, i32 arg6, f32* arg7);

    // ?PreCalcCubics@mmAnimTrain@@QAEXXZ
    ARTS_IMPORT void PreCalcCubics();

    // ?Reset@mmAnimTrain@@QAEXXZ
    ARTS_IMPORT void Reset();

    // ?SetPathSpeed@mmAnimTrain@@QAEXXZ
    ARTS_IMPORT void SetPathSpeed();

    // ?SolvePosition@mmAnimTrain@@QAEXAAVVector3@@AAM@Z
    ARTS_IMPORT void SolvePosition(Vector3& arg1, f32& arg2);

    // ?SolveXZCurve@mmAnimTrain@@QAEXAAVVector3@@0M@Z
    ARTS_IMPORT void SolveXZCurve(Vector3& arg1, Vector3& arg2, f32 arg3);

    // ?Update@mmAnimTrain@@QAEXXZ
    ARTS_IMPORT void Update();

    // ?UpdatePathPosition@mmAnimTrain@@QAEXXZ
    ARTS_IMPORT void UpdatePathPosition();

private:
    // ?CalculateAudioPanning@mmAnimTrain@@AAEXXZ
    ARTS_IMPORT void CalculateAudioPanning();

    // ?CalculateDistToPlayer2@mmAnimTrain@@AAEXXZ
    ARTS_IMPORT void CalculateDistToPlayer2();

    // ?CalculateDoppler@mmAnimTrain@@AAEMM@Z
    ARTS_IMPORT f32 CalculateDoppler(f32 arg1);

    // ?UpdateAudio@mmAnimTrain@@AAEXXZ
    ARTS_IMPORT void UpdateAudio();

    // ?s_fAudioAttenuationMult@mmAnimTrain@@0MA
    ARTS_IMPORT static f32 s_fAudioAttenuationMult;

    // ?s_fAudioMaxDistance@mmAnimTrain@@0MA
    ARTS_IMPORT static f32 s_fAudioMaxDistance;

    // ?s_fAudioMinDistance@mmAnimTrain@@0MA
    ARTS_IMPORT static f32 s_fAudioMinDistance;

    // ?s_fAudioVolume@mmAnimTrain@@0MA
    ARTS_IMPORT static f32 s_fAudioVolume;

    // ?s_fCloserMinDistMult@mmAnimTrain@@0MA
    ARTS_IMPORT static f32 s_fCloserMinDistMult;

    u8 gap0[0x100];
};

check_size(mmAnimTrain, 0x100);

// ?SplineBasis@@3VMatrix44@@A
ARTS_IMPORT extern Matrix44 SplineBasis;

// ?TrainHermite@@3VMatrix44@@A
ARTS_IMPORT extern Matrix44 TrainHermite;
