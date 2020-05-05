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

define_dummy_symbol(mminput_joystick);

#include "joystick.h"

mmJoystick::mmJoystick()
{
    unimplemented();
}

mmJoystick::~mmJoystick()
{
    unimplemented();
}

i32 mmJoystick::DisableAutoCenter()
{
    return stub<thiscall_t<i32, mmJoystick*>>(0xE66C0_Offset, this);
}

f32 mmJoystick::GetAxis(i32 arg1)
{
    return stub<thiscall_t<f32, mmJoystick*, i32>>(0xE6850_Offset, this, arg1);
}

f32 mmJoystick::GetButton(i32 arg1)
{
    return stub<thiscall_t<f32, mmJoystick*, i32>>(0xE6950_Offset, this, arg1);
}

class mmEffectFF* mmJoystick::GetFFEffect(i32 arg1)
{
    return stub<thiscall_t<class mmEffectFF*, mmJoystick*, i32>>(0xE6D80_Offset, this, arg1);
}

i32 mmJoystick::Init(struct IDirectInputDevice2A* arg1, struct HWND__* arg2)
{
    return stub<thiscall_t<i32, mmJoystick*, struct IDirectInputDevice2A*, struct HWND__*>>(
        0xE6360_Offset, this, arg1, arg2);
}

void mmJoystick::InputCreateEffect()
{
    return stub<thiscall_t<void, mmJoystick*>>(0xE6A90_Offset, this);
}

void mmJoystick::InputInitEffect()
{
    return stub<thiscall_t<void, mmJoystick*>>(0xE6BB0_Offset, this);
}

void mmJoystick::InputStopEffect()
{
    return stub<thiscall_t<void, mmJoystick*>>(0xE6BF0_Offset, this);
}

i32 mmJoystick::PlayCollision()
{
    return stub<thiscall_t<i32, mmJoystick*>>(0xE6CA0_Offset, this);
}

i32 mmJoystick::PlayFriction()
{
    return stub<thiscall_t<i32, mmJoystick*>>(0xE6D40_Offset, this);
}

i32 mmJoystick::PlayShake()
{
    return stub<thiscall_t<i32, mmJoystick*>>(0xE6C60_Offset, this);
}

i32 mmJoystick::PlaySteer()
{
    return stub<thiscall_t<i32, mmJoystick*>>(0xE6CE0_Offset, this);
}

u32 mmJoystick::Poll()
{
    return stub<thiscall_t<u32, mmJoystick*>>(0xE6720_Offset, this);
}

void mmJoystick::PrintDeviceCaps()
{
    return stub<thiscall_t<void, mmJoystick*>>(0xE6DD0_Offset, this);
}

void mmJoystick::ResetAxisCapture()
{
    return stub<thiscall_t<void, mmJoystick*>>(0xE6A10_Offset, this);
}

i32 mmJoystick::SetDeadZone(f32 arg1)
{
    return stub<thiscall_t<i32, mmJoystick*, f32>>(0xE6620_Offset, this, arg1);
}

i32 mmJoystick::SetFriction(i32 arg1)
{
    return stub<thiscall_t<i32, mmJoystick*, i32>>(0xE6D20_Offset, this, arg1);
}

i32 mmJoystick::SetShake(u32 arg1, u32 arg2)
{
    return stub<thiscall_t<i32, mmJoystick*, u32, u32>>(0xE6C30_Offset, this, arg1, arg2);
}

i32 mmJoystick::SetSteer(i32 arg1)
{
    return stub<thiscall_t<i32, mmJoystick*, i32>>(0xE6CC0_Offset, this, arg1);
}

i32 mmJoystick::StopFriction()
{
    return stub<thiscall_t<i32, mmJoystick*>>(0xE6D60_Offset, this);
}

i32 mmJoystick::StopShake()
{
    return stub<thiscall_t<i32, mmJoystick*>>(0xE6C80_Offset, this);
}

i32 mmJoystick::StopSteer()
{
    return stub<thiscall_t<i32, mmJoystick*>>(0xE6D00_Offset, this);
}

void mmJoystick::Update()
{
    return stub<thiscall_t<void, mmJoystick*>>(0xE6980_Offset, this);
}

i32 mmJoystick::inputPrepareDevice()
{
    return stub<thiscall_t<i32, mmJoystick*>>(0xE6470_Offset, this);
}

mmJaxis::mmJaxis()
{
    unimplemented();
}

mmJaxis::~mmJaxis()
{
    unimplemented();
}

i32 mmJaxis::Capture()
{
    return stub<thiscall_t<i32, mmJaxis*>>(0xE6130_Offset, this);
}

void mmJaxis::Normalize(f32 arg1)
{
    return stub<thiscall_t<void, mmJaxis*, f32>>(0xE60D0_Offset, this, arg1);
}

void mmJaxis::NormalizePOV(u32 arg1)
{
    return stub<thiscall_t<void, mmJaxis*, u32>>(0xE60F0_Offset, this, arg1);
}

void mmJaxis::ResetCapture()
{
    return stub<thiscall_t<void, mmJaxis*>>(0xE6160_Offset, this);
}

void mmJaxis::SetRange(f32 arg1, f32 arg2)
{
    return stub<thiscall_t<void, mmJaxis*, f32, f32>>(0xE60B0_Offset, this, arg1, arg2);
}

void DecodeDIErrorMFlag(i32 arg1)
{
    return stub<cdecl_t<void, i32>>(0xE6FB0_Offset, arg1);
}
