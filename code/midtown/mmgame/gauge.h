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
    mmgame:gauge

    0x423840 | public: __thiscall RadialGauge::RadialGauge(void) | ??0RadialGauge@@QAE@XZ
    0x4238B0 | public: void __thiscall RadialGauge::Init(char *,char *,float *,float *,float) | ?Init@RadialGauge@@QAEXPAD0PAM1M@Z
    0x423910 | public: virtual void __thiscall RadialGauge::AddWidgets(class Bank *) | ?AddWidgets@RadialGauge@@UAEXPAVBank@@@Z
    0x423920 | public: virtual void __thiscall RadialGauge::Update(void) | ?Update@RadialGauge@@UAEXXZ
    0x423A40 | public: virtual void __thiscall RadialGauge::Cull(void) | ?Cull@RadialGauge@@UAEXXZ
    0x423A70 | public: __thiscall mmLinearGauge::mmLinearGauge(void) | ??0mmLinearGauge@@QAE@XZ
    0x423A80 | public: __thiscall mmLinearGauge::~mmLinearGauge(void) | ??1mmLinearGauge@@QAE@XZ
    0x423A90 | public: void __thiscall mmLinearGauge::Init(char *,float *,float *,float *,int,class mmExternalView *) | ?Init@mmLinearGauge@@QAEXPADPAM11HPAVmmExternalView@@@Z
    0x423BA0 | public: void __thiscall mmLinearGauge::Draw(void) | ?Draw@mmLinearGauge@@QAEXXZ
    0x423C30 | public: void __thiscall mmRadGauge::Init(float *,float *,class mmExternalView *,int,unsigned int) | ?Init@mmRadGauge@@QAEXPAM0PAVmmExternalView@@HI@Z
    0x423C60 | public: void __thiscall mmRadGauge::ResChange(void) | ?ResChange@mmRadGauge@@QAEXXZ
    0x423CB0 | public: void __thiscall mmRadGauge::Draw(void) | ?Draw@mmRadGauge@@QAEXXZ
    0x423DE0 | public: void __thiscall mmGearIndicator::Init(class mmExternalView *,class mmPlayer *) | ?Init@mmGearIndicator@@QAEXPAVmmExternalView@@PAVmmPlayer@@@Z
    0x423F10 | public: void __thiscall mmGearIndicator::Draw(void) | ?Draw@mmGearIndicator@@QAEXXZ
    0x423F90 | public: void __thiscall mmSpeedIndicator::Init(class mmExternalView *,class mmCarSim *) | ?Init@mmSpeedIndicator@@QAEXPAVmmExternalView@@PAVmmCarSim@@@Z
    0x424020 | public: void __thiscall mmSpeedIndicator::Draw(void) | ?Draw@mmSpeedIndicator@@QAEXXZ
    0x424170 | public: virtual void * __thiscall RadialGauge::`scalar deleting destructor'(unsigned int) | ??_GRadialGauge@@UAEPAXI@Z
    0x424170 | public: virtual void * __thiscall RadialGauge::`vector deleting destructor'(unsigned int) | ??_ERadialGauge@@UAEPAXI@Z
    0x61ABA8 | const RadialGauge::`vftable' | ??_7RadialGauge@@6B@
*/

#include "arts7/node.h"

class RadialGauge /*final*/ : public asNode
{
    // const RadialGauge::`vftable' @ 0x61ABA8

public:
    // 0x423840 | ??0RadialGauge@@QAE@XZ
    ARTS_IMPORT RadialGauge();

    // 0x424170 | ??_ERadialGauge@@UAEPAXI@Z
    // 0x424170 | ??_GRadialGauge@@UAEPAXI@Z
    // 0x422F10 | ??1RadialGauge@@UAE@XZ | inline
    ARTS_IMPORT ~RadialGauge() override;

    // 0x423910 | ?AddWidgets@RadialGauge@@UAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(class Bank* arg1) override;

    // 0x423A40 | ?Cull@RadialGauge@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x4238B0 | ?Init@RadialGauge@@QAEXPAD0PAM1M@Z
    ARTS_IMPORT void Init(char* arg1, char* arg2, f32* arg3, f32* arg4, f32 arg5);

    // 0x423920 | ?Update@RadialGauge@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0xAC];
};

check_size(RadialGauge, 0xCC);

struct mmLinearGauge
{
public:
    // 0x423A70 | ??0mmLinearGauge@@QAE@XZ
    ARTS_IMPORT mmLinearGauge();

    // 0x423A80 | ??1mmLinearGauge@@QAE@XZ
    ARTS_IMPORT ~mmLinearGauge();

    // 0x423BA0 | ?Draw@mmLinearGauge@@QAEXXZ
    ARTS_IMPORT void Draw();

    // 0x423A90 | ?Init@mmLinearGauge@@QAEXPADPAM11HPAVmmExternalView@@@Z
    ARTS_IMPORT void Init(char* arg1, f32* arg2, f32* arg3, f32* arg4, i32 arg5, class mmExternalView* arg6);

    u8 gap0[0x34];
};

check_size(mmLinearGauge, 0x34);

struct mmRadGauge
{
public:
    // 0x423CB0 | ?Draw@mmRadGauge@@QAEXXZ | unused
    ARTS_IMPORT void Draw();

    // 0x423C30 | ?Init@mmRadGauge@@QAEXPAM0PAVmmExternalView@@HI@Z | unused
    ARTS_IMPORT void Init(f32* arg1, f32* arg2, class mmExternalView* arg3, i32 arg4, u32 arg5);

    // 0x423C60 | ?ResChange@mmRadGauge@@QAEXXZ
    ARTS_IMPORT void ResChange();

    u8 gap0[0x3C];
};

check_size(mmRadGauge, 0x3C);

struct mmGearIndicator
{
public:
    // 0x423F10 | ?Draw@mmGearIndicator@@QAEXXZ
    ARTS_IMPORT void Draw();

    // 0x423DE0 | ?Init@mmGearIndicator@@QAEXPAVmmExternalView@@PAVmmPlayer@@@Z
    ARTS_IMPORT void Init(class mmExternalView* arg1, class mmPlayer* arg2);

    u8 gap0[0x40];
};

check_size(mmGearIndicator, 0x40);

struct mmSpeedIndicator
{
public:
    // 0x424020 | ?Draw@mmSpeedIndicator@@QAEXXZ
    ARTS_IMPORT void Draw();

    // 0x423F90 | ?Init@mmSpeedIndicator@@QAEXPAVmmExternalView@@PAVmmCarSim@@@Z
    ARTS_IMPORT void Init(class mmExternalView* arg1, class mmCarSim* arg2);

    u8 gap0[0x38];
};

check_size(mmSpeedIndicator, 0x38);
