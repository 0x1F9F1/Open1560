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

#pragma once

/*
    mmcityinfo:state

    0x4CBB40 | public: virtual __thiscall mmPlayerData::~mmPlayerData(void) | ??1mmPlayerData@@UAE@XZ
    0x4CBBE0 | public: virtual void * __thiscall mmPlayerData::`scalar deleting destructor'(unsigned int) | ??_GmmPlayerData@@UAEPAXI@Z
    0x61F898 | const mmPlayerData::`vftable' | ??_7mmPlayerData@@6B@
    0x706068 | struct mmStatePack MMSTATE | ?MMSTATE@@3UmmStatePack@@A
    0x706360 | int CHEATING | ?CHEATING@@3HA
    0x706368 | class mmPlayerData MMCURRPLAYER | ?MMCURRPLAYER@@3VmmPlayerData@@A
    0x7084E0 | int CHICAGO | ?CHICAGO@@3HA
*/

// 0x706360 | ?CHEATING@@3HA
ARTS_IMPORT extern i32 CHEATING;

// 0x7084E0 | ?CHICAGO@@3HA
ARTS_IMPORT extern i32 CHICAGO;

// 0x706368 | ?MMCURRPLAYER@@3VmmPlayerData@@A
ARTS_IMPORT extern class mmPlayerData MMCURRPLAYER;

enum class mmGameMode : i32
{
    Cruise = 0,
    Race = 1, // Checkpoint
    CnR = 2,
    Circuit = 3,
    Blitz = 4,
    Edit = 5,
};

struct mmStatePack
{
    i32 CurrentCar;
    i32 field_4;

    // mmInputType
    i32 InputType;

    i32 NetworkStatus;
    i32 NumPlayers;
    i32 field_14;
    i32 CopBehaviorFlag; // Cops chase opponents?
    i32 NoUI;
    i32 field_20;
    i32 Closing;
    i32 field_28;

    mmGameMode GameMode;
    i32 EventId;
    f32 RaceDifficulty;
    i32 AutoTransmission;
    i32 field_3C;
    i32 field_40;
    i32 field_44;
    f32 AmbientDensity;
    f32 PedDensity;
    f32 CopDensity;
    f32 MaxOpponents;
    f32 PhysicsRealism;
    i32 EnableFF;
    i32 UnlockAllRaces;

    // 0 | Sun
    // 1 | Fog
    // 2 | Rain
    // 3 | Snow
    i32 Weather;

    // 0 | Morning
    // 1 | Noon
    // 2 | Sunset
    // 3 | Night
    i32 TimeOfDay;
    char CarName[80];
    i32 CurrentColor;
    char NetName[80];
    f32 TimeLimit;

    // -1 | Loading
    //  0 | Menus
    //  1 | Race
    i32 GameState;
    b32 DisableDamage;
    b32 DisableAI;
    b32 SuperCops;
    i32 AmbientCount;
    i32 NumLaps;

    // 0 | Amateur
    // 1 | Professional
    i32 Difficulty;
    f32 WaveVolume;
    f32 AudBalance;
    f32 CDVolume;
    i32 AudFlags;
    i16 AudNumChannels;
    char field_142[20];
    char AudDeviceName[200];
    bool HasMidtownCD;
    i32 FreeForAll;
    i32 CREnableTimer;
    i32 IsRobber;
    f32 CRTimeLimit;
    i32 CRTimeLimit2;
    i32 CRGoldMass;
    i32 field_238;
    i32 field_23C;
    char IntroText[160];
    i8 CameraIndex;
    i8 HudmapMode;
    bool WideFov;
    bool DashView;
    bool EnableMirror;
    bool ExternalView;
    bool XcamView;
    bool ShowPositions;
    i8 MapRes;
    b32 DisablePeds;
    b32 EnablePaging;
    b32 Interlaced;
};

check_size(mmStatePack, 0x2F8);

// 0x706068 | ?MMSTATE@@3UmmStatePack@@A
ARTS_IMPORT extern struct mmStatePack MMSTATE;
