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
    agiworld:skeleton

    0x514C40 | public: __thiscall bnSkeleton::bnSkeleton(void) | ??0bnSkeleton@@QAE@XZ
    0x514C50 | public: __thiscall bnSkeleton::~bnSkeleton(void) | ??1bnSkeleton@@QAE@XZ
    0x514C70 | public: int __thiscall bnSkeleton::Load(char const *) | ?Load@bnSkeleton@@QAEHPBD@Z
    0x514FA0 | public: int __thiscall bnSkeleton::Save(char const *) | ?Save@bnSkeleton@@QAEHPBD@Z
    0x515050 | public: void __thiscall bnSkeleton::Transform(class Matrix34 *) | ?Transform@bnSkeleton@@QAEXPAVMatrix34@@@Z
    0x515070 | public: void __thiscall bnSkeleton::Draw(void) | ?Draw@bnSkeleton@@QAEXXZ
    0x515080 | public: void __thiscall bnSkeleton::Attach(class Matrix34 * const) | ?Attach@bnSkeleton@@QAEXQAVMatrix34@@@Z
    0x5150B0 | public: void __thiscall bnSkeleton::Pose(class Vector3 const *) | ?Pose@bnSkeleton@@QAEXPBVVector3@@@Z
    0x515100 | public: class bnBone * __thiscall bnSkeleton::FindBone(char *,int,char) | ?FindBone@bnSkeleton@@QAEPAVbnBone@@PADHD@Z
    0x515220 | public: int __thiscall bnSkeleton::HowMany(char *,char) | ?HowMany@bnSkeleton@@QAEHPADD@Z
    0x515260 | public: int __thiscall bnAnimation::Load(char *) | ?Load@bnAnimation@@QAEHPAD@Z
    0x5153F0 | public: static class bnAnimation * __cdecl bnAnimation::Lookup(char *) | ?Lookup@bnAnimation@@SAPAV1@PAD@Z
*/

class bnBone;

struct bnSkeleton
{
public:
    // ??0bnSkeleton@@QAE@XZ
    ARTS_IMPORT bnSkeleton();

    // ??1bnSkeleton@@QAE@XZ | unused
    ARTS_IMPORT ~bnSkeleton();

    // ?Attach@bnSkeleton@@QAEXQAVMatrix34@@@Z | unused
    ARTS_IMPORT void Attach(Matrix34* const arg1);

    // ?Draw@bnSkeleton@@QAEXXZ | unused
    ARTS_IMPORT void Draw();

    // ?FindBone@bnSkeleton@@QAEPAVbnBone@@PADHD@Z
    ARTS_IMPORT bnBone* FindBone(char* arg1, i32 arg2, char arg3);

    // ?HowMany@bnSkeleton@@QAEHPADD@Z | unused
    ARTS_IMPORT i32 HowMany(char* arg1, char arg2);

    // ?Load@bnSkeleton@@QAEHPBD@Z
    ARTS_IMPORT i32 Load(char const* arg1);

    // ?Pose@bnSkeleton@@QAEXPBVVector3@@@Z
    ARTS_IMPORT void Pose(Vector3 const* arg1);

    // ?Save@bnSkeleton@@QAEHPBD@Z | unused
    ARTS_IMPORT i32 Save(char const* arg1);

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

    // ?Lookup@bnAnimation@@SAPAV1@PAD@Z | unused
    ARTS_IMPORT static bnAnimation* Lookup(char* arg1);

    u8 gap0[0xC];
};

check_size(bnAnimation, 0xC);
