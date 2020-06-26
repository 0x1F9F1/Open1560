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
    arts7:midgets

    0x5267F0 | public: __thiscall asMidgets::asMidgets(void) | ??0asMidgets@@QAE@XZ
    0x526890 | public: virtual __thiscall asMidgets::~asMidgets(void) | ??1asMidgets@@UAE@XZ
    0x526900 | public: virtual void __thiscall asMidgets::Off(void) | ?Off@asMidgets@@UAEXXZ
    0x526950 | public: void __thiscall asMidgets::Open(class asNode *) | ?Open@asMidgets@@QAEXPAVasNode@@@Z
    0x526B60 | public: void __thiscall asMidgets::Toggle(void) | ?Toggle@asMidgets@@QAEXXZ
    0x526B80 | public: void __thiscall asMidgets::Update(void) | ?Update@asMidgets@@QAEXXZ
    0x526BF0 | public: void __thiscall asMidgets::UpdateKey(int,int) | ?UpdateKey@asMidgets@@QAEXHH@Z
    0x526E40 | public: virtual void __thiscall asMidgets::SetLabel(char *) | ?SetLabel@asMidgets@@UAEXPAD@Z
    0x526E50 | private: void __thiscall asMidgets::AddItem(class MI *) | ?AddItem@asMidgets@@AAEXPAVMI@@@Z
    0x526E90 | private: int __thiscall asMidgets::IsVisible(int) | ?IsVisible@asMidgets@@AAEHH@Z
    0x526ED0 | public: virtual void __thiscall asMidgets::Cull(void) | ?Cull@asMidgets@@UAEXXZ
    0x526FC0 | public: virtual class bkWindow * __thiscall asMidgets::AddTitle(char *) | ?AddTitle@asMidgets@@UAEPAVbkWindow@@PAD@Z
    0x527020 | public: virtual class bkButton * __thiscall asMidgets::AddButton(char *,class Callback) | ?AddButton@asMidgets@@UAEPAVbkButton@@PADVCallback@@@Z
    0x527090 | public: virtual class bkButton * __thiscall asMidgets::AddToggle(char *,int *,int,class Callback) | ?AddToggle@asMidgets@@UAEPAVbkButton@@PADPAHHVCallback@@@Z
    0x527110 | public: virtual class bkButton * __thiscall asMidgets::AddMex(char *,int *,int,class Callback) | ?AddMex@asMidgets@@UAEPAVbkButton@@PADPAHHVCallback@@@Z
    0x527190 | public: virtual class bkButton * __thiscall asMidgets::AddText(class Callback) | ?AddText@asMidgets@@UAEPAVbkButton@@VCallback@@@Z
    0x5271C0 | public: virtual class bkButton * __thiscall asMidgets::AddText(char *,class Callback) | ?AddText@asMidgets@@UAEPAVbkButton@@PADVCallback@@@Z
    0x5271F0 | public: virtual class bkSlider * __thiscall asMidgets::AddSlider(char *,char *,char,char,float,class Callback) | ?AddSlider@asMidgets@@UAEPAVbkSlider@@PAD0DDMVCallback@@@Z
    0x527280 | public: virtual class bkSlider * __thiscall asMidgets::AddSlider(char *,unsigned char *,unsigned char,unsigned char,float,class Callback) | ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAEEEMVCallback@@@Z
    0x527310 | public: virtual class bkSlider * __thiscall asMidgets::AddSlider(char *,short *,short,short,float,class Callback) | ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAFFFMVCallback@@@Z
    0x5273A0 | public: virtual class bkSlider * __thiscall asMidgets::AddSlider(char *,unsigned short *,unsigned short,unsigned short,float,class Callback) | ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAGGGMVCallback@@@Z
    0x527430 | public: virtual class bkSlider * __thiscall asMidgets::AddSlider(char *,int *,int,int,float,class Callback) | ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAHHHMVCallback@@@Z
    0x5274C0 | public: virtual class bkSlider * __thiscall asMidgets::AddSlider(char *,unsigned int *,unsigned int,unsigned int,float,class Callback) | ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAIIIMVCallback@@@Z
    0x527550 | public: virtual class bkSlider * __thiscall asMidgets::AddSlider(char *,float *,float,float,float,class Callback) | ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAMMMMVCallback@@@Z
    0x5275E0 | public: virtual class bkSlider * __thiscall asMidgets::AddTextSlider(char *,char *,int *,float,class Callback) | ?AddTextSlider@asMidgets@@UAEPAVbkSlider@@PAD0PAHMVCallback@@@Z
    0x527610 | public: virtual void __thiscall asMidgets::AddVector(char *,class Vector2 *,float,float,float,class Callback) | ?AddVector@asMidgets@@UAEXPADPAVVector2@@MMMVCallback@@@Z
    0x5276B0 | public: virtual void __thiscall asMidgets::AddVector(char *,class Vector3 *,float,float,float,class Callback) | ?AddVector@asMidgets@@UAEXPADPAVVector3@@MMMVCallback@@@Z
    0x527790 | public: virtual void __thiscall asMidgets::AddVector(char *,class Vector4 *,float,float,float,class Callback) | ?AddVector@asMidgets@@UAEXPADPAVVector4@@MMMVCallback@@@Z
    0x5278B0 | public: virtual void __thiscall asMidgets::AddColor(char *,class Vector3 *,class Callback) | ?AddColor@asMidgets@@UAEXPADPAVVector3@@VCallback@@@Z
    0x527990 | public: virtual void __thiscall asMidgets::AddColor(char *,class Vector4 *,class Callback) | ?AddColor@asMidgets@@UAEXPADPAVVector4@@VCallback@@@Z
    0x527AB0 | public: virtual void __thiscall asMidgets::AddFileButton(char *,class Callback) | ?AddFileButton@asMidgets@@UAEXPADVCallback@@@Z
    0x527AE0 | public: virtual void __thiscall asMidgets::PushSection(char *,int) | ?PushSection@asMidgets@@UAEXPADH@Z
    0x527B50 | public: virtual void __thiscall asMidgets::PopSection(void) | ?PopSection@asMidgets@@UAEXXZ
    0x527B80 | public: virtual void __thiscall asMidgets::PushColumn(int) | ?PushColumn@asMidgets@@UAEXH@Z
    0x527B90 | public: virtual void __thiscall asMidgets::PopColumn(void) | ?PopColumn@asMidgets@@UAEXXZ
    0x527BA0 | public: virtual void * __thiscall asMidgets::`vector deleting destructor'(unsigned int) | ??_EasMidgets@@UAEPAXI@Z
    0x527BA0 | public: virtual void * __thiscall asMidgets::`scalar deleting destructor'(unsigned int) | ??_GasMidgets@@UAEPAXI@Z
    0x527BD0 | public: virtual void __thiscall SMI::Key(int,int) | ?Key@SMI@@UAEXHH@Z
    0x527BE0 | public: virtual int __thiscall SMI::Update(int) | ?Update@SMI@@UAEHH@Z
    0x527C00 | public: virtual void __thiscall BMI::Key(int,int) | ?Key@BMI@@UAEXHH@Z
    0x527C20 | public: virtual int __thiscall BMI::Update(int) | ?Update@BMI@@UAEHH@Z
    0x527C40 | public: virtual void __thiscall TMI::Key(int,int) | ?Key@TMI@@UAEXHH@Z
    0x527CA0 | public: virtual int __thiscall TMI::Update(int) | ?Update@TMI@@UAEHH@Z
    0x527CF0 | public: virtual void __thiscall scharMI::Key(int,int) | ?Key@scharMI@@UAEXHH@Z
    0x527D80 | public: virtual int __thiscall scharMI::Update(int) | ?Update@scharMI@@UAEHH@Z
    0x527DD0 | public: virtual void __thiscall ucharMI::Key(int,int) | ?Key@ucharMI@@UAEXHH@Z
    0x527E60 | public: virtual int __thiscall ucharMI::Update(int) | ?Update@ucharMI@@UAEHH@Z
    0x527EB0 | public: virtual void __thiscall shortMI::Key(int,int) | ?Key@shortMI@@UAEXHH@Z
    0x527F50 | public: virtual int __thiscall shortMI::Update(int) | ?Update@shortMI@@UAEHH@Z
    0x527FA0 | public: virtual void __thiscall ushortMI::Key(int,int) | ?Key@ushortMI@@UAEXHH@Z
    0x528040 | public: virtual int __thiscall ushortMI::Update(int) | ?Update@ushortMI@@UAEHH@Z
    0x528090 | public: virtual void __thiscall intMI::Key(int,int) | ?Key@intMI@@UAEXHH@Z
    0x528120 | public: virtual int __thiscall intMI::Update(int) | ?Update@intMI@@UAEHH@Z
    0x528170 | public: virtual void __thiscall uintMI::Key(int,int) | ?Key@uintMI@@UAEXHH@Z
    0x528210 | public: virtual int __thiscall uintMI::Update(int) | ?Update@uintMI@@UAEHH@Z
    0x528260 | public: virtual void __thiscall floatMI::Key(int,int) | ?Key@floatMI@@UAEXHH@Z
    0x5282F0 | public: virtual int __thiscall floatMI::Update(int) | ?Update@floatMI@@UAEHH@Z
    0x528340 | public: virtual void __thiscall SBMI::Key(int,int) | ?Key@SBMI@@UAEXHH@Z
    0x528360 | public: virtual int __thiscall SBMI::Update(int) | ?Update@SBMI@@UAEHH@Z
    0x620BC0 | const asMidgets::`vftable'{for `asCullable'} | ??_7asMidgets@@6BasCullable@@@
    0x620BD8 | const asMidgets::`vftable'{for `Bank'} | ??_7asMidgets@@6BBank@@@
    0x620C40 | const Bank::`vftable' | ??_7Bank@@6B@
    0x620CA8 | const MI::`vftable' | ??_7MI@@6B@
    0x620CB0 | const SMI::`vftable' | ??_7SMI@@6B@
    0x620CB8 | const BMI::`vftable' | ??_7BMI@@6B@
    0x620CC0 | const TMI::`vftable' | ??_7TMI@@6B@
    0x620CC8 | const scharMI::`vftable' | ??_7scharMI@@6B@
    0x620CD8 | const ucharMI::`vftable' | ??_7ucharMI@@6B@
    0x620CE0 | const shortMI::`vftable' | ??_7shortMI@@6B@
    0x620CE8 | const ushortMI::`vftable' | ??_7ushortMI@@6B@
    0x620CF0 | const intMI::`vftable' | ??_7intMI@@6B@
    0x620CF8 | const uintMI::`vftable' | ??_7uintMI@@6B@
    0x620D00 | const floatMI::`vftable' | ??_7floatMI@@6B@
    0x620D08 | const SBMI::`vftable' | ??_7SBMI@@6B@
    0x790928 | class asMidgets * MIDGETSPTR | ?MIDGETSPTR@@3PAVasMidgets@@A
*/

#include "bank.h"
#include "cullable.h"

class asMidgets
    : public Bank
    , public asCullable /* Warning: Unordered Multiple Inheritance */
{
    // const asMidgets::`vftable'{for `asCullable'} @ 0x620BC0
    // const asMidgets::`vftable'{for `Bank'} @ 0x620BD8

