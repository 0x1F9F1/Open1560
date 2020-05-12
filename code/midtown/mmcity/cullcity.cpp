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

define_dummy_symbol(mmcity_cullcity);

#include "cullcity.h"

mmCullCity::mmCullCity()
{
    unimplemented();
}

mmCullCity::~mmCullCity()
{
    unimplemented(arg1);
}

void mmCullCity::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmCullCity*, class Bank*>>(0x48E4B0, this, arg1);
}

void mmCullCity::Cull()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x48D820, this);
}

class MetaClass* mmCullCity::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmCullCity*>>(0x48FA30, this);
}

i16 mmCullCity::GetHitId(class Vector3& arg1)
{
    return stub<thiscall_t<i16, mmCullCity*, class Vector3&>>(0x48BF10, this, arg1);
}

i16 mmCullCity::GetRoomFlags(i16 arg1)
{
    return stub<thiscall_t<i16, mmCullCity*, i16>>(0x48D960, this, arg1);
}

void mmCullCity::Init(char* arg1, class asCamera* arg2)
{
    return stub<thiscall_t<void, mmCullCity*, char*, class asCamera*>>(0x48C6D0, this, arg1, arg2);
}

void mmCullCity::InitObjectDetail()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x48CEA0, this);
}

i32 mmCullCity::IsPolyWater(class mmPolygon* arg1)
{
    return stub<thiscall_t<i32, mmCullCity*, class mmPolygon*>>(0x48D590, this, arg1);
}

void mmCullCity::LoadBangers(char* arg1)
{
    return stub<thiscall_t<void, mmCullCity*, char*>>(0x48CED0, this, arg1);
}

void mmCullCity::LoadFacades(char* arg1)
{
    return stub<thiscall_t<void, mmCullCity*, char*>>(0x48CFF0, this, arg1);
}

void mmCullCity::RelightEverything()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x48D9A0, this);
}

void mmCullCity::ReparentObject(class mmInstance* arg1)
{
    return stub<thiscall_t<void, mmCullCity*, class mmInstance*>>(0x48C640, this, arg1);
}

void mmCullCity::Reset()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x48CDD0, this);
}

void mmCullCity::ToggleSky()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x48D950, this);
}

void mmCullCity::Update()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x48D5D0, this);
}

void mmCullCity::DeclareFields()
{
    return stub<cdecl_t<void>>(0x48F8C0);
}

class mmCullCity* mmCullCity::GetInstance()
{
    return stub<cdecl_t<class mmCullCity*>>(0x4A9F40);
}

void mmCullCity::AddInstance(
    i32 arg1, char* arg2, char* arg3, i32 arg4, class Vector3* arg5, class Vector3* arg6, class Vector3* arg7, f32 arg8)
{
    return stub<
        thiscall_t<void, mmCullCity*, i32, char*, char*, i32, class Vector3*, class Vector3*, class Vector3*, f32>>(
        0x48C2C0, this, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}

void mmCullCity::InitSnowTextures()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x48D100, this);
}

void mmCullCity::InitTimeOfDayAndWeather()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x48DB10, this);
}

void mmCullCity::UpdateSnowTextures()
{
    return stub<thiscall_t<void, mmCullCity*>>(0x48D2F0, this);
}

mmUpperInstance::~mmUpperInstance()
{
    unimplemented(arg1);
}

void __fastcall mmUpperInstance::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmUpperInstance*, i32>>(0x48BF40, this, arg1);
}

mmRunwayLight::mmRunwayLight(char* arg1, class Vector3& arg2, class Vector3& arg3)
{
    unimplemented(arg1, arg2, arg3);
}

mmRunwayLight::~mmRunwayLight()
{
    unimplemented(arg1);
}

void mmRunwayLight::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, mmRunwayLight*, class Bank*>>(0x48FA40, this, arg1);
}

void __fastcall mmRunwayLight::Draw(i32 arg1)
{
    return stub<fastcall_t<void, mmRunwayLight*, i32>>(0x48C1B0, this, arg1);
}

void __fastcall mmRunwayLight::FromMatrix(class Matrix34 const& arg1)
{
    return stub<fastcall_t<void, mmRunwayLight*, class Matrix34 const&>>(0x48C170, this, arg1);
}

class Vector3& __fastcall mmRunwayLight::GetPos()
{
    return stub<fastcall_t<class Vector3&, mmRunwayLight*>>(0x48C160, this);
}

f32 __fastcall mmRunwayLight::GetScale()
{
    return stub<fastcall_t<f32, mmRunwayLight*>>(0x48C2B0, this);
}

class Matrix34& __fastcall mmRunwayLight::ToMatrix(class Matrix34& arg1)
{
    return stub<fastcall_t<class Matrix34&, mmRunwayLight*, class Matrix34&>>(0x48C180, this, arg1);
}

void fix_clip()
{
    return stub<cdecl_t<void>>(0x48DA00);
}

void fix_fog()
{
    return stub<cdecl_t<void>>(0x48E450);
}

void fix_lighting()
{
    return stub<cdecl_t<void>>(0x48DA70);
}

void fix_shadow()
{
    return stub<cdecl_t<void>>(0x48E480);
}

static void fix_fill1()
{
    return stub<cdecl_t<void>>(0x48E220);
}

static void fix_fill2()
{
    return stub<cdecl_t<void>>(0x48E290);
}

static void fix_sun()
{
    return stub<cdecl_t<void>>(0x48E1B0);
}

static void parseARGB(u32& arg1)
{
    return stub<cdecl_t<void, u32&>>(0x48E3D0, arg1);
}

static void parseFloat(f32& arg1)
{
    return stub<cdecl_t<void, f32&>>(0x48E300, arg1);
}

static void parseRGB(u32& arg1)
{
    return stub<cdecl_t<void, u32&>>(0x48E360, arg1);
}

static void parseVector3(class Vector3& arg1)
{
    return stub<cdecl_t<void, class Vector3&>>(0x48E330, arg1);
}

mmBangerManager::~mmBangerManager()
{
    unimplemented(arg1);
}

class mmHitBangerInstance* mmBangerManager::GetBanger()
{
    return stub<thiscall_t<class mmHitBangerInstance*, mmBangerManager*>>(0x4CAC70, this);
}

void mmBangerManager::Init(i32 arg1)
{
    return stub<thiscall_t<void, mmBangerManager*, i32>>(0x4CACD0, this, arg1);
}

void mmBangerManager::Reset()
{
    return stub<thiscall_t<void, mmBangerManager*>>(0x4CAD90, this);
}
