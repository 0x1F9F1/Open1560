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

#include "cmodelx.h"

agiColorModelRGB555::agiColorModelRGB555()
{
    unimplemented();
}

agiColorModelRGB555::~agiColorModelRGB555()
{
    unimplemented();
}

u32 agiColorModelRGB555::Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
    return stub<thiscall_t<u32, agiColorModelRGB555*, u32, u32, u32, u32>>(
        0x15C560_Offset, this, arg1, arg2, arg3, arg4);
}

u32 agiColorModelRGB555::FindColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelRGB555*, struct agiRgba>>(0x15C520_Offset, this, arg1);
}

u32 agiColorModelRGB555::GetColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelRGB555*, struct agiRgba>>(0x15C4E0_Offset, this, arg1);
}

u32 agiColorModelRGB555::GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<u32, agiColorModelRGB555*, class agiSurfaceDesc*, i32, i32>>(
        0x15C5F0_Offset, this, arg1, arg2, arg3);
}

void agiColorModelRGB555::SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4)
{
    return stub<thiscall_t<void, agiColorModelRGB555*, class agiSurfaceDesc*, i32, i32, u32>>(
        0x15C610_Offset, this, arg1, arg2, arg3, arg4);
}

agiColorModelRGB565::agiColorModelRGB565()
{
    unimplemented();
}

agiColorModelRGB565::~agiColorModelRGB565()
{
    unimplemented();
}

u32 agiColorModelRGB565::Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
    return stub<thiscall_t<u32, agiColorModelRGB565*, u32, u32, u32, u32>>(
        0x15C740_Offset, this, arg1, arg2, arg3, arg4);
}

u32 agiColorModelRGB565::FindColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelRGB565*, struct agiRgba>>(0x15C700_Offset, this, arg1);
}

u32 agiColorModelRGB565::GetColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelRGB565*, struct agiRgba>>(0x15C6C0_Offset, this, arg1);
}

u32 agiColorModelRGB565::GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<u32, agiColorModelRGB565*, class agiSurfaceDesc*, i32, i32>>(
        0x15C7D0_Offset, this, arg1, arg2, arg3);
}

void agiColorModelRGB565::SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4)
{
    return stub<thiscall_t<void, agiColorModelRGB565*, class agiSurfaceDesc*, i32, i32, u32>>(
        0x15C7F0_Offset, this, arg1, arg2, arg3, arg4);
}

agiColorModelRGB555_Rev::agiColorModelRGB555_Rev()
{
    unimplemented();
}

agiColorModelRGB555_Rev::~agiColorModelRGB555_Rev()
{
    unimplemented();
}

u32 agiColorModelRGB555_Rev::Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
    return stub<thiscall_t<u32, agiColorModelRGB555_Rev*, u32, u32, u32, u32>>(
        0x15C920_Offset, this, arg1, arg2, arg3, arg4);
}

u32 agiColorModelRGB555_Rev::FindColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelRGB555_Rev*, struct agiRgba>>(0x15C8E0_Offset, this, arg1);
}

u32 agiColorModelRGB555_Rev::GetColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelRGB555_Rev*, struct agiRgba>>(0x15C8A0_Offset, this, arg1);
}

u32 agiColorModelRGB555_Rev::GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<u32, agiColorModelRGB555_Rev*, class agiSurfaceDesc*, i32, i32>>(
        0x15C9B0_Offset, this, arg1, arg2, arg3);
}

void agiColorModelRGB555_Rev::SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4)
{
    return stub<thiscall_t<void, agiColorModelRGB555_Rev*, class agiSurfaceDesc*, i32, i32, u32>>(
        0x15C9D0_Offset, this, arg1, arg2, arg3, arg4);
}

agiColorModelRGB565_Rev::agiColorModelRGB565_Rev()
{
    unimplemented();
}

agiColorModelRGB565_Rev::~agiColorModelRGB565_Rev()
{
    unimplemented();
}

u32 agiColorModelRGB565_Rev::Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
    return stub<thiscall_t<u32, agiColorModelRGB565_Rev*, u32, u32, u32, u32>>(
        0x15CB00_Offset, this, arg1, arg2, arg3, arg4);
}

