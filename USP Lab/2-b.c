//2-b) Write a C program to demonstrate the creation of soft links and hard links.

#include <stdio.h>
#include <unistd.h>

int main() {

    link("test.txt", "hardlink.txt");
    printf("Hard link created successfully.\n");

    symlink("test.txt", "softlink.txt");
    printf("Soft link created successfully.\n");

    return 0;
}

/*Use ls -l command to confirm creation.
Hardlink has same inode/file number as test.txt and softlink -> test.txt

    if (link("test.txt", "hardlink.txt") == 0)
        printf("Hard link created successfully.\n");
    else
        perror("Hard link");
if u wanna include error handling*/
