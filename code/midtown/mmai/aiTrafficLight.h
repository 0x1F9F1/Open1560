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
    mmai:aiTrafficLight

    0x443F60 | public: __thiscall aiTrafficLightSet::aiTrafficLightSet(class aiIntersection *) | ??0aiTrafficLightSet@@QAE@PAVaiIntersection@@@Z
    0x444150 | public: virtual __thiscall aiTrafficLightSet::~aiTrafficLightSet(void) | ??1aiTrafficLightSet@@UAE@XZ
    0x4441B0 | public: virtual void __thiscall aiTrafficLightSet::Reset(void) | ?Reset@aiTrafficLightSet@@UAEXXZ
    0x444250 | public: virtual void __thiscall aiTrafficLightSet::Update(void) | ?Update@aiTrafficLightSet@@UAEXXZ
    0x444330 | public: virtual int __thiscall aiTrafficLightInstance::Init(char *,class Vector3 &,class Vector3 &,int,char *) | ?Init@aiTrafficLightInstance@@UAEHPADAAVVector3@@1H0@Z
    0x444530 | public: virtual void __fastcall aiTrafficLightInstance::Draw(int) | ?Draw@aiTrafficLightInstance@@UAIXH@Z
    0x4446C0 | public: virtual void * __thiscall aiTrafficLightSet::`vector deleting destructor'(unsigned int) | ??_EaiTrafficLightSet@@UAEPAXI@Z
    0x4446C0 | public: virtual void * __thiscall aiTrafficLightSet::`scalar deleting destructor'(unsigned int) | ??_GaiTrafficLightSet@@UAEPAXI@Z
    0x4446F0 | public: __thiscall mmBangerInstance::mmBangerInstance(void) | ??0mmBangerInstance@@QAE@XZ
    0x444710 | public: virtual void __thiscall mmBangerInstance::AddWidgets(class Bank *) | ?AddWidgets@mmBangerInstance@@UAEXPAVBank@@@Z
    0x444720 | public: virtual void * __thiscall mmBangerInstance::`scalar deleting destructor'(unsigned int) | ??_GmmBangerInstance@@UAEPAXI@Z
    0x444720 | public: virtual void * __thiscall mmBangerInstance::`vector deleting destructor'(unsigned int) | ??_EmmBangerInstance@@UAEPAXI@Z
    0x444740 | public: virtual __thiscall mmBangerInstance::~mmBangerInstance(void) | ??1mmBangerInstance@@UAE@XZ
    0x444750 | public: virtual unsigned int __thiscall mmUnhitBangerInstance::SizeOf(void) | ?SizeOf@mmUnhitBangerInstance@@UAEIXZ
    0x444760 | public: virtual void * __thiscall aiTrafficLightInstance::`scalar deleting destructor'(unsigned int) | ??_GaiTrafficLightInstance@@UAEPAXI@Z
    0x444760 | public: virtual void * __thiscall aiTrafficLightInstance::`vector deleting destructor'(unsigned int) | ??_EaiTrafficLightInstance@@UAEPAXI@Z
    0x444780 | public: virtual __thiscall aiTrafficLightInstance::~aiTrafficLightInstance(void) | ??1aiTrafficLightInstance@@UAE@XZ
    0x61B3D8 | const aiTrafficLightInstance::`vftable' | ??_7aiTrafficLightInstance@@6B@
    0x61B438 | const aiTrafficLightSet::`vftable' | ??_7aiTrafficLightSet@@6B@
    0x61B480 | const mmBangerInstance::`vftable' | ??_7mmBangerInstance@@6B@
    0x6A7970 | private: static short aiTrafficLightSet::ObjCount | ?ObjCount@aiTrafficLightSet@@0FA
*/

#include "arts7/node.h"
#include "mmbangers/banger.h"

class aiTrafficLightSet : public asNode
{
    // const aiTrafficLightSet::`vftable' @ 0x61B438

public:
    // 0x443F60 | ??0aiTrafficLightSet@@QAE@PAVaiIntersection@@@Z
    ARTS_IMPORT aiTrafficLightSet(class aiIntersection* arg1);

    // 0x4446C0 | ??_GaiTrafficLightSet@@UAEPAXI@Z
    // 0x444150 | ??1aiTrafficLightSet@@UAE@XZ
    ARTS_IMPORT ~aiTrafficLightSet() override;

    // 0x4441B0 | ?Reset@aiTrafficLightSet@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x444250 | ?Update@aiTrafficLightSet@@UAEXXZ
    ARTS_IMPORT void Update() override;

private:
    // 0x6A7970 | ?ObjCount@aiTrafficLightSet@@0FA
    ARTS_IMPORT static i16 ObjCount;
};

check_size(aiTrafficLightSet, 0x38);

class aiTrafficLightInstance : public mmUnhitBangerInstance
{
    // const aiTrafficLightInstance::`vftable' @ 0x61B3D8

public:
    // 0x444760 | ??_EaiTrafficLightInstance@@UAEPAXI@Z
    // 0x444780 | ??1aiTrafficLightInstance@@UAE@XZ | inline
    ARTS_IMPORT ~aiTrafficLightInstance() override;

    // 0x444530 | ?Draw@aiTrafficLightInstance@@UAIXH@Z
    ARTS_IMPORT void ARTS_FASTCALL Draw(i32 arg1) override;

    // 0x444330 | ?Init@aiTrafficLightInstance@@UAEHPADAAVVector3@@1H0@Z
    ARTS_IMPORT i32 Init(char* arg1, class Vector3& arg2, class Vector3& arg3, i32 arg4, char* arg5) override;
};

check_size(aiTrafficLightInstance, 0x0);
