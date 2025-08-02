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

#include "mmwidget/menu.h"

class VehShowcase final : public UIMenu
{
public:
    // ??0VehShowcase@@QAE@H@Z
    ARTS_IMPORT VehShowcase(i32 arg1);

    // ??_GVehShowcase@@UAEPAXI@Z
    // ??_EVehShowcase@@UAEPAXI@Z
    // ??1VehShowcase@@UAE@XZ
    ARTS_IMPORT ~VehShowcase() override;

    // ?PostSetup@VehShowcase@@UAEXXZ
    ARTS_EXPORT void PostSetup() override;

    // ?PreSetup@VehShowcase@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    u8 gap90[0x8];
};

check_size(VehShowcase, 0x98);
