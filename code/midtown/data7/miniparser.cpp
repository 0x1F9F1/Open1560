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

#include "miniparser.h"

MiniParser::MiniParser(char* arg1)
{
    unimplemented();
}

MiniParser::~MiniParser()
{
    unimplemented();
}

i32 MiniParser::RawGetCh()
{
    return stub<thiscall_t<i32, MiniParser*>>(0x - 400000_Offset, this);
}

void MiniParser::RawPutCh(i32 arg1)
{
    return stub<thiscall_t<void, MiniParser*, i32>>(0x - 400000_Offset, this, arg1);
}

void MiniParser::Commentf(char const* arg1, ...)
{
    unimplemented();
}

void MiniParser::Errorf(char const* arg1, ...)
{
    unimplemented();
}

f32 MiniParser::FloatVal()
{
    return stub<thiscall_t<f32, MiniParser*>>(0x17CD80_Offset, this);
}

i32 MiniParser::GetCh()
{
    return stub<thiscall_t<i32, MiniParser*>>(0x17C810_Offset, this);
}

void MiniParser::Indent(i32 arg1)
{
    return stub<thiscall_t<void, MiniParser*, i32>>(0x17C880_Offset, this, arg1);
}

i64 MiniParser::Int64Val()
{
    return stub<thiscall_t<i64, MiniParser*>>(0x17CD40_Offset, this);
}

i32 MiniParser::IntVal()
{
    return stub<thiscall_t<i32, MiniParser*>>(0x17CD00_Offset, this);
}

void MiniParser::Match(i32 arg1)
{
    return stub<thiscall_t<void, MiniParser*, i32>>(0x17C8A0_Offset, this, arg1);
}

i32 MiniParser::NextToken()
{
    return stub<thiscall_t<i32, MiniParser*>>(0x17CB00_Offset, this);
}

void MiniParser::PlaceLabel(void* arg1)
{
    return stub<thiscall_t<void, MiniParser*, void*>>(0x17CA80_Offset, this, arg1);
}

void MiniParser::PlaceLabelRef(void* arg1)
{
    return stub<thiscall_t<void, MiniParser*, void*>>(0x17CAA0_Offset, this, arg1);
}

void MiniParser::PrintString(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, MiniParser*, char*, i32>>(0x17C6B0_Offset, this, arg1, arg2);
}

void MiniParser::Printf(char const* arg1, ...)
{
    unimplemented();
}

void MiniParser::PutBack(i32 arg1)
{
    return stub<thiscall_t<void, MiniParser*, i32>>(0x17CAD0_Offset, this, arg1);
}

void MiniParser::PutCh(i32 arg1)
{
    return stub<thiscall_t<void, MiniParser*, i32>>(0x17C830_Offset, this, arg1);
}

void* MiniParser::ResolveLabel(char* arg1, void** arg2)
{
    return stub<thiscall_t<void*, MiniParser*, char*, void**>>(0x17CAC0_Offset, this, arg1, arg2);
}

char* MiniParser::TokenName(i32 arg1)
{
    return stub<cdecl_t<char*, i32>>(0x17C8E0_Offset, arg1);
}

define_dummy_symbol(data7_miniparser);
