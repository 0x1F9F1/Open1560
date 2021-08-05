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
    agirend:rdlp

    0x550800 | public: __thiscall RDLP::RDLP(class agiPipeline *) | ??0RDLP@@QAE@PAVagiPipeline@@@Z
    0x550850 | public: virtual __thiscall RDLP::~RDLP(void) | ??1RDLP@@UAE@XZ
    0x5508A0 | private: int __thiscall RDLP::InitFacet(struct agiPatch *,int,int,int,int) | ?InitFacet@RDLP@@AAEHPAUagiPatch@@HHHH@Z
    0x550C40 | public: virtual int __thiscall RDLP::BeginGfx(void) | ?BeginGfx@RDLP@@UAEHXZ
    0x551200 | public: virtual void __thiscall RDLP::EndGfx(void) | ?EndGfx@RDLP@@UAEXXZ
    0x551290 | public: __thiscall RDynamicDLP::RDynamicDLP(int,class RDLP *) | ??0RDynamicDLP@@QAE@HPAVRDLP@@@Z
    0x5512F0 | public: virtual __thiscall RDynamicDLP::~RDynamicDLP(void) | ??1RDynamicDLP@@UAE@XZ
    0x551360 | public: virtual int __thiscall RDynamicDLP::Init(char *) | ?Init@RDynamicDLP@@UAEHPAD@Z
    0x5513B0 | public: virtual void __thiscall RDynamicDLP::SetTexture(short) | ?SetTexture@RDynamicDLP@@UAEXF@Z
    0x551440 | public: virtual void __thiscall RDynamicDLP::Lock(void) | ?Lock@RDynamicDLP@@UAEXXZ
    0x551480 | public: virtual void __thiscall RDynamicDLP::Unlock(void) | ?Unlock@RDynamicDLP@@UAEXXZ
    0x551490 | public: virtual class DynamicDLP * __thiscall RDLP::GetDynamic(int) | ?GetDynamic@RDLP@@UAEPAVDynamicDLP@@H@Z
    0x551530 | public: virtual class MultipassDLP * __thiscall RDLP::GetMultipass(int) | ?GetMultipass@RDLP@@UAEPAVMultipassDLP@@H@Z
    0x551540 | public: virtual void __thiscall RDLP::FixROpts(int,int) | ?FixROpts@RDLP@@UAEXHH@Z
    0x5515E0 | public: virtual void * __thiscall RDLP::`scalar deleting destructor'(unsigned int) | ??_GRDLP@@UAEPAXI@Z
    0x5515E0 | public: virtual void * __thiscall RDLP::`vector deleting destructor'(unsigned int) | ??_ERDLP@@UAEPAXI@Z
    0x551610 | public: virtual void * __thiscall RDynamicDLP::`scalar deleting destructor'(unsigned int) | ??_GRDynamicDLP@@UAEPAXI@Z
    0x551610 | public: virtual void * __thiscall RDynamicDLP::`vector deleting destructor'(unsigned int) | ??_ERDynamicDLP@@UAEPAXI@Z
    0x6213B8 | const RDLP::`vftable' | ??_7RDLP@@6B@
    0x6213F0 | const RDynamicDLP::`vftable' | ??_7RDynamicDLP@@6B@
*/

#include "agi/dlp.h"
#include "agi/dyndlp.h"

class RDLP final : public DLP
{
    // const RDLP::`vftable'

public:
    // ??0RDLP@@QAE@PAVagiPipeline@@@Z
    ARTS_IMPORT RDLP(class agiPipeline* arg1);

    // ??_ERDLP@@UAEPAXI@Z
    // ??_GRDLP@@UAEPAXI@Z
    // ??1RDLP@@UAE@XZ
    ARTS_IMPORT ~RDLP() override;

    // ?BeginGfx@RDLP@@UAEHXZ
    ARTS_IMPORT i32 BeginGfx() override;

    // ?EndGfx@RDLP@@UAEXXZ
    ARTS_IMPORT void EndGfx() override;

    // ?FixROpts@RDLP@@UAEXHH@Z
    ARTS_IMPORT void FixROpts(i32 arg1, i32 arg2) override;

    // ?GetDynamic@RDLP@@UAEPAVDynamicDLP@@H@Z
    ARTS_IMPORT class DynamicDLP* GetDynamic(i32 arg1) override;

    // ?GetMultipass@RDLP@@UAEPAVMultipassDLP@@H@Z
    ARTS_EXPORT class MultipassDLP* GetMultipass(i32 arg1) override;

private:
    // ?InitFacet@RDLP@@AAEHPAUagiPatch@@HHHH@Z
    ARTS_IMPORT i32 InitFacet(struct agiPatch* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5);

    u8 gap94[0x18];
};

check_size(RDLP, 0xAC);

class RDynamicDLP final : public DynamicDLP
{
    // const RDynamicDLP::`vftable'

public:
    // ??0RDynamicDLP@@QAE@HPAVRDLP@@@Z
    ARTS_IMPORT RDynamicDLP(i32 arg1, class RDLP* arg2);

    // ??_ERDynamicDLP@@UAEPAXI@Z
    // ??_GRDynamicDLP@@UAEPAXI@Z
    // ??1RDynamicDLP@@UAE@XZ
    ARTS_IMPORT ~RDynamicDLP() override;

    // ?Init@RDynamicDLP@@UAEHPAD@Z
    ARTS_IMPORT i32 Init(char* arg1) override;

    // ?Lock@RDynamicDLP@@UAEXXZ
    ARTS_IMPORT void Lock() override;

    // ?SetTexture@RDynamicDLP@@UAEXF@Z
    ARTS_IMPORT void SetTexture(i16 arg1) override;

    // ?Unlock@RDynamicDLP@@UAEXXZ
    ARTS_IMPORT void Unlock() override;

    u8 gap24[0x4];
};

check_size(RDynamicDLP, 0x28);
