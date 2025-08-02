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

class BaseCamCS : public asNode
{
public:
    // ??0BaseCamCS@@QAE@XZ
    ARTS_IMPORT BaseCamCS();

    // ??_EBaseCamCS@@UAEPAXI@Z
    // ??1BaseCamCS@@UAE@XZ
    ARTS_EXPORT ~BaseCamCS() override = default;

    // ?MakeActive@BaseCamCS@@UAEXXZ | inline
    ARTS_EXPORT virtual void MakeActive();

    // ?UpdateInput@BaseCamCS@@UAEXXZ | inline
    ARTS_EXPORT virtual void UpdateInput();

    // ?ForceMatrixDelta@BaseCamCS@@UAEXABVVector3@@@Z
    ARTS_IMPORT virtual void ForceMatrixDelta(const Vector3& arg1);

    // ?SetST@BaseCamCS@@UAEXPAM@Z | inline
    ARTS_EXPORT virtual void SetST(f32* arg1);

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@BaseCamCS@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?AfterLoad@BaseCamCS@@UAEXXZ
    ARTS_IMPORT void AfterLoad() override;

    // ?GetClass@BaseCamCS@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?IsViewCSInTransition@BaseCamCS@@QAEHXZ
    ARTS_IMPORT i32 IsViewCSInTransition();

    // ?UpdateView@BaseCamCS@@QAEXXZ
    ARTS_IMPORT void UpdateView();

    // ?DeclareFields@BaseCamCS@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x7C];
};

check_size(BaseCamCS, 0x9C);
