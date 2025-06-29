//11.a) Write a program to differentiate between dup and dup2 functions

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
        int file=open("test.txt", O_WRONLY | O_TRUNC);    //assuming blank file test.txt already exists

        int dfile=dup(file);
        char text[]="written using dup\n";
        write(dfile, text, strlen(text));                //dfile and text
        printf("dup used fd: %d\n",dfile);               //optional
        close(dfile);

        int d2file=dup2(file,3);
        char text1[]="written using dup2";
        write(d2file, text1, strlen(text));              //d2file and text1
        printf("dup2 used fd: %d", d2file);              //optional
        close(d2file);

        close(file);

        return 0;
}

/* dup(file) → duplicates file to the lowest available file descriptor (e.g., 4). You don’t control the target FD.
dup2(file, 3) → duplicates file specifically to FD 3, replacing it if already in use.

So:
dup() = automatic FD assignment
dup2() = manual FD assignment (you choose the number)
Both point to the same file and share the same file offset. */
