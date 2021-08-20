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

define_dummy_symbol(mmcar_shard);

#include "shard.h"

#include "agi/rsys.h"
#include "agi/viewport.h"
#include "agiworld/meshset.h"
#include "arts7/sim.h"

void mmShard::Draw(i32 lod)
{
    if (ARTSPTR->IsDebugDrawEnabled())
        return;

    Matrix34 world;
    Viewport()->SetWorld(ToMatrix(world));

    agiMeshSet* mesh = GetMeshSet(lod, 0);
    mmShardManager* manager = mmShardManager::GetInstance(SubType);

    if (mesh && manager)
    {
        mesh->Textures[0][1] = manager->TexDef;

        // FIXME: Backfaces are still culled in HW mode, because the verts are not directly sent to the rasterizer
        auto cull_mode = agiCurState.SetCullMode(agiCullMode::None);

        mesh->Draw(MESH_DRAW_CLIP);

        agiCurState.SetCullMode(cull_mode);
    }
}

mmShardManager* mmShardManager::Instances[64];

mmShardManager::mmShardManager()
{
    ArAssert(NumInstances < ARTS_SSIZE32(Instances), "Too Many ShardManagers");
    Index = NumInstances++;
    Instances[Index] = this;
}

mmShardManager::~mmShardManager()
{
    // FIXME: Incorrectly assumes destruction order
    --NumInstances;
}

mmShardManager* mmShardManager::GetInstance(i32 index)
{
    if (index >= 0 && index < NumInstances)
        return Instances[index];

    return nullptr;
}
