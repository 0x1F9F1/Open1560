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
    agisw:swpipe

    0x533DC0 | public: virtual int __thiscall agiSWPipeline::Validate(void) | ?Validate@agiSWPipeline@@UAEHXZ
    0x533DD0 | public: __thiscall agiSWPipeline::agiSWPipeline(int,char * *) | ??0agiSWPipeline@@QAE@HPAPAD@Z
    0x533E50 | public: virtual __thiscall agiSWPipeline::~agiSWPipeline(void) | ??1agiSWPipeline@@UAE@XZ
    0x533E60 | public: virtual int __thiscall agiSWPipeline::BeginGfx(void) | ?BeginGfx@agiSWPipeline@@UAEHXZ
    0x534010 | public: virtual void __thiscall agiSWPipeline::EndGfx(void) | ?EndGfx@agiSWPipeline@@UAEXXZ
    0x534030 | public: virtual void __thiscall agiSWPipeline::BeginFrame(void) | ?BeginFrame@agiSWPipeline@@UAEXXZ
    0x534070 | public: virtual void __thiscall agiSWPipeline::BeginScene(void) | ?BeginScene@agiSWPipeline@@UAEXXZ
    0x5340A0 | public: virtual void __thiscall agiSWPipeline::EndScene(void) | ?EndScene@agiSWPipeline@@UAEXXZ
    0x5340C0 | public: virtual void __thiscall agiSWPipeline::EndFrame(void) | ?EndFrame@agiSWPipeline@@UAEXXZ
    0x5340E0 | public: virtual class DLP * __thiscall agiSWPipeline::CreateDLP(void) | ?CreateDLP@agiSWPipeline@@UAEPAVDLP@@XZ
    0x534140 | public: virtual class agiLight * __thiscall agiSWPipeline::CreateLight(void) | ?CreateLight@agiSWPipeline@@UAEPAVagiLight@@XZ
    0x5341A0 | public: virtual void __thiscall agiSWPipeline::ClearAll(int) | ?ClearAll@agiSWPipeline@@UAEXH@Z
    0x534230 | public: virtual void __thiscall agiSWPipeline::ClearRect(int,int,int,int,unsigned int) | ?ClearRect@agiSWPipeline@@UAEXHHHHI@Z
    0x534290 | public: virtual class agiViewport * __thiscall agiSWPipeline::CreateViewport(void) | ?CreateViewport@agiSWPipeline@@UAEPAVagiViewport@@XZ
    0x5342F0 | void __cdecl zmemset(unsigned short *,unsigned int) | ?zmemset@@YAXPAGI@Z
    0x534320 | public: virtual class agiLightModel * __thiscall agiSWPipeline::CreateLightModel(void) | ?CreateLightModel@agiSWPipeline@@UAEPAVagiLightModel@@XZ
    0x534380 | public: virtual class agiTexDef * __thiscall agiSWPipeline::CreateTexDef(void) | ?CreateTexDef@agiSWPipeline@@UAEPAVagiTexDef@@XZ
    0x5343E0 | public: virtual class agiTexLut * __thiscall agiSWPipeline::CreateTexLut(void) | ?CreateTexLut@agiSWPipeline@@UAEPAVagiTexLut@@XZ
    0x534440 | public: virtual class agiMtlDef * __thiscall agiSWPipeline::CreateMtlDef(void) | ?CreateMtlDef@agiSWPipeline@@UAEPAVagiMtlDef@@XZ
    0x534450 | public: virtual class agiBitmap * __thiscall agiSWPipeline::CreateBitmap(void) | ?CreateBitmap@agiSWPipeline@@UAEPAVagiBitmap@@XZ
    0x5344C0 | public: virtual void __thiscall agiSWPipeline::CopyBitmap(int,int,class agiBitmap *,int,int,int,int) | ?CopyBitmap@agiSWPipeline@@UAEXHHPAVagiBitmap@@HHHH@Z
    0x534690 | class agiPipeline * __cdecl swCreatePipeline(int,char * *) | ?swCreatePipeline@@YAPAVagiPipeline@@HPAPAD@Z
    0x534900 | public: virtual void * __thiscall agiSWPipeline::`vector deleting destructor'(unsigned int) | ??_EagiSWPipeline@@UAEPAXI@Z
    0x534900 | public: virtual void * __thiscall agiSWPipeline::`scalar deleting destructor'(unsigned int) | ??_GagiSWPipeline@@UAEPAXI@Z
    0x534930 | public: virtual void __thiscall agiSWViewport::Activate(void) | ?Activate@agiSWViewport@@UAEXXZ
    0x534950 | public: virtual void __thiscall agiSWViewport::SetBackground(class Vector3 &) | ?SetBackground@agiSWViewport@@UAEXAAVVector3@@@Z
    0x5349B0 | public: virtual void __thiscall agiSWViewport::Clear(int) | ?Clear@agiSWViewport@@UAEXH@Z
    0x534BC0 | public: virtual int __thiscall agiSWViewport::BeginGfx(void) | ?BeginGfx@agiSWViewport@@UAEHXZ
    0x534BD0 | public: virtual void __thiscall agiSWViewport::EndGfx(void) | ?EndGfx@agiSWViewport@@UAEXXZ
    0x534BE0 | public: virtual void * __thiscall agiSWViewport::`scalar deleting destructor'(unsigned int) | ??_GagiSWViewport@@UAEPAXI@Z
    0x534BE0 | public: virtual void * __thiscall agiSWViewport::`vector deleting destructor'(unsigned int) | ??_EagiSWViewport@@UAEPAXI@Z
    0x534C10 | public: virtual __thiscall agiSWViewport::~agiSWViewport(void) | ??1agiSWViewport@@UAE@XZ
    0x534C20 | public: virtual int __thiscall agiSWBitmap::BeginGfx(void) | ?BeginGfx@agiSWBitmap@@UAEHXZ
    0x534DA0 | public: virtual void __thiscall agiSWBitmap::UpdateFlags(void) | ?UpdateFlags@agiSWBitmap@@UAEXXZ
    0x534DC0 | public: virtual void __thiscall agiSWBitmap::EndGfx(void) | ?EndGfx@agiSWBitmap@@UAEXXZ
    0x534DE0 | public: virtual void __thiscall agiSWBitmap::Restore(void) | ?Restore@agiSWBitmap@@UAEXXZ
    0x534DF0 | public: virtual void * __thiscall agiSWBitmap::`vector deleting destructor'(unsigned int) | ??_EagiSWBitmap@@UAEPAXI@Z
    0x534DF0 | public: virtual void * __thiscall agiSWBitmap::`scalar deleting destructor'(unsigned int) | ??_GagiSWBitmap@@UAEPAXI@Z
    0x534E20 | public: virtual __thiscall agiSWBitmap::~agiSWBitmap(void) | ??1agiSWBitmap@@UAE@XZ
    0x6211D8 | const agiSWPipeline::`vftable' | ??_7agiSWPipeline@@6B@
    0x621248 | const agiSWViewport::`vftable' | ??_7agiSWViewport@@6B@
    0x621288 | const agiSWBitmap::`vftable' | ??_7agiSWBitmap@@6B@
*/

#include "agi/bitmap.h"
#include "agi/pipeline.h"
#include "agi/viewport.h"

class agiSWPipeline : public agiPipeline
{
    // const agiSWPipeline::`vftable' @ 0x6211D8

