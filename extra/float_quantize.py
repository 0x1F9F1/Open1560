import struct

def f2i(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]

def i2f(x):
    return struct.unpack('<f', struct.pack('<I', x))[0]

# Convert (quantize) a float to fixed point
# https://en.wikipedia.org/wiki/Single-precision_floating-point_format
# https://en.wikipedia.org/wiki/Fixed-point_arithmetic
# http://pages.cs.wisc.edu/~markhill/cs354/Fall2008/notes/flpt.apprec.html

is_signed = int(True)
whole_bits = 0
fract_bits = 22
total_bits = is_signed + whole_bits + fract_bits
assert total_bits <= 23

print('Fixed Point {}:{}:{} ({} bits)'.format(is_signed, whole_bits, fract_bits, total_bits))

total_mask = (1 << total_bits) - 1
whole_mask = (1 << whole_bits) - 1
fract_mask = (1 << fract_bits) - 1

# An exponent value of 127 represents the actual zero
exponent_bias = 127

# Masking may be better if you only want part of the value, especially if it can become a truncation
# Xoring may be better if the compiler is able to use the same immediate for both operations (and it's symetrical)
use_xor_quant = True

if is_signed and not use_xor_quant:
    quantizer = float(3 << (22 - fract_bits))
    iquantizer = ((exponent_bias + 23 - fract_bits) << 23) + (1 << 22)
    assert quantizer == i2f(iquantizer)
else:
    quantizer = float(1 << (23 - fract_bits))
    iquantizer = ((exponent_bias + 23 - fract_bits) << 23)

assert quantizer == i2f(iquantizer)

if is_signed:
    dequantizer = quantizer + (1 << whole_bits)
    idequantizer = iquantizer + (1 << whole_bits + fract_bits)
else:
    dequantizer = quantizer
    idequantizer = iquantizer

assert dequantizer == i2f(idequantizer)

if is_signed:
    min_qvalue = 1 << (total_bits - 1)
    max_qvalue = min_qvalue - 1
else:
    min_qvalue = 0
    max_qvalue = (1 << total_bits) - 1

if use_xor_quant:
    def quantize(x):
        return f2i(x + dequantizer) ^ f2i(dequantizer)
else:
    def quantize(x):
        return f2i(x + quantizer) & total_mask

def dequantize(x):
    return i2f(x ^ f2i(dequantizer)) - dequantizer

min_value = dequantize(min_qvalue)
max_value = dequantize(max_qvalue)

if use_xor_quant:
    print('Quant: f2i(x + {}f) ^ 0x{:X}'.format(dequantizer, f2i(dequantizer)))
else:
    print('Quant: f2i(x + {}f) & 0x{:X}'.format(quantizer, total_mask))

print('Dequant: i2f(x ^ 0x{:X}) - {}f'.format(f2i(dequantizer), dequantizer))

print('Total: x & 0x{:X}'.format(total_mask))

if whole_mask:
    print('Whole: (x >> {}) & 0x{:X}'.format(fract_bits, whole_mask))

if fract_mask:
    print('Fract: x & 0x{:X}'.format(fract_mask))

if is_signed:
    print('Sign: (x >> {}) & 0x1'.format(whole_bits + fract_bits))

print('FRange: {} -> {}'.format(min_value, max_value))
print('QRange: {} -> {}'.format(min_qvalue, max_qvalue))

assert min_value <= max_value
assert max_value >= 0

if is_signed:
    assert min_value < 0
else:
    assert min_value == 0

if True: # Validate round-trip
    for x in range(1 << total_bits):
        v1 = dequantize(x)
        w2 = ((x ^ min_qvalue) - min_qvalue) / (1 << fract_bits)

        if w2 != v1:
            print('Bad dequantize', w2, v1)
            break

        v2 = quantize(v1)
        w2 = int(w2 * (1 << fract_bits)) & total_mask

        if x != v2 or x != w2:
            print('Bad quantize', x, v1, v2, w2)
            break