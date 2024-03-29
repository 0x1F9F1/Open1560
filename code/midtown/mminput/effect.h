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
    mminput:effect

    0x4E7350 | int __stdcall inputEnumEffectTypeProc(struct DIEFFECTINFOA const *,void *) | ?inputEnumEffectTypeProc@@YGHPBUDIEFFECTINFOA@@PAX@Z
    0x4E73B0 | public: __thiscall mmEffectFF::mmEffectFF(void) | ??0mmEffectFF@@QAE@XZ
    0x4E7420 | public: __thiscall mmEffectFF::~mmEffectFF(void) | ??1mmEffectFF@@QAE@XZ
    0x4E7440 | public: virtual int __thiscall mmEffectFF::Play(void) | ?Play@mmEffectFF@@UAEHXZ
    0x4E7450 | public: virtual int __thiscall mmEffectFF::Stop(void) | ?Stop@mmEffectFF@@UAEHXZ
    0x4E7460 | public: virtual int __thiscall mmEffectFF::SetValues(float,float) | ?SetValues@mmEffectFF@@UAEHMM@Z
    0x61FD10 | const mmEffectFF::`vftable' | ??_7mmEffectFF@@6B@
*/

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