public:
    // 0x5267F0 | ??0asMidgets@@QAE@XZ
    ARTS_IMPORT asMidgets();

    // 0x527BA0 | ??_GasMidgets@@UAEPAXI@Z
    // 0x526890 | ??1asMidgets@@UAE@XZ
    ARTS_IMPORT ~asMidgets() override;

    // 0x527020 | ?AddButton@asMidgets@@UAEPAVbkButton@@PADVCallback@@@Z
    ARTS_IMPORT class bkButton* AddButton(char* arg1, class Callback arg2) override;

    // 0x5278B0 | ?AddColor@asMidgets@@UAEXPADPAVVector3@@VCallback@@@Z
    ARTS_IMPORT void AddColor(char* arg1, class Vector3* arg2, class Callback arg3) override;

    // 0x527990 | ?AddColor@asMidgets@@UAEXPADPAVVector4@@VCallback@@@Z
    ARTS_IMPORT void AddColor(char* arg1, class Vector4* arg2, class Callback arg3) override;

    // 0x527AB0 | ?AddFileButton@asMidgets@@UAEXPADVCallback@@@Z
    ARTS_IMPORT void AddFileButton(char* arg1, class Callback arg2) override;

    // 0x527110 | ?AddMex@asMidgets@@UAEPAVbkButton@@PADPAHHVCallback@@@Z
    ARTS_IMPORT class bkButton* AddMex(char* arg1, i32* arg2, i32 arg3, class Callback arg4) override;

    // 0x5271F0 | ?AddSlider@asMidgets@@UAEPAVbkSlider@@PAD0DDMVCallback@@@Z
    ARTS_IMPORT class bkSlider* AddSlider(
        char* arg1, char* arg2, char arg3, char arg4, f32 arg5, class Callback arg6) override;

    // 0x527550 | ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAMMMMVCallback@@@Z
    ARTS_IMPORT class bkSlider* AddSlider(
        char* arg1, f32* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6) override;

    // 0x527310 | ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAFFFMVCallback@@@Z
    ARTS_IMPORT class bkSlider* AddSlider(
        char* arg1, i16* arg2, i16 arg3, i16 arg4, f32 arg5, class Callback arg6) override;

    // 0x527430 | ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAHHHMVCallback@@@Z
    ARTS_IMPORT class bkSlider* AddSlider(
        char* arg1, i32* arg2, i32 arg3, i32 arg4, f32 arg5, class Callback arg6) override;

    // 0x5273A0 | ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAGGGMVCallback@@@Z
    ARTS_IMPORT class bkSlider* AddSlider(
        char* arg1, u16* arg2, u16 arg3, u16 arg4, f32 arg5, class Callback arg6) override;

    // 0x5274C0 | ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAIIIMVCallback@@@Z
    ARTS_IMPORT class bkSlider* AddSlider(
        char* arg1, u32* arg2, u32 arg3, u32 arg4, f32 arg5, class Callback arg6) override;

    // 0x527280 | ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAEEEMVCallback@@@Z
    ARTS_IMPORT class bkSlider* AddSlider(
        char* arg1, u8* arg2, u8 arg3, u8 arg4, f32 arg5, class Callback arg6) override;

    // 0x527190 | ?AddText@asMidgets@@UAEPAVbkButton@@VCallback@@@Z
    ARTS_IMPORT class bkButton* AddText(class Callback arg1) override;

    // 0x5271C0 | ?AddText@asMidgets@@UAEPAVbkButton@@PADVCallback@@@Z
    ARTS_IMPORT class bkButton* AddText(char* arg1, class Callback arg2) override;

    // 0x5275E0 | ?AddTextSlider@asMidgets@@UAEPAVbkSlider@@PAD0PAHMVCallback@@@Z
    ARTS_IMPORT class bkSlider* AddTextSlider(
        char* arg1, char* arg2, i32* arg3, f32 arg4, class Callback arg5) override;

    // 0x526FC0 | ?AddTitle@asMidgets@@UAEPAVbkWindow@@PAD@Z
    ARTS_IMPORT class bkWindow* AddTitle(char* arg1) override;

    // 0x527090 | ?AddToggle@asMidgets@@UAEPAVbkButton@@PADPAHHVCallback@@@Z
    ARTS_IMPORT class bkButton* AddToggle(char* arg1, i32* arg2, i32 arg3, class Callback arg4) override;

    // 0x527610 | ?AddVector@asMidgets@@UAEXPADPAVVector2@@MMMVCallback@@@Z
    ARTS_IMPORT void AddVector(
        char* arg1, class Vector2* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6) override;

    // 0x5276B0 | ?AddVector@asMidgets@@UAEXPADPAVVector3@@MMMVCallback@@@Z
    ARTS_IMPORT void AddVector(
        char* arg1, class Vector3* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6) override;

    // 0x527790 | ?AddVector@asMidgets@@UAEXPADPAVVector4@@MMMVCallback@@@Z
    ARTS_IMPORT void AddVector(
        char* arg1, class Vector4* arg2, f32 arg3, f32 arg4, f32 arg5, class Callback arg6) override;

    // 0x526ED0 | ?Cull@asMidgets@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // 0x526900 | ?Off@asMidgets@@UAEXXZ
    ARTS_IMPORT void Off() override;

    // 0x526950 | ?Open@asMidgets@@QAEXPAVasNode@@@Z
    ARTS_IMPORT void Open(class asNode* arg1);

    // 0x527B90 | ?PopColumn@asMidgets@@UAEXXZ
    ARTS_IMPORT void PopColumn() override;

    // 0x527B50 | ?PopSection@asMidgets@@UAEXXZ
    ARTS_IMPORT void PopSection() override;

    // 0x527B80 | ?PushColumn@asMidgets@@UAEXH@Z
    ARTS_IMPORT void PushColumn(i32 arg1) override;

    // 0x527AE0 | ?PushSection@asMidgets@@UAEXPADH@Z
    ARTS_IMPORT void PushSection(char* arg1, i32 arg2) override;

    // 0x526E40 | ?SetLabel@asMidgets@@UAEXPAD@Z
    ARTS_IMPORT void SetLabel(char* arg1) override;

    // 0x526B60 | ?Toggle@asMidgets@@QAEXXZ
    ARTS_IMPORT void Toggle();

    // 0x526B80 | ?Update@asMidgets@@QAEXXZ
    ARTS_IMPORT void Update();

    // 0x526BF0 | ?UpdateKey@asMidgets@@QAEXHH@Z
    ARTS_IMPORT void UpdateKey(i32 arg1, i32 arg2);

