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

define_dummy_symbol(agisw_swddraw);

#include "swddraw.h"

#include <ddraw.h>

#include "agi/pipeline.h"
#include "data7/utimer.h"
#include "pcwindis/dxinit.h"
#include "swrend.h"

// 0x534FA0 | ?ddEnd@@YAXXZ
ARTS_EXPORT /*static*/ void ddEnd()
{}

// 0x535070 | ?ddEndFrame@@YAXXZ
ARTS_IMPORT /*static*/ void ddEndFrame();

// 0x535030 | ?ddEndScene@@YAXXZ
ARTS_EXPORT /*static*/ void ddEndScene()
{
    ARTS_UTIMED(agiEndScene);
    lpdsRend->Unlock(NULL);
    swScreen = 0;
}

// 0x534EA0 | ?ddStart@@YAXXZ
ARTS_EXPORT /*static*/ void ddStart()
{
    swFbWidth = dxiWidth;
    swFbHeight = dxiHeight;

    DDSURFACEDESC2 sd {sizeof(sd)};
    lpdsRend->Lock(NULL, &sd, DDLOCK_WAIT, NULL);
    lpdsRend->Unlock(NULL);

    swScreenDesc = agiSurfaceDesc::FromDDSD2(sd);

    if (!(sd.ddpfPixelFormat.dwFlags & DDPF_RGB))
        Quitf("ddStart: Require RGB color!");

    swBytesPerPixel = sd.ddpfPixelFormat.dwRGBBitCount >> 3;
    swRedMask = sd.ddpfPixelFormat.dwRBitMask;
    swGreenMask = sd.ddpfPixelFormat.dwGBitMask;
    swBlueMask = sd.ddpfPixelFormat.dwBBitMask;
    Displayf("SCREEN MODEL: %x / %x / %x", sd.ddpfPixelFormat.dwRBitMask, sd.ddpfPixelFormat.dwGBitMask,
        sd.ddpfPixelFormat.dwBBitMask);

    swActualScreenStride = sd.lPitch;
    swScreenStride = sd.lPitch << swIsInterlaced;

    for (i32 i = 0; i < 256; ++i)
        swNibbleLut[i] = static_cast<u8>(i >> 4);

    for (i32 i = 256; i < 512; ++i)
        swNibbleLut[i] = static_cast<u8>(i & 0xF);
}

// 0x534FC0 | ?ddStartFrame@@YAXXZ
ARTS_EXPORT /*static*/ void ddStartFrame()
{
    debugTri = 0;
}

// 0x534FD0 | ?ddStartScene@@YAXXZ
ARTS_EXPORT /*static*/ void ddStartScene()
{
    ARTS_UTIMED(agiBeginScene);

    DDSURFACEDESC2 sd {sizeof(sd)};
    lpdsRend->Lock(NULL, &sd, DDLOCK_WAIT, NULL);
    swScreen = static_cast<u8*>(sd.lpSurface) + swFrameOffset;
}

static i32 swBitDepth = 0; // Unused

static extern_var(0x795D34, i32, bEnableVerticalSync);

void ddAttach(i32 flags, i32 bit_depth)
{
    bEnableVerticalSync = flags & 1;

    if (flags & 0x10)
        bRenderToSystem = 1;

    swFbStart = ddStart;
    swBitDepth = bit_depth;
    swFbEnd = ddEnd;
    swFbStartFrame = ddStartFrame;
    swFbEndFrame = ddEndFrame;
    swFbStartScene = ddStartScene;
    swFbEndScene = ddEndScene;
}
