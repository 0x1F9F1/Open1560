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
    mmai:aiPedestrian

    0x447CC0 | public: __thiscall aiPedestrian::aiPedestrian(void) | ??0aiPedestrian@@QAE@XZ
    0x447DA0 | public: __thiscall aiPedestrian::~aiPedestrian(void) | ??1aiPedestrian@@QAE@XZ
    0x447DB0 | public: void __thiscall aiPedestrian::Init(char *,int,int) | ?Init@aiPedestrian@@QAEXPADHH@Z
    0x448130 | public: void __thiscall aiPedestrian::Reset(class aiPath *) | ?Reset@aiPedestrian@@QAEXPAVaiPath@@@Z
    0x448460 | public: void __thiscall aiPedestrian::Update(void) | ?Update@aiPedestrian@@QAEXXZ
    0x449850 | private: void __thiscall aiPedestrian::Wander(void) | ?Wander@aiPedestrian@@AAEXXZ
    0x449CB0 | private: void __thiscall aiPedestrian::Anticipate(class mmIntersection &,int) | ?Anticipate@aiPedestrian@@AAEXAAVmmIntersection@@H@Z
    0x449ED0 | private: void __thiscall aiPedestrian::Avoid(class mmIntersection &,float *) | ?Avoid@aiPedestrian@@AAEXAAVmmIntersection@@PAM@Z
    0x44A2D0 | private: float __thiscall aiPedestrian::TimeToCollision(float) | ?TimeToCollision@aiPedestrian@@AAEMM@Z
    0x44A2F0 | private: int __thiscall aiPedestrian::DetectPlayerForwardCollision(float *,float *) | ?DetectPlayerForwardCollision@aiPedestrian@@AAEHPAM0@Z
    0x44A4D0 | private: int __thiscall aiPedestrian::DetectPlayerAnticipate(float *,float *) | ?DetectPlayerAnticipate@aiPedestrian@@AAEHPAM0@Z
    0x44A690 | private: float __thiscall aiPedestrian::RoadDistance(void) | ?RoadDistance@aiPedestrian@@AAEMXZ
    0x44AD90 | private: void __thiscall aiPedestrian::SolveRoadSegment(float) | ?SolveRoadSegment@aiPedestrian@@AAEXM@Z
    0x44AED0 | private: class aiPath * __thiscall aiPedestrian::PickNextRdSeg(void) | ?PickNextRdSeg@aiPedestrian@@AAEPAVaiPath@@XZ
    0x44B0C0 | private: int __thiscall aiPedestrian::DetectPlayerCollision(float *) | ?DetectPlayerCollision@aiPedestrian@@AAEHPAM@Z
    0x44B420 | private: int __thiscall aiPedestrian::DetectBangerCollision(class mmInstance * *,float *,float) | ?DetectBangerCollision@aiPedestrian@@AAEHPAPAVmmInstance@@PAMM@Z
    0x44BA10 | private: class mmInstance * __thiscall aiPedestrian::DetectBangerObstacle(void) | ?DetectBangerObstacle@aiPedestrian@@AAEPAVmmInstance@@XZ
    0x44BB80 | private: class aiPedestrian * __thiscall aiPedestrian::DetectPedObstacle(void) | ?DetectPedObstacle@aiPedestrian@@AAEPAV1@XZ
    0x44BC00 | private: int __thiscall aiPedestrian::DetectPedCollision(float,class aiPedestrian * *,float *) | ?DetectPedCollision@aiPedestrian@@AAEHMPAPAV1@PAM@Z
    0x44C0E0 | private: void __thiscall aiPedestrian::AvoidPlayer(class Vector3 &,float) | ?AvoidPlayer@aiPedestrian@@AAEXAAVVector3@@M@Z
    0x44C170 | private: void __thiscall aiPedestrian::AvoidBanger(class mmInstance *,float) | ?AvoidBanger@aiPedestrian@@AAEXPAVmmInstance@@M@Z
    0x44C260 | private: void __thiscall aiPedestrian::AvoidPedCollision(class aiPedestrian *,float) | ?AvoidPedCollision@aiPedestrian@@AAEXPAV1@M@Z
    0x44C350 | private: void __thiscall aiPedestrian::AvoidObstacle(class Vector3 &,float) | ?AvoidObstacle@aiPedestrian@@AAEXAAVVector3@@M@Z
    0x44C670 | private: void __thiscall aiPedestrian::SolveTargetPoint(float) | ?SolveTargetPoint@aiPedestrian@@AAEXM@Z
    0x44C6E0 | private: void __thiscall aiPedestrian::CalcCurve(int,int,float) | ?CalcCurve@aiPedestrian@@AAEXHHM@Z
    0x44CDA0 | private: void __thiscall aiPedestrian::ComputeCurve(class Vector3 &,class Vector3 &,class Vector3 &,class Vector3 &) | ?ComputeCurve@aiPedestrian@@AAEXAAVVector3@@000@Z
    0x44CE50 | private: void __thiscall aiPedestrian::SolvePosition(class Vector3 &,float) | ?SolvePosition@aiPedestrian@@AAEXAAVVector3@@M@Z
    0x44CEA0 | public: void __thiscall aiPedestrian::PlayVoice(short) | ?PlayVoice@aiPedestrian@@QAEXF@Z
    0x44CF70 | public: void __thiscall aiPedestrian::CalculateDistToPlayer2(void) | ?CalculateDistToPlayer2@aiPedestrian@@QAEXXZ
    0x44CFC0 | public: void __thiscall aiPedestrian::CalculateAudioPanning(void) | ?CalculateAudioPanning@aiPedestrian@@QAEXXZ
    0x44D010 | public: void __thiscall aiPedestrian::UpdateAudio(void) | ?UpdateAudio@aiPedestrian@@QAEXXZ
    0x44D0E0 | public: void __thiscall aiPedestrian::SetVoiceSoundPtr(class AudSound *) | ?SetVoiceSoundPtr@aiPedestrian@@QAEXPAVAudSound@@@Z
    0x44D0F0 | public: void __thiscall aiPedestrian::UnAssignSounds(void) | ?UnAssignSounds@aiPedestrian@@QAEXXZ
    0x44D130 | public: void __thiscall aiPedestrian::Reset(void) | ?Reset@aiPedestrian@@QAEXXZ
    0x44D160 | public: void __thiscall aiPedestrian::Stop(void) | ?Stop@aiPedestrian@@QAEXXZ
    0x44D1A0 | public: void __thiscall aiPedestrian::Go(void) | ?Go@aiPedestrian@@QAEXXZ
    0x44D1E0 | public: void __thiscall aiPedestrian::Dump(void) | ?Dump@aiPedestrian@@QAEXXZ
    0x44D3B0 | public: void __thiscall aiPedestrian::DrawDebug(void) | ?DrawDebug@aiPedestrian@@QAEXXZ
    0x44D480 | private: short __thiscall aiPedestrian::GetRoamVoiceIndex(void) | ?GetRoamVoiceIndex@aiPedestrian@@AAEFXZ
    0x44D650 | private: short __thiscall aiPedestrian::GetRaceVoiceIndex(void) | ?GetRaceVoiceIndex@aiPedestrian@@AAEFXZ
    0x44D7F0 | public: virtual class Matrix34 & __fastcall aiPedestrianInstance::ToMatrix(class Matrix34 &) | ?ToMatrix@aiPedestrianInstance@@UAIAAVMatrix34@@AAV2@@Z
    0x44D800 | public: virtual void __fastcall aiPedestrianInstance::FromMatrix(class Matrix34 const &) | ?FromMatrix@aiPedestrianInstance@@UAIXABVMatrix34@@@Z
    0x44D810 | public: virtual class Vector3 & __fastcall aiPedestrianInstance::GetPos(void) | ?GetPos@aiPedestrianInstance@@UAIAAVVector3@@XZ
    0x44D820 | public: virtual int __thiscall aiPedestrianInstance::ComputeLod(float,float) | ?ComputeLod@aiPedestrianInstance@@UAEHMM@Z
    0x44D850 | public: virtual void __fastcall aiPedestrianInstance::Draw(int) | ?Draw@aiPedestrianInstance@@UAIXH@Z
    0x44D960 | public: virtual void __fastcall aiPedestrianInstance::DrawShadow(void) | ?DrawShadow@aiPedestrianInstance@@UAIXXZ
    0x44DA30 | public: virtual void __thiscall aiPedestrianInstance::AddWidgets(class Bank *) | ?AddWidgets@aiPedestrianInstance@@UAEXPAVBank@@@Z
    0x44DA40 | public: virtual void * __thiscall aiPedestrianInstance::`scalar deleting destructor'(unsigned int) | ??_GaiPedestrianInstance@@UAEPAXI@Z
    0x44DA40 | public: virtual void * __thiscall aiPedestrianInstance::`vector deleting destructor'(unsigned int) | ??_EaiPedestrianInstance@@UAEPAXI@Z
    0x44DA60 | public: virtual __thiscall aiPedestrianInstance::~aiPedestrianInstance(void) | ??1aiPedestrianInstance@@UAE@XZ
    0x61B660 | const aiPedestrianInstance::`vftable' | ??_7aiPedestrianInstance@@6B@
    0x639370 | private: static float aiPedestrian::s_fAudioVolume | ?s_fAudioVolume@aiPedestrian@@0MA
    0x639374 | private: static float aiPedestrian::s_fAudioMaxDistance | ?s_fAudioMaxDistance@aiPedestrian@@0MA
    0x6A7A18 | private: static float aiPedestrian::s_fAttenuationMult | ?s_fAttenuationMult@aiPedestrian@@0MA
*/

#include "mmcity/inst.h"

class aiPath;
class AudSound;
class mmIntersection;

class aiPedestrian final
{
public:
    // ??0aiPedestrian@@QAE@XZ
    ARTS_IMPORT aiPedestrian();

    // ??_EaiPedestrian@@QAEPAXI@Z | unused
    // ??1aiPedestrian@@QAE@XZ
    ARTS_IMPORT ~aiPedestrian();

    // ?CalculateAudioPanning@aiPedestrian@@QAEXXZ
    ARTS_IMPORT void CalculateAudioPanning();

    // ?CalculateDistToPlayer2@aiPedestrian@@QAEXXZ | unused
    ARTS_IMPORT void CalculateDistToPlayer2();

    // ?DrawDebug@aiPedestrian@@QAEXXZ
    ARTS_IMPORT void DrawDebug();

    // ?Dump@aiPedestrian@@QAEXXZ | unused
    ARTS_IMPORT void Dump();

    // ?Go@aiPedestrian@@QAEXXZ | unused
    ARTS_IMPORT void Go();

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

    // ?Stop@aiPedestrian@@QAEXXZ | unused
    ARTS_IMPORT void Stop();

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

    // ?DetectBangerObstacle@aiPedestrian@@AAEPAVmmInstance@@XZ | unused
    ARTS_IMPORT mmInstance* DetectBangerObstacle();

    // ?DetectPedCollision@aiPedestrian@@AAEHMPAPAV1@PAM@Z
    ARTS_IMPORT i32 DetectPedCollision(f32 arg1, aiPedestrian** arg2, f32* arg3);

    // ?DetectPedObstacle@aiPedestrian@@AAEPAV1@XZ | unused
    ARTS_IMPORT aiPedestrian* DetectPedObstacle();

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
    // ??_EaiPedestrianInstance@@UAEPAXI@Z
    // ??_GaiPedestrianInstance@@UAEPAXI@Z
    // ??1aiPedestrianInstance@@UAE@XZ | inline
    ARTS_IMPORT ~aiPedestrianInstance() override = default;

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
