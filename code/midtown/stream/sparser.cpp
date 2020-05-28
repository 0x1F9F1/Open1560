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

define_dummy_symbol(stream_sparser);

#include "sparser.h"

#include "stream.h"

StreamMiniParser::StreamMiniParser(const char* name, class Stream* stream)
    : MiniParser(name)
    , stream_(stream)
{
    export_hook(0x561370);
}

StreamMiniParser::~StreamMiniParser()
{
    export_hook(0x5613A0);
}

i32 StreamMiniParser::RawGetCh()
{
    return stub<thiscall_t<i32, StreamMiniParser*>>(0x561440, this);
}

void StreamMiniParser::RawPutCh(i32 arg1)
{
    return stub<thiscall_t<void, StreamMiniParser*, i32>>(0x561400, this, arg1);
}

void StreamMiniParser::Load(class MetaClass* arg1, char* arg2, void* arg3)
{
    return stub<cdecl_t<void, class MetaClass*, char*, void*>>(0x561470, arg1, arg2, arg3);
}

void StreamMiniParser::Save(class MetaClass* arg1, char* arg2, void* arg3)
{
    return stub<cdecl_t<void, class MetaClass*, char*, void*>>(0x561520, arg1, arg2, arg3);
}
