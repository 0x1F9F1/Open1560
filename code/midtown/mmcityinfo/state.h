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

class mmPlayerData;

// ?CHEATING@@3HA
ARTS_IMPORT extern i32 CHEATING;

// ?CHICAGO@@3HA
ARTS_IMPORT extern i32 CHICAGO;

// ?MMCURRPLAYER@@3VmmPlayerData@@A
ARTS_IMPORT extern mmPlayerData MMCURRPLAYER;

enum class mmGameMode : i32
{
    Cruise = 0,     // roam/ro
    Checkpoint = 1, // waypt/race/ch, -race
    CnR = 2,        // cops/cr
    Circuit = 3,    // circ/circuit/ci, -circuit
    Blitz = 4,      // blitz/bl, -blitz
    Edit = 5,       // -edit
};

enum class mmSkillLevel : i32
{
    Amateur = 0,
    Professional = 1,
};

// InputConfiguration
enum class mmInputType : i32
{
    Mouse = 0,      // mmiMOUSE
    Keyboard = 1,   // mmiKEYBOARD
    Joystick = 2,   // mmiJOYSTICK
    Gamepad = 3,    // mmiGAMEPAD
    Wheel2Axis = 4, // mmiWHEEL2AXIS
};

enum class mmCRGameClass : i32
{
    FreeForAll = 0,  // melee
    CopsRobbers = 1, // copr
    RobberTeams = 2, // rvsr
};

enum class mmCRLimitMode : i32
{
    None = 0,
    Time = 1,
    Points = 2,
};

// TODO: Pick a better name
enum class mmGameState : i32
{
    Running = -1,
    Menus = 0,
    Drive = 1,
};

enum class mmWeather : i32
{
    Sun = 0,
    Fog = 1,
    Rain = 2,
    Snow = 3,
};

enum class mmTimeOfDay : i32
{
    Morning = 0,
    Noon = 1,
    Sunset = 2,
    Night = 3,
};

struct mmStatePack
{
    i32 CurrentCar;
    i32 field_4;

    mmInputType InputType;

    i32 NetworkStatus;
    i32 NetworkID;
    i32 field_14;
    b32 ChaseOpponents;
    i32 NoUI;
    i32 field_20;
    i32 Shutdown;
    i32 field_28;

    mmGameMode GameMode;
    i32 EventId;
    f32 RaceDifficulty;
    b32 AutoTransmission;
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

    mmWeather Weather;
    mmTimeOfDay TimeOfDay;

    char CarName[80];
    i32 CurrentColor;
    char NetName[80];
    f32 TimeLimit;

    mmGameState GameState;
    b32 DisableDamage;
    b32 DisableAI;
    b32 SuperCops;
    i32 AmbientCount;
    i32 NumLaps;

    mmSkillLevel Difficulty;

    // Audio
    f32 WaveVolume;
    f32 AudBalance;
    f32 CDVolume;
    i32 AudFlags;
    i16 AudNumChannels;
    char field_142[20];
    char AudDeviceName[200];
    bool HasMidtownCD;

    // Cops and Robbers
    mmCRGameClass CRGameClass;
    mmCRLimitMode CRLimitMode;
    i32 CRIsRobber;
    f32 CRTimeLimit;
    i32 CRScoreLimit;
    i32 CRGoldMass;

    i32 field_238;
    i32 field_23C;

    char IntroText[160];

    // Camera
    i8 CameraIndex;
    i8 HudmapMode;
    bool WideFov;
    bool DashView;
    bool EnableMirror;
    bool ExternalView;
    bool XcamView;

    // HUD
    bool ShowPositions;
    i8 MapRes;

    b32 DisablePeds;
    b32 EnablePaging;
    b32 Interlaced;

    void SetDefaults();
    bool ParseStateArgs(i32 argc, char** argv);
};

check_size(mmStatePack, 0x2F8);

// ?MMSTATE@@3UmmStatePack@@A
ARTS_IMPORT extern mmStatePack MMSTATE;
