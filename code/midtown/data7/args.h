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

struct asArg
{
public:
    // ??0asArg@@QAE@DPAD@Z
    asArg(char flag, const char* usage);

    // ?Print@asArg@@QAEXPAD@Z
    void Print(const char* name);

    b32 Found {};
    char Flag {};
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
    void ParseArgs(i32 argc, const char** argv);

    // ?Print@ArgSet@@QAEXPAD@Z | unused
    void Print(const char* title);

    // ?Usage@ArgSet@@QAEXXZ
    void Usage();

    asArg* operator[](char flag);

    asArg* Args[128] {};
    void* UsageText {};
    char* Path {};
};

check_size(ArgSet, 0x208);

// ?GBArgs@@3VArgSet@@A
ARTS_EXPORT extern ArgSet GBArgs;

inline asArg* ArgSet::operator[](char flag)
{
    asArg* result = Args[static_cast<u8>(flag & 0x7F)];

    return (result && result->Found) ? result : nullptr;
}
