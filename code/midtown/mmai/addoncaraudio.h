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
    mmai:addoncaraudio

    0x45C560 | public: __thiscall AddOnCarAudio::AddOnCarAudio(char *,short) | ??0AddOnCarAudio@@QAE@PADF@Z
    0x45C690 | public: __thiscall AddOnCarAudio::~AddOnCarAudio(void) | ??1AddOnCarAudio@@QAE@XZ
    0x45C6E0 | public: class AudSound * __thiscall AddOnCarAudio::GetEngineSoundPtr(short) | ?GetEngineSoundPtr@AddOnCarAudio@@QAEPAVAudSound@@F@Z
    0x45C700 | public: void __thiscall AddOnCarAudio::EchoOn(float) | ?EchoOn@AddOnCarAudio@@QAEXM@Z
    0x45C750 | public: void __thiscall AddOnCarAudio::EchoOff(void) | ?EchoOff@AddOnCarAudio@@QAEXXZ
    0x45C780 | public: void __thiscall AddOnCarAudio::Update(void) | ?Update@AddOnCarAudio@@QAEXXZ
*/

struct AddOnCarAudio
{
public:
    // 0x45C560 | ??0AddOnCarAudio@@QAE@PADF@Z
    ARTS_IMPORT AddOnCarAudio(char* arg1, i16 arg2);

    // 0x45C690 | ??1AddOnCarAudio@@QAE@XZ
    ARTS_IMPORT ~AddOnCarAudio();

    // 0x45C750 | ?EchoOff@AddOnCarAudio@@QAEXXZ
    ARTS_IMPORT void EchoOff();

    // 0x45C700 | ?EchoOn@AddOnCarAudio@@QAEXM@Z
    ARTS_IMPORT void EchoOn(f32 arg1);

    // 0x45C6E0 | ?GetEngineSoundPtr@AddOnCarAudio@@QAEPAVAudSound@@F@Z
    ARTS_IMPORT class AudSound* GetEngineSoundPtr(i16 arg1);

    // 0x45C780 | ?Update@AddOnCarAudio@@QAEXXZ
    ARTS_IMPORT void Update();
};

check_size(AddOnCarAudio, 0xC);
