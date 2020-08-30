import re
import ctypes
import copy
import os
from collections import defaultdict, OrderedDict
import json

from binaryninja.binaryview import *
from binaryninja.architecture import *
from binaryninja.demangle import *
from binaryninja.enums import *
from binaryninja.types import *

MAP_REGEX = re.compile(r'[0-9a-fA-F]+:[0-9a-fA-F]+\s+(\S+)\s+([0-9a-fA-F]+)([fi ]{5})(\S+)')

IGNORED_LIB_PREFIXES = [
    'LIBCMTD',
    'LIBCD',
    'dinput',
    'dxguid',
    'uuid',
    'setargv',
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
        sym_attribs = result[3].split()
        lib_name = result[4]

        sym_addr = int(sym_addr, 16)

        if sym_name not in ['__purecall', '??_H@YGXPAXIHP6EX0@Z@Z', '??_L@YGXPAXIHP6EX0@Z1@Z', '??_M@YGXPAXIHP6EX0@Z@Z']:
            if any(prefix for prefix in IGNORED_LIB_PREFIXES if lib_name.startswith(prefix)):
                continue

            if lib_name.endswith('.dll') \
            or sym_name.startswith('??_C@') \
            or sym_name.startswith('??_9') \
            or sym_name.startswith('_$E'):
                continue

        if lib_name.endswith('.obj'):
            lib_name = lib_name[:-4]

        if addrs is not None:
            sym_addr = addrs[sym_name] if sym_name in addrs else None

        symbol = MapSymbol(sym_name, sym_addr, lib_name, sym_attribs)

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
    def __init__(self, raw_name, address, library, map_attribs = []):
        self.raw_name = raw_name
        self.address = address
        self.library = library
        self.map_attribs = map_attribs

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
                self.dtor_type = 'dtor'
            elif self.parts[-1] == '`vector deleting destructor\'':
                self.member_type = 'dtor'
                self.dtor_type = 'vdtor'
            elif self.parts[-1] == '`scalar deleting destructor\'':
                self.member_type = 'dtor'
                self.dtor_type = 'sdtor'

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
    type_classes = dict()

    pending = [symbol.type for symbol in symbols if symbol.type is not None]

    while pending:
        current = pending.pop()
        type_class = current.type_class

        if type_class == TypeClass.FunctionTypeClass:
            pending.append(current.return_value)
            pending.extend((v.type for v in current.parameters))
        elif type_class == TypeClass.PointerTypeClass:
            pending.append(current.target)
        elif type_class == TypeClass.ArrayTypeClass:
            pending.append(current.target)
        elif type_class == TypeClass.NamedTypeReferenceClass:
            named_type = current.named_type_reference
            named_type_class = named_type.type_class

            if named_type_class in type_class_to_str:
                type_classes[named_type.name] = type_class_to_str[named_type_class]

    for _ in range(2):
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
            if symbol.path in type_classes:
                continue
            if not symbol.is_member:
                continue
            if symbol.is_virtual or (symbol.visibility != 'public'):
                type_classes[symbol.path] = 'class'

    for symbol in symbols:
        if (symbol.is_member or symbol.is_vftable) and (symbol.path not in type_classes):
            type_classes[symbol.path] = 'struct'

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

    for a, b in extra.items():
        done[a] = b

    return dict(done)

def compuate_final_classes(class_hier):
    final_classes = set(class_hier.keys())

    for parents in class_hier.values():
        for parent in parents:
            if parent in final_classes:
                final_classes.remove(parent)

    return final_classes

def backport_vftable_purecalls(raw_vftables, hiers, overrides):
    vftables = dict()

    # vftables[None] = None

    for symbol in all_symbols:
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
                    new_symbol.override = False

                    if new_symbol.visibility == 'private':
                        new_symbol.visibility = 'public'

                    parent_table[i] = new_symbol

                    changed = True

    return vftables

def group_stray_symbols(symbols, overrides):
    path_libs = defaultdict(lambda: defaultdict(lambda: 0))

    inline_symbols = []

    for symbol in symbols:
        if not symbol.path:
            continue

        if symbol.library == 'purevirt':
            continue

        if 'i' in symbol.map_attribs:
            inline_symbols.append(symbol)
            continue

        path_libs[symbol.path][symbol.library] += 1

    path_libs = dict((k, max(v.items(), key = lambda x: x[1])[0]) for k, v in path_libs.items() if k)

    path_libs.update(overrides)

    inline_path_libs = dict()

    for symbol in inline_symbols:
        if symbol.path in inline_path_libs:
            if symbol.library != inline_path_libs[symbol.path]:
                print('Unsure of symbol library: {}'.format(symbol))

        if symbol.path not in path_libs:
            inline_path_libs[symbol.path] = symbol.library

    path_libs.update(inline_path_libs)

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

def calculate_class_paddings(class_sizes, class_hier, vftables):
    class_paddings = {}

    for name, size in class_sizes.items():
        padding_offset = 0
        is_parent_virtual = False

        if name in class_hier:
            hiers = class_hier[name]
            if len(hiers) > 1:
                continue
            if len(hiers) == 1:
                parent = hiers[0]
                padding_offset = class_sizes[parent]
                assert padding_offset <= size, (name, parent)
                is_parent_virtual = parent in vftables

        if name in vftables and not is_parent_virtual:
            padding_offset += 4

        if padding_offset != size:
            class_paddings[name] = (padding_offset, size - padding_offset)

    # print(class_paddings)
    # assert False

    return class_paddings

def collect_default_dtor(view, symbols, class_hier):
    def inherits_from(child, parent):
        pending = [child]

        while pending:
            current = pending.pop()
            if current == parent:
                return True
            if current in class_hier:
                pending.extend(class_hier[current])

        return False


    default_dtors = set()

    for symbol in symbols.values():
        if symbol.member_type != 'dtor':
            continue

        if symbol.dtor_type != 'dtor':
            continue

        func = view.get_function_at(symbol.address)

        if func is None:
            print('Invalid ctor/dtor {} @ 0x{:X}'.format(symbol.undec_name, symbol.address))
            continue

        hlil = func.hlil

        if len(hlil) > 2:
            continue

        index = 0

        if hlil[index].operation == HighLevelILOperation.HLIL_ASSIGN:
            assign_src = hlil[index].src

            if assign_src.operation not in [HighLevelILOperation.HLIL_CONST, HighLevelILOperation.HLIL_CONST_PTR]:
                continue

            if assign_src.constant not in symbols:
                continue

            assign_sym = symbols[assign_src.constant]

            if not assign_sym.is_vftable:
                continue

            if not inherits_from(symbol.path, assign_sym.path):
                continue

            index += 1

        if hlil[index].operation in [HighLevelILOperation.HLIL_CALL, HighLevelILOperation.HLIL_TAILCALL]:
            dest = hlil[index].dest

            if dest.operation not in [HighLevelILOperation.HLIL_CONST, HighLevelILOperation.HLIL_CONST_PTR]:
                continue

            if dest.constant not in symbols:
                continue

            dest_sym = symbols[dest.constant]

            if dest_sym.member_type != 'dtor':
                continue

            if dest_sym.dtor_type != 'dtor':
                continue

            if not inherits_from(symbol.path, dest_sym.path):
                continue

            index += 1
        elif hlil[index].operation == HighLevelILOperation.HLIL_RET:
            if len(hlil[index].src) != 0:
                continue

            index += 1
        else:
            continue

        if index != len(hlil):
            continue

        default_dtors.add(symbol.path)

    return default_dtors

def collect_empty_functions(view, symbols):
    empty_functions = set()

    for symbol in symbols.values():
        if symbol.member_type is not None:
            continue

        if symbol.type.type_class != TypeClass.FunctionTypeClass:
            continue

        func = view.get_function_at(symbol.address)

        if func is None:
            print('Invalid func {} @ 0x{:X}'.format(symbol.undec_name, symbol.address))
            continue

        hlil = func.hlil

        if len(hlil) != 1:
            continue

        insn = hlil[0]

        if insn.operation != HighLevelILOperation.HLIL_RET:
            continue

        src = insn.src

        if len(src) > 1:
            continue

        if len(src) == 1:
            src = src[0]

            if src.operation not in [HighLevelILOperation.HLIL_CONST, HighLevelILOperation.HLIL_CALL_SSA]:
                continue

            if src.constant != 0:
                continue

        empty_functions.add(symbol.address)

    return empty_functions

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
    elif symbol.visibility == 'public':
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

        ('__stdcall', 'ARTS_STDCALL'),
        ('__fastcall', 'ARTS_FASTCALL'),

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

def is_ignored_token(token):
    if token.type == InstructionTextTokenType.KeywordToken:
        return token.text in [
            'public:',
            'protected:',
            'private:',
            'static',
        ]

    return False

def filter_type_tokens(tokens):
    return ''.join((replace_builtin_types(token.text) for token in tokens if not is_ignored_token(token)))

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
view = BinaryViewType.get_view_of_file('test1560.bndb', update_analysis=False)

print('Processing Symbols')
for symbol in all_symbols:
    symbol.process(view.arch)

for sym in [
    MapSymbol('?TouchMemory@@YAXPAXH@Z', 0x402E70, 'test', ['f']),
    MapSymbol('?exeDirFile@@YAPADPAD0@Z', 0x402EC0, 'test', ['f']),
    MapSymbol('?GameCloseCallback@@YAXXZ', 0x402F20, 'test', ['f']),
    MapSymbol('?IsModemDialin@@YA_NXZ', 0x409CD0, 'mmgame:interface', ['f']),
    MapSymbol('?ZoneWatcher@@YGKPAX@Z', 0x409D50, 'mmgame:interface', ['f']),
    MapSymbol('?randcall@@YAXXZ', 0x404390, 'mmgame:gameman', ['f']),
    MapSymbol('?DoScan@@YAXPAX@Z', 0x4046D0, 'mmgame:gameman', ['f']),
    MapSymbol('?StuckCB@@YAXPAVaiStuck@@@Z', 0x46B470, 'mmai:aiStuck', ['f']),
    MapSymbol('?SplashCB@@YAXPAVmmSplash@@@Z', 0x481050, 'mmcar:splash', ['f']),
    MapSymbol('?StuckCB@@YAXPAVmmStuck@@@Z', 0x47C4F0, 'mmcar:stuck', ['f']),
    MapSymbol('?MatrixFromPoints@@YAXAAVMatrix34@@AAVVector3@@1M@Z', 0x493670, 'mmcity:inst', ['f']),
    MapSymbol('?fix_sun@@YAXXZ', 0x48E1B0, 'mmcity:cullcity', ['f']),
    MapSymbol('?fix_fill1@@YAXXZ', 0x48E220, 'mmcity:cullcity', ['f']),
    MapSymbol('?fix_fill2@@YAXXZ', 0x48E290, 'mmcity:cullcity', ['f']),
    MapSymbol('?parseFloat@@YAXAAM@Z', 0x48E300, 'mmcity:cullcity', ['f']),
    MapSymbol('?parseVector3@@YAXAAVVector3@@@Z', 0x48E330, 'mmcity:cullcity', ['f']),
    MapSymbol('?parseRGB@@YAXAAI@Z', 0x48E360, 'mmcity:cullcity', ['f']),
    MapSymbol('?parseARGB@@YAXAAI@Z', 0x48E3D0, 'mmcity:cullcity', ['f']),
    MapSymbol('?toggle_interlace@@YAXXZ', 0x4A9E70, 'mmui:pu_graphics', ['f']),
    MapSymbol('?toggle_filter@@YAXXZ', 0x4A9E90, 'mmui:pu_graphics', ['f']),
    MapSymbol('?fix_lighting_lame@@YAXXZ', 0x4A9EC0, 'mmui:pu_graphics', ['f']),
    MapSymbol('?CalibrateWatcher@@YGKPAX@Z', 0x4A37A0, 'mmui:control', ['f']),
    MapSymbol('?SetTexQualString@@YAXXZ', 0x49A050, 'mmui:graphics', ['f']),
    MapSymbol('?HelpWatcher@@YGKPAX@Z', 0x4B1B30, 'mmwidget:manager', ['f']),
    MapSymbol('?Matrix34__FromEulersXZY@@YAXAAVMatrix34@@ABVVector3@@@Z', 0x517090, 'agiworld:bone', ['f']),
    MapSymbol('?cmpTex@@YAHPBX0@Z', 0x512080, 'agiworld:texsheet', ['f']),
    MapSymbol('?mmxTriple@@YAXPAI0HPAEH@Z', 0x510EE0, 'agiworld:meshlight', ['f']),
    MapSymbol('?agiInitCones@@YAXAAVMatrix34@@M@Z', 0x5116B0, 'agiworld:meshlight', ['f']),
    MapSymbol('?FullClip@@YAHPAUCV@@0H@Z', 0x5061B0, 'agiworld:meshrend', ['f']),
    MapSymbol('?ClipNX@@YAHPAUCV@@0H@Z', 0x506260, 'agiworld:meshrend', ['f']),
    MapSymbol('?ClipNX@@YIXAAUCV@@0@Z', 0x506380, 'agiworld:meshrend', ['f']),
    MapSymbol('?ClipPX@@YAHPAUCV@@0H@Z', 0x506470, 'agiworld:meshrend', ['f']),
    MapSymbol('?ClipPX@@YIXAAUCV@@0@Z', 0x506590, 'agiworld:meshrend', ['f']),
    MapSymbol('?ClipNY@@YAHPAUCV@@0H@Z', 0x506680, 'agiworld:meshrend', ['f']),
    MapSymbol('?ClipNY@@YIXAAUCV@@0@Z', 0x5067A0, 'agiworld:meshrend', ['f']),
    MapSymbol('?ClipPY@@YAHPAUCV@@0H@Z', 0x506890, 'agiworld:meshrend', ['f']),
    MapSymbol('?ClipPY@@YIXAAUCV@@0@Z', 0x5069B0, 'agiworld:meshrend', ['f']),
    MapSymbol('?ClipNZ@@YAHPAUCV@@0H@Z', 0x506A90, 'agiworld:meshrend', ['f']),
    MapSymbol('?ClipNZ@@YIXAAUCV@@0@Z', 0x506BB0, 'agiworld:meshrend', ['f']),
    MapSymbol('?ClipPZ@@YAHPAUCV@@0H@Z', 0x506CA0, 'agiworld:meshrend', ['f']),
    MapSymbol('?ClipPZ@@YIXAAUCV@@0@Z', 0x506DC0, 'agiworld:meshrend', ['f']),
    MapSymbol('?ZClipOnly@@YAHPAUCV@@0H@Z', 0x506EA0, 'agiworld:meshrend', ['f']),
    MapSymbol('?HeapAssert@@YAHPAXHPADH@Z', 0x521250, 'memory:allocator', ['f']),
    MapSymbol('?InitMap@@YAXXZ', 0x5201C0, 'memory:stack', ['f']),
    MapSymbol('?QuietPrinter@@YAXHPBDPAD@Z', 0x521C20, 'arts7:sim', ['f']),
    MapSymbol('?IsValidPointer@@YAHPAXIH@Z', 0x523510, 'arts7:sim', ['f']),
    MapSymbol('?xlat@@YAXAAU_D3DCOLORVALUE@@AAVVector4@@@Z', 0x533720, 'agid3d:d3dmtldef', ['f']),
    MapSymbol('?EnumCallback@@YGJPAU_GUID@@PAD1PAU_D3DDeviceDesc@@2PAX@Z', 0x5307B0, 'agid3d:d3dpipe', ['f']),
    MapSymbol('?EnumTextureCallback@@YGJPAU_DDPIXELFORMAT@@PAX@Z', 0x5308B0, 'agid3d:d3dpipe', ['f']),
    MapSymbol('?EnumZ@@YGJPAU_DDPIXELFORMAT@@PAX@Z', 0x530980, 'agid3d:d3dpipe', ['f']),
    MapSymbol('?EnumZ@@YGJPAU_DDPIXELFORMAT@@PAX@Z', 0x575FD0, 'pcwindis:dxsetup', ['f']),
    MapSymbol('?swSetupEdgeScan@@YAXPAUswEdge@@HH@Z', 0x535460, 'agisw:swrend', ['f']),
    MapSymbol('?__emitZwrite@@YIXPAUswSurface@@H@Z', 0x535910, 'agisw:swrend', ['f']),
    MapSymbol('?__emitSemiBlack@@YIXH@Z', 0x5367C0, 'agisw:swrend', ['f']),
    MapSymbol('?__emitStippleBlack@@YIXH@Z', 0x536800, 'agisw:swrend', ['f']),
    MapSymbol('?swComputeIntensity@@YAHAAUagiScreenVtx@@@Z', 0x536840, 'agisw:swrend', ['f']),
    MapSymbol('?emms@@YAXXZ', 0x536940, 'agisw:swrend', ['f']),
    MapSymbol('?swFindColor555@@YAII@Z', 0x537550, 'agisw:swrend', ['f']),
    MapSymbol('?swFindColor565@@YAII@Z', 0x537590, 'agisw:swrend', ['f']),
    MapSymbol('?swClampAddColor565@@YIII@Z', 0x5375D0, 'agisw:swrend', ['f']),
    MapSymbol('?swClampAddColor555@@YIII@Z', 0x537610, 'agisw:swrend', ['f']),
    MapSymbol('?swClampAdd565@@YIIII@Z', 0x537650, 'agisw:swrend', ['f']),
    MapSymbol('?swClampAdd555@@YIIII@Z', 0x537690, 'agisw:swrend', ['f']),
    MapSymbol('?ddStart@@YAXXZ', 0x534EA0, 'agisw:swddraw', ['f']),
    MapSymbol('?ddEnd@@YAXXZ', 0x534FA0, 'agisw:swddraw', ['f']),
    MapSymbol('?ddStartFrame@@YAXXZ', 0x534FC0, 'agisw:swddraw', ['f']),
    MapSymbol('?ddStartScene@@YAXXZ', 0x534FD0, 'agisw:swddraw', ['f']),
    MapSymbol('?ddEndScene@@YAXXZ', 0x535030, 'agisw:swddraw', ['f']),
    MapSymbol('?ddEndFrame@@YAXXZ', 0x535070, 'agisw:swddraw', ['f']),
    MapSymbol('?zmemset@@YAXPAGI@Z', 0x5342F0, 'agisw:swpipe', ['f']),
    MapSymbol('?RescaleJpeg@@YAXIIPAEAAUjpeg_decompress_struct@@@Z', 0x55AAE0, 'agi:surface', ['f']),
    MapSymbol('?copyrow565_to_555@@YAXPAX0II@Z', 0x55B510, 'agi:surface', ['f']),
    MapSymbol('?copyrow565_to_5551@@YAXPAX0II@Z', 0x55B560, 'agi:surface', ['f']),
    MapSymbol('?copyrow565_to_888@@YAXPAX0II@Z', 0x55B5C0, 'agi:surface', ['f']),
    MapSymbol('?copyrow565_to_888rev@@YAXPAX0II@Z', 0x55B640, 'agi:surface', ['f']),
    MapSymbol('?copyrow4444_to_8888@@YAXPAX0II@Z', 0x55B6C0, 'agi:surface', ['f']),
    MapSymbol('?copyrow4444_to_8888rev@@YAXPAX0II@Z', 0x55B750, 'agi:surface', ['f']),
    MapSymbol('?copyrow4444_to_555@@YAXPAX0II@Z', 0x55B7E0, 'agi:surface', ['f']),
    MapSymbol('?copyrow4444_to_565@@YAXPAX0II@Z', 0x55B860, 'agi:surface', ['f']),
    MapSymbol('?copyrow4444_to_5551@@YAXPAX0II@Z', 0x55B8E0, 'agi:surface', ['f']),
    MapSymbol('?InitBuiltin@@YAXXZ', 0x557FE0, 'agi:print', ['f']),
    MapSymbol('?LibOutOfDate@@YAHPAD0@Z', 0x556AD0, 'agi:getdlp', ['f']),
    MapSymbol('?cmpProblem@@YAHPBX0@Z', 0x561050, 'stream:problems', ['f']),
    MapSymbol('?SubString@@YAPADHPAD@Z', 0x55FAF0, 'stream:fsystem', ['f']),
    MapSymbol('?NumSubStrings@@YAHPAD@Z', 0x55FB70, 'stream:fsystem', ['f']),
    MapSymbol('?Contains@@YAHPAD0@Z', 0x55FBA0, 'stream:fsystem', ['f']),
    MapSymbol('?ExpandEnvs@@YAXPAD@Z', 0x55FC20, 'stream:fsystem', ['f']),
    MapSymbol('?DIError@@YAPADH@Z', 0x564050, 'eventq7:geinputLib', ['f']),
    MapSymbol('?NeedDX6@@YAXXZ', 0x575710, 'pcwindis:dxsetup', ['f']),
    MapSymbol('?EnumCounter@@YGHPAU_GUID@@PAD1PAX@Z', 0x575740, 'pcwindis:dxsetup', ['f']),
    MapSymbol('?MyDirectDrawEnumerate@@YAXP6GHPAU_GUID@@PAD1PAX@Z2@Z', 0x575760, 'pcwindis:dxsetup', ['f']),
    MapSymbol('?EnumerateRenderers2@@YAXXZ', 0x5757D0, 'pcwindis:dxsetup', ['f']),
    MapSymbol('?CheckSoftwareRenderer@@YAHPAUIDirectDraw4@@PAU_GUID@@@Z', 0x575920, 'pcwindis:dxsetup', ['f']),
    MapSymbol('?LockScreen@@YAJPAUIDirectDraw4@@@Z', 0x575A10, 'pcwindis:dxsetup', ['f']),
    MapSymbol('?UnlockScreen@@YAXXZ', 0x575AD0, 'pcwindis:dxsetup', ['f']),
    MapSymbol('?TestResolution@@YAHPAUIDirectDraw4@@AAUdxiRendererInfo_t@@@Z', 0x575AF0, 'pcwindis:dxsetup', ['f']),
    MapSymbol('?ModeCallback@@YGJPAU_DDSURFACEDESC2@@PAX@Z', 0x575F40, 'pcwindis:dxsetup', ['f']),
    MapSymbol('?AddRenderer@@YAXPAUIDirectDraw4@@PAU_GUID@@PAD@Z', 0x576000, 'pcwindis:dxsetup', ['f']),
    MapSymbol('?EnumTextures@@YGJPAU_DDPIXELFORMAT@@PAX@Z', 0x576470, 'pcwindis:dxsetup', ['f']),
    MapSymbol('?NotLameChipset@@YAHKK@Z', 0x5764A0, 'pcwindis:dxsetup', ['f']),
    MapSymbol('?GetSpecialFlags@@YAIKK@Z', 0x5764B0, 'pcwindis:dxsetup', ['f']),
    MapSymbol('?Enumerator@@YGHPAU_GUID@@PAD1PAX@Z', 0x576580, 'pcwindis:dxsetup', ['f']),
    MapSymbol('?strtoguid@@YAXPAU_GUID@@PAD@Z', 0x574DF0, 'pcwindis:setupdata', ['f']),
    MapSymbol('?guidtostr@@YAXPADPAU_GUID@@@Z', 0x575090, 'pcwindis:setupdata', ['f']),
    MapSymbol('?translate565@@YAXPAEPAGI@Z', 0x5748D0, 'pcwindis:dxinit', ['f']),
    MapSymbol('?translate555@@YAXPAEPAGI@Z', 0x574940, 'pcwindis:dxinit', ['f']),
    MapSymbol('?rdtsc@@YAIXZ', 0x57CF40, 'data7:speed', ['f']),
    MapSymbol('?cpuid@@YAHXZ', 0x57C400, 'data7:mmx', ['f']),
    MapSymbol('?getMem@@YAHXZ', 0x578B80, 'data7:memstat', ['f']),
    MapSymbol('?compareExchange@@YIHPAIH@Z', 0x578AB0, 'data7:ipc', ['f']),
]:
    sym.process(view.arch)
    sym.static = True
    all_symbols.append(sym)

for sym in all_symbols:
    if sym.library == 'test':
        sym.library = 'midtown'

all_symbols.sort(key = lambda x: x.address)

# for i in range(len(all_symbols) - 1):
#     sym = all_symbols[i]
#     if sym.type.type_class != TypeClass.PointerTypeClass:
#         continue
#     if sym.type.target.type_class == TypeClass.VoidTypeClass:
#         continue
#     if all_symbols[i + 1].address < sym.address + 12:
#         continue
#     print(sym)
# assert False

# for sym in all_symbols:
#     name = sym.raw_name

#     if name.startswith('??_'):
#         continue
#     if name.startswith('_'): # malloc, free, etc.
#         continue
#     if name in '?EnumZ@@YGJPAU_DDPIXELFORMAT@@PAX@Z': # Duplicate static symbol
#         continue

#     with open('../code/loader/stubs/imp_{:X}.asm'.format(sym.address), 'w') as f:
#         f.write('.386\n')
#         f.write('.MODEL FLAT\n')

#         f.write('.CONST\n')
#         f.write('PUBLIC __imp_{}\n'.format(name))
#         f.write('__imp_{} dd {:X}h\n'.format(name, sym.address))

#         f.write('END')

#     if sym.virtual:
#         with open('../code/loader/stubs/stub_{:X}.asm'.format(sym.address), 'w') as f:
#             f.write('.386\n')
#             f.write('.MODEL FLAT\n')

#             f.write('EXTERN __imp_{} : DWORD\n'.format(name))
#             f.write('.CODE\n')
#             f.write('{} PROC PUBLIC\n'.format(name))
#             f.write('jmp dword ptr [__imp_{}]\n'.format(name))
#             f.write('{} ENDP\n'.format(name))

#             f.write('END')

# with open('../code/loader/Open1560_stubs.asm', 'w') as f:
#     f.write('.386\n')
#     f.write('.MODEL FLAT\n')

#     for sym in all_symbols:
#         name = sym.raw_name

#         if name.startswith('??_'):
#             continue
#         if name.startswith('_'): # malloc, free, etc.
#             continue
#         if name in '?EnumZ@@YGJPAU_DDPIXELFORMAT@@PAX@Z': # Duplicate static symbol
#             continue

#         f.write('.CONST\n')
#         f.write('PUBLIC __imp_{}\n'.format(name))
#         f.write('__imp_{} dd {:X}h\n'.format(name, sym.address))

#         if sym.type.type_class == TypeClass.FunctionTypeClass:
#             f.write('_TEXT${:X} SEGMENT \'CODE\'\n'.format(sym.address))
#             f.write('{} PROC PUBLIC\n'.format(name))
#             f.write('jmp dword ptr [__imp_{}]\n'.format(name))
#             f.write('{} ENDP\n'.format(name))

#     f.write('END')

# assert False

# for symbol in all_symbols:
#     if symbol.address is None:
#         print('{:40} | {:80} | {}'.format(symbol.library, symbol.undec_name or '', symbol.raw_name))

print('Grouping symbol libs')
path_libs = group_stray_symbols(all_symbols, {
    'MetaType': 'data7:metatype',
    'asPortalRenderable': 'mmcity:portal',
    'mmCompBase': 'mmwidget:compbase',
    'Dispatchable': 'eventq7:dispatchable',
    'Bank': 'arts7:bank',
    'agiMeshSet': 'agiworld:meshset',
    'agiLib<class agiMtlParameters,class agiMtlDef>': 'agi:mtllib',
    'agiLib<class agiPhysParameters,class agiPhysDef>': 'agi:physlib',
    'agiLib<class agiTexParameters,class agiTexDef>': 'agi:texlib',
    'PagerInfo_t': 'data7:pager',
    'aiGoal': 'mmai:aiGoal',
    'mmPhysEntity': 'mmphysics:entity',
})

# print(path_libs)

# for sym in all_symbols:
#     print(sym.raw_name, hex(sym.address or 0))

# Create a dictionary from the valid symbols
symbols = dict((symbol.address, symbol) for symbol in all_symbols if symbol.address is not None)
# print(symbols)

for array_sym_addr, array_sym_len in [
    (0x634690, 0),
    (0x635AC8, 7),
    (0x63E260, 4),
    (0x63F828, 3),
    (0x6401C0, 4),
    (0x640A60, 10),
    (0x640A88, 12),
    (0x642808, 16),
    (0x647DD8, 16),
    (0x64A0D8, 32),
    (0x64A730, 4),
    (0x64B6A0, 198),
    (0x656C30, 768),
    (0x658D70, 16),
    (0x658DB0, 16),
    (0x658DF0, 16),
    (0x658E30, 16),
    (0x658E70, 16),
    (0x65A548, 4300),
    (0x65E878, 1034),
    (0x65F8A0, 1034),
    (0x6608C8, 401),
    (0x661AC0, 0),
    (0x662478, 256),
    (0x671D08, 40),
    (0x672050, 40),
    (0x6A6E40, 128),
    (0x6A6EC8, 80),
    (0x6A6F30, 20),
    (0x6A7378, 30),
    (0x6A7CE0, 6),
    (0x6A7F18, 20),
    (0x6ED4F8, 4096),
    (0x6F1538, 4096),
    (0x7057C0, 3),
    (0x7057D0, 3),
    (0x7086C0, 32),
    (0x716F90, 32),
    (0x719630, 64),
    (0x719788, 32),
    (0x719C48, 256),
    (0x719E50, 16384),
    (0x720EB8, 2),
    (0x720EE0, 256),
    (0x721128, 16384),
    (0x725140, 16384),
    (0x72D160, 256),
    (0x73D398, 2),
    (0x73E738, 198),
    (0x73EE30, 16384),
    (0x77F4A0, 30),
    (0x77F518, 30),
    (0x780730, 16384),
    (0x795D38, 256),
    (0x7E0028, 16),
    (0x7E0040, 16),
    (0x7E0080, 16),
    (0x7E00B0, 16),
    (0x7E0170, 16),
    (0x7E01B0, 16),
    (0x7E0270, 16),
    (0x7E02D8, 6968),
    (0x8B3220, 6968),
    (0x8BAC08, 16384),
    (0x8FAD70, 64),
    (0x907A38, 64),
    (0x909680, 8),
    (0x90A688, 10),
    (0x90AA28, 256),
    (0x90B208, 128),
    (0x90B288, 128),
    (0x90B3D0, 128),
]:
    sym = symbols[array_sym_addr]
    assert sym.type.type_class == TypeClass.PointerTypeClass
    sym.type = Type.array(sym.type.target, array_sym_len)

symbols[0x63F828].type = Type.array(Type.array(Type.array(Type.float(4), 3), 4), 3)

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

if False:
    class_sizes = collect_class_sizes(view, symbols)
else:
    class_sizes = {}

class_sizes.update({
    'AICamCS': 0x120,
    'AboutMenu': 0xB0,
    'AddOnCarAudio': 0xC,
    'AppCamCS': 0x114,
    'ArgSet': 0x208,
    'ArrayOfType': 0xC,
    'AudHead': 0x50,
    'AudManager': 0xA0,
    'AudSound': 0xB8,
    'AudStream': 0x54,
    'AudioOptions': 0x6F00,
    'BMI': 0x5C,
    'Bank': 0x4,
    'Base': 0x4,
    'BaseCamCS': 0x9C,
    'CArrayList': 0x8,
    'CDMan': 0x30,
    'CRSettings': 0x140,
    'CReverb': 0x4,
    'CReverbBuffer': 0x4,
    'Callback': 0x14,
    'CarCamCS': 0x118,
    'Card2D': 0x38,
    'CharType': 0x4,
    'ControlBase': 0x14,
    'ControlSetup': 0x6F08,
    'DLP': 0x94,
    'DLPGroup': 0x30,
    'DLPPatch': 0x18,
    'DLPTemplate': 0x3C,
    'DLPVertex': 0x28,
    'DSGlobal': 0xB8,
    'DataCache': 0x40,
    'Dialog_City': 0xCC,
    'Dialog_ControlAssign': 0xC0,
    'Dialog_DriverRec': 0xE4,
    'Dialog_HallOfFame': 0xE4,
    'Dialog_Message': 0xD0,
    'Dialog_NewPlayer': 0x110,
    'Dialog_Password': 0xEC,
    'Dialog_RaceEnvironment': 0xF0,
    'Dialog_Serial': 0x148,
    'Dialog_TCPIP': 0xEC,
    'Dispatchable': 0x4,
    'DriverMenu': 0x12C,
    'DupBuffCreator': 0x8,
    'DynamicDLP': 0x24,
    'EngineAudio': 0x90,
    'EngineAudioOpponent': 0x54,
    'FileStream': 0x28,
    'FileSystem': 0x8,
    'FloatArray': 0x14,
    'FloatType': 0x4,
    'GraphicsOptions': 0x6EE8,
    'HashIterator': 0xC,
    'HashTable': 0x10,
    'HierFileSystem': 0x8,
    'HostRaceMenu': 0xF98,
    'IntArray': 0x14,
    'Joint3Dof': 0xE0,
    'JointedStruct': 0x20,
    'List': 0x8,
    'MArray': 0xC,
    'MI': 0x48,
    'MainMenu': 0x90,
    'Matrix34': 0x30,
    'Matrix44': 0x40,
    'MenuManager': 0x140,
    'MetaClass': 0x28,
    'MetaType': 0x4,
    'MiniParser': 0x11C,
    'MixerCTL': 0x38,
    'NetAddOnCarAudio': 0xC,
    'NetArena': 0x130,
    'NetAudioManager': 0x74,
    'NetSelectMenu': 0x27C,
    'OptionsBase': 0x6EC8,
    'OptionsMenu': 0x98,
    'PUAudioOptions': 0xC0,
    'PUChat': 0x128,
    'PUControl': 0xD8,
    'PUDebug': 0x128,
    'PUExit': 0xC0,
    'PUGraphics': 0xC0,
    'PUKey': 0xCC,
    'PUMain': 0xC0,
    'PUMenuBase': 0xC0,
    'PUOptions': 0xC0,
    'PUQuit': 0xC0,
    'PUResults': 0xF0,
    'PURoster': 0x240,
    'PagerInfo_t': 0x10,
    'PointCamCS': 0x144,
    'PolarCamCS': 0x130,
    'PostCamCS': 0x12C,
    'PovCamCS': 0x144,
    'PreCamCS': 0x130,
    'PtrToType': 0x8,
    'Quaternion': 0x10,
    'RDLP': 0xAC,
    'RDynamicDLP': 0x28,
    'RaceMenu': 0xF94,
    'RaceMenuBase': 0xF90,
    'RadialGauge': 0xCC,
    'Random': 0xE8,
    'RefToType': 0x10,
    'Root': 0x0,
    'SBMI': 0x50,
    'SMI': 0x48,
    'SignedCharType': 0x4,
    'SignedInt64Type': 0x4,
    'SignedIntType': 0x4,
    'SignedShortType': 0x4,
    'SoundObj': 0x88,
    'Spline': 0x74,
    'Stream': 0x20,
    'StreamMiniParser': 0x120,
    'StreamObj': 0x138,
    'StringArray': 0x14,
    'StringType': 0x4,
    'StructType': 0x8,
    'TMI': 0x68,
    'TextDropWidget': 0x38,
    'Timer': 0x4,
    'Tokenizer': 0x10,
    'TrackCamCS': 0x324,
    'TransitionCS': 0x130,
    'UIBMButton': 0xF0,
    'UIBMLabel': 0xA0,
    'UIButton': 0xB4,
    'UICWArray': 0xDC,
    'UICompositeScroll': 0xE4,
    'UIControlWidget': 0xB8,
    'UIIcon': 0x94,
    'UIIconW': 0xBC,
    'UILabel': 0x88,
    'UIMenu': 0x90,
    'UIMexButton': 0xCC,
    'UISlider': 0xCC,
    'UITextDropdown': 0x104,
    'UITextField': 0x144,
    'UITextRoller': 0x110,
    'UITextRoller2': 0x144,
    'UITextScroll': 0xE4,
    'UIToggleButton': 0xBC,
    'UIToggleButton2': 0xC0,
    'UIVScrollBar': 0x10C,
    'UnsignedCharType': 0x4,
    'UnsignedIntType': 0x4,
    'UnsignedShortType': 0x4,
    'VSWidget': 0xD0,
    'Vector2': 0x8,
    'Vector2Array': 0x14,
    'Vector2Type': 0x4,
    'Vector3': 0xC,
    'Vector3Array': 0x14,
    'Vector3Type': 0x4,
    'Vector4': 0x10,
    'Vector4Array': 0x14,
    'Vector4Type': 0x4,
    'VehGyro': 0x34,
    'VehShowcase': 0x98,
    'Vehicle': 0x184,
    'VehicleSelectBase': 0x168,
    'VirtualFileSystem': 0x24,
    'VirtualStream': 0x30,
    'VolumeDW': 0xC,
    'WArray': 0xC,
    'WINEventHandler': 0x16C,
    'agiBILight': 0x88,
    'agiBILightModel': 0x40,
    'agiBitmap': 0x3C,
    'agiColorModel': 0x2C,
    'agiColorModel8': 0x30,
    'agiColorModelABGR': 0x2C,
    'agiColorModelARGB': 0x2C,
    'agiColorModelRGB555': 0x2C,
    'agiColorModelRGB555_Rev': 0x2C,
    'agiColorModelRGB565': 0x2C,
    'agiColorModelRGB565_Rev': 0x2C,
    'agiColorModelRGB888': 0x2C,
    'agiColorModelRGB888_Rev': 0x2C,
    'agiColorModelRGBA4444': 0x2C,
    'agiColorModelRGBA5551': 0x2C,
    'agiD3DLight': 0x8C,
    'agiD3DMtlDef': 0x88,
    'agiD3DPipeline': 0x49C,
    'agiD3DRPipeline': 0x49C,
    'agiD3DRasterizer': 0x18,
    'agiD3DTexDef': 0x88,
    'agiD3DTexLut': 0x420,
    'agiD3DViewport': 0x14C,
    'agiDDBitmap': 0x40,
    'agiDDPipeline': 0x32C,
    'agiLib<class agiMtlParameters,class agiMtlDef>': 0x4014,
    'agiLib<class agiPhysParameters,class agiPhysDef>': 0x4014,
    'agiLib<class agiTexParameters,class agiTexDef>': 0x4014,
    'agiLight': 0x88,
    'agiLightModel': 0x40,
    'agiLightModelParameters': 0x28,
    'agiLightParameters': 0x70,
    'agiLighter': 0x4,
    'agiLitAnimation': 0x10,
    'agiMeshCardInfo': 0x10,
    'agiMeshModel': 0xA8,
    'agiMeshSet': 0x64,
    'agiMonoLighter': 0x4,
    'agiMtlDef': 0x80,
    'agiMtlParameters': 0x68,
    'agiPalette': 0x410,
    'agiPhysParameters': 0x58,
    'agiPipeline': 0x2F0,
    'agiPolySet': 0x2C,
    'agiRGBLighter': 0x4,
    'agiRasterizer': 0x18,
    'agiRefreshable': 0x18,
    'agiRendStateStruct': 0x3C,
    'agiRenderer': 0xC,
    'agiSWBitmap': 0x40,
    'agiSWPipeline': 0x2F0,
    'agiSWRasterizer': 0x18,
    'agiSWTexDef': 0x9C,
    'agiSWTexLut': 0x1420,
    'agiSWViewport': 0x14C,
    'agiSurfRenderer': 0x14,
    'agiSurfaceDesc': 0x7C,
    'agiTexDef': 0x74,
    'agiTexLut': 0x420,
    'agiTexParameters': 0x30,
    'agiTexSheet': 0xC,
    'agiTexSorter': 0x1,
    'agiViewParameters': 0x12C,
    'agiViewport': 0x14C,
    'agiZBufRenderer': 0x14,
    'aiAudioManager': 0x204,
    'aiGoal': 0x8,
    'aiGoalAvoidPlayer': 0x1C,
    'aiGoalBackup': 0x14,
    'aiGoalChase': 0x1AC,
    'aiGoalCollision': 0x10,
    'aiGoalFollowWayPts': 0x18C,
    'aiGoalRandomDrive': 0x14,
    'aiGoalRegainRail': 0x28,
    'aiGoalStop': 0x10,
    'aiIntersection': 0x2C,
    'aiMap': 0xBC,
    'aiPath': 0x104,
    'aiPedAudioManager': 0x120,
    'aiPedestrian': 0xAC,
    'aiPedestrianInstance': 0x28,
    'aiPoliceForce': 0x3C,
    'aiRaceData': 0x2C,
    'aiRailSet': 0x60,
    'aiStuck': 0x58,
    'aiTrafficLightInstance': 0x34,
    'aiTrafficLightSet': 0x38,
    'aiVehicle': 0x14,
    'aiVehicleActive': 0xA6C,
    'aiVehicleAmbient': 0x138,
    'aiVehicleData': 0xC0,
    'aiVehicleInstance': 0x24,
    'aiVehicleManager': 0x16628,
    'aiVehicleOpponent': 0x23BC,
    'aiVehiclePolice': 0x241C,
    'aiVehicleSpline': 0xD8,
    'artsReplayChannel': 0xC,
    'asAero': 0x74,
    'asArg': 0x48,
    'asBenchStats': 0x50,
    'asBirthRule': 0xB0,
    'asBound': 0x3C,
    'asCamera': 0x18C,
    'asCullManager': 0x1F8,
    'asCullable': 0x4,
    'asDofCS': 0xF8,
    'asForm': 0xC8,
    'asInertialCS': 0x1A8,
    'asLamp': 0x30,
    'asLineSparks': 0x5C,
    'asLinearCS': 0x88,
    'asMemoryAllocator': 0xA0,
    'asMeshSetForm': 0x2C,
    'asMidgets': 0x87C,
    'asNetObject': 0x28,
    'asNetwork': 0x64,
    'asNode': 0x20,
    'asOverSample': 0x30,
    'asParticles': 0x6C,
    'asPerfGraph': 0x94,
    'asPortalEdge': 0x30,
    'asPortalPVS': 0x8,
    'asPortalRenderable': 0x4,
    'asPortalWeb': 0x904C,
    'asRenderWeb': 0x9178,
    'asSafeHeap': 0x14,
    'asSimulation': 0x2B0,
    'asSparkLut': 0xC,
    'asViewCS': 0x124,
    'bnAnimation': 0xC,
    'bnBone': 0x8C,
    'bnSkeleton': 0x20,
    'eqEventHandler': 0x164,
    'eqEventMonitor': 0x14,
    'eqEventQ': 0x2C,
    'eqEventReplayChannelClass': 0x638,
    'eqReplayChannel': 0xC,
    'floatMI': 0x6C,
    'foobar': 0x20,
    'initHaveMMX': 0x1,
    'intMI': 0x6C,
    'ipcMessageQueue': 0x28,
    'mmAmbientAudio': 0x14,
    'mmAnimDOF': 0x98,
    'mmAnimExcel': 0x10,
    'mmAnimInstState': 0x8,
    'mmAnimMgr': 0x26B0,
    'mmAnimPlane': 0x108,
    'mmAnimSpline': 0x34,
    'mmAnimTrain': 0x100,
    'mmAnimTrainCar': 0x58,
    'mmAnimTrigger': 0x24,
    'mmAnimation': 0x18,
    'mmArrow': 0x38,
    'mmAxle': 0x9C,
    'mmBangerActive': 0x27C,
    'mmBangerActiveManager': 0x5024,
    'mmBangerData': 0x134,
    'mmBangerDataManager': 0x268D0,
    'mmBangerInstance': 0x1C,
    'mmBangerManager': 0x2C,
    'mmBoat': 0x3A4,
    'mmBoundTemplate': 0xB4,
    'mmBridgeAudMgr': 0x38,
    'mmBridgeMgr': 0x2674,
    'mmBridgeSet': 0x438,
    'mmBuildingInstance': 0x48,
    'mmCDPlayer': 0x14C,
    'mmCRHUD': 0x218,
    'mmCar': 0x230C,
    'mmCarModel': 0x110,
    'mmCarRoadFF': 0x44,
    'mmCarSim': 0x1FAC,
    'mmCellRenderer': 0x48,
    'mmCircuitHUD': 0x9C,
    'mmCityInfo': 0xA0,
    'mmCityList': 0x10,
    'mmCollideFF': 0x98,
    'mmCompBase': 0x48,
    'mmCompCRPlayer': 0x98,
    'mmCompDRecord': 0xA4,
    'mmCompRaceRecord': 0xA8,
    'mmCompRoster': 0x90,
    'mmCtrlCFG': 0x6C80,
    'mmCullCity': 0x34D6C,
    'mmDamage': 0x20,
    'mmDashView': 0x880,
    'mmDofBangerInstance': 0x34,
    'mmDrawbridgeInstance': 0x34,
    'mmDrivetrain': 0x48,
    'mmDropDown': 0xC8,
    'mmEdgeBodyIsect': 0xF4,
    'mmEffectFF': 0x80,
    'mmEngine': 0x7C,
    'mmExternalView': 0x10C,
    'mmFacadeBangerInstance': 0x30,
    'mmFacadeInstance': 0x44,
    'mmFacadeQuad': 0x18,
    'mmForce': 0x2C,
    'mmFrictionFF': 0x9C,
    'mmGame': 0x1E570,
    'mmGameEdit': 0x1E738,
    'mmGameManager': 0x5C,
    'mmGameMulti': 0x1EEA8,
    'mmGameRecord': 0x20,
    'mmGameSingle': 0x1E5F0,
    'mmGate': 0x18,
    'mmGearIndicator': 0x40,
    'mmGfxCFG': 0x34,
    'mmGlassBangerInstance': 0x1C,
    'mmHUD': 0xE94,
    'mmHitBangerInstance': 0x50,
    'mmHudMap': 0x2C8,
    'mmIO': 0x1C,
    'mmIODev': 0xA8,
    'mmIcons': 0x5C,
    'mmImpactAudio': 0x1EC,
    'mmInfoBase': 0x88,
    'mmInput': 0x248,
    'mmInstChain': 0xC,
    'mmInstance': 0x14,
    'mmInterface': 0x35830,
    'mmIntersection': 0xB0,
    'mmJaxis': 0x1C,
    'mmJoyMan': 0x48,
    'mmJoystick': 0x3A8,
    'mmLinearGauge': 0x34,
    'mmLoader': 0x2C4,
    'mmMapData': 0x90,
    'mmMatrixInstance': 0x44,
    'mmMiscData': 0x173C8,
    'mmMouseSteerBar': 0x44,
    'mmMultiBlitz': 0x1EEB8,
    'mmMultiCR': 0x1EF30,
    'mmMultiCircuit': 0x1EEB0,
    'mmMultiRace': 0x1EEB0,
    'mmNetObject': 0xF4,
    'mmNetworkCarAudio': 0xD4,
    'mmNumber': 0x80,
    'mmNumberFont': 0x24,
    'mmOpponentCarAudio': 0xE0,
    'mmOpponentImpactAudio': 0x18,
    'mmOpponentSurfaceAudio': 0x2C,
    'mmPed': 0x34,
    'mmPedManager': 0x2C,
    'mmPhysEntity': 0x20,
    'mmPhysExec': 0x24,
    'mmPhysicsMGR': 0x224,
    'mmPlayer': 0x4A98,
    'mmPlayerCarAudio': 0x100,
    'mmPlayerConfig': 0x6E30,
    'mmPlayerData': 0x2178,
    'mmPlayerDirectory': 0xE4,
    'mmPlayerRecord': 0xE4,
    'mmPoliceCarAudio': 0x114,
    'mmPolygon': 0x4C,
    'mmPopup': 0x60,
    'mmPositions': 0xC,
    'mmPropInfo': 0x94,
    'mmRaceData': 0x4B4,
    'mmRadGauge': 0x3C,
    'mmRainAudio': 0x1C,
    'mmRecord': 0x108,
    'mmRoadFF': 0x94,
    'mmRoadSect': 0x6CC,
    'mmRoadSide': 0x2E0,
    'mmRunwayLight': 0x60,
    'mmScreenClearFlunky': 0x20,
    'mmShard': 0x64,
    'mmShardManager': 0x54,
    'mmShearInstance': 0x48,
    'mmShock': 0x98,
    'mmSingleBlitz': 0x1E5B8,
    'mmSingleCircuit': 0x1E600,
    'mmSkid': 0x48,
    'mmSkidManager': 0x68,
    'mmSky': 0x8,
    'mmSlider': 0xA4,
    'mmSpeedIndicator': 0x38,
    'mmSplash': 0x330,
    'mmSpringFF': 0x9C,
    'mmStaticInstance': 0x38,
    'mmStuck': 0x58,
    'mmSurfaceAudio': 0xAC,
    'mmText': 0x2,
    'mmTextNode': 0x54,
    'mmTimer': 0x30,
    'mmToggle': 0x38,
    'mmToggle2': 0x40,
    'mmToolTip': 0x34,
    'mmTrailer': 0x1204,
    'mmTrailerInstance': 0x48,
    'mmTransmission': 0xD4,
    'mmUnhitBangerInstance': 0x30,
    'mmUpperInstance': 0x44,
    'mmVehInfo': 0xF8,
    'mmVehList': 0xC,
    'mmVehicleForm': 0x54,
    'mmViewCS': 0xC0,
    'mmVoiceCommentary': 0x158,
    'mmWPHUD': 0x98,
    'mmWaypointInstance': 0x44,
    'mmWaypointObject': 0x4C,
    'mmWaypoints': 0xAC,
    'mmWheel': 0x268,
    'mmWheelCheap': 0x17C,
    'mmYInstance': 0x2C,
    'position_t': 0x24,
    'problem_t': 0x10,
    'scharMI': 0x68,
    'sfPointer': 0x54,
    'shortMI': 0x68,
    'string': 0x8,
    'ucharMI': 0x68,
    'uiNavBar': 0xC0,
    'uiWidget': 0x74,
    'uintMI': 0x6C,
    'ushortMI': 0x68,
})

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

    'CDMan': ['Dispatchable'],

    'aiGoalAvoidPlayer': ['aiGoal'],
    'aiGoalBackup': ['aiGoal'],
    'aiGoalChase': ['aiGoal'],
    'aiGoalCollision': ['aiGoal'],
    'aiGoalFollowWayPts': ['aiGoal'],
    'aiGoalRandomDrive': ['aiGoal'],
    'aiGoalRegainRail': ['aiGoal'],
    'aiGoalStop': ['aiGoal'],

    'aiVehicleActive': ['mmPhysEntity'],
    'mmCar': ['mmPhysEntity'],
    'mmTrailer': ['mmPhysEntity'],
    'mmBangerActive': ['mmPhysEntity'],

    'mmCellRenderer': ['asPortalRenderable'],

    'Joint3Dof': ['JointedStruct'],

    'mmFacadeBangerInstance': ['mmBangerInstance'],
    'mmGlassBangerInstance': ['mmBangerInstance'],

    'agiMeshModel': ['agiMeshSet'],
}, {
    'Timer',
    'Callback'
})

