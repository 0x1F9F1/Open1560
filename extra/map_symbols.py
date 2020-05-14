import re
import ctypes
import copy
import os
from collections import defaultdict, OrderedDict

from binaryninja.binaryview import *
from binaryninja.architecture import *
from binaryninja.demangle import *
from binaryninja.enums import *
from binaryninja.types import *

IDC_NAME_REGEX = re.compile(r'set_name\t\(0X([0-9A-F]+),\t"(.+)"\);')

def parse_idc_symbols(lines):
    results = { }

    for line in lines:
        result = IDC_NAME_REGEX.match(line.strip())

        if result is None:
            continue

        addr = result[1]
        name = result[2]

        results[name] = int(addr, 16)

    return results

MAP_REGEX = re.compile(r'[0-9a-fA-F]+:[0-9a-fA-F]+\s+(\S+)\s+([0-9a-fA-F]+).* (\S+)')

IGNORED_LIB_PREFIXES = [
    'LIBCMTD',
    'LIBCD',
    'dinput',
    'dxguid',
    'uuid',
    '__imp__',
    '<common>'
]

def parse_map_symbols(lines, addrs, ignored):
    results = []

    for line in lines:
        result = MAP_REGEX.match(line.strip())

        if result is None:
            continue

        sym_name = result[1]

        if ignored is not None:
            if sym_name in ignored:
                continue

        sym_addr = result[2]
        lib_name = result[3]

        sym_addr = int(sym_addr, 16)

        if sym_name not in ['__purecall', '??_H@YGXPAXIHP6EX0@Z@Z', '??_L@YGXPAXIHP6EX0@Z1@Z', '??_M@YGXPAXIHP6EX0@Z@Z']:
            if any(prefix for prefix in IGNORED_LIB_PREFIXES if lib_name.startswith(prefix)):
                continue

            if lib_name.endswith('.dll') \
            or sym_name.startswith('__') \
            or sym_name.startswith('??_C@') \
            or sym_name.startswith('_$E'):
                continue

        if lib_name.endswith('.obj'):
            lib_name = lib_name[:-4]

        if addrs is not None:
            sym_addr = addrs[sym_name] if sym_name in addrs else None

        symbol = MapSymbol(sym_name, sym_addr, lib_name)

        results.append(symbol)

    return results

UnDecorateSymbolName = ctypes.windll.dbghelp.UnDecorateSymbolName
UnDecorateSymbolName.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_uint, ctypes.c_uint]

def undecorate_symbol(symbol):
    result = ctypes.create_string_buffer(1024)

    if not UnDecorateSymbolName(symbol.encode('ascii'), result, ctypes.sizeof(result), 0):
        return None

    result = result.value.decode('ascii')

    if symbol == result:
        return None

    result = result.replace(')const ', ') const')

    return result

class MapSymbol:
    def __init__(self, raw_name, address, library):
        self.raw_name = raw_name
        self.address = address
        self.library = library

        self.undec_name = undecorate_symbol(self.raw_name)
        self.visibility = None
        self.type = None
        self.parts = None
        self.static = False
        self.virtual = False
        self.member_type = None
        self.override = False
        self.vftable_index = None

    @property
    def path(self):
        return '::'.join(self.parts[:-1])

    @property
    def name(self):
        return self.parts[-1]

    @property
    def full_name(self):
        return '::'.join(self.parts)

    @property
    def is_member(self):
        return self.visibility is not None

    @property
    def is_vftable(self):
        return self.name.startswith('`vftable\'')

    @property
    def is_thunk(self):
        if self.undec_name is None:
            return None
        return '[thunk]:' in self.undec_name

    @property
    def is_virtual(self):
        return self.vftable_index is not None

    @property
    def parent_vftable(self):
        if self.undec_name is None:
            return None
        hier_idx = self.undec_name.find('\'{for `')
        return self.undec_name[hier_idx + 7:-2] if hier_idx != -1 else None

    @staticmethod
    def PURECALL():
        symbol = MapSymbol('__purecall', 0, '')
        symbol.process(None)
        return symbol

    def __repr__(self):
        return '<symbol \'{}\' @ 0x{:X}>'.format(self.full_name, self.address)

    def process(self, arch):
        if self.undec_name is not None:
            if 'public: ' in self.undec_name:
                self.visibility = 'public'

            if 'protected: ' in self.undec_name:
                self.visibility = 'protected'

            if 'private: ' in self.undec_name:
                self.visibility = 'private'

            self.static = 'static ' in self.undec_name
            self.virtual = 'virtual ' in self.undec_name

            sym_type, sym_parts = demangle_ms(arch, self.raw_name)

            if ('`vftable\'' in self.undec_name) or ('`vbtable\'' in self.undec_name):
                sym_type = Type.void()
            elif sym_type is None:
                sym_type = Type.void()

            if isinstance(sym_parts, str):
                sym_parts = [sym_parts]
        else:
            sym_type = Type.void()
            sym_parts = [self.raw_name]

        self.type = sym_type
        self.parts = sym_parts

        if (self.type is not None) and (self.type.type_class == TypeClass.FunctionTypeClass):
            self.fixup_func_type(arch)

    def fixup_func_type(self, arch):
        return_type = self.type.return_value
        param_types = [v for v in self.type.parameters if v.type.type_class != TypeClass.VoidTypeClass]

        for i in range(len(param_types)):
            param_types[i].name = 'arg{}'.format(i + 1)

        is_variadic = self.type.has_variable_arguments

        if ' __cdecl ' in self.undec_name:
            cc_name = 'cdecl'
        elif ' __stdcall ' in self.undec_name:
            cc_name = 'stdcall'
        elif ' __thiscall ' in self.undec_name:
            cc_name = 'thiscall'
        elif ' __fastcall ' in self.undec_name:
            cc_name = 'fastcall'
        else:
            assert False, (self.undec_name, self.raw_name)

        if self.is_member:
            assert len(self.parts) >= 2, (self, self.undec_name, self.raw_name)

            if self.parts[-1] == self.parts[-2]:
                self.member_type = 'ctor'
            elif self.parts[-1] == ('~' + self.parts[-2]):
                self.member_type = 'dtor'
            elif self.parts[-1] in ['`vector deleting destructor\'', '`scalar deleting destructor\'']:
                self.member_type = 'dtor'

            if self.member_type == 'dtor':
                param_types = []

        self.type = Type.function(return_type, param_types, arch.calling_conventions[cc_name], is_variadic)

type_class_to_str = {
    NamedTypeReferenceClass.ClassNamedTypeClass: 'class',
    NamedTypeReferenceClass.StructNamedTypeClass: 'struct',
    NamedTypeReferenceClass.EnumNamedTypeClass: 'enum',
    NamedTypeReferenceClass.UnionNamedTypeClass: 'union',
}

