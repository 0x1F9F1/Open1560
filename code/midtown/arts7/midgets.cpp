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
#include "eventq7/keys.h"
#include "sim.h"
#include "vector7/vector2.h"
#include "vector7/vector3.h"
#include "vector7/vector4.h"

ARTS_EXPORT asMidgets* MIDGETSPTR = nullptr;

class MI
{
public:
    MI(const char* name)
        : Name(name)
    {
        Text[0] = '\0';
    }

    virtual ~MI() = default;

    virtual i32 Update(b32 active) = 0;

    virtual void Key(i32 key, i32 flags) = 0;

    char Text[64];
    ConstString Name;
};

check_size(MI, 0x48);

asMidgets::asMidgets()
    : visible_lines_(5)
    , current_node_(ARTSPTR)
    , event_queue_(1, EQ_EVENT_MASK(eqEventType::Keyboard), 32)
{
    // These fields are accessed publicly and cannot easily be changed
    static_assert(offsetof(asMidgets, visible_lines_) == 0x8);
    static_assert(offsetof(asMidgets, open_) == 0x1C);
}

asMidgets::~asMidgets()
{
    Off();
}

class BMI final : public MI
{
public:
    BMI(const char* title, Callback cb)
        : MI(title)
        , CB(cb)
    {}

    // ?Key@BMI@@UAEXHH@Z | inline
    void Key(i32 key, [[maybe_unused]] i32 flags) override
    {
        if (key == EQ_VK_RETURN)
            CB.Call();
    }

    // ?Update@BMI@@UAEHH@Z | inline
    i32 Update([[maybe_unused]] b32 active) override
    {
        arts_sprintf(Text, "[ %s ]", Name.get());

        return 0;
    }

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
    AddSlider(arts_formatf<128>("%s R", arg1), &arg2->x, 0.0f, 1.0f, 1.0f / 255.0f, arg3);
    AddSlider(arts_formatf<128>("%s G", arg1), &arg2->y, 0.0f, 1.0f, 1.0f / 255.0f, arg3);
    AddSlider(arts_formatf<128>("%s B", arg1), &arg2->z, 0.0f, 1.0f, 1.0f / 255.0f, arg3);
}

void asMidgets::AddColor(const char* arg1, Vector4* arg2, Callback arg3)
{
    AddSlider(arts_formatf<128>("%s R", arg1), &arg2->x, 0.0f, 1.0f, 1.0f / 255.0f, arg3);
    AddSlider(arts_formatf<128>("%s G", arg1), &arg2->y, 0.0f, 1.0f, 1.0f / 255.0f, arg3);
    AddSlider(arts_formatf<128>("%s B", arg1), &arg2->z, 0.0f, 1.0f, 1.0f / 255.0f, arg3);
    AddSlider(arts_formatf<128>("%s A", arg1), &arg2->w, 0.0f, 1.0f, 1.0f / 255.0f, arg3);
}

void asMidgets::AddFileButton(const char* arg1, [[maybe_unused]] Callback arg2)
{
    AddButton(arg1, nullptr);
}

class TMI final : public MI
{
public:
    TMI(const char* title, i32* value, i32 expected, i32 mask, Callback cb)
        : MI(title)
        , Value(value)
        , Expected(expected)
        , Mask(mask)
        , CB(cb)
    {}

    // ?Key@TMI@@UAEXHH@Z | inline
    void Key(i32 key, [[maybe_unused]] i32 flags) override
    {
        if (key == EQ_VK_RETURN)
        {
            if (Mask != 0)
            {
                if (Mask == Expected)
                    *Value ^= Expected;
                else
                    *Value = Expected;
            }
            else
            {
                *Value = *Value == 0;
            }

            CB.Call();
        }
    }

    // ?Update@TMI@@UAEHH@Z | inline
    i32 Update([[maybe_unused]] b32 active) override
    {
        i32 value = (Mask != 0) ? ((Mask & *Value) == Expected) : *Value;
        char flag = value ? '+' : '-';
        arts_sprintf(Text, "%c %s %c", flag, Name.get(), flag);
        return 0;
    }

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

template <typename T>
class sliderMI : public MI
{
public:
    sliderMI(const char* title, T* value, T min, T max, f32 step, Callback cb)
        : MI(title)
        , Value(value)
        , ValueMin(min)
        , ValueMax(max)
        , ValueStep(step)
        , CB(cb)
    {}

