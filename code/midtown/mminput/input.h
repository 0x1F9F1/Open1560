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

#include "eventq7/eventq.h"

struct IDirectInputA;
class mmIODev;

// ?testsuperq@@YAXXZ | unused
ARTS_IMPORT void testsuperq();

// mmIO Flags
#define IO_FLAG_EVENT 0x1
#define IO_FLAG_DISCRETE 0x2
#define IO_FLAG_CONTINUOUS 0x4

// mmIODev Index
#define IOID_MAP 0      // Map Toggle (Event)
#define IOID_FMAP 1     // Full Screen Map (Event)
#define IOID_MAPRES 2   // Map Resolution (Event)
#define IOID_HUD 3      // HUD Toggle (Event)
#define IOID_STR 4      // Steering (Continuous)
#define IOID_STRL 5     // Steer Left (Discrete)
#define IOID_STRR 6     // Steer Right (Discrete)
#define IOID_THROT 7    // Throttle (Discrete | Continuous)
#define IOID_BRAKE 8    // Brakes (Discrete | Continuous)
#define IOID_HAND 9     // Handbrake (Discrete)
#define IOID_CAM 10     // Change Camera (Event)
#define IOID_XVIEW 11   // External View (Event)
#define IOID_HORN 12    // Horn (Discrete | Continuous)
#define IOID_LOKL 13    // Look Left (Discrete | Continuous)
#define IOID_LOKR 14    // Look Right (Discrete | Continuous)
#define IOID_LOKB 15    // Look Back (Discrete | Continuous)
#define IOID_LOKF 16    // Look Forward (Discrete | Continuous)
#define IOID_WFOV 17    // Wide Angle (Event)
#define IOID_DASH 18    // Dashboard On/Off (Event)
#define IOID_TRANS 19   // Transmission (Event)
#define IOID_UPSH 20    // Shift Up (Event)
#define IOID_DWNS 21    // Shift Down (Event)
#define IOID_REV 22     // Reverse (Event)
#define IOID_WYPTN 23   // Next Waypoint (Event)
#define IOID_WYPTP 24   // Prev. Waypoint (Event)
#define IOID_CDSHOW 25  // Toggle CD Player (Event)
#define IOID_CDPLAY 26  // Start/Stop CD (Event)
#define IOID_CDPRIOR 27 // Prev. CD Track (Event)
#define IOID_CDNEXT 28  // Next CD Track (Event)
#define IOID_MIRROR 29  // Rear View Mirror (Event)
#define IOID_PAN 30     // Camera Pan (Continuous)
#define IOID_OPPPOS 31  // Opponent Position (Event)
#define IOID_CHAT 32    // Enter Chat Msg (Event)
#define IOID_COUNT 33

// mmInputType
#define IODEV_NUM_CONFIGS 5

// mmInput::PollStates
#define MM_POLL_KEYBOARD 0x10000
#define MM_POLL_MOUSE 0x20000
#define MM_POLL_JOYSTICK 0x40000

// See mmInput::BuildCaptureIO for how these are handled

// mmJoyMan::PollJoyButtons
#define MM_POLL_JOY_BUTTON_INDEX_SHIFT 8 // Joystick index of button pressed ((index + 1) << 8)

// mmJoyMan::PollJoyAxes
#define MM_POLL_JOY_AXES_INDEX 0x1000 // Joystick index of axis pressed (0x1000 << index)

// ?IODev@@3PAVmmIODev@@A
ARTS_IMPORT extern mmIODev* IODev;

namespace $
{
    enum ioType : i32 // 'k' prefix
    {
        Undef = 0,
        Discrete = 1,   // Key/Button
        Continuous = 2, // Mouse/Joystick
        Event = 3,
    };

    enum mmIODevice : i32
    {
        Mouse = 2,     // MM_MOUSE
        Keyboard = 3,  // MM_KEYBOARD
        Joystick1 = 4, // MM_JOYSTICK1

        // Unsupported
        Joystick2 = 5, // MM_JOYSTICK2
        Joystick3 = 6, // MM_JOYSTICK3
        Joystick4 = 7, // MM_JOYSTICK4
    };

    enum mmJoyInput : i32 // 'k' prefix
    {
        MButtonLeft = 1,  // EQ_BUTTON_LEFT
        MButtonRight = 2, // EQ_BUTTON_RIGHT