public:
    // 0x533DD0 | ??0agiSWPipeline@@QAE@HPAPAD@Z
    ARTS_IMPORT agiSWPipeline(i32 arg1, char** arg2);

    // 0x534900 | ??_GagiSWPipeline@@UAEPAXI@Z
    // 0x533E50 | ??1agiSWPipeline@@UAE@XZ
    ARTS_IMPORT ~agiSWPipeline() override;

    // 0x534030 | ?BeginFrame@agiSWPipeline@@UAEXXZ
    ARTS_IMPORT void BeginFrame() override;

    // 0x533E60 | ?BeginGfx@agiSWPipeline@@UAEHXZ
    ARTS_IMPORT i32 BeginGfx() override;

    // 0x534070 | ?BeginScene@agiSWPipeline@@UAEXXZ
    ARTS_IMPORT void BeginScene() override;

    // 0x5341A0 | ?ClearAll@agiSWPipeline@@UAEXH@Z
    ARTS_IMPORT void ClearAll(i32 arg1) override;

    // 0x534230 | ?ClearRect@agiSWPipeline@@UAEXHHHHI@Z
    ARTS_IMPORT void ClearRect(i32 arg1, i32 arg2, i32 arg3, i32 arg4, u32 arg5) override;

    // 0x5344C0 | ?CopyBitmap@agiSWPipeline@@UAEXHHPAVagiBitmap@@HHHH@Z
    ARTS_IMPORT void CopyBitmap(
        i32 arg1, i32 arg2, class agiBitmap* arg3, i32 arg4, i32 arg5, i32 arg6, i32 arg7) override;

    // 0x534450 | ?CreateBitmap@agiSWPipeline@@UAEPAVagiBitmap@@XZ
    ARTS_IMPORT class agiBitmap* CreateBitmap() override;

    // 0x5340E0 | ?CreateDLP@agiSWPipeline@@UAEPAVDLP@@XZ
    ARTS_IMPORT class DLP* CreateDLP() override;

    // 0x534140 | ?CreateLight@agiSWPipeline@@UAEPAVagiLight@@XZ
    ARTS_IMPORT class agiLight* CreateLight() override;

    // 0x534320 | ?CreateLightModel@agiSWPipeline@@UAEPAVagiLightModel@@XZ
    ARTS_IMPORT class agiLightModel* CreateLightModel() override;

    // 0x534440 | ?CreateMtlDef@agiSWPipeline@@UAEPAVagiMtlDef@@XZ
    ARTS_IMPORT class agiMtlDef* CreateMtlDef() override;

    // 0x534380 | ?CreateTexDef@agiSWPipeline@@UAEPAVagiTexDef@@XZ
    ARTS_IMPORT class agiTexDef* CreateTexDef() override;

    // 0x5343E0 | ?CreateTexLut@agiSWPipeline@@UAEPAVagiTexLut@@XZ
    ARTS_IMPORT class agiTexLut* CreateTexLut() override;

    // 0x534290 | ?CreateViewport@agiSWPipeline@@UAEPAVagiViewport@@XZ
    ARTS_IMPORT class agiViewport* CreateViewport() override;

    // 0x5340C0 | ?EndFrame@agiSWPipeline@@UAEXXZ
    ARTS_IMPORT void EndFrame() override;

    // 0x534010 | ?EndGfx@agiSWPipeline@@UAEXXZ
    ARTS_IMPORT void EndGfx() override;

    // 0x5340A0 | ?EndScene@agiSWPipeline@@UAEXXZ
    ARTS_IMPORT void EndScene() override;

    // 0x533DC0 | ?Validate@agiSWPipeline@@UAEHXZ
    ARTS_IMPORT i32 Validate() override;
};

