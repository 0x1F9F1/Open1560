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

struct DIEFFECTINFOA;
struct IDirectInputDevice2A;

// ?inputEnumEffectTypeProc@@YGHPBUDIEFFECTINFOA@@PAX@Z
ARTS_IMPORT i32 ARTS_STDCALL inputEnumEffectTypeProc(const DIEFFECTINFOA* arg1, void* arg2);

class mmEffectFF
{
public:
    // ??0mmEffectFF@@QAE@XZ
    ARTS_IMPORT mmEffectFF();

    // ??1mmEffectFF@@QAE@XZ
    ARTS_IMPORT ~mmEffectFF();

    virtual i32 Init(IDirectInputDevice2A* arg1) = 0;

    // ?Play@mmEffectFF@@UAEHXZ | inline
    ARTS_EXPORT virtual i32 Play();

    // ?Stop@mmEffectFF@@UAEHXZ | inline
    ARTS_EXPORT virtual i32 Stop();

    // ?SetValues@mmEffectFF@@UAEHMM@Z | inline
    ARTS_IMPORT virtual i32 SetValues(f32 arg1, f32 arg2);

    u8 gap4[0x7C];
};

check_size(mmEffectFF, 0x80);
