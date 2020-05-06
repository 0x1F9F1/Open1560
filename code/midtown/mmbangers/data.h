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
    mmbangers:data

    0x4C81B0 | public: int __thiscall mmBangerData::LoadEntry(char *) | ?LoadEntry@mmBangerData@@QAEHPAD@Z
    0x4C8370 | public: void __thiscall mmBangerData::LaunchInstance(float,class Vector3 *) | ?LaunchInstance@mmBangerData@@QAEXMPAVVector3@@@Z
    0x4C8550 | public: virtual void __thiscall mmBangerDataManager::AddWidgets(class Bank *) | ?AddWidgets@mmBangerDataManager@@UAEXPAVBank@@@Z
    0x4C85E0 | public: virtual void __thiscall mmBangerData::AddWidgets(class Bank *) | ?AddWidgets@mmBangerData@@UAEXPAVBank@@@Z
    0x4C8A30 | public: __thiscall mmBangerDataManager::mmBangerDataManager(void) | ??0mmBangerDataManager@@QAE@XZ
    0x4C8B50 | public: virtual __thiscall mmBangerDataManager::~mmBangerDataManager(void) | ??1mmBangerDataManager@@UAE@XZ
    0x4C8C10 | public: int __thiscall mmBangerDataManager::AddBangerDataEntry(char *,char *) | ?AddBangerDataEntry@mmBangerDataManager@@QAEHPAD0@Z
    0x4C8E70 | public: int __thiscall mmBangerData::Bootstrap(char *,char *) | ?Bootstrap@mmBangerData@@QAEHPAD0@Z
    0x4C8ED0 | public: void __thiscall mmBangerData::BootstrapBreakablesOnly(char *) | ?BootstrapBreakablesOnly@mmBangerData@@QAEXPAD@Z
    0x4C8F10 | public: void __thiscall mmBangerData::InitBreakables(char *) | ?InitBreakables@mmBangerData@@QAEXPAD@Z
    0x4C9150 | public: int __thiscall mmBangerData::InitPhysics(char *,char *) | ?InitPhysics@mmBangerData@@QAEHPAD0@Z
    0x4C93D0 | public: void __thiscall mmBangerData::ComputeYRadius(char *) | ?ComputeYRadius@mmBangerData@@QAEXPAD@Z
    0x4C9510 | public: virtual void __thiscall mmBangerDataManager::Save(void) | ?Save@mmBangerDataManager@@UAEXXZ
    0x4C9540 | public: static void __cdecl mmBangerData::DeclareFields(void) | ?DeclareFields@mmBangerData@@SAXXZ
    0x4C98C0 | public: virtual class MetaClass * __thiscall mmBangerData::GetClass(void) | ?GetClass@mmBangerData@@UAEPAVMetaClass@@XZ
    0x4C98D0 | public: static void __cdecl mmBangerDataManager::DeclareFields(void) | ?DeclareFields@mmBangerDataManager@@SAXXZ
    0x4C9A40 | public: virtual class MetaClass * __thiscall mmBangerDataManager::GetClass(void) | ?GetClass@mmBangerDataManager@@UAEPAVMetaClass@@XZ
    0x4C9A50 | struct MetaType * __cdecl RefTo(struct MetaType *,int,short *) | ?RefTo@@YAPAUMetaType@@PAU1@HPAF@Z
    0x4C9A90 | public: virtual void * __thiscall mmBangerData::`vector deleting destructor'(unsigned int) | ??_EmmBangerData@@UAEPAXI@Z
    0x4C9AF0 | public: virtual void * __thiscall mmBangerDataManager::`vector deleting destructor'(unsigned int) | ??_EmmBangerDataManager@@UAEPAXI@Z
    0x4C9B50 | public: __thiscall mmBangerData::mmBangerData(void) | ??0mmBangerData@@QAE@XZ
    0x4C9BE0 | public: virtual __thiscall mmBangerData::~mmBangerData(void) | ??1mmBangerData@@UAE@XZ
    0x61F6E0 | const mmBangerDataManager::`vftable' | ??_7mmBangerDataManager@@6B@
    0x61F720 | const RefToType::`vftable' | ??_7RefToType@@6B@
    0x61F738 | const mmBangerData::`vftable' | ??_7mmBangerData@@6B@
    0x705FB0 | class MetaClass mmBangerDataMetaClass | ?mmBangerDataMetaClass@@3VMetaClass@@A
    0x705FD8 | public: static float mmBangerDataManager::FloatClock | ?FloatClock@mmBangerDataManager@@2MA
    0x705FDC | protected: static class mmBangerDataManager * mmBangerDataManager::Instance | ?Instance@mmBangerDataManager@@1PAV1@A
    0x705FF0 | public: static int mmBangerDataManager::SignalClock | ?SignalClock@mmBangerDataManager@@2HA
    0x706008 | class MetaClass mmBangerDataManagerMetaClass | ?mmBangerDataManagerMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class mmBangerData : public asNode
{
    // const mmBangerData::`vftable' @ 0x61F738

