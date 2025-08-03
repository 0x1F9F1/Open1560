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

class MiniParser
{
public:
    enum Token : i32
    {
        EndToken = -1,
        IntegerToken = 256,
        StringToken = 257,
        IdentToken = 258,
        LabelToken = 259,
        LabelRefToken = 260,
        FloatToken = 261,
    };

    // ??0MiniParser@@QAE@PAD@Z
    MiniParser(const char* name)
        : name_(name)
    {}

    // ??1MiniParser@@QAE@XZ
    ~MiniParser() = default;

    virtual i32 RawGetCh() = 0;

    virtual void RawPutCh(i32 arg1) = 0;

    // ?Commentf@MiniParser@@QAAXPBDZZ | unused
    void Commentf(ARTS_FORMAT_STRING const char* format, ...);

    // ?Errorf@MiniParser@@QAAXPBDZZ
    void Errorf(ARTS_FORMAT_STRING const char* format, ...);

    // ?FloatVal@MiniParser@@QAEMXZ
    ARTS_EXPORT f32 FloatVal();

    // ?GetCh@MiniParser@@QAEHXZ
    i32 GetCh();

    // ?Indent@MiniParser@@QAEXH@Z
    ARTS_EXPORT void Indent(i32 amount);

    // ?Int64Val@MiniParser@@QAE_JXZ
    ARTS_EXPORT i64 Int64Val();

    // ?IntVal@MiniParser@@QAEHXZ
    ARTS_EXPORT i32 IntVal();

    // ?Match@MiniParser@@QAEXH@Z
    ARTS_EXPORT void Match(i32 expected);

    // ?NextToken@MiniParser@@QAEHXZ
    ARTS_EXPORT i32 NextToken();

    // ?PlaceLabel@MiniParser@@QAEXPAX@Z
    void PlaceLabel(void* ptr);

    // ?PlaceLabelRef@MiniParser@@QAEXPAX@Z
    void PlaceLabelRef(void* ptr);

    // ?PrintString@MiniParser@@QAEXPADH@Z
    void PrintString(const char* str, i32 len);

    // ?Printf@MiniParser@@QAAXPBDZZ
    ARTS_EXPORT void Printf(ARTS_FORMAT_STRING const char* format, ...);

    // ?PutBack@MiniParser@@QAEXH@Z
    ARTS_EXPORT void PutBack(i32 token);

    // ?PutCh@MiniParser@@QAEXH@Z
    ARTS_EXPORT void PutCh(i32 value);

    // ?ResolveLabel@MiniParser@@QAEPAXPADPAPAX@Z | unused
    void* ResolveLabel(char* arg1, void** arg2);

    const char* GetBuffer() const
    {
        return buffer_;
    }

    i32 GetErrorCount() const
    {
        return error_count_;
    }

    // ?TokenName@MiniParser@@SAPADH@Z
    static const char* TokenName(i32 token);

private:
    void PutString(const char* str);

    char buffer_[256] {};
    i32 error_count_ {};
    ConstString name_;
    i32 current_char_ {' '};
    i32 indentation_ {};
    i32 current_line_ {1};
    i32 put_back_ {};
};

check_size(MiniParser, 0x11C);
