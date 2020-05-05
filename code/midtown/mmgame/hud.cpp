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

define_dummy_symbol(mmgame_hud);

#include "hud.h"

mmHUD::mmHUD()
{
    unimplemented();
}

mmHUD::~mmHUD()
{
    unimplemented(arg1);
}

void mmHUD::ActivateDash()
{
    return stub<thiscall_t<void, mmHUD*>>(0x5800_Offset, this);
}

void mmHUD::ActivateGold()
{
    return stub<thiscall_t<void, mmHUD*>>(0x5FA0_Offset, this);
}

void mmHUD::AddPlayer(char* arg1, u32 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<void, mmHUD*, char*, u32, i32, i32>>(0x5F30_Offset, this, arg1, arg2, arg3, arg4);
}

void mmHUD::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmHUD*, class Bank*>>(0x6170_Offset, this, arg1);
}

void mmHUD::Cull()
{
    return stub<thiscall_t<void, mmHUD*>>(0x5D30_Offset, this);
}

void mmHUD::DeactivateDash()
{
    return stub<thiscall_t<void, mmHUD*>>(0x5830_Offset, this);
}

void mmHUD::DeactivateGold()
{
    return stub<thiscall_t<void, mmHUD*>>(0x5FB0_Offset, this);
}

void mmHUD::Disable(i32 arg1)
{
    return stub<thiscall_t<void, mmHUD*, i32>>(0x5700_Offset, this, arg1);
}

void mmHUD::Enable()
{
    return stub<thiscall_t<void, mmHUD*>>(0x56C0_Offset, this);
}

class MetaClass* mmHUD::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmHUD*>>(0x68D0_Offset, this);
}

void mmHUD::GetPosHdg(class Vector4& arg1)
{
    return stub<thiscall_t<void, mmHUD*, class Vector4&>>(0x6060_Offset, this, arg1);
}

void mmHUD::GetTime(char* arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmHUD*, char*, f32>>(0x5FC0_Offset, this, arg1, arg2);
}

void mmHUD::Init(char* arg1, class mmPlayer* arg2)
{
    return stub<thiscall_t<void, mmHUD*, char*, class mmPlayer*>>(0x53E0_Offset, this, arg1, arg2);
}

i32 mmHUD::IsDashActive()
{
    return stub<thiscall_t<i32, mmHUD*>>(0x5860_Offset, this);
}

void mmHUD::PlayNetAlert()
{
    return stub<thiscall_t<void, mmHUD*>>(0x5FE0_Offset, this);
}

void mmHUD::PostChatMessage(char* arg1)
{
    return stub<thiscall_t<void, mmHUD*, char*>>(0x5060_Offset, this, arg1);
}

void mmHUD::RecordPosition(char* arg1)
{
    return stub<thiscall_t<void, mmHUD*, char*>>(0x60F0_Offset, this, arg1);
}

void mmHUD::RemovePlayer(u32 arg1)
{
    return stub<thiscall_t<void, mmHUD*, u32>>(0x5F80_Offset, this, arg1);
}

void mmHUD::ResChange(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmHUD*, i32, i32>>(0x50C0_Offset, this, arg1, arg2);
}

void mmHUD::Reset()
{
    return stub<thiscall_t<void, mmHUD*>>(0x5870_Offset, this);
}

void mmHUD::ResetTimers()
{
    return stub<thiscall_t<void, mmHUD*>>(0x5360_Offset, this);
}

void mmHUD::SetLapTime(i32 arg1, f32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmHUD*, i32, f32, i32>>(0x5E40_Offset, this, arg1, arg2, arg3);
}

void mmHUD::SetMessage(struct LocString* arg1, f32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmHUD*, struct LocString*, f32, i32>>(0x5EA0_Offset, this, arg1, arg2, arg3);
}

void mmHUD::SetMessage2(struct LocString* arg1)
{
    return stub<thiscall_t<void, mmHUD*, struct LocString*>>(0x5EE0_Offset, this, arg1);
}

