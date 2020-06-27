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
    agirend:zbrender

    0x54FA70 | public: __thiscall agiZBufRenderer::agiZBufRenderer(class agiRasterizer *) | ??0agiZBufRenderer@@QAE@PAVagiRasterizer@@@Z
    0x54FA90 | public: virtual __thiscall agiZBufRenderer::~agiZBufRenderer(void) | ??1agiZBufRenderer@@UAE@XZ
    0x54FAA0 | public: virtual void __thiscall agiZBufRenderer::EndGroup(void) | ?EndGroup@agiZBufRenderer@@UAEXXZ
    0x5507D0 | public: virtual void * __thiscall agiZBufRenderer::`scalar deleting destructor'(unsigned int) | ??_GagiZBufRenderer@@UAEPAXI@Z
    0x5507D0 | public: virtual void * __thiscall agiZBufRenderer::`vector deleting destructor'(unsigned int) | ??_EagiZBufRenderer@@UAEPAXI@Z
    0x621388 | const agiZBufRenderer::`vftable' | ??_7agiZBufRenderer@@6B@
    0x656348 | int twiddle | ?twiddle@@3HA
    0x65634C | float aa_expansion | ?aa_expansion@@3MA
*/

#include "surfrender.h"

class agiZBufRenderer : public agiSurfRenderer
{
    // const agiZBufRenderer::`vftable' @ 0x621388

public:
    // 0x54FA70 | ??0agiZBufRenderer@@QAE@PAVagiRasterizer@@@Z
    ARTS_IMPORT agiZBufRenderer(class agiRasterizer* arg1);

    // 0x5507D0 | ??_EagiZBufRenderer@@UAEPAXI@Z
    // 0x5507D0 | ??_GagiZBufRenderer@@UAEPAXI@Z
    // 0x54FA90 | ??1agiZBufRenderer@@UAE@XZ
    ARTS_IMPORT ~agiZBufRenderer() override;

    // 0x54FAA0 | ?EndGroup@agiZBufRenderer@@UAEXXZ
    ARTS_IMPORT void EndGroup() override;
};

check_size(agiZBufRenderer, 0x14);

// 0x65634C | ?aa_expansion@@3MA
ARTS_IMPORT extern f32 aa_expansion;

// 0x656348 | ?twiddle@@3HA
ARTS_IMPORT extern i32 twiddle;
