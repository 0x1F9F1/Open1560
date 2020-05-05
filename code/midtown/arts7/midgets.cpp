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

define_dummy_symbol(arts7_midgets);

#include "midgets.h"

asMidgets::asMidgets()
{
    unimplemented();
}

asMidgets::~asMidgets()
{
    unimplemented(arg1);
}

class bkButton* asMidgets::AddButton(char* arg1, class Callback arg2)
{
    return stub<thiscall_t<class bkButton*, asMidgets*, char*, class Callback>>(0x127020_Offset, this, arg1, arg2);
}

void asMidgets::AddColor(char* arg1, class Vector3* arg2, class Callback arg3)
{
    return stub<thiscall_t<void, asMidgets*, char*, class Vector3*, class Callback>>(
        0x1278B0_Offset, this, arg1, arg2, arg3);
}

void asMidgets::AddColor(char* arg1, class Vector4* arg2, class Callback arg3)
{
    return stub<thiscall_t<void, asMidgets*, char*, class Vector4*, class Callback>>(
        0x127990_Offset, this, arg1, arg2, arg3);
}

void asMidgets::AddFileButton(char* arg1, class Callback arg2)
{
    return stub<thiscall_t<void, asMidgets*, char*, class Callback>>(0x127AB0_Offset, this, arg1, arg2);
}

class bkButton* asMidgets::AddMex(char* arg1, i32* arg2, i32 arg3, class Callback arg4)
{
    return stub<thiscall_t<class bkButton*, asMidgets*, char*, i32*, i32, class Callback>>(
        0x127110_Offset, this, arg1, arg2, arg3, arg4);
}

