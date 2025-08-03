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

#include "bank.h"

class asCullable : public Base
{
public:
    // ??0asCullable@@QAE@XZ | inline
    ARTS_EXPORT asCullable() = default;

    // ??1asCullable@@UAE@XZ | inline
    ARTS_EXPORT ~asCullable() override = 0;

    // ?Cull@asCullable@@UAEXXZ
    ARTS_EXPORT virtual void Cull();

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@asCullable@@QAEXPAVBank@@@Z
    void AddWidgets(Bank* bank);
#endif

    VIRTUAL_META_DECLARE;
};

check_size(asCullable, 0x4);

inline asCullable::~asCullable() = default;
