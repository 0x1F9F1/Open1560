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

#include "bank.h"
#include "cullable.h"
#include "eventq7/eventq.h"

class asNode;
class MI;

class asMidgets final
    : public Bank
    , public asCullable
{
public:
    // ??0asMidgets@@QAE@XZ
    asMidgets();

    // ??1asMidgets@@UAE@XZ
    ~asMidgets() override;

    // ?AddButton@asMidgets@@UAEPAVbkButton@@PADVCallback@@@Z
    bkButton* AddButton(const char* arg1, Callback arg2) override;

    // ?AddColor@asMidgets@@UAEXPADPAVVector3@@VCallback@@@Z
    void AddColor(const char* arg1, Vector3* arg2, Callback arg3) override;

    // ?AddColor@asMidgets@@UAEXPADPAVVector4@@VCallback@@@Z
    void AddColor(const char* arg1, Vector4* arg2, Callback arg3) override;

    // ?AddFileButton@asMidgets@@UAEXPADVCallback@@@Z
    void AddFileButton(const char* arg1, Callback arg2) override;

    // ?AddMex@asMidgets@@UAEPAVbkButton@@PADPAHHVCallback@@@Z
    bkButton* AddMex(const char* arg1, i32* arg2, i32 arg3, Callback arg4) override;

    // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PAD0DDMVCallback@@@Z
    bkSlider* AddSlider(const char* arg1, i8* arg2, i8 arg3, i8 arg4, f32 arg5, Callback arg6) override;

    // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAMMMMVCallback@@@Z
    bkSlider* AddSlider(const char* arg1, f32* arg2, f32 arg3, f32 arg4, f32 arg5, Callback arg6) override;

    // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAFFFMVCallback@@@Z
    bkSlider* AddSlider(const char* arg1, i16* arg2, i16 arg3, i16 arg4, f32 arg5, Callback arg6) override;

    // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAHHHMVCallback@@@Z
    bkSlider* AddSlider(const char* arg1, i32* arg2, i32 arg3, i32 arg4, f32 arg5, Callback arg6) override;

    // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAGGGMVCallback@@@Z
    bkSlider* AddSlider(const char* arg1, u16* arg2, u16 arg3, u16 arg4, f32 arg5, Callback arg6) override;

    // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAIIIMVCallback@@@Z
    bkSlider* AddSlider(const char* arg1, u32* arg2, u32 arg3, u32 arg4, f32 arg5, Callback arg6) override;

    // ?AddSlider@asMidgets@@UAEPAVbkSlider@@PADPAEEEMVCallback@@@Z
    bkSlider* AddSlider(const char* arg1, u8* arg2, u8 arg3, u8 arg4, f32 arg5, Callback arg6) override;

    // ?AddText@asMidgets@@UAEPAVbkButton@@VCallback@@@Z
    bkButton* AddText(Callback arg1) override;

    // ?AddText@asMidgets@@UAEPAVbkButton@@PADVCallback@@@Z
    bkButton* AddText(const char* arg1, Callback arg2) override;

    // ?AddTextSlider@asMidgets@@UAEPAVbkSlider@@PAD0PAHMVCallback@@@Z
    bkSlider* AddTextSlider(
        const char* arg1, const char* arg2, i32* arg3, f32 arg4, Callback arg5) override;

    // ?AddTitle@asMidgets@@UAEPAVbkWindow@@PAD@Z
    bkWindow* AddTitle(const char* arg1) override;

    // TODO: Add bool overload to for AddToggle

    // ?AddToggle@asMidgets@@UAEPAVbkButton@@PADPAHHVCallback@@@Z
    bkButton* AddToggle(const char* arg1, i32* arg2, i32 arg3, Callback arg4) override;

    // ?AddVector@asMidgets@@UAEXPADPAVVector2@@MMMVCallback@@@Z
    void AddVector(const char* arg1, Vector2* arg2, f32 arg3, f32 arg4, f32 arg5, Callback arg6) override;

    // ?AddVector@asMidgets@@UAEXPADPAVVector3@@MMMVCallback@@@Z
    void AddVector(const char* arg1, Vector3* arg2, f32 arg3, f32 arg4, f32 arg5, Callback arg6) override;

    // ?AddVector@asMidgets@@UAEXPADPAVVector4@@MMMVCallback@@@Z
    void AddVector(const char* arg1, Vector4* arg2, f32 arg3, f32 arg4, f32 arg5, Callback arg6) override;

    // ?Cull@asMidgets@@UAEXXZ
    void Cull() override;

    // ?Off@asMidgets@@UAEXXZ
    void Off() override;

    // ?Open@asMidgets@@QAEXPAVasNode@@@Z
    void Open(asNode* node);

    // ?PopColumn@asMidgets@@UAEXXZ
    void PopColumn() override;

    // ?PopSection@asMidgets@@UAEXXZ
    void PopSection() override;

    // ?PushColumn@asMidgets@@UAEXH@Z
    void PushColumn(i32 arg1) override;

    // ?PushSection@asMidgets@@UAEXPADH@Z
    void PushSection(const char* arg1, b32 open) override;

    // ?SetLabel@asMidgets@@UAEXPAD@Z
    void SetLabel(const char* title) override;

    // ?Toggle@asMidgets@@QAEXXZ
    void Toggle();

    // ?Update@asMidgets@@QAEXXZ
    ARTS_EXPORT void Update();

    // ?UpdateKey@asMidgets@@QAEXHH@Z
    void UpdateKey(i32 key, i32 mods);

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
    void AddItem(MI* item);

    // ?IsVisible@asMidgets@@AAEHH@Z
    i32 IsVisible(i32 line);

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
check_size(asMidgets, 0x898);

// ?MIDGETSPTR@@3PAVasMidgets@@A
ARTS_EXPORT extern asMidgets* MIDGETSPTR;