    void Key(i32 key, i32 flags) override
    {
        if (key == EQ_VK_Z)
        {
            *Value = 0;
        }
        else
        {
            f32 step = (key == EQ_VK_NUMPAD4) ? -ValueStep : (key == EQ_VK_NUMPAD6) ? ValueStep : 0.0f;

            if (step == 0.0f)
                return;

            if (flags & EQ_KMOD_CTRL)
                step *= 10.0f;

            *Value = static_cast<T>(*Value + step);
        }

        if (!(flags & EQ_KMOD_ALT))
            *Value = std::clamp(*Value, ValueMin, ValueMax);

        CB.Call();
    }

    T* Value;
    T ValueMin;
    T ValueMax;
    f32 ValueStep;
    Callback CB;
};

class scharMI final : public sliderMI<i8>
{
public:
    using sliderMI::sliderMI;

    i32 Update([[maybe_unused]] b32 active) override
    {
        arts_sprintf(Text, "%s: %i", Name.get(), *Value);

        return 0;
    }
};

bkSlider* asMidgets::AddSlider(const char* arg1, i8* arg2, i8 arg3, i8 arg4, f32 arg5, Callback arg6)
{
    AddItem(new scharMI(arg1, arg2, arg3, arg4, arg5, arg6));

    return nullptr;
}

class floatMI final : public sliderMI<f32>
{
public:
    using sliderMI::sliderMI;

    i32 Update([[maybe_unused]] b32 active) override
    {
        arts_sprintf(Text, "%s: %6.3g", Name.get(), *Value);

        return 0;
    }
};

check_size(floatMI, 0x6C);

bkSlider* asMidgets::AddSlider(const char* arg1, f32* arg2, f32 arg3, f32 arg4, f32 arg5, Callback arg6)
{
    AddItem(new floatMI(arg1, arg2, arg3, arg4, arg5, arg6));

    return nullptr;
}

class shortMI final : public sliderMI<i16>
{
public:
    using sliderMI::sliderMI;

    i32 Update([[maybe_unused]] b32 active) override
    {
        arts_sprintf(Text, "%s: %i", Name.get(), *Value);

        return 0;
    }
};

check_size(shortMI, 0x68);

bkSlider* asMidgets::AddSlider(const char* arg1, i16* arg2, i16 arg3, i16 arg4, f32 arg5, Callback arg6)
{
    AddItem(new shortMI(arg1, arg2, arg3, arg4, arg5, arg6));

    return nullptr;
}

class intMI final : public sliderMI<i32>
{
public:
    using sliderMI::sliderMI;

    i32 Update([[maybe_unused]] b32 active) override
    {
        arts_sprintf(Text, "%s: %i", Name.get(), *Value);

        return 0;
    }
};

check_size(intMI, 0x6C);

bkSlider* asMidgets::AddSlider(const char* arg1, i32* arg2, i32 arg3, i32 arg4, f32 arg5, Callback arg6)
{
    AddItem(new intMI(arg1, arg2, arg3, arg4, arg5, arg6));

    return nullptr;
}

class ushortMI final : public sliderMI<u16>
{
public:
    using sliderMI::sliderMI;

    i32 Update([[maybe_unused]] b32 active) override
    {
        arts_sprintf(Text, "%s: %u", Name.get(), *Value);

        return 0;
    }
};

check_size(ushortMI, 0x68);

bkSlider* asMidgets::AddSlider(const char* arg1, u16* arg2, u16 arg3, u16 arg4, f32 arg5, Callback arg6)
{
    AddItem(new ushortMI(arg1, arg2, arg3, arg4, arg5, arg6));

    return nullptr;
}

class uintMI final : public sliderMI<u32>
{
public:
    using sliderMI::sliderMI;

