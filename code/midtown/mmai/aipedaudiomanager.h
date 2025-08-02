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

class aiPedestrian;

class aiPedAudioManager final : public asNode
{
public:
    // ??0aiPedAudioManager@@QAE@XZ
    ARTS_IMPORT aiPedAudioManager();

    // ??_GaiPedAudioManager@@UAEPAXI@Z
    // ??_EaiPedAudioManager@@UAEPAXI@Z
    // ??1aiPedAudioManager@@UAE@XZ
    ARTS_IMPORT ~aiPedAudioManager() override;

    // ?Add@aiPedAudioManager@@QAEFPAVaiPedestrian@@@Z
    ARTS_IMPORT i16 Add(aiPedestrian* arg1);

    // ?AssignSounds@aiPedAudioManager@@QAEXF@Z
    ARTS_IMPORT void AssignSounds(i16 arg1);

    // ?FindGreatestDistance@aiPedAudioManager@@QAEFPAVaiPedestrian@@@Z
    ARTS_IMPORT i16 FindGreatestDistance(aiPedestrian* arg1);

    // ?FindUnusedSlot@aiPedAudioManager@@QAEFXZ
    ARTS_IMPORT i16 FindUnusedSlot();

    // ?RandomizeSeconds@aiPedAudioManager@@QAEXMM@Z | unused
    ARTS_EXPORT void RandomizeSeconds(f32 arg1, f32 arg2);

    // ?Remove@aiPedAudioManager@@QAEXPAVaiPedestrian@@F@Z
    ARTS_IMPORT void Remove(aiPedestrian* arg1, i16 arg2);

    // ?Update@aiPedAudioManager@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x100];
};

check_size(aiPedAudioManager, 0x120);

// ?AIPEDAUDMGRPTR@@3PAVaiPedAudioManager@@A
ARTS_IMPORT extern aiPedAudioManager* AIPEDAUDMGRPTR;
