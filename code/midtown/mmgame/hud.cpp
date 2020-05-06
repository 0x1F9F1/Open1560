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
    return stub<thiscall_t<void, mmHUD*>>(0x405800, this);
}

void mmHUD::ActivateGold()
{
    return stub<thiscall_t<void, mmHUD*>>(0x405FA0, this);
}

void mmHUD::AddPlayer(char* arg1, u32 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<void, mmHUD*, char*, u32, i32, i32>>(0x405F30, this, arg1, arg2, arg3, arg4);
}

void mmHUD::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmHUD*, class Bank*>>(0x406170, this, arg1);
}

void mmHUD::Cull()
{
    return stub<thiscall_t<void, mmHUD*>>(0x405D30, this);
}

void mmHUD::DeactivateDash()
{
    return stub<thiscall_t<void, mmHUD*>>(0x405830, this);
}

void mmHUD::DeactivateGold()
{
    return stub<thiscall_t<void, mmHUD*>>(0x405FB0, this);
}

void mmHUD::Disable(i32 arg1)
{
    return stub<thiscall_t<void, mmHUD*, i32>>(0x405700, this, arg1);
}

void mmHUD::Enable()
{
    return stub<thiscall_t<void, mmHUD*>>(0x4056C0, this);
}

class MetaClass* mmHUD::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmHUD*>>(0x4068D0, this);
}

void mmHUD::GetPosHdg(class Vector4& arg1)
{
    return stub<thiscall_t<void, mmHUD*, class Vector4&>>(0x406060, this, arg1);
}

void mmHUD::GetTime(char* arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmHUD*, char*, f32>>(0x405FC0, this, arg1, arg2);
}

void mmHUD::Init(char* arg1, class mmPlayer* arg2)
{
    return stub<thiscall_t<void, mmHUD*, char*, class mmPlayer*>>(0x4053E0, this, arg1, arg2);
}

i32 mmHUD::IsDashActive()
{
    return stub<thiscall_t<i32, mmHUD*>>(0x405860, this);
}

void mmHUD::PlayNetAlert()
{
    return stub<thiscall_t<void, mmHUD*>>(0x405FE0, this);
}

void mmHUD::PostChatMessage(char* arg1)
{
    return stub<thiscall_t<void, mmHUD*, char*>>(0x405060, this, arg1);
}

void mmHUD::RecordPosition(char* arg1)
{
    return stub<thiscall_t<void, mmHUD*, char*>>(0x4060F0, this, arg1);
}

void mmHUD::RemovePlayer(u32 arg1)
{
    return stub<thiscall_t<void, mmHUD*, u32>>(0x405F80, this, arg1);
}

void mmHUD::ResChange(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmHUD*, i32, i32>>(0x4050C0, this, arg1, arg2);
}

void mmHUD::Reset()
{
    return stub<thiscall_t<void, mmHUD*>>(0x405870, this);
}

void mmHUD::ResetTimers()
{
    return stub<thiscall_t<void, mmHUD*>>(0x405360, this);
}

void mmHUD::SetLapTime(i32 arg1, f32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmHUD*, i32, f32, i32>>(0x405E40, this, arg1, arg2, arg3);
}

void mmHUD::SetMessage(struct LocString* arg1, f32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmHUD*, struct LocString*, f32, i32>>(0x405EA0, this, arg1, arg2, arg3);
}

void mmHUD::SetMessage2(struct LocString* arg1)
{
    return stub<thiscall_t<void, mmHUD*, struct LocString*>>(0x405EE0, this, arg1);
}

void mmHUD::SetScore(char* arg1)
{
    return stub<thiscall_t<void, mmHUD*, char*>>(0x405F10, this, arg1);
}

void mmHUD::SetScore(u32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmHUD*, u32, i32>>(0x405F60, this, arg1, arg2);
}

void mmHUD::SetStandings(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmHUD*, i32, i32>>(0x405E00, this, arg1, arg2);
}

void mmHUD::SetWPCleared(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, mmHUD*, i32, i32>>(0x405E80, this, arg1, arg2);
}

void mmHUD::ShowClockTime()
{
    return stub<thiscall_t<void, mmHUD*>>(0x405390, this);
}

void mmHUD::StartTimers()
{
    return stub<thiscall_t<void, mmHUD*>>(0x405320, this);
}

void mmHUD::StopTimers()
{
    return stub<thiscall_t<void, mmHUD*>>(0x405340, this);
}

void mmHUD::Toggle()
{
    return stub<thiscall_t<void, mmHUD*>>(0x405750, this);
}

void mmHUD::ToggleDash()
{
    return stub<thiscall_t<void, mmHUD*>>(0x4057C0, this);
}

void mmHUD::ToggleExternalView()
{
    return stub<thiscall_t<void, mmHUD*>>(0x405770, this);
}

void mmHUD::ToggleMirror()
{
    return stub<thiscall_t<void, mmHUD*>>(0x405D10, this);
}

void mmHUD::TogglePositionDisplay(i32 arg1)
{
    return stub<thiscall_t<void, mmHUD*, i32>>(0x406000, this, arg1);
}

void mmHUD::Update()
{
    return stub<thiscall_t<void, mmHUD*>>(0x405910, this);
}

void mmHUD::UpdatePaused()
{
    return stub<thiscall_t<void, mmHUD*>>(0x405CE0, this);
}

void mmHUD::DeclareFields()
{
    return stub<cdecl_t<void>>(0x406760);
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
    return stub<thiscall_t<f32, mmTimer*>>(0x406230, this);
}

void mmTimer::Init(i32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmTimer*, i32, f32>>(0x406210, this, arg1, arg2);
}

void mmTimer::Reset()
{
    return stub<thiscall_t<void, mmTimer*>>(0x406290, this);
}

void mmTimer::Start()
{
    return stub<thiscall_t<void, mmTimer*>>(0x4062A0, this);
}

void mmTimer::StartStop()
{
    return stub<thiscall_t<void, mmTimer*>>(0x4062C0, this);
}

void mmTimer::Stop()
{
    return stub<thiscall_t<void, mmTimer*>>(0x4062B0, this);
}

void mmTimer::Update()
{
    return stub<thiscall_t<void, mmTimer*>>(0x406240, this);
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
    return stub<thiscall_t<void, mmArrow*, class Matrix34*>>(0x4064C0, this, arg1);
}

void mmArrow::Reset()
{
    return stub<thiscall_t<void, mmArrow*>>(0x4064D0, this);
}

void mmArrow::SetInterest(class Vector3* arg1)
{
    return stub<thiscall_t<void, mmArrow*, class Vector3*>>(0x4064E0, this, arg1);
}

void mmArrow::Update()
{
    return stub<thiscall_t<void, mmArrow*>>(0x406560, this);
}

void mmArrow::ReColorArrow(i32 arg1)
{
    return stub<thiscall_t<void, mmArrow*, i32>>(0x4064F0, this, arg1);
}
