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

define_dummy_symbol(mminput_input);

#include "input.h"

void testsuperq()
{
    return stub<cdecl_t<void>>(0x4E06E0);
}

mmInput::mmInput()
{
    unimplemented();
}

mmInput::~mmInput()
{
    unimplemented();
}

void mmInput::AssignIO(class mmIO* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmInput*, class mmIO*, i32, i32>>(0x4E21F0, this, arg1, arg2, arg3);
}

i32 mmInput::AttachToPipe()
{
    return stub<thiscall_t<i32, mmInput*>>(0x4E09F0, this);
}

void mmInput::AutoSetup()
{
    return stub<thiscall_t<void, mmInput*>>(0x4E0F00, this);
}

i32 mmInput::BinaryLoadConfig(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmInput*, class Stream*>>(0x4E3CE0, this, arg1);
}

i32 mmInput::BinarySaveConfig(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmInput*, class Stream*>>(0x4E3E20, this, arg1);
}

i32 mmInput::BuildCaptureIO(i32 arg1, class mmIO* arg2, union eqEvent arg3)
{
    return stub<thiscall_t<i32, mmInput*, i32, class mmIO*, union eqEvent>>(0x4E1EB0, this, arg1, arg2, arg3);
}

void mmInput::CaptureState(i32 arg1)
{
    return stub<thiscall_t<void, mmInput*, i32>>(0x4E1E80, this, arg1);
}

void mmInput::ClearEventHitFlags()
{
    return stub<thiscall_t<void, mmInput*>>(0x4E24B0, this);
}

i32 mmInput::DeviceConnected()
{
    return stub<thiscall_t<i32, mmInput*>>(0x4E3990, this);
}

i32 mmInput::DoingFF()
{
    return stub<thiscall_t<i32, mmInput*>>(0x4E3A60, this);
}

i32 mmInput::FFIsPlaying(i32 arg1)
{
    return stub<thiscall_t<i32, mmInput*, i32>>(0x4E3BC0, this, arg1);
}

i32 mmInput::FFPlay(i32 arg1)
{
    return stub<thiscall_t<i32, mmInput*, i32>>(0x4E3B60, this, arg1);
}

i32 mmInput::FFSetValues(i32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<i32, mmInput*, i32, f32, f32>>(0x4E3BF0, this, arg1, arg2, arg3);
}

i32 mmInput::FFStop(i32 arg1)
{
    return stub<thiscall_t<i32, mmInput*, i32>>(0x4E3B90, this, arg1);
}

f32 mmInput::FilterGamepadSteering()
{
    return stub<thiscall_t<f32, mmInput*>>(0x4E3650, this);
}

void mmInput::FlagIODevChanged()
{
    return stub<thiscall_t<void, mmInput*>>(0x4E1E40, this);
}

void mmInput::Flush()
{
    return stub<thiscall_t<void, mmInput*>>(0x4E2450, this);
}

void mmInput::ForceAssignment(class mmIO* arg1)
{
    return stub<thiscall_t<void, mmInput*, class mmIO*>>(0x4E2070, this, arg1);
}

i32 mmInput::GamepadConnected()
{
    return stub<thiscall_t<i32, mmInput*>>(0x4E39B0, this);
}

f32 mmInput::GetBrakes()
{
    return stub<thiscall_t<f32, mmInput*>>(0x4E33A0, this);
}

f32 mmInput::GetBrakesVal()
{
    return stub<thiscall_t<f32, mmInput*>>(0x4E33C0, this);
}

f32 mmInput::GetCamPan()
{
    return stub<thiscall_t<f32, mmInput*>>(0x4E3890, this);
}

class MetaClass* mmInput::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmInput*>>(0x4E4290, this);
}

f32 mmInput::GetHandBrake()
{
    return stub<thiscall_t<f32, mmInput*>>(0x4E3430, this);
}

f32 mmInput::GetSteering()
{
    return stub<thiscall_t<f32, mmInput*>>(0x4E37E0, this);
}

f32 mmInput::GetThrottle()
{
    return stub<thiscall_t<f32, mmInput*>>(0x4E3310, this);
}

f32 mmInput::GetThrottleVal()
{
    return stub<thiscall_t<f32, mmInput*>>(0x4E3330, this);
}

void mmInput::IOInit(i32 arg1, struct LocString* arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmInput*, i32, struct LocString*, i32>>(0x4E0ED0, this, arg1, arg2, arg3);
}

void mmInput::Init(i32 arg1)
{
    return stub<thiscall_t<void, mmInput*, i32>>(0x4E1C60, this, arg1);
}

i32 mmInput::IsAlreadyAssigned(class mmIO* arg1, i32 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<i32, mmInput*, class mmIO*, i32, i32, i32>>(0x4E2110, this, arg1, arg2, arg3, arg4);
}

i32 mmInput::JoystickConnected()
{
    return stub<thiscall_t<i32, mmInput*>>(0x4E39A0, this);
}

i32 mmInput::JoystickHasCoolie()
{
    return stub<thiscall_t<i32, mmInput*>>(0x4E3A00, this);
}

i32 mmInput::JoystickHasThrottle()
{
    return stub<thiscall_t<i32, mmInput*>>(0x4E3A10, this);
}

i32 mmInput::LoadConfig(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmInput*, class Stream*>>(0x4E3C50, this, arg1);
}

