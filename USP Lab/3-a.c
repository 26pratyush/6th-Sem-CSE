//Write a C program to remove empty files from the given directory.

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct dirent *entry;
    struct stat filestat;
    char path[256];
    DIR *dir = opendir(".");

    while ((entry = readdir(dir)))
        if (entry->d_name[0] != '.') {
            snprintf(path, sizeof(path), "./%s", entry->d_name);
            if (!stat(path, &filestat) && S_ISREG(filestat.st_mode) && filestat.st_size == 0)
                remove(path), printf("Removed: %s\n", path);
        }

    closedir(dir);
    return 0;
}

// Pointer to hold each directory entry 
// Struct to store file metadata 
// Buffer to store the full file path
// Loop through each entry in the directory
// Skip hidden files and special entries "." and ".."
// Build full path to the file (e.g., "./file.txt")
// Get file info and check success (stat returns 0 on success)
// Check if it's a regular file (not a dir, symlink, etc.)
// Check if the file size is zero (empty file)
// Delete the file and print a confirmation message
