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

#include "agi/pipeline.h"
#include "agi/print.h"
#include "cullmgr.h"
#include "eventq7/key_codes.h"
#include "sim.h"
#include "vector7/vector2.h"
#include "vector7/vector3.h"
#include "vector7/vector4.h"

class MI
{
    // const MI::`vftable' @ 0x620CA8

public:
    MI(const char* name)
        : Name(name)
    {
        Text[0] = '\0';
    }

    // TODO: Add virtual destructor

    virtual i32 Update(b32 active) = 0;

    virtual void Key(i32 key, i32 flags) = 0;

    char Text[64];
    CString Name;
};

check_size(MI, 0x48);

asMidgets::asMidgets()
    : event_queue_(1, EQ_EVENT_MASK(eqEventType::Keyboard), 32)
    , root_(ARTSPTR)
    , max_lines_(5)
{}

asMidgets::~asMidgets()
{
    Off();
}

class BMI final : public MI
{
    // const BMI::`vftable' @ 0x620CB8

public:
    BMI(const char* title, Callback cb)
        : MI(title)
        , CB(cb)
    {}

    // 0x527C00 | ?Key@BMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 key, i32 flags) override;

    // 0x527C20 | ?Update@BMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(b32 active) override;

    Callback CB;
};

check_size(BMI, 0x5C);

bkButton* asMidgets::AddButton(const char* arg1, Callback arg2)
{
    AddItem(new BMI(arg1, arg2));

    return nullptr;
}

void asMidgets::AddColor(const char* arg1, Vector3* arg2, Callback arg3)
{
    CStringBuffer<128> buffer;

    buffer.sprintf("%s R", arg1);
    AddSlider(buffer.get(), &arg2->x, 0.0f, 1.0f, 1.0f / 255.0f, arg3);

    buffer.sprintf("%s G", arg1);
    AddSlider(buffer.get(), &arg2->y, 0.0f, 1.0f, 1.0f / 255.0f, arg3);

    buffer.sprintf("%s B", arg1);
    AddSlider(buffer.get(), &arg2->z, 0.0f, 1.0f, 1.0f / 255.0f, arg3);
}

void asMidgets::AddColor(const char* arg1, Vector4* arg2, Callback arg3)
{
    CStringBuffer<128> buffer;

    buffer.sprintf("%s R", arg1);
    AddSlider(buffer.get(), &arg2->x, 0.0f, 1.0f, 1.0f / 255.0f, arg3);

    buffer.sprintf("%s G", arg1);
    AddSlider(buffer.get(), &arg2->y, 0.0f, 1.0f, 1.0f / 255.0f, arg3);

    buffer.sprintf("%s B", arg1);
    AddSlider(buffer.get(), &arg2->z, 0.0f, 1.0f, 1.0f / 255.0f, arg3);

    buffer.sprintf("%s A", arg1);
    AddSlider(buffer.get(), &arg2->w, 0.0f, 1.0f, 1.0f / 255.0f, arg3);
}

void asMidgets::AddFileButton(const char* arg1, [[maybe_unused]] Callback arg2)
{
    AddButton(arg1, NullCallback);
}

class TMI final : public MI
{
    // const TMI::`vftable' @ 0x620CC0

public:
    TMI(const char* title, i32* value, i32 expected, i32 mask, Callback cb)
        : MI(title)
        , Value(value)
        , Expected(expected)
        , Mask(mask)
        , CB(cb)
    {}

    // 0x527C40 | ?Key@TMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 key, i32 flags) override;

    // 0x527CA0 | ?Update@TMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(b32 active) override;

    i32* Value;
    i32 Expected;
    i32 Mask;
    Callback CB;
};

check_size(TMI, 0x68);

bkButton* asMidgets::AddMex(const char* arg1, i32* arg2, i32 arg3, Callback arg4)
{
    AddItem(new TMI(arg1, arg2, arg3, -1, arg4));

    return nullptr;
}

class scharMI final : public MI
{
    // const scharMI::`vftable' @ 0x620CC8

public:
    scharMI(const char* title, i8* value, i8 min, i8 max, f32 step, Callback cb)
        : MI(title)
        , Value(value)
        , ValueMin(min)
        , ValueMax(max)
        , ValueStep(step)
        , CB(cb)
    {}

    // 0x527CF0 | ?Key@scharMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 key, i32 flags) override;

    // 0x527D80 | ?Update@scharMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(b32 active) override;

    i8* Value;
    i8 ValueMin;
    i8 ValueMax;
    f32 ValueStep;
    Callback CB;
};

check_size(scharMI, 0x68);

bkSlider* asMidgets::AddSlider(const char* arg1, i8* arg2, i8 arg3, i8 arg4, f32 arg5, Callback arg6)
{
    AddItem(new scharMI(arg1, arg2, arg3, arg4, arg5, arg6));

    return nullptr;
}

