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
    agid3d:d3dtexdef

    0x5319A0 | public: __thiscall agiD3DTexDef::agiD3DTexDef(class agiPipeline *) | ??0agiD3DTexDef@@QAE@PAVagiPipeline@@@Z
    0x5319D0 | public: virtual __thiscall agiD3DTexDef::~agiD3DTexDef(void) | ??1agiD3DTexDef@@UAE@XZ
    0x5319E0 | public: virtual int __thiscall agiD3DTexDef::BeginGfx(void) | ?BeginGfx@agiD3DTexDef@@UAEHXZ
    0x531D40 | public: virtual void __thiscall agiD3DTexDef::Request(void) | ?Request@agiD3DTexDef@@UAEXXZ
    0x531DA0 | public: struct IDirect3DTexture2 * __thiscall agiD3DTexDef::GetHandle(int) | ?GetHandle@agiD3DTexDef@@QAEPAUIDirect3DTexture2@@H@Z
    0x531E20 | public: virtual int __thiscall agiD3DTexDef::Lock(struct agiTexLock &) | ?Lock@agiD3DTexDef@@UAEHAAUagiTexLock@@@Z
    0x531EC0 | public: virtual void __thiscall agiD3DTexDef::Unlock(struct agiTexLock &) | ?Unlock@agiD3DTexDef@@UAEXAAUagiTexLock@@@Z
    0x531EF0 | public: virtual void __thiscall agiD3DTexDef::EndGfx(void) | ?EndGfx@agiD3DTexDef@@UAEXXZ
    0x531F60 | public: virtual int __thiscall agiD3DTexDef::IsAvailable(void) | ?IsAvailable@agiD3DTexDef@@UAEHXZ
    0x531F70 | public: virtual void __thiscall agiD3DTexDef::Set(class Vector2 &,class Vector2 &) | ?Set@agiD3DTexDef@@UAEXAAVVector2@@0@Z
    0x531F90 | public: virtual void __thiscall agiD3DTexDef::Restore(void) | ?Restore@agiD3DTexDef@@UAEXXZ
    0x531FD0 | public: virtual int __thiscall agiD3DTexLut::BeginGfx(void) | ?BeginGfx@agiD3DTexLut@@UAEHXZ
    0x532020 | public: virtual void __thiscall agiD3DTexLut::EndGfx(void) | ?EndGfx@agiD3DTexLut@@UAEXXZ
    0x532060 | public: virtual void * __thiscall agiD3DTexDef::`scalar deleting destructor'(unsigned int) | ??_GagiD3DTexDef@@UAEPAXI@Z
    0x532060 | public: virtual void * __thiscall agiD3DTexDef::`vector deleting destructor'(unsigned int) | ??_EagiD3DTexDef@@UAEPAXI@Z
    0x621090 | const agiD3DTexDef::`vftable' | ??_7agiD3DTexDef@@6B@
    0x795C38 | int DontCacheTextures | ?DontCacheTextures@@3HA
*/

#include "agi/texdef.h"

class agiD3DTexDef : public agiTexDef
{
    // const agiD3DTexDef::`vftable' @ 0x621090

public:
    // 0x5319A0 | ??0agiD3DTexDef@@QAE@PAVagiPipeline@@@Z
    agiD3DTexDef(class agiPipeline* arg1);

    // 0x532060 | ??_EagiD3DTexDef@@UAEPAXI@Z
    // 0x5319D0 | ??1agiD3DTexDef@@UAE@XZ
    ~agiD3DTexDef() override;

    // 0x5319E0 | ?BeginGfx@agiD3DTexDef@@UAEHXZ
    i32 BeginGfx() override;

    // 0x531EF0 | ?EndGfx@agiD3DTexDef@@UAEXXZ
    void EndGfx() override;

    // 0x531DA0 | ?GetHandle@agiD3DTexDef@@QAEPAUIDirect3DTexture2@@H@Z
    struct IDirect3DTexture2* GetHandle(i32 arg1);

    // 0x531F60 | ?IsAvailable@agiD3DTexDef@@UAEHXZ
    i32 IsAvailable() override;

    // 0x531E20 | ?Lock@agiD3DTexDef@@UAEHAAUagiTexLock@@@Z
    i32 Lock(struct agiTexLock& arg1) override;

    // 0x531D40 | ?Request@agiD3DTexDef@@UAEXXZ
    void Request() override;

    // 0x531F90 | ?Restore@agiD3DTexDef@@UAEXXZ
    void Restore() override;

    // 0x531F70 | ?Set@agiD3DTexDef@@UAEXAAVVector2@@0@Z
    void Set(class Vector2& arg1, class Vector2& arg2) override;

    // 0x531EC0 | ?Unlock@agiD3DTexDef@@UAEXAAUagiTexLock@@@Z
    void Unlock(struct agiTexLock& arg1) override;

    // 0x52FA90 | ?Prober@agiD3DTexDef@@SAXPAX@Z | inline
    static void Prober(void* arg1);
};

check_size(agiD3DTexDef, 0x88);

// 0x795C38 | ?DontCacheTextures@@3HA
inline extern_var(0x795C38, i32, DontCacheTextures);
