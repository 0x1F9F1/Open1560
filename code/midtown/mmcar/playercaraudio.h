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

class mmCarSim;

class mmPlayerCarAudio final : public asNode
{
public:
    // ??0mmPlayerCarAudio@@QAE@XZ | inline
    ARTS_IMPORT mmPlayerCarAudio();

    // ??0mmPlayerCarAudio@@QAE@PAVmmCarSim@@@Z
    ARTS_IMPORT mmPlayerCarAudio(mmCarSim* arg1);

    // ??1mmPlayerCarAudio@@UAE@XZ
    ARTS_IMPORT ~mmPlayerCarAudio() override;

    // ?EchoOff@mmPlayerCarAudio@@QAEXXZ
    ARTS_IMPORT void EchoOff();

    // ?EchoOn@mmPlayerCarAudio@@QAEXM@Z
    ARTS_IMPORT void EchoOn(f32 arg1);

    // ?FluctuateFastSiren@mmPlayerCarAudio@@QAEXXZ
    ARTS_IMPORT void FluctuateFastSiren();

    // ?FluctuateSlowSiren@mmPlayerCarAudio@@QAEXXZ
    ARTS_IMPORT void FluctuateSlowSiren();

    // ?GetClass@mmPlayerCarAudio@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmPlayerCarAudio@@QAEXPAVmmCarSim@@@Z
    ARTS_IMPORT void Init(mmCarSim* arg1);

    // ?LoadSucessful@mmPlayerCarAudio@@QAEXXZ
    ARTS_IMPORT void LoadSucessful();

    // ?PlayHorn@mmPlayerCarAudio@@QAEXXZ
    ARTS_IMPORT void PlayHorn();

    // ?Reset@mmPlayerCarAudio@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?StartSiren@mmPlayerCarAudio@@QAEXXZ
    ARTS_IMPORT void StartSiren();

    // ?StopSiren@mmPlayerCarAudio@@QAEXXZ
    ARTS_IMPORT void StopSiren();

    // ?Update@mmPlayerCarAudio@@QAEXHMMF@Z
    ARTS_IMPORT void Update(i32 arg1, f32 arg2, f32 arg3, i16 arg4);

    // ?DeclareFields@mmPlayerCarAudio@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0xE0];
};

check_size(mmPlayerCarAudio, 0x100);