def collect_symbol_type_classes(symbols, class_hier):
    pending = [symbol.type for symbol in symbols if symbol.type is not None]

    type_classes = dict()

    while pending:
        current = pending.pop()
        type_class = current.type_class

        if type_class == TypeClass.FunctionTypeClass:
            pending.append(current.return_value)
            pending.extend((v.type for v in current.parameters))
        elif type_class == TypeClass.PointerTypeClass:
            pending.append(current.target)
        elif type_class == TypeClass.NamedTypeReferenceClass:
            named_type = current.named_type_reference
            named_type_class = named_type.type_class

            if named_type_class in type_class_to_str:
                type_classes[named_type.name] = type_class_to_str[named_type_class]

    changed = True
    while changed:
        changed = False
        for name, hiers in class_hier.items():
            if name in type_classes:
                continue
            if len(hiers) != 1:
                continue
            if hiers[0] not in type_classes:
                continue
            type_classes[name] = type_classes[hiers[0]]
            changed = True

    for symbol in symbols:
        if symbol.is_member or symbol.is_vftable:
            symbol_path = symbol.path
            if symbol_path not in type_classes:
                type_classes[symbol_path] = 'struct'

    # TODO: Handle namespaces

    for symbol in symbols:
        assert symbol.path in type_classes, symbol

    return type_classes

def collect_vftables(view, symbols, class_hier):
    vftable_symbols = [symbol for symbol in symbols.values() if symbol.is_vftable]
    vftables = dict()
    reader = BinaryReader(view)

    for vftable in vftable_symbols:
        reader.seek(vftable.address)
        funcs = []

        for _ in range(128):
            if funcs and (reader.offset in symbols or view.get_code_refs(reader.offset) or view.get_data_refs(reader.offset)):
                break
            vfunc = reader.read32()
            if not view.is_offset_executable(vfunc):
                break

            assert vfunc in symbols, (vfunc)

            func_symbol = symbols[vfunc]
            if func_symbol.is_member:
                assert func_symbol.virtual
                class_hier[vftable.path].add(func_symbol.path)
            else:
                assert func_symbol.raw_name == '__purecall'

            funcs.append(func_symbol)

        if not 0 < len(funcs) < 128:
            print('Invalid vftable: {} @ 0x{:X}'.format(vftable.undec_name, vftable.address))
            continue

        hier_idx = vftable.undec_name.find('\'{for `')

        if hier_idx != -1:
            class_hier[vftable.path].add(vftable.undec_name[hier_idx + 7:-2])

        vftables[vftable.address] = funcs

    return vftables

def collect_ctor_dtor_hierarchy(view, symbols, class_hier):
    for symbol in symbols.values():
        if symbol.member_type not in ['ctor', 'dtor']:
            continue

        func = view.get_function_at(symbol.address)

        if func is None:
            print('Invalid ctor/dtor {} @ 0x{:X}'.format(symbol.undec_name, symbol.address))
            continue

        parameters = func.parameter_vars

        if (not parameters) or (parameters[0].storage != 51): # ecx
            continue

        hlil = func.hlil

        for insn in hlil.instructions:
            if insn.operation in [HighLevelILOperation.HLIL_ASSIGN, HighLevelILOperation.HLIL_VAR_INIT]:
                insn = insn.src

            if insn.operation in [HighLevelILOperation.HLIL_CALL, HighLevelILOperation.HLIL_TAILCALL]:
                if insn.dest.operation not in [HighLevelILOperation.HLIL_CONST, HighLevelILOperation.HLIL_CONST_PTR]:
                    continue

                dest_addr = insn.dest.constant
                if dest_addr not in symbols:
                    continue

                dest_symbol = symbols[dest_addr]
                if dest_symbol.member_type != symbol.member_type:
                    continue

                params = insn.params
                if not params:
                    continue
                if params[0].operation != HighLevelILOperation.HLIL_VAR:
                    continue
                if params[0].var != parameters[0]:
                    continue

                class_hier[symbol.path].add(dest_symbol.path)
            elif insn.operation == HighLevelILOperation.HLIL_ASSIGN:
                if insn.dest.operation != HighLevelILOperation.HLIL_DEREF:
                    continue
                if insn.dest.src.operation != HighLevelILOperation.HLIL_VAR:
                    continue
                if insn.dest.src.var != parameters[0]:
                    continue
                if insn.src.operation not in [HighLevelILOperation.HLIL_CONST, HighLevelILOperation.HLIL_CONST_PTR]:
                    continue

                vftable_addr = insn.src.constant
                if vftable_addr not in symbols:
                    continue

                vftable_symbol = symbols[vftable_addr]
                if not vftable_symbol.is_vftable:
                    continue

                class_hier[symbol.path].add(vftable_symbol.path)

def collect_class_sizes(view, symbols):
    pending_functions = set()

    # TODO: Handle inlined constructors with vftables

    for symbol in symbols.values():
        if (symbol.member_type == 'ctor') \
        or (symbol.raw_name in ['??_H@YGXPAXIHP6EX0@Z@Z', '??_L@YGXPAXIHP6EX0@Z1@Z', '??_M@YGXPAXIHP6EX0@Z@Z']):
            for ref in view.get_code_refs(symbol.address):
                if ref.function is not None:
                    pending_functions.add(ref.function)

    def get_alloc_size(hlil, var):
        defin = hlil.get_ssa_var_definition(var)

        if defin is None:
            return None

        if defin.operation == HighLevelILOperation.HLIL_VAR_SSA:
            defin = defin.instr

        if defin.operation not in [HighLevelILOperation.HLIL_VAR_INIT_SSA, HighLevelILOperation.HLIL_ASSIGN]:
            return None

        defin = defin.src

        if defin.operation != HighLevelILOperation.HLIL_CALL_SSA:
            return None

        if defin.dest.operation not in [HighLevelILOperation.HLIL_CONST, HighLevelILOperation.HLIL_CONST_PTR]:
            return None

        alloc_addr = defin.dest.constant
        if alloc_addr not in symbols:
            return None

        if symbols[alloc_addr].full_name != 'operator new':
            return None

        if len(defin.params) != 1:
            return None

        if defin.params[0].operation != HighLevelILOperation.HLIL_CONST:
            return None

        return defin.params[0].constant

    class_sizes = dict()
    ignored_sizes = set()

    def add_class_size(name, size):
        if size is not None:
            if name not in class_sizes:
                class_sizes[name] = size
            elif class_sizes[name] != size:
                ignored_sizes.add(name)

    for func in pending_functions:
        hlil = func.hlil.ssa_form

        for insn in hlil.instructions:
            if insn.operation in [HighLevelILOperation.HLIL_VAR_INIT_SSA, HighLevelILOperation.HLIL_ASSIGN]:
                insn = insn.src

            if insn.operation != HighLevelILOperation.HLIL_CALL_SSA:
                continue

            if insn.dest.operation not in [HighLevelILOperation.HLIL_CONST, HighLevelILOperation.HLIL_CONST_PTR]:
                continue

            dest_addr = insn.dest.constant
            if dest_addr not in symbols:
                continue

            dest_symbol = symbols[dest_addr]

            if dest_symbol.member_type == 'ctor':
                params = insn.params

                if (len(params) == 0) or (params[0].operation != HighLevelILOperation.HLIL_VAR_SSA):
                    continue

                add_class_size(dest_symbol.path, get_alloc_size(hlil, params[0].var))

            elif dest_symbol.raw_name in ['??_H@YGXPAXIHP6EX0@Z@Z', '??_L@YGXPAXIHP6EX0@Z1@Z', '??_M@YGXPAXIHP6EX0@Z@Z']:
                params = insn.params

                if (len(params) != 4) or (params[1].operation != HighLevelILOperation.HLIL_CONST):
                    continue

                iter_size = params[1].constant

                if params[3].operation not in [HighLevelILOperation.HLIL_CONST, HighLevelILOperation.HLIL_CONST_PTR]:
                    continue

                cdtor_addr = params[3].constant

                if cdtor_addr not in symbols:
                    continue

                cdtor_symbol = symbols[cdtor_addr]

                if (dest_symbol.raw_name in ['??_H@YGXPAXIHP6EX0@Z@Z', '??_L@YGXPAXIHP6EX0@Z1@Z']) and (cdtor_symbol.member_type != 'ctor'):
                    continue
                if (dest_symbol.raw_name in ['??_M@YGXPAXIHP6EX0@Z@Z']) and (cdtor_symbol.member_type != 'dtor'):
                    continue

                add_class_size(cdtor_symbol.path, iter_size)

    for v in ignored_sizes:
        print('Skipped Class Size {}'.format(v))
        del class_sizes[v]

    return class_sizes

