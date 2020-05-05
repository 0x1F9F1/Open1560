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

class mmPlayer : public asNode
{
    // const mmPlayer::`vftable' @ 0x61AF00

public:
    // 0x429FF0 | ??0mmPlayer@@QAE@XZ
    mmPlayer();

    // 0x42D310 | ??_EmmPlayer@@UAEPAXI@Z
    // 0x42D370 | ??1mmPlayer@@UAE@XZ
    ~mmPlayer() override;

    // 0x42C590 | ?AddWidgets@mmPlayer@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x42A380 | ?AfterLoad@mmPlayer@@UAEXXZ
    void AfterLoad() override;

    // 0x42A370 | ?BeforeSave@mmPlayer@@UAEXXZ
    void BeforeSave() override;

    // 0x42C4C0 | ?EnableRegen@mmPlayer@@QAEXH@Z
    void EnableRegen(i32 arg1);

    // 0x42D1B0 | ?GetClass@mmPlayer@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x42A520 | ?Init@mmPlayer@@QAEXPAD0PAVmmGame@@@Z
    void Init(char* arg1, char* arg2, class mmGame* arg3);

    // 0x42C490 | ?IsMaxDamaged@mmPlayer@@QAEHXZ
    i32 IsMaxDamaged();

    // 0x42AC10 | ?IsPOV@mmPlayer@@QAEHXZ
    i32 IsPOV();

    // 0x42A390 | ?ReInit@mmPlayer@@QAEXPAD@Z
    void ReInit(char* arg1);

    // 0x42B440 | ?Reset@mmPlayer@@UAEXXZ
    void Reset() override;

    // 0x42C4E0 | ?ResetDamage@mmPlayer@@QAEXXZ
    void ResetDamage();

    // 0x42C420 | ?SetCamInterest@mmPlayer@@QAEXPAVasInertialCS@@@Z
    void SetCamInterest(class asInertialCS* arg1);

    // 0x42A9A0 | ?SetMirrorFOV@mmPlayer@@QAEXXZ
    void SetMirrorFOV();

    // 0x42AAF0 | ?SetPostRaceCam@mmPlayer@@QAEXXZ
    void SetPostRaceCam();

    // 0x42A9D0 | ?SetPreRaceCam@mmPlayer@@QAEXXZ
    void SetPreRaceCam();

    // 0x42B5F0 | ?SetSteering@mmPlayer@@QAEXM@Z
    void SetSteering(f32 arg1);

    // 0x42AC60 | ?SetWideFOV@mmPlayer@@QAEXH@Z
    void SetWideFOV(i32 arg1);

    // 0x42AE10 | ?ToggleCam@mmPlayer@@QAEXXZ
    void ToggleCam();

    // 0x42B0E0 | ?ToggleDash@mmPlayer@@QAEXXZ
    void ToggleDash();

    // 0x42AF30 | ?ToggleExternalView@mmPlayer@@QAEXXZ
    void ToggleExternalView();

    // 0x42ADF0 | ?ToggleWideFOV@mmPlayer@@QAEXXZ
    void ToggleWideFOV();

    // 0x42BBC0 | ?Update@mmPlayer@@UAEXXZ
    void Update() override;

    // 0x42B310 | ?UpdateHOG@mmPlayer@@QAEXXZ
    void UpdateHOG();

    // 0x42C4F0 | ?UpdateRegen@mmPlayer@@QAEXXZ
    void UpdateRegen();

    // 0x42CD40 | ?DeclareFields@mmPlayer@@SAXXZ
    static void DeclareFields();
};

check_size(mmPlayer, 0x4A98);

// 0x6A7778 | ?RestoreCityCam@@3HA
inline extern_var(0x2A7778_Offset, i32, RestoreCityCam);

// 0x6A7750 | ?mmPlayerMetaClass@@3VMetaClass@@A
inline extern_var(0x2A7750_Offset, class MetaClass, mmPlayerMetaClass);
