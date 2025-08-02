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
    0x5307B0 | long __stdcall EnumCallback(struct _GUID *,char *,char *,struct _D3DDeviceDesc *,struct _D3DDeviceDesc *,void *) | ?EnumCallback@@YGJPAU_GUID@@PAD1PAU_D3DDeviceDesc@@2PAX@Z
    0x5308B0 | long __stdcall EnumTextureCallback(struct _DDPIXELFORMAT *,void *) | ?EnumTextureCallback@@YGJPAU_DDPIXELFORMAT@@PAX@Z
    0x530980 | long __stdcall EnumZ(struct _DDPIXELFORMAT *,void *) | ?EnumZ@@YGJPAU_DDPIXELFORMAT@@PAX@Z
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
*/

#include "ddpipe.h"

#include <d3d.h>

class agiRasterizer;

class agiD3DPipeline : public agiDDPipeline
{
public:
    // ??0agiD3DPipeline@@QAE@XZ
    ARTS_EXPORT agiD3DPipeline();

    // ??_GagiD3DPipeline@@UAEPAXI@Z
    // ??_EagiD3DPipeline@@UAEPAXI@Z
    // ??1agiD3DPipeline@@UAE@XZ
    ARTS_EXPORT ~agiD3DPipeline() override;

    // ?BeginFrame@agiD3DPipeline@@UAEXXZ
    ARTS_EXPORT void BeginFrame() override;

    // ?BeginGfx@agiD3DPipeline@@UAEHXZ
    ARTS_EXPORT i32 BeginGfx() override;

    // ?BeginScene@agiD3DPipeline@@UAEXXZ
    ARTS_EXPORT void BeginScene() override;

    // ?ClearAll@agiD3DPipeline@@UAEXH@Z
    ARTS_EXPORT void ClearAll(i32 color) override;

    // ?CopyBitmap@agiD3DPipeline@@UAEXHHPAVagiBitmap@@HHHH@Z
    ARTS_EXPORT void CopyBitmap(
        i32 dst_x, i32 dst_y, agiBitmap* src, i32 src_x, i32 src_y, i32 width, i32 height) override;

    // ?CreateBitmap@agiD3DPipeline@@UAEPAVagiBitmap@@XZ
    ARTS_EXPORT RcOwner<agiBitmap> CreateBitmap() override;

    // ?CreateLight@agiD3DPipeline@@UAEPAVagiLight@@XZ
    ARTS_EXPORT RcOwner<agiLight> CreateLight() override;

    // ?CreateMtlDef@agiD3DPipeline@@UAEPAVagiMtlDef@@XZ
    ARTS_EXPORT RcOwner<agiMtlDef> CreateMtlDef() override;

    // ?CreateTexDef@agiD3DPipeline@@UAEPAVagiTexDef@@XZ
    ARTS_EXPORT RcOwner<agiTexDef> CreateTexDef() override;

    // ?CreateTexLut@agiD3DPipeline@@UAEPAVagiTexLut@@XZ
    ARTS_EXPORT RcOwner<agiTexLut> CreateTexLut() override;

    // ?CreateViewport@agiD3DPipeline@@UAEPAVagiViewport@@XZ
    ARTS_EXPORT RcOwner<agiViewport> CreateViewport() override;

    // ?Defragment@agiD3DPipeline@@UAEXXZ
    ARTS_EXPORT void Defragment() override;

    // ?DumpStatus@agiD3DPipeline@@UAEXAAUagiMemStatus@@@Z
    ARTS_EXPORT void DumpStatus(agiMemStatus& status) override;

    // ?EndFrame@agiD3DPipeline@@UAEXXZ
    ARTS_EXPORT void EndFrame() override;

    // ?EndGfx@agiD3DPipeline@@UAEXXZ
    ARTS_EXPORT void EndGfx() override;

    // ?EndScene@agiD3DPipeline@@UAEXXZ
    ARTS_EXPORT void EndScene() override;

    i32 GetFilterCaps() const
    {
        return filter_caps_;
    }

    i32 GetTextureFilter() const
    {
        return texture_filter_;
    }

    const DDPIXELFORMAT& GetOpaqueDDFormat() const
    {
        return opaque_dd_format_;
    }

    const DDPIXELFORMAT& GetAlphaDDFormat() const
    {
        return alpha_dd_format_;
    }

    IDirect3D3* GetD3D() const
    {
        return d3d_;
    }

    IDirect3DDevice3* GetD3DDevice() const
    {
        return d3d_device_;
    }

    IDirect3DViewport3* GetD3DView() const
    {
        return d3d_view_;
    }

protected:
    IDirect3D3* d3d_ {};
    IDirect3DDevice3* d3d_device_ {};
    IDirect3DViewport3* d3d_view_ {};
    IDirectDrawSurface4* d_zbuffer_ {};
    DDPIXELFORMAT opaque_dd_format_ {};
    DDPIXELFORMAT alpha_dd_format_ {};
    b32 is_hardware_ {};

    // D3DPTFILTERCAPS
    i32 filter_caps_ {};

    // 0x1 | POINT
    // 0x2 | TRILINEAR
    i32 texture_filter_ {};
    CLSID d3d_guid_ {};
    D3DDEVICEDESC device_desc_ {};
    char* device_name_ {};
    Rc<agiRasterizer> rasterizer_;
};

check_size(agiD3DPipeline, 0x49C);

// ?callb@@YGJPAUIDirectDrawSurface4@@PAU_DDSURFACEDESC2@@PAX@Z
ARTS_IMPORT long ARTS_STDCALL callb(IDirectDrawSurface4* arg1, _DDSURFACEDESC2* arg2, void* arg3);

// ?AlphaPalette@@3HA
ARTS_IMPORT extern b32 AlphaPalette;

// ?NoTextureCompression@@3HA
ARTS_IMPORT extern b32 NoTextureCompression;

// ?NotIndependentUV@@3HA
ARTS_IMPORT extern b32 NotIndependentUV;

// ?SeparateTextureMemories@@3HA
ARTS_IMPORT extern b32 SeparateTextureMemories;

// ?agiFOURCC@@3KA
ARTS_IMPORT extern ulong agiFOURCC;

// ?dummyGlobal@@3IA
ARTS_IMPORT extern u32 dummyGlobal;
