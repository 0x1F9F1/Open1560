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

class agiLight;
class agiLightModel;
struct agiLitVtx;
class agiShadowMap;

class agiLighter
{
public:
    // ??0agiLighter@@QAE@XZ
    ARTS_IMPORT agiLighter();

protected:
    // ??1agiLighter@@MAE@XZ
    ARTS_EXPORT virtual ~agiLighter() = default;

public:
    // ?TransformAll@agiLighter@@UAEXPAVMatrix34@@PAVVector3@@I@Z
    ARTS_IMPORT virtual void TransformAll(Matrix34* arg1, Vector3* arg2, u32 arg3);

    virtual u32 LightVertex(u32 arg1, agiLitVtx* arg2, Vector3* arg3) = 0;

    // ?BeginScene@agiLighter@@SAXXZ
    ARTS_IMPORT static void BeginScene();

    // ?DeclareLight@agiLighter@@SAXPAVagiLight@@@Z
    ARTS_IMPORT static void DeclareLight(agiLight* arg1);

    // ?RemoveLight@agiLighter@@SAXPAVagiLight@@@Z
    ARTS_IMPORT static void RemoveLight(agiLight* arg1);

    // ?ACTIVELIGHTS@agiLighter@@2PAPAVagiLight@@A
    ARTS_IMPORT static agiLight* ACTIVELIGHTS[16];

    // ?Attenuate@agiLighter@@2PADA
    ARTS_IMPORT static char Attenuate[16];

    // ?CosSpread@agiLighter@@2PAMA
    ARTS_IMPORT static f32 CosSpread[16];

    // ?Current@agiLighter@@2HA
    ARTS_IMPORT static i32 Current;

    // ?Dir@agiLighter@@2PAVVector3@@A
    ARTS_IMPORT static Vector3 Dir[16];

    // ?Eye@agiLighter@@2VVector3@@A
    ARTS_IMPORT static Vector3 Eye;

    // ?LIGHTS@agiLighter@@2PAPAVagiLight@@A
    ARTS_IMPORT static agiLight* LIGHTS[16];

    // ?LMODEL@agiLighter@@2PAVagiLightModel@@A
    ARTS_IMPORT static agiLightModel* LMODEL;

    // ?LocalViewer@agiLighter@@2HA
    ARTS_IMPORT static i32 LocalViewer;

    // ?Pos@agiLighter@@2PAVVector3@@A
    ARTS_IMPORT static Vector3 Pos[16];

    // ?Positional@agiLighter@@2PADA
    ARTS_IMPORT static char Positional[16];

    // ?SceneActive@agiLighter@@2HA
    ARTS_IMPORT static i32 SceneActive;

    // ?SceneAmbient@agiLighter@@2VVector3@@A
    ARTS_IMPORT static Vector3 SceneAmbient;

    // ?SceneCurrent@agiLighter@@2HA
    ARTS_IMPORT static i32 SceneCurrent;

    // ?ShadowMap@agiLighter@@2PAVagiShadowMap@@A
    ARTS_IMPORT static agiShadowMap* ShadowMap;
};

check_size(agiLighter, 0x4);

class agiMonoLighter final : public agiLighter
{
public:
    // ??0agiMonoLighter@@QAE@XZ
    ARTS_IMPORT agiMonoLighter();

    // ??1agiMonoLighter@@UAE@XZ
    ARTS_EXPORT ~agiMonoLighter() override = default;

    // ?LightVertex@agiMonoLighter@@UAEIIPAUagiLitVtx@@PAVVector3@@@Z
    ARTS_IMPORT u32 LightVertex(u32 arg1, agiLitVtx* arg2, Vector3* arg3) override;
};

check_size(agiMonoLighter, 0x4);

class agiRGBLighter final : public agiLighter
{
public:
    // ??0agiRGBLighter@@QAE@XZ
    ARTS_IMPORT agiRGBLighter();

    // ??1agiRGBLighter@@UAE@XZ
    ARTS_EXPORT ~agiRGBLighter() override = default;

    // ?LightVertex@agiRGBLighter@@UAEIIPAUagiLitVtx@@PAVVector3@@@Z
    ARTS_IMPORT u32 LightVertex(u32 arg1, agiLitVtx* arg2, Vector3* arg3) override;
};

check_size(agiRGBLighter, 0x4);

// ?MONOLIGHTER@@3VagiMonoLighter@@A
ARTS_IMPORT extern agiMonoLighter MONOLIGHTER;

// ?RGBLIGHTER@@3VagiRGBLighter@@A
ARTS_IMPORT extern agiRGBLighter RGBLIGHTER;
