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

struct bnSkeleton
{
public:
    // 0x514C40 | ??0bnSkeleton@@QAE@XZ
    bnSkeleton();

    // 0x514C50 | ??1bnSkeleton@@QAE@XZ | unused
    ~bnSkeleton();

    // 0x515080 | ?Attach@bnSkeleton@@QAEXQAVMatrix34@@@Z | unused
    void Attach(class Matrix34* const arg1);

    // 0x515070 | ?Draw@bnSkeleton@@QAEXXZ | unused
    void Draw();

    // 0x515100 | ?FindBone@bnSkeleton@@QAEPAVbnBone@@PADHD@Z
    class bnBone* FindBone(char* arg1, i32 arg2, char arg3);

    // 0x515220 | ?HowMany@bnSkeleton@@QAEHPADD@Z | unused
    i32 HowMany(char* arg1, char arg2);

    // 0x514C70 | ?Load@bnSkeleton@@QAEHPBD@Z
    i32 Load(char const* arg1);

    // 0x5150B0 | ?Pose@bnSkeleton@@QAEXPBVVector3@@@Z
    void Pose(class Vector3 const* arg1);

    // 0x514FA0 | ?Save@bnSkeleton@@QAEHPBD@Z | unused
    i32 Save(char const* arg1);

    // 0x515050 | ?Transform@bnSkeleton@@QAEXPAVMatrix34@@@Z
    void Transform(class Matrix34* arg1);
};

check_size(bnSkeleton, 0x0);

class bnAnimation
{
public:
    // 0x515260 | ?Load@bnAnimation@@QAEHPAD@Z
    i32 Load(char* arg1);

    // 0x5153F0 | ?Lookup@bnAnimation@@SAPAV1@PAD@Z | unused
    static class bnAnimation* Lookup(char* arg1);
};

check_size(bnAnimation, 0x0);
