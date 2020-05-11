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
    data7:metaclass

    0x577AA0 | public: __thiscall MetaClass::MetaClass(char *,unsigned int,void * (__cdecl*)(int),void (__cdecl*)(void *,int),void (__cdecl*)(void),class MetaClass *) | ??0MetaClass@@QAE@PADIP6APAXH@ZP6AXPAXH@ZP6AXXZPAV0@@Z
    0x577B20 | public: __thiscall MetaClass::~MetaClass(void) | ??1MetaClass@@QAE@XZ
    0x577B80 | public: static void __cdecl MetaClass::UndeclareAll(void) | ?UndeclareAll@MetaClass@@SAXXZ
    0x577BB0 | public: int __thiscall MetaClass::IsSubclassOf(class MetaClass *) | ?IsSubclassOf@MetaClass@@QAEHPAV1@@Z
    0x577BE0 | public: static class MetaClass * __cdecl MetaClass::FindByName(char *,class MetaClass *) | ?FindByName@MetaClass@@SAPAV1@PADPAV1@@Z
    0x577C50 | void __cdecl __BadSafeCall(char *,class Base *) | ?__BadSafeCall@@YAXPADPAVBase@@@Z
    0x577C70 | public: void __thiscall MetaClass::InitFields(void) | ?InitFields@MetaClass@@QAEXXZ
    0x577C90 | public: void __thiscall MetaClass::Save(class MiniParser *,void *) | ?Save@MetaClass@@QAEXPAVMiniParser@@PAX@Z
    0x577DE0 | public: void __thiscall MetaClass::SkipBlock(class MiniParser *) | ?SkipBlock@MetaClass@@QAEXPAVMiniParser@@@Z
    0x577E90 | public: void __thiscall MetaClass::Load(class MiniParser *,void *) | ?Load@MetaClass@@QAEXPAVMiniParser@@PAX@Z
    0x578000 | public: static void __cdecl MetaClass::DeclareNamedTypedField(char *,unsigned int,struct MetaType *) | ?DeclareNamedTypedField@MetaClass@@SAXPADIPAUMetaType@@@Z
    0x661EF8 | int NoDefault | ?NoDefault@@3HA
    0x90AA20 | public: static int MetaClass::NextSerial | ?NextSerial@MetaClass@@2HA
    0x90AA28 | public: static class MetaClass * * MetaClass::ClassIndex | ?ClassIndex@MetaClass@@2PAPAV1@A
    0x90AE28 | public: static class MetaClass * MetaClass::Current | ?Current@MetaClass@@2PAV1@A
    0x90AE2C | public: static struct MetaField * * MetaClass::ppField | ?ppField@MetaClass@@2PAPAUMetaField@@A
    0x90AE30 | public: static class MetaClass MetaClass::RootMetaClass | ?RootMetaClass@MetaClass@@2V1@A
*/

struct MetaType;

struct MetaField
{
    MetaField* Next {nullptr};
    const char* Name {nullptr};
    u32 Offset {0};
    MetaType* Type {nullptr};
};

check_size(MetaField, 0x10);

struct StaticMetaField
{
    const char* Name {nullptr};
    usize Offset {0};
    const MetaType* (*Getter)() {nullptr};
};

constexpr usize MAX_CLASSES = 512;

class MetaClass
{
public:
    // 0x577AA0 | ??0MetaClass@@QAE@PADIP6APAXH@ZP6AXPAXH@ZP6AXXZPAV0@@Z
    MetaClass(const char* name, u32 size, void* (*allocate)(i32), void (*free)(void*, i32), void (*declare)(void),
        class MetaClass* parent);

    // 0x577B20 | ??1MetaClass@@QAE@XZ
    ~MetaClass();

    // 0x577C70 | ?InitFields@MetaClass@@QAEXXZ
    void InitFields();

    // 0x577BB0 | ?IsSubclassOf@MetaClass@@QAEHPAV1@@Z
    i32 IsSubclassOf(class MetaClass* arg1);

    // 0x577E90 | ?Load@MetaClass@@QAEXPAVMiniParser@@PAX@Z
    void Load(class MiniParser* arg1, void* arg2);

    // 0x577C90 | ?Save@MetaClass@@QAEXPAVMiniParser@@PAX@Z
    void Save(class MiniParser* arg1, void* arg2);

    // 0x577DE0 | ?SkipBlock@MetaClass@@QAEXPAVMiniParser@@@Z
    void SkipBlock(class MiniParser* arg1);

    const char* GetName() const
    {
        return name_;
    }

    static void FixupClasses();

    // 0x578000 | ?DeclareNamedTypedField@MetaClass@@SAXPADIPAUMetaType@@@Z
    static void DeclareNamedTypedField(const char* name, u32 offset, struct MetaType* type);

    static void ARTS_FASTCALL DeclareStaticFields(const std::initializer_list<const StaticMetaField>& fields);

    // 0x577BE0 | ?FindByName@MetaClass@@SAPAV1@PADPAV1@@Z
    static class MetaClass* FindByName(char* arg1, class MetaClass* arg2);

    // 0x577B80 | ?UndeclareAll@MetaClass@@SAXXZ
    static void UndeclareAll();

    // 0x90AA28 | ?ClassIndex@MetaClass@@2PAPAV1@A
    static class MetaClass* ClassIndex[MAX_CLASSES];

    // 0x90AE28 | ?Current@MetaClass@@2PAV1@A
    static inline extern_var(0x90AE28, class MetaClass*, Current);

    // 0x90AA20 | ?NextSerial@MetaClass@@2HA
    static i32 NextSerial;

    // 0x90AE30 | ?RootMetaClass@MetaClass@@2V1@A
    static class MetaClass RootMetaClass;

    // 0x90AE2C | ?ppField@MetaClass@@2PAPAUMetaField@@A
    static inline extern_var(0x90AE2C, struct MetaField**, ppField);

private:
    const char* name_ {nullptr};
    u32 size_ {0};
    void* (*allocate_)(i32) {nullptr};
    void (*free_)(void*, i32) {nullptr};
    void (*declare_)() {nullptr};
    MetaClass* parent_ {nullptr};

    MetaClass* children_ {nullptr};
    MetaClass* next_child_ {nullptr};
    MetaField* fields_ {nullptr};

    i32 index_ {0};
};

check_size(MetaClass, 0x28);

// 0x577C50 | ?__BadSafeCall@@YAXPADPAVBase@@@Z
void __BadSafeCall(char* arg1, class Base* arg2);

// 0x661EF8 | ?NoDefault@@3HA
inline extern_var(0x661EF8, i32, NoDefault);