def compute_hierarchy(raw_hierarchy, extra, ignored):
    raw_hierarchy = dict((a, set(v for v in b if v not in ignored)) for a, b in raw_hierarchy.items())

    for a, b in extra.items():
        if a not in raw_hierarchy:
            raw_hierarchy[a] = set()

        raw_hierarchy[a].update(b)

        for c in b:
            if c not in raw_hierarchy:
                raw_hierarchy[c] = set()

    done = OrderedDict()
    pending = list(raw_hierarchy.keys())

    while pending:
        class_name = pending.pop()

        if class_name in done:
            continue

        if class_name not in raw_hierarchy:
            raw_hierarchy[class_name] = set()

        parents = raw_hierarchy[class_name]

        uniques = set(v for v in parents if (v != class_name) and (v not in done))

        if uniques:
            pending.append(class_name)
            pending.extend(list(uniques))
            continue

        uniques = set(v for v in parents if (v != class_name) and (v not in ignored))
        uniques.update(set(r for v in uniques for r in done[v]))

        done[class_name] = uniques

    for key, vvv in reversed(done.items()):
        new_parents = list(v for v in vvv if all(v not in done[q] for q in vvv))
        # assert len(new_parents) <= 1
        done[key] = new_parents

    return dict(done)

def backport_vftable_purecalls(raw_vftables, hiers, overrides):
    vftables = dict()

    # vftables[None] = None

    for symbol in symbols.values():
        if not symbol.is_vftable:
            continue

        if symbol.path not in vftables:
            vftables[symbol.path] = dict()

        parent = symbol.parent_vftable
        if parent is None:
            assert symbol.path in hiers, (symbol)
            parents = hiers[symbol.path]
            if parents:
                assert len(parents) == 1, (symbol, parents)
                parent = parents[0]

        if symbol.address not in raw_vftables:
            print('Invalid vftable: {} @ 0x{:X}'.format(symbol.undec_name, symbol.address))

        vftables[symbol.path][parent] = raw_vftables[symbol.address]

    for class_name, tables in overrides.items():
        if class_name not in vftables:
            vftables[class_name] = dict()

        for parent_name, func_count in tables.items():
            funcs = vftables[class_name].get(parent_name, [])

            if len(funcs) > func_count:
                funcs = funcs[:func_count]
            else:
                for _ in range(func_count - len(funcs)):
                    funcs.append(MapSymbol.PURECALL())

            vftables[class_name][parent_name] = funcs

    changed = True
    while changed:
        changed = False

        for class_name, tables in vftables.items():
            for parent in tables:
                if parent is None:
                    continue

                assert parent in vftables, ('Unknown vftable', class_name, parent)

                parent_tables = vftables[parent]
                if len(parent_tables) != 1:
                    continue

                table = tables[parent]
                parent_table = next(iter(parent_tables.values()))

                assert len(table) >= len(parent_table)

                for i in range(min(len(table), len(parent_table))):
                    if parent_table[i].name != '__purecall':
                        # if table[i].name != parent_table[i].name:
                        #     print(class_name, parent, table[i].name, parent_table[i].name)
                        continue
                    if table[i].name == '__purecall':
                        continue

                    new_symbol = copy.copy(table[i])
                    new_symbol.address = 0
                    new_symbol.undec_name = None
                    new_symbol.raw_name = '__purecall'
                    new_symbol.parts = parent.split('::') + new_symbol.parts[-1:]
                    parent_table[i] = new_symbol

                    changed = True

    return vftables

def group_stray_symbols(symbols):
    path_libs = defaultdict(lambda: defaultdict(lambda: 0))

    for symbol in symbols:
        if 'purevirt' not in symbol.library:
            path_libs[symbol.path][symbol.library] += 1

    path_libs = dict((k, max(v.items(), key = lambda x: x[1])[0]) for k, v in path_libs.items() if k)

    # Group Stray Symbols
    # for symbol in symbols:
    #     if symbol.path:
    #         symbol.library = path_libs[symbol.path]

    return path_libs

def fixup_vftable_symbols(grouped_symbols, vftables):
    for class_name, tables in vftables.items():
        if class_name not in path_libs:
            continue

        class_symbols = grouped_symbols[path_libs[class_name]][class_name]

        for table in tables.values():
            for i, entry in enumerate(table):
                if entry.raw_name != '__purecall':
                    continue

                real_entry = next((v for v in class_symbols if v.name == entry.name and v.type == entry.type), None)

                if real_entry is not None:
                    table[i] = real_entry

    for class_name, tables in vftables.items():
        for parent, table in tables.items():
            if parent is None:
                continue

            assert parent in vftables, ('Unknown vftable', class_name, parent)

            parent_tables = vftables[parent]

            if len(parent_tables) != 1:
                continue

            parent_table = next(iter(parent_tables.values()))

            assert len(table) >= len(parent_table)

            for i in range(len(parent_table)):
                if table[i].path != class_name:
                    continue

                if table[i].address == parent_table[i].address:
                    if (table[i].raw_name != '__purecall') or (parent_table[i].raw_name != '__purecall'):
                        continue

                table[i].override = True

    for class_name, tables in vftables.items():
        if not class_name in path_libs:
            print('Skipped ' + class_name)
            continue

        for parent_name, table in tables.items():
            for (i, func) in enumerate(table):
                if func.path == class_name:
                    func.vftable_index = (i, parent_name)

                if func.raw_name == '__purecall' and not func.override:
                    grouped_symbols[path_libs[class_name]][class_name].append(func)

