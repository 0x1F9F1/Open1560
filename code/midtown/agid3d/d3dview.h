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

#include "d3dpipe.h"

class agiD3DViewport final : public agiViewport
{
public:
    // ??0agiD3DViewport@@QAE@PAVagiPipeline@@@Z
    ARTS_IMPORT agiD3DViewport(agiPipeline* pipe)
        : agiViewport(pipe)
    {}

    // ??_EagiD3DViewport@@UAEPAXI@Z
    // ??_GagiD3DViewport@@UAEPAXI@Z
    // ??1agiD3DViewport@@UAE@XZ
    ARTS_IMPORT ~agiD3DViewport() override = default;

    // ?Activate@agiD3DViewport@@UAEXXZ
    ARTS_EXPORT void Activate() override;

    // ?BeginGfx@agiD3DViewport@@UAEHXZ
    ARTS_EXPORT i32 BeginGfx() override;

    // ?Clear@agiD3DViewport@@UAEXH@Z
    ARTS_EXPORT void Clear(i32 flags) override;

    // ?EndGfx@agiD3DViewport@@UAEXXZ
    ARTS_EXPORT void EndGfx() override;

    // ?SetBackground@agiD3DViewport@@UAEXAAVVector3@@@Z
    ARTS_EXPORT void SetBackground(Vector3& color) override;

    agiD3DPipeline* Pipe() const
    {
        return static_cast<agiD3DPipeline*>(agiRefreshable::Pipe());
    }

private:
    u32 clear_color_ {0};
};

check_size(agiD3DViewport, 0x14C);
