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

define_dummy_symbol(vector7_vector3);

#include "vector3.h"

#include "data7/metadefine.h"
#include "data7/metatype.h"
#include "data7/miniparser.h"

struct Vector3Type final : MetaType
{
    // const Vector3Type::`vftable'

public:
    // ?Delete@Vector3Type@@UAEXPAXH@Z
    ARTS_EXPORT void Delete(void* ptr, isize len) override
    {
        MetaDelete<Vector3>(ptr, len);
    }

    // ?Load@Vector3Type@@UAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Load(class MiniParser* parser, void* ptr) override
    {
        Vector3* val = static_cast<Vector3*>(ptr);

        val->x = parser->FloatVal();
        val->y = parser->FloatVal();
        val->z = parser->FloatVal();
    }

    // ?New@Vector3Type@@UAEPAXH@Z
    ARTS_EXPORT void* New(isize count) override
    {
        return MetaNew<Vector3>(count);
    }

    // ?Save@Vector3Type@@UAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Save(class MiniParser* parser, void* ptr) override
    {
        Vector3* val = static_cast<Vector3*>(ptr);

        parser->Printf("%.4g %.4g %.4g", val->x, val->y, val->z);
    }

    // ?SizeOf@Vector3Type@@UAEIXZ
    ARTS_EXPORT usize SizeOf() override
    {
        return sizeof(Vector3);
    }
};

check_size(Vector3Type, 0x4);

static const Vector3Type Vector3Inst;

template <>
const MetaType* CreateMetaType_<Vector3>()
{
    return &Vector3Inst;
}
