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
    mmgame:mmambientaudio

    0x427DB0 | public: __thiscall mmAmbientAudio::mmAmbientAudio(class mmPlayer *) | ??0mmAmbientAudio@@QAE@PAVmmPlayer@@@Z
    0x427E50 | public: __thiscall mmAmbientAudio::~mmAmbientAudio(void) | ??1mmAmbientAudio@@QAE@XZ
    0x427E60 | public: void __thiscall mmAmbientAudio::Update(void) | ?Update@mmAmbientAudio@@QAEXXZ
*/

class mmPlayer;

struct mmAmbientAudio
{
public:
    // ??0mmAmbientAudio@@QAE@PAVmmPlayer@@@Z
    ARTS_IMPORT mmAmbientAudio(mmPlayer* arg1);

    // ??1mmAmbientAudio@@QAE@XZ
    ARTS_IMPORT ~mmAmbientAudio();

    // ?Update@mmAmbientAudio@@QAEXXZ
    ARTS_IMPORT void Update();

    u8 gap0[0x14];
};

check_size(mmAmbientAudio, 0x14);
