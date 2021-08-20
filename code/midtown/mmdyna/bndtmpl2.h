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
    mmdyna:bndtmpl2

    0x5171D0 | public: void __thiscall mmBoundTemplate::InitGeometry(int,int) | ?InitGeometry@mmBoundTemplate@@QAEXHH@Z
    0x517280 | public: void __thiscall mmBoundTemplate::AddTriangle(int,int,int,int,int) | ?AddTriangle@mmBoundTemplate@@QAEXHHHHH@Z
    0x517370 | public: void __thiscall mmBoundTemplate::AddQuad(int,int,int,int,int,int) | ?AddQuad@mmBoundTemplate@@QAEXHHHHHH@Z
    0x5175E0 | public: void __thiscall mmBoundTemplate::ComputeBounds(void) | ?ComputeBounds@mmBoundTemplate@@QAEXXZ
    0x517620 | bool __cdecl EdgeInList(int,int,long,int *,int *) | ?EdgeInList@@YA_NHHJPAH0@Z
    0x517680 | public: void __thiscall mmBoundTemplate::ComputeEdges(void) | ?ComputeEdges@mmBoundTemplate@@QAEXXZ
    0x517850 | public: int __thiscall mmBoundTemplate::Load(char *,char *,class Vector3 *,int,int,int,int,int,int) | ?Load@mmBoundTemplate@@QAEHPAD0PAVVector3@@HHHHHH@Z
    0x518D40 | private: static void __cdecl mmBoundTemplate::PageOutCallback(void *,int) | ?PageOutCallback@mmBoundTemplate@@CAXPAXH@Z
    0x518E90 | private: void __thiscall mmBoundTemplate::DoPageIn(void) | ?DoPageIn@mmBoundTemplate@@AAEXXZ
    0x5192F0 | private: static void __cdecl mmBoundTemplate::PageInCallback(void *) | ?PageInCallback@mmBoundTemplate@@CAXPAX@Z
    0x519300 | public: void __thiscall mmBoundTemplate::PageIn(void) | ?PageIn@mmBoundTemplate@@QAEXXZ
    0x519320 | public: int __thiscall mmBoundTemplate::LockIfResident(void) | ?LockIfResident@mmBoundTemplate@@QAEHXZ
    0x519380 | public: void __thiscall mmBoundTemplate::Unlock(void) | ?Unlock@mmBoundTemplate@@QAEXXZ
    0x5193A0 | public: void __thiscall mmBoundTemplate::ComputeEdgeNormals(void) | ?ComputeEdgeNormals@mmBoundTemplate@@QAEXXZ
    0x519830 | private: void __thiscall mmBoundTemplate::MakeTable(int,int,int) | ?MakeTable@mmBoundTemplate@@AAEXHHH@Z
    0x519A30 | private: void __thiscall mmBoundTemplate::DoMakeTable(int,int,int) | ?DoMakeTable@mmBoundTemplate@@AAEXHHH@Z
    0x519F70 | public: void __thiscall mmBoundTemplate::AddIndex(int,int,int) | ?AddIndex@mmBoundTemplate@@QAEXHHH@Z
    0x51A090 | public: void __thiscall mmBoundTemplate::PlotLine(class Vector3,class Vector3) | ?PlotLine@mmBoundTemplate@@QAEXVVector3@@0@Z
    0x51A1A0 | public: void __thiscall mmBoundTemplate::PlotSpan(int,int,int) | ?PlotSpan@mmBoundTemplate@@QAEXHHH@Z
    0x77EE30 | int BoundBytesPaged | ?BoundBytesPaged@@3HA
    0x77EE38 | public: static int mmBoundTemplate::WinID | ?WinID@mmBoundTemplate@@2HA
    0x77EE3C | public: static int mmBoundTemplate::NumIndexs | ?NumIndexs@mmBoundTemplate@@2HA
    0x77EE44 | int BoundsPaged | ?BoundsPaged@@3HA
    0x77EE48 | public: static int mmBoundTemplate::DrawGrid | ?DrawGrid@mmBoundTemplate@@2HA
    0x77EED0 | public: static unsigned short * mmBoundTemplate::ConstructionTable | ?ConstructionTable@mmBoundTemplate@@2PAGA
    0x77EED4 | public: static int mmBoundTemplate::MaxPerBucket | ?MaxPerBucket@mmBoundTemplate@@2HA
    0x77EED8 | class Stream * MakeTableStats | ?MakeTableStats@@3PAVStream@@A
*/

// ?EdgeInList@@YA_NHHJPAH0@Z
ARTS_IMPORT bool EdgeInList(i32 arg1, i32 arg2, ilong arg3, i32* arg4, i32* arg5);

// ?BoundBytesPaged@@3HA
ARTS_IMPORT extern i32 BoundBytesPaged;

// ?BoundsPaged@@3HA
ARTS_IMPORT extern i32 BoundsPaged;

// ?MakeTableStats@@3PAVStream@@A
ARTS_IMPORT extern Stream* MakeTableStats;
