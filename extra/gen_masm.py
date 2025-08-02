import struct
import itertools
import json

# o_*
op_types = {
    0: 'void',
    1: 'reg',
    2: 'mem',
    3: 'phrase',
    4: 'displ',
    5: 'imm',
    6: 'far',
    7: 'near',
    8: 'trreg', # idpspec0 / trace register
    9: 'dbreg', # idpspec1 / debug register
    10: 'crreg', # idpspec2 / control register
    11: 'fpreg', # idpspec3 / floating point register
    12: 'mxreg', # _idpspec4 / mmx register
    13: 'mmreg', # _idpspec5 / xmm register
}

# ida_ua.dt_*
op_dtypes = {
    0: 'byte',
    1: 'word',
    2: 'dword',
    3: 'dword', # float
    4: 'qword', # double
    5: 'tbyte',
    6: 'packreal',
    7: 'qword',
    8: 'xmmword',
    9: 'code',
    10: 'void',
    11: 'fword',
    12: 'bitfild',
    13: 'string',
    14: 'unicode',
    15: 'ldbl',
    16: 'byte32',
    17: 'byte64',
    18: 'half',
}

op_dtype_sizes = {
    ida_ua.dt_byte: 1,
    ida_ua.dt_word: 2,
    ida_ua.dt_dword: 4,
    ida_ua.dt_float: 4,
    ida_ua.dt_double: 8,
    ida_ua.dt_tbyte: 10,
    ida_ua.dt_qword: 8,
    ida_ua.dt_byte16: 16,
}

op_dtype_suffixes = {
    ida_ua.dt_byte: 'b',
    ida_ua.dt_word: 'w',
    ida_ua.dt_dword: 'd',
}

# FF_N_*
op_ftypes = {
    0: 'VOID', # Void (unknown)?
    1: 'NUMH', # Hexadecimal number?
    2: 'NUMD', # Decimal number?
    3: 'CHAR', # Char ('x')?
    4: 'SEG', # Segment?
    5: 'OFF', # Offset?
    6: 'NUMB', # Binary number?
    7: 'NUMO', # Octal number?
    8: 'ENUM', # Enumeration?
    9: 'FOP', # Forced operand?
    10: 'STRO', # Struct offset?
    11: 'STK', # Stack variable?
    12: 'FLT', # Floating point number?
    13: 'CUST', # Custom representation?
}

# REF_*
op_rtypes = {
    1: 'OFF16', # 16bit full offset
    2: 'OFF32', # 32bit full offset
    3: 'LOW8', # low 8bits of 16bit offset
    4: 'LOW16', # low 16bits of 32bit offset
    5: 'HIGH8', # high 8bits of 16bit offset
    6: 'HIGH16', # high 16bits of 32bit offset
    9: 'OFF64', # 64bit full offset
    10: 'OFF8', # 8bit full offset
}

# FF_*
ff_dtypes = {
    0x00000000: 'BYTE',
    0x10000000: 'WORD',
    0x20000000: 'DWORD',
    0x30000000: 'QWORD',
    0x40000000: 'TBYTE',
    0x50000000: 'STRLIT',
    0x60000000: 'STRUCT',
    0x70000000: 'OWORD',
    0x80000000: 'FLOAT',
    0x90000000: 'DOUBLE',
    0xa0000000: 'PACKREAL',
    0xb0000000: 'ALIGN',
}

# FRB_*
udm_frbtypes = {
    0: 'UNK',
    1: 'NUMB',
    2: 'NUMO',
    3: 'NUMH',
    4: 'NUMD',
    5: 'FLOAT',
    6: 'CHAR',
    7: 'SEG',
    8: 'ENUM',
    9: 'OFFSET',
    10: 'STRLIT',
    11: 'STROFF',
    12: 'CUSTOM',
}

def sext64(v):
    sign = 0x8000000000000000
    if v >= sign:
        v = (int(v) ^ sign) - sign
    return v

NATIVE_WIDTH = 4 # 32-bit

def calc_reference_target(ea, ri, addr):
    target = ida_pro.ea_pointer()
    base = ida_pro.ea_pointer()
    if not ida_offset.calc_reference_data(target.cast(), base.cast(), ea, ri, addr):
        return None
    target = target.value()
    # base = base.value()
    if target == BADADDR:
        return None
    return sext64(target)

all_seen = dict()
all_done = set()

