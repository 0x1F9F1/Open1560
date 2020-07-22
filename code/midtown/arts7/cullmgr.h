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
    arts7:cullmgr

    0x5246C0 | public: __thiscall asCullManager::asCullManager(int,int) | ??0asCullManager@@QAE@HH@Z
    0x524D40 | public: virtual __thiscall asCullManager::~asCullManager(void) | ??1asCullManager@@UAE@XZ
    0x524DF0 | public: virtual void __thiscall asCullManager::Reset(void) | ?Reset@asCullManager@@UAEXXZ
    0x524E50 | protected: void __thiscall asCullManager::DisplayVersionString(void) | ?DisplayVersionString@asCullManager@@IAEXXZ
    0x524E70 | void __cdecl Statsf(char const *,...) | ?Statsf@@YAXPBDZZ
    0x524F00 | protected: void __thiscall asCullManager::PrintMiniStats(void) | ?PrintMiniStats@asCullManager@@IAEXXZ
    0x524F90 | protected: void __thiscall asCullManager::PrintStats(void) | ?PrintStats@asCullManager@@IAEXXZ
    0x525090 | public: virtual void __thiscall asCullManager::Update(void) | ?Update@asCullManager@@UAEXXZ
    0x525400 | public: void __thiscall asCullManager::AddPage(class Callback) | ?AddPage@asCullManager@@QAEXVCallback@@@Z
    0x525440 | public: virtual void __thiscall asCullManager::DeclareCamera(class asCamera *) | ?DeclareCamera@asCullManager@@UAEXPAVasCamera@@@Z
    0x5254A0 | public: virtual void __thiscall asCullManager::DeclareCullable(class asCullable *) | ?DeclareCullable@asCullManager@@UAEXPAVasCullable@@@Z
    0x525550 | public: virtual void __thiscall asCullManager::DeclareCullable2D(class asCullable *) | ?DeclareCullable2D@asCullManager@@UAEXPAVasCullable@@@Z
    0x5255F0 | public: void __thiscall asCullManager::DeclareBitmap(class asCullable *,class agiBitmap *) | ?DeclareBitmap@asCullManager@@QAEXPAVasCullable@@PAVagiBitmap@@@Z
    0x525660 | public: void __thiscall asCullManager::DeclarePrint(class asCullable *) | ?DeclarePrint@asCullManager@@QAEXPAVasCullable@@@Z
    0x5256D0 | public: static void __cdecl asCullManager::DeclareFields(void) | ?DeclareFields@asCullManager@@SAXXZ
    0x525840 | public: virtual class MetaClass * __thiscall asCullManager::GetClass(void) | ?GetClass@asCullManager@@UAEPAVMetaClass@@XZ
    0x525850 | public: virtual void * __thiscall asCullManager::`vector deleting destructor'(unsigned int) | ??_EasCullManager@@UAEPAXI@Z
    0x5258B0 | public: void __thiscall asCullManager::`default constructor closure'(void) | ??_FasCullManager@@QAEXXZ
    0x620AD0 | const asCullManager::`vftable' | ??_7asCullManager@@6B@
    0x79086C | class asCullManager * CULLMGR | ?CULLMGR@@3PAVasCullManager@@A
    0x790880 | class MetaClass asCullManagerMetaClass | ?asCullManagerMetaClass@@3VMetaClass@@A
    0x7908A8 | float Update3D | ?Update3D@@3MA
*/

#include "node.h"

#include "data7/callback.h"
#include "data7/mutex.h"
#include "data7/timer.h"

class asCamera;
class asCullable;
class Matrix34;

class asCullManager /*final*/ : public asNode
{
    // const asCullManager::`vftable' @ 0x620AD0

public:
    // 0x5246C0 | ??0asCullManager@@QAE@HH@Z
    ARTS_EXPORT asCullManager(i32 max_cullables, i32 max_cullables_2D);

    // 0x525850 | ??_EasCullManager@@UAEPAXI@Z
    // 0x524D40 | ??1asCullManager@@UAE@XZ
    ARTS_EXPORT ~asCullManager() override;

    // 0x525440 | ?DeclareCamera@asCullManager@@UAEXPAVasCamera@@@Z
    ARTS_EXPORT virtual void DeclareCamera(class asCamera* camera);

    // 0x5254A0 | ?DeclareCullable@asCullManager@@UAEXPAVasCullable@@@Z
    ARTS_IMPORT virtual void DeclareCullable(class asCullable* cullable);

    // 0x525550 | ?DeclareCullable2D@asCullManager@@UAEXPAVasCullable@@@Z
    ARTS_IMPORT virtual void DeclareCullable2D(class asCullable* cullable);

    // 0x525400 | ?AddPage@asCullManager@@QAEXVCallback@@@Z
    ARTS_EXPORT void AddPage(class Callback callback);

    // 0x5255F0 | ?DeclareBitmap@asCullManager@@QAEXPAVasCullable@@PAVagiBitmap@@@Z
    ARTS_IMPORT void DeclareBitmap(class asCullable* cullable, class agiBitmap* bitmap);

    // 0x525660 | ?DeclarePrint@asCullManager@@QAEXPAVasCullable@@@Z
    ARTS_IMPORT void DeclarePrint(class asCullable* cullable);

    // 0x524DF0 | ?Reset@asCullManager@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // 0x525090 | ?Update@asCullManager@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u32 GetTextColor() const
    {
        return text_color_;
    }

    VIRTUAL_META_DECLARE;

protected:
    // 0x524E50 | ?DisplayVersionString@asCullManager@@IAEXXZ
    ARTS_EXPORT void DisplayVersionString();

    // 0x524F00 | ?PrintMiniStats@asCullManager@@IAEXXZ
    ARTS_EXPORT void PrintMiniStats();

    // 0x524F90 | ?PrintStats@asCullManager@@IAEXXZ
    ARTS_EXPORT void PrintStats();

private:
    u32 text_color_ {0};

    u32 color_red_ {0};
    u32 color_green_ {0};
    u32 color_blue_ {0};

    b32 debug_ {0};

    i32 num_cameras_ {0};
    asCamera* cameras_[16] {};
    asCamera* current_camera_ {nullptr};

    i32 num_cullables_ {0};
    i32 max_cullables_ {0};

    i32 num_cullables_2D_ {0};
    i32 max_cullables_2D_ {0};

    Ptr<asCullable* []> cullables_ { nullptr };
    Ptr<asCullable* []> cullables_2D_ { nullptr };
    Ptr<Matrix34* []> transforms_ { nullptr };

    f32 current_fps_ {0.0f};
    f32 average_fps_ {0.0f};

    Timer frame_timer_ {};
    Timer stats_timer_ {};

    u32 stats_counter_ {0};

    u32 current_page_ {0};
    u32 num_pages_ {0};

    Callback page_callbacks_[16] {};

    // TODO: Is this mutex necessary? It never seems to be initialized.
    Mutex mutex_ {};
};

check_size(asCullManager, 0x1F8);

// 0x524E70 | ?Statsf@@YAXPBDZZ
ARTS_EXPORT void Statsf(char const* format, ...);

// 0x79086C | ?CULLMGR@@3PAVasCullManager@@A
ARTS_IMPORT extern class asCullManager* CULLMGR;

// 0x7908A8 | ?Update3D@@3MA
ARTS_IMPORT extern f32 Update3D;

// 0x790880 | ?asCullManagerMetaClass@@3VMetaClass@@A
// ARTS_IMPORT extern class MetaClass asCullManagerMetaClass;
