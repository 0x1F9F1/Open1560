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

#include "data7/metaclass.h"
#include "stream.h"

StreamMiniParser::StreamMiniParser(const char* name, Owner<Stream> stream)
    : MiniParser(name)
    , stream_(std::move(stream))
{}

StreamMiniParser::~StreamMiniParser() = default;

i32 StreamMiniParser::RawGetCh()
{
    return stream_->GetCh();
}

void StreamMiniParser::RawPutCh(i32 value)
{
    stream_->PutCh(static_cast<u8>(value));
}

void StreamMiniParser::Load(MetaClass* cls, const char* path, void* ptr)
{
    Ptr<Stream> input {arts_fopen(path, "r")};

    if (input)
    {
        StreamMiniParser parser(path, AsOwner(input));

        cls->Load(&parser, ptr);

        if (i32 errors = parser.GetErrorCount())
            ::Errorf("%d error(s) during load of '%s'", errors, path);
    }
    else
    {
        ::Errorf("Load: '%s' not found.", path);
    }
}

void StreamMiniParser::Save(MetaClass* cls, const char* path, void* ptr)
{
    Ptr<Stream> output {arts_fopen(path, "w")};

    if (output)
    {
        StreamMiniParser parser(path, AsOwner(output));

        cls->Save(&parser, ptr);

        if (i32 errors = parser.GetErrorCount(); errors != 0)
            ::Errorf("%d error(s) during save of '%s'", errors, path);
    }
    else
    {
        ::Errorf("Save: Cannot create '%s'.", path);
    }
}
