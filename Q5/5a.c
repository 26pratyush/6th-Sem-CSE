//5-a) Write a program to copy access and modification time of a file to another file using utime function.

#include<stdio.h>
#include<utime.h>
#include<sys/stat.h>

int main()
{
        char *src="src.txt";
        char *dest="dest.txt";

        struct stat st;
        struct utimbuf newtime;

        stat(src,&st);

        newtime.actime=st.st_atime;
        newtime.modtime=st.st_mtime;

        utime(dest, &newtime);

        printf("Timestamps copied from %s to %s", src, dest);

        return 0;
}

//To confirm access and modification times, enter on terminal before and after execution:
//stat src.txt
//stat dest.txt
