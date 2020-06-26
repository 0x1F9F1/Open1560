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

/*
    mmnetwork:netobject

    0x48B4A0 | public: __thiscall asNetObject::asNetObject(void) | ??0asNetObject@@QAE@XZ
    0x48B4C0 | public: virtual __thiscall asNetObject::~asNetObject(void) | ??1asNetObject@@UAE@XZ
    0x48B4D0 | public: virtual void __thiscall asNetObject::PositionUpdate(class Matrix34 *,class Vector3,float,float,float) | ?PositionUpdate@asNetObject@@UAEXPAVMatrix34@@VVector3@@MMM@Z
    0x48B4F0 | public: virtual void __thiscall asNetObject::Update(void) | ?Update@asNetObject@@UAEXXZ
    0x48B500 | public: virtual void * __thiscall asNetObject::`vector deleting destructor'(unsigned int) | ??_EasNetObject@@UAEPAXI@Z
    0x48B500 | public: virtual void * __thiscall asNetObject::`scalar deleting destructor'(unsigned int) | ??_GasNetObject@@UAEPAXI@Z
    0x61CB80 | const asNetObject::`vftable' | ??_7asNetObject@@6B@
*/

#include "arts7/node.h"

class asNetObject : public asNode
{
    // const asNetObject::`vftable' @ 0x61CB80

public:
    // 0x48B4A0 | ??0asNetObject@@QAE@XZ
    ARTS_IMPORT asNetObject();

    // 0x48B500 | ??_GasNetObject@@UAEPAXI@Z
    // 0x48B4C0 | ??1asNetObject@@UAE@XZ
    ARTS_IMPORT ~asNetObject() override;

    virtual void SetLocalData() = 0;

    // 0x48B4D0 | ?PositionUpdate@asNetObject@@UAEXPAVMatrix34@@VVector3@@MMM@Z
    ARTS_IMPORT virtual void PositionUpdate(class Matrix34* arg1, class Vector3 arg2, f32 arg3, f32 arg4, f32 arg5);

    // 0x48B4F0 | ?Update@asNetObject@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x8];
};

check_size(asNetObject, 0x28);
