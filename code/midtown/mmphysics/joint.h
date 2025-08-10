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

#include "arts7/node.h"

class asInertialCS;

class JointedStruct : public asNode
{
public:
    // ??1JointedStruct@@UAE@XZ | inline
    ARTS_EXPORT ~JointedStruct() = default;

    virtual void GetCMatrix(const asInertialCS* arg1, Matrix34& arg2, const Vector3& arg3) = 0;

    virtual void GetCMatrix(
        const asInertialCS* arg1, const asInertialCS* arg2, Matrix34& arg3, const Vector3& arg4) = 0;
};

check_size(JointedStruct, 0x20);
