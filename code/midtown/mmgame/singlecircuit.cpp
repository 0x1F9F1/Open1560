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

define_dummy_symbol(mmgame_singlecircuit);

#include "singlecircuit.h"

#include "arts7/lamp.h"
#include "mmai/aiMap.h"
#include "mmaudio/manager.h"
#include "mmaudio/mmvoicecommentary.h"
#include "mmcity/cullcity.h"
#include "mmcityinfo/racedata.h"
#include "mmcityinfo/state.h"
#include "mmgame/popup.h"
#include "mminput/input.h"
#include "player.h"
#include "waypoints.h"

#ifndef ARTS_STANDALONE
i16 mmSingleCircuit::OppFinishPositions[MaxOpponents] {};
i32 mmSingleCircuit::OppNumCheck[MaxOpponents] {};
#endif

mmSingleCircuit::mmSingleCircuit() = default;

b32 mmSingleCircuit::Init()
{
    if (!mmGame::Init())
        return false;

    RaceData = arnew mmRaceData();
    RaceData->Load(arts_formatf<128>("%s\\mmcircuitdata", RaceDir));

    GameState = 0;

#ifndef ARTS_STANDALONE
    std::memset(&OldOppNumCheck, 0xAA, sizeof(OldOppNumCheck));
    std::memset(&OldOppFinishPositions, 0xAA, sizeof(OldOppFinishPositions));
#endif

    for (usize i = 0; i < MaxOpponents; ++i)
    {
        OppNumCheck[i] = 1;
        OppFinishPositions[i] = 0;
    }

    NumFinished = 0;

    AddChild(Player.get());

    if (HasAIMap)
        AddChild(&AIMAP);

    AddChild(pCullCity.get());
    AddChild(&Icons);

    if (Waypoints)
        AddChild(Waypoints);

    AddChild(&Player->HudMap);
    AddChild(&Player->Hud);

    LampCS->AddChild(Lamp.get());
    AddChild(LampCS.get());

    AddChild(&FooBar);
    AddChild(Popup.get());

    return true;
}

void mmSingleCircuit::Reset()
{
    AudMgr()->Reset();

    if (MMSTATE.HasMidtownCD)
        AudMgr()->StopCD();

    GameInput()->Reset();

    GameStateWait = 0.0f;
    GameState = 0;
    LapCounter = 1;
    BestLapTime = 0.0f;

    for (usize i = 0; i < MaxOpponents; ++i)
    {
        OppNumCheck[i] = 1;
        OppFinishPositions[i] = 0;
    }

    NumFinished = 0;
    DisableRacers();

    mmGame::Reset();

    Player->SetPreRaceCam();

    if (MMSTATE.HasMidtownCD)
        AudMgr()->PlayCDTrack(GetCDTrack(4), 1);

    if (VoiceCommentary)
        VoiceCommentary->PlayPreRace();

    Player->Hud.StopTimers();
}

void mmSingleCircuit::UpdateDebugKeyInput(i32 /*arg1*/)
{}

void mmSingleCircuit::UpdateGameInput(i32 /*arg1*/)
{}