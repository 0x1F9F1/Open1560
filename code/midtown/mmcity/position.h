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
    mmcity:position

    0x491E00 | public: __thiscall mmPositions::mmPositions(void) | ??0mmPositions@@QAE@XZ
    0x491E10 | public: void __thiscall mmPositions::Init(int) | ?Init@mmPositions@@QAEXH@Z
    0x491E40 | public: int __thiscall mmPositions::Load(char *) | ?Load@mmPositions@@QAEHPAD@Z
    0x492010 | public: int __thiscall mmPositions::GetCount(void) | ?GetCount@mmPositions@@QAEHXZ
    0x492020 | public: class Vector4 & __thiscall mmPositions::GetVector4(int) | ?GetVector4@mmPositions@@QAEAAVVector4@@H@Z
    0x492050 | public: void __thiscall mmPositions::Dump(char *) | ?Dump@mmPositions@@QAEXPAD@Z
    0x4920F0 | public: int __thiscall mmPositions::Recall(int,class Matrix34 *,int *,char *) | ?Recall@mmPositions@@QAEHHPAVMatrix34@@PAHPAD@Z
    0x492180 | public: int __thiscall mmPositions::Register(class Vector4 &,int,int,int,int,char *) | ?Register@mmPositions@@QAEHAAVVector4@@HHHHPAD@Z
*/

struct mmPositions
{
public:
    // 0x491E00 | ??0mmPositions@@QAE@XZ
    mmPositions();

    // 0x492050 | ?Dump@mmPositions@@QAEXPAD@Z | unused
    void Dump(char* arg1);

    // 0x492010 | ?GetCount@mmPositions@@QAEHXZ
    i32 GetCount();

    // 0x492020 | ?GetVector4@mmPositions@@QAEAAVVector4@@H@Z | unused
    class Vector4& GetVector4(i32 arg1);

    // 0x491E10 | ?Init@mmPositions@@QAEXH@Z
    void Init(i32 arg1);

    // 0x491E40 | ?Load@mmPositions@@QAEHPAD@Z
    i32 Load(char* arg1);

    // 0x4920F0 | ?Recall@mmPositions@@QAEHHPAVMatrix34@@PAHPAD@Z
    i32 Recall(i32 arg1, class Matrix34* arg2, i32* arg3, char* arg4);

    // 0x492180 | ?Register@mmPositions@@QAEHAAVVector4@@HHHHPAD@Z
    i32 Register(class Vector4& arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5, char* arg6);
};

check_size(mmPositions, 0xC);
