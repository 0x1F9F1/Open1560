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
    mmwidget:mstore

    0x4AB7B0 | public: __thiscall MArray::MArray(void) | ??0MArray@@QAE@XZ
    0x4AB7C0 | public: __thiscall MArray::~MArray(void) | ??1MArray@@QAE@XZ
    0x4AB7D0 | public: void __thiscall MArray::Init(int) | ?Init@MArray@@QAEXH@Z
    0x4AB810 | public: void __thiscall MArray::Write(char *) | ?Write@MArray@@QAEXPAD@Z
    0x4ABB20 | public: void __thiscall MArray::Flush(void) | ?Flush@MArray@@QAEXXZ
    0x4ABB30 | public: void __thiscall MArray::Read(char *) | ?Read@MArray@@QAEXPAD@Z
    0x4ABCF0 | public: void __thiscall MArray::AddMenuData(int,class Vector4 &,char *) | ?AddMenuData@MArray@@QAEXHAAVVector4@@PAD@Z
    0x4ABD60 | public: int __thiscall MArray::RetrieveMenuData(int,float &,float &,float &,float &) | ?RetrieveMenuData@MArray@@QAEHHAAM000@Z
*/

struct MArray
{
public:
    // 0x4AB7B0 | ??0MArray@@QAE@XZ
    ARTS_IMPORT MArray();

    // 0x4AB7C0 | ??1MArray@@QAE@XZ | unused
    ARTS_IMPORT ~MArray();

    // 0x4ABCF0 | ?AddMenuData@MArray@@QAEXHAAVVector4@@PAD@Z
    ARTS_IMPORT void AddMenuData(i32 arg1, class Vector4& arg2, char* arg3);

    // 0x4ABB20 | ?Flush@MArray@@QAEXXZ | unused
    ARTS_IMPORT void Flush();

    // 0x4AB7D0 | ?Init@MArray@@QAEXH@Z
    ARTS_IMPORT void Init(i32 arg1);

    // 0x4ABB30 | ?Read@MArray@@QAEXPAD@Z
    ARTS_IMPORT void Read(char* arg1);

    // 0x4ABD60 | ?RetrieveMenuData@MArray@@QAEHHAAM000@Z | unused
    ARTS_IMPORT i32 RetrieveMenuData(i32 arg1, f32& arg2, f32& arg3, f32& arg4, f32& arg5);

    // 0x4AB810 | ?Write@MArray@@QAEXPAD@Z
    ARTS_IMPORT void Write(char* arg1);
};

check_size(MArray, 0xC);
