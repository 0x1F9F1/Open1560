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
    mmai:aiVehicleAmbient

    0x44EC60 | public: __thiscall aiVehicleAmbient::aiVehicleAmbient(void) | ??0aiVehicleAmbient@@QAE@XZ
    0x44ED40 | public: __thiscall aiVehicleAmbient::~aiVehicleAmbient(void) | ??1aiVehicleAmbient@@QAE@XZ
    0x44EE10 | public: void __thiscall aiVehicleAmbient::Init(char *,int) | ?Init@aiVehicleAmbient@@QAEXPADH@Z
    0x44F200 | public: virtual void __thiscall aiVehicleAmbient::Reset(void) | ?Reset@aiVehicleAmbient@@UAEXXZ
    0x44F2E0 | public: virtual void __thiscall aiVehicleAmbient::Update(void) | ?Update@aiVehicleAmbient@@UAEXXZ
    0x44F490 | public: virtual void __thiscall aiVehicleAmbient::Impact(int) | ?Impact@aiVehicleAmbient@@UAEXH@Z
    0x44F540 | public: void __thiscall aiVehicleAmbient::UnAssignSounds(void) | ?UnAssignSounds@aiVehicleAmbient@@QAEXXZ
    0x44F620 | private: float __thiscall aiVehicleAmbient::CalculateDoppler(float) | ?CalculateDoppler@aiVehicleAmbient@@AAEMM@Z
    0x44F650 | private: float __thiscall aiVehicleAmbient::CalculateFerrariPitch(float,int) | ?CalculateFerrariPitch@aiVehicleAmbient@@AAEMMH@Z
    0x44F820 | public: void __thiscall aiVehicleAmbient::UpdateAudio(void) | ?UpdateAudio@aiVehicleAmbient@@QAEXXZ
    0x44F850 | private: void __thiscall aiVehicleAmbient::UpdateAudio(float) | ?UpdateAudio@aiVehicleAmbient@@AAEXM@Z
    0x44FBE0 | public: void __thiscall aiVehicleAmbient::CalculateDistToPlayer2(void) | ?CalculateDistToPlayer2@aiVehicleAmbient@@QAEXXZ
    0x44FCF0 | public: void __thiscall aiVehicleAmbient::CalculateAudioPanning(void) | ?CalculateAudioPanning@aiVehicleAmbient@@QAEXXZ
    0x44FD80 | public: virtual void __thiscall aiVehicleAmbient::DrawId(void) | ?DrawId@aiVehicleAmbient@@UAEXXZ
    0x44FD90 | public: void __thiscall aiVehicleAmbient::DrawBBox(short) | ?DrawBBox@aiVehicleAmbient@@QAEXF@Z
    0x4500F0 | public: void __thiscall aiVehicleAmbient::StopHorn(void) | ?StopHorn@aiVehicleAmbient@@QAEXXZ
    0x450120 | public: void __thiscall aiVehicleAmbient::PlayVoice(void) | ?PlayVoice@aiVehicleAmbient@@QAEXXZ
    0x450370 | public: void __thiscall aiVehicleAmbient::PlayHorn(void) | ?PlayHorn@aiVehicleAmbient@@QAEXXZ
    0x4505C0 | public: virtual void __thiscall aiVehicleAmbient::PlayHorn(float,float) | ?PlayHorn@aiVehicleAmbient@@UAEXMM@Z
    0x4506B0 | public: void __thiscall aiVehicleAmbient::PlayTrippleHorn(float) | ?PlayTrippleHorn@aiVehicleAmbient@@QAEXM@Z
    0x450790 | public: void __thiscall aiVehicleAmbient::UpdateHorn(void) | ?UpdateHorn@aiVehicleAmbient@@QAEXXZ
    0x450A30 | public: virtual void __thiscall aiVehicleAmbient::StopVoice(void) | ?StopVoice@aiVehicleAmbient@@UAEXXZ
    0x450A70 | public: void __thiscall aiVehicleAmbient::UpdateAudImpactReaction(void) | ?UpdateAudImpactReaction@aiVehicleAmbient@@QAEXXZ
    0x450AB0 | public: virtual void __thiscall aiVehicleAmbient::ImpactAudioReaction(float) | ?ImpactAudioReaction@aiVehicleAmbient@@UAEXM@Z
    0x450B10 | private: void __thiscall aiVehicleAmbient::ImpactAudioReaction(void) | ?ImpactAudioReaction@aiVehicleAmbient@@AAEXXZ
    0x450BF0 | public: void __thiscall aiVehicleAmbient::PlayDoubleHorn(float) | ?PlayDoubleHorn@aiVehicleAmbient@@QAEXM@Z
    0x450CC0 | private: void __thiscall aiVehicleAmbient::AddToAiAudMgr(void) | ?AddToAiAudMgr@aiVehicleAmbient@@AAEXXZ
    0x450DA0 | public: static void __cdecl aiVehicleAmbient::SetAudioMaxDistance(float) | ?SetAudioMaxDistance@aiVehicleAmbient@@SAXM@Z
    0x450DC0 | private: void __thiscall aiVehicleAmbient::UpdateDSound3DAudio(void) | ?UpdateDSound3DAudio@aiVehicleAmbient@@AAEXXZ
    0x451000 | public: void __thiscall aiVehicleAmbient::AssignSounds(class AudSound *,class AudSound *,class AudSound *,class mmOpponentImpactAudio *) | ?AssignSounds@aiVehicleAmbient@@QAEXPAVAudSound@@00PAVmmOpponentImpactAudio@@@Z
    0x451150 | public: static float __cdecl aiVehicleAmbient::GetSecsSinceImpactReaction(void) | ?GetSecsSinceImpactReaction@aiVehicleAmbient@@SAMXZ
    0x451160 | public: void __thiscall aiVehicleAmbient::Dump(void) | ?Dump@aiVehicleAmbient@@QAEXXZ
    0x4512F0 | public: class Vector3 __thiscall Vector3::operator+(class Vector3 const &) const | ??HVector3@@QBE?AV0@ABV0@@Z
    0x451320 | public: class Vector3 __thiscall Vector3::operator*(float) const | ??DVector3@@QBE?AV0@M@Z
    0x451350 | public: virtual int __thiscall aiVehicleAmbient::Type(void) | ?Type@aiVehicleAmbient@@UAEHXZ
    0x451360 | public: virtual class mmOpponentImpactAudio * __thiscall aiVehicleAmbient::GetImpactAudioPtr(void) | ?GetImpactAudioPtr@aiVehicleAmbient@@UAEPAVmmOpponentImpactAudio@@XZ
    0x61B7B8 | const aiVehicleAmbient::`vftable' | ??_7aiVehicleAmbient@@6B@
    0x6398B0 | private: static float aiVehicleAmbient::s_fAudioVolume | ?s_fAudioVolume@aiVehicleAmbient@@0MA
    0x6398B4 | private: static float aiVehicleAmbient::s_fAudioVolumeSemi | ?s_fAudioVolumeSemi@aiVehicleAmbient@@0MA
    0x6398B8 | private: static float aiVehicleAmbient::s_fAudioMaxDistance | ?s_fAudioMaxDistance@aiVehicleAmbient@@0MA
    0x6398BC | private: static float aiVehicleAmbient::s_fHornVolume | ?s_fHornVolume@aiVehicleAmbient@@0MA
    0x6398C0 | private: static float aiVehicleAmbient::s_fVoiceVolume | ?s_fVoiceVolume@aiVehicleAmbient@@0MA
    0x6398C4 | private: static float aiVehicleAmbient::s_fSecsSinceImpactReaction | ?s_fSecsSinceImpactReaction@aiVehicleAmbient@@0MA
    0x6A7AA0 | private: static float aiVehicleAmbient::s_fAttenuationMult | ?s_fAttenuationMult@aiVehicleAmbient@@0MA
    0x6A7AD0 | private: static short aiVehicleAmbient::s_iPrevSoundObjIndex | ?s_iPrevSoundObjIndex@aiVehicleAmbient@@0FA
*/

#include "aiVehicleSpline.h"

class aiVehicleAmbient /*final*/ : public aiVehicleSpline
{
    // const aiVehicleAmbient::`vftable' @ 0x61B7B8

