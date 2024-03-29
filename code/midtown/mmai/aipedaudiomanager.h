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
    mmai:aipedaudiomanager

    0x446C80 | public: __thiscall aiPedAudioManager::aiPedAudioManager(void) | ??0aiPedAudioManager@@QAE@XZ
    0x446F80 | public: virtual __thiscall aiPedAudioManager::~aiPedAudioManager(void) | ??1aiPedAudioManager@@UAE@XZ
    0x447030 | public: short __thiscall aiPedAudioManager::Add(class aiPedestrian *) | ?Add@aiPedAudioManager@@QAEFPAVaiPedestrian@@@Z
    0x4470E0 | public: void __thiscall aiPedAudioManager::Remove(class aiPedestrian *,short) | ?Remove@aiPedAudioManager@@QAEXPAVaiPedestrian@@F@Z
    0x447150 | public: short __thiscall aiPedAudioManager::FindGreatestDistance(class aiPedestrian *) | ?FindGreatestDistance@aiPedAudioManager@@QAEFPAVaiPedestrian@@@Z
    0x4471E0 | public: short __thiscall aiPedAudioManager::FindUnusedSlot(void) | ?FindUnusedSlot@aiPedAudioManager@@QAEFXZ
    0x447220 | public: virtual void __thiscall aiPedAudioManager::Update(void) | ?Update@aiPedAudioManager@@UAEXXZ
    0x447280 | public: void __thiscall aiPedAudioManager::AssignSounds(short) | ?AssignSounds@aiPedAudioManager@@QAEXF@Z
    0x4472A0 | public: void __thiscall aiPedAudioManager::RandomizeSeconds(float,float) | ?RandomizeSeconds@aiPedAudioManager@@QAEXMM@Z
    0x4472B0 | public: virtual void * __thiscall aiPedAudioManager::`vector deleting destructor'(unsigned int) | ??_EaiPedAudioManager@@UAEPAXI@Z
    0x4472B0 | public: virtual void * __thiscall aiPedAudioManager::`scalar deleting destructor'(unsigned int) | ??_GaiPedAudioManager@@UAEPAXI@Z
    0x61B568 | const aiPedAudioManager::`vftable' | ??_7aiPedAudioManager@@6B@
    0x6A79AC | class aiPedAudioManager * AIPEDAUDMGRPTR | ?AIPEDAUDMGRPTR@@3PAVaiPedAudioManager@@A
*/

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
