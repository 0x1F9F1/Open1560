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

#include "data7/hash.h"
#include "stream/stream.h"

constexpr i32 agiLibMax = 2048;

template <typename Param, typename Def>
class agiLib
{
public:
    agiLib(const char* name)
        : lookup_(name)
    {}

    ~agiLib()
    {
        Kill();
    }

    void Init(i32 count)
    {
        ArAssert(count <= agiLibMax, "Too many values");

        lookup_.Init(64);

        for (i32 i = 0; i < count; ++i)
        {
            params_[i] = new Param();
            defs_[i] = nullptr;
        }
    }

    void Kill()
    {
        while (count_)
        {
            --count_;

            delete params_[count_];
            params_[count_] = nullptr;

            if (Def* def = defs_[count_])
            {
                def->Release();
                defs_[count_] = nullptr;
            }
        }

        lookup_.Kill();
    }

    i32 Lookup(const char* name)
    {
        char buffer[64];
        arts_strcpy(buffer, name);
        arts_strupr(buffer);
        return reinterpret_cast<i32>(lookup_.Access(buffer));
    }

    i32 Add(Param& param)
    {
        i32 index = Lookup(param.Name);

        if (index == 0)
        {
            ArAssert(count_ < agiLibMax, "Too many values");

            params_[count_] = new Param(param);
            lookup_.Insert(param.Name, reinterpret_cast<void*>(count_ + 1));
            defs_[count_] = nullptr;

            index = count_ + 1;
            ++count_;
        }

        return index;
    }

    i32 Add(Param& param, i32 count)
    {
        i32 index = Lookup(param.Name);

        if (index == 0)
        {
            ArAssert(count_ + count <= agiLibMax, "Too many values");

            lookup_.Insert(param.Name, reinterpret_cast<void*>(count_ + 1));

            for (i32 i = 0; i < count; ++i)
            {
                params_[count_ + i] = new Param(param);
                defs_[count_ + i] = nullptr;
            }

            index = count_ + 1;
            count_ += count;
        }

        return index;
    }

    void Load(Stream* input)
    {
        Kill();

        count_ = static_cast<i32>(input->GetLong());
        Init(count_);

        for (i32 i = 0; i < count_; ++i)
        {
            params_[i]->Load(input);
            lookup_.Insert(params_[i]->Name, reinterpret_cast<void*>(i + 1));
        }
    }

    void Save(Stream* output)
    {
        output->Put(static_cast<u32>(count_));

        for (i32 i = 0; i < count_; ++i)
            params_[i]->Save(output);
    }

    Param* GetParam(i32 index)
    {
        ArAssert(index > 0 && index - 1 < count_, "Invalid index");
        return params_[index - 1];
    }

    Def** GetDef(i32 index)
    {
        // NOTE: <= to allow access during Kill()
        ArAssert(index > 0 && index - 1 <= count_, "Invalid index");
        return &defs_[index - 1];
    }

private:
    Param* params_[agiLibMax] {};
    Def* defs_[agiLibMax] {};
    HashTable lookup_ {};
    i32 count_ {0};
};
