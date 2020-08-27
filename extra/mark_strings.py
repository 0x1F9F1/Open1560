with open(os.path.dirname(bv.file.filename) + '/relocs.json', 'r') as f:
    relocs = json.load(f)

def is_bad_char(value):
    value = ord(value)
    if value >= 0x7F:
        return True
    if value < 0x20:
        return value not in b'\r\n\t'
    return False

for _, target in relocs:
    if bv.is_offset_executable(target):
        continue
    var = bv.get_data_var_at(target)
    if var is not None:
        if var.type != Type.void():
            continue
    string = bv.get_ascii_string_at(target, 1)
    if string is None:
        continue
    if (target & 3) != 0:
        print('Unaligned', hex(target))
        continue
    if (any(is_bad_char(v) for v in string.value)):
        continue
    if string.value in ['%s', '%d', '%f', '|', ',', 'r', 'w', ' ', '\r\n', '  ', '\n']:
        bv.define_data_var(target, Type.array(Type.char(), string.length + 1))
        continue
    # if string.length < 3:
    print(hex(target), string.value)
