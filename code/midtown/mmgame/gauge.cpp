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

define_dummy_symbol(mmgame_gauge);

#include "gauge.h"

RadialGauge::RadialGauge()
{
    unimplemented();
}

RadialGauge::~RadialGauge()
{
    unimplemented();
}

void RadialGauge::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, RadialGauge*, class Bank*>>(0x423910, this, arg1);
}

void RadialGauge::Cull()
{
    return stub<thiscall_t<void, RadialGauge*>>(0x423A40, this);
}

void RadialGauge::Init(char* arg1, char* arg2, f32* arg3, f32* arg4, f32 arg5)
{
    return stub<thiscall_t<void, RadialGauge*, char*, char*, f32*, f32*, f32>>(
        0x4238B0, this, arg1, arg2, arg3, arg4, arg5);
}

void RadialGauge::Update()
{
    return stub<thiscall_t<void, RadialGauge*>>(0x423920, this);
}

mmLinearGauge::mmLinearGauge()
{
    unimplemented();
}

mmLinearGauge::~mmLinearGauge()
{
    unimplemented();
}

void mmLinearGauge::Draw()
{
    return stub<thiscall_t<void, mmLinearGauge*>>(0x423BA0, this);
}

void mmLinearGauge::Init(char* arg1, f32* arg2, f32* arg3, f32* arg4, i32 arg5, class mmExternalView* arg6)
{
    return stub<thiscall_t<void, mmLinearGauge*, char*, f32*, f32*, f32*, i32, class mmExternalView*>>(
        0x423A90, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void mmRadGauge::Draw()
{
    return stub<thiscall_t<void, mmRadGauge*>>(0x423CB0, this);
}

void mmRadGauge::Init(f32* arg1, f32* arg2, class mmExternalView* arg3, i32 arg4, u32 arg5)
{
    return stub<thiscall_t<void, mmRadGauge*, f32*, f32*, class mmExternalView*, i32, u32>>(
        0x423C30, this, arg1, arg2, arg3, arg4, arg5);
}

void mmRadGauge::ResChange()
{
    return stub<thiscall_t<void, mmRadGauge*>>(0x423C60, this);
}

void mmGearIndicator::Draw()
{
    return stub<thiscall_t<void, mmGearIndicator*>>(0x423F10, this);
}

void mmGearIndicator::Init(class mmExternalView* arg1, class mmPlayer* arg2)
{
    return stub<thiscall_t<void, mmGearIndicator*, class mmExternalView*, class mmPlayer*>>(0x423DE0, this, arg1, arg2);
}

void mmSpeedIndicator::Draw()
{
    return stub<thiscall_t<void, mmSpeedIndicator*>>(0x424020, this);
}

void mmSpeedIndicator::Init(class mmExternalView* arg1, class mmCarSim* arg2)
{
    return stub<thiscall_t<void, mmSpeedIndicator*, class mmExternalView*, class mmCarSim*>>(
        0x423F90, this, arg1, arg2);
}
