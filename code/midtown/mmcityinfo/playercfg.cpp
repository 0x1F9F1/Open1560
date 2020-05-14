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
    unimplemented();
}

void mmPlayerConfig::operator=(class mmPlayerConfig& arg1)
{
    return stub<thiscall_t<void, mmPlayerConfig*, class mmPlayerConfig&>>(0x4CDB10, this, arg1);
}

void mmPlayerConfig::DefaultAudio()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0x4CE800, this);
}

void mmPlayerConfig::DefaultControls()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0x4CE910, this);
}

void mmPlayerConfig::DefaultGraphics()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0x4CE9C0, this);
}

void mmPlayerConfig::DefaultViewSettings()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0x4CE970, this);
}

void mmPlayerConfig::GetAudio()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0x4CE650, this);
}

class MetaClass* mmPlayerConfig::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmPlayerConfig*>>(0x4CEE70, this);
}

void mmPlayerConfig::GetControls()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0x4CE6C0, this);
}

void mmPlayerConfig::GetGraphics()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0x4CE630, this);
}

void mmPlayerConfig::GetViewSettings()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0x4CE7A0, this);
}

i32 mmPlayerConfig::Load(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerConfig*, char*>>(0x4CDC90, this, arg1);
}

i32 mmPlayerConfig::LoadBinary(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerConfig*, char*>>(0x4CDD60, this, arg1);
}

void mmPlayerConfig::Reset()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0x4CE9B0, this);
}

i32 mmPlayerConfig::Save(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmPlayerConfig*, char*, i32>>(0x4CE240, this, arg1, arg2);
}

i32 mmPlayerConfig::SaveBinary(char* arg1)
{
    return stub<thiscall_t<i32, mmPlayerConfig*, char*>>(0x4CDFE0, this, arg1);
}

void mmPlayerConfig::SetAudio()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0x4CE2E0, this);
}

void mmPlayerConfig::SetControls()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0x4CE450, this);
}

void mmPlayerConfig::SetDefaults()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0x4CE230, this);
}

void mmPlayerConfig::SetGraphics()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0x4CE640, this);
}

void mmPlayerConfig::SetViewSettings()
{
    return stub<thiscall_t<void, mmPlayerConfig*>>(0x4CE7D0, this);
}

void mmPlayerConfig::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4CE9E0);
}

void mmGfxCFG::Get()
{
    return stub<thiscall_t<void, mmGfxCFG*>>(0x4CE540, this);
}

void mmGfxCFG::Set()
{
    return stub<thiscall_t<void, mmGfxCFG*>>(0x4CE5B0, this);
}

mmCtrlCFG::~mmCtrlCFG()
{
    unimplemented();
}