    i32 Update([[maybe_unused]] b32 active) override
    {
        arts_sprintf(Text, "%s: %u", Name.get(), *Value);

        return 0;
    }
};

check_size(uintMI, 0x6C);

bkSlider* asMidgets::AddSlider(const char* arg1, u32* arg2, u32 arg3, u32 arg4, f32 arg5, Callback arg6)
{
    AddItem(new uintMI(arg1, arg2, arg3, arg4, arg5, arg6));

    return nullptr;
}

class ucharMI final : public sliderMI<u8>
{
public:
    using sliderMI::sliderMI;

    i32 Update([[maybe_unused]] b32 active) override
    {
        arts_sprintf(Text, "%s: %u", Name.get(), *Value);

        return 0;
    }
};

check_size(ucharMI, 0x68);

bkSlider* asMidgets::AddSlider(const char* arg1, u8* arg2, u8 arg3, u8 arg4, f32 arg5, Callback arg6)
{
    AddItem(new ucharMI(arg1, arg2, arg3, arg4, arg5, arg6));

    return nullptr;
}

bkButton* asMidgets::AddText([[maybe_unused]] Callback arg1)
{
    return AddButton("Text Edit", nullptr);
}

bkButton* asMidgets::AddText([[maybe_unused]] const char* arg1, [[maybe_unused]] Callback arg2)
{
    return AddButton("Labelled text edit", nullptr);
}

bkSlider* asMidgets::AddTextSlider(const char* arg1, [[maybe_unused]] const char* arg2, [[maybe_unused]] i32* arg3,
    [[maybe_unused]] f32 arg4, [[maybe_unused]] Callback arg5)
{
    AddButton(arg1, nullptr);

    return nullptr;
}

class SMI final : public MI
{
public:
    using MI::MI;

    // ?Key@SMI@@UAEXHH@Z | inline
    void Key([[maybe_unused]] i32 key, [[maybe_unused]] i32 flags) override
    {}

    // ?Update@SMI@@UAEHH@Z | inline
    i32 Update([[maybe_unused]] b32 active) override
    {
        arts_sprintf(Text, "*** %s ***", Name.get());

        return 0;
    }
};

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
    AddSlider(arts_formatf<128>("%s X", arg1), &arg2->x, arg3, arg4, arg5, arg6);
    AddSlider(arts_formatf<128>("%s Y", arg1), &arg2->y, arg3, arg4, arg5, arg6);
}

void asMidgets::AddVector(const char* arg1, Vector3* arg2, f32 arg3, f32 arg4, f32 arg5, Callback arg6)
{
    AddSlider(arts_formatf<128>("%s X", arg1), &arg2->x, arg3, arg4, arg5, arg6);
    AddSlider(arts_formatf<128>("%s Y", arg1), &arg2->y, arg3, arg4, arg5, arg6);
    AddSlider(arts_formatf<128>("%s Z", arg1), &arg2->z, arg3, arg4, arg5, arg6);
}

void asMidgets::AddVector(const char* arg1, Vector4* arg2, f32 arg3, f32 arg4, f32 arg5, Callback arg6)
{
    AddSlider(arts_formatf<128>("%s X", arg1), &arg2->x, arg3, arg4, arg5, arg6);
    AddSlider(arts_formatf<128>("%s Y", arg1), &arg2->y, arg3, arg4, arg5, arg6);
    AddSlider(arts_formatf<128>("%s Z", arg1), &arg2->z, arg3, arg4, arg5, arg6);
    AddSlider(arts_formatf<128>("%s W", arg1), &arg2->w, arg3, arg4, arg5, arg6);
}