private:
    // 0x526E50 | ?AddItem@asMidgets@@AAEXPAVMI@@@Z
    ARTS_IMPORT void AddItem(class MI* arg1);

    // 0x526E90 | ?IsVisible@asMidgets@@AAEHH@Z
    ARTS_IMPORT i32 IsVisible(i32 arg1);
};

check_size(asMidgets, 0x87C);

class SMI : public MI
{
    // const SMI::`vftable' @ 0x620CB0

public:
    // 0x527BD0 | ?Key@SMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 arg1, i32 arg2) override;

    // 0x527BE0 | ?Update@SMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(i32 arg1) override;
};

check_size(SMI, 0x48);

class BMI : public MI
{
    // const BMI::`vftable' @ 0x620CB8

public:
    // 0x527C00 | ?Key@BMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 arg1, i32 arg2) override;

    // 0x527C20 | ?Update@BMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(i32 arg1) override;

    u8 gap48[0x14];
};

check_size(BMI, 0x5C);

class TMI : public MI
{
    // const TMI::`vftable' @ 0x620CC0

public:
    // 0x527C40 | ?Key@TMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 arg1, i32 arg2) override;

    // 0x527CA0 | ?Update@TMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(i32 arg1) override;

    u8 gap48[0x20];
};

check_size(TMI, 0x68);

