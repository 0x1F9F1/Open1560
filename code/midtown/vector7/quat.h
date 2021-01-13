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
    vector7:quat

    0x572550 | public: void __thiscall Quaternion::Init(float,float,float,float) | ?Init@Quaternion@@QAEXMMMM@Z
    0x5726A0 | public: void __thiscall Quaternion::FromMatrix(class Matrix34 const &) | ?FromMatrix@Quaternion@@QAEXABVMatrix34@@@Z
    0x5727F0 | public: class Quaternion __thiscall Quaternion::operator~(void) const | ??SQuaternion@@QBE?AV0@XZ
    0x572890 | public: float __thiscall Quaternion::Mag(void) const | ?Mag@Quaternion@@QBEMXZ
    0x572960 | public: void __thiscall Quaternion::Normalize(void) | ?Normalize@Quaternion@@QAEXXZ
    0x5729C0 | public: float __thiscall Quaternion::Angle(class Quaternion const &) const | ?Angle@Quaternion@@QBEMABV1@@Z
    0x572A30 | public: void __thiscall Quaternion::TrackBall(float,float,float,float,float) | ?TrackBall@Quaternion@@QAEXMMMMM@Z
    0x572CE0 | public: void __thiscall Quaternion::Lerp(float,class Quaternion const &,class Quaternion const &) | ?Lerp@Quaternion@@QAEXMABV1@0@Z
    0x572F60 | public: void __thiscall Quaternion::Slerp(float,class Quaternion const &,class Quaternion const &) | ?Slerp@Quaternion@@QAEXMABV1@0@Z
    0x573120 | public: int __thiscall Quaternion::Approach(class Quaternion const &,float,float) | ?Approach@Quaternion@@QAEHABV1@MM@Z
    0x5731A0 | public: void __thiscall Quaternion::CatmullRom(float,class Quaternion const &,class Quaternion const &,class Quaternion const &,class Quaternion const &) | ?CatmullRom@Quaternion@@QAEXMABV1@000@Z
*/

class Quaternion
{
public:
    // 0x5727F0 | ??SQuaternion@@QBE?AV0@XZ | unused
    ARTS_IMPORT class Quaternion operator~() const;

    // 0x5729C0 | ?Angle@Quaternion@@QBEMABV1@@Z
    ARTS_IMPORT f32 Angle(class Quaternion const& arg1) const;

    // 0x573120 | ?Approach@Quaternion@@QAEHABV1@MM@Z | unused
    ARTS_IMPORT i32 Approach(class Quaternion const& arg1, f32 arg2, f32 arg3);

    // 0x5731A0 | ?CatmullRom@Quaternion@@QAEXMABV1@000@Z | unused
    ARTS_IMPORT void CatmullRom(f32 arg1, class Quaternion const& arg2, class Quaternion const& arg3,
        class Quaternion const& arg4, class Quaternion const& arg5);

    // 0x5726A0 | ?FromMatrix@Quaternion@@QAEXABVMatrix34@@@Z
    ARTS_IMPORT void FromMatrix(class Matrix34 const& arg1);

    // 0x572550 | ?Init@Quaternion@@QAEXMMMM@Z
    ARTS_IMPORT void Init(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // 0x572CE0 | ?Lerp@Quaternion@@QAEXMABV1@0@Z
    ARTS_IMPORT void Lerp(f32 arg1, class Quaternion const& arg2, class Quaternion const& arg3);

    // 0x572890 | ?Mag@Quaternion@@QBEMXZ
    ARTS_IMPORT f32 Mag() const;

    // 0x572960 | ?Normalize@Quaternion@@QAEXXZ
    ARTS_IMPORT void Normalize();

    // 0x572F60 | ?Slerp@Quaternion@@QAEXMABV1@0@Z | unused
    ARTS_IMPORT void Slerp(f32 arg1, class Quaternion const& arg2, class Quaternion const& arg3);

    // 0x572A30 | ?TrackBall@Quaternion@@QAEXMMMMM@Z | unused
    ARTS_IMPORT void TrackBall(f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    u8 gap0[0x10];
};

check_size(Quaternion, 0x10);
