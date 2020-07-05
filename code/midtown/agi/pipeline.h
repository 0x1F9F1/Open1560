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
    agi:pipeline

    0x555480 | protected: __thiscall agiPipeline::agiPipeline(void) | ??0agiPipeline@@IAE@XZ
    0x555540 | public: virtual int __thiscall agiPipeline::Validate(void) | ?Validate@agiPipeline@@UAEHXZ
    0x555550 | public: int __thiscall agiPipeline::Init(char *,int,int,int,int,int,int,void *) | ?Init@agiPipeline@@QAEHPADHHHHHHPAX@Z
    0x5555C0 | public: class agiTexDef * __thiscall agiPipeline::GetTexture(char *,int) | ?GetTexture@agiPipeline@@QAEPAVagiTexDef@@PADH@Z
    0x555620 | public: class agiTexDef * __thiscall agiPipeline::GetTexture(int,int) | ?GetTexture@agiPipeline@@QAEPAVagiTexDef@@HH@Z
    0x555750 | public: class agiBitmap * __thiscall agiPipeline::GetBitmap(char *,float,float,int) | ?GetBitmap@agiPipeline@@QAEPAVagiBitmap@@PADMMH@Z
    0x5557F0 | public: class agiTexLut * __thiscall agiPipeline::GetTexLut(char *) | ?GetTexLut@agiPipeline@@QAEPAVagiTexLut@@PAD@Z
    0x555860 | public: class agiMtlDef * __thiscall agiPipeline::GetMaterial(char *) | ?GetMaterial@agiPipeline@@QAEPAVagiMtlDef@@PAD@Z
    0x5558C0 | public: class agiMtlDef * __thiscall agiPipeline::GetMaterial(int) | ?GetMaterial@agiPipeline@@QAEPAVagiMtlDef@@H@Z
    0x555950 | public: class DLP * __thiscall agiPipeline::GetDLP(char *,char *,class Vector3 *,int,int) | ?GetDLP@agiPipeline@@QAEPAVDLP@@PAD0PAVVector3@@HH@Z
    0x555B10 | public: virtual class agiMtlDef * __thiscall agiPipeline::CreateMtlDef(void) | ?CreateMtlDef@agiPipeline@@UAEPAVagiMtlDef@@XZ
    0x555B20 | public: virtual class agiLight * __thiscall agiPipeline::CreateLight(void) | ?CreateLight@agiPipeline@@UAEPAVagiLight@@XZ
    0x555B30 | public: virtual class agiLightModel * __thiscall agiPipeline::CreateLightModel(void) | ?CreateLightModel@agiPipeline@@UAEPAVagiLightModel@@XZ
    0x555B40 | public: int __thiscall agiPipeline::BeginAllGfx(void) | ?BeginAllGfx@agiPipeline@@QAEHXZ
    0x555C40 | public: void __thiscall agiPipeline::EndAllGfx(void) | ?EndAllGfx@agiPipeline@@QAEXXZ
    0x555CD0 | public: void __thiscall agiPipeline::RestoreAll(void) | ?RestoreAll@agiPipeline@@QAEXXZ
    0x555D10 | public: virtual void __thiscall agiPipeline::BeginFrame(void) | ?BeginFrame@agiPipeline@@UAEXXZ
    0x555D30 | public: virtual class agiBitmap * __thiscall agiPipeline::CreateBitmap(void) | ?CreateBitmap@agiPipeline@@UAEPAVagiBitmap@@XZ
    0x555D40 | public: virtual void __thiscall agiPipeline::CopyBitmap(int,int,class agiBitmap *,int,int,int,int) | ?CopyBitmap@agiPipeline@@UAEXHHPAVagiBitmap@@HHHH@Z
    0x555D50 | public: int __thiscall agiPipeline::CopyClippedBitmap(int,int,class agiBitmap *,int,int,int,int) | ?CopyClippedBitmap@agiPipeline@@QAEHHHPAVagiBitmap@@HHHH@Z
    0x555D90 | public: int __thiscall agiPipeline::CopyClippedBitmap(int,int,class agiBitmap *,int,int,int,int,int,int,int,int) | ?CopyClippedBitmap@agiPipeline@@QAEHHHPAVagiBitmap@@HHHHHHHH@Z
    0x555E40 | public: void __thiscall agiPipeline::NotifyNew(class agiRefreshable *) | ?NotifyNew@agiPipeline@@QAEXPAVagiRefreshable@@@Z
    0x555E70 | public: void __thiscall agiPipeline::NotifyDelete(class agiRefreshable *) | ?NotifyDelete@agiPipeline@@QAEXPAVagiRefreshable@@@Z
    0x555EB0 | public: void __thiscall agiPipeline::ValidateObject(class agiRefreshable *) | ?ValidateObject@agiPipeline@@QAEXPAVagiRefreshable@@@Z
    0x555F00 | public: void __thiscall agiPipeline::DumpStatus(void) | ?DumpStatus@agiPipeline@@QAEXXZ
    0x555F70 | void * __cdecl GetRootWindow(void) | ?GetRootWindow@@YAPAXXZ
    0x555F80 | void * __cdecl CreatePipelineAttachableWindow(char *,int,int,int,int,void *) | ?CreatePipelineAttachableWindow@@YAPAXPADHHHHPAX@Z
    0x555F90 | void __cdecl DestroyPipelineAttachableWindow(void) | ?DestroyPipelineAttachableWindow@@YAXXZ
    0x555FA0 | public: virtual __thiscall agiPipeline::~agiPipeline(void) | ??1agiPipeline@@UAE@XZ
    0x556000 | public: virtual void __thiscall agiPipeline::BeginScene(void) | ?BeginScene@agiPipeline@@UAEXXZ
    0x556020 | public: virtual void __thiscall agiPipeline::EndScene(void) | ?EndScene@agiPipeline@@UAEXXZ
    0x556030 | public: virtual void __thiscall agiPipeline::EndFrame(void) | ?EndFrame@agiPipeline@@UAEXXZ
    0x556040 | public: virtual int __thiscall agiPipeline::LockFrameBuffer(class agiSurfaceDesc &) | ?LockFrameBuffer@agiPipeline@@UAEHAAVagiSurfaceDesc@@@Z
    0x556050 | public: virtual void __thiscall agiPipeline::UnlockFrameBuffer(void) | ?UnlockFrameBuffer@agiPipeline@@UAEXXZ
    0x556060 | public: virtual void __thiscall agiPipeline::DumpStatus(struct agiMemStatus &) | ?DumpStatus@agiPipeline@@UAEXAAUagiMemStatus@@@Z
    0x556070 | public: virtual void __thiscall agiPipeline::ClearRect(int,int,int,int,unsigned int) | ?ClearRect@agiPipeline@@UAEXHHHHI@Z
    0x556080 | public: virtual void __thiscall agiPipeline::Defragment(void) | ?Defragment@agiPipeline@@UAEXXZ
    0x621548 | const agiPipeline::`vftable' | ??_7agiPipeline@@6B@
    0x6565B8 | int ZFill | ?ZFill@@3HA
    0x6565BC | char agiEnableZBuffer | ?agiEnableZBuffer@@3DA
    0x8FAC18 | struct agiStats STATS | ?STATS@@3UagiStats@@A
    0x8FAC5C | unsigned long agiBeginFrame | ?agiBeginFrame@@3KA
    0x8FAC60 | unsigned long agiLightTimer | ?agiLightTimer@@3KA
    0x8FAC64 | unsigned long agiCopyBitmap | ?agiCopyBitmap@@3KA
    0x8FAC68 | int agiBitmapPixels | ?agiBitmapPixels@@3HA
    0x8FAC6C | unsigned long agiEndFrame | ?agiEndFrame@@3KA
    0x8FAC70 | int agiBitmapCount | ?agiBitmapCount@@3HA
    0x8FACA0 | unsigned long agiTraverseTimer | ?agiTraverseTimer@@3KA
    0x8FACA4 | unsigned long agiEndScene | ?agiEndScene@@3KA
    0x8FACA8 | unsigned long agiBeginScene | ?agiBeginScene@@3KA
    0x8FACAC | public: static class agiRenderer * agiPipeline::CurrentRenderer | ?CurrentRenderer@agiPipeline@@2PAVagiRenderer@@A
    0x8FACB0 | unsigned long agiRasterization | ?agiRasterization@@3KA
    0x8FACB4 | public: static class agiPipeline * agiPipeline::CurrentPipe | ?CurrentPipe@agiPipeline@@2PAV1@A
    0x8FACB8 | unsigned long agiSecondPass | ?agiSecondPass@@3KA
    0x8FACBC | unsigned long agiTransformTimer | ?agiTransformTimer@@3KA
    0x8FACC0 | void (__cdecl* PROBER)(void *) | ?PROBER@@3P6AXPAX@ZA
    0x8FACC4 | unsigned long agiInvertTimer | ?agiInvertTimer@@3KA
    0x8FACC8 | unsigned long agiStateChanges | ?agiStateChanges@@3KA
    0x8FACCC | unsigned long agiClipTimer | ?agiClipTimer@@3KA
    0x8FACD0 | unsigned long agiFirstPass | ?agiFirstPass@@3KA
    0x8FACD4 | unsigned long agiClearViewport | ?agiClearViewport@@3KA
    0x8FACD8 | int LightCount | ?LightCount@@3HA
    0x8FACDC | int DrawModeOr | ?DrawModeOr@@3HA
    0x8FACE0 | int DrawModeAnd | ?DrawModeAnd@@3HA
*/

#include "surface.h"

class agiRefreshable;

class agiPipeline
{
    // const agiPipeline::`vftable' @ 0x621548