        Xaxis = 10,
        Yaxis = 11,
        Zaxis = 12,
        Uaxis = 13,
        Raxis = 14,
        Vaxis = 15,
        POVaxis = 16,
        XaxisLeft = 17,
        XaxisRight = 18,
        YaxisUp = 19,
        YaxisDown = 20,
        JButton1 = 21,
        JButton2 = 22,
        JButton3 = 23,
        JButton4 = 24,
        JButton5 = 25,
        JButton6 = 26,
        JButton7 = 27,
        JButton8 = 28,
        JButton9 = 29,
        JButton10 = 30,
        JButton11 = 31,
        JButton12 = 32,

        // New
        // TODO: Handle in mmInput::ProcessJoyEvents
        // TODO: Handle in mmInput::BuildCaptureIO
        // TODO: Handle in mmInput::SaveCodeConfig
        ZaxisUp = 33,
        ZaxisDown = 34,

        RaxisUp = 35,
        RaxisDown = 36,
    };
} // namespace $

using $::ioType;
using $::mmIODevice;
using $::mmJoyInput;

// ?InputConfiguration@@3HA
ARTS_IMPORT extern i32 InputConfiguration;

// ?LocStrButton@@3PADA
ARTS_IMPORT extern char* LocStrButton;

// ?LocStrJoystick@@3PADA
ARTS_IMPORT extern char* LocStrJoystick;

// ?LocStrKey@@3PADA
ARTS_IMPORT extern char* LocStrKey;

// ?LocStrUndef@@3PADA
ARTS_IMPORT extern char* LocStrUndef;

// ?UseDIKey@@3HA
ARTS_IMPORT extern i32 UseDIKey;

// ?gpdi@@3PAUIDirectInputA@@A
ARTS_IMPORT extern IDirectInputA* gpdi;

// ?testValue@@3MA
ARTS_IMPORT extern f32 testValue;

class eqEventQ;
class mmIO;
class mmJoyMan;

class mmInput final : public asNode
{
public:
    // ??0mmInput@@QAE@XZ
    ARTS_IMPORT mmInput();

    // ??_EmmInput@@UAEPAXI@Z
    // ??1mmInput@@UAE@XZ
    ARTS_IMPORT ~mmInput() override;

    // ?AssignIO@mmInput@@QAEXPAVmmIO@@HH@Z
    ARTS_IMPORT void AssignIO(mmIO* arg1, i32 arg2, i32 arg3);

    // ?AttachToPipe@mmInput@@QAEHXZ
    ARTS_IMPORT i32 AttachToPipe();

    // ?AutoSetup@mmInput@@QAEXXZ
    ARTS_EXPORT void AutoSetup();

    // ?BinaryLoadConfig@mmInput@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 BinaryLoadConfig(Stream* arg1);

    // ?BinarySaveConfig@mmInput@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 BinarySaveConfig(Stream* arg1);

    // ?BuildCaptureIO@mmInput@@QAEHHPAVmmIO@@TeqEvent@@@Z
    ARTS_EXPORT i32 BuildCaptureIO(i32 button, mmIO* io, eqEvent event);

    // ?CaptureState@mmInput@@QAEXH@Z
    ARTS_IMPORT void CaptureState(i32 arg1);

    // ?ClearEventHitFlags@mmInput@@QAEXXZ
    ARTS_IMPORT void ClearEventHitFlags();

    // ?DeviceConnected@mmInput@@QAEHXZ
    ARTS_IMPORT b32 DeviceConnected();

    // ?DoingFF@mmInput@@QAEHXZ
    ARTS_IMPORT i32 DoingFF();

    // ?FFIsPlaying@mmInput@@QAEHH@Z
    ARTS_IMPORT i32 FFIsPlaying(i32 arg1);

    // ?FFPlay@mmInput@@QAEHH@Z
    ARTS_IMPORT i32 FFPlay(i32 arg1);

    // ?FFSetValues@mmInput@@QAEHHMM@Z
    ARTS_IMPORT i32 FFSetValues(i32 arg1, f32 arg2, f32 arg3);

    // ?FFStop@mmInput@@QAEHH@Z
    ARTS_IMPORT i32 FFStop(i32 arg1);

    // ?FilterGamepadSteering@mmInput@@QAEMXZ
    ARTS_IMPORT f32 FilterGamepadSteering();

    // ?FlagIODevChanged@mmInput@@QAEXXZ
    ARTS_EXPORT void FlagIODevChanged();

    // ?Flush@mmInput@@QAEXXZ
    ARTS_EXPORT void Flush();

    // ?ForceAssignment@mmInput@@QAEXPAVmmIO@@@Z
    ARTS_IMPORT void ForceAssignment(mmIO* arg1);

