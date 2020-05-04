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
    data7:args

    0x578C30 | public: __thiscall asArg::asArg(char,char *) | ??0asArg@@QAE@DPAD@Z
    0x578C80 | public: void __thiscall asArg::Print(char *) | ?Print@asArg@@QAEXPAD@Z
    0x578D80 | public: void __thiscall ArgSet::Print(char *) | ?Print@ArgSet@@QAEXPAD@Z
    0x578DD0 | public: void __thiscall ArgSet::ParseArgs(int,char * *) | ?ParseArgs@ArgSet@@QAEXHPAPAD@Z
    0x579010 | public: void __thiscall ArgSet::Usage(void) | ?Usage@ArgSet@@QAEXXZ
    0x90AEF0 | class ArgSet GBArgs | ?GBArgs@@3VArgSet@@A
*/

struct asArg
{
public:
    // 0x578C30 | ??0asArg@@QAE@DPAD@Z
    asArg(char arg1, char* arg2);

    // 0x578C80 | ?Print@asArg@@QAEXPAD@Z
    void Print(char* arg1);
};

check_size(asArg, 0x0);

class ArgSet
{
public:
    // 0x578DD0 | ?ParseArgs@ArgSet@@QAEXHPAPAD@Z
    void ParseArgs(i32 arg1, char** arg2);

    // 0x578D80 | ?Print@ArgSet@@QAEXPAD@Z
    void Print(char* arg1);

    // 0x579010 | ?Usage@ArgSet@@QAEXXZ
    void Usage();
};

check_size(ArgSet, 0x0);

// 0x90AEF0 | ?GBArgs@@3VArgSet@@A
inline extern_var(0x50AEF0_Offset, class ArgSet, GBArgs);