def symbol_sort_order(symbol):
    # 1. public
    # 2. protected
    # 3. private

    '''
        public

        ...
        virts
        ...

        protected

        private
    '''

    # Priority
    # 1. Constructor
    # 2. Destructor
    # 3. Member Function
    # 4. Static Function
    # 5. Static Variable

    # Ensure correct overing of new virtual functions
    vftable_index = symbol.vftable_index if not symbol.override else None

    primary_order = 0

    if symbol.is_vftable:
        primary_order = -1
    elif (symbol.visibility == 'public') or (vftable_index is not None):
        primary_order = 0
    elif symbol.visibility == 'protected':
        primary_order = 1
    elif symbol.visibility == 'private':
        primary_order = 2

    if vftable_index is not None:
        secondary_order = 4
    elif symbol.member_type == 'ctor':
        secondary_order = 0
    elif symbol.member_type == 'dtor':
        secondary_order = 1
    elif symbol.name == 'operator=':
        secondary_order = 2
    elif symbol.name.startswith('operator'):
        secondary_order = 3
    else:
        secondary_order = 10

    visiblity_level = 0

    if symbol.visibility == 'public':
        visiblity_level = 0
    elif symbol.visibility == 'protected':
        visiblity_level = 1
    elif symbol.visibility == 'private':
        visiblity_level = 2

    assert symbol.name is not None, (symbol)

    if symbol.member_type == 'ctor':
        third_order = 1
    elif symbol.member_type == 'dtor':
        third_order = 2
    elif symbol.name == 'operator=':
        third_order = 3
    elif symbol.name.startswith('operator'):
        third_order = 4
    else:
        third_order = 10

    return (
        primary_order, # publics+virtuals -> protected -> private
        symbol.static, # non static -> static
        symbol.type.type_class != TypeClass.FunctionTypeClass, # functions -> non functions
        secondary_order,
        vftable_index or (),
        visiblity_level,
        third_order, # Ctor, Dtor, Virtual Functions, Regular functions
        symbol.name,
        len(symbol.type.parameters) if symbol.type.type_class == TypeClass.FunctionTypeClass else 0,
        str(symbol.type),
        symbol.address
    )

def replace_builtin_types(value):
    for a, b in [
        ('uint8_t', 'u8'),
        ('uint16_t', 'u16'),
        ('uint32_t', 'u32'),
        ('uint64_t', 'u64'),

        ('int8_t', 'i8'),
        ('int16_t', 'i16'),
        ('int32_t', 'i32'),
        ('int64_t', 'i64'),

        ('float', 'f32'),
        ('double', 'f64'),

        ('__cdecl', ''),

        # ('struct ', ''),
        # ('class ', ''),
        # ('union ', ''),

        # Needs to be done post-format
        # ('struct HWND__*', 'HWND'),
        # ('struct HINSTANCE__*', 'HINSTANCE'),
        # ('struct _iobuf', 'FILE'),
        # ('struct _GUID', 'struct GUID'),
    ]:
        value = re.sub('\\b' + a + '\\b', b, value)

    return value

def beautify_type(ty):
    return replace_builtin_types(
        str(ty).replace('public: ', '').replace('protected: ', '').replace('private: ', '').replace('static ', '')
    )

def choose_best_dtor(class_symbols):
    all_dtors = [v for v in class_symbols if v.member_type == 'dtor']

    all_dtors.sort(key = lambda x: (x.vftable_index is None, len(x.type.parameters), x.override))

    if any((x.override for x in all_dtors)):
        assert all_dtors[0].override

    return all_dtors

def format_address(address):
    return '0x{:X}'.format(value.address)
    # return '0x{:X}_Offset'.format(value.address - 0x400000)

print('Loading MAP')
# Load symbols from .map, but using addresses from the .idc
all_symbols = parse_map_symbols(open('TEST1560.MAP', 'r').readlines(), None, {
    '??BVector3@@QBE?AVVector2@@XZ',
    '??BVector2@@QBE?AVVector3@@XZ',
    '??BVector3@@QBE?AVVector4@@XZ',
    '?LodTable@?1??ComputeLod@aiPedestrianInstance@@UAEHMM@Z@4PAMA',
})

print('Loading BNDB')
view = BinaryViewType.get_view_of_file('test1560.bndb')

print('Processing Symbols')
for symbol in all_symbols:
    symbol.process(view.arch)