def is_pub_name(name):
    if name.endswith('_SEH'):
        return False
    if ida_name.get_name_ea(BADADDR, f"__imp_{name}") != BADADDR:
        return False
    return name.startswith('?')

named_addrs = {}
renames = {}

def get_sym_name(ea):
    if ea in all_seen:
        return all_seen[ea]
    if ea in named_addrs:
        name = named_addrs[ea]
    else:
        name = ida_name.get_ea_name(ea, GN_LOCAL)
        if not name:
            return None
        if name in renames:
            name = renames[name]
        else:
            flags = ida_bytes.get_full_flags(ea)
            if not ida_bytes.has_dummy_name(flags) and not (name.startswith('?') or name.startswith('_')):
                name = f'sym_{ea:X}'
    all_seen[ea] = name
    return name

def resolve_imm(ea, value, oi, ftype, force_addr=False):
    value = sext64(value)
    target = None

    if ftype == ida_bytes.FF_N_OFF:
        target = calc_reference_target(ea, oi.ri, value)

    if force_addr and (target is None):
        target = value

    if target is not None:
        target = ida_bytes.get_item_head(target)
        if target != BADADDR:
            target = sext64(target)
        else:
            target = None

    if target is not None:
        head_name = get_sym_name(target)

        if head_name is not None:
            delta = value - target
            return head_name, delta

    return None, value

class MasmPrinter:
    def __init__(self):
        self.tokens = []
        self._indent = 0
        self._newline = True

    def __str__(self):
        return ''.join(self.tokens)

    def write(self, value):
        if value:
            if value == '\n':
                self._newline = True
            elif self._newline:
                self.tokens.append(' ' * self._indent)
                self._newline = False

            self.tokens.append(value)

    def extend(self, other):
        for token in other.tokens:
            self.write(token)

    def indent(self, level):
        self._indent += level

    def line(self, value = ''):
        self.write(value)
        self.write('\n')

    def hex(self, value, force_sign=False):
        value = sext64(value)

        if value < 0:
            self.write('-')
            value = -value
        elif force_sign:
            self.write('+')

        if value < 10:
            self.write(f'{value}')
        else:
            x = f'{value:X}h'
            if x[0] in '0123456789':
                self.write(x)
            else:
                self.write(f'0{x}')

    def write_bytes(self, data, offset, length, per_line = 32):
        for i in range(length):
            if i % per_line:
                p.write(',')
            else:
                if i:
                    p.line()
                p.write('db ')
            p.hex(data[offset + i])

