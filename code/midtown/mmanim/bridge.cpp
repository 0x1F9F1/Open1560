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

#include "mmai/aiMap.h"
#include "mmai/aiPath.h"
#include "mmaudio/sound.h"
#include "mmcity/cullcity.h"
#include "mmcityinfo/state.h"

i32 mmBridgeSet::Init(char* name, Stream* file)
{
    SetName(name);

    for (i32 entry_index = 0; entry_index < NumEntries; ++entry_index)
    {
        if (!ReadEntry(file, entry_index))
        {
            Errorf("Error reading bridge file");
            return 0;
        }
    }

    if (!MMSTATE.NetworkStatus)
    {
        i32 chain_id = AnimDofs[0].DofBanger->ChainId;

        asPortalCell* cell = nullptr;

        if (chain_id >= 0 && chain_id < CullCity()->RenderWeb.MaxCells)
            cell = CullCity()->RenderWeb.CellArray[chain_id];

        if (cell && cell->NumPtlPaths > 0)
        {
            PtlPath* base_path = cell->PtlPaths[0];

            if (base_path && base_path->Type == 1)
                if (AIMAP.Path(base_path->PathId))
                    AIMAP.Path(base_path->PathId)->HasBridge = 1;

            if (cell->NumPtlPaths > 1)
            {
                PtlPath* oncoming_path = cell->PtlPaths[1];

                if (oncoming_path && AIMAP.Path(oncoming_path->PathId))
                    AIMAP.Path(oncoming_path->PathId)->OncomingPath->HasBridge = 1;
            }
        }
    }

    return 1;
}

void mmBridgeSet::InitTrigger()
{
    if (Triggered)
    {
        State = 3;

        mmAnimTrigger anim;
        anim.Init(&TriggerPos, &TriggerDist2);
    }
}

void mmBridgeSet::SetSoundPtrs(AudSound* sound1, AudSound* sound2)
{
    if (Sound1 && Sound1->IsPlaying(0))
        Sound1->Stop();

    if (Sound2 && Sound2->IsPlaying(0))
        Sound2->Stop();

    Sound1 = sound1;
    Sound2 = sound2;
}

void mmBridgeSet::UnAssignSounds()
{
    SetSoundPtrs(0, 0);
    MgrIndex = -1;
}
