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
    midtown

    0x4010B0 | class agiPipeline * __cdecl CreatePipeline(int,char * *) | ?CreatePipeline@@YAPAVagiPipeline@@HPAPAD@Z
    0x4012D0 | int __cdecl GenerateLoadScreenName(void) | ?GenerateLoadScreenName@@YAHXZ
    0x4014B0 | int __cdecl GameFilter(struct _EXCEPTION_POINTERS *) | ?GameFilter@@YAHPAU_EXCEPTION_POINTERS@@@Z
    0x4015A0 | void __cdecl GameLoop(class mmInterface *,class mmGameManager *,char *) | ?GameLoop@@YAXPAVmmInterface@@PAVmmGameManager@@PAD@Z
    0x401830 | void __cdecl ApplicationHelper(int,char * *) | ?ApplicationHelper@@YAXHPAPAD@Z
    0x402E70 | void __cdecl TouchMemory(void *,int) | ?TouchMemory@@YAXPAXH@Z
    0x402EC0 | char * __cdecl exeDirFile(char *,char *) | ?exeDirFile@@YAPADPAD0@Z
    0x402F20 | void __cdecl GameCloseCallback(void) | ?GameCloseCallback@@YAXXZ
    0x402F40 | void __cdecl InitAudioManager(void) | ?InitAudioManager@@YAXXZ
    0x4030C0 | void __cdecl Application(int,char * *) | ?Application@@YAXHPAPAD@Z
    0x4031A0 | _WinMain@16
    0x403C00 | void __stdcall `vector constructor iterator'(void *,unsigned int,int,void (__thiscall*)(void *)) | ??_H@YGXPAXIHP6EX0@Z@Z
    0x634680 | float CycleTime | ?CycleTime@@3MA
    0x634684 | int page_override | ?page_override@@3HA
    0x634688 | float GlobalDamageScale | ?GlobalDamageScale@@3MA
    0x63468C | char * APPTITLE | ?APPTITLE@@3PADA
    0x634690 | char * VERSION_STRING | ?VERSION_STRING@@3PADA
    0x671D04 | int bHaveIME | ?bHaveIME@@3HA
    0x671D08 | char * LoadScreen | ?LoadScreen@@3PADA
    0x671D30 | int (__cdecl* __VtResumeSampling)(void) | ?__VtResumeSampling@@3P6AHXZA
    0x671E38 | class Timer LoadTimer | ?LoadTimer@@3VTimer@@A
    0x672040 | int (__cdecl* __VtPauseSampling)(void) | ?__VtPauseSampling@@3P6AHXZA
    0x672044 | class mmGameRecord * SystemStatsRecord | ?SystemStatsRecord@@3PAVmmGameRecord@@A
    0x672048 | unsigned long hImmContext | ?hImmContext@@3KA
    0x672050 | char * CityName | ?CityName@@3PADA
    0x672078 | int CycleTest | ?CycleTest@@3HA
    0x67207C | int SampleStats | ?SampleStats@@3HA
    0x672080 | int DragTimer | ?DragTimer@@3HA
    0x672084 | int CycleState | ?CycleState@@3HA
    0x672088 | unsigned char GraphicsChange | ?GraphicsChange@@3EA
    0x67208C | unsigned char GraphicsPreviousMenu | ?GraphicsPreviousMenu@@3EA
    0x672090 | int BlitzCheatTime | ?BlitzCheatTime@@3HA
    0x672094 | int AllCars | ?AllCars@@3HA
*/

struct _EXCEPTION_POINTERS;
class agiPipeline;
class CallbackArray;
class mmGameManager;
class mmGameRecord;
class mmInterface;
class Timer;

// _WinMain@16 | void

// ?Application@@YAXHPAPAD@Z
ARTS_EXPORT void Application(i32 argc, char** argv);

// ?ApplicationHelper@@YAXHPAPAD@Z
ARTS_EXPORT void ApplicationHelper(i32 argc, char** argv);

// ?CreatePipeline@@YAPAVagiPipeline@@HPAPAD@Z
ARTS_EXPORT Owner<agiPipeline> CreatePipeline(i32 argc, char** argv);

// ?GameFilter@@YAHPAU_EXCEPTION_POINTERS@@@Z
ARTS_EXPORT i32 GameFilter(_EXCEPTION_POINTERS* exception);

// ?GameLoop@@YAXPAVmmInterface@@PAVmmGameManager@@PAD@Z
ARTS_IMPORT void GameLoop(mmInterface* mm_interface, mmGameManager* game_manager, char* replay_name);

// ?GenerateLoadScreenName@@YAHXZ
ARTS_EXPORT b32 GenerateLoadScreenName();

// ?InitAudioManager@@YAXXZ
ARTS_EXPORT void InitAudioManager();

// ?APPTITLE@@3PADA
ARTS_IMPORT extern char* APPTITLE;

// ?AllCars@@3HA
ARTS_IMPORT extern i32 AllCars;

// ?BlitzCheatTime@@3HA
ARTS_IMPORT extern i32 BlitzCheatTime;

// ?CityName@@3PADA
ARTS_IMPORT extern char CityName[40];

// ?CycleState@@3HA
ARTS_IMPORT extern i32 CycleState;

#ifdef ARTS_DEV_BUILD
// ?CycleTest@@3HA
ARTS_IMPORT extern i32 CycleTest;
#endif

// ?CycleTime@@3MA
ARTS_IMPORT extern f32 CycleTime;

#ifdef ARTS_DEV_BUILD
// ?DragTimer@@3HA
ARTS_IMPORT extern i32 DragTimer;
#endif

// ?GlobalDamageScale@@3MA
ARTS_IMPORT extern f32 GlobalDamageScale;

// ?GraphicsChange@@3EA
ARTS_IMPORT extern u8 GraphicsChange;

// ?GraphicsPreviousMenu@@3EA
ARTS_IMPORT extern u8 GraphicsPreviousMenu;

// ?LoadScreen@@3PADA
ARTS_IMPORT extern char LoadScreen[40];

// ?LoadTimer@@3VTimer@@A
ARTS_IMPORT extern Timer LoadTimer;

#ifdef ARTS_DEV_BUILD
// ?SampleStats@@3HA
ARTS_IMPORT extern i32 SampleStats;
#endif

// ?SystemStatsRecord@@3PAVmmGameRecord@@A
ARTS_IMPORT extern mmGameRecord* SystemStatsRecord;

// ?VERSION_STRING@@3PADA
ARTS_IMPORT extern char* VERSION_STRING;

extern const char* DEFAULT_CITY;

// ?__VtPauseSampling@@3P6AHXZA
ARTS_IMPORT extern i32 (*__VtPauseSampling)(void);

// ?__VtResumeSampling@@3P6AHXZA
ARTS_IMPORT extern i32 (*__VtResumeSampling)(void);

// ?bHaveIME@@3HA
ARTS_IMPORT extern i32 bHaveIME;

// ?hImmContext@@3KA
ARTS_IMPORT extern ulong hImmContext; // TODO: Use usize/void*

// ?page_override@@3HA
ARTS_IMPORT extern i32 page_override;

extern CallbackArray OnGameReset;
