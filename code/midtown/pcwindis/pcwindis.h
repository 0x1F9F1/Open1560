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
    pcwindis:pcwindis

    0x5765F0 | long __stdcall MasterWindowProc(struct HWND__ *,unsigned int,unsigned int,long) | ?MasterWindowProc@@YGJPAUHWND__@@IIJ@Z
    0x576670 | void __cdecl RegisterMap(char *,unsigned int *,int,class Dispatchable *) | ?RegisterMap@@YAXPADPAIHPAVDispatchable@@@Z
    0x576750 | void __cdecl UnregisterMap(char *) | ?UnregisterMap@@YAXPAD@Z
*/

// 0x5765F0 | ?MasterWindowProc@@YGJPAUHWND__@@IIJ@Z
i32 __stdcall MasterWindowProc(struct HWND__* arg1, u32 arg2, u32 arg3, i32 arg4);

// 0x576670 | ?RegisterMap@@YAXPADPAIHPAVDispatchable@@@Z
void RegisterMap(char* arg1, u32* arg2, i32 arg3, class Dispatchable* arg4);

// 0x576750 | ?UnregisterMap@@YAXPAD@Z
void UnregisterMap(char* arg1);
