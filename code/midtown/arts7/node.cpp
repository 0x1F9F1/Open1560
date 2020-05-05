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

define_dummy_symbol(arts7_node);

#include "node.h"

asNode::asNode()
{
    unimplemented();
}

asNode::~asNode()
{
    unimplemented(arg1);
}

void asNode::Update()
{
    return stub<thiscall_t<void, asNode*>>(0x123890_Offset, this);
}

void asNode::Reset()
{
    return stub<thiscall_t<void, asNode*>>(0x123960_Offset, this);
}

void asNode::ResChange(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, asNode*, i32, i32>>(0x123980_Offset, this, arg1, arg2);
}

void asNode::UpdatePaused()
{
    return stub<thiscall_t<void, asNode*>>(0x4BB0_Offset, this);
}

void asNode::Load()
{
    return stub<thiscall_t<void, asNode*>>(0x124150_Offset, this);
}

void asNode::Save()
{
    return stub<thiscall_t<void, asNode*>>(0x123F70_Offset, this);
}

void asNode::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asNode*, class Bank*>>(0x124330_Offset, this, arg1);
}

void asNode::OpenWidgets(char* arg1, class bkWindow* arg2)
{
    return stub<thiscall_t<void, asNode*, char*, class bkWindow*>>(0x1243E0_Offset, this, arg1, arg2);
}

void asNode::CloseWidgets()
{
    return stub<thiscall_t<void, asNode*>>(0x1243F0_Offset, this);
}

void asNode::AddButton(class Bank* arg1, i32& arg2)
{
    return stub<thiscall_t<void, asNode*, class Bank*, i32&>>(0x124400_Offset, this, arg1, arg2);
}

i32 asNode::AddChild(class asNode* arg1)
{
    return stub<thiscall_t<i32, asNode*, class asNode*>>(0x123A70_Offset, this, arg1);
}

class asNode* asNode::GetChild(i32 arg1)
{
    return stub<thiscall_t<class asNode*, asNode*, i32>>(0x123C80_Offset, this, arg1);
}

class MetaClass* asNode::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asNode*>>(0x124600_Offset, this);
}

class asNode* asNode::GetLastChild()
{
    return stub<thiscall_t<class asNode*, asNode*>>(0x123CC0_Offset, this);
}

class asNode* asNode::GetNext()
{
    return stub<thiscall_t<class asNode*, asNode*>>(0x123CB0_Offset, this);
}

char* asNode::GetNodeType()
{
    return stub<thiscall_t<char*, asNode*>>(0x123DC0_Offset, this);
}

class asNode* asNode::GetParent(class MetaClass* arg1)
{
    return stub<thiscall_t<class asNode*, asNode*, class MetaClass*>>(0x123D80_Offset, this, arg1);
}

i32 asNode::InsertChild(i32 arg1, class asNode* arg2)
{
    return stub<thiscall_t<i32, asNode*, i32, class asNode*>>(0x123AF0_Offset, this, arg1, arg2);
}

i32 asNode::Load(char* arg1)
{
    return stub<thiscall_t<i32, asNode*, char*>>(0x123DD0_Offset, this, arg1);
}

i32 asNode::NumChildren()
{
    return stub<thiscall_t<i32, asNode*>>(0x123D00_Offset, this);
}

void asNode::PerfReport(class Stream* arg1, i32 arg2)
{
    return stub<thiscall_t<void, asNode*, class Stream*, i32>>(0x1239D0_Offset, this, arg1, arg2);
}

void asNode::RemoveAllChildren()
{
    return stub<thiscall_t<void, asNode*>>(0x123C60_Offset, this);
}

i32 asNode::RemoveChild(class asNode* arg1)
{
    return stub<thiscall_t<i32, asNode*, class asNode*>>(0x123C20_Offset, this, arg1);
}

i32 asNode::RemoveChild(i32 arg1)
{
    return stub<thiscall_t<i32, asNode*, i32>>(0x123B80_Offset, this, arg1);
}

void asNode::ResetTime()
{
    return stub<thiscall_t<void, asNode*>>(0x1239B0_Offset, this);
}

i32 asNode::Save(char* arg1)
{
    return stub<thiscall_t<i32, asNode*, char*>>(0x123EC0_Offset, this, arg1);
}

void asNode::SetName(char* arg1)
{
    return stub<thiscall_t<void, asNode*, char*>>(0x123860_Offset, this, arg1);
}

void asNode::SwitchTo(i32 arg1)
{
    return stub<thiscall_t<void, asNode*, i32>>(0x123D20_Offset, this, arg1);
}

char* asNode::VerifyTree()
{
    return stub<thiscall_t<char*, asNode*>>(0x123440_Offset, this);
}

void asNode::DeclareFields()
{
    return stub<cdecl_t<void>>(0x124410_Offset);
}

struct MetaType* PtrTo(struct MetaType* arg1)
{
    return stub<cdecl_t<struct MetaType*, struct MetaType*>>(0x124610_Offset, arg1);
}
