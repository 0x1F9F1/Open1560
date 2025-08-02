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

class AudSound;
class mmCarSim;
class mmOpponentImpactAudio;

class mmOpponentCarAudio : public asNode
{
public:
    // ??0mmOpponentCarAudio@@QAE@XZ | inline
    ARTS_IMPORT mmOpponentCarAudio();

    // ??0mmOpponentCarAudio@@QAE@PAVmmCarSim@@@Z
    ARTS_IMPORT mmOpponentCarAudio(mmCarSim* arg1);

    // ??_EmmOpponentCarAudio@@UAEPAXI@Z
    // ??1mmOpponentCarAudio@@UAE@XZ
    ARTS_IMPORT ~mmOpponentCarAudio() override;

    // ?AssignSounds@mmOpponentCarAudio@@QAEXPAVAudSound@@0PAVmmOpponentImpactAudio@@0@Z
    ARTS_IMPORT void AssignSounds(AudSound* arg1, AudSound* arg2, mmOpponentImpactAudio* arg3, AudSound* arg4);

    // ?CalculateDistToPlayer2@mmOpponentCarAudio@@QAEXXZ
    ARTS_IMPORT void CalculateDistToPlayer2();

    // ?CalculateDoppler@mmOpponentCarAudio@@QAEXM@Z
    ARTS_IMPORT void CalculateDoppler(f32 arg1);

    // ?CalculatePan@mmOpponentCarAudio@@QAEXXZ
    ARTS_IMPORT void CalculatePan();

    // ?GetClass@mmOpponentCarAudio@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmOpponentCarAudio@@QAEXPAVmmCarSim@@@Z
    ARTS_IMPORT void Init(mmCarSim* arg1);

    // ?LoadSucessful@mmOpponentCarAudio@@QAEXPAVmmCarSim@@@Z
    ARTS_IMPORT void LoadSucessful(mmCarSim* arg1);

    // ?Reset@mmOpponentCarAudio@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetMinAmpSpeed@mmOpponentCarAudio@@QAEXM@Z
    ARTS_IMPORT void SetMinAmpSpeed(f32 arg1);

    // ?UnAssignSounds@mmOpponentCarAudio@@QAEXXZ
    ARTS_IMPORT void UnAssignSounds();

    // ?Update@mmOpponentCarAudio@@QAEXHMM@Z
    ARTS_IMPORT void Update(i32 arg1, f32 arg2, f32 arg3);

    // ?UpdateDoppler@mmOpponentCarAudio@@QAEXXZ
    ARTS_IMPORT void UpdateDoppler();

    // ?UpdateDoppler@mmOpponentCarAudio@@QAEXM@Z
    ARTS_IMPORT void UpdateDoppler(f32 arg1);

    // ?DeclareFields@mmOpponentCarAudio@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0xC0];
};

check_size(mmOpponentCarAudio, 0xE0);