i32 mmInput::PollStates()
{
    return stub<thiscall_t<i32, mmInput*>>(0x4E2370, this);
}

i32 mmInput::PollSuperQ()
{
    return stub<thiscall_t<i32, mmInput*>>(0x4E2420, this);
}

i32 mmInput::PopEvent(i32* arg1)
{
    return stub<thiscall_t<i32, mmInput*, i32*>>(0x4E3C20, this, arg1);
}

void mmInput::PrintIODev()
{
    return stub<thiscall_t<void, mmInput*>>(0x4E42A0, this);
}

void mmInput::Reset()
{
    return stub<thiscall_t<void, mmInput*>>(0x4E0EA0, this);
}

void mmInput::RestoreDefaultConfig(i32 arg1)
{
    return stub<thiscall_t<void, mmInput*, i32>>(0x4E1010, this, arg1);
}

i32 mmInput::ReturnStateCaptured()
{
    return stub<thiscall_t<i32, mmInput*>>(0x4E1E60, this);
}

i32 mmInput::SanityCheck(class mmIO* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<i32, mmInput*, class mmIO*, i32, i32>>(0x4E2090, this, arg1, arg2, arg3);
}

void mmInput::SaveCB()
{
    return stub<thiscall_t<void, mmInput*>>(0x4E0FD0, this);
}

i32 mmInput::SaveCodeConfig(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmInput*, class Stream*>>(0x4E4370, this, arg1);
}

i32 mmInput::SaveConfig(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmInput*, class Stream*>>(0x4E3DA0, this, arg1);
}

void mmInput::SetDeadZone(f32 arg1)
{
    return stub<thiscall_t<void, mmInput*, f32>>(0x4E39D0, this, arg1);
}

void mmInput::SetDefaultConfig(i32 arg1)
{
    return stub<thiscall_t<void, mmInput*, i32>>(0x4E1070, this, arg1);
}

void mmInput::SetForceFeedbackScale(f32 arg1)
{
    return stub<thiscall_t<void, mmInput*, f32>>(0x4E3AA0, this, arg1);
}

void mmInput::SetRoadForceScale(f32 arg1)
{
    return stub<thiscall_t<void, mmInput*, f32>>(0x4E3AF0, this, arg1);
}

void mmInput::StopAllFF()
{
    return stub<thiscall_t<void, mmInput*>>(0x4E3A90, this);
}

i32 mmInput::ToggleFFEnabled(i32 arg1)
{
    return stub<thiscall_t<i32, mmInput*, i32>>(0x4E3B40, this, arg1);
}

void mmInput::Update()
{
    return stub<thiscall_t<void, mmInput*>>(0x4E2290, this);
}

i32 mmInput::WheelConnected()
{
    return stub<thiscall_t<i32, mmInput*>>(0x4E39C0, this);
}

i32 mmInput::WheelHas3Axis()
{
    return stub<thiscall_t<i32, mmInput*>>(0x4E3A20, this);
}

void mmInput::DeclareFields()
{
    return stub<cdecl_t<void>>(0x4E40E0);
}

void mmInput::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmInput*, class Bank*>>(0x4E3EB0, this, arg1);
}

i32 mmInput::EventToButton(i32 arg1)
{
    return stub<thiscall_t<i32, mmInput*, i32>>(0x4E2890, this, arg1);
}

f32 mmInput::FilterDiscreteSteering(f32 arg1)
{
    return stub<thiscall_t<f32, mmInput*, f32>>(0x4E34B0, this, arg1);
}

void mmInput::GetBufferedKeyboardData()
{
    return stub<thiscall_t<void, mmInput*>>(0x4E2580, this);
}

i32 mmInput::GetNextKeyboardEvent(union eqEvent* arg1)
{
    return stub<thiscall_t<i32, mmInput*, union eqEvent*>>(0x4E25A0, this, arg1);
}

void mmInput::PollContinuous(class mmIO* arg1)
{
    return stub<thiscall_t<void, mmInput*, class mmIO*>>(0x4E2E80, this, arg1);
}

void mmInput::ProcessEvents()
{
    return stub<thiscall_t<void, mmInput*>>(0x4E25E0, this);
}

void mmInput::ProcessJoyEvents()
{
    return stub<thiscall_t<void, mmInput*>>(0x4E28C0, this);
}

void mmInput::ProcessKeyboardEvents()
{
    return stub<thiscall_t<void, mmInput*>>(0x4E2530, this);
}

void mmInput::ProcessMouseEvents()
{
    return stub<thiscall_t<void, mmInput*>>(0x4E24D0, this);
}

i64 mmInput::ProcessStates()
{
    return stub<thiscall_t<i64, mmInput*>>(0x4E2600, this);
}

void mmInput::PutEventInQueue(i64 arg1)
{
    return stub<thiscall_t<void, mmInput*, i64>>(0x4E2E50, this, arg1);
}

i64 mmInput::ScanForEvent(union eqEvent* arg1)
{
    return stub<thiscall_t<i64, mmInput*, union eqEvent*>>(0x4E2D90, this, arg1);
}

i64 mmInput::ScanState(class mmIO* arg1)
{
    return stub<thiscall_t<i64, mmInput*, class mmIO*>>(0x4E26E0, this, arg1);
}
