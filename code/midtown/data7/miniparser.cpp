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

define_dummy_symbol(data7_miniparser);

#include "miniparser.h"

void MiniParser::Commentf(ARTS_FORMAT_STRING char const* format, ...)
{
    CStringBuffer<1024> buffer;

    std::va_list va;
    va_start(va, format);
    buffer.vsprintf(format, va);
    va_end(va);

    PutCh(';');
    PutCh(' ');

    PutString(buffer);
}

static i32 TotalParserErrors = 0;

void MiniParser::Errorf(ARTS_FORMAT_STRING char const* format, ...)
{
    ++TotalParserErrors;

    if (TotalParserErrors < 25)
    {
        CStringBuffer<1024> buffer;

        std::va_list va;
        va_start(va, format);
        buffer.vsprintf(format, va);
        va_end(va);

        ++error_count_;

        if (error_count_ < 10)
            ::Errorf("Parser(%s,%d): %s", name_.get(), current_line_, buffer.get());
        else if (error_count_ == 10)
            ::Errorf("This file sucks, change it!");
    }
    else if (TotalParserErrors == 25)
    {
        ::Errorf("Too many errors in metaclass files, ignoring all others");
    }
}

f32 MiniParser::FloatVal()
{
    if (i32 token = NextToken(); token != IntegerToken && token != FloatToken)
        Errorf("Expected integer or floating-point literal");

    return static_cast<f32>(std::atof(buffer_));
}

i32 MiniParser::GetCh()
{
    i32 ch = current_char_ = RawGetCh();

    if (ch == '\n')
        ++current_line_;

    return ch;
}

void MiniParser::Indent(i32 amount)
{
    indentation_ += amount;
}

i64 MiniParser::Int64Val()
{
    if (i32 token = NextToken(); token != IntegerToken && token != FloatToken)
        Errorf("Expected integer or floating-point literal");

    return std::atoll(buffer_);
}

i32 MiniParser::IntVal()
{
    if (i32 token = NextToken(); token != IntegerToken && token != FloatToken)
        Errorf("Expected integer or floating-point literal");

    return std::atoi(buffer_);
}

void MiniParser::Match(i32 expected)
{
    if (i32 token = NextToken(); token != expected)
        Errorf("Expected '%s', got '%s'", TokenName(expected), TokenName(token));
}

i32 MiniParser::NextToken()
{
    if (put_back_)
    {
        i32 result = put_back_;
        put_back_ = 0;
        return result;
    }

    i32 v = current_char_;

    while (true)
    {
        while (IsSpace(v))
            v = GetCh();

        if (v == EndToken)
            return '\0';

        if (v != ';')
            break;

        do
        {
            v = GetCh();
        } while (v != '\n' && v != EndToken);
    }

    if (v == '\'')
    {
        // TODO: Is this GetCh() needed? Should it be after the sprintf?
        GetCh();

        v = GetCh();
        arts_sprintf(buffer_, "%d", v);

        return IntegerToken;
    }

    if (v == '"')
    {
        i32 len = 0;

        while ((v = GetCh()) != '"')
        {
            if (v == '\n')
            {
                Errorf("Newline in string.");
                break;
            }

            if (v == '\\')
                v = GetCh();

            if (v == EndToken)
            {
                Errorf("EOF in string");
                break;
            }

            if (len < 255)
                buffer_[len++] = static_cast<char>(v);
        }

        // TODO: Is this GetCh() needed?
        GetCh();

        buffer_[len] = '\0';

        return StringToken;
    }

    i32 token = 0;

    if (v == '$')
    {
        token = LabelRefToken;
    }
    else if (v == ':')
    {
        token = LabelToken;
    }
    else if (v == '.')
    {
        token = FloatToken;
    }
    else if (v == '-' || IsDigit(v))
    {
        token = IntegerToken;
    }
    else if (v == '_' || IsLetter(v))
    {
        token = IdentToken;
    }
    else
    {
        buffer_[0] = static_cast<char>(v);
        buffer_[1] = '\0';

        GetCh();

        return v;
    }

    usize len = 0;

    while (v != ';' && !IsSpace(v))
    {
        if (len + 1 < ARTS_SIZE(buffer_))
            buffer_[len++] = static_cast<char>(v);

        v = GetCh();
    }

    buffer_[len] = '\0';

    return token;
}

void MiniParser::PlaceLabel(void* ptr)
{
    Printf(":%08zx", reinterpret_cast<usize>(ptr));
}

void MiniParser::PlaceLabelRef(void* ptr)
{
    Printf("$%08zx", reinterpret_cast<usize>(ptr));
}

void MiniParser::PrintString(const char* str, i32 len)
{
    if (str)
    {
        RawPutCh('"');

        if (len) // TODO: Is this actually a max length?
        {
            for (char v; (v = *str) != '\0'; ++str)
            {
                if (v < ' ' || v == '"')
                    RawPutCh('\\');

                RawPutCh(v);
            }
        }

        RawPutCh('"');
    }
    else
    {
        RawPutCh('0');
    }
}

void MiniParser::Printf(ARTS_FORMAT_STRING char const* format, ...)
{
    CStringBuffer<1024> buffer;

    std::va_list va;
    va_start(va, format);
    buffer.vsprintf(format, va);
    va_end(va);

    PutString(buffer);
}

void MiniParser::PutBack(i32 token)
{
    if (put_back_)
        Errorf("PutBack already called.");

    put_back_ = token;
}

void MiniParser::PutCh(i32 value)
{
    if (current_char_ == '\n')
    {
        for (i32 i = indentation_; i; --i)
            RawPutCh(' ');
    }

    current_char_ = value;

    RawPutCh(value);
}

void* MiniParser::ResolveLabel(char*, void**)
{
    return nullptr;
}

const char* MiniParser::TokenName(i32 token)
{
    switch (token)
    {
        case '\0':
        case EndToken: return "end-of-file";

        case '(': return "(";
        case ')': return ")";
        case '[': return "[";
        case '{': return "{";
        case '}': return "}";
        case ',': return ",";

        case IntegerToken: return "integer literal";
        case StringToken: return "string literal";
        case IdentToken: return "identifier";
        case LabelToken: return "label definition";
        case LabelRefToken: return "reference to label";
        case FloatToken: return "float literal";
    }

    static char buffer[2]; // FIXME: Static buffer

    buffer[0] = static_cast<char>(token);
    buffer[1] = '\0';

    return buffer;
}

void MiniParser::PutString(const char* str)
{
    for (; *str; ++str)
        PutCh(*str);
}
