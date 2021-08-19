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
    mmcar:roadff

    0x4814D0 | public: __thiscall mmCarRoadFF::mmCarRoadFF(void) | ??0mmCarRoadFF@@QAE@XZ
    0x481510 | public: virtual __thiscall mmCarRoadFF::~mmCarRoadFF(void) | ??1mmCarRoadFF@@UAE@XZ
    0x481570 | public: void __thiscall mmCarRoadFF::AssignProperties(float,int) | ?AssignProperties@mmCarRoadFF@@QAEXMH@Z
    0x481610 | public: void __thiscall mmCarRoadFF::SetFGVals(float,float,float) | ?SetFGVals@mmCarRoadFF@@QAEXMMM@Z
    0x481700 | public: void __thiscall mmCarRoadFF::Start(void) | ?Start@mmCarRoadFF@@QAEXXZ
    0x481720 | public: void __thiscall mmCarRoadFF::Stop(void) | ?Stop@mmCarRoadFF@@QAEXXZ
    0x481730 | public: virtual void __thiscall mmCarRoadFF::Reset(void) | ?Reset@mmCarRoadFF@@UAEXXZ
    0x481760 | public: int __thiscall mmCarRoadFF::IsPlaying(void) | ?IsPlaying@mmCarRoadFF@@QAEHXZ
    0x481770 | public: virtual void __thiscall mmCarRoadFF::Update(void) | ?Update@mmCarRoadFF@@UAEXXZ
    0x4817C0 | public: void __thiscall mmCarRoadFF::UpdateVals(void) | ?UpdateVals@mmCarRoadFF@@QAEXXZ
    0x481810 | public: virtual void __thiscall mmCarRoadFF::AddWidgets(class Bank *) | ?AddWidgets@mmCarRoadFF@@UAEXPAVBank@@@Z
    0x481920 | public: static void __cdecl mmCarRoadFF::DeclareFields(void) | ?DeclareFields@mmCarRoadFF@@SAXXZ
    0x481A90 | public: virtual class MetaClass * __thiscall mmCarRoadFF::GetClass(void) | ?GetClass@mmCarRoadFF@@UAEPAVMetaClass@@XZ
    0x481AA0 | public: virtual void * __thiscall mmCarRoadFF::`vector deleting destructor'(unsigned int) | ??_EmmCarRoadFF@@UAEPAXI@Z
    0x61C920 | const mmCarRoadFF::`vftable' | ??_7mmCarRoadFF@@6B@
    0x6A8170 | class MetaClass mmCarRoadFFMetaClass | ?mmCarRoadFFMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class mmCarRoadFF final : public asNode
{
public:
    // ??0mmCarRoadFF@@QAE@XZ
    ARTS_IMPORT mmCarRoadFF();

    // ??_EmmCarRoadFF@@UAEPAXI@Z
    // ??1mmCarRoadFF@@UAE@XZ
    ARTS_IMPORT ~mmCarRoadFF() override;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@mmCarRoadFF@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(class Bank* arg1) override;
#endif

    // ?AssignProperties@mmCarRoadFF@@QAEXMH@Z
    ARTS_IMPORT void AssignProperties(f32 arg1, i32 arg2);

    // ?GetClass@mmCarRoadFF@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT class MetaClass* GetClass() override;

    // ?IsPlaying@mmCarRoadFF@@QAEHXZ
    ARTS_IMPORT i32 IsPlaying();

    // ?Reset@mmCarRoadFF@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetFGVals@mmCarRoadFF@@QAEXMMM@Z
    ARTS_IMPORT void SetFGVals(f32 arg1, f32 arg2, f32 arg3);

    // ?Start@mmCarRoadFF@@QAEXXZ
    ARTS_IMPORT void Start();

    // ?Stop@mmCarRoadFF@@QAEXXZ
    ARTS_IMPORT void Stop();

    // ?Update@mmCarRoadFF@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?UpdateVals@mmCarRoadFF@@QAEXXZ
    ARTS_IMPORT void UpdateVals();

    // ?DeclareFields@mmCarRoadFF@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x24];
};

check_size(mmCarRoadFF, 0x44);
