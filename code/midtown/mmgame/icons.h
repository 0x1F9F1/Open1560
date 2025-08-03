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

struct OppIconInfo;

class mmIcons final : public asNode
{
public:
    // ??0mmIcons@@QAE@XZ
    ARTS_IMPORT mmIcons();

    // ??1mmIcons@@UAE@XZ
    ARTS_IMPORT ~mmIcons() override;

    // ?Cull@mmIcons@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?Init@mmIcons@@QAEXPAVMatrix34@@MM@Z
    ARTS_IMPORT void Init(Matrix34* arg1, f32 arg2, f32 arg3);

    // ?RegisterOpponents@mmIcons@@QAEXPAUOppIconInfo@@HPAX@Z
    ARTS_IMPORT void RegisterOpponents(OppIconInfo* arg1, i32 arg2, void* arg3);

    // ?Update@mmIcons@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x3C];
};

check_size(mmIcons, 0x5C);
