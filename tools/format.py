import fnmatch
import os
import subprocess
import re

paths = ['code']
exts = ['cpp', 'h']

base_dir = os.path.abspath('..')

print(base_dir)

file_patterns = []

for path in paths:
    for ext in exts:
        file_patterns.append(os.path.join(base_dir, path, f'**.{ext}'))

modified_regex = re.compile(rb'modified:\s*(.+)\n')

status_text = subprocess.check_output(["git", "status"])

unstaged_find = status_text.find(b'Changes not staged for commit:')

if unstaged_find != -1:
    status_text = status_text[unstaged_find:]

    modified_files = (os.path.abspath(file).decode('utf-8') for file in modified_regex.findall(status_text))

    files = [path for path in modified_files if any(fnmatch.fnmatch(path, match) for match in file_patterns)]

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
else:
    print('No files to process')
