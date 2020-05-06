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

define_dummy_symbol(mmeffects_mmtext);

#include "mmtext.h"

mmTextNode::mmTextNode()
{
    unimplemented();
}

mmTextNode::~mmTextNode()
{
    unimplemented(arg1);
}

i32 mmTextNode::AddText(void* arg1, struct LocString* arg2, i32 arg3, f32 arg4, f32 arg5)
{
    return stub<thiscall_t<i32, mmTextNode*, void*, struct LocString*, i32, f32, f32>>(
        0x4FF930, this, arg1, arg2, arg3, arg4, arg5);
}

void mmTextNode::Cull()
{
    return stub<thiscall_t<void, mmTextNode*>>(0x4FFD90, this);
}

u32 mmTextNode::GetFGColor()
{
    return stub<thiscall_t<u32, mmTextNode*>>(0x4FF750, this);
}

void mmTextNode::GetTextDimensions(void* arg1, struct LocString* arg2, f32& arg3, f32& arg4)
{
    return stub<thiscall_t<void, mmTextNode*, void*, struct LocString*, f32&, f32&>>(
        0x4FF790, this, arg1, arg2, arg3, arg4);
}

void mmTextNode::Init(f32 arg1, f32 arg2, f32 arg3, f32 arg4, i32 arg5, i32 arg6)
{
    return stub<thiscall_t<void, mmTextNode*, f32, f32, f32, f32, i32, i32>>(
        0x4FF540, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void mmTextNode::Printf(char const* arg1, ...)
{
    unimplemented(arg1);
}

void mmTextNode::RenderText(class agiSurfaceDesc* arg1, struct mmTextData* arg2, i32 arg3, u32 arg4)
{
    return stub<thiscall_t<void, mmTextNode*, class agiSurfaceDesc*, struct mmTextData*, i32, u32>>(
        0x4FFB60, this, arg1, arg2, arg3, arg4);
}

void mmTextNode::SetBGColor(class Vector4& arg1)
{
    return stub<thiscall_t<void, mmTextNode*, class Vector4&>>(0x4FF690, this, arg1);
}

void mmTextNode::SetEffects(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmTextNode*, i32, i32>>(0x4FF760, this, arg1, arg2);
}

void mmTextNode::SetFGColor(class Vector4& arg1)
{
    return stub<thiscall_t<void, mmTextNode*, class Vector4&>>(0x4FF6F0, this, arg1);
}

void mmTextNode::SetPosition(i32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmTextNode*, i32, f32, f32>>(0x4FFAA0, this, arg1, arg2, arg3);
}

void mmTextNode::SetString(i32 arg1, struct LocString* arg2)
{
    return stub<thiscall_t<void, mmTextNode*, i32, struct LocString*>>(0x4FFA40, this, arg1, arg2);
}

void mmTextNode::SetTextPosition(i32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<void, mmTextNode*, i32, f32, f32>>(0x4FF8D0, this, arg1, arg2, arg3);
}

void mmTextNode::Update()
{
    return stub<thiscall_t<void, mmTextNode*>>(0x4FFB30, this);
}

void ddGDIFlip()
{
    return stub<cdecl_t<void>>(0x4FEE30);
}

mmText::mmText()
{
    unimplemented();
}

mmText::~mmText()
{
    unimplemented();
}

void mmText::Draw(class agiSurfaceDesc* arg1, f32 arg2, f32 arg3, char* arg4, void* arg5)
{
    return stub<thiscall_t<void, mmText*, class agiSurfaceDesc*, f32, f32, char*, void*>>(
        0x4FF2D0, this, arg1, arg2, arg3, arg4, arg5);
}

void mmText::Draw2(class agiSurfaceDesc* arg1, f32 arg2, f32 arg3, char* arg4, void* arg5, u32 arg6)
{
    return stub<thiscall_t<void, mmText*, class agiSurfaceDesc*, f32, f32, char*, void*, u32>>(
        0x4FF360, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class agiBitmap* mmText::CreateFitBitmap(char* arg1, void* arg2, i32 arg3, i32 arg4)
{
    return stub<cdecl_t<class agiBitmap*, char*, void*, i32, i32>>(0x4FF0C0, arg1, arg2, arg3, arg4);
}

void* mmText::CreateFont(char* arg1, i32 arg2)
{
    return stub<cdecl_t<void*, char*, i32>>(0x4FEF30, arg1, arg2);
}

void* mmText::CreateLocFont(struct LocString* arg1, i32 arg2)
{
    return stub<cdecl_t<void*, struct LocString*, i32>>(0x4FEE60, arg1, arg2);
}

void mmText::DeleteFont(void* arg1)
{
    return stub<cdecl_t<void, void*>>(0x4FEF60, arg1);
}

void* mmText::GetDC(class agiSurfaceDesc* arg1)
{
    return stub<cdecl_t<void*, class agiSurfaceDesc*>>(0x4FEF70, arg1);
}

void mmText::ReleaseDC()
{
    return stub<cdecl_t<void>>(0x4FF010);
}
