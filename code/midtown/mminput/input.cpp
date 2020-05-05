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
    return stub<cdecl_t<void>>(0xE06E0_Offset);
}

mmInput::mmInput()
{
    unimplemented();
}

mmInput::~mmInput()
{
    unimplemented(arg1);
}

void mmInput::AssignIO(class mmIO* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmInput*, class mmIO*, i32, i32>>(0xE21F0_Offset, this, arg1, arg2, arg3);
}

i32 mmInput::AttachToPipe()
{
    return stub<thiscall_t<i32, mmInput*>>(0xE09F0_Offset, this);
}

void mmInput::AutoSetup()
{
    return stub<thiscall_t<void, mmInput*>>(0xE0F00_Offset, this);
}

i32 mmInput::BinaryLoadConfig(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmInput*, class Stream*>>(0xE3CE0_Offset, this, arg1);
}

i32 mmInput::BinarySaveConfig(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmInput*, class Stream*>>(0xE3E20_Offset, this, arg1);
}

i32 mmInput::BuildCaptureIO(i32 arg1, class mmIO* arg2, union eqEvent arg3)
{
    return stub<thiscall_t<i32, mmInput*, i32, class mmIO*, union eqEvent>>(0xE1EB0_Offset, this, arg1, arg2, arg3);
}

void mmInput::CaptureState(i32 arg1)
{
    return stub<thiscall_t<void, mmInput*, i32>>(0xE1E80_Offset, this, arg1);
}

void mmInput::ClearEventHitFlags()
{
    return stub<thiscall_t<void, mmInput*>>(0xE24B0_Offset, this);
}

i32 mmInput::DeviceConnected()
{
    return stub<thiscall_t<i32, mmInput*>>(0xE3990_Offset, this);
}

i32 mmInput::DoingFF()
{
    return stub<thiscall_t<i32, mmInput*>>(0xE3A60_Offset, this);
}

i32 mmInput::FFIsPlaying(i32 arg1)
{
    return stub<thiscall_t<i32, mmInput*, i32>>(0xE3BC0_Offset, this, arg1);
}

i32 mmInput::FFPlay(i32 arg1)
{
    return stub<thiscall_t<i32, mmInput*, i32>>(0xE3B60_Offset, this, arg1);
}

i32 mmInput::FFSetValues(i32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<i32, mmInput*, i32, f32, f32>>(0xE3BF0_Offset, this, arg1, arg2, arg3);
}

i32 mmInput::FFStop(i32 arg1)
{
    return stub<thiscall_t<i32, mmInput*, i32>>(0xE3B90_Offset, this, arg1);
}

f32 mmInput::FilterGamepadSteering()
{
    return stub<thiscall_t<f32, mmInput*>>(0xE3650_Offset, this);
}

void mmInput::FlagIODevChanged()
{
    return stub<thiscall_t<void, mmInput*>>(0xE1E40_Offset, this);
}

void mmInput::Flush()
{
    return stub<thiscall_t<void, mmInput*>>(0xE2450_Offset, this);
}

void mmInput::ForceAssignment(class mmIO* arg1)
{
    return stub<thiscall_t<void, mmInput*, class mmIO*>>(0xE2070_Offset, this, arg1);
}

i32 mmInput::GamepadConnected()
{
    return stub<thiscall_t<i32, mmInput*>>(0xE39B0_Offset, this);
}

f32 mmInput::GetBrakes()
{
    return stub<thiscall_t<f32, mmInput*>>(0xE33A0_Offset, this);
}

f32 mmInput::GetBrakesVal()
{
    return stub<thiscall_t<f32, mmInput*>>(0xE33C0_Offset, this);
}

f32 mmInput::GetCamPan()
{
    return stub<thiscall_t<f32, mmInput*>>(0xE3890_Offset, this);
}

class MetaClass* mmInput::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmInput*>>(0xE4290_Offset, this);
}

f32 mmInput::GetHandBrake()
{
    return stub<thiscall_t<f32, mmInput*>>(0xE3430_Offset, this);
}

f32 mmInput::GetSteering()
{
    return stub<thiscall_t<f32, mmInput*>>(0xE37E0_Offset, this);
}

f32 mmInput::GetThrottle()
{
    return stub<thiscall_t<f32, mmInput*>>(0xE3310_Offset, this);
}

f32 mmInput::GetThrottleVal()
{
    return stub<thiscall_t<f32, mmInput*>>(0xE3330_Offset, this);
}

void mmInput::IOInit(i32 arg1, struct LocString* arg2, i32 arg3)
{
    return stub<thiscall_t<void, mmInput*, i32, struct LocString*, i32>>(0xE0ED0_Offset, this, arg1, arg2, arg3);
}

void mmInput::Init(i32 arg1)
{
    return stub<thiscall_t<void, mmInput*, i32>>(0xE1C60_Offset, this, arg1);
}

i32 mmInput::IsAlreadyAssigned(class mmIO* arg1, i32 arg2, i32 arg3, i32 arg4)
{
    return stub<thiscall_t<i32, mmInput*, class mmIO*, i32, i32, i32>>(0xE2110_Offset, this, arg1, arg2, arg3, arg4);
}

i32 mmInput::JoystickConnected()
{
    return stub<thiscall_t<i32, mmInput*>>(0xE39A0_Offset, this);
}

i32 mmInput::JoystickHasCoolie()
{
    return stub<thiscall_t<i32, mmInput*>>(0xE3A00_Offset, this);
}

i32 mmInput::JoystickHasThrottle()
{
    return stub<thiscall_t<i32, mmInput*>>(0xE3A10_Offset, this);
}

