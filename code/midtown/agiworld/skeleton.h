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

class bnBone;

struct bnSkeleton
{
public:
    // ??0bnSkeleton@@QAE@XZ
    ARTS_IMPORT bnSkeleton();

    // ?FindBone@bnSkeleton@@QAEPAVbnBone@@PADHD@Z
    ARTS_IMPORT bnBone* FindBone(char* arg1, i32 arg2, char arg3);

    // ?Load@bnSkeleton@@QAEHPBD@Z
    ARTS_IMPORT i32 Load(const char* arg1);

    // ?Pose@bnSkeleton@@QAEXPBVVector3@@@Z
    ARTS_IMPORT void Pose(const Vector3* arg1);

    // ?Transform@bnSkeleton@@QAEXPAVMatrix34@@@Z
    ARTS_IMPORT void Transform(Matrix34* arg1);

    u8 gap0[0x20];
};

check_size(bnSkeleton, 0x20);

class bnAnimation
{
public:
    // ?Load@bnAnimation@@QAEHPAD@Z
    ARTS_IMPORT i32 Load(char* arg1);

    u8 gap0[0xC];
};

check_size(bnAnimation, 0xC);
