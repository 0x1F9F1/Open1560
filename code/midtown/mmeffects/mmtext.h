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
    mmeffects:mmtext

    0x4FEE30 | void __cdecl ddGDIFlip(void) | ?ddGDIFlip@@YAXXZ
    0x4FEE40 | public: __thiscall mmText::mmText(void) | ??0mmText@@QAE@XZ
    0x4FEE50 | public: __thiscall mmText::~mmText(void) | ??1mmText@@QAE@XZ
    0x4FEE60 | public: static void * __cdecl mmText::CreateLocFont(struct LocString *,int) | ?CreateLocFont@mmText@@SAPAXPAULocString@@H@Z
    0x4FEF30 | public: static void * __cdecl mmText::CreateFont(char *,int) | ?CreateFont@mmText@@SAPAXPADH@Z
    0x4FEF60 | public: static void __cdecl mmText::DeleteFont(void *) | ?DeleteFont@mmText@@SAXPAX@Z
    0x4FEF70 | public: static void * __cdecl mmText::GetDC(class agiSurfaceDesc *) | ?GetDC@mmText@@SAPAXPAVagiSurfaceDesc@@@Z
    0x4FF010 | public: static void __cdecl mmText::ReleaseDC(void) | ?ReleaseDC@mmText@@SAXXZ
    0x4FF0C0 | public: static class agiBitmap * __cdecl mmText::CreateFitBitmap(char *,void *,int,int) | ?CreateFitBitmap@mmText@@SAPAVagiBitmap@@PADPAXHH@Z
    0x4FF2D0 | public: void __thiscall mmText::Draw(class agiSurfaceDesc *,float,float,char *,void *) | ?Draw@mmText@@QAEXPAVagiSurfaceDesc@@MMPADPAX@Z
    0x4FF360 | public: void __thiscall mmText::Draw2(class agiSurfaceDesc *,float,float,char *,void *,unsigned int) | ?Draw2@mmText@@QAEXPAVagiSurfaceDesc@@MMPADPAXI@Z
    0x4FF450 | public: __thiscall mmTextNode::mmTextNode(void) | ??0mmTextNode@@QAE@XZ
    0x4FF4D0 | public: virtual __thiscall mmTextNode::~mmTextNode(void) | ??1mmTextNode@@UAE@XZ
    0x4FF540 | public: void __thiscall mmTextNode::Init(float,float,float,float,int,int) | ?Init@mmTextNode@@QAEXMMMMHH@Z
    0x4FF690 | public: void __thiscall mmTextNode::SetBGColor(class Vector4 &) | ?SetBGColor@mmTextNode@@QAEXAAVVector4@@@Z
    0x4FF6F0 | public: void __thiscall mmTextNode::SetFGColor(class Vector4 &) | ?SetFGColor@mmTextNode@@QAEXAAVVector4@@@Z
    0x4FF750 | public: unsigned int __thiscall mmTextNode::GetFGColor(void) | ?GetFGColor@mmTextNode@@QAEIXZ
    0x4FF760 | public: void __thiscall mmTextNode::SetEffects(int,int) | ?SetEffects@mmTextNode@@QAEXHH@Z
    0x4FF790 | public: void __thiscall mmTextNode::GetTextDimensions(void *,struct LocString *,float &,float &) | ?GetTextDimensions@mmTextNode@@QAEXPAXPAULocString@@AAM2@Z
    0x4FF8D0 | public: void __thiscall mmTextNode::SetTextPosition(int,float,float) | ?SetTextPosition@mmTextNode@@QAEXHMM@Z
    0x4FF930 | public: int __thiscall mmTextNode::AddText(void *,struct LocString *,int,float,float) | ?AddText@mmTextNode@@QAEHPAXPAULocString@@HMM@Z
    0x4FFA40 | public: void __thiscall mmTextNode::SetString(int,struct LocString *) | ?SetString@mmTextNode@@QAEXHPAULocString@@@Z
    0x4FFAA0 | public: void __thiscall mmTextNode::SetPosition(int,float,float) | ?SetPosition@mmTextNode@@QAEXHMM@Z
    0x4FFB00 | public: void __cdecl mmTextNode::Printf(char const *,...) | ?Printf@mmTextNode@@QAAXPBDZZ
    0x4FFB30 | public: virtual void __thiscall mmTextNode::Update(void) | ?Update@mmTextNode@@UAEXXZ
    0x4FFB60 | public: void __thiscall mmTextNode::RenderText(class agiSurfaceDesc *,struct mmTextData *,int,unsigned int) | ?RenderText@mmTextNode@@QAEXPAVagiSurfaceDesc@@PAUmmTextData@@HI@Z
    0x4FFD90 | public: virtual void __thiscall mmTextNode::Cull(void) | ?Cull@mmTextNode@@UAEXXZ
    0x4FFE70 | public: virtual void * __thiscall mmTextNode::`scalar deleting destructor'(unsigned int) | ??_GmmTextNode@@UAEPAXI@Z
    0x620658 | const mmTextNode::`vftable' | ??_7mmTextNode@@6B@
