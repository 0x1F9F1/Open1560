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

define_dummy_symbol(mmcar_carsim);

#include "carsim.h"

b32 EnableSmoke = true;
b32 ForceSmoke = false;

void mmCarSim::SetGlobalTuning(f32 /*arg1*/, f32 /*arg2*/)
{}

hook_func(INIT_main, [] {
    create_packed_patch<u8, u8, b32*, u8, u8, u8>(
        "mmCarSim::UpdateDamage", "Use EnableSmoke", 0x46E3F4, 0x8B, 0x0D, &EnableSmoke, 0x85, 0xC9, 0x74);
    create_packed_patch<u8, b32*, u8, u8, u8, u8>(
        "mmWheel::Update", "Use EnableSmoke", 0x47EFC9, 0xA1, &EnableSmoke, 0x85, 0xC0, 0x0F, 0x84);
});