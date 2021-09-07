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
    mmgame:hud

    0x404C20 | public: __thiscall mmHUD::mmHUD(void) | ??0mmHUD@@QAE@XZ
    0x405060 | public: void __thiscall mmHUD::PostChatMessage(char *) | ?PostChatMessage@mmHUD@@QAEXPAD@Z
    0x4050C0 | public: virtual void __thiscall mmHUD::ResChange(int,int) | ?ResChange@mmHUD@@UAEXHH@Z
    0x405190 | public: virtual __thiscall mmHUD::~mmHUD(void) | ??1mmHUD@@UAE@XZ
    0x405320 | public: void __thiscall mmHUD::StartTimers(void) | ?StartTimers@mmHUD@@QAEXXZ
    0x405340 | public: void __thiscall mmHUD::StopTimers(void) | ?StopTimers@mmHUD@@QAEXXZ
    0x405360 | public: void __thiscall mmHUD::ResetTimers(void) | ?ResetTimers@mmHUD@@QAEXXZ
    0x405390 | public: void __thiscall mmHUD::ShowClockTime(void) | ?ShowClockTime@mmHUD@@QAEXXZ
    0x4053E0 | public: void __thiscall mmHUD::Init(char *,class mmPlayer *) | ?Init@mmHUD@@QAEXPADPAVmmPlayer@@@Z
    0x4056C0 | public: void __thiscall mmHUD::Enable(void) | ?Enable@mmHUD@@QAEXXZ
    0x405700 | public: void __thiscall mmHUD::Disable(int) | ?Disable@mmHUD@@QAEXH@Z
    0x405750 | public: void __thiscall mmHUD::Toggle(void) | ?Toggle@mmHUD@@QAEXXZ
    0x405770 | public: void __thiscall mmHUD::ToggleExternalView(void) | ?ToggleExternalView@mmHUD@@QAEXXZ
    0x4057C0 | public: void __thiscall mmHUD::ToggleDash(void) | ?ToggleDash@mmHUD@@QAEXXZ
    0x405800 | public: void __thiscall mmHUD::ActivateDash(void) | ?ActivateDash@mmHUD@@QAEXXZ
    0x405830 | public: void __thiscall mmHUD::DeactivateDash(void) | ?DeactivateDash@mmHUD@@QAEXXZ
    0x405860 | public: int __thiscall mmHUD::IsDashActive(void) | ?IsDashActive@mmHUD@@QAEHXZ
    0x405870 | public: virtual void __thiscall mmHUD::Reset(void) | ?Reset@mmHUD@@UAEXXZ
    0x405910 | public: virtual void __thiscall mmHUD::Update(void) | ?Update@mmHUD@@UAEXXZ
    0x405CE0 | public: virtual void __thiscall mmHUD::UpdatePaused(void) | ?UpdatePaused@mmHUD@@UAEXXZ
    0x405D10 | public: void __thiscall mmHUD::ToggleMirror(void) | ?ToggleMirror@mmHUD@@QAEXXZ
    0x405D30 | public: virtual void __thiscall mmHUD::Cull(void) | ?Cull@mmHUD@@UAEXXZ
    0x405E00 | public: void __thiscall mmHUD::SetStandings(int,int) | ?SetStandings@mmHUD@@QAEXHH@Z
    0x405E40 | public: void __thiscall mmHUD::SetLapTime(int,float,int) | ?SetLapTime@mmHUD@@QAEXHMH@Z
    0x405E80 | public: void __thiscall mmHUD::SetWPCleared(int,int) | ?SetWPCleared@mmHUD@@QAEXHH@Z
    0x405EA0 | public: void __thiscall mmHUD::SetMessage(struct LocString *,float,int) | ?SetMessage@mmHUD@@QAEXPAULocString@@MH@Z
    0x405EE0 | public: void __thiscall mmHUD::SetMessage2(struct LocString *) | ?SetMessage2@mmHUD@@QAEXPAULocString@@@Z
    0x405F10 | public: void __thiscall mmHUD::SetScore(char *) | ?SetScore@mmHUD@@QAEXPAD@Z
    0x405F30 | public: void __thiscall mmHUD::AddPlayer(char *,unsigned long,int,int) | ?AddPlayer@mmHUD@@QAEXPADKHH@Z
    0x405F60 | public: void __thiscall mmHUD::SetScore(unsigned long,int) | ?SetScore@mmHUD@@QAEXKH@Z
    0x405F80 | public: void __thiscall mmHUD::RemovePlayer(unsigned long) | ?RemovePlayer@mmHUD@@QAEXK@Z
    0x405FA0 | public: void __thiscall mmHUD::ActivateGold(void) | ?ActivateGold@mmHUD@@QAEXXZ
    0x405FB0 | public: void __thiscall mmHUD::DeactivateGold(void) | ?DeactivateGold@mmHUD@@QAEXXZ
    0x405FC0 | public: void __thiscall mmHUD::GetTime(char *,float) | ?GetTime@mmHUD@@QAEXPADM@Z
    0x405FE0 | public: void __thiscall mmHUD::PlayNetAlert(void) | ?PlayNetAlert@mmHUD@@QAEXXZ
    0x406000 | public: void __thiscall mmHUD::TogglePositionDisplay(int) | ?TogglePositionDisplay@mmHUD@@QAEXH@Z
    0x406060 | public: void __thiscall mmHUD::GetPosHdg(class Vector4 &) | ?GetPosHdg@mmHUD@@QAEXAAVVector4@@@Z
    0x4060F0 | public: void __thiscall mmHUD::RecordPosition(char *) | ?RecordPosition@mmHUD@@QAEXPAD@Z
    0x406170 | public: virtual void __thiscall mmHUD::AddWidgets(class Bank *) | ?AddWidgets@mmHUD@@UAEXPAVBank@@@Z
    0x4061E0 | public: __thiscall mmTimer::mmTimer(void) | ??0mmTimer@@QAE@XZ
    0x406200 | public: virtual __thiscall mmTimer::~mmTimer(void) | ??1mmTimer@@UAE@XZ
    0x406210 | public: void __thiscall mmTimer::Init(int,float) | ?Init@mmTimer@@QAEXHM@Z
    0x406230 | public: float __thiscall mmTimer::GetTime(void) | ?GetTime@mmTimer@@QAEMXZ
    0x406240 | public: virtual void __thiscall mmTimer::Update(void) | ?Update@mmTimer@@UAEXXZ
    0x406290 | public: virtual void __thiscall mmTimer::Reset(void) | ?Reset@mmTimer@@UAEXXZ
    0x4062A0 | public: void __thiscall mmTimer::Start(void) | ?Start@mmTimer@@QAEXXZ
    0x4062B0 | public: void __thiscall mmTimer::Stop(void) | ?Stop@mmTimer@@QAEXXZ
    0x4062C0 | public: void __thiscall mmTimer::StartStop(void) | ?StartStop@mmTimer@@QAEXXZ
    0x4062D0 | public: __thiscall mmArrow::mmArrow(void) | ??0mmArrow@@QAE@XZ
    0x406450 | public: virtual __thiscall mmArrow::~mmArrow(void) | ??1mmArrow@@UAE@XZ
    0x4064C0 | public: void __thiscall mmArrow::Init(class Matrix34 *) | ?Init@mmArrow@@QAEXPAVMatrix34@@@Z
    0x4064D0 | public: virtual void __thiscall mmArrow::Reset(void) | ?Reset@mmArrow@@UAEXXZ
    0x4064E0 | public: void __thiscall mmArrow::SetInterest(class Vector3 *) | ?SetInterest@mmArrow@@QAEXPAVVector3@@@Z
    0x4064F0 | private: void __thiscall mmArrow::ReColorArrow(int) | ?ReColorArrow@mmArrow@@AAEXH@Z
    0x406560 | public: virtual void __thiscall mmArrow::Update(void) | ?Update@mmArrow@@UAEXXZ
    0x406760 | public: static void __cdecl mmHUD::DeclareFields(void) | ?DeclareFields@mmHUD@@SAXXZ
    0x4068D0 | public: virtual class MetaClass * __thiscall mmHUD::GetClass(void) | ?GetClass@mmHUD@@UAEPAVMetaClass@@XZ
    0x406910 | public: virtual __thiscall mmExternalView::~mmExternalView(void) | ??1mmExternalView@@UAE@XZ
    0x406960 | public: virtual __thiscall mmCDPlayer::~mmCDPlayer(void) | ??1mmCDPlayer@@UAE@XZ
    0x4069C0 | public: virtual void * __thiscall mmTimer::`vector deleting destructor'(unsigned int) | ??_EmmTimer@@UAEPAXI@Z
    0x4069C0 | public: virtual void * __thiscall mmTimer::`scalar deleting destructor'(unsigned int) | ??_GmmTimer@@UAEPAXI@Z
    0x4069F0 | public: virtual void * __thiscall mmArrow::`vector deleting destructor'(unsigned int) | ??_EmmArrow@@UAEPAXI@Z
    0x4069F0 | public: virtual void * __thiscall mmArrow::`scalar deleting destructor'(unsigned int) | ??_GmmArrow@@UAEPAXI@Z
    0x406A20 | public: virtual void * __thiscall mmHUD::`vector deleting destructor'(unsigned int) | ??_EmmHUD@@UAEPAXI@Z
    0x61A1C8 | const mmHUD::`vftable' | ??_7mmHUD@@6B@
    0x61A208 | const mmTimer::`vftable' | ??_7mmTimer@@6B@
    0x61A248 | const mmArrow::`vftable' | ??_7mmArrow@@6B@
    0x635170 | float arotX | ?arotX@@3MA
    0x635174 | int FirstPrintTime | ?FirstPrintTime@@3HA
    0x6A6D98 | float defmass | ?defmass@@3MA
    0x6A6DA8 | class MetaClass mmHUDMetaClass | ?mmHUDMetaClass@@3VMetaClass@@A
    0x6A6DD0 | float LastResetTime | ?LastResetTime@@3MA
