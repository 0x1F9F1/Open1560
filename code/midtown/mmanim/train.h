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
    mmanim:train

    0x4C5F20 | public: __thiscall mmAnimTrain::mmAnimTrain(void) | ??0mmAnimTrain@@QAE@XZ
    0x4C6010 | public: __thiscall mmAnimTrain::~mmAnimTrain(void) | ??1mmAnimTrain@@QAE@XZ
    0x4C6080 | public: void __thiscall mmAnimTrain::Init(int,char *,char *,class Vector3 *,int,int,float *) | ?Init@mmAnimTrain@@QAEXHPAD0PAVVector3@@HHPAM@Z
    0x4C6350 | public: void __thiscall mmAnimTrain::Reset(void) | ?Reset@mmAnimTrain@@QAEXXZ
    0x4C63C0 | public: void __thiscall mmAnimTrain::Update(void) | ?Update@mmAnimTrain@@QAEXXZ
    0x4C6460 | public: void __thiscall mmAnimTrain::UpdatePathPosition(void) | ?UpdatePathPosition@mmAnimTrain@@QAEXXZ
    0x4C65B0 | public: void __thiscall mmAnimTrain::SetPathSpeed(void) | ?SetPathSpeed@mmAnimTrain@@QAEXXZ
    0x4C65C0 | public: void __thiscall mmAnimTrain::ReverseCalcPathSpeed(void) | ?ReverseCalcPathSpeed@mmAnimTrain@@QAEXXZ
    0x4C65D0 | public: void __thiscall mmAnimTrain::SolvePosition(class Vector3 &,float &) | ?SolvePosition@mmAnimTrain@@QAEXAAVVector3@@AAM@Z
    0x4C66D0 | public: void __thiscall mmAnimTrain::AdjustPhaseOffsets(void) | ?AdjustPhaseOffsets@mmAnimTrain@@QAEXXZ
    0x4C6740 | public: void __thiscall mmAnimTrain::GetStart(float,int &,float &) | ?GetStart@mmAnimTrain@@QAEXMAAHAAM@Z
    0x4C67C0 | public: void __thiscall mmAnimTrain::PreCalcCubics(void) | ?PreCalcCubics@mmAnimTrain@@QAEXXZ
    0x4C6890 | public: void __thiscall mmAnimTrain::CalculateCubics(int,class Vector4 &,class Vector4 &,class Vector4 &) | ?CalculateCubics@mmAnimTrain@@QAEXHAAVVector4@@00@Z
    0x4C6A90 | public: void __thiscall mmAnimTrain::ComputeXZCurve(class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &,class Vector4 &,class Vector4 &,class Vector4 &) | ?ComputeXZCurve@mmAnimTrain@@QAEXAAVVector3@@000AAVVector4@@11@Z
    0x4C6B70 | public: void __thiscall mmAnimTrain::SolveXZCurve(class Vector3 &,class Vector3 &,float) | ?SolveXZCurve@mmAnimTrain@@QAEXAAVVector3@@0M@Z
    0x4C6CA0 | private: void __thiscall mmAnimTrain::UpdateAudio(void) | ?UpdateAudio@mmAnimTrain@@AAEXXZ
    0x4C6E00 | private: void __thiscall mmAnimTrain::CalculateDistToPlayer2(void) | ?CalculateDistToPlayer2@mmAnimTrain@@AAEXXZ
    0x4C6ED0 | private: void __thiscall mmAnimTrain::CalculateAudioPanning(void) | ?CalculateAudioPanning@mmAnimTrain@@AAEXXZ
    0x4C6F20 | private: float __thiscall mmAnimTrain::CalculateDoppler(float) | ?CalculateDoppler@mmAnimTrain@@AAEMM@Z
    0x4C7060 | public: virtual void * __thiscall mmAnimTrainCar::`vector deleting destructor'(unsigned int) | ??_EmmAnimTrainCar@@UAEPAXI@Z
    0x642780 | private: static float mmAnimTrain::s_fAudioMinDistance | ?s_fAudioMinDistance@mmAnimTrain@@0MA
    0x642784 | private: static float mmAnimTrain::s_fCloserMinDistMult | ?s_fCloserMinDistMult@mmAnimTrain@@0MA
    0x642788 | private: static float mmAnimTrain::s_fAudioMaxDistance | ?s_fAudioMaxDistance@mmAnimTrain@@0MA
    0x64278C | private: static float mmAnimTrain::s_fAudioVolume | ?s_fAudioVolume@mmAnimTrain@@0MA
    0x705E70 | class Matrix44 TrainHermite | ?TrainHermite@@3VMatrix44@@A
    0x705EB0 | class Matrix44 SplineBasis | ?SplineBasis@@3VMatrix44@@A
    0x705EFC | private: static float mmAnimTrain::s_fAudioAttenuationMult | ?s_fAudioAttenuationMult@mmAnimTrain@@0MA
*/

struct mmAnimTrain
{
public:
    // 0x4C5F20 | ??0mmAnimTrain@@QAE@XZ
    mmAnimTrain();

    // 0x4C6010 | ??1mmAnimTrain@@QAE@XZ
    ~mmAnimTrain();

    // 0x4C66D0 | ?AdjustPhaseOffsets@mmAnimTrain@@QAEXXZ | unused
    void AdjustPhaseOffsets();

    // 0x4C6890 | ?CalculateCubics@mmAnimTrain@@QAEXHAAVVector4@@00@Z
    void CalculateCubics(i32 arg1, class Vector4& arg2, class Vector4& arg3, class Vector4& arg4);

    // 0x4C6A90 | ?ComputeXZCurve@mmAnimTrain@@QAEXAAVVector3@@000AAVVector4@@11@Z
    void ComputeXZCurve(class Vector3& arg1, class Vector3& arg2, class Vector3& arg3, class Vector3& arg4,
        class Vector4& arg5, class Vector4& arg6, class Vector4& arg7);

    // 0x4C6740 | ?GetStart@mmAnimTrain@@QAEXMAAHAAM@Z
    void GetStart(f32 arg1, i32& arg2, f32& arg3);

    // 0x4C6080 | ?Init@mmAnimTrain@@QAEXHPAD0PAVVector3@@HHPAM@Z
    void Init(i32 arg1, char* arg2, char* arg3, class Vector3* arg4, i32 arg5, i32 arg6, f32* arg7);

    // 0x4C67C0 | ?PreCalcCubics@mmAnimTrain@@QAEXXZ
    void PreCalcCubics();

    // 0x4C6350 | ?Reset@mmAnimTrain@@QAEXXZ
    void Reset();

    // 0x4C65C0 | ?ReverseCalcPathSpeed@mmAnimTrain@@QAEXXZ | unused
    void ReverseCalcPathSpeed();

    // 0x4C65B0 | ?SetPathSpeed@mmAnimTrain@@QAEXXZ
    void SetPathSpeed();

    // 0x4C65D0 | ?SolvePosition@mmAnimTrain@@QAEXAAVVector3@@AAM@Z
    void SolvePosition(class Vector3& arg1, f32& arg2);

    // 0x4C6B70 | ?SolveXZCurve@mmAnimTrain@@QAEXAAVVector3@@0M@Z
    void SolveXZCurve(class Vector3& arg1, class Vector3& arg2, f32 arg3);

    // 0x4C63C0 | ?Update@mmAnimTrain@@QAEXXZ
    void Update();

    // 0x4C6460 | ?UpdatePathPosition@mmAnimTrain@@QAEXXZ
    void UpdatePathPosition();

private:
    // 0x4C6ED0 | ?CalculateAudioPanning@mmAnimTrain@@AAEXXZ
    void CalculateAudioPanning();

    // 0x4C6E00 | ?CalculateDistToPlayer2@mmAnimTrain@@AAEXXZ
    void CalculateDistToPlayer2();

    // 0x4C6F20 | ?CalculateDoppler@mmAnimTrain@@AAEMM@Z
    f32 CalculateDoppler(f32 arg1);

    // 0x4C6CA0 | ?UpdateAudio@mmAnimTrain@@AAEXXZ
    void UpdateAudio();

    // 0x705EFC | ?s_fAudioAttenuationMult@mmAnimTrain@@0MA
    static inline extern_var(0x705EFC, f32, s_fAudioAttenuationMult);

    // 0x642788 | ?s_fAudioMaxDistance@mmAnimTrain@@0MA
    static inline extern_var(0x642788, f32, s_fAudioMaxDistance);

    // 0x642780 | ?s_fAudioMinDistance@mmAnimTrain@@0MA
    static inline extern_var(0x642780, f32, s_fAudioMinDistance);

    // 0x64278C | ?s_fAudioVolume@mmAnimTrain@@0MA
    static inline extern_var(0x64278C, f32, s_fAudioVolume);

    // 0x642784 | ?s_fCloserMinDistMult@mmAnimTrain@@0MA
    static inline extern_var(0x642784, f32, s_fCloserMinDistMult);
};

check_size(mmAnimTrain, 0x100);

// 0x705EB0 | ?SplineBasis@@3VMatrix44@@A
inline extern_var(0x705EB0, class Matrix44, SplineBasis);

// 0x705E70 | ?TrainHermite@@3VMatrix44@@A
inline extern_var(0x705E70, class Matrix44, TrainHermite);
