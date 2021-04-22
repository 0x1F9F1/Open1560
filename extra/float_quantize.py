import struct

def signed_to_unsigned(value, bit_count):
    return value & ((1 << bit_count) - 1)

def unsigned_to_signed(value, bit_count):
    value = signed_to_unsigned(value, bit_count)
    if value & (1 << (bit_count - 1)):
         value -= (1 << bit_count)
    return value

# Convert (quantize) a float to fixed point
# https://en.wikipedia.org/wiki/Single-precision_floating-point_format
# https://en.wikipedia.org/wiki/Fixed-point_arithmetic

whole_bits = 12
fract_bits = 22 - whole_bits

max_value = (1 << whole_bits)
quantizer = float(3 << whole_bits)

max_fract = 1 << fract_bits

whole_mask = max_value - 1
fract_mask = max_fract - 1
unorm_mask  = (max_fract << 1) - 1
snorm_mask  = (max_fract << 2) - 1

print('Q{}.{} = {}'.format(whole_bits, fract_bits, quantizer))

print('Whole: (x >> {}) & 0x{:X}'.format(fract_bits, whole_mask))
print('Fract: x & 0x{:X}'.format(fract_mask))
print('Unsigned Normal: x & 0x{:X}'.format(unorm_mask))
print('Signed Normal: x & 0x{:X}'.format(snorm_mask))

for x in range(max_value):
    v, = struct.unpack('<I', struct.pack('<f', x + quantizer))
    v = (v >> fract_bits) & whole_mask
    if x != v:
        print('Bad Whole', hex(x), hex(v))
        break

for x in range(-max_fract, max_fract + 1):
    v, = struct.unpack('<I', struct.pack('<f', (x / max_fract) + quantizer))
    v = unsigned_to_signed(v & snorm_mask, fract_bits + 2)
    if x != v:
        print('Bad Fract', hex(x), hex(v))
        break

# for x in range(1 << 22):
#     v, = struct.unpack('<I', struct.pack('<f', (x / max_fract) + quantizer))
#     v = v & ((1 << 22) - 1)
#     if x != v:
#         print('Bad', hex(x), hex(v))
#         break