*/

#include "arts7/node.h"

#include "cd.h"
#include "dash.h"
#include "mmeffects/mmnumber.h"
#include "mmeffects/mmtext.h"
#include "vector7/vector4.h"

class AudSound;
class mmCircuitHUD;
class mmCRHUD;
class mmWPHUD;

class mmTimer final : public asNode
{
public:
    // ??0mmTimer@@QAE@XZ
    ARTS_IMPORT mmTimer();

    // ??_GmmTimer@@UAEPAXI@Z
    // ??_EmmTimer@@UAEPAXI@Z
    // ??1mmTimer@@UAE@XZ
    ARTS_IMPORT ~mmTimer() override = default;

    // ?GetTime@mmTimer@@QAEMXZ
    ARTS_IMPORT f32 GetTime();

    // ?Init@mmTimer@@QAEXHM@Z
    ARTS_IMPORT void Init(i32 arg1, f32 arg2);

    // ?Reset@mmTimer@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Start@mmTimer@@QAEXXZ
    ARTS_IMPORT void Start();

    // ?StartStop@mmTimer@@QAEXXZ | unused
    ARTS_IMPORT void StartStop();

    // ?Stop@mmTimer@@QAEXXZ
    ARTS_IMPORT void Stop();

    // ?Update@mmTimer@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x10];
};

