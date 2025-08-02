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

class Quaternion
{
public:
    // ?Angle@Quaternion@@QBEMABV1@@Z
    ARTS_IMPORT f32 Angle(const Quaternion& arg1) const;

    // ?CatmullRom@Quaternion@@QAEXMABV1@000@Z | unused
    ARTS_IMPORT void CatmullRom(
        f32 arg1, const Quaternion& arg2, const Quaternion& arg3, const Quaternion& arg4, const Quaternion& arg5);

    // ?FromMatrix@Quaternion@@QAEXABVMatrix34@@@Z
    ARTS_IMPORT void FromMatrix(const Matrix34& arg1);

    // ?Init@Quaternion@@QAEXMMMM@Z
    ARTS_IMPORT void Init(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    // ?Lerp@Quaternion@@QAEXMABV1@0@Z
    ARTS_IMPORT void Lerp(f32 arg1, const Quaternion& arg2, const Quaternion& arg3);

    // ?Mag@Quaternion@@QBEMXZ
    ARTS_IMPORT f32 Mag() const;

    // ?Normalize@Quaternion@@QAEXXZ
    ARTS_IMPORT void Normalize();

    u8 gap0[0x10];
};

check_size(Quaternion, 0x10);
