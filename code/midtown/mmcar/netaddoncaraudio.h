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

class mmNetworkCarAudio;

struct NetAddOnCarAudio
{
public:
    // ??0NetAddOnCarAudio@@QAE@PADF@Z
    ARTS_IMPORT NetAddOnCarAudio(char* arg1, i16 arg2);

    // ??1NetAddOnCarAudio@@QAE@XZ
    ARTS_IMPORT ~NetAddOnCarAudio();

    // ?AssignSounds@NetAddOnCarAudio@@QAEHPAVmmNetworkCarAudio@@F@Z
    ARTS_IMPORT i32 AssignSounds(mmNetworkCarAudio* arg1, i16 arg2);

    // ?EchoOff@NetAddOnCarAudio@@QAEXXZ
    ARTS_IMPORT void EchoOff();

    // ?EchoOn@NetAddOnCarAudio@@QAEXM@Z
    ARTS_IMPORT void EchoOn(f32 arg1);

    // ?Update@NetAddOnCarAudio@@QAEXXZ
    ARTS_IMPORT void Update();

    u8 gap0[0xC];
};

check_size(NetAddOnCarAudio, 0xC);