for sym in [
    MapSymbol("?TouchMemory@@YAXPAXH@Z", 0x402E70, "test"),
    MapSymbol("?exeDirFile@@YAPADPAD0@Z", 0x402EC0, "test"),
    MapSymbol("?GameCloseCallback@@YAXXZ", 0x402F20, "test"),
    MapSymbol("?IsModemDialin@@YA_NXZ", 0x409CD0, "mmgame:interface"),
    MapSymbol("?ZoneWatcher@@YGKPAX@Z", 0x409D50, "mmgame:interface"),
    MapSymbol("?randcall@@YAXXZ", 0x404390, "mmgame:gameman"),
    MapSymbol("?DoScan@@YAXPAX@Z", 0x4046D0, "mmgame:gameman"),
    MapSymbol("?StuckCB@@YAXPAVaiStuck@@@Z", 0x46B470, "mmai:aiStuck"),
    MapSymbol("?SplashCB@@YAXPAVmmSplash@@@Z", 0x481050, "mmcar:splash"),
    MapSymbol("?StuckCB@@YAXPAVmmStuck@@@Z", 0x47C4F0, "mmcar:stuck"),
    MapSymbol("?MatrixFromPoints@@YAXAAVMatrix34@@AAVVector3@@1M@Z", 0x493670, "mmcity:inst"),
    MapSymbol("?fix_sun@@YAXXZ", 0x48E1B0, "mmcity:cullcity"),
    MapSymbol("?fix_fill1@@YAXXZ", 0x48E220, "mmcity:cullcity"),
    MapSymbol("?fix_fill2@@YAXXZ", 0x48E290, "mmcity:cullcity"),
    MapSymbol("?parseFloat@@YAXAAM@Z", 0x48E300, "mmcity:cullcity"),
    MapSymbol("?parseVector3@@YAXAAVVector3@@@Z", 0x48E330, "mmcity:cullcity"),
    MapSymbol("?parseRGB@@YAXAAI@Z", 0x48E360, "mmcity:cullcity"),
    MapSymbol("?parseARGB@@YAXAAI@Z", 0x48E3D0, "mmcity:cullcity"),
    MapSymbol("?toggle_interlace@@YAXXZ", 0x4A9E70, "mmui:pu_graphics"),
    MapSymbol("?toggle_filter@@YAXXZ", 0x4A9E90, "mmui:pu_graphics"),
    MapSymbol("?fix_lighting_lame@@YAXXZ", 0x4A9EC0, "mmui:pu_graphics"),
    MapSymbol("?CalibrateWatcher@@YGKPAX@Z", 0x4A37A0, "mmui:control"),
    MapSymbol("?SetTexQualString@@YAXXZ", 0x49A050, "mmui:graphics"),
    MapSymbol("?HelpWatcher@@YGKPAX@Z", 0x4B1B30, "mmwidget:manager"),
    MapSymbol("?Matrix34__FromEulersXZY@@YAXAAVMatrix34@@ABVVector3@@@Z", 0x517090, "agiworld:bone"),
    MapSymbol("?cmpTex@@YAHPBX0@Z", 0x512080, "agiworld:texsheet"),
    MapSymbol("?mmxTriple@@YAXPAI0HPAEH@Z", 0x510EE0, "agiworld:meshlight"),
    MapSymbol("?agiInitCones@@YAXAAVMatrix34@@M@Z", 0x5116B0, "agiworld:meshlight"),
    MapSymbol("?FullClip@@YAHPAUCV@@0H@Z", 0x5061B0, "agiworld:meshrend"),
    MapSymbol("?ClipNX@@YAHPAUCV@@0H@Z", 0x506260, "agiworld:meshrend"),
    MapSymbol("?ClipNX@@YIXAAUCV@@0@Z", 0x506380, "agiworld:meshrend"),
    MapSymbol("?ClipPX@@YAHPAUCV@@0H@Z", 0x506470, "agiworld:meshrend"),
    MapSymbol("?ClipPX@@YIXAAUCV@@0@Z", 0x506590, "agiworld:meshrend"),
    MapSymbol("?ClipNY@@YAHPAUCV@@0H@Z", 0x506680, "agiworld:meshrend"),
    MapSymbol("?ClipNY@@YIXAAUCV@@0@Z", 0x5067A0, "agiworld:meshrend"),
    MapSymbol("?ClipPY@@YAHPAUCV@@0H@Z", 0x506890, "agiworld:meshrend"),
    MapSymbol("?ClipPY@@YIXAAUCV@@0@Z", 0x5069B0, "agiworld:meshrend"),
    MapSymbol("?ClipNZ@@YAHPAUCV@@0H@Z", 0x506A90, "agiworld:meshrend"),
    MapSymbol("?ClipNZ@@YIXAAUCV@@0@Z", 0x506BB0, "agiworld:meshrend"),
    MapSymbol("?ClipPZ@@YAHPAUCV@@0H@Z", 0x506CA0, "agiworld:meshrend"),
    MapSymbol("?ClipPZ@@YIXAAUCV@@0@Z", 0x506DC0, "agiworld:meshrend"),
    MapSymbol("?ZClipOnly@@YAHPAUCV@@0H@Z", 0x506EA0, "agiworld:meshrend"),
    MapSymbol("?HeapAssert@@YAHPAXHPADH@Z", 0x521250, "memory:allocator"),
    MapSymbol("?InitMap@@YAXXZ", 0x5201C0, "memory:stack"),
    MapSymbol("?QuietPrinter@@YAXHPBDPAD@Z", 0x521C20, "arts7:sim"),
    MapSymbol("?IsValidPointer@@YAHPAXIH@Z", 0x523510, "arts7:sim"),
    MapSymbol("?xlat@@YAXAAU_D3DCOLORVALUE@@AAVVector4@@@Z", 0x533720, "agid3d:d3dmtldef"),
    MapSymbol("?EnumCallback@@YGJPAU_GUID@@PAD1PAU_D3DDeviceDesc@@2PAX@Z", 0x5307B0, "agid3d:d3dpipe"),
    MapSymbol("?EnumTextureCallback@@YGJPAU_DDPIXELFORMAT@@PAX@Z", 0x5308B0, "agid3d:d3dpipe"),
    MapSymbol("?EnumZ@@YGJPAU_DDPIXELFORMAT@@PAX@Z", 0x530980, "pcwindis:dxsetup"),
    MapSymbol("?swSetupEdgeScan@@YAXPAUswEdge@@HH@Z", 0x535460, "agisw:swrend"),
    MapSymbol("?__emitZwrite@@YIXPAUswSurface@@H@Z", 0x535910, "agisw:swrend"),
    MapSymbol("?__emitSemiBlack@@YIXH@Z", 0x5367C0, "agisw:swrend"),
    MapSymbol("?__emitStippleBlack@@YIXH@Z", 0x536800, "agisw:swrend"),
    MapSymbol("?swComputeIntensity@@YAHAAUagiScreenVtx@@@Z", 0x536840, "agisw:swrend"),
    MapSymbol("?emms@@YAXXZ", 0x536940, "agisw:swrend"),
    MapSymbol("?swFindColor555@@YAII@Z", 0x537550, "agisw:swrend"),
    MapSymbol("?swFindColor565@@YAII@Z", 0x537590, "agisw:swrend"),
    MapSymbol("?swClampAddColor565@@YIII@Z", 0x5375D0, "agisw:swrend"),
    MapSymbol("?swClampAddColor555@@YIII@Z", 0x537610, "agisw:swrend"),
    MapSymbol("?swClampAdd565@@YIIII@Z", 0x537650, "agisw:swrend"),
    MapSymbol("?swClampAdd555@@YIIII@Z", 0x537690, "agisw:swrend"),
    MapSymbol("?ddStart@@YAXXZ", 0x534EA0, "agisw:swddraw"),
    MapSymbol("?ddEnd@@YAXXZ", 0x534FA0, "agisw:swddraw"),
    MapSymbol("?ddStartFrame@@YAXXZ", 0x534FC0, "agisw:swddraw"),
    MapSymbol("?ddStartScene@@YAXXZ", 0x534FD0, "agisw:swddraw"),
    MapSymbol("?ddEndScene@@YAXXZ", 0x535030, "agisw:swddraw"),
    MapSymbol("?ddEndFrame@@YAXXZ", 0x535070, "agisw:swddraw"),
    MapSymbol("?zmemset@@YAXPAGI@Z", 0x5342F0, "agisw:swpipe"),
    MapSymbol("?RescaleJpeg@@YAXIIPAEAAUjpeg_decompress_struct@@@Z", 0x55AAE0, "agi:surface"),
    MapSymbol("?copyrow565_to_555@@YAXPAX0II@Z", 0x55B510, "agi:surface"),
    MapSymbol("?copyrow565_to_5551@@YAXPAX0II@Z", 0x55B560, "agi:surface"),
    MapSymbol("?copyrow565_to_888@@YAXPAX0II@Z", 0x55B5C0, "agi:surface"),
    MapSymbol("?copyrow565_to_888rev@@YAXPAX0II@Z", 0x55B640, "agi:surface"),
    MapSymbol("?copyrow4444_to_8888@@YAXPAX0II@Z", 0x55B6C0, "agi:surface"),
    MapSymbol("?copyrow4444_to_8888rev@@YAXPAX0II@Z", 0x55B750, "agi:surface"),
    MapSymbol("?copyrow4444_to_555@@YAXPAX0II@Z", 0x55B7E0, "agi:surface"),
    MapSymbol("?copyrow4444_to_565@@YAXPAX0II@Z", 0x55B860, "agi:surface"),
    MapSymbol("?copyrow4444_to_5551@@YAXPAX0II@Z", 0x55B8E0, "agi:surface"),
    MapSymbol("?InitBuiltin@@YAXXZ", 0x557FE0, "agi:print"),
    MapSymbol("?LibOutOfDate@@YAHPAD0@Z", 0x556AD0, "agi:getdlp"),
    MapSymbol("?cmpProblem@@YAHPBX0@Z", 0x561050, "stream:problems"),
    MapSymbol("?SubString@@YAPADHPAD@Z", 0x55FAF0, "stream:fsystem"),
    MapSymbol("?NumSubStrings@@YAHPAD@Z", 0x55FB70, "stream:fsystem"),
    MapSymbol("?Contains@@YAHPAD0@Z", 0x55FBA0, "stream:fsystem"),
    MapSymbol("?ExpandEnvs@@YAXPAD@Z", 0x55FC20, "stream:fsystem"),
    MapSymbol("?DIError@@YAPADH@Z", 0x564050, "eventq7:geinputLib"),
    MapSymbol("?NeedDX6@@YAXXZ", 0x575710, "pcwindis:dxsetup"),
    MapSymbol("?EnumCounter@@YGHPAU_GUID@@PAD1PAX@Z", 0x575740, "pcwindis:dxsetup"),
    MapSymbol("?MyDirectDrawEnumerate@@YAXP6GHPAU_GUID@@PAD1PAX@Z2@Z", 0x575760, "pcwindis:dxsetup"),
    MapSymbol("?EnumerateRenderers2@@YAXXZ", 0x5757D0, "pcwindis:dxsetup"),
    MapSymbol("?CheckSoftwareRenderer@@YAHPAUIDirectDraw4@@PAU_GUID@@@Z", 0x575920, "pcwindis:dxsetup"),
    MapSymbol("?LockScreen@@YAJPAUIDirectDraw4@@@Z", 0x575A10, "pcwindis:dxsetup"),
    MapSymbol("?UnlockScreen@@YAXXZ", 0x575AD0, "pcwindis:dxsetup"),
    MapSymbol("?TestResolution@@YAHPAUIDirectDraw4@@AAUdxiRendererInfo_t@@@Z", 0x575AF0, "pcwindis:dxsetup"),
    MapSymbol("?ModeCallback@@YGJPAU_DDSURFACEDESC2@@PAX@Z", 0x575F40, "pcwindis:dxsetup"),
    MapSymbol("?AddRenderer@@YAXPAUIDirectDraw4@@PAU_GUID@@PAD@Z", 0x576000, "pcwindis:dxsetup"),
    MapSymbol("?EnumTextures@@YGJPAU_DDPIXELFORMAT@@PAX@Z", 0x576470, "pcwindis:dxsetup"),
    MapSymbol("?NotLameChipset@@YAHKK@Z", 0x5764A0, "pcwindis:dxsetup"),
    MapSymbol("?GetSpecialFlags@@YAIKK@Z", 0x5764B0, "pcwindis:dxsetup"),
    MapSymbol("?Enumerator@@YGHPAU_GUID@@PAD1PAX@Z", 0x576580, "pcwindis:dxsetup"),
    MapSymbol("?strtoguid@@YAXPAU_GUID@@PAD@Z", 0x574DF0, "pcwindis:setupdata"),
    MapSymbol("?guidtostr@@YAXPADPAU_GUID@@@Z", 0x575090, "pcwindis:setupdata"),
    MapSymbol("?translate565@@YAXPAEPAGI@Z", 0x5748D0, "pcwindis:dxinit"),
    MapSymbol("?translate555@@YAXPAEPAGI@Z", 0x574940, "pcwindis:dxinit"),
    MapSymbol("?rdtsc@@YAIXZ", 0x57CF40, "data7:speed"),
    MapSymbol("?cpuid@@YAHXZ", 0x57C400, "data7:mmx"),
    MapSymbol("?getMem@@YAHXZ", 0x578B80, "data7:memstat"),
    MapSymbol("?compareExchange@@YIHPAIH@Z", 0x578AB0, "data7:ipc"),
]:
    sym.process(view.arch)
    sym.static = True
    all_symbols.append(sym)

