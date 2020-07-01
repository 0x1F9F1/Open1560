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

#pragma once

/*
    mminput:input

    0x4E06E0 | void __cdecl testsuperq(void) | ?testsuperq@@YAXXZ
    0x4E0710 | public: __thiscall mmInput::mmInput(void) | ??0mmInput@@QAE@XZ
    0x4E0930 | public: virtual __thiscall mmInput::~mmInput(void) | ??1mmInput@@UAE@XZ
    0x4E09F0 | public: int __thiscall mmInput::AttachToPipe(void) | ?AttachToPipe@mmInput@@QAEHXZ
    0x4E0EA0 | public: virtual void __thiscall mmInput::Reset(void) | ?Reset@mmInput@@UAEXXZ
    0x4E0ED0 | public: void __thiscall mmInput::IOInit(int,struct LocString *,long) | ?IOInit@mmInput@@QAEXHPAULocString@@J@Z
    0x4E0F00 | public: void __thiscall mmInput::AutoSetup(void) | ?AutoSetup@mmInput@@QAEXXZ
    0x4E0FD0 | public: void __thiscall mmInput::SaveCB(void) | ?SaveCB@mmInput@@QAEXXZ
    0x4E1010 | public: void __thiscall mmInput::RestoreDefaultConfig(int) | ?RestoreDefaultConfig@mmInput@@QAEXH@Z
    0x4E1070 | public: void __thiscall mmInput::SetDefaultConfig(int) | ?SetDefaultConfig@mmInput@@QAEXH@Z
    0x4E1C60 | public: void __thiscall mmInput::Init(int) | ?Init@mmInput@@QAEXH@Z
    0x4E1E40 | public: void __thiscall mmInput::FlagIODevChanged(void) | ?FlagIODevChanged@mmInput@@QAEXXZ
    0x4E1E60 | public: int __thiscall mmInput::ReturnStateCaptured(void) | ?ReturnStateCaptured@mmInput@@QAEHXZ
    0x4E1E80 | public: void __thiscall mmInput::CaptureState(int) | ?CaptureState@mmInput@@QAEXH@Z
    0x4E1EB0 | public: int __thiscall mmInput::BuildCaptureIO(int,class mmIO *,union eqEvent) | ?BuildCaptureIO@mmInput@@QAEHHPAVmmIO@@TeqEvent@@@Z
    0x4E2070 | public: void __thiscall mmInput::ForceAssignment(class mmIO *) | ?ForceAssignment@mmInput@@QAEXPAVmmIO@@@Z
    0x4E2090 | public: int __thiscall mmInput::SanityCheck(class mmIO *,int,int) | ?SanityCheck@mmInput@@QAEHPAVmmIO@@HH@Z
    0x4E2110 | public: int __thiscall mmInput::IsAlreadyAssigned(class mmIO *,int,int,int) | ?IsAlreadyAssigned@mmInput@@QAEHPAVmmIO@@HHH@Z
    0x4E21F0 | public: void __thiscall mmInput::AssignIO(class mmIO *,int,int) | ?AssignIO@mmInput@@QAEXPAVmmIO@@HH@Z
    0x4E2290 | public: virtual void __thiscall mmInput::Update(void) | ?Update@mmInput@@UAEXXZ
    0x4E2370 | public: int __thiscall mmInput::PollStates(void) | ?PollStates@mmInput@@QAEHXZ
    0x4E2420 | public: int __thiscall mmInput::PollSuperQ(void) | ?PollSuperQ@mmInput@@QAEHXZ
    0x4E2450 | public: void __thiscall mmInput::Flush(void) | ?Flush@mmInput@@QAEXXZ
    0x4E24B0 | public: void __thiscall mmInput::ClearEventHitFlags(void) | ?ClearEventHitFlags@mmInput@@QAEXXZ
    0x4E24D0 | private: void __thiscall mmInput::ProcessMouseEvents(void) | ?ProcessMouseEvents@mmInput@@AAEXXZ
    0x4E2530 | private: void __thiscall mmInput::ProcessKeyboardEvents(void) | ?ProcessKeyboardEvents@mmInput@@AAEXXZ
    0x4E2580 | private: void __thiscall mmInput::GetBufferedKeyboardData(void) | ?GetBufferedKeyboardData@mmInput@@AAEXXZ
    0x4E25A0 | private: int __thiscall mmInput::GetNextKeyboardEvent(union eqEvent *) | ?GetNextKeyboardEvent@mmInput@@AAEHPATeqEvent@@@Z
    0x4E25E0 | private: void __thiscall mmInput::ProcessEvents(void) | ?ProcessEvents@mmInput@@AAEXXZ
    0x4E2600 | private: __int64 __thiscall mmInput::ProcessStates(void) | ?ProcessStates@mmInput@@AAE_JXZ
    0x4E26E0 | private: __int64 __thiscall mmInput::ScanState(class mmIO *) | ?ScanState@mmInput@@AAE_JPAVmmIO@@@Z
    0x4E2890 | private: int __thiscall mmInput::EventToButton(int) | ?EventToButton@mmInput@@AAEHH@Z
    0x4E28C0 | private: void __thiscall mmInput::ProcessJoyEvents(void) | ?ProcessJoyEvents@mmInput@@AAEXXZ
    0x4E2D90 | private: __int64 __thiscall mmInput::ScanForEvent(union eqEvent *) | ?ScanForEvent@mmInput@@AAE_JPATeqEvent@@@Z
    0x4E2E50 | private: void __thiscall mmInput::PutEventInQueue(__int64) | ?PutEventInQueue@mmInput@@AAEX_J@Z
    0x4E2E80 | private: void __thiscall mmInput::PollContinuous(class mmIO *) | ?PollContinuous@mmInput@@AAEXPAVmmIO@@@Z
    0x4E3310 | public: float __thiscall mmInput::GetThrottle(void) | ?GetThrottle@mmInput@@QAEMXZ
    0x4E3330 | public: float __thiscall mmInput::GetThrottleVal(void) | ?GetThrottleVal@mmInput@@QAEMXZ
    0x4E33A0 | public: float __thiscall mmInput::GetBrakes(void) | ?GetBrakes@mmInput@@QAEMXZ
    0x4E33C0 | public: float __thiscall mmInput::GetBrakesVal(void) | ?GetBrakesVal@mmInput@@QAEMXZ
    0x4E3430 | public: float __thiscall mmInput::GetHandBrake(void) | ?GetHandBrake@mmInput@@QAEMXZ
    0x4E34B0 | private: float __thiscall mmInput::FilterDiscreteSteering(float) | ?FilterDiscreteSteering@mmInput@@AAEMM@Z
    0x4E3650 | public: float __thiscall mmInput::FilterGamepadSteering(void) | ?FilterGamepadSteering@mmInput@@QAEMXZ
    0x4E37E0 | public: float __thiscall mmInput::GetSteering(void) | ?GetSteering@mmInput@@QAEMXZ
    0x4E3890 | public: float __thiscall mmInput::GetCamPan(void) | ?GetCamPan@mmInput@@QAEMXZ
    0x4E3990 | public: int __thiscall mmInput::DeviceConnected(void) | ?DeviceConnected@mmInput@@QAEHXZ
    0x4E39A0 | public: int __thiscall mmInput::JoystickConnected(void) | ?JoystickConnected@mmInput@@QAEHXZ
    0x4E39B0 | public: int __thiscall mmInput::GamepadConnected(void) | ?GamepadConnected@mmInput@@QAEHXZ
    0x4E39C0 | public: int __thiscall mmInput::WheelConnected(void) | ?WheelConnected@mmInput@@QAEHXZ
    0x4E39D0 | public: void __thiscall mmInput::SetDeadZone(float) | ?SetDeadZone@mmInput@@QAEXM@Z
    0x4E3A00 | public: int __thiscall mmInput::JoystickHasCoolie(void) | ?JoystickHasCoolie@mmInput@@QAEHXZ
    0x4E3A10 | public: int __thiscall mmInput::JoystickHasThrottle(void) | ?JoystickHasThrottle@mmInput@@QAEHXZ
    0x4E3A20 | public: int __thiscall mmInput::WheelHas3Axis(void) | ?WheelHas3Axis@mmInput@@QAEHXZ
    0x4E3A60 | public: int __thiscall mmInput::DoingFF(void) | ?DoingFF@mmInput@@QAEHXZ
    0x4E3A90 | public: void __thiscall mmInput::StopAllFF(void) | ?StopAllFF@mmInput@@QAEXXZ
    0x4E3AA0 | public: void __thiscall mmInput::SetForceFeedbackScale(float) | ?SetForceFeedbackScale@mmInput@@QAEXM@Z
    0x4E3AF0 | public: void __thiscall mmInput::SetRoadForceScale(float) | ?SetRoadForceScale@mmInput@@QAEXM@Z
    0x4E3B40 | public: int __thiscall mmInput::ToggleFFEnabled(int) | ?ToggleFFEnabled@mmInput@@QAEHH@Z
    0x4E3B60 | public: int __thiscall mmInput::FFPlay(int) | ?FFPlay@mmInput@@QAEHH@Z
    0x4E3B90 | public: int __thiscall mmInput::FFStop(int) | ?FFStop@mmInput@@QAEHH@Z
    0x4E3BC0 | public: int __thiscall mmInput::FFIsPlaying(int) | ?FFIsPlaying@mmInput@@QAEHH@Z
    0x4E3BF0 | public: int __thiscall mmInput::FFSetValues(int,float,float) | ?FFSetValues@mmInput@@QAEHHMM@Z
    0x4E3C20 | public: int __thiscall mmInput::PopEvent(int *) | ?PopEvent@mmInput@@QAEHPAH@Z
    0x4E3C50 | public: int __thiscall mmInput::LoadConfig(class Stream *) | ?LoadConfig@mmInput@@QAEHPAVStream@@@Z
    0x4E3CE0 | public: int __thiscall mmInput::BinaryLoadConfig(class Stream *) | ?BinaryLoadConfig@mmInput@@QAEHPAVStream@@@Z
    0x4E3DA0 | public: int __thiscall mmInput::SaveConfig(class Stream *) | ?SaveConfig@mmInput@@QAEHPAVStream@@@Z
    0x4E3E20 | public: int __thiscall mmInput::BinarySaveConfig(class Stream *) | ?BinarySaveConfig@mmInput@@QAEHPAVStream@@@Z
    0x4E3EB0 | private: virtual void __thiscall mmInput::AddWidgets(class Bank *) | ?AddWidgets@mmInput@@EAEXPAVBank@@@Z
    0x4E40E0 | public: static void __cdecl mmInput::DeclareFields(void) | ?DeclareFields@mmInput@@SAXXZ
    0x4E4290 | public: virtual class MetaClass * __thiscall mmInput::GetClass(void) | ?GetClass@mmInput@@UAEPAVMetaClass@@XZ
    0x4E42A0 | public: void __thiscall mmInput::PrintIODev(void) | ?PrintIODev@mmInput@@QAEXXZ
    0x4E4370 | public: int __thiscall mmInput::SaveCodeConfig(class Stream *) | ?SaveCodeConfig@mmInput@@QAEHPAVStream@@@Z
    0x4E4A40 | public: void * __thiscall mmIO::`vector deleting destructor'(unsigned int) | ??_EmmIO@@QAEPAXI@Z
    0x4E4AA0 | public: virtual void * __thiscall mmIODev::`vector deleting destructor'(unsigned int) | ??_EmmIODev@@UAEPAXI@Z
    0x4E4B00 | public: virtual void * __thiscall mmInput::`vector deleting destructor'(unsigned int) | ??_EmmInput@@UAEPAXI@Z
    0x61FC38 | const mmInput::`vftable' | ??_7mmInput@@6B@
    0x719220 | class mmIODev * IODev | ?IODev@@3PAVmmIODev@@A
    0x719228 | class MetaClass mmInputMetaClass | ?mmInputMetaClass@@3VMetaClass@@A
    0x719250 | char * LocStrKey | ?LocStrKey@@3PADA
    0x719254 | class mmInput * GameInputPtr | ?GameInputPtr@@3PAVmmInput@@A
    0x719258 | char * LocStrButton | ?LocStrButton@@3PADA
    0x71925C | char * LocStrUndef | ?LocStrUndef@@3PADA
    0x719260 | char * LocStrJoystick | ?LocStrJoystick@@3PADA
    0x719264 | int UseDIKey | ?UseDIKey@@3HA
    0x719268 | int InputConfiguration | ?InputConfiguration@@3HA
    0x71926C | struct IDirectInputA * gpdi | ?gpdi@@3PAUIDirectInputA@@A
    0x719270 | float testValue | ?testValue@@3MA
*/

