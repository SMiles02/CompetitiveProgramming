#!/bin/bash
# cleanup.sh
# Deletes all .txt files and executables in the current directory and subdirectories,
# but never deletes this script itself.

echo "Starting cleanup..."

# Get the absolute path of this script
SCRIPT_PATH="$(realpath "$0")"
SCRIPT_NAME="$(basename "$SCRIPT_PATH")"

# Delete all .txt files except this script
find . -type f -name "*.txt" ! -path "$SCRIPT_PATH" -exec echo "Deleting {}" \; -delete

# Delete all executable files except this script
find . -type f -perm /111 ! -path "$SCRIPT_PATH" ! -name "$SCRIPT_NAME" -exec echo "Deleting {}" \; -delete

echo "Cleanup complete."