# for symbol in all_symbols:
#     if symbol.address is None:
#         print('{:40} | {:80} | {}'.format(symbol.library, symbol.undec_name or '', symbol.raw_name))

print('Grouping symbol libs')
path_libs = group_stray_symbols(all_symbols)
path_libs.update({
    'MetaType': 'data7:metatype'
})

# print(path_libs)

# for sym in all_symbols:
#     print(sym.raw_name, hex(sym.address or 0))

# Create a dictionary from the valid symbols
symbols = dict((symbol.address, symbol) for symbol in all_symbols if symbol.address is not None)
# print(symbols)

# for name, addr in idc_symbols.items():
#     if name.endswith('_SEH'):
#         continue
#     if 'jpeg' in name:
#         continue
#     if addr not in symbols:
#         if name.startswith('?'):
#             print(name, hex(addr))

# assert False

class_hier = defaultdict(lambda: set())

print('Collecting ctor/dtor hierarchy')
collect_ctor_dtor_hierarchy(view, symbols, class_hier)

print('Collecting vftables')
vftables = collect_vftables(view, symbols, class_hier)
# print(vftables)

print('Collecting class sizes')

if True:
    class_sizes = collect_class_sizes(view, symbols)
else:
    class_sizes = {}

# print(class_sizes)

# print(class_hier)
print('Computing hierarchy')
class_hier = compute_hierarchy(class_hier, {
    'agiColorModelRGB555': ['agiColorModel'],
    'agiColorModelRGB565': ['agiColorModel'],
    'agiColorModelRGB555_Rev': ['agiColorModel'],
    'agiColorModelRGB565_Rev': ['agiColorModel'],
    'agiColorModelRGB888': ['agiColorModel'],
    'agiColorModelRGB888_Rev': ['agiColorModel'],
    'agiColorModelRGBA5551': ['agiColorModel'],
    'agiColorModelRGBA4444': ['agiColorModel'],
    'agiColorModelARGB': ['agiColorModel'],
    'agiColorModelABGR': ['agiColorModel'],
    'agiColorModel8': ['agiColorModel'],

    'mmRoadFF': ['mmEffectFF'],
    'mmSpringFF': ['mmEffectFF'],
    'mmCollideFF': ['mmEffectFF'],
    'mmFrictionFF': ['mmEffectFF'],

    'SMI': ['MI'],
    'BMI': ['MI'],
    'TMI': ['MI'],
    'scharMI': ['MI'],
    'ucharMI': ['MI'],
    'shortMI': ['MI'],
    'ushortMI': ['MI'],
    'intMI': ['MI'],
    'uintMI': ['MI'],
    'floatMI': ['MI'],
    'SBMI': ['MI'],

    'Vector3Type': ['MetaType'],
    'Vector4Type': ['MetaType'],
    'Vector2Type': ['MetaType'],
    'PtrToType': ['MetaType'],
    'RefToType': ['MetaType'],
    'ArrayOfType': ['MetaType'],
    'StructType': ['MetaType'],
    'CharType': ['MetaType'],
    'SignedCharType': ['MetaType'],
    'UnsignedCharType': ['MetaType'],
    'SignedShortType': ['MetaType'],
    'UnsignedShortType': ['MetaType'],
    'SignedIntType': ['MetaType'],
    'SignedInt64Type': ['MetaType'],
    'UnsignedIntType': ['MetaType'],
    'FloatType': ['MetaType'],
    'StringType': ['MetaType'],

    'MixerCTL': ['Dispatchable', 'Base'],
    'asMidgets': ['Bank', 'asCullable'],
    'WINEventHandler': ['eqEventHandler', 'Dispatchable'],

    'aiGoalAvoidPlayer': ['aiGoal'],
    'aiGoalBackup': ['aiGoal'],
    'aiGoalChase': ['aiGoal'],
    'aiGoalCollision': ['aiGoal'],
    'aiGoalFollowWayPts': ['aiGoal'],
    'aiGoalRandomDrive': ['aiGoal'],
    'aiGoalRegainRail': ['aiGoal'],
    'aiGoalStop': ['aiGoal'],
}, {
    'Timer',
    'Callback'
})
# print(class_hier)