*/

#include "arts7/node.h"

#ifdef CreateFont
#    undef CreateFont
#endif

class agiBitmap;
class agiSurfaceDesc;

struct mmText
{
public:
    // ??0mmText@@QAE@XZ
    ARTS_EXPORT mmText() = default;

    // ??1mmText@@QAE@XZ
    ARTS_EXPORT ~mmText() = default;

    // ?Draw@mmText@@QAEXPAVagiSurfaceDesc@@MMPADPAX@Z | unused
    ARTS_EXPORT void Draw(agiSurfaceDesc* surface, f32 x, f32 y, char* text, void* font);

    // ?Draw2@mmText@@QAEXPAVagiSurfaceDesc@@MMPADPAXI@Z
    ARTS_EXPORT void Draw2(agiSurfaceDesc* surface, f32 x, f32 y, char* text, void* font, u32 color);

    // ?CreateFitBitmap@mmText@@SAPAVagiBitmap@@PADPAXHH@Z
    ARTS_EXPORT static RcOwner<agiBitmap> CreateFitBitmap(char* text, void* font, i32 color, i32 bg_color);

    // ?CreateFont@mmText@@SAPAXPADH@Z
    ARTS_EXPORT static void* CreateFont(const char* font_name, i32 height);

    // ?CreateLocFont@mmText@@SAPAXPAULocString@@H@Z
    ARTS_EXPORT static void* CreateLocFont(LocString* params, i32 screen_width);

    // ?DeleteFont@mmText@@SAXPAX@Z
    ARTS_EXPORT static void DeleteFont(void* font);

    // ?GetDC@mmText@@SAPAXPAVagiSurfaceDesc@@@Z
    ARTS_EXPORT static void* GetDC(agiSurfaceDesc* surface);

    // ?ReleaseDC@mmText@@SAXXZ
    ARTS_EXPORT static void ReleaseDC();

private:
    u8 byte0 {1};
    u8 byte1 {};
};

check_size(mmText, 0x2);

#define MM_TEXT_VCENTER 0x1    // Centers text vertically
#define MM_TEXT_CENTER 0x2     // Centers text horizontally
#define MM_TEXT_BORDER 0x4     // Draw a white border
#define MM_TEXT_PADDING 0x10   // Shift text 2 pixels to the right
#define MM_TEXT_WORDBREAK 0x20 // Breaks lines which extend past the rectangle
#define MM_TEXT_REQUIRED 0x40  // Draw even if the text is empty
#define MM_TEXT_HIGHLIGHT 0x80 // Draws text using the highlight color (unimplemented)
#define MM_TEXT_RIGHT 0x100    // Aligns text to the right
#define MM_TEXT_BOTTOM 0x200   // Aligns text to the bottom

struct mmTextData
{
    u32 X {};
    u32 Y {};

    // 0x1 | Vertical Centered
    // 0x2 | Horizontal Centered
    // 0x4 | White Border
    // 0x10 | Move right 2 pixels
    // 0x20 | Word Break
    // 0x40 | Always Draw
    // 0x80 | Highlight text
    u32 Effects {};
    void* Font {};
    char Text[256] {};
};

