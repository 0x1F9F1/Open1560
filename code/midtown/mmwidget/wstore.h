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

class Stream;
class UIMenu;

class WArray
{
public:
    // ??0WArray@@QAE@XZ
    ARTS_IMPORT WArray();

    // ??1WArray@@QAE@XZ
    ARTS_IMPORT ~WArray();

    // ?AddWidgetData@WArray@@QAEXHHAAVVector4@@PAD@Z
    ARTS_IMPORT void AddWidgetData(i32 arg1, i32 arg2, Vector4& arg3, char* arg4);

    // ?DumpMenu@WArray@@QAEXPAVStream@@PAVUIMenu@@@Z
    ARTS_IMPORT void DumpMenu(Stream* arg1, UIMenu* arg2);

    // ?Flush@WArray@@QAEXXZ | unused
    ARTS_EXPORT void Flush();

    // ?Init@WArray@@QAEXH@Z
    ARTS_IMPORT void Init(i32 arg1);

    // ?Read@WArray@@QAEXPAD@Z
    ARTS_EXPORT void Read(char* name);

    // ?RetrieveWidgetData@WArray@@QAEHHHAAM000@Z
    ARTS_IMPORT i32 RetrieveWidgetData(i32 arg1, i32 arg2, f32& arg3, f32& arg4, f32& arg5, f32& arg6);

    // ?Write@WArray@@QAEXPAD@Z
    ARTS_IMPORT void Write(char* arg1);

    u8 gap0[0xC];
};

check_size(WArray, 0xC);
