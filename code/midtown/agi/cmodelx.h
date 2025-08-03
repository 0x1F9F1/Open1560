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

#include "cmodel.h"

class agiColorModelRGB555 final : public agiColorModel
{
public:
    // ??0agiColorModelRGB555@@QAE@XZ
    ARTS_IMPORT agiColorModelRGB555();

    // ??1agiColorModelRGB555@@UAE@XZ | inline
    ARTS_EXPORT ~agiColorModelRGB555() override = default;

    // ?Filter@agiColorModelRGB555@@UAEIIIII@Z
    ARTS_IMPORT u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // ?FindColor@agiColorModelRGB555@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 FindColor(agiRgba arg1) override;

    // ?GetColor@agiColorModelRGB555@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 GetColor(agiRgba arg1) override;

    // ?GetPixel@agiColorModelRGB555@@UAEIPAVagiSurfaceDesc@@HH@Z
    ARTS_EXPORT u32 GetPixel(agiSurfaceDesc* surface, i32 x, i32 y) override;

    // ?SetPixel@agiColorModelRGB555@@UAEXPAVagiSurfaceDesc@@HHI@Z
    ARTS_IMPORT void SetPixel(agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelRGB555, 0x2C);

class agiColorModelRGB565 final : public agiColorModel
{
public:
    // ??0agiColorModelRGB565@@QAE@XZ
    ARTS_IMPORT agiColorModelRGB565();

    // ??1agiColorModelRGB565@@UAE@XZ | inline
    ARTS_EXPORT ~agiColorModelRGB565() override = default;

    // ?Filter@agiColorModelRGB565@@UAEIIIII@Z
    ARTS_IMPORT u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // ?FindColor@agiColorModelRGB565@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 FindColor(agiRgba arg1) override;

    // ?GetColor@agiColorModelRGB565@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 GetColor(agiRgba arg1) override;

    // ?GetPixel@agiColorModelRGB565@@UAEIPAVagiSurfaceDesc@@HH@Z
    ARTS_EXPORT u32 GetPixel(agiSurfaceDesc* surface, i32 x, i32 y) override;

    // ?SetPixel@agiColorModelRGB565@@UAEXPAVagiSurfaceDesc@@HHI@Z
    ARTS_IMPORT void SetPixel(agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelRGB565, 0x2C);

class agiColorModelRGB555_Rev final : public agiColorModel
{
public:
    // ??0agiColorModelRGB555_Rev@@QAE@XZ
    ARTS_IMPORT agiColorModelRGB555_Rev();

    // ??1agiColorModelRGB555_Rev@@UAE@XZ | inline
    ARTS_EXPORT ~agiColorModelRGB555_Rev() override = default;

    // ?Filter@agiColorModelRGB555_Rev@@UAEIIIII@Z
    ARTS_IMPORT u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // ?FindColor@agiColorModelRGB555_Rev@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 FindColor(agiRgba arg1) override;

    // ?GetColor@agiColorModelRGB555_Rev@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 GetColor(agiRgba arg1) override;

    // ?GetPixel@agiColorModelRGB555_Rev@@UAEIPAVagiSurfaceDesc@@HH@Z
    ARTS_EXPORT u32 GetPixel(agiSurfaceDesc* surface, i32 x, i32 y) override;

    // ?SetPixel@agiColorModelRGB555_Rev@@UAEXPAVagiSurfaceDesc@@HHI@Z
    ARTS_IMPORT void SetPixel(agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelRGB555_Rev, 0x2C);

class agiColorModelRGB565_Rev final : public agiColorModel
{
public:
    // ??0agiColorModelRGB565_Rev@@QAE@XZ
    ARTS_IMPORT agiColorModelRGB565_Rev();

    // ??1agiColorModelRGB565_Rev@@UAE@XZ | inline
    ARTS_EXPORT ~agiColorModelRGB565_Rev() override = default;

    // ?Filter@agiColorModelRGB565_Rev@@UAEIIIII@Z
    ARTS_IMPORT u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // ?FindColor@agiColorModelRGB565_Rev@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 FindColor(agiRgba arg1) override;

    // ?GetColor@agiColorModelRGB565_Rev@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 GetColor(agiRgba arg1) override;

    // ?GetPixel@agiColorModelRGB565_Rev@@UAEIPAVagiSurfaceDesc@@HH@Z
    ARTS_EXPORT u32 GetPixel(agiSurfaceDesc* surface, i32 x, i32 y) override;