def print_operand(insn, op, oi, ftype):
    ea = insn.ea
    ty = op.type

    if ty == o_void:
        return None

    # Hide implicit operands (op.flags & ida_ua.OF_SHOW)
    if not op.shown():
        return None

    out = []

    def emit(value):
        out.append(value)

    def emit_reg(reg, size = NATIVE_WIDTH):
        reg_name = ida_idp.get_reg_name(reg, size)
        assert reg_name, ('Invalid register', reg, size)
        emit(reg_name)

    def emit_hex(value, force_sign=False):
        value = sext64(value)

        if value < 0:
            emit('-')
            value = -value
        elif force_sign:
            emit('+')

        if value < 10:
            emit(f'{value}')
        else:
            x = f'{value:X}h'
            if x[0] in '0123456789':
                emit(x)
            else:
                emit(f'0{x}')

    dty = op.dtype
    # print(op.n, op_types[ty], op_dtypes[dty], op_ftypes[ftype])
    dty_size = op_dtype_sizes[dty]

    if ty == o_reg:
        emit_reg(op.reg, dty_size)
    elif ty in [o_mem, o_phrase, o_displ]:
        if ty in [o_mem, o_displ]:
            if ty == o_displ:
                if op.flags & (ida_ua.OF_OUTER_DISP | ida_ua.OF_NO_BASE_DISP):
                    assert False, 'Displacement stuff'
            disp = op.addr
        else:
            disp = 0

        target, disp = resolve_imm(ea, disp, oi, ftype, force_addr=(ty == o_mem))
        base_reg = None
        index_reg = None
        index_scale = None

        if op.specflag1 == 1: # SIB
            sib = op.specflag2
            sib_base = (sib & 0x7)
            sib_index = (sib >> 3) & 0x7
            sib_scale = (sib >> 6) & 0x3
            # sib_base_reg = ida_idp.get_reg_name(sib_base, NATIVE_WIDTH)
            # sib_index_reg = ida_idp.get_reg_name(sib_index, NATIVE_WIDTH)
            # print('SIB', sib_base_reg, sib_index_reg, 1 << sib_scale, hex(disp))
            if (sib_base != 5) or (insn.auxpref & 0x400): # ebp, and 32-bit displacement (aux_op_is_32), ignore base reg
                base_reg = sib_base
            if sib_index != 4: # esp, ignore index/scale
                index_reg = sib_index
                index_scale = 1 << sib_scale
        else:
            assert op.specflag1 == 0
            assert op.specflag2 == 0

            if ty in [o_phrase, o_displ]:
                base_reg = op.phrase

        assert op.specflag3 == 0
        assert op.specflag4 == 0

        if insn.itype != ida_allins.NN_lea:
            emit(f'{op_dtypes[dty]} ptr ')

            if insn.segpref:
                emit_reg(insn.segpref)
                emit(':')
            elif (base_reg is None) and (target is None):
                emit('ds:')

        bracket_before_target = (base_reg is None) and (index_reg is None)
        first_part = True

        if bracket_before_target:
            emit('[')

        if target is not None:
            emit(target)
            first_part = False

        if not bracket_before_target:
            emit('[')
            first_part = True

        if base_reg is not None:
            if not first_part:
                emit('+')
            emit_reg(base_reg)
            first_part = False

        if index_reg is not None:
            if not first_part:
                emit('+')
            emit_reg(index_reg)
            emit('*')
            emit_hex(1 << sib_scale)
            first_part = False

        if first_part:
            emit_hex(disp)
        elif disp != 0:
            emit_hex(disp, force_sign=True)

        emit(']')
    elif ty in [o_imm, o_near]:
        if ty == o_imm:
            disp = op.value
        else:
            disp = op.addr

        target, disp = resolve_imm(ea, disp, oi, ftype, force_addr=(ty == o_near))

        first_part = True

        if target is not None:
            if ty == o_imm:
                emit('offset ')
            emit(target)
            first_part = False

        if first_part:
            emit_hex(disp)
        elif disp != 0:
            emit_hex(disp, force_sign=True)
    elif ty == o_idpspec3: # fpreg
        if op.reg == 0:
            emit('st')
        else:
            emit(f'st({op.reg})')
    else:
        assert False, (op_types[ty])

    if op.flags & ~ida_ua.OF_SHOW:
        assert False, ('FLAGS', hex(op.flags))

    if ftype == ida_bytes.FF_N_OFF:
        # calc_reference_data
        # flags -> REFINFO_*
        ri = oi.ri
        rty = ri.type() #  ri.flags & REFINFO_TYPE
        # print('RI', hex(ri.target), hex(ri.base), hex(ri.tdelta), op_rtypes[rty], hex(ri.flags))
    elif ftype == ida_bytes.FF_N_STRO:
        path = oi.path
        # print('STROFF', path.len, path.delta)
    elif ftype == ida_bytes.FF_N_ENUM:
        ec = oi.ec
    elif ftype != ida_bytes.FF_N_VOID:
        # print('FTYPE', op_ftypes[ftype])
        assert oi == None

    return out

def print_insn(ea, flags):
    p = MasmPrinter()

    assert ida_bytes.is_code(flags)
    insn = idaapi.insn_t()
    length = idaapi.decode_insn(insn, ea)
    assert length > 0

    insn_mnem = insn.get_canon_mnem()
    # print(hex(ea), insn_mnem)

    '''
        //---------------------------------
        // Intel 80x86 cmd.auxpref bits
        #define aux_lock        0x0001
        #define aux_rep         0x0002
        #define aux_repne       0x0004
        #define aux_use32       0x0008  // segment type
        #define aux_large       0x0010  // offset field is 32-bit (16-bit is not enough)
        #define aux_short       0x0020  // short (byte) displacement used
        #define aux_prefix      0x0040  // prefix byte is not used
        #define aux_op32        0x0080  // op32 prefix byte is not used
        #define aux_ad32        0x0100  // ad32 prefix byte is not used
        #define aux_basess      0x0200  // SS based instruction
        #define aux_op_is_32    0x0400  // operand size 32
        #define aux_ad_is_32    0x0800  // addressing mode 32
        #define aux_fpemu       0x1000  // FP emulator instruction
    '''
    if insn.auxpref & 0x1:
        p.write('lock ')
    if insn.auxpref & 0x2:
        if insn_mnem == 'cmps':
            p.write('repe ')
        else:
            p.write('rep ')
    if insn.auxpref & 0x4:
        p.write('repne ')

    p.write(insn_mnem)

    if insn_mnem in ['movs', 'scas', 'stos', 'cmps', 'xlat']:
        p.write(op_dtype_suffixes[insn.ops[0].dtype])

    first_op = True

    for i, op in enumerate(insn.ops):
        assert op.n == i
        oi = ida_nalt.opinfo_t()
        if not ida_bytes.get_opinfo(oi, ea, i, flags):
            oi = None
        ftype = (flags >> ida_bytes.get_operand_type_shift(i)) & ida_bytes.MS_N_TYPE
        tokens = print_operand(insn, op, oi, ftype)

        if tokens:
            p.write(' ' if first_op else ', ')
            first_op = False
            for tok in tokens:
                p.write(tok)

    return p