class scharMI : public MI
{
    // const scharMI::`vftable' @ 0x620CC8

public:
    // 0x527CF0 | ?Key@scharMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 arg1, i32 arg2) override;

    // 0x527D80 | ?Update@scharMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(i32 arg1) override;

    u8 gap48[0x20];
};

check_size(scharMI, 0x68);

class ucharMI : public MI
{
    // const ucharMI::`vftable' @ 0x620CD8

public:
    // 0x527DD0 | ?Key@ucharMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 arg1, i32 arg2) override;

    // 0x527E60 | ?Update@ucharMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(i32 arg1) override;

    u8 gap48[0x20];
};

check_size(ucharMI, 0x68);

class shortMI : public MI
{
    // const shortMI::`vftable' @ 0x620CE0

public:
    // 0x527EB0 | ?Key@shortMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 arg1, i32 arg2) override;

    // 0x527F50 | ?Update@shortMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(i32 arg1) override;

    u8 gap48[0x20];
};

check_size(shortMI, 0x68);

class ushortMI : public MI
{
    // const ushortMI::`vftable' @ 0x620CE8

public:
    // 0x527FA0 | ?Key@ushortMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 arg1, i32 arg2) override;

    // 0x528040 | ?Update@ushortMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(i32 arg1) override;

    u8 gap48[0x20];
};

