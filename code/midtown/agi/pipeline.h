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

#include "surface.h"

#include "cmodel.h"
#include "render.h"

typedef struct SDL_Window SDL_Window;

class agiBitmap;
class agiColorModel;
class agiLight;
class agiLightModel;
class agiMtlDef;
class agiRefreshable;
class agiRenderer;
class agiTexDef;
class agiViewport;
class ipcMessageQueue;

struct agiMemStatus
{
    // SYS, AGP, LOCALVID, VID
    // Probably actually i32[4][3]
    i32 Texture[4];
    i32 Buffer[4];
    i32 Bitmap[4];
};

check_size(agiMemStatus, 0x30);

class agiPipeline
{
public:
    // ??1agiPipeline@@UAE@XZ
    virtual ~agiPipeline() = 0;

    // ?Validate@agiPipeline@@UAEHXZ
    virtual i32 Validate();

    virtual i32 BeginGfx() = 0;

    virtual void EndGfx() = 0;

    // ?BeginFrame@agiPipeline@@UAEXXZ
    virtual void BeginFrame();

    // ?BeginScene@agiPipeline@@UAEXXZ
    virtual void BeginScene();

    // ?EndScene@agiPipeline@@UAEXXZ
    virtual void EndScene();

    // ?EndFrame@agiPipeline@@UAEXXZ
    virtual void EndFrame();

    virtual RcOwner<agiTexDef> CreateTexDef() = 0;

    virtual RcOwner<agiTexLut> CreateTexLut() = 0;

    // ?CreateMtlDef@agiPipeline@@UAEPAVagiMtlDef@@XZ
    virtual RcOwner<agiMtlDef> CreateMtlDef();

    virtual RcOwner<DLP> CreateDLP() = 0;

    virtual RcOwner<agiViewport> CreateViewport() = 0;

    // ?CreateLight@agiPipeline@@UAEPAVagiLight@@XZ
    virtual RcOwner<agiLight> CreateLight();

    // ?CreateLightModel@agiPipeline@@UAEPAVagiLightModel@@XZ
    virtual RcOwner<agiLightModel> CreateLightModel();

    // ?CreateBitmap@agiPipeline@@UAEPAVagiBitmap@@XZ
    virtual RcOwner<agiBitmap> CreateBitmap();

    // ?CopyBitmap@agiPipeline@@UAEXHHPAVagiBitmap@@HHHH@Z
    virtual void CopyBitmap(
        i32 dst_x, i32 dst_y, agiBitmap* src, i32 src_x, i32 src_y, i32 width, i32 height);

    virtual void ClearAll(i32 color) = 0;

    // ?ClearRect@agiPipeline@@UAEXHHHHI@Z
    virtual void ClearRect(i32 x, i32 y, i32 width, i32 height, u32 color);

    // ?Print@agiPipeline@@UAEXHHHPBD@Z | agi:print
    virtual void Print(i32 x, i32 y, i32 color, const char* text);

    // ?PrintIs3D@agiPipeline@@UAEHXZ | agi:print
    virtual b32 PrintIs3D();

    // ?PrintInit@agiPipeline@@UAEXXZ | agi:print
    virtual void PrintInit();

    // ?PrintShutdown@agiPipeline@@UAEXXZ | agi:print
    virtual void PrintShutdown();

    // ?Defragment@agiPipeline@@UAEXXZ
    virtual void Defragment();

    // ?LockFrameBuffer@agiPipeline@@UAEHAAVagiSurfaceDesc@@@Z
    virtual b32 LockFrameBuffer(agiSurfaceDesc& arg1);

    // ?UnlockFrameBuffer@agiPipeline@@UAEXXZ
    virtual void UnlockFrameBuffer();

    // ?DumpStatus@agiPipeline@@UAEXAAUagiMemStatus@@@Z
    virtual void DumpStatus(agiMemStatus& arg1);

    // ?BeginAllGfx@agiPipeline@@QAEHXZ
    i32 BeginAllGfx();

