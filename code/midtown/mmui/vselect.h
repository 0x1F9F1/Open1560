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
    mmui:vselect

    0x49A790 | public: __thiscall VehicleSelectBase::VehicleSelectBase(int) | ??0VehicleSelectBase@@QAE@H@Z
    0x49A8F0 | public: void __thiscall VehicleSelectBase::IncColor(void) | ?IncColor@VehicleSelectBase@@QAEXXZ
    0x49A9B0 | public: void __thiscall VehicleSelectBase::DecColor(void) | ?DecColor@VehicleSelectBase@@QAEXXZ
    0x49AA70 | public: void __thiscall VehicleSelectBase::ColorCB(void) | ?ColorCB@VehicleSelectBase@@QAEXXZ
    0x49AA90 | public: void __thiscall VehicleSelectBase::InitCarSelection(int,float,float,float,float) | ?InitCarSelection@VehicleSelectBase@@QAEXHMMMM@Z
    0x49B7D0 | public: virtual __thiscall VehicleSelectBase::~VehicleSelectBase(void) | ??1VehicleSelectBase@@UAE@XZ
    0x49B870 | public: virtual void __thiscall VehicleSelectBase::PreSetup(void) | ?PreSetup@VehicleSelectBase@@UAEXXZ
    0x49B960 | public: virtual void __thiscall VehicleSelectBase::PostSetup(void) | ?PostSetup@VehicleSelectBase@@UAEXXZ
    0x49B990 | public: void __thiscall VehicleSelectBase::AllSetCar(char *,int) | ?AllSetCar@VehicleSelectBase@@QAEXPADH@Z
    0x49B9E0 | public: void __thiscall VehicleSelectBase::TDPickCB(void) | ?TDPickCB@VehicleSelectBase@@QAEXXZ
    0x49B9F0 | public: virtual void __thiscall VehicleSelectBase::Reset(void) | ?Reset@VehicleSelectBase@@UAEXXZ
    0x49BA00 | public: virtual void __thiscall VehicleSelectBase::Update(void) | ?Update@VehicleSelectBase@@UAEXXZ
    0x49BAA0 | public: char * __thiscall VehicleSelectBase::GetCarTitle(int,char *,short,class string *) | ?GetCarTitle@VehicleSelectBase@@QAEPADHPADFPAVstring@@@Z
    0x49BBD0 | public: int __thiscall VehicleSelectBase::CurrentVehicleIsLocked(void) | ?CurrentVehicleIsLocked@VehicleSelectBase@@QAEHXZ
    0x49BBF0 | public: void __thiscall VehicleSelectBase::SetLastUnlockedVehicle(void) | ?SetLastUnlockedVehicle@VehicleSelectBase@@QAEXXZ
    0x49BC50 | public: void __thiscall VehicleSelectBase::CarMod(int &) | ?CarMod@VehicleSelectBase@@QAEXAAH@Z
    0x49BC80 | public: void __thiscall VehicleSelectBase::SetPick(int,short) | ?SetPick@VehicleSelectBase@@QAEXHF@Z
    0x49BF60 | public: int __thiscall VehicleSelectBase::LoadStats(char *) | ?LoadStats@VehicleSelectBase@@QAEHPAD@Z
    0x49C000 | public: void __thiscall VehicleSelectBase::AssignVehicleStats(int,float,float,float,float) | ?AssignVehicleStats@VehicleSelectBase@@QAEXHMMMM@Z
    0x49C1E0 | public: void __thiscall VehicleSelectBase::FillStats(void) | ?FillStats@VehicleSelectBase@@QAEXXZ
    0x49C230 | public: void __thiscall VehicleSelectBase::SetLockedLabel(void) | ?SetLockedLabel@VehicleSelectBase@@QAEXXZ
    0x49C3A0 | public: virtual void * __thiscall VehicleSelectBase::`scalar deleting destructor'(unsigned int) | ??_GVehicleSelectBase@@UAEPAXI@Z
    0x49C3A0 | public: virtual void * __thiscall VehicleSelectBase::`vector deleting destructor'(unsigned int) | ??_EVehicleSelectBase@@UAEPAXI@Z
    0x49C3D0 | public: virtual void * __thiscall asDofCS::`vector deleting destructor'(unsigned int) | ??_EasDofCS@@UAEPAXI@Z
    0x49C430 | public: virtual __thiscall asDofCS::~asDofCS(void) | ??1asDofCS@@UAE@XZ
    0x49C440 | public: virtual void * __thiscall mmVehicleForm::`vector deleting destructor'(unsigned int) | ??_EmmVehicleForm@@UAEPAXI@Z
    0x49C4A0 | public: virtual __thiscall mmVehicleForm::~mmVehicleForm(void) | ??1mmVehicleForm@@UAE@XZ
    0x49C4F0 | public: virtual int __thiscall UIMenu::IsAnOptionMenu(void) | ?IsAnOptionMenu@UIMenu@@UAEHXZ
    0x49C500 | public: void __thiscall VehicleSelectBase::DecCar(void) | ?DecCar@VehicleSelectBase@@QAEXXZ
    0x49C510 | public: void __thiscall VehicleSelectBase::IncCar(void) | ?IncCar@VehicleSelectBase@@QAEXXZ
    0x49C520 | public: void __thiscall VehicleSelectBase::SetShowcaseFlag(void) | ?SetShowcaseFlag@VehicleSelectBase@@QAEXXZ
    0x49C530 | public: void __thiscall Card2D::SetColor(class Vector4) | ?SetColor@Card2D@@QAEXVVector4@@@Z
    0x49C590 | public: int __thiscall mmVehInfo::IsValid(void) | ?IsValid@mmVehInfo@@QAEHXZ
    0x61D3D0 | const VehicleSelectBase::`vftable' | ??_7VehicleSelectBase@@6B@
*/

#include "mmwidget/menu.h"

class VehicleSelectBase : public UIMenu
{
    // const VehicleSelectBase::`vftable'