check_size(ushortMI, 0x68);

class intMI : public MI
{
    // const intMI::`vftable' @ 0x620CF0

public:
    // 0x528090 | ?Key@intMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 arg1, i32 arg2) override;

    // 0x528120 | ?Update@intMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(i32 arg1) override;

    u8 gap48[0x24];
};

check_size(intMI, 0x6C);

class uintMI : public MI
{
    // const uintMI::`vftable' @ 0x620CF8

public:
    // 0x528170 | ?Key@uintMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 arg1, i32 arg2) override;

    // 0x528210 | ?Update@uintMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(i32 arg1) override;

    u8 gap48[0x24];
};

check_size(uintMI, 0x6C);

class floatMI : public MI
{
    // const floatMI::`vftable' @ 0x620D00

public:
    // 0x528260 | ?Key@floatMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 arg1, i32 arg2) override;

    // 0x5282F0 | ?Update@floatMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(i32 arg1) override;

    u8 gap48[0x24];
};

check_size(floatMI, 0x6C);

class SBMI : public MI
{
    // const SBMI::`vftable' @ 0x620D08

public:
    // 0x528340 | ?Key@SBMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 arg1, i32 arg2) override;

    // 0x528360 | ?Update@SBMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(i32 arg1) override;

    u8 gap48[0x8];
};

check_size(SBMI, 0x50);

class MI
{
    // const MI::`vftable' @ 0x620CA8

public:
    virtual i32 Update(i32 arg1) = 0;

    virtual void Key(i32 arg1, i32 arg2) = 0;

    u8 gap4[0x44];
};

check_size(MI, 0x48);

// 0x790928 | ?MIDGETSPTR@@3PAVasMidgets@@A
ARTS_IMPORT extern class asMidgets* MIDGETSPTR;