    // ?CopyClippedBitmap@agiPipeline@@QAEHHHPAVagiBitmap@@HHHH@Z
    ARTS_EXPORT b32 CopyClippedBitmap(
        i32 dst_x, i32 dst_y, agiBitmap* src, i32 src_x, i32 src_y, i32 width, i32 height);

    // ?CopyClippedBitmap@agiPipeline@@QAEHHHPAVagiBitmap@@HHHHHHHH@Z
    ARTS_EXPORT b32 CopyClippedBitmap(i32 dst_x, i32 dst_y, agiBitmap* src, i32 src_x, i32 src_y, i32 width, i32 height,
        i32 min_x, i32 min_y, i32 max_x, i32 max_y);

    void ClearBorder(i32 x, i32 y, i32 width, i32 height, u32 color);

    // ?DumpStatus@agiPipeline@@QAEXXZ | unused
    void DumpStatus();

    // ?EndAllGfx@agiPipeline@@QAEXXZ
    void EndAllGfx();

    // ?GetBitmap@agiPipeline@@QAEPAVagiBitmap@@PADMMH@Z
    RcOwner<agiBitmap> GetBitmap(const char* name, f32 sx, f32 sy, i32 flags);

    // ?GetDLP@agiPipeline@@QAEPAVDLP@@PAD0PAVVector3@@HH@Z
    ARTS_IMPORT RcOwner<DLP> GetDLP(aconst char* arg1, aconst char* arg2, Vector3* arg3, i32 arg4, i32 arg5);

    // ?GetMaterial@agiPipeline@@QAEPAVagiMtlDef@@H@Z
    ARTS_IMPORT RcOwner<agiMtlDef> GetMaterial(i32 arg1);

    // ?GetTexLut@agiPipeline@@QAEPAVagiTexLut@@PAD@Z
    ARTS_IMPORT RcOwner<agiTexLut> GetTexLut(aconst char* arg1);

    // ?GetTexture@agiPipeline@@QAEPAVagiTexDef@@PADH@Z
    RcOwner<agiTexDef> GetTexture(const char* name, i32 pack_shift);

    // ?GetTexture@agiPipeline@@QAEPAVagiTexDef@@HH@Z
    ARTS_EXPORT RcOwner<agiTexDef> GetTexture(i32 index, i32 pack_shift);

    // ?Init@agiPipeline@@QAEHPADHHHHHHPAX@Z | unused
    i32 Init(const char* name, i32 x, i32 y, i32 width, i32 height, i32 bit_depth, i32 flags, SDL_Window* window);

    // ?NotifyDelete@agiPipeline@@QAEXPAVagiRefreshable@@@Z
    void NotifyDelete(agiRefreshable* ptr);

    // ?NotifyNew@agiPipeline@@QAEXPAVagiRefreshable@@@Z
    void NotifyNew(agiRefreshable* ptr);

    // ?RestoreAll@agiPipeline@@QAEXXZ
    void RestoreAll();

    // ?ValidateObject@agiPipeline@@QAEXPAVagiRefreshable@@@Z | unused
    void ValidateObject(agiRefreshable* ptr);

    static void RequestScreenShot(ConstString file_name);

    // ?CurrentPipe@agiPipeline@@2PAV1@A
    ARTS_IMPORT static agiPipeline* CurrentPipe;

    // ?CurrentRenderer@agiPipeline@@2PAVagiRenderer@@A
    ARTS_IMPORT static agiRenderer* CurrentRenderer;

    i32 GetWidth() const
    {
        return width_;
    }

    i32 GetHeight() const
    {
        return height_;
    }

    i32 GetDepth() const
    {
        return bit_depth_;
    }

    bool HaveGfxStarted() const
    {
        return gfx_started_;
    }

    const agiSurfaceDesc& GetScreenFormat() const
    {
        return screen_format_;
    }

    const agiSurfaceDesc& GetOpaqueFormat() const
    {
        return opaque_format_;
    }

    const agiSurfaceDesc& GetAlphaFormat() const
    {
        return alpha_format_;
    }

    const Rc<agiColorModel>& GetScreenColorModel() const
    {
        return screen_color_model_;
    }

