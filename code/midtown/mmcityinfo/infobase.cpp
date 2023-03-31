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

define_dummy_symbol(mmcityinfo_infobase);

#include "infobase.h"

#include "data7/metadefine.h"
#include "stream/sparser.h"
#include "stream/stream.h"

b32 mmInfoBase::Load(const char* path)
{
    Ptr<Stream> input {arts_fopen(path, "r")};

    if (!input)
    {
        Errorf("mmInfoBase::Load(%s) failed.", path);
        return false;
    }

    StreamMiniParser parser {path, as_owner std::move(input)};

    GetClass()->Load(&parser, this);

    return true;
}

b32 mmInfoBase::Save(const char* path)
{
    Ptr<Stream> output {arts_fopen(path, "w")};

    if (!output)
    {
        Errorf("mmInfoBase::Save(%s) failed.", path);
        return false;
    }

    StreamMiniParser parser {path, as_owner std::move(output)};

    GetClass()->Save(&parser, this);

    return true;
}

void mmInfoBase::SetIOPath(const char* path)
{
    arts_strcpy(FilePath, path);
}

META_DEFINE_CHILD("mmInfoBase", mmInfoBase, Base)
{}
