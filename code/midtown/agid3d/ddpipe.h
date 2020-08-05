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
    agid3d:ddpipe

    0x5328C0 | public: virtual int __thiscall agiDDPipeline::Validate(void) | ?Validate@agiDDPipeline@@UAEHXZ
    0x5328D0 | int __stdcall DDCallback(struct _GUID *,char *,char *,void *) | ?DDCallback@@YGHPAU_GUID@@PAD1PAX@Z
    0x532950 | long __stdcall EnumModesCallback(struct _DDSURFACEDESC2 *,void *) | ?EnumModesCallback@@YGJPAU_DDSURFACEDESC2@@PAX@Z
    0x532A00 | long __stdcall EnumSurfsCallback(struct IDirectDrawSurface *,struct _DDSURFACEDESC *,void *) | ?EnumSurfsCallback@@YGJPAUIDirectDrawSurface@@PAU_DDSURFACEDESC@@PAX@Z
    0x532A40 | public: __thiscall agiDDPipeline::agiDDPipeline(void) | ??0agiDDPipeline@@QAE@XZ
    0x532AE0 | public: virtual int __thiscall agiDDPipeline::BeginGfx(void) | ?BeginGfx@agiDDPipeline@@UAEHXZ
    0x532E30 | public: virtual void __thiscall agiDDPipeline::EndGfx(void) | ?EndGfx@agiDDPipeline@@UAEXXZ
    0x532EF0 | public: virtual __thiscall agiDDPipeline::~agiDDPipeline(void) | ??1agiDDPipeline@@UAE@XZ
    0x532F40 | public: virtual void __thiscall agiDDPipeline::BeginFrame(void) | ?BeginFrame@agiDDPipeline@@UAEXXZ
    0x532FA0 | public: virtual void __thiscall agiDDPipeline::BeginScene(void) | ?BeginScene@agiDDPipeline@@UAEXXZ
    0x532FF0 | public: virtual void __thiscall agiDDPipeline::EndScene(void) | ?EndScene@agiDDPipeline@@UAEXXZ
    0x533000 | public: virtual void __thiscall agiDDPipeline::EndFrame(void) | ?EndFrame@agiDDPipeline@@UAEXXZ
    0x533010 | public: virtual class agiBitmap * __thiscall agiDDPipeline::CreateBitmap(void) | ?CreateBitmap@agiDDPipeline@@UAEPAVagiBitmap@@XZ
    0x533070 | public: virtual void __thiscall agiDDPipeline::CopyBitmap(int,int,class agiBitmap *,int,int,int,int) | ?CopyBitmap@agiDDPipeline@@UAEXHHPAVagiBitmap@@HHHH@Z
    0x5331E0 | public: virtual int __thiscall agiDDPipeline::LockFrameBuffer(class agiSurfaceDesc &) | ?LockFrameBuffer@agiDDPipeline@@UAEHAAVagiSurfaceDesc@@@Z
    0x533220 | public: virtual void __thiscall agiDDPipeline::UnlockFrameBuffer(void) | ?UnlockFrameBuffer@agiDDPipeline@@UAEXXZ
    0x533240 | public: virtual void __thiscall agiDDPipeline::ClearRect(int,int,int,int,unsigned int) | ?ClearRect@agiDDPipeline@@UAEXHHHHI@Z
    0x5332A0 | public: virtual void * __thiscall agiDDPipeline::`vector deleting destructor'(unsigned int) | ??_EagiDDPipeline@@UAEPAXI@Z
    0x5332A0 | public: virtual void * __thiscall agiDDPipeline::`scalar deleting destructor'(unsigned int) | ??_GagiDDPipeline@@UAEPAXI@Z
    0x6210C0 | const agiDDPipeline::`vftable' | ??_7agiDDPipeline@@6B@
*/

#include "agi/pipeline.h"

#include <ddraw.h>

class agiDDPipeline : public agiPipeline
{
    // const agiDDPipeline::`vftable' @ 0x6210C0

