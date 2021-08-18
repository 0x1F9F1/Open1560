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
    mmgame:player

    0x429FF0 | public: __thiscall mmPlayer::mmPlayer(void) | ??0mmPlayer@@QAE@XZ
    0x42A370 | public: virtual void __thiscall mmPlayer::BeforeSave(void) | ?BeforeSave@mmPlayer@@UAEXXZ
    0x42A380 | public: virtual void __thiscall mmPlayer::AfterLoad(void) | ?AfterLoad@mmPlayer@@UAEXXZ
    0x42A390 | public: void __thiscall mmPlayer::ReInit(char *) | ?ReInit@mmPlayer@@QAEXPAD@Z
    0x42A520 | public: void __thiscall mmPlayer::Init(char *,char *,class mmGame *) | ?Init@mmPlayer@@QAEXPAD0PAVmmGame@@@Z
    0x42A9A0 | public: void __thiscall mmPlayer::SetMirrorFOV(void) | ?SetMirrorFOV@mmPlayer@@QAEXXZ
    0x42A9D0 | public: void __thiscall mmPlayer::SetPreRaceCam(void) | ?SetPreRaceCam@mmPlayer@@QAEXXZ
    0x42AAF0 | public: void __thiscall mmPlayer::SetPostRaceCam(void) | ?SetPostRaceCam@mmPlayer@@QAEXXZ
    0x42AC10 | public: int __thiscall mmPlayer::IsPOV(void) | ?IsPOV@mmPlayer@@QAEHXZ
    0x42AC60 | public: void __thiscall mmPlayer::SetWideFOV(int) | ?SetWideFOV@mmPlayer@@QAEXH@Z
    0x42ADF0 | public: void __thiscall mmPlayer::ToggleWideFOV(void) | ?ToggleWideFOV@mmPlayer@@QAEXXZ
    0x42AE10 | public: void __thiscall mmPlayer::ToggleCam(void) | ?ToggleCam@mmPlayer@@QAEXXZ
    0x42AF30 | public: void __thiscall mmPlayer::ToggleExternalView(void) | ?ToggleExternalView@mmPlayer@@QAEXXZ
    0x42B0E0 | public: void __thiscall mmPlayer::ToggleDash(void) | ?ToggleDash@mmPlayer@@QAEXXZ
    0x42B310 | public: void __thiscall mmPlayer::UpdateHOG(void) | ?UpdateHOG@mmPlayer@@QAEXXZ
    0x42B440 | public: virtual void __thiscall mmPlayer::Reset(void) | ?Reset@mmPlayer@@UAEXXZ
    0x42B5F0 | public: void __thiscall mmPlayer::SetSteering(float) | ?SetSteering@mmPlayer@@QAEXM@Z
    0x42BBC0 | public: virtual void __thiscall mmPlayer::Update(void) | ?Update@mmPlayer@@UAEXXZ
    0x42C420 | public: void __thiscall mmPlayer::SetCamInterest(class asInertialCS *) | ?SetCamInterest@mmPlayer@@QAEXPAVasInertialCS@@@Z
    0x42C490 | public: int __thiscall mmPlayer::IsMaxDamaged(void) | ?IsMaxDamaged@mmPlayer@@QAEHXZ
    0x42C4C0 | public: void __thiscall mmPlayer::EnableRegen(int) | ?EnableRegen@mmPlayer@@QAEXH@Z
    0x42C4E0 | public: void __thiscall mmPlayer::ResetDamage(void) | ?ResetDamage@mmPlayer@@QAEXXZ
    0x42C4F0 | public: void __thiscall mmPlayer::UpdateRegen(void) | ?UpdateRegen@mmPlayer@@QAEXXZ
    0x42C590 | public: virtual void __thiscall mmPlayer::AddWidgets(class Bank *) | ?AddWidgets@mmPlayer@@UAEXPAVBank@@@Z
    0x42CD40 | public: static void __cdecl mmPlayer::DeclareFields(void) | ?DeclareFields@mmPlayer@@SAXXZ
    0x42D1B0 | public: virtual class MetaClass * __thiscall mmPlayer::GetClass(void) | ?GetClass@mmPlayer@@UAEPAVMetaClass@@XZ
    0x42D1F0 | public: virtual __thiscall mmCar::~mmCar(void) | ??1mmCar@@UAE@XZ
    0x42D2B0 | public: virtual __thiscall PolarCamCS::~PolarCamCS(void) | ??1PolarCamCS@@UAE@XZ
    0x42D2C0 | public: virtual __thiscall AICamCS::~AICamCS(void) | ??1AICamCS@@UAE@XZ
    0x42D2D0 | public: virtual __thiscall PointCamCS::~PointCamCS(void) | ??1PointCamCS@@UAE@XZ
    0x42D2E0 | public: virtual __thiscall PreCamCS::~PreCamCS(void) | ??1PreCamCS@@UAE@XZ
    0x42D2F0 | public: virtual __thiscall PostCamCS::~PostCamCS(void) | ??1PostCamCS@@UAE@XZ
    0x42D300 | public: virtual __thiscall asOverSample::~asOverSample(void) | ??1asOverSample@@UAE@XZ
    0x42D310 | public: virtual void * __thiscall mmPlayer::`vector deleting destructor'(unsigned int) | ??_EmmPlayer@@UAEPAXI@Z
    0x42D370 | public: virtual __thiscall mmPlayer::~mmPlayer(void) | ??1mmPlayer@@UAE@XZ
    0x42D510 | public: virtual __thiscall mmPhysEntity::~mmPhysEntity(void) | ??1mmPhysEntity@@UAE@XZ
    0x61AF00 | const mmPlayer::`vftable' | ??_7mmPlayer@@6B@
    0x6A7750 | class MetaClass mmPlayerMetaClass | ?mmPlayerMetaClass@@3VMetaClass@@A
    0x6A7778 | int RestoreCityCam | ?RestoreCityCam@@3HA
