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

class mmMouseSteerBar final : public asNode
{
public:
    // ??0mmMouseSteerBar@@QAE@XZ
    ARTS_IMPORT mmMouseSteerBar();

    // ??_GmmMouseSteerBar@@UAEPAXI@Z
    // ??_EmmMouseSteerBar@@UAEPAXI@Z
    // ??1mmMouseSteerBar@@UAE@XZ
    ARTS_EXPORT ~mmMouseSteerBar() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmMouseSteerBar@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Cull@mmMouseSteerBar@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?Init@mmMouseSteerBar@@QAEXMMPAM@Z
    ARTS_IMPORT void Init(f32 arg1, f32 arg2, f32* arg3);

    // ?Update@mmMouseSteerBar@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x24];
};

check_size(mmMouseSteerBar, 0x44);
