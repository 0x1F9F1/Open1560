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

#include "surfrender.h"

class agiZBufRenderer final : public agiSurfRenderer
{
public:
    // ??0agiZBufRenderer@@QAE@PAVagiRasterizer@@@Z
    ARTS_IMPORT agiZBufRenderer(agiRasterizer* arg1);

    // ??_EagiZBufRenderer@@UAEPAXI@Z
    // ??_GagiZBufRenderer@@UAEPAXI@Z
    // ??1agiZBufRenderer@@UAE@XZ
    ARTS_EXPORT ~agiZBufRenderer() override = default;

    // ?EndGroup@agiZBufRenderer@@UAEXXZ
    ARTS_IMPORT void EndGroup() override;
};

check_size(agiZBufRenderer, 0x14);

// ?aa_expansion@@3MA
ARTS_IMPORT extern f32 aa_expansion;

// ?twiddle@@3HA
ARTS_IMPORT extern i32 twiddle;
