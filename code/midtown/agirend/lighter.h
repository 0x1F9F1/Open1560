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
    agirend:lighter

    0x551740 | public: __thiscall agiLighter::agiLighter(void) | ??0agiLighter@@QAE@XZ
    0x551750 | protected: virtual __thiscall agiLighter::~agiLighter(void) | ??1agiLighter@@MAE@XZ
    0x551760 | public: static void __cdecl agiLighter::BeginScene(void) | ?BeginScene@agiLighter@@SAXXZ
    0x551780 | public: static void __cdecl agiLighter::DeclareLight(class agiLight *) | ?DeclareLight@agiLighter@@SAXPAVagiLight@@@Z
    0x5517A0 | public: static void __cdecl agiLighter::RemoveLight(class agiLight *) | ?RemoveLight@agiLighter@@SAXPAVagiLight@@@Z
    0x551800 | public: virtual void __thiscall agiLighter::TransformAll(class Matrix34 *,class Vector3 *,unsigned int) | ?TransformAll@agiLighter@@UAEXPAVMatrix34@@PAVVector3@@I@Z
    0x5519F0 | public: __thiscall agiMonoLighter::agiMonoLighter(void) | ??0agiMonoLighter@@QAE@XZ
    0x551A10 | public: virtual __thiscall agiMonoLighter::~agiMonoLighter(void) | ??1agiMonoLighter@@UAE@XZ
    0x551A20 | public: virtual unsigned int __thiscall agiMonoLighter::LightVertex(unsigned int,struct agiLitVtx *,class Vector3 *) | ?LightVertex@agiMonoLighter@@UAEIIPAUagiLitVtx@@PAVVector3@@@Z
    0x551E40 | public: __thiscall agiRGBLighter::agiRGBLighter(void) | ??0agiRGBLighter@@QAE@XZ
    0x551E60 | public: virtual __thiscall agiRGBLighter::~agiRGBLighter(void) | ??1agiRGBLighter@@UAE@XZ
    0x551E70 | public: virtual unsigned int __thiscall agiRGBLighter::LightVertex(unsigned int,struct agiLitVtx *,class Vector3 *) | ?LightVertex@agiRGBLighter@@UAEIIPAUagiLitVtx@@PAVVector3@@@Z
    0x552420 | protected: virtual void * __thiscall agiLighter::`scalar deleting destructor'(unsigned int) | ??_GagiLighter@@MAEPAXI@Z
    0x552420 | protected: virtual void * __thiscall agiLighter::`vector deleting destructor'(unsigned int) | ??_EagiLighter@@MAEPAXI@Z
    0x552450 | public: virtual void * __thiscall agiMonoLighter::`vector deleting destructor'(unsigned int) | ??_EagiMonoLighter@@UAEPAXI@Z
    0x552450 | public: virtual void * __thiscall agiMonoLighter::`scalar deleting destructor'(unsigned int) | ??_GagiMonoLighter@@UAEPAXI@Z
    0x552480 | public: virtual void * __thiscall agiRGBLighter::`vector deleting destructor'(unsigned int) | ??_EagiRGBLighter@@UAEPAXI@Z
    0x552480 | public: virtual void * __thiscall agiRGBLighter::`scalar deleting destructor'(unsigned int) | ??_GagiRGBLighter@@UAEPAXI@Z
    0x621458 | const agiLighter::`vftable' | ??_7agiLighter@@6B@
    0x621468 | const agiMonoLighter::`vftable' | ??_7agiMonoLighter@@6B@
    0x621478 | const agiRGBLighter::`vftable' | ??_7agiRGBLighter@@6B@
    0x7E0020 | class agiRGBLighter RGBLIGHTER | ?RGBLIGHTER@@3VagiRGBLighter@@A
    0x7E0028 | public: static char * agiLighter::Positional | ?Positional@agiLighter@@2PADA
    0x7E0038 | public: static class agiShadowMap * agiLighter::ShadowMap | ?ShadowMap@agiLighter@@2PAVagiShadowMap@@A
    0x7E0040 | public: static class agiLight * * agiLighter::LIGHTS | ?LIGHTS@agiLighter@@2PAPAVagiLight@@A
    0x7E0080 | public: static char * agiLighter::Attenuate | ?Attenuate@agiLighter@@2PADA
    0x7E0090 | public: static class Vector3 agiLighter::Eye | ?Eye@agiLighter@@2VVector3@@A
    0x7E009C | public: static int agiLighter::Current | ?Current@agiLighter@@2HA
    0x7E00A0 | public: static int agiLighter::SceneCurrent | ?SceneCurrent@agiLighter@@2HA
    0x7E00A4 | public: static class agiLightModel * agiLighter::LMODEL | ?LMODEL@agiLighter@@2PAVagiLightModel@@A
    0x7E00A8 | public: static int agiLighter::LocalViewer | ?LocalViewer@agiLighter@@2HA
    0x7E00B0 | public: static class Vector3 * agiLighter::Pos | ?Pos@agiLighter@@2PAVVector3@@A
    0x7E0170 | public: static class agiLight * * agiLighter::ACTIVELIGHTS | ?ACTIVELIGHTS@agiLighter@@2PAPAVagiLight@@A
    0x7E01B0 | public: static class Vector3 * agiLighter::Dir | ?Dir@agiLighter@@2PAVVector3@@A
    0x7E0270 | public: static float * agiLighter::CosSpread | ?CosSpread@agiLighter@@2PAMA
    0x7E02B0 | public: static int agiLighter::SceneActive | ?SceneActive@agiLighter@@2HA
    0x7E02B4 | class agiMonoLighter MONOLIGHTER | ?MONOLIGHTER@@3VagiMonoLighter@@A
    0x7E02B8 | public: static class Vector3 agiLighter::SceneAmbient | ?SceneAmbient@agiLighter@@2VVector3@@A
*/

class agiLighter
{
    // const agiLighter::`vftable' @ 0x621458

