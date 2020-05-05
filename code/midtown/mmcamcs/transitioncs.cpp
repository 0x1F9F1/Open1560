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

define_dummy_symbol(mmcamcs_transitioncs);

#include "transitioncs.h"

TransitionCS::TransitionCS()
{
    unimplemented();
}

TransitionCS::~TransitionCS()
{
    unimplemented(arg1);
}

void TransitionCS::ForceMatrixDelta(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, TransitionCS*, class Vector3 const&>>(0xFBC00_Offset, this, arg1);
}

void TransitionCS::Init(class mmCar* arg1)
{
    return stub<thiscall_t<void, TransitionCS*, class mmCar*>>(0xFB550_Offset, this, arg1);
}

void TransitionCS::NewTransition(class CarCamCS* arg1, class CarCamCS* arg2)
{
    return stub<thiscall_t<void, TransitionCS*, class CarCamCS*, class CarCamCS*>>(0xFBC30_Offset, this, arg1, arg2);
}

void TransitionCS::NextTransition(class CarCamCS* arg1)
{
    return stub<thiscall_t<void, TransitionCS*, class CarCamCS*>>(0xFBC60_Offset, this, arg1);
}

void TransitionCS::Reset()
{
    return stub<thiscall_t<void, TransitionCS*>>(0xFB570_Offset, this);
}

void TransitionCS::ReverseTransition()
{
    return stub<thiscall_t<void, TransitionCS*>>(0xFBD50_Offset, this);
}

void TransitionCS::StartNextTransition()
{
    return stub<thiscall_t<void, TransitionCS*>>(0xFBD10_Offset, this);
}

void TransitionCS::StartTransition()
{
    return stub<thiscall_t<void, TransitionCS*>>(0xFBCA0_Offset, this);
}

void TransitionCS::Update()
{
    return stub<thiscall_t<void, TransitionCS*>>(0xFB580_Offset, this);
}
