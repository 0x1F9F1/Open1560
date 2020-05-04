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

#include "agi/dlp.h"
#include "agi/dyndlp.h"

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

class RDLP : public DLP
{
    // const RDLP::`vftable' @ 0x6213B8

public:
    // 0x550800 | ??0RDLP@@QAE@PAVagiPipeline@@@Z
    RDLP(class agiPipeline* arg1);

    // 0x5515E0 | ??_ERDLP@@UAEPAXI@Z
    // 0x550850 | ??1RDLP@@UAE@XZ
    ~RDLP() override;

    // 0x550C40 | ?BeginGfx@RDLP@@UAEHXZ
    i32 BeginGfx() override;

    // 0x551200 | ?EndGfx@RDLP@@UAEXXZ
    void EndGfx() override;

    // 0x551540 | ?FixROpts@RDLP@@UAEXHH@Z
    void FixROpts(i32 arg1, i32 arg2) override;

    // 0x551490 | ?GetDynamic@RDLP@@UAEPAVDynamicDLP@@H@Z
    class DynamicDLP* GetDynamic(i32 arg1) override;

    // 0x551530 | ?GetMultipass@RDLP@@UAEPAVMultipassDLP@@H@Z
    class MultipassDLP* GetMultipass(i32 arg1) override;

private:
    // 0x5508A0 | ?InitFacet@RDLP@@AAEHPAUagiPatch@@HHHH@Z
    i32 InitFacet(struct agiPatch* arg1, i32 arg2, i32 arg3, i32 arg4, i32 arg5);
};

check_size(RDLP, 0xAC);

class RDynamicDLP : public DynamicDLP
{
    // const RDynamicDLP::`vftable' @ 0x6213F0

public:
    // 0x551290 | ??0RDynamicDLP@@QAE@HPAVRDLP@@@Z
    RDynamicDLP(i32 arg1, class RDLP* arg2);

    // 0x551610 | ??_ERDynamicDLP@@UAEPAXI@Z
    // 0x5512F0 | ??1RDynamicDLP@@UAE@XZ
    ~RDynamicDLP() override;

    // 0x551360 | ?Init@RDynamicDLP@@UAEHPAD@Z
    i32 Init(char* arg1) override;

    // 0x551440 | ?Lock@RDynamicDLP@@UAEXXZ
    void Lock() override;

    // 0x5513B0 | ?SetTexture@RDynamicDLP@@UAEXF@Z
    void SetTexture(i16 arg1) override;

    // 0x551480 | ?Unlock@RDynamicDLP@@UAEXXZ
    void Unlock() override;
};

check_size(RDynamicDLP, 0x28);
