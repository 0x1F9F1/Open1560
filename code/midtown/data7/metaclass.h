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
struct MetaField;
class MiniParser;

constexpr usize MAX_CLASSES = 512;

class MetaClass
{
public:
    // ??0MetaClass@@QAE@PADIP6APAXH@ZP6AXPAXH@ZP6AXXZPAV0@@Z
    ARTS_EXPORT MetaClass(const char* name, usize size, void* (*allocate)(isize), void (*free)(void*, isize),
        void (*declare)(void), MetaClass* parent);

    // ??1MetaClass@@QAE@XZ
    ARTS_EXPORT ~MetaClass();

    // ?InitFields@MetaClass@@QAEXXZ
    ARTS_EXPORT void InitFields();

    // ?IsSubclassOf@MetaClass@@QAEHPAV1@@Z
    ARTS_EXPORT b32 IsSubclassOf(MetaClass* parent);

    // ?Load@MetaClass@@QAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Load(MiniParser* parser, void* ptr);

    // ?Save@MetaClass@@QAEXPAVMiniParser@@PAX@Z
    ARTS_EXPORT void Save(MiniParser* parser, void* ptr);

    // ?SkipBlock@MetaClass@@QAEXPAVMiniParser@@@Z
    ARTS_EXPORT void SkipBlock(MiniParser* parser);

    const char* GetName() const
    {
        return name_;
    }

    usize GetSize() const
    {
        return size_;
    }

    void* Allocate(isize count)
    {
        return allocate_ ? allocate_(count) : nullptr;
    }

    void Free(void* ptr, isize count)
    {
        free_(ptr, count);
    }

    MetaClass* GetParent() const
    {
        return parent_;
    }

    void DeclareFields()
    {
        if (declare_)
            declare_();
    }

    static void FixupClasses();

    // ?DeclareNamedTypedField@MetaClass@@SAXPADIPAUMetaType@@@Z
    ARTS_EXPORT static void DeclareNamedTypedField(const char* name, u32 offset, MetaType* type);

    // ?FindByName@MetaClass@@SAPAV1@PADPAV1@@Z
    ARTS_EXPORT static MetaClass* FindByName(const char* name, MetaClass* root);

    // ?UndeclareAll@MetaClass@@SAXXZ
    ARTS_EXPORT static void UndeclareAll();

    // ?ClassIndex@MetaClass@@2PAPAV1@A
    static MetaClass* ClassIndex[MAX_CLASSES];

    // ?Current@MetaClass@@2PAV1@A
    static MetaClass* Current;

    // ?NextSerial@MetaClass@@2HA
    static i32 NextSerial;

    // ?RootMetaClass@MetaClass@@2V1@A
    static MetaClass RootMetaClass;

    // ?ppField@MetaClass@@2PAPAUMetaField@@A
    static MetaField** ppField;

private:
    const char* name_ {};
    usize size_ {};
    void* (*allocate_)(isize) {};
    void (*free_)(void*, isize) {};
    void (*declare_)() {};
    MetaClass* parent_ {};

    MetaClass* children_ {};
    MetaClass* next_child_ {};
    MetaField* fields_ {};

    i32 index_ {-1};

    void Register();
    void Unregister();
    void FreeFields();
};

check_size(MetaClass, 0x28);

// ?__BadSafeCall@@YAXPADPAVBase@@@Z | unused
ARTS_EXPORT void __BadSafeCall(const char* name, Base* ptr);

// ?NoDefault@@3HA
ARTS_IMPORT extern i32 NoDefault;
