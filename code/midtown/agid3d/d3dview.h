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
    agid3d:d3dview

    0x5332D0 | public: __thiscall agiD3DViewport::agiD3DViewport(class agiPipeline *) | ??0agiD3DViewport@@QAE@PAVagiPipeline@@@Z
    0x533300 | public: virtual int __thiscall agiD3DViewport::BeginGfx(void) | ?BeginGfx@agiD3DViewport@@UAEHXZ
    0x533330 | public: virtual void __thiscall agiD3DViewport::EndGfx(void) | ?EndGfx@agiD3DViewport@@UAEXXZ
    0x533340 | public: virtual __thiscall agiD3DViewport::~agiD3DViewport(void) | ??1agiD3DViewport@@UAE@XZ
    0x533350 | public: virtual void __thiscall agiD3DViewport::Activate(void) | ?Activate@agiD3DViewport@@UAEXXZ
    0x533410 | public: virtual void __thiscall agiD3DViewport::SetBackground(class Vector3 &) | ?SetBackground@agiD3DViewport@@UAEXAAVVector3@@@Z
    0x533460 | public: virtual void __thiscall agiD3DViewport::Clear(int) | ?Clear@agiD3DViewport@@UAEXH@Z
    0x533530 | public: virtual void * __thiscall agiD3DViewport::`scalar deleting destructor'(unsigned int) | ??_GagiD3DViewport@@UAEPAXI@Z
    0x533530 | public: virtual void * __thiscall agiD3DViewport::`vector deleting destructor'(unsigned int) | ??_EagiD3DViewport@@UAEPAXI@Z
    0x621130 | const agiD3DViewport::`vftable' | ??_7agiD3DViewport@@6B@
*/

#include "agi/viewport.h"

class agiD3DViewport : public agiViewport
{
    // const agiD3DViewport::`vftable' @ 0x621130

public:
    // 0x5332D0 | ??0agiD3DViewport@@QAE@PAVagiPipeline@@@Z
    agiD3DViewport(class agiPipeline* arg1);

    // 0x533530 | ??_EagiD3DViewport@@UAEPAXI@Z
    // 0x533340 | ??1agiD3DViewport@@UAE@XZ
    ~agiD3DViewport() override;

    // 0x533350 | ?Activate@agiD3DViewport@@UAEXXZ
    void Activate() override;

    // 0x533300 | ?BeginGfx@agiD3DViewport@@UAEHXZ
    i32 BeginGfx() override;

    // 0x533460 | ?Clear@agiD3DViewport@@UAEXH@Z
    void Clear(i32 arg1) override;

    // 0x533330 | ?EndGfx@agiD3DViewport@@UAEXXZ
    void EndGfx() override;

    // 0x533410 | ?SetBackground@agiD3DViewport@@UAEXAAVVector3@@@Z
    void SetBackground(class Vector3& arg1) override;
};

check_size(agiD3DViewport, 0x14C);
