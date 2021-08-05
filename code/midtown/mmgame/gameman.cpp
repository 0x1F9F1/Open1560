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

define_dummy_symbol(mmgame_gameman);

#include "gameman.h"

#include "agi/texdef.h"
#include "agiworld/meshload.h"
#include "arts7/cullmgr.h"
#include "data7/cache.h"
#include "mmdyna/bndtmpl2.h"

// ?DoScan@@YAXPAX@Z
ARTS_IMPORT /*static*/ void DoScan(void* arg1);

// ?randcall@@YAXXZ
ARTS_IMPORT /*static*/ void randcall();

void ShowGameManagerStats()
{
    // TODO: Make these atomic
    Statsf("Meshes: %d paged, %d bytes", MeshesPaged, MeshBytesPaged);
    Statsf("Bounds: %d paged, %d bytes", BoundsPaged, BoundBytesPaged);
    Statsf("Textures: %d paged, %d bytes", TexsPaged, TexBytesPaged);

    u32 objects = 0;
    u32 bytes = 0;
    u32 waste = 0;

    CACHE.GetStatus(objects, bytes, waste);
    Statsf("GEOM: Handles: %u%%; memory: %u%%; wasted: %u%%; evict: %u/%u", objects, bytes, waste,
        CACHE.GetEvictedObjects(), CACHE.GetEvictedBytes());

    TEXCACHE.GetStatus(objects, bytes, waste);
    Statsf("TEX: Handles: %u%%; memory: %u%%; wasted: %u%%; evict: %u/%u", objects, bytes, waste,
        TEXCACHE.GetEvictedObjects(), TEXCACHE.GetEvictedBytes());

    TEXCACHE.ResetEvictionCounter();
    CACHE.ResetEvictionCounter();

    MeshesPaged = 0;
    MeshBytesPaged = 0;
    BoundsPaged = 0;
    BoundBytesPaged = 0;
    TexsPaged = 0;
    TexBytesPaged = 0;
}

run_once([] { auto_hook(0x404280, ShowGameManagerStats); });