public:
    // 0x532A40 | ??0agiDDPipeline@@QAE@XZ
    ARTS_IMPORT agiDDPipeline();

    // 0x5332A0 | ??_GagiDDPipeline@@UAEPAXI@Z
    // 0x5332A0 | ??_EagiDDPipeline@@UAEPAXI@Z
    // 0x532EF0 | ??1agiDDPipeline@@UAE@XZ
    ARTS_IMPORT ~agiDDPipeline() override;

    // 0x532F40 | ?BeginFrame@agiDDPipeline@@UAEXXZ
    ARTS_IMPORT void BeginFrame() override;

    // 0x532AE0 | ?BeginGfx@agiDDPipeline@@UAEHXZ
    ARTS_IMPORT i32 BeginGfx() override;

    // 0x532FA0 | ?BeginScene@agiDDPipeline@@UAEXXZ
    ARTS_IMPORT void BeginScene() override;

    // 0x533240 | ?ClearRect@agiDDPipeline@@UAEXHHHHI@Z
    ARTS_IMPORT void ClearRect(i32 arg1, i32 arg2, i32 arg3, i32 arg4, u32 arg5) override;

    // 0x533070 | ?CopyBitmap@agiDDPipeline@@UAEXHHPAVagiBitmap@@HHHH@Z
    ARTS_IMPORT void CopyBitmap(
        i32 arg1, i32 arg2, class agiBitmap* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7) override;

    // 0x533010 | ?CreateBitmap@agiDDPipeline@@UAEPAVagiBitmap@@XZ
    ARTS_IMPORT class agiBitmap* CreateBitmap() override;

    // 0x533000 | ?EndFrame@agiDDPipeline@@UAEXXZ
    ARTS_EXPORT void EndFrame() override;

    // 0x532E30 | ?EndGfx@agiDDPipeline@@UAEXXZ
    ARTS_IMPORT void EndGfx() override;

    // 0x532FF0 | ?EndScene@agiDDPipeline@@UAEXXZ
    ARTS_EXPORT void EndScene() override;

    // 0x5331E0 | ?LockFrameBuffer@agiDDPipeline@@UAEHAAVagiSurfaceDesc@@@Z
    ARTS_IMPORT i32 LockFrameBuffer(class agiSurfaceDesc& arg1) override;

    // 0x533220 | ?UnlockFrameBuffer@agiDDPipeline@@UAEXXZ
    ARTS_IMPORT void UnlockFrameBuffer() override;

    // 0x5328C0 | ?Validate@agiDDPipeline@@UAEHXZ
    ARTS_EXPORT i32 Validate() override;

    IDirectDraw4* GetDirectDraw() const
    {
        return d_draw_;
    }

private:
    IDirectDraw4* d_draw_ {nullptr};
    IDirectDrawClipper* d_clip_ {nullptr};
    IDirectDrawSurface4* d_front_ {nullptr};
    IDirectDrawSurface4* d_back_ {nullptr};
    IDirectDrawSurface4* d_rend_ {nullptr};
    IDirectDrawPalette* d_pal_ {nullptr};
    agiPixelFormat d_pix_format_ {};
    bool set_rend_palette_ {false};
};

check_size(agiDDPipeline, 0x32C);

// 0x5328D0 | ?DDCallback@@YGHPAU_GUID@@PAD1PAX@Z | unused
ARTS_IMPORT i32 ARTS_STDCALL DDCallback(struct _GUID* arg1, char* arg2, char* arg3, void* arg4);

// 0x532950 | ?EnumModesCallback@@YGJPAU_DDSURFACEDESC2@@PAX@Z | unused
ARTS_IMPORT i32 ARTS_STDCALL EnumModesCallback(struct _DDSURFACEDESC2* arg1, void* arg2);

// 0x532A00 | ?EnumSurfsCallback@@YGJPAUIDirectDrawSurface@@PAU_DDSURFACEDESC@@PAX@Z | unused
ARTS_IMPORT i32 ARTS_STDCALL EnumSurfsCallback(
    struct IDirectDrawSurface* arg1, struct _DDSURFACEDESC* arg2, void* arg3);
