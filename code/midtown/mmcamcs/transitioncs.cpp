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
    unimplemented();
}

void TransitionCS::ForceMatrixDelta(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, TransitionCS*, class Vector3 const&>>(0x4FBC00, this, arg1);
}

void TransitionCS::Init(class mmCar* arg1)
{
    return stub<thiscall_t<void, TransitionCS*, class mmCar*>>(0x4FB550, this, arg1);
}

void TransitionCS::NewTransition(class CarCamCS* arg1, class CarCamCS* arg2)
{
    return stub<thiscall_t<void, TransitionCS*, class CarCamCS*, class CarCamCS*>>(0x4FBC30, this, arg1, arg2);
}

void TransitionCS::NextTransition(class CarCamCS* arg1)
{
    return stub<thiscall_t<void, TransitionCS*, class CarCamCS*>>(0x4FBC60, this, arg1);
}

void TransitionCS::Reset()
{
    return stub<thiscall_t<void, TransitionCS*>>(0x4FB570, this);
}

void TransitionCS::ReverseTransition()
{
    return stub<thiscall_t<void, TransitionCS*>>(0x4FBD50, this);
}

void TransitionCS::StartNextTransition()
{
    return stub<thiscall_t<void, TransitionCS*>>(0x4FBD10, this);
}

void TransitionCS::StartTransition()
{
    return stub<thiscall_t<void, TransitionCS*>>(0x4FBCA0, this);
}

void TransitionCS::Update()
{
    return stub<thiscall_t<void, TransitionCS*>>(0x4FB580, this);
}
