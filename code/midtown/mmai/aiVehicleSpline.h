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
    mmai:aiVehicleSpline

    0x459EE0 | public: __thiscall aiVehicleSpline::aiVehicleSpline(void) | ??0aiVehicleSpline@@QAE@XZ
    0x459F50 | public: __thiscall aiVehicleSpline::~aiVehicleSpline(void) | ??1aiVehicleSpline@@QAE@XZ
    0x459FC0 | public: void __thiscall aiVehicleSpline::Init(char *,int) | ?Init@aiVehicleSpline@@QAEXPADH@Z
    0x45A2B0 | public: virtual void __thiscall aiVehicleSpline::Reset(void) | ?Reset@aiVehicleSpline@@UAEXXZ
    0x45A2F0 | public: virtual void __thiscall aiVehicleSpline::Update(void) | ?Update@aiVehicleSpline@@UAEXXZ
    0x45A340 | public: void __thiscall aiVehicleSpline::ResetReactTicks(void) | ?ResetReactTicks@aiVehicleSpline@@QAEXXZ
    0x45A3A0 | public: void __thiscall aiVehicleSpline::SolvePositionAndOrientation(void) | ?SolvePositionAndOrientation@aiVehicleSpline@@QAEXXZ
    0x45AAB0 | public: void __thiscall aiVehicleSpline::SolveYPositionAndOrientation(void) | ?SolveYPositionAndOrientation@aiVehicleSpline@@QAEXXZ
    0x45B040 | public: int __thiscall aiVehicleSpline::DetectPlayerForwardCollision(void) | ?DetectPlayerForwardCollision@aiVehicleSpline@@QAEHXZ
    0x45B130 | public: int __thiscall aiVehicleSpline::DetectPlayerTargetPtCollision(void) | ?DetectPlayerTargetPtCollision@aiVehicleSpline@@QAEHXZ
    0x45B270 | public: int __thiscall aiVehicleSpline::DetectPlayerCollision(int,float) | ?DetectPlayerCollision@aiVehicleSpline@@QAEHHM@Z
    0x45B870 | public: int __thiscall aiVehicleSpline::DetectPlayerZoneCollision(void) | ?DetectPlayerZoneCollision@aiVehicleSpline@@QAEHXZ
    0x45BA60 | public: int __thiscall aiVehicleSpline::IsThePlayerInFrontOfMe(void) | ?IsThePlayerInFrontOfMe@aiVehicleSpline@@QAEHXZ
    0x45BB60 | public: int __thiscall aiVehicleSpline::IsAmbientBlockingPlayer(void) | ?IsAmbientBlockingPlayer@aiVehicleSpline@@QAEHXZ
    0x45BC50 | public: void __thiscall aiVehicleSpline::AvoidPlayerCollision(void) | ?AvoidPlayerCollision@aiVehicleSpline@@QAEXXZ
    0x45BCD0 | public: int __thiscall aiVehicleSpline::WaitTime(void) | ?WaitTime@aiVehicleSpline@@QAEHXZ
    0x45BCF0 | public: float __thiscall aiVehicleSpline::TotLength(void) | ?TotLength@aiVehicleSpline@@QAEMXZ
    0x45BD00 | public: virtual void __thiscall aiVehicleSpline::Impact(int) | ?Impact@aiVehicleSpline@@UAEXH@Z
    0x45BD10 | public: float __thiscall aiVehicleSpline::DistanceToVehicle(class aiVehicleSpline *) | ?DistanceToVehicle@aiVehicleSpline@@QAEMPAV1@@Z
    0x45BFF0 | public: float __thiscall aiVehicleSpline::DistanceToIntersection(void) | ?DistanceToIntersection@aiVehicleSpline@@QAEMXZ
    0x45C090 | public: void __thiscall aiVehicleSpline::Dump(void) | ?Dump@aiVehicleSpline@@QAEXXZ
    0x45C1F0 | public: void __thiscall aiVehicleSpline::AddWidgets(class Bank *) | ?AddWidgets@aiVehicleSpline@@QAEXPAVBank@@@Z
    0x45C200 | public: virtual void __thiscall aiVehicleSpline::DrawId(void) | ?DrawId@aiVehicleSpline@@UAEXXZ
    0x45C250 | public: static void __cdecl aiVehicleSpline::DeclareFields(void) | ?DeclareFields@aiVehicleSpline@@SAXXZ
    0x45C3E0 | public: virtual class MetaClass * __thiscall aiVehicleSpline::GetClass(void) | ?GetClass@aiVehicleSpline@@UAEPAVMetaClass@@XZ
    0x45C420 | public: class Vector3 __thiscall Vector3::operator%(class Vector3 const &) const | ??LVector3@@QBE?AV0@ABV0@@Z
    0x45C470 | public: void __thiscall Vector3::Scale(class Vector3 const &,float) | ?Scale@Vector3@@QAEXABV1@M@Z
    0x45C4A0 | public: void * __thiscall aiVehicleSpline::`vector deleting destructor'(unsigned int) | ??_EaiVehicleSpline@@QAEPAXI@Z
    0x45C500 | public: virtual int __thiscall aiVehicleSpline::Type(void) | ?Type@aiVehicleSpline@@UAEHXZ
    0x45C510 | public: virtual void __thiscall aiVehicleInstance::AddWidgets(class Bank *) | ?AddWidgets@aiVehicleInstance@@UAEXPAVBank@@@Z
    0x45C530 | public: virtual void * __thiscall aiVehicleInstance::`vector deleting destructor'(unsigned int) | ??_EaiVehicleInstance@@UAEPAXI@Z
    0x45C530 | public: virtual void * __thiscall aiVehicleInstance::`scalar deleting destructor'(unsigned int) | ??_GaiVehicleInstance@@UAEPAXI@Z
    0x45C550 | public: virtual __thiscall aiVehicleInstance::~aiVehicleInstance(void) | ??1aiVehicleInstance@@UAE@XZ
    0x61B9F0 | const aiVehicleSpline::`vftable' | ??_7aiVehicleSpline@@6B@
    0x61BA18 | const aiVehicleInstance::`vftable' | ??_7aiVehicleInstance@@6B@
    0x6A7BA0 | class MetaClass aiVehicleSplineMetaClass | ?aiVehicleSplineMetaClass@@3VMetaClass@@A
*/

#include "aiVehicle.h"

class aiVehicleSpline : public aiVehicle
{
    // const aiVehicleSpline::`vftable' @ 0x61B9F0

