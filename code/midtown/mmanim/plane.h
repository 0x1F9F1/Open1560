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
    mmanim:plane

    0x4C4F20 | public: __thiscall mmAnimPlane::mmAnimPlane(void) | ??0mmAnimPlane@@QAE@XZ
    0x4C5010 | public: virtual __thiscall mmAnimPlane::~mmAnimPlane(void) | ??1mmAnimPlane@@UAE@XZ
    0x4C50C0 | public: void __thiscall mmAnimPlane::Init(int,char *,char *,class Vector3 *,int,int,float *) | ?Init@mmAnimPlane@@QAEXHPAD0PAVVector3@@HHPAM@Z
    0x4C52C0 | public: virtual void __thiscall mmAnimPlane::Reset(void) | ?Reset@mmAnimPlane@@UAEXXZ
    0x4C5330 | public: void __thiscall mmAnimPlane::Activate(void) | ?Activate@mmAnimPlane@@QAEXXZ
    0x4C5340 | public: void __thiscall mmAnimPlane::Deactivate(void) | ?Deactivate@mmAnimPlane@@QAEXXZ
    0x4C5350 | public: void __thiscall mmAnimPlane::Update(void) | ?Update@mmAnimPlane@@QAEXXZ
    0x4C5370 | public: void __thiscall mmAnimPlane::UpdatePathPosition(void) | ?UpdatePathPosition@mmAnimPlane@@QAEXXZ
    0x4C5540 | public: void __thiscall mmAnimPlane::SetPathSpeed(void) | ?SetPathSpeed@mmAnimPlane@@QAEXXZ
    0x4C5550 | public: void __thiscall mmAnimPlane::ReverseCalcPathSpeed(void) | ?ReverseCalcPathSpeed@mmAnimPlane@@QAEXXZ
    0x4C5560 | public: void __thiscall mmAnimPlane::SolvePosition(class Vector3 &,float &) | ?SolvePosition@mmAnimPlane@@QAEXAAVVector3@@AAM@Z
    0x4C5630 | public: void __thiscall mmAnimPlane::AdjustPhaseOffsets(void) | ?AdjustPhaseOffsets@mmAnimPlane@@QAEXXZ
    0x4C56A0 | public: void __thiscall mmAnimPlane::PreCalcCubics(void) | ?PreCalcCubics@mmAnimPlane@@QAEXXZ
    0x4C5770 | public: void __thiscall mmAnimPlane::CalculateCubics(int,class Vector4 &,class Vector4 &,class Vector4 &) | ?CalculateCubics@mmAnimPlane@@QAEXHAAVVector4@@00@Z
    0x4C58F0 | public: void __thiscall mmAnimPlane::SolveVector(float,class Vector3 &,class Vector3 &) | ?SolveVector@mmAnimPlane@@QAEXMAAVVector3@@0@Z
    0x4C5A70 | public: virtual void __fastcall mmAnimPlane::Draw(int) | ?Draw@mmAnimPlane@@UAIXH@Z
    0x4C5AC0 | private: void __thiscall mmAnimPlane::UpdateAudio(void) | ?UpdateAudio@mmAnimPlane@@AAEXXZ
    0x4C5C20 | private: void __thiscall mmAnimPlane::CalculateDistToPlayer2(void) | ?CalculateDistToPlayer2@mmAnimPlane@@AAEXXZ
    0x4C5CF0 | private: void __thiscall mmAnimPlane::CalculateAudioPanning(void) | ?CalculateAudioPanning@mmAnimPlane@@AAEXXZ
    0x4C5D40 | private: float __thiscall mmAnimPlane::CalculateDoppler(float) | ?CalculateDoppler@mmAnimPlane@@AAEMM@Z
    0x4C5E80 | public: virtual void * __thiscall mmAnimPlane::`scalar deleting destructor'(unsigned int) | ??_GmmAnimPlane@@UAEPAXI@Z
    0x4C5E80 | public: virtual void * __thiscall mmAnimPlane::`vector deleting destructor'(unsigned int) | ??_EmmAnimPlane@@UAEPAXI@Z
    0x61F570 | const mmAnimPlane::`vftable' | ??_7mmAnimPlane@@6B@
    0x6426F4 | private: static float mmAnimPlane::s_fAudioMinDistance | ?s_fAudioMinDistance@mmAnimPlane@@0MA
    0x6426F8 | private: static float mmAnimPlane::s_fCloserMinDistMult | ?s_fCloserMinDistMult@mmAnimPlane@@0MA
    0x6426FC | private: static float mmAnimPlane::s_fAudioMaxDistance | ?s_fAudioMaxDistance@mmAnimPlane@@0MA
    0x642700 | private: static float mmAnimPlane::s_fAudioVolume | ?s_fAudioVolume@mmAnimPlane@@0MA
    0x705E58 | private: static float mmAnimPlane::s_fAudioAttenuationMult | ?s_fAudioAttenuationMult@mmAnimPlane@@0MA
*/

#include "mmcity/inst.h"

class mmAnimPlane /*final*/ : public mmMatrixInstance
{
    // const mmAnimPlane::`vftable' @ 0x61F570