#include "arts7/node.h"

// 0x4E06E0 | ?testsuperq@@YAXXZ | unused
ARTS_IMPORT void testsuperq();

// 0x719254 | ?GameInputPtr@@3PAVmmInput@@A
ARTS_IMPORT extern class mmInput* GameInputPtr;

// 0x719220 | ?IODev@@3PAVmmIODev@@A
ARTS_IMPORT extern class mmIODev* IODev;

// 0x719268 | ?InputConfiguration@@3HA
ARTS_IMPORT extern i32 InputConfiguration;

// 0x719258 | ?LocStrButton@@3PADA
ARTS_IMPORT extern char* LocStrButton;

// 0x719260 | ?LocStrJoystick@@3PADA
ARTS_IMPORT extern char* LocStrJoystick;

// 0x719250 | ?LocStrKey@@3PADA
ARTS_IMPORT extern char* LocStrKey;

// 0x71925C | ?LocStrUndef@@3PADA
ARTS_IMPORT extern char* LocStrUndef;

// 0x719264 | ?UseDIKey@@3HA
ARTS_IMPORT extern i32 UseDIKey;

// 0x71926C | ?gpdi@@3PAUIDirectInputA@@A
ARTS_IMPORT extern struct IDirectInputA* gpdi;

// 0x719228 | ?mmInputMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmInputMetaClass;

