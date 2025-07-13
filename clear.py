import os

# Root directory (current directory)
root_dir = '.'

# Walk through all subdirectories
for dirpath, dirnames, filenames in os.walk(root_dir):
    for file in filenames:
        if file.lower() == 'a.exe':
            file_path = os.path.join(dirpath, file)
            try:
                os.remove(file_path)
                print(f"Deleted: {file_path}")
            except Exception as e:
                print(f"Failed to delete {file_path}: {e}")
import os

EXCLUDED = [".\\temp\\Finished" , ".\\temp\\Not finished"]

def remove_empty_dirs(root='.'):
    removed = 0
    # Traverse the directory tree from bottom up
    for dirpath, dirnames, filenames in os.walk(root, topdown=False):
        if not dirnames and not filenames and dirpath not in EXCLUDED:
            try:
                os.rmdir(dirpath)
                print(f"Removed empty directory: {dirpath}")
                removed += 1
            except OSError as e:
                print(f"Failed to remove {dirpath}: {e}")
    print(f"Total empty directories removed: {removed}")

remove_empty_dirs()

