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

#include "arts7/camera.h"
#include "arts7/cullable.h"
#include "data7/timer.h"
#include "mmeffects/mmtext.h"

class mmLoader final : public asCullable
{
public:
    // ??0mmLoader@@QAE@XZ
    ARTS_IMPORT mmLoader();

    // ??_EmmLoader@@UAEPAXI@Z
    // ??1mmLoader@@UAE@XZ
    ARTS_IMPORT ~mmLoader() override;

    // ?BeginTask@mmLoader@@QAEXPAULocString@@M@Z
    ARTS_IMPORT void BeginTask(LocString* arg1, f32 arg2 = 0.0f);

    // ?Cull@mmLoader@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?EndTask@mmLoader@@QAEXM@Z
    ARTS_IMPORT void EndTask(f32 arg1 = 0.0f);

    // ?Init@mmLoader@@QAEXPADMM@Z
    ARTS_EXPORT void Init(aconst char* underlay_name, f32 bar_x, f32 bar_y);

    // ?Percent@mmLoader@@QAEXH@Z | unused
    ARTS_IMPORT void Percent(i32 arg1);

    // ?Reset@mmLoader@@QAEXXZ
    ARTS_IMPORT void Reset();

    // ?SetIntroText@mmLoader@@QAEXPAULocString@@@Z
    ARTS_IMPORT void SetIntroText(LocString* arg1);

    // ?Shutdown@mmLoader@@QAEXXZ | unused
    ARTS_IMPORT void Shutdown();

    // ?Update@mmLoader@@QAEXXZ
    ARTS_IMPORT void Update();

    friend mmLoader* Loader();

private:
    // ?Current@mmLoader@@0PAV1@A
    ARTS_IMPORT static mmLoader* Current;

    i32 task_percent_ {};
    i32 field_8_ {};
    i32 bar_x_ {};
    i32 bar_y_ {};
    i32 field_14_ {};
    i32 field_18_ {};
    asCamera camera_ {};
    Timer timer_ {};
    mmTextNode task_text_ {};
    mmTextNode intro_text_ {};
    mmTextNode text_node3_ {};
    agiBitmap* bar_active_ {};
    agiBitmap* bar_inactive_ {};
    i32 field_2b0_ {};
    f32 task_start_percent_ {};
    i32 field_2b8_ {};
    f32 current_task_percent_ {};
    f32 task_start_time_ {};
};

check_size(mmLoader, 0x2C4);

inline mmLoader* Loader()
{
    return mmLoader::Current;
}

// ?IntroFont@@3PAXA
ARTS_IMPORT extern void* IntroFont;

// ?myFont@@3PAXA
ARTS_IMPORT extern void* myFont;