void asMidgets::Cull()
{
    if (midget_count_ == 0)
        return;

    i32 max_lines = visible_lines_;
    i32 text_y = Pipe()->GetHeight() - agiFontHeight * max_lines;

    {
        char title[64];

        arts_strcpy(title, current_node_->GetNodeType());

        if (const char* node_name = current_node_->GetNodeName(); node_name && *node_name != '_')
        {
            arts_strcat(title, " ");
            arts_strcat(title, node_name);
        }

        agiPrintf(0, text_y - (agiFontHeight * 2), CullMgr()->GetTextColor(), "%s %p | %i/%i", title, current_node_,
            current_index_ + 1, midget_count_);
    }

    start_index_ = IndexBefore(IndexAfter(current_index_, visible_lines_ / 2), visible_lines_ - 1);

    i32 index = start_index_;

    if (index != 0)
        agiPrint(0, text_y, CullMgr()->GetTextColor(), "^");

    while (max_lines > 0 && index < midget_count_)
    {
        bool selected = index == current_index_;

        if (selected)
            agiPrint(agiFontWidth, text_y, CullMgr()->GetTextColor(), ">");

        MI* midget = midgets_[index];

        i32 lines = midget->Update(index == current_index_);

        // if (IsVisible(index))
        {
            agiPrint(agiFontWidth * 2, text_y, selected ? 0xFF20F0F0 : CullMgr()->GetTextColor(), midget->Text);
            text_y += agiFontHeight;
            --max_lines;
        }

        index += lines + 1;
    }

    if (index != midget_count_)
        agiPrint(0, text_y - agiFontHeight, CullMgr()->GetTextColor(), "v");
}

void asMidgets::Off()
{
    while (midget_count_)
    {
        --midget_count_;
        delete midgets_[midget_count_];
        midgets_[midget_count_] = nullptr;
    }

    event_queue_.Clear();
    current_index_ = 0;
    start_index_ = 0;
    section_count_ = 0;
    open_ = false;
}

void asMidgets::Open(asNode* node)
{
    Off();

    current_node_ = node;

    if (current_node_ == nullptr)
        return;

    node->AddWidgets(this);

    if (section_count_ != 0)
    {
        Errorf("Widgets missing %i PopSection: %s %s (%p)", section_count_, node->GetTypeName(), node->GetNodeName(),
            node);
    }

    if (asNode* parent = node->GetParentNode())
    {
        char buffer[64];

        arts_sprintf(buffer, "Parent: %s", parent->GetNodeType());

        if (const char* parent_name = parent->GetNodeName(); parent_name && *parent_name != '_')
        {
            arts_strcat(buffer, " ");
            arts_strcat(buffer, parent_name);
        }

        parent_midget_index_ = midget_count_;

        AddButton(buffer, [this, parent] { Open(parent); });
    }
    else
    {
        parent_midget_index_ = -1;
    }

    for (usize i = 0; i < ARTS_SIZE(child_midget_index_); ++i)
        child_midget_index_[i] = -1;

    usize count = 0;

    for (asNode* child = node->GetChildNode(); child; child = child->GetNextNode())
    {
        if (count < ARTS_SIZE(child_midget_index_))
            child_midget_index_[count++] = midget_count_;

        char buffer[64];

        arts_sprintf(buffer, "Child: %s", child->GetNodeType());

        if (const char* child_name = child->GetNodeName(); child_name && *child_name != '_')
        {
            arts_strcat(buffer, " ");
            arts_strcat(buffer, child_name);
        }

        AddButton(buffer, [this, child] { Open(child); });
    }

    open_ = midget_count_ > 0;
}

class SBMI final : public MI
{
public:
    using MI::MI;

    // ?Key@SBMI@@UAEXHH@Z | inline
    void Key(i32 key, [[maybe_unused]] i32 flags) override
    {
        if (key == EQ_VK_RETURN)
            Start ^= End;
    }

    // ?Update@SBMI@@UAEHH@Z | inline
    i32 Update([[maybe_unused]] b32 active) override
    {
        if (Start)
            arts_sprintf(Text, "<<< %s >>>", Name.get());
        else
            arts_sprintf(Text, ">>> %s <<<", Name.get());

        return Start;
    }

    i32 End {};
    i32 Start {};
};

check_size(SBMI, 0x50);

void asMidgets::PushSection(const char* arg1, [[maybe_unused]] i32 arg2)
{
    // TODO: Is arg2 whether the section should be open by default?

    ArAssert(section_count_ < ARTS_SSIZE(sections_), "Too many sections");

    sections_[section_count_++] = midget_count_;

    AddItem(new SBMI(arg1));
}