// 0x719270 | ?testValue@@3MA
ARTS_IMPORT extern f32 testValue;

class mmInput : public asNode
{
    // const mmInput::`vftable' @ 0x61FC38

public:
    // 0x4E0710 | ??0mmInput@@QAE@XZ
    ARTS_IMPORT mmInput();

    // 0x4E4B00 | ??_EmmInput@@UAEPAXI@Z
    // 0x4E0930 | ??1mmInput@@UAE@XZ
    ARTS_IMPORT ~mmInput() override;

    // 0x4E21F0 | ?AssignIO@mmInput@@QAEXPAVmmIO@@HH@Z
    ARTS_IMPORT void AssignIO(class mmIO* arg1, i32 arg2, i32 arg3);

    // 0x4E09F0 | ?AttachToPipe@mmInput@@QAEHXZ
    ARTS_IMPORT i32 AttachToPipe();

    // 0x4E0F00 | ?AutoSetup@mmInput@@QAEXXZ
    ARTS_IMPORT void AutoSetup();

    // 0x4E3CE0 | ?BinaryLoadConfig@mmInput@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 BinaryLoadConfig(class Stream* arg1);

    // 0x4E3E20 | ?BinarySaveConfig@mmInput@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 BinarySaveConfig(class Stream* arg1);