check_size(mmTimer, 0x30);

class mmArrow final : public asNode
{
public:
    // ??0mmArrow@@QAE@XZ
    ARTS_IMPORT mmArrow();

    // ??_GmmArrow@@UAEPAXI@Z
    // ??_EmmArrow@@UAEPAXI@Z
    // ??1mmArrow@@UAE@XZ
    ARTS_IMPORT ~mmArrow() override;

    // ?Init@mmArrow@@QAEXPAVMatrix34@@@Z
    ARTS_IMPORT void Init(Matrix34* arg1);

    // ?Reset@mmArrow@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetInterest@mmArrow@@QAEXPAVVector3@@@Z
    ARTS_IMPORT void SetInterest(Vector3* arg1);

    // ?Update@mmArrow@@UAEXXZ
    ARTS_IMPORT void Update() override;

private:
    // ?ReColorArrow@mmArrow@@AAEXH@Z
    ARTS_IMPORT void ReColorArrow(i32 arg1);

    u8 gap20[0x18];
};

check_size(mmArrow, 0x38);

class mmHUD final : public asNode
{
public:
    // ??0mmHUD@@QAE@XZ
    ARTS_IMPORT mmHUD();

    // ??_EmmHUD@@UAEPAXI@Z
    // ??1mmHUD@@UAE@XZ
    ARTS_IMPORT ~mmHUD() override;

    // ?ActivateDash@mmHUD@@QAEXXZ
    ARTS_IMPORT void ActivateDash();

    // ?ActivateGold@mmHUD@@QAEXXZ
    ARTS_IMPORT void ActivateGold();

    // ?AddPlayer@mmHUD@@QAEXPADKHH@Z
    ARTS_IMPORT void AddPlayer(char* arg1, ulong arg2, i32 arg3, i32 arg4);

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmHUD@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Cull@mmHUD@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?DeactivateDash@mmHUD@@QAEXXZ
    ARTS_IMPORT void DeactivateDash();

    // ?DeactivateGold@mmHUD@@QAEXXZ
    ARTS_IMPORT void DeactivateGold();

    // ?Disable@mmHUD@@QAEXH@Z
    ARTS_IMPORT void Disable(i32 arg1);

    // ?Enable@mmHUD@@QAEXXZ
    ARTS_IMPORT void Enable();

    // ?GetClass@mmHUD@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetPosHdg@mmHUD@@QAEXAAVVector4@@@Z
    ARTS_IMPORT void GetPosHdg(Vector4& arg1);

    // ?GetTime@mmHUD@@QAEXPADM@Z
    ARTS_IMPORT void GetTime(char* arg1, f32 arg2);

    // ?Init@mmHUD@@QAEXPADPAVmmPlayer@@@Z
    ARTS_IMPORT void Init(char* arg1, mmPlayer* arg2);

    // ?IsDashActive@mmHUD@@QAEHXZ
    ARTS_IMPORT i32 IsDashActive();

    // ?PlayNetAlert@mmHUD@@QAEXXZ
    ARTS_IMPORT void PlayNetAlert();

