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
    // 0x4AB700 | ??0ControlBase@@QAE@XZ
    ControlBase();

    // 0x4AB710 | ??1ControlBase@@QAE@XZ
    ~ControlBase();

    // 0x4AB720 | ?InitSensitivity@ControlBase@@QAEXXZ
    void InitSensitivity();

    // 0x4AB780 | ?SetSensitivity@ControlBase@@QAEXXZ
    void SetSensitivity();
};

check_size(ControlBase, 0x0);
