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

define_dummy_symbol(mmgame_gamesingle);

#include "gamesingle.h"

#include "arts7/lamp.h"
#include "mmai/aiMap.h"
#include "mmai/aiaudiomanager.h"
#include "mmaudio/manager.h"
#include "mmaudio/mmvoicecommentary.h"
#include "mmcity/cullcity.h"
#include "mmcityinfo/racedata.h"
#include "mmcityinfo/state.h"
#include "mminput/input.h"
#include "player.h"
#include "popup.h"
#include "waypoints.h"

#ifndef ARTS_STANDALONE
i32 mmGameSingle::OppNumCheck[MaxOpponents] {};
i16 mmGameSingle::OppFinishPositions[MaxOpponents] {};
#endif

b32 mmGameSingle::Init()
{
    if (!mmGame::Init())
        return false;

    RaceData = arnew mmRaceData();
    RaceData->Load(arts_formatf<128>("%s\\mmracedata", RaceDir));

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

void mmGameSingle::Reset()
{
    AudMgr()->Reset();
    InWater = false;

    if (MMSTATE.HasMidtownCD)
        AudMgr()->StopCD();

    if (AiAudMgr())
        AiAudMgr()->LoadCopVoice();

    GameInput()->Reset();

    GameStateWait = 0.0f;
    GameState = 0;

    for (usize i = 0; i < MaxOpponents; ++i)
    {
        OppNumCheck[i] = 1;
        OppFinishPositions[i] = 0;
    }

    NumFinished = 0;

    if (MMSTATE.GameMode == mmGameMode::Checkpoint)
        DisableRacers();

    mmGame::Reset();

    if (MMSTATE.GameMode == mmGameMode::Cruise)
    {
        if (VoiceCommentary)
            VoiceCommentary->PlayRoam();
    }
    else
    {
        Player->SetPreRaceCam();

        if (MMSTATE.HasMidtownCD)
            AudMgr()->PlayCDTrack(GetCDTrack(4), 1);

        if (VoiceCommentary)
            VoiceCommentary->PlayPreRace();

        Player->Hud.StopTimers();
    }
}

void mmGameSingle::UpdateDebugKeyInput(i32 /*arg1*/)
{}

hook_func(INIT_main, [] {
    const i32 OppNumCheckAddr =
        mem::pointer(&mmGameSingle::OppNumCheck).sub(offsetof(mmGameSingle, OldOppNumCheck)).as<i32>();

    for (mem::pointer addr : {
             0x417D24,
             0x417F2C,
             0x418050,
         })
    {
        ArAssert(addr.as<u8&>() == 0x8D, "Invalid Opcode");

        u8 modrm = addr.add(1).as<u8&>();
        u8 mod = (modrm >> 6);
        u8 reg = (modrm >> 3) & 0x7;
        // u8 rm = (modrm >> 0) & 0x7;

        ArAssert(mod == 2, "Invalid Mod");

        i32 offset = addr.add(2).as<i32&>();

        create_packed_patch<u8, i32, u8>(
            "mmGameSingle::OppNumCheck", "Support More Icons", addr, 0xB8 + reg, OppNumCheckAddr + offset, 0x90);
    }

    const i32 OppFinishPositionsAddr =
        mem::pointer(&mmGameSingle::OppFinishPositions).sub(offsetof(mmGameSingle, OldOppFinishPositions)).as<i32>();

    for (mem::pointer addr : {
             0x417D1E,
             0x417F32,
             0x418062,
         })
    {
        ArAssert(addr.as<u8&>() == 0x8D, "Invalid Opcode");

        u8 modrm = addr.add(1).as<u8&>();
        u8 mod = (modrm >> 6);
        u8 reg = (modrm >> 3) & 0x7;
        // u8 rm = (modrm >> 0) & 0x7;

        ArAssert(mod == 2, "Invalid Mod");

        i32 offset = addr.add(2).as<i32&>();

        create_packed_patch<u8, i32, u8>("mmGameSingle::OppFinishPositions", "Support More Icons", addr, 0xB8 + reg,
            OppFinishPositionsAddr + offset, 0x90);
    }
});