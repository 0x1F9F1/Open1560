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

class aiVehicleAmbient final : public aiVehicleSpline
{
    // const aiVehicleAmbient::`vftable'

public:
    // ??0aiVehicleAmbient@@QAE@XZ
    ARTS_IMPORT aiVehicleAmbient();

    // ??_EaiVehicleAmbient@@QAEPAXI@Z | unused
    // ??1aiVehicleAmbient@@QAE@XZ
    ARTS_IMPORT ~aiVehicleAmbient();

    // ?AssignSounds@aiVehicleAmbient@@QAEXPAVAudSound@@00PAVmmOpponentImpactAudio@@@Z
    ARTS_IMPORT void AssignSounds(
        class AudSound* arg1, class AudSound* arg2, class AudSound* arg3, class mmOpponentImpactAudio* arg4);

    // ?CalculateAudioPanning@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void CalculateAudioPanning();

    // ?CalculateDistToPlayer2@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void CalculateDistToPlayer2();

    // ?DrawBBox@aiVehicleAmbient@@QAEXF@Z
    ARTS_IMPORT void DrawBBox(i16 arg1);

    // ?DrawId@aiVehicleAmbient@@UAEXXZ
    ARTS_IMPORT void DrawId() override;

    // ?Dump@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void Dump();

    // ?GetImpactAudioPtr@aiVehicleAmbient@@UAEPAVmmOpponentImpactAudio@@XZ | inline
    ARTS_IMPORT class mmOpponentImpactAudio* GetImpactAudioPtr() override;

    // ?Impact@aiVehicleAmbient@@UAEXH@Z
    ARTS_IMPORT void Impact(i32 arg1) override;

    // ?ImpactAudioReaction@aiVehicleAmbient@@UAEXM@Z
    ARTS_IMPORT void ImpactAudioReaction(f32 arg1) override;

    // ?Init@aiVehicleAmbient@@QAEXPADH@Z
    ARTS_IMPORT void Init(char* arg1, i32 arg2);

    // ?PlayDoubleHorn@aiVehicleAmbient@@QAEXM@Z
    ARTS_IMPORT void PlayDoubleHorn(f32 arg1);

    // ?PlayHorn@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void PlayHorn();

    // ?PlayHorn@aiVehicleAmbient@@UAEXMM@Z
    ARTS_IMPORT void PlayHorn(f32 arg1, f32 arg2) override;

    // ?PlayTrippleHorn@aiVehicleAmbient@@QAEXM@Z
    ARTS_IMPORT void PlayTrippleHorn(f32 arg1);

    // ?PlayVoice@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void PlayVoice();

    // ?Reset@aiVehicleAmbient@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?StopHorn@aiVehicleAmbient@@QAEXXZ | unused
    ARTS_IMPORT void StopHorn();

    // ?StopVoice@aiVehicleAmbient@@UAEXXZ
    ARTS_IMPORT void StopVoice() override;

    // ?Type@aiVehicleAmbient@@UAEHXZ | inline
    ARTS_EXPORT i32 Type() override;

    // ?UnAssignSounds@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void UnAssignSounds();

    // ?Update@aiVehicleAmbient@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateAudImpactReaction@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void UpdateAudImpactReaction();

    // ?UpdateAudio@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void UpdateAudio();

    // ?UpdateHorn@aiVehicleAmbient@@QAEXXZ
    ARTS_IMPORT void UpdateHorn();

    // ?GetSecsSinceImpactReaction@aiVehicleAmbient@@SAMXZ
    ARTS_IMPORT static f32 GetSecsSinceImpactReaction();

    // ?SetAudioMaxDistance@aiVehicleAmbient@@SAXM@Z
    ARTS_IMPORT static void SetAudioMaxDistance(f32 arg1);

private:
    // ?AddToAiAudMgr@aiVehicleAmbient@@AAEXXZ
    ARTS_IMPORT void AddToAiAudMgr();

    // ?CalculateDoppler@aiVehicleAmbient@@AAEMM@Z
    ARTS_IMPORT f32 CalculateDoppler(f32 arg1);

    // ?CalculateFerrariPitch@aiVehicleAmbient@@AAEMMH@Z
    ARTS_IMPORT f32 CalculateFerrariPitch(f32 arg1, i32 arg2);

    // ?ImpactAudioReaction@aiVehicleAmbient@@AAEXXZ
    ARTS_IMPORT void ImpactAudioReaction();

    // ?UpdateAudio@aiVehicleAmbient@@AAEXM@Z
    ARTS_IMPORT void UpdateAudio(f32 arg1);

    // ?UpdateDSound3DAudio@aiVehicleAmbient@@AAEXXZ
    ARTS_IMPORT void UpdateDSound3DAudio();

    // ?s_fAttenuationMult@aiVehicleAmbient@@0MA
    ARTS_IMPORT static f32 s_fAttenuationMult;

    // ?s_fAudioMaxDistance@aiVehicleAmbient@@0MA
    ARTS_IMPORT static f32 s_fAudioMaxDistance;

    // ?s_fAudioVolume@aiVehicleAmbient@@0MA
    ARTS_IMPORT static f32 s_fAudioVolume;

    // ?s_fAudioVolumeSemi@aiVehicleAmbient@@0MA
    ARTS_IMPORT static f32 s_fAudioVolumeSemi;

    // ?s_fHornVolume@aiVehicleAmbient@@0MA
    ARTS_IMPORT static f32 s_fHornVolume;

    // ?s_fSecsSinceImpactReaction@aiVehicleAmbient@@0MA
    ARTS_IMPORT static f32 s_fSecsSinceImpactReaction;

    // ?s_fVoiceVolume@aiVehicleAmbient@@0MA
    ARTS_IMPORT static f32 s_fVoiceVolume;

    // ?s_iPrevSoundObjIndex@aiVehicleAmbient@@0FA
    ARTS_IMPORT static i16 s_iPrevSoundObjIndex;

    u8 gapD8[0x60];
};

check_size(aiVehicleAmbient, 0x138);
