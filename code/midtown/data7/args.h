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
    // ??0asArg@@QAE@DPAD@Z
    ARTS_EXPORT asArg(char flag, const char* usage);

    // ?Print@asArg@@QAEXPAD@Z
    ARTS_EXPORT void Print(const char* name);

    b32 Found {false};
    char Flag {0};
    char* Usage {};
    int iValues[5] {};
    float fValues[5] {};
    char* sValues[5] {};
};

check_size(asArg, 0x48);

class ArgSet
{
public:
    ~ArgSet();

    // ?ParseArgs@ArgSet@@QAEXHPAPAD@Z
    ARTS_EXPORT void ParseArgs(i32 argc, const char** argv);

    // ?Print@ArgSet@@QAEXPAD@Z | unused
    ARTS_EXPORT void Print(const char* title);

    // ?Usage@ArgSet@@QAEXXZ
    ARTS_EXPORT void Usage();

    asArg* operator[](char flag);

    asArg* Args[128] {};
    void* UsageText {nullptr};
    char* Path {nullptr};
};

check_size(ArgSet, 0x208);

// ?GBArgs@@3VArgSet@@A
ARTS_IMPORT extern class ArgSet GBArgs;

inline asArg* ArgSet::operator[](char flag)
{
    asArg* result = Args[static_cast<u8>(flag & 0x7F)];

    return (result && result->Found) ? result : nullptr;
}