    // ?GamepadConnected@mmInput@@QAEHXZ
    ARTS_EXPORT b32 GamepadConnected();

    // ?GetBrakes@mmInput@@QAEMXZ
    ARTS_EXPORT f32 GetBrakes();

    // ?GetBrakesVal@mmInput@@QAEMXZ
    ARTS_EXPORT f32 GetBrakesVal();

    // ?GetCamPan@mmInput@@QAEMXZ
    ARTS_IMPORT f32 GetCamPan();

    // ?GetClass@mmInput@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetHandBrake@mmInput@@QAEMXZ
    ARTS_IMPORT f32 GetHandBrake();

    // ?GetSteering@mmInput@@QAEMXZ
    ARTS_IMPORT f32 GetSteering();

    // ?GetThrottle@mmInput@@QAEMXZ
    ARTS_IMPORT f32 GetThrottle();

    // ?GetThrottleVal@mmInput@@QAEMXZ
    ARTS_IMPORT f32 GetThrottleVal();

    // ?IOInit@mmInput@@QAEXHPAULocString@@J@Z
    ARTS_IMPORT void IOInit(i32 arg1, LocString* arg2, ilong arg3);

    // ?Init@mmInput@@QAEXH@Z
    ARTS_IMPORT void Init(i32 arg1);

    // ?IsAlreadyAssigned@mmInput@@QAEHPAVmmIO@@HHH@Z
    ARTS_IMPORT i32 IsAlreadyAssigned(mmIO* arg1, i32 arg2, i32 arg3, i32 arg4);

    // ?JoystickConnected@mmInput@@QAEHXZ
    ARTS_EXPORT b32 JoystickConnected();

    // ?JoystickHasCoolie@mmInput@@QAEHXZ
    ARTS_IMPORT b32 JoystickHasCoolie();

    // ?JoystickHasThrottle@mmInput@@QAEHXZ | unused
    ARTS_IMPORT b32 JoystickHasThrottle();

    // ?LoadConfig@mmInput@@QAEHPAVStream@@@Z | unused
    ARTS_IMPORT i32 LoadConfig(Stream* arg1);

    // ?PollStates@mmInput@@QAEHXZ
    ARTS_IMPORT i32 PollStates();

    // ?PollSuperQ@mmInput@@QAEHXZ
    ARTS_IMPORT i32 PollSuperQ();

    // ?PopEvent@mmInput@@QAEHPAH@Z
    ARTS_IMPORT i32 PopEvent(i32* arg1);

    // ?PrintIODev@mmInput@@QAEXXZ | unused
    ARTS_IMPORT void PrintIODev();

    // ?Reset@mmInput@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?RestoreDefaultConfig@mmInput@@QAEXH@Z
    ARTS_IMPORT void RestoreDefaultConfig(i32 arg1);

    // ?ReturnStateCaptured@mmInput@@QAEHXZ
    ARTS_IMPORT i32 ReturnStateCaptured();

    // ?SanityCheck@mmInput@@QAEHPAVmmIO@@HH@Z
    ARTS_IMPORT i32 SanityCheck(mmIO* arg1, i32 arg2, i32 arg3);

    // ?SaveCB@mmInput@@QAEXXZ
    ARTS_IMPORT void SaveCB();

    // ?SaveCodeConfig@mmInput@@QAEHPAVStream@@@Z
    ARTS_IMPORT i32 SaveCodeConfig(Stream* arg1);

    // ?SaveConfig@mmInput@@QAEHPAVStream@@@Z | unused
    ARTS_IMPORT i32 SaveConfig(Stream* arg1);

    // ?SetDeadZone@mmInput@@QAEXM@Z | unused
    ARTS_IMPORT void SetDeadZone(f32 arg1);

    // ?SetDefaultConfig@mmInput@@QAEXH@Z
    ARTS_EXPORT void SetDefaultConfig(i32 config);

    // ?SetForceFeedbackScale@mmInput@@QAEXM@Z | unused
    ARTS_IMPORT void SetForceFeedbackScale(f32 arg1);

    // ?SetRoadForceScale@mmInput@@QAEXM@Z | unused
    ARTS_IMPORT void SetRoadForceScale(f32 arg1);

    // ?StopAllFF@mmInput@@QAEXXZ
    ARTS_IMPORT void StopAllFF();

    // ?ToggleFFEnabled@mmInput@@QAEHH@Z
    ARTS_IMPORT i32 ToggleFFEnabled(i32 arg1);