i32 mmInput::LoadConfig(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmInput*, class Stream*>>(0xE3C50_Offset, this, arg1);
}

i32 mmInput::PollStates()
{
    return stub<thiscall_t<i32, mmInput*>>(0xE2370_Offset, this);
}

i32 mmInput::PollSuperQ()
{
    return stub<thiscall_t<i32, mmInput*>>(0xE2420_Offset, this);
}

i32 mmInput::PopEvent(i32* arg1)
{
    return stub<thiscall_t<i32, mmInput*, i32*>>(0xE3C20_Offset, this, arg1);
}

void mmInput::PrintIODev()
{
    return stub<thiscall_t<void, mmInput*>>(0xE42A0_Offset, this);
}

void mmInput::Reset()
{
    return stub<thiscall_t<void, mmInput*>>(0xE0EA0_Offset, this);
}

void mmInput::RestoreDefaultConfig(i32 arg1)
{
    return stub<thiscall_t<void, mmInput*, i32>>(0xE1010_Offset, this, arg1);
}

i32 mmInput::ReturnStateCaptured()
{
    return stub<thiscall_t<i32, mmInput*>>(0xE1E60_Offset, this);
}

i32 mmInput::SanityCheck(class mmIO* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<i32, mmInput*, class mmIO*, i32, i32>>(0xE2090_Offset, this, arg1, arg2, arg3);
}

void mmInput::SaveCB()
{
    return stub<thiscall_t<void, mmInput*>>(0xE0FD0_Offset, this);
}

i32 mmInput::SaveCodeConfig(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmInput*, class Stream*>>(0xE4370_Offset, this, arg1);
}

i32 mmInput::SaveConfig(class Stream* arg1)
{
    return stub<thiscall_t<i32, mmInput*, class Stream*>>(0xE3DA0_Offset, this, arg1);
}

void mmInput::SetDeadZone(f32 arg1)
{
    return stub<thiscall_t<void, mmInput*, f32>>(0xE39D0_Offset, this, arg1);
}

void mmInput::SetDefaultConfig(i32 arg1)
{
    return stub<thiscall_t<void, mmInput*, i32>>(0xE1070_Offset, this, arg1);
}

void mmInput::SetForceFeedbackScale(f32 arg1)
{
    return stub<thiscall_t<void, mmInput*, f32>>(0xE3AA0_Offset, this, arg1);
}

void mmInput::SetRoadForceScale(f32 arg1)
{
    return stub<thiscall_t<void, mmInput*, f32>>(0xE3AF0_Offset, this, arg1);
}

void mmInput::StopAllFF()
{
    return stub<thiscall_t<void, mmInput*>>(0xE3A90_Offset, this);
}

i32 mmInput::ToggleFFEnabled(i32 arg1)
{
    return stub<thiscall_t<i32, mmInput*, i32>>(0xE3B40_Offset, this, arg1);
}

void mmInput::Update()
{
    return stub<thiscall_t<void, mmInput*>>(0xE2290_Offset, this);
}

i32 mmInput::WheelConnected()
{
    return stub<thiscall_t<i32, mmInput*>>(0xE39C0_Offset, this);
}

i32 mmInput::WheelHas3Axis()
{
    return stub<thiscall_t<i32, mmInput*>>(0xE3A20_Offset, this);
}

void mmInput::DeclareFields()
{
    return stub<cdecl_t<void>>(0xE40E0_Offset);
}

void mmInput::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmInput*, class Bank*>>(0xE3EB0_Offset, this, arg1);
}

i32 mmInput::EventToButton(i32 arg1)
{
    return stub<thiscall_t<i32, mmInput*, i32>>(0xE2890_Offset, this, arg1);
}

f32 mmInput::FilterDiscreteSteering(f32 arg1)
{
    return stub<thiscall_t<f32, mmInput*, f32>>(0xE34B0_Offset, this, arg1);
}

void mmInput::GetBufferedKeyboardData()
{
    return stub<thiscall_t<void, mmInput*>>(0xE2580_Offset, this);
}

i32 mmInput::GetNextKeyboardEvent(union eqEvent* arg1)
{
    return stub<thiscall_t<i32, mmInput*, union eqEvent*>>(0xE25A0_Offset, this, arg1);
}

void mmInput::PollContinuous(class mmIO* arg1)
{
    return stub<thiscall_t<void, mmInput*, class mmIO*>>(0xE2E80_Offset, this, arg1);
}

void mmInput::ProcessEvents()
{
    return stub<thiscall_t<void, mmInput*>>(0xE25E0_Offset, this);
}

void mmInput::ProcessJoyEvents()
{
    return stub<thiscall_t<void, mmInput*>>(0xE28C0_Offset, this);
}

void mmInput::ProcessKeyboardEvents()
{
    return stub<thiscall_t<void, mmInput*>>(0xE2530_Offset, this);
}

void mmInput::ProcessMouseEvents()
{
    return stub<thiscall_t<void, mmInput*>>(0xE24D0_Offset, this);
}

i64 mmInput::ProcessStates()
{
    return stub<thiscall_t<i64, mmInput*>>(0xE2600_Offset, this);
}

void mmInput::PutEventInQueue(i64 arg1)
{
    return stub<thiscall_t<void, mmInput*, i64>>(0xE2E50_Offset, this, arg1);
}

i64 mmInput::ScanForEvent(union eqEvent* arg1)
{
    return stub<thiscall_t<i64, mmInput*, union eqEvent*>>(0xE2D90_Offset, this, arg1);
}

i64 mmInput::ScanState(class mmIO* arg1)
{
    return stub<thiscall_t<i64, mmInput*, class mmIO*>>(0xE26E0_Offset, this, arg1);
}
