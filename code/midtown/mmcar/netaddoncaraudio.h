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
    mmcar:netaddoncaraudio

    0x485540 | public: __thiscall NetAddOnCarAudio::NetAddOnCarAudio(char *,short) | ??0NetAddOnCarAudio@@QAE@PADF@Z
    0x485660 | public: __thiscall NetAddOnCarAudio::~NetAddOnCarAudio(void) | ??1NetAddOnCarAudio@@QAE@XZ
    0x4856B0 | public: int __thiscall NetAddOnCarAudio::AssignSounds(class mmNetworkCarAudio *,short) | ?AssignSounds@NetAddOnCarAudio@@QAEHPAVmmNetworkCarAudio@@F@Z
    0x485740 | public: void __thiscall NetAddOnCarAudio::EchoOn(float) | ?EchoOn@NetAddOnCarAudio@@QAEXM@Z
    0x4857A0 | public: void __thiscall NetAddOnCarAudio::EchoOff(void) | ?EchoOff@NetAddOnCarAudio@@QAEXXZ
    0x4857D0 | public: void __thiscall NetAddOnCarAudio::Update(void) | ?Update@NetAddOnCarAudio@@QAEXXZ
*/

struct NetAddOnCarAudio
{
public:
    // 0x485540 | ??0NetAddOnCarAudio@@QAE@PADF@Z
    ARTS_IMPORT NetAddOnCarAudio(char* arg1, i16 arg2);

    // 0x485660 | ??1NetAddOnCarAudio@@QAE@XZ
    ARTS_IMPORT ~NetAddOnCarAudio();

    // 0x4856B0 | ?AssignSounds@NetAddOnCarAudio@@QAEHPAVmmNetworkCarAudio@@F@Z
    ARTS_IMPORT i32 AssignSounds(class mmNetworkCarAudio* arg1, i16 arg2);

    // 0x4857A0 | ?EchoOff@NetAddOnCarAudio@@QAEXXZ
    ARTS_IMPORT void EchoOff();

    // 0x485740 | ?EchoOn@NetAddOnCarAudio@@QAEXM@Z
    ARTS_IMPORT void EchoOn(f32 arg1);

    // 0x4857D0 | ?Update@NetAddOnCarAudio@@QAEXXZ
    ARTS_IMPORT void Update();
};

check_size(NetAddOnCarAudio, 0x0);