u32 agiColorModelRGB565_Rev::FindColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelRGB565_Rev*, struct agiRgba>>(0x15CAC0_Offset, this, arg1);
}

u32 agiColorModelRGB565_Rev::GetColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelRGB565_Rev*, struct agiRgba>>(0x15CA80_Offset, this, arg1);
}

u32 agiColorModelRGB565_Rev::GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<u32, agiColorModelRGB565_Rev*, class agiSurfaceDesc*, i32, i32>>(
        0x15CB90_Offset, this, arg1, arg2, arg3);
}

void agiColorModelRGB565_Rev::SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4)
{
    return stub<thiscall_t<void, agiColorModelRGB565_Rev*, class agiSurfaceDesc*, i32, i32, u32>>(
        0x15CBB0_Offset, this, arg1, arg2, arg3, arg4);
}

agiColorModelRGB888::agiColorModelRGB888()
{
    unimplemented();
}

agiColorModelRGB888::~agiColorModelRGB888()
{
    unimplemented();
}

u32 agiColorModelRGB888::Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
    return stub<thiscall_t<u32, agiColorModelRGB888*, u32, u32, u32, u32>>(
        0x15CCC0_Offset, this, arg1, arg2, arg3, arg4);
}

u32 agiColorModelRGB888::FindColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelRGB888*, struct agiRgba>>(0x15CC90_Offset, this, arg1);
}

u32 agiColorModelRGB888::GetColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelRGB888*, struct agiRgba>>(0x15CC60_Offset, this, arg1);
}

u32 agiColorModelRGB888::GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<u32, agiColorModelRGB888*, class agiSurfaceDesc*, i32, i32>>(
        0x15CD40_Offset, this, arg1, arg2, arg3);
}

void agiColorModelRGB888::SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4)
{
    return stub<thiscall_t<void, agiColorModelRGB888*, class agiSurfaceDesc*, i32, i32, u32>>(
        0x15CD60_Offset, this, arg1, arg2, arg3, arg4);
}

agiColorModelRGB888_Rev::agiColorModelRGB888_Rev()
{
    unimplemented();
}

agiColorModelRGB888_Rev::~agiColorModelRGB888_Rev()
{
    unimplemented();
}

u32 agiColorModelRGB888_Rev::Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
    return stub<thiscall_t<u32, agiColorModelRGB888_Rev*, u32, u32, u32, u32>>(
        0x15CE60_Offset, this, arg1, arg2, arg3, arg4);
}

u32 agiColorModelRGB888_Rev::FindColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelRGB888_Rev*, struct agiRgba>>(0x15CE30_Offset, this, arg1);
}

u32 agiColorModelRGB888_Rev::GetColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelRGB888_Rev*, struct agiRgba>>(0x15CE00_Offset, this, arg1);
}

u32 agiColorModelRGB888_Rev::GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<u32, agiColorModelRGB888_Rev*, class agiSurfaceDesc*, i32, i32>>(
        0x15CEE0_Offset, this, arg1, arg2, arg3);
}

void agiColorModelRGB888_Rev::SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4)
{
    return stub<thiscall_t<void, agiColorModelRGB888_Rev*, class agiSurfaceDesc*, i32, i32, u32>>(
        0x15CF00_Offset, this, arg1, arg2, arg3, arg4);
}

agiColorModelRGBA5551::agiColorModelRGBA5551()
{
    unimplemented();
}

agiColorModelRGBA5551::~agiColorModelRGBA5551()
{
    unimplemented();
}

u32 agiColorModelRGBA5551::Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
    return stub<thiscall_t<u32, agiColorModelRGBA5551*, u32, u32, u32, u32>>(
        0x15D050_Offset, this, arg1, arg2, arg3, arg4);
}

u32 agiColorModelRGBA5551::FindColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelRGBA5551*, struct agiRgba>>(0x15D000_Offset, this, arg1);
}

u32 agiColorModelRGBA5551::GetColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelRGBA5551*, struct agiRgba>>(0x15CFB0_Offset, this, arg1);
}