check_size(mmTextData, 0x110);

class mmTextNode final : public asNode
{
public:
    // ??0mmTextNode@@QAE@XZ
    ARTS_EXPORT mmTextNode();

    // ??_EmmTextNode@@UAEPAXI@Z
    // ??_GmmTextNode@@UAEPAXI@Z | unused
    // ??1mmTextNode@@UAE@XZ
    ARTS_EXPORT ~mmTextNode() override;

    // ?AddText@mmTextNode@@QAEHPAXPAULocString@@HMM@Z
    ARTS_IMPORT i32 AddText(void* font, LocString* text, i32 effects, f32 x, f32 y);

    // ?Cull@mmTextNode@@UAEXXZ
    ARTS_EXPORT void Cull() override;

    // ?GetFGColor@mmTextNode@@QAEIXZ
    ARTS_IMPORT u32 GetFGColor();

    // ?GetTextDimensions@mmTextNode@@QAEXPAXPAULocString@@AAM2@Z
    ARTS_EXPORT void GetTextDimensions(void* font, LocString* text, f32& width, f32& height);

    // ?Init@mmTextNode@@QAEXMMMMHH@Z
    ARTS_EXPORT void Init(f32 x, f32 y, f32 width, f32 height, i32 num_lines, i32 flags);

    // ?Printf@mmTextNode@@QAAXPBDZZ | unused
    ARTS_IMPORT void Printf(const char* arg1, ...);

    // ?RenderText@mmTextNode@@QAEXPAVagiSurfaceDesc@@PAUmmTextData@@HI@Z
    ARTS_EXPORT void RenderText(agiSurfaceDesc* surface, mmTextData* lines, i32 num_lines, u32 enabled_lines);

    // ?SetBGColor@mmTextNode@@QAEXAAVVector4@@@Z | unused
    ARTS_IMPORT void SetBGColor(Vector4& arg1);

    // ?SetEffects@mmTextNode@@QAEXHH@Z
    ARTS_IMPORT void SetEffects(i32 line, i32 effects);

    // ?SetFGColor@mmTextNode@@QAEXAAVVector4@@@Z
    ARTS_IMPORT void SetFGColor(Vector4& arg1);

    // ?SetPosition@mmTextNode@@QAEXHMM@Z
    ARTS_IMPORT void SetPosition(i32 arg1, f32 arg2, f32 arg3);

    // ?SetString@mmTextNode@@QAEXHPAULocString@@@Z
    ARTS_EXPORT void SetString(i32 line, LocString* text);

    // ?SetTextPosition@mmTextNode@@QAEXHMM@Z
    ARTS_IMPORT void SetTextPosition(i32 arg1, f32 arg2, f32 arg3);

    // ?Update@mmTextNode@@UAEXXZ
    ARTS_IMPORT void Update() override;

    agiBitmap* GetBitmap()
    {
        return text_bitmap_.get();
    }

private:
    f32 x_ {};
    f32 y_ {};
    i32 line_count_ {};
    i32 max_lines_ {};
    u32 enabled_lines_ {0xFFFFFFFF};
    mmText int30_ {};
    Ptr<mmTextData[]> lines_;
    Rc<agiBitmap> text_bitmap_;
    u32 touched_ {1};
    u32 empty_ {};
    u32 format_ {};
    u32 fg_color_ {0xFFFFFF};
    u32 bg_color_ {};
};

check_size(mmTextNode, 0x54);

struct mmLocFontInfo
{
    mmLocFontInfo(LocString* params);
    ~mmLocFontInfo();

    char* FontName;

    i32 HeightLow;  // Pipe < 640
    i32 HeightHigh; // Pipe >= 640

    i32 CharSet;
    i32 Weight;

private:
    char* Context;
};

// ?ddGDIFlip@@YAXXZ | unused
ARTS_IMPORT void ddGDIFlip();

// RGBA <-> BGRA
inline u32 TwiddleColor(u32 color)
{
    return ((color >> 16) & 0xFF) | (color & 0xFF00) | ((color & 0xFF) << 16);
}
