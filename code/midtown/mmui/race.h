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

#include "racebase.h"

enum class mmGameMode : i32;

class RaceMenu final : public RaceMenuBase
{
public:
    // ??0RaceMenu@@QAE@H@Z
    ARTS_IMPORT RaceMenu(i32 arg1);

    // ??1RaceMenu@@UAE@XZ
    ARTS_EXPORT ~RaceMenu() override = default;

    // ?SetBlitzMask@RaceMenu@@QAEXH@Z
    ARTS_IMPORT void SetBlitzMask(i32 arg1);

    // ?SetCheckpointMask@RaceMenu@@QAEXH@Z
    ARTS_IMPORT void SetCheckpointMask(i32 arg1);

    // ?SetCircuitMask@RaceMenu@@QAEXH@Z
    ARTS_IMPORT void SetCircuitMask(i32 arg1);

    // ?SetProgressMask@RaceMenu@@QAEXH@Z
    ARTS_IMPORT void SetProgressMask(i32 arg1);

    u8 gapF90[0x4];
};

check_size(RaceMenu, 0xF94);
