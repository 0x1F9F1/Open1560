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

#include "agi/texdef.h"

class agiSWTexDef final : public agiTexDef
{
public:
    agiSWTexDef(agiPipeline* pipe)
        : agiTexDef(pipe)
    {}

    // ??_GagiSWTexDef@@UAEPAXI@Z
    // ??_EagiSWTexDef@@UAEPAXI@Z
    // ??1agiSWTexDef@@UAE@XZ
    ARTS_EXPORT ~agiSWTexDef() override = default;

    // ?BeginGfx@agiSWTexDef@@UAEHXZ
    ARTS_EXPORT i32 BeginGfx() override;

    // ?EndGfx@agiSWTexDef@@UAEXXZ
    ARTS_EXPORT void EndGfx() override;

    // ?IsAvailable@agiSWTexDef@@UAEHXZ
    ARTS_IMPORT b32 IsAvailable() override;

    // ?Lock@agiSWTexDef@@UAEHAAUagiTexLock@@@Z
    ARTS_IMPORT b32 Lock(agiTexLock& arg1) override;

    // ?Request@agiSWTexDef@@UAEXXZ
    ARTS_IMPORT void Request() override;

    // ?Set@agiSWTexDef@@UAEXAAVVector2@@0@Z
    ARTS_IMPORT void Set(Vector2& arg1, Vector2& arg2) override;

    // ?Unlock@agiSWTexDef@@UAEXAAUagiTexLock@@@Z
    ARTS_EXPORT void Unlock(agiTexLock& arg1) override;

private:
    i32 field_74 {};
    i32 width_mips_ {};
    i32 height_mips_ {};
    Ptr<u8[]> surfaces_[7];
};

check_size(agiSWTexDef, 0x9C);

class agiSWTexLut final : public agiTexLut
{
public:
    agiSWTexLut(agiPipeline* pipe)
        : agiTexLut(pipe)
    {}

    // ??_GagiSWTexLut@@UAEPAXI@Z
    // ??_EagiSWTexLut@@UAEPAXI@Z
    // ??1agiSWTexLut@@UAE@XZ | inline
    ARTS_EXPORT ~agiSWTexLut() override = default;

    // ?BeginGfx@agiSWTexLut@@UAEHXZ
    ARTS_IMPORT i32 BeginGfx() override;

    // ?EndGfx@agiSWTexLut@@UAEXXZ
    ARTS_EXPORT void EndGfx() override;

    u32 fog_color_ {};
    u16 intensities_[8][256];
};

check_size(agiSWTexLut, 0x1420);

// ?swLutInvGamma@@3MA
ARTS_IMPORT extern f32 swLutInvGamma;
