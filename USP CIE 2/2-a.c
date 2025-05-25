//2.a) Write a C program to display various details of a file using stat structure (At least 5 fields).

#include <stdio.h>
#include <sys/stat.h>

int main() {
    char filename[100];
    struct stat fileStat;

    printf("Enter the file name: ");
    scanf("%s", filename);

    stat(filename, &fileStat);

    printf("File Size      : %ld bytes\n", fileStat.st_size);
    printf("Number of Links: %ld\n", fileStat.st_nlink);
    printf("Inode Number   : %ld\n", fileStat.st_ino);
    printf("File Mode      : %o\n", fileStat.st_mode);
    printf("Last Access    : %ld\n", fileStat.st_atime);

    return 0;
}
