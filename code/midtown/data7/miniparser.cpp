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

MiniParser::MiniParser(const char* name)
    : name_(name)
{
    export_hook(0x57C5E0);
}

MiniParser::~MiniParser()
{
    export_hook(0x57C640);
}

void MiniParser::Commentf(char const* format, ...)
{
    export_hook(0x57C7B0);

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

void MiniParser::Errorf(char const* format, ...)
{
    export_hook(0x57C710);

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
            ::Errorf("Parser(%s,%d): %s", name_.get(), current_line_, buffer);
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
    export_hook(0x57CD80);

    if (i32 token = NextToken(); token != IntegerToken && token != FloatToken)
        Errorf("Expected integer or floating-point literal");

    return static_cast<f32>(std::atof(buffer_));
}

i32 MiniParser::GetCh()
{
    export_hook(0x57C810);

    i32 ch = current_char_ = RawGetCh();

    if (ch == '\n')
        ++current_line_;

    return ch;
}

void MiniParser::Indent(i32 amount)
{
    export_hook(0x57C880);

    indentation_ += amount;
}

i64 MiniParser::Int64Val()
{
    export_hook(0x57CD40);

    if (i32 token = NextToken(); token != IntegerToken && token != FloatToken)
        Errorf("Expected integer or floating-point literal");

    return std::atoll(buffer_);
}

i32 MiniParser::IntVal()
{
    export_hook(0x57CD00);

    if (i32 token = NextToken(); token != IntegerToken && token != FloatToken)
        Errorf("Expected integer or floating-point literal");

    return std::atoi(buffer_);
}

void MiniParser::Match(i32 expected)
{
    export_hook(0x57C8A0);

    if (i32 token = NextToken(); token != expected)
        Errorf("Expected '%s', got '%s'", TokenName(expected), TokenName(token));
}

i32 MiniParser::NextToken()
{
    export_hook(0x57CB00);

    if (put_back_)
    {
        i32 result = put_back_;
        put_back_ = 0;
        return result;
    }

    i32 v = current_char_;

    while (true)
    {
        while (v == '\t' || v == '\n' || v == '\r' || v == ' ')
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
    else if (v == '-' || (v >= '0' && v <= '9'))
    {
        token = IntegerToken;
    }
    else if ((v >= 'A' && v <= 'Z') || (v >= 'a' && v <= 'z') || (v == '_'))
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

    i32 len = 0;

    for (; v != '\t' && v != ' ' && v != '\n' && v != '\r' && v != ';'; v = GetCh())
    {
        if (len < 255)
            buffer_[len++] = static_cast<char>(v);
    }

    buffer_[len] = '\0';

    return token;
}

void MiniParser::PlaceLabel(void* ptr)
{
    export_hook(0x57CA80);

    Printf(":%08x", u32(ptr));
}

void MiniParser::PlaceLabelRef(void* ptr)
{
    export_hook(0x57CAA0);

    Printf("$%08x", u32(ptr));
}

void MiniParser::PrintString(const char* str, i32 len)
{
    export_hook(0x57C6B0);

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

void MiniParser::Printf(char const* format, ...)
{
    export_hook(0x57C660);

    CStringBuffer<1024> buffer;

    std::va_list va;
    va_start(va, format);
    buffer.vsprintf(format, va);
    va_end(va);

    PutString(buffer);
}

void MiniParser::PutBack(i32 token)
{
    export_hook(0x57CAD0);

    if (put_back_)
        Errorf("PutBack already called.");

    put_back_ = token;
}

void MiniParser::PutCh(i32 value)
{
    export_hook(0x57C830);

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
    export_hook(0x57CAC0);

    return nullptr;
}

static char TokenNameBuffer[2] {};

const char* MiniParser::TokenName(i32 token)
{
    export_hook(0x57C8E0);

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

    // TODO: This is a bad idea
    TokenNameBuffer[0] = static_cast<char>(token);

    return TokenNameBuffer;
}

void MiniParser::PutString(const char* str)
{
    for (; *str; ++str)
        PutCh(*str);
}
