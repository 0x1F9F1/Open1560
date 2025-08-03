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

#include "metadeclare.h"

class Base
{
public:
    // ??1Base@@UAE@XZ
    ARTS_EXPORT virtual ~Base() = 0;

    // ?GetClass@Base@@UAEPAVMetaClass@@XZ
    ARTS_EXPORT virtual MetaClass* GetClass();

    // ?GetTypeNameV@Base@@UAEPADXZ
    virtual const char* GetTypeNameV();

    // ?BeforeSave@Base@@UAEXXZ
    ARTS_EXPORT virtual void BeforeSave();

    // ?AfterLoad@Base@@UAEXXZ
    ARTS_EXPORT virtual void AfterLoad();

    // ?GetTypeName@Base@@QAEPADXZ
    const char* GetTypeName();

    META_DECLARE;
};

check_size(Base, 0x4);

inline Base::~Base() = default;
