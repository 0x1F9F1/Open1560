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

class mmHUD;

class mmCDPlayer final : public asNode
{
public:
    // ??0mmCDPlayer@@QAE@XZ
    ARTS_IMPORT mmCDPlayer();

    // ??1mmCDPlayer@@UAE@XZ | inline
    ARTS_IMPORT ~mmCDPlayer() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmCDPlayer@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Cull@mmCDPlayer@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?Init@mmCDPlayer@@QAEXPAVmmHUD@@@Z
    ARTS_IMPORT void Init(mmHUD* arg1);

    // ?NextTrack@mmCDPlayer@@QAEXXZ
    ARTS_IMPORT void NextTrack();

    // ?PlayStop@mmCDPlayer@@QAEXXZ
    ARTS_IMPORT void PlayStop();

    // ?PrevTrack@mmCDPlayer@@QAEXXZ
    ARTS_IMPORT void PrevTrack();

    // ?Reset@mmCDPlayer@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Toggle@mmCDPlayer@@QAEXXZ
    ARTS_IMPORT void Toggle();

    // ?Update@mmCDPlayer@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x12C];
};

check_size(mmCDPlayer, 0x14C);