class bkSlider* asMidgets::AddSlider(char* arg1, char* arg2, char arg3, char arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, asMidgets*, char*, char*, char, char, f32, class Callback>>(
        0x1271F0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* asMidgets::AddSlider(char* arg1, f32* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, asMidgets*, char*, f32*, f32, f32, f32, class Callback>>(
        0x127550_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* asMidgets::AddSlider(char* arg1, i16* arg2, i16 arg3, i16 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, asMidgets*, char*, i16*, i16, i16, f32, class Callback>>(
        0x127310_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* asMidgets::AddSlider(char* arg1, i32* arg2, i32 arg3, i32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, asMidgets*, char*, i32*, i32, i32, f32, class Callback>>(
        0x127430_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* asMidgets::AddSlider(char* arg1, u16* arg2, u16 arg3, u16 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, asMidgets*, char*, u16*, u16, u16, f32, class Callback>>(
        0x1273A0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* asMidgets::AddSlider(char* arg1, u32* arg2, u32 arg3, u32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, asMidgets*, char*, u32*, u32, u32, f32, class Callback>>(
        0x1274C0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* asMidgets::AddSlider(char* arg1, u8* arg2, u8 arg3, u8 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, asMidgets*, char*, u8*, u8, u8, f32, class Callback>>(
        0x127280_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkButton* asMidgets::AddText(class Callback arg1)
{
    return stub<thiscall_t<class bkButton*, asMidgets*, class Callback>>(0x127190_Offset, this, arg1);
}

class bkButton* asMidgets::AddText(char* arg1, class Callback arg2)
{
    return stub<thiscall_t<class bkButton*, asMidgets*, char*, class Callback>>(0x1271C0_Offset, this, arg1, arg2);
}

class bkSlider* asMidgets::AddTextSlider(char* arg1, char* arg2, i32* arg3, f32 arg4, class Callback arg5)
{
    return stub<thiscall_t<class bkSlider*, asMidgets*, char*, char*, i32*, f32, class Callback>>(
        0x1275E0_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

class bkWindow* asMidgets::AddTitle(char* arg1)
{
    return stub<thiscall_t<class bkWindow*, asMidgets*, char*>>(0x126FC0_Offset, this, arg1);
}

class bkButton* asMidgets::AddToggle(char* arg1, i32* arg2, i32 arg3, class Callback arg4)
{
    return stub<thiscall_t<class bkButton*, asMidgets*, char*, i32*, i32, class Callback>>(
        0x127090_Offset, this, arg1, arg2, arg3, arg4);
}

void asMidgets::AddVector(char* arg1, class Vector2* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<void, asMidgets*, char*, class Vector2*, f32, f32, f32, class Callback>>(
        0x127610_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void asMidgets::AddVector(char* arg1, class Vector3* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<void, asMidgets*, char*, class Vector3*, f32, f32, f32, class Callback>>(
        0x1276B0_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void asMidgets::AddVector(char* arg1, class Vector4* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<void, asMidgets*, char*, class Vector4*, f32, f32, f32, class Callback>>(
        0x127790_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void asMidgets::Cull()
{
    return stub<thiscall_t<void, asMidgets*>>(0x126ED0_Offset, this);
}

void asMidgets::Off()
{
    return stub<thiscall_t<void, asMidgets*>>(0x126900_Offset, this);
}

void asMidgets::Open(class asNode* arg1)
{
    return stub<thiscall_t<void, asMidgets*, class asNode*>>(0x126950_Offset, this, arg1);
}

void asMidgets::PopColumn()
{
    return stub<thiscall_t<void, asMidgets*>>(0x127B90_Offset, this);
}

void asMidgets::PopSection()
{
    return stub<thiscall_t<void, asMidgets*>>(0x127B50_Offset, this);
}

void asMidgets::PushColumn(i32 arg1)
{
    return stub<thiscall_t<void, asMidgets*, i32>>(0x127B80_Offset, this, arg1);
}

void asMidgets::PushSection(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, asMidgets*, char*, i32>>(0x127AE0_Offset, this, arg1, arg2);
}

void asMidgets::SetLabel(char* arg1)
{
    return stub<thiscall_t<void, asMidgets*, char*>>(0x126E40_Offset, this, arg1);
}

void asMidgets::Toggle()
{
    return stub<thiscall_t<void, asMidgets*>>(0x126B60_Offset, this);
}

void asMidgets::Update()
{
    return stub<thiscall_t<void, asMidgets*>>(0x126B80_Offset, this);
}

void asMidgets::UpdateKey(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, asMidgets*, i32, i32>>(0x126BF0_Offset, this, arg1, arg2);
}

void asMidgets::AddItem(class MI* arg1)
{
    return stub<thiscall_t<void, asMidgets*, class MI*>>(0x126E50_Offset, this, arg1);
}

i32 asMidgets::IsVisible(i32 arg1)
{
    return stub<thiscall_t<i32, asMidgets*, i32>>(0x126E90_Offset, this, arg1);
}

void SMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, SMI*, i32, i32>>(0x127BD0_Offset, this, arg1, arg2);
}

i32 SMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, SMI*, i32>>(0x127BE0_Offset, this, arg1);
}

void BMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, BMI*, i32, i32>>(0x127C00_Offset, this, arg1, arg2);
}

i32 BMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, BMI*, i32>>(0x127C20_Offset, this, arg1);
}

void TMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, TMI*, i32, i32>>(0x127C40_Offset, this, arg1, arg2);
}

i32 TMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, TMI*, i32>>(0x127CA0_Offset, this, arg1);
}

void scharMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, scharMI*, i32, i32>>(0x127CF0_Offset, this, arg1, arg2);
}

i32 scharMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, scharMI*, i32>>(0x127D80_Offset, this, arg1);
}

void ucharMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, ucharMI*, i32, i32>>(0x127DD0_Offset, this, arg1, arg2);
}

i32 ucharMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, ucharMI*, i32>>(0x127E60_Offset, this, arg1);
}

void shortMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, shortMI*, i32, i32>>(0x127EB0_Offset, this, arg1, arg2);
}

i32 shortMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, shortMI*, i32>>(0x127F50_Offset, this, arg1);
}

void ushortMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, ushortMI*, i32, i32>>(0x127FA0_Offset, this, arg1, arg2);
}

i32 ushortMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, ushortMI*, i32>>(0x128040_Offset, this, arg1);
}

void intMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, intMI*, i32, i32>>(0x128090_Offset, this, arg1, arg2);
}

i32 intMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, intMI*, i32>>(0x128120_Offset, this, arg1);
}

void uintMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, uintMI*, i32, i32>>(0x128170_Offset, this, arg1, arg2);
}

i32 uintMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, uintMI*, i32>>(0x128210_Offset, this, arg1);
}

void floatMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, floatMI*, i32, i32>>(0x128260_Offset, this, arg1, arg2);
}

i32 floatMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, floatMI*, i32>>(0x1282F0_Offset, this, arg1);
}

void SBMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, SBMI*, i32, i32>>(0x128340_Offset, this, arg1, arg2);
}

i32 SBMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, SBMI*, i32>>(0x128360_Offset, this, arg1);
}

void Bank::SetLabel(char* arg1)
{
    return stub<thiscall_t<void, Bank*, char*>>(0x - 400000_Offset, this, arg1);
}

class bkWindow* Bank::AddTitle(char* arg1)
{
    return stub<thiscall_t<class bkWindow*, Bank*, char*>>(0x - 400000_Offset, this, arg1);
}

class bkButton* Bank::AddButton(char* arg1, class Callback arg2)
{
    return stub<thiscall_t<class bkButton*, Bank*, char*, class Callback>>(0x - 400000_Offset, this, arg1, arg2);
}

