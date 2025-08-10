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

#include "game.h"
#include "player.h"

#include "agi/bitmap.h"
#include "agi/pipeline.h"
#include "agi/texdef.h"
#include "agiworld/meshload.h"
#include "arts7/cullmgr.h"
#include "arts7/sim.h"
#include "data7/cache.h"
#include "memory/stack.h"
#include "mmcityinfo/state.h"
#include "mmdyna/bndtmpl2.h"
#include "mmeffects/card2d.h"
#include "mminput/input.h"
#include "vector7/randmath.h"

// ?randcall@@YAXXZ
ARTS_IMPORT /*static*/ void randcall();

// ?ResetFadeCard@@3PAVCard2D@@A
ARTS_EXPORT Card2D* ResetFadeCard = nullptr;

struct mmReplayFrame
{
    f32 UpdateDelta;
    f32 TotalElapsed;
    i8 Steering;
    u8 Brakes;
    u8 Throttle;
};
check_size(mmReplayFrame, 0xC);

static constexpr usize MaxReplayFrames = 18000;

// ?ReplayData@@3PAUmmReplayFrame@@A
ARTS_EXPORT mmReplayFrame ReplayData[MaxReplayFrames];

i32 ScreenClearCount = 0;

// ?ShowGameManagerStats@@YAXXZ
ARTS_EXPORT void ShowGameManagerStats()
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

void mmGameManager::BeDone()
{
    MMSTATE.GameState = mmGameState::Menus;
}

void mmGameManager::Cull()
{
    auto bitmap = ReplayBitmap;

    Pipe()->CopyBitmap((Pipe()->GetWidth() - bitmap->GetWidth()) / 2, (Pipe()->GetHeight() - bitmap->GetHeight()) / 4,
        bitmap, 0, 0, bitmap->GetWidth(), bitmap->GetHeight());
}

void mmGameManager::Reset()
{
    // Actual reset is handled in Update()
    NeedsReset = true;
    InReplay = false;
}

void mmGameManager::Update()
{
    ScreenClearCount = 3;

    if (NeedsReset)
    {
        gRandSeed = 1;
        Frame = 0;
        asNode::Reset();
        NeedsReset = false;

        Current->Player->Camera.FadeIn(1.0f, 0);
    }

    DebugLog('dees', &gRandSeed, sizeof(gRandSeed));

    if (InReplay)
    {
        Sim()->SetUpdateDelta(ReplayData[Frame].UpdateDelta);
        Sim()->SetElapsed(ReplayData[Frame].TotalElapsed);

        asNode::Update();

        if (++Frame == PendingFrames)
            InReplay = false;

        if (ReplayBitmap && (Frame & 31) < 16)
            CullMgr()->DeclareBitmap(this, ReplayBitmap);
    }
    else
    {
        ReplayData[Frame].UpdateDelta = Sim()->GetUpdateDelta();
        ReplayData[Frame].TotalElapsed = Sim()->GetElapsed();
        ReplayData[Frame].Steering = static_cast<i8>(GameInput()->GetSteering() * 127.0f);
        ReplayData[Frame].Throttle = static_cast<u8>(GameInput()->GetThrottle() * 255.0f);
        ReplayData[Frame].Brakes = static_cast<u8>(GameInput()->GetBrakes() * 255.0f);

        asNode::Update();

        if (Frame < MaxReplayFrames - 1)
            ++Frame;
    }
}
