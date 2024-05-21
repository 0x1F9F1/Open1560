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

#include "arts7/camera.h"
#include "arts7/cullable.h"
#include "data7/timer.h"
#include "mmeffects/mmtext.h"

class mmLoader final : public asCullable
{
public:
    // ??0mmLoader@@QAE@XZ
    ARTS_IMPORT mmLoader();

    // ??1mmLoader@@UAE@XZ
    ARTS_IMPORT ~mmLoader() override;

    // ?BeginTask@mmLoader@@QAEXPAULocString@@M@Z
    ARTS_IMPORT void BeginTask(LocString* arg1, f32 arg2 = 0.0f);

    // ?Cull@mmLoader@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?EndTask@mmLoader@@QAEXM@Z
    ARTS_IMPORT void EndTask(f32 arg1 = 0.0f);

    // ?Init@mmLoader@@QAEXPADMM@Z
    void Init(aconst char* underlay_name, f32 bar_x, f32 bar_y);

    // ?Reset@mmLoader@@QAEXXZ
    ARTS_IMPORT void Reset();

    // ?SetIntroText@mmLoader@@QAEXPAULocString@@@Z
    ARTS_IMPORT void SetIntroText(LocString* arg1);

    // ?Update@mmLoader@@QAEXXZ
    ARTS_EXPORT void Update();

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

struct LoaderTask
{
    LocString* Name {};
    f32 Percent {};

    LoaderTask(LocString* name, f32 percent)
        : Percent(percent)
    {
        Begin(name);
    }

    ~LoaderTask()
    {
        End();
    }

    void Begin(LocString* name)
    {
        End();
        Loader()->BeginTask(name);
        Name = name;
    }

    void End()
    {
        if (Name)
        {
            Loader()->EndTask(Percent);
            Name = nullptr;
        }
    }
};

#define ARTS_LOADER_TASK(NAME, PERCENT)             \
    LoaderTask ARTS_CONCAT(loader_task_, ARTS_LINE) \
    {                                               \
        LOC_STRING(NAME), PERCENT                   \
    }
