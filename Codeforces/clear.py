import argparse
import shutil
import sys
from pathlib import Path
import pathspec

def remove_empty_folders(root_path):
    """Recursively removes empty directories."""
    # We walk bottom-up so we can catch folders that become empty 
    # after their subfolders are deleted.
    for p in sorted(Path(root_path).rglob('*'), key=lambda x: len(str(x)), reverse=True):
        if p.is_dir() and not any(p.iterdir()) and '.git' not in p.parts:
            try:
                p.rmdir()
                print(f"Removed empty folder: {p.relative_to(root_path)}")
            except Exception as e:
                print(f"Could not remove folder {p}: {e}")

def clean_git_and_empty(root_path, gitignore_path):
    root = Path(root_path).resolve()
    gitignore = Path(gitignore_path).resolve()
    
    if not root.exists():
        print(f"Error: Root path '{root}' does not exist.")
        sys.exit(1)

    # 1. Parse .gitignore
    try:
        with open(gitignore, 'r') as f:
            spec = pathspec.PathSpec.from_lines('gitwildmatch', f)
    except FileNotFoundError:
        print(f"Error: Gitignore file '{gitignore}' not found.")
        sys.exit(1)

    # 2. Gather and Match paths
    all_paths = [str(p.relative_to(root)) for p in root.rglob('*') if '.git' not in p.parts]
    matches = list(spec.match_files(all_paths))

    # 3. Delete Ignored Content
    if matches:
        print(f"Deleting {len(matches)} ignored items...")
        for relative_path in sorted(matches, key=len, reverse=True):
            full_path = root / relative_path
            try:
                if full_path.is_dir():
                    shutil.rmtree(full_path)
                elif full_path.is_file():
                    full_path.unlink()
            except Exception as e:
                print(f"Error deleting {relative_path}: {e}")
    else:
        print("No ignored files found.")

    # 4. Remove Remaining Empty Folders
    print("Checking for empty folders...")
    remove_empty_folders(root)
    print("Cleanup complete.")

def main():
    parser = argparse.ArgumentParser(description="Delete ignored files and empty folders.")
    parser.add_argument("root", help="The root directory to clean.")
    parser.add_argument("gitignore", help="Path to the .gitignore file.")

    args = parser.parse_args()
    clean_git_and_empty(args.root, args.gitignore)

if __name__ == "__main__":
    main()