class bkButton* Bank::AddToggle(char* arg1, i32* arg2, i32 arg3, class Callback arg4)
{
    return stub<thiscall_t<class bkButton*, Bank*, char*, i32*, i32, class Callback>>(
        0x - 400000_Offset, this, arg1, arg2, arg3, arg4);
}

class bkButton* Bank::AddMex(char* arg1, i32* arg2, i32 arg3, class Callback arg4)
{
    return stub<thiscall_t<class bkButton*, Bank*, char*, i32*, i32, class Callback>>(
        0x - 400000_Offset, this, arg1, arg2, arg3, arg4);
}

class bkButton* Bank::AddText(char* arg1, class Callback arg2)
{
    return stub<thiscall_t<class bkButton*, Bank*, char*, class Callback>>(0x - 400000_Offset, this, arg1, arg2);
}

class bkButton* Bank::AddText(class Callback arg1)
{
    return stub<thiscall_t<class bkButton*, Bank*, class Callback>>(0x - 400000_Offset, this, arg1);
}

class bkSlider* Bank::AddSlider(char* arg1, f32* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, Bank*, char*, f32*, f32, f32, f32, class Callback>>(
        0x - 400000_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* Bank::AddSlider(char* arg1, u32* arg2, u32 arg3, u32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, Bank*, char*, u32*, u32, u32, f32, class Callback>>(
        0x - 400000_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* Bank::AddSlider(char* arg1, i32* arg2, i32 arg3, i32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, Bank*, char*, i32*, i32, i32, f32, class Callback>>(
        0x - 400000_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* Bank::AddSlider(char* arg1, u16* arg2, u16 arg3, u16 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, Bank*, char*, u16*, u16, u16, f32, class Callback>>(
        0x - 400000_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* Bank::AddSlider(char* arg1, i16* arg2, i16 arg3, i16 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, Bank*, char*, i16*, i16, i16, f32, class Callback>>(
        0x - 400000_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* Bank::AddSlider(char* arg1, u8* arg2, u8 arg3, u8 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, Bank*, char*, u8*, u8, u8, f32, class Callback>>(
        0x - 400000_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* Bank::AddSlider(char* arg1, char* arg2, char arg3, char arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, Bank*, char*, char*, char, char, f32, class Callback>>(
        0x - 400000_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* Bank::AddTextSlider(char* arg1, char* arg2, i32* arg3, f32 arg4, class Callback arg5)
{
    return stub<thiscall_t<class bkSlider*, Bank*, char*, char*, i32*, f32, class Callback>>(
        0x - 400000_Offset, this, arg1, arg2, arg3, arg4, arg5);
}

void Bank::AddVector(char* arg1, class Vector4* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<void, Bank*, char*, class Vector4*, f32, f32, f32, class Callback>>(
        0x - 400000_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void Bank::AddVector(char* arg1, class Vector3* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<void, Bank*, char*, class Vector3*, f32, f32, f32, class Callback>>(
        0x - 400000_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void Bank::AddVector(char* arg1, class Vector2* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<void, Bank*, char*, class Vector2*, f32, f32, f32, class Callback>>(
        0x - 400000_Offset, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void Bank::AddColor(char* arg1, class Vector4* arg2, class Callback arg3)
{
    return stub<thiscall_t<void, Bank*, char*, class Vector4*, class Callback>>(
        0x - 400000_Offset, this, arg1, arg2, arg3);
}

void Bank::AddColor(char* arg1, class Vector3* arg2, class Callback arg3)
{
    return stub<thiscall_t<void, Bank*, char*, class Vector3*, class Callback>>(
        0x - 400000_Offset, this, arg1, arg2, arg3);
}

void Bank::AddFileButton(char* arg1, class Callback arg2)
{
    return stub<thiscall_t<void, Bank*, char*, class Callback>>(0x - 400000_Offset, this, arg1, arg2);
}

void Bank::PushSection(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, Bank*, char*, i32>>(0x - 400000_Offset, this, arg1, arg2);
}

void Bank::PopSection()
{
    return stub<thiscall_t<void, Bank*>>(0x - 400000_Offset, this);
}

void Bank::PushColumn(i32 arg1)
{
    return stub<thiscall_t<void, Bank*, i32>>(0x - 400000_Offset, this, arg1);
}

void Bank::PopColumn()
{
    return stub<thiscall_t<void, Bank*>>(0x - 400000_Offset, this);
}

void Bank::Off()
{
    return stub<thiscall_t<void, Bank*>>(0x - 400000_Offset, this);
}

i32 MI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, MI*, i32>>(0x - 400000_Offset, this, arg1);
}

void MI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, MI*, i32, i32>>(0x - 400000_Offset, this, arg1, arg2);
}
