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

MiniParser::MiniParser(char* arg1)
{
    unimplemented(arg1);
}

MiniParser::~MiniParser()
{
    unimplemented();
}

void MiniParser::Commentf(char const* arg1, ...)
{
    unimplemented(arg1);
}

void MiniParser::Errorf(char const* arg1, ...)
{
    unimplemented(arg1);
}

f32 MiniParser::FloatVal()
{
    return stub<thiscall_t<f32, MiniParser*>>(0x57CD80, this);
}

i32 MiniParser::GetCh()
{
    return stub<thiscall_t<i32, MiniParser*>>(0x57C810, this);
}

void MiniParser::Indent(i32 arg1)
{
    return stub<thiscall_t<void, MiniParser*, i32>>(0x57C880, this, arg1);
}

i64 MiniParser::Int64Val()
{
    return stub<thiscall_t<i64, MiniParser*>>(0x57CD40, this);
}

i32 MiniParser::IntVal()
{
    return stub<thiscall_t<i32, MiniParser*>>(0x57CD00, this);
}

void MiniParser::Match(i32 arg1)
{
    return stub<thiscall_t<void, MiniParser*, i32>>(0x57C8A0, this, arg1);
}

i32 MiniParser::NextToken()
{
    return stub<thiscall_t<i32, MiniParser*>>(0x57CB00, this);
}

void MiniParser::PlaceLabel(void* arg1)
{
    return stub<thiscall_t<void, MiniParser*, void*>>(0x57CA80, this, arg1);
}

void MiniParser::PlaceLabelRef(void* arg1)
{
    return stub<thiscall_t<void, MiniParser*, void*>>(0x57CAA0, this, arg1);
}

void MiniParser::PrintString(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, MiniParser*, char*, i32>>(0x57C6B0, this, arg1, arg2);
}

void MiniParser::Printf(char const* arg1, ...)
{
    unimplemented(arg1);
}

void MiniParser::PutBack(i32 arg1)
{
    return stub<thiscall_t<void, MiniParser*, i32>>(0x57CAD0, this, arg1);
}

void MiniParser::PutCh(i32 arg1)
{
    return stub<thiscall_t<void, MiniParser*, i32>>(0x57C830, this, arg1);
}

void* MiniParser::ResolveLabel(char* arg1, void** arg2)
{
    return stub<thiscall_t<void*, MiniParser*, char*, void**>>(0x57CAC0, this, arg1, arg2);
}

char* MiniParser::TokenName(i32 arg1)
{
    return stub<cdecl_t<char*, i32>>(0x57C8E0, arg1);
}