public:
    // 0x459EE0 | ??0aiVehicleSpline@@QAE@XZ
    ARTS_IMPORT aiVehicleSpline();

    // 0x45C4A0 | ??_EaiVehicleSpline@@QAEPAXI@Z | unused
    // 0x459F50 | ??1aiVehicleSpline@@QAE@XZ
    ARTS_IMPORT ~aiVehicleSpline();

    // 0x45BD00 | ?Impact@aiVehicleSpline@@UAEXH@Z
    ARTS_EXPORT virtual void Impact(i32 arg1);

    // 0x4465E0 | ?GetImpactAudioPtr@aiVehicleSpline@@UAEPAVmmOpponentImpactAudio@@XZ | inline
    ARTS_EXPORT virtual class mmOpponentImpactAudio* GetImpactAudioPtr();

    // 0x4465F0 | ?PlayHorn@aiVehicleSpline@@UAEXMM@Z | inline
    ARTS_EXPORT virtual void PlayHorn(f32 arg1, f32 arg2);

    // 0x446600 | ?ImpactAudioReaction@aiVehicleSpline@@UAEXM@Z | inline
    ARTS_EXPORT virtual void ImpactAudioReaction(f32 arg1);

    // 0x446610 | ?StopVoice@aiVehicleSpline@@UAEXXZ | inline
    ARTS_EXPORT virtual void StopVoice();

    // 0x45C3E0 | ?GetClass@aiVehicleSpline@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT virtual class MetaClass* GetClass();

