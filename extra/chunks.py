for func in Functions():
    print('0x{:06X}: {}'.format(func, Name(func)))
    for chunk_start, chunk_end in Chunks(func):
        print('  0x{:06X} -> 0x{:06X}'.format(chunk_start, chunk_end))