void asMidgets::PopSection()
{
    if (section_count_ == 0)
    {
        Errorf("Section count underflow");
        return;
    }

    i32 start = sections_[--section_count_];

    SBMI* section = static_cast<SBMI*>(midgets_[start]);

    if (start + 1 == midget_count_)
    {
        delete section;
        midgets_[--midget_count_] = nullptr;
        return;
    }

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
        Open(current_node_);
}

void asMidgets::Update()
{
    eqEvent ev;

    while (event_queue_.Pop(&ev))
    {
        if ((ev.Common.Type == eqEventType::Keyboard) && (ev.Key.Modifiers & EQ_KMOD_DOWN))
            UpdateKey(ev.Key.Key, ev.Key.Modifiers);
    }

    CullMgr()->DeclarePrint(this);
}

void asMidgets::UpdateKey(i32 key, i32 mods)
{
    switch (key)
    {
        case EQ_VK_1:
        case EQ_VK_2:
        case EQ_VK_3:
        case EQ_VK_4:
        case EQ_VK_5:
        case EQ_VK_6:
        case EQ_VK_7:
        case EQ_VK_8:
        case EQ_VK_9: {
            if (i32 index = child_midget_index_[key - EQ_VK_1]; index != -1)
            {
                if (mods & EQ_KMOD_CTRL)
                {
                    midgets_[index]->Key(EQ_VK_RETURN, 0);
                }
                else
                {
                    SetCurrentIndex(index);
                }
            }

            break;
        }

        case EQ_VK_NUMPAD0: {
            if (i32 index = parent_midget_index_; index != -1)
            {
                if (mods & EQ_KMOD_CTRL)
                {
                    midgets_[index]->Key(EQ_VK_RETURN, 0);
                }
                else
                {
                    SetCurrentIndex(index);
                }
            }

            break;
        }

        case EQ_VK_NUMPAD1: {
            SetCurrentIndex(IndexBefore(midget_count_, 1));
            break;
        }

        case EQ_VK_NUMPAD2: {
            SetCurrentIndex(IndexAfter(current_index_, 1));
            break;
        }

        case EQ_VK_NUMPAD3: {
            SetCurrentIndex(IndexAfter(current_index_, visible_lines_ / 2));
            break;
        }

        case EQ_VK_NUMPAD7: {
            SetCurrentIndex(0);
            break;
        }

        case EQ_VK_NUMPAD8: {
            SetCurrentIndex(IndexBefore(current_index_, 1));
            break;
        }

        case EQ_VK_NUMPAD9: {
            SetCurrentIndex(IndexBefore(current_index_, visible_lines_ / 2));
            break;
        }

        default: {
            if (MI* midget = midgets_[current_index_])
                midget->Key(key, mods & ~EQ_KMOD_DOWN); // TODO: Why does this clear EQ_KMOD_DOWN?

            break;
        }
    }
}

void asMidgets::AddItem(MI* item)
{
    if (midget_count_ < ARTS_SSIZE(midgets_))
    {
        midgets_[midget_count_++] = item;

        if (midget_count_ == ARTS_SSIZE(midgets_))
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

i32 asMidgets::IndexBefore(i32 index, i32 count)
{
    i32 cache[64];

    i32 total = 0;
    i32 here = 0;

    while (here < index)
    {
        cache[total++ % ARTS_SIZE(cache)] = here;
        here += midgets_[here]->Update(false) + 1;
    }

    if (count >= total)
        return 0;

    if (count <= ARTS_SSIZE(cache))
        return cache[(total - count) % ARTS_SIZE(cache)];

    return IndexAfter(0, total - count);
}

i32 asMidgets::IndexAfter(i32 index, i32 count)
{
    while (count > 0)
    {
        i32 next = index + midgets_[index]->Update(false) + 1;

        if (next >= midget_count_)
            break;

        index = next;
        --count;
    }

    return index;
}

void asMidgets::SetCurrentIndex(i32 index)
{
    if (midget_count_ == 0)
        return;

    current_index_ = index;
}

void asMidgets::PushColumn(i32 /*arg1*/)
{}

void asMidgets::PopColumn()
{}

run_once([] { create_hook("new asMidgets", "Size of asMidgets", 0x521A1C, alloc_proxy<asMidgets>, hook_type::call); });