public:
    // 0x555FA0 | ??1agiPipeline@@UAE@XZ
    virtual ~agiPipeline() = 0;

    // 0x555540 | ?Validate@agiPipeline@@UAEHXZ
    ARTS_EXPORT virtual i32 Validate();

    virtual i32 BeginGfx() = 0;

    virtual void EndGfx() = 0;

    // 0x555D10 | ?BeginFrame@agiPipeline@@UAEXXZ
    ARTS_EXPORT virtual void BeginFrame();

    // 0x556000 | ?BeginScene@agiPipeline@@UAEXXZ
    ARTS_IMPORT virtual void BeginScene();

    // 0x556020 | ?EndScene@agiPipeline@@UAEXXZ
    ARTS_EXPORT virtual void EndScene();

    // 0x556030 | ?EndFrame@agiPipeline@@UAEXXZ
    ARTS_EXPORT virtual void EndFrame();

    virtual class agiTexDef* CreateTexDef() = 0;

    virtual class agiTexLut* CreateTexLut() = 0;

    // 0x555B10 | ?CreateMtlDef@agiPipeline@@UAEPAVagiMtlDef@@XZ
    ARTS_EXPORT virtual class agiMtlDef* CreateMtlDef();

    virtual class DLP* CreateDLP() = 0;

    virtual class agiViewport* CreateViewport() = 0;

    // 0x555B20 | ?CreateLight@agiPipeline@@UAEPAVagiLight@@XZ
    ARTS_EXPORT virtual class agiLight* CreateLight();

    // 0x555B30 | ?CreateLightModel@agiPipeline@@UAEPAVagiLightModel@@XZ
    ARTS_EXPORT virtual class agiLightModel* CreateLightModel();

    // 0x555D30 | ?CreateBitmap@agiPipeline@@UAEPAVagiBitmap@@XZ
    ARTS_EXPORT virtual class agiBitmap* CreateBitmap();

    // 0x555D40 | ?CopyBitmap@agiPipeline@@UAEXHHPAVagiBitmap@@HHHH@Z
    ARTS_EXPORT virtual void CopyBitmap(
        i32 dst_x, i32 dst_y, class agiBitmap* src, i32 src_x, i32 src_y, i32 width, i32 height);

    virtual void ClearAll(i32 arg1) = 0;

    // 0x556070 | ?ClearRect@agiPipeline@@UAEXHHHHI@Z
    ARTS_EXPORT virtual void ClearRect(i32 x, i32 y, i32 width, i32 height, u32 color);

    // 0x557F20 | ?Print@agiPipeline@@UAEXHHHPBD@Z | agi:print
    ARTS_IMPORT virtual void Print(i32 x, i32 y, i32 color, char const* text);

    // 0x558110 | ?PrintIs3D@agiPipeline@@UAEHXZ | agi:print
    ARTS_IMPORT virtual i32 PrintIs3D();

    // 0x558130 | ?PrintInit@agiPipeline@@UAEXXZ | agi:print
    ARTS_IMPORT virtual void PrintInit();

    // 0x558140 | ?PrintShutdown@agiPipeline@@UAEXXZ | agi:print
    ARTS_IMPORT virtual void PrintShutdown();

    // 0x556080 | ?Defragment@agiPipeline@@UAEXXZ
    ARTS_EXPORT virtual void Defragment();

    // 0x556040 | ?LockFrameBuffer@agiPipeline@@UAEHAAVagiSurfaceDesc@@@Z
    ARTS_EXPORT virtual i32 LockFrameBuffer(class agiSurfaceDesc& arg1);

    // 0x556050 | ?UnlockFrameBuffer@agiPipeline@@UAEXXZ
    ARTS_EXPORT virtual void UnlockFrameBuffer();

    // 0x556060 | ?DumpStatus@agiPipeline@@UAEXAAUagiMemStatus@@@Z
    ARTS_EXPORT virtual void DumpStatus(struct agiMemStatus& arg1);

    // 0x555B40 | ?BeginAllGfx@agiPipeline@@QAEHXZ
    ARTS_IMPORT i32 BeginAllGfx();

    // 0x555D50 | ?CopyClippedBitmap@agiPipeline@@QAEHHHPAVagiBitmap@@HHHH@Z
    ARTS_IMPORT i32 CopyClippedBitmap(
        i32 arg1, i32 arg2, class agiBitmap* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7);

    // 0x555D90 | ?CopyClippedBitmap@agiPipeline@@QAEHHHPAVagiBitmap@@HHHHHHHH@Z
    ARTS_IMPORT i32 CopyClippedBitmap(i32 arg1, i32 arg2, class agiBitmap* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7,
        i32 arg8, i32 arg9, i32 arg10, i32 arg11);

    // 0x555F00 | ?DumpStatus@agiPipeline@@QAEXXZ | unused
    ARTS_IMPORT void DumpStatus();

    // 0x555C40 | ?EndAllGfx@agiPipeline@@QAEXXZ
    ARTS_IMPORT void EndAllGfx();

    // 0x555750 | ?GetBitmap@agiPipeline@@QAEPAVagiBitmap@@PADMMH@Z
    ARTS_IMPORT class agiBitmap* GetBitmap(char* arg1, f32 arg2, f32 arg3, i32 arg4);

    // 0x555950 | ?GetDLP@agiPipeline@@QAEPAVDLP@@PAD0PAVVector3@@HH@Z
    ARTS_IMPORT class DLP* GetDLP(char* arg1, char* arg2, class Vector3* arg3, i32 arg4, i32 arg5);

    // 0x555860 | ?GetMaterial@agiPipeline@@QAEPAVagiMtlDef@@PAD@Z | unused
    ARTS_IMPORT class agiMtlDef* GetMaterial(char* arg1);

    // 0x5558C0 | ?GetMaterial@agiPipeline@@QAEPAVagiMtlDef@@H@Z
    ARTS_IMPORT class agiMtlDef* GetMaterial(i32 arg1);

    // 0x5557F0 | ?GetTexLut@agiPipeline@@QAEPAVagiTexLut@@PAD@Z
    ARTS_IMPORT class agiTexLut* GetTexLut(char* arg1);

    // 0x5555C0 | ?GetTexture@agiPipeline@@QAEPAVagiTexDef@@PADH@Z
    ARTS_IMPORT class agiTexDef* GetTexture(char* arg1, i32 arg2);

    // 0x555620 | ?GetTexture@agiPipeline@@QAEPAVagiTexDef@@HH@Z
    ARTS_IMPORT class agiTexDef* GetTexture(i32 arg1, i32 arg2);

    // 0x555550 | ?Init@agiPipeline@@QAEHPADHHHHHHPAX@Z | unused
    ARTS_EXPORT i32 Init(const char* name, i32 x, i32 y, i32 width, i32 height, i32 bit_depth, i32 flags, void* window);

    // 0x555E70 | ?NotifyDelete@agiPipeline@@QAEXPAVagiRefreshable@@@Z
    ARTS_EXPORT void NotifyDelete(class agiRefreshable* ptr);

    // 0x555E40 | ?NotifyNew@agiPipeline@@QAEXPAVagiRefreshable@@@Z
    ARTS_EXPORT void NotifyNew(class agiRefreshable* ptr);

    // 0x555CD0 | ?RestoreAll@agiPipeline@@QAEXXZ
    ARTS_EXPORT void RestoreAll();

    // 0x555EB0 | ?ValidateObject@agiPipeline@@QAEXPAVagiRefreshable@@@Z | unused
    ARTS_EXPORT void ValidateObject(class agiRefreshable* ptr);

    // 0x8FACB4 | ?CurrentPipe@agiPipeline@@2PAV1@A
    ARTS_IMPORT static class agiPipeline* CurrentPipe;

    // 0x8FACAC | ?CurrentRenderer@agiPipeline@@2PAVagiRenderer@@A
    ARTS_IMPORT static class agiRenderer* CurrentRenderer;