    // 0x4E1EB0 | ?BuildCaptureIO@mmInput@@QAEHHPAVmmIO@@TeqEvent@@@Z
    ARTS_IMPORT i32 BuildCaptureIO(i32 arg1, class mmIO* arg2, union eqEvent arg3);

    // 0x4E1E80 | ?CaptureState@mmInput@@QAEXH@Z
    ARTS_IMPORT void CaptureState(i32 arg1);

    // 0x4E24B0 | ?ClearEventHitFlags@mmInput@@QAEXXZ
    ARTS_IMPORT void ClearEventHitFlags();

    // 0x4E3990 | ?DeviceConnected@mmInput@@QAEHXZ
    ARTS_IMPORT i32 DeviceConnected();

    // 0x4E3A60 | ?DoingFF@mmInput@@QAEHXZ
    ARTS_IMPORT i32 DoingFF();

    // 0x4E3BC0 | ?FFIsPlaying@mmInput@@QAEHH@Z
    ARTS_IMPORT i32 FFIsPlaying(i32 arg1);

    // 0x4E3B60 | ?FFPlay@mmInput@@QAEHH@Z
    ARTS_IMPORT i32 FFPlay(i32 arg1);

    // 0x4E3BF0 | ?FFSetValues@mmInput@@QAEHHMM@Z
    ARTS_IMPORT i32 FFSetValues(i32 arg1, f32 arg2, f32 arg3);

    // 0x4E3B90 | ?FFStop@mmInput@@QAEHH@Z
    ARTS_IMPORT i32 FFStop(i32 arg1);