public:
    // 0x4C9B50 | ??0mmBangerData@@QAE@XZ
    mmBangerData();

    // 0x4C9A90 | ??_EmmBangerData@@UAEPAXI@Z
    // 0x4C9BE0 | ??1mmBangerData@@UAE@XZ
    ~mmBangerData() override;

    // 0x4C85E0 | ?AddWidgets@mmBangerData@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x4C8E70 | ?Bootstrap@mmBangerData@@QAEHPAD0@Z
    i32 Bootstrap(char* arg1, char* arg2);

    // 0x4C8ED0 | ?BootstrapBreakablesOnly@mmBangerData@@QAEXPAD@Z
    void BootstrapBreakablesOnly(char* arg1);

    // 0x4C93D0 | ?ComputeYRadius@mmBangerData@@QAEXPAD@Z
    void ComputeYRadius(char* arg1);

    // 0x4C98C0 | ?GetClass@mmBangerData@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4C8F10 | ?InitBreakables@mmBangerData@@QAEXPAD@Z
    void InitBreakables(char* arg1);

    // 0x4C9150 | ?InitPhysics@mmBangerData@@QAEHPAD0@Z
    i32 InitPhysics(char* arg1, char* arg2);

    // 0x4C8370 | ?LaunchInstance@mmBangerData@@QAEXMPAVVector3@@@Z
    void LaunchInstance(f32 arg1, class Vector3* arg2);

    // 0x4C81B0 | ?LoadEntry@mmBangerData@@QAEHPAD@Z
    i32 LoadEntry(char* arg1);

    // 0x4C9540 | ?DeclareFields@mmBangerData@@SAXXZ
    static void DeclareFields();
};

check_size(mmBangerData, 0x134);

class mmBangerDataManager : public asNode
{
    // const mmBangerDataManager::`vftable' @ 0x61F6E0

public:
    // 0x4C8A30 | ??0mmBangerDataManager@@QAE@XZ
    mmBangerDataManager();

    // 0x4C9AF0 | ??_EmmBangerDataManager@@UAEPAXI@Z
    // 0x4C8B50 | ??1mmBangerDataManager@@UAE@XZ
    ~mmBangerDataManager() override;

    // 0x4C8C10 | ?AddBangerDataEntry@mmBangerDataManager@@QAEHPAD0@Z
    i32 AddBangerDataEntry(char* arg1, char* arg2);

    // 0x4C8550 | ?AddWidgets@mmBangerDataManager@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x4C9A40 | ?GetClass@mmBangerDataManager@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4C9510 | ?Save@mmBangerDataManager@@UAEXXZ
    void Save() override;

    // 0x4C98D0 | ?DeclareFields@mmBangerDataManager@@SAXXZ
    static void DeclareFields();

    // 0x705FD8 | ?FloatClock@mmBangerDataManager@@2MA
    static inline extern_var(0x705FD8, f32, FloatClock);

    // 0x705FF0 | ?SignalClock@mmBangerDataManager@@2HA
    static inline extern_var(0x705FF0, i32, SignalClock);

protected:
    // 0x705FDC | ?Instance@mmBangerDataManager@@1PAV1@A
    static inline extern_var(0x705FDC, class mmBangerDataManager*, Instance);
};

check_size(mmBangerDataManager, 0x268D0);

// 0x4C9A50 | ?RefTo@@YAPAUMetaType@@PAU1@HPAF@Z
struct MetaType* RefTo(struct MetaType* arg1, i32 arg2, i16* arg3);

// 0x706008 | ?mmBangerDataManagerMetaClass@@3VMetaClass@@A
inline extern_var(0x706008, class MetaClass, mmBangerDataManagerMetaClass);

// 0x705FB0 | ?mmBangerDataMetaClass@@3VMetaClass@@A
inline extern_var(0x705FB0, class MetaClass, mmBangerDataMetaClass);
