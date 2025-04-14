//5-a) Write a C program that takes the file name as an argument and prints the type of the given file.

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])       //Send filename as argument:- ./a.out test.txt
{
    struct stat st;
    lstat(argv[1], &st);		//lstat

    if (S_ISREG(st.st_mode)) printf("Regular file\n");
    else if (S_ISDIR(st.st_mode)) printf("Directory\n");
    else if (S_ISLNK(st.st_mode)) printf("Symbolic link\n");
    else if (S_ISCHR(st.st_mode)) printf("Character device\n");
    else if (S_ISBLK(st.st_mode)) printf("Block device\n");
    else if (S_ISFIFO(st.st_mode)) printf("FIFO (named pipe)\n");
    else if (S_ISSOCK(st.st_mode)) printf("Socket\n");
    else printf("Unknown file type\n");

    return 0;
}