    // ?SetPixel@agiColorModelRGB565_Rev@@UAEXPAVagiSurfaceDesc@@HHI@Z
    ARTS_IMPORT void SetPixel(agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelRGB565_Rev, 0x2C);

class agiColorModelRGB888 final : public agiColorModel
{
public:
    // ??0agiColorModelRGB888@@QAE@XZ
    ARTS_IMPORT agiColorModelRGB888();

    // ??1agiColorModelRGB888@@UAE@XZ | inline
    ARTS_EXPORT ~agiColorModelRGB888() override = default;

    // ?Filter@agiColorModelRGB888@@UAEIIIII@Z
    ARTS_IMPORT u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // ?FindColor@agiColorModelRGB888@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 FindColor(agiRgba arg1) override;

    // ?GetColor@agiColorModelRGB888@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 GetColor(agiRgba arg1) override;

    // ?GetPixel@agiColorModelRGB888@@UAEIPAVagiSurfaceDesc@@HH@Z
    ARTS_EXPORT u32 GetPixel(agiSurfaceDesc* surface, i32 x, i32 y) override;

    // ?SetPixel@agiColorModelRGB888@@UAEXPAVagiSurfaceDesc@@HHI@Z
    ARTS_IMPORT void SetPixel(agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelRGB888, 0x2C);

class agiColorModelRGB888_Rev final : public agiColorModel
{
public:
    // ??0agiColorModelRGB888_Rev@@QAE@XZ
    ARTS_IMPORT agiColorModelRGB888_Rev();

    // ??1agiColorModelRGB888_Rev@@UAE@XZ | inline
    ARTS_EXPORT ~agiColorModelRGB888_Rev() override = default;

    // ?Filter@agiColorModelRGB888_Rev@@UAEIIIII@Z
    ARTS_IMPORT u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // ?FindColor@agiColorModelRGB888_Rev@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 FindColor(agiRgba arg1) override;

    // ?GetColor@agiColorModelRGB888_Rev@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 GetColor(agiRgba arg1) override;

    // ?GetPixel@agiColorModelRGB888_Rev@@UAEIPAVagiSurfaceDesc@@HH@Z
    ARTS_EXPORT u32 GetPixel(agiSurfaceDesc* surface, i32 x, i32 y) override;

    // ?SetPixel@agiColorModelRGB888_Rev@@UAEXPAVagiSurfaceDesc@@HHI@Z
    ARTS_IMPORT void SetPixel(agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelRGB888_Rev, 0x2C);

class agiColorModelRGBA5551 final : public agiColorModel
{
public:
    // ??0agiColorModelRGBA5551@@QAE@XZ
    ARTS_IMPORT agiColorModelRGBA5551();

    // ??1agiColorModelRGBA5551@@UAE@XZ | inline
    ARTS_EXPORT ~agiColorModelRGBA5551() override = default;

    // ?Filter@agiColorModelRGBA5551@@UAEIIIII@Z
    ARTS_IMPORT u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // ?FindColor@agiColorModelRGBA5551@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 FindColor(agiRgba arg1) override;

    // ?GetColor@agiColorModelRGBA5551@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 GetColor(agiRgba arg1) override;

    // ?GetPixel@agiColorModelRGBA5551@@UAEIPAVagiSurfaceDesc@@HH@Z
    ARTS_EXPORT u32 GetPixel(agiSurfaceDesc* surface, i32 x, i32 y) override;

    // ?SetPixel@agiColorModelRGBA5551@@UAEXPAVagiSurfaceDesc@@HHI@Z
    ARTS_IMPORT void SetPixel(agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelRGBA5551, 0x2C);

class agiColorModelRGBA4444 final : public agiColorModel
{
public:
    // ??0agiColorModelRGBA4444@@QAE@XZ
    ARTS_IMPORT agiColorModelRGBA4444();

    // ??1agiColorModelRGBA4444@@UAE@XZ | inline
    ARTS_EXPORT ~agiColorModelRGBA4444() override = default;

    // ?Filter@agiColorModelRGBA4444@@UAEIIIII@Z
    ARTS_IMPORT u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // ?FindColor@agiColorModelRGBA4444@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 FindColor(agiRgba arg1) override;

    // ?GetColor@agiColorModelRGBA4444@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 GetColor(agiRgba arg1) override;

