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

class aiPath;
class AudSound;
class mmIntersection;

class aiPedestrian final
{
public:
    // ??0aiPedestrian@@QAE@XZ
    ARTS_IMPORT aiPedestrian();

    // ??1aiPedestrian@@QAE@XZ
    ARTS_IMPORT ~aiPedestrian();

    // ?CalculateAudioPanning@aiPedestrian@@QAEXXZ
    ARTS_IMPORT void CalculateAudioPanning();

    // ?DrawDebug@aiPedestrian@@QAEXXZ
    ARTS_IMPORT void DrawDebug();

    // ?Init@aiPedestrian@@QAEXPADHH@Z
    ARTS_IMPORT void Init(char* arg1, i32 arg2, i32 arg3);

    // ?PlayVoice@aiPedestrian@@QAEXF@Z
    ARTS_IMPORT void PlayVoice(i16 arg1);

    // ?Reset@aiPedestrian@@QAEXXZ
    ARTS_IMPORT void Reset();

    // ?Reset@aiPedestrian@@QAEXPAVaiPath@@@Z
    ARTS_IMPORT void Reset(aiPath* arg1);

    // ?SetVoiceSoundPtr@aiPedestrian@@QAEXPAVAudSound@@@Z
    ARTS_IMPORT void SetVoiceSoundPtr(AudSound* arg1);

    // ?UnAssignSounds@aiPedestrian@@QAEXXZ
    ARTS_IMPORT void UnAssignSounds();

    // ?Update@aiPedestrian@@QAEXXZ
    ARTS_IMPORT void Update();

    // ?UpdateAudio@aiPedestrian@@QAEXXZ
    ARTS_IMPORT void UpdateAudio();

private:
    // ?Anticipate@aiPedestrian@@AAEXAAVmmIntersection@@H@Z
    ARTS_IMPORT void Anticipate(mmIntersection& arg1, i32 arg2);

    // ?Avoid@aiPedestrian@@AAEXAAVmmIntersection@@PAM@Z
    ARTS_IMPORT void Avoid(mmIntersection& arg1, f32* arg2);

    // ?AvoidBanger@aiPedestrian@@AAEXPAVmmInstance@@M@Z
    ARTS_IMPORT void AvoidBanger(mmInstance* arg1, f32 arg2);

    // ?AvoidObstacle@aiPedestrian@@AAEXAAVVector3@@M@Z
    ARTS_IMPORT void AvoidObstacle(Vector3& arg1, f32 arg2);

    // ?AvoidPedCollision@aiPedestrian@@AAEXPAV1@M@Z
    ARTS_IMPORT void AvoidPedCollision(aiPedestrian* arg1, f32 arg2);

    // ?AvoidPlayer@aiPedestrian@@AAEXAAVVector3@@M@Z
    ARTS_IMPORT void AvoidPlayer(Vector3& arg1, f32 arg2);

    // ?CalcCurve@aiPedestrian@@AAEXHHM@Z
    ARTS_IMPORT void CalcCurve(i32 arg1, i32 arg2, f32 arg3);

    // ?ComputeCurve@aiPedestrian@@AAEXAAVVector3@@000@Z
    ARTS_IMPORT void ComputeCurve(Vector3& arg1, Vector3& arg2, Vector3& arg3, Vector3& arg4);

    // ?DetectBangerCollision@aiPedestrian@@AAEHPAPAVmmInstance@@PAMM@Z
    ARTS_IMPORT i32 DetectBangerCollision(mmInstance** arg1, f32* arg2, f32 arg3);

    // ?DetectPedCollision@aiPedestrian@@AAEHMPAPAV1@PAM@Z
    ARTS_IMPORT i32 DetectPedCollision(f32 arg1, aiPedestrian** arg2, f32* arg3);

    // ?DetectPlayerAnticipate@aiPedestrian@@AAEHPAM0@Z
    ARTS_IMPORT i32 DetectPlayerAnticipate(f32* arg1, f32* arg2);

    // ?DetectPlayerCollision@aiPedestrian@@AAEHPAM@Z
    ARTS_IMPORT i32 DetectPlayerCollision(f32* arg1);

    // ?DetectPlayerForwardCollision@aiPedestrian@@AAEHPAM0@Z
    ARTS_IMPORT i32 DetectPlayerForwardCollision(f32* arg1, f32* arg2);

    // ?GetRaceVoiceIndex@aiPedestrian@@AAEFXZ
    ARTS_IMPORT i16 GetRaceVoiceIndex();

    // ?GetRoamVoiceIndex@aiPedestrian@@AAEFXZ
    ARTS_IMPORT i16 GetRoamVoiceIndex();

    // ?PickNextRdSeg@aiPedestrian@@AAEPAVaiPath@@XZ
    ARTS_IMPORT aiPath* PickNextRdSeg();

    // ?RoadDistance@aiPedestrian@@AAEMXZ
    ARTS_IMPORT f32 RoadDistance();

    // ?SolvePosition@aiPedestrian@@AAEXAAVVector3@@M@Z
    ARTS_IMPORT void SolvePosition(Vector3& arg1, f32 arg2);

    // ?SolveRoadSegment@aiPedestrian@@AAEXM@Z
    ARTS_IMPORT void SolveRoadSegment(f32 arg1);

    // ?SolveTargetPoint@aiPedestrian@@AAEXM@Z
    ARTS_IMPORT void SolveTargetPoint(f32 arg1);

    // ?TimeToCollision@aiPedestrian@@AAEMM@Z
    ARTS_IMPORT f32 TimeToCollision(f32 arg1);

    // ?Wander@aiPedestrian@@AAEXXZ
    ARTS_IMPORT void Wander();

    // ?s_fAttenuationMult@aiPedestrian@@0MA
    ARTS_IMPORT static f32 s_fAttenuationMult;

    // ?s_fAudioMaxDistance@aiPedestrian@@0MA
    ARTS_IMPORT static f32 s_fAudioMaxDistance;

    // ?s_fAudioVolume@aiPedestrian@@0MA
    ARTS_IMPORT static f32 s_fAudioVolume;

    u8 gap0[0xAC];
};

check_size(aiPedestrian, 0xAC);

class aiPedestrianInstance final : public mmInstance
{
public:
    // ??1aiPedestrianInstance@@UAE@XZ | inline
    ARTS_EXPORT ~aiPedestrianInstance() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@aiPedestrianInstance@@UAEXPAVBank@@@Z | inline
    ARTS_EXPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?ComputeLod@aiPedestrianInstance@@UAEHMM@Z | inline
    ARTS_IMPORT i32 ComputeLod(f32 arg1, f32 arg2) override;

    // ?Draw@aiPedestrianInstance@@UAIXH@Z | inline
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // ?DrawShadow@aiPedestrianInstance@@UAIXXZ | inline
    ARTS_IMPORT void ARTS_FASTCALL DrawShadow() override;

    // ?FromMatrix@aiPedestrianInstance@@UAIXABVMatrix34@@@Z | inline
    ARTS_IMPORT void ARTS_FASTCALL FromMatrix(const Matrix34& arg1) override;

    // ?GetPos@aiPedestrianInstance@@UAIAAVVector3@@XZ | inline
    ARTS_IMPORT Vector3& ARTS_FASTCALL GetPos() override;

    // ?ToMatrix@aiPedestrianInstance@@UAIAAVMatrix34@@AAV2@@Z | inline
    ARTS_IMPORT Matrix34& ARTS_FASTCALL ToMatrix(Matrix34& arg1) override;

    u8 gap14[0x14];
};

check_size(aiPedestrianInstance, 0x28);
