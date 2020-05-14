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

define_dummy_symbol(arts7_camera);

#include "camera.h"

asCamera::asCamera()
{
    unimplemented();
}

asCamera::~asCamera()
{
    unimplemented();
}

void asCamera::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asCamera*, class Bank*>>(0x52A040, this, arg1);
}

void asCamera::DrawBegin()
{
    return stub<thiscall_t<void, asCamera*>>(0x5297D0, this);
}

void asCamera::DrawEnd()
{
    return stub<thiscall_t<void, asCamera*>>(0x5299C0, this);
}

void asCamera::FadeIn(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, asCamera*, f32, i32>>(0x529D40, this, arg1, arg2);
}

void asCamera::FadeOut(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, asCamera*, f32, i32>>(0x529CE0, this, arg1, arg2);
}

void asCamera::FileIO(class MiniParser* arg1)
{
    return stub<thiscall_t<void, asCamera*, class MiniParser*>>(0x529DA0, this, arg1);
}

class MetaClass* asCamera::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asCamera*>>(0x52A810, this);
}

void asCamera::GetNearClip(class Vector3* arg1, class Matrix34& arg2, enum asCamera::kNearClip arg3)
{
    return stub<thiscall_t<void, asCamera*, class Vector3*, class Matrix34&, enum asCamera::kNearClip>>(
        0x529270, this, arg1, arg2, arg3);
}

i32 asCamera::GetViewportHeight()
{
    return stub<thiscall_t<i32, asCamera*>>(0x529CC0, this);
}

i32 asCamera::GetViewportWidth()
{
    return stub<thiscall_t<i32, asCamera*>>(0x529CA0, this);
}

void asCamera::SetAmbient(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, asCamera*, class Vector3 const&>>(0x529F50, this, arg1);
}

void asCamera::SetClipArea(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, asCamera*, f32, f32, f32, f32>>(0x529100, this, arg1, arg2, arg3, arg4);
}

void asCamera::SetFog(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, asCamera*, f32, f32, f32, f32>>(0x529C10, this, arg1, arg2, arg3, arg4);
}

void asCamera::SetLighting(i32 arg1)
{
    return stub<thiscall_t<void, asCamera*, i32>>(0x529230, this, arg1);
}

void asCamera::SetMonochrome(i32 arg1)
{
    return stub<thiscall_t<void, asCamera*, i32>>(0x529F90, this, arg1);
}

void asCamera::SetUnderlay(char* arg1)
{
    return stub<thiscall_t<void, asCamera*, char*>>(0x529C40, this, arg1);
}

void asCamera::SetUnderlayCB(class agiBitmap* arg1, class Callback* arg2)
{
    return stub<thiscall_t<void, asCamera*, class agiBitmap*, class Callback*>>(0x529C80, this, arg1, arg2);
}

void asCamera::SetView(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, asCamera*, f32, f32, f32, f32>>(0x529BC0, this, arg1, arg2, arg3, arg4);
}

void asCamera::SetViewport(f32 arg1, f32 arg2, f32 arg3, f32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, asCamera*, f32, f32, f32, f32, i32>>(0x529B70, this, arg1, arg2, arg3, arg4, arg5);
}

void asCamera::SetWorld(class Matrix34& arg1)
{
    return stub<thiscall_t<void, asCamera*, class Matrix34&>>(0x529250, this, arg1);
}

f32 asCamera::SphereVisible(class Vector3 const& arg1, f32 arg2, f32* arg3)
{
    return stub<thiscall_t<f32, asCamera*, class Vector3 const&, f32, f32*>>(0x529DB0, this, arg1, arg2, arg3);
}

void asCamera::Update()
{
    return stub<thiscall_t<void, asCamera*>>(0x528DF0, this);
}

void asCamera::DeclareFields()
{
    return stub<cdecl_t<void>>(0x52A6A0);
}

void asCamera::Regen()
{
    return stub<thiscall_t<void, asCamera*>>(0x529FB0, this);
}

void FadeItIn(class asCamera* arg1)
{
    return stub<cdecl_t<void, class asCamera*>>(0x529FF0, arg1);
}

void FadeItOut(class asCamera* arg1)
{
    return stub<cdecl_t<void, class asCamera*>>(0x529FD0, arg1);
}

void FritzIt(class asCamera* arg1)
{
    return stub<cdecl_t<void, class asCamera*>>(0x52A010, arg1);
}

void ViewIt(class asCamera* arg1)
{
    return stub<cdecl_t<void, class asCamera*>>(0x52A020, arg1);
}
