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

define_dummy_symbol(mmeffects_card2d);

#include "card2d.h"

Card2D::Card2D()
{
    unimplemented();
}

Card2D::~Card2D()
{
    unimplemented();
}

void Card2D::Init(class asCamera* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6)
{
    return stub<thiscall_t<void, Card2D*, class asCamera*, f32, f32, f32, f32, f32>>(
        0x4FE170, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void Card2D::SetAlpha(f32 arg1)
{
    return stub<thiscall_t<void, Card2D*, f32>>(0x4FE2C0, this, arg1);
}

void Card2D::SetColor(class Vector4 arg1)
{
    return stub<thiscall_t<void, Card2D*, class Vector4>>(0x49C530, this, arg1);
}

void Card2D::SetDimensions(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, Card2D*, f32, f32, f32, f32>>(0x4FE1B0, this, arg1, arg2, arg3, arg4);
}

void Card2D::SetPosition(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, Card2D*, f32, f32>>(0x4FE2A0, this, arg1, arg2);
}

void Card2D::Update()
{
    return stub<thiscall_t<void, Card2D*>>(0x4FE320, this);
}

void Card2D::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, Card2D*, class Bank*>>(0x4FE540, this, arg1);
}

void Card2D::Cull()
{
    return stub<thiscall_t<void, Card2D*>>(0x4FE330, this);
}