*/

#include "arts7/node.h"

#include "hud.h"
#include "mmcar/car.h"

class mmPlayer final : public asNode
{
    // const mmPlayer::`vftable'

public:
    // ??0mmPlayer@@QAE@XZ
    ARTS_IMPORT mmPlayer();

    // ??_EmmPlayer@@UAEPAXI@Z
    // ??1mmPlayer@@UAE@XZ | inline
    ARTS_IMPORT ~mmPlayer() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmPlayer@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // ?AfterLoad@mmPlayer@@UAEXXZ
    ARTS_EXPORT void AfterLoad() override;

    // ?BeforeSave@mmPlayer@@UAEXXZ
    ARTS_EXPORT void BeforeSave() override;

    // ?EnableRegen@mmPlayer@@QAEXH@Z
    ARTS_IMPORT void EnableRegen(i32 arg1);

    // ?GetClass@mmPlayer@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?Init@mmPlayer@@QAEXPAD0PAVmmGame@@@Z
    ARTS_IMPORT void Init(char* arg1, char* arg2, class mmGame* arg3);

    // ?IsMaxDamaged@mmPlayer@@QAEHXZ
    ARTS_IMPORT i32 IsMaxDamaged();

    // ?IsPOV@mmPlayer@@QAEHXZ
    ARTS_IMPORT i32 IsPOV();

    // ?ReInit@mmPlayer@@QAEXPAD@Z
    ARTS_IMPORT void ReInit(char* arg1);

    // ?Reset@mmPlayer@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?ResetDamage@mmPlayer@@QAEXXZ
    ARTS_IMPORT void ResetDamage();

    // ?SetCamInterest@mmPlayer@@QAEXPAVasInertialCS@@@Z
    ARTS_IMPORT void SetCamInterest(class asInertialCS* arg1);

    // ?SetMirrorFOV@mmPlayer@@QAEXXZ | unused
    ARTS_IMPORT void SetMirrorFOV();

    // ?SetPostRaceCam@mmPlayer@@QAEXXZ
    ARTS_IMPORT void SetPostRaceCam();

    // ?SetPreRaceCam@mmPlayer@@QAEXXZ
    ARTS_IMPORT void SetPreRaceCam();

    // ?SetSteering@mmPlayer@@QAEXM@Z
    ARTS_IMPORT void SetSteering(f32 arg1);

    // ?SetWideFOV@mmPlayer@@QAEXH@Z
    ARTS_IMPORT void SetWideFOV(i32 arg1);

    // ?ToggleCam@mmPlayer@@QAEXXZ
    ARTS_IMPORT void ToggleCam();

    // ?ToggleDash@mmPlayer@@QAEXXZ
    ARTS_IMPORT void ToggleDash();

    // ?ToggleExternalView@mmPlayer@@QAEXXZ
    ARTS_IMPORT void ToggleExternalView();

    // ?ToggleWideFOV@mmPlayer@@QAEXXZ
    ARTS_IMPORT void ToggleWideFOV();

    // ?Update@mmPlayer@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateHOG@mmPlayer@@QAEXXZ
    ARTS_IMPORT void UpdateHOG();

    // ?UpdateRegen@mmPlayer@@QAEXXZ
    ARTS_IMPORT void UpdateRegen();

    // ?DeclareFields@mmPlayer@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    offset_field(0x38, mmCar, Car);
    offset_field(0x2344, mmCarSim*, CarSim);
    offset_field(0x2348, mmHUD, Hud);

    u8 gap20[0x4A78];
};

check_size(mmPlayer, 0x4A98);

// ?RestoreCityCam@@3HA
ARTS_IMPORT extern i32 RestoreCityCam;

// ?mmPlayerMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmPlayerMetaClass;
