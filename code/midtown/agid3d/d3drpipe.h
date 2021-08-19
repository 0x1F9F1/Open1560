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
    agid3d:d3drpipe

    0x531600 | public: __thiscall agiD3DRPipeline::agiD3DRPipeline(void) | ??0agiD3DRPipeline@@QAE@XZ
    0x531620 | public: virtual __thiscall agiD3DRPipeline::~agiD3DRPipeline(void) | ??1agiD3DRPipeline@@UAE@XZ
    0x531630 | public: virtual int __thiscall agiD3DRPipeline::BeginGfx(void) | ?BeginGfx@agiD3DRPipeline@@UAEHXZ
    0x531700 | public: virtual void __thiscall agiD3DRPipeline::EndGfx(void) | ?EndGfx@agiD3DRPipeline@@UAEXXZ
    0x531730 | public: virtual class agiViewport * __thiscall agiD3DRPipeline::CreateViewport(void) | ?CreateViewport@agiD3DRPipeline@@UAEPAVagiViewport@@XZ
    0x531790 | public: virtual class DLP * __thiscall agiD3DRPipeline::CreateDLP(void) | ?CreateDLP@agiD3DRPipeline@@UAEPAVDLP@@XZ
    0x5317F0 | public: virtual void __thiscall agiD3DRPipeline::BeginScene(void) | ?BeginScene@agiD3DRPipeline@@UAEXXZ
    0x531890 | public: virtual void __thiscall agiD3DRPipeline::EndScene(void) | ?EndScene@agiD3DRPipeline@@UAEXXZ
    0x5318B0 | public: virtual class agiLightModel * __thiscall agiD3DRPipeline::CreateLightModel(void) | ?CreateLightModel@agiD3DRPipeline@@UAEPAVagiLightModel@@XZ
    0x531910 | public: virtual class agiLight * __thiscall agiD3DRPipeline::CreateLight(void) | ?CreateLight@agiD3DRPipeline@@UAEPAVagiLight@@XZ
    0x531970 | public: virtual void * __thiscall agiD3DRPipeline::`vector deleting destructor'(unsigned int) | ??_EagiD3DRPipeline@@UAEPAXI@Z
    0x531970 | public: virtual void * __thiscall agiD3DRPipeline::`scalar deleting destructor'(unsigned int) | ??_GagiD3DRPipeline@@UAEPAXI@Z
    0x621010 | const agiD3DRPipeline::`vftable' | ??_7agiD3DRPipeline@@6B@
    0x795C34 | int UseSimpleRenderer | ?UseSimpleRenderer@@3HA
*/

#include "d3dpipe.h"

class agiD3DRPipeline final : public agiD3DPipeline
{
public:
    // ??0agiD3DRPipeline@@QAE@XZ
    ARTS_EXPORT agiD3DRPipeline() = default;

    // ??_GagiD3DRPipeline@@UAEPAXI@Z
    // ??_EagiD3DRPipeline@@UAEPAXI@Z
    // ??1agiD3DRPipeline@@UAE@XZ
    ARTS_EXPORT ~agiD3DRPipeline() override = default;

    // ?BeginGfx@agiD3DRPipeline@@UAEHXZ
    ARTS_EXPORT i32 BeginGfx() override;

    // ?BeginScene@agiD3DRPipeline@@UAEXXZ
    ARTS_EXPORT void BeginScene() override;

    // ?CreateDLP@agiD3DRPipeline@@UAEPAVDLP@@XZ
    ARTS_EXPORT RcOwner<class DLP> CreateDLP() override;

    // ?CreateLight@agiD3DRPipeline@@UAEPAVagiLight@@XZ
    ARTS_EXPORT RcOwner<class agiLight> CreateLight() override;

    // ?CreateLightModel@agiD3DRPipeline@@UAEPAVagiLightModel@@XZ
    ARTS_EXPORT RcOwner<class agiLightModel> CreateLightModel() override;

    // ?CreateViewport@agiD3DRPipeline@@UAEPAVagiViewport@@XZ
    ARTS_EXPORT RcOwner<class agiViewport> CreateViewport() override;

    // ?EndGfx@agiD3DRPipeline@@UAEXXZ
    ARTS_EXPORT void EndGfx() override;

    // ?EndScene@agiD3DRPipeline@@UAEXXZ
    ARTS_EXPORT void EndScene() override;
};

check_size(agiD3DRPipeline, 0x49C);

// ?UseSimpleRenderer@@3HA
ARTS_IMPORT extern i32 UseSimpleRenderer;