protected:
    // 0x555480 | ??0agiPipeline@@IAE@XZ
    ARTS_IMPORT agiPipeline();

public:
    CString Name {};
    i32 X {0};
    i32 Y {0};
    i32 Width {0};
    i32 Height {0};
    i32 BitDepth {0};
    i32 DeviceFlags {0};
    i32 DeviceFlags2 {0};
    i32 DeviceFlags3 {0};
    void* Window {nullptr};
    i32 HorzRes {0};
    i32 VertRes {0};
    u8 gap34[0x114];
    agiSurfaceDesc ScreenFormat {};
    u8 gap1C4[0x118];
    agiRefreshable* Objects {nullptr};
    b32 GfxStarted {false};
    u8 gap2E4[0xC];
};

check_size(agiPipeline, 0x2F0);

// 0x555F80 | ?CreatePipelineAttachableWindow@@YAPAXPADHHHHPAX@Z
ARTS_EXPORT void* CreatePipelineAttachableWindow(char* title, i32 x, i32 y, i32 width, i32 height, void* ptr);

// 0x555F90 | ?DestroyPipelineAttachableWindow@@YAXXZ
ARTS_EXPORT void DestroyPipelineAttachableWindow();

// 0x555F70 | ?GetRootWindow@@YAPAXXZ
ARTS_EXPORT void* GetRootWindow();

