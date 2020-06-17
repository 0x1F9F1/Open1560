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
    test

    0x4010B0 | class agiPipeline * __cdecl CreatePipeline(int,char * *) | ?CreatePipeline@@YAPAVagiPipeline@@HPAPAD@Z
    0x4012D0 | int __cdecl GenerateLoadScreenName(void) | ?GenerateLoadScreenName@@YAHXZ
    0x4014B0 | int __cdecl GameFilter(struct _EXCEPTION_POINTERS *) | ?GameFilter@@YAHPAU_EXCEPTION_POINTERS@@@Z
    0x4015A0 | void __cdecl GameLoop(class mmInterface *,class mmGameManager *,char *) | ?GameLoop@@YAXPAVmmInterface@@PAVmmGameManager@@PAD@Z
    0x401830 | void __cdecl ApplicationHelper(int,char * *) | ?ApplicationHelper@@YAXHPAPAD@Z
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

#include "core/minwin.h"

// 0x4031A0 | _WinMain@16 (Skipped: void)
ARTS_EXPORT int WINAPI MidtownMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);

// 0x4030C0 | ?Application@@YAXHPAPAD@Z
void Application(i32 arg1, char** arg2);

// 0x401830 | ?ApplicationHelper@@YAXHPAPAD@Z
void ApplicationHelper(i32 arg1, char** arg2);

// 0x4010B0 | ?CreatePipeline@@YAPAVagiPipeline@@HPAPAD@Z
class agiPipeline* CreatePipeline(i32 arg1, char** arg2);

// 0x4014B0 | ?GameFilter@@YAHPAU_EXCEPTION_POINTERS@@@Z
ARTS_EXPORT i32 GameFilter(struct _EXCEPTION_POINTERS* arg1);

// 0x4015A0 | ?GameLoop@@YAXPAVmmInterface@@PAVmmGameManager@@PAD@Z
void GameLoop(class mmInterface* arg1, class mmGameManager* arg2, char* arg3);

// 0x4012D0 | ?GenerateLoadScreenName@@YAHXZ
i32 GenerateLoadScreenName();

// 0x402F40 | ?InitAudioManager@@YAXXZ
void InitAudioManager();

// 0x403C00 | ??_H@YGXPAXIHP6EX0@Z@Z (Skipped: invalid name)

// 0x63468C | ?APPTITLE@@3PADA
inline extern_var(0x63468C, char*, APPTITLE);

// 0x672094 | ?AllCars@@3HA
inline extern_var(0x672094, i32, AllCars);

// 0x672090 | ?BlitzCheatTime@@3HA
inline extern_var(0x672090, i32, BlitzCheatTime);

// 0x672050 | ?CityName@@3PADA
inline extern_var(0x672050, char*, CityName);

// 0x672084 | ?CycleState@@3HA
inline extern_var(0x672084, i32, CycleState);

// 0x672078 | ?CycleTest@@3HA
inline extern_var(0x672078, i32, CycleTest);

// 0x634680 | ?CycleTime@@3MA
inline extern_var(0x634680, f32, CycleTime);

// 0x672080 | ?DragTimer@@3HA
inline extern_var(0x672080, i32, DragTimer);

// 0x634688 | ?GlobalDamageScale@@3MA
inline extern_var(0x634688, f32, GlobalDamageScale);

// 0x672088 | ?GraphicsChange@@3EA
inline extern_var(0x672088, u8, GraphicsChange);

// 0x67208C | ?GraphicsPreviousMenu@@3EA
inline extern_var(0x67208C, u8, GraphicsPreviousMenu);

// 0x671D08 | ?LoadScreen@@3PADA
inline extern_var(0x671D08, char*, LoadScreen);

// 0x671E38 | ?LoadTimer@@3VTimer@@A
inline extern_var(0x671E38, class Timer, LoadTimer);

// 0x67207C | ?SampleStats@@3HA
inline extern_var(0x67207C, i32, SampleStats);

// 0x672044 | ?SystemStatsRecord@@3PAVmmGameRecord@@A
inline extern_var(0x672044, class mmGameRecord*, SystemStatsRecord);

// 0x634690 | ?VERSION_STRING@@3PADA
inline extern_var(0x634690, char*, VERSION_STRING);

// 0x672040 | ?__VtPauseSampling@@3P6AHXZA
inline extern_var(0x672040, i32 (*)(void), __VtPauseSampling);

// 0x671D30 | ?__VtResumeSampling@@3P6AHXZA
inline extern_var(0x671D30, i32 (*)(void), __VtResumeSampling);

// 0x671D04 | ?bHaveIME@@3HA
inline extern_var(0x671D04, i32, bHaveIME);

// 0x672048 | ?hImmContext@@3KA
inline extern_var(0x672048, u32, hImmContext);

// 0x634684 | ?page_override@@3HA
inline extern_var(0x634684, i32, page_override);
