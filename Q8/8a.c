//8-a) Write a C program that takes the file name as an argument and prints the type of the given file.

#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
        if(argc<2)
        {
                printf("Usage: ./a.out file.txt\n");
                return 0;
        }

        struct stat st;
        lstat(argv[1], &st);             //use lstat not stat !!

        if(S_ISREG(st.st_mode))
                printf("Regular File \n");
        else if(S_ISDIR(st.st_mode))
                printf("Directory \n");
        else if(S_ISLNK(st.st_mode))
                printf("Symbolic Link \n");
        else if(S_ISBLK(st.st_mode))
                printf("Block Device \n");
        else if(S_ISCHR(st.st_mode))
                printf("Character Device \n");
        else if(S_ISFIFO(st.st_mode))
                printf("FIFO (named pipe \n");
        else if(S_ISSOCK(st.st_mode))
                printf("Socket \n");
        else
                printf("Unknown File Type \n");

        return 0;
}
