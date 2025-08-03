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

#include "aiVehicleSpline.h"

class AudSound;
class mmOpponentImpactAudio;

class aiVehicleAmbient final : public aiVehicleSpline
{
public:
    // ??0aiVehicleAmbient@@QAE@XZ
    ARTS_IMPORT aiVehicleAmbient();

    // ??1aiVehicleAmbient@@QAE@XZ
    ARTS_IMPORT ~aiVehicleAmbient();

    // ?AssignSounds@aiVehicleAmbient@@QAEXPAVAudSound@@00PAVmmOpponentImpactAudio@@@Z
    ARTS_IMPORT void AssignSounds(AudSound* arg1, AudSound* arg2, AudSound* arg3, mmOpponentImpactAudio* arg4);

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
    ARTS_IMPORT mmOpponentImpactAudio* GetImpactAudioPtr() override;

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
