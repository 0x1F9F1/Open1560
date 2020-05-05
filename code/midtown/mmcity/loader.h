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
    mmcity:loader

    0x48B530 | public: __thiscall mmLoader::mmLoader(void) | ??0mmLoader@@QAE@XZ
    0x48B680 | public: virtual __thiscall mmLoader::~mmLoader(void) | ??1mmLoader@@UAE@XZ
    0x48B720 | public: void __thiscall mmLoader::Init(char *,float,float) | ?Init@mmLoader@@QAEXPADMM@Z
    0x48B810 | public: void __thiscall mmLoader::Shutdown(void) | ?Shutdown@mmLoader@@QAEXXZ
    0x48B820 | public: void __thiscall mmLoader::SetIntroText(struct LocString *) | ?SetIntroText@mmLoader@@QAEXPAULocString@@@Z
    0x48B850 | public: void __thiscall mmLoader::BeginTask(struct LocString *,float) | ?BeginTask@mmLoader@@QAEXPAULocString@@M@Z
    0x48B8D0 | public: void __thiscall mmLoader::EndTask(float) | ?EndTask@mmLoader@@QAEXM@Z
    0x48B970 | public: void __thiscall mmLoader::Percent(int) | ?Percent@mmLoader@@QAEXH@Z
    0x48B9C0 | public: void __thiscall mmLoader::Reset(void) | ?Reset@mmLoader@@QAEXXZ
    0x48B9E0 | public: void __thiscall mmLoader::Update(void) | ?Update@mmLoader@@QAEXXZ
    0x48BA70 | public: virtual void __thiscall mmLoader::Cull(void) | ?Cull@mmLoader@@UAEXXZ
    0x48BB20 | public: virtual void * __thiscall mmLoader::`scalar deleting destructor'(unsigned int) | ??_GmmLoader@@UAEPAXI@Z
    0x48BB20 | public: virtual void * __thiscall mmLoader::`vector deleting destructor'(unsigned int) | ??_EmmLoader@@UAEPAXI@Z
    0x48BB50 | public: virtual void * __thiscall asCullable::`scalar deleting destructor'(unsigned int) | ??_GasCullable@@UAEPAXI@Z
    0x48BB80 | public: virtual __thiscall asCullable::~asCullable(void) | ??1asCullable@@UAE@XZ
    0x61CBC8 | const mmLoader::`vftable' | ??_7mmLoader@@6B@
    0x61CBE0 | const asCullable::`vftable' | ??_7asCullable@@6B@
    0x6A8DA4 | private: static class mmLoader * mmLoader::Current | ?Current@mmLoader@@0PAV1@A
    0x6A8DA8 | void * IntroFont | ?IntroFont@@3PAXA
    0x6A8DAC | void * myFont | ?myFont@@3PAXA
*/

#include "arts7/cullable.h"

class mmLoader : public asCullable
{
    // const mmLoader::`vftable' @ 0x61CBC8

public:
    // 0x48B530 | ??0mmLoader@@QAE@XZ
    mmLoader();

    // 0x48BB20 | ??_EmmLoader@@UAEPAXI@Z
    // 0x48B680 | ??1mmLoader@@UAE@XZ
    ~mmLoader() override;

    // 0x48B850 | ?BeginTask@mmLoader@@QAEXPAULocString@@M@Z
    void BeginTask(struct LocString* arg1, f32 arg2);

    // 0x48BA70 | ?Cull@mmLoader@@UAEXXZ
    void Cull() override;

    // 0x48B8D0 | ?EndTask@mmLoader@@QAEXM@Z
    void EndTask(f32 arg1);

    // 0x48B720 | ?Init@mmLoader@@QAEXPADMM@Z
    void Init(char* arg1, f32 arg2, f32 arg3);

    // 0x48B970 | ?Percent@mmLoader@@QAEXH@Z
    void Percent(i32 arg1);

    // 0x48B9C0 | ?Reset@mmLoader@@QAEXXZ
    void Reset();

    // 0x48B820 | ?SetIntroText@mmLoader@@QAEXPAULocString@@@Z
    void SetIntroText(struct LocString* arg1);

    // 0x48B810 | ?Shutdown@mmLoader@@QAEXXZ
    void Shutdown();

    // 0x48B9E0 | ?Update@mmLoader@@QAEXXZ
    void Update();

private:
    // 0x6A8DA4 | ?Current@mmLoader@@0PAV1@A
    static inline extern_var(0x2A8DA4_Offset, class mmLoader*, Current);
};

check_size(mmLoader, 0x0);

// 0x6A8DA8 | ?IntroFont@@3PAXA
inline extern_var(0x2A8DA8_Offset, void*, IntroFont);

// 0x6A8DAC | ?myFont@@3PAXA
inline extern_var(0x2A8DAC_Offset, void*, myFont);