    // ?GetPixel@agiColorModelRGBA4444@@UAEIPAVagiSurfaceDesc@@HH@Z
    ARTS_EXPORT u32 GetPixel(agiSurfaceDesc* surface, i32 x, i32 y) override;

    // ?SetPixel@agiColorModelRGBA4444@@UAEXPAVagiSurfaceDesc@@HHI@Z
    ARTS_IMPORT void SetPixel(agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelRGBA4444, 0x2C);

class agiColorModelARGB final : public agiColorModel
{
public:
    // ??0agiColorModelARGB@@QAE@XZ
    ARTS_IMPORT agiColorModelARGB();

    // ??1agiColorModelARGB@@UAE@XZ | inline
    ARTS_EXPORT ~agiColorModelARGB() override = default;

    // ?Filter@agiColorModelARGB@@UAEIIIII@Z
    ARTS_IMPORT u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // ?FindColor@agiColorModelARGB@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 FindColor(agiRgba arg1) override;

    // ?GetColor@agiColorModelARGB@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 GetColor(agiRgba arg1) override;

    // ?GetPixel@agiColorModelARGB@@UAEIPAVagiSurfaceDesc@@HH@Z
    ARTS_EXPORT u32 GetPixel(agiSurfaceDesc* surface, i32 x, i32 y) override;

    // ?SetPixel@agiColorModelARGB@@UAEXPAVagiSurfaceDesc@@HHI@Z
    ARTS_IMPORT void SetPixel(agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelARGB, 0x2C);

class agiColorModelABGR final : public agiColorModel
{
public:
    // ??0agiColorModelABGR@@QAE@XZ
    ARTS_IMPORT agiColorModelABGR();

    // ??1agiColorModelABGR@@UAE@XZ | inline
    ARTS_EXPORT ~agiColorModelABGR() override = default;

    // ?Filter@agiColorModelABGR@@UAEIIIII@Z
    ARTS_IMPORT u32 Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4) override;

    // ?FindColor@agiColorModelABGR@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 FindColor(agiRgba arg1) override;

    // ?GetColor@agiColorModelABGR@@UAEIUagiRgba@@@Z
    ARTS_IMPORT u32 GetColor(agiRgba arg1) override;

    // ?GetPixel@agiColorModelABGR@@UAEIPAVagiSurfaceDesc@@HH@Z
    ARTS_EXPORT u32 GetPixel(agiSurfaceDesc* surface, i32 x, i32 y) override;

    // ?SetPixel@agiColorModelABGR@@UAEXPAVagiSurfaceDesc@@HHI@Z
    ARTS_IMPORT void SetPixel(agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4) override;
};

check_size(agiColorModelABGR, 0x2C);

// ?ColorModelABGR@@3VagiColorModelABGR@@A
ARTS_IMPORT extern agiColorModelABGR ColorModelABGR;

// ?ColorModelARGB@@3VagiColorModelARGB@@A
ARTS_IMPORT extern agiColorModelARGB ColorModelARGB;

// ?ColorModelRGB555@@3VagiColorModelRGB555@@A
ARTS_IMPORT extern agiColorModelRGB555 ColorModelRGB555;

// ?ColorModelRGB555_Rev@@3VagiColorModelRGB555_Rev@@A
ARTS_IMPORT extern agiColorModelRGB555_Rev ColorModelRGB555_Rev;

// ?ColorModelRGB565@@3VagiColorModelRGB565@@A
ARTS_IMPORT extern agiColorModelRGB565 ColorModelRGB565;

// ?ColorModelRGB565_Rev@@3VagiColorModelRGB565_Rev@@A
ARTS_IMPORT extern agiColorModelRGB565_Rev ColorModelRGB565_Rev;

// ?ColorModelRGB888@@3VagiColorModelRGB888@@A
ARTS_IMPORT extern agiColorModelRGB888 ColorModelRGB888;

// ?ColorModelRGB888_Rev@@3VagiColorModelRGB888_Rev@@A
ARTS_IMPORT extern agiColorModelRGB888_Rev ColorModelRGB888_Rev;

// ?ColorModelRGBA4444@@3VagiColorModelRGBA4444@@A
ARTS_IMPORT extern agiColorModelRGBA4444 ColorModelRGBA4444;

// ?ColorModelRGBA5551@@3VagiColorModelRGBA5551@@A
ARTS_IMPORT extern agiColorModelRGBA5551 ColorModelRGBA5551;