    const Rc<agiColorModel>& GetOpaqueColorModel() const
    {
        return opaque_color_model_;
    }

    const Rc<agiColorModel>& GetAlphaColorModel() const
    {
        return alpha_color_model_;
    }

    bool IsHardware() const
    {
        return flags_ & 0x4;
    }

    bool SupportsAlpha() const
    {
        return flags_ & 0x10;
    }

    i32 GetSceneIndex() const
    {
        return scene_index_;
    }

    u32 GetDword38() const
    {
        return field_38;
    }

    i32 GetHorzRes() const
    {
        return horz_res_;
    }

    i32 GetVertRes() const
    {
        return vert_res_;
    }

    void SetRes(i32 width, i32 height)
    {
        width_ = width;
        height_ = height;
    }

    void SetWindow(SDL_Window* window)
    {
        window_ = window;
    }

    void RoundNormalized(f32& x, f32& y)
    {
        x = std::round(x * width_) / width_;
        y = std::round(y * height_) / height_;
    }

protected:
    // ??0agiPipeline@@IAE@XZ
    agiPipeline();

    static bool ScreenShotRequested();
    static void SaveScreenShot(Ptr<agiSurfaceDesc> surface);

    ConstString name_;
    i32 x_ {};
    i32 y_ {};
    i32 width_ {};
    i32 height_ {};
    i32 bit_depth_ {};

    // 0x1 | Enable VSync ?
    // 0x2 | Use Video Ram (-vram, -system)
    // 0x4 | Single Buffer ?
    // 0x10 | Enable Z Buffer
    // 0x20 | Enable Z Buffer 2 ? (-debug, -primary)
    // 0x80 | Low?
    // 0x100 | Enable TexLut (-paltex)
    // 0x400 | Ramp Emulation (-ramp)
    // 0x800 | RGB Emulation (-rgb, -debug)
    // 0x1000 | Direct3D HAL (-hal)
    // 0x2000 | MMX Emulation (-mmx)
    i32 device_flags_1_ {}; // Main Flags
    i32 device_flags_2_ {};
    i32 device_flags_3_ {}; // UI Flags

    SDL_Window* window_ {};
    i32 horz_res_ {};
    i32 vert_res_ {};
    f32 scale_ {1.0f};
    u32 field_38 {2}; // ViewIndex ?
    u32 light_mask_ {0xFFFFFFFF};
    char gap40[260] {};

    // 0x1 | 16-bit
    // 0x2 | 24-bit
    // 0x4 | 32-bit
    i32 valid_bit_depths_ {};

    agiSurfaceDesc screen_format_ {};
    agiSurfaceDesc opaque_format_ {};
    agiSurfaceDesc alpha_format_ {};

    Rc<agiColorModel> screen_color_model_;
    Rc<agiColorModel> opaque_color_model_;
    Rc<agiColorModel> alpha_color_model_;
    Rc<agiColorModel> text_color_model_;

    Rc<agiRenderer> renderer_;

    b32 is_software_ {};
    i32 max_tex_width_ {};
    i32 max_tex_height_ {};
    agiRefreshable* objects_ {};
    b32 gfx_started_ {};

    // 0x1 | Z Buffer
    // 0x4 | Hardware
    // 0x10 | Supports Alpha
    // 0x20 | Square Textures
    u32 flags_ {};
    b32 in_scene_ {};
    i32 scene_index_ {};
};

check_size(agiPipeline, 0x2F0);

inline agiPipeline* Pipe()
{
    return agiPipeline::CurrentPipe;
}

// ?CreatePipelineAttachableWindow@@YAPAXPADHHHHPAX@Z
SDL_Window* CreatePipelineAttachableWindow(const char* title, i32 x, i32 y, i32 width, i32 height, void* ptr);

// ?DestroyPipelineAttachableWindow@@YAXXZ
void DestroyPipelineAttachableWindow();

// ?GetRootWindow@@YAPAXXZ
SDL_Window* GetRootWindow();

// ?DrawModeAnd@@3HA
ARTS_IMPORT extern i32 DrawModeAnd;

