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

define_dummy_symbol(stream_token);

#include "token.h"

Tokenizer::Tokenizer(char const* arg1, class Stream* arg2)
{
    unimplemented(arg1, arg2);
}

f32 Tokenizer::GetFloat()
{
    return stub<thiscall_t<f32, Tokenizer*>>(0x161770_Offset, this);
}

i32 Tokenizer::GetInt()
{
    return stub<thiscall_t<i32, Tokenizer*>>(0x161710_Offset, this);
}

i32 Tokenizer::GetToken(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, Tokenizer*, char*, i32>>(0x161600_Offset, this, arg1, arg2);
}

void Tokenizer::IgnoreToken()
{
    return stub<thiscall_t<void, Tokenizer*>>(0x1617D0_Offset, this);
}

void Tokenizer::MatchToken(char* arg1)
{
    return stub<thiscall_t<void, Tokenizer*, char*>>(0x161690_Offset, this, arg1);
}
