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
    ARTS_EXPORT mmTimer() = default;

    // ??_GmmTimer@@UAEPAXI@Z
    // ??_EmmTimer@@UAEPAXI@Z
    // ??1mmTimer@@UAE@XZ
    ARTS_EXPORT ~mmTimer() override = default;

    // ?GetTime@mmTimer@@QAEMXZ
    ARTS_EXPORT f32 GetTime();

    // ?Init@mmTimer@@QAEXHM@Z
    ARTS_EXPORT void Init(b32 count_down, f32 start_time);

    // ?Reset@mmTimer@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // ?Start@mmTimer@@QAEXXZ
    ARTS_EXPORT void Start();

    // ?StartStop@mmTimer@@QAEXXZ | unused
    ARTS_EXPORT void StartStop();

    // ?Stop@mmTimer@@QAEXXZ
    ARTS_EXPORT void Stop();

    // ?Update@mmTimer@@UAEXXZ
    ARTS_EXPORT void Update() override;

    b32 CountDown {};
    f32 StartTime {};
    f32 Time {};
    b32 Running {};
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

    // ?StartTimers@mmHUD@@QAEXXZ
    ARTS_IMPORT void StartTimers();

    // ?StopTimers@mmHUD@@QAEXXZ
    ARTS_IMPORT void StopTimers();

    // ?ToggleDash@mmHUD@@QAEXXZ
    ARTS_IMPORT void ToggleDash();

    // ?ToggleExternalView@mmHUD@@QAEXXZ
    ARTS_IMPORT void ToggleExternalView();

    // ?ToggleMirror@mmHUD@@QAEXXZ
    ARTS_EXPORT void ToggleMirror();

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
