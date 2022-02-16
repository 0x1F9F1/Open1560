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

class asBound;
class asInertialCS;

class mmPhysEntity : public asNode
{
public:
    // ??_GmmPhysEntity@@UAEPAXI@Z
    // ??_EmmPhysEntity@@UAEPAXI@Z
    // ??1mmPhysEntity@@UAE@XZ | inline
    ARTS_EXPORT ~mmPhysEntity() override = default;

    // ?PostUpdate@mmPhysEntity@@UAEXXZ | inline
    ARTS_EXPORT virtual void PostUpdate()
    {}

    // ?GetBound@mmPhysEntity@@UAEPAVasBound@@XZ | inline
    ARTS_EXPORT virtual asBound* GetBound()
    {
        return nullptr;
    }

    // ?GetICS@mmPhysEntity@@UAEPAVasInertialCS@@XZ | inline
    ARTS_EXPORT virtual asInertialCS* GetICS()
    {
        return nullptr;
    }

    // ?DetachMe@mmPhysEntity@@UAEXXZ | inline
    ARTS_EXPORT virtual void DetachMe()
    {}

    // ?Update@mmPhysEntity@@UAEXXZ | inline
    ARTS_EXPORT void Update() override
    {}
};

check_size(mmPhysEntity, 0x20);
