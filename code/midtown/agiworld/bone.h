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

class Tokenizer;

class bnBone
{
public:
    // ??0bnBone@@QAE@XZ
    ARTS_IMPORT bnBone();

    // ?AddChild@bnBone@@QAEXPAV1@@Z
    ARTS_IMPORT void AddChild(bnBone* arg1);

    // ?Attach@bnBone@@QAEXQAVMatrix34@@AAH@Z
    ARTS_IMPORT void Attach(Matrix34* const arg1, i32& arg2);

    // ?Draw@bnBone@@QAEXXZ
    void Draw();

    // ?Load@bnBone@@QAEHPAVTokenizer@@PAPAV1@@Z
    ARTS_IMPORT i32 Load(Tokenizer* arg1, bnBone** arg2);

    // ?Pose@bnBone@@QAEXPBVVector3@@AAH@Z
    ARTS_IMPORT void Pose(const Vector3* arg1, i32& arg2);

    // ?Transform@bnBone@@QAEXPAVMatrix34@@@Z
    ARTS_IMPORT void Transform(Matrix34* arg1);

    u8 gap0[0x8C];
};

check_size(bnBone, 0x8C);
