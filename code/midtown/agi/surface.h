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
    agi:surface

    0x55A720 | public: static class agiSurfaceDesc * __cdecl agiSurfaceDesc::Init(int,int,class agiSurfaceDesc &) | ?Init@agiSurfaceDesc@@SAPAV1@HHAAV1@@Z
    0x55A7A0 | public: static class agiSurfaceDesc * __cdecl agiSurfaceDesc::Load(char *,char *,int,int,int,int) | ?Load@agiSurfaceDesc@@SAPAV1@PAD0HHHH@Z
    0x55ADE0 | public: void __thiscall agiSurfaceDesc::Reload(char *,char *,int,int,class Stream *,int,int) | ?Reload@agiSurfaceDesc@@QAEXPAD0HHPAVStream@@HH@Z
    0x55B160 | public: void __thiscall agiSurfaceDesc::Unload(void) | ?Unload@agiSurfaceDesc@@QAEXXZ
    0x55B180 | public: void __thiscall agiSurfaceDesc::CopyFrom(class agiSurfaceDesc *,int) | ?CopyFrom@agiSurfaceDesc@@QAEXPAV1@H@Z
    0x903190 | int AnnotateTextures | ?AnnotateTextures@@3HA
*/

class agiSurfaceDesc
{
public:
    // 0x55B180 | ?CopyFrom@agiSurfaceDesc@@QAEXPAV1@H@Z
    void CopyFrom(class agiSurfaceDesc* arg1, i32 arg2);

    // 0x55ADE0 | ?Reload@agiSurfaceDesc@@QAEXPAD0HHPAVStream@@HH@Z
    void Reload(char* arg1, char* arg2, i32 arg3, i32 arg4, class Stream* arg5, i32 arg6, i32 arg7);

    // 0x55B160 | ?Unload@agiSurfaceDesc@@QAEXXZ
    void Unload();

    // 0x55A720 | ?Init@agiSurfaceDesc@@SAPAV1@HHAAV1@@Z
    static class agiSurfaceDesc* Init(i32 arg1, i32 arg2, class agiSurfaceDesc& arg3);

    // 0x55A7A0 | ?Load@agiSurfaceDesc@@SAPAV1@PAD0HHHH@Z
    static class agiSurfaceDesc* Load(char* arg1, char* arg2, i32 arg3, i32 arg4, i32 arg5, i32 arg6);
};

check_size(agiSurfaceDesc, 0x0);

// 0x903190 | ?AnnotateTextures@@3HA
inline extern_var(0x903190, i32, AnnotateTextures);
