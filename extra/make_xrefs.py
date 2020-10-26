import json
import struct
from collections import defaultdict

def joaat(data, seed = 0):
    h = seed
    for value in data:
        h = (h + value) * 1025 & 0xFFFFFFFF
        h = (h >> 6 ^ h)
    h = (h * 9) & 0xFFFFFFFF
    return (h >> 11 ^ h) * 32769 & 0xFFFFFFFF

def encode_uleb128(value):
    result = bytearray()
    while value >= 0x80:
        result.append((value | 0x80) & 0xFF)
        value >>= 7
    result.append(value)
    return result

def encode_ileb128(value):
    return encode_uleb128((value << 1) ^ (value >> 31))

with open('xrefs.json', 'r') as f:
    raw_xrefs = json.load(f)

processed = list()

hashes = set()

# 0: Function
# 1: Simple Data (No Deltas)
# 2: Complex Data (Deltas)


for sym_addr, (sym_name, sym_is_func, sym_refs) in raw_xrefs.items():
    # if not sym_name.startswith('?'):
    #     print(sym_name, sym_addr)

    sym_addr = int(sym_addr)
    name_hash = joaat(sym_name.encode('utf-8'))
    assert name_hash not in hashes
    hashes.add(name_hash)

    data = bytearray()

    if sym_is_func: # For functions, we only need the address (to create a jump patch)
        data += encode_uleb128(0)
    else: # For data, we need all xrefs
        sym_refs.sort()
        prev_addr = 0x400000
        prev_delta = 0
        no_deltas = (len(sym_refs) == 0) or all(delta == 0 for addr, delta in sym_refs)
        data += encode_uleb128(1 if no_deltas else 2)

        for addr, delta in sym_refs:
            offset = addr - prev_addr
            data += encode_uleb128(offset)
            if not no_deltas:
                data += encode_ileb128(delta - prev_delta)
                prev_delta = delta
            prev_addr = addr + 4

        data += encode_uleb128(0)

    processed.append((name_hash, sym_addr, sym_name, data))

processed.sort(key = lambda x: x[1])

xref_data = bytearray()
xref_data_lookup = dict()

def pack_32(data):
    data = data + b'\x00' * (-len(data) & 0x3)
    return struct.unpack('<{}I'.format(len(data) // 4), data)

def add_xref_data(data):
    global xref_data

    data = bytes(data)
    # data = pack_32(data)
    index = xref_data_lookup.get(data)
    if index is None:
        index = len(xref_data)
        xref_data += data
        xref_data_lookup[data] = index
    assert index <= 0xFFFF
    return index

add_xref_data(b'\x00')
add_xref_data(b'\x01\x00')

print('static constexpr SymbolInfo BaseSymbols[] {')
print('    // clang-format off')

for name_hash, sym_addr, name, data in processed:
    # ','.join('0x{:08X}'.format(v) for v in pack_32(data))

    print('    {{ 0x{:06X}, 0x{:08X}, 0x{:04X} }}, // {}'.format(sym_addr, name_hash, add_xref_data(data), name ))

print('    // clang-format on')
print('};')

print('static constexpr u32 BaseSymbolData[] {')
print('    // clang-format off')

xref_data_str = '    '
for i, v in enumerate(pack_32(xref_data)):
    if i != 0:
        xref_data_str += ' ' if (i % 16) else '\n    '
    xref_data_str += '0x{:08X},'.format(v)

print(xref_data_str)
print('    // clang-format on')
print('};')

print(hex(len(processed)))
print(len(xref_data) / 4)
print(hex(len(processed) * 12 + len(xref_data)))
