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

#include "core/minwin.h"

void SDLWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// ?MasterWindowProc@@YGJPAUHWND__@@IIJ@Z
ARTS_EXPORT LRESULT ARTS_STDCALL MasterWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// ?RegisterMap@@YAXPADPAIHPAVDispatchable@@@Z
ARTS_EXPORT void RegisterMap(const char* name, u32* msgs, i32 num_msgs, class Dispatchable* handler);

// ?UnregisterMap@@YAXPAD@Z
ARTS_EXPORT void UnregisterMap(const char* name);