check_size(agiSWPipeline, 0x2F0);

// 0x534690 | ?swCreatePipeline@@YAPAVagiPipeline@@HPAPAD@Z
ARTS_IMPORT class agiPipeline* swCreatePipeline(i32 arg1, char** arg2);

class agiSWViewport : public agiViewport
{
    // const agiSWViewport::`vftable' @ 0x621248

public:
    // 0x534BE0 | ??_EagiSWViewport@@UAEPAXI@Z
    // 0x534C10 | ??1agiSWViewport@@UAE@XZ | inline
    ARTS_IMPORT ~agiSWViewport() override;

    // 0x534930 | ?Activate@agiSWViewport@@UAEXXZ | inline
    ARTS_IMPORT void Activate() override;

    // 0x534BC0 | ?BeginGfx@agiSWViewport@@UAEHXZ | inline
    ARTS_IMPORT i32 BeginGfx() override;

    // 0x5349B0 | ?Clear@agiSWViewport@@UAEXH@Z | inline
    ARTS_IMPORT void Clear(i32 arg1) override;

    // 0x534BD0 | ?EndGfx@agiSWViewport@@UAEXXZ | inline
    ARTS_IMPORT void EndGfx() override;

    // 0x534950 | ?SetBackground@agiSWViewport@@UAEXAAVVector3@@@Z | inline
    ARTS_IMPORT void SetBackground(class Vector3& arg1) override;
};

check_size(agiSWViewport, 0x14C);

class agiSWBitmap : public agiBitmap
{
    // const agiSWBitmap::`vftable' @ 0x621288

public:
    // 0x534DF0 | ??_GagiSWBitmap@@UAEPAXI@Z
    // 0x534E20 | ??1agiSWBitmap@@UAE@XZ | inline
    ARTS_IMPORT ~agiSWBitmap() override;

    // 0x534C20 | ?BeginGfx@agiSWBitmap@@UAEHXZ | inline
    ARTS_IMPORT i32 BeginGfx() override;

    // 0x534DC0 | ?EndGfx@agiSWBitmap@@UAEXXZ | inline
    ARTS_IMPORT void EndGfx() override;

    // 0x534DE0 | ?Restore@agiSWBitmap@@UAEXXZ | inline
    ARTS_IMPORT void Restore() override;

    // 0x534DA0 | ?UpdateFlags@agiSWBitmap@@UAEXXZ | inline
    ARTS_IMPORT void UpdateFlags() override;
};

check_size(agiSWBitmap, 0x40);
