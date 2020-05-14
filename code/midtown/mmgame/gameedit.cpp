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

define_dummy_symbol(mmgame_gameedit);

#include "gameedit.h"

mmGameEdit::mmGameEdit()
{
    unimplemented();
}

mmGameEdit::~mmGameEdit()
{
    unimplemented();
}

void mmGameEdit::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmGameEdit*, class Bank*>>(0x412860, this, arg1);
}

void mmGameEdit::ChangeWPCallback()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x412B20, this);
}

class MetaClass* mmGameEdit::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmGameEdit*>>(0x412D00, this);
}

class mmWaypoints* mmGameEdit::GetWaypoints()
{
    return stub<thiscall_t<class mmWaypoints*, mmGameEdit*>>(0x412EE0, this);
}

i32 mmGameEdit::Init()
{
    return stub<thiscall_t<i32, mmGameEdit*>>(0x4122D0, this);
}

void mmGameEdit::InitGameObjects()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x412430, this);
}

void mmGameEdit::InitHUD()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x4123F0, this);
}

void mmGameEdit::InitMyPlayer()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x412380, this);
}

void mmGameEdit::InitOtherPlayers()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x412EC0, this);
}

void mmGameEdit::NextRace()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x412ED0, this);
}

void mmGameEdit::RegisterMapObjects()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x412520, this);
}

void mmGameEdit::Reset()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x412760, this);
}

void mmGameEdit::SetWPCallback()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x412A80, this);
}

void mmGameEdit::Update()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x4127F0, this);
}

void mmGameEdit::UpdateDebugKeyInput(i32 arg1)
{
    return stub<thiscall_t<void, mmGameEdit*, i32>>(0x412570, this, arg1);
}

void mmGameEdit::UpdateGame()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x412820, this);
}

void mmGameEdit::UpdateGameInput(i32 arg1)
{
    return stub<thiscall_t<void, mmGameEdit*, i32>>(0x412810, this, arg1);
}

void mmGameEdit::DeclareFields()
{
    return stub<cdecl_t<void>>(0x412B80);
}
