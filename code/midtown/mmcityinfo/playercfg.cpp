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

define_dummy_symbol(mmcityinfo_playercfg);

#include "playercfg.h"

mmPlayerConfig::mmPlayerConfig()
{
    unimplemented();
}

mmPlayerConfig::~mmPlayerConfig()
{
    unimplemented(arg1);
}

void mmPlayerConfig::operator=(class mmPlayerConfig& arg1)
{
    return stub<thiscall_t<void, mmPlayerConfig*, class mmPlayerConfig&>>(0xCDB10_Offset, this, arg1);
}

void mmPlayerConfig::DefaultAudio()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0xCE800_Offset, this);
}

void mmPlayerConfig::DefaultControls()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0xCE910_Offset, this);
}

void mmPlayerConfig::DefaultGraphics()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0xCE9C0_Offset, this);
}

void mmPlayerConfig::DefaultViewSettings()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0xCE970_Offset, this);
}

void mmPlayerConfig::GetAudio()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0xCE650_Offset, this);
}

class MetaClass* mmPlayerConfig::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmPlayerConfig*>>(0xCEE70_Offset, this);
}

void mmPlayerConfig::GetControls()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0xCE6C0_Offset, this);
}

void mmPlayerConfig::GetGraphics()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0xCE630_Offset, this);
}

void mmPlayerConfig::GetViewSettings()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0xCE7A0_Offset, this);
}

i32 mmPlayerConfig::Load(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerConfig*, char*>>(0xCDC90_Offset, this, arg1);
}

i32 mmPlayerConfig::LoadBinary(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerConfig*, char*>>(0xCDD60_Offset, this, arg1);
}

void mmPlayerConfig::Reset()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0xCE9B0_Offset, this);
}

i32 mmPlayerConfig::Save(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmPlayerConfig*, char*, i32>>(0xCE240_Offset, this, arg1, arg2);
}

i32 mmPlayerConfig::SaveBinary(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerConfig*, char*>>(0xCDFE0_Offset, this, arg1);
}

void mmPlayerConfig::SetAudio()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0xCE2E0_Offset, this);
}

void mmPlayerConfig::SetControls()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0xCE450_Offset, this);
}

void mmPlayerConfig::SetDefaults()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0xCE230_Offset, this);
}

void mmPlayerConfig::SetGraphics()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0xCE640_Offset, this);
}

void mmPlayerConfig::SetViewSettings()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0xCE7D0_Offset, this);
}

void mmPlayerConfig::DeclareFields()
{
    return stub<cdecl_t<void>>(0xCE9E0_Offset);
}

void mmGfxCFG::Get()
{
    return stub<thiscall_t<void, mmGfxCFG*>>(0xCE540_Offset, this);
}

void mmGfxCFG::Set()
{
    return stub<thiscall_t<void, mmGfxCFG*>>(0xCE5B0_Offset, this);
}

mmCtrlCFG::~mmCtrlCFG()
{
    unimplemented();
}
