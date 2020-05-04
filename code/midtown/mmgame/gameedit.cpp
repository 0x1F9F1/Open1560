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
    return stub<thiscall_t<void, mmGameEdit*, class Bank*>>(0x12860_Offset, this, arg1);
}

void mmGameEdit::ChangeWPCallback()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x12B20_Offset, this);
}

class MetaClass* mmGameEdit::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmGameEdit*>>(0x12D00_Offset, this);
}

class mmWaypoints* mmGameEdit::GetWaypoints()
{
    return stub<thiscall_t<class mmWaypoints*, mmGameEdit*>>(0x12EE0_Offset, this);
}

i32 mmGameEdit::Init()
{
    return stub<thiscall_t<i32, mmGameEdit*>>(0x122D0_Offset, this);
}

void mmGameEdit::InitGameObjects()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x12430_Offset, this);
}

void mmGameEdit::InitHUD()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x123F0_Offset, this);
}

void mmGameEdit::InitMyPlayer()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x12380_Offset, this);
}

void mmGameEdit::InitOtherPlayers()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x12EC0_Offset, this);
}

void mmGameEdit::NextRace()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x12ED0_Offset, this);
}

void mmGameEdit::RegisterMapObjects()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x12520_Offset, this);
}

void mmGameEdit::Reset()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x12760_Offset, this);
}

void mmGameEdit::SetWPCallback()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x12A80_Offset, this);
}

void mmGameEdit::Update()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x127F0_Offset, this);
}

void mmGameEdit::UpdateDebugKeyInput(i32 arg1)
{
    return stub<thiscall_t<void, mmGameEdit*, i32>>(0x12570_Offset, this, arg1);
}

void mmGameEdit::UpdateGame()
{
    return stub<thiscall_t<void, mmGameEdit*>>(0x12820_Offset, this);
}

void mmGameEdit::UpdateGameInput(i32 arg1)
{
    return stub<thiscall_t<void, mmGameEdit*, i32>>(0x12810_Offset, this, arg1);
}

void mmGameEdit::DeclareFields()
{
    return stub<cdecl_t<void>>(0x12B80_Offset);
}

define_dummy_symbol(mmgame_gameedit);