// 0x8FACE0 | ?DrawModeAnd@@3HA
ARTS_IMPORT extern i32 DrawModeAnd;

// 0x8FACDC | ?DrawModeOr@@3HA
ARTS_IMPORT extern i32 DrawModeOr;

// 0x8FACD8 | ?LightCount@@3HA
ARTS_IMPORT extern i32 LightCount;

// 0x8FACC0 | ?PROBER@@3P6AXPAX@ZA
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

// 0x8FAC18 | ?STATS@@3UagiStats@@A
ARTS_IMPORT extern struct agiStats STATS;

// 0x6565B8 | ?ZFill@@3HA
ARTS_IMPORT extern i32 ZFill;

// 0x8FAC5C | ?agiBeginFrame@@3KA
ARTS_IMPORT extern u32 agiBeginFrame;

// 0x8FACA8 | ?agiBeginScene@@3KA
ARTS_IMPORT extern u32 agiBeginScene;

// 0x8FAC70 | ?agiBitmapCount@@3HA
ARTS_IMPORT extern i32 agiBitmapCount;

// 0x8FAC68 | ?agiBitmapPixels@@3HA
ARTS_IMPORT extern i32 agiBitmapPixels;

// 0x8FACD4 | ?agiClearViewport@@3KA
ARTS_IMPORT extern u32 agiClearViewport;

