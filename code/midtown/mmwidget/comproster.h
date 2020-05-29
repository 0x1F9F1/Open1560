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
    mmwidget:comproster

    0x4B7840 | public: __thiscall mmCompRoster::mmCompRoster(void) | ??0mmCompRoster@@QAE@XZ
    0x4B78B0 | public: virtual __thiscall mmCompRoster::~mmCompRoster(void) | ??1mmCompRoster@@UAE@XZ
    0x4B7940 | public: void __thiscall mmCompRoster::Init(char *,char *,char *,unsigned long) | ?Init@mmCompRoster@@QAEXPAD00K@Z
    0x4B79C0 | public: void __thiscall mmCompRoster::InitTitle(float,float,float,float,struct LocString *,struct LocString *,struct LocString *,struct LocString *,int) | ?InitTitle@mmCompRoster@@QAEXMMMMPAULocString@@000H@Z
    0x4B79D0 | public: void __thiscall mmCompRoster::LoadBitmap(char *) | ?LoadBitmap@mmCompRoster@@QAEXPAD@Z
    0x4B7A20 | public: virtual void __thiscall mmCompRoster::Reset(void) | ?Reset@mmCompRoster@@UAEXXZ
    0x4B7A30 | public: virtual void __thiscall mmCompRoster::Update(void) | ?Update@mmCompRoster@@UAEXXZ
    0x4B7A60 | public: void __thiscall mmCompRoster::SetReady(int) | ?SetReady@mmCompRoster@@QAEXH@Z
    0x4B7A80 | public: void __thiscall mmCompRoster::SetSubwidgetGeometry(void) | ?SetSubwidgetGeometry@mmCompRoster@@QAEXXZ
    0x4B7B20 | public: virtual void __thiscall mmCompRoster::SetPosition(class mmTextNode *,int,float) | ?SetPosition@mmCompRoster@@UAEXPAVmmTextNode@@HM@Z
    0x4B7BA0 | public: virtual void __thiscall mmCompRoster::SetGeometry(float,float,float,float) | ?SetGeometry@mmCompRoster@@UAEXMMMM@Z
    0x4B7BD0 | public: virtual void __thiscall mmCompRoster::SetBltXY(float,float) | ?SetBltXY@mmCompRoster@@UAEXMM@Z
    0x4B7C10 | public: virtual void __thiscall mmCompRoster::Cull(void) | ?Cull@mmCompRoster@@UAEXXZ
    0x4B7C40 | public: virtual void * __thiscall mmCompRoster::`scalar deleting destructor'(unsigned int) | ??_GmmCompRoster@@UAEPAXI@Z
    0x4B7C40 | public: virtual void * __thiscall mmCompRoster::`vector deleting destructor'(unsigned int) | ??_EmmCompRoster@@UAEPAXI@Z
    0x61E978 | const mmCompRoster::`vftable' | ??_7mmCompRoster@@6B@
*/

#include "compbase.h"

class mmCompRoster : public mmCompBase
{
    // const mmCompRoster::`vftable' @ 0x61E978

public:
    // 0x4B7840 | ??0mmCompRoster@@QAE@XZ
    mmCompRoster();

    // 0x4B7C40 | ??_EmmCompRoster@@UAEPAXI@Z
    // 0x4B78B0 | ??1mmCompRoster@@UAE@XZ
    ~mmCompRoster() override;

    // 0x4B7C10 | ?Cull@mmCompRoster@@UAEXXZ
    void Cull() override;

    // 0x4B7940 | ?Init@mmCompRoster@@QAEXPAD00K@Z
    void Init(char* arg1, char* arg2, char* arg3, u32 arg4);

    // 0x4B79C0 | ?InitTitle@mmCompRoster@@QAEXMMMMPAULocString@@000H@Z | unused
    void InitTitle(f32 arg1, f32 arg2, f32 arg3, f32 arg4, struct LocString* arg5, struct LocString* arg6,
        struct LocString* arg7, struct LocString* arg8, i32 arg9);

    // 0x4B79D0 | ?LoadBitmap@mmCompRoster@@QAEXPAD@Z
    void LoadBitmap(char* arg1);

    // 0x4B7A20 | ?Reset@mmCompRoster@@UAEXXZ
    void Reset() override;

    // 0x4B7BD0 | ?SetBltXY@mmCompRoster@@UAEXMM@Z
    void SetBltXY(f32 arg1, f32 arg2) override;

    // 0x4B7BA0 | ?SetGeometry@mmCompRoster@@UAEXMMMM@Z
    void SetGeometry(f32 arg1, f32 arg2, f32 arg3, f32 arg4) override;

    // 0x4B7B20 | ?SetPosition@mmCompRoster@@UAEXPAVmmTextNode@@HM@Z
    void SetPosition(class mmTextNode* arg1, i32 arg2, f32 arg3) override;

    // 0x4B7A60 | ?SetReady@mmCompRoster@@QAEXH@Z
    void SetReady(i32 arg1);

    // 0x4B7A80 | ?SetSubwidgetGeometry@mmCompRoster@@QAEXXZ
    void SetSubwidgetGeometry();

    // 0x4B7A30 | ?Update@mmCompRoster@@UAEXXZ
    void Update() override;
};

check_size(mmCompRoster, 0x90);