// ?DrawModeOr@@3HA
ARTS_IMPORT extern i32 DrawModeOr;

// ?LightCount@@3HA
ARTS_IMPORT extern i32 LightCount;

// ?PROBER@@3P6AXPAX@ZA
ARTS_IMPORT extern void (*PROBER)(void*);

struct agiStats
{
    i32 DlpDrawn;
    i32 DlpClipped;
    i32 DlpVerts;
    i32 DlpTris;
    i32 VertsXfrm;
    i32 VertsLit;
    i32 VertsOut;
    i32 VertsClip;
    i32 Tris;
    i32 Lines;
    i32 Cards;
    i32 StateChanges;
    i32 TextureChanges;
    i32 StateChangeCalls;
    i32 GeomCalls;
    i32 TxlsXrfd;
    i32 XtraTex;
};

check_size(agiStats, 0x44);

// ?STATS@@3UagiStats@@A
ARTS_IMPORT extern agiStats STATS;

// ?ZFill@@3HA
ARTS_IMPORT extern i32 ZFill;

#ifdef ARTS_DEV_BUILD
// ?agiBeginFrame@@3KA
ARTS_IMPORT extern ulong agiBeginFrame;

// ?agiBeginScene@@3KA
ARTS_IMPORT extern ulong agiBeginScene;

// ?agiBitmapCount@@3HA
ARTS_IMPORT extern i32 agiBitmapCount;

// ?agiBitmapPixels@@3HA
ARTS_IMPORT extern i32 agiBitmapPixels;

// ?agiClearViewport@@3KA
ARTS_IMPORT extern ulong agiClearViewport;

// ?agiClipTimer@@3KA
ARTS_IMPORT extern ulong agiClipTimer;

// ?agiCopyBitmap@@3KA
ARTS_IMPORT extern ulong agiCopyBitmap;
#endif

// ?agiEnableZBuffer@@3DA
ARTS_IMPORT extern char agiEnableZBuffer;

#ifdef ARTS_DEV_BUILD
// ?agiEndFrame@@3KA
ARTS_IMPORT extern ulong agiEndFrame;

// ?agiEndScene@@3KA
ARTS_IMPORT extern ulong agiEndScene;

// ?agiFirstPass@@3KA
ARTS_IMPORT extern ulong agiFirstPass;

// ?agiInvertTimer@@3KA
ARTS_IMPORT extern ulong agiInvertTimer;

// ?agiLightTimer@@3KA
ARTS_IMPORT extern ulong agiLightTimer;

// ?agiRasterization@@3KA
ARTS_IMPORT extern ulong agiRasterization;

// ?agiSecondPass@@3KA
ARTS_IMPORT extern ulong agiSecondPass;

// ?agiStateChanges@@3KA
ARTS_IMPORT extern ulong agiStateChanges;

// ?agiTransformTimer@@3KA
ARTS_IMPORT extern ulong agiTransformTimer;

// ?agiTraverseTimer@@3KA
ARTS_IMPORT extern ulong agiTraverseTimer;
#endif

extern ipcMessageQueue GFXPAGER;

extern i32 UI_XPos;
extern i32 UI_YPos;

extern i32 UI_Width;
extern i32 UI_Height;

extern f32 UI_StartX;
extern f32 UI_StartY;

extern f32 UI_ScaleX;
extern f32 UI_ScaleY;

extern f32 UI_FullW;
extern f32 UI_FullH;

extern mem::cmd_param PARAM_width;
extern mem::cmd_param PARAM_height;
extern mem::cmd_param PARAM_depth;
extern mem::cmd_param PARAM_vsync;
extern mem::cmd_param PARAM_window;

extern mem::cmd_param PARAM_afilter;
extern mem::cmd_param PARAM_annotate;
extern mem::cmd_param PARAM_labelf;
extern mem::cmd_param PARAM_labelp;
extern mem::cmd_param PARAM_mip;
extern mem::cmd_param PARAM_multitex;
extern mem::cmd_param PARAM_nfog;
extern mem::cmd_param PARAM_pack;
extern mem::cmd_param PARAM_square;
