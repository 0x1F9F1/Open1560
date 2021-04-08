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

define_dummy_symbol(agiworld_meshset);

#include "meshset.h"

#include "agi/texdef.h"

agiMeshSet::agiMeshSet() = default;

agiMeshSet::~agiMeshSet()
{
    EndGfx();

    if (Textures)
    {
        for (i32 i = 0; i < VariationCount; ++i)
        {
            for (i32 j = 1; j < TextureCount; ++j)
            {
                if (agiTexDef* texture = Textures[i][j])
                    texture->Release();
            }

            delete[] Textures[i];
        }

        delete[] Textures;
    }

    // TODO: Should this free the other fields?
}