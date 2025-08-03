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

#include "data7/base.h"

class mmInfoBase : public Base
{
public:
    // ??0mmInfoBase@@QAE@XZ
    ARTS_EXPORT mmInfoBase() = default;

    // ??1mmInfoBase@@UAE@XZ | inline
    ARTS_EXPORT ~mmInfoBase() override = default;

    // ?Load@mmInfoBase@@QAEHPAD@Z
    b32 Load(const char* path);

    // ?Save@mmInfoBase@@QAEHPAD@Z
    b32 Save(const char* path);

    // ?SetIOPath@mmInfoBase@@QAEXPAD@Z
    void SetIOPath(const char* path);

    char FilePath[128] {};
    i32 Type {1234};

    VIRTUAL_META_DECLARE;
};

check_size(mmInfoBase, 0x88);
