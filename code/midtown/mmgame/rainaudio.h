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
    mmgame:rainaudio

    0x433200 | public: __thiscall mmRainAudio::mmRainAudio(void) | ??0mmRainAudio@@QAE@XZ
    0x433400 | public: __thiscall mmRainAudio::~mmRainAudio(void) | ??1mmRainAudio@@QAE@XZ
    0x433440 | public: void __thiscall mmRainAudio::SetInterior(unsigned char) | ?SetInterior@mmRainAudio@@QAEXE@Z
    0x4334D0 | public: void __thiscall mmRainAudio::ShelterOn(void) | ?ShelterOn@mmRainAudio@@QAEXXZ
    0x433540 | public: void __thiscall mmRainAudio::ShelterOff(void) | ?ShelterOff@mmRainAudio@@QAEXXZ
    0x4335B0 | public: void __thiscall mmRainAudio::Update(void) | ?Update@mmRainAudio@@QAEXXZ
*/

struct mmRainAudio
{
public:
    // 0x433200 | ??0mmRainAudio@@QAE@XZ
    mmRainAudio();

    // 0x433400 | ??1mmRainAudio@@QAE@XZ
    ~mmRainAudio();

    // 0x433440 | ?SetInterior@mmRainAudio@@QAEXE@Z
    void SetInterior(u8 arg1);

    // 0x433540 | ?ShelterOff@mmRainAudio@@QAEXXZ
    void ShelterOff();

    // 0x4334D0 | ?ShelterOn@mmRainAudio@@QAEXXZ
    void ShelterOn();

    // 0x4335B0 | ?Update@mmRainAudio@@QAEXXZ
    void Update();
};

check_size(mmRainAudio, 0x1C);
