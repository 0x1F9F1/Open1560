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

class AudSound;

struct AddOnCarAudio
{
public:
    // ??0AddOnCarAudio@@QAE@PADF@Z
    ARTS_IMPORT AddOnCarAudio(char* arg1, i16 arg2);

    // ??1AddOnCarAudio@@QAE@XZ
    ARTS_IMPORT ~AddOnCarAudio();

    // ?EchoOff@AddOnCarAudio@@QAEXXZ
    ARTS_IMPORT void EchoOff();

    // ?EchoOn@AddOnCarAudio@@QAEXM@Z
    ARTS_IMPORT void EchoOn(f32 arg1);

    // ?GetEngineSoundPtr@AddOnCarAudio@@QAEPAVAudSound@@F@Z
    ARTS_IMPORT AudSound* GetEngineSoundPtr(i16 arg1);

    // ?Update@AddOnCarAudio@@QAEXXZ
    ARTS_IMPORT void Update();

    u8 gap0[0xC];
};

check_size(AddOnCarAudio, 0xC);
