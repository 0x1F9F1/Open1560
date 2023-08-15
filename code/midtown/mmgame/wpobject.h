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
#include "vector7/vector3.h"

class mmWaypointObject final : public asNode
{
public:
    // ??0mmWaypointObject@@QAE@AAVVector4@@PADHMHM@Z
    ARTS_IMPORT mmWaypointObject(Vector4& arg1, char* arg2, i32 arg3, f32 arg4, i32 arg5, f32 arg6);

    // ??_EmmWaypointObject@@UAEPAXI@Z
    // ??_GmmWaypointObject@@UAEPAXI@Z
    // ??1mmWaypointObject@@UAE@XZ
    ARTS_IMPORT ~mmWaypointObject() override = default;

    // ?Activate@mmWaypointObject@@QAEXXZ
    ARTS_IMPORT void Activate();

    // ?Deactivate@mmWaypointObject@@QAEXXZ
    ARTS_IMPORT void Deactivate();

    // ?Move@mmWaypointObject@@QAEXXZ
    ARTS_IMPORT void Move();

    // ?Reset@mmWaypointObject@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetHeading@mmWaypointObject@@QAEXM@Z
    ARTS_IMPORT void SetHeading(f32 arg1);

    // ?Update@mmWaypointObject@@UAEXXZ
    ARTS_IMPORT void Update() override;

    b32 Initialized;
    i32 IdentMask;
    i32 HitId;
    i32* Inst;
    Vector3 Position;
    i32 Heading;
    i32 Type;
    i32 Radius;
    i32 RadiusSqr;
};

check_size(mmWaypointObject, 0x4C);