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
    mmwidget:comprrec

    0x4B48F0 | public: __thiscall mmCompRaceRecord::mmCompRaceRecord(void) | ??0mmCompRaceRecord@@QAE@XZ
    0x4B4930 | public: virtual __thiscall mmCompRaceRecord::~mmCompRaceRecord(void) | ??1mmCompRaceRecord@@UAE@XZ
    0x4B49D0 | public: void __thiscall mmCompRaceRecord::Init(int,char *,char *,char *,char *,char *,int,int) | ?Init@mmCompRaceRecord@@QAEXHPAD0000HH@Z
    0x4B4A60 | public: void __thiscall mmCompRaceRecord::InitTitle(float,float,float,float,struct LocString *,struct LocString *,struct LocString *,struct LocString *,struct LocString *,struct LocString *,int) | ?InitTitle@mmCompRaceRecord@@QAEXMMMMPAULocString@@00000H@Z
    0x4B4AD0 | public: void __thiscall mmCompRaceRecord::LoadBitmap(char *) | ?LoadBitmap@mmCompRaceRecord@@QAEXPAD@Z
    0x4B4B20 | public: virtual void __thiscall mmCompRaceRecord::Reset(void) | ?Reset@mmCompRaceRecord@@UAEXXZ
    0x4B4B30 | public: virtual void __thiscall mmCompRaceRecord::Update(void) | ?Update@mmCompRaceRecord@@UAEXXZ
    0x4B4B40 | public: void __thiscall mmCompRaceRecord::SetSubwidgetGeometry(void) | ?SetSubwidgetGeometry@mmCompRaceRecord@@QAEXXZ
    0x4B4C70 | public: virtual void __thiscall mmCompRaceRecord::SetGeometry(float,float,float,float) | ?SetGeometry@mmCompRaceRecord@@UAEXMMMM@Z
    0x4B4CA0 | public: void __thiscall mmCompRaceRecord::SelectIfRaceType(int,int) | ?SelectIfRaceType@mmCompRaceRecord@@QAEXHH@Z
    0x4B4CE0 | public: virtual void __thiscall mmCompRaceRecord::SetPosition(class mmTextNode *,int,float) | ?SetPosition@mmCompRaceRecord@@UAEXPAVmmTextNode@@HM@Z
    0x4B4D80 | public: virtual void __thiscall mmCompRaceRecord::Cull(void) | ?Cull@mmCompRaceRecord@@UAEXXZ
    0x4B4DC0 | public: virtual void * __thiscall mmCompRaceRecord::`scalar deleting destructor'(unsigned int) | ??_GmmCompRaceRecord@@UAEPAXI@Z
    0x4B4DC0 | public: virtual void * __thiscall mmCompRaceRecord::`vector deleting destructor'(unsigned int) | ??_EmmCompRaceRecord@@UAEPAXI@Z
    0x4B4DF0 | public: virtual __thiscall mmCompBase::~mmCompBase(void) | ??1mmCompBase@@UAE@XZ
    0x4B4E00 | public: virtual void __thiscall mmCompBase::DisableBlt(void) | ?DisableBlt@mmCompBase@@UAEXXZ
    0x4B4E10 | public: virtual void __thiscall mmCompBase::SetBltXY(float,float) | ?SetBltXY@mmCompBase@@UAEXMM@Z
    0x4B4E40 | public: virtual void __thiscall mmCompBase::Action(union eqEvent) | ?Action@mmCompBase@@UAEXTeqEvent@@@Z
    0x4B4E50 | public: virtual void __thiscall mmCompBase::CaptureAction(union eqEvent) | ?CaptureAction@mmCompBase@@UAEXTeqEvent@@@Z
    0x4B4E60 | public: virtual void __thiscall mmCompBase::Switch(int) | ?Switch@mmCompBase@@UAEXH@Z
    0x4B4E70 | public: virtual void __thiscall mmCompBase::Action(union eqEvent,float,float,int) | ?Action@mmCompBase@@UAEXTeqEvent@@MMH@Z
    0x4B4E80 | public: virtual void __thiscall mmCompBase::EvalMouseXY(float,float) | ?EvalMouseXY@mmCompBase@@UAEXMM@Z
    0x4B4E90 | public: virtual void __thiscall mmCompBase::Highlight(class mmTextNode *,int) | ?Highlight@mmCompBase@@UAEXPAVmmTextNode@@H@Z
    0x4B4EA0 | public: virtual void __thiscall mmCompBase::SetGeometry(float,float,float,float) | ?SetGeometry@mmCompBase@@UAEXMMMM@Z
    0x4B4EC0 | public: virtual void * __thiscall mmCompBase::`vector deleting destructor'(unsigned int) | ??_EmmCompBase@@UAEPAXI@Z
    0x4B4EC0 | public: virtual void * __thiscall mmCompBase::`scalar deleting destructor'(unsigned int) | ??_GmmCompBase@@UAEPAXI@Z
    0x61E680 | const mmCompRaceRecord::`vftable' | ??_7mmCompRaceRecord@@6B@
    0x61E6E8 | const mmCompBase::`vftable' | ??_7mmCompBase@@6B@
