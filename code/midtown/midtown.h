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

class agiPipeline;
class CallbackArray;
class mmGameRecord;
class Timer;

// ?CreatePipeline@@YAPAVagiPipeline@@HPAPAD@Z
Owner<agiPipeline> CreatePipeline(i32 argc, char** argv);

// ?APPTITLE@@3PADA
ARTS_EXPORT extern aconst char* APPTITLE;

// ?AllCars@@3HA
extern b32 AllCars;

// ?BlitzCheatTime@@3HA
ARTS_EXPORT extern i32 BlitzCheatTime;

// ?CityName@@3PADA
ARTS_EXPORT extern char CityName[40];

// ?CycleState@@3HA
extern i32 CycleState;

// ?CycleTime@@3MA
extern f32 CycleTime;

// ?GlobalDamageScale@@3MA
ARTS_EXPORT extern f32 GlobalDamageScale;

// ?GraphicsChange@@3EA
ARTS_EXPORT extern u8 GraphicsChange;

// ?GraphicsPreviousMenu@@3EA
ARTS_EXPORT extern u8 GraphicsPreviousMenu;

// ?LoadScreen@@3PADA
extern char LoadScreen[40];

// ?LoadTimer@@3VTimer@@A
extern Timer LoadTimer;

// ?SystemStatsRecord@@3PAVmmGameRecord@@A
extern mmGameRecord* SystemStatsRecord;

// ?page_override@@3HA
ARTS_EXPORT extern i32 page_override;

#ifdef ARTS_DEV_BUILD
// ?CycleTest@@3HA
extern i32 CycleTest;

// ?DragTimer@@3HA
ARTS_EXPORT extern i32 DragTimer;

// ?SampleStats@@3HA
extern i32 SampleStats;
#endif

extern CallbackArray OnGameReset;
