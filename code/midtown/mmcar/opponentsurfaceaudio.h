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
    mmcar:opponentsurfaceaudio

    0x485E00 | public: __thiscall mmOpponentSurfaceAudio::mmOpponentSurfaceAudio(void) | ??0mmOpponentSurfaceAudio@@QAE@XZ
    0x485E30 | public: __thiscall mmOpponentSurfaceAudio::~mmOpponentSurfaceAudio(void) | ??1mmOpponentSurfaceAudio@@QAE@XZ
    0x485E40 | public: void __thiscall mmOpponentSurfaceAudio::SetWheelPointers(class mmWheel *,class mmWheel *,class mmWheel *,class mmWheel *) | ?SetWheelPointers@mmOpponentSurfaceAudio@@QAEXPAVmmWheel@@000@Z
    0x485E60 | public: void __thiscall mmOpponentSurfaceAudio::Update(float) | ?Update@mmOpponentSurfaceAudio@@QAEXM@Z
    0x485EA0 | public: void __thiscall mmOpponentSurfaceAudio::UpdateSkid(float) | ?UpdateSkid@mmOpponentSurfaceAudio@@QAEXM@Z
    0x486120 | public: void __thiscall mmOpponentSurfaceAudio::UpdateSkidSnow(float) | ?UpdateSkidSnow@mmOpponentSurfaceAudio@@QAEXM@Z
    0x486380 | public: void __thiscall mmOpponentSurfaceAudio::Enable3DMode(class Vector3 *) | ?Enable3DMode@mmOpponentSurfaceAudio@@QAEXPAVVector3@@@Z
    0x4863A0 | public: void __thiscall mmOpponentSurfaceAudio::Disable3DMode(void) | ?Disable3DMode@mmOpponentSurfaceAudio@@QAEXXZ
*/

class mmWheel;

struct mmOpponentSurfaceAudio
{
public:
    // ??0mmOpponentSurfaceAudio@@QAE@XZ
    ARTS_IMPORT mmOpponentSurfaceAudio();

    // ??1mmOpponentSurfaceAudio@@QAE@XZ
    ARTS_IMPORT ~mmOpponentSurfaceAudio() = default;

    // ?Disable3DMode@mmOpponentSurfaceAudio@@QAEXXZ
    ARTS_IMPORT void Disable3DMode();

    // ?Enable3DMode@mmOpponentSurfaceAudio@@QAEXPAVVector3@@@Z
    ARTS_IMPORT void Enable3DMode(Vector3* arg1);

    // ?SetWheelPointers@mmOpponentSurfaceAudio@@QAEXPAVmmWheel@@000@Z
    ARTS_IMPORT void SetWheelPointers(mmWheel* arg1, mmWheel* arg2, mmWheel* arg3, mmWheel* arg4);

    // ?Update@mmOpponentSurfaceAudio@@QAEXM@Z
    ARTS_IMPORT void Update(f32 arg1);

    // ?UpdateSkid@mmOpponentSurfaceAudio@@QAEXM@Z
    ARTS_IMPORT void UpdateSkid(f32 arg1);

    // ?UpdateSkidSnow@mmOpponentSurfaceAudio@@QAEXM@Z
    ARTS_IMPORT void UpdateSkidSnow(f32 arg1);

    u8 gap0[0x2C];
};

check_size(mmOpponentSurfaceAudio, 0x2C);
