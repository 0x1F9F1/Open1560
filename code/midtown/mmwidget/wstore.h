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
    mmwidget:wstore

    0x4ABE40 | public: __thiscall WArray::WArray(void) | ??0WArray@@QAE@XZ
    0x4ABE50 | public: __thiscall WArray::~WArray(void) | ??1WArray@@QAE@XZ
    0x4ABE60 | public: void __thiscall WArray::Init(int) | ?Init@WArray@@QAEXH@Z
    0x4ABEA0 | public: void __thiscall WArray::Write(char *) | ?Write@WArray@@QAEXPAD@Z
    0x4AC0C0 | public: void __thiscall WArray::DumpMenu(class Stream *,class UIMenu *) | ?DumpMenu@WArray@@QAEXPAVStream@@PAVUIMenu@@@Z
    0x4AC320 | public: void __thiscall WArray::Flush(void) | ?Flush@WArray@@QAEXXZ
    0x4AC330 | public: void __thiscall WArray::Read(char *) | ?Read@WArray@@QAEXPAD@Z
    0x4AC510 | public: void __thiscall WArray::AddWidgetData(int,int,class Vector4 &,char *) | ?AddWidgetData@WArray@@QAEXHHAAVVector4@@PAD@Z
    0x4AC590 | public: int __thiscall WArray::RetrieveWidgetData(int,int,float &,float &,float &,float &) | ?RetrieveWidgetData@WArray@@QAEHHHAAM000@Z
*/

struct WArray
{
public:
    // 0x4ABE40 | ??0WArray@@QAE@XZ
    ARTS_IMPORT WArray();

    // 0x4ABE50 | ??1WArray@@QAE@XZ
    ARTS_IMPORT ~WArray();

    // 0x4AC510 | ?AddWidgetData@WArray@@QAEXHHAAVVector4@@PAD@Z
    ARTS_IMPORT void AddWidgetData(i32 arg1, i32 arg2, class Vector4& arg3, char* arg4);

    // 0x4AC0C0 | ?DumpMenu@WArray@@QAEXPAVStream@@PAVUIMenu@@@Z
    ARTS_IMPORT void DumpMenu(class Stream* arg1, class UIMenu* arg2);

    // 0x4AC320 | ?Flush@WArray@@QAEXXZ | unused
    ARTS_EXPORT void Flush();

    // 0x4ABE60 | ?Init@WArray@@QAEXH@Z
    ARTS_IMPORT void Init(i32 arg1);

    // 0x4AC330 | ?Read@WArray@@QAEXPAD@Z
    ARTS_IMPORT void Read(char* arg1);

    // 0x4AC590 | ?RetrieveWidgetData@WArray@@QAEHHHAAM000@Z
    ARTS_IMPORT i32 RetrieveWidgetData(i32 arg1, i32 arg2, f32& arg3, f32& arg4, f32& arg5, f32& arg6);

    // 0x4ABEA0 | ?Write@WArray@@QAEXPAD@Z
    ARTS_IMPORT void Write(char* arg1);

    u8 gap0[0xC];
};

check_size(WArray, 0xC);
