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

struct _EXCEPTION_POINTERS;
class agiPipeline;
class CallbackArray;
class mmGameManager;
class mmGameRecord;
class mmInterface;
class Timer;

// ?Application@@YAXHPAPAD@Z
ARTS_EXPORT void Application(i32 argc, char** argv);

// ?ApplicationHelper@@YAXHPAPAD@Z
ARTS_EXPORT void ApplicationHelper(i32 argc, char** argv);

// ?CreatePipeline@@YAPAVagiPipeline@@HPAPAD@Z
ARTS_EXPORT Owner<agiPipeline> CreatePipeline(i32 argc, char** argv);

// ?GameFilter@@YAHPAU_EXCEPTION_POINTERS@@@Z
ARTS_EXPORT i32 GameFilter(_EXCEPTION_POINTERS* exception);

// ?GameLoop@@YAXPAVmmInterface@@PAVmmGameManager@@PAD@Z
ARTS_EXPORT void GameLoop(mmInterface* mm_interface, mmGameManager* game_manager, char* replay_name);

// ?GenerateLoadScreenName@@YAHXZ
ARTS_EXPORT b32 GenerateLoadScreenName();

// ?InitAudioManager@@YAXXZ
ARTS_EXPORT void InitAudioManager();

// ?APPTITLE@@3PADA
ARTS_EXPORT extern aconst char* APPTITLE;

// ?AllCars@@3HA
ARTS_EXPORT extern b32 AllCars;

// ?BlitzCheatTime@@3HA
ARTS_EXPORT extern i32 BlitzCheatTime;

// ?CityName@@3PADA
ARTS_EXPORT extern char CityName[40];

// ?CycleState@@3HA
ARTS_EXPORT extern i32 CycleState;

// ?CycleTime@@3MA
ARTS_EXPORT extern f32 CycleTime;

// ?GlobalDamageScale@@3MA
ARTS_EXPORT extern f32 GlobalDamageScale;

// ?GraphicsChange@@3EA
ARTS_EXPORT extern u8 GraphicsChange;

// ?GraphicsPreviousMenu@@3EA
ARTS_EXPORT extern u8 GraphicsPreviousMenu;

// ?LoadScreen@@3PADA
ARTS_EXPORT extern char LoadScreen[40];

// ?LoadTimer@@3VTimer@@A
ARTS_EXPORT extern Timer LoadTimer;

// ?SystemStatsRecord@@3PAVmmGameRecord@@A
ARTS_EXPORT extern mmGameRecord* SystemStatsRecord;

// ?bHaveIME@@3HA
ARTS_EXPORT extern b32 bHaveIME;

// ?hImmContext@@3KA
ARTS_EXPORT extern ulong hImmContext; // TODO: Use usize/void*

// ?page_override@@3HA
ARTS_EXPORT extern i32 page_override;

#ifdef ARTS_DEV_BUILD
// ?CycleTest@@3HA
ARTS_EXPORT extern i32 CycleTest;

// ?DragTimer@@3HA
ARTS_EXPORT extern i32 DragTimer;

// ?SampleStats@@3HA
ARTS_EXPORT extern i32 SampleStats;
#endif

extern CallbackArray OnGameReset;
