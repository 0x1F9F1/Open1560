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
    mmgame:wpinst

    0x433730 | public: __thiscall mmWaypointInstance::mmWaypointInstance(int,float,float) | ??0mmWaypointInstance@@QAE@HMM@Z
    0x433780 | public: virtual __thiscall mmWaypointInstance::~mmWaypointInstance(void) | ??1mmWaypointInstance@@UAE@XZ
    0x433790 | public: virtual float __fastcall mmWaypointInstance::GetScale(void) | ?GetScale@mmWaypointInstance@@UAIMXZ
    0x4337A0 | public: virtual int __thiscall mmWaypointInstance::ComputeLod(float,float) | ?ComputeLod@mmWaypointInstance@@UAEHMM@Z
    0x4337C0 | public: virtual void __fastcall mmWaypointInstance::Draw(int) | ?Draw@mmWaypointInstance@@UAIXH@Z
    0x433B90 | public: virtual void __thiscall mmWaypointInstance::AddWidgets(class Bank *) | ?AddWidgets@mmWaypointInstance@@UAEXPAVBank@@@Z
    0x433BA0 | public: static void __cdecl mmWaypointInstance::DeclareFields(void) | ?DeclareFields@mmWaypointInstance@@SAXXZ
    0x433D20 | public: virtual class MetaClass * __thiscall mmWaypointInstance::GetClass(void) | ?GetClass@mmWaypointInstance@@UAEPAVMetaClass@@XZ
    0x433D30 | public: virtual void * __thiscall mmWaypointInstance::`vector deleting destructor'(unsigned int) | ??_EmmWaypointInstance@@UAEPAXI@Z
    0x433D90 | public: void __thiscall mmWaypointInstance::`default constructor closure'(void) | ??_FmmWaypointInstance@@QAEXXZ
    0x433DB0 | public: virtual class mmPhysEntity * __thiscall mmInstance::GetEntity(void) | ?GetEntity@mmInstance@@UAEPAVmmPhysEntity@@XZ
    0x433DC0 | public: virtual class mmPhysEntity * __thiscall mmInstance::AttachEntity(void) | ?AttachEntity@mmInstance@@UAEPAVmmPhysEntity@@XZ
    0x433DD0 | public: virtual class Vector3 __thiscall mmInstance::GetVelocity(void) | ?GetVelocity@mmInstance@@UAE?AVVector3@@XZ
    0x433DF0 | public: virtual void __thiscall mmInstance::Impact(class mmInstance *,class Vector3 *) | ?Impact@mmInstance@@UAEXPAV1@PAVVector3@@@Z
    0x433E00 | public: virtual void __thiscall mmInstance::Detach(void) | ?Detach@mmInstance@@UAEXXZ
    0x61B168 | const mmWaypointInstance::`vftable' | ??_7mmWaypointInstance@@6B@
    0x6A7800 | class MetaClass mmWaypointInstanceMetaClass | ?mmWaypointInstanceMetaClass@@3VMetaClass@@A
*/

#include "mmcity/inst.h"

class mmWaypointInstance : public mmStaticInstance
{
    // const mmWaypointInstance::`vftable' @ 0x61B168

public:
    // 0x433730 | ??0mmWaypointInstance@@QAE@HMM@Z
    ARTS_IMPORT mmWaypointInstance(i32 arg1, f32 arg2, f32 arg3);

    // 0x433D30 | ??_EmmWaypointInstance@@UAEPAXI@Z
    // 0x433780 | ??1mmWaypointInstance@@UAE@XZ
    ARTS_IMPORT ~mmWaypointInstance() override = default;

    // 0x433B90 | ?AddWidgets@mmWaypointInstance@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;

    // 0x4337A0 | ?ComputeLod@mmWaypointInstance@@UAEHMM@Z
    ARTS_IMPORT i32 ComputeLod(f32 arg1, f32 arg2) override;

    // 0x4337C0 | ?Draw@mmWaypointInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // 0x433D20 | ?GetClass@mmWaypointInstance@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // 0x433790 | ?GetScale@mmWaypointInstance@@UAIMXZ
    ARTS_IMPORT f32 ARTS_FASTCALL GetScale() override;

    // 0x433D90 | ??_FmmWaypointInstance@@QAEXXZ | invalid name

    // 0x433BA0 | ?DeclareFields@mmWaypointInstance@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap38[0xC];
};

check_size(mmWaypointInstance, 0x44);

// 0x6A7800 | ?mmWaypointInstanceMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass mmWaypointInstanceMetaClass;
