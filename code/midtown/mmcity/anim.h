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
    mmcity:anim

    0x497E50 | public: int __thiscall mmAnimation::LookupSequence(char *) | ?LookupSequence@mmAnimation@@QAEHPAD@Z
    0x497EB0 | public: void __thiscall mmAnimation::Load(char *,class Stream *) | ?Load@mmAnimation@@QAEXPADPAVStream@@@Z
    0x498700 | class mmAnimation * __cdecl GetAnimation(char *) | ?GetAnimation@@YAPAVmmAnimation@@PAD@Z
    0x498830 | public: static void __cdecl mmAnimInstState::PreUpdate(float) | ?PreUpdate@mmAnimInstState@@SAXM@Z
    0x498880 | public: void __thiscall mmAnimInstState::Update(void) | ?Update@mmAnimInstState@@QAEXXZ
    0x498950 | public: __thiscall HashTable::~HashTable(void) | ??1HashTable@@QAE@XZ
    0x7057B0 | public: static float mmAnimInstState::FrameFraction | ?FrameFraction@mmAnimInstState@@2MA
    0x7057B4 | public: static int mmAnimInstState::FrameDelta | ?FrameDelta@mmAnimInstState@@2HA
*/

class mmAnimation
{
public:
    // ?Load@mmAnimation@@QAEXPADPAVStream@@@Z
    ARTS_IMPORT void Load(char* arg1, Stream* arg2);

    // ?LookupSequence@mmAnimation@@QAEHPAD@Z
    ARTS_IMPORT i32 LookupSequence(char* arg1);

    u8 gap0[0x18];
};

check_size(mmAnimation, 0x18);

// ?GetAnimation@@YAPAVmmAnimation@@PAD@Z
ARTS_IMPORT mmAnimation* GetAnimation(char* arg1);

struct mmAnimInstState
{
public:
    // ?Update@mmAnimInstState@@QAEXXZ
    ARTS_IMPORT void Update();

    // ?PreUpdate@mmAnimInstState@@SAXM@Z
    ARTS_EXPORT static void PreUpdate(f32 delta);

    // ?FrameDelta@mmAnimInstState@@2HA
    ARTS_IMPORT static i32 FrameDelta;

    // ?FrameFraction@mmAnimInstState@@2MA
    ARTS_IMPORT static f32 FrameFraction;

    mmAnimation* Anim {};
    i16 Frame {};
    u8 CurrentSequence {};
    u8 NextSequence {};
};

check_size(mmAnimInstState, 0x8);
