//9.a) Write a C program to demonstrate the usage of umask and chmod functions.

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
        umask(0022);

        int file=open("demo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);            //drops to 644 cuz of umask
        close(file);

        struct stat st;
        stat("demo.txt", &st);
        printf("File Created.\nInitial Permissions: %o\n", st.st_mode & 0777);    //remember %o for st.st_mode & 0777

        chmod("demo.txt", 0704);
        stat("demo.txt", &st);
        printf("Permissions after chmod: %o\n", st.st_mode & 0777);

        return 0;
}  

//dont create demo.txt, program will do it. use ls -li to confirm permissions after.
