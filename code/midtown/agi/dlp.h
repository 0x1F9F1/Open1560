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

#include "refresh.h"

/*
    agi:dlp

    0x55DE90 | public: __thiscall DLP::DLP(class agiPipeline *) | ??0DLP@@QAE@PAVagiPipeline@@@Z
    0x55DEF0 | public: virtual __thiscall DLP::~DLP(void) | ??1DLP@@UAE@XZ
    0x55E000 | protected: void __thiscall DLP::FixTemplateRefs(int) | ?FixTemplateRefs@DLP@@IAEXH@Z
    0x55E0D0 | public: virtual int __thiscall DLP::BeginGfx(void) | ?BeginGfx@DLP@@UAEHXZ
    0x55E2F0 | public: virtual void __thiscall DLP::EndGfx(void) | ?EndGfx@DLP@@UAEXXZ
    0x55E300 | public: int __thiscall DLP::Init(char *,char *,class Vector3 *) | ?Init@DLP@@QAEHPAD0PAVVector3@@@Z
    0x55E380 | public: int __thiscall DLP::Init(class DLPTemplate *,char *,class Vector3 *) | ?Init@DLP@@QAEHPAVDLPTemplate@@PADPAVVector3@@@Z
    0x55E460 | public: class DLP * __thiscall DLP::Clone(void) | ?Clone@DLP@@QAEPAV1@XZ
    0x55E490 | public: virtual void __thiscall DLP::Cull(int) | ?Cull@DLP@@UAEXH@Z
    0x55E4F0 | public: virtual char * __thiscall DLP::GetName(void) | ?GetName@DLP@@UAEPADXZ
    0x55E530 | public: virtual void __thiscall DLP::FixROpts(int,int) | ?FixROpts@DLP@@UAEXHH@Z
    0x55E580 | public: virtual void * __thiscall DLP::`vector deleting destructor'(unsigned int) | ??_EDLP@@UAEPAXI@Z
    0x55E580 | public: virtual void * __thiscall DLP::`scalar deleting destructor'(unsigned int) | ??_GDLP@@UAEPAXI@Z
    0x6218A8 | const DLP::`vftable' | ??_7DLP@@6B@
    0x907950 | class HashTable DLPHash | ?DLPHash@@3VHashTable@@A
*/

class DLP : public agiRefreshable
{
    // const DLP::`vftable' @ 0x6218A8

public:
    // 0x55DE90 | ??0DLP@@QAE@PAVagiPipeline@@@Z
    DLP(class agiPipeline* arg1);

    // 0x55E580 | ??_GDLP@@UAEPAXI@Z
    // 0x55DEF0 | ??1DLP@@UAE@XZ
    ~DLP() override;

    // 0x55E490 | ?Cull@DLP@@UAEXH@Z
    virtual void Cull(i32 arg1);

    // 0x55E530 | ?FixROpts@DLP@@UAEXHH@Z
    virtual void FixROpts(i32 arg1, i32 arg2);

    virtual class DynamicDLP* GetDynamic(i32 arg1) = 0;

    virtual class MultipassDLP* GetMultipass(i32 arg1) = 0;

    // 0x55E0D0 | ?BeginGfx@DLP@@UAEHXZ
    i32 BeginGfx() override;

    // 0x55E460 | ?Clone@DLP@@QAEPAV1@XZ
    class DLP* Clone();

    // 0x55E2F0 | ?EndGfx@DLP@@UAEXXZ
    void EndGfx() override;

    // 0x55E4F0 | ?GetName@DLP@@UAEPADXZ
    char* GetName() override;

    // 0x55E300 | ?Init@DLP@@QAEHPAD0PAVVector3@@@Z
    i32 Init(char* arg1, char* arg2, class Vector3* arg3);

    // 0x55E380 | ?Init@DLP@@QAEHPAVDLPTemplate@@PADPAVVector3@@@Z
    i32 Init(class DLPTemplate* arg1, char* arg2, class Vector3* arg3);

protected:
    // 0x55E000 | ?FixTemplateRefs@DLP@@IAEXH@Z
    void FixTemplateRefs(i32 arg1);
};

check_size(DLP, 0x0);

// 0x907950 | ?DLPHash@@3VHashTable@@A
inline extern_var(0x507950_Offset, class HashTable, DLPHash);