u32 agiColorModelRGBA5551::GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<u32, agiColorModelRGBA5551*, class agiSurfaceDesc*, i32, i32>>(
        0x15D110_Offset, this, arg1, arg2, arg3);
}

void agiColorModelRGBA5551::SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4)
{
    return stub<thiscall_t<void, agiColorModelRGBA5551*, class agiSurfaceDesc*, i32, i32, u32>>(
        0x15D130_Offset, this, arg1, arg2, arg3, arg4);
}

agiColorModelRGBA4444::agiColorModelRGBA4444()
{
    unimplemented();
}

agiColorModelRGBA4444::~agiColorModelRGBA4444()
{
    unimplemented();
}

u32 agiColorModelRGBA4444::Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
    return stub<thiscall_t<u32, agiColorModelRGBA4444*, u32, u32, u32, u32>>(
        0x15D280_Offset, this, arg1, arg2, arg3, arg4);
}

u32 agiColorModelRGBA4444::FindColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelRGBA4444*, struct agiRgba>>(0x15D230_Offset, this, arg1);
}

u32 agiColorModelRGBA4444::GetColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelRGBA4444*, struct agiRgba>>(0x15D1E0_Offset, this, arg1);
}

u32 agiColorModelRGBA4444::GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<u32, agiColorModelRGBA4444*, class agiSurfaceDesc*, i32, i32>>(
        0x15D340_Offset, this, arg1, arg2, arg3);
}

void agiColorModelRGBA4444::SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4)
{
    return stub<thiscall_t<void, agiColorModelRGBA4444*, class agiSurfaceDesc*, i32, i32, u32>>(
        0x15D360_Offset, this, arg1, arg2, arg3, arg4);
}

agiColorModelARGB::agiColorModelARGB()
{
    unimplemented();
}

agiColorModelARGB::~agiColorModelARGB()
{
    unimplemented();
}

u32 agiColorModelARGB::Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
    return stub<thiscall_t<u32, agiColorModelARGB*, u32, u32, u32, u32>>(0x15D490_Offset, this, arg1, arg2, arg3, arg4);
}

u32 agiColorModelARGB::FindColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelARGB*, struct agiRgba>>(0x15D450_Offset, this, arg1);
}

u32 agiColorModelARGB::GetColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelARGB*, struct agiRgba>>(0x15D410_Offset, this, arg1);
}

u32 agiColorModelARGB::GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<u32, agiColorModelARGB*, class agiSurfaceDesc*, i32, i32>>(
        0x15D530_Offset, this, arg1, arg2, arg3);
}

void agiColorModelARGB::SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4)
{
    return stub<thiscall_t<void, agiColorModelARGB*, class agiSurfaceDesc*, i32, i32, u32>>(
        0x15D550_Offset, this, arg1, arg2, arg3, arg4);
}

agiColorModelABGR::agiColorModelABGR()
{
    unimplemented();
}

agiColorModelABGR::~agiColorModelABGR()
{
    unimplemented();
}

u32 agiColorModelABGR::Filter(u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
    return stub<thiscall_t<u32, agiColorModelABGR*, u32, u32, u32, u32>>(0x15D670_Offset, this, arg1, arg2, arg3, arg4);
}

u32 agiColorModelABGR::FindColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelABGR*, struct agiRgba>>(0x15D630_Offset, this, arg1);
}

u32 agiColorModelABGR::GetColor(struct agiRgba arg1)
{
    return stub<thiscall_t<u32, agiColorModelABGR*, struct agiRgba>>(0x15D5F0_Offset, this, arg1);
}

u32 agiColorModelABGR::GetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3)
{
    return stub<thiscall_t<u32, agiColorModelABGR*, class agiSurfaceDesc*, i32, i32>>(
        0x15D720_Offset, this, arg1, arg2, arg3);
}

void agiColorModelABGR::SetPixel(class agiSurfaceDesc* arg1, i32 arg2, i32 arg3, u32 arg4)
{
    return stub<thiscall_t<void, agiColorModelABGR*, class agiSurfaceDesc*, i32, i32, u32>>(
        0x15D740_Offset, this, arg1, arg2, arg3, arg4);
}

define_dummy_symbol(agi_cmodelx);
