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

class mmHUD : public asNode
{
    // const mmHUD::`vftable' @ 0x61A1C8

public:
    // 0x404C20 | ??0mmHUD@@QAE@XZ
    ARTS_IMPORT mmHUD();

    // 0x406A20 | ??_EmmHUD@@UAEPAXI@Z
    // 0x405190 | ??1mmHUD@@UAE@XZ
    ARTS_IMPORT ~mmHUD() override;

    // 0x405800 | ?ActivateDash@mmHUD@@QAEXXZ
    ARTS_IMPORT void ActivateDash();

    // 0x405FA0 | ?ActivateGold@mmHUD@@QAEXXZ
    ARTS_IMPORT void ActivateGold();

    // 0x405F30 | ?AddPlayer@mmHUD@@QAEXPADKHH@Z
    ARTS_IMPORT void AddPlayer(char* arg1, u32 arg2, i32 arg3, i32 arg4);

    // 0x406170 | ?AddWidgets@mmHUD@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x405D30 | ?Cull@mmHUD@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x405830 | ?DeactivateDash@mmHUD@@QAEXXZ
    ARTS_IMPORT void DeactivateDash();

    // 0x405FB0 | ?DeactivateGold@mmHUD@@QAEXXZ
    ARTS_IMPORT void DeactivateGold();

    // 0x405700 | ?Disable@mmHUD@@QAEXH@Z
    ARTS_IMPORT void Disable(i32 arg1);

    // 0x4056C0 | ?Enable@mmHUD@@QAEXXZ
    ARTS_IMPORT void Enable();

    // 0x4068D0 | ?GetClass@mmHUD@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x406060 | ?GetPosHdg@mmHUD@@QAEXAAVVector4@@@Z
    ARTS_IMPORT void GetPosHdg(class Vector4& arg1);

    // 0x405FC0 | ?GetTime@mmHUD@@QAEXPADM@Z
    ARTS_IMPORT void GetTime(char* arg1, f32 arg2);

    // 0x4053E0 | ?Init@mmHUD@@QAEXPADPAVmmPlayer@@@Z
    ARTS_IMPORT void Init(char* arg1, class mmPlayer* arg2);

    // 0x405860 | ?IsDashActive@mmHUD@@QAEHXZ
    ARTS_IMPORT i32 IsDashActive();

    // 0x405FE0 | ?PlayNetAlert@mmHUD@@QAEXXZ
    ARTS_IMPORT void PlayNetAlert();

    // 0x405060 | ?PostChatMessage@mmHUD@@QAEXPAD@Z
    ARTS_IMPORT void PostChatMessage(char* arg1);

    // 0x4060F0 | ?RecordPosition@mmHUD@@QAEXPAD@Z
    ARTS_IMPORT void RecordPosition(char* arg1);

    // 0x405F80 | ?RemovePlayer@mmHUD@@QAEXK@Z
    ARTS_IMPORT void RemovePlayer(u32 arg1);

    // 0x4050C0 | ?ResChange@mmHUD@@UAEXHH@Z
    ARTS_IMPORT void ResChange(i32 arg1, i32 arg2) override;

    // 0x405870 | ?Reset@mmHUD@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x405360 | ?ResetTimers@mmHUD@@QAEXXZ
    ARTS_IMPORT void ResetTimers();

    // 0x405E40 | ?SetLapTime@mmHUD@@QAEXHMH@Z
    ARTS_IMPORT void SetLapTime(i32 arg1, f32 arg2, i32 arg3);

    // 0x405EA0 | ?SetMessage@mmHUD@@QAEXPAULocString@@MH@Z
    ARTS_IMPORT void SetMessage(struct LocString* arg1, f32 arg2, i32 arg3);

    // 0x405EE0 | ?SetMessage2@mmHUD@@QAEXPAULocString@@@Z
    ARTS_IMPORT void SetMessage2(struct LocString* arg1);

    // 0x405F10 | ?SetScore@mmHUD@@QAEXPAD@Z
    ARTS_IMPORT void SetScore(char* arg1);

    // 0x405F60 | ?SetScore@mmHUD@@QAEXKH@Z
    ARTS_IMPORT void SetScore(u32 arg1, i32 arg2);

    // 0x405E00 | ?SetStandings@mmHUD@@QAEXHH@Z
    ARTS_IMPORT void SetStandings(i32 arg1, i32 arg2);

    // 0x405E80 | ?SetWPCleared@mmHUD@@QAEXHH@Z
    ARTS_IMPORT void SetWPCleared(i32 arg1, i32 arg2);

