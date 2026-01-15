#!/bin/bash

TARGET_DIR="#include"      # Folder to move files into
FILENAME_PATTERN="$1"      # Pattern to match files (passed as first argument)

if [ -z "$FILENAME_PATTERN" ]; then
  echo "Usage: $0 <filename_pattern>"
  exit 1
fi

mkdir -p "$TARGET_DIR"

files=($FILENAME_PATTERN)
total=${#files[@]}
if [ $total -eq 0 ]; then
  echo "No files found matching '$FILENAME_PATTERN'."
  exit 0
fi

progress=0

show_progress() {
  percent=$1
  bar_length=20
  filled=$(( (percent * bar_length) / 100 ))
  empty=$((bar_length - filled))
  bar=$(printf "%0.s#" $(seq 1 $filled))
  bar="$bar$(printf "%0.s-" $(seq 1 $empty))"
  echo -ne "\rProgress: [$bar] $percent%"
}

for file in "${files[@]}"; do
  if [ -f "$file" ]; then
    mv "$file" "$TARGET_DIR/"
    # Update progress
    progress=$((progress + 100 / total))
    show_progress $progress
  fi
done

show_progress 100
echo -e "\nDone! Moved $total files to '$TARGET_DIR'."