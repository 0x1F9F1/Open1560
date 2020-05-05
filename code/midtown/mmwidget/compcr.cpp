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

define_dummy_symbol(mmwidget_compcr);

#include "compcr.h"

mmCompCRPlayer::mmCompCRPlayer()
{
    unimplemented();
}

mmCompCRPlayer::~mmCompCRPlayer()
{
    unimplemented(arg1);
}

void mmCompCRPlayer::Cull()
{
    return stub<thiscall_t<void, mmCompCRPlayer*>>(0xB7770_Offset, this);
}

void mmCompCRPlayer::Init(char* arg1, i32 arg2, char* arg3, i32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, mmCompCRPlayer*, char*, i32, char*, i32, i32>>(
        0xB73D0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void mmCompCRPlayer::InitTitle(f32 arg1, f32 arg2, f32 arg3, f32 arg4, struct LocString* arg5, struct LocString* arg6,
    struct LocString* arg7, struct LocString* arg8, i32 arg9)
{
    return stub<thiscall_t<void, mmCompCRPlayer*, f32, f32, f32, f32, struct LocString*, struct LocString*,
        struct LocString*, struct LocString*, i32>>(
        0xB7500_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}

void mmCompCRPlayer::LoadBitmap(char* arg1)
{
    return stub<thiscall_t<void, mmCompCRPlayer*, char*>>(0xB7510_Offset, this, arg1);
}

void mmCompCRPlayer::Reset()
{
    return stub<thiscall_t<void, mmCompCRPlayer*>>(0xB7570_Offset, this);
}

void mmCompCRPlayer::SetGeometry(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, mmCompCRPlayer*, f32, f32, f32, f32>>(0xB7740_Offset, this, arg1, arg2, arg3, arg4);
}

void mmCompCRPlayer::SetPoints(i32 arg1)
{
    return stub<thiscall_t<void, mmCompCRPlayer*, i32>>(0xB7590_Offset, this, arg1);
}

void mmCompCRPlayer::SetPosition(class mmTextNode* arg1, i32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmCompCRPlayer*, class mmTextNode*, i32, f32>>(0xB76B0_Offset, this, arg1, arg2, arg3);
}

void mmCompCRPlayer::SetSubwidgetGeometry()
{
    return stub<thiscall_t<void, mmCompCRPlayer*>>(0xB75B0_Offset, this);
}

void mmCompCRPlayer::Update()
{
    return stub<thiscall_t<void, mmCompCRPlayer*>>(0xB7580_Offset, this);
}
