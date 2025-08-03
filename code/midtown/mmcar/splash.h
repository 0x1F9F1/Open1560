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

class asInertialCS;

class mmSplash final : public asNode
{
public:
    // ??0mmSplash@@QAE@XZ
    ARTS_IMPORT mmSplash();

    // ??1mmSplash@@UAE@XZ | inline
    ARTS_EXPORT ~mmSplash() override = default;

    // ?Activate@mmSplash@@QAEXM@Z
    ARTS_IMPORT void Activate(f32 arg1);

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmSplash@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Init@mmSplash@@QAEXPAVasInertialCS@@VVector3@@1@Z
    ARTS_IMPORT void Init(asInertialCS* arg1, Vector3 arg2, Vector3 arg3);

    // ?Reset@mmSplash@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@mmSplash@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x310];
};

check_size(mmSplash, 0x330);
