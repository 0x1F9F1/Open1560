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

struct MetaType;
struct MetaField;
class MiniParser;

constexpr usize MAX_CLASSES = 512;

class MetaClass
{
public:
    // ??0MetaClass@@QAE@PADIP6APAXH@ZP6AXPAXH@ZP6AXXZPAV0@@Z
    MetaClass(const char* name, usize size, void* (*allocate)(isize), void (*free)(void*, isize),
        void (*declare)(void), MetaClass* parent);

    // ??1MetaClass@@QAE@XZ
    ARTS_EXPORT ~MetaClass();

    // ?InitFields@MetaClass@@QAEXXZ
    void InitFields();

    // ?IsSubclassOf@MetaClass@@QAEHPAV1@@Z
    b32 IsSubclassOf(MetaClass* parent);

    // ?Load@MetaClass@@QAEXPAVMiniParser@@PAX@Z
    void Load(MiniParser* parser, void* ptr);

    // ?Save@MetaClass@@QAEXPAVMiniParser@@PAX@Z
    void Save(MiniParser* parser, void* ptr);

    // ?SkipBlock@MetaClass@@QAEXPAVMiniParser@@@Z
    void SkipBlock(MiniParser* parser);

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
    static void DeclareNamedTypedField(const char* name, usize offset, MetaType* type);

    // ?FindByName@MetaClass@@SAPAV1@PADPAV1@@Z
    static MetaClass* FindByName(const char* name, MetaClass* root);

    // ?UndeclareAll@MetaClass@@SAXXZ
    static void UndeclareAll();

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
void __BadSafeCall(const char* name, Base* ptr);

// ?NoDefault@@3HA
ARTS_IMPORT extern i32 NoDefault;