    // ?PostChatMessage@mmHUD@@QAEXPAD@Z
    ARTS_IMPORT void PostChatMessage(aconst char* arg1);

    // ?RecordPosition@mmHUD@@QAEXPAD@Z
    ARTS_IMPORT void RecordPosition(aconst char* arg1);

    // ?RemovePlayer@mmHUD@@QAEXK@Z
    ARTS_IMPORT void RemovePlayer(ulong arg1);

    // ?ResChange@mmHUD@@UAEXHH@Z
    ARTS_IMPORT void ResChange(i32 arg1, i32 arg2) override;

    // ?Reset@mmHUD@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?ResetTimers@mmHUD@@QAEXXZ
    ARTS_IMPORT void ResetTimers();

    // ?SetLapTime@mmHUD@@QAEXHMH@Z
    ARTS_IMPORT void SetLapTime(i32 arg1, f32 arg2, i32 arg3);

    // ?SetMessage@mmHUD@@QAEXPAULocString@@MH@Z
    ARTS_IMPORT void SetMessage(LocString* arg1, f32 time, b32 top = false);

    // ?SetMessage2@mmHUD@@QAEXPAULocString@@@Z
    ARTS_IMPORT void SetMessage2(LocString* arg1);

    // ?SetScore@mmHUD@@QAEXPAD@Z
    ARTS_IMPORT void SetScore(char* arg1);

    // ?SetScore@mmHUD@@QAEXKH@Z
    ARTS_IMPORT void SetScore(ulong arg1, i32 arg2);

    // ?SetStandings@mmHUD@@QAEXHH@Z
    ARTS_IMPORT void SetStandings(i32 arg1, i32 arg2);

    // ?SetWPCleared@mmHUD@@QAEXHH@Z
    ARTS_IMPORT void SetWPCleared(i32 arg1, i32 arg2);

    // ?ShowClockTime@mmHUD@@QAEXXZ | unused
    ARTS_IMPORT void ShowClockTime();

    // ?StartTimers@mmHUD@@QAEXXZ
    ARTS_IMPORT void StartTimers();

    // ?StopTimers@mmHUD@@QAEXXZ
    ARTS_IMPORT void StopTimers();

    // ?Toggle@mmHUD@@QAEXXZ | unused
    ARTS_IMPORT void Toggle();

    // ?ToggleDash@mmHUD@@QAEXXZ
    ARTS_IMPORT void ToggleDash();

    // ?ToggleExternalView@mmHUD@@QAEXXZ
    ARTS_IMPORT void ToggleExternalView();

    // ?ToggleMirror@mmHUD@@QAEXXZ
    ARTS_IMPORT void ToggleMirror();

    // ?TogglePositionDisplay@mmHUD@@QAEXH@Z
    ARTS_EXPORT void TogglePositionDisplay(i32 mode);

    // ?Update@mmHUD@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdatePaused@mmHUD@@UAEXXZ
    ARTS_EXPORT void UpdatePaused() override;

    // ?DeclareFields@mmHUD@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    mmPlayer* Player;
    mmDashView DashView;
    mmExternalView ExternalView;
    void* PositionFont;
    void* MessageFont;
    void* ChatFont;
    mmTextNode UpperMessage;
    mmTextNode LowerMessage;
    mmTextNode ChatMessages;
    mmNumberFont NumberFont;
    i32 TimerCountDown;
    i32 WaypointDist;
    i32 field_AE4;
    i32 ShowTimer;
    agiBitmap* Bitmaps[11];
    i32 field_B18;
    i32 field_B1C;
    i32 field_B20;
    i32 field_B24;
    i32 TimerParts[8];
    i32 field_B48;
    i32 field_B4C;
    i32 TimerY;
    asNode HudElements;
    mmWPHUD* WpHud;
    mmCircuitHUD* CircuitHud;
    mmCRHUD* CrHud;
    mmArrow Arrow;
    f32 MessageFadeTime;
    i32 field_BBC;
    b32 ShowMessageAtTop;
    mmTimer ClockTimer;
    mmTimer LapTimer;
    mmTimer BlitzTimer;
    AudSound* AlertSound;
    b32 ShowPosition;
    mmNumber NumberText;
    mmTextNode PositionText;
    Vector4 CurrentPosition;
    mmCDPlayer CDPlayer;
    b16 DamageWarning;
    AudSound* DamageWarningSound;
};

check_size(mmHUD, 0xE94);

// ?FirstPrintTime@@3HA
ARTS_IMPORT extern i32 FirstPrintTime;

// ?LastResetTime@@3MA
ARTS_IMPORT extern f32 LastResetTime;

// ?arotX@@3MA
ARTS_IMPORT extern f32 arotX;

// ?defmass@@3MA
ARTS_IMPORT extern f32 defmass;
