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

#include "node.h"

#include "data7/callback.h"
#include "data7/mutex.h"
#include "data7/timer.h"

class agiBitmap;
class asCamera;
class asCullable;

class asCullManager final : public asNode
{
public:
    // ??0asCullManager@@QAE@HH@Z
    ARTS_EXPORT asCullManager(i32 max_cullables, i32 max_cullables_2D);

    // ??_EasCullManager@@UAEPAXI@Z
    // ??1asCullManager@@UAE@XZ
    ARTS_EXPORT ~asCullManager() override;

    // ?DeclareCamera@asCullManager@@UAEXPAVasCamera@@@Z
    ARTS_EXPORT virtual void DeclareCamera(asCamera* camera);

    // ?DeclareCullable@asCullManager@@UAEXPAVasCullable@@@Z
    ARTS_EXPORT virtual void DeclareCullable(asCullable* cullable);

    // ?DeclareCullable2D@asCullManager@@UAEXPAVasCullable@@@Z
    ARTS_EXPORT virtual void DeclareCullable2D(asCullable* cullable);

#ifdef ARTS_DEV_BUILD
    // ?AddPage@asCullManager@@QAEXVCallback@@@Z
    ARTS_EXPORT void AddPage(Callback callback);
#endif

    // ?DeclareBitmap@asCullManager@@QAEXPAVasCullable@@PAVagiBitmap@@@Z
    ARTS_EXPORT void DeclareBitmap(asCullable* cullable, agiBitmap* bitmap);

    // ?DeclarePrint@asCullManager@@QAEXPAVasCullable@@@Z
    ARTS_EXPORT void DeclarePrint(asCullable* cullable);

    // ?Reset@asCullManager@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // ?Update@asCullManager@@UAEXXZ
    ARTS_IMPORT void Update() override;

    void ToggleDebug()
    {
        debug_ ^= true;
    }

    u32 GetTextColor() const
    {
        return text_color_;
    }

#ifdef ARTS_DEV_BUILD
    u32 CurrentPage() const
    {
        return current_page_;
    }

    void HidePage()
    {
        current_page_ = 0;
    }

    void PrevPage()
    {
        if (current_page_ == 0)
            current_page_ = num_pages_ + 1;

        --current_page_;
    }

    void NextPage()
    {
        if (++current_page_ == num_pages_ + 1)
            current_page_ = 0;
    }
#endif

    VIRTUAL_META_DECLARE;

protected:
    // ?DisplayVersionString@asCullManager@@IAEXXZ
    ARTS_EXPORT void DisplayVersionString();

    // ?PrintMiniStats@asCullManager@@IAEXXZ
    ARTS_EXPORT void PrintMiniStats();

    // ?PrintStats@asCullManager@@IAEXXZ
    ARTS_EXPORT void PrintStats();

private:
    u32 text_color_ {0xFFFFFFFF};

    u32 color_red_ {0xFFFF0000};
    u32 color_green_ {0xFF00FF00};
    u32 color_blue_ {0xFF0000FF};

    b32 debug_ {};

    i32 num_cameras_ {};
    asCamera* cameras_[16] {};
    asCamera* current_camera_ {};

    i32 num_cullables_ {};
    i32 max_cullables_ {};

    i32 num_cullables_2D_ {};
    i32 max_cullables_2D_ {};

    Ptr<asCullable*[]> cullables_;
    Ptr<asCullable*[]> cullables_2D_;
    Ptr<Matrix34*[]> transforms_;

    f32 current_frame_time_ {};
    f32 average_frame_time_ {};

    Timer frame_timer_ {};
    Timer stats_timer_ {};

    u32 stats_counter_ {};

#ifdef ARTS_DEV_BUILD
    u32 current_page_ {};
    u32 num_pages_ {};

    Callback page_callbacks_[16] {};
#endif

    // NOTE: The mutex is never initialized
    // FIXME: ipcWaitSingle is still used in asCullManager::Update
    Mutex mutex_ {};
};

check_size(asCullManager, 0x1F8);

// ?Statsf@@YAXPBDZZ
ARTS_EXPORT void Statsf(ARTS_FORMAT_STRING const char* format, ...);

// ?CULLMGR@@3PAVasCullManager@@A
ARTS_IMPORT extern asCullManager* CULLMGR;

inline asCullManager* CullMgr()
{
    return CULLMGR;
}

// ?Update3D@@3MA
ARTS_IMPORT extern f32 Update3D;

// ?VERSION_STRING@@3PADA
extern const char* VERSION_STRING;
