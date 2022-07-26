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

define_dummy_symbol(mmai_aiPedestrian);

#include "aiPedestrian.h"

#ifdef ARTS_DEV_BUILD
void aiPedestrianInstance::AddWidgets(Bank* /*arg1*/)
{}
#endif

hook_func(INIT_main, [] {
    create_patch("aiPedestrian::DetectBangerCollision", "Banger Check", 0x44B6F2,
        "\xF6\x46\x05\x02\x74\x20\xE8\x63\xED\x07\x00\x85\xC0\x0F\x84\xD6\x00\x00\x00", 0x13);
});