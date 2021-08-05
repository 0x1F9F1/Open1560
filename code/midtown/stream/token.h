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
    stream:token

    0x5615D0 | public: __thiscall Tokenizer::Tokenizer(char const *,class Stream *) | ??0Tokenizer@@QAE@PBDPAVStream@@@Z
    0x561600 | public: int __thiscall Tokenizer::GetToken(char *,int) | ?GetToken@Tokenizer@@QAEHPADH@Z
    0x561690 | public: void __thiscall Tokenizer::MatchToken(char *) | ?MatchToken@Tokenizer@@QAEXPAD@Z
    0x561710 | public: int __thiscall Tokenizer::GetInt(void) | ?GetInt@Tokenizer@@QAEHXZ
    0x561770 | public: float __thiscall Tokenizer::GetFloat(void) | ?GetFloat@Tokenizer@@QAEMXZ
    0x5617D0 | public: void __thiscall Tokenizer::IgnoreToken(void) | ?IgnoreToken@Tokenizer@@QAEXXZ
*/

class Tokenizer
{
public:
    // ??0Tokenizer@@QAE@PBDPAVStream@@@Z
    ARTS_EXPORT Tokenizer(char const* name, class Stream* input);

    // ?GetFloat@Tokenizer@@QAEMXZ
    ARTS_EXPORT f32 GetFloat();

    // ?GetInt@Tokenizer@@QAEHXZ
    ARTS_EXPORT i32 GetInt();

    // ?GetToken@Tokenizer@@QAEHPADH@Z
    ARTS_EXPORT i32 GetToken(char* buffer, isize buffer_len);

    // ?IgnoreToken@Tokenizer@@QAEXXZ
    ARTS_EXPORT void IgnoreToken();

    // ?MatchToken@Tokenizer@@QAEXPAD@Z
    ARTS_EXPORT void MatchToken(const char* value);

private:
    const char* name_ {nullptr};
    i32 current_line_ {1};
    Stream* input_ {nullptr};
    i32 current_char_ {' '};
};

check_size(Tokenizer, 0x10);