class floatMI final : public MI
{
    // const floatMI::`vftable' @ 0x620D00

public:
    floatMI(const char* title, f32* value, f32 min, f32 max, f32 step, Callback cb)
        : MI(title)
        , Value(value)
        , ValueMin(min)
        , ValueMax(max)
        , ValueStep(step)
        , CB(cb)
    {}

    // 0x528260 | ?Key@floatMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 key, i32 flags) override;

    // 0x5282F0 | ?Update@floatMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(b32 active) override;

    f32* Value;
    f32 ValueMin;
    f32 ValueMax;
    f32 ValueStep;
    Callback CB;
};

check_size(floatMI, 0x6C);

bkSlider* asMidgets::AddSlider(const char* arg1, f32* arg2, f32 arg3, f32 arg4, f32 arg5, Callback arg6)
{
    AddItem(new floatMI(arg1, arg2, arg3, arg4, arg5, arg6));

    return nullptr;
}

class shortMI final : public MI
{
    // const shortMI::`vftable' @ 0x620CE0

public:
    shortMI(const char* title, i16* value, i16 min, i16 max, f32 step, Callback cb)
        : MI(title)
        , Value(value)
        , ValueMin(min)
        , ValueMax(max)
        , ValueStep(step)
        , CB(cb)
    {}

    // 0x527EB0 | ?Key@shortMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 key, i32 flags) override;

    // 0x527F50 | ?Update@shortMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(b32 active) override;

    i16* Value;
    i16 ValueMin;
    i16 ValueMax;
    f32 ValueStep;
    Callback CB;
};

check_size(shortMI, 0x68);

bkSlider* asMidgets::AddSlider(const char* arg1, i16* arg2, i16 arg3, i16 arg4, f32 arg5, Callback arg6)
{
    AddItem(new shortMI(arg1, arg2, arg3, arg4, arg5, arg6));

    return nullptr;
}

class intMI final : public MI
{
    // const intMI::`vftable' @ 0x620CF0

public:
    intMI(const char* title, i32* value, i32 min, i32 max, f32 step, Callback cb)
        : MI(title)
        , Value(value)
        , ValueMin(min)
        , ValueMax(max)
        , ValueStep(step)
        , CB(cb)
    {}

    // 0x528090 | ?Key@intMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 key, i32 flags) override;

    // 0x528120 | ?Update@intMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(b32 active) override;

    i32* Value;
    i32 ValueMin;
    i32 ValueMax;
    f32 ValueStep;
    Callback CB;
};

check_size(intMI, 0x6C);

bkSlider* asMidgets::AddSlider(const char* arg1, i32* arg2, i32 arg3, i32 arg4, f32 arg5, Callback arg6)
{
    AddItem(new intMI(arg1, arg2, arg3, arg4, arg5, arg6));

    return nullptr;
}

class ushortMI final : public MI
{
    // const ushortMI::`vftable' @ 0x620CE8

public:
    ushortMI(const char* title, u16* value, u16 min, u16 max, f32 step, Callback cb)
        : MI(title)
        , Value(value)
        , ValueMin(min)
        , ValueMax(max)
        , ValueStep(step)
        , CB(cb)
    {}

    // 0x527FA0 | ?Key@ushortMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 key, i32 flags) override;

    // 0x528040 | ?Update@ushortMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(b32 active) override;

    u16* Value;
    u16 ValueMin;
    u16 ValueMax;
    f32 ValueStep;
    Callback CB;
};

check_size(ushortMI, 0x68);

bkSlider* asMidgets::AddSlider(const char* arg1, u16* arg2, u16 arg3, u16 arg4, f32 arg5, Callback arg6)
{
    AddItem(new ushortMI(arg1, arg2, arg3, arg4, arg5, arg6));

    return nullptr;
}

class uintMI final : public MI
{
    // const uintMI::`vftable' @ 0x620CF8

public:
    uintMI(const char* title, u32* value, u32 min, u32 max, f32 step, Callback cb)
        : MI(title)
        , Value(value)
        , ValueMin(min)
        , ValueMax(max)
        , ValueStep(step)
        , CB(cb)
    {}

    // 0x528170 | ?Key@uintMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 key, i32 flags) override;

    // 0x528210 | ?Update@uintMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(b32 active) override;

    u32* Value;
    u32 ValueMin;
    u32 ValueMax;
    f32 ValueStep;
    Callback CB;
};

check_size(uintMI, 0x6C);

bkSlider* asMidgets::AddSlider(const char* arg1, u32* arg2, u32 arg3, u32 arg4, f32 arg5, Callback arg6)
{
    AddItem(new uintMI(arg1, arg2, arg3, arg4, arg5, arg6));

    return nullptr;
}