// 0x8FACCC | ?agiClipTimer@@3KA
ARTS_IMPORT extern u32 agiClipTimer;

// 0x8FAC64 | ?agiCopyBitmap@@3KA
ARTS_IMPORT extern u32 agiCopyBitmap;

// 0x6565BC | ?agiEnableZBuffer@@3DA
ARTS_IMPORT extern char agiEnableZBuffer;

// 0x8FAC6C | ?agiEndFrame@@3KA
ARTS_IMPORT extern u32 agiEndFrame;

// 0x8FACA4 | ?agiEndScene@@3KA
ARTS_IMPORT extern u32 agiEndScene;

// 0x8FACD0 | ?agiFirstPass@@3KA
ARTS_IMPORT extern u32 agiFirstPass;

// 0x8FACC4 | ?agiInvertTimer@@3KA
ARTS_IMPORT extern u32 agiInvertTimer;

// 0x8FAC60 | ?agiLightTimer@@3KA
ARTS_IMPORT extern u32 agiLightTimer;

// 0x8FACB0 | ?agiRasterization@@3KA
ARTS_IMPORT extern u32 agiRasterization;

// 0x8FACB8 | ?agiSecondPass@@3KA
ARTS_IMPORT extern u32 agiSecondPass;

// 0x8FACC8 | ?agiStateChanges@@3KA
ARTS_IMPORT extern u32 agiStateChanges;

// 0x8FACBC | ?agiTransformTimer@@3KA
ARTS_IMPORT extern u32 agiTransformTimer;

// 0x8FACA0 | ?agiTraverseTimer@@3KA
ARTS_IMPORT extern u32 agiTraverseTimer;
