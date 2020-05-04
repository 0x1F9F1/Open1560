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

#include "data7/miniparser.h"

/*
    stream:sparser

    0x561370 | public: __thiscall StreamMiniParser::StreamMiniParser(char *,class Stream *) | ??0StreamMiniParser@@QAE@PADPAVStream@@@Z
    0x5613A0 | public: __thiscall StreamMiniParser::~StreamMiniParser(void) | ??1StreamMiniParser@@QAE@XZ
    0x561400 | public: virtual void __thiscall StreamMiniParser::RawPutCh(int) | ?RawPutCh@StreamMiniParser@@UAEXH@Z
    0x561440 | public: virtual int __thiscall StreamMiniParser::RawGetCh(void) | ?RawGetCh@StreamMiniParser@@UAEHXZ
    0x561470 | public: static void __cdecl StreamMiniParser::Load(class MetaClass *,char *,void *) | ?Load@StreamMiniParser@@SAXPAVMetaClass@@PADPAX@Z
    0x561520 | public: static void __cdecl StreamMiniParser::Save(class MetaClass *,char *,void *) | ?Save@StreamMiniParser@@SAXPAVMetaClass@@PADPAX@Z
    0x6219E8 | const StreamMiniParser::`vftable' | ??_7StreamMiniParser@@6B@
*/

class StreamMiniParser : public MiniParser
{
    // const StreamMiniParser::`vftable' @ 0x6219E8

public:
    // 0x561370 | ??0StreamMiniParser@@QAE@PADPAVStream@@@Z
    StreamMiniParser(char* arg1, class Stream* arg2);

    // 0x5613A0 | ??1StreamMiniParser@@QAE@XZ
    ~StreamMiniParser();

    // 0x561440 | ?RawGetCh@StreamMiniParser@@UAEHXZ
    i32 RawGetCh() override;

    // 0x561400 | ?RawPutCh@StreamMiniParser@@UAEXH@Z
    void RawPutCh(i32 arg1) override;

    // 0x561470 | ?Load@StreamMiniParser@@SAXPAVMetaClass@@PADPAX@Z
    static void Load(class MetaClass* arg1, char* arg2, void* arg3);

    // 0x561520 | ?Save@StreamMiniParser@@SAXPAVMetaClass@@PADPAX@Z
    static void Save(class MetaClass* arg1, char* arg2, void* arg3);
};

check_size(StreamMiniParser, 0x0);