    // 0x4E3650 | ?FilterGamepadSteering@mmInput@@QAEMXZ
    ARTS_IMPORT f32 FilterGamepadSteering();

    // 0x4E1E40 | ?FlagIODevChanged@mmInput@@QAEXXZ
    ARTS_IMPORT void FlagIODevChanged();

    // 0x4E2450 | ?Flush@mmInput@@QAEXXZ
    ARTS_IMPORT void Flush();

    // 0x4E2070 | ?ForceAssignment@mmInput@@QAEXPAVmmIO@@@Z
    ARTS_IMPORT void ForceAssignment(class mmIO* arg1);

    // 0x4E39B0 | ?GamepadConnected@mmInput@@QAEHXZ
    ARTS_EXPORT i32 GamepadConnected();

    // 0x4E33A0 | ?GetBrakes@mmInput@@QAEMXZ
    ARTS_IMPORT f32 GetBrakes();

    // 0x4E33C0 | ?GetBrakesVal@mmInput@@QAEMXZ
    ARTS_IMPORT f32 GetBrakesVal();

    // 0x4E3890 | ?GetCamPan@mmInput@@QAEMXZ
    ARTS_IMPORT f32 GetCamPan();

    // 0x4E4290 | ?GetClass@mmInput@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x4E3430 | ?GetHandBrake@mmInput@@QAEMXZ
    ARTS_IMPORT f32 GetHandBrake();

    // 0x4E37E0 | ?GetSteering@mmInput@@QAEMXZ
    ARTS_IMPORT f32 GetSteering();

    // 0x4E3310 | ?GetThrottle@mmInput@@QAEMXZ
    ARTS_IMPORT f32 GetThrottle();

    // 0x4E3330 | ?GetThrottleVal@mmInput@@QAEMXZ
    ARTS_IMPORT f32 GetThrottleVal();

    // 0x4E0ED0 | ?IOInit@mmInput@@QAEXHPAULocString@@J@Z
    ARTS_IMPORT void IOInit(i32 arg1, struct LocString* arg2, i32 arg3);

    // 0x4E1C60 | ?Init@mmInput@@QAEXH@Z
    ARTS_IMPORT void Init(i32 arg1);

    // 0x4E2110 | ?IsAlreadyAssigned@mmInput@@QAEHPAVmmIO@@HHH@Z
    ARTS_IMPORT i32 IsAlreadyAssigned(class mmIO* arg1, i32 arg2, i32 arg3, i32 arg4);

    // 0x4E39A0 | ?JoystickConnected@mmInput@@QAEHXZ
    ARTS_EXPORT i32 JoystickConnected();

    // 0x4E3A00 | ?JoystickHasCoolie@mmInput@@QAEHXZ
    ARTS_IMPORT i32 JoystickHasCoolie();

    // 0x4E3A10 | ?JoystickHasThrottle@mmInput@@QAEHXZ | unused
    ARTS_IMPORT i32 JoystickHasThrottle();

    // 0x4E3C50 | ?LoadConfig@mmInput@@QAEHPAVStream@@@Z | unused
    ARTS_IMPORT i32 LoadConfig(class Stream* arg1);

    // 0x4E2370 | ?PollStates@mmInput@@QAEHXZ
    ARTS_IMPORT i32 PollStates();

    // 0x4E2420 | ?PollSuperQ@mmInput@@QAEHXZ
    ARTS_IMPORT i32 PollSuperQ();

    // 0x4E3C20 | ?PopEvent@mmInput@@QAEHPAH@Z
    ARTS_IMPORT i32 PopEvent(i32* arg1);

    // 0x4E42A0 | ?PrintIODev@mmInput@@QAEXXZ | unused
    ARTS_IMPORT void PrintIODev();

    // 0x4E0EA0 | ?Reset@mmInput@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4E1010 | ?RestoreDefaultConfig@mmInput@@QAEXH@Z
    ARTS_IMPORT void RestoreDefaultConfig(i32 arg1);

    // 0x4E1E60 | ?ReturnStateCaptured@mmInput@@QAEHXZ
    ARTS_IMPORT i32 ReturnStateCaptured();

    // 0x4E2090 | ?SanityCheck@mmInput@@QAEHPAVmmIO@@HH@Z
    ARTS_IMPORT i32 SanityCheck(class mmIO* arg1, i32 arg2, i32 arg3);