class ucharMI final : public MI
{
    // const ucharMI::`vftable' @ 0x620CD8

public:
    ucharMI(const char* title, u8* value, u8 min, u8 max, f32 step, Callback cb)
        : MI(title)
        , Value(value)
        , ValueMin(min)
        , ValueMax(max)
        , ValueStep(step)
        , CB(cb)
    {}

    // 0x527DD0 | ?Key@ucharMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 key, i32 flags) override;

    // 0x527E60 | ?Update@ucharMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(b32 active) override;

    u8* Value;
    u8 ValueMin;
    u8 ValueMax;
    f32 ValueStep;
    Callback CB;
};

check_size(ucharMI, 0x68);

bkSlider* asMidgets::AddSlider(const char* arg1, u8* arg2, u8 arg3, u8 arg4, f32 arg5, Callback arg6)
{
    AddItem(new ucharMI(arg1, arg2, arg3, arg4, arg5, arg6));

    return nullptr;
}

bkButton* asMidgets::AddText([[maybe_unused]] Callback arg1)
{
    return AddButton("Text Edit", NullCallback);
}

bkButton* asMidgets::AddText([[maybe_unused]] const char* arg1, [[maybe_unused]] Callback arg2)
{
    return AddButton("Labelled text edit", NullCallback);
}

bkSlider* asMidgets::AddTextSlider(const char* arg1, [[maybe_unused]] const char* arg2, [[maybe_unused]] i32* arg3,
    [[maybe_unused]] f32 arg4, [[maybe_unused]] Callback arg5)
{
    AddButton(arg1, NullCallback);

    return nullptr;
}

class SMI final : public MI
{
    // const SMI::`vftable' @ 0x620CB0

public:
    using MI::MI;

    // 0x527BD0 | ?Key@SMI@@UAEXHH@Z | inline
    ARTS_EXPORT void Key(i32 key, i32 flags) override;

    // 0x527BE0 | ?Update@SMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(b32 active) override;
};

void SMI::Key(i32 /*arg1*/, i32 /*arg2*/)
{}

check_size(SMI, 0x48);

bkWindow* asMidgets::AddTitle(const char* arg1)
{
    AddItem(new SMI(arg1));

    return nullptr;
}

bkButton* asMidgets::AddToggle(const char* arg1, i32* arg2, i32 arg3, Callback arg4)
{
    AddItem(new TMI(arg1, arg2, arg3, arg3, arg4));

    return nullptr;
}

void asMidgets::AddVector(const char* arg1, Vector2* arg2, f32 arg3, f32 arg4, f32 arg5, Callback arg6)
{
    CStringBuffer<128> buffer;

    buffer.sprintf("%s X", arg1);
    AddSlider(buffer.get(), &arg2->x, arg3, arg4, arg5, arg6);

    buffer.sprintf("%s Y", arg1);
    AddSlider(buffer.get(), &arg2->y, arg3, arg4, arg5, arg6);
}

void asMidgets::AddVector(const char* arg1, Vector3* arg2, f32 arg3, f32 arg4, f32 arg5, Callback arg6)
{
    CStringBuffer<128> buffer;

    buffer.sprintf("%s X", arg1);
    AddSlider(buffer.get(), &arg2->x, arg3, arg4, arg5, arg6);

    buffer.sprintf("%s Y", arg1);
    AddSlider(buffer.get(), &arg2->y, arg3, arg4, arg5, arg6);

    buffer.sprintf("%s Z", arg1);
    AddSlider(buffer.get(), &arg2->z, arg3, arg4, arg5, arg6);
}

void asMidgets::AddVector(const char* arg1, Vector4* arg2, f32 arg3, f32 arg4, f32 arg5, Callback arg6)
{
    CStringBuffer<128> buffer;

    buffer.sprintf("%s X", arg1);
    AddSlider(buffer.get(), &arg2->x, arg3, arg4, arg5, arg6);

    buffer.sprintf("%s Y", arg1);
    AddSlider(buffer.get(), &arg2->y, arg3, arg4, arg5, arg6);

    buffer.sprintf("%s Z", arg1);
    AddSlider(buffer.get(), &arg2->z, arg3, arg4, arg5, arg6);

    buffer.sprintf("%s W", arg1);
    AddSlider(buffer.get(), &arg2->w, arg3, arg4, arg5, arg6);
}