    // ?Update@mmInput@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?WheelConnected@mmInput@@QAEHXZ
    ARTS_EXPORT b32 WheelConnected();

    // ?WheelHas3Axis@mmInput@@QAEHXZ | unused
    ARTS_IMPORT b32 WheelHas3Axis();

    // ?DeclareFields@mmInput@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    ARTS_ZEROED;

    bool IsInputPressed(i32 ioid) const
    {
        return (CurrentState >> ioid) & 1;
    }

    mmJoyMan* Joy;
    mmIO* IO;
    i32 NumControls;
    eqEventQ* Events;
    eqEvent CaptureEvent;
    i32 field_54;
    i64 EventQueue[30];
    i32 QueuedEvents;
    i32 WantPoll;
    i32 StateCaptured;
    i32 field_154;
    i32 LastUnassigned;
    i32 field_15C;

    // Bitset of pressed IOID_* inputs
    i64 CurrentState;

    i32 HasForceFeedback;
    i32 UseForceFeedback;
    f32 CollideCooldown;
    f32 CollidePeriod;
    i32 field_178;
    i32 field_17C;
    i32 field_180;
    i32 SteeringType;
    i32 field_188;
    i32 HasCoolie;
    i32 field_190;
    i32 AutoReverse;
    f32 BrakesVal;
    f32 HandbrakeVal;
    f32 ThrottleVal;
    f32 SteeringVal;
    f32 GamepadSteeringVal;
    f32 CamPanVal;
    f32 DiscreteSteeringLimit;
    f32 ForceFeedbackScale;
    f32 RoadForceScale;
    f32 JoyDeadZone;
    f32 MouseSensitivity;
    f32 UserSteeringSensitivity;
    f32 DiscreteSteeringDeltaIn;
    f32 DiscreteSteeringDeltaOut;
    f32 SteeringExponent;
    b32 SwapThrottle;
    b32 ResetMouse;
    i32 MousePrevX;
    i32 MousePrevY;
    f32 ScreenCenterX;
    f32 ScreenCenterY;
    f32 InvScreenCenterX;
    f32 InvScreenCenterY;
    i32 CaptureDevice;
    i32 CaptureComponent;
    i32 field_1FC;
    i8 KeyboardPresses[64];
    i32 NumKeyboardInputs;
    i32 field_244;

private:
#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmInput@@EAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?EventToButton@mmInput@@AAEHH@Z | unused
    ARTS_EXPORT i32 EventToButton(i32 event);

    // ?FilterDiscreteSteering@mmInput@@AAEMM@Z
    ARTS_IMPORT f32 FilterDiscreteSteering(f32 arg1);

    // ?GetBufferedKeyboardData@mmInput@@AAEXXZ
    ARTS_EXPORT void GetBufferedKeyboardData();

    // ?GetNextKeyboardEvent@mmInput@@AAEHPATeqEvent@@@Z
    ARTS_EXPORT b32 GetNextKeyboardEvent(eqEvent* event);

    // ?PollContinuous@mmInput@@AAEXPAVmmIO@@@Z
    ARTS_IMPORT void PollContinuous(mmIO* arg1);

    // ?ProcessEvents@mmInput@@AAEXXZ
    ARTS_EXPORT void ProcessEvents();

    // ?ProcessJoyEvents@mmInput@@AAEXXZ
    ARTS_IMPORT void ProcessJoyEvents();

    // ?ProcessKeyboardEvents@mmInput@@AAEXXZ
    ARTS_EXPORT void ProcessKeyboardEvents();

    // ?ProcessMouseEvents@mmInput@@AAEXXZ
    ARTS_EXPORT void ProcessMouseEvents();

    // ?ProcessStates@mmInput@@AAE_JXZ
    ARTS_IMPORT i64 ProcessStates();

    // ?PutEventInQueue@mmInput@@AAEX_J@Z
    ARTS_IMPORT void PutEventInQueue(i64 arg1);

    // ?ScanForEvent@mmInput@@AAE_JPATeqEvent@@@Z
    ARTS_EXPORT i64 ScanForEvent(eqEvent* event);

    // ?ScanState@mmInput@@AAE_JPAVmmIO@@@Z
    ARTS_IMPORT i64 ScanState(mmIO* arg1);
};

check_size(mmInput, 0x248);

// ?GameInputPtr@@3PAVmmInput@@A
ARTS_IMPORT extern mmInput* GameInputPtr;

inline mmInput* GameInput()
{
    return GameInputPtr;
}