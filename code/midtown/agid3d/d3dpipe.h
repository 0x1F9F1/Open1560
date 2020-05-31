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
    agid3d:d3dpipe

    0x52FA90 | public: static void __cdecl agiD3DTexDef::Prober(void *) | ?Prober@agiD3DTexDef@@SAXPAX@Z
    0x52FB50 | public: __thiscall agiD3DPipeline::agiD3DPipeline(void) | ??0agiD3DPipeline@@QAE@XZ
    0x52FB90 | public: virtual int __thiscall agiD3DPipeline::BeginGfx(void) | ?BeginGfx@agiD3DPipeline@@UAEHXZ
    0x5309D0 | public: virtual __thiscall agiD3DPipeline::~agiD3DPipeline(void) | ??1agiD3DPipeline@@UAE@XZ
    0x530A20 | long __stdcall RestoreCallback(struct IDirectDrawSurface4 *,struct _DDSURFACEDESC2 *,void *) | ?RestoreCallback@@YGJPAUIDirectDrawSurface4@@PAU_DDSURFACEDESC2@@PAX@Z
    0x530A40 | public: virtual void __thiscall agiD3DPipeline::BeginFrame(void) | ?BeginFrame@agiD3DPipeline@@UAEXXZ
    0x530AF0 | public: virtual void __thiscall agiD3DPipeline::BeginScene(void) | ?BeginScene@agiD3DPipeline@@UAEXXZ
    0x530B60 | public: virtual void __thiscall agiD3DPipeline::EndScene(void) | ?EndScene@agiD3DPipeline@@UAEXXZ
    0x530BD0 | public: virtual void __thiscall agiD3DPipeline::EndFrame(void) | ?EndFrame@agiD3DPipeline@@UAEXXZ
    0x530D30 | long __stdcall callb(struct IDirectDrawSurface4 *,struct _DDSURFACEDESC2 *,void *) | ?callb@@YGJPAUIDirectDrawSurface4@@PAU_DDSURFACEDESC2@@PAX@Z
    0x530FE0 | public: virtual void __thiscall agiD3DPipeline::DumpStatus(struct agiMemStatus &) | ?DumpStatus@agiD3DPipeline@@UAEXAAUagiMemStatus@@@Z
    0x531100 | public: virtual void __thiscall agiD3DPipeline::EndGfx(void) | ?EndGfx@agiD3DPipeline@@UAEXXZ
    0x5311F0 | public: virtual class agiViewport * __thiscall agiD3DPipeline::CreateViewport(void) | ?CreateViewport@agiD3DPipeline@@UAEPAVagiViewport@@XZ
    0x531250 | public: virtual class agiMtlDef * __thiscall agiD3DPipeline::CreateMtlDef(void) | ?CreateMtlDef@agiD3DPipeline@@UAEPAVagiMtlDef@@XZ
    0x5312B0 | public: virtual class agiTexDef * __thiscall agiD3DPipeline::CreateTexDef(void) | ?CreateTexDef@agiD3DPipeline@@UAEPAVagiTexDef@@XZ
    0x531310 | public: virtual class agiTexLut * __thiscall agiD3DPipeline::CreateTexLut(void) | ?CreateTexLut@agiD3DPipeline@@UAEPAVagiTexLut@@XZ
    0x5313A0 | public: virtual class agiLight * __thiscall agiD3DPipeline::CreateLight(void) | ?CreateLight@agiD3DPipeline@@UAEPAVagiLight@@XZ
    0x531400 | public: virtual void __thiscall agiD3DPipeline::ClearAll(int) | ?ClearAll@agiD3DPipeline@@UAEXH@Z
    0x5314C0 | public: virtual class agiBitmap * __thiscall agiD3DPipeline::CreateBitmap(void) | ?CreateBitmap@agiD3DPipeline@@UAEPAVagiBitmap@@XZ
    0x531520 | public: virtual void __thiscall agiD3DPipeline::CopyBitmap(int,int,class agiBitmap *,int,int,int,int) | ?CopyBitmap@agiD3DPipeline@@UAEXHHPAVagiBitmap@@HHHH@Z
    0x531580 | public: virtual void __thiscall agiD3DPipeline::Defragment(void) | ?Defragment@agiD3DPipeline@@UAEXXZ
    0x531590 | public: virtual void * __thiscall agiD3DPipeline::`vector deleting destructor'(unsigned int) | ??_EagiD3DPipeline@@UAEPAXI@Z
    0x531590 | public: virtual void * __thiscall agiD3DPipeline::`scalar deleting destructor'(unsigned int) | ??_GagiD3DPipeline@@UAEPAXI@Z
    0x5315C0 | public: virtual void * __thiscall agiD3DTexLut::`vector deleting destructor'(unsigned int) | ??_EagiD3DTexLut@@UAEPAXI@Z
    0x5315C0 | public: virtual void * __thiscall agiD3DTexLut::`scalar deleting destructor'(unsigned int) | ??_GagiD3DTexLut@@UAEPAXI@Z
    0x5315F0 | public: virtual __thiscall agiD3DTexLut::~agiD3DTexLut(void) | ??1agiD3DTexLut@@UAE@XZ
    0x620F78 | const agiD3DPipeline::`vftable' | ??_7agiD3DPipeline@@6B@
    0x620FF8 | const agiD3DTexLut::`vftable' | ??_7agiD3DTexLut@@6B@
    0x64E7C8 | int NoTextureCompression | ?NoTextureCompression@@3HA
    0x795BD8 | unsigned long agiFOURCC | ?agiFOURCC@@3KA
    0x795C0C | int SeparateTextureMemories | ?SeparateTextureMemories@@3HA
    0x795C14 | unsigned int dummyGlobal | ?dummyGlobal@@3IA
    0x795C18 | int AlphaPalette | ?AlphaPalette@@3HA
    0x795C20 | int NotIndependentUV | ?NotIndependentUV@@3HA
    0x5307B0 | long __stdcall EnumCallback(struct _GUID *,char *,char *,struct _D3DDeviceDesc *,struct _D3DDeviceDesc *,void *) | ?EnumCallback@@YGJPAU_GUID@@PAD1PAU_D3DDeviceDesc@@2PAX@Z
    0x5308B0 | long __stdcall EnumTextureCallback(struct _DDPIXELFORMAT *,void *) | ?EnumTextureCallback@@YGJPAU_DDPIXELFORMAT@@PAX@Z
    0x530980 | long __stdcall EnumZ(struct _DDPIXELFORMAT *,void *) | ?EnumZ@@YGJPAU_DDPIXELFORMAT@@PAX@Z
