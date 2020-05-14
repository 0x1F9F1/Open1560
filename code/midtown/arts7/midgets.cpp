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
    unimplemented();
}

class bkButton* asMidgets::AddButton(char* arg1, class Callback arg2)
{
    return stub<thiscall_t<class bkButton*, asMidgets*, char*, class Callback>>(0x527020, this, arg1, arg2);
}

void asMidgets::AddColor(char* arg1, class Vector3* arg2, class Callback arg3)
{
    return stub<thiscall_t<void, asMidgets*, char*, class Vector3*, class Callback>>(0x5278B0, this, arg1, arg2, arg3);
}

void asMidgets::AddColor(char* arg1, class Vector4* arg2, class Callback arg3)
{
    return stub<thiscall_t<void, asMidgets*, char*, class Vector4*, class Callback>>(0x527990, this, arg1, arg2, arg3);
}

void asMidgets::AddFileButton(char* arg1, class Callback arg2)
{
    return stub<thiscall_t<void, asMidgets*, char*, class Callback>>(0x527AB0, this, arg1, arg2);
}

class bkButton* asMidgets::AddMex(char* arg1, i32* arg2, i32 arg3, class Callback arg4)
{
    return stub<thiscall_t<class bkButton*, asMidgets*, char*, i32*, i32, class Callback>>(
        0x527110, this, arg1, arg2, arg3, arg4);
}

