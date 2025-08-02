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

class mmRainAudio
{
public:
    // ??0mmRainAudio@@QAE@XZ
    ARTS_IMPORT mmRainAudio();

    // ?SetInterior@mmRainAudio@@QAEXE@Z
    ARTS_IMPORT void SetInterior(u8 arg1);

    // ?ShelterOff@mmRainAudio@@QAEXXZ
    ARTS_IMPORT void ShelterOff();

    // ?ShelterOn@mmRainAudio@@QAEXXZ
    ARTS_IMPORT void ShelterOn();

    // ?Update@mmRainAudio@@QAEXXZ
    ARTS_IMPORT void Update();

    u8 gap0[0x1C];
};

check_size(mmRainAudio, 0x1C);
