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
    mmai:aiIntersection

    0x4472E0 | public: __thiscall aiIntersection::aiIntersection(int) | ??0aiIntersection@@QAE@H@Z
    0x447300 | public: __thiscall aiIntersection::~aiIntersection(void) | ??1aiIntersection@@QAE@XZ
    0x447370 | public: void __thiscall aiIntersection::Init(void) | ?Init@aiIntersection@@QAEXXZ
    0x447520 | public: void __thiscall aiIntersection::Reset(void) | ?Reset@aiIntersection@@QAEXXZ
    0x447530 | public: void __thiscall aiIntersection::AddSinkPath(class aiPath *) | ?AddSinkPath@aiIntersection@@QAEXPAVaiPath@@@Z
    0x4475A0 | public: void __thiscall aiIntersection::AddSourcePath(class aiPath *) | ?AddSourcePath@aiIntersection@@QAEXPAVaiPath@@@Z
    0x447610 | public: void __thiscall aiIntersection::SaveBinary(class Stream *) | ?SaveBinary@aiIntersection@@QAEXPAVStream@@@Z
    0x4476E0 | public: void __thiscall aiIntersection::ReadBinary(class Stream *) | ?ReadBinary@aiIntersection@@QAEXPAVStream@@@Z
    0x447880 | public: void __thiscall aiIntersection::DrawPaths(void) | ?DrawPaths@aiIntersection@@QAEXXZ
    0x4478B0 | public: void __thiscall aiIntersection::DrawId(void) | ?DrawId@aiIntersection@@QAEXXZ
    0x4478F0 | public: void __thiscall aiIntersection::Dump(void) | ?Dump@aiIntersection@@QAEXXZ
    0x447920 | public: void __thiscall aiIntersection::CreateRoadMap(void) | ?CreateRoadMap@aiIntersection@@QAEXXZ
    0x447C50 | public: class aiPath * __thiscall aiIntersection::Path(int) | ?Path@aiIntersection@@QAEPAVaiPath@@H@Z
*/

class aiIntersection
{
public:
    // 0x4472E0 | ??0aiIntersection@@QAE@H@Z
    aiIntersection(i32 arg1);

    // 0x447300 | ??1aiIntersection@@QAE@XZ
    ~aiIntersection();

    // 0x447530 | ?AddSinkPath@aiIntersection@@QAEXPAVaiPath@@@Z
    void AddSinkPath(class aiPath* arg1);

    // 0x4475A0 | ?AddSourcePath@aiIntersection@@QAEXPAVaiPath@@@Z
    void AddSourcePath(class aiPath* arg1);

    // 0x447920 | ?CreateRoadMap@aiIntersection@@QAEXXZ
    void CreateRoadMap();

    // 0x4478B0 | ?DrawId@aiIntersection@@QAEXXZ
    void DrawId();

    // 0x447880 | ?DrawPaths@aiIntersection@@QAEXXZ
    void DrawPaths();

    // 0x4478F0 | ?Dump@aiIntersection@@QAEXXZ
    void Dump();

    // 0x447370 | ?Init@aiIntersection@@QAEXXZ
    void Init();

    // 0x447C50 | ?Path@aiIntersection@@QAEPAVaiPath@@H@Z
    class aiPath* Path(i32 arg1);

    // 0x4476E0 | ?ReadBinary@aiIntersection@@QAEXPAVStream@@@Z
    void ReadBinary(class Stream* arg1);

    // 0x447520 | ?Reset@aiIntersection@@QAEXXZ
    void Reset();

    // 0x447610 | ?SaveBinary@aiIntersection@@QAEXPAVStream@@@Z
    void SaveBinary(class Stream* arg1);
};

check_size(aiIntersection, 0x2C);
