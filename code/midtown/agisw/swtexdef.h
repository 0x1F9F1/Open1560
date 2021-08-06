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
    agisw:swtexdef

    0x5376D0 | public: __thiscall agiSWTexDef::agiSWTexDef(class agiSWPipeline *) | ??0agiSWTexDef@@QAE@PAVagiSWPipeline@@@Z
    0x537700 | public: virtual __thiscall agiSWTexDef::~agiSWTexDef(void) | ??1agiSWTexDef@@UAE@XZ
    0x537710 | public: virtual void __thiscall agiSWTexDef::Set(class Vector2 &,class Vector2 &) | ?Set@agiSWTexDef@@UAEXAAVVector2@@0@Z
    0x537730 | public: virtual int __thiscall agiSWTexDef::BeginGfx(void) | ?BeginGfx@agiSWTexDef@@UAEHXZ
    0x537810 | public: virtual int __thiscall agiSWTexDef::IsAvailable(void) | ?IsAvailable@agiSWTexDef@@UAEHXZ
    0x537820 | public: virtual void __thiscall agiSWTexDef::EndGfx(void) | ?EndGfx@agiSWTexDef@@UAEXXZ
    0x537870 | public: virtual int __thiscall agiSWTexDef::Lock(struct agiTexLock &) | ?Lock@agiSWTexDef@@UAEHAAUagiTexLock@@@Z
    0x5378C0 | public: virtual void __thiscall agiSWTexDef::Unlock(struct agiTexLock &) | ?Unlock@agiSWTexDef@@UAEXAAUagiTexLock@@@Z
    0x5378D0 | public: virtual void __thiscall agiSWTexDef::Request(void) | ?Request@agiSWTexDef@@UAEXXZ
    0x537930 | public: __thiscall agiSWTexLut::agiSWTexLut(class agiSWPipeline *) | ??0agiSWTexLut@@QAE@PAVagiSWPipeline@@@Z
    0x537950 | public: virtual int __thiscall agiSWTexLut::BeginGfx(void) | ?BeginGfx@agiSWTexLut@@UAEHXZ
    0x537B30 | public: virtual void __thiscall agiSWTexLut::EndGfx(void) | ?EndGfx@agiSWTexLut@@UAEXXZ
    0x537B40 | public: virtual void * __thiscall agiSWTexDef::`vector deleting destructor'(unsigned int) | ??_EagiSWTexDef@@UAEPAXI@Z
    0x537B40 | public: virtual void * __thiscall agiSWTexDef::`scalar deleting destructor'(unsigned int) | ??_GagiSWTexDef@@UAEPAXI@Z
    0x537B70 | public: virtual void * __thiscall agiSWTexLut::`vector deleting destructor'(unsigned int) | ??_EagiSWTexLut@@UAEPAXI@Z
    0x537B70 | public: virtual void * __thiscall agiSWTexLut::`scalar deleting destructor'(unsigned int) | ??_GagiSWTexLut@@UAEPAXI@Z
    0x537BA0 | public: virtual __thiscall agiSWTexLut::~agiSWTexLut(void) | ??1agiSWTexLut@@UAE@XZ
    0x6212D8 | const agiSWTexDef::`vftable' | ??_7agiSWTexDef@@6B@
    0x621308 | const agiSWTexLut::`vftable' | ??_7agiSWTexLut@@6B@
    0x652304 | float swLutInvGamma | ?swLutInvGamma@@3MA
*/

#include "agi/texdef.h"

#include "swpipe.h"

class agiSWTexDef final : public agiTexDef
{
    // const agiSWTexDef::`vftable'

public:
    // ??0agiSWTexDef@@QAE@PAVagiSWPipeline@@@Z
    ARTS_EXPORT agiSWTexDef(class agiSWPipeline* pipe)
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
    ARTS_IMPORT b32 Lock(struct agiTexLock& arg1) override;

    // ?Request@agiSWTexDef@@UAEXXZ
    ARTS_IMPORT void Request() override;

    // ?Set@agiSWTexDef@@UAEXAAVVector2@@0@Z
    ARTS_IMPORT void Set(class Vector2& arg1, class Vector2& arg2) override;

    // ?Unlock@agiSWTexDef@@UAEXAAUagiTexLock@@@Z
    ARTS_EXPORT void Unlock(struct agiTexLock& arg1) override;

private:
    i32 field_74 {0};
    i32 width_mips_ {0};
    i32 height_mips_ {0};
    Ptr<u8[]> surfaces_[7] {};
};

check_size(agiSWTexDef, 0x9C);

class agiSWTexLut final : public agiTexLut
{
    // const agiSWTexLut::`vftable'

public:
    // ??0agiSWTexLut@@QAE@PAVagiSWPipeline@@@Z
    ARTS_IMPORT agiSWTexLut(class agiSWPipeline* arg1);

    // ??_GagiSWTexLut@@UAEPAXI@Z
    // ??_EagiSWTexLut@@UAEPAXI@Z
    // ??1agiSWTexLut@@UAE@XZ | inline
    ARTS_IMPORT ~agiSWTexLut() override = default;

    // ?BeginGfx@agiSWTexLut@@UAEHXZ
    ARTS_IMPORT i32 BeginGfx() override;

    // ?EndGfx@agiSWTexLut@@UAEXXZ
    ARTS_EXPORT void EndGfx() override;

    u32 fog_color_ {0};
    u16 intensities_[8][256];
};

check_size(agiSWTexLut, 0x1420);

// ?swLutInvGamma@@3MA
ARTS_IMPORT extern f32 swLutInvGamma;
