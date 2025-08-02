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

#include "aiVehicle.h"

#include "aiRailSet.h"

class mmOpponentImpactAudio;
class DLPTemplate;
class aiVehicleInstance;

class aiVehicleSpline : public aiVehicle
{
public:
    // ??0aiVehicleSpline@@QAE@XZ
    ARTS_IMPORT aiVehicleSpline();

    // ??_EaiVehicleSpline@@QAEPAXI@Z | unused
    // ??1aiVehicleSpline@@QAE@XZ
    ARTS_IMPORT ~aiVehicleSpline();

    // ?Impact@aiVehicleSpline@@UAEXH@Z
    ARTS_EXPORT virtual void Impact(i32 arg1);

    // ?GetImpactAudioPtr@aiVehicleSpline@@UAEPAVmmOpponentImpactAudio@@XZ | inline
    ARTS_EXPORT virtual mmOpponentImpactAudio* GetImpactAudioPtr();

    // ?PlayHorn@aiVehicleSpline@@UAEXMM@Z | inline
    ARTS_EXPORT virtual void PlayHorn(f32 arg1, f32 arg2);

    // ?ImpactAudioReaction@aiVehicleSpline@@UAEXM@Z | inline
    ARTS_EXPORT virtual void ImpactAudioReaction(f32 arg1);

    // ?StopVoice@aiVehicleSpline@@UAEXXZ | inline
    ARTS_EXPORT virtual void StopVoice();

    // ?GetClass@aiVehicleSpline@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT virtual MetaClass* GetClass();

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@aiVehicleSpline@@QAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(Bank* arg1);
#endif

    // ?DetectPlayerZoneCollision@aiVehicleSpline@@QAEHXZ
    ARTS_IMPORT i32 DetectPlayerZoneCollision();

    // ?DistanceToIntersection@aiVehicleSpline@@QAEMXZ
    ARTS_IMPORT f32 DistanceToIntersection();

    // ?DistanceToVehicle@aiVehicleSpline@@QAEMPAV1@@Z
    ARTS_IMPORT f32 DistanceToVehicle(aiVehicleSpline* arg1);

    // ?DrawId@aiVehicleSpline@@UAEXXZ
    ARTS_IMPORT void DrawId() override;

    // ?Dump@aiVehicleSpline@@QAEXXZ
    ARTS_IMPORT void Dump();

    // ?Init@aiVehicleSpline@@QAEXPADH@Z
    ARTS_IMPORT void Init(char* arg1, i32 arg2);

    // ?IsAmbientBlockingPlayer@aiVehicleSpline@@QAEHXZ
    ARTS_IMPORT i32 IsAmbientBlockingPlayer();

    // ?IsThePlayerInFrontOfMe@aiVehicleSpline@@QAEHXZ
    ARTS_IMPORT i32 IsThePlayerInFrontOfMe();

    // ?Reset@aiVehicleSpline@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?ResetReactTicks@aiVehicleSpline@@QAEXXZ
    ARTS_IMPORT void ResetReactTicks();

    // ?SolvePositionAndOrientation@aiVehicleSpline@@QAEXXZ
    ARTS_IMPORT void SolvePositionAndOrientation();

    // ?SolveYPositionAndOrientation@aiVehicleSpline@@QAEXXZ
    ARTS_IMPORT void SolveYPositionAndOrientation();

    // ?TotLength@aiVehicleSpline@@QAEMXZ
    ARTS_IMPORT f32 TotLength();

    // ?Type@aiVehicleSpline@@UAEHXZ | inline
    ARTS_IMPORT i32 Type() override;

    // ?Update@aiVehicleSpline@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@aiVehicleSpline@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    aiRailSet RailSet;
    aiVehicleSpline* Next[4];
    aiVehicleSpline* Prev[4];
    aiVehicleInstance* Inst;
    Matrix34* Matrix;
    DLPTemplate* Dlp;
    i16 Tries;
    i16 State;
    i16 LastState;
    i16 TotReactTicks;
    i16 CurReactTicks;
    i16 field_CA;
    f32 CurSpeed;
    f32 OOTurnDist;
    f32 TireRotation;
};

check_size(aiVehicleSpline, 0xD8);
