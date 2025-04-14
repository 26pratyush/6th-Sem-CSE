//Write a C program to implement ls  –li command which lists the files in a specified directory.
//Your program should Print 5 attributes of files.

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    DIR *dir = opendir(".");
    struct dirent *entry;
    struct stat st;

    printf("Inode\tSize\tLinks\tModTime\t\tName\n");
    while ((entry = readdir(dir)) != NULL) 
     {
        if (stat(entry->d_name, &st) == 0) 
        {
            printf("%lu\t%ld\t%d\t%ld\t%s\n",
              
                st.st_ino,        // Inode number
                st.st_size,       // File size
                st.st_nlink,      // Number of hard links
                st.st_mtime,      // Last modification time
                entry->d_name);   // File name
        }
    }

    closedir(dir);
    return 0;
}

