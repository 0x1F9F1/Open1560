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

/*
    mmui:pu_key

    0x4A93C0 | public: __thiscall PUKey::PUKey(int,float,float,float,float) | ??0PUKey@@QAE@HMMMM@Z
    0x4A9460 | public: virtual __thiscall PUKey::~PUKey(void) | ??1PUKey@@UAE@XZ
    0x4A9470 | private: virtual void __thiscall PUKey::PreSetup(void) | ?PreSetup@PUKey@@EAEXXZ
    0x4A9710 | private: virtual void __thiscall PUKey::PostSetup(void) | ?PostSetup@PUKey@@EAEXXZ
    0x4A9750 | public: virtual void * __thiscall PUKey::`vector deleting destructor'(unsigned int) | ??_EPUKey@@UAEPAXI@Z
    0x4A9750 | public: virtual void * __thiscall PUKey::`scalar deleting destructor'(unsigned int) | ??_GPUKey@@UAEPAXI@Z
    0x61DE58 | const PUKey::`vftable' | ??_7PUKey@@6B@
*/

#include "pu_menu.h"

class mmTextNode;

class PUKey final : public PUMenuBase
{
public:
    // ??0PUKey@@QAE@HMMMM@Z
    ARTS_IMPORT PUKey(i32 menu_id, f32 x, f32 y, f32 width, f32 height);

    // ??_GPUKey@@UAEPAXI@Z
    // ??_EPUKey@@UAEPAXI@Z
    // ??1PUKey@@UAE@XZ
    ARTS_IMPORT ~PUKey() override = default;

private:
    // ?PostSetup@PUKey@@EAEXXZ
    ARTS_IMPORT void PostSetup() override;

    // ?PreSetup@PUKey@@EAEXXZ
    ARTS_IMPORT void PreSetup() override;

    Ptr<mmTextNode> text_node_;
    i32 key_count_ {0};
    f32 title_pos_ {0.0f};
};

check_size(PUKey, 0xCC);
