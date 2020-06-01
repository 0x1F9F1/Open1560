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
    data7:miniparser

    0x57C5E0 | public: __thiscall MiniParser::MiniParser(char *) | ??0MiniParser@@QAE@PAD@Z
    0x57C640 | public: __thiscall MiniParser::~MiniParser(void) | ??1MiniParser@@QAE@XZ
    0x57C660 | public: void __cdecl MiniParser::Printf(char const *,...) | ?Printf@MiniParser@@QAAXPBDZZ
    0x57C6B0 | public: void __thiscall MiniParser::PrintString(char *,int) | ?PrintString@MiniParser@@QAEXPADH@Z
    0x57C710 | public: void __cdecl MiniParser::Errorf(char const *,...) | ?Errorf@MiniParser@@QAAXPBDZZ
    0x57C7B0 | public: void __cdecl MiniParser::Commentf(char const *,...) | ?Commentf@MiniParser@@QAAXPBDZZ
    0x57C810 | public: int __thiscall MiniParser::GetCh(void) | ?GetCh@MiniParser@@QAEHXZ
    0x57C830 | public: void __thiscall MiniParser::PutCh(int) | ?PutCh@MiniParser@@QAEXH@Z
    0x57C880 | public: void __thiscall MiniParser::Indent(int) | ?Indent@MiniParser@@QAEXH@Z
    0x57C8A0 | public: void __thiscall MiniParser::Match(int) | ?Match@MiniParser@@QAEXH@Z
    0x57C8E0 | public: static char * __cdecl MiniParser::TokenName(int) | ?TokenName@MiniParser@@SAPADH@Z
    0x57CA80 | public: void __thiscall MiniParser::PlaceLabel(void *) | ?PlaceLabel@MiniParser@@QAEXPAX@Z
    0x57CAA0 | public: void __thiscall MiniParser::PlaceLabelRef(void *) | ?PlaceLabelRef@MiniParser@@QAEXPAX@Z
    0x57CAC0 | public: void * __thiscall MiniParser::ResolveLabel(char *,void * *) | ?ResolveLabel@MiniParser@@QAEPAXPADPAPAX@Z
    0x57CAD0 | public: void __thiscall MiniParser::PutBack(int) | ?PutBack@MiniParser@@QAEXH@Z
    0x57CB00 | public: int __thiscall MiniParser::NextToken(void) | ?NextToken@MiniParser@@QAEHXZ
    0x57CD00 | public: int __thiscall MiniParser::IntVal(void) | ?IntVal@MiniParser@@QAEHXZ
    0x57CD40 | public: __int64 __thiscall MiniParser::Int64Val(void) | ?Int64Val@MiniParser@@QAE_JXZ
    0x57CD80 | public: float __thiscall MiniParser::FloatVal(void) | ?FloatVal@MiniParser@@QAEMXZ
    0x621EC8 | const MiniParser::`vftable' | ??_7MiniParser@@6B@
*/

class MiniParser
{
    // const MiniParser::`vftable' @ 0x621EC8

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

    // 0x57C5E0 | ??0MiniParser@@QAE@PAD@Z
    MiniParser(const char* name);

    // 0x57C640 | ??1MiniParser@@QAE@XZ
    ~MiniParser();

    virtual i32 RawGetCh() = 0;

    virtual void RawPutCh(i32 arg1) = 0;

    // 0x57C7B0 | ?Commentf@MiniParser@@QAAXPBDZZ | unused
    void Commentf(char const* format, ...);

    // 0x57C710 | ?Errorf@MiniParser@@QAAXPBDZZ
    void Errorf(char const* format, ...);

    // 0x57CD80 | ?FloatVal@MiniParser@@QAEMXZ
    f32 FloatVal();

    // 0x57C810 | ?GetCh@MiniParser@@QAEHXZ
    i32 GetCh();

    // 0x57C880 | ?Indent@MiniParser@@QAEXH@Z
    void Indent(i32 amount);

    // 0x57CD40 | ?Int64Val@MiniParser@@QAE_JXZ
    i64 Int64Val();

    // 0x57CD00 | ?IntVal@MiniParser@@QAEHXZ
    i32 IntVal();

    // 0x57C8A0 | ?Match@MiniParser@@QAEXH@Z
    void Match(i32 expected);

    // 0x57CB00 | ?NextToken@MiniParser@@QAEHXZ
    i32 NextToken();

    // 0x57CA80 | ?PlaceLabel@MiniParser@@QAEXPAX@Z
    void PlaceLabel(void* ptr);

    // 0x57CAA0 | ?PlaceLabelRef@MiniParser@@QAEXPAX@Z
    void PlaceLabelRef(void* ptr);

    // 0x57C6B0 | ?PrintString@MiniParser@@QAEXPADH@Z
    void PrintString(const char* str, i32 len);

    // 0x57C660 | ?Printf@MiniParser@@QAAXPBDZZ
    void Printf(char const* format, ...);

    // 0x57CAD0 | ?PutBack@MiniParser@@QAEXH@Z
    void PutBack(i32 token);

    // 0x57C830 | ?PutCh@MiniParser@@QAEXH@Z
    void PutCh(i32 value);

    // 0x57CAC0 | ?ResolveLabel@MiniParser@@QAEPAXPADPAPAX@Z | unused
    void* ResolveLabel(char* arg1, void** arg2);

    const char* GetBuffer() const
    {
        return buffer_;
    }

    i32 GetErrorCount()
    {
        return error_count_;
    }

    // 0x57C8E0 | ?TokenName@MiniParser@@SAPADH@Z
    static const char* TokenName(i32 token);

private:
    void PutString(const char* str);

    char buffer_[256] {};
    i32 error_count_ {0};
    CString name_ {};
    i32 current_char_ {' '};
    i32 indentation_ {0};
    i32 current_line_ {1};
    i32 put_back_ {0};
};

check_size(MiniParser, 0x11C);