final_classes = compuate_final_classes(class_hier)

print('Collecting Defualt Dtors')
default_dtors = collect_default_dtor(view, symbols, class_hier)

print('Collecting Empty Funcs')
empty_functions = collect_empty_functions(view, symbols)

# print(class_hier)

# for a, b in class_hier:
#     print(a, b)

# TODO: Sort hierarchy when multiple inheritance

print('Backporting vftable purecalls')
vftables = backport_vftable_purecalls(vftables, class_hier, {
    'MetaType':  { None: 5 },
    'asPortalRenderable': { None: 1 },
    'JointedStruct': { 'asNode': 17 },
})

class_paddings = calculate_class_paddings(class_sizes, class_hier, vftables)

'''
Comment out the following code in fixup_func_type to create a proper vftable dump
if self.member_type == 'dtor':
    param_types = []
'''
# with open('vftables.h', 'w') as f:
#     for class_name, tables in vftables.items():
#         if len(tables) != 1:
#             continue

#         table = next(iter(tables.values()))

#         f.write('struct {};\n'.format(class_name))

#         f.write('struct {}_vtbl'.format(class_name))

#         f.write('\n{\n')

#         seen = set()

#         for sym in table:
#             if sym.member_type == 'dtor':
#                 sym_name = 'Destructor'
#             else:
#                 sym_name = sym.name