public:
    // 0x44EC60 | ??0aiVehicleAmbient@@QAE@XZ
    ARTS_IMPORT aiVehicleAmbient();

    // 0x43BEF0 | ??_EaiVehicleAmbient@@QAEPAXI@Z | unused
    // 0x44ED40 | ??1aiVehicleAmbient@@QAE@XZ
    ARTS_IMPORT ~aiVehicleAmbient();

    // 0x451000 | ?AssignSounds@aiVehicleAmbient@@QAEXPAVAudSound@@00PAVmmOpponentImpactAudio@@@Z
    ARTS_IMPORT void AssignSounds(
        class AudSound* arg1, class AudSound* arg2, class AudSound* arg3, class mmOpponentImpactAudio* arg4);

    // 0x44FCF0 | ?CalculateAudioPanning@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void CalculateAudioPanning();

    // 0x44FBE0 | ?CalculateDistToPlayer2@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void CalculateDistToPlayer2();

    // 0x44FD90 | ?DrawBBox@aiVehicleAmbient@@QAEXF@Z
    ARTS_IMPORT void DrawBBox(i16 arg1);

    // 0x44FD80 | ?DrawId@aiVehicleAmbient@@UAEXXZ
    ARTS_IMPORT void DrawId() override;

    // 0x451160 | ?Dump@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void Dump();

    // 0x451360 | ?GetImpactAudioPtr@aiVehicleAmbient@@UAEPAVmmOpponentImpactAudio@@XZ | inline
    ARTS_IMPORT class mmOpponentImpactAudio* GetImpactAudioPtr() override;

    // 0x44F490 | ?Impact@aiVehicleAmbient@@UAEXH@Z
    ARTS_IMPORT void Impact(i32 arg1) override;

    // 0x450AB0 | ?ImpactAudioReaction@aiVehicleAmbient@@UAEXM@Z
    ARTS_IMPORT void ImpactAudioReaction(f32 arg1) override;

    // 0x44EE10 | ?Init@aiVehicleAmbient@@QAEXPADH@Z
    ARTS_IMPORT void Init(char* arg1, i32 arg2);

    // 0x450BF0 | ?PlayDoubleHorn@aiVehicleAmbient@@QAEXM@Z
    ARTS_IMPORT void PlayDoubleHorn(f32 arg1);

    // 0x450370 | ?PlayHorn@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void PlayHorn();

    // 0x4505C0 | ?PlayHorn@aiVehicleAmbient@@UAEXMM@Z
    ARTS_IMPORT void PlayHorn(f32 arg1, f32 arg2) override;

    // 0x4506B0 | ?PlayTrippleHorn@aiVehicleAmbient@@QAEXM@Z
    ARTS_IMPORT void PlayTrippleHorn(f32 arg1);

    // 0x450120 | ?PlayVoice@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void PlayVoice();

    // 0x44F200 | ?Reset@aiVehicleAmbient@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4500F0 | ?StopHorn@aiVehicleAmbient@@QAEXXZ | unused
    ARTS_IMPORT void StopHorn();

    // 0x450A30 | ?StopVoice@aiVehicleAmbient@@UAEXXZ
    ARTS_IMPORT void StopVoice() override;

    // 0x451350 | ?Type@aiVehicleAmbient@@UAEHXZ | inline
    ARTS_EXPORT i32 Type() override;

    // 0x44F540 | ?UnAssignSounds@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void UnAssignSounds();

    // 0x44F2E0 | ?Update@aiVehicleAmbient@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x450A70 | ?UpdateAudImpactReaction@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void UpdateAudImpactReaction();

    // 0x44F820 | ?UpdateAudio@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void UpdateAudio();

    // 0x450790 | ?UpdateHorn@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void UpdateHorn();

    // 0x451150 | ?GetSecsSinceImpactReaction@aiVehicleAmbient@@SAMXZ
    ARTS_IMPORT static f32 GetSecsSinceImpactReaction();

    // 0x450DA0 | ?SetAudioMaxDistance@aiVehicleAmbient@@SAXM@Z
    ARTS_IMPORT static void SetAudioMaxDistance(f32 arg1);

