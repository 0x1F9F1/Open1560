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
    agiworld:bone

    0x516DE0 | public: __thiscall bnBone::bnBone(void) | ??0bnBone@@QAE@XZ
    0x516E40 | public: void __thiscall bnBone::AddChild(class bnBone *) | ?AddChild@bnBone@@QAEXPAV1@@Z
    0x516E80 | public: int __thiscall bnBone::Load(class Tokenizer *,class bnBone * *) | ?Load@bnBone@@QAEHPAVTokenizer@@PAPAV1@@Z
    0x516F70 | public: void __thiscall bnBone::Transform(class Matrix34 *) | ?Transform@bnBone@@QAEXPAVMatrix34@@@Z
    0x516FC0 | public: void __thiscall bnBone::Draw(void) | ?Draw@bnBone@@QAEXXZ
    0x516FD0 | public: void __thiscall bnBone::Attach(class Matrix34 * const,int &) | ?Attach@bnBone@@QAEXQAVMatrix34@@AAH@Z
    0x517030 | public: void __thiscall bnBone::Pose(class Vector3 const *,int &) | ?Pose@bnBone@@QAEXPBVVector3@@AAH@Z
    0x517090 | void __cdecl Matrix34__FromEulersXZY(class Matrix34 &,class Vector3 const &) | ?Matrix34__FromEulersXZY@@YAXAAVMatrix34@@ABVVector3@@@Z
*/

class bnBone
{
public:
    // 0x516DE0 | ??0bnBone@@QAE@XZ
    bnBone();

    // 0x516E40 | ?AddChild@bnBone@@QAEXPAV1@@Z
    void AddChild(class bnBone* arg1);

    // 0x516FD0 | ?Attach@bnBone@@QAEXQAVMatrix34@@AAH@Z
    void Attach(class Matrix34* const arg1, i32& arg2);

    // 0x516FC0 | ?Draw@bnBone@@QAEXXZ
    void Draw();

    // 0x516E80 | ?Load@bnBone@@QAEHPAVTokenizer@@PAPAV1@@Z
    i32 Load(class Tokenizer* arg1, class bnBone** arg2);

    // 0x517030 | ?Pose@bnBone@@QAEXPBVVector3@@AAH@Z
    void Pose(class Vector3 const* arg1, i32& arg2);

    // 0x516F70 | ?Transform@bnBone@@QAEXPAVMatrix34@@@Z
    void Transform(class Matrix34* arg1);
};

check_size(bnBone, 0x0);