void asMidgets::Cull()
{
    i32 max_lines = max_lines_;
    i32 text_y = agiPipeline::CurrentPipe->GetHeight() - agiFontHeight * max_lines;

    i32 index = start_index_;

    if (index != 0)
        agiPrint(0, text_y, CULLMGR->GetTextColor(), "^");

    while (max_lines > 0 && index < midget_count_)
    {
        if (index == current_index_)
            agiPrint(agiFontWidth, text_y, CULLMGR->GetTextColor(), ">");

        MI* midget = midgets_[index];

        i32 lines = midget->Update(index == current_index_);

        if (IsVisible(index))
        {
            agiPrint(agiFontWidth * 2, text_y, CULLMGR->GetTextColor(), midget->Text);
            text_y += agiFontHeight;
            --max_lines;
        }

        index += lines + 1;
    }

    if (index != midget_count_)
        agiPrint(0, text_y, CULLMGR->GetTextColor(), "v");
}

void asMidgets::Off()
{
    while (midget_count_)
    {
        --midget_count_;

        // FIXME: delete of an abstract class 'MI' that has a non-virtual destructor results in undefined behavior
        operator delete(midgets_[midget_count_]);
        midgets_[midget_count_] = nullptr;
    }

    current_index_ = 0;
    start_index_ = 0;
    open_ = false;
}

static void OpenNodeMidgets(void* param)
{
    MIDGETSPTR->Open(static_cast<asNode*>(param));
}

void asMidgets::Open(asNode* root)
{
    Off();

    root_ = root;

    if (root_ != nullptr)
    {
        root->AddWidgets(this);

        if (asNode* parent = root->GetParent())
        {
            char buffer[64];

            arts_sprintf(buffer, "Parent: %s", parent->GetNodeType());

            if (const char* parent_name = parent->GetNodeName(); parent_name && *parent_name != '_')
            {
                arts_strcat(buffer, " ");
                arts_strcat(buffer, parent_name);
            }

            parent_midget_count_ = static_cast<i8>(midget_count_);

            AddButton(buffer, CFA1(OpenNodeMidgets, parent));
        }
        else
        {
            parent_midget_count_ = -1;
        }

        for (usize i = 0; i < std::size(midget_counts_); ++i)
            midget_counts_[i] = -1;

        usize count = 0;

        for (asNode* child = root->GetFirstChild(); child; child = child->GetNext())
        {
            if (count < std::size(midget_counts_))
                midget_counts_[count++] = static_cast<i8>(midget_count_);

            char buffer[64];

            arts_sprintf(buffer, "Child: %s", child->GetNodeType());

            if (const char* child_name = child->GetNodeName(); child_name && *child_name != '_')
            {
                arts_strcat(buffer, " ");
                arts_strcat(buffer, child_name);
            }

            AddButton(buffer, CFA1(OpenNodeMidgets, child));
        }
    }

    open_ = true;
}

class SBMI final : public MI
{
    // const SBMI::`vftable' @ 0x620D08

public:
    using MI::MI;

    // 0x528340 | ?Key@SBMI@@UAEXHH@Z | inline
    ARTS_IMPORT void Key(i32 key, i32 flags) override;

    // 0x528360 | ?Update@SBMI@@UAEHH@Z | inline
    ARTS_IMPORT i32 Update(b32 active) override;

    i32 End {0};
    i32 Start {0};
};

check_size(SBMI, 0x50);

void asMidgets::PushSection(const char* arg1, [[maybe_unused]] i32 arg2)
{
    ArAssert(section_count_ < static_cast<i32>(std::size(sections_)), "Too many sections");

    sections_[section_count_++] = midget_count_;

    AddItem(new SBMI(arg1));
}

void asMidgets::PopSection()
{
    i32 start = sections_[--section_count_];
    SBMI* section = static_cast<SBMI*>(midgets_[start]);
    section->Start = section->End = midget_count_ - start - 1;
}

void asMidgets::SetLabel(const char* title)
{
    AddTitle(title);
}

void asMidgets::Toggle()
{
    if (open_)
        Off();
    else
        Open(root_);
}

void asMidgets::Update()
{
    eqEvent ev;

    while (event_queue_.Pop(&ev))
    {
        if ((ev.Common.Type == eqEventType::Keyboard) && (ev.Keyboard.Modifiers & EQ_KMOD_DOWN))
            UpdateKey(ev.Keyboard.VirtualKey, ev.Keyboard.Modifiers);
    }

    CULLMGR->DeclarePrint(this);
}

void asMidgets::AddItem(MI* item)
{
    if (midget_count_ < static_cast<i32>(std::size(midgets_)))
    {
        midgets_[midget_count_++] = item;

        if (midget_count_ == static_cast<i32>(std::size(midgets_)))
            Errorf("Too many midgets!");
    }
}

i32 asMidgets::IsVisible(i32 line)
{
    i32 total = 0;

    while (total < line)
        total += midgets_[total]->Update(false) + 1;

    return line == total;
}

void asMidgets::PushColumn(i32 /*arg1*/)
{}

void asMidgets::PopColumn()
{}
