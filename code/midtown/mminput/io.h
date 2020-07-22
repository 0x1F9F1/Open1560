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
    mminput:io

    0x4E4B60 | public: __thiscall mmIO::mmIO(void) | ??0mmIO@@QAE@XZ
    0x4E4B80 | public: __thiscall mmIO::~mmIO(void) | ??1mmIO@@QAE@XZ
    0x4E4B90 | public: void __thiscall mmIO::Clear(void) | ?Clear@mmIO@@QAEXXZ
    0x4E4BB0 | public: void __thiscall mmIO::Init(char *,int,long) | ?Init@mmIO@@QAEXPADHJ@Z
    0x4E4C10 | public: void __thiscall mmIO::InitDev(int,__int64,int,int,int) | ?InitDev@mmIO@@QAEXH_JHHH@Z
    0x4E4CC0 | public: void __thiscall mmIO::Assign(int,int) | ?Assign@mmIO@@QAEXHH@Z
    0x4E4D20 | public: int __thiscall mmIO::operator==(union eqEvent *) | ??8mmIO@@QAEHPATeqEvent@@@Z
    0x4E4D70 | public: void __thiscall mmIO::GetDescription(char *) | ?GetDescription@mmIO@@QAEXPAD@Z
    0x4E4DC0 | public: int __thiscall mmIO::Write(class Stream *) | ?Write@mmIO@@QAEHPAVStream@@@Z
    0x4E4E00 | public: int __thiscall mmIO::Read(class Stream *) | ?Read@mmIO@@QAEHPAVStream@@@Z
    0x4E4ED0 | public: int __thiscall mmIO::CompareComponent(int) | ?CompareComponent@mmIO@@QAEHH@Z
    0x4E4FA0 | public: void __thiscall mmIO::ForceSettingAcrossConfigs(int) | ?ForceSettingAcrossConfigs@mmIO@@QAEXH@Z
*/

class mmIO final
{
public:
    // 0x4E4B60 | ??0mmIO@@QAE@XZ
    ARTS_IMPORT mmIO();

    // 0x4E4A40 | ??_EmmIO@@QAEPAXI@Z | unused
    // 0x4E4B80 | ??1mmIO@@QAE@XZ
    ARTS_IMPORT ~mmIO();

    // 0x4E4D20 | ??8mmIO@@QAEHPATeqEvent@@@Z
    ARTS_IMPORT i32 operator==(union eqEvent* arg1);

    // 0x4E4CC0 | ?Assign@mmIO@@QAEXHH@Z
    ARTS_IMPORT void Assign(i32 arg1, i32 arg2);

    // 0x4E4B90 | ?Clear@mmIO@@QAEXXZ | unused
    ARTS_IMPORT void Clear();

    // 0x4E4ED0 | ?CompareComponent@mmIO@@QAEHH@Z
    ARTS_IMPORT i32 CompareComponent(i32 arg1);

    // 0x4E4FA0 | ?ForceSettingAcrossConfigs@mmIO@@QAEXH@Z
    ARTS_IMPORT void ForceSettingAcrossConfigs(i32 arg1);

    // 0x4E4D70 | ?GetDescription@mmIO@@QAEXPAD@Z
    ARTS_IMPORT void GetDescription(char* arg1);

    // 0x4E4BB0 | ?Init@mmIO@@QAEXPADHJ@Z
    ARTS_IMPORT void Init(char* arg1, i32 arg2, i32 arg3);

    // 0x4E4C10 | ?InitDev@mmIO@@QAEXH_JHHH@Z
    ARTS_IMPORT void InitDev(i32 arg1, i64 arg2, i32 arg3, i32 arg4, i32 arg5);

    // 0x4E4E00 | ?Read@mmIO@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 Read(class Stream* arg1);

    // 0x4E4DC0 | ?Write@mmIO@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 Write(class Stream* arg1);

    u8 gap0[0x1C];
};

check_size(mmIO, 0x1C);
