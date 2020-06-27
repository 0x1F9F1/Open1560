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
    mmgame:wpobject

    0x430370 | public: __thiscall mmWaypointObject::mmWaypointObject(class Vector4 &,char *,int,float,int,float) | ??0mmWaypointObject@@QAE@AAVVector4@@PADHMHM@Z
    0x430510 | public: virtual __thiscall mmWaypointObject::~mmWaypointObject(void) | ??1mmWaypointObject@@UAE@XZ
    0x430520 | public: virtual void __thiscall mmWaypointObject::Reset(void) | ?Reset@mmWaypointObject@@UAEXXZ
    0x430530 | public: virtual void __thiscall mmWaypointObject::Update(void) | ?Update@mmWaypointObject@@UAEXXZ
    0x430540 | public: void __thiscall mmWaypointObject::Activate(void) | ?Activate@mmWaypointObject@@QAEXXZ
    0x430550 | public: void __thiscall mmWaypointObject::Deactivate(void) | ?Deactivate@mmWaypointObject@@QAEXXZ
    0x430560 | public: void __thiscall mmWaypointObject::SetHeading(float) | ?SetHeading@mmWaypointObject@@QAEXM@Z
    0x4305D0 | public: void __thiscall mmWaypointObject::Move(void) | ?Move@mmWaypointObject@@QAEXXZ
    0x430660 | public: virtual void * __thiscall mmWaypointObject::`scalar deleting destructor'(unsigned int) | ??_GmmWaypointObject@@UAEPAXI@Z
    0x430660 | public: virtual void * __thiscall mmWaypointObject::`vector deleting destructor'(unsigned int) | ??_EmmWaypointObject@@UAEPAXI@Z
    0x430690 | public: static void __cdecl mmInstance::operator delete(void *) | ??3mmInstance@@SAXPAX@Z
    0x61AFC0 | const mmWaypointObject::`vftable' | ??_7mmWaypointObject@@6B@
*/

#include "arts7/node.h"

class mmWaypointObject : public asNode
{
    // const mmWaypointObject::`vftable' @ 0x61AFC0

public:
    // 0x430370 | ??0mmWaypointObject@@QAE@AAVVector4@@PADHMHM@Z
    ARTS_IMPORT mmWaypointObject(class Vector4& arg1, char* arg2, i32 arg3, f32 arg4, i32 arg5, f32 arg6);

    // 0x430660 | ??_EmmWaypointObject@@UAEPAXI@Z
    // 0x430660 | ??_GmmWaypointObject@@UAEPAXI@Z
    // 0x430510 | ??1mmWaypointObject@@UAE@XZ
    ARTS_IMPORT ~mmWaypointObject() override = default;

    // 0x430540 | ?Activate@mmWaypointObject@@QAEXXZ
    ARTS_IMPORT void Activate();

    // 0x430550 | ?Deactivate@mmWaypointObject@@QAEXXZ
    ARTS_IMPORT void Deactivate();

    // 0x4305D0 | ?Move@mmWaypointObject@@QAEXXZ
    ARTS_IMPORT void Move();

    // 0x430520 | ?Reset@mmWaypointObject@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x430560 | ?SetHeading@mmWaypointObject@@QAEXM@Z
    ARTS_IMPORT void SetHeading(f32 arg1);

    // 0x430530 | ?Update@mmWaypointObject@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x2C];
};

check_size(mmWaypointObject, 0x4C);
