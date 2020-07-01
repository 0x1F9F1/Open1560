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
    mmphysics:entity
*/

#include "arts7/node.h"

class mmPhysEntity : public asNode
{
    // const mmPhysEntity::`vftable' @ 0x61B8A0

public:
    // 0x453B40 | ??_GmmPhysEntity@@UAEPAXI@Z
    // 0x453B40 | ??_EmmPhysEntity@@UAEPAXI@Z
    // 0x42D510 | ??1mmPhysEntity@@UAE@XZ | inline
    ARTS_IMPORT ~mmPhysEntity() override = default;

    // 0x453B00 | ?PostUpdate@mmPhysEntity@@UAEXXZ | inline
    ARTS_EXPORT virtual void PostUpdate();

    // 0x453B10 | ?GetBound@mmPhysEntity@@UAEPAVasBound@@XZ | inline
    ARTS_EXPORT virtual class asBound* GetBound();

    // 0x453B20 | ?GetICS@mmPhysEntity@@UAEPAVasInertialCS@@XZ | inline
    ARTS_EXPORT virtual class asInertialCS* GetICS();

    // 0x453B30 | ?DetachMe@mmPhysEntity@@UAEXXZ | inline
    ARTS_EXPORT virtual void DetachMe();

    // 0x453AF0 | ?Update@mmPhysEntity@@UAEXXZ | inline
    ARTS_EXPORT void Update() override;
};

check_size(mmPhysEntity, 0x20);