class bkSlider* asMidgets::AddSlider(char* arg1, char* arg2, char arg3, char arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, asMidgets*, char*, char*, char, char, f32, class Callback>>(
        0x5271F0, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* asMidgets::AddSlider(char* arg1, f32* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, asMidgets*, char*, f32*, f32, f32, f32, class Callback>>(
        0x527550, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* asMidgets::AddSlider(char* arg1, i16* arg2, i16 arg3, i16 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, asMidgets*, char*, i16*, i16, i16, f32, class Callback>>(
        0x527310, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* asMidgets::AddSlider(char* arg1, i32* arg2, i32 arg3, i32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, asMidgets*, char*, i32*, i32, i32, f32, class Callback>>(
        0x527430, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* asMidgets::AddSlider(char* arg1, u16* arg2, u16 arg3, u16 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, asMidgets*, char*, u16*, u16, u16, f32, class Callback>>(
        0x5273A0, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* asMidgets::AddSlider(char* arg1, u32* arg2, u32 arg3, u32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, asMidgets*, char*, u32*, u32, u32, f32, class Callback>>(
        0x5274C0, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkSlider* asMidgets::AddSlider(char* arg1, u8* arg2, u8 arg3, u8 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<class bkSlider*, asMidgets*, char*, u8*, u8, u8, f32, class Callback>>(
        0x527280, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

class bkButton* asMidgets::AddText(class Callback arg1)
{
    return stub<thiscall_t<class bkButton*, asMidgets*, class Callback>>(0x527190, this, arg1);
}

class bkButton* asMidgets::AddText(char* arg1, class Callback arg2)
{
    return stub<thiscall_t<class bkButton*, asMidgets*, char*, class Callback>>(0x5271C0, this, arg1, arg2);
}

class bkSlider* asMidgets::AddTextSlider(char* arg1, char* arg2, i32* arg3, f32 arg4, class Callback arg5)
{
    return stub<thiscall_t<class bkSlider*, asMidgets*, char*, char*, i32*, f32, class Callback>>(
        0x5275E0, this, arg1, arg2, arg3, arg4, arg5);
}

class bkWindow* asMidgets::AddTitle(char* arg1)
{
    return stub<thiscall_t<class bkWindow*, asMidgets*, char*>>(0x526FC0, this, arg1);
}

class bkButton* asMidgets::AddToggle(char* arg1, i32* arg2, i32 arg3, class Callback arg4)
{
    return stub<thiscall_t<class bkButton*, asMidgets*, char*, i32*, i32, class Callback>>(
        0x527090, this, arg1, arg2, arg3, arg4);
}

void asMidgets::AddVector(char* arg1, class Vector2* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<void, asMidgets*, char*, class Vector2*, f32, f32, f32, class Callback>>(
        0x527610, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void asMidgets::AddVector(char* arg1, class Vector3* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<void, asMidgets*, char*, class Vector3*, f32, f32, f32, class Callback>>(
        0x5276B0, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void asMidgets::AddVector(char* arg1, class Vector4* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6)
{
    return stub<thiscall_t<void, asMidgets*, char*, class Vector4*, f32, f32, f32, class Callback>>(
        0x527790, this, arg1, arg2, arg3, arg4, arg5, arg6);
}

void asMidgets::Cull()
{
    return stub<thiscall_t<void, asMidgets*>>(0x526ED0, this);
}

void asMidgets::Off()
{
    return stub<thiscall_t<void, asMidgets*>>(0x526900, this);
}

void asMidgets::Open(class asNode* arg1)
{
    return stub<thiscall_t<void, asMidgets*, class asNode*>>(0x526950, this, arg1);
}

void asMidgets::PopColumn()
{
    return stub<thiscall_t<void, asMidgets*>>(0x527B90, this);
}

void asMidgets::PopSection()
{
    return stub<thiscall_t<void, asMidgets*>>(0x527B50, this);
}

void asMidgets::PushColumn(i32 arg1)
{
    return stub<thiscall_t<void, asMidgets*, i32>>(0x527B80, this, arg1);
}

void asMidgets::PushSection(char* arg1, i32 arg2)
{
    return stub<thiscall_t<void, asMidgets*, char*, i32>>(0x527AE0, this, arg1, arg2);
}

void asMidgets::SetLabel(char* arg1)
{
    return stub<thiscall_t<void, asMidgets*, char*>>(0x526E40, this, arg1);
}

void asMidgets::Toggle()
{
    return stub<thiscall_t<void, asMidgets*>>(0x526B60, this);
}

void asMidgets::Update()
{
    return stub<thiscall_t<void, asMidgets*>>(0x526B80, this);
}

void asMidgets::UpdateKey(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, asMidgets*, i32, i32>>(0x526BF0, this, arg1, arg2);
}

void asMidgets::AddItem(class MI* arg1)
{
    return stub<thiscall_t<void, asMidgets*, class MI*>>(0x526E50, this, arg1);
}

i32 asMidgets::IsVisible(i32 arg1)
{
    return stub<thiscall_t<i32, asMidgets*, i32>>(0x526E90, this, arg1);
}

void SMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, SMI*, i32, i32>>(0x527BD0, this, arg1, arg2);
}

i32 SMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, SMI*, i32>>(0x527BE0, this, arg1);
}

void BMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, BMI*, i32, i32>>(0x527C00, this, arg1, arg2);
}

i32 BMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, BMI*, i32>>(0x527C20, this, arg1);
}

void TMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, TMI*, i32, i32>>(0x527C40, this, arg1, arg2);
}

i32 TMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, TMI*, i32>>(0x527CA0, this, arg1);
}

void scharMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, scharMI*, i32, i32>>(0x527CF0, this, arg1, arg2);
}

i32 scharMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, scharMI*, i32>>(0x527D80, this, arg1);
}

void ucharMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, ucharMI*, i32, i32>>(0x527DD0, this, arg1, arg2);
}

i32 ucharMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, ucharMI*, i32>>(0x527E60, this, arg1);
}

void shortMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, shortMI*, i32, i32>>(0x527EB0, this, arg1, arg2);
}

i32 shortMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, shortMI*, i32>>(0x527F50, this, arg1);
}

void ushortMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, ushortMI*, i32, i32>>(0x527FA0, this, arg1, arg2);
}

i32 ushortMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, ushortMI*, i32>>(0x528040, this, arg1);
}

void intMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, intMI*, i32, i32>>(0x528090, this, arg1, arg2);
}

i32 intMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, intMI*, i32>>(0x528120, this, arg1);
}

void uintMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, uintMI*, i32, i32>>(0x528170, this, arg1, arg2);
}

i32 uintMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, uintMI*, i32>>(0x528210, this, arg1);
}

void floatMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, floatMI*, i32, i32>>(0x528260, this, arg1, arg2);
}

i32 floatMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, floatMI*, i32>>(0x5282F0, this, arg1);
}

void SBMI::Key(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<void, SBMI*, i32, i32>>(0x528340, this, arg1, arg2);
}

i32 SBMI::Update(i32 arg1)
{
    return stub<thiscall_t<i32, SBMI*, i32>>(0x528360, this, arg1);
}