*/

#include "compbase.h"

class mmCompRaceRecord final : public mmCompBase
{
    // const mmCompRaceRecord::`vftable' @ 0x61E680

public:
    // 0x4B48F0 | ??0mmCompRaceRecord@@QAE@XZ
    ARTS_IMPORT mmCompRaceRecord();

    // 0x4B4DC0 | ??_EmmCompRaceRecord@@UAEPAXI@Z
    // 0x4B4DC0 | ??_GmmCompRaceRecord@@UAEPAXI@Z
    // 0x4B4930 | ??1mmCompRaceRecord@@UAE@XZ
    ARTS_IMPORT ~mmCompRaceRecord() override;

    // 0x4B4D80 | ?Cull@mmCompRaceRecord@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x4B49D0 | ?Init@mmCompRaceRecord@@QAEXHPAD0000HH@Z
    ARTS_IMPORT void Init(i32 arg1, char* arg2, char* arg3, char* arg4, char* arg5, char* arg6, i32 arg7, i32 arg8);

    // 0x4B4A60 | ?InitTitle@mmCompRaceRecord@@QAEXMMMMPAULocString@@00000H@Z
    ARTS_IMPORT void InitTitle(f32 arg1, f32 arg2, f32 arg3, f32 arg4, struct LocString* arg5, struct LocString* arg6,
        struct LocString* arg7, struct LocString* arg8, struct LocString* arg9, struct LocString* arg10, i32 arg11);

    // 0x4B4AD0 | ?LoadBitmap@mmCompRaceRecord@@QAEXPAD@Z
    ARTS_IMPORT void LoadBitmap(char* arg1);

    // 0x4B4B20 | ?Reset@mmCompRaceRecord@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // 0x4B4CA0 | ?SelectIfRaceType@mmCompRaceRecord@@QAEXHH@Z
    ARTS_IMPORT void SelectIfRaceType(i32 arg1, i32 arg2);

    // 0x4B4C70 | ?SetGeometry@mmCompRaceRecord@@UAEXMMMM@Z
    ARTS_IMPORT void SetGeometry(f32 arg1, f32 arg2, f32 arg3, f32 arg4) override;

    // 0x4B4CE0 | ?SetPosition@mmCompRaceRecord@@UAEXPAVmmTextNode@@HM@Z
    ARTS_IMPORT void SetPosition(class mmTextNode* arg1, i32 arg2, f32 arg3) override;

    // 0x4B4B40 | ?SetSubwidgetGeometry@mmCompRaceRecord@@QAEXXZ
    ARTS_IMPORT void SetSubwidgetGeometry();

    // 0x4B4B30 | ?Update@mmCompRaceRecord@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap48[0x60];
};

check_size(mmCompRaceRecord, 0xA8);
