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
    mmwidget:compdrec

    0x4B5A80 | public: __thiscall mmCompDRecord::mmCompDRecord(void) | ??0mmCompDRecord@@QAE@XZ
    0x4B5AC0 | public: virtual __thiscall mmCompDRecord::~mmCompDRecord(void) | ??1mmCompDRecord@@UAE@XZ
    0x4B5B70 | public: void __thiscall mmCompDRecord::Init(int,char *,float,char *,int,int,int) | ?Init@mmCompDRecord@@QAEXHPADM0HHH@Z
    0x4B5C60 | public: void __thiscall mmCompDRecord::InitTitle(float,float,float,float,struct LocString *,struct LocString *,struct LocString *,struct LocString *,struct LocString *,int) | ?InitTitle@mmCompDRecord@@QAEXMMMMPAULocString@@0000H@Z
    0x4B5CD0 | public: void __thiscall mmCompDRecord::LoadBitmap(char *) | ?LoadBitmap@mmCompDRecord@@QAEXPAD@Z
    0x4B5D40 | public: virtual void __thiscall mmCompDRecord::Reset(void) | ?Reset@mmCompDRecord@@UAEXXZ
    0x4B5D50 | public: virtual void __thiscall mmCompDRecord::Update(void) | ?Update@mmCompDRecord@@UAEXXZ
    0x4B5D80 | public: void __thiscall mmCompDRecord::SetSubwidgetGeometry(void) | ?SetSubwidgetGeometry@mmCompDRecord@@QAEXXZ
    0x4B5EA0 | public: virtual void __thiscall mmCompDRecord::SetPosition(class mmTextNode *,int,float) | ?SetPosition@mmCompDRecord@@UAEXPAVmmTextNode@@HM@Z
    0x4B5F40 | public: virtual void __thiscall mmCompDRecord::SetGeometry(float,float,float,float) | ?SetGeometry@mmCompDRecord@@UAEXMMMM@Z
    0x4B5F70 | public: virtual void __thiscall mmCompDRecord::SetBltXY(float,float) | ?SetBltXY@mmCompDRecord@@UAEXMM@Z
    0x4B5FC0 | public: virtual void __thiscall mmCompDRecord::Cull(void) | ?Cull@mmCompDRecord@@UAEXXZ
    0x4B6060 | public: virtual void * __thiscall mmCompDRecord::`scalar deleting destructor'(unsigned int) | ??_GmmCompDRecord@@UAEPAXI@Z
    0x4B6060 | public: virtual void * __thiscall mmCompDRecord::`vector deleting destructor'(unsigned int) | ??_EmmCompDRecord@@UAEPAXI@Z
    0x4B6090 | public: virtual void __thiscall mmCompDRecord::DisableBlt(void) | ?DisableBlt@mmCompDRecord@@UAEXXZ
    0x61E800 | const mmCompDRecord::`vftable' | ??_7mmCompDRecord@@6B@
*/

#include "compbase.h"

class mmCompDRecord : public mmCompBase
{
    // const mmCompDRecord::`vftable' @ 0x61E800

public:
    // 0x4B5A80 | ??0mmCompDRecord@@QAE@XZ
    mmCompDRecord();

    // 0x4B6060 | ??_EmmCompDRecord@@UAEPAXI@Z
    // 0x4B5AC0 | ??1mmCompDRecord@@UAE@XZ
    ~mmCompDRecord() override;

    // 0x4B5FC0 | ?Cull@mmCompDRecord@@UAEXXZ
    void Cull() override;

    // 0x4B6090 | ?DisableBlt@mmCompDRecord@@UAEXXZ
    void DisableBlt() override;

    // 0x4B5B70 | ?Init@mmCompDRecord@@QAEXHPADM0HHH@Z
    void Init(i32 arg1, char* arg2, f32 arg3, char* arg4, i32 arg5, i32 arg6, i32 arg7);

    // 0x4B5C60 | ?InitTitle@mmCompDRecord@@QAEXMMMMPAULocString@@0000H@Z
    void InitTitle(f32 arg1, f32 arg2, f32 arg3, f32 arg4, struct LocString* arg5, struct LocString* arg6,
        struct LocString* arg7, struct LocString* arg8, struct LocString* arg9, i32 arg10);

    // 0x4B5CD0 | ?LoadBitmap@mmCompDRecord@@QAEXPAD@Z
    void LoadBitmap(char* arg1);

    // 0x4B5D40 | ?Reset@mmCompDRecord@@UAEXXZ
    void Reset() override;

    // 0x4B5F70 | ?SetBltXY@mmCompDRecord@@UAEXMM@Z
    void SetBltXY(f32 arg1, f32 arg2) override;

    // 0x4B5F40 | ?SetGeometry@mmCompDRecord@@UAEXMMMM@Z
    void SetGeometry(f32 arg1, f32 arg2, f32 arg3, f32 arg4) override;

    // 0x4B5EA0 | ?SetPosition@mmCompDRecord@@UAEXPAVmmTextNode@@HM@Z
    void SetPosition(class mmTextNode* arg1, i32 arg2, f32 arg3) override;

    // 0x4B5D80 | ?SetSubwidgetGeometry@mmCompDRecord@@QAEXXZ
    void SetSubwidgetGeometry();

    // 0x4B5D50 | ?Update@mmCompDRecord@@UAEXXZ
    void Update() override;
};

check_size(mmCompDRecord, 0xA4);
