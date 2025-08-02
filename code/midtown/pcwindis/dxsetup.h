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
    pcwindis:dxsetup

    0x575320 | int __stdcall MultiMonCallback(struct _GUID *,char *,char *,void *,void *) | ?MultiMonCallback@@YGHPAU_GUID@@PAD1PAX2@Z
    0x575360 | void __cdecl dxiConfig(int,char * *) | ?dxiConfig@@YAXHPAPAD@Z
    0x575710 | void __cdecl NeedDX6(void) | ?NeedDX6@@YAXXZ
    0x575740 | int __stdcall EnumCounter(struct _GUID *,char *,char *,void *) | ?EnumCounter@@YGHPAU_GUID@@PAD1PAX@Z
    0x575760 | void __cdecl MyDirectDrawEnumerate(int (__stdcall*)(struct _GUID *,char *,char *,void *),void *) | ?MyDirectDrawEnumerate@@YAXP6GHPAU_GUID@@PAD1PAX@Z2@Z
    0x5757D0 | void __cdecl EnumerateRenderers2(void) | ?EnumerateRenderers2@@YAXXZ
    0x575920 | int __cdecl CheckSoftwareRenderer(struct IDirectDraw4 *,struct _GUID *) | ?CheckSoftwareRenderer@@YAHPAUIDirectDraw4@@PAU_GUID@@@Z
    0x575A10 | long __cdecl LockScreen(struct IDirectDraw4 *) | ?LockScreen@@YAJPAUIDirectDraw4@@@Z
    0x575AD0 | void __cdecl UnlockScreen(void) | ?UnlockScreen@@YAXXZ
    0x575AF0 | int __cdecl TestResolution(struct IDirectDraw4 *,struct dxiRendererInfo_t &) | ?TestResolution@@YAHPAUIDirectDraw4@@AAUdxiRendererInfo_t@@@Z
    0x575F40 | long __stdcall ModeCallback(struct _DDSURFACEDESC2 *,void *) | ?ModeCallback@@YGJPAU_DDSURFACEDESC2@@PAX@Z
    0x575FD0 | long __stdcall EnumZ(struct _DDPIXELFORMAT *,void *) | ?EnumZ@@YGJPAU_DDPIXELFORMAT@@PAX@Z
    0x576000 | void __cdecl AddRenderer(struct IDirectDraw4 *,struct _GUID *,char *) | ?AddRenderer@@YAXPAUIDirectDraw4@@PAU_GUID@@PAD@Z
    0x576470 | long __stdcall EnumTextures(struct _DDPIXELFORMAT *,void *) | ?EnumTextures@@YGJPAU_DDPIXELFORMAT@@PAX@Z
    0x5764A0 | int __cdecl NotLameChipset(unsigned long,unsigned long) | ?NotLameChipset@@YAHKK@Z
    0x5764B0 | unsigned int __cdecl GetSpecialFlags(unsigned long,unsigned long) | ?GetSpecialFlags@@YAIKK@Z
    0x576580 | int __stdcall Enumerator(struct _GUID *,char *,char *,void *) | ?Enumerator@@YGHPAU_GUID@@PAD1PAX@Z
    0x90A560 | int dxiCpuSpeed | ?dxiCpuSpeed@@3HA
*/

// ?dxiConfig@@YAXHPAPAD@Z
ARTS_EXPORT void dxiConfig(i32 argc, char** argv);

// ?dxiCpuSpeed@@3HA
ARTS_IMPORT extern i32 dxiCpuSpeed;