#             if sym_name in seen:
#                 print('Check order of {}'.format(sym))

#                 for i in range(1, 1000):
#                     test_sym_name = '{}{}'.format(sym_name, i)
#                     if test_sym_name not in seen:
#                         sym_name = test_sym_name
#                         break

#             seen.add(sym_name)

#             params = []

#             params.append('{} * __hidden this'.format(class_name))

#             for param in sym.type.parameters:
#                 params.append(beautify_type(param.type))

#             if sym.type.has_variable_arguments:
#                 params.append('...')

#             f.write('    {} (__{}*{})({});\n'.format(beautify_type(sym.type.return_value), sym.type.calling_convention.name, sym_name, ','.join(params)))

#         f.write('};\n\n')

# assert False

with open('class_sizes.json', 'w') as f:
    json.dump(class_sizes, f, indent = 4, sort_keys = True)

with open('class_hier.json', 'w') as f:
    json.dump(class_hier, f, indent = 4, sort_keys = True)

with open('final_classes.json', 'w') as f:
    json.dump(sorted(final_classes), f, indent = 4, sort_keys = True)

with open('default_dtors.json', 'w') as f:
    json.dump(sorted(default_dtors), f, indent = 4, sort_keys = True)

with open('empty_functions.json', 'w') as f:
    json.dump(sorted(empty_functions), f, indent = 4, sort_keys = True)

