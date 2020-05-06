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
    return stub<thiscall_t<void, asNode*>>(0x523890, this);
}

void asNode::Reset()
{
    return stub<thiscall_t<void, asNode*>>(0x523960, this);
}

void asNode::ResChange(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, asNode*, i32, i32>>(0x523980, this, arg1, arg2);
}

void asNode::UpdatePaused()
{
    return stub<thiscall_t<void, asNode*>>(0x404BB0, this);
}

void asNode::Load()
{
    return stub<thiscall_t<void, asNode*>>(0x524150, this);
}

void asNode::Save()
{
    return stub<thiscall_t<void, asNode*>>(0x523F70, this);
}

void asNode::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asNode*, class Bank*>>(0x524330, this, arg1);
}

void asNode::OpenWidgets(char* arg1, class bkWindow* arg2)
{
    return stub<thiscall_t<void, asNode*, char*, class bkWindow*>>(0x5243E0, this, arg1, arg2);
}

void asNode::CloseWidgets()
{
    return stub<thiscall_t<void, asNode*>>(0x5243F0, this);
}

void asNode::AddButton(class Bank* arg1, i32& arg2)
{
    return stub<thiscall_t<void, asNode*, class Bank*, i32&>>(0x524400, this, arg1, arg2);
}

i32 asNode::AddChild(class asNode* arg1)
{
    return stub<thiscall_t<i32, asNode*, class asNode*>>(0x523A70, this, arg1);
}

class asNode* asNode::GetChild(i32 arg1)
{
    return stub<thiscall_t<class asNode*, asNode*, i32>>(0x523C80, this, arg1);
}

class MetaClass* asNode::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asNode*>>(0x524600, this);
}

class asNode* asNode::GetLastChild()
{
    return stub<thiscall_t<class asNode*, asNode*>>(0x523CC0, this);
}

class asNode* asNode::GetNext()
{
    return stub<thiscall_t<class asNode*, asNode*>>(0x523CB0, this);
}

char* asNode::GetNodeType()
{
    return stub<thiscall_t<char*, asNode*>>(0x523DC0, this);
}

class asNode* asNode::GetParent(class MetaClass* arg1)
{
    return stub<thiscall_t<class asNode*, asNode*, class MetaClass*>>(0x523D80, this, arg1);
}

i32 asNode::InsertChild(i32 arg1, class asNode* arg2)
{
    return stub<thiscall_t<i32, asNode*, i32, class asNode*>>(0x523AF0, this, arg1, arg2);
}

i32 asNode::Load(char* arg1)
{
    return stub<thiscall_t<i32, asNode*, char*>>(0x523DD0, this, arg1);
}

i32 asNode::NumChildren()
{
    return stub<thiscall_t<i32, asNode*>>(0x523D00, this);
}

void asNode::PerfReport(class Stream* arg1, i32 arg2)
{
    return stub<thiscall_t<void, asNode*, class Stream*, i32>>(0x5239D0, this, arg1, arg2);
}

void asNode::RemoveAllChildren()
{
    return stub<thiscall_t<void, asNode*>>(0x523C60, this);
}

i32 asNode::RemoveChild(class asNode* arg1)
{
    return stub<thiscall_t<i32, asNode*, class asNode*>>(0x523C20, this, arg1);
}

i32 asNode::RemoveChild(i32 arg1)
{
    return stub<thiscall_t<i32, asNode*, i32>>(0x523B80, this, arg1);
}

void asNode::ResetTime()
{
    return stub<thiscall_t<void, asNode*>>(0x5239B0, this);
}

i32 asNode::Save(char* arg1)
{
    return stub<thiscall_t<i32, asNode*, char*>>(0x523EC0, this, arg1);
}

void asNode::SetName(char* arg1)
{
    return stub<thiscall_t<void, asNode*, char*>>(0x523860, this, arg1);
}

void asNode::SwitchTo(i32 arg1)
{
    return stub<thiscall_t<void, asNode*, i32>>(0x523D20, this, arg1);
}

char* asNode::VerifyTree()
{
    return stub<thiscall_t<char*, asNode*>>(0x523440, this);
}

void asNode::DeclareFields()
{
    return stub<cdecl_t<void>>(0x524410);
}

struct MetaType* PtrTo(struct MetaType* arg1)
{
    return stub<cdecl_t<struct MetaType*, struct MetaType*>>(0x524610, arg1);
}
