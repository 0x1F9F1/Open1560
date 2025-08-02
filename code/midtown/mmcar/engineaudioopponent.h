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

class EngineAudioOpponent final : public asNode
{
public:
    // ??0EngineAudioOpponent@@QAE@XZ
    ARTS_IMPORT EngineAudioOpponent();

    // ??_EEngineAudioOpponent@@UAEPAXI@Z
    // ??1EngineAudioOpponent@@UAE@XZ
    ARTS_IMPORT ~EngineAudioOpponent() override;

    // ?ClearName@EngineAudioOpponent@@QAEXXZ
    ARTS_IMPORT void ClearName();

    // ?Disable3DMode@EngineAudioOpponent@@QAEXXZ
    ARTS_IMPORT void Disable3DMode();

    // ?Enable3DMode@EngineAudioOpponent@@QAEXPAVVector3@@@Z
    ARTS_IMPORT void Enable3DMode(Vector3* arg1);

    // ?GetClass@EngineAudioOpponent@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@EngineAudioOpponent@@QAEXXZ
    ARTS_IMPORT void Init();

    // ?SetSoundPtr@EngineAudioOpponent@@QAEXPAVAudSound@@@Z | inline
    ARTS_IMPORT void SetSoundPtr(AudSound* arg1);

    // ?UpdateRPM@EngineAudioOpponent@@QAEXM@Z
    ARTS_IMPORT void UpdateRPM(f32 arg1);

    // ?DeclareFields@EngineAudioOpponent@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x34];
};

check_size(EngineAudioOpponent, 0x54);
