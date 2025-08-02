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

class mmNetworkCarAudio final : public asNode
{
public:
    // ??0mmNetworkCarAudio@@QAE@XZ | inline
    ARTS_IMPORT mmNetworkCarAudio();

    // ??0mmNetworkCarAudio@@QAE@PAVmmCarSim@@@Z
    ARTS_IMPORT mmNetworkCarAudio(mmCarSim* arg1);

    // ??_EmmNetworkCarAudio@@UAEPAXI@Z
    // ??1mmNetworkCarAudio@@UAE@XZ
    ARTS_IMPORT ~mmNetworkCarAudio() override;

    // ?CalculateDistToPlayer2@mmNetworkCarAudio@@QAEXXZ
    ARTS_IMPORT void CalculateDistToPlayer2();

    // ?CalculateDoppler@mmNetworkCarAudio@@QAEXXZ
    ARTS_IMPORT void CalculateDoppler();

    // ?DeactivateAudio@mmNetworkCarAudio@@QAEXXZ
    ARTS_IMPORT void DeactivateAudio();

    // ?FluctuateFastSiren@mmNetworkCarAudio@@QAEXXZ
    ARTS_IMPORT void FluctuateFastSiren();

    // ?FluctuateSlowSiren@mmNetworkCarAudio@@QAEXXZ
    ARTS_IMPORT void FluctuateSlowSiren();

    // ?GetClass@mmNetworkCarAudio@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?Init@mmNetworkCarAudio@@QAEXPAVmmCarSim@@G@Z
    ARTS_IMPORT void Init(mmCarSim* arg1, u16 arg2);

    // ?LoadSucessful@mmNetworkCarAudio@@QAEXPAVmmCarSim@@@Z
    ARTS_IMPORT void LoadSucessful(mmCarSim* arg1);

    // ?RemoveFromManager@mmNetworkCarAudio@@QAEXXZ
    ARTS_IMPORT void RemoveFromManager();

    // ?Reset@mmNetworkCarAudio@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?StartSiren@mmNetworkCarAudio@@QAEXXZ
    ARTS_IMPORT void StartSiren();

    // ?StopSiren@mmNetworkCarAudio@@QAEXXZ
    ARTS_IMPORT void StopSiren();

    // ?Update@mmNetworkCarAudio@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateAudio@mmNetworkCarAudio@@QAEXXZ
    ARTS_IMPORT void UpdateAudio();

    // ?UpdateDoppler@mmNetworkCarAudio@@QAEXXZ
    ARTS_IMPORT void UpdateDoppler();

    // ?DeclareFields@mmNetworkCarAudio@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    // ?s_iPlayingFluctuator@mmNetworkCarAudio@@2FA
    ARTS_IMPORT static i16 s_iPlayingFluctuator;

    u8 gap20[0xB4];
};

check_size(mmNetworkCarAudio, 0xD4);
