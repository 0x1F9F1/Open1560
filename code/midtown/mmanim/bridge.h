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

#include "arts7/node.h"

#include "AnimDOF.h"
#include "AnimTrigger.h"

class AudSound;
class mmInstance;

class mmBridgeSet final : public asNode
{
public:
    // ??0mmBridgeSet@@QAE@XZ
    ARTS_IMPORT mmBridgeSet();

    // ??1mmBridgeSet@@UAE@XZ
    ARTS_IMPORT ~mmBridgeSet() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmBridgeSet@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Cull@mmBridgeSet@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?GetClass@mmBridgeSet@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmBridgeSet@@QAEHPADPAVStream@@@Z
    ARTS_EXPORT b32 Init(char* name, Stream* file);

    // ?InitTrigger@mmBridgeSet@@QAEXXZ
    ARTS_EXPORT void InitTrigger();

    // ?ReadEntry@mmBridgeSet@@QAEHPAVStream@@H@Z
    ARTS_IMPORT i32 ReadEntry(Stream* arg1, i32 arg2);

    // ?Reset@mmBridgeSet@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetSoundPtrs@mmBridgeSet@@QAEXPAVAudSound@@0@Z
    ARTS_EXPORT void SetSoundPtrs(AudSound* sound1, AudSound* sound2);

    // ?UnAssignSounds@mmBridgeSet@@QAEXXZ
    ARTS_EXPORT void UnAssignSounds();

    // ?Update@mmBridgeSet@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateAudio@mmBridgeSet@@QAEXXZ
    ARTS_IMPORT void UpdateAudio();

    // ?DeclareFields@mmBridgeSet@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // ?CalculateAudioPanning@mmBridgeSet@@AAEXXZ
    ARTS_IMPORT void CalculateAudioPanning();

    // ?CalculateDistToPlayer2@mmBridgeSet@@AAEXXZ
    ARTS_IMPORT void CalculateDistToPlayer2();

    // ?CalculateDoppler@mmBridgeSet@@AAEMM@Z
    ARTS_IMPORT f32 CalculateDoppler(f32 arg1);

    // ?RampDownBridgeVolume@mmBridgeSet@@AAEXXZ
    ARTS_IMPORT void RampDownBridgeVolume();

    // ?s_fAudioAttenuationMult@mmBridgeSet@@0MA
    ARTS_IMPORT static f32 s_fAudioAttenuationMult;

    // ?s_fAudioMaxDistance@mmBridgeSet@@0MA
    ARTS_IMPORT static f32 s_fAudioMaxDistance;

    // ?s_fAudioMinDistance@mmBridgeSet@@0MA
    ARTS_IMPORT static f32 s_fAudioMinDistance;

    // ?s_fAudioVolume@mmBridgeSet@@0MA
    ARTS_IMPORT static f32 s_fAudioVolume;

    // ?s_fCloserMinDistMult@mmBridgeSet@@0MA
    ARTS_IMPORT static f32 s_fCloserMinDistMult;

public:
    mmAnimTrigger Trigger;
    i32 Triggered;
    f32 TriggerTimeout;
    Vector3 TriggerPos;
    f32 TriggerDist2;
    i32 NumEntries;
    mmAnimDOF AnimDofs[6];
    i32 Switch;
    i32 State;
    i32 InitialPos;
    f32 DownInterval;
    f32 UpInterval;
    i32 field_404;
    i32 field_408;
    f32 Pan;
    f32 Volume;
    f32 field_414;
    f32 MaxAudioDistSqr;
    f32 field_41C;
    f32 field_420;
    f32 field_424;
    f32 field_428;
    AudSound* Sound1;
    AudSound* Sound2;
    i16 MgrIndex;
    u8 Flags;
};

check_size(mmBridgeSet, 0x438);

class mmBridgeMgr final : public asNode
{
public:
    // ??0mmBridgeMgr@@QAE@XZ
    ARTS_IMPORT mmBridgeMgr();

    // ??1mmBridgeMgr@@UAE@XZ
    ARTS_IMPORT ~mmBridgeMgr() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmBridgeMgr@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Cull@mmBridgeMgr@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?GetClass@mmBridgeMgr@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmBridgeMgr@@QAEXPADPAVmmInstance@@PAPAV2@H@Z
    ARTS_IMPORT void Init(char* arg1, mmInstance* arg2, mmInstance** arg3, i32 arg4);

    // ?Save@mmBridgeMgr@@UAEXXZ
    ARTS_IMPORT void Save() override;

    // ?ToggleDrawLabels@mmBridgeMgr@@QAEXXZ
    ARTS_IMPORT void ToggleDrawLabels();

    // ?DeclareFields@mmBridgeMgr@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    i32 DrawBridges;
    i32 NumBridges;
    mmBridgeSet Bridges[9];
    f32 BridgeDelta;
    f32 BridgeOffGoal;
    f32 BridgeOnGoal;
    f32 BridgeOnDelay;
    f32 BridgeOffDelay;
    f32 GateDelta;
    f32 GateOffGoal;
    f32 GateOnGoal;
    f32 GateOnDelay;
    f32 GateOffDelay;
    mmInstance* Inst;
    i32 field_264C[9];
    i32 NumTrackedObjects;

protected:
    friend mmBridgeMgr* BridgeMgr();

    // ?Instance@mmBridgeMgr@@1PAV1@A
    ARTS_IMPORT static mmBridgeMgr* Instance;
};

check_size(mmBridgeMgr, 0x2674);

inline mmBridgeMgr* BridgeMgr()
{
    return mmBridgeMgr::Instance;
}
