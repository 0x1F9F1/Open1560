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
    agid3d:d3dmtldef

    0x533560 | public: __thiscall agiD3DMtlDef::agiD3DMtlDef(class agiPipeline *) | ??0agiD3DMtlDef@@QAE@PAVagiPipeline@@@Z
    0x533590 | public: virtual int __thiscall agiD3DMtlDef::BeginGfx(void) | ?BeginGfx@agiD3DMtlDef@@UAEHXZ
    0x533620 | public: virtual void __thiscall agiD3DMtlDef::EndGfx(void) | ?EndGfx@agiD3DMtlDef@@UAEXXZ
    0x533660 | public: virtual __thiscall agiD3DMtlDef::~agiD3DMtlDef(void) | ??1agiD3DMtlDef@@UAE@XZ
    0x533670 | public: void __thiscall agiD3DMtlDef::Activate(void) | ?Activate@agiD3DMtlDef@@QAEXXZ
    0x533720 | void __cdecl xlat(struct _D3DCOLORVALUE &,class Vector4 &) | ?xlat@@YAXAAU_D3DCOLORVALUE@@AAVVector4@@@Z
    0x533750 | public: unsigned long __thiscall agiD3DMtlDef::GetHandle(void) | ?GetHandle@agiD3DMtlDef@@QAEKXZ
    0x533770 | public: virtual void * __thiscall agiD3DMtlDef::`vector deleting destructor'(unsigned int) | ??_EagiD3DMtlDef@@UAEPAXI@Z
    0x533770 | public: virtual void * __thiscall agiD3DMtlDef::`scalar deleting destructor'(unsigned int) | ??_GagiD3DMtlDef@@UAEPAXI@Z
    0x621170 | const agiD3DMtlDef::`vftable' | ??_7agiD3DMtlDef@@6B@
*/

#include "agi/mtldef.h"

#include "d3dpipe.h"

class agiD3DMtlDef final : public agiMtlDef
{
public:
    // ??0agiD3DMtlDef@@QAE@PAVagiPipeline@@@Z
    ARTS_EXPORT agiD3DMtlDef(agiPipeline* pipe)
        : agiMtlDef(pipe)
    {}

    // ??_GagiD3DMtlDef@@UAEPAXI@Z
    // ??_EagiD3DMtlDef@@UAEPAXI@Z
    // ??1agiD3DMtlDef@@UAE@XZ
    ARTS_EXPORT ~agiD3DMtlDef() override = default;

    // ?Activate@agiD3DMtlDef@@QAEXXZ
    ARTS_EXPORT void Activate();

    // ?BeginGfx@agiD3DMtlDef@@UAEHXZ
    ARTS_EXPORT i32 BeginGfx() override;

    // ?EndGfx@agiD3DMtlDef@@UAEXXZ
    ARTS_EXPORT void EndGfx() override;

    agiD3DPipeline* Pipe() const
    {
        return static_cast<agiD3DPipeline*>(agiRefreshable::Pipe());
    }

    IDirect3DMaterial3* material_ {};
    D3DMATERIALHANDLE handle_ {};
};

check_size(agiD3DMtlDef, 0x88);
