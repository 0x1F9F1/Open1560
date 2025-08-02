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

b32 mmBridgeSet::Init(char* name, Stream* file)
{
    SetName(name);

    for (i32 i = 0; i < NumEntries; ++i)
    {
        if (!ReadEntry(file, i))
        {
            Errorf("Error reading bridge file");
            return false;
        }
    }

    if (!MMSTATE.NetworkStatus)
    {
        if (auto cell = CullCity()->RenderWeb.GetCell(AnimDofs[0].DofBanger->ChainId))
        {
            for (i32 i = 0; i < cell->NumPtlPaths; ++i)
            {
                if (auto ptl = cell->PtlPaths[i]; ptl && ptl->Type == 1)
                {
                    if (auto path = AIMAP.Path(ptl->PathId))
                    {
                        path->HasBridge = true;

                        if (auto oncoming = path->OncomingPath)
                        {
                            oncoming->HasBridge = true;
                        }
                    }
                }
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
