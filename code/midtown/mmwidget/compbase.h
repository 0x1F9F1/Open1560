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
    mmwidget:compbase

    0x4BF2D0 | public: virtual void __thiscall mmCompBase::Reset(void) | ?Reset@mmCompBase@@UAEXXZ
    0x4BF2E0 | public: virtual void __thiscall mmCompBase::Update(void) | ?Update@mmCompBase@@UAEXXZ
*/

#include "arts7/node.h"

class mmCompBase : public asNode
{
    // const mmCompBase::`vftable' @ 0x61E6E8

public:
    // 0x4B4EC0 | ??_GmmCompBase@@UAEPAXI@Z
    // 0x4B4DF0 | ??1mmCompBase@@UAE@XZ | inline
    ARTS_IMPORT ~mmCompBase() override;

    // 0x4B4E00 | ?DisableBlt@mmCompBase@@UAEXXZ | inline
    ARTS_IMPORT virtual void DisableBlt();

    // 0x4B4E10 | ?SetBltXY@mmCompBase@@UAEXMM@Z | inline
    ARTS_IMPORT virtual void SetBltXY(f32 arg1, f32 arg2);

    // 0x4B4E70 | ?Action@mmCompBase@@UAEXTeqEvent@@MMH@Z | inline
    ARTS_IMPORT virtual void Action(union eqEvent arg1, f32 arg2, f32 arg3, i32 arg4);

    // 0x4B4E40 | ?Action@mmCompBase@@UAEXTeqEvent@@@Z | inline
    ARTS_IMPORT virtual void Action(union eqEvent arg1);

    // 0x4B4E50 | ?CaptureAction@mmCompBase@@UAEXTeqEvent@@@Z | inline
    ARTS_IMPORT virtual void CaptureAction(union eqEvent arg1);

    // 0x4B4E60 | ?Switch@mmCompBase@@UAEXH@Z | inline
    ARTS_IMPORT virtual void Switch(i32 arg1);

    // 0x4B4E80 | ?EvalMouseXY@mmCompBase@@UAEXMM@Z | inline
    ARTS_IMPORT virtual void EvalMouseXY(f32 arg1, f32 arg2);

    // 0x4B4E90 | ?Highlight@mmCompBase@@UAEXPAVmmTextNode@@H@Z | inline
    ARTS_IMPORT virtual void Highlight(class mmTextNode* arg1, i32 arg2);

    // 0x4B4EA0 | ?SetGeometry@mmCompBase@@UAEXMMMM@Z | inline
    ARTS_IMPORT virtual void SetGeometry(f32 arg1, f32 arg2, f32 arg3, f32 arg4);

    virtual void SetPosition(class mmTextNode* arg1, i32 arg2, f32 arg3) = 0;

    // 0x4BF2D0 | ?Reset@mmCompBase@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4BF2E0 | ?Update@mmCompBase@@UAEXXZ
    ARTS_IMPORT void Update() override;
};

check_size(mmCompBase, 0x48);
