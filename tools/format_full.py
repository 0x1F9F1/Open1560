import glob
import os
import subprocess

paths = ['code']
exts = ['cpp', 'h']

base_dir = os.path.abspath('..')

print(base_dir)

files = []

for path in paths:
    for ext in exts:
        files.extend(glob.glob(os.path.join(base_dir, path, '**', f'*.{ext}'), recursive = True))

print(f'Processing {len(files)} files')

def chunks(l, n):
    """Yield successive n-sized chunks from l."""
    for i in range(0, len(l), n):
        yield l[i:i + n]

for chunk in chunks(files, 128):
    subprocess.run([
        'clang-format',
        '-i',
        *chunk
    ])
