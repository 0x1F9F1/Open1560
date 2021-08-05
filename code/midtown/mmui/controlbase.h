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
    mmui:controlbase

    0x4AB700 | public: __thiscall ControlBase::ControlBase(void) | ??0ControlBase@@QAE@XZ
    0x4AB710 | public: __thiscall ControlBase::~ControlBase(void) | ??1ControlBase@@QAE@XZ
    0x4AB720 | public: void __thiscall ControlBase::InitSensitivity(void) | ?InitSensitivity@ControlBase@@QAEXXZ
    0x4AB780 | public: void __thiscall ControlBase::SetSensitivity(void) | ?SetSensitivity@ControlBase@@QAEXXZ
*/

struct ControlBase
{
public:
    // ??0ControlBase@@QAE@XZ
    ARTS_IMPORT ControlBase();

    // ??1ControlBase@@QAE@XZ
    ARTS_IMPORT ~ControlBase() = default;

    // ?InitSensitivity@ControlBase@@QAEXXZ
    ARTS_IMPORT void InitSensitivity();

    // ?SetSensitivity@ControlBase@@QAEXXZ
    ARTS_IMPORT void SetSensitivity();

    u8 gap0[0x14];
};

check_size(ControlBase, 0x14);