with open('path_libs.json', 'w') as f:
    json.dump(path_libs, f, indent = 4, sort_keys = True)

grouped_symbols = defaultdict(lambda: defaultdict(lambda: list()))

for symbol in all_symbols:
    _ = grouped_symbols[symbol.library] # Touch All Libraries

for symbol in all_symbols:
    if (symbol.path) and (symbol.path in path_libs):
        lib = path_libs[symbol.path]
    else:
        lib = symbol.library

    grouped_symbols[lib][symbol.path].append(symbol)

fixup_vftable_symbols(grouped_symbols, vftables)

print('Collecting Type Names')
type_classes = collect_symbol_type_classes(all_symbols, class_hier)

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

SKIPPED_LIBS = set()

SKIPPED_LIBS.update({

})

with open('../code/loader/loader.cpp', 'r') as f:
    dummy_symbol_regex = re.compile(r'^include_dummy_symbol\((.+)\)')
    for line in f.readlines():
        match = dummy_symbol_regex.match(line)
        if not match:
            continue
        SKIPPED_LIBS.add(match[1].replace('_', ':'))

def is_ignored_lib(lib):
    if 'purevirt' in lib:
        return True

    if any((lib.startswith(v) for v in IGNORED_LIB_PREFIXES)):
        return True

    if lib == 'midtown':
        return True

    if lib in SKIPPED_LIBS:
        return True

    return False