*/

#include "ddpipe.h"

class agiD3DPipeline : public agiDDPipeline
{
    // const agiD3DPipeline::`vftable' @ 0x620F78

public:
    // 0x52FB50 | ??0agiD3DPipeline@@QAE@XZ
    agiD3DPipeline();

    // 0x531590 | ??_GagiD3DPipeline@@UAEPAXI@Z
    // 0x5309D0 | ??1agiD3DPipeline@@UAE@XZ
    ~agiD3DPipeline() override;

    // 0x530A40 | ?BeginFrame@agiD3DPipeline@@UAEXXZ
    void BeginFrame() override;

    // 0x52FB90 | ?BeginGfx@agiD3DPipeline@@UAEHXZ
    i32 BeginGfx() override;

    // 0x530AF0 | ?BeginScene@agiD3DPipeline@@UAEXXZ
    void BeginScene() override;

    // 0x531400 | ?ClearAll@agiD3DPipeline@@UAEXH@Z
    void ClearAll(i32 arg1) override;

    // 0x531520 | ?CopyBitmap@agiD3DPipeline@@UAEXHHPAVagiBitmap@@HHHH@Z
    void CopyBitmap(i32 arg1, i32 arg2, class agiBitmap* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7) override;

    // 0x5314C0 | ?CreateBitmap@agiD3DPipeline@@UAEPAVagiBitmap@@XZ
    class agiBitmap* CreateBitmap() override;

    // 0x5313A0 | ?CreateLight@agiD3DPipeline@@UAEPAVagiLight@@XZ
    class agiLight* CreateLight() override;

    // 0x531250 | ?CreateMtlDef@agiD3DPipeline@@UAEPAVagiMtlDef@@XZ
    class agiMtlDef* CreateMtlDef() override;

    // 0x5312B0 | ?CreateTexDef@agiD3DPipeline@@UAEPAVagiTexDef@@XZ
    class agiTexDef* CreateTexDef() override;

    // 0x531310 | ?CreateTexLut@agiD3DPipeline@@UAEPAVagiTexLut@@XZ
    class agiTexLut* CreateTexLut() override;

    // 0x5311F0 | ?CreateViewport@agiD3DPipeline@@UAEPAVagiViewport@@XZ
    class agiViewport* CreateViewport() override;

    // 0x531580 | ?Defragment@agiD3DPipeline@@UAEXXZ
    void Defragment() override;

    // 0x530FE0 | ?DumpStatus@agiD3DPipeline@@UAEXAAUagiMemStatus@@@Z
    void DumpStatus(struct agiMemStatus& arg1) override;

    // 0x530BD0 | ?EndFrame@agiD3DPipeline@@UAEXXZ
    void EndFrame() override;

    // 0x531100 | ?EndGfx@agiD3DPipeline@@UAEXXZ
    void EndGfx() override;

    // 0x530B60 | ?EndScene@agiD3DPipeline@@UAEXXZ
    void EndScene() override;
};

check_size(agiD3DPipeline, 0x0);

// 0x530A20 | ?RestoreCallback@@YGJPAUIDirectDrawSurface4@@PAU_DDSURFACEDESC2@@PAX@Z | unused
i32 __stdcall RestoreCallback(struct IDirectDrawSurface4* arg1, struct _DDSURFACEDESC2* arg2, void* arg3);

// 0x530D30 | ?callb@@YGJPAUIDirectDrawSurface4@@PAU_DDSURFACEDESC2@@PAX@Z
i32 __stdcall callb(struct IDirectDrawSurface4* arg1, struct _DDSURFACEDESC2* arg2, void* arg3);

// 0x795C18 | ?AlphaPalette@@3HA
inline extern_var(0x795C18, i32, AlphaPalette);

// 0x64E7C8 | ?NoTextureCompression@@3HA
inline extern_var(0x64E7C8, i32, NoTextureCompression);

// 0x795C20 | ?NotIndependentUV@@3HA
inline extern_var(0x795C20, i32, NotIndependentUV);

// 0x795C0C | ?SeparateTextureMemories@@3HA
inline extern_var(0x795C0C, i32, SeparateTextureMemories);

// 0x795BD8 | ?agiFOURCC@@3KA
inline extern_var(0x795BD8, u32, agiFOURCC);

// 0x795C14 | ?dummyGlobal@@3IA
inline extern_var(0x795C14, u32, dummyGlobal);
