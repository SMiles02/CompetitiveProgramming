#!/bin/bash
# cleanup.sh
# Deletes all .txt files and executables in the current directory and subdirectories.

echo "Starting cleanup..."

# Delete all .txt files
find . -type f -name "*.txt" -print -delete

# Delete all executable files (excluding directories)
# This checks for executable permission and excludes symbolic links
find . -type f -perm /111 -print -delete

echo "Cleanup complete."