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
#include "eventq7/eventq.h"

class MI;

class asMidgets final
    : public Bank
    , public asCullable
{
public:
    // ??0asMidgets@@QAE@XZ
    ARTS_EXPORT asMidgets();

    // ??_GasMidgets@@UAEPAXI@Z
    // ??_EasMidgets@@UAEPAXI@Z
    // ??1asMidgets@@UAE@XZ
    ARTS_EXPORT ~asMidgets() override;

    // ?AddButton@asMidgets@@UAEPAVbkButton@@PADVCallback@@@Z
    ARTS_EXPORT bkButton* AddButton(const char* arg1, Callback arg2) override;

    // ?AddColor@asMidgets@@UAEXPADPAVVector3@@VCallback@@@Z
    ARTS_EXPORT void AddColor(const char* arg1, Vector3* arg2, Callback arg3) override;

    // ?AddColor@asMidgets@@UAEXPADPAVVector4@@VCallback@@@Z
    ARTS_EXPORT void AddColor(const char* arg1, Vector4* arg2, Callback arg3) override;

    // ?AddFileButton@asMidgets@@UAEXPADVCallback@@@Z
    ARTS_EXPORT void AddFileButton(const char* arg1, Callback arg2) override;

    // ?AddMex@asMidgets@@UAEPAVbkButton@@PADPAHHVCallback@@@Z
    ARTS_EXPORT bkButton* AddMex(const char* arg1, i32* arg2, i32 arg3, Callback arg4) override;

    // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PAD0DDMVCallback@@@Z
    ARTS_EXPORT bkSlider* AddSlider(const char* arg1, i8* arg2, i8 arg3, i8 arg4, f32 arg5, Callback arg6) override;

    // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAMMMMVCallback@@@Z
    ARTS_EXPORT bkSlider* AddSlider(const char* arg1, f32* arg2, f32 arg3, f32 arg4, f32 arg5, Callback arg6) override;

    // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAFFFMVCallback@@@Z
    ARTS_EXPORT bkSlider* AddSlider(const char* arg1, i16* arg2, i16 arg3, i16 arg4, f32 arg5, Callback arg6) override;

    // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAHHHMVCallback@@@Z
    ARTS_EXPORT bkSlider* AddSlider(const char* arg1, i32* arg2, i32 arg3, i32 arg4, f32 arg5, Callback arg6) override;

    // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAGGGMVCallback@@@Z
    ARTS_EXPORT bkSlider* AddSlider(const char* arg1, u16* arg2, u16 arg3, u16 arg4, f32 arg5, Callback arg6) override;

    // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAIIIMVCallback@@@Z
    ARTS_EXPORT bkSlider* AddSlider(const char* arg1, u32* arg2, u32 arg3, u32 arg4, f32 arg5, Callback arg6) override;

    // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAEEEMVCallback@@@Z
    ARTS_EXPORT bkSlider* AddSlider(const char* arg1, u8* arg2, u8 arg3, u8 arg4, f32 arg5, Callback arg6) override;

    // ?AddText@asMidgets@@UAEPAVbkButton@@VCallback@@@Z
    ARTS_EXPORT bkButton* AddText(Callback arg1) override;

    // ?AddText@asMidgets@@UAEPAVbkButton@@PADVCallback@@@Z
    ARTS_EXPORT bkButton* AddText(const char* arg1, Callback arg2) override;

    // ?AddTextSlider@asMidgets@@UAEPAVbkSlider@@PAD0PAHMVCallback@@@Z
    ARTS_EXPORT bkSlider* AddTextSlider(
        const char* arg1, const char* arg2, i32* arg3, f32 arg4, Callback arg5) override;

    // ?AddTitle@asMidgets@@UAEPAVbkWindow@@PAD@Z
    ARTS_EXPORT bkWindow* AddTitle(const char* arg1) override;

    // TODO: Add bool overload to for AddToggle

    // ?AddToggle@asMidgets@@UAEPAVbkButton@@PADPAHHVCallback@@@Z
    ARTS_EXPORT bkButton* AddToggle(const char* arg1, i32* arg2, i32 arg3, Callback arg4) override;

    // ?AddVector@asMidgets@@UAEXPADPAVVector2@@MMMVCallback@@@Z
    ARTS_EXPORT void AddVector(const char* arg1, Vector2* arg2, f32 arg3, f32 arg4, f32 arg5, Callback arg6) override;

    // ?AddVector@asMidgets@@UAEXPADPAVVector3@@MMMVCallback@@@Z
    ARTS_EXPORT void AddVector(const char* arg1, Vector3* arg2, f32 arg3, f32 arg4, f32 arg5, Callback arg6) override;

    // ?AddVector@asMidgets@@UAEXPADPAVVector4@@MMMVCallback@@@Z
    ARTS_EXPORT void AddVector(const char* arg1, Vector4* arg2, f32 arg3, f32 arg4, f32 arg5, Callback arg6) override;

    // ?Cull@asMidgets@@UAEXXZ
    ARTS_EXPORT void Cull() override;

    // ?Off@asMidgets@@UAEXXZ
    ARTS_EXPORT void Off() override;

    // ?Open@asMidgets@@QAEXPAVasNode@@@Z
    ARTS_EXPORT void Open(asNode* node);

    // ?PopColumn@asMidgets@@UAEXXZ
    ARTS_EXPORT void PopColumn() override;

    // ?PopSection@asMidgets@@UAEXXZ
    ARTS_EXPORT void PopSection() override;

    // ?PushColumn@asMidgets@@UAEXH@Z
    ARTS_EXPORT void PushColumn(i32 arg1) override;

    // ?PushSection@asMidgets@@UAEXPADH@Z
    ARTS_EXPORT void PushSection(const char* arg1, i32 arg2) override;

    // ?SetLabel@asMidgets@@UAEXPAD@Z
    ARTS_EXPORT void SetLabel(const char* title) override;

    // ?Toggle@asMidgets@@QAEXXZ
    ARTS_EXPORT void Toggle();

    // ?Update@asMidgets@@QAEXXZ
    ARTS_EXPORT void Update();

    // ?UpdateKey@asMidgets@@QAEXHH@Z
    ARTS_EXPORT void UpdateKey(i32 key, i32 mods);

    bool IsOpen() const
    {
        return open_;
    }

    i32 GetVisibleLines() const
    {
        return visible_lines_;
    }

    void SetVisibleLines(i32 lines)
    {
        visible_lines_ = lines;

        SetCurrentIndex(current_index_);
    }

private:
    // ?AddItem@asMidgets@@AAEXPAVMI@@@Z
    ARTS_EXPORT void AddItem(MI* item);

    // ?IsVisible@asMidgets@@AAEHH@Z
    ARTS_EXPORT i32 IsVisible(i32 line);

    i32 IndexBefore(i32 index, i32 count);
    i32 IndexAfter(i32 index, i32 count);

    void SetCurrentIndex(i32 index);

    i32 visible_lines_ {};
    asNode* current_node_ {};
    i32 midget_count_ {};
    i32 start_index_ {};
    i32 current_index_ {};
    b32 open_ {};
    MI* midgets_[512] {};

    i32 parent_midget_index_ {};
    i32 child_midget_index_[9] {};

    i32 sections_[8] {};
    i32 section_count_ {};
    eqEventQ event_queue_;
};

// check_size(asMidgets, 0x87C);

// ?MIDGETSPTR@@3PAVasMidgets@@A
ARTS_EXPORT extern asMidgets* MIDGETSPTR;