    // 0x4E0FD0 | ?SaveCB@mmInput@@QAEXXZ
    ARTS_IMPORT void SaveCB();

    // 0x4E4370 | ?SaveCodeConfig@mmInput@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 SaveCodeConfig(class Stream* arg1);

    // 0x4E3DA0 | ?SaveConfig@mmInput@@QAEHPAVStream@@@Z | unused
    ARTS_IMPORT i32 SaveConfig(class Stream* arg1);

    // 0x4E39D0 | ?SetDeadZone@mmInput@@QAEXM@Z | unused
    ARTS_IMPORT void SetDeadZone(f32 arg1);

    // 0x4E1070 | ?SetDefaultConfig@mmInput@@QAEXH@Z
    ARTS_IMPORT void SetDefaultConfig(i32 arg1);

    // 0x4E3AA0 | ?SetForceFeedbackScale@mmInput@@QAEXM@Z | unused
    ARTS_IMPORT void SetForceFeedbackScale(f32 arg1);

    // 0x4E3AF0 | ?SetRoadForceScale@mmInput@@QAEXM@Z | unused
    ARTS_IMPORT void SetRoadForceScale(f32 arg1);

    // 0x4E3A90 | ?StopAllFF@mmInput@@QAEXXZ
    ARTS_IMPORT void StopAllFF();

    // 0x4E3B40 | ?ToggleFFEnabled@mmInput@@QAEHH@Z
    ARTS_IMPORT i32 ToggleFFEnabled(i32 arg1);

    // 0x4E2290 | ?Update@mmInput@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x4E39C0 | ?WheelConnected@mmInput@@QAEHXZ
    ARTS_EXPORT i32 WheelConnected();

    // 0x4E3A20 | ?WheelHas3Axis@mmInput@@QAEHXZ | unused
    ARTS_IMPORT i32 WheelHas3Axis();

    // 0x4E40E0 | ?DeclareFields@mmInput@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

private:
    // 0x4E3EB0 | ?AddWidgets@mmInput@@EAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x4E2890 | ?EventToButton@mmInput@@AAEHH@Z | unused
    ARTS_IMPORT i32 EventToButton(i32 arg1);

    // 0x4E34B0 | ?FilterDiscreteSteering@mmInput@@AAEMM@Z
    ARTS_IMPORT f32 FilterDiscreteSteering(f32 arg1);

    // 0x4E2580 | ?GetBufferedKeyboardData@mmInput@@AAEXXZ
    ARTS_IMPORT void GetBufferedKeyboardData();

    // 0x4E25A0 | ?GetNextKeyboardEvent@mmInput@@AAEHPATeqEvent@@@Z
    ARTS_IMPORT i32 GetNextKeyboardEvent(union eqEvent* arg1);

    // 0x4E2E80 | ?PollContinuous@mmInput@@AAEXPAVmmIO@@@Z
    ARTS_IMPORT void PollContinuous(class mmIO* arg1);

    // 0x4E25E0 | ?ProcessEvents@mmInput@@AAEXXZ
    ARTS_IMPORT void ProcessEvents();

    // 0x4E28C0 | ?ProcessJoyEvents@mmInput@@AAEXXZ
    ARTS_IMPORT void ProcessJoyEvents();

    // 0x4E2530 | ?ProcessKeyboardEvents@mmInput@@AAEXXZ
    ARTS_IMPORT void ProcessKeyboardEvents();

    // 0x4E24D0 | ?ProcessMouseEvents@mmInput@@AAEXXZ
    ARTS_IMPORT void ProcessMouseEvents();

    // 0x4E2600 | ?ProcessStates@mmInput@@AAE_JXZ
    ARTS_IMPORT i64 ProcessStates();

    // 0x4E2E50 | ?PutEventInQueue@mmInput@@AAEX_J@Z
    ARTS_IMPORT void PutEventInQueue(i64 arg1);

    // 0x4E2D90 | ?ScanForEvent@mmInput@@AAE_JPATeqEvent@@@Z
    ARTS_IMPORT i64 ScanForEvent(union eqEvent* arg1);

    // 0x4E26E0 | ?ScanState@mmInput@@AAE_JPAVmmIO@@@Z
    ARTS_IMPORT i64 ScanState(class mmIO* arg1);

    u8 gap20[0x228];
};

check_size(mmInput, 0x248);