# for a, b in class_hier:
#     print(a, b)

# TODO: Sort hierarchy when multiple inheritance

print('Collecting Type Names')
type_classes = collect_symbol_type_classes(all_symbols, class_hier)
# print(type_classes)

type_classes.update({
    'aiGoal': 'class',
})

print('Backporting vftable purecalls')
vftables = backport_vftable_purecalls(vftables, class_hier, {
    'MetaType':  { None: 5 },
})
# print(vftables)

grouped_symbols = defaultdict(lambda: defaultdict(lambda: list()))

for symbol in symbols.values():
    _ = grouped_symbols[symbol.library] # Touch All Libraries

for symbol in symbols.values():
    grouped_symbols[path_libs[symbol.path] if symbol.path else symbol.library][symbol.path].append(symbol)

fixup_vftable_symbols(grouped_symbols, vftables)

SOURCE_DIR = os.path.normpath(os.path.realpath('../code/midtown'))
LICENSE_TXT = '''/*
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
'''

all_files = {}

# assert False

for lib, paths in grouped_symbols.items():
    if 'purevirt' in lib:
        continue

    if any((lib.startswith(v) for v in IGNORED_LIB_PREFIXES)):
        continue

    # if lib not in {}:
    #     continue

    if lib in {'test', 'agiworld:meshrend', 'agiworld:texsort', 'arts7:camera', 'arts7:cullable', 'arts7:node', 'data7:base', 'data7:machname', 'data7:metaclass', 'data7:metatype', 'data7:printer', 'data7:quitf', 'data7:timer', 'memory:allocator', 'memory:stack', 'memory:stub', 'memory:valloc', 'mmcity:loader', 'mmeffects:mmtext', 'pcwindis:dxinit', 'pcwindis:dxsetup', 'vector7:vector3'}:
        continue

    lib_header = ''
    lib_header_includes = set()
    lib_source = ''

    lib_path = lib.replace(':', '\\')
    output_dir = os.path.normpath(SOURCE_DIR + '\\' + lib_path)
    parent_dir = os.path.dirname(output_dir)

    if parent_dir not in all_files:
        lib_name = parent_dir[len(SOURCE_DIR) + 1:].replace(':', '/')
        all_files[parent_dir] = (lib_name, [ ])

    all_files[parent_dir][1].append(output_dir + '.cpp')
    all_files[parent_dir][1].append(output_dir + '.h')

    base_name = os.path.basename(output_dir)

    if not os.path.exists(parent_dir):
        try:
            os.makedirs(parent_dir)
        except:
            pass

    sym_comment = ''
    sym_comment += '/*\n'
    sym_comment += '    ' + lib + '\n\n'

    for sym in all_symbols:
        if sym.library != lib:
            continue

        sym_comment += '    '

        if sym.address is not None:
            sym_comment += '0x%06X | ' % (sym.address)

        if sym.undec_name is not None:
            sym_comment += sym.undec_name + ' | '

        sym_comment += sym.raw_name
        sym_comment += '\n'

    sym_comment += '*/'

    for path, values in paths.items():
        if path:
            path_type = type_classes[path]
            lib_header += '{} {}'.format(path_type, path)

            if path in class_hier:
                parents = class_hier[path]
                if parents:
                    for parent in parents:
                        if parent in path_libs:
                            parent_lib = path_libs[parent]
                            if parent_lib != lib:
                                lib_header_includes.add(parent_lib.replace(':', '/'))

                    lib_header += ': '
                    lib_header += ', '.join(
                        ('public ' if path_type == 'class' else '') + v for v in parents
                    )

                    if len(parents) > 1:
                        lib_header += '/* Warning: Unordered Multiple Inheritance */'

            lib_header += ' {\n'

        values.sort(key=symbol_sort_order)

        visibility = None

        sym_dtors = choose_best_dtor(values)

        for value in values:
            if value.is_vftable:
                lib_header += '// {} @ 0x{:X}\n'.format(value.undec_name, value.address)
                continue

            skip_reason = None

            if value.member_type == 'dtor':
                 if value != sym_dtors[0]:
                    continue
            elif (value.type.type_class == TypeClass.VoidTypeClass):
                skip_reason = 'void'
            elif value.is_thunk:
                skip_reason = 'thunk'
            elif any((v in value.full_name for v in '`\'')):
                skip_reason = 'invalid name'

            if skip_reason is not None:
                lib_header += '// 0x{:X} | {} (Skipped: {})\n\n'.format(value.address, value.raw_name, skip_reason)
                continue

            if value.visibility != visibility:
                visibility = value.visibility

                if visibility is not None:
                    lib_header += '\n'
                    lib_header += visibility
                    lib_header += ': \n'

            tokens = []

            show_calling_convention = False
            add_this_ptr = False
            cc_name = None

            if value.member_type == 'dtor':
                assert value == sym_dtors[0]
                for dtor in sym_dtors:
                    if dtor.raw_name != '__purecall':
                        lib_header += '// 0x{:X} | {}\n'.format(dtor.address, dtor.raw_name)
            elif (value.raw_name != '__purecall') and not (value.type.type_class == TypeClass.FunctionTypeClass and value.static and not value.is_member):
                lib_header += '// 0x{:X} | {}\n'.format(value.address, value.raw_name)

            sym_name = value.parts[:]

            if value.type.type_class == TypeClass.FunctionTypeClass:
                add_this_ptr = value.is_member and not value.static

                cc_name = value.type.calling_convention.name

                if cc_name != ('thiscall' if add_this_ptr and not value.type.has_variable_arguments else 'cdecl'):
                    cc_name = '__' + cc_name
                else:
                    cc_name = None

                if value.member_type == 'dtor':
                    sym_name[-1] = '~' + sym_name[-2]

                skip_declaration = value.static and not value.is_member
                skip_definition = value.raw_name == '__purecall'

                if not skip_declaration:
                    if value.static:
                        tokens.append('static')

                    if value.is_virtual and not value.override:
                        tokens.append('virtual')

                    if value.member_type not in ['ctor', 'dtor']:
                        tokens.extend([beautify_type(v) for v in value.type.get_tokens_before_name()])

                    if cc_name is not None:
                        tokens.append(cc_name)

                    tokens.append(sym_name[-1])

                    tokens.extend([beautify_type(v) for v in value.type.get_tokens_after_name()])

                    if value.override:
                        tokens.append('override')

                    if value.raw_name == '__purecall':
                        tokens.append(' = 0')

                if not skip_definition:
                    assert value.address != 0

                    src_tokens = []

                    if value.static and not value.is_member:
                        src_tokens.append('static')

                    if value.member_type not in ['ctor', 'dtor']:
                        src_tokens.extend([beautify_type(v) for v in value.type.get_tokens_before_name()])

                    if cc_name is not None:
                        src_tokens.append(cc_name)

                    src_tokens.append('::'.join(sym_name))

                    src_tokens.extend([beautify_type(v) for v in value.type.get_tokens_after_name()])

                    src_tokens.append('{')

                    if (value.member_type not in ['ctor', 'dtor']) and not value.type.has_variable_arguments:
                        src_tokens.append('return')

                        src_tokens.append('stub')
                        src_tokens.append('<')

                        src_tokens.append('{}_t'.format(value.type.calling_convention.name))
                        src_tokens.append('<')

                        src_tokens.append(beautify_type(value.type.return_value))

                        if add_this_ptr:
                            src_tokens.append(',')
                            src_tokens.append(value.parts[-2])
                            src_tokens.append('*')

                        for param in value.type.parameters:
                            src_tokens.append(',')
                            src_tokens.append(beautify_type(param.type))

                        src_tokens.append('>')
                        src_tokens.append('>')

                        src_tokens.append('(')

                        src_tokens.append(format_address(value.address))

                        if add_this_ptr:
                            src_tokens.append(',')
                            src_tokens.append('this')

                        for param in value.type.parameters:
                            src_tokens.append(',')
                            src_tokens.append(param.name)

                        src_tokens.append(')')
                    else:
                        src_tokens.append('unimplemented({})'.format(', '.join( p.name for p in value.type.parameters )))

                    src_tokens.append(';')

                    src_tokens.append('}')

                    if src_tokens:
                        lib_source += ' '.join(src_tokens)
                        lib_source += '\n\n'
            else:
                if value.static:
                    tokens.append('static')

                tokens.append('inline')

                tokens.append('extern_var')
                tokens.append('(')

                tokens.append(format_address(value.address))
                tokens.append(', ')

                tokens.append(beautify_type(value.type))
                tokens.append(', ')

                tokens.append(value.name)
                tokens.append(')')

            if tokens:
                lib_header += ' '.join(tokens)
                lib_header += ';';
                lib_header += '\n\n'

        if path:
            lib_header += '};\n\n'

            if (any(not v.static for v in values)):
                lib_header += 'check_size({}, 0x{:X});\n\n'.format(path, class_sizes.get(path, 0))

    # print(lib_header)

    with open(output_dir + '.h', 'w') as f:
        f.write(LICENSE_TXT)
        f.write('\n')
        f.write('#pragma once')
        f.write('\n\n')
        f.write(sym_comment)
        f.write('\n\n')

        if lib_header_includes:
            lib_header_includes = list(lib_header_includes)

            lib_parts = lib.split(':')

            for i, include in enumerate(lib_header_includes):
                include_parts = include.split('/')

                if include_parts[:-1] == lib_parts[:-1]:
                    lib_header_includes[i] = include_parts[-1]

            lib_header_includes.sort()

            for include in lib_header_includes:
                f.write('#include "{}.h"\n'.format(include))

            f.write('\n')

        f.write(lib_header)

    with open(output_dir + '.cpp', 'w') as f:
        f.write(LICENSE_TXT)
        f.write('\n')
        f.write('define_dummy_symbol({});\n'.format(lib.replace(':', '_')))
        f.write('\n')
        f.write('#include "{}.h"\n'.format(base_name))
        f.write('\n')
        f.write(lib_source)

if False:
    for lib_dir, (lib_name, files) in all_files.items():
        with open(lib_dir + '\\premake5.lua', 'w') as f:
            if lib_dir == SOURCE_DIR:
                lib_name = 'midtown'

                for sub_dir, _ in sorted(all_files.items()):
                    if sub_dir != SOURCE_DIR:
                        f.write('-- include "' + sub_dir[len(SOURCE_DIR) + 1:] + '"\n')
                f.write('\n')

            f.write('arts_component "' + lib_name + '"\n')
            f.write('    files {\n')

            for file in sorted(files):
                file = file[len(lib_dir) + 1:].replace('\\', '/')
                f.write('        -- "' + file + '",\n')

            f.write('    }\n\n')

            if lib_dir == SOURCE_DIR:
                f.write('    links {\n')

                for _, (obj_name, _) in sorted(all_files.items()):
                    if obj_name != '':
                        f.write('        -- "arts_' + obj_name + '",\n')

                f.write('    }\n')

print('Formatting')

exec(open("../tools/format_full.py").read())
