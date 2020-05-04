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
    return stub<thiscall_t<void, asCamera*, class Bank*>>(0x12A040_Offset, this, arg1);
}

void asCamera::DrawBegin()
{
    return stub<thiscall_t<void, asCamera*>>(0x1297D0_Offset, this);
}

void asCamera::DrawEnd()
{
    return stub<thiscall_t<void, asCamera*>>(0x1299C0_Offset, this);
}

void asCamera::FadeIn(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, asCamera*, f32, i32>>(0x129D40_Offset, this, arg1, arg2);
}

void asCamera::FadeOut(f32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, asCamera*, f32, i32>>(0x129CE0_Offset, this, arg1, arg2);
}

void asCamera::FileIO(class MiniParser* arg1)
{
    return stub<thiscall_t<void, asCamera*, class MiniParser*>>(0x129DA0_Offset, this, arg1);
}

class MetaClass* asCamera::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asCamera*>>(0x12A810_Offset, this);
}

void asCamera::GetNearClip(class Vector3* arg1, class Matrix34& arg2, enum asCamera::kNearClip arg3)
{
    return stub<thiscall_t<void, asCamera*, class Vector3*, class Matrix34&, enum asCamera::kNearClip>>(
        0x129270_Offset, this, arg1, arg2, arg3);
}

i32 asCamera::GetViewportHeight()
{
    return stub<thiscall_t<i32, asCamera*>>(0x129CC0_Offset, this);
}

i32 asCamera::GetViewportWidth()
{
    return stub<thiscall_t<i32, asCamera*>>(0x129CA0_Offset, this);
}

void asCamera::SetAmbient(class Vector3 const& arg1)
{
    return stub<thiscall_t<void, asCamera*, class Vector3 const&>>(0x129F50_Offset, this, arg1);
}

void asCamera::SetClipArea(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, asCamera*, f32, f32, f32, f32>>(0x129100_Offset, this, arg1, arg2, arg3, arg4);
}

void asCamera::SetFog(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, asCamera*, f32, f32, f32, f32>>(0x129C10_Offset, this, arg1, arg2, arg3, arg4);
}

void asCamera::SetLighting(i32 arg1)
{
    return stub<thiscall_t<void, asCamera*, i32>>(0x129230_Offset, this, arg1);
}

void asCamera::SetMonochrome(i32 arg1)
{
    return stub<thiscall_t<void, asCamera*, i32>>(0x129F90_Offset, this, arg1);
}

void asCamera::SetUnderlay(char* arg1)
{
    return stub<thiscall_t<void, asCamera*, char*>>(0x129C40_Offset, this, arg1);
}

void asCamera::SetUnderlayCB(class agiBitmap* arg1, class Callback* arg2)
{
    return stub<thiscall_t<void, asCamera*, class agiBitmap*, class Callback*>>(0x129C80_Offset, this, arg1, arg2);
}

void asCamera::SetView(f32 arg1, f32 arg2, f32 arg3, f32 arg4)
{
    return stub<thiscall_t<void, asCamera*, f32, f32, f32, f32>>(0x129BC0_Offset, this, arg1, arg2, arg3, arg4);
}

void asCamera::SetViewport(f32 arg1, f32 arg2, f32 arg3, f32 arg4, i32 arg5)
{
    return stub<thiscall_t<void, asCamera*, f32, f32, f32, f32, i32>>(
        0x129B70_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void asCamera::SetWorld(class Matrix34& arg1)
{
    return stub<thiscall_t<void, asCamera*, class Matrix34&>>(0x129250_Offset, this, arg1);
}

f32 asCamera::SphereVisible(class Vector3 const& arg1, f32 arg2, f32* arg3)
{
    return stub<thiscall_t<f32, asCamera*, class Vector3 const&, f32, f32*>>(0x129DB0_Offset, this, arg1, arg2, arg3);
}

void asCamera::Update()
{
    return stub<thiscall_t<void, asCamera*>>(0x128DF0_Offset, this);
}

void asCamera::DeclareFields()
{
    return stub<cdecl_t<void>>(0x12A6A0_Offset);
}

void asCamera::Regen()
{
    return stub<thiscall_t<void, asCamera*>>(0x129FB0_Offset, this);
}

void FadeItIn(class asCamera* arg1)
{
    return stub<cdecl_t<void, class asCamera*>>(0x129FF0_Offset, arg1);
}

void FadeItOut(class asCamera* arg1)
{
    return stub<cdecl_t<void, class asCamera*>>(0x129FD0_Offset, arg1);
}

void FritzIt(class asCamera* arg1)
{
    return stub<cdecl_t<void, class asCamera*>>(0x12A010_Offset, arg1);
}

void ViewIt(class asCamera* arg1)
{
    return stub<cdecl_t<void, class asCamera*>>(0x12A020_Offset, arg1);
}

define_dummy_symbol(arts7_camera);
