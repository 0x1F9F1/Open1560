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

define_dummy_symbol(mmanim_bridge);

#include "bridge.h"

#include "arts7/node.h"

i32 mmBridgeSet::Init(char* name, Stream* file)
{
    SetName(name);

    for (i32 entry_index = 0; entry_index < NumEntries; ++entry_index)
    {
        if (!ReadEntry(file, entry_index))
        {
            Errorf("Error reading bridge file");
            return false;
        }
    }
}