class LibOutput:
    def __init__(self):
        self.header = ''
        self.source = ''
        self.includes = set()
        self.src_includes = set()

lib_outputs = defaultdict(lambda: LibOutput())

for lib, paths in grouped_symbols.items():
    output = lib_outputs[lib]

    for path, values in paths.items():
        if path:
            path_type = type_classes[path]
            output.header += '{} {}'.format(path_type, path)

            if path in final_classes:
                output.header += ' final '

            if path in class_hier:
                parents = class_hier[path]
                if parents:
                    for parent in parents:
                        if parent in path_libs:
                            parent_lib = path_libs[parent]
                            if parent_lib != lib:
                                output.includes.add(parent_lib)

                    output.header += ': '
                    output.header += ', '.join(
                        ('public ' if path_type == 'class' else '') + v for v in parents
                    )

                    if len(parents) > 1:
                        output.header += '/* Warning: Unordered Multiple Inheritance */'

            output.header += ' {\n'

        values.sort(key=symbol_sort_order)

        i = len(values)
        while i > 0:
            i -= 1
            v = values[i]
            if v.vftable_index is None:
                continue
            if v.override:
                continue

            j = i - 1
            while j >= 0:
                w = values[j]
                j -= 1
                if w.vftable_index is None:
                    continue
                if w.override:
                    continue
                if w.vftable_index < v.vftable_index:
                    continue
                del values[i]
                i += 1
                values.insert(j + 1, v)
                break

        visibility = None

        sym_dtors = choose_best_dtor(values)

        for value in values:
            if value.is_vftable:
                output.header += '// {} @ 0x{:X}\n'.format(value.undec_name, value.address)
                continue

            skip_reason = None

            if value.member_type == 'dtor':
                 if value != sym_dtors[0]:
                    continue
            elif value.type.type_class == TypeClass.VoidTypeClass:
                skip_reason = 'void'
            elif value.is_thunk:
                skip_reason = 'thunk'
            elif any((v in value.full_name for v in '`\'')):
                skip_reason = 'invalid name'

            if skip_reason is not None:
                output.header += '// 0x{:X} | {} | {}\n\n'.format(value.address, value.raw_name, skip_reason)
                continue

            if value.visibility != visibility:
                visibility = value.visibility

                if visibility is not None:
                    output.header += '\n'
                    output.header += visibility
                    output.header += ': \n'

            tokens = []
            src_tokens = []

            def add_sym_info(tokens, sym):
                if sym.raw_name == '__purecall':
                    return

                sym_info = ''
                sym_info += '// 0x{:X} | {}'.format(sym.address, sym.raw_name)

                if 'i' in sym.map_attribs:
                    if not sym.parts[-1] in ['`vector deleting destructor\'', '`scalar deleting destructor\'']:
                        sym_info += ' | inline'
                elif sym.library != lib:
                    sym_info += ' | ' + sym.library

                if (sym.type.type_class == TypeClass.FunctionTypeClass) and (sym.address != 0):
                    if not (view.get_code_refs(sym.address) or view.get_data_refs(sym.address)):
                        sym_info += ' | unused'

                sym_info += '\n'
                tokens.append(sym_info)

            if value.member_type == 'dtor':
                assert value == sym_dtors[0]
                for dtor in sym_dtors:
                    add_sym_info(tokens, dtor)
            else:
                add_sym_info(tokens, value)

            sym_name = value.parts[:]

            if (value.type.type_class == TypeClass.NamedTypeReferenceClass) and (value.type.named_type_reference.name == 'MetaClass'):
                tokens.append('//')

            is_default = (value.member_type == 'dtor') and (value.path in default_dtors)
            is_empty = (value.address in empty_functions) and (value.is_member or not value.static)

            if value.raw_name != '__purecall':
                if is_empty:
                    tokens.append('ARTS_EXPORT')
                else:
                    tokens.append('ARTS_IMPORT')

            if value.static:
                tokens.append('static' if value.is_member else '/*static*/')

            cc_name = None
            body_tokens = None

            if value.type.type_class == TypeClass.FunctionTypeClass:
                cc_name = value.type.calling_convention.name

                if cc_name != ('thiscall' if value.is_member and not value.static and not value.type.has_variable_arguments else 'cdecl'):
                    cc_name = 'ARTS_' + cc_name.upper()
                else:
                    cc_name = None

                if value.member_type == 'dtor':
                    sym_name[-1] = '~' + sym_name[-2]

                if is_empty:
                    body_tokens = []

                    body_tokens.append(filter_type_tokens(value.type.get_tokens_before_name()))

                    if cc_name is not None:
                        body_tokens.append(cc_name)

                    full_path = value.path

                    body_tokens.append('::'.join(sym_name))

                    body_tokens.append('(')

                    for i, param in enumerate(value.type.parameters):
                        if i:
                            body_tokens.append(', ')

                        body_tokens.append(filter_type_tokens(param.type.get_tokens_before_name()))
                        body_tokens.append('/*{}*/'.format(param.name))
                        body_tokens.append(filter_type_tokens(param.type.get_tokens_after_name()))

                    body_tokens.append(')')

                    body_tokens.append('{')

                    return_type_class = value.type.return_value.type_class

                    if return_type_class != TypeClass.VoidTypeClass:
                        body_tokens.append('return')

                        if return_type_class == TypeClass.IntegerTypeClass:
                            body_tokens.append('0')
                        elif return_type_class == TypeClass.PointerTypeClass:
                            body_tokens.append('nullptr')
                        else:
                            assert False, ('Invalid Return Type', value)

                        body_tokens.append(';')

                    body_tokens.append('}')
            else:
                if not value.is_member:
                    tokens.append('extern')

            if value.is_virtual and not value.override:
                tokens.append('virtual')

            if value.member_type not in ['ctor', 'dtor']:
                tokens.append(filter_type_tokens(value.type.get_tokens_before_name()))

            if cc_name is not None:
                tokens.append(cc_name)

            tokens.append(sym_name[-1] + filter_type_tokens(value.type.get_tokens_after_name()))

            if value.override:
                tokens.append('override')

            if is_default:
                tokens.append('= default')
            elif value.raw_name == '__purecall':
                tokens.append('= 0')

            # if ('i' not in value.map_attribs) and (value.library != lib):
            #     print('Moved Symbol', value, lib, value.library)
            #     lib_outputs[value.library].source += ' '.join(src_tokens)
            #     lib_outputs[value.library].source += '\n\n'
            #     lib_outputs[value.library].src_includes.add(lib)

            tokens = ' '.join(filter(None, tokens)) + ';\n\n'

            if value.is_member or not value.static:
                output.header += tokens

                if body_tokens is not None:
                    output.source += ' '.join(body_tokens) + '\n\n'
            else:
                output.source += tokens

        if path:
            if path in class_paddings:
                padding_offset, padding_size = class_paddings[path]
                output.header += 'u8 gap{:X}[0x{:X}];\n'.format(padding_offset, padding_size)

            output.header += '};\n\n'

            if (any(not v.static for v in values)):
                output.header += 'check_size({}, 0x{:X});\n\n'.format(path, class_sizes.get(path, 0))