    // 0x405390 | ?ShowClockTime@mmHUD@@QAEXXZ | unused
    ARTS_IMPORT void ShowClockTime();

    // 0x405320 | ?StartTimers@mmHUD@@QAEXXZ
    ARTS_IMPORT void StartTimers();

    // 0x405340 | ?StopTimers@mmHUD@@QAEXXZ
    ARTS_IMPORT void StopTimers();

    // 0x405750 | ?Toggle@mmHUD@@QAEXXZ | unused
    ARTS_IMPORT void Toggle();

    // 0x4057C0 | ?ToggleDash@mmHUD@@QAEXXZ
    ARTS_IMPORT void ToggleDash();

    // 0x405770 | ?ToggleExternalView@mmHUD@@QAEXXZ
    ARTS_IMPORT void ToggleExternalView();

    // 0x405D10 | ?ToggleMirror@mmHUD@@QAEXXZ
    ARTS_IMPORT void ToggleMirror();

    // 0x406000 | ?TogglePositionDisplay@mmHUD@@QAEXH@Z
    ARTS_IMPORT void TogglePositionDisplay(i32 arg1);

    // 0x405910 | ?Update@mmHUD@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x405CE0 | ?UpdatePaused@mmHUD@@UAEXXZ
    ARTS_IMPORT void UpdatePaused() override;

    // 0x406760 | ?DeclareFields@mmHUD@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0xE74];
};

check_size(mmHUD, 0xE94);

class mmTimer : public asNode
{
    // const mmTimer::`vftable' @ 0x61A208

public:
    // 0x4061E0 | ??0mmTimer@@QAE@XZ
    ARTS_IMPORT mmTimer();

    // 0x4069C0 | ??_GmmTimer@@UAEPAXI@Z
    // 0x4069C0 | ??_EmmTimer@@UAEPAXI@Z
    // 0x406200 | ??1mmTimer@@UAE@XZ
    ARTS_IMPORT ~mmTimer() override = default;

    // 0x406230 | ?GetTime@mmTimer@@QAEMXZ
    ARTS_IMPORT f32 GetTime();

    // 0x406210 | ?Init@mmTimer@@QAEXHM@Z
    ARTS_IMPORT void Init(i32 arg1, f32 arg2);

    // 0x406290 | ?Reset@mmTimer@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4062A0 | ?Start@mmTimer@@QAEXXZ
    ARTS_IMPORT void Start();

    // 0x4062C0 | ?StartStop@mmTimer@@QAEXXZ | unused
    ARTS_IMPORT void StartStop();

    // 0x4062B0 | ?Stop@mmTimer@@QAEXXZ
    ARTS_IMPORT void Stop();

    // 0x406240 | ?Update@mmTimer@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x10];
};

check_size(mmTimer, 0x30);

class mmArrow : public asNode
{
    // const mmArrow::`vftable' @ 0x61A248

public:
    // 0x4062D0 | ??0mmArrow@@QAE@XZ
    ARTS_IMPORT mmArrow();

    // 0x4069F0 | ??_GmmArrow@@UAEPAXI@Z
    // 0x4069F0 | ??_EmmArrow@@UAEPAXI@Z
    // 0x406450 | ??1mmArrow@@UAE@XZ
    ARTS_IMPORT ~mmArrow() override;

    // 0x4064C0 | ?Init@mmArrow@@QAEXPAVMatrix34@@@Z
    ARTS_IMPORT void Init(class Matrix34* arg1);

    // 0x4064D0 | ?Reset@mmArrow@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4064E0 | ?SetInterest@mmArrow@@QAEXPAVVector3@@@Z
    ARTS_IMPORT void SetInterest(class Vector3* arg1);

    // 0x406560 | ?Update@mmArrow@@UAEXXZ
    ARTS_IMPORT void Update() override;

private:
    // 0x4064F0 | ?ReColorArrow@mmArrow@@AAEXH@Z
    ARTS_IMPORT void ReColorArrow(i32 arg1);

    u8 gap20[0x18];
};

check_size(mmArrow, 0x38);

// 0x635174 | ?FirstPrintTime@@3HA
ARTS_IMPORT extern i32 FirstPrintTime;

// 0x6A6DD0 | ?LastResetTime@@3MA
ARTS_IMPORT extern f32 LastResetTime;

// 0x635170 | ?arotX@@3MA
ARTS_IMPORT extern f32 arotX;

// 0x6A6D98 | ?defmass@@3MA
ARTS_IMPORT extern f32 defmass;

// 0x6A6DA8 | ?mmHUDMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmHUDMetaClass;