public:
    // ??0VehicleSelectBase@@QAE@H@Z
    ARTS_IMPORT VehicleSelectBase(i32 arg1);

    // ??_EVehicleSelectBase@@UAEPAXI@Z
    // ??_GVehicleSelectBase@@UAEPAXI@Z
    // ??1VehicleSelectBase@@UAE@XZ
    ARTS_IMPORT ~VehicleSelectBase() override;

    // ?AllSetCar@VehicleSelectBase@@QAEXPADH@Z
    ARTS_IMPORT void AllSetCar(char* arg1, i32 arg2);

    // ?AssignVehicleStats@VehicleSelectBase@@QAEXHMMMM@Z
    ARTS_IMPORT void AssignVehicleStats(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // ?CarMod@VehicleSelectBase@@QAEXAAH@Z
    ARTS_IMPORT void CarMod(i32& arg1);

    // ?ColorCB@VehicleSelectBase@@QAEXXZ
    ARTS_IMPORT void ColorCB();

    // ?CurrentVehicleIsLocked@VehicleSelectBase@@QAEHXZ
    ARTS_IMPORT i32 CurrentVehicleIsLocked();

    // ?DecCar@VehicleSelectBase@@QAEXXZ | inline
    ARTS_IMPORT void DecCar();

    // ?DecColor@VehicleSelectBase@@QAEXXZ
    ARTS_IMPORT void DecColor();

    // ?FillStats@VehicleSelectBase@@QAEXXZ
    ARTS_IMPORT void FillStats();

    // ?GetCarTitle@VehicleSelectBase@@QAEPADHPADFPAVstring@@@Z
    ARTS_IMPORT char* GetCarTitle(i32 arg1, char* arg2, i16 arg3, class string* arg4);

    // ?IncCar@VehicleSelectBase@@QAEXXZ | inline
    ARTS_IMPORT void IncCar();

    // ?IncColor@VehicleSelectBase@@QAEXXZ
    ARTS_IMPORT void IncColor();

    // ?InitCarSelection@VehicleSelectBase@@QAEXHMMMM@Z
    ARTS_IMPORT void InitCarSelection(i32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

    // ?LoadStats@VehicleSelectBase@@QAEHPAD@Z
    ARTS_IMPORT i32 LoadStats(char* arg1);

    // ?PostSetup@VehicleSelectBase@@UAEXXZ
    ARTS_IMPORT void PostSetup() override;

    // ?PreSetup@VehicleSelectBase@@UAEXXZ
    ARTS_IMPORT void PreSetup() override;

    // ?Reset@VehicleSelectBase@@UAEXXZ
    ARTS_EXPORT void Reset() override;

    // ?SetLastUnlockedVehicle@VehicleSelectBase@@QAEXXZ
    ARTS_IMPORT void SetLastUnlockedVehicle();

    // ?SetLockedLabel@VehicleSelectBase@@QAEXXZ
    ARTS_IMPORT void SetLockedLabel();

    // ?SetPick@VehicleSelectBase@@QAEXHF@Z
    ARTS_IMPORT void SetPick(i32 arg1, i16 arg2);

    // ?SetShowcaseFlag@VehicleSelectBase@@QAEXXZ | inline
    ARTS_IMPORT void SetShowcaseFlag();

    // ?TDPickCB@VehicleSelectBase@@QAEXXZ
    ARTS_IMPORT void TDPickCB();

    // ?Update@VehicleSelectBase@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap90[0xD8];
};

check_size(VehicleSelectBase, 0x168);
