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

#include "optionsbase.h"

// ?AutoDetect@@YAXHH@Z
ARTS_EXPORT void AutoDetect(i32 renderer, i32 resolution);

// ?RenderToSystemMemory@@3HA
ARTS_IMPORT extern i32 RenderToSystemMemory;

// ?TextureLevel@@3HA
ARTS_IMPORT extern i32 TextureLevel;

// ?data1@@3HA
ARTS_IMPORT extern i32 data1;

// ?data2@@3HA
ARTS_IMPORT extern i32 data2;

// ?data3@@3HA
ARTS_IMPORT extern i32 data3;

// ?data4@@3HA
ARTS_IMPORT extern i32 data4;

// ?data5@@3HA
ARTS_IMPORT extern i32 data5;

// ?data6@@3HA
ARTS_IMPORT extern i32 data6;

class GraphicsOptions final : public OptionsBase
{
public:
    // ??0GraphicsOptions@@QAE@H@Z
    ARTS_IMPORT GraphicsOptions(i32 arg1);

    // ??1GraphicsOptions@@UAE@XZ
    ARTS_IMPORT ~GraphicsOptions() override;

    // ?CancelAction@GraphicsOptions@@UAEXXZ
    ARTS_IMPORT void CancelAction() override;

    // ?DoneAction@GraphicsOptions@@UAEXXZ
    ARTS_IMPORT void DoneAction() override;

    // ?PreSetup@GraphicsOptions@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    // ?ResetDefaultAction@GraphicsOptions@@UAEXXZ
    ARTS_IMPORT void ResetDefaultAction() override;

    // ?SetLightQuality@GraphicsOptions@@QAEXXZ
    ARTS_IMPORT void SetLightQuality();

    // ?SetRenderer@GraphicsOptions@@QAEXXZ
    ARTS_IMPORT void SetRenderer();

    // ?SetResolution@GraphicsOptions@@QAEXXZ
    ARTS_IMPORT void SetResolution();

    u8 gap6EC8[0x20];
};

check_size(GraphicsOptions, 0x6EE8);