public:
    // 0x4C4F20 | ??0mmAnimPlane@@QAE@XZ
    ARTS_IMPORT mmAnimPlane();

    // 0x4C5E80 | ??_EmmAnimPlane@@UAEPAXI@Z
    // 0x4C5E80 | ??_GmmAnimPlane@@UAEPAXI@Z
    // 0x4C5010 | ??1mmAnimPlane@@UAE@XZ
    ARTS_IMPORT ~mmAnimPlane() override;

    // 0x4C5330 | ?Activate@mmAnimPlane@@QAEXXZ | unused
    ARTS_IMPORT void Activate();

    // 0x4C5630 | ?AdjustPhaseOffsets@mmAnimPlane@@QAEXXZ
    ARTS_IMPORT void AdjustPhaseOffsets();

    // 0x4C5770 | ?CalculateCubics@mmAnimPlane@@QAEXHAAVVector4@@00@Z
    ARTS_IMPORT void CalculateCubics(i32 arg1, class Vector4& arg2, class Vector4& arg3, class Vector4& arg4);

    // 0x4C5340 | ?Deactivate@mmAnimPlane@@QAEXXZ | unused
    ARTS_IMPORT void Deactivate();

    // 0x4C5A70 | ?Draw@mmAnimPlane@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // 0x4C50C0 | ?Init@mmAnimPlane@@QAEXHPAD0PAVVector3@@HHPAM@Z
    ARTS_IMPORT void Init(i32 arg1, char* arg2, char* arg3, class Vector3* arg4, i32 arg5, i32 arg6, f32* arg7);

    // 0x4C56A0 | ?PreCalcCubics@mmAnimPlane@@QAEXXZ
    ARTS_IMPORT void PreCalcCubics();

    // 0x4C52C0 | ?Reset@mmAnimPlane@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4C5550 | ?ReverseCalcPathSpeed@mmAnimPlane@@QAEXXZ | unused
    ARTS_IMPORT void ReverseCalcPathSpeed();

    // 0x4C5540 | ?SetPathSpeed@mmAnimPlane@@QAEXXZ
    ARTS_IMPORT void SetPathSpeed();

    // 0x4C5560 | ?SolvePosition@mmAnimPlane@@QAEXAAVVector3@@AAM@Z
    ARTS_IMPORT void SolvePosition(class Vector3& arg1, f32& arg2);

    // 0x4C58F0 | ?SolveVector@mmAnimPlane@@QAEXMAAVVector3@@0@Z
    ARTS_IMPORT void SolveVector(f32 arg1, class Vector3& arg2, class Vector3& arg3);

    // 0x4C5350 | ?Update@mmAnimPlane@@QAEXXZ
    ARTS_IMPORT void Update();

    // 0x4C5370 | ?UpdatePathPosition@mmAnimPlane@@QAEXXZ
    ARTS_IMPORT void UpdatePathPosition();

private:
    // 0x4C5CF0 | ?CalculateAudioPanning@mmAnimPlane@@AAEXXZ
    ARTS_IMPORT void CalculateAudioPanning();

    // 0x4C5C20 | ?CalculateDistToPlayer2@mmAnimPlane@@AAEXXZ
    ARTS_IMPORT void CalculateDistToPlayer2();

    // 0x4C5D40 | ?CalculateDoppler@mmAnimPlane@@AAEMM@Z
    ARTS_IMPORT f32 CalculateDoppler(f32 arg1);

    // 0x4C5AC0 | ?UpdateAudio@mmAnimPlane@@AAEXXZ
    ARTS_IMPORT void UpdateAudio();

    // 0x705E58 | ?s_fAudioAttenuationMult@mmAnimPlane@@0MA
    ARTS_IMPORT static f32 s_fAudioAttenuationMult;

    // 0x6426FC | ?s_fAudioMaxDistance@mmAnimPlane@@0MA
    ARTS_IMPORT static f32 s_fAudioMaxDistance;

    // 0x6426F4 | ?s_fAudioMinDistance@mmAnimPlane@@0MA
    ARTS_IMPORT static f32 s_fAudioMinDistance;

    // 0x642700 | ?s_fAudioVolume@mmAnimPlane@@0MA
    ARTS_IMPORT static f32 s_fAudioVolume;

    // 0x6426F8 | ?s_fCloserMinDistMult@mmAnimPlane@@0MA
    ARTS_IMPORT static f32 s_fCloserMinDistMult;

    u8 gap44[0xC4];
};

check_size(mmAnimPlane, 0x108);
