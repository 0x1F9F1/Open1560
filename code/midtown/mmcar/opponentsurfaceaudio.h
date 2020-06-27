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

struct mmOpponentSurfaceAudio
{
public:
    // 0x485E00 | ??0mmOpponentSurfaceAudio@@QAE@XZ
    ARTS_IMPORT mmOpponentSurfaceAudio();

    // 0x485E30 | ??1mmOpponentSurfaceAudio@@QAE@XZ
    ARTS_IMPORT ~mmOpponentSurfaceAudio() = default;

    // 0x4863A0 | ?Disable3DMode@mmOpponentSurfaceAudio@@QAEXXZ
    ARTS_IMPORT void Disable3DMode();

    // 0x486380 | ?Enable3DMode@mmOpponentSurfaceAudio@@QAEXPAVVector3@@@Z
    ARTS_IMPORT void Enable3DMode(class Vector3* arg1);

    // 0x485E40 | ?SetWheelPointers@mmOpponentSurfaceAudio@@QAEXPAVmmWheel@@000@Z
    ARTS_IMPORT void SetWheelPointers(
        class mmWheel* arg1, class mmWheel* arg2, class mmWheel* arg3, class mmWheel* arg4);

    // 0x485E60 | ?Update@mmOpponentSurfaceAudio@@QAEXM@Z
    ARTS_IMPORT void Update(f32 arg1);

    // 0x485EA0 | ?UpdateSkid@mmOpponentSurfaceAudio@@QAEXM@Z
    ARTS_IMPORT void UpdateSkid(f32 arg1);

    // 0x486120 | ?UpdateSkidSnow@mmOpponentSurfaceAudio@@QAEXM@Z
    ARTS_IMPORT void UpdateSkidSnow(f32 arg1);

    u8 gap0[0x2C];
};

check_size(mmOpponentSurfaceAudio, 0x2C);