void mmHUD::SetScore(char* arg1)
{
    return stub<thiscall_t<void, mmHUD*, char*>>(0x5F10_Offset, this, arg1);
}

void mmHUD::SetScore(u32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmHUD*, u32, i32>>(0x5F60_Offset, this, arg1, arg2);
}

void mmHUD::SetStandings(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmHUD*, i32, i32>>(0x5E00_Offset, this, arg1, arg2);
}

void mmHUD::SetWPCleared(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmHUD*, i32, i32>>(0x5E80_Offset, this, arg1, arg2);
}

void mmHUD::ShowClockTime()
{
    return stub<thiscall_t<void, mmHUD*>>(0x5390_Offset, this);
}

void mmHUD::StartTimers()
{
    return stub<thiscall_t<void, mmHUD*>>(0x5320_Offset, this);
}

void mmHUD::StopTimers()
{
    return stub<thiscall_t<void, mmHUD*>>(0x5340_Offset, this);
}

void mmHUD::Toggle()
{
    return stub<thiscall_t<void, mmHUD*>>(0x5750_Offset, this);
}

void mmHUD::ToggleDash()
{
    return stub<thiscall_t<void, mmHUD*>>(0x57C0_Offset, this);
}

void mmHUD::ToggleExternalView()
{
    return stub<thiscall_t<void, mmHUD*>>(0x5770_Offset, this);
}

void mmHUD::ToggleMirror()
{
    return stub<thiscall_t<void, mmHUD*>>(0x5D10_Offset, this);
}

void mmHUD::TogglePositionDisplay(i32 arg1)
{
    return stub<thiscall_t<void, mmHUD*, i32>>(0x6000_Offset, this, arg1);
}

void mmHUD::Update()
{
    return stub<thiscall_t<void, mmHUD*>>(0x5910_Offset, this);
}

void mmHUD::UpdatePaused()
{
    return stub<thiscall_t<void, mmHUD*>>(0x5CE0_Offset, this);
}

void mmHUD::DeclareFields()
{
    return stub<cdecl_t<void>>(0x6760_Offset);
}

mmTimer::mmTimer()
{
    unimplemented();
}

mmTimer::~mmTimer()
{
    unimplemented(arg1);
}

f32 mmTimer::GetTime()
{
    return stub<thiscall_t<f32, mmTimer*>>(0x6230_Offset, this);
}

void mmTimer::Init(i32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmTimer*, i32, f32>>(0x6210_Offset, this, arg1, arg2);
}

void mmTimer::Reset()
{
    return stub<thiscall_t<void, mmTimer*>>(0x6290_Offset, this);
}

void mmTimer::Start()
{
    return stub<thiscall_t<void, mmTimer*>>(0x62A0_Offset, this);
}

void mmTimer::StartStop()
{
    return stub<thiscall_t<void, mmTimer*>>(0x62C0_Offset, this);
}

void mmTimer::Stop()
{
    return stub<thiscall_t<void, mmTimer*>>(0x62B0_Offset, this);
}

void mmTimer::Update()
{
    return stub<thiscall_t<void, mmTimer*>>(0x6240_Offset, this);
}

mmArrow::mmArrow()
{
    unimplemented();
}

mmArrow::~mmArrow()
{
    unimplemented(arg1);
}

void mmArrow::Init(class Matrix34* arg1)
{
    return stub<thiscall_t<void, mmArrow*, class Matrix34*>>(0x64C0_Offset, this, arg1);
}

void mmArrow::Reset()
{
    return stub<thiscall_t<void, mmArrow*>>(0x64D0_Offset, this);
}

void mmArrow::SetInterest(class Vector3* arg1)
{
    return stub<thiscall_t<void, mmArrow*, class Vector3*>>(0x64E0_Offset, this, arg1);
}

void mmArrow::Update()
{
    return stub<thiscall_t<void, mmArrow*>>(0x6560_Offset, this);
}

void mmArrow::ReColorArrow(i32 arg1)
{
    return stub<thiscall_t<void, mmArrow*, i32>>(0x64F0_Offset, this, arg1);
}