#ifdef ARTS_DEV_BUILD
    // 0x45C1F0 | ?AddWidgets@aiVehicleSpline@@QAEXPAVBank@@@Z
    ARTS_EXPORT void AddWidgets(class Bank* arg1);
#endif

    // 0x45BC50 | ?AvoidPlayerCollision@aiVehicleSpline@@QAEXXZ | unused
    ARTS_IMPORT void AvoidPlayerCollision();

    // 0x45B270 | ?DetectPlayerCollision@aiVehicleSpline@@QAEHHM@Z | unused
    ARTS_IMPORT i32 DetectPlayerCollision(i32 arg1, f32 arg2);

    // 0x45B040 | ?DetectPlayerForwardCollision@aiVehicleSpline@@QAEHXZ | unused
    ARTS_IMPORT i32 DetectPlayerForwardCollision();

    // 0x45B130 | ?DetectPlayerTargetPtCollision@aiVehicleSpline@@QAEHXZ | unused
    ARTS_IMPORT i32 DetectPlayerTargetPtCollision();

    // 0x45B870 | ?DetectPlayerZoneCollision@aiVehicleSpline@@QAEHXZ
    ARTS_IMPORT i32 DetectPlayerZoneCollision();

    // 0x45BFF0 | ?DistanceToIntersection@aiVehicleSpline@@QAEMXZ
    ARTS_IMPORT f32 DistanceToIntersection();

    // 0x45BD10 | ?DistanceToVehicle@aiVehicleSpline@@QAEMPAV1@@Z
    ARTS_IMPORT f32 DistanceToVehicle(class aiVehicleSpline* arg1);

    // 0x45C200 | ?DrawId@aiVehicleSpline@@UAEXXZ
    ARTS_IMPORT void DrawId() override;

    // 0x45C090 | ?Dump@aiVehicleSpline@@QAEXXZ
    ARTS_IMPORT void Dump();

    // 0x459FC0 | ?Init@aiVehicleSpline@@QAEXPADH@Z
    ARTS_IMPORT void Init(char* arg1, i32 arg2);

    // 0x45BB60 | ?IsAmbientBlockingPlayer@aiVehicleSpline@@QAEHXZ
    ARTS_IMPORT i32 IsAmbientBlockingPlayer();

    // 0x45BA60 | ?IsThePlayerInFrontOfMe@aiVehicleSpline@@QAEHXZ
    ARTS_IMPORT i32 IsThePlayerInFrontOfMe();

    // 0x45A2B0 | ?Reset@aiVehicleSpline@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x45A340 | ?ResetReactTicks@aiVehicleSpline@@QAEXXZ
    ARTS_IMPORT void ResetReactTicks();

    // 0x45A3A0 | ?SolvePositionAndOrientation@aiVehicleSpline@@QAEXXZ
    ARTS_IMPORT void SolvePositionAndOrientation();

    // 0x45AAB0 | ?SolveYPositionAndOrientation@aiVehicleSpline@@QAEXXZ
    ARTS_IMPORT void SolveYPositionAndOrientation();

    // 0x45BCF0 | ?TotLength@aiVehicleSpline@@QAEMXZ
    ARTS_IMPORT f32 TotLength();

    // 0x45C500 | ?Type@aiVehicleSpline@@UAEHXZ | inline
    ARTS_IMPORT i32 Type() override;

    // 0x45A2F0 | ?Update@aiVehicleSpline@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // 0x45BCD0 | ?WaitTime@aiVehicleSpline@@QAEHXZ | unused
    ARTS_IMPORT i32 WaitTime();

    // 0x45C250 | ?DeclareFields@aiVehicleSpline@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap14[0xC4];
};

check_size(aiVehicleSpline, 0xD8);

// 0x6A7BA0 | ?aiVehicleSplineMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass aiVehicleSplineMetaClass;
