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

class UIMenu;

class mmToolTip final : public asNode
{
public:
    // ??_GmmToolTip@@UAEPAXI@Z
    // ??_EmmToolTip@@UAEPAXI@Z
    // ??1mmToolTip@@UAE@XZ
    ARTS_IMPORT ~mmToolTip() override;

    // ?SetText@mmToolTip@@QAEXPAULocString@@@Z
    ARTS_IMPORT void SetText(LocString* arg1);

    // ?Switch@mmToolTip@@QAEXH@Z
    ARTS_EXPORT void Switch(i32 arg1);

    // ?Update@mmToolTip@@UAEXXZ
    ARTS_EXPORT void Update() override;

    u8 gap20[0x14];
};

check_size(mmToolTip, 0x34);
