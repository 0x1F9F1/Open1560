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
    data7:str

    0x5794E0 | public: __thiscall string::string(void) | ??0string@@QAE@XZ
    0x579510 | public: class string __thiscall string::operator+(char const *) const | ??Hstring@@QBE?AV0@PBD@Z
    0x579640 | class string __cdecl operator+(char const *,class string const &) | ??H@YA?AVstring@@PBDABV0@@Z
    0x579770 | public: void __thiscall string::operator+=(char const *) | ??Ystring@@QAEXPBD@Z
    0x579860 | public: void __thiscall string::operator+=(char) | ??Ystring@@QAEXD@Z
    0x579900 | public: class string __thiscall string::operator-(char const *) const | ??Gstring@@QBE?AV0@PBD@Z
    0x579A60 | public: void __thiscall string::operator-=(char const *) | ??Zstring@@QAEXPBD@Z
    0x579B10 | public: void __thiscall string::MinusEqual(char) | ?MinusEqual@string@@QAEXD@Z
    0x579C60 | public: int __thiscall string::Contains(class string &) const | ?Contains@string@@QBEHAAV1@@Z
    0x579D00 | public: void __thiscall string::SaveName(class string const &,int,class string const &,class string const &) | ?SaveName@string@@QAEXABV1@H00@Z
    0x579ED0 | public: int __thiscall string::FindFile(class string const &,int,class string const &,class string const &) | ?FindFile@string@@QAEHABV1@H00@Z
    0x57A260 | public: int __thiscall string::FileExists(void) const | ?FileExists@string@@QBEHXZ
    0x57A290 | public: void __thiscall string::DirFileExt(class string &,class string &,class string &) const | ?DirFileExt@string@@QBEXAAV1@00@Z
    0x57A4A0 | public: int __thiscall string::CommaFile(void) const | ?CommaFile@string@@QBEHXZ
    0x57A6A0 | public: class string __thiscall string::FileName(void) const | ?FileName@string@@QBE?AV1@XZ
    0x57A800 | public: class string __thiscall string::Extension(void) const | ?Extension@string@@QBE?AV1@XZ
    0x57A950 | public: void __thiscall string::ChangeExtension(class string const &) | ?ChangeExtension@string@@QAEXABV1@@Z
    0x57AAD0 | public: void __thiscall string::RemoveExtension(void) | ?RemoveExtension@string@@QAEXXZ
    0x57AB10 | public: void __thiscall string::ExpandEnvs(void) | ?ExpandEnvs@string@@QAEXXZ
    0x57ACB0 | public: class string __thiscall string::SubString(int) const | ?SubString@string@@QBE?AV1@H@Z
    0x57ADC0 | public: int __thiscall string::NumSubStrings(void) const | ?NumSubStrings@string@@QBEHXZ
    0x57AE10 | public: int __thiscall string::IsNumeric(void) const | ?IsNumeric@string@@QBEHXZ
    0x57AE60 | public: void __thiscall StringArray::Init(int) | ?Init@StringArray@@QAEXH@Z
    0x57AED0 | public: void __thiscall StringArray::Delete(void) | ?Delete@StringArray@@QAEXXZ
    0x57AF30 | private: void __thiscall StringArray::NewTable(int) | ?NewTable@StringArray@@AAEXH@Z
    0x57AFA0 | public: class string & __thiscall StringArray::operator[](int) | ??AStringArray@@QAEAAVstring@@H@Z
    0x57B050 | public: void __thiscall StringArray::operator=(class StringArray &) | ??4StringArray@@QAEXAAV0@@Z
    0x57B1F0 | public: void __thiscall StringArray::BlockCopy(class StringArray &) | ?BlockCopy@StringArray@@QAEXAAV1@@Z
    0x57B320 | public: void __thiscall string::operator=(char const *) | ??4string@@QAEXPBD@Z
    0x57B380 | public: class string __thiscall string::operator+(class string const &) const | ??Hstring@@QBE?AV0@ABV0@@Z
    0x57B3B0 | public: void * __thiscall string::`vector deleting destructor'(unsigned int) | ??_Estring@@QAEPAXI@Z
    0x90B208 | char * ProjPath | ?ProjPath@@3PADA
    0x90B288 | char * ImageExts | ?ImageExts@@3PADA
    0x90B3D0 | char * ExecPath | ?ExecPath@@3PADA
*/

class string
{
public:
    // 0x5794E0 | ??0string@@QAE@XZ
    string();

    // 0x4A4BA0 | ??0string@@QAE@PBD@Z
    string(char const* arg1);

    // 0x49A730 | ??0string@@QAE@ABV0@@Z
    string(class string const& arg1);

    // 0x40E7E0 | ??1string@@QAE@XZ
    // 0x57B3B0 | ??_Estring@@QAEPAXI@Z
    ~string();

    // 0x57B320 | ??4string@@QAEXPBD@Z
    void operator=(char const* arg1);

    // 0x579510 | ??Hstring@@QBE?AV0@PBD@Z
    class string operator+(char const* arg1);

    // 0x57B380 | ??Hstring@@QBE?AV0@ABV0@@Z
    class string operator+(class string const& arg1);

    // 0x579860 | ??Ystring@@QAEXD@Z
    void operator+=(char arg1);

    // 0x579770 | ??Ystring@@QAEXPBD@Z
    void operator+=(char const* arg1);

    // 0x579900 | ??Gstring@@QBE?AV0@PBD@Z
    class string operator-(char const* arg1);

    // 0x579A60 | ??Zstring@@QAEXPBD@Z
    void operator-=(char const* arg1);

    // 0x57A950 | ?ChangeExtension@string@@QAEXABV1@@Z
    void ChangeExtension(class string const& arg1);

    // 0x57A4A0 | ?CommaFile@string@@QBEHXZ
    i32 CommaFile();

    // 0x579C60 | ?Contains@string@@QBEHAAV1@@Z
    i32 Contains(class string& arg1);

    // 0x57A290 | ?DirFileExt@string@@QBEXAAV1@00@Z
    void DirFileExt(class string& arg1, class string& arg2, class string& arg3);

    // 0x57AB10 | ?ExpandEnvs@string@@QAEXXZ
    void ExpandEnvs();

    // 0x57A800 | ?Extension@string@@QBE?AV1@XZ
    class string Extension();

    // 0x57A260 | ?FileExists@string@@QBEHXZ
    i32 FileExists();

    // 0x57A6A0 | ?FileName@string@@QBE?AV1@XZ
    class string FileName();

    // 0x579ED0 | ?FindFile@string@@QAEHABV1@H00@Z
    i32 FindFile(class string const& arg1, i32 arg2, class string const& arg3, class string const& arg4);

    // 0x49A6F0 | ?Init@string@@QAEXH@Z
    void Init(i32 arg1);

    // 0x57AE10 | ?IsNumeric@string@@QBEHXZ
    i32 IsNumeric();

    // 0x579B10 | ?MinusEqual@string@@QAEXD@Z
    void MinusEqual(char arg1);

    // 0x57ADC0 | ?NumSubStrings@string@@QBEHXZ
    i32 NumSubStrings();

    // 0x57AAD0 | ?RemoveExtension@string@@QAEXXZ
    void RemoveExtension();

    // 0x579D00 | ?SaveName@string@@QAEXABV1@H00@Z
    void SaveName(class string const& arg1, i32 arg2, class string const& arg3, class string const& arg4);

    // 0x57ACB0 | ?SubString@string@@QBE?AV1@H@Z
    class string SubString(i32 arg1);
};

check_size(string, 0x8);

// 0x579640 | ??H@YA?AVstring@@PBDABV0@@Z
class string operator+(char const* arg1, class string const& arg2);

// 0x90B3D0 | ?ExecPath@@3PADA
inline extern_var(0x50B3D0_Offset, char*, ExecPath);

// 0x90B288 | ?ImageExts@@3PADA
inline extern_var(0x50B288_Offset, char*, ImageExts);

// 0x90B208 | ?ProjPath@@3PADA
inline extern_var(0x50B208_Offset, char*, ProjPath);

class StringArray
{
public:
    // 0x57B050 | ??4StringArray@@QAEXAAV0@@Z
    void operator=(class StringArray& arg1);

    // 0x57AFA0 | ??AStringArray@@QAEAAVstring@@H@Z
    class string& operator[](i32 arg1);

    // 0x57B1F0 | ?BlockCopy@StringArray@@QAEXAAV1@@Z
    void BlockCopy(class StringArray& arg1);

    // 0x57AED0 | ?Delete@StringArray@@QAEXXZ
    void Delete();

    // 0x57AE60 | ?Init@StringArray@@QAEXH@Z
    void Init(i32 arg1);

private:
    // 0x57AF30 | ?NewTable@StringArray@@AAEXH@Z
    void NewTable(i32 arg1);
};

check_size(StringArray, 0x0);
