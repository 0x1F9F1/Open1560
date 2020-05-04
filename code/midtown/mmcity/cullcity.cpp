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

#include "cullcity.h"

mmCullCity::mmCullCity()
{
    unimplemented();
}

mmCullCity::~mmCullCity()
{
    unimplemented();
}

void mmCullCity::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmCullCity*, class Bank*>>(0x8E4B0_Offset, this, arg1);
}

void mmCullCity::Cull()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x8D820_Offset, this);
}

class MetaClass* mmCullCity::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmCullCity*>>(0x8FA30_Offset, this);
}

i16 mmCullCity::GetHitId(class Vector3& arg1)
{
    return stub<thiscall_t<i16, mmCullCity*, class Vector3&>>(0x8BF10_Offset, this, arg1);
}

i16 mmCullCity::GetRoomFlags(i16 arg1)
{
    return stub<thiscall_t<i16, mmCullCity*, i16>>(0x8D960_Offset, this, arg1);
}

void mmCullCity::Init(char* arg1, class asCamera* arg2)
{
    return stub<thiscall_t<void, mmCullCity*, char*, class asCamera*>>(0x8C6D0_Offset, this, arg1, arg2);
}

void mmCullCity::InitObjectDetail()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x8CEA0_Offset, this);
}

i32 mmCullCity::IsPolyWater(class mmPolygon* arg1)
{
    return stub<thiscall_t<i32, mmCullCity*, class mmPolygon*>>(0x8D590_Offset, this, arg1);
}

void mmCullCity::LoadBangers(char* arg1)
{
    return stub<thiscall_t<void, mmCullCity*, char*>>(0x8CED0_Offset, this, arg1);
}

void mmCullCity::LoadFacades(char* arg1)
{
    return stub<thiscall_t<void, mmCullCity*, char*>>(0x8CFF0_Offset, this, arg1);
}

void mmCullCity::RelightEverything()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x8D9A0_Offset, this);
}

void mmCullCity::ReparentObject(class mmInstance* arg1)
{
    return stub<thiscall_t<void, mmCullCity*, class mmInstance*>>(0x8C640_Offset, this, arg1);
}

void mmCullCity::Reset()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x8CDD0_Offset, this);
}

void mmCullCity::ToggleSky()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x8D950_Offset, this);
}

void mmCullCity::Update()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x8D5D0_Offset, this);
}

void mmCullCity::DeclareFields()
{
    return stub<cdecl_t<void>>(0x8F8C0_Offset);
}

class mmCullCity* mmCullCity::GetInstance()
{
    return stub<cdecl_t<class mmCullCity*>>(0xA9F40_Offset);
}

void mmCullCity::AddInstance(
    i32 arg1, char* arg2, char* arg3, i32 arg4, class Vector3* arg5, class Vector3* arg6, class Vector3* arg7, f32 arg8)
{
    return stub<
        thiscall_t<void, mmCullCity*, i32, char*, char*, i32, class Vector3*, class Vector3*, class Vector3*, f32>>(
        0x8C2C0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

void mmCullCity::InitSnowTextures()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x8D100_Offset, this);
}

void mmCullCity::InitTimeOfDayAndWeather()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x8DB10_Offset, this);
}

void mmCullCity::UpdateSnowTextures()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x8D2F0_Offset, this);
}

mmUpperInstance::~mmUpperInstance()
{
    unimplemented();
}

void __fastcall mmUpperInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmUpperInstance*, i32>>(0x8BF40_Offset, this, arg1);
}

mmRunwayLight::mmRunwayLight(char* arg1, class Vector3& arg2, class Vector3& arg3)
{
    unimplemented();
}

mmRunwayLight::~mmRunwayLight()
{
    unimplemented();
}

void mmRunwayLight::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmRunwayLight*, class Bank*>>(0x8FA40_Offset, this, arg1);
}

void __fastcall mmRunwayLight::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmRunwayLight*, i32>>(0x8C1B0_Offset, this, arg1);
}

void __fastcall mmRunwayLight::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, mmRunwayLight*, class Matrix34 const&>>(0x8C170_Offset, this, arg1);
}

class Vector3& __fastcall mmRunwayLight::GetPos()
{
    return stub<fastcall_t<class Vector3&, mmRunwayLight*>>(0x8C160_Offset, this);
}

f32 __fastcall mmRunwayLight::GetScale()
{
    return stub<fastcall_t<f32, mmRunwayLight*>>(0x8C2B0_Offset, this);
}

class Matrix34& __fastcall mmRunwayLight::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmRunwayLight*, class Matrix34&>>(0x8C180_Offset, this, arg1);
}

void fix_clip()
{
    return stub<cdecl_t<void>>(0x8DA00_Offset);
}

void fix_fog()
{
    return stub<cdecl_t<void>>(0x8E450_Offset);
}

void fix_lighting()
{
    return stub<cdecl_t<void>>(0x8DA70_Offset);
}

void fix_shadow()
{
    return stub<cdecl_t<void>>(0x8E480_Offset);
}

mmBangerManager::~mmBangerManager()
{
    unimplemented();
}

class mmHitBangerInstance* mmBangerManager::GetBanger()
{
    return stub<thiscall_t<class mmHitBangerInstance*, mmBangerManager*>>(0xCAC70_Offset, this);
}

void mmBangerManager::Init(i32 arg1)
{
    return stub<thiscall_t<void, mmBangerManager*, i32>>(0xCACD0_Offset, this, arg1);
}

void mmBangerManager::Reset()
{
    return stub<thiscall_t<void, mmBangerManager*>>(0xCAD90_Offset, this);
}

define_dummy_symbol(mmcity_cullcity);
