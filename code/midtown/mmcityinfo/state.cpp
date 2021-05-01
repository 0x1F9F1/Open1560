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

define_dummy_symbol(mmcityinfo_state);

#include "state.h"

#include "data7/args.h"
#include "midtown.h"
#include "mmaudio/manager.h"

void mmStatePack::SetDefaults()
{
    CurrentCar = 2; // Hopefully vpbug
    InputType = mmInputType::Mouse;
    NetworkStatus = 0;
    NumPlayers = 0;
    CopBehaviorFlag = 0;
    NoUI = false;
    Shutdown = false;
    GameMode = mmGameMode::Cruise;
    EventId = 0;
    RaceDifficulty = 0.0f;
    AutoTransmission = true;
    AmbientDensity = 0.33f;
    PedDensity = 1.0f;
    CopDensity = 1.0f;
    MaxOpponents = 7.0f;
    PhysicsRealism = 0.75f;
    EnableFF = true;
    UnlockAllRaces = false;
    Weather = 0;
    TimeOfDay = 1;
    arts_strcpy(CarName, "vpbug");
    CurrentColor = 0;
    arts_strcpy(NetName, "loaf");
    TimeLimit = 0.0f;
    GameState = 0;
    DisableDamage = false;
    DisableAI = false;
    SuperCops = false;
    AmbientCount = 100;
    NumLaps = 0;
    Difficulty = mmSkillLevel::Amateur;
    WaveVolume = 1.0f;
    AudBalance = 0.0f;
    CDVolume = 0.5f;
    AudFlags = AudManager::GetHiSampleSizeMask() | AudManager::GetHiResMask() | AudManager::GetStereoOnMask() |
        AudManager::GetCommentaryOnMask() | AudManager::GetCDMusicOnMask() | AudManager::GetSoundFXOnMask();
    AudNumChannels = 32;
    arts_strcpy(AudDeviceName, "Primary Sound Driver");
    HasMidtownCD = false;
    FreeForAll = false;
    CREnableTimer = false;
    IsRobber = false;
    CRTimeLimit = false;
    CRTimeLimit2 = false;
    CRGoldMass = {};
    arts_strcpy(IntroText, "Loading Open1560");
    CameraIndex = 0;
    HudmapMode = 0;
    WideFov = false;
    DashView = false;
    EnableMirror = true;
    ExternalView = false;
    XcamView = false;
    ShowPositions = true;
    MapRes = 0;
    DisablePeds = false;
    EnablePaging = false;
    Interlaced = false;
}

bool mmStatePack::ParseStateArgs(i32 argc, char** argv)
{
    bool no_ui = false;

#define ARG(NAME) !std::strcmp(arg, NAME)

    for (int i = 1; i < argc;)
    {
        // FIXME: Extra args may read out of bounds
        char* arg = argv[i++];

        if (ARG("-noui"))
        {
            const char* veh_name = "vpbug";

            if (asArg* veh = GBArgs['v'])
                veh_name = veh->sValues[0];

            NoUI = true;
            no_ui = true;
            arts_strcpy(CarName, veh_name);
            GameState = 1;
        }
        else if (ARG("-keyboard"))
        {
            InputType = mmInputType::Keyboard;
        }
        else if (ARG("-joystick"))
        {
            InputType = mmInputType::Joystick;
        }
        else if (ARG("-wheel"))
        {
            InputType = mmInputType::Wheel2Axis;
        }
        else if (ARG("-nodamage"))
        {
            DisableDamage = true;
        }
        else if (ARG("-allrace"))
        {
            UnlockAllRaces = true;
        }
        else if (ARG("-allcars"))
        {
            AllCars = true;
        }
        else if (ARG("-stoabs"))
        {
            BlitzCheatTime = 800;
            DisableDamage = true;
            UnlockAllRaces = true;
            AllCars = true;
        }
        else if (ARG("-supercops"))
        {
            SuperCops = true;
        }
        else if (ARG("-ambient"))
        {
            AmbientCount = std::atoi(argv[i++]);
        }
        else if (ARG("-noai"))
        {
            AmbientDensity = 0.0f;
            CopDensity = 0.0f;
            MaxOpponents = 0.0f;
            DisableAI = true;
        }
        else if (ARG("-nopcops"))
        {
            CopDensity = 0.0f;
        }
        else if (ARG("-blitztime"))
        {
            BlitzCheatTime = std::atoi(argv[i++]);
        }
        else if (ARG("-race"))
        {
            GameMode = mmGameMode::Race;
            EventId = std::atoi(argv[i++]);
        }
        else if (ARG("-circuit"))
        {
            GameMode = mmGameMode::Circuit;
            EventId = std::atoi(argv[i++]);
        }
        else if (ARG("-blitz"))
        {
            GameMode = mmGameMode::Blitz;
            EventId = std::atoi(argv[i++]);
        }
        else if (ARG("-edit"))
        {
            GameMode = mmGameMode::Edit;
        }
        else if (ARG("-archivecycle"))
        {
            CycleTest = 2;
        }
        else if (ARG("-sample"))
        {
            SampleStats = true;
        }
        else if (ARG("-dragtimer"))
        {
            DragTimer = true;
        }
        else if (ARG("-noopponents"))
        {
            MaxOpponents = 0.0f;
        }
        else if (ARG("-damagescale"))
        {
            GlobalDamageScale = static_cast<f32>(std::atof(argv[i++]));
        }
    }

#undef ARG

    return no_ui;
}