public:
    // 0x551740 | ??0agiLighter@@QAE@XZ
    agiLighter();

protected:
    // 0x552420 | ??_EagiLighter@@MAEPAXI@Z
    // 0x551750 | ??1agiLighter@@MAE@XZ
    virtual ~agiLighter();

public:
    // 0x551800 | ?TransformAll@agiLighter@@UAEXPAVMatrix34@@PAVVector3@@I@Z
    virtual void TransformAll(class Matrix34* arg1, class Vector3* arg2, u32 arg3);

    virtual u32 LightVertex(u32 arg1, struct agiLitVtx* arg2, class Vector3* arg3) = 0;

    // 0x551760 | ?BeginScene@agiLighter@@SAXXZ
    static void BeginScene();

    // 0x551780 | ?DeclareLight@agiLighter@@SAXPAVagiLight@@@Z
    static void DeclareLight(class agiLight* arg1);

    // 0x5517A0 | ?RemoveLight@agiLighter@@SAXPAVagiLight@@@Z
    static void RemoveLight(class agiLight* arg1);

    // 0x7E0170 | ?ACTIVELIGHTS@agiLighter@@2PAPAVagiLight@@A
    static inline extern_var(0x3E0170_Offset, class agiLight**, ACTIVELIGHTS);

    // 0x7E0080 | ?Attenuate@agiLighter@@2PADA
    static inline extern_var(0x3E0080_Offset, char*, Attenuate);

    // 0x7E0270 | ?CosSpread@agiLighter@@2PAMA
    static inline extern_var(0x3E0270_Offset, f32*, CosSpread);

    // 0x7E009C | ?Current@agiLighter@@2HA
    static inline extern_var(0x3E009C_Offset, i32, Current);

    // 0x7E01B0 | ?Dir@agiLighter@@2PAVVector3@@A
    static inline extern_var(0x3E01B0_Offset, class Vector3*, Dir);

    // 0x7E0090 | ?Eye@agiLighter@@2VVector3@@A
    static inline extern_var(0x3E0090_Offset, class Vector3, Eye);

    // 0x7E0040 | ?LIGHTS@agiLighter@@2PAPAVagiLight@@A
    static inline extern_var(0x3E0040_Offset, class agiLight**, LIGHTS);

    // 0x7E00A4 | ?LMODEL@agiLighter@@2PAVagiLightModel@@A
    static inline extern_var(0x3E00A4_Offset, class agiLightModel*, LMODEL);

    // 0x7E00A8 | ?LocalViewer@agiLighter@@2HA
    static inline extern_var(0x3E00A8_Offset, i32, LocalViewer);

    // 0x7E00B0 | ?Pos@agiLighter@@2PAVVector3@@A
    static inline extern_var(0x3E00B0_Offset, class Vector3*, Pos);

    // 0x7E0028 | ?Positional@agiLighter@@2PADA
    static inline extern_var(0x3E0028_Offset, char*, Positional);

    // 0x7E02B0 | ?SceneActive@agiLighter@@2HA
    static inline extern_var(0x3E02B0_Offset, i32, SceneActive);

    // 0x7E02B8 | ?SceneAmbient@agiLighter@@2VVector3@@A
    static inline extern_var(0x3E02B8_Offset, class Vector3, SceneAmbient);

    // 0x7E00A0 | ?SceneCurrent@agiLighter@@2HA
    static inline extern_var(0x3E00A0_Offset, i32, SceneCurrent);

    // 0x7E0038 | ?ShadowMap@agiLighter@@2PAVagiShadowMap@@A
    static inline extern_var(0x3E0038_Offset, class agiShadowMap*, ShadowMap);
};

check_size(agiLighter, 0x0);

class agiMonoLighter : public agiLighter
{
    // const agiMonoLighter::`vftable' @ 0x621468

public:
    // 0x5519F0 | ??0agiMonoLighter@@QAE@XZ
    agiMonoLighter();

    // 0x552450 | ??_GagiMonoLighter@@UAEPAXI@Z
    // 0x551A10 | ??1agiMonoLighter@@UAE@XZ
    ~agiMonoLighter() override;

    // 0x551A20 | ?LightVertex@agiMonoLighter@@UAEIIPAUagiLitVtx@@PAVVector3@@@Z
    u32 LightVertex(u32 arg1, struct agiLitVtx* arg2, class Vector3* arg3) override;
};

check_size(agiMonoLighter, 0x0);

class agiRGBLighter : public agiLighter
{
    // const agiRGBLighter::`vftable' @ 0x621478

public:
    // 0x551E40 | ??0agiRGBLighter@@QAE@XZ
    agiRGBLighter();

    // 0x552480 | ??_GagiRGBLighter@@UAEPAXI@Z
    // 0x551E60 | ??1agiRGBLighter@@UAE@XZ
    ~agiRGBLighter() override;

    // 0x551E70 | ?LightVertex@agiRGBLighter@@UAEIIPAUagiLitVtx@@PAVVector3@@@Z
    u32 LightVertex(u32 arg1, struct agiLitVtx* arg2, class Vector3* arg3) override;
};

check_size(agiRGBLighter, 0x0);

// 0x7E02B4 | ?MONOLIGHTER@@3VagiMonoLighter@@A
inline extern_var(0x3E02B4_Offset, class agiMonoLighter, MONOLIGHTER);

// 0x7E0020 | ?RGBLIGHTER@@3VagiRGBLighter@@A
inline extern_var(0x3E0020_Offset, class agiRGBLighter, RGBLIGHTER);