def get_init_bytes(ea, size):
    values, mask = ida_bytes.get_bytes_and_mask(ea, size)

    if all((mask[i // 8] & (1 << (i & 7))) for i in range(size)):
        return values

    return ''

DT_TYPE  = ida_bytes.DT_TYPE & 0xFFFFFFFF  # Mask for DATA typing

FF_BYTE      = ida_bytes.FF_BYTE & 0xFFFFFFFF      # byte
FF_WORD      = ida_bytes.FF_WORD & 0xFFFFFFFF      # word
FF_DWORD      = ida_bytes.FF_DWORD & 0xFFFFFFFF      # dword
FF_QWORD      = ida_bytes.FF_QWORD & 0xFFFFFFFF      # qword
FF_TBYTE      = ida_bytes.FF_TBYTE & 0xFFFFFFFF      # tbyte
FF_STRLIT      = ida_bytes.FF_STRLIT & 0xFFFFFFFF      # ASCII ?
FF_STRUCT      = ida_bytes.FF_STRUCT & 0xFFFFFFFF      # Struct ?
FF_OWORD      = ida_bytes.FF_OWORD & 0xFFFFFFFF      # octaword (16 bytes)
FF_FLOAT     = ida_bytes.FF_FLOAT & 0xFFFFFFFF     # float
FF_DOUBLE    = ida_bytes.FF_DOUBLE & 0xFFFFFFFF    # double
FF_PACKREAL  = ida_bytes.FF_PACKREAL & 0xFFFFFFFF  # packed decimal real
FF_ALIGN     = ida_bytes.FF_ALIGN & 0xFFFFFFFF     # alignment directive

def print_strlit(ea, size):
    p = MasmPrinter()

    data = get_init_bytes(ea, size)
    assert data

    valid_chars = set(ord(v) for v in ' !"#$%&()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~')
    in_quotes = False
    new_line = True
    this_line = 0

    for v in data:
        if new_line:
            if this_line:
                p.line()
            p.write('db ')
            new_line = False
            this_line = 0
            assert not in_quotes

        if v in valid_chars:
            if not in_quotes:
                if this_line:
                    p.write(',')
                p.write('\'')
                in_quotes = True
            p.write(chr(v))
        else:
            if in_quotes:
                p.write('\'')
                in_quotes = False
            if this_line:
                p.write(',')
            p.hex(v)
            if v in [0, 10]:
                new_line = True
        this_line += 1

    if in_quotes:
        p.write('\'')

    return p

def print_type(p, data, offset, tinfo):
    ty_decl = tinfo.get_realtype()
    sz = tinfo.get_size()

    if ida_typeinf.is_type_ptr(ty_decl):
        value, = struct.unpack_from('<I', data, offset)
        target, disp = resolve_imm(BADADDR, value, None, ida_bytes.FF_N_VOID, force_addr=True)

        p.write('dd ')

        if target is not None:
            p.write('offset ')
            p.write(target)
            if disp != 0:
                p.hex(disp, force_sign=True)
        else:
            p.hex(disp)
    elif ida_typeinf.is_type_struct(ty_decl):
        print_struct(p, data, offset, tinfo.get_tid())
    elif ida_typeinf.is_type_union(ty_decl):
        p.write_bytes(data, offset, sz)
    elif ida_typeinf.is_type_array(ty_decl):
        ai = ida_typeinf.array_type_data_t()
        assert tinfo.get_array_details(ai)
        assert ai.base == 0
        nelems = ai.nelems
        elty = ai.elem_type
        elsize = elty.get_size()
        for i in range(nelems):
            print_type(p, data, offset + i * elsize, elty)
    elif ida_typeinf.is_type_float(ty_decl):
        assert sz == 4
        value, = struct.unpack_from('<I', data, offset)
        p.write('dd ')
        p.write(f'0{value:08X}r')
    elif ida_typeinf.is_type_integral(ty_decl):
        if sz == 1:
            value, = struct.unpack_from('<B', data, offset)
            p.write('db ')
        elif sz == 2:
            value, = struct.unpack_from('<H', data, offset)
            p.write('dw ')
        elif sz == 4:
            value, = struct.unpack_from('<I', data, offset)
            p.write('dd ')
        else:
            assert False
        p.hex(value)
    else:
        assert False, (str(ty), ty_decl)

    p.line()

def print_struct(p, data, offset, tid):
    tif = ida_typeinf.tinfo_t()
    if not tif.get_type_by_tid(tid) or not tif.is_udt():
        raise Exception("No structure with ID: 0x%x" % tid)
    udt = ida_typeinf.udt_type_data_t()
    tif.get_udt_details(udt)

    if udt.is_union:
        p.write_bytes(data, offset, udt.total_size)
        return

    for udm in udt:
        rep = udm.repr
        rep_type = rep.bits & ida_typeinf.FRB_MASK
        tinfo = udm.type
        assert (udm.offset % 8) == 0
        assert (udm.size % 8) == 0
        off = udm.offset // 8
        sz = udm.size // 8
        assert not udm.is_gap()
        assert rep_type in [ida_typeinf.FRB_NUMH, ida_typeinf.FRB_NUMD, ida_typeinf.FRB_UNK]
        print_type(p, data, offset + off, tinfo)

    return p

def print_data(ea, flags, seg):
    dtype = flags & DT_TYPE
    size = ida_bytes.get_item_size(ea)

    oi = ida_nalt.opinfo_t()
    ftype = (flags >> ida_bytes.get_operand_type_shift(0)) & ida_bytes.MS_N_TYPE
    if not ida_bytes.get_opinfo(oi, ea, 0, flags):
        oi = None

    elsize = ida_bytes.get_data_elsize(ea, flags, oi)
    assert (size % elsize) == 0 # TODO: Handle structs with variable length array
    nelems = size // elsize

    if dtype == FF_STRLIT:
        return print_strlit(ea, size)

    if dtype == FF_STRUCT:
        p = MasmPrinter()
        data = get_init_bytes(ea, size)

        if data:
            for i in range(nelems):
                print_struct(p, data, i * elsize, oi.tid)
        else:
            p.write(f'db {size} dup (?)')

        return p

    # TODO: Handle arrays!
    # TODO: Handle dup elements
    # TODO: Handle alignment
    # TODO: Handle uninitialized values

    p = MasmPrinter()

    values = [ get_init_bytes(ea + i * elsize, elsize) for i in range(nelems) ]
    groups = [ (k, len(list(v))) for k, v in itertools.groupby(values) ]

    if (dtype == FF_BYTE) and (len(groups) == 1) and (seg.perm & ida_segment.SEGPERM_EXEC):
        data, _ = groups[0]
        if (not data) or (data[0] in [0, 0x90, 0xCC]):
            p.write('; PADDING')
            return p

    for i, (data, count) in enumerate(groups):
        if i:
            p.line()

        if dtype == FF_BYTE:
            assert elsize == 1
            p.write('db ')
        elif dtype == FF_WORD:
            assert elsize == 2
            p.write('dw ')
        elif dtype in [FF_DWORD, FF_FLOAT]:
            assert elsize == 4
            p.write('dd ')
        elif dtype in [FF_QWORD, FF_DOUBLE]:
            assert elsize == 8
            p.write('dq ')
        elif dtype == FF_TBYTE:
            assert elsize == 10
            p.write('dt ')
        elif dtype == FF_OWORD:
            assert elsize == 16
            p.write('xmmword ')
        else:
            assert False, ('Unexpected dtype', dtype)

        if count > 1:
            p.write(f'{count} dup (')

        if not data:
            p.write('?')
        else:
            if dtype == FF_BYTE:
                value, = struct.unpack('<B', data)
                p.hex(value)
            elif dtype == FF_WORD:
                value, = struct.unpack('<H', data)
                p.hex(value)
            elif dtype == FF_DWORD:
                value, = struct.unpack('<I', data)
                target, disp = resolve_imm(ea, value, oi, ftype)

                if target is not None:
                    p.write('offset ')
                    p.write(target)
                    if disp != 0:
                        p.hex(disp, force_sign=True)
                else:
                    p.hex(disp)
            elif dtype == FF_FLOAT:
                value, = struct.unpack('<I', data)
                p.write(f'0{value:08X}r')
            elif dtype == FF_QWORD:
                value, = struct.unpack('<Q', data)
                p.hex(value)
            elif dtype == FF_DOUBLE:
                value, = struct.unpack('<Q', data)
                p.write(f'0{value:016X}r')
            elif dtype == FF_TBYTE:
                value2, value1 = struct.unpack('<QH', data)
                p.write(f'0{value1:04X}{value2:016X}r')
            elif dtype == FF_OWORD:
                value2, value1 = struct.unpack('<2Q', data)
                p.write(f'0{value1:016X}{value2:016X}h')

        if count > 1:
            p.write(f')')

    return p

with open('ignored_names.json', 'r') as f:
    name_data = json.load(f)
    ignored_names = set(name_data['ignored_names'])

    for newname, oldname in name_data["renames"]:
        renames[oldname] = newname
        ignored_names.add(newname)

    for addr, newname in name_data["forced_names"]:
        named_addrs[int(addr, 16)] = newname

def print_segment(p, seg):
    for ea in Heads(seg.start_ea, seg.end_ea):
        flags = ida_bytes.get_full_flags(ea)
        insn = None
        is_label = False
        ea_name = None

        if ida_bytes.has_any_name(flags):
            ea_name = get_sym_name(ea)

        try:
            if ida_bytes.is_align(flags):
                assert not ea_name
                align = ida_nalt.get_alignment(ea)
                assert align != 0xffffffff
                align = 1 << align
                align = min(align, 16)
                p.line(f'ALIGN {align}')
                continue
            elif ida_bytes.is_code(flags):
                insn = print_insn(ea, flags)
                is_label = True
            elif ida_bytes.is_data(flags):
                insn = print_data(ea, flags, seg)
        except Exception as ex:
            print(hex(ea), ex)
            raise

        if insn:
            if ea_name:
                p.line()
                if ea_name in ignored_names:
                    if is_label:
                        p.line('EXTERN {}:PROC'.format(ea_name))
                    else:
                        p.line('EXTERN {}:BYTE'.format(ea_name))
                else:
                    if is_pub_name(ea_name):
                        p.line('PUBLIC {}'.format(ea_name))
                    if is_label:
                        p.line('{}:'.format(ea_name))
                    else:
                        p.write('{} '.format(ea_name))
                all_done.add(ea_name)

            p.indent(4)
            p.extend(insn)
            p.indent(-4)
            p.line()

def print_all():
    p = MasmPrinter()

    p.line('.686')
    p.line('.XMM')
    p.line('.MODEL FLAT')
    p.line('ASSUME FS:NOTHING')
    p.line('OPTION CASEMAP:NONE')

    for n in range(ida_segment.get_segm_qty()):
        seg = ida_segment.getnseg(n)
        assert seg
        if seg.type == ida_segment.SEG_XTRN: # Ignore imports
            continue
        seg_name = None
        if seg.perm & ida_segment.SEGPERM_EXEC:
            seg_name = 'CODE'
        elif seg.perm & ida_segment.SEGPERM_WRITE:
            seg_name = 'DATA'
        else:
            seg_name = 'CONST'

        p.line()
        p.line(f'.{seg_name}')
        p.line()

        print_segment(p, seg)

    p.line()

    for addr, name in sorted(all_seen.items()):
        if name not in all_done:
            p.line(f'EXTERN {name}:BYTE')

    p.line()

    for i in range(ida_nalt.get_import_module_qty()):
        name = ida_nalt.get_import_module_name(i)
        assert name
        p.line(f'INCLUDELIB {name}')

    p.line()
    p.line('END')

    return str(p)

output = print_all()

with open('game.asm', 'w') as f:
    f.write(output)

print('Done!')