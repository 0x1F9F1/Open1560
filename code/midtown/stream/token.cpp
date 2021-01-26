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

#include "stream.h"

Tokenizer::Tokenizer(char const* name, Stream* input)
    : name_(name)
    , input_(input)
{}

f32 Tokenizer::GetFloat()
{
    char buffer[32];

    if (GetToken(buffer, ARTS_SIZE(buffer)))
    {
        if ((buffer[0] == '-') || (buffer[0] == '.') || IsDigit(buffer[0]))
            return static_cast<f32>(std::atof(buffer));
    }

    Errorf("%s(%d): Expected float.", name_, current_line_);

    return 0.0f;
}

i32 Tokenizer::GetInt()
{
    char buffer[32];

    if (GetToken(buffer, ARTS_SIZE(buffer)))
    {
        if ((buffer[0] == '-') || IsDigit(buffer[0]))
            return static_cast<i32>(std::atoi(buffer));
    }

    Errorf("%s(%d): Expected integer.", name_, current_line_);

    return 0;
}

i32 Tokenizer::GetToken(char* buffer, isize buffer_len)
{
    while (IsSpace(current_char_))
    {
        current_char_ = input_->GetCh();

        if (current_char_ == '\n')
            ++current_line_;
    }

    i32 count = 0;

    while ((current_char_ != -1) && !IsSpace(current_char_))
    {
        if (count + 1 < buffer_len)
            buffer[count++] = static_cast<char>(current_char_);

        current_char_ = input_->GetCh();
    }

    buffer[count] = 0;

    return count;
}

void Tokenizer::IgnoreToken()
{
    char buffer[1];

    GetToken(buffer, ARTS_SIZE(buffer));
}

void Tokenizer::MatchToken(const char* value)
{
    char buffer[64];
    buffer[0] = 0;

    if (GetToken(buffer, ARTS_SIZE(buffer)))
    {
        if (!std::strcmp(value, buffer))
            return;
    }

    Errorf("%s(%d): Expected '%s', got '%s'.", name_, current_line_, value, buffer);
}
