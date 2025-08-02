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

#include "pu_menu.h"

class mmTextNode;

class PUKey final : public PUMenuBase
{
public:
    // ??0PUKey@@QAE@HMMMM@Z
    ARTS_EXPORT PUKey(i32 menu_id, f32 x, f32 y, f32 width, f32 height);

    // ??_GPUKey@@UAEPAXI@Z
    // ??_EPUKey@@UAEPAXI@Z
    // ??1PUKey@@UAE@XZ
    ARTS_EXPORT ~PUKey() override;

private:
    // ?PreSetup@PUKey@@EAEXXZ
    ARTS_EXPORT void PreSetup() override;

    // ?PostSetup@PUKey@@EAEXXZ
    ARTS_EXPORT void PostSetup() override;

    Ptr<mmTextNode> text_node_;
    i32 key_count_ {};
    f32 title_pos_ {};
};

check_size(PUKey, 0xCC);