for lib, output in lib_outputs.items():
    output_dir = os.path.normpath(SOURCE_DIR + '\\' + lib.replace(':', '\\'))
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
    sym_comment += '    ' + lib + '\n'

    first_sym = True

    for sym in all_symbols:
        if sym.library != lib:
            continue

        if first_sym:
            first_sym = False
            sym_comment += '\n'

        sym_comment += '    '

        if sym.address is not None:
            sym_comment += '0x%06X | ' % (sym.address)

        if sym.undec_name is not None:
            sym_comment += sym.undec_name + ' | '

        sym_comment += sym.raw_name
        sym_comment += '\n'

    sym_comment += '*/'

    def process_includes(includes):
        includes = [ inc.replace(':', '/') for inc in includes ]
        lib_parts = lib.split(':')

        for i, include in enumerate(includes):
            include_parts = include.split('/')
            if include_parts[:-1] == lib_parts[:-1]:
                includes[i] = include_parts[-1]

        includes.sort()
        return includes

    if is_ignored_lib(lib):
        continue

    output.src_includes -= output.includes

    with open(output_dir + '.h', 'w') as f:
        f.write(LICENSE_TXT)
        f.write('\n')
        f.write('#pragma once')
        f.write('\n\n')
        f.write(sym_comment)
        f.write('\n\n')

        if output.includes:
            for include in process_includes(output.includes):
                f.write('#include "{}.h"\n'.format(include))

            f.write('\n')

        f.write(output.header)

    with open(output_dir + '.cpp', 'w') as f:
        f.write(LICENSE_TXT)
        f.write('\n')
        f.write('define_dummy_symbol({});\n'.format(lib.replace(':', '_')))
        f.write('\n')
        f.write('#include "{}.h"\n'.format(base_name))
        f.write('\n')

        if output.src_includes:
            for include in process_includes(output.src_includes):
                f.write('#include "{}.h"\n'.format(include))

            f.write('\n')

        f.write(output.source)

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

view.file.close()
