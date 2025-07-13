import os
import re
import requests
import shutil

# Folder with unsorted .cpp files
TEMP_DIR = './temp/Finished'

# Regex to match Codeforces-style filenames like 1234A.cpp
pattern = re.compile(r'^(\d+)([A-Z][0-9]?)\.cpp$', re.IGNORECASE)

# Use bulk problem list to avoid excessive API calls
print("Fetching Codeforces problem list...")
resp = requests.get("https://codeforces.com/api/problemset.problems")
if resp.status_code != 200 or resp.json()['status'] != 'OK':
    print("Failed to fetch Codeforces problems.")
    exit()

problems = resp.json()['result']['problems']

# Create lookup: (contestId, index) → rating
difficulty_map = {}
for prob in problems:
    contest_id = str(prob.get('contestId'))
    index = prob.get('index', '').upper()
    rating = prob.get('rating', 'Unknown')
    difficulty_map[(contest_id, index)] = rating

# Process each file in ./temp
for filename in os.listdir(TEMP_DIR):
    match = pattern.match(filename)
    if not match:
        continue

    src_file_name = os.path.join(TEMP_DIR , filename)
    directory_name = os.path.join(TEMP_DIR , os.path.splitext(filename)[0])
    contest_id, index = match.groups()
    index = index.upper()
    rating = difficulty_map.get((contest_id, index), 'Unknown')
    rating_folder = os.path.join("./", str(rating))
    # Create dst folder
    os.makedirs(directory_name , exist_ok=True)
    shutil.move(src_file_name, directory_name)
    # Ensure folder exists
    os.makedirs(rating_folder, exist_ok=True)

    # Move folder
    src_path = directory_name
    dst_path = os.path.join(rating_folder, os.path.splitext(filename)[0])
    shutil.move(src_path, dst_path)

    print(f"Moved {filename} → {rating}/")

print("Done.")