private:
    // 0x450CC0 | ?AddToAiAudMgr@aiVehicleAmbient@@AAEXXZ
    ARTS_IMPORT void AddToAiAudMgr();

    // 0x44F620 | ?CalculateDoppler@aiVehicleAmbient@@AAEMM@Z
    ARTS_IMPORT f32 CalculateDoppler(f32 arg1);

    // 0x44F650 | ?CalculateFerrariPitch@aiVehicleAmbient@@AAEMMH@Z
    ARTS_IMPORT f32 CalculateFerrariPitch(f32 arg1, i32 arg2);

    // 0x450B10 | ?ImpactAudioReaction@aiVehicleAmbient@@AAEXXZ
    ARTS_IMPORT void ImpactAudioReaction();

    // 0x44F850 | ?UpdateAudio@aiVehicleAmbient@@AAEXM@Z
    ARTS_IMPORT void UpdateAudio(f32 arg1);

    // 0x450DC0 | ?UpdateDSound3DAudio@aiVehicleAmbient@@AAEXXZ
    ARTS_IMPORT void UpdateDSound3DAudio();

    // 0x6A7AA0 | ?s_fAttenuationMult@aiVehicleAmbient@@0MA
    ARTS_IMPORT static f32 s_fAttenuationMult;

    // 0x6398B8 | ?s_fAudioMaxDistance@aiVehicleAmbient@@0MA
    ARTS_IMPORT static f32 s_fAudioMaxDistance;

    // 0x6398B0 | ?s_fAudioVolume@aiVehicleAmbient@@0MA
    ARTS_IMPORT static f32 s_fAudioVolume;

    // 0x6398B4 | ?s_fAudioVolumeSemi@aiVehicleAmbient@@0MA
    ARTS_IMPORT static f32 s_fAudioVolumeSemi;

    // 0x6398BC | ?s_fHornVolume@aiVehicleAmbient@@0MA
    ARTS_IMPORT static f32 s_fHornVolume;

    // 0x6398C4 | ?s_fSecsSinceImpactReaction@aiVehicleAmbient@@0MA
    ARTS_IMPORT static f32 s_fSecsSinceImpactReaction;

    // 0x6398C0 | ?s_fVoiceVolume@aiVehicleAmbient@@0MA
    ARTS_IMPORT static f32 s_fVoiceVolume;

    // 0x6A7AD0 | ?s_iPrevSoundObjIndex@aiVehicleAmbient@@0FA
    ARTS_IMPORT static i16 s_iPrevSoundObjIndex;

    u8 gapD8[0x60];
};

check_size(aiVehicleAmbient, 0x138);
