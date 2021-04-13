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

#include "mmaudio/manager.h"

void mmStatePack::SetDefaults()
{
    CurrentCar = 2; // Hopefully vpbug
    InputType = mmInputType::Mouse;
    NetworkStatus = 0;
    NumPlayers = 0;
    CopBehaviorFlag = 0;
    NoUI = false;
    Closing = false;
